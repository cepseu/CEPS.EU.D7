<?php
/**
 * Settings metadata file.
 */

return array(
  'sparkpost_apiKey' => array(
    'group_name' => CRM_Sparkpost::SPARKPOST_EXTENSION_SETTINGS,
    'group' => 'com.cividesk.email.sparkpost',
    'name' => 'sparkpost_apiKey',
    'type' => 'String',
    'html_type' => 'password',
    'default' => null,
    'add' => '4.4',
    'is_domain' => 1,
    'is_contact' => 0,
    'description' => 'SparkPost REST API key',
    'help_text' => 'You can create API keys at: https://app.sparkpost.com/account/credentials',
  ),
  'sparkpost_useBackupMailer' => array(
    'group_name' => CRM_Sparkpost::SPARKPOST_EXTENSION_SETTINGS,
    'group' => 'com.cividesk.email.sparkpost',
    'name' => 'sparkpost_useBackupMailer',
    'type' => 'Boolean',
    'html_type' => 'radio',
    'default' => FALSE,
    'add' => '4.4',
    'is_domain' => 1,
    'is_contact' => 0,
    'description' => 'Use backup mailer?',
    'help_text' => 'The backup mailer will be used if Sparkpost cannot send emails (unverified sending domain, sending limits exceeded, ...).',
  ),
);
