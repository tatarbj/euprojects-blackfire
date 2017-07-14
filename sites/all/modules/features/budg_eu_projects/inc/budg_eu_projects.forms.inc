<?php
/**
 * @file
 * budg_eu_projects.forms.inc
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function budg_eu_projects_form_project_node_form_alter(&$form, &$form_state, $form_id) {

  // Adds a description to the Project Name.
  $form['title']['#description'] = t('Content limited to @limit characters', array(
    '@limit' => 100,
  ));

  // Specific validations for Projects.
  $form['#validate'][] = 'budg_eu_project_project_form_validate';
}

/**
 * Implements hook_form_NODE_FORM_alter().
 */
function budg_eu_projects_form_node_form_alter(&$form, &$form_state, $form_id) {

  // Prevents creation of additional empty fields
  // when the field allows unlimited values.
  if (isset($form['#node']->translation_source) or (isset($form['#node']->nid) and $form['#node']->nid > 0)) {
    $form_fields = array_keys($form);

    foreach ($form_fields as $field_name) {
      if (drupal_substr($field_name, 0, 6) == "field_") {

        // Check if the field is a custom field.
        $field_language = $form[$field_name]['#language'];
        if (isset($form[$field_name][$field_language]['#cardinality']) && $form[$field_name][$form[$field_name]['#language']]['#cardinality'] == -1) {
          $field = $form['#node']->$field_name;
          if (empty($form[$field_name])) {
            continue;
          }

          if (isset($field[$field_language][0])) {
            $max_delta = $form[$field_name][$field_language]['#max_delta'];
            unset($form[$field_name][$field_language][$max_delta]);
          }
        }
      }
    }
  }
}

/**
 * Validate function for the edit project form.
 */
function budg_eu_project_project_form_validate($form, &$form_state) {
  global $language;
  if (isset($form_state['values']['field_visual'][LANGUAGE_NONE])) {
    $fid = array_column($form_state['values']['field_visual'][LANGUAGE_NONE], 'fid');

    // Defines the mandatory fields and their corresponding error messages.
    $mandatory_fields = array(
      'field_copyright_notice_value' => array(
        'message' => t("The following visuals don't have a copyright notice:"),
      ),
      'field_file_image_alt_text_value' => array(
        'message' => t("The following visuals don't have an alt text:"),
      ),
    );

    // Get the required fields.
    $query = db_select('file_managed', 'n');
    $query->leftjoin('field_data_field_copyright_notice', 'u', "n.fid = u.entity_id AND u.entity_type = 'file' AND u.bundle = 'image'");
    $query->leftjoin('field_data_field_file_image_alt_text', 'a', "n.fid = a.entity_id AND a.entity_type = 'file'  AND a.bundle = 'image'");
    $query->fields('n', array(
      'filename',
      'fid',
    ))->fields('u', array(
      'field_copyright_notice_value',
    ))->fields('a', array(
      'field_file_image_alt_text_value',
    ))->condition('fid', $fid, 'IN');
    $result = $query->execute();

    // Check if the required fields are present.
    $errors = array();
    while ($record = $result->fetchAssoc()) {
      $name = isset($record['filename']) ? $record['filename'] : $record['fid'];
      foreach (array_keys($mandatory_fields) as $field) {
        if (!isset($record[$field])) {
          $errors[$field][] = $name;
        }
      }
    }

    // Display the error messages.
    foreach ($errors as $field => $files) {
      form_set_error($field, $mandatory_fields[$field]['message'] . ' ' . implode(', ', $files));
    }
  }
  // Limit the name to 100 chacracters.
  $limit = 100;

  $title_field = isset($form_state['values']['title_field'][$language->language][0]['value']) ?
    $form_state['values']['title_field'][$language->language][0]['value'] :
    (isset($form_state['values']['title_field'][LANGUAGE_NONE][0]['value']) ?
        $form_state['values']['title_field'][LANGUAGE_NONE][0]['value'] : ''
     );
  if (drupal_strlen($title_field) > $limit) {
    form_set_error('title', t('Project name must be less than @limit characters.', array(
      '@limit' => $limit,
    )));
  }
}

/**
 * Generates the the sort by menu.
 *
 * @return array
 *   Renderable array.
 */
function _budg_eu_projects_search_projects_sort($form, &$form_state) {
  include_once 'budg_eu_projects.functions.inc';

  $result_display = _budg_eu_projects_result_display();

  $sort = $result_display['sort'];
  $order = $result_display['order'];
  $order_sort = $order . '|' . $sort;

  $field_title = t("Sort by");
  $sort = array(
    '' => $field_title,
    'title|asc' => t('Project Name A-Z'),
    'title|desc' => t('Project Name Z-A'),
    'field_eu_budget_contribution|asc' => t('EU contribution A-Z'),
    'field_eu_budget_contribution|desc' => t('EU contribution Z-A'),
  );

  $options = array();
  foreach ($sort as $field => $title) {
    $options[$field] = $title;
  }

  $form = array();
  $form['sort_menu'] = array(
    'q' => array(
      '#type' => 'value',
      '#value' => isset($form_state['values']['q']) ? $form_state['values']['q'] : $_GET['q'],
    ),
    'sort_order' => array(
      '#type' => 'select',
      '#name' => 'order_sort',
      '#options' => $options,
      '#value' => $order_sort,
    ),
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('submit'),
    ),
  );
  $_GET['q'] = isset($form_state['values']['q']) ? $form_state['values']['q'] : $_GET['q'];

  return $form;
}

/**
 * Generates the the project search form.
 *
 * @return array
 *   Renderable array.
 */
