<?php
/**
 * Define the plugin.
 */
$plugin = array(
  'title'           => t('Link to all topics pane'),
  'category'        => array(t('WK')),
  'render callback' => 'all_topics_link_pane_content_type_render'
);

/**
 * Render function for the pane.
 */
function all_topics_link_pane_content_type_render($subtype, $conf, $panel_args, &$contexts) {
  $block = new stdClass();
  $block->content = l(t('View all topics'), 'topics');

  return $block;
}
