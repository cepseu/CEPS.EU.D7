<?php

/*
 * Enable developer settings
 */

function glue_developer() {

  $module_list = array('features', 'devel', 'devel_generate', 'devel_node_access', 'schema', 'views_ui', 'l10n_update', 'simpletest', 'switcheroo', 'diff', 'update', 'dblog', 'features_orphans', 'ftools', 'masquerade', 'fe_block', 'strongarm');

  module_enable($module_list);

  //WD
  watchdog('glue installer', 'Developer tools enabled', array(), WATCHDOG_INFO);

  //Enable other dev settings
  module_load_include('inc', 'views', 'drush/views.drush');
  views_development_settings();
  glue_developer_blocks();
  //Disable features ajax loading
  variable_get('ftools_disable_features_page_js', 1);//not working f*cks up js loading of everything
  //enable permissions for admin
  variable_get('platform_edit_permissions', 1);
}

/**
 * Enable Dropsolid features
 */
function glue_enable_dropsolid_features() {
  //@todo write here the features that you want to enable during install
}

/*
 * Default variables set
 */

function glue_variables() {
  //Set the environment
  //@todo introduce an environment variable #666
  if (glue_check_cli()) {
    variable_set('glue_env', drush_get_option('env'));
  }
  elseif (variable_get('glue_env') == '') {
    variable_set('glue_env', 'local');
  }

  /* Site settings */
  variable_set('cron_safe_threshold', 0);
  variable_set('update_notify_emails', array()); // Module update notification adress
  variable_set('user_mail_status_activated_notify', FALSE); // Don't send mails on account creation
  variable_set('user_mail_status_blocked_notify', FALSE); // Don't send mails on account creation
  variable_set('user_register', USER_REGISTER_ADMINISTRATORS_ONLY);
  variable_set('date_default_timezone', 'Europe/Brussels');
  variable_set('user_default_timezone', 0);
  variable_set('site_default_country', 'BE');
  variable_set('date_first_day', 1);
  variable_set('l10n_update_check_mode', 2);
  variable_set('l10n_update_import_mode', 0);
  variable_set('l10n_update_download_store', 'sites/all/translations');
  variable_set('ds_extras_vd', 1); //DS fields in views
  variable_set('node_content_enabled', TRUE); //Default content
  variable_set('user-pictures', TRUE);

  //Enable pagemanger tasks
  variable_set('page_manager_term_view_disabled', 0); // Enale pagemanager taxonomy/term/%term override
  variable_set('page_manager_node_view_disabled', 0); // Enale pagemanager node/%node override
  //Disable core search indexing
  variable_set('search_cron_limit', 0);

  //WD
  watchdog('glue installer', 'All variables have been set', array(), WATCHDOG_INFO);
}

/**
 * Enable languages
 */
function glue_languages($langs) {
  require_once DRUPAL_ROOT . '/includes/locale.inc';
  $languages = explode(':', $langs);

  $languages_en = language_list('enabled');
  foreach ($languages_en[1] as $lang_key => $values) {
    $installed[$lang_key] = $lang_key;
  }

  foreach ($languages as $key => $language) {
    if (!in_array($language, $installed)) {
      locale_add_language($language);
    }
    //The first lang is default
    if ($key == 0) {
      $lang = language_list();
      variable_set('language_default', $lang[$language]);
      // Required for l18n_field: translate field labels.
      variable_set('i18n_string_source_language', $language);
    }
  }

  //WD
  watchdog('installer', 'All languages have been set', array(), WATCHDOG_INFO);
}

/**
 * Update the languages
 * @todo this does not work
 */
function glue_languages_update() {
  //@todo in installer make sure the path is writeable #675
  $translation_path = variable_get('l10n_update_download_store', 'sites/all/translations');
  $file = new stdClass();
  $item = new stdClass();

  foreach (glob($translation_path . '/*.po') as $name) {
    if (!in_array($name, $last)) {
      $file->uri = $name;
      $file->filename = $name;
      _locale_import_po($file, 'nl', LOCALE_IMPORT_OVERWRITE, 'default');
    }
  }

  //WD
  watchdog('glue installer', 'All languages have been updated', array(), WATCHDOG_INFO);
}

