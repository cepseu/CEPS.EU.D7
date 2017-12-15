<?php

/*
 +--------------------------------------------------------------------+
 | CiviCRM version 3.2                                                |
 +--------------------------------------------------------------------+
 | Copyright CiviCRM LLC (c) 2004-2010                                |
 +--------------------------------------------------------------------+
 | This file is a part of CiviCRM.                                    |
 |                                                                    |
 | CiviCRM is free software; you can copy, modify, and distribute it  |
 | under the terms of the GNU Affero General Public License           |
 | Version 3, 19 November 2007 and the CiviCRM Licensing Exception.   |
 |                                                                    |
 | CiviCRM is distributed in the hope that it will be useful, but     |
 | WITHOUT ANY WARRANTY; without even the implied warranty of         |
 | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.               |
 | See the GNU Affero General Public License for more details.        |
 |                                                                    |
 | You should have received a copy of the GNU Affero General Public   |
 | License and the CiviCRM Licensing Exception along                  |
 | with this program; if not, contact CiviCRM LLC                     |
 | at info[AT]civicrm[DOT]org. If you have questions about the        |
 | GNU Affero General Public License or the licensing of CiviCRM,     |
 | see the CiviCRM license FAQ at http://civicrm.org/licensing        |
 +--------------------------------------------------------------------+
*/

/**
 *
 * @package CRM
 * @copyright CiviCRM LLC (c) 2004-2010
 * $Id$
 *
 */
class CRM_Extendedreport_Form_Report_Pledge_Sybuns extends CRM_Extendedreport_Form_Report_ExtendedReport {
  protected $_charts = array(
    '' => 'Tabular',
    'barChart' => 'Bar Chart',
    'pieChart' => 'Pie Chart'
  );
  protected $_add2groupSupported = FALSE;
  protected $_customGroupExtends = array(
    'Pledge'
  );

  /**
   *
   */
  public function __construct() {
    $yearsInPast = 8;
    $yearsInFuture = 2;
    $date = CRM_Core_SelectValues::date('custom', NULL, $yearsInPast, $yearsInFuture);
    $count = $date['maxYear'];
    while ($date['minYear'] <= $count) {
      $optionYear[$date['minYear']] = $date['minYear'];
      $date['minYear']++;
    }

    $this->_columns = array(
      'civicrm_contact' => array(
        'dao' => 'CRM_Contact_DAO_Contact',
        'grouping' => 'contact-field',
        'fields' => array(
          'display_name' => array(
            'title' => ts('Donor Name'),
            'required' => TRUE
          )
        ),
        'filters' => array(
          'sort_name' => array(
            'title' => ts('Donor Name'),
            'operator' => 'like'
          )
        )
      ),
      'civicrm_email' => array(
        'dao' => 'CRM_Core_DAO_Email',
        'grouping' => 'contact-field',
        'fields' => array(
          'email' => array(
            'title' => ts('Email'),
            'default' => TRUE
          )
        )
      ),
      'civicrm_phone' => array(
        'dao' => 'CRM_Core_DAO_Phone',
        'grouping' => 'contact-field',
        'fields' => array(
          'phone' => array(
            'title' => ts('Phone No'),
            'default' => TRUE
          )
        )
      ),
      'civicrm_pledge' => array(
        'dao' => 'CRM_Pledge_DAO_Pledge',
        'fields' => array(
          'contact_id' => array(
            'title' => ts('contactId'),
            'no_display' => TRUE,
            'required' => TRUE,
            'no_repeat' => TRUE
          ),
          'amount' => array(
            'title' => ts('Total Amount'),
            'no_display' => TRUE,
            'required' => TRUE,
            'no_repeat' => TRUE
          ),
          'start_date' => array(
            'title' => ts('Year'),
            'no_display' => TRUE,
            'required' => TRUE,
            'no_repeat' => TRUE,
          ),
        ),
        'filters' => array(
          'yid' => array(
            'name' => 'start_date',
            'title' => ts('This Year'),
            'operatorType' => CRM_Report_Form::OP_SELECT,
            'options' => $optionYear,
            'default' => date('Y'),
          ),
          'status_id' => array(
            'title' => 'Status',
            'operatorType' => CRM_Report_Form::OP_MULTISELECT,
            'options' => CRM_Contribute_PseudoConstant::contributionStatus(),
            'default' => array('1'),
          ),
        ),
      ),
      'civicrm_group' => array(
        'dao' => 'CRM_Contact_DAO_GroupContact',
        'alias' => 'cgroup',
        'filters' => array(
          'gid' => array(
            'name' => 'group_id',
            'title' => ts('Group'),
            'operatorType' => CRM_Report_Form::OP_MULTISELECT,
            'group' => TRUE,
            'options' => CRM_Core_PseudoConstant::group()
          )
        )
      )
    );

    $this->_tagFilter = TRUE;
    parent::__construct();
  }

