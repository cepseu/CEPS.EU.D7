<?php

/*
 * $Id$
 *
 * Copyright 2012 Sasha Gerrand
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * 	http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * Covers administrative interface hook functions.
 *
 * @author Sasha Gerrand <drupal.org-module-google_tag_manager@sgerrand.com>
 * @version $Id$
 * @package google_tag_manager
 */

/**
 * Implements hook_admin_settings() for module settings configuration.
 * @param array $form_state
 */
function google_tag_manager_admin_settings_form($form_state) {
	$form['account'] = array(
		'#title' => t('General settings'),
		'#type' => 'fieldset',
	);

	$form['account']['google_tag_manager_account'] = array(
		'#default_value' => variable_get('google_tag_manager_account', 'GTM-'),
		'#description' => t('This ID is unique to each account.'),
		'#maxlength' => 20,
		'#required' => TRUE,
		'#size' => 15,
		'#title' => t('Container ID'),
		'#type' => 'textfield',
	);

	return system_settings_form($form);
}

/**
 * Implements hook_form_validate().
 * @param array $form
 * @param array $form_state
 */
function google_tag_manager_admin_settings_form_validate($form, &$form_state) {
	// First, clean the input variables
	$form_state['values']['google_tag_manager_account'] = trim($form_state['values']['google_tag_manager_account']);

	if (!preg_match('/^GTM-\w+$/', $form_state['values']['google_tag_manager_account'])) {
		form_set_error('google_tag_manager_account', t('A valid Google Tag Manager container ID is case sensitive and is formatted like GTM-XXXX'));
	}
}

// vim: set filetype=php expandtab tabstop=2 shiftwidth=2 autoindent smartindent:
