<?php
/**
 * @file
 * budg_eu_projects.solr.inc
 */

/**
 * Defines the default fields for a solr search.
 *
 * @return array
 *          The fields.
 */
function _budg_eu_projects_solr_default_fields() {
  include_once 'budg_eu_projects.functions.inc';
  global $language;
  $result_display = _budg_eu_projects_result_display();
  return array(
    'ss_language'  => array(
      'field_type' => 'hidden',
      'value' => $language->language,
      'default' => 'en',
    ),
    'view'  => array(
      'field_type' => 'hidden',
      'value' => $result_display['view'],
      'default' => $result_display['view'],
    ),
    'content'  => array(
      'field_type' => 'textfield',
      'title' => t('Keywords'),
      'default' => '',
    ),
    'sm_af_country' => array(
      'field_type' => 'select',
      'title' => t('Country'),
      'default' => 'All',
    ),
    'im_field_broad_area' => array(
      'field_type' => 'select',
      'title' => t('Funding area'),
      'default' => 'All',
    ),
    'im_field_programme_name' => array(
      'field_type' => 'select',
      'title' => t('Programme name'),
      'default' => 'All',
    ),
    'im_field_ec_priorities_' => array(
      'field_type' => 'select',
      'title' => t('EC’s priorities'),
      'default' => 'All',
    ),
    'its_field_eu_budget_contribution' => array(
      'field_type' => 'select',
      'title' => t('EU contribution'),
      'value' => array(
        '1' => '< 10 000',
        '2' => '10 000 - 99 999',
        '3' => '100 000 - 999 999',
        '4' => '>= 1 000 000',
      ),
      'value_mapping' => array(
        1 => array(
          'solr' => '[0 TO 9999]',
          'php' => array(
            'function' => 'is_smaller' ,
            'figures' => 10000,
          ),
        ),
        2 => array(
          'solr' => '[10000 TO 99999]',
          'php' => array(
            'function' => 'is_between' ,
            'figures' => array(10000, 99999),
          ),
        ),
        3 => array(
          'solr' => '[100000 TO 999999]',
          'php' => array(
            'function' => 'is_between' ,
            'figures' => array(100000, 999999),
          ),
        ),
        4 => array(
          'solr' => '[1000000 TO *]',
          'php' => array(
            'function' => 'is_equal_bigger' ,
            'figures' => 1000000,
          ),
        ),
      ),
      'default' => 'All',
    ),
  );
}

/**
 * Gets a response from solr.
 *
 * @param array $options
 *          Solr query parameters.
 *
 * @return array
 *          Returns an array of the response.
 */
function _budg_eu_projects_solr_response($options = array()) {
  // The solr server.
  $default_environment = apachesolr_default_environment();
  $default_server = apachesolr_environment_load($default_environment);

  // The query.
  $query = array();
  foreach ($options as $variable => $value) {
    $query[$variable] = $value;
  }

  $qt = '/select';

  // The default values.
  if (isset($query['qt'])) {
    $qt = $query['qt'];
    unset($query['qt']);
  }

  if (!isset($query['q'])) {
    $query['q'] = budg_eu_projects_params_to_solr_q();
  }
  elseif (is_array($query['q'])) {
    $query['q'] = budg_eu_projects_params_to_solr_q($query['q']);
  }
  $site_query = '';
  if ($default_environment != 'local') {
    $site_query = 'site:*euprojects* AND ';
  }

  $query['q'] = $site_query . 'bundle:project AND ' . $query['q'];

  if (!isset($query['rows'])) {
    $query['rows'] = 10000;
  }

  if (!isset($query['wt'])) {
    $query['wt'] = 'json';
  }

  $query = str_replace('%2A', '*', drupal_http_build_query($query));

  $url = $default_server['url'] . $qt . '?' . $query;

  // Send the query to solr.
  $response = drupal_http_request($url);

  return $response;
}

/**
 * Generates a solr query string out ot paramaters.
 *
 * @param array $params
 *   The query parameters.
 *
 * @return string
 *          The query.
 */
function budg_eu_projects_params_to_solr_q($params = '') {
  if (!$params) {
    $params = _budg_eu_projects_default_search_values();
  }
  $default_fields = _budg_eu_projects_solr_default_fields();

  $exceptions = array(
    'ss_language',
  );

  $params = _budg_eu_projects_solr_filter_params($params, $exceptions);
  $q = array();
  foreach ($params as $variable => $value) {
    if (isset($default_fields[$variable]['value_mapping'][$value]['solr'])) {
      $value = $default_fields[$variable]['value_mapping'][$value]['solr'];
    }
    elseif ($value == 'All') {
      $value = '';
    }

    if ($variable == 'content' and $value) {
      $value = preg_replace('/\s+/', '+', $value);
    }
    elseif ($variable == 'sm_af_country' and $value) {
      $value = '"' . $value . '"';
    }

    if ($value) {
      if ($variable != 'content') {
        $q[] = $variable . ':' . $value;
      }
      else {
        $q[] = $value;
      }
    }
  }

  $q = implode(' && ', $q);

  return $q;
}

/**
 * Generates geojson compatible array out of solr reponse.
 *
 * @param array $solr_options
 *          Solr query parameters.
 *
 * @return array
 *          Returns an geojson compatible array.
 */
