<?php
//render the referenced profile node.
function wk_general_author_profile_reference($field) {
  $entity = $field['entity'];
  $formatter_view_mode = $field['formatter_settings']['node_reference_view_mode'];

  $rendered_profile = wk_general_get_author_profile_reference($entity, 'field_author',$formatter_view_mode);

  return $rendered_profile;
}

//render the book author referenced profile node
function wk_general_book_author_profile_reference($field) {
  $entity = $field['entity'];
  $formatter_view_mode = $field['formatter_settings']['node_reference_view_mode'];

  $rendered_profile = wk_general_get_author_profile_reference($entity, 'field_book_authors',$formatter_view_mode);

  return $rendered_profile;
}

//render the function title and organisation on one line, comma seperated.
function wk_general_profile_function_organisation($field) {
  $entity = $field['entity'];
  $string_arr = array();
  $content = '';
  $entity_wrapper = entity_metadata_wrapper('node', $entity);
  if(isset($entity_wrapper->field_ceps_profile_id)){
    $profile = $entity_wrapper->field_ceps_profile_id->value();
    $profile_wrapper = entity_metadata_wrapper('node', $profile);
    $image = $profile_wrapper->field_head_photo->value();
    $settings = array(
      'style_name' => 'portrait_thumb',
      'path' => $image['uri'],
    );
    $content .= '<table width="100%">';
    $content .= '<tr>';
    $content .= '<td class="group-td1">';
    $content .= theme('image_style', $settings);
    $content .= '</td>';
    $content .= '<td class="group-td2">';
    $content .= '<div class="profile-title">' . $profile_wrapper->title->value() . '</div>';
    $content .= '<div class="profile-function">' . $profile_wrapper->field_head_title->value() . '</div>';
    $content .= '</td>';
    $content .= '</tr>';
    $content .= '</table>';
  }

  return $content;
}

// return topic in a div with color field as bg-color
function wk_general_topic_box_color(&$field) {
  $entity = $field['entity'];

  $color = '#030303';

  $fieldResearchArea = '';
  if ($entity->type == "book") {
    $fieldResearchArea = field_get_items('node', $entity, 'taxonomy_vocabulary_3');
  } else if ($entity->type == "blog_post") {
    $fieldResearchArea = field_get_items('node', $entity, 'field_research_area');
  } else if ($entity->type == "events") {
    $fieldResearchArea = field_get_items('node', $entity, 'taxonomy_vocabulary_3');
  }

  if (!empty($fieldResearchArea)) {

    $researchAreaID = $fieldResearchArea[0]['tid'];

    $researchArea = taxonomy_term_load($researchAreaID);
    $fieldResearchAreaColor = field_get_items('taxonomy_term', $researchArea, 'field_research_area_color');

    if (!empty ($fieldResearchAreaColor)) {
      $color = $fieldResearchAreaColor[0]['rgb'];
    }
  }

  return '<div class="topic-box-color" style="background-color: ' . $color . ';"></div>';
}

/**
 * render all the contributors which are profiles refered by authors which are
 * nodes refered by certain content types which refer this term... you dig ?
 */
function wk_general_taxonomy_term_contributors($field) {
  $entity = $field['entity'];
  $tid = $entity->tid;
  $formatter_view_mode = $field['formatter_settings']['node_reference_view_mode'];
  $profile_nids = array();

  $query = 'SELECT t.entity_id, a.field_author_nid, p.field_ceps_profile_id_nid from {field_data_field_topic} t';
  $query .= ' JOIN {field_data_field_author} a ON t.entity_id = a.entity_id';
  $query .= ' JOIN {field_data_field_ceps_profile_id} p ON a.field_author_nid = p.entity_id';
  $query .= ' WHERE t.field_topic_tid = :tid';
  $result = db_query($query, array(':tid' =>  $tid));

  foreach($result as $record){
    $profile_nids[] = $record->field_ceps_profile_id_nid;
  }

  if(empty($profile_nids)){
    return;
  }

  $profile_nodes = node_load_multiple($profile_nids);
  $rendered_profiles = node_view_multiple($profile_nodes, $formatter_view_mode);

//  return render($rendered_profiles);
    return;
}
//render the publication date and all the authors.
function wk_all_publication_date_authors($field) {
   $entity = $field['entity'];

         $string_arr = array();
         $author_arr = array();
         $entity_wrapper = entity_metadata_wrapper('node', $entity);

         if($entity_wrapper->field_book_publication_date->value()){
             $string_arr[] = format_date($entity_wrapper->field_book_publication_date->value(),'medium');
         }

         if($authors = $entity_wrapper->field_book_authors->value()){

             foreach($authors as $author){
                 $author_arr[] = $author->title;
             }

             $string_arr[] = implode(', ', $author_arr);
         }

         return implode(', by ', $string_arr);

}
//render the publication date and all the authors.
function wk_general_publication_date_author($field) {
  $entity = $field['entity'];
  $string_arr = array();
  $author_arr = array();
  $entity_wrapper = entity_metadata_wrapper('node', $entity);

  if($entity_wrapper->field_book_publication_date->value()){
    $string_arr[] = format_date($entity_wrapper->field_book_publication_date->value(),'medium');
  }

  if($authors = $entity_wrapper->field_book_authors->value()){

    foreach($authors as $author){
      $author_arr[] = $author->title;
    }

    $string_arr[] = implode(', ', $author_arr);
  }

  return implode(', by ', $string_arr);
}