  function preProcess() {
    parent::preProcess();
  }

  function select() {
    $select = array();
    $this->_columnHeaders = array();
    $current_year = $this->_params['yid_value'];
    $previous_year = $current_year - 1;
    $previous_pyear = $current_year - 2;
    $previous_ppyear = $current_year - 3;
    $upTo_year = $current_year - 4;

    foreach ($this->_columns as $tableName => $table) {
      if (array_key_exists('fields', $table)) {
        foreach ($table['fields'] as $fieldName => $field) {

          if (CRM_Utils_Array::value('required', $field) || CRM_Utils_Array::value($fieldName, $this->_params['fields'])) {
            if ($fieldName == 'amount') {
              $select[] = "SUM({$field['dbAlias']}) as {$tableName}_{$fieldName}";

              $this->_columnHeaders["civicrm_upto_{$upTo_year}"]['type'] = $field['type'];
              $this->_columnHeaders["civicrm_upto_{$upTo_year}"]['title'] = "Up To $upTo_year";

              $this->_columnHeaders["{$previous_ppyear}"]['type'] = $field['type'];
              $this->_columnHeaders["{$previous_ppyear}"]['title'] = $previous_ppyear;

              $this->_columnHeaders["{$previous_pyear}"]['type'] = $field['type'];
              $this->_columnHeaders["{$previous_pyear}"]['title'] = $previous_pyear;

              $this->_columnHeaders["{$previous_year}"]['type'] = $field['type'];
              $this->_columnHeaders["{$previous_year}"]['title'] = $previous_year;

              $this->_columnHeaders["civicrm_life_time_total"]['type'] = $field['type'];
              $this->_columnHeaders["civicrm_life_time_total"]['title'] = 'LifeTime';;
            }
            else {
              if ($fieldName == 'start_date') {
                $select[] = "Year({$field['dbAlias']} ) as {$tableName}_{$fieldName}";
              }
              else {
                $select[] = "{$field['dbAlias']} as {$tableName}_{$fieldName}";
                $this->_columnHeaders["{$tableName}_{$fieldName}"]['type'] = CRM_Utils_Array::value('type', $field);
                $this->_columnHeaders["{$tableName}_{$fieldName}"]['title'] = $field['title'];
              }
            }
            if (CRM_Utils_Array::value('no_display', $field)) {
              $this->_columnHeaders["{$tableName}_{$fieldName}"]['no_display'] = TRUE;
            }
          }
        }
      }
    }

    $this->_select = "SELECT " . implode(', ', $select) . " ";
  }

  function from() {
    $this->_from = "
        FROM  civicrm_pledge  {$this->_aliases['civicrm_pledge']}
             INNER JOIN civicrm_contact {$this->_aliases['civicrm_contact']}
                         ON {$this->_aliases['civicrm_contact']}.id = {$this->_aliases['civicrm_pledge']}.contact_id
             {$this->_aclFrom}
             LEFT  JOIN civicrm_email  {$this->_aliases['civicrm_email']}
                         ON {$this->_aliases['civicrm_contact']}.id = {$this->_aliases['civicrm_email']}.contact_id
                         AND {$this->_aliases['civicrm_email']}.is_primary = 1
             LEFT  JOIN civicrm_phone  {$this->_aliases['civicrm_phone']}
                         ON {$this->_aliases['civicrm_contact']}.id = {$this->_aliases['civicrm_phone']}.contact_id AND
                            {$this->_aliases['civicrm_phone']}.is_primary = 1 ";
  }

