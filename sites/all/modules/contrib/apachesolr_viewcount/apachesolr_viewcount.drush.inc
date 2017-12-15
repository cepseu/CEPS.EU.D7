<?php

/**
 * @file
 *   drush integration for apachesolr view count module.
 */

/**
 * Implements of hook_drush_command().
 */
function apachesolr_viewcount_drush_command() {
  $items = array();
  $items['initiate-solr-count'] = array(
    'description' => 'Insert node view count in the solr_node_view_count table first time',
    'callback' => 'drush_initiate_node_view_count',
  );
  $items['update-solr-count'] = array(
    'description' => 'Update node view count in the solr_node_view_count table and mark node for reindexing',
    'callback' => 'drush_update_node_view_count',
  );
  return $items;
}

/**
 * Drush command to insert values to solr_node_view_count table for the first time alone.
 */
function drush_initiate_node_view_count() {
  $module_name = variable_get('apachesolr_viewcount_count_module');
  if ($module_name == 'statistics') {
    $nids = db_query("SELECT nid from {node_counter} nc
            JOIN {apachesolr_index_entities_node} aien ON nc.nid = aien.entity_id")->fetchCol();
  }
  else {
    $nids = db_query("SELECT DISTINCT(nid) from {nodeviewcount} nvc
            JOIN {apachesolr_index_entities_node} aien ON nvc.nid = aien.entity_id")->fetchCol();
  }
  $query = db_insert('solr_node_view_count')->fields(array('nid', 'is_solr_indexed'));
  foreach ($nids as $nid) {
    $query->values(array(
     'nid' => $nid,
     'is_solr_indexed' => 0,
    ));
  }
  if (isset($query)) {
    $query->execute();
  }
  // Set the time when the insertion is completed.
  variable_set('node_count_time', REQUEST_TIME);
}

/**
 * Drush command to update solr_node_view_count table when there are new views or new nodes created.
 * Then mark the node for reindexing to apache solr accordingly.
 */
function drush_update_node_view_count() {
  // Get the time when insertion/updation was complete.
  $time = variable_get('node_count_time', REQUEST_TIME);
  $module_name = variable_get('apachesolr_viewcount_count_module');
  // Find nid of nodes that were viewed after insertion/updation.
  if ($module_name == 'statistics') {
    $nids = db_query("SELECT nid from {node_counter} nc
            JOIN {apachesolr_index_entities_node} aien ON nc.nid = aien.entity_id
            WHERE nc.timestamp >= :time", array(':time' => $time))->fetchCol();
  }
  else {
    $nids = db_query("SELECT DISTINCT(nid) from {nodeviewcount} nvc
            JOIN {apachesolr_index_entities_node} aien ON nvc.nid = aien.entity_id
            WHERE nvc.timestamp >= :time", array(':time' => $time))->fetchCol();
  }
  foreach ($nids as $nid) {
    $query = db_merge('solr_node_view_count')->key(array('nid' => $nid));
    $query->fields(array(
     'nid' => $nid,
     'is_solr_indexed' => 0,
    ));
    $query->execute();
  }
  // Set the time when the updation is completed.
  variable_set('node_count_time', REQUEST_TIME);
  // Find the nids to be marked for reindexing by using is_solr_indexed field value.
  $to_reindex = db_query("SELECT nid from {solr_node_view_count}
                WHERE is_solr_indexed = :value", array(':value' => 0))->fetchCol();
  foreach ($to_reindex as $nid) {
    // Mark nid to be reindexed.
    apachesolr_mark_entity('node', $nid);
    $query = db_merge('solr_node_view_count')->key(array('nid' => $nid));
    $query->fields(array(
      'is_solr_indexed' => 1,
    ));
    $query->execute();
  }
}