//render the quote date and medium of appearance.
function wk_general_quote_date_media($field) {
  $entity = $field['entity'];
  $string_arr = array();
  $entity_wrapper = entity_metadata_wrapper('node', $entity);

  if($entity_wrapper->field_quotedate->value()){
    $string_arr[] = format_date($entity_wrapper->field_quotedate->value(),'medium');
  }

  if($entity_wrapper->field_quotenewspaper->value()){
    $string_arr[] = $entity_wrapper->field_quotenewspaper->value();
  }

  return implode(', in ', $string_arr);
}

//render the quote researcher and medium of appearance.
function wk_general_quote_researcher_media($field) {
  $entity = $field['entity'];
  $string_arr = array();
  $entity_wrapper = entity_metadata_wrapper('node', $entity);

  if($researcher = $entity_wrapper->field_quoteauthor->value()){
    $string_arr[] = check_plain($researcher->title);
  }

  if($entity_wrapper->field_quotenewspaper->value()){
    $string_arr[] = $entity_wrapper->field_quotenewspaper->value();
  }

  return implode(', in ', $string_arr);
}

//render the quote researcher linked to the it's page and medium of appearance.
function wk_general_quote_researcher_media_linked($field) {
  $entity = $field['entity'];
  $string_arr = array();
  $entity_wrapper = entity_metadata_wrapper('node', $entity);

  if($researcher = $entity_wrapper->field_quoteauthor->value()){
    $string_arr[] = l(check_plain($researcher->title),'node/' . $researcher->nid );
  }

  if($entity_wrapper->field_quotenewspaper->value()){
    $string_arr[] = $entity_wrapper->field_quotenewspaper->value();
  }

  return implode(', in ', $string_arr);
}

//render the downloads of a publication
function wk_general_publication_downloads($field) {
  $entity = $field['entity'];
  $entity_wrapper = entity_metadata_wrapper('node', $entity);
  $downloads = array();
  $links = array();
  $output = '';
  $outp = '';

  //pdf
  if($entity_wrapper->field_pub_pdf->value()){
    $pdf = $entity_wrapper->field_pub_pdf->value();
    $downloads['PDF'] = file_create_url($pdf['uri']);
//    $outp .= l(t('Download PDF'), $downloads['PDF']);
$outp .= '<a href="'.$downloads['PDF'].'">' . t('Download PDF') . '</a>';
  }
  //epub
  if($entity_wrapper->field_pub_epub->value()){
    $epub = $entity_wrapper->field_pub_epub->value();
    $downloads['EPUB'] = file_create_url($epub['uri']);
//    $outp .= t(' ') . l(t('EPUB'), $downloads['EPUB']);
$outp .= '<a href="'.$downloads['EPUB'].'">' . t('EPUB') . '</a>';
  }
  //mobi
  if($entity_wrapper->field_pub_mobi->value()){
    $mobi = $entity_wrapper->field_pub_mobi->value();
    $downloads['MOBI'] = file_create_url($mobi['uri']);
//    $outp .= t(' ') . l(t('MOBI'), $downloads['MOBI']);
$outp .= '<a href="'.$downloads['MOBI'].'">' . t('MOBI') . '</a>';
  }

  if(empty($downloads)){
    return;
  }

  if(count($downloads) > 1){
    foreach($downloads as $key => $download){
      $links[] = array(
        'title'  =>  t('Download @type', array('@type'  =>  $key)),
        'href'  =>  $download,
      );
    }
    //$output .= '<a href="#">' . t('Download publication') . '</a>';
    //$output .= theme('links', array('links'  =>  $links));
    $output .= $outp;
  }
  else{
    $output .= l(t('Download publication'), reset($downloads));
  }

  return $output;
}

function wk_general_view_all_topics($field){
  return l(t('View all topics'), 'topics');

}

/**
 * Generate a link to the topics landingspage.
 */
function wk_general_topics_link($field){
  return l(t('All topics →'), 'topics');
}

/**
 * Generate a link to the events landingspage.
 */
