<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Four column mail template'),
  'category' => t('Mail templates'),
  'icon' => 'fourcol.png',
  'theme' => 'panels_fourcol_mailtemplate',
  'css' => 'fourcol.css',
  'regions' => array(
    'left' => t('Left column'),
    'middle_left' => t('Middle left column'),
    'middle_right' => t('Middle right column'),
    'right' => t('Right column'),
  ),
);