  function where() {
    $this->_where = "";
    $this->_statusClause = "";
    foreach ($this->_columns as $tableName => $table) {
      if (array_key_exists('filters', $table)) {
        foreach ($table['filters'] as $fieldName => $field) {
          $clause = NULL;
          if (CRM_Utils_Array::value('type', $field) & CRM_Utils_Type::T_DATE) {
            $relative = CRM_Utils_Array::value("{$fieldName}_relative", $this->_params);
            $from = CRM_Utils_Array::value("{$fieldName}_from", $this->_params);
            $to = CRM_Utils_Array::value("{$fieldName}_to", $this->_params);

            if ($relative || $from || $to) {
              $clause = $this->dateClause($field['name'], $relative, $from, $to, $field['type']);
            }
          }
          else {
            $op = CRM_Utils_Array::value("{$fieldName}_op", $this->_params);
            if ($op) {
              $clause = $this->whereClause($field, $op, CRM_Utils_Array::value("{$fieldName}_value", $this->_params), CRM_Utils_Array::value("{$fieldName}_min", $this->_params), CRM_Utils_Array::value("{$fieldName}_max", $this->_params));
              if ($fieldName == 'contribution_status_id' && !empty($clause)) {
                $this->_statusClause = " AND " . $clause;
              }
            }
          }

          if (!empty($clause)) {
            $clauses[] = $clause;
          }
        }
      }
    }


    if (empty($clauses)) {
      $this->_where = "WHERE {$this->_aliases['civicrm_pledge']}.is_test = 0 ";
    }
    else {
      $this->_where = "WHERE {$this->_aliases['civicrm_pledge']}.is_test = 0 AND " . implode(' AND ', $clauses);
    }
    if ($this->_aclWhere) {
      $this->_where .= " AND {$this->_aclWhere} ";
    }
  }

  /**
   * Overriding this is the best way to alter the where statement for an individual field.
   *
   * @param array $field Field specifications
   * @param string $op Query operator (not an exact match to sql)
   * @param mixed $value
   * @param float $min
   * @param float $max
   *
   * @return null|string
   */
  function whereClause(&$field, $op, $value, $min, $max) {
    if ($field['name'] =='start_date') {
      return(
        "pledge_civireport.contact_id NOT IN
(SELECT distinct cont.id FROM civicrm_contact cont, civicrm_pledge pledge
 WHERE  cont.id = pledge.contact_id AND YEAR (pledge.start_date) = $value AND pledge.is_test = 0 )"
      );
    }
    return parent::whereClause($field, $op, $value, $min, $max);
  }

  function groupBy() {
    $this->assign('chartSupported', TRUE);
    $this->_groupBy = "Group BY {$this->_aliases['civicrm_pledge']}.contact_id, Year({$this->_aliases['civicrm_pledge']}.start_date) WITH ROLLUP ";
  }

  /**
   * @param $rows
   *
   * @return mixed
   */
  function statistics(&$rows) {
    $statistics = parent::statistics($rows);

    if (!empty($rows)) {
      $select = "
                   SELECT
                        SUM({$this->_aliases['civicrm_pledge']}.amount ) as amount ";

      $sql = "{$select} {$this->_from } {$this->_where}";
      $dao = CRM_Core_DAO::executeQuery($sql);
      if ($dao->fetch()) {
        $statistics['counts']['amount'] = array(
          'value' => $dao->amount,
          'title' => 'Total LifeTime',
          'type' => CRM_Utils_Type::T_MONEY
        );
      }
    }
    return $statistics;
  }

