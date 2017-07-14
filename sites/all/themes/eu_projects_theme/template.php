<?php
/**
 * @file
 * template.php
 */

/**
 * Implements hook_preprocess_page().
 */
function eu_projects_theme_preprocess_page(&$variables) {
  global $language;
  // Add javascript variables.
  include_once drupal_get_path('module', 'budg_eu_projects') . '/inc/budg_eu_projects.functions.inc';
  $settings = array(
    'baseUrl' => $GLOBALS['base_url'],
    'language' => $language->language,
    'label_read_more' => t('Read more'),
    'label_close' => t('Close'),
    'pathEuropaTheme' => drupal_get_path('theme', 'europa'),
    'labelBasicSearch' => t('Basic search'),
    'labelAdvancedSearch' => t('Advanced search'),
    'labelShowSearch' => t("Show search"),
    'labelHideSearch' => t("Hide search"),
  );
  drupal_add_js(array('eu_projects_theme' => $settings), 'setting');

  // Webtools.
  $inline_script = '<script defer src="//europa.eu/webtools/load.js" type="text/javascript"></script>';
  $element = array(
    '#type' => 'markup',
    '#markup' => $inline_script,
  );
  drupal_add_html_head($element, 'webtools');

  // Application-name.
  $application_name = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'application-name',
      'content' => t('EU Results'),
    ),
  );
  drupal_add_html_head($application_name, 'application-name');

  // Apple-mobile-web-app-title.
  $apple_mobile_web_app_title = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'apple-mobile-web-app-title',
      'content' => t('EU Results'),
    ),
  );
  drupal_add_html_head($apple_mobile_web_app_title, 'apple-mobile-web-app-title');

  // Add ds_2col_stacked_fluid.css (not always loaded).
  $ds = array(
    '#tag' => 'link',
    '#attributes' => array(
      'rel' => 'stylesheet',
      'type' => 'text/css',
      'href' => file_create_url(drupal_get_path('module', 'ds') . '/layouts/ds_2col_stacked_fluid/ds_2col_stacked_fluid.css'),
    ),
  );
  drupal_add_html_head($ds, 'ds_2col_stacked_fluid');

  // Add social bookmark css.
  $social_bookmarks = array(
    '#tag' => 'link',
    '#attributes' => array(
      'rel' => 'stylesheet',
      'type' => 'text/css',
      'href' => '//europa.eu/webtools/css.php?widgets=sbkm&lang=en&wtdebug=false',
    ),
  );
  drupal_add_html_head($social_bookmarks, 'social_bookmarks');

  // Admin css.
  if (path_is_admin(current_path())) {
    drupal_add_css(drupal_get_path('theme', 'eu_projects_theme') . '/css/eu.projects.layout.admin.css',
        array('weight' => CSS_THEME));
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function eu_projects_theme_preprocess_field(&$variables) {

  // Puts the country inside locality_block.
  if ($variables['element']['#field_name'] == 'field_project_location') {
    foreach ($variables['items'] as $index => $item) {
      $variables['items'][$index]['locality_block']['country'] = $variables['items'][$index]['country'];
      unset($variables['items'][$index]['country']);
    }
  }

  // Adds the EUR sign.
  if ($variables['element']['#field_name'] == 'field_eu_budget_contribution') {
    foreach ($variables['items'] as $index => $item) {
      $variables['items'][$index]['#markup'] = 'EUR ' . $item['#markup'];
    }
  }
}

/**
 * Implements theme_pager_link().
 */
function eu_projects_theme_pager_link($variables) {
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];
  $project = FALSE;

  $url = $_GET['q'];

  if (($node = menu_get_object()) && $node->type == 'project') {
    $project = TRUE;
    $attributes['data-nid'] = $node->nid;
  }

  if ($project or $url == 'search-projects') {
    $parameters['search_display'] = 'ok';
  }

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();

  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title.
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array(
        '@number' => $text,
      ));
    }
  }

  // @todo l() cannot be used here, since it adds an 'active' class based on the
  // path only (which is always the current path for pager links). Apparently,
  // none of the pager links is active at any time - but it should still be
  // possible to use l() here.
  // @see http://drupal.org/node/1410574
  $attributes['href'] = url($url, array(
    'query' => $query,
  ));
  return '<a' . drupal_attributes($attributes) . '>' . $text . '</a>';
}

/**
 * Implements hook_html_head_alter().
 */
function eu_projects_theme_html_head_alter(&$head_elements) {

  // Overwrites the Europa favicons.
  $europa_theme_png_path = base_path() . drupal_get_path('theme', 'eu_projects_theme') . '/images/png/favicon/';

  $elements = array(
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '57x57',
        'href' => 'apple-touch-icon-57x57.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '60x60',
        'href' => 'apple-touch-icon-60x60.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '114x114',
        'href' => 'apple-touch-icon-114x114.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '120x120',
        'href' => 'apple-touch-icon-120x120.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '144x144',
        'href' => 'apple-touch-icon-144x144.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '152x152',
        'href' => 'apple-touch-icon-152x152.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '180x180',
        'href' => 'apple-touch-icon-180x180.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'icon',
        'type' => 'image/png',
        'sizes' => '32x32',
        'href' => 'favicon-32x32.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'icon',
        'type' => 'image/png',
        'sizes' => '192x192',
        'href' => 'android-chrome-192x192.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'icon',
        'type' => 'image/png',
        'sizes' => '96x96',
        'href' => 'favicon-96x96.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'icon',
        'type' => 'image/png',
        'sizes' => '16x16',
        'href' => 'favicon-16x16.png',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-TileColor',
        'content' => '#034ea1',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-TileImage',
        'content' => $europa_theme_png_path . 'mstile-144x144.png',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'theme-color',
        'content' => '#034ea1',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-square70x70logo',
        'content' => $europa_theme_png_path . 'mstile-70x70.png',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-square150x150logo',
        'content' => $europa_theme_png_path . 'mstile-150x150.png',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-wide310x150logo',
        'content' => $europa_theme_png_path . 'mstile-310x150.png',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-square310x310logo',
        'content' => $europa_theme_png_path . 'mstile-310x310.png',
      ),
    ),
  );
  $i = 0;
  foreach ($elements as $element) {
    $element['#type'] = 'html_tag';
    if (isset($element['#attributes']['href'])) {
      $element['#attributes']['href'] = $europa_theme_png_path . $element['#attributes']['href'];
    }
    $head_elements[$i] = $element;
    $i++;
  }
}