/**
 * Use this in the afterbuilder to complete translations
 * @param type $last
 */
function glue_languages_update_last($last = array()) {
  //@todo not working yet
  foreach ($last as $name) {
    $file->uri = $name;
    $file->filename = $name;
    _locale_import_po($file, 'nl', LOCALE_IMPORT_OVERWRITE, 'default');
  }

  //WD
  watchdog('glue installer', 'All custom translations have been applied.', array(), WATCHDOG_INFO);
}

/*
 * Default theme settings
 */

function glue_themes($default = 'bartik') {
  //@todo this needs to be our theme or a template monster theme we can drop in #677
  $themes = array('bartik', 'seven');

  variable_set('theme_default', $default);
  variable_set('admin_theme', 'adminimal');
  variable_set('node_admin_theme', 1);

  theme_enable($themes);

  //WD
  watchdog('glue installer', 'The theme has been initialized', array(), WATCHDOG_INFO);
}

/*
 * Default text formats
 */

function glue_text_formats() {
  // Add text formats.
  $filtered_html_format = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'weight' => 0,
    'filters' => array(
      // URL filter.
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
      ),
      // HTML filter.
      'filter_html' => array(
        'weight' => 1,
        'status' => 0,
      ),
      // Line break filter.
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
      ),
      // HTML corrector filter.
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
      ),
    ),
  );
  $filtered_html_format = (object) $filtered_html_format;
  filter_format_save($filtered_html_format);

  $full_html_format = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'weight' => 1,
    'filters' => array(
      // URL filter.
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
      ),
      // Line break filter.
      'filter_autop' => array(
        'weight' => 1,
        'status' => 1,
      ),
      // HTML corrector filter.
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
      ),
    ),
  );
  $full_html_format = (object) $full_html_format;
  filter_format_save($full_html_format);

  $filtered_html_permission = filter_permission_name($filtered_html_format);
  user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, array('access content'));
  user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, array('access content', $filtered_html_permission));

  //WD
  watchdog('glue installer', 'All text formats are configurated', array(), WATCHDOG_INFO);
}

/**
 * Date formates
 */
function glue_date_formats() {
  system_date_format_delete('month_year');
  system_date_format_type_delete('month_year');
  system_date_format_delete('day_month_year_long');
  system_date_format_type_delete('day_month_year_long');
  system_date_format_delete('day_month_year_short');
  system_date_format_type_delete('day_month_year_short');
  system_date_format_delete('day_month_year_short_no_time');
  system_date_format_type_delete('day_month_year_short_no_time');

  $date_formats[0]['format'] = 'F Y'; //Displayed as: January 2012
  $date_formats[0]['type'] = 'month_year';
  $date_formats[0]['locked'] = '0';
  $date_formats[0]['is_new'] = '1';

  $date_formats[1]['format'] = 'l j F Y'; //Displayed as: Wednesday 11 January 2012
  $date_formats[1]['type'] = 'day_month_year_long';
  $date_formats[1]['locked'] = '0';
  $date_formats[1]['is_new'] = '1';

  $date_formats[2]['format'] = 'j F Y'; //Displayed as: 11 January 2012
  $date_formats[2]['type'] = 'day_month_year_short';
  $date_formats[2]['locked'] = '0';
  $date_formats[2]['is_new'] = '1';

  $date_formats[3]['format'] = 'j/m/Y';
  $date_formats[3]['type'] = 'day_month_year_short_no_time';
  $date_formats[3]['locked'] = '0';
  $date_formats[3]['is_new'] = '1';

  foreach ($date_formats as $date_format) {
    system_date_format_save($date_format, 0);
  }

  $format_types[0]['title'] = 'month_year';
  $format_types[0]['type'] = 'month_year';
  $format_types[0]['locked'] = 0;
  $format_types[0]['is_new'] = 1;
  $format_types[0]['value'] = 'F Y';

  $format_types[1]['title'] = 'day_month_year_long';
  $format_types[1]['type'] = 'day_month_year_long';
  $format_types[1]['locked'] = 0;
  $format_types[1]['is_new'] = 1;
  $format_types[1]['value'] = 'l j F Y';

  $format_types[2]['title'] = 'day_month_year_short';
  $format_types[2]['type'] = 'day_month_year_short';
  $format_types[2]['locked'] = 0;
  $format_types[2]['is_new'] = 1;
  $format_types[2]['value'] = 'j F Y';

  $format_types[3]['title'] = 'day_month_year_short_no_time';
  $format_types[3]['type'] = 'day_month_year_short_no_time';
  $format_types[3]['locked'] = 0;
  $format_types[3]['is_new'] = 1;
  $format_types[3]['value'] = 'j/m/Y';

  foreach ($format_types as $format) {
    system_date_format_type_save($format);
    variable_set('date_format_' . $format['title'], $format['value']);
    locale_date_format_save('nl', $format['type'], $format['value']);
    locale_date_format_save('en', $format['type'], $format['value']);
  }
  // Localize general date settings. (European format)
  variable_set('date_format_long', "l, j F, Y - H:i");
  variable_set('date_format_medium', "D, d/m/Y - H:i");
  variable_set('date_format_short', "d/m/Y - H:i");

  watchdog('glue installer', 'All date formats are configured', array(), WATCHDOG_INFO);
}