function wk_general_events_link($field){
  return l(t('All events →'), 'events', array(
    'attributes' => array(
      'style' => 'display: block;font-weight: normal;padding: 6px;text-align: center;text-decoration: none;text-transform: uppercase;border: 2px solid #496E5C;color: #666666;background-color: #f7f7f7;',
      ),
    ));
}

/**
 * Generate a link to the events registration with anchor to webform.
 */
function wk_general_registration_link($field){
  $entity = $field['entity'];
  $link = "node/" . $entity -> nid;
  $options = array(
    'fragment' => "register",
  );
  return l(t('Register'), $link, $options);
}

/**
 * Generate a link to Event overview page
 */
function wk_general_see_all($fields){
  $entity = $fields['entity'];
 if ($entity -> field_newsletter_events != null){
    return l(t('See all'), 'events');
  }
}

/**
 * Generate a link to the frontpage of the website.
 */
function wk_general_explore_more_link($field){
  return l(t('To explore more on our website'), '<front>');
}

/**
 * Generate a link to the research areas landingspage.
 */
function wk_general_research_areas_link($field){
  return l(t('Go to Research areas'), 'research-areas');
}

/**
 * Generate a link to the topics landingspage.
 */
function wk_general_all_topics_link($field){
  return l(t('All topics'), 'topics', array(
    'attributes' => array(
      'style' => 'display: block;font-weight: normal;padding: 6px;text-align: center;text-decoration: none;text-transform: uppercase;border: 2px solid #496E5C;color: #666666;background-color: #f7f7f7;',
      ),
    ));
}


/**
 * Generic function for author referenced profiles.
 */
function wk_general_get_author_profile_reference($entity, $author_field, $formatter_view_mode) {

  $entity_wrapper = entity_metadata_wrapper('node', $entity);
  $author_field_value = $entity_wrapper->{$author_field}->value();
  $rendered_profile = NULL;

  if(!$author_field_value){
    return;
  }

  if(is_array($author_field_value)){

    $profiles = NULL;

    foreach($author_field_value as $author){
      $author_field_wrapper = entity_metadata_wrapper('node', $author);
      $profile_field_value = $author_field_wrapper->field_ceps_profile_id->value();

      if(!$profile_field_value){

        $profiles .= render(node_view($author, $formatter_view_mode));

      }
      else {
        $profiles .= render(node_view($profile_field_value, $formatter_view_mode));
      }

}
    $rendered_profile = $profiles;
  }
  else{
    $author_field_wrapper = entity_metadata_wrapper('node', $author_field_value);
    $profile_field_value = $author_field_wrapper->field_ceps_profile_id->value();

    if(!$profile_field_value){
      return;
    }
    $rendered_profile = render(node_view($profile_field_value, $formatter_view_mode));
  }

  return $rendered_profile;
}

/**
 * Generic function for paypal button.
 */
function wk_general_paypal($field){
  $entity = $field['entity'];
  $price =  number_format($entity->sell_price, 2);
  $output = '';

  if($price != 0){
    $output .= '
      <span class="uc-price-label">Price:</span>
      <span class="uc-price">&euro; ' . $price . '</span>';

    $add_to_cart = array( '#theme' => 'uc_product_add_to_cart','#form' => drupal_get_form('uc_product_add_to_cart_form_' . $entity->nid, $entity), );
    $output .= drupal_render($add_to_cart);

  }
  return $output;
} 

function wk_general_formatted_event_date($field) {
  $entity = $field['entity'];
  $items = field_get_items('node', $entity, 'field_event1_date');
  $content = '';
  if ($items)  {

    $timestamp = strtotime($items[0]['value']);
    $end = strtotime($items[0]['value2']);
    $beginTime = format_date($timestamp, 'custom', 'H:i');
    $endTime = format_date($end, 'custom', 'H:i');
    $dayNumber = format_date($timestamp, 'custom', 'j');
    $month = format_date($timestamp, 'custom', 'F Y');
    $dayName = format_date($timestamp, 'custom', 'l');
    $content .= '<div class="formatted-date-wrapper clearfix">';
      $content .= '<div class="formatted-date-number">';
        $content .= $dayNumber;
      $content .= '</div>';
      $content .= '<div class="formatted-date-rest">';
        $content .= '<div class="formatted-date-month-year">';
          $content .= $month;
        $content .= '</div>';
        $content .= '<div class="formatted-date-day-name">';
          $content .= $dayName;
        $content .= '</div>';
      $content .= '</div>';
      $content .= '<div class="formatted-date-time">';
        $content .= '<span class="formatted-date-time-from">' . $beginTime . '</span>';
        $content .= '-';
        $content .= '<span class="formatted-date-time-to">' . $endTime . '</span>';
      $content .= '</div>';
    $content .= '</div>';
  }

  return $content;
}

