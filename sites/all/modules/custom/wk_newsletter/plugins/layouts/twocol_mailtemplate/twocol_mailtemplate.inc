<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Two column mail template'),
  'category' => t('Mail templates'),
  'icon' => 'twocol.png',
  'theme' => 'panels_twocol_mailtemplate',
  'css' => 'twocol.css',
  'regions' => array(
    'left' => t('Left column'),
    'right' => t('Right column'),
  ),
);
