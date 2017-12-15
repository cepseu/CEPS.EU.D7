<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Three column mail template'),
  'category' => t('Mail templates'),
  'icon' => 'threecol.png',
  'theme' => 'panels_threecol_mailtemplate',
  'css' => 'threecol.css',
  'regions' => array(
    'left' => t('Left column'),
    'middle' => t('Middle column'),
    'right' => t('Right column'),
  ),
);