function _budg_eu_projects_search_projects($form, &$form_state) {
  include_once 'budg_eu_projects.functions.inc';
  global $language;

  $params = drupal_get_query_parameters([
    $_GET,
  ], array(
    'form_build_id',
    'form_token',
    'form_id',
  ));
  $params = $params[0];
  $default_values = _budg_eu_projects_default_search_values($params);
  $default_fields = _budg_eu_projects_solr_default_fields();

  $solr_values = array();
  foreach ($default_values as $variable => $value) {
    if (isset($default_fields[$variable]['value_mapping'][$value]['solr'])) {
      $solr_values[$variable] = $default_fields[$variable]['value_mapping'][$value]['solr'];
    }
    else {
      $solr_values[$variable] = $value;
    }
  }

  // The form.
  $form = array(
    '#method' => 'get',
    '#token' => FALSE,
    '#after_build' => array(
      '_budg_eu_projects_unset_default_form_elements',
    ),
    'q' => array(
      '#type' => 'value',
      '#value' => 'search-projects_' . $language->language,
    ),
    '#action' => 'search-projects_' . $language->language,
    'form' => array(
      '#prefix' => '<div class="project-search">',
      'fields' => array(
        '#prefix' => '<div class="fields">',
        'advanced_basic' => array(
          '#prefix' => '<div class="field-group basic-search">',
        ),
      ),
    ),
  );

  // The fields.
  $i = 0;
  $search_type = 'basic_search';
  foreach ($default_fields as $field => $values) {
    if ($values['field_type'] == 'hidden') {
      $form[$field] = array(
        '#type' => 'hidden',
        '#value' => $values['value'],
      );
    }
    else {
      $i++;
      if (!in_array($field, array('content'))) {
        $options = $default_options = array(
          'All' => t('- Any -'),
        );
        $adapted_params = $solr_values;
        $adapted_params[$field] = 'All';
        $q = budg_eu_projects_params_to_solr_q($adapted_params);
        if (!in_array($field, array('its_field_eu_budget_contribution'))) {
          $solr_options = array(
            'q' => $q,
            'wt' => 'phps',
            'rows' => 0,
            'facet' => 'true',
            'facet.field' => $field,
          );
          $response = _budg_eu_projects_solr_response($solr_options);
          $response = isset($response->data) ? unserialize($response->data) : array();
        }
        elseif ($field == 'its_field_eu_budget_contribution') {
          foreach ($default_fields[$field]['value_mapping'] as $value => $criteria) {
            $facet_query = $field . ':' . $criteria['solr'];
            $solr_options = array(
              'q' => $q,
              'wt' => 'phps',
              'rows' => 0,
              'facet' => 'true',
              'facet.field' => $field,
              'facet.query' => $facet_query,
            );
            $response = _budg_eu_projects_solr_response($solr_options);
            $response = isset($response->data) ? unserialize($response->data) : array();
            $available_values = isset($response['facet_counts']['facet_queries'][$facet_query]) ? $response['facet_counts']['facet_queries'][$facet_query] : 0;
            if ($available_values > 0) {
              $options[$value] = $default_fields[$field]['value'][$value];
            }
          }
        }
      }
      $available_values = isset($response['facet_counts']['facet_fields'][$field]) ? array_filter($response['facet_counts']['facet_fields'][$field]) : array();

      $first = array();

      // Countries.
      if ($field == 'sm_af_country') {
        include_once DRUPAL_ROOT . '/includes/locale.inc';
        $all_values = country_get_list();

        $ec_countries = array(
          'BE',
          'BG',
          'CZ',
          'DK',
          'DE',
          'EE',
          'IE',
          'EL',
          'ES',
          'FR',
          'HR',
          'IT',
          'CY',
          'LV',
          'LT',
          'LU',
          'HU',
          'MT',
          'NL',
          'AT',
          'PL',
          'PT',
          'RO',
          'SI',
          'SK',
          'FI',
          'SE',
          'UK',
        );

        $first = array();
        $second = array();
        foreach ($available_values as $code => $number) {
          if (isset($all_values[$code])) {
            if (in_array($code, $ec_countries)) {
              $first[$code] = $all_values[$code];
            }
            else {
              $second[$code] = $all_values[$code];
            }
          }
        }
        asort($first);
        asort($second);
        $options = array_merge($options, $first, $second);
      }
      elseif (!in_array($field, array('content', 'its_field_eu_budget_contribution'))) {
        if (!isset($values['value'])) {
          $terms = i18n_taxonomy_localize_terms(taxonomy_term_load_multiple(array_keys($available_values)));
          foreach ($terms as $tid => $term) {
            $options[$tid] = $term->name;
          }
        }
        else {
          $options = array_replace($default_options, $values['value']);
        }
      }
      if ($i == 3) {
        $form['project_search']['form']['fields']['advanced_basic'][$search_type]['#suffix'] = '</div>';
        $search_type = 'advance_search';
        $form['project_search']['form']['fields']['advanced_basic'][$search_type]['#prefix'] = '<div class="field-group advanced-search">';
      }
      $form['project_search']['form']['fields']['advanced_basic'][$search_type][$field] = array(
        '#type' => $values['field_type'],
        '#name' => $field,
        '#value' => isset($default_values[$field]) ? $default_values[$field] : '',
      );

      if (isset($values['title'])) {
        $form['project_search']['form']['fields']['advanced_basic'][$search_type][$field]['#title'] = $values['title'];
      }

      if ($values['field_type'] == 'select') {
        $form['project_search']['form']['fields']['advanced_basic'][$search_type][$field]['#options'] = $options;
      }
    }
  }

  $form['project_search']['form']['fields']['advanced_basic'][$search_type]['#suffix'] = '</div>';
  $form['project_search']['form']['fields']['advanced_basic']['#suffix'] = '</div>';
  $form['project_search']['form']['buttons'] = array(
    '#prefix' => '<div class="buttons">',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Apply'),
      '#attributes' => array(
        'class' => array(
          'btn-primary',
          'form-submit',
        ),
      ),
    ),
    'clear' => array(
      '#name' => 'clear',
      '#type' => 'submit',
      '#value' => t('Clear'),
      '#attributes' => array(
        'class' => array(
          'form-clear',
        ),
      ),
    ),
    '#suffix' => '</div>',
  );
  $form['project_search']['form']['#suffix'] = '</div>';

  return $form;
}

/**
 * Stores the submitted values.
 */
function _budg_eu_projects_search_projects_sort_submit($form, &$form_state) {
  _budg_eu_projects_result_display($form_state['values']);
}

/**
 * Cleans the url.
 */
function _budg_eu_projects_unset_default_form_elements($form) {
  unset($form['#build_id'], $form['form_build_id'], $form['form_id']);
  return $form;
}
