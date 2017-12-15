<?php
      $db_name = 'db_drupal_ceps';
      $db_user = 'u_dru_ceps';
      $db_pass = 'NyOn33dhUYvZEHeh';
      $db_host = 'localhost';

      $databases = array (
        'default' =>
        array (
          'default' =>
          array (
            'database' => $db_name,
            'username' => $db_user,
            'password' => $db_pass,
            'host' => $db_host,
            'port' => '',
            'driver' => 'mysql',
            'prefix' => '',
          ),
        ),
      );

$databases['default']['default']['prefix']= array(
  'default' => '',
  'civicrm_acl'                              => '`db_civi_ceps`.',
  'civicrm_acl_cache'                        => '`db_civi_ceps`.',
  'civicrm_acl_contact_cache'                => '`db_civi_ceps`.',
  'civicrm_acl_entity_role'                  => '`db_civi_ceps`.',
  'civicrm_action_log'                       => '`db_civi_ceps`.',
  'civicrm_action_mapping'                   => '`db_civi_ceps`.',
  'civicrm_action_schedule'                  => '`db_civi_ceps`.',
  'civicrm_activity'                         => '`db_civi_ceps`.',
  'civicrm_activity_contact'                 => '`db_civi_ceps`.',
  'civicrm_address'                          => '`db_civi_ceps`.',
  'civicrm_address_format'                   => '`db_civi_ceps`.',
  'civicrm_batch'                            => '`db_civi_ceps`.',
  'civicrm_cache'                            => '`db_civi_ceps`.',
  'civicrm_campaign'                         => '`db_civi_ceps`.',
  'civicrm_campaign_group'                   => '`db_civi_ceps`.',
  'civicrm_case'                             => '`db_civi_ceps`.',
  'civicrm_case_activity'                    => '`db_civi_ceps`.',
  'civicrm_case_contact'                     => '`db_civi_ceps`.',
  'civicrm_component'                        => '`db_civi_ceps`.',
  'civicrm_contact'                          => '`db_civi_ceps`.',
  'civicrm_contact_type'                     => '`db_civi_ceps`.',
  'civicrm_contribution'                     => '`db_civi_ceps`.',
  'civicrm_contribution_page'                => '`db_civi_ceps`.',
  'civicrm_contribution_product'             => '`db_civi_ceps`.',
  'civicrm_contribution_recur'               => '`db_civi_ceps`.',
  'civicrm_contribution_soft'                => '`db_civi_ceps`.',
  'civicrm_contribution_widget'              => '`db_civi_ceps`.',
  'civicrm_country'                          => '`db_civi_ceps`.',
  'civicrm_county'                           => '`db_civi_ceps`.',
  'civicrm_currency'                         => '`db_civi_ceps`.',
  'civicrm_custom_field'                     => '`db_civi_ceps`.',
  'civicrm_custom_group'                     => '`db_civi_ceps`.',
  'civicrm_dashboard'                        => '`db_civi_ceps`.',
  'civicrm_dashboard_contact'                => '`db_civi_ceps`.',
  'civicrm_dedupe_exception'                 => '`db_civi_ceps`.',
  'civicrm_dedupe_rule'                      => '`db_civi_ceps`.',
  'civicrm_dedupe_rule_group'                => '`db_civi_ceps`.',
  'civicrm_discount'                         => '`db_civi_ceps`.',
  'civicrm_domain'                           => '`db_civi_ceps`.',
  'civicrm_email'                            => '`db_civi_ceps`.',
  'civicrm_entity_batch'                     => '`db_civi_ceps`.',
  'civicrm_entity_file'                      => '`db_civi_ceps`.',
  'civicrm_entity_financial_account'         => '`db_civi_ceps`.',
  'civicrm_entity_financial_trxn'            => '`db_civi_ceps`.',
  'civicrm_entity_tag'                       => '`db_civi_ceps`.',
  'civicrm_event'                            => '`db_civi_ceps`.',
  'civicrm_event_carts'                      => '`db_civi_ceps`.',
  'civicrm_events_in_carts'                  => '`db_civi_ceps`.',
  'civicrm_extension'                        => '`db_civi_ceps`.',
  'civicrm_file'                             => '`db_civi_ceps`.',
  'civicrm_financial_account'                => '`db_civi_ceps`.',
  'civicrm_financial_item'                   => '`db_civi_ceps`.',
  'civicrm_financial_trxn'                   => '`db_civi_ceps`.',
  'civicrm_financial_type'                   => '`db_civi_ceps`.',
  'civicrm_grant'                            => '`db_civi_ceps`.',
  'civicrm_group'                            => '`db_civi_ceps`.',
  'civicrm_group_contact'                    => '`db_civi_ceps`.',
  'civicrm_group_contact_cache'              => '`db_civi_ceps`.',
  'civicrm_group_nesting'                    => '`db_civi_ceps`.',
  'civicrm_group_organization'               => '`db_civi_ceps`.',
  'civicrm_im'                               => '`db_civi_ceps`.',
  'civicrm_job'                              => '`db_civi_ceps`.',
  'civicrm_job_log'                          => '`db_civi_ceps`.',
  'civicrm_line_item'                        => '`db_civi_ceps`.',
  'civicrm_loc_block'                        => '`db_civi_ceps`.',
  'civicrm_location_type'                    => '`db_civi_ceps`.',
  'civicrm_log'                              => '`db_civi_ceps`.',
  'civicrm_mail_settings'                    => '`db_civi_ceps`.',
  'civicrm_mailing'                          => '`db_civi_ceps`.',
  'civicrm_mailing_bounce_pattern'           => '`db_civi_ceps`.',
  'civicrm_mailing_bounce_type'              => '`db_civi_ceps`.',
  'civicrm_mailing_component'                => '`db_civi_ceps`.',
  'civicrm_mailing_event_bounce'             => '`db_civi_ceps`.',
  'civicrm_mailing_event_confirm'            => '`db_civi_ceps`.',
  'civicrm_mailing_event_delivered'          => '`db_civi_ceps`.',
  'civicrm_mailing_event_forward'            => '`db_civi_ceps`.',
  'civicrm_mailing_event_opened'             => '`db_civi_ceps`.',
  'civicrm_mailing_event_queue'              => '`db_civi_ceps`.',
  'civicrm_mailing_event_reply'              => '`db_civi_ceps`.',
  'civicrm_mailing_event_subscribe'          => '`db_civi_ceps`.',
  'civicrm_mailing_event_trackable_url_open' => '`db_civi_ceps`.',
  'civicrm_mailing_event_unsubscribe'        => '`db_civi_ceps`.',
  'civicrm_mailing_group'                    => '`db_civi_ceps`.',
  'civicrm_mailing_job'                      => '`db_civi_ceps`.',
  'civicrm_mailing_recipients'               => '`db_civi_ceps`.',
  'civicrm_mailing_spool'                    => '`db_civi_ceps`.',
  'civicrm_mailing_trackable_url'            => '`db_civi_ceps`.',
  'civicrm_managed'                          => '`db_civi_ceps`.',
  'civicrm_mandrill_activity'                => '`db_civi_ceps`.',
  'civicrm_mapping'                          => '`db_civi_ceps`.',
  'civicrm_mapping_field'                    => '`db_civi_ceps`.',
  'civicrm_membership'                       => '`db_civi_ceps`.',
  'civicrm_membership_block'                 => '`db_civi_ceps`.',
  'civicrm_membership_log'                   => '`db_civi_ceps`.',
  'civicrm_membership_payment'               => '`db_civi_ceps`.',
  'civicrm_membership_status'                => '`db_civi_ceps`.',
  'civicrm_membership_type'                  => '`db_civi_ceps`.',
  'civicrm_menu'                             => '`db_civi_ceps`.',
  'civicrm_navigation'                       => '`db_civi_ceps`.',
  'civicrm_note'                             => '`db_civi_ceps`.',
  'civicrm_openid'                           => '`db_civi_ceps`.',
  'civicrm_option_group'                     => '`db_civi_ceps`.',
  'civicrm_option_value'                     => '`db_civi_ceps`.',
  'civicrm_participant'                      => '`db_civi_ceps`.',
  'civicrm_participant_payment'              => '`db_civi_ceps`.',
  'civicrm_participant_status_type'          => '`db_civi_ceps`.',
  'civicrm_payment_processor'                => '`db_civi_ceps`.',
  'civicrm_payment_processor_type'           => '`db_civi_ceps`.',
  'civicrm_pcp'                              => '`db_civi_ceps`.',
  'civicrm_pcp_block'                        => '`db_civi_ceps`.',
  'civicrm_persistent'                       => '`db_civi_ceps`.',
  'civicrm_phone'                            => '`db_civi_ceps`.',
  'civicrm_pledge'                           => '`db_civi_ceps`.',
  'civicrm_pledge_block'                     => '`db_civi_ceps`.',
  'civicrm_pledge_payment'                   => '`db_civi_ceps`.',
  'civicrm_preferences_date'                 => '`db_civi_ceps`.',
  'civicrm_premiums'                         => '`db_civi_ceps`.',
  'civicrm_premiums_product'                 => '`db_civi_ceps`.',
  'civicrm_prevnext_cache'                   => '`db_civi_ceps`.',
  'civicrm_price_field'                      => '`db_civi_ceps`.',
  'civicrm_price_field_value'                => '`db_civi_ceps`.',
  'civicrm_price_set'                        => '`db_civi_ceps`.',
  'civicrm_price_set_entity'                 => '`db_civi_ceps`.',
  'civicrm_print_label'                      => '`db_civi_ceps`.',
  'civicrm_product'                          => '`db_civi_ceps`.',
  'civicrm_queue_item'                       => '`db_civi_ceps`.',
  'civicrm_relationship'                     => '`db_civi_ceps`.',
  'civicrm_relationship_type'                => '`db_civi_ceps`.',
  'civicrm_report_instance'                  => '`db_civi_ceps`.',
  'civicrm_saved_search'                     => '`db_civi_ceps`.',
  'civicrm_setting'                          => '`db_civi_ceps`.',
  'civicrm_sms_provider'                     => '`db_civi_ceps`.',
  'civicrm_state_province'                   => '`db_civi_ceps`.',
  'civicrm_subscription_history'             => '`db_civi_ceps`.',
  'civicrm_survey'                           => '`db_civi_ceps`.',
  'civicrm_tag'                              => '`db_civi_ceps`.',
  'civicrm_tell_friend'                      => '`db_civi_ceps`.',
  'civicrm_timezone'                         => '`db_civi_ceps`.',
  'civicrm_uf_field'                         => '`db_civi_ceps`.',
  'civicrm_uf_group'                         => '`db_civi_ceps`.',
  'civicrm_uf_join'                          => '`db_civi_ceps`.',
  'civicrm_uf_match'                         => '`db_civi_ceps`.',
  'civicrm_value_ac2014_8'                   => '`db_civi_ceps`.',
  'civicrm_value_ac2015_14'                  => '`db_civi_ceps`.',
  'civicrm_value_company_info_4'             => '`db_civi_ceps`.',
  'civicrm_value_dietary_preferences_9'      => '`db_civi_ceps`.',
  'civicrm_value_event_info_5'               => '`db_civi_ceps`.',
  'civicrm_value_il2016_16'                  => '`db_civi_ceps`.',
  'civicrm_value_individual_info_2'          => '`db_civi_ceps`.',
  'civicrm_value_neujobs_final_conference3_13' => '`db_civi_ceps`.',
  'civicrm_value_newsletters_15'             => '`db_civi_ceps`.',
  'civicrm_value_other_1'                    => '`db_civi_ceps`.',
  'civicrm_value_publications_3'             => '`db_civi_ceps`.',
  'civicrm_value_research_areas_6'           => '`db_civi_ceps`.',
  'civicrm_value_ubercart_purchases_7'       => '`db_civi_ceps`.',
  'civicrm_website'                          => '`db_civi_ceps`.',
  'civicrm_word_replacement'                 => '`db_civi_ceps`.',
  'civicrm_worldregion'                      => '`db_civi_ceps`.',
);

      $update_free_access = FALSE;
      $drupal_hash_salt = 'Wuc3CPLHTfTHGXLIzmW7Hn8iS-ErWaJlJOL2nhed2xI';

      $base_url = 'https://www.ceps.eu';  // NO trailing slash!

