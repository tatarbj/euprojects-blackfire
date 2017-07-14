<?php
/**
 * @file
 * budg_eu_projects.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function budg_eu_projects_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_visual',
        1 => 'field_description',
        2 => 'field_project_achievements',
      ),
      'right' => array(
        3 => 'group_details',
        4 => 'field_related_link_s_',
        5 => 'field_programme_name',
        6 => 'field_ec_priorities_',
        8 => 'field_coordinating_organisations',
        9 => 'field_eu_budget_contribution',
        10 => 'field_project_partner',
        11 => 'field_project_location',
        12 => 'field_timeframe',
        13 => 'field_project_webpage',
      ),
      'footer' => array(
        7 => 'field_disclaimer',
      ),
    ),
    'fields' => array(
      'field_visual' => 'left',
      'field_description' => 'left',
      'field_project_achievements' => 'left',
      'group_details' => 'right',
      'field_related_link_s_' => 'right',
      'field_programme_name' => 'right',
      'field_ec_priorities_' => 'right',
      'field_disclaimer' => 'footer',
      'field_coordinating_organisations' => 'right',
      'field_eu_budget_contribution' => 'right',
      'field_project_partner' => 'right',
      'field_project_location' => 'right',
      'field_timeframe' => 'right',
      'field_project_webpage' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|project|default'] = $ds_layout;

  return $export;
}
