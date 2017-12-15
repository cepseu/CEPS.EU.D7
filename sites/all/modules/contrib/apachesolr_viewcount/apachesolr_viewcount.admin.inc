<?php

/**
 * @file
 *   Administrative pages for the Apachesolr view count module.
 */

/*
 * View count settings form.
 */
function apachesolr_viewcount_page_form() {
  $count_module = '';
  if (module_exists('statistics') && module_exists('nodeviewcount')) {
    $count_module = '';
    $desc = t('Both modules are already enabled, you can use one among it.');
  }
  elseif (module_exists('statistics')) {
    $count_module = 'statistics';
    $desc = t('Statistics module is already enabled, so you can use it.');
  }
  elseif (module_exists('nodeviewcount')) {
    $count_module = 'nodeviewcount';
    $desc = t('Node view count module is already enabled, so you can use it.');
  }
  else {
    $count_module = '';
    $desc = t('Both modules are disabled. You can choose Statistics module option to enable and use it. To use Node view count module, you need to install/enable the module.');
  }
  $default_count_module = !empty(variable_get('apachesolr_viewcount_count_module')) ? variable_get('apachesolr_viewcount_count_module') : $count_module;
  $form['apachesolr_viewcount_count_module'] = array(
    '#type' => 'radios',
    '#title' => t('Select the module which should be used for fetching the node view count:'),
    '#options' => array(
      'statistics' => t('Statistics module'),
      'nodeviewcount' => t('Node view count module'),
    ),
    '#description' => check_plain($desc),
    '#default_value' => $default_count_module,
    '#required' => TRUE,
  );
  $form['apachesolr_viewcount_sorting'] = array(
    '#type' => 'radios',
    '#title' => t('Make the node view count field to be used as a sorting field?'),
    '#options' => array(
      'yes' => t('Yes'),
      'no' => t('No'),
    ),
    '#description' => t('Kindly install/enable Apache solr sort module.'),
    '#default_value' => !empty(variable_get('apachesolr_viewcount_sorting')) ? variable_get('apachesolr_viewcount_sorting') : 'no',
  );

  $form['#validate'][] = 'apachesolr_viewcount_page_form_validate';
  $form['#submit'][] = 'apachesolr_viewcount_page_form_submit';

  return system_settings_form($form);
}

/*
 * Custom validation handler for apachesolr_viewcount_page_form.
 */
function apachesolr_viewcount_page_form_validate($form, &$form_state) {
  // Throw an error when user sets make sorting 'yes' without enabling apachesolr_sort module
  if (isset($form_state['values']['apachesolr_viewcount_sorting']) && $form_state['values']['apachesolr_viewcount_sorting'] == 'yes') {
    if (!module_exists('apachesolr_sort')) {
      form_set_error('apachesolr_viewcount_sorting', t("Install/Enable Apache solr sort module to use node view count field for sorting."));
    }
  }
  // Throw an error when user selects nodeviewcount module without enabling the module
  if (isset($form_state['values']['apachesolr_viewcount_count_module']) && $form_state['values']['apachesolr_viewcount_count_module'] == 'nodeviewcount') {
    if (!module_exists($form_state['values']['apachesolr_viewcount_count_module'])) {
      form_set_error('apachesolr_viewcount_count_module', t("Install/Enable Node view count module to use it for fetching the count."));
    }
  }
}

/*
 * Custom submit handler for apachesolr_viewcount_page_form.
 */
function apachesolr_viewcount_page_form_submit($form, &$form_state) {
  // Enable Statistics module when user selects Statistics module in config page
  if (isset($form_state['values']['apachesolr_viewcount_count_module']) && !empty($form_state['values']['apachesolr_viewcount_count_module'])) {
    $module_name = $form_state['values']['apachesolr_viewcount_count_module'];
    if (!module_exists($module_name)) {
      module_enable(array($module_name));
      drupal_set_message(t("The %module has been enabled successfully.", array('%module' => $module_name, )));
    }
  }
}