function wk_general_formatted_event_date_mail($field) {
  $entity = $field['entity'];
  $items = field_get_items('node', $entity, 'field_event1_date');
  $content = '';
  if ($items) {
    $timestamp = strtotime($items[0]['value']);
    $end = strtotime($items[0]['value2']);
    $beginTime = format_date($timestamp, 'custom', 'H:i');
    $endTime = format_date($end, 'custom', 'H:i');
    $dayNumber = format_date($timestamp, 'custom', 'j');
    $month = format_date($timestamp, 'custom', 'F Y');
    $dayName = format_date($timestamp, 'custom', 'l');
    $content .= '<div class="formatted-date-wrapper clearfix">';
      $content .= '<table width="100%">';
        $content .= '<tr>';
          $content .= '<td class="formatted-date-number">';
            $content .= $dayNumber;
          $content .= '</td>';
          $content .= '<td width="100%" class="formatted-date-rest">';
            $content .= '<div class="formatted-date-month-year">';
              $content .= $month;
            $content .= '</div>';
            $content .= '<div>';
              $content .= '<span class="formatted-date-day-name">';
                $content .= $dayName;
              $content .= '</span> ';
              $content .= '<span class="formatted-date-time">';
                $content .= '<span class="formatted-date-time-from">' . $beginTime . '</span>';
                $content .= ' - ';
                $content .= '<span class="formatted-date-time-to">' . $endTime . '</span>';
              $content .= '</span>';
            $content .= '</div>';
          $content .= '</td>';
        $content .= '</tr>';
      $content .= '</table>';
    $content .= '</div>';
  }
  return $content;
}

function wk_general_newsletter_icon($field) {
  $path = drupal_get_path('theme', 'wundertheme');
  return theme('image', array('path' => $path . '/images/icon-screen-grey.png', 'alt' => '', 'width' => 97, 'height' => 117)) . $vars['label'];
}

function wk_general_colored_element($field) {
  $term = $field['entity'];
  $title = $term->name;
  $color = $term->field_research_area_color[LANGUAGE_NONE][0]['rgb'];
  $abbr = $term->field_research_area_abbreviation[LANGUAGE_NONE][0]['safe_value'];

  $content = '<div class="element-box" style="border: 3px solid ' . $color . ';text-align: center;">';
  $content .= '<div class="element-box-name">' . $title . '</div>';
  $content .= '<div class="element-box-abbr" style="color: ' . $color . ';">' . $abbr . '</div>';
  $content .= '</div>';
  return $content;
}

function wk_general_pricing_link($field) {
  return '<a href="#pricing">' . t('Fee information') . '</a>';
}

function wk_general_newsletter_event_speakers($field) {
  $entity = $field['entity'];
  $items = field_get_items('node', $entity, 'field_event1_speakers');
  $output ='';
  $output .= wk_general_newsletter_short_fields($items, 'Speakers');
  $items = field_get_items('node', $entity, 'field_event1_chair');
  $output .= wk_general_newsletter_short_fields($items, 'Chair');
  return $output;
}

function wk_general_newsletter_short_fields($items, $label) {
  $output = '';
  if($items) {
    $output .= '<div class="field field-label-inline"><div class="field-label">'. $label . ':&nbsp</div>';
    $pattern = '/<dl><dt>([^<]+)<\/dt><dd>([^<]+)<\/dd><\/dl>/';
    preg_match_all($pattern, $items[0]['value'], $matches);
    if (count($matches[0])) {
      $output .= '<div class="field-items"><ul>';
    $cnt = count($matches[0]);
    if (count($matches[0]) > 5) $cnt = 5;
      for ($i=0; $i < $cnt; $i++) {
        $output .= '<li>' . $matches[1][$i] . ', ' . $matches[2][$i] .'</li>';
      }
      $output .= '</ul></div></div>';
    }
  }
  return $output;
}

function wk_general_newsletter_social_links($field) {
  $themePath = url('<front>', array('absolute' => TRUE)) . drupal_get_path('theme', 'wundertheme');
  $output = '<div class="social">';
  // email
  $output .= '<a class="facebook" href="https://www.facebook.com/pages/Centre-for-European-Policy-Studies-CEPS/174179289289966">';
  $output .= '<img src="' . $themePath . '/images/icon-facebook.png" />';
  $output .= '</a>';
  // twitter
  $output .= '<a class="twitter" href="https://twitter.com/CEPS_thinktank">';
  $output .= '<img src="' . $themePath . '/images/icon-twitter.png" />';
  $output .= '</a>';
  // linkedin
  $output .= '<a class="linkedin" href="http://www.linkedin.com/company/ceps">';
  $output .= '<img src="' . $themePath . '/images/icon-linkedin.png" />';
  $output .= '</a>';
  $output .= '</div>';
  return $output;
}