function _budg_eu_projects_solr_prepare_geojson($solr_options = array()) {
  include_once 'budg_eu_projects.functions.inc';

  // The search variables.
  if (!isset($solr_options['q'])) {
    $filters = _budg_eu_projects_default_search_values('', FALSE);
  }
  else {
    $filters = $solr_options['q'];
  }
  $selected_country = isset($filters['sm_af_country']) ? $filters['sm_af_country'] : '';

  // Gets the solr response.
  $response = _budg_eu_projects_solr_response($solr_options);

  // Prepares the geojspon compatible array.
  $response = isset($response->data) ? drupal_json_decode($response->data, TRUE) : array();

  $geo_array = array(
    'type' => 'FeatureCollection',
  );
  if (isset($response['response']['docs'])) {
    foreach ($response['response']['docs'] as $document) {
      $nid = isset($document['entity_id']) ? $document['entity_id'] : '';
      $title = isset($document['sm_title_field'][0]) ?
        $document['sm_title_field'][0] :
        (isset($document['label']) ? $document['label'] : t('No title'));
      $path = isset($document['path_alias']) ? $document['path_alias'] . '_' . $document['ss_language'] : 'node/' . $nid;
      $path = base_path() . $path;

      // Map country with coordinate
      // Display a project per country whenever it has its coordinates.
      $countries = isset($document['sm_af_country']) ? $document['sm_af_country'] : array();
      $coordinates = isset($document['geom_field_gps_coordinates_proje']) ? $document['geom_field_gps_coordinates_proje'] : array();
      foreach ($countries as $index => $country_code) {
        $lat = '';
        $long = '';
        if (isset($coordinates[$index]) and
            list($lat, $long) = explode(',', $coordinates[$index]) and
            !empty($lat) and
            !empty($long) and
            (!$selected_country  or $selected_country == 'All' or $selected_country == $country_code)) {
          $link_options = array('attributes' => array('data-nid' => $nid, 'title' => $title));
          $description = '';
          if (isset($document['im_field_broad_area'])) {
            $description = '<h3>' . t('Funding area(s)') . "</h3>\n";
            $terms = i18n_taxonomy_localize_terms(taxonomy_term_load_multiple($document['im_field_broad_area']));
            $funding_areas = array();
            foreach ($terms as $term) {
              $funding_areas[] = $term->name;
            }
            $description .= '<p>' . implode(', ', $funding_areas) . "</p>\n";
          }
          if (isset($document['itm_field_eu_budget_contribution'])) {
            $description .= '<h3>' . t('EU contribution') . "</h3>\n";
            $description .= '<p>EUR ' . $document['itm_field_eu_budget_contribution'][0] . "</p>\n";
          }
          if (isset($document['ts_field_description'])) {
            $description .= '<h3>' . t('Description') . "</h3>\n";
            $description .= '<div> ' . $document['ts_field_description'];
            $description .= '<span class="more_info">' . l(t('view'), $path, $link_options) . "</span></div> \n";
          }
          $geo_array['features'][] = (object) array(
            'type' => 'Feature',
            'geometry' => array(
              'type' => 'Point',
              'coordinates' => array($long, $lat),
            ),
            'properties' => array(
              'name' => l($title, $path, $link_options),
              'description' => $description,
            ),
          );
        }
      }
    }
  }

  return $geo_array;
}

/**
 * Filters the parameters, only retains the default fields.
 *
 * @param array $params
 *   Parameters to be filtered.
 * @param array $exceptions
 *   Values not to be filtered.
 *
 * @return array
 *    Filtered parameters.
 */
function _budg_eu_projects_solr_filter_params($params, $exceptions = array()) {
  $solr_default_fields = _budg_eu_projects_solr_default_fields();

  $visible_fields = array();
  foreach ($solr_default_fields as $field => $value) {
    if ($value['field_type'] != 'hidden') {
      $visible_fields[] = $field;
    }
  }

  $available_fields = array_merge($visible_fields, $exceptions);

  foreach (array_keys($params) as $field) {
    if (!in_array($field, $available_fields)) {
      unset($params[$field]);
    }
  }
  return $params;
}

/**
 * Implements hook_apachesolr_field_mappings_alter().
 */
function budg_eu_projects_apachesolr_field_mappings_alter(&$mappings, $entity_type) {
  // Enable indexing for text fields.
  $mappings['text'] = array(
    'indexing_callback' => 'apachesolr_fields_default_indexing_callback',
    'map callback' => '',
    'index_type' => 'string',
    'facets' => TRUE,
    'facet missing allowed' => TRUE,
    'dependency plugins' => array('bundle', 'role'),
    'hierarchy callback' => FALSE,
    'name_callback' => '',
    'facet mincount allowed' => FALSE,
    // Field API allows any field to be multi-valued.
    // If we set this to false we are able to sort.
    'multiple' => FALSE,
  );
}

/**
 * Implements hook_apachesolr_index_document_build_node().
 */
function budg_eu_projects_apachesolr_index_document_build_node(ApacheSolrDocument $document, $entity, $env_id) {
  // Adds the description field.
  if (!empty($entity->field_description[LANGUAGE_NONE][0]['value'])) {
    $document->ts_field_description = $entity->field_description[LANGUAGE_NONE][0]['value'];
  }
}
