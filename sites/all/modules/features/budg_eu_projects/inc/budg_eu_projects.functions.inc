<?php
/**
 * @file
 * budg_eu_projects.functions.inc
 */

/**
 * Returns the current display options.
 *
 * @param array $params
 *          Parameters to apply.
 *
 * @return array
 *          Array of display options.
 */
function _budg_eu_projects_result_display($params = array()) {
  if (!is_array($params) or empty($params)) {
    $params = drupal_get_query_parameters();
  }
  $cookie_path = _budg_eu_projects_cookie_path();
  $default = array(
    'view' => 'grid',
    'order' => 'title',
    'sort' => 'asc',
    'page' => array(
      'grid' => 0,
      'list' => 0,
    ),
  );

  $update = FALSE;

  // If cookie present and not empty, takes its values.
  if (isset($_COOKIE['euprojects_display']) and
      $cookie_output = $_COOKIE['euprojects_display']) {
    $result_display = drupal_json_decode($cookie_output, TRUE);
    if (is_null($result_display)) {
      $result_display = $default;
    }
  }
  else {
    $result_display = $default;
  }

  // Update if display change.
  $display_view = $result_display['view'];
  if (isset($params['view'])) {
    $update = TRUE;
    $result_display['view'] = $display_view = $params['view'];
  }

  // Update if sort order change.
  if (isset($params['order_sort'])) {
    $update = TRUE;
    if (!isset($params['order']) and !isset($params['sort'])) {
      if (!empty($params['order_sort'])) {
        list($result_display['order'], $result_display['sort']) = explode('|', $params['order_sort']);
      }
    }
  }

  // Set page to 0 after search.
  if (isset($params['content']) and $display_view != 'map') {
    $update = TRUE;
    $result_display['page'] = $default['page'];
  }

  // Update after changes of pagination.
  if (isset($params['search_display']) and $display_view != 'map') {
    $update = TRUE;
    $current_page = isset($params['page']) ? $params['page'] : 0;
    $result_display['page'][$display_view] = $current_page;
  }

  // If update, store the values in a cookie.
  if ($update) {
    setcookie('euprojects_display', drupal_json_encode($result_display), time() + 60 * 60 * 24 * 30, $cookie_path);
    $_COOKIE['euprojects_display'] = drupal_json_encode($result_display);
  }

  return $result_display;
}

/**
 * Saves and returns the search values.
 *
 * @param array $params
 *          Parameters to apply.
 * @param bool $stored_data
 *          Reads stored data without saving new ones.
 *
 * @return array
 *          The used filters.
 */
function _budg_eu_projects_default_search_values($params = array(), $stored_data = FALSE) {
  if (!is_array($params) or empty($params)) {
    $params = drupal_get_query_parameters();
  }
  $cookie_path = _budg_eu_projects_cookie_path();
  $update = isset($params['content']) ? TRUE : '';

  $default = array();
  $default_fields = _budg_eu_projects_solr_default_fields();

  foreach ($default_fields as $field => $value) {
    $default[$field] = $value['default'];
  }

  // Clear button.
  if (isset($params['clear'])) {
    if (isset($_COOKIE['euprojects_default_filters'])) {
      unset($_COOKIE['euprojects_default_filters']);
      setcookie('euprojects_default_filters', '', time() - 3600, $cookie_path);
    }
    return $default;
  }

  if (isset($_COOKIE['euprojects_default_filters'])
      and $cookie_data = $_COOKIE['euprojects_default_filters']) {
    $exposed_filters = drupal_json_decode($cookie_data, TRUE);
    if (is_null($exposed_filters)) {
      $exposed_filters = $default;
    }
  }
  else {
    $exposed_filters = $default;
  }

  if (!$stored_data) {
    if ($update) {
      setcookie('euprojects_default_filters',
          drupal_json_encode(_budg_eu_projects_solr_filter_params($params)),
          time() + 60 * 60 * 24 * 30,
          $cookie_path);
      $exposed_filters = $params;
    }
  }

  return $exposed_filters;
}

/**
 * Provides the needed information for the next previous buttons.
 *
 * @param string $view_name
 *          The machine name of the view.
 * @param int $nid
 *          The nid if the current project.
 * @param int $display
 *          The view display.
 * @param array $filters
 *          The filters to be applied.
 * @param int $page
 *          Page number within the pager.
 *          .
 *
 * @return array
 *          position: the position of the $nid within the reults,
 *          view: The views object.
 */
function _budg_eu_projects_project_in_results($view_name, $nid, $display, array $filters, $page) {

  // Gets the data af the search view.
  $view = _budg_eu_projects_search_update_view($view_name, $display, $filters, $page);
  // Establishes the current row position.
  $position = NULL;

  foreach ($view->result as $pos => $row) {
    if ($row->nid == $nid) {
      $position = $pos;
      break;
    }
  }

  return array(
    'position' => $position,
    'view' => $view,
  );
}

/**
 * Helper function to get the readable language from a language code.
 *
 * @param string $langcode
 *          The langcode to get the language object for.
 *
 * @return object
 *          The language object.
 */
