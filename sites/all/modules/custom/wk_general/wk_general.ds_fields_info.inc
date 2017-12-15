<?php
/**
 * Implements hook_ds_fields_info().
 */
function wk_general_ds_fields_info($entity_type) {
  $fields = array();
  $file = drupal_get_path('module', 'wk_general') . '/includes/ds.inc';

  //options for author_profile_reference
  $entity_info = entity_get_info('node');
  $modes = $entity_info['view modes'];
  $options = array();
  foreach ($modes as $name => $mode) {
    $options[$name] = $mode['label'];
  }
  $fields['node']['author_profile_reference'] = array(
    'title' => t('Blog author Profile reference'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_author_profile_reference',
    'file' => $file,
    'properties' => array(
      'settings' => array(
        'node_reference_view_mode' => array('type' => 'select', 'options' => $options),
      ),
    ),
    'ui_limit' => array('blog_post|full'),
  );
  $fields['node']['book_author_profile_reference'] = array(
    'title' => t('Book author Profile reference'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_book_author_profile_reference',
    'file' => $file,
    'properties' => array(
      'settings' => array(
        'node_reference_view_mode' => array('type' => 'select', 'options' => $options),
      ),
    ),
    'ui_limit' => array('book|full'),
  );

  $fields['node']['profile_function_organisation'] = array(
    'title' => t('Function title, organisation'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_profile_function_organisation',
    'file' => $file,
  );

  $fields['node']['paypal'] = array(
    'title' => t('Paypal'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_paypal',
    'file' => $file,
  );

  $fields['node']['topic_box_color'] = array(
    'title' => t('Logo with Research Area Color'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_topic_box_color',
    'file' => $file,
    'ui_limit' => array('events|*', 'blog_post|*', 'book|*', 'project|*', 'network|*', 'task_force|*'),
  );

  $fields['node']['quote_date_media'] = array(
    'title' => t('Quote date, media'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_quote_date_media',
    'file' => $file,
    'ui_limit' => array('quote|*'),
  );
  $fields['node']['quote_researcher_media'] = array(
    'title' => t('Quote researcher, media'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_quote_researcher_media',
    'file' => $file,
    'ui_limit' => array('quote|*'),
  );

  $fields['node']['quote_researcher_linked_media'] = array(
    'title' => t('Quote researcher linked, media'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_quote_researcher_media_linked',
    'file' => $file,
    'ui_limit' => array('quote|*'),
  );


  $fields['node']['publication_downloads'] = array(
    'title' => t('Publication downloads'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_publication_downloads',
    'file' => $file,
    'ui_limit' => array('book|full'),
  );
//
  $fields['taxonomy_term']['view_all_topics'] = array(
    'title' => t('View all topics'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_view_all_topics',
    'file' => $file,
    'ui_limit' => array('topics|detailed'),
  );


  $fields['node']['publication_embedded_list'] = array(
    'title' => t('Publication embedded list'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_all_publication_date_authors',
    'file' => $file,
    'ui_limit' => array('book|embedded_list'),
  );


  $fields['node']['topics_link'] = array(
    'title' => t('Link to topics landingspage'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_topics_link',
    'file' => $file,
    'ui_limit' => array('newsletter|full', 'newsletter_weekly|full'),
  );

  $fields['node']['events_link'] = array(
    'title' => t('Link to events landingspage'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_events_link',
    'file' => $file,
    'ui_limit' => array('newsletter|full', 'newsletter_weekly|full'),
  );

  $fields['node']['registration_link'] = array(
    'title' => t('Link to events registration'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_registration_link',
    'file' => $file,
    'ui_limit' => array('events|*'),
  );

  $fields['node']['pricing_link'] = array(
    'title' => t('Link to pricing information'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_pricing_link',
    'file' => $file,
    'ui_limit' => array('events|full'),
  );

  $fields ['node']['see_all_link_lunch'] = array(
    'title' => ('See all link lunch'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_see_all',
    'ui_limit' => array('newsletter_weekly|full'),
  );
  $fields ['node']['see_all_link_conferences'] = array(
    'title' => ('See all link conferences'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_see_all',
    'ui_limit' => array('newsletter_weekly|full'),
  );

  $fields['node']['explore_more_link'] = array(
    'title' => t('More to explore link'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_explore_more_link',
    'file' => $file,
    'ui_limit' => array('newsletter|full', 'newsletter_weekly|full'),
  );

  $fields['node']['research_areas_link'] = array(
    'title' => t('Research areas link'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_research_areas_link',
    'file' => $file,
    'ui_limit' => array('newsletter|full', 'newsletter_weekly|full'),
  );

  $fields['node']['all_topics_link'] = array(
    'title' => t('Explore all topics link'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_all_topics_link',
    'file' => $file,
    'ui_limit' => array('newsletter|full', 'newsletter_weekly|full'),
  );

  $fields['node']['contact_info'] = array(
    'title' => t('Contact info'),
    'field_type' => DS_FIELD_TYPE_BLOCK,
    'ui_limit' => array('newsletter|full', 'newsletter_weekly|full'),
    'properties' => array(
     'block' => 'wk_general|ceps_contact_info',
     'block_render' => DS_BLOCK_CONTENT,
    )
  );

  $fields['node']['social_links'] = array(
    'title' => t('Social media links'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'ui_limit' => array('newsletter|full', 'newsletter_weekly|full'),
    'function' => 'wk_general_newsletter_social_links',
    'file' => $file,
  );

  $fields['node']['newsletter_footer'] = array(
    'title' => t('Newsletter footer'),
    'field_type' => DS_FIELD_TYPE_BLOCK,
    'ui_limit' => array('newsletter|full', 'newsletter_weekly|full'),
    'properties' => array(
     'block' => 'wk_general|ceps_newsletter_footer',
     'block_render' => DS_BLOCK_TEMPLATE,
    )
  );

  $fields['node']['copyright_footer'] = array(
    'title' => t('Copyright footer'),
    'field_type' => DS_FIELD_TYPE_BLOCK,
    'ui_limit' => array('newsletter|full', 'newsletter_weekly|full'),
    'properties' => array(
     'block' => 'wk_general|ceps_copyright_footer',
     'block_render' => DS_BLOCK_CONTENT,
    )
  );

  $fields['node']['newsletter_weekly_events'] = array(
    'title' => t('Newsletter weekly events'),
    'field_type' => DS_FIELD_TYPE_BLOCK,
    'ui_limit' => array('newsletter_weekly|full'),
    'properties' => array(
     'block' => 'views|events_weekly_newsletter-block',
     'block_render' => DS_BLOCK_TEMPLATE,
    )
  );

  $fields['node']['publications_weekly_events'] = array(
    'title' => t('Publications weekly events'),
    'field_type' => DS_FIELD_TYPE_BLOCK,
    'ui_limit' => array('newsletter_weekly|full'),
    'properties' => array(
     'block' => 'views|publications_weekly_newsletter-block',
     'block_render' => DS_BLOCK_TEMPLATE,
    )
  );

  $fields['node']['formatted_event_date'] = array(
    'title' => t('Formatted event date'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_formatted_event_date',
    'file' => $file,
    'ui_limit' => array('events|*'),
  );

  $fields['node']['formatted_event_date_mail'] = array(
    'title' => t('Formatted event date for e-mail'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_formatted_event_date_mail',
    'file' => $file,
    'ui_limit' => array('events|*'),
  );

  $fields['node']['newsletter_icon'] = array(
    'title' => t('Newsletter Icon'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_newsletter_icon',
    'file' => $file,
    'ui_limit' => array('article|*'),
  );

  $fields['taxonomy_term']['colored_element'] = array(
    'title' => t('Colored box'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_colored_element',
    'file' => $file,
    'ui_limit' => array('*|newsletter_mini'),
  );

  $fields['taxonomy_term']['contributors'] = array(
    'title' => t('Contributors'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_taxonomy_term_contributors',
    'file' => $file,
    'properties' => array(
      'settings' => array(
        'node_reference_view_mode' => array('type' => 'select', 'options' => $options),
      ),
    )
  );

  $fields['node']['newsletter_event_speakers'] = array(
    'title' => t('Newsletter Event Speakers'),
    'field_type' => DS_FIELD_TYPE_FUNCTION,
    'function' => 'wk_general_newsletter_event_speakers',
    'file' => $file,
    'ui_limit' => array('events|newsletter_mini'),
  );

  return $fields;
}

/**
 * Implements hook_ds_field_settings_form().
 */
function wk_general_ds_field_settings_form($field) {
  return ds_ds_field_settings_form($field);
}

/**
 * Implements hook_ds_field_format_summary().
 */
function wk_general_ds_field_format_summary($field) {
  return ds_ds_field_format_summary($field);
}