/*
 *  Enable some standard blocks.
 */

function glue_blocks() {
  //Main theme
  $default_theme = variable_get('theme_default', 'bartik');
  $query = db_delete('block')
      ->condition('theme', $default_theme, '=')
      ->execute();
  $values = array(
    array(
      'module' => 'system',
      'delta' => 'main',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'content',
      'pages' => '',
      'cache' => -1,
    ),
    array(
      'module' => 'masquerade',
      'delta' => 'masquerade',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => 1,
      'region' => 'content',
      'pages' => '',
      'cache' => -1,
    ),
  );

  $query = db_insert('block')->fields(array('module', 'delta', 'theme', 'status', 'weight', 'region', 'pages', 'cache'));
  foreach ($values as $record) {
    $query->values($record);
  }
  $query->execute();


  //Admin theme
  //Delete blocks from seven
  $admin_theme = variable_get('admin_theme', 'seven');
  $query = db_delete('block')
      ->condition('theme', $admin_theme, '=')
      ->execute();

  $values = array(
    array(
      'module' => 'system',
      'delta' => 'main',
      'theme' => $admin_theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'content',
      'pages' => '',
      'cache' => -1,
    ),
    array(
      'module' => 'masquerade',
      'delta' => 'masquerade',
      'theme' => $admin_theme,
      'status' => 1,
      'weight' => 1,
      'region' => 'content',
      'pages' => '',
      'cache' => -1,
    ),
  );

  $query = db_insert('block')->fields(array('module', 'delta', 'theme', 'status', 'weight', 'region', 'pages', 'cache'));
  foreach ($values as $record) {
    $query->values($record);
  }
  $query->execute();

  //WD
  watchdog('glue installer', 'All blocks have been set', array(), WATCHDOG_INFO);
}

/**
 * Only enabled when installing developmentprofile
 */
function glue_developer_blocks() {
  $default_theme = variable_get('theme_default', 'bartik');

  $values = array(
    array(
      'module' => 'masquerade',
      'delta' => 'masquerade',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => 1,
      'region' => 'content',
    ),
  );
  // Make shure all blocks are in the db.
  _block_rehash($default_theme);

  foreach ($values as $record) {
    db_update('block')
        ->fields(array(
          'region' => $record['region'],
          'weight' => $record['weight'],
          'status' => $record['status'],
        ))
        ->condition('module', $record['module'])
        ->condition('delta', $record['delta'])
        ->condition('theme', $record['theme'])
        ->execute();
  }

  //WD
  watchdog('glue installer', 'All developer blocks have been set', array(), WATCHDOG_INFO);
}

/*
 * Default menu's
 */

function glue_menus() {
  require_once DRUPAL_ROOT . '/modules/menu/menu.module';
  require_once DRUPAL_ROOT . '/modules/menu/menu.admin.inc';

  /* Save the menu */
  $t = get_t();
  $menus = array();

  $menus[] = array(
    'menu_name' => 'corporate-menu',
    'title' => $t('Corporate menu'),
    'description' => 'This is the main menu on a corporate site.',
  );
  $menus[] = array(
    'menu_name' => 'site-links',
    'title' => $t('Site links'),
    'description' => 'Site links',
  );

  foreach ($menus as $menu) {
    menu_save($menu);
  }

  //WD
  watchdog('glue installer', 'All menus have been set', array(), WATCHDOG_INFO);
}

