<?php
/**
 * @file
 * ceps_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ceps_search_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_existing_search_pages_panel_context';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'existing_search_pages';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Advanced search page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'simple_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'banner' => NULL,
      'main' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b59c9ee8-7b21-4f00-bbef-5c443fcbfff5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a5110577-e407-436a-aff9-f50e4ff9bf9f';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'views-f4291f1b3867b84a863bbec6aa9deedf';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 0,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a5110577-e407-436a-aff9-f50e4ff9bf9f';
    $display->content['new-a5110577-e407-436a-aff9-f50e4ff9bf9f'] = $pane;
    $display->panels['main'][0] = 'new-a5110577-e407-436a-aff9-f50e4ff9bf9f';
    $pane = new stdClass();
    $pane->pid = 'new-32111cd5-bebe-4f8e-8054-ab0027fd823f';
    $pane->panel = 'main';
    $pane->type = 'views';
    $pane->subtype = 'solr_search';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => 'search',
      'display' => 'search_advanced_page',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '32111cd5-bebe-4f8e-8054-ab0027fd823f';
    $display->content['new-32111cd5-bebe-4f8e-8054-ab0027fd823f'] = $pane;
    $display->panels['main'][1] = 'new-32111cd5-bebe-4f8e-8054-ab0027fd823f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a5110577-e407-436a-aff9-f50e4ff9bf9f';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_existing_search_pages_panel_context'] = $handler;

  return $export;
}
