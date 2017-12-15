<?php

// Plugin definition
$plugin = array(
	'title'		=> t('Four column stacked'),
	'category'	=> t('Columns: 4'),
	'icon'		=> 'fourcol_stacked.png',
	'theme'		=> 'panels_fourcol_stacked',
	'css'		=> 'fourcol_stacked.css',
	'regions' => array(
		'top' => t('Top'),
		'left'		=> t('Left side'),
		'midleft'	=> t('Middle left'),
		'midright'	=> t('Middle right'),
		'right'		=> t('Right side'),
 		'bottom'	=> t('Bottom'),
	),
);