/**
 * Create menu links
 */
function glue_menu_links() {
  require_once DRUPAL_ROOT . '/modules/menu/menu.module';
  require_once DRUPAL_ROOT . '/modules/menu/menu.admin.inc';

  glue_menu_site_links();

  //WD
  watchdog('glue installer', 'All menu links have been set', array(), WATCHDOG_INFO);
}

/*
 * This file contains the site links. This just contains an example link
 * @todo determine default links #680
 */

function glue_menu_site_links() {
  $menu_items = array();

  $menu_items[] = array(
    'link_title' => 'Example',
    'link_path' => '<front>',
    'menu_name' => 'site-links',
    'module' => 'glue',
  );

  foreach ($menu_items as $item) {
    menu_link_save($item);
  }
}

/*
 * Default roles
 * @todo determine default roles #681
 */

function glue_roles() {
  user_role_grant_permissions(DRUPAL_ANONYMOUS_RID, array('access content', 'access comments'));
  user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, array('access content', 'access comments', 'post comments', 'skip comment approval'));

  // Create a default role for site administrators, with all available permissions assigned.
  $admin_role = user_role_load_by_name('administrator');
  user_role_grant_permissions($admin_role->rid, array_keys(module_invoke_all('permission')));
  // Set this as the administrator role.
  variable_set('user_admin_role', $admin_role->rid);

  $role = user_role_load_by_name('webmaster');
  if (!empty($role->rid)) {
    // Webmaster role
    $webmaster_role = new stdClass();
    $webmaster_role->name = 'webmaster';
    $webmaster_role->weight = 3;
    user_role_save($webmaster_role);

    $edit = array();
    $edit['name'] = 'webmaster';
    $edit['mail'] = 'webmaster@dropsolid.com';
    $edit['roles'] = array($webmaster_role->rid => $webmaster_role->rid);
    $edit['pass'] = 'webmaster';
    $edit['status'] = 1;

    $account = user_save(drupal_anonymous_user(), $edit);
  }

  $role = user_role_load_by_name('editor');
  if (!empty($role->rid)) {
    // Editor role
    $editor_role = new stdClass();
    $editor_role->name = 'editor';
    $editor_role->weight = 4;
    user_role_save($editor_role);

    $edit = array();
    $edit['name'] = 'editor';
    $edit['mail'] = 'editor@dropsolid.com';
    $edit['roles'] = array($editor_role->rid => $editor_role->rid);
    $edit['pass'] = 'editor';
    $edit['status'] = 1;

    $account = user_save(drupal_anonymous_user(), $edit);
  }
//WD
  watchdog('glue installer', 'All roles have been set', array(), WATCHDOG_INFO);
}

/*
 * Default users
 * @todo determine default users #682
 */

function glue_users() {
  //change the admin user (set by drush)
  /* $admin_user = user_load(1);
    $edit = array();
    $edit['name'] = 'admin';
    $edit['mail'] = 'admin@dropsolid.com';
    $edit['pass'] = 'admin';
    $edit['status'] = 1;
    user_save($admin_user, $edit);
   */
  //WD
  watchdog('glue installer', 'All users have been created', array(), WATCHDOG_INFO);
}

/*
 * Enable features
 * @param array features array of feature names
 */

function glue_features($features = array()) {
  module_enable($features);

  //Needed to allow everything to be properly initalized
  features_rebuild();
  //@todo make sure you can access drush commands #684
  //so_features_revert_all();
  cache_clear_all();

  //WD
  watchdog('glue installer', 'All features were enabled', array(), WATCHDOG_INFO);
}

/**
 * Revert features.
 *
 * Only works when called with drush
 */
function glue_features_revert_all() {
  $features_to_revert = array();
  $force = TRUE;
  foreach (features_get_features() as $module) {
    if ($module->status) {
      $features_to_revert[] = $module->name;
    }
  }
  foreach ($features_to_revert as $module_name) {
    drush_backend_invoke('features-revert ' . $module_name, array('force' => $force));
  }
}

