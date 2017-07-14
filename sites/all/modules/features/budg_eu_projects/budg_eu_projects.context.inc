<?php
/**
 * @file
 * budg_eu_projects.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function budg_eu_projects_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage_custom';
  $context->description = 'context of homepage';
  $context->tag = 'hompeage';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'budg_eu_projects-project_search' => array(
          'module' => 'budg_eu_projects',
          'delta' => 'project_search',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'budg_eu_projects-view_switcher_results' => array(
          'module' => 'budg_eu_projects',
          'delta' => 'view_switcher_results',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'search-page',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('context of homepage');
  t('hompeage');
  $export['homepage_custom'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'project_page';
  $context->description = '';
  $context->tag = 'project';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'project' => 'project',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'budg_eu_projects-project_search' => array(
          'module' => 'budg_eu_projects',
          'delta' => 'project_search',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'budg_eu_projects-view_switcher_results' => array(
          'module' => 'budg_eu_projects',
          'delta' => 'view_switcher_results',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('project');
  $export['project_page'] = $context;

  return $export;
}
