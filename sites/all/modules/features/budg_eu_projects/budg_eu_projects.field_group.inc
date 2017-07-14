<?php
/**
 * @file
 * budg_eu_projects.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function budg_eu_projects_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_1|node|project|form';
  $field_group->group_name = 'group_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs1';
  $field_group->data = array(
    'label' => 'Budget information',
    'weight' => '2',
    'children' => array(
      0 => 'field_broad_area',
      1 => 'field_ec_priorities_',
      2 => 'field_eu_budget_contribution',
      3 => 'field_eu_budget_mff_heading',
      4 => 'field_programme_name',
      5 => 'field_total_project_budget',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_1|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_2|node|project|form';
  $field_group->group_name = 'group_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs1';
  $field_group->data = array(
    'label' => 'Project information',
    'weight' => '1',
    'children' => array(
      0 => 'field_coordinating_organisations',
      1 => 'field_gps_coordinates_project',
      2 => 'field_project_acronym',
      3 => 'field_project_location',
      4 => 'field_project_partner',
      5 => 'field_project_webpage',
      6 => 'field_related_link_s_',
      7 => 'field_timeframe',
      8 => 'field_visual',
      9 => 'field_description',
      10 => 'field_project_achievements',
      11 => 'field_disclaimer',
      12 => 'field_video',
      13 => 'field_original_id',
      14 => 'title_field',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_2|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_3|node|project|form';
  $field_group->group_name = 'group_3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs1';
  $field_group->data = array(
    'label' => 'Invest EU',
    'weight' => '3',
    'children' => array(
      0 => 'field_subtitle',
      1 => 'field_background_information',
      2 => 'field_campaign',
      3 => 'field_projects_banner',
      4 => 'field_projects_banner_slogan',
      5 => 'field_project_documents',
      6 => 'field_project_summary',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_3|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_4|node|project|form';
  $field_group->group_name = 'group_4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs1';
  $field_group->data = array(
    'label' => 'DGT',
    'weight' => '4',
    'children' => array(
      0 => 'field_dgt_editor',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-4 field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_4|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_5|node|project|form';
  $field_group->group_name = 'group_5';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs1';
  $field_group->data = array(
    'label' => 'Currently not used',
    'weight' => '5',
    'children' => array(
      0 => 'field_beneficiary_location',
      1 => 'field_beneficiary_region_nuts_',
      2 => 'field_gps_coordinates_beneficiar',
      3 => 'field_project_region_nuts_',
      4 => 'field_link_to_a_video',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-5 field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_5|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|project|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '3',
    'children' => array(
      0 => 'field_coordinating_organisations',
      1 => 'field_ec_priorities_',
      2 => 'field_eu_budget_contribution',
      3 => 'field_programme_name',
      4 => 'field_project_location',
      5 => 'field_project_partner',
      6 => 'field_project_webpage',
      7 => 'field_timeframe',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'element' => 'div',
        'show_label' => 0,
        'label_element' => 'div',
        'classes' => 'group-details field-group-html-element',
        'attributes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_details|node|project|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs1|node|project|form';
  $field_group->group_name = 'group_tabs1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'group_1',
      1 => 'group_2',
      2 => 'group_3',
      3 => 'group_4',
      4 => 'group_5',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabs1 field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_tabs1|node|project|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Budget information');
  t('Currently not used');
  t('DGT');
  t('Details');
  t('Invest EU');
  t('Project information');

  return $field_groups;
}