/**
 * Import taxonomy terms (recursive)
 *
 * @param array $terms format like array(array('name' => '', 'children' => array('name' => '', ...)), array());
 * @param $voc_name string
 */
function glue_taxonomy($voc_name, $terms = array()) {
  $voc = taxonomy_vocabulary_machine_name_load($voc_name);
  glue_save_terms($voc->vid, $terms);

  //WD
  watchdog('glue installer', 'Taxonomy terms were saved', array(), WATCHDOG_INFO);
}

/**
 * Save terms
 *
 * This recursive function can save a tree of taxonomy terms
 *
 * @param type $vid
 * @param type $terms
 * @param type $parent
 */
function glue_save_terms($vid, $terms, $parent = 0) {
  foreach ($terms as $values) {
    $term = new stdClass();
    $term->name = $values['name'];
    $term->vid = $vid;
    $term->tid = '';

    $term->parent = $parent;

    if (isset($values['body'])) {
      $term->description = $values['body'];
    }

    //Save the term
    taxonomy_term_save($term);

    //WD
    watchdog('glue import', t('Term vid:%vid tid:%tid:%name imported', array('%vid' => $term->vid, '%tid' => $term->tid, '%name' => $term->name)), NULL, WATCHDOG_INFO);

    if (isset($values['children']) && !empty($values['children'])) {
      glue_save_terms($vid, $values['children'], $term->tid);
    }
  }
}

/**
 * Sets the default wysiwyg
 *
 * @todo #689
 */
