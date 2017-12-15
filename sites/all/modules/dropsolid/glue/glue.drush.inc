<?php

/**
 * Implements hook_drush_command().
 */
function glue_drush_command() {
  $items = array();  
  $items['glue-migrate'] = array(
    'description' => 'Migrate the content',
    'bootstrap' => 'DRUSH_BOOTSTRAP_DRUPAL_FULL',
    'callback' => 'drush_glue_migrate',
  );
  $items['glue-post-install'] = array(
    'description' => 'Migrate the content',
    'bootstrap' => 'DRUSH_BOOTSTRAP_DRUPAL_FULL',
    'callback' => 'drush_glue_postinstall',
  );
  $items['glue-check-state'] = array(
    'description' => 'Check feature state',
    'bootstrap' => 'DRUSH_BOOTSTRAP_DRUPAL_FULL',
    'callback' => 'drush_glue_check_state',
  );
  //This depends on the search api module it call the cron which adds all items to the queue, the next function processes it concurrently
  $items['search-api-add-to-queue'] = array(
    'description' => 'Fetch all items to be indexed, and add them to the queue.',
    'bootstrap' => 'DRUSH_BOOTSTRAP_DRUPAL_FULL',
    'callback' => 'search_api_cron',
    'aliases' => array('sapi-aq'),
  );
  //This thing can run a queue with concurrent processes > mainly used to process apache solr indexing > makes it faster #688
  $items['queue-run-concurrent'] = array(
    'description' => 'Run a specific queue by name',
    'arguments' => array(
      'queue_name' => 'The name of the queue to run, as defined in either hook_queue_info or hook_cron_queue_info.',
      'concurrency level' => 'The amount of background processes to spin-off'
    ),
    'required-arguments' => TRUE,
  );
  return $items;
}

/**
 *  Creates a queue that can process items during installation
 *  Queue is created in the beginning and is terminated at the very end.
 */
function drush_glue_queue() {
  $queue = DrupalQueue::get('glue_jobs');
  $queue->createQueue();
  $kill = FALSE;
  while ($kill == FALSE) {
    $item = $queue->claimItem();
    if (!$item) {
      sleep(1);
    }
    elseif ($item->data->function == 'kill') {
      $kill = TRUE;
      $queue->deleteItem($item);
    }
    else {
      try {
        $job = call_user_func_array($item->data->function, $item->data->arguments);
      } 
      catch (Exception $e) {
        watchdog('glue_jobs', 'An error occured:' . $e->getMessage());
      }
      if (isset($item->returnstatus)) {
        if ($job != $item->returnstatus) {
          watchdog('glue_jobs', 'An error occured while processing ' . $item->data->function);
        }
      }
      $queue->deleteItem($item);
    }
  }
}

/**
 * Use this to migrate content
 */
function drush_glue_migrate() {
  //Call your content function that migrates content
  glue_import_content();
}

/**
 * This is the post installer
 */
function drush_glue_postinstall() {
  glue_post_install();
}

/**
 * Checks the state of features
 */
function drush_glue_check_state() {
  module_load_include('inc', 'features', 'features.export');
  $all_is_fine = TRUE;
  foreach (features_get_features(NULL, TRUE) as $k => $m) {
    switch (features_get_storage($m->name)) {
      case FEATURES_OVERRIDDEN:
        $all_is_fine = FALSE;
        drush_log(t('Feature %name is in the OVERRIDDEN state', array('%name' => $m->name)), 'warning');
        break;
      case FEATURES_NEEDS_REVIEW:
        $all_is_fine = FALSE;
        drush_log(t('Feature %name is in the NEEDS REVIEW state', array('%name' => $m->name)), 'warning');
        break;
    }
  }
  if ($all_is_fine == TRUE) {
    drush_log(t('All features are in the default state, well done!'), 'ok');
  }
}

/**
 * Command callback for drush queue-run-concurrent.
 *
 * Queue runner that is compatible with queues declared using both
 * hook_queue_info() and hook_cron_queue_info().
 *
 * @param $queue_name
 *   Arbitrary string. The name of the queue to work with.
 * @param $concurrency_level
 *   Amount of background
 */
function drush_glue_queue_run_concurrent($queue_name, $concurrency_level) {
  // Get all queues.
  $queues = drush_queue_get_queues();
  if (isset($queues[$queue_name])) {
    $queue = DrupalQueue::get($queue_name);
    $invocations = array();
    for ($i = 0; $queue->numberOfItems() > $i; $i++) {
      $invocations[] = array('command' => 'queue-run ' . $queue_name, 'site' => '@self');
    }
    $common_options = array(
      'concurrency' => $concurrency_level,
    );
    
    if (!empty($invocations)) {
      drush_print_r("indexing " . $queue->numberOfItems() . " items");
      drush_backend_invoke_concurrent($invocations, array(), $common_options);
    }
    else {
      drush_print_r("No items to index");
    }
  }
}
