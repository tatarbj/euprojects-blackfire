<?php

/**
 * @file
 * Implements indexing of addressfield fields.
 *
 * Taken from: https://www.drupal.org/project/apachesolr_addressfield.
 *
 * By default addressfield fields don't get indexed. Here apachesolr hooks and
 * facetapi hooks are used to index the addressfield field.
 */

/**
 * Maps the addressfield field to a solr definition.
 *
 * @return array
 *   $mappings is an array containing all the field mappings.
 */
function budg_eu_projects_apachesolr_field_mappings() {
  $fields = field_info_fields();
  $mappings = array();
  foreach ($fields as $field) {
    if ($field['type'] == 'addressfield') {
      $mappings['per-field'][$field['field_name']] = array(
        // REQUIRED FIELDS.
        // Function callback to return the value that will be put in the
        // solr index.
        'indexing_callback' => 'budg_eu_projects_fields_indexing_callback',
        // 'map callback' => 'budg_eu_projects_map_callback',
        // NON REQUIRED FIELDS.
        // See apachesolr_index_key() for the correct type. Defaults string.
        'index_type' => 'addressfield',
        // We do not want default facet for the lat/lon until there is a widget
        // that can support this (Slider?)
        'facets' => FALSE,
        'multiple' => FALSE,
        'query types' => array('term'),
      );
    }
  }
  return $mappings;
}

/**
 * Takes the values from the field and tells the module where to put them.
 *
 * @param object $entity
 *   An object containing the entity that will get indexed.
 * @param string $field_name
 *   A string containing the name of the location field.
 * @param string $index_key
 *   A string containing the solr index field name.
 * @param array $field_info
 *   Array.
 *
 * @return array
 *   An array containing all the fields that needs to be indexed.
 */
function budg_eu_projects_fields_indexing_callback($entity, $field_name, $index_key, $field_info) {
  $fields = array();

  if (!empty($entity->{$field_name})) {
    $field_address = (array_key_exists($entity->language, $entity->{$field_name}) && is_array($entity->{$field_name}[$entity->language])) ?
      $entity->{$field_name}[$entity->language] :
      $entity->{$field_name}[LANGUAGE_NONE];

    if (!empty($field_address)) {
      foreach ($field_address as $item) {
        foreach ($item as $property => $value) {
          if (!empty($value)) {
            $field = array(
              'index_type' => 'string',
              'name' => 'af_' . $property,
              'multiple' => TRUE,
            );
            $field_index_key = apachesolr_index_key($field);
            $fields[] = array(
              'key' => $field_index_key,
              'value' => $value,
            );
          }
        }
      }
    }
  }

  return $fields;
}

/**
 * Implements hook_facetapi_facet_info().
 *
 * Provides the definitions for the extra facets.
 */
function budg_eu_projects_facetapi_facet_info($searcher_info) {
  $facets = array();
  $property_infos = addressfield_data_property_info();
  foreach ($property_infos as $property => $info) {
    $facets[$property] = array(
      'name' => $property,
      'label' => $info['label'],
      'description' => t('Filter by @label.', array('@label' => $info['label'])),
      'field' => 'sm_af_' . $property,
      'field alias' => $property,
      'field api bundles' => array('node'),
      'facet mincount allowed' => TRUE,
      'dependency plugins' => array('bundle', 'role'),
    );
  }

  $facets['country']['map callback'] = 'country_get_list';

  return $facets;
}