function glue_wysiwyg() {
  // Wysiwyg profiles

  db_merge('wysiwyg')
      ->fields(array(
        'format' => 'full_html',
        'editor' => 'ckeditor',
        'settings' => 'a:20:{s:7:"default";i:1;s:11:"user_choose";i:0;s:11:"show_toggle";i:1;s:5:"theme";s:8:"advanced";s:8:"language";s:2:"en";s:7:"buttons";a:2:{s:7:"default";a:33:{s:4:"Bold";i:1;s:6:"Italic";i:1;s:9:"Underline";i:1;s:6:"Strike";i:1;s:11:"JustifyLeft";i:1;s:13:"JustifyCenter";i:1;s:12:"JustifyRight";i:1;s:12:"JustifyBlock";i:1;s:12:"BulletedList";i:1;s:12:"NumberedList";i:1;s:7:"Outdent";i:1;s:6:"Indent";i:1;s:4:"Undo";i:1;s:4:"Redo";i:1;s:4:"Link";i:1;s:6:"Unlink";i:1;s:6:"Anchor";i:1;s:5:"Image";i:1;s:10:"Blockquote";i:1;s:14:"HorizontalRule";i:1;s:3:"Cut";i:1;s:4:"Copy";i:1;s:5:"Paste";i:1;s:9:"PasteText";i:1;s:12:"RemoveFormat";i:1;s:6:"Format";i:1;s:5:"Table";i:1;s:9:"SelectAll";i:1;s:4:"Find";i:1;s:7:"Replace";i:1;s:5:"Flash";i:1;s:6:"Iframe";i:1;s:8:"Maximize";i:1;}s:4:"imce";a:1:{s:4:"imce";i:1;}}s:11:"toolbar_loc";s:3:"top";s:13:"toolbar_align";s:4:"left";s:8:"path_loc";s:6:"bottom";s:8:"resizing";i:1;s:11:"verify_html";i:1;s:12:"preformatted";i:0;s:22:"convert_fonts_to_spans";i:1;s:17:"remove_linebreaks";i:1;s:23:"apply_source_formatting";i:0;s:27:"paste_auto_cleanup_on_paste";i:0;s:13:"block_formats";s:32:"p,address,pre,h2,h3,h4,h5,h6,div";s:11:"css_setting";s:5:"theme";s:8:"css_path";s:0:"";s:11:"css_classes";s:0:"";}',
      ))
      ->key(array('format' => 'full_html',))->execute();

  // Imce profiles
  variable_set('imce_profiles', unserialize('a:2:{i:1;a:10:{s:4:"name";s:6:"User-1";s:7:"usertab";i:1;s:8:"filesize";i:0;s:5:"quota";i:0;s:7:"tuquota";i:0;s:10:"extensions";s:1:"*";s:10:"dimensions";s:9:"1200x1200";s:7:"filenum";i:0;s:11:"directories";a:1:{i:0;a:7:{s:4:"name";s:1:".";s:6:"subnav";i:1;s:6:"browse";i:1;s:6:"upload";i:1;s:5:"thumb";i:1;s:6:"delete";i:1;s:6:"resize";i:1;}}s:10:"thumbnails";a:3:{i:0;a:4:{s:4:"name";s:5:"Small";s:10:"dimensions";s:5:"90x90";s:6:"prefix";s:6:"small_";s:6:"suffix";s:0:"";}i:1;a:4:{s:4:"name";s:6:"Medium";s:10:"dimensions";s:7:"120x120";s:6:"prefix";s:7:"medium_";s:6:"suffix";s:0:"";}i:2;a:4:{s:4:"name";s:5:"Large";s:10:"dimensions";s:7:"180x180";s:6:"prefix";s:6:"large_";s:6:"suffix";s:0:"";}}}i:2;a:10:{s:4:"name";s:14:"Sample profile";s:7:"usertab";i:1;s:8:"filesize";i:1;s:5:"quota";i:2;s:7:"tuquota";i:0;s:10:"extensions";s:16:"gif png jpg jpeg";s:10:"dimensions";s:7:"800x600";s:7:"filenum";i:1;s:11:"directories";a:1:{i:0;a:7:{s:4:"name";s:5:"u%uid";s:6:"subnav";i:0;s:6:"browse";i:1;s:6:"upload";i:1;s:5:"thumb";i:1;s:6:"delete";i:0;s:6:"resize";i:0;}}s:10:"thumbnails";a:1:{i:0;a:4:{s:4:"name";s:5:"Thumb";s:10:"dimensions";s:5:"90x90";s:6:"prefix";s:6:"thumb_";s:6:"suffix";s:0:"";}}}}'));
  variable_set('imce_roles_profiles', unserialize('a:5:{i:5;a:2:{s:6:"weight";s:1:"0";s:10:"public_pid";s:1:"1";}i:3;a:2:{s:6:"weight";s:1:"0";s:10:"public_pid";s:1:"1";}i:4;a:2:{s:6:"weight";s:1:"0";s:10:"public_pid";s:1:"1";}i:2;a:2:{s:6:"weight";i:11;s:10:"public_pid";i:0;}i:1;a:2:{s:6:"weight";i:12;s:10:"public_pid";i:0;}}'));

  //WD
  watchdog('glue installer', 'Wysiwyg & imce profile was saved', array(), WATCHDOG_INFO);
}

/**
 * Generates all aliasses
 */
function glue_generate_aliasses() {

  //Delete aliasses
  db_delete('url_alias')
      ->condition('source', 'node%', 'LIKE')
      ->execute();
  drupal_set_message(t('All of your path aliases have been deleted.'));

  //Create
  $query = db_select('node', 'n');
  $query->leftJoin('url_alias', 'ua', "CONCAT('node/', n.nid) = ua.source");
  $query->addField('n', 'nid');
  $query->isNull('ua.source');
  $query->orderBy('n.nid');
  $query->addTag('pathauto_bulk_update');
  $query->addMetaData('entity', 'node');
  $nids = $query->execute()->fetchCol();

  pathauto_node_update_alias_multiple($nids, 'bulkupdate');

  //WD
  watchdog('glue postinstaller', 'Aliasses generated', array(), WATCHDOG_INFO);
}

/**
 * Flush all image cache styles
 */
function glue_flush_image_style() {
// Flush all image styles in Drupal 7. Old files will be removed to avoid wrong sized images
  foreach (image_styles() as $style) {
    image_style_flush($style);
  }

  //WD
  watchdog('glue postinstaller', 'Styles flushed', array(), WATCHDOG_INFO);
}

//Helpers
/*
 * Import custom database tables
 *
 * @param string file path to the sql to be executed example file drupal_get_path('module', 'glue') . "/files/some_tables.sql"
 */