function _budg_eu_projects_shared_functions_get_language_obj($langcode, $type = 'name') {
  $languages = locale_language_list($type);
  return isset($languages[$langcode]) ? $languages[$langcode] : NULL;
}

/**
 * Helper function for contact phone fields.
 *
 * This function returns an array that will help
 * in validation/visualization of parts of
 * phone number number fields.
 *
 * @param string $label
 *          Field label, shoud display at errors.
 *
 * @return array
 *          Available patterns.
 */
function _budg_eu_projects_shared_functions_contactphone_patterns($label) {
  $patterns = [
    'phone_label' => [
      'pattern' => '/\s?\(([^)]+)\)$/',
      'return_key' => 0,
    ],
    'country_prefix' => [
      'pattern' => '/^(\+[0-9]{2,3}\s?)/',
      'return_key' => 0,
      'required' => TRUE,
      'explain' => t('Country code missing or in wrong format, ex:+32'),
    ],
    'telephone' => [
      'pattern' => '/^(\+[0-9]{2,3}\s+)((([0-9]{1,4})\s?)+)(\s?\(([^)]+)\))?$/',
      'return_key' => 2,
      'required' => 1,
      'explain' => t('@label is missing or with wrong format (+cc r xxx xx xx (description))', [
        '@label' => $label,
      ]),
    ],
  ];
  return $patterns;
}

/**
 * Updates the view with the stored data.
 *
 * @param string $id
 *          The id of the view.
 * @param string $view_display
 *          The display name of the view.
 * @param array $filters
 *          The filters used tu update the view.
 * @param int $page
 *          Pagination page number.
 *
 * @return Object
 *          View object.
 */
function _budg_eu_projects_search_update_view($id, $view_display, array $filters, $page = 0) {
  $view = views_get_view($id);
  if ($view_display) {
    $view->set_display($view_display);
    $view->exposed_data = $filters;
    $view->set_current_page($page);
    $view->pre_execute();
    $view->execute();
  }

  return $view;
}

/**
 * Gets the language from the url and updates the exisiting values.
 *
 * @param array $params
 *   Parameters to apply.
 *
 * @return string
 *   Language iso code.
 */
function _budg_adapt_language($params = array()) {
  global $language;
  global $language_url;

  if (!is_array($params) or empty($params)) {
    $params = drupal_get_query_parameters();
  }

  // Full Page load.
  if (!isset($params['language'])) {
    $delimiter = variable_get('language_suffix_delimiter', '_');
    $path = request_uri();
    $args = explode($delimiter, $path);
    $lang_code = mb_substr($args[1], 0, 2);
  }
  // Block loaded via ajax.
  else {
    $lang_code = $params['language'];
    $languages = language_list();

    // Make sure the required language object is actually set.
    if (!isset($languages[$lang_code])) {
      $lang_code = $language->language;
    }
    elseif ($language != $lang_code) {
      // Overwrite the global language object.
      $language = $languages[$lang_code];
      $language_url = $languages[$lang_code];
    }
  }

  return $lang_code;
}

/**
 * Generates "<a href=tel:" tag for the contact phone field.
 *
 * If in the generation it fails it will return false.
 *
 * @param string $label
 *          Field label, shoud display at errors.
 * @param string $tel
 *          String containing phone number.
 *
 * @return string
 *          Returns formatted value or the source one.
 */
function budg_eu_projects_shared_function_phonetohtml($label, $tel) {
  $data = trim($tel);

  // Load the array containing our regular expressions and loop to convert them
  // into a link.
  foreach (_budg_eu_projects_shared_functions_contactphone_patterns($label) as $regexp_index => $regexp_values) {
    preg_match($regexp_values['pattern'], $data, $matches);
    // Something is wrong with the phone value and can't be displayed correctly.
    if (!isset($matches[$regexp_values['return_key']]) and isset($regexp_values['required'])) {
      return $tel;
    }
    else {
      if (isset($matches[$regexp_values['return_key']])) {
        $phone[$regexp_index] = trim($matches[$regexp_values['return_key']]);
      }
      else {
        $phone[$regexp_index] = '';
      }
    }
  }

  // Create the href tel: value.
  $tel = 'tel:' . str_replace(' ', '', $phone['country_prefix'] . $phone['telephone']);

  // This defines the element telephone in the component field.
  $classes = [
    'class' => 'field__telephone',
  ];

  // This will be the link title.
  $title = $phone['country_prefix'] . ' ' . $phone['telephone'];

  // Build the link.
  $htmlphone = l($title, $tel, [
    'attributes' => $classes,
  ]);

  // The full element.
  $markup = $htmlphone . ' ' . $phone['phone_label'];

  return $markup;
}

/**
 * Gets the path used for the cookie path.
 *
 * @return string
 *          Returns the path.
 */
function _budg_eu_projects_cookie_path() {
  global $base_url;

  $domain = $_SERVER['HTTP_HOST'];
  $pattern = array(
    "|$domain|",
    "|http://|",
    "|https://|",
  );

  return preg_replace($pattern, '', $base_url);
}