//     Force ssl responses
      $_SERVER['HTTPS'] = 'on';

      ini_set('session.gc_probability', 1);
      ini_set('session.gc_divisor', 100);
      ini_set('session.gc_maxlifetime', 200000);
      ini_set('session.cookie_lifetime', 2000000);

      $conf['404_fast_paths_exclude'] = '/\/(?:styles)\//';
      $conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
      $conf['404_fast_html'] = '<html xmlns=http://www.w3.org/1999/xhtml><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL @path was not found on this server.</p></body></html>';
      $conf['dropsolid_env'] = 'live';

      /**
       * Varnish
       */
      $conf['varnish_flush_cron'] = 0;
      $conf['varnish_version'] = '4';
      $conf['varnish_control_terminal'] = '127.0.0.1:6082';
      $conf['varnish_control_key'] = 'c98ecdbc-a33b-421d-bba1-6e0d3f5c708c';
      $conf['varnish_socket_timeout'] = '250';
      $conf['varnish_cache_clear'] = 1;//Drupal default will clear all page caches on node updates and cache flush events. None will allow pages to persist for their full max-age
      $conf['varnish_bantype'] = 0;
      $conf['cache_backends'][] = 'sites/all/modules/contrib/varnish/varnish.cache.inc';
      $conf['cache_class_cache_page'] = 'VarnishCache';
      // Jan added params - Varnish sits idle if params not set here ....
      $conf['cache'] = 1;
//      $conf['cache_lifetime'] = 86400;
//      $conf['page_cache_maximum_age'] = 86400;

      // Drupal 7 does not cache pages when we invoke hooks during bootstrap. This needs
      // to be disabled.
      $conf['page_cache_invoke_hooks'] = FALSE;

     /**
      * Memcache - Disabled because it slows down Varnish
     $conf['cache_backends'][] = './sites/all/modules/contrib/memcache/memcache.inc';
     $conf['cache_default_class'] = 'MemCacheDrupal';
     $conf['cache_class_cache_form'] = 'DrupalDatabaseCache';
     $conf['memcache_key_prefix'] = 'ceps';
      */

     /**
      * Solr
      */
     $conf['dropsolid_host_solr'] = '127.0.0.1';
     $conf['dropsolid_port_solr'] = '8983';
     $conf['dropsolid_path_solr'] = '/solr/ceps';


     /**
     * The site has an nginx to varnish revers proxy in front of it
     * Make Drupal aware of this to use correct forwarded ip
     */
     $conf['reverse_proxy'] = 1;
     $conf['reverse_proxy_addresses'] = array('127.0.0.1');
     $conf['reverse_proxy_header'] = 'HTTP_X_FORWARDED_FOR';