  function postProcess() {
    // get ready with post process params
    $this->beginPostProcess();

    $this->buildACLClause($this->_aliases['civicrm_contact']);
    $this->select();
    $this->from();
    $this->extendedCustomDataFrom();
    $this->where();
    $this->groupBy();

    $rows = $contactIds = array();
    if (!CRM_Utils_Array::value('charts', $this->_params)) {
      $this->limit();
      $getContacts = "SELECT SQL_CALC_FOUND_ROWS {$this->_aliases['civicrm_contact']}.id as cid {$this->_from} {$this->_where} GROUP BY {$this->_aliases['civicrm_contact']}.id {$this->_limit}";

      $dao = CRM_Core_DAO::executeQuery($getContacts);

      while ($dao->fetch()) {
        $contactIds[] = $dao->cid;
      }
      $dao->free();
      $this->setPager();
    }

    if (!empty($contactIds) || CRM_Utils_Array::value('charts', $this->_params)) {
      if (CRM_Utils_Array::value('charts', $this->_params)) {
        $sql = "{$this->_select} {$this->_from} {$this->_where} {$this->_groupBy}";
      }
      else {
        $sql = "{$this->_select} {$this->_from} WHERE {$this->_aliases['civicrm_contact']}.id IN (" . implode(',', $contactIds) . ") AND {$this->_aliases['civicrm_pledge']}.is_test = 0 {$this->_statusClause} {$this->_groupBy} ";
      }

      $current_year = $this->_params['yid_value'];
      $upTo_year = $current_year - 4;

      $rows = $row = array();
      $this->addDeveloperTab($sql);
      $dao = CRM_Core_DAO::executeQuery($sql);
      $contributionSum = 0;
      while ($dao->fetch()) {
        if (!$dao->civicrm_pledge_contact_id) {
          continue;
        }
        $row = array();
        foreach ($this->_columnHeaders as $key => $value) {
          if (property_exists($dao, $key)) {
            $rows[$dao->civicrm_pledge_contact_id][$key] = $dao->$key;
          }
        }
        if ($dao->civicrm_pledge_start_date) {
          if ($dao->civicrm_pledge_start_date > $upTo_year) {
            $contributionSum += $dao->civicrm_pledge_amount;
            $rows[$dao->civicrm_pledge_contact_id][$dao->civicrm_pledge_start_date] = $dao->civicrm_pledge_amount;
          }
        }
        else {
          $rows[$dao->civicrm_pledge_contact_id]['civicrm_life_time_total'] = $dao->civicrm_pledge_amount;
          if (($dao->civicrm_pledge_amount - $contributionSum) > 0) {
            $rows[$dao->civicrm_pledge_contact_id]["civicrm_upto_{$upTo_year}"] = $dao->civicrm_pledge_amount - $contributionSum;
          }
          $contributionSum = 0;
        }
      }
      $dao->free();
    }
    // format result set.
    $this->formatDisplay($rows, FALSE);

    // assign variables to templates
    $this->doTemplateAssignment($rows);

    // do print / pdf / instance stuff if needed
    $this->endPostProcess($rows);
  }

  /**
   * @param $rows
   */
  function buildChart(&$rows) {
    $graphRows = array();
    $count = 0;
    $current_year = $this->_params['yid_value'];
    $previous_year = $current_year - 1;
    $previous_two_year = $current_year - 2;
    $previous_three_year = $current_year - 3;
    $upto = $current_year - 4;

    $interval[$previous_year] = $previous_year;
    $interval[$previous_two_year] = $previous_two_year;
    $interval[$previous_three_year] = $previous_three_year;
    $interval["upto_{$upto}"] = "Up To {$upto}";

    foreach ($rows as $key => $row) {
      $display["upto_{$upto}"] = CRM_Utils_Array::value("upto_{$upto}", $display) + CRM_Utils_Array::value("civicrm_upto_{$upto}", $row);
      $display[$previous_year] = CRM_Utils_Array::value($previous_year, $display) + CRM_Utils_Array::value($previous_year, $row);
      $display[$previous_two_year] = CRM_Utils_Array::value($previous_two_year, $display) + CRM_Utils_Array::value($previous_two_year, $row);
      $display[$previous_three_year] = CRM_Utils_Array::value($previous_three_year, $display) + CRM_Utils_Array::value($previous_three_year, $row);
    }

    $graphRows['value'] = $display;
    $config = CRM_Core_Config::Singleton();
    $chartInfo = array(
      'legend' => 'Sybunt Report',
      'xname' => 'Year',
      'yname' => "Amount ({$config->defaultCurrency})"
    );
    if ($this->_params['charts']) {
      // build the chart.
      require_once 'CRM/Utils/OpenFlashChart.php';
      CRM_Utils_OpenFlashChart::reportChart($graphRows, $this->_params['charts'], $interval, $chartInfo);
      $this->assign('chartType', $this->_params['charts']);
    }
  }

  /**
   * @param $rows
   */
  function alterDisplay(&$rows) {
    foreach ($rows as $rowNum => $row) {
      //Convert Display name into link
      if (array_key_exists('civicrm_contact_display_name', $row) && array_key_exists('civicrm_pledge_contact_id', $row)) {
        $url = CRM_Utils_System::url("civicrm/contact/view", 'reset=1&cid=' . $row['civicrm_pledge_contact_id'], $this->_absoluteUrl);
        $rows[$rowNum]['civicrm_contact_display_name_link'] = $url;
        $rows[$rowNum]['civicrm_contact_display_name_hover'] = ts("View Contribution Details for this Contact.");
      }
    }
  }
}