function glue_import_custom_db_table($file) {
  $file_handle = fopen($file, "r");
  while (!feof($file_handle)) {
    $line = fgets($file_handle);
    if (!empty($line)) {
      db_query($line);
    }
  }
  fclose($file_handle);

  //WD
  watchdog('glue installer', 'All query executed "glue_import_custom_db_table()"', array(), WATCHDOG_INFO);
}

/**
 *  Save field collection
 */

/**
 * Save a field collection item to a node
 *
 * @param type $node
 * @param type $field_name
 * @param type $fields
 */
function glue_save_methode_collection($node, $field_name, $fields) {
  $fieldcollection = new FieldCollectionItemEntity(array('field_name' => $field_name));
  $fieldcollection->field_name = $field_name;

  //Mapping example
  $fieldcollection->field_school_methode[LANGUAGE_NONE][0] = array(
    'value' => $fields['title'],
  );
  if ($fields['body']) {
    $fieldcollection->field_school_methode_body[LANGUAGE_NONE][0] = array(
      'value' => $body,
      'format' => 'filtered_html'
    );
  }

  //Saving
  $fieldcollection->is_new = TRUE;
  $fieldcollection->setHostEntity('node', $node, 'nl');
  $fieldcollection->save();

  //WD
  watchdog('glue importer', 'Fieldcollection created on node "%nid"', array('%nid' => $node->nid), WATCHDOG_INFO);
}

/**
 * Creates a file
 *
 * @param type $name
 * @param type $csv
 * @param $file_mime 'image/jpeg'
 * @return type
 */
function glue_create_file($file_path, $name, $file_mime) {
  if (!is_file($file_path . $name)) {
    //WD
    watchdog('glue importer', "\n\n" . ('No valid file found for:"%name"') . "\n", array('%name' => $file_path . $name, '%line' => __LINE__), WATCHDOG_WARNING);
    return;
  }

  $saved_file = false;

  $fid = db_query("SELECT fid FROM {file_managed} WHERE uri = :uri", array(':uri' => 'public://' . $name))->fetchColumn(0);
  if (!$fid) {
    $file = new stdClass();

    $file = array(
      'uid' => 1,
      'filename' => $name,
      'uri' => 'public://' . $name,
      'filemime' => $file_mime,
      'timestamp' => time(),
      'status' => FILE_STATUS_PERMANENT,
    );
    $file = (object) $file;

    //Copy file
    file_unmanaged_copy($file_path . $file->filename, 'public://' . $file->filename, FILE_EXISTS_REPLACE);
    //WD
    watchdog('glue importer', 'File created:public://' . $name, array(), WATCHDOG_INFO);

    // Save it, inserting a new record.
    $saved_file = file_save($file);
  }
  else {
    $saved_file = file_load($fid);
  }

  return $saved_file;
}

/**
 *  Helper to check for cli
 */
function glue_check_cli() {
  $cli = false;
  $sapi_type = php_sapi_name();
  if (substr($sapi_type, 0, 3) == 'cli') {
    $cli = true;
  }
  return $cli;
}

/**
 * Creates a glue queue
 * This queue can be used and closed
 * Only works when called from within a drush command
 */
function glue_create_glue_queue() {
  variable_set('queue_class_glue_jobs', 'GlueQueue');
  $queue = DrupalQueue::get('glue_jobs');
  $queue->createQueue();
  $queue->drush_fork_glue_queue();

  return $queue;
}

/**
 * GlueQueue class
 */
class GlueQueue extends SystemQueue {

  protected $process_count;

  public function drush_fork_glue_queue($process_count = 4) {
    $this->process_count = $process_count;
    for ($i = 0; $i < $process_count; $i++) {
      drush_backend_fork('glue-queue', array());
    }
  }

  function drush_create_kill_function() {
    $item = new stdClass();
    for ($i = 0; $i < $this->process_count; $i++) {
      $item->function = 'kill';
      $item->arguments = array();
      $this->createItem($item);
    }
  }

  /*
   * Debug function to see how many items in queue left
   */

  function wait_for_empty() {
    $count = 1;
    while ($count > 0) {
      $count = $this->numberOfItems();
      drush_print('In queue: ' . $count);
      sleep(1);
    }
    return;
  }

}
