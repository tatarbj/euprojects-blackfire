<?php
/**
 * @file
 * budg_eu_projects.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function budg_eu_projects_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'project_additional_content_data_interface';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Project additional content data interface';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Project Additional Content data interface data interface';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['required'] = TRUE;
  /* Relationship: Content: Videos (field_videos:fid) */
  $handler->display->display_options['relationships']['field_videos_fid']['id'] = 'field_videos_fid';
  $handler->display->display_options['relationships']['field_videos_fid']['table'] = 'field_data_field_videos';
  $handler->display->display_options['relationships']['field_videos_fid']['field'] = 'field_videos_fid';
  /* Relationship: Content: Visuals (field_visuals:fid) */
  $handler->display->display_options['relationships']['field_visuals_fid']['id'] = 'field_visuals_fid';
  $handler->display->display_options['relationships']['field_visuals_fid']['table'] = 'field_data_field_visuals';
  $handler->display->display_options['relationships']['field_visuals_fid']['field'] = 'field_visuals_fid';
  /* Relationship: Content: Documents (field_pac_documents:fid) */
  $handler->display->display_options['relationships']['field_pac_documents_fid']['id'] = 'field_pac_documents_fid';
  $handler->display->display_options['relationships']['field_pac_documents_fid']['table'] = 'field_data_field_pac_documents';
  $handler->display->display_options['relationships']['field_pac_documents_fid']['field'] = 'field_pac_documents_fid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Subtitle */
  $handler->display->display_options['fields']['field_pac_subtitle']['id'] = 'field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle']['field'] = 'field_pac_subtitle';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_videos_fid';
  $handler->display->display_options['fields']['uri']['label'] = 'Videos';
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri_1']['id'] = 'uri_1';
  $handler->display->display_options['fields']['uri_1']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri_1']['field'] = 'uri';
  $handler->display->display_options['fields']['uri_1']['relationship'] = 'field_visuals_fid';
  $handler->display->display_options['fields']['uri_1']['label'] = 'Visuals';
  $handler->display->display_options['fields']['uri_1']['file_download_path'] = TRUE;
  /* Field: Content: Project */
  $handler->display->display_options['fields']['field_project']['id'] = 'field_project';
  $handler->display->display_options['fields']['field_project']['table'] = 'field_data_field_project';
  $handler->display->display_options['fields']['field_project']['field'] = 'field_project';
  $handler->display->display_options['fields']['field_project']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_project']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_project']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_project']['separator'] = ';';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_0']['id'] = 'body_et_0';
  $handler->display->display_options['fields']['body_et_0']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_0']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_0']['label'] = 'Body: bg';
  $handler->display->display_options['fields']['body_et_0']['language'] = 'bg';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_0']['id'] = 'title_field_et_0';
  $handler->display->display_options['fields']['title_field_et_0']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_0']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_0']['label'] = 'Title: bg';
  $handler->display->display_options['fields']['title_field_et_0']['language'] = 'bg';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_1']['id'] = 'body_et_1';
  $handler->display->display_options['fields']['body_et_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_1']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_1']['label'] = 'Body: hr';
  $handler->display->display_options['fields']['body_et_1']['language'] = 'hr';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_1']['id'] = 'title_field_et_1';
  $handler->display->display_options['fields']['title_field_et_1']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_1']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_1']['label'] = 'Title: hr';
  $handler->display->display_options['fields']['title_field_et_1']['language'] = 'hr';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_2']['id'] = 'body_et_2';
  $handler->display->display_options['fields']['body_et_2']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_2']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_2']['label'] = 'Body: cs';
  $handler->display->display_options['fields']['body_et_2']['language'] = 'cs';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_2']['id'] = 'title_field_et_2';
  $handler->display->display_options['fields']['title_field_et_2']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_2']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_2']['label'] = 'Title: cs';
  $handler->display->display_options['fields']['title_field_et_2']['language'] = 'cs';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_3']['id'] = 'body_et_3';
  $handler->display->display_options['fields']['body_et_3']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_3']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_3']['label'] = 'Body: da';
  $handler->display->display_options['fields']['body_et_3']['language'] = 'da';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_3']['id'] = 'title_field_et_3';
  $handler->display->display_options['fields']['title_field_et_3']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_3']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_3']['label'] = 'Title: da';
  $handler->display->display_options['fields']['title_field_et_3']['language'] = 'da';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_4']['id'] = 'body_et_4';
  $handler->display->display_options['fields']['body_et_4']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_4']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_4']['label'] = 'Body: nl';
  $handler->display->display_options['fields']['body_et_4']['language'] = 'nl';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_4']['id'] = 'title_field_et_4';
  $handler->display->display_options['fields']['title_field_et_4']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_4']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_4']['label'] = 'Title: nl';
  $handler->display->display_options['fields']['title_field_et_4']['language'] = 'nl';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_5']['id'] = 'body_et_5';
  $handler->display->display_options['fields']['body_et_5']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_5']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_5']['label'] = 'Body: et';
  $handler->display->display_options['fields']['body_et_5']['language'] = 'et';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_5']['id'] = 'title_field_et_5';
  $handler->display->display_options['fields']['title_field_et_5']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_5']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_5']['label'] = 'Title: et';
  $handler->display->display_options['fields']['title_field_et_5']['language'] = 'et';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_6']['id'] = 'body_et_6';
  $handler->display->display_options['fields']['body_et_6']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_6']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_6']['label'] = 'Body: fi';
  $handler->display->display_options['fields']['body_et_6']['language'] = 'fi';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_6']['id'] = 'title_field_et_6';
  $handler->display->display_options['fields']['title_field_et_6']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_6']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_6']['label'] = 'Title: fi';
  $handler->display->display_options['fields']['title_field_et_6']['language'] = 'fi';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_7']['id'] = 'body_et_7';
  $handler->display->display_options['fields']['body_et_7']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_7']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_7']['label'] = 'Body: fr';
  $handler->display->display_options['fields']['body_et_7']['language'] = 'fr';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_7']['id'] = 'title_field_et_7';
  $handler->display->display_options['fields']['title_field_et_7']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_7']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_7']['label'] = 'Title: fr';
  $handler->display->display_options['fields']['title_field_et_7']['language'] = 'fr';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_8']['id'] = 'body_et_8';
  $handler->display->display_options['fields']['body_et_8']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_8']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_8']['label'] = 'Body: de';
  $handler->display->display_options['fields']['body_et_8']['language'] = 'de';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_8']['id'] = 'title_field_et_8';
  $handler->display->display_options['fields']['title_field_et_8']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_8']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_8']['label'] = 'Title: de';
  $handler->display->display_options['fields']['title_field_et_8']['language'] = 'de';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_9']['id'] = 'body_et_9';
  $handler->display->display_options['fields']['body_et_9']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_9']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_9']['label'] = 'Body: el';
  $handler->display->display_options['fields']['body_et_9']['language'] = 'el';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_9']['id'] = 'title_field_et_9';
  $handler->display->display_options['fields']['title_field_et_9']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_9']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_9']['label'] = 'Title: el';
  $handler->display->display_options['fields']['title_field_et_9']['language'] = 'el';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_10']['id'] = 'body_et_10';
  $handler->display->display_options['fields']['body_et_10']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_10']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_10']['label'] = 'Body: hu';
  $handler->display->display_options['fields']['body_et_10']['language'] = 'hu';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_10']['id'] = 'title_field_et_10';
  $handler->display->display_options['fields']['title_field_et_10']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_10']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_10']['label'] = 'Title: hu';
  $handler->display->display_options['fields']['title_field_et_10']['language'] = 'hu';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_11']['id'] = 'body_et_11';
  $handler->display->display_options['fields']['body_et_11']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_11']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_11']['label'] = 'Body: ga';
  $handler->display->display_options['fields']['body_et_11']['language'] = 'ga';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_11']['id'] = 'title_field_et_11';
  $handler->display->display_options['fields']['title_field_et_11']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_11']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_11']['label'] = 'Title: ga';
  $handler->display->display_options['fields']['title_field_et_11']['language'] = 'ga';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_12']['id'] = 'body_et_12';
  $handler->display->display_options['fields']['body_et_12']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_12']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_12']['label'] = 'Body: it';
  $handler->display->display_options['fields']['body_et_12']['language'] = 'it';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_12']['id'] = 'title_field_et_12';
  $handler->display->display_options['fields']['title_field_et_12']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_12']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_12']['label'] = 'Title: it';
  $handler->display->display_options['fields']['title_field_et_12']['language'] = 'it';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_13']['id'] = 'body_et_13';
  $handler->display->display_options['fields']['body_et_13']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_13']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_13']['label'] = 'Body: lv';
  $handler->display->display_options['fields']['body_et_13']['language'] = 'lv';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_13']['id'] = 'title_field_et_13';
  $handler->display->display_options['fields']['title_field_et_13']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_13']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_13']['label'] = 'Title: lv';
  $handler->display->display_options['fields']['title_field_et_13']['language'] = 'lv';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_14']['id'] = 'body_et_14';
  $handler->display->display_options['fields']['body_et_14']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_14']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_14']['label'] = 'Body: lt';
  $handler->display->display_options['fields']['body_et_14']['language'] = 'lt';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_14']['id'] = 'title_field_et_14';
  $handler->display->display_options['fields']['title_field_et_14']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_14']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_14']['label'] = 'Title: lt';
  $handler->display->display_options['fields']['title_field_et_14']['language'] = 'lt';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_15']['id'] = 'body_et_15';
  $handler->display->display_options['fields']['body_et_15']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_15']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_15']['label'] = 'Body: mt';
  $handler->display->display_options['fields']['body_et_15']['language'] = 'mt';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_15']['id'] = 'title_field_et_15';
  $handler->display->display_options['fields']['title_field_et_15']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_15']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_15']['label'] = 'Title: mt';
  $handler->display->display_options['fields']['title_field_et_15']['language'] = 'mt';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_16']['id'] = 'body_et_16';
  $handler->display->display_options['fields']['body_et_16']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_16']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_16']['label'] = 'Body: pl';
  $handler->display->display_options['fields']['body_et_16']['language'] = 'pl';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_16']['id'] = 'title_field_et_16';
  $handler->display->display_options['fields']['title_field_et_16']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_16']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_16']['label'] = 'Title: pl';
  $handler->display->display_options['fields']['title_field_et_16']['language'] = 'pl';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_17']['id'] = 'body_et_17';
  $handler->display->display_options['fields']['body_et_17']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_17']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_17']['label'] = 'Body: pt';
  $handler->display->display_options['fields']['body_et_17']['language'] = 'pt';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_17']['id'] = 'title_field_et_17';
  $handler->display->display_options['fields']['title_field_et_17']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_17']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_17']['label'] = 'Title: pt';
  $handler->display->display_options['fields']['title_field_et_17']['language'] = 'pt';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_18']['id'] = 'body_et_18';
  $handler->display->display_options['fields']['body_et_18']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_18']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_18']['label'] = 'Body: ro';
  $handler->display->display_options['fields']['body_et_18']['language'] = 'ro';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_18']['id'] = 'title_field_et_18';
  $handler->display->display_options['fields']['title_field_et_18']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_18']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_18']['label'] = 'Title: ro';
  $handler->display->display_options['fields']['title_field_et_18']['language'] = 'ro';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_19']['id'] = 'body_et_19';
  $handler->display->display_options['fields']['body_et_19']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_19']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_19']['label'] = 'Body: sk';
  $handler->display->display_options['fields']['body_et_19']['language'] = 'sk';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_19']['id'] = 'title_field_et_19';
  $handler->display->display_options['fields']['title_field_et_19']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_19']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_19']['label'] = 'Title: sk';
  $handler->display->display_options['fields']['title_field_et_19']['language'] = 'sk';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_20']['id'] = 'body_et_20';
  $handler->display->display_options['fields']['body_et_20']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_20']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_20']['label'] = 'Body: sl';
  $handler->display->display_options['fields']['body_et_20']['language'] = 'sl';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_20']['id'] = 'title_field_et_20';
  $handler->display->display_options['fields']['title_field_et_20']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_20']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_20']['label'] = 'Title: sl';
  $handler->display->display_options['fields']['title_field_et_20']['language'] = 'sl';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_21']['id'] = 'body_et_21';
  $handler->display->display_options['fields']['body_et_21']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_21']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_21']['label'] = 'Body: es';
  $handler->display->display_options['fields']['body_et_21']['language'] = 'es';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_21']['id'] = 'title_field_et_21';
  $handler->display->display_options['fields']['title_field_et_21']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_21']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_21']['label'] = 'Title: es';
  $handler->display->display_options['fields']['title_field_et_21']['language'] = 'es';
  /* Field: Entity translation: Body: translated */
  $handler->display->display_options['fields']['body_et_22']['id'] = 'body_et_22';
  $handler->display->display_options['fields']['body_et_22']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_et_22']['field'] = 'body_et';
  $handler->display->display_options['fields']['body_et_22']['label'] = 'Body: sv';
  $handler->display->display_options['fields']['body_et_22']['language'] = 'sv';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_22']['id'] = 'title_field_et_22';
  $handler->display->display_options['fields']['title_field_et_22']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_22']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_22']['label'] = 'Title: sv';
  $handler->display->display_options['fields']['title_field_et_22']['language'] = 'sv';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_0']['id'] = 'field_pac_subtitle_0';
  $handler->display->display_options['fields']['field_pac_subtitle_0']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_0']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_0']['label'] = 'Subtitle: bg';
  $handler->display->display_options['fields']['field_pac_subtitle_0']['language'] = 'bg';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_1']['id'] = 'field_pac_subtitle_1';
  $handler->display->display_options['fields']['field_pac_subtitle_1']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_1']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_1']['label'] = 'Subtitle: cs';
  $handler->display->display_options['fields']['field_pac_subtitle_1']['language'] = 'cs';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_2']['id'] = 'field_pac_subtitle_2';
  $handler->display->display_options['fields']['field_pac_subtitle_2']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_2']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_2']['label'] = 'Subtitle: da';
  $handler->display->display_options['fields']['field_pac_subtitle_2']['language'] = 'da';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_3']['id'] = 'field_pac_subtitle_3';
  $handler->display->display_options['fields']['field_pac_subtitle_3']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_3']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_3']['label'] = 'Subtitle: de';
  $handler->display->display_options['fields']['field_pac_subtitle_3']['language'] = 'de';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_4']['id'] = 'field_pac_subtitle_4';
  $handler->display->display_options['fields']['field_pac_subtitle_4']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_4']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_4']['label'] = 'Subtitle: el';
  $handler->display->display_options['fields']['field_pac_subtitle_4']['language'] = 'el';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_5']['id'] = 'field_pac_subtitle_5';
  $handler->display->display_options['fields']['field_pac_subtitle_5']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_5']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_5']['label'] = 'Subtitle: en';
  $handler->display->display_options['fields']['field_pac_subtitle_5']['language'] = 'en';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_6']['id'] = 'field_pac_subtitle_6';
  $handler->display->display_options['fields']['field_pac_subtitle_6']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_6']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_6']['label'] = 'Subtitle: es';
  $handler->display->display_options['fields']['field_pac_subtitle_6']['language'] = 'es';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_7']['id'] = 'field_pac_subtitle_7';
  $handler->display->display_options['fields']['field_pac_subtitle_7']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_7']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_7']['label'] = 'Subtitle: et';
  $handler->display->display_options['fields']['field_pac_subtitle_7']['language'] = 'et';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_8']['id'] = 'field_pac_subtitle_8';
  $handler->display->display_options['fields']['field_pac_subtitle_8']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_8']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_8']['label'] = 'Subtitle: fi';
  $handler->display->display_options['fields']['field_pac_subtitle_8']['language'] = 'fi';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_9']['id'] = 'field_pac_subtitle_9';
  $handler->display->display_options['fields']['field_pac_subtitle_9']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_9']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_9']['label'] = 'Subtitle: fr';
  $handler->display->display_options['fields']['field_pac_subtitle_9']['language'] = 'fr';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_10']['id'] = 'field_pac_subtitle_10';
  $handler->display->display_options['fields']['field_pac_subtitle_10']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_10']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_10']['label'] = 'Subtitle: ga';
  $handler->display->display_options['fields']['field_pac_subtitle_10']['language'] = 'ga';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_11']['id'] = 'field_pac_subtitle_11';
  $handler->display->display_options['fields']['field_pac_subtitle_11']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_11']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_11']['label'] = 'Subtitle: hr';
  $handler->display->display_options['fields']['field_pac_subtitle_11']['language'] = 'hr';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_12']['id'] = 'field_pac_subtitle_12';
  $handler->display->display_options['fields']['field_pac_subtitle_12']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_12']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_12']['label'] = 'Subtitle: hu';
  $handler->display->display_options['fields']['field_pac_subtitle_12']['language'] = 'hu';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_13']['id'] = 'field_pac_subtitle_13';
  $handler->display->display_options['fields']['field_pac_subtitle_13']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_13']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_13']['label'] = 'Subtitle: it';
  $handler->display->display_options['fields']['field_pac_subtitle_13']['language'] = 'it';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_14']['id'] = 'field_pac_subtitle_14';
  $handler->display->display_options['fields']['field_pac_subtitle_14']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_14']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_14']['label'] = 'Subtitle: lt';
  $handler->display->display_options['fields']['field_pac_subtitle_14']['language'] = 'lt';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_15']['id'] = 'field_pac_subtitle_15';
  $handler->display->display_options['fields']['field_pac_subtitle_15']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_15']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_15']['label'] = 'Subtitle: lv';
  $handler->display->display_options['fields']['field_pac_subtitle_15']['language'] = 'lv';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_16']['id'] = 'field_pac_subtitle_16';
  $handler->display->display_options['fields']['field_pac_subtitle_16']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_16']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_16']['label'] = 'Subtitle: mt';
  $handler->display->display_options['fields']['field_pac_subtitle_16']['language'] = 'mt';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_17']['id'] = 'field_pac_subtitle_17';
  $handler->display->display_options['fields']['field_pac_subtitle_17']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_17']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_17']['label'] = 'Subtitle: nl';
  $handler->display->display_options['fields']['field_pac_subtitle_17']['language'] = 'nl';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_18']['id'] = 'field_pac_subtitle_18';
  $handler->display->display_options['fields']['field_pac_subtitle_18']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_18']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_18']['label'] = 'Subtitle: pl';
  $handler->display->display_options['fields']['field_pac_subtitle_18']['language'] = 'pl';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_19']['id'] = 'field_pac_subtitle_19';
  $handler->display->display_options['fields']['field_pac_subtitle_19']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_19']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_19']['label'] = 'Subtitle: pt';
  $handler->display->display_options['fields']['field_pac_subtitle_19']['language'] = 'pt';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_20']['id'] = 'field_pac_subtitle_20';
  $handler->display->display_options['fields']['field_pac_subtitle_20']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_20']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_20']['label'] = 'Subtitle: ro';
  $handler->display->display_options['fields']['field_pac_subtitle_20']['language'] = 'ro';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_21']['id'] = 'field_pac_subtitle_21';
  $handler->display->display_options['fields']['field_pac_subtitle_21']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_21']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_21']['label'] = 'Subtitle: sk';
  $handler->display->display_options['fields']['field_pac_subtitle_21']['language'] = 'sk';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_22']['id'] = 'field_pac_subtitle_22';
  $handler->display->display_options['fields']['field_pac_subtitle_22']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_22']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_22']['label'] = 'Subtitle: sl';
  $handler->display->display_options['fields']['field_pac_subtitle_22']['language'] = 'sl';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_pac_subtitle_23']['id'] = 'field_pac_subtitle_23';
  $handler->display->display_options['fields']['field_pac_subtitle_23']['table'] = 'field_data_field_pac_subtitle';
  $handler->display->display_options['fields']['field_pac_subtitle_23']['field'] = 'field_pac_subtitle_et';
  $handler->display->display_options['fields']['field_pac_subtitle_23']['label'] = 'Subtitle: sv';
  $handler->display->display_options['fields']['field_pac_subtitle_23']['language'] = 'sv';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri_2']['id'] = 'uri_2';
  $handler->display->display_options['fields']['uri_2']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri_2']['field'] = 'uri';
  $handler->display->display_options['fields']['uri_2']['relationship'] = 'field_pac_documents_fid';
  $handler->display->display_options['fields']['uri_2']['label'] = 'Documents';
  $handler->display->display_options['fields']['uri_2']['file_download_path'] = TRUE;
  /* Field: Content: External links */
  $handler->display->display_options['fields']['field_pac_external_links']['id'] = 'field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links']['field'] = 'field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links']['label'] = 'External links: title';
  $handler->display->display_options['fields']['field_pac_external_links']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_pac_external_links']['separator'] = ';';
  /* Field: Content: External links */
  $handler->display->display_options['fields']['field_pac_external_links_1']['id'] = 'field_pac_external_links_1';
  $handler->display->display_options['fields']['field_pac_external_links_1']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_1']['field'] = 'field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_1']['label'] = 'External links: url';
  $handler->display->display_options['fields']['field_pac_external_links_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_1']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_pac_external_links_1']['separator'] = ';';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_3']['id'] = 'field_pac_external_links_3';
  $handler->display->display_options['fields']['field_pac_external_links_3']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_3']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_3']['label'] = 'External Links title: bg';
  $handler->display->display_options['fields']['field_pac_external_links_3']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_3']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_3']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_3']['language'] = 'bg';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_43']['id'] = 'field_pac_external_links_43';
  $handler->display->display_options['fields']['field_pac_external_links_43']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_43']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_43']['label'] = 'External Links url: bg';
  $handler->display->display_options['fields']['field_pac_external_links_43']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_43']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_43']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_43']['language'] = 'bg';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_4']['id'] = 'field_pac_external_links_4';
  $handler->display->display_options['fields']['field_pac_external_links_4']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_4']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_4']['label'] = 'External Links title: cs';
  $handler->display->display_options['fields']['field_pac_external_links_4']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_4']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_4']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_4']['language'] = 'cs';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_44']['id'] = 'field_pac_external_links_44';
  $handler->display->display_options['fields']['field_pac_external_links_44']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_44']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_44']['label'] = 'External Links url: cs';
  $handler->display->display_options['fields']['field_pac_external_links_44']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_44']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_44']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_44']['language'] = 'cs';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_5']['id'] = 'field_pac_external_links_5';
  $handler->display->display_options['fields']['field_pac_external_links_5']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_5']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_5']['label'] = 'External Links title: da';
  $handler->display->display_options['fields']['field_pac_external_links_5']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_5']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_5']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_5']['language'] = 'da';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_45']['id'] = 'field_pac_external_links_45';
  $handler->display->display_options['fields']['field_pac_external_links_45']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_45']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_45']['label'] = 'External Links url: da';
  $handler->display->display_options['fields']['field_pac_external_links_45']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_45']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_45']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_45']['language'] = 'da';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_6']['id'] = 'field_pac_external_links_6';
  $handler->display->display_options['fields']['field_pac_external_links_6']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_6']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_6']['label'] = 'External Links title: de';
  $handler->display->display_options['fields']['field_pac_external_links_6']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_6']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_6']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_6']['language'] = 'de';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_46']['id'] = 'field_pac_external_links_46';
  $handler->display->display_options['fields']['field_pac_external_links_46']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_46']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_46']['label'] = 'External Links url: de';
  $handler->display->display_options['fields']['field_pac_external_links_46']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_46']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_46']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_46']['language'] = 'de';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_7']['id'] = 'field_pac_external_links_7';
  $handler->display->display_options['fields']['field_pac_external_links_7']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_7']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_7']['label'] = 'External Links title: el';
  $handler->display->display_options['fields']['field_pac_external_links_7']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_7']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_7']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_7']['language'] = 'el';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_47']['id'] = 'field_pac_external_links_47';
  $handler->display->display_options['fields']['field_pac_external_links_47']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_47']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_47']['label'] = 'External Links url: el';
  $handler->display->display_options['fields']['field_pac_external_links_47']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_47']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_47']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_47']['language'] = 'el';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_8']['id'] = 'field_pac_external_links_8';
  $handler->display->display_options['fields']['field_pac_external_links_8']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_8']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_8']['label'] = 'External Links title: en';
  $handler->display->display_options['fields']['field_pac_external_links_8']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_8']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_8']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_8']['language'] = 'en';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_48']['id'] = 'field_pac_external_links_48';
  $handler->display->display_options['fields']['field_pac_external_links_48']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_48']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_48']['label'] = 'External Links url: en';
  $handler->display->display_options['fields']['field_pac_external_links_48']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_48']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_48']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_48']['language'] = 'en';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_9']['id'] = 'field_pac_external_links_9';
  $handler->display->display_options['fields']['field_pac_external_links_9']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_9']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_9']['label'] = 'External Links title: es';
  $handler->display->display_options['fields']['field_pac_external_links_9']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_9']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_9']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_9']['language'] = 'es';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_49']['id'] = 'field_pac_external_links_49';
  $handler->display->display_options['fields']['field_pac_external_links_49']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_49']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_49']['label'] = 'External Links url: es';
  $handler->display->display_options['fields']['field_pac_external_links_49']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_49']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_49']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_49']['language'] = 'es';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_10']['id'] = 'field_pac_external_links_10';
  $handler->display->display_options['fields']['field_pac_external_links_10']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_10']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_10']['label'] = 'External Links title: et';
  $handler->display->display_options['fields']['field_pac_external_links_10']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_10']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_10']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_10']['language'] = 'et';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_50']['id'] = 'field_pac_external_links_50';
  $handler->display->display_options['fields']['field_pac_external_links_50']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_50']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_50']['label'] = 'External Links url: et';
  $handler->display->display_options['fields']['field_pac_external_links_50']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_50']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_50']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_50']['language'] = 'et';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_11']['id'] = 'field_pac_external_links_11';
  $handler->display->display_options['fields']['field_pac_external_links_11']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_11']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_11']['label'] = 'External Links title: fi';
  $handler->display->display_options['fields']['field_pac_external_links_11']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_11']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_11']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_11']['language'] = 'fi';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_51']['id'] = 'field_pac_external_links_51';
  $handler->display->display_options['fields']['field_pac_external_links_51']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_51']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_51']['label'] = 'External Links url: fi';
  $handler->display->display_options['fields']['field_pac_external_links_51']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_51']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_51']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_51']['language'] = 'fi';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_12']['id'] = 'field_pac_external_links_12';
  $handler->display->display_options['fields']['field_pac_external_links_12']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_12']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_12']['label'] = 'External Links title: fr';
  $handler->display->display_options['fields']['field_pac_external_links_12']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_12']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_12']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_12']['language'] = 'fr';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_52']['id'] = 'field_pac_external_links_52';
  $handler->display->display_options['fields']['field_pac_external_links_52']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_52']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_52']['label'] = 'External Links url: fr';
  $handler->display->display_options['fields']['field_pac_external_links_52']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_52']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_52']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_52']['language'] = 'fr';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_13']['id'] = 'field_pac_external_links_13';
  $handler->display->display_options['fields']['field_pac_external_links_13']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_13']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_13']['label'] = 'External Links title: ga';
  $handler->display->display_options['fields']['field_pac_external_links_13']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_13']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_13']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_13']['language'] = 'ga';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_53']['id'] = 'field_pac_external_links_53';
  $handler->display->display_options['fields']['field_pac_external_links_53']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_53']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_53']['label'] = 'External Links url: ga';
  $handler->display->display_options['fields']['field_pac_external_links_53']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_53']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_53']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_53']['language'] = 'ga';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_14']['id'] = 'field_pac_external_links_14';
  $handler->display->display_options['fields']['field_pac_external_links_14']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_14']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_14']['label'] = 'External Links title: hr';
  $handler->display->display_options['fields']['field_pac_external_links_14']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_14']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_14']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_14']['language'] = 'hr';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_54']['id'] = 'field_pac_external_links_54';
  $handler->display->display_options['fields']['field_pac_external_links_54']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_54']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_54']['label'] = 'External Links url: hr';
  $handler->display->display_options['fields']['field_pac_external_links_54']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_54']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_54']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_54']['language'] = 'hr';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_15']['id'] = 'field_pac_external_links_15';
  $handler->display->display_options['fields']['field_pac_external_links_15']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_15']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_15']['label'] = 'External Links title: hu';
  $handler->display->display_options['fields']['field_pac_external_links_15']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_15']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_15']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_15']['language'] = 'hu';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_55']['id'] = 'field_pac_external_links_55';
  $handler->display->display_options['fields']['field_pac_external_links_55']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_55']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_55']['label'] = 'External Links url: hu';
  $handler->display->display_options['fields']['field_pac_external_links_55']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_55']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_55']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_55']['language'] = 'hu';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_16']['id'] = 'field_pac_external_links_16';
  $handler->display->display_options['fields']['field_pac_external_links_16']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_16']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_16']['label'] = 'External Links title: it';
  $handler->display->display_options['fields']['field_pac_external_links_16']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_16']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_16']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_16']['language'] = 'it';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_56']['id'] = 'field_pac_external_links_56';
  $handler->display->display_options['fields']['field_pac_external_links_56']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_56']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_56']['label'] = 'External Links url: it';
  $handler->display->display_options['fields']['field_pac_external_links_56']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_56']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_56']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_56']['language'] = 'it';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_17']['id'] = 'field_pac_external_links_17';
  $handler->display->display_options['fields']['field_pac_external_links_17']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_17']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_17']['label'] = 'External Links title: lt';
  $handler->display->display_options['fields']['field_pac_external_links_17']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_17']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_17']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_17']['language'] = 'lt';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_57']['id'] = 'field_pac_external_links_57';
  $handler->display->display_options['fields']['field_pac_external_links_57']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_57']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_57']['label'] = 'External Links url: lt';
  $handler->display->display_options['fields']['field_pac_external_links_57']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_57']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_57']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_57']['language'] = 'lt';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_18']['id'] = 'field_pac_external_links_18';
  $handler->display->display_options['fields']['field_pac_external_links_18']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_18']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_18']['label'] = 'External Links title: lv';
  $handler->display->display_options['fields']['field_pac_external_links_18']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_18']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_18']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_18']['language'] = 'lv';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_58']['id'] = 'field_pac_external_links_58';
  $handler->display->display_options['fields']['field_pac_external_links_58']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_58']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_58']['label'] = 'External Links url: lv';
  $handler->display->display_options['fields']['field_pac_external_links_58']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_58']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_58']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_58']['language'] = 'lv';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_19']['id'] = 'field_pac_external_links_19';
  $handler->display->display_options['fields']['field_pac_external_links_19']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_19']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_19']['label'] = 'External Links title: mt';
  $handler->display->display_options['fields']['field_pac_external_links_19']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_19']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_19']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_19']['language'] = 'mt';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_59']['id'] = 'field_pac_external_links_59';
  $handler->display->display_options['fields']['field_pac_external_links_59']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_59']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_59']['label'] = 'External Links url: mt';
  $handler->display->display_options['fields']['field_pac_external_links_59']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_59']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_59']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_59']['language'] = 'mt';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_20']['id'] = 'field_pac_external_links_20';
  $handler->display->display_options['fields']['field_pac_external_links_20']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_20']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_20']['label'] = 'External Links title: nl';
  $handler->display->display_options['fields']['field_pac_external_links_20']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_20']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_20']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_20']['language'] = 'nl';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_60']['id'] = 'field_pac_external_links_60';
  $handler->display->display_options['fields']['field_pac_external_links_60']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_60']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_60']['label'] = 'External Links url: nl';
  $handler->display->display_options['fields']['field_pac_external_links_60']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_60']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_60']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_60']['language'] = 'nl';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_21']['id'] = 'field_pac_external_links_21';
  $handler->display->display_options['fields']['field_pac_external_links_21']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_21']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_21']['label'] = 'External Links title: pl';
  $handler->display->display_options['fields']['field_pac_external_links_21']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_21']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_21']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_21']['language'] = 'pl';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_61']['id'] = 'field_pac_external_links_61';
  $handler->display->display_options['fields']['field_pac_external_links_61']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_61']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_61']['label'] = 'External Links url: pl';
  $handler->display->display_options['fields']['field_pac_external_links_61']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_61']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_61']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_61']['language'] = 'pl';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_22']['id'] = 'field_pac_external_links_22';
  $handler->display->display_options['fields']['field_pac_external_links_22']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_22']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_22']['label'] = 'External Links title: pt';
  $handler->display->display_options['fields']['field_pac_external_links_22']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_22']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_22']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_22']['language'] = 'pt';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_62']['id'] = 'field_pac_external_links_62';
  $handler->display->display_options['fields']['field_pac_external_links_62']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_62']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_62']['label'] = 'External Links url: pt';
  $handler->display->display_options['fields']['field_pac_external_links_62']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_62']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_62']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_62']['language'] = 'pt';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_23']['id'] = 'field_pac_external_links_23';
  $handler->display->display_options['fields']['field_pac_external_links_23']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_23']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_23']['label'] = 'External Links title: ro';
  $handler->display->display_options['fields']['field_pac_external_links_23']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_23']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_23']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_23']['language'] = 'ro';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_63']['id'] = 'field_pac_external_links_63';
  $handler->display->display_options['fields']['field_pac_external_links_63']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_63']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_63']['label'] = 'External Links url: ro';
  $handler->display->display_options['fields']['field_pac_external_links_63']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_63']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_63']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_63']['language'] = 'ro';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_24']['id'] = 'field_pac_external_links_24';
  $handler->display->display_options['fields']['field_pac_external_links_24']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_24']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_24']['label'] = 'External Links title: sk';
  $handler->display->display_options['fields']['field_pac_external_links_24']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_24']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_24']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_24']['language'] = 'sk';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_64']['id'] = 'field_pac_external_links_64';
  $handler->display->display_options['fields']['field_pac_external_links_64']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_64']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_64']['label'] = 'External Links url: sk';
  $handler->display->display_options['fields']['field_pac_external_links_64']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_64']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_64']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_64']['language'] = 'sk';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_25']['id'] = 'field_pac_external_links_25';
  $handler->display->display_options['fields']['field_pac_external_links_25']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_25']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_25']['label'] = 'External Links title: sl';
  $handler->display->display_options['fields']['field_pac_external_links_25']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_25']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_25']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_25']['language'] = 'sl';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_65']['id'] = 'field_pac_external_links_65';
  $handler->display->display_options['fields']['field_pac_external_links_65']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_65']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_65']['label'] = 'External Links url: sl';
  $handler->display->display_options['fields']['field_pac_external_links_65']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_65']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_65']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_65']['language'] = 'sl';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_26']['id'] = 'field_pac_external_links_26';
  $handler->display->display_options['fields']['field_pac_external_links_26']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_26']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_26']['label'] = 'External Links title: sv';
  $handler->display->display_options['fields']['field_pac_external_links_26']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_26']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_pac_external_links_26']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_26']['language'] = 'sv';
  /* Field: Entity translation: External links: translated */
  $handler->display->display_options['fields']['field_pac_external_links_66']['id'] = 'field_pac_external_links_66';
  $handler->display->display_options['fields']['field_pac_external_links_66']['table'] = 'field_data_field_pac_external_links';
  $handler->display->display_options['fields']['field_pac_external_links_66']['field'] = 'field_pac_external_links_et';
  $handler->display->display_options['fields']['field_pac_external_links_66']['label'] = 'External Links url: sv';
  $handler->display->display_options['fields']['field_pac_external_links_66']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_pac_external_links_66']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_pac_external_links_66']['separator'] = ';';
  $handler->display->display_options['fields']['field_pac_external_links_66']['language'] = 'sv';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project_additional_content' => 'project_additional_content',
  );
  /* Filter criterion: Entity translation: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'project-additional-content';

  /* Display:  Campaign: invest eu - csv */
  $handler = $view->new_display('views_data_export', ' Campaign: invest eu - csv', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['merge_rows'] = TRUE;
  $handler->display->display_options['field_config'] = array(
    'nid' => array(
      'merge_option' => 'filter',
      'separator' => ';',
    ),
    'title' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'field_pac_subtitle' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'body' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'uri' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'uri_1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'body_et_0' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'title_field_et_0' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'body_et_1' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'title_field_et_1' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'body_et_2' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'title_field_et_2' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'body_et_3' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'title_field_et_3' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'body_et_4' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'title_field_et_4' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'body_et_5' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'title_field_et_5' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'body_et_6' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'title_field_et_6' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'body_et_7' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'title_field_et_7' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'body_et_8' => array(
      'merge_option' => 'first_value',
      'separator' => ';',
    ),
    'title_field_et_8' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'body_et_9' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_et_9' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'body_et_10' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_et_10' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'body_et_11' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_et_11' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'body_et_12' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_et_12' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'body_et_13' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_et_13' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'body_et_14' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_et_14' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'body_et_15' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_et_15' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'body_et_16' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_et_16' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'body_et_17' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_et_17' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'body_et_18' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_et_18' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'body_et_19' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_et_19' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'body_et_20' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_et_20' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'body_et_21' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_et_21' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'body_et_22' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_et_22' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_0' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_2' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_3' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_4' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_5' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_6' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_7' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_8' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_9' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_10' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_11' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_12' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_13' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_14' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_15' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_16' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_17' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_18' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_19' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_20' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_21' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_22' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_pac_subtitle_23' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'uri_2' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
  );
  $handler->display->display_options['path'] = 'export/project-additional-content/csv';
  $export['project_additional_content_data_interface'] = $view;

  $view = new view();
  $view->name = 'project_data_interface';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Project data interface';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Project data interface';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['required'] = TRUE;
  /* Relationship: Content: Video (field_video:fid) */
  $handler->display->display_options['relationships']['field_video_fid']['id'] = 'field_video_fid';
  $handler->display->display_options['relationships']['field_video_fid']['table'] = 'field_data_field_video';
  $handler->display->display_options['relationships']['field_video_fid']['field'] = 'field_video_fid';
  /* Relationship: Content: Visual (field_visual:fid) */
  $handler->display->display_options['relationships']['field_visual_fid']['id'] = 'field_visual_fid';
  $handler->display->display_options['relationships']['field_visual_fid']['table'] = 'field_data_field_visual';
  $handler->display->display_options['relationships']['field_visual_fid']['field'] = 'field_visual_fid';
  /* Relationship: Content: Banner (field_projects_banner:fid) */
  $handler->display->display_options['relationships']['field_projects_banner_fid']['id'] = 'field_projects_banner_fid';
  $handler->display->display_options['relationships']['field_projects_banner_fid']['table'] = 'field_data_field_projects_banner';
  $handler->display->display_options['relationships']['field_projects_banner_fid']['field'] = 'field_projects_banner_fid';
  /* Relationship: Content: Documents (field_project_documents:fid) */
  $handler->display->display_options['relationships']['field_project_documents_fid']['id'] = 'field_project_documents_fid';
  $handler->display->display_options['relationships']['field_project_documents_fid']['table'] = 'field_data_field_project_documents';
  $handler->display->display_options['relationships']['field_project_documents_fid']['field'] = 'field_project_documents_fid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Subtitle */
  $handler->display->display_options['fields']['field_subtitle']['id'] = 'field_subtitle';
  $handler->display->display_options['fields']['field_subtitle']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle']['field'] = 'field_subtitle';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  /* Field: Content: Background information */
  $handler->display->display_options['fields']['field_background_information']['id'] = 'field_background_information';
  $handler->display->display_options['fields']['field_background_information']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information']['field'] = 'field_background_information';
  /* Field: Content: Coordinators */
  $handler->display->display_options['fields']['field_coordinating_organisations']['id'] = 'field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations']['field'] = 'field_coordinating_organisations';
  /* Field: Content: EU Budget contribution to the project */
  $handler->display->display_options['fields']['field_eu_budget_contribution']['id'] = 'field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['table'] = 'field_data_field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['field'] = 'field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['label'] = 'EU Budget contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Funding area */
  $handler->display->display_options['fields']['field_broad_area']['id'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['table'] = 'field_data_field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['field'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_broad_area']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_broad_area']['separator'] = ';';
  /* Field: Content: Partners */
  $handler->display->display_options['fields']['field_project_partner']['id'] = 'field_project_partner';
  $handler->display->display_options['fields']['field_project_partner']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner']['field'] = 'field_project_partner';
  /* Field: Content: Project location - Country */
  $handler->display->display_options['fields']['field_project_location_country']['id'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['fields']['field_project_location_country']['field'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_project_location_country']['display_name'] = 0;
  /* Field: Content: Project location - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_project_location_locality']['id'] = 'field_project_location_locality';
  $handler->display->display_options['fields']['field_project_location_locality']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['fields']['field_project_location_locality']['field'] = 'field_project_location_locality';
  $handler->display->display_options['fields']['field_project_location_locality']['label'] = 'Locality';
  /* Field: Content: Project location - Postal code */
  $handler->display->display_options['fields']['field_project_location_postal_code']['id'] = 'field_project_location_postal_code';
  $handler->display->display_options['fields']['field_project_location_postal_code']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['fields']['field_project_location_postal_code']['field'] = 'field_project_location_postal_code';
  $handler->display->display_options['fields']['field_project_location_postal_code']['label'] = 'Postal code';
  /* Field: Content: Project location - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_project_location_thoroughfare']['id'] = 'field_project_location_thoroughfare';
  $handler->display->display_options['fields']['field_project_location_thoroughfare']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['fields']['field_project_location_thoroughfare']['field'] = 'field_project_location_thoroughfare';
  $handler->display->display_options['fields']['field_project_location_thoroughfare']['label'] = 'address';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_related_link_s_']['id'] = 'field_related_link_s_';
  $handler->display->display_options['fields']['field_related_link_s_']['table'] = 'field_data_field_related_link_s_';
  $handler->display->display_options['fields']['field_related_link_s_']['field'] = 'field_related_link_s_';
  $handler->display->display_options['fields']['field_related_link_s_']['label'] = 'Related links - title';
  $handler->display->display_options['fields']['field_related_link_s_']['alter']['text'] = '[field_related_link_s_-title]';
  $handler->display->display_options['fields']['field_related_link_s_']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_related_link_s_']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_related_link_s_']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_related_link_s_']['separator'] = ';';
  /* Field: Content: Related links */
  $handler->display->display_options['fields']['field_related_link_s__1']['id'] = 'field_related_link_s__1';
  $handler->display->display_options['fields']['field_related_link_s__1']['table'] = 'field_data_field_related_link_s_';
  $handler->display->display_options['fields']['field_related_link_s__1']['field'] = 'field_related_link_s_';
  $handler->display->display_options['fields']['field_related_link_s__1']['label'] = 'Related links - url';
  $handler->display->display_options['fields']['field_related_link_s__1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_related_link_s__1']['type'] = 'link_absolute';
  $handler->display->display_options['fields']['field_related_link_s__1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_related_link_s__1']['separator'] = ';';
  /* Field: Content: Timeframe */
  $handler->display->display_options['fields']['field_timeframe']['id'] = 'field_timeframe';
  $handler->display->display_options['fields']['field_timeframe']['table'] = 'field_data_field_timeframe';
  $handler->display->display_options['fields']['field_timeframe']['field'] = 'field_timeframe';
  $handler->display->display_options['fields']['field_timeframe']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_timeframe']['alter']['text'] = '[field_timeframe-value]';
  $handler->display->display_options['fields']['field_timeframe']['element_type'] = '0';
  $handler->display->display_options['fields']['field_timeframe']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_timeframe']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_timeframe']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_timeframe']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Timeframe */
  $handler->display->display_options['fields']['field_timeframe_1']['id'] = 'field_timeframe_1';
  $handler->display->display_options['fields']['field_timeframe_1']['table'] = 'field_data_field_timeframe';
  $handler->display->display_options['fields']['field_timeframe_1']['field'] = 'field_timeframe';
  $handler->display->display_options['fields']['field_timeframe_1']['label'] = 'Timeframe end';
  $handler->display->display_options['fields']['field_timeframe_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_timeframe_1']['alter']['text'] = '[field_timeframe_1-value2]';
  $handler->display->display_options['fields']['field_timeframe_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_timeframe_1']['element_type'] = '0';
  $handler->display->display_options['fields']['field_timeframe_1']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_timeframe_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_timeframe_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_timeframe_1']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Visual */
  $handler->display->display_options['fields']['field_visual']['id'] = 'field_visual';
  $handler->display->display_options['fields']['field_visual']['table'] = 'field_data_field_visual';
  $handler->display->display_options['fields']['field_visual']['field'] = 'field_visual';
  $handler->display->display_options['fields']['field_visual']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_visual']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_visual']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_visual']['separator'] = ';';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_video_fid';
  $handler->display->display_options['fields']['uri']['label'] = 'Video';
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: Content: Campaign */
  $handler->display->display_options['fields']['field_campaign']['id'] = 'field_campaign';
  $handler->display->display_options['fields']['field_campaign']['table'] = 'field_data_field_campaign';
  $handler->display->display_options['fields']['field_campaign']['field'] = 'field_campaign';
  $handler->display->display_options['fields']['field_campaign']['label'] = '';
  $handler->display->display_options['fields']['field_campaign']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaign']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaign']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_campaign']['delta_offset'] = '0';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri_2']['id'] = 'uri_2';
  $handler->display->display_options['fields']['uri_2']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri_2']['field'] = 'uri';
  $handler->display->display_options['fields']['uri_2']['relationship'] = 'field_projects_banner_fid';
  $handler->display->display_options['fields']['uri_2']['label'] = 'Banner';
  $handler->display->display_options['fields']['uri_2']['file_download_path'] = TRUE;
  /* Field: Content: Banner slogan */
  $handler->display->display_options['fields']['field_projects_banner_slogan']['id'] = 'field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan']['field'] = 'field_projects_banner_slogan';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_0']['id'] = 'title_field_0';
  $handler->display->display_options['fields']['title_field_0']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_0']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_0']['label'] = 'Title: bg';
  $handler->display->display_options['fields']['title_field_0']['language'] = 'bg';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_0']['id'] = 'field_subtitle_0';
  $handler->display->display_options['fields']['field_subtitle_0']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_0']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_0']['label'] = 'Subtitle: bg';
  $handler->display->display_options['fields']['field_subtitle_0']['language'] = 'bg';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_0']['id'] = 'field_background_information_0';
  $handler->display->display_options['fields']['field_background_information_0']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_0']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_0']['label'] = 'Background information: bg';
  $handler->display->display_options['fields']['field_background_information_0']['language'] = 'bg';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_0']['id'] = 'field_description_0';
  $handler->display->display_options['fields']['field_description_0']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_0']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_0']['label'] = 'Description: bg';
  $handler->display->display_options['fields']['field_description_0']['language'] = 'bg';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_1']['id'] = 'title_field_1';
  $handler->display->display_options['fields']['title_field_1']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_1']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_1']['label'] = 'Title: hr';
  $handler->display->display_options['fields']['title_field_1']['language'] = 'hr';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_1']['id'] = 'field_subtitle_1';
  $handler->display->display_options['fields']['field_subtitle_1']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_1']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_1']['label'] = 'Subtitle: hr';
  $handler->display->display_options['fields']['field_subtitle_1']['language'] = 'hr';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_1']['id'] = 'field_background_information_1';
  $handler->display->display_options['fields']['field_background_information_1']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_1']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_1']['label'] = 'Background information: hr';
  $handler->display->display_options['fields']['field_background_information_1']['language'] = 'hr';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_1']['id'] = 'field_description_1';
  $handler->display->display_options['fields']['field_description_1']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_1']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_1']['label'] = 'Description: hr';
  $handler->display->display_options['fields']['field_description_1']['language'] = 'hr';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_2']['id'] = 'title_field_2';
  $handler->display->display_options['fields']['title_field_2']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_2']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_2']['label'] = 'Title: cs';
  $handler->display->display_options['fields']['title_field_2']['language'] = 'cs';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_2']['id'] = 'field_subtitle_2';
  $handler->display->display_options['fields']['field_subtitle_2']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_2']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_2']['label'] = 'Subtitle: cs';
  $handler->display->display_options['fields']['field_subtitle_2']['language'] = 'cs';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_2']['id'] = 'field_background_information_2';
  $handler->display->display_options['fields']['field_background_information_2']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_2']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_2']['label'] = 'Background information: cs';
  $handler->display->display_options['fields']['field_background_information_2']['language'] = 'cs';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_2']['id'] = 'field_description_2';
  $handler->display->display_options['fields']['field_description_2']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_2']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_2']['label'] = 'Description: cs';
  $handler->display->display_options['fields']['field_description_2']['language'] = 'cs';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_3']['id'] = 'title_field_3';
  $handler->display->display_options['fields']['title_field_3']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_3']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_3']['label'] = 'Title: da';
  $handler->display->display_options['fields']['title_field_3']['language'] = 'da';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_3']['id'] = 'field_subtitle_3';
  $handler->display->display_options['fields']['field_subtitle_3']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_3']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_3']['label'] = 'Subtitle: da';
  $handler->display->display_options['fields']['field_subtitle_3']['language'] = 'da';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_3']['id'] = 'field_background_information_3';
  $handler->display->display_options['fields']['field_background_information_3']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_3']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_3']['label'] = 'Background information: da';
  $handler->display->display_options['fields']['field_background_information_3']['language'] = 'da';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_3']['id'] = 'field_description_3';
  $handler->display->display_options['fields']['field_description_3']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_3']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_3']['label'] = 'Description: da';
  $handler->display->display_options['fields']['field_description_3']['language'] = 'da';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_4']['id'] = 'title_field_4';
  $handler->display->display_options['fields']['title_field_4']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_4']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_4']['label'] = 'Title: nl';
  $handler->display->display_options['fields']['title_field_4']['language'] = 'nl';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_4']['id'] = 'field_subtitle_4';
  $handler->display->display_options['fields']['field_subtitle_4']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_4']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_4']['label'] = 'Subtitle: nl';
  $handler->display->display_options['fields']['field_subtitle_4']['language'] = 'nl';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_4']['id'] = 'field_background_information_4';
  $handler->display->display_options['fields']['field_background_information_4']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_4']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_4']['label'] = 'Background information: nl';
  $handler->display->display_options['fields']['field_background_information_4']['language'] = 'nl';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_4']['id'] = 'field_description_4';
  $handler->display->display_options['fields']['field_description_4']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_4']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_4']['label'] = 'Description: nl';
  $handler->display->display_options['fields']['field_description_4']['language'] = 'nl';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_5']['id'] = 'title_field_5';
  $handler->display->display_options['fields']['title_field_5']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_5']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_5']['label'] = 'Title: et';
  $handler->display->display_options['fields']['title_field_5']['language'] = 'et';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_5']['id'] = 'field_subtitle_5';
  $handler->display->display_options['fields']['field_subtitle_5']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_5']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_5']['label'] = 'Subtitle: et';
  $handler->display->display_options['fields']['field_subtitle_5']['language'] = 'et';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_5']['id'] = 'field_background_information_5';
  $handler->display->display_options['fields']['field_background_information_5']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_5']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_5']['label'] = 'Background information: et';
  $handler->display->display_options['fields']['field_background_information_5']['language'] = 'et';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_5']['id'] = 'field_description_5';
  $handler->display->display_options['fields']['field_description_5']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_5']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_5']['label'] = 'Description: et';
  $handler->display->display_options['fields']['field_description_5']['language'] = 'et';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_6']['id'] = 'title_field_6';
  $handler->display->display_options['fields']['title_field_6']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_6']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_6']['label'] = 'Title: fi';
  $handler->display->display_options['fields']['title_field_6']['language'] = 'fi';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_6']['id'] = 'field_subtitle_6';
  $handler->display->display_options['fields']['field_subtitle_6']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_6']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_6']['label'] = 'Subtitle: fi';
  $handler->display->display_options['fields']['field_subtitle_6']['language'] = 'fi';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_6']['id'] = 'field_background_information_6';
  $handler->display->display_options['fields']['field_background_information_6']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_6']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_6']['label'] = 'Background information: fi';
  $handler->display->display_options['fields']['field_background_information_6']['language'] = 'fi';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_6']['id'] = 'field_description_6';
  $handler->display->display_options['fields']['field_description_6']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_6']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_6']['label'] = 'Description: fi';
  $handler->display->display_options['fields']['field_description_6']['language'] = 'fi';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_7']['id'] = 'title_field_7';
  $handler->display->display_options['fields']['title_field_7']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_7']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_7']['label'] = 'Title: fr';
  $handler->display->display_options['fields']['title_field_7']['language'] = 'fr';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_7']['id'] = 'field_subtitle_7';
  $handler->display->display_options['fields']['field_subtitle_7']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_7']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_7']['label'] = 'Subtitle: fr';
  $handler->display->display_options['fields']['field_subtitle_7']['language'] = 'fr';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_7']['id'] = 'field_background_information_7';
  $handler->display->display_options['fields']['field_background_information_7']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_7']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_7']['label'] = 'Background information: fr';
  $handler->display->display_options['fields']['field_background_information_7']['language'] = 'fr';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_7']['id'] = 'field_description_7';
  $handler->display->display_options['fields']['field_description_7']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_7']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_7']['label'] = 'Description: fr';
  $handler->display->display_options['fields']['field_description_7']['language'] = 'fr';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_8']['id'] = 'title_field_8';
  $handler->display->display_options['fields']['title_field_8']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_8']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_8']['label'] = 'Title: de';
  $handler->display->display_options['fields']['title_field_8']['language'] = 'de';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_8']['id'] = 'field_subtitle_8';
  $handler->display->display_options['fields']['field_subtitle_8']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_8']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_8']['label'] = 'Subtitle: de';
  $handler->display->display_options['fields']['field_subtitle_8']['language'] = 'de';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_8']['id'] = 'field_background_information_8';
  $handler->display->display_options['fields']['field_background_information_8']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_8']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_8']['label'] = 'Background information: de';
  $handler->display->display_options['fields']['field_background_information_8']['language'] = 'de';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_8']['id'] = 'field_description_8';
  $handler->display->display_options['fields']['field_description_8']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_8']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_8']['label'] = 'Description: de';
  $handler->display->display_options['fields']['field_description_8']['language'] = 'de';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_9']['id'] = 'title_field_9';
  $handler->display->display_options['fields']['title_field_9']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_9']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_9']['label'] = 'Title: el';
  $handler->display->display_options['fields']['title_field_9']['language'] = 'el';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_9']['id'] = 'field_subtitle_9';
  $handler->display->display_options['fields']['field_subtitle_9']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_9']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_9']['label'] = 'Subtitle: el';
  $handler->display->display_options['fields']['field_subtitle_9']['language'] = 'el';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_9']['id'] = 'field_background_information_9';
  $handler->display->display_options['fields']['field_background_information_9']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_9']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_9']['label'] = 'Background information: el';
  $handler->display->display_options['fields']['field_background_information_9']['language'] = 'el';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_9']['id'] = 'field_description_9';
  $handler->display->display_options['fields']['field_description_9']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_9']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_9']['label'] = 'Description: el';
  $handler->display->display_options['fields']['field_description_9']['language'] = 'el';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_10']['id'] = 'title_field_10';
  $handler->display->display_options['fields']['title_field_10']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_10']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_10']['label'] = 'Title: hu';
  $handler->display->display_options['fields']['title_field_10']['language'] = 'hu';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_10']['id'] = 'field_subtitle_10';
  $handler->display->display_options['fields']['field_subtitle_10']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_10']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_10']['label'] = 'Subtitle: hu';
  $handler->display->display_options['fields']['field_subtitle_10']['language'] = 'hu';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_10']['id'] = 'field_background_information_10';
  $handler->display->display_options['fields']['field_background_information_10']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_10']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_10']['label'] = 'Background information: hu';
  $handler->display->display_options['fields']['field_background_information_10']['language'] = 'hu';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_10']['id'] = 'field_description_10';
  $handler->display->display_options['fields']['field_description_10']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_10']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_10']['label'] = 'Description: hu';
  $handler->display->display_options['fields']['field_description_10']['language'] = 'hu';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_11']['id'] = 'title_field_11';
  $handler->display->display_options['fields']['title_field_11']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_11']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_11']['label'] = 'Title: ga';
  $handler->display->display_options['fields']['title_field_11']['language'] = 'ga';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_11']['id'] = 'field_subtitle_11';
  $handler->display->display_options['fields']['field_subtitle_11']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_11']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_11']['label'] = 'Subtitle: ga';
  $handler->display->display_options['fields']['field_subtitle_11']['language'] = 'ga';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_11']['id'] = 'field_background_information_11';
  $handler->display->display_options['fields']['field_background_information_11']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_11']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_11']['label'] = 'Background information: ga';
  $handler->display->display_options['fields']['field_background_information_11']['language'] = 'ga';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_11']['id'] = 'field_description_11';
  $handler->display->display_options['fields']['field_description_11']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_11']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_11']['label'] = 'Description: ga';
  $handler->display->display_options['fields']['field_description_11']['language'] = 'ga';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_12']['id'] = 'title_field_12';
  $handler->display->display_options['fields']['title_field_12']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_12']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_12']['label'] = 'Title: it';
  $handler->display->display_options['fields']['title_field_12']['language'] = 'it';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_12']['id'] = 'field_subtitle_12';
  $handler->display->display_options['fields']['field_subtitle_12']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_12']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_12']['label'] = 'Subtitle: it';
  $handler->display->display_options['fields']['field_subtitle_12']['language'] = 'it';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_12']['id'] = 'field_background_information_12';
  $handler->display->display_options['fields']['field_background_information_12']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_12']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_12']['label'] = 'Background information: it';
  $handler->display->display_options['fields']['field_background_information_12']['language'] = 'it';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_12']['id'] = 'field_description_12';
  $handler->display->display_options['fields']['field_description_12']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_12']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_12']['label'] = 'Description: it';
  $handler->display->display_options['fields']['field_description_12']['language'] = 'it';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_13']['id'] = 'title_field_13';
  $handler->display->display_options['fields']['title_field_13']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_13']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_13']['label'] = 'Title: lv';
  $handler->display->display_options['fields']['title_field_13']['language'] = 'lv';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_13']['id'] = 'field_subtitle_13';
  $handler->display->display_options['fields']['field_subtitle_13']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_13']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_13']['label'] = 'Subtitle: lv';
  $handler->display->display_options['fields']['field_subtitle_13']['language'] = 'lv';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_13']['id'] = 'field_background_information_13';
  $handler->display->display_options['fields']['field_background_information_13']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_13']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_13']['label'] = 'Background information: lv';
  $handler->display->display_options['fields']['field_background_information_13']['language'] = 'lv';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_13']['id'] = 'field_description_13';
  $handler->display->display_options['fields']['field_description_13']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_13']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_13']['label'] = 'Description: lv';
  $handler->display->display_options['fields']['field_description_13']['language'] = 'lv';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_14']['id'] = 'title_field_14';
  $handler->display->display_options['fields']['title_field_14']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_14']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_14']['label'] = 'Title: lt';
  $handler->display->display_options['fields']['title_field_14']['language'] = 'lt';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_14']['id'] = 'field_subtitle_14';
  $handler->display->display_options['fields']['field_subtitle_14']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_14']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_14']['label'] = 'Subtitle: lt';
  $handler->display->display_options['fields']['field_subtitle_14']['language'] = 'lt';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_14']['id'] = 'field_background_information_14';
  $handler->display->display_options['fields']['field_background_information_14']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_14']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_14']['label'] = 'Background information: lt';
  $handler->display->display_options['fields']['field_background_information_14']['language'] = 'lt';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_14']['id'] = 'field_description_14';
  $handler->display->display_options['fields']['field_description_14']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_14']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_14']['label'] = 'Description: lt';
  $handler->display->display_options['fields']['field_description_14']['language'] = 'lt';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_15']['id'] = 'title_field_15';
  $handler->display->display_options['fields']['title_field_15']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_15']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_15']['label'] = 'Title: mt';
  $handler->display->display_options['fields']['title_field_15']['language'] = 'mt';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_15']['id'] = 'field_subtitle_15';
  $handler->display->display_options['fields']['field_subtitle_15']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_15']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_15']['label'] = 'Subtitle: mt';
  $handler->display->display_options['fields']['field_subtitle_15']['language'] = 'mt';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_15']['id'] = 'field_background_information_15';
  $handler->display->display_options['fields']['field_background_information_15']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_15']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_15']['label'] = 'Background information: mt';
  $handler->display->display_options['fields']['field_background_information_15']['language'] = 'mt';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_15']['id'] = 'field_description_15';
  $handler->display->display_options['fields']['field_description_15']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_15']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_15']['label'] = 'Description: mt';
  $handler->display->display_options['fields']['field_description_15']['language'] = 'mt';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_16']['id'] = 'title_field_16';
  $handler->display->display_options['fields']['title_field_16']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_16']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_16']['label'] = 'Title: pl';
  $handler->display->display_options['fields']['title_field_16']['language'] = 'pl';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_16']['id'] = 'field_subtitle_16';
  $handler->display->display_options['fields']['field_subtitle_16']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_16']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_16']['label'] = 'Subtitle: pl';
  $handler->display->display_options['fields']['field_subtitle_16']['language'] = 'pl';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_16']['id'] = 'field_background_information_16';
  $handler->display->display_options['fields']['field_background_information_16']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_16']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_16']['label'] = 'Background information: pl';
  $handler->display->display_options['fields']['field_background_information_16']['language'] = 'pl';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_16']['id'] = 'field_description_16';
  $handler->display->display_options['fields']['field_description_16']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_16']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_16']['label'] = 'Description: pl';
  $handler->display->display_options['fields']['field_description_16']['language'] = 'pl';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_17']['id'] = 'title_field_17';
  $handler->display->display_options['fields']['title_field_17']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_17']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_17']['label'] = 'Title: pt';
  $handler->display->display_options['fields']['title_field_17']['language'] = 'pt';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_17']['id'] = 'field_subtitle_17';
  $handler->display->display_options['fields']['field_subtitle_17']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_17']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_17']['label'] = 'Subtitle: pt';
  $handler->display->display_options['fields']['field_subtitle_17']['language'] = 'pt';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_17']['id'] = 'field_background_information_17';
  $handler->display->display_options['fields']['field_background_information_17']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_17']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_17']['label'] = 'Background information: pt';
  $handler->display->display_options['fields']['field_background_information_17']['language'] = 'pt';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_17']['id'] = 'field_description_17';
  $handler->display->display_options['fields']['field_description_17']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_17']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_17']['label'] = 'Description: pt';
  $handler->display->display_options['fields']['field_description_17']['language'] = 'pt';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_18']['id'] = 'title_field_18';
  $handler->display->display_options['fields']['title_field_18']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_18']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_18']['label'] = 'Title: ro';
  $handler->display->display_options['fields']['title_field_18']['language'] = 'ro';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_18']['id'] = 'field_subtitle_18';
  $handler->display->display_options['fields']['field_subtitle_18']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_18']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_18']['label'] = 'Subtitle: ro';
  $handler->display->display_options['fields']['field_subtitle_18']['language'] = 'ro';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_18']['id'] = 'field_background_information_18';
  $handler->display->display_options['fields']['field_background_information_18']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_18']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_18']['label'] = 'Background information: ro';
  $handler->display->display_options['fields']['field_background_information_18']['language'] = 'ro';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_18']['id'] = 'field_description_18';
  $handler->display->display_options['fields']['field_description_18']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_18']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_18']['label'] = 'Description: ro';
  $handler->display->display_options['fields']['field_description_18']['language'] = 'ro';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_19']['id'] = 'title_field_19';
  $handler->display->display_options['fields']['title_field_19']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_19']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_19']['label'] = 'Title: sk';
  $handler->display->display_options['fields']['title_field_19']['language'] = 'sk';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_19']['id'] = 'field_subtitle_19';
  $handler->display->display_options['fields']['field_subtitle_19']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_19']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_19']['label'] = 'Subtitle: sk';
  $handler->display->display_options['fields']['field_subtitle_19']['language'] = 'sk';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_19']['id'] = 'field_background_information_19';
  $handler->display->display_options['fields']['field_background_information_19']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_19']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_19']['label'] = 'Background information: sk';
  $handler->display->display_options['fields']['field_background_information_19']['language'] = 'sk';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_19']['id'] = 'field_description_19';
  $handler->display->display_options['fields']['field_description_19']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_19']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_19']['label'] = 'Description: sk';
  $handler->display->display_options['fields']['field_description_19']['language'] = 'sk';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_20']['id'] = 'title_field_20';
  $handler->display->display_options['fields']['title_field_20']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_20']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_20']['label'] = 'Title: sl';
  $handler->display->display_options['fields']['title_field_20']['language'] = 'sl';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_20']['id'] = 'field_subtitle_20';
  $handler->display->display_options['fields']['field_subtitle_20']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_20']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_20']['label'] = 'Subtitle: sl';
  $handler->display->display_options['fields']['field_subtitle_20']['language'] = 'sl';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_20']['id'] = 'field_background_information_20';
  $handler->display->display_options['fields']['field_background_information_20']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_20']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_20']['label'] = 'Background information: sl';
  $handler->display->display_options['fields']['field_background_information_20']['language'] = 'sl';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_20']['id'] = 'field_description_20';
  $handler->display->display_options['fields']['field_description_20']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_20']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_20']['label'] = 'Description: sl';
  $handler->display->display_options['fields']['field_description_20']['language'] = 'sl';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_21']['id'] = 'title_field_21';
  $handler->display->display_options['fields']['title_field_21']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_21']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_21']['label'] = 'Title: es';
  $handler->display->display_options['fields']['title_field_21']['language'] = 'es';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_21']['id'] = 'field_subtitle_21';
  $handler->display->display_options['fields']['field_subtitle_21']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_21']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_21']['label'] = 'Subtitle: es';
  $handler->display->display_options['fields']['field_subtitle_21']['language'] = 'es';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_21']['id'] = 'field_background_information_21';
  $handler->display->display_options['fields']['field_background_information_21']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_21']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_21']['label'] = 'Background information: es';
  $handler->display->display_options['fields']['field_background_information_21']['language'] = 'es';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_21']['id'] = 'field_description_21';
  $handler->display->display_options['fields']['field_description_21']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_21']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_21']['label'] = 'Description: es';
  $handler->display->display_options['fields']['field_description_21']['language'] = 'es';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_22']['id'] = 'title_field_22';
  $handler->display->display_options['fields']['title_field_22']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_22']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_22']['label'] = 'Title: sv';
  $handler->display->display_options['fields']['title_field_22']['language'] = 'sv';
  /* Field: Entity translation: Subtitle: translated */
  $handler->display->display_options['fields']['field_subtitle_22']['id'] = 'field_subtitle_22';
  $handler->display->display_options['fields']['field_subtitle_22']['table'] = 'field_data_field_subtitle';
  $handler->display->display_options['fields']['field_subtitle_22']['field'] = 'field_subtitle_et';
  $handler->display->display_options['fields']['field_subtitle_22']['label'] = 'Subtitle: sv';
  $handler->display->display_options['fields']['field_subtitle_22']['language'] = 'sv';
  /* Field: Entity translation: Background information: translated */
  $handler->display->display_options['fields']['field_background_information_22']['id'] = 'field_background_information_22';
  $handler->display->display_options['fields']['field_background_information_22']['table'] = 'field_data_field_background_information';
  $handler->display->display_options['fields']['field_background_information_22']['field'] = 'field_background_information_et';
  $handler->display->display_options['fields']['field_background_information_22']['label'] = 'Background information: sv';
  $handler->display->display_options['fields']['field_background_information_22']['language'] = 'sv';
  /* Field: Entity translation: Description: translated */
  $handler->display->display_options['fields']['field_description_22']['id'] = 'field_description_22';
  $handler->display->display_options['fields']['field_description_22']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description_22']['field'] = 'field_description_et';
  $handler->display->display_options['fields']['field_description_22']['label'] = 'Description: sv';
  $handler->display->display_options['fields']['field_description_22']['language'] = 'sv';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri_1']['id'] = 'uri_1';
  $handler->display->display_options['fields']['uri_1']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri_1']['field'] = 'uri';
  $handler->display->display_options['fields']['uri_1']['relationship'] = 'field_video_fid';
  $handler->display->display_options['fields']['uri_1']['label'] = 'Video';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et']['id'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et']['label'] = 'Banner slogan: bg';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et']['language'] = 'bg';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_1']['id'] = 'field_projects_banner_slogan_et_1';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_1']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_1']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_1']['label'] = 'Banner slogan: hr';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_1']['language'] = 'hr';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_2']['id'] = 'field_projects_banner_slogan_et_2';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_2']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_2']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_2']['label'] = 'Banner slogan: cs';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_2']['language'] = 'cs';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_3']['id'] = 'field_projects_banner_slogan_et_3';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_3']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_3']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_3']['label'] = 'Banner slogan: da';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_3']['language'] = 'da';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_4']['id'] = 'field_projects_banner_slogan_et_4';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_4']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_4']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_4']['label'] = 'Banner slogan: nl';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_4']['language'] = 'nl';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_5']['id'] = 'field_projects_banner_slogan_et_5';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_5']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_5']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_5']['label'] = 'Banner slogan: es';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_5']['language'] = 'es';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_6']['id'] = 'field_projects_banner_slogan_et_6';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_6']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_6']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_6']['label'] = 'Banner slogan: et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_6']['language'] = 'et';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_7']['id'] = 'field_projects_banner_slogan_et_7';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_7']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_7']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_7']['label'] = 'Banner slogan: fi';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_7']['language'] = 'fi';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_8']['id'] = 'field_projects_banner_slogan_et_8';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_8']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_8']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_8']['label'] = 'Banner slogan: fr';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_8']['language'] = 'fr';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_9']['id'] = 'field_projects_banner_slogan_et_9';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_9']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_9']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_9']['label'] = 'Banner slogan: de';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_9']['language'] = 'de';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_10']['id'] = 'field_projects_banner_slogan_et_10';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_10']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_10']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_10']['label'] = 'Banner slogan: el';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_10']['language'] = 'el';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_11']['id'] = 'field_projects_banner_slogan_et_11';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_11']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_11']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_11']['label'] = 'Banner slogan: hu';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_11']['language'] = 'hu';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_12']['id'] = 'field_projects_banner_slogan_et_12';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_12']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_12']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_12']['label'] = 'Banner slogan: ga';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_12']['language'] = 'ga';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_13']['id'] = 'field_projects_banner_slogan_et_13';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_13']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_13']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_13']['label'] = 'Banner slogan: it';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_13']['language'] = 'it';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_14']['id'] = 'field_projects_banner_slogan_et_14';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_14']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_14']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_14']['label'] = 'Banner slogan: lv';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_14']['language'] = 'lv';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_15']['id'] = 'field_projects_banner_slogan_et_15';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_15']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_15']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_15']['label'] = 'Banner slogan: lt';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_15']['language'] = 'lt';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_16']['id'] = 'field_projects_banner_slogan_et_16';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_16']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_16']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_16']['label'] = 'Banner slogan: mt';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_16']['language'] = 'mt';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_17']['id'] = 'field_projects_banner_slogan_et_17';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_17']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_17']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_17']['label'] = 'Banner slogan: pl';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_17']['language'] = 'pl';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_18']['id'] = 'field_projects_banner_slogan_et_18';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_18']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_18']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_18']['label'] = 'Banner slogan: pt';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_18']['language'] = 'pt';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_19']['id'] = 'field_projects_banner_slogan_et_19';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_19']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_19']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_19']['label'] = 'Banner slogan: ro';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_19']['language'] = 'ro';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_20']['id'] = 'field_projects_banner_slogan_et_20';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_20']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_20']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_20']['label'] = 'Banner slogan: sk';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_20']['language'] = 'sk';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_21']['id'] = 'field_projects_banner_slogan_et_21';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_21']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_21']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_21']['label'] = 'Banner slogan: sl';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_21']['language'] = 'sl';
  /* Field: Entity translation: Banner slogan: translated */
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_22']['id'] = 'field_projects_banner_slogan_et_22';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_22']['table'] = 'field_data_field_projects_banner_slogan';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_22']['field'] = 'field_projects_banner_slogan_et';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_22']['label'] = 'Banner slogan: sv';
  $handler->display->display_options['fields']['field_projects_banner_slogan_et_22']['language'] = 'sv';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri_3']['id'] = 'uri_3';
  $handler->display->display_options['fields']['uri_3']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri_3']['field'] = 'uri';
  $handler->display->display_options['fields']['uri_3']['relationship'] = 'field_project_documents_fid';
  $handler->display->display_options['fields']['uri_3']['label'] = 'Documents';
  $handler->display->display_options['fields']['uri_3']['file_download_path'] = TRUE;
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_project_summary']['id'] = 'field_project_summary';
  $handler->display->display_options['fields']['field_project_summary']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary']['field'] = 'field_project_summary';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_et']['id'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_et']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_et']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_et']['label'] = 'Summary: bg';
  $handler->display->display_options['fields']['field_project_summary_et']['language'] = 'bg';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_1']['id'] = 'field_project_summary_1';
  $handler->display->display_options['fields']['field_project_summary_1']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_1']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_1']['label'] = 'Summary: cs';
  $handler->display->display_options['fields']['field_project_summary_1']['language'] = 'cs';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_2']['id'] = 'field_project_summary_2';
  $handler->display->display_options['fields']['field_project_summary_2']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_2']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_2']['label'] = 'Summary: da';
  $handler->display->display_options['fields']['field_project_summary_2']['language'] = 'da';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_3']['id'] = 'field_project_summary_3';
  $handler->display->display_options['fields']['field_project_summary_3']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_3']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_3']['label'] = 'Summary: de';
  $handler->display->display_options['fields']['field_project_summary_3']['language'] = 'de';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_4']['id'] = 'field_project_summary_4';
  $handler->display->display_options['fields']['field_project_summary_4']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_4']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_4']['label'] = 'Summary: el';
  $handler->display->display_options['fields']['field_project_summary_4']['language'] = 'el';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_5']['id'] = 'field_project_summary_5';
  $handler->display->display_options['fields']['field_project_summary_5']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_5']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_5']['label'] = 'Summary: en';
  $handler->display->display_options['fields']['field_project_summary_5']['language'] = 'en';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_6']['id'] = 'field_project_summary_6';
  $handler->display->display_options['fields']['field_project_summary_6']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_6']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_6']['label'] = 'Summary: es';
  $handler->display->display_options['fields']['field_project_summary_6']['language'] = 'es';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_7']['id'] = 'field_project_summary_7';
  $handler->display->display_options['fields']['field_project_summary_7']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_7']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_7']['label'] = 'Summary: et';
  $handler->display->display_options['fields']['field_project_summary_7']['language'] = 'et';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_8']['id'] = 'field_project_summary_8';
  $handler->display->display_options['fields']['field_project_summary_8']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_8']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_8']['label'] = 'Summary: fi';
  $handler->display->display_options['fields']['field_project_summary_8']['language'] = 'fi';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_9']['id'] = 'field_project_summary_9';
  $handler->display->display_options['fields']['field_project_summary_9']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_9']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_9']['label'] = 'Summary: fr';
  $handler->display->display_options['fields']['field_project_summary_9']['language'] = 'fr';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_10']['id'] = 'field_project_summary_10';
  $handler->display->display_options['fields']['field_project_summary_10']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_10']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_10']['label'] = 'Summary: ga';
  $handler->display->display_options['fields']['field_project_summary_10']['language'] = 'ga';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_11']['id'] = 'field_project_summary_11';
  $handler->display->display_options['fields']['field_project_summary_11']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_11']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_11']['label'] = 'Summary: hr';
  $handler->display->display_options['fields']['field_project_summary_11']['language'] = 'hr';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_12']['id'] = 'field_project_summary_12';
  $handler->display->display_options['fields']['field_project_summary_12']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_12']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_12']['label'] = 'Summary: hu';
  $handler->display->display_options['fields']['field_project_summary_12']['language'] = 'hu';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_13']['id'] = 'field_project_summary_13';
  $handler->display->display_options['fields']['field_project_summary_13']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_13']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_13']['label'] = 'Summary: it';
  $handler->display->display_options['fields']['field_project_summary_13']['language'] = 'it';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_14']['id'] = 'field_project_summary_14';
  $handler->display->display_options['fields']['field_project_summary_14']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_14']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_14']['label'] = 'Summary: lt';
  $handler->display->display_options['fields']['field_project_summary_14']['language'] = 'lt';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_15']['id'] = 'field_project_summary_15';
  $handler->display->display_options['fields']['field_project_summary_15']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_15']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_15']['label'] = 'Summary: lv';
  $handler->display->display_options['fields']['field_project_summary_15']['language'] = 'lv';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_16']['id'] = 'field_project_summary_16';
  $handler->display->display_options['fields']['field_project_summary_16']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_16']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_16']['label'] = 'Summary: mt';
  $handler->display->display_options['fields']['field_project_summary_16']['language'] = 'mt';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_17']['id'] = 'field_project_summary_17';
  $handler->display->display_options['fields']['field_project_summary_17']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_17']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_17']['label'] = 'Summary: nl';
  $handler->display->display_options['fields']['field_project_summary_17']['language'] = 'nl';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_18']['id'] = 'field_project_summary_18';
  $handler->display->display_options['fields']['field_project_summary_18']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_18']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_18']['label'] = 'Summary: pl';
  $handler->display->display_options['fields']['field_project_summary_18']['language'] = 'pl';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_19']['id'] = 'field_project_summary_19';
  $handler->display->display_options['fields']['field_project_summary_19']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_19']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_19']['label'] = 'Summary: pt';
  $handler->display->display_options['fields']['field_project_summary_19']['language'] = 'pt';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_20']['id'] = 'field_project_summary_20';
  $handler->display->display_options['fields']['field_project_summary_20']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_20']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_20']['label'] = 'Summary: ro';
  $handler->display->display_options['fields']['field_project_summary_20']['language'] = 'ro';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_21']['id'] = 'field_project_summary_21';
  $handler->display->display_options['fields']['field_project_summary_21']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_21']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_21']['label'] = 'Summary: sk';
  $handler->display->display_options['fields']['field_project_summary_21']['language'] = 'sk';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_22']['id'] = 'field_project_summary_22';
  $handler->display->display_options['fields']['field_project_summary_22']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_22']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_22']['label'] = 'Summary: sl';
  $handler->display->display_options['fields']['field_project_summary_22']['language'] = 'sl';
  /* Field: Entity translation: Summary: translated */
  $handler->display->display_options['fields']['field_project_summary_23']['id'] = 'field_project_summary_23';
  $handler->display->display_options['fields']['field_project_summary_23']['table'] = 'field_data_field_project_summary';
  $handler->display->display_options['fields']['field_project_summary_23']['field'] = 'field_project_summary_et';
  $handler->display->display_options['fields']['field_project_summary_23']['label'] = 'Summary: sv';
  $handler->display->display_options['fields']['field_project_summary_23']['language'] = 'sv';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_0']['id'] = 'field_coordinating_organisations_0';
  $handler->display->display_options['fields']['field_coordinating_organisations_0']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_0']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_0']['label'] = 'Coordinators: bg';
  $handler->display->display_options['fields']['field_coordinating_organisations_0']['language'] = 'bg';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_1']['id'] = 'field_coordinating_organisations_1';
  $handler->display->display_options['fields']['field_coordinating_organisations_1']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_1']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_1']['label'] = 'Coordinators: cs';
  $handler->display->display_options['fields']['field_coordinating_organisations_1']['language'] = 'cs';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_2']['id'] = 'field_coordinating_organisations_2';
  $handler->display->display_options['fields']['field_coordinating_organisations_2']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_2']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_2']['label'] = 'Coordinators: da';
  $handler->display->display_options['fields']['field_coordinating_organisations_2']['language'] = 'da';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_3']['id'] = 'field_coordinating_organisations_3';
  $handler->display->display_options['fields']['field_coordinating_organisations_3']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_3']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_3']['label'] = 'Coordinators: de';
  $handler->display->display_options['fields']['field_coordinating_organisations_3']['language'] = 'de';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_4']['id'] = 'field_coordinating_organisations_4';
  $handler->display->display_options['fields']['field_coordinating_organisations_4']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_4']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_4']['label'] = 'Coordinators: el';
  $handler->display->display_options['fields']['field_coordinating_organisations_4']['language'] = 'el';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_5']['id'] = 'field_coordinating_organisations_5';
  $handler->display->display_options['fields']['field_coordinating_organisations_5']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_5']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_5']['label'] = 'Coordinators: en';
  $handler->display->display_options['fields']['field_coordinating_organisations_5']['language'] = 'en';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_6']['id'] = 'field_coordinating_organisations_6';
  $handler->display->display_options['fields']['field_coordinating_organisations_6']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_6']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_6']['label'] = 'Coordinators: es';
  $handler->display->display_options['fields']['field_coordinating_organisations_6']['language'] = 'es';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_7']['id'] = 'field_coordinating_organisations_7';
  $handler->display->display_options['fields']['field_coordinating_organisations_7']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_7']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_7']['label'] = 'Coordinators: et';
  $handler->display->display_options['fields']['field_coordinating_organisations_7']['language'] = 'et';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_8']['id'] = 'field_coordinating_organisations_8';
  $handler->display->display_options['fields']['field_coordinating_organisations_8']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_8']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_8']['label'] = 'Coordinators: fi';
  $handler->display->display_options['fields']['field_coordinating_organisations_8']['language'] = 'fi';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_9']['id'] = 'field_coordinating_organisations_9';
  $handler->display->display_options['fields']['field_coordinating_organisations_9']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_9']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_9']['label'] = 'Coordinators: fr';
  $handler->display->display_options['fields']['field_coordinating_organisations_9']['language'] = 'fr';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_10']['id'] = 'field_coordinating_organisations_10';
  $handler->display->display_options['fields']['field_coordinating_organisations_10']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_10']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_10']['label'] = 'Coordinators: ga';
  $handler->display->display_options['fields']['field_coordinating_organisations_10']['language'] = 'ga';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_11']['id'] = 'field_coordinating_organisations_11';
  $handler->display->display_options['fields']['field_coordinating_organisations_11']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_11']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_11']['label'] = 'Coordinators: hr';
  $handler->display->display_options['fields']['field_coordinating_organisations_11']['language'] = 'hr';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_12']['id'] = 'field_coordinating_organisations_12';
  $handler->display->display_options['fields']['field_coordinating_organisations_12']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_12']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_12']['label'] = 'Coordinators: hu';
  $handler->display->display_options['fields']['field_coordinating_organisations_12']['language'] = 'hu';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_13']['id'] = 'field_coordinating_organisations_13';
  $handler->display->display_options['fields']['field_coordinating_organisations_13']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_13']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_13']['label'] = 'Coordinators: it';
  $handler->display->display_options['fields']['field_coordinating_organisations_13']['language'] = 'it';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_14']['id'] = 'field_coordinating_organisations_14';
  $handler->display->display_options['fields']['field_coordinating_organisations_14']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_14']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_14']['label'] = 'Coordinators: lt';
  $handler->display->display_options['fields']['field_coordinating_organisations_14']['language'] = 'lt';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_15']['id'] = 'field_coordinating_organisations_15';
  $handler->display->display_options['fields']['field_coordinating_organisations_15']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_15']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_15']['label'] = 'Coordinators: lv';
  $handler->display->display_options['fields']['field_coordinating_organisations_15']['language'] = 'lv';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_16']['id'] = 'field_coordinating_organisations_16';
  $handler->display->display_options['fields']['field_coordinating_organisations_16']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_16']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_16']['label'] = 'Coordinators: mt';
  $handler->display->display_options['fields']['field_coordinating_organisations_16']['language'] = 'mt';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_17']['id'] = 'field_coordinating_organisations_17';
  $handler->display->display_options['fields']['field_coordinating_organisations_17']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_17']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_17']['label'] = 'Coordinators: nl';
  $handler->display->display_options['fields']['field_coordinating_organisations_17']['language'] = 'nl';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_18']['id'] = 'field_coordinating_organisations_18';
  $handler->display->display_options['fields']['field_coordinating_organisations_18']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_18']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_18']['label'] = 'Coordinators: pl';
  $handler->display->display_options['fields']['field_coordinating_organisations_18']['language'] = 'pl';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_19']['id'] = 'field_coordinating_organisations_19';
  $handler->display->display_options['fields']['field_coordinating_organisations_19']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_19']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_19']['label'] = 'Coordinators: pt';
  $handler->display->display_options['fields']['field_coordinating_organisations_19']['language'] = 'pt';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_20']['id'] = 'field_coordinating_organisations_20';
  $handler->display->display_options['fields']['field_coordinating_organisations_20']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_20']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_20']['label'] = 'Coordinators: ro';
  $handler->display->display_options['fields']['field_coordinating_organisations_20']['language'] = 'ro';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_21']['id'] = 'field_coordinating_organisations_21';
  $handler->display->display_options['fields']['field_coordinating_organisations_21']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_21']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_21']['label'] = 'Coordinators: sk';
  $handler->display->display_options['fields']['field_coordinating_organisations_21']['language'] = 'sk';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_22']['id'] = 'field_coordinating_organisations_22';
  $handler->display->display_options['fields']['field_coordinating_organisations_22']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_22']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_22']['label'] = 'Coordinators: sl';
  $handler->display->display_options['fields']['field_coordinating_organisations_22']['language'] = 'sl';
  /* Field: Entity translation: Coordinators: translated */
  $handler->display->display_options['fields']['field_coordinating_organisations_23']['id'] = 'field_coordinating_organisations_23';
  $handler->display->display_options['fields']['field_coordinating_organisations_23']['table'] = 'field_data_field_coordinating_organisations';
  $handler->display->display_options['fields']['field_coordinating_organisations_23']['field'] = 'field_coordinating_organisations_et';
  $handler->display->display_options['fields']['field_coordinating_organisations_23']['label'] = 'Coordinators: sv';
  $handler->display->display_options['fields']['field_coordinating_organisations_23']['language'] = 'sv';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_0']['id'] = 'field_project_partner_0';
  $handler->display->display_options['fields']['field_project_partner_0']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_0']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_0']['label'] = 'Partners: bg';
  $handler->display->display_options['fields']['field_project_partner_0']['language'] = 'bg';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_1']['id'] = 'field_project_partner_1';
  $handler->display->display_options['fields']['field_project_partner_1']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_1']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_1']['label'] = 'Partners: cs';
  $handler->display->display_options['fields']['field_project_partner_1']['language'] = 'cs';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_2']['id'] = 'field_project_partner_2';
  $handler->display->display_options['fields']['field_project_partner_2']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_2']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_2']['label'] = 'Partners: da';
  $handler->display->display_options['fields']['field_project_partner_2']['language'] = 'da';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_3']['id'] = 'field_project_partner_3';
  $handler->display->display_options['fields']['field_project_partner_3']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_3']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_3']['label'] = 'Partners: de';
  $handler->display->display_options['fields']['field_project_partner_3']['language'] = 'de';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_4']['id'] = 'field_project_partner_4';
  $handler->display->display_options['fields']['field_project_partner_4']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_4']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_4']['label'] = 'Partners: el';
  $handler->display->display_options['fields']['field_project_partner_4']['language'] = 'el';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_5']['id'] = 'field_project_partner_5';
  $handler->display->display_options['fields']['field_project_partner_5']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_5']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_5']['label'] = 'Partners: en';
  $handler->display->display_options['fields']['field_project_partner_5']['language'] = 'en';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_6']['id'] = 'field_project_partner_6';
  $handler->display->display_options['fields']['field_project_partner_6']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_6']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_6']['label'] = 'Partners: es';
  $handler->display->display_options['fields']['field_project_partner_6']['language'] = 'es';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_7']['id'] = 'field_project_partner_7';
  $handler->display->display_options['fields']['field_project_partner_7']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_7']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_7']['label'] = 'Partners: et';
  $handler->display->display_options['fields']['field_project_partner_7']['language'] = 'et';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_8']['id'] = 'field_project_partner_8';
  $handler->display->display_options['fields']['field_project_partner_8']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_8']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_8']['label'] = 'Partners: fi';
  $handler->display->display_options['fields']['field_project_partner_8']['language'] = 'fi';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_9']['id'] = 'field_project_partner_9';
  $handler->display->display_options['fields']['field_project_partner_9']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_9']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_9']['label'] = 'Partners: fr';
  $handler->display->display_options['fields']['field_project_partner_9']['language'] = 'fr';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_10']['id'] = 'field_project_partner_10';
  $handler->display->display_options['fields']['field_project_partner_10']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_10']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_10']['label'] = 'Partners: ga';
  $handler->display->display_options['fields']['field_project_partner_10']['language'] = 'ga';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_11']['id'] = 'field_project_partner_11';
  $handler->display->display_options['fields']['field_project_partner_11']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_11']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_11']['label'] = 'Partners: hr';
  $handler->display->display_options['fields']['field_project_partner_11']['language'] = 'hr';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_12']['id'] = 'field_project_partner_12';
  $handler->display->display_options['fields']['field_project_partner_12']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_12']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_12']['label'] = 'Partners: hu';
  $handler->display->display_options['fields']['field_project_partner_12']['language'] = 'hu';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_13']['id'] = 'field_project_partner_13';
  $handler->display->display_options['fields']['field_project_partner_13']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_13']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_13']['label'] = 'Partners: it';
  $handler->display->display_options['fields']['field_project_partner_13']['language'] = 'it';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_14']['id'] = 'field_project_partner_14';
  $handler->display->display_options['fields']['field_project_partner_14']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_14']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_14']['label'] = 'Partners: lt';
  $handler->display->display_options['fields']['field_project_partner_14']['language'] = 'lt';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_15']['id'] = 'field_project_partner_15';
  $handler->display->display_options['fields']['field_project_partner_15']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_15']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_15']['label'] = 'Partners: lv';
  $handler->display->display_options['fields']['field_project_partner_15']['language'] = 'lv';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_16']['id'] = 'field_project_partner_16';
  $handler->display->display_options['fields']['field_project_partner_16']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_16']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_16']['label'] = 'Partners: mt';
  $handler->display->display_options['fields']['field_project_partner_16']['language'] = 'mt';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_17']['id'] = 'field_project_partner_17';
  $handler->display->display_options['fields']['field_project_partner_17']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_17']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_17']['label'] = 'Partners: nl';
  $handler->display->display_options['fields']['field_project_partner_17']['language'] = 'nl';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_18']['id'] = 'field_project_partner_18';
  $handler->display->display_options['fields']['field_project_partner_18']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_18']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_18']['label'] = 'Partners: pl';
  $handler->display->display_options['fields']['field_project_partner_18']['language'] = 'pl';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_19']['id'] = 'field_project_partner_19';
  $handler->display->display_options['fields']['field_project_partner_19']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_19']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_19']['label'] = 'Partners: pt';
  $handler->display->display_options['fields']['field_project_partner_19']['language'] = 'pt';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_20']['id'] = 'field_project_partner_20';
  $handler->display->display_options['fields']['field_project_partner_20']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_20']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_20']['label'] = 'Partners: ro';
  $handler->display->display_options['fields']['field_project_partner_20']['language'] = 'ro';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_21']['id'] = 'field_project_partner_21';
  $handler->display->display_options['fields']['field_project_partner_21']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_21']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_21']['label'] = 'Partners: sk';
  $handler->display->display_options['fields']['field_project_partner_21']['language'] = 'sk';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_22']['id'] = 'field_project_partner_22';
  $handler->display->display_options['fields']['field_project_partner_22']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_22']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_22']['label'] = 'Partners: sl';
  $handler->display->display_options['fields']['field_project_partner_22']['language'] = 'sl';
  /* Field: Entity translation: Partners: translated */
  $handler->display->display_options['fields']['field_project_partner_23']['id'] = 'field_project_partner_23';
  $handler->display->display_options['fields']['field_project_partner_23']['table'] = 'field_data_field_project_partner';
  $handler->display->display_options['fields']['field_project_partner_23']['field'] = 'field_project_partner_et';
  $handler->display->display_options['fields']['field_project_partner_23']['label'] = 'Partners: sv';
  $handler->display->display_options['fields']['field_project_partner_23']['language'] = 'sv';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Entity translation: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    2358 => '2358',
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'campaign';
  $handler->display->display_options['merge_rows'] = TRUE;
  $handler->display->display_options['field_config'] = array(
    'nid' => array(
      'merge_option' => 'filter',
      'separator' => ';',
    ),
    'title' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_et' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_coordinating_organisations' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_eu_budget_contribution' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_broad_area' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_partner' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_location_country' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_location_locality' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_location_postal_code' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_location_thoroughfare' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_related_link_s_' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_related_link_s__1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_timeframe' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_visual' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'uri' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_campaign' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'uri_2' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_0' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_0' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_0' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_0' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_2' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_2' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_2' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_2' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_3' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_3' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_3' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_3' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_4' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_4' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_4' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_4' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_5' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_5' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_5' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_5' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_6' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_6' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_6' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_6' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_7' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_7' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_7' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_7' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_8' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_8' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_8' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_8' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_9' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_9' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_9' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_9' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_10' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_10' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_10' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_10' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_11' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_11' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_11' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_11' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_12' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_12' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_12' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_12' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_13' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_13' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_13' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_13' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_14' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_14' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_14' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_14' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_15' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_15' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_15' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_15' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_16' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_16' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_16' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_16' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_17' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_17' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_17' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_17' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_18' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_18' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_18' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_18' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_19' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_19' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_19' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_19' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_20' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_20' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_20' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_20' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_21' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_21' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_21' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_21' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_22' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_22' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_22' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_22' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'uri_1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'project-data-interface';

  /* Display: Campaign: invest eu - csv */
  $handler = $view->new_display('views_data_export', 'Campaign: invest eu - csv', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 1;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 1;
  $handler->display->display_options['merge_rows'] = TRUE;
  $handler->display->display_options['field_config'] = array(
    'nid' => array(
      'merge_option' => 'filter',
      'separator' => ';',
    ),
    'title' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_coordinating_organisations' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_eu_budget_contribution' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_broad_area' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_partner' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_location_country' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_location_locality' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_location_postal_code' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_location_thoroughfare' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_related_link_s_' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_related_link_s__1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_timeframe' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_timeframe_1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_visual' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'uri' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_campaign' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'uri_2' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_0' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_0' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_0' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_0' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_2' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_2' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_2' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_2' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_3' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_3' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_3' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_3' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_4' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_4' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_4' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_4' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_5' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_5' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_5' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_5' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_6' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_6' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_6' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_6' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_7' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_7' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_7' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_7' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_8' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_8' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_8' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_8' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_9' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_9' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_9' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_9' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_10' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_10' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_10' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_10' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_11' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_11' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_11' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_11' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_12' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_12' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_12' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_12' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_13' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_13' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_13' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_13' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_14' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_14' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_14' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_14' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_15' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_15' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_15' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_15' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_16' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_16' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_16' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_16' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_17' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_17' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_17' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_17' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_18' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_18' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_18' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_18' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_19' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_19' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_19' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_19' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_20' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_20' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_20' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_20' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_21' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_21' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_21' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_21' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_22' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_subtitle_22' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_background_information_22' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description_22' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'uri_1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_2' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_3' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_4' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_5' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_6' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_7' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_8' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_9' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_10' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_11' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_12' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_13' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_14' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_15' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_16' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_17' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_18' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_19' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_20' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_21' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_projects_banner_slogan_et_22' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'uri_3' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
  );
  $handler->display->display_options['path'] = 'export/project/csv';
  $export['project_data_interface'] = $view;

  $view = new view();
  $view->name = 'project_geojson';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Project Geojson';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Project Geojson';
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '21600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: GPS coordinates project location */
  $handler->display->display_options['fields']['field_gps_coordinates_project']['id'] = 'field_gps_coordinates_project';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['table'] = 'field_data_field_gps_coordinates_project';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['field'] = 'field_gps_coordinates_project';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['label'] = '';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gps_coordinates_project']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 0,
  );
  $handler->display->display_options['fields']['field_gps_coordinates_project']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_gps_coordinates_project']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['delta_offset'] = '0';
  /* Field: Content: Programme name */
  $handler->display->display_options['fields']['field_programme_name']['id'] = 'field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['table'] = 'field_data_field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['field'] = 'field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['label'] = 'Programm';
  $handler->display->display_options['fields']['field_programme_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_programme_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_name']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_programme_name']['delta_offset'] = '0';
  /* Field: Content: EC’s priorities */
  $handler->display->display_options['fields']['field_ec_priorities_']['id'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['table'] = 'field_data_field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['field'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ec_priorities_']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_ec_priorities_']['delta_offset'] = '0';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = 'https://ec.europa.eu[view_node]';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Field: Content: EU Budget contribution to the project */
  $handler->display->display_options['fields']['field_eu_budget_contribution']['id'] = 'field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['table'] = 'field_data_field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['field'] = 'field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_eu_budget_contribution']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '<div class="categories">
  <div class="field programme_name">[field_programme_name]</div> <divclass="field_ec_priorities">[field_ec_priorities_]  </div>
<div class="field_eu_budget_contribution"><span class="label">EU Contribution:</span><span class="amount">EUR [field_eu_budget_contribution]</span></div>
</div>
<div class="description">
 [field_description]
<span class="more_info">[view_node]</span>
</div>


';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_description']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Content: Results */
  $handler->display->display_options['fields']['field_project_achievements']['id'] = 'field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['table'] = 'field_data_field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['field'] = 'field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['label'] = '';
  $handler->display->display_options['fields']['field_project_achievements']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_achievements']['element_label_colon'] = FALSE;
  /* Field: Content: Project location - Country */
  $handler->display->display_options['fields']['field_project_location_country']['id'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['fields']['field_project_location_country']['field'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_location_country']['display_name'] = 1;
  /* Field: Content: Funding area */
  $handler->display->display_options['fields']['field_broad_area']['id'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['table'] = 'field_data_field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['field'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['label'] = '';
  $handler->display->display_options['fields']['field_broad_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_broad_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_broad_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_broad_area']['delta_offset'] = '0';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Description (field_description) */
  $handler->display->display_options['filters']['field_description_value']['id'] = 'field_description_value';
  $handler->display->display_options['filters']['field_description_value']['table'] = 'field_data_field_description';
  $handler->display->display_options['filters']['field_description_value']['field'] = 'field_description_value';
  $handler->display->display_options['filters']['field_description_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_description_value']['group'] = 1;
  $handler->display->display_options['filters']['field_description_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_description_value']['expose']['operator_id'] = 'field_description_value_op';
  $handler->display->display_options['filters']['field_description_value']['expose']['label'] = 'Description (field_description)';
  $handler->display->display_options['filters']['field_description_value']['expose']['operator'] = 'field_description_value_op';
  $handler->display->display_options['filters']['field_description_value']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['field_description_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    9 => 0,
    6 => 0,
    8 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Author uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'node';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author uid';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***DEFAULT_LANGUAGE***' => '***DEFAULT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  /* Filter criterion: Content: Funding area (field_broad_area) */
  $handler->display->display_options['filters']['field_broad_area_tid']['id'] = 'field_broad_area_tid';
  $handler->display->display_options['filters']['field_broad_area_tid']['table'] = 'field_data_field_broad_area';
  $handler->display->display_options['filters']['field_broad_area_tid']['field'] = 'field_broad_area_tid';
  $handler->display->display_options['filters']['field_broad_area_tid']['value'] = '';
  $handler->display->display_options['filters']['field_broad_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_broad_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_broad_area_tid']['expose']['operator_id'] = 'field_broad_area_tid_op';
  $handler->display->display_options['filters']['field_broad_area_tid']['expose']['label'] = 'Broad area (field_broad_area)';
  $handler->display->display_options['filters']['field_broad_area_tid']['expose']['operator'] = 'field_broad_area_tid_op';
  $handler->display->display_options['filters']['field_broad_area_tid']['expose']['identifier'] = 'broad_area';
  $handler->display->display_options['filters']['field_broad_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_broad_area_tid']['vocabulary'] = 'budget_broad_areas';
  $handler->display->display_options['filters']['field_broad_area_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: EC’s priorities (field_ec_priorities_) */
  $handler->display->display_options['filters']['field_ec_priorities__tid']['id'] = 'field_ec_priorities__tid';
  $handler->display->display_options['filters']['field_ec_priorities__tid']['table'] = 'field_data_field_ec_priorities_';
  $handler->display->display_options['filters']['field_ec_priorities__tid']['field'] = 'field_ec_priorities__tid';
  $handler->display->display_options['filters']['field_ec_priorities__tid']['value'] = '';
  $handler->display->display_options['filters']['field_ec_priorities__tid']['group'] = 1;
  $handler->display->display_options['filters']['field_ec_priorities__tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ec_priorities__tid']['expose']['operator_id'] = 'field_ec_priorities__tid_op';
  $handler->display->display_options['filters']['field_ec_priorities__tid']['expose']['label'] = 'EC’s priorities (field_ec_priorities_)';
  $handler->display->display_options['filters']['field_ec_priorities__tid']['expose']['operator'] = 'field_ec_priorities__tid_op';
  $handler->display->display_options['filters']['field_ec_priorities__tid']['expose']['identifier'] = 'priorities';
  $handler->display->display_options['filters']['field_ec_priorities__tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_ec_priorities__tid']['vocabulary'] = 'eu_priorities';
  $handler->display->display_options['filters']['field_ec_priorities__tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Programme name (field_programme_name) */
  $handler->display->display_options['filters']['field_programme_name_tid']['id'] = 'field_programme_name_tid';
  $handler->display->display_options['filters']['field_programme_name_tid']['table'] = 'field_data_field_programme_name';
  $handler->display->display_options['filters']['field_programme_name_tid']['field'] = 'field_programme_name_tid';
  $handler->display->display_options['filters']['field_programme_name_tid']['value'] = '';
  $handler->display->display_options['filters']['field_programme_name_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_programme_name_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programme_name_tid']['expose']['operator_id'] = 'field_programme_name_tid_op';
  $handler->display->display_options['filters']['field_programme_name_tid']['expose']['label'] = 'Programme name (field_programme_name)';
  $handler->display->display_options['filters']['field_programme_name_tid']['expose']['operator'] = 'field_programme_name_tid_op';
  $handler->display->display_options['filters']['field_programme_name_tid']['expose']['identifier'] = 'programme';
  $handler->display->display_options['filters']['field_programme_name_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_programme_name_tid']['vocabulary'] = 'mff_programmes';
  $handler->display->display_options['filters']['field_programme_name_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Project location - Country */
  $handler->display->display_options['filters']['field_project_location_country']['id'] = 'field_project_location_country';
  $handler->display->display_options['filters']['field_project_location_country']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['filters']['field_project_location_country']['field'] = 'field_project_location_country';
  $handler->display->display_options['filters']['field_project_location_country']['group'] = 1;
  $handler->display->display_options['filters']['field_project_location_country']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_location_country']['expose']['operator_id'] = 'field_project_location_country_op';
  $handler->display->display_options['filters']['field_project_location_country']['expose']['label'] = 'Project location - Country';
  $handler->display->display_options['filters']['field_project_location_country']['expose']['operator'] = 'field_project_location_country_op';
  $handler->display->display_options['filters']['field_project_location_country']['expose']['identifier'] = 'project_country';
  $handler->display->display_options['filters']['field_project_location_country']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'project-geojson';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_geojson_feed';
  $handler->display->display_options['style_options']['data_source']['value'] = 'geofield';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_gps_coordinates_project';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'title';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'title_field_et';
  $handler->display->display_options['style_options']['data_source']['description_field'] = 'field_description';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Funding area */
  $handler->display->display_options['fields']['field_broad_area']['id'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['table'] = 'field_data_field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['field'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['label'] = 'Funding area(s)';
  $handler->display->display_options['fields']['field_broad_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_broad_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_broad_area']['delta_offset'] = '0';
  /* Field: Content: EU Budget contribution to the project */
  $handler->display->display_options['fields']['field_eu_budget_contribution']['id'] = 'field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['table'] = 'field_data_field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['field'] = 'field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['label'] = 'EU  contributions';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_eu_budget_contribution']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_eu_budget_contribution']['alter']['text'] = 'EUR [field_eu_budget_contribution] ';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_eu_budget_contribution']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: GPS coordinates project location */
  $handler->display->display_options['fields']['field_gps_coordinates_project']['id'] = 'field_gps_coordinates_project';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['table'] = 'field_data_field_gps_coordinates_project';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['field'] = 'field_gps_coordinates_project';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['label'] = '';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gps_coordinates_project']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 0,
  );
  $handler->display->display_options['fields']['field_gps_coordinates_project']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_gps_coordinates_project']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['delta_offset'] = '0';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et']['id'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['label'] = 'Name';
  $handler->display->display_options['fields']['title_field_et']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field_et']['alter']['text'] = '<a href="[path]" data-nid="[nid]!>[title_field_et]</a>';
  $handler->display->display_options['fields']['title_field_et']['empty'] = '<a href="[path]" data-nid="[nid]" data-language="en">[title_field_et_1]</a> [en]';
  $handler->display->display_options['fields']['title_field_et']['hide_alter_empty'] = FALSE;
  /* Field: Content: Programme name */
  $handler->display->display_options['fields']['field_programme_name']['id'] = 'field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['table'] = 'field_data_field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['field'] = 'field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['label'] = 'Programm';
  $handler->display->display_options['fields']['field_programme_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_programme_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_name']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_programme_name']['delta_offset'] = '0';
  /* Field: Content: EC’s priorities */
  $handler->display->display_options['fields']['field_ec_priorities_']['id'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['table'] = 'field_data_field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['field'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ec_priorities_']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_ec_priorities_']['delta_offset'] = '0';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = 'https://ec.europa.eu[view_node]';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '<h3>Funding area(s)</h3>
<p>[field_broad_area] </p>
<h3>EU contribution</h3>
<p>[field_eu_budget_contribution] </p>
<h3>Description</h3>
<div>[field_description]</div>
<span class="more_info"><a href="[path]" data-nid="[nid]">view</a></span>


';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['settings'] = array(
    'trim_length' => '3000',
  );
  /* Field: Content: Project location - Country */
  $handler->display->display_options['fields']['field_project_location_country']['id'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['fields']['field_project_location_country']['field'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_location_country']['display_name'] = 1;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Project location - Country */
  $handler->display->display_options['filters']['field_project_location_country']['id'] = 'field_project_location_country';
  $handler->display->display_options['filters']['field_project_location_country']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['filters']['field_project_location_country']['field'] = 'field_project_location_country';
  $handler->display->display_options['filters']['field_project_location_country']['group'] = 1;
  $handler->display->display_options['filters']['field_project_location_country']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_location_country']['expose']['operator_id'] = 'field_project_location_country_op';
  $handler->display->display_options['filters']['field_project_location_country']['expose']['label'] = 'Project location - Country';
  $handler->display->display_options['filters']['field_project_location_country']['expose']['operator'] = 'field_project_location_country_op';
  $handler->display->display_options['filters']['field_project_location_country']['expose']['identifier'] = 'project_country';
  $handler->display->display_options['filters']['field_project_location_country']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
  );
  /* Filter criterion: Funding area (field_broad_area) (selective) */
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['id'] = 'field_broad_area_tid_selective';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['table'] = 'field_data_field_broad_area';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['field'] = 'field_broad_area_tid_selective';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['ui_name'] = 'Funding area (field_broad_area) (selective)';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['label'] = 'Funding area (field_broad_area) (selective)';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['identifier'] = 'broad_area';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['selective_display_field'] = 'field_broad_area';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: EC’s priorities (field_ec_priorities_) (selective) */
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['id'] = 'field_ec_priorities__tid_selective';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['table'] = 'field_data_field_ec_priorities_';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['field'] = 'field_ec_priorities__tid_selective';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['ui_name'] = 'EC’s priorities (field_ec_priorities_) (selective)';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['expose']['label'] = 'EC’s priorities (field_ec_priorities_) (selective)';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['expose']['identifier'] = 'ec_priorities';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    23 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    28 => 0,
    29 => 0,
    30 => 0,
    31 => 0,
    32 => 0,
    33 => 0,
    34 => 0,
    35 => 0,
    36 => 0,
    37 => 0,
  );
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['selective_display_field'] = 'field_ec_priorities_';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Programme name (field_programme_name) (selective) */
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['id'] = 'field_programme_name_tid_selective';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['table'] = 'field_data_field_programme_name';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['field'] = 'field_programme_name_tid_selective';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['ui_name'] = 'Programme name (field_programme_name) (selective)';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['label'] = 'Programme name (field_programme_name) (selective)';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['identifier'] = 'programme';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['selective_display_field'] = 'field_programme_name';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
    9 => 0,
  );
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search Terms';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: EU Budget contribution to the project (field_eu_budget_contribution) */
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['id'] = 'field_eu_budget_contribution_value';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['table'] = 'field_data_field_eu_budget_contribution';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['field'] = 'field_eu_budget_contribution_value';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['expose']['operator_id'] = 'field_eu_budget_contribution_value_op';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['expose']['label'] = 'EU Budget contribution (field_eu_budget_contribution)';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['expose']['operator'] = 'field_eu_budget_contribution_value_op';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['expose']['identifier'] = 'field_eu_budget_contribution_value';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['group_info']['label'] = 'EU Budget contribution (field_eu_budget_contribution)';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['group_info']['identifier'] = 'eu_contribution';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => '< 1000 ',
      'operator' => '<',
      'value' => array(
        'value' => '1000 ',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => '10000 - 99999',
      'operator' => 'between',
      'value' => array(
        'value' => '',
        'min' => '10000  ',
        'max' => '99999',
      ),
    ),
    3 => array(
      'title' => '100000 - 999999',
      'operator' => 'between',
      'value' => array(
        'value' => '',
        'min' => '100000',
        'max' => '999999',
      ),
    ),
    4 => array(
      'title' => '>= 1000000',
      'operator' => '>=',
      'value' => array(
        'value' => '1000000',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  $handler->display->display_options['field_config'] = array(
    'path' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'nid' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_broad_area' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_eu_budget_contribution' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_gps_coordinates_project' => array(
      'merge_option' => 'filter',
      'separator' => ';',
    ),
    'title' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_programme_name' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_ec_priorities_' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'view_node' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_visual' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_achievements' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_location_country' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
  );
  $handler->display->display_options['path'] = 'projects-geojson';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );

  /* Display: Feed export */
  $handler = $view->new_display('feed', 'Feed export', 'feed_1');
  $handler->display->display_options['display_description'] = 'For integration in external sites';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_geojson_feed';
  $handler->display->display_options['style_options']['data_source']['value'] = 'geofield';
  $handler->display->display_options['style_options']['data_source']['latitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['longitude'] = 'title';
  $handler->display->display_options['style_options']['data_source']['geofield'] = 'field_gps_coordinates_project';
  $handler->display->display_options['style_options']['data_source']['wkt'] = 'title';
  $handler->display->display_options['style_options']['data_source']['name_field'] = 'title';
  $handler->display->display_options['style_options']['data_source']['description_field'] = 'field_description';
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: GPS coordinates project location */
  $handler->display->display_options['fields']['field_gps_coordinates_project']['id'] = 'field_gps_coordinates_project';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['table'] = 'field_data_field_gps_coordinates_project';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['field'] = 'field_gps_coordinates_project';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['label'] = '';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gps_coordinates_project']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 0,
  );
  $handler->display->display_options['fields']['field_gps_coordinates_project']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_gps_coordinates_project']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_gps_coordinates_project']['delta_offset'] = '0';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Programme name */
  $handler->display->display_options['fields']['field_programme_name']['id'] = 'field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['table'] = 'field_data_field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['field'] = 'field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['label'] = 'Programm';
  $handler->display->display_options['fields']['field_programme_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_programme_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_name']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_programme_name']['delta_offset'] = '0';
  /* Field: Content: EC’s priorities */
  $handler->display->display_options['fields']['field_ec_priorities_']['id'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['table'] = 'field_data_field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['field'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ec_priorities_']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_ec_priorities_']['delta_offset'] = '0';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = 'https://ec.europa.eu[view_node]';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Field: Content: EU Budget contribution to the project */
  $handler->display->display_options['fields']['field_eu_budget_contribution']['id'] = 'field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['table'] = 'field_data_field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['field'] = 'field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_eu_budget_contribution']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['text'] = '<div class="categories">
  <div class="field programme_name">[field_programme_name]</div> <divclass="field_ec_priorities">[field_ec_priorities_]  </div>
<div class="field_eu_budget_contribution"><span class="label">EU Contribution:</span><span class="amount">EUR [field_eu_budget_contribution]</span></div>
</div>
<div class="description">
 [field_description]
<span class="more_info"><a href="https://ec.europa.eu[path]" target="_blank">view</a></span>
</div>


';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_description']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: Content: Results */
  $handler->display->display_options['fields']['field_project_achievements']['id'] = 'field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['table'] = 'field_data_field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['field'] = 'field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['label'] = '';
  $handler->display->display_options['fields']['field_project_achievements']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_achievements']['element_label_colon'] = FALSE;
  /* Field: Content: Project location - Country */
  $handler->display->display_options['fields']['field_project_location_country']['id'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['fields']['field_project_location_country']['field'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_location_country']['display_name'] = 1;
  /* Field: Content: Funding area */
  $handler->display->display_options['fields']['field_broad_area']['id'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['table'] = 'field_data_field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['field'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['label'] = '';
  $handler->display->display_options['fields']['field_broad_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_broad_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_broad_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_broad_area']['delta_offset'] = '0';
  $handler->display->display_options['merge_rows'] = TRUE;
  $handler->display->display_options['field_config'] = array(
    'field_gps_coordinates_project' => array(
      'merge_option' => 'filter',
      'separator' => ';',
    ),
    'path' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_programme_name' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_ec_priorities_' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'view_node' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_eu_budget_contribution' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_achievements' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_location_country' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_broad_area' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
  );
  $handler->display->display_options['path'] = 'projects-geojson-external';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $export['project_geojson'] = $view;

  $view = new view();
  $view->name = 'search_projects';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Search Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '21600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear';
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '< Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next >';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['separator'] = 'test';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et']['id'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['label'] = '';
  $handler->display->display_options['fields']['title_field_et']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field_et']['language'] = 'en';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['empty'] = '[title_field_et]';
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Content: Results */
  $handler->display->display_options['fields']['field_project_achievements']['id'] = 'field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['table'] = 'field_data_field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['field'] = 'field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['label'] = '';
  $handler->display->display_options['fields']['field_project_achievements']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_achievements']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_project_achievements']['alter']['text'] = 'EUR [field_project_achievements]';
  $handler->display->display_options['fields']['field_project_achievements']['element_label_colon'] = FALSE;
  /* Field: Content: Programme name */
  $handler->display->display_options['fields']['field_programme_name']['id'] = 'field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['table'] = 'field_data_field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['field'] = 'field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['label'] = '';
  $handler->display->display_options['fields']['field_programme_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_programme_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_name']['delta_offset'] = '0';
  /* Field: Content: EC’s priorities */
  $handler->display->display_options['fields']['field_ec_priorities_']['id'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['table'] = 'field_data_field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['field'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['label'] = '';
  $handler->display->display_options['fields']['field_ec_priorities_']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ec_priorities_']['element_label_colon'] = FALSE;
  /* Field: Content: Project location - Country */
  $handler->display->display_options['fields']['field_project_location_country']['id'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['fields']['field_project_location_country']['field'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['label'] = '';
  $handler->display->display_options['fields']['field_project_location_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_location_country']['display_name'] = 1;
  /* Field: Content: Funding area */
  $handler->display->display_options['fields']['field_broad_area']['id'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['table'] = 'field_data_field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['field'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_broad_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_broad_area']['delta_offset'] = '0';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd-m-Y H:i:s';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['changed']['timezone'] = 'Europe/Brussels';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: Content: EU Budget contribution to the project (field_eu_budget_contribution) */
  $handler->display->display_options['sorts']['field_eu_budget_contribution_value']['id'] = 'field_eu_budget_contribution_value';
  $handler->display->display_options['sorts']['field_eu_budget_contribution_value']['table'] = 'field_data_field_eu_budget_contribution';
  $handler->display->display_options['sorts']['field_eu_budget_contribution_value']['field'] = 'field_eu_budget_contribution_value';
  $handler->display->display_options['sorts']['field_eu_budget_contribution_value']['expose']['label'] = 'EU Budget contribution to the project (field_eu_budget_contribution)';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Broad area (field_broad_area) (selective) */
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['id'] = 'field_broad_area_tid_selective';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['table'] = 'field_data_field_broad_area';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['field'] = 'field_broad_area_tid_selective';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['ui_name'] = 'Broad area (field_broad_area) (selective)';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['label'] = 'Funding areas';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['identifier'] = 'im_field_broad_area';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    23 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    28 => 0,
    29 => 0,
    30 => 0,
    31 => 0,
    32 => 0,
    33 => 0,
    34 => 0,
    35 => 0,
    36 => 0,
    37 => 0,
  );
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['selective_display_field'] = 'field_broad_area';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Project location - Country (selective) */
  $handler->display->display_options['filters']['field_project_location_country_selective']['id'] = 'field_project_location_country_selective';
  $handler->display->display_options['filters']['field_project_location_country_selective']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['filters']['field_project_location_country_selective']['field'] = 'field_project_location_country_selective';
  $handler->display->display_options['filters']['field_project_location_country_selective']['ui_name'] = 'Project location - Country (selective)';
  $handler->display->display_options['filters']['field_project_location_country_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_project_location_country_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_location_country_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_project_location_country_selective']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_project_location_country_selective']['expose']['identifier'] = 'sm_af_country';
  $handler->display->display_options['filters']['field_project_location_country_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    23 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    28 => 0,
    29 => 0,
    30 => 0,
    31 => 0,
    32 => 0,
    33 => 0,
    34 => 0,
    35 => 0,
    36 => 0,
    37 => 0,
  );
  $handler->display->display_options['filters']['field_project_location_country_selective']['selective_display_field'] = 'field_project_location_country';
  $handler->display->display_options['filters']['field_project_location_country_selective']['selective_items_limit'] = '200';
  /* Filter criterion: Programme name (field_programme_name) (selective) */
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['id'] = 'field_programme_name_tid_selective';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['table'] = 'field_data_field_programme_name';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['field'] = 'field_programme_name_tid_selective';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['ui_name'] = 'Programme name (field_programme_name) (selective)';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['label'] = 'Programme name';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['identifier'] = 'im_field_programme_name';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    23 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    28 => 0,
    29 => 0,
    30 => 0,
    31 => 0,
    32 => 0,
    33 => 0,
    34 => 0,
    35 => 0,
    36 => 0,
    37 => 0,
  );
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['selective_display_field'] = 'field_programme_name';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search Terms';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'content';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    23 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    28 => 0,
    29 => 0,
    30 => 0,
    31 => 0,
    32 => 0,
    33 => 0,
    34 => 0,
    35 => 0,
    36 => 0,
    37 => 0,
  );
  /* Filter criterion: MFF Period */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['ui_name'] = 'MFF Period';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    792 => '792',
    844 => '844',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'MFF Period';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'mff_period';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['group_info']['label'] = 'Has taxonomy terms (with depth)';
  $handler->display->display_options['filters']['term_node_tid_depth']['group_info']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['term_node_tid_depth']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'mff_programmes';
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '10';
  /* Filter criterion: EC’s priorities (field_ec_priorities_) (selective) */
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['id'] = 'field_ec_priorities__tid_selective';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['table'] = 'field_data_field_ec_priorities_';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['field'] = 'field_ec_priorities__tid_selective';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['ui_name'] = 'EC’s priorities (field_ec_priorities_) (selective)';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['expose']['label'] = 'EC’s priorities (field_ec_priorities_) (selective)';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['expose']['identifier'] = 'im_field_ec_priorities_';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    23 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    28 => 0,
    29 => 0,
    30 => 0,
    31 => 0,
    32 => 0,
    33 => 0,
    34 => 0,
    35 => 0,
    36 => 0,
    37 => 0,
  );
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['selective_display_field'] = 'field_ec_priorities_';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Content: EU Budget contribution to the project (field_eu_budget_contribution) */
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['id'] = 'field_eu_budget_contribution_value';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['table'] = 'field_data_field_eu_budget_contribution';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['field'] = 'field_eu_budget_contribution_value';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['expose']['operator_id'] = 'field_eu_budget_contribution_value_op';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['expose']['label'] = 'EU Budget contribution (field_eu_budget_contribution)';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['expose']['operator'] = 'field_eu_budget_contribution_value_op';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['expose']['identifier'] = 'field_eu_budget_contribution_value';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['group_info']['label'] = 'EU Budget contribution (field_eu_budget_contribution)';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['group_info']['identifier'] = 'its_field_eu_budget_contribution';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => '< 10 000',
      'operator' => '<',
      'value' => array(
        'value' => '10000',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => '10 000 - 99 999',
      'operator' => 'between',
      'value' => array(
        'value' => '',
        'min' => '10000',
        'max' => '99999',
      ),
    ),
    3 => array(
      'title' => '100 000 - 999 999',
      'operator' => 'between',
      'value' => array(
        'value' => '',
        'min' => '100000',
        'max' => '999999',
      ),
    ),
    4 => array(
      'title' => '>= 1 000 000',
      'operator' => '>=',
      'value' => array(
        'value' => '1000000',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Search Page List */
  $handler = $view->new_display('page', 'Search Page List', 'page_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '< Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next >';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Content: Results */
  $handler->display->display_options['fields']['field_project_achievements']['id'] = 'field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['table'] = 'field_data_field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['field'] = 'field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['label'] = '';
  $handler->display->display_options['fields']['field_project_achievements']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_achievements']['element_label_colon'] = FALSE;
  /* Field: Content: Programme name */
  $handler->display->display_options['fields']['field_programme_name']['id'] = 'field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['table'] = 'field_data_field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['field'] = 'field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['label'] = '';
  $handler->display->display_options['fields']['field_programme_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_programme_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_name']['delta_offset'] = '0';
  /* Field: Content: EC’s priorities */
  $handler->display->display_options['fields']['field_ec_priorities_']['id'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['table'] = 'field_data_field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['field'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['label'] = '';
  $handler->display->display_options['fields']['field_ec_priorities_']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ec_priorities_']['element_label_colon'] = FALSE;
  /* Field: Content: Project location - Country */
  $handler->display->display_options['fields']['field_project_location_country']['id'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['fields']['field_project_location_country']['field'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['label'] = '';
  $handler->display->display_options['fields']['field_project_location_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_location_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_location_country']['display_name'] = 0;
  /* Field: Content: Funding area */
  $handler->display->display_options['fields']['field_broad_area']['id'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['table'] = 'field_data_field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['field'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_broad_area']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_broad_area']['delta_offset'] = '0';
  /* Field: Content: EU Budget contribution to the project */
  $handler->display->display_options['fields']['field_eu_budget_contribution']['id'] = 'field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['table'] = 'field_data_field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['field'] = 'field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_eu_budget_contribution']['alter']['text'] = 'EUR [title]';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['settings'] = array(
    'thousand_separator' => '.',
    'prefix_suffix' => 1,
  );
  /* Field: Content: EC’s priorities */
  $handler->display->display_options['fields']['field_ec_priorities__1']['id'] = 'field_ec_priorities__1';
  $handler->display->display_options['fields']['field_ec_priorities__1']['table'] = 'field_data_field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities__1']['field'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities__1']['label'] = '';
  $handler->display->display_options['fields']['field_ec_priorities__1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ec_priorities__1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ec_priorities__1']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Keywords ';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Project location - Country (selective) */
  $handler->display->display_options['filters']['field_project_location_country_selective']['id'] = 'field_project_location_country_selective';
  $handler->display->display_options['filters']['field_project_location_country_selective']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['filters']['field_project_location_country_selective']['field'] = 'field_project_location_country_selective';
  $handler->display->display_options['filters']['field_project_location_country_selective']['ui_name'] = 'Project location - Country (selective)';
  $handler->display->display_options['filters']['field_project_location_country_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_project_location_country_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_location_country_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_project_location_country_selective']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_project_location_country_selective']['expose']['identifier'] = 'project_country';
  $handler->display->display_options['filters']['field_project_location_country_selective']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_location_country_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_project_location_country_selective']['selective_display_field'] = 'field_project_location_country';
  $handler->display->display_options['filters']['field_project_location_country_selective']['selective_items_limit'] = '200';
  /* Filter criterion: Broad area (field_broad_area) (selective) */
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['id'] = 'field_broad_area_tid_selective';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['table'] = 'field_data_field_broad_area';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['field'] = 'field_broad_area_tid_selective';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['ui_name'] = 'Broad area (field_broad_area) (selective)';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['label'] = 'Funding areas';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['identifier'] = 'broad_area';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['selective_display_field'] = 'field_broad_area';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Programme name (field_programme_name) (selective) */
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['id'] = 'field_programme_name_tid_selective';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['table'] = 'field_data_field_programme_name';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['field'] = 'field_programme_name_tid_selective';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['ui_name'] = 'Programme name (field_programme_name) (selective)';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['label'] = 'Programme name';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['identifier'] = 'programme';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['selective_display_field'] = 'field_programme_name';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: EC’s priorities (field_ec_priorities_) (selective) */
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['id'] = 'field_ec_priorities__tid_selective_1';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['table'] = 'field_data_field_ec_priorities_';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['field'] = 'field_ec_priorities__tid_selective';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['ui_name'] = 'EC’s priorities (field_ec_priorities_) (selective)';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['group'] = 1;
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['expose']['label'] = 'EC’s priorities';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['expose']['identifier'] = 'ec_priorities';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['selective_display_field'] = 'field_ec_priorities_';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['selective_items_limit'] = '100';
  /* Filter criterion: Content: EU Budget contribution to the project (field_eu_budget_contribution) */
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['id'] = 'field_eu_budget_contribution_value';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['table'] = 'field_data_field_eu_budget_contribution';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['field'] = 'field_eu_budget_contribution_value';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['expose']['operator_id'] = 'field_eu_budget_contribution_value_op';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['expose']['label'] = 'EU Budget contribution (field_eu_budget_contribution)';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['expose']['operator'] = 'field_eu_budget_contribution_value_op';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['expose']['identifier'] = 'field_eu_budget_contribution_value';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['group_info']['label'] = 'EU contribution';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['group_info']['identifier'] = 'eu_contribution';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => '< 10 000',
      'operator' => '<',
      'value' => array(
        'value' => '10000',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => '10 000 - 99 999',
      'operator' => 'between',
      'value' => array(
        'value' => '',
        'min' => '10000',
        'max' => '99999',
      ),
    ),
    3 => array(
      'title' => '100 000 - 999 999',
      'operator' => 'between',
      'value' => array(
        'value' => '',
        'min' => '100000',
        'max' => '999 999',
      ),
    ),
    4 => array(
      'title' => '>= 1 000 000',
      'operator' => '>=',
      'value' => array(
        'value' => '1000000',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  $handler->display->display_options['field_config'] = array(
    'title' => array(
      'merge_option' => 'filter',
      'separator' => ';',
    ),
    'field_description' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_achievements' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_programme_name' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_ec_priorities_' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_location_country' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_broad_area' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
  );
  $handler->display->display_options['path'] = 'search-projects1';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Project list';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'List';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['link_field'] = 'path';
  $handler->display->display_options['row_options']['description_field'] = 'field_description';
  $handler->display->display_options['row_options']['creator_field'] = 'name';
  $handler->display->display_options['row_options']['date_field'] = 'changed';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'nid',
    'guid_field_is_permalink' => 1,
  );
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['merge_rows'] = TRUE;
  $handler->display->display_options['field_config'] = array(
    'title' => array(
      'merge_option' => 'filter',
      'separator' => ';',
    ),
    'field_description' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_achievements' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_programme_name' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_ec_priorities_' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_location_country' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_broad_area' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'nid' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'changed' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'name' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'path' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
  );
  $handler->display->display_options['path'] = 'search-projects/rss';

  /* Display: Search Page Map JPO */
  $handler = $view->new_display('page', 'Search Page Map JPO', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Search for the opend orrs days';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['text_input_required'] = '';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Content: Results */
  $handler->display->display_options['fields']['field_project_achievements']['id'] = 'field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['table'] = 'field_data_field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['field'] = 'field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['label'] = '';
  $handler->display->display_options['fields']['field_project_achievements']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_achievements']['element_label_colon'] = FALSE;
  /* Field: Content: Programme name */
  $handler->display->display_options['fields']['field_programme_name']['id'] = 'field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['table'] = 'field_data_field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['field'] = 'field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['label'] = '';
  $handler->display->display_options['fields']['field_programme_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_programme_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_name']['delta_offset'] = '0';
  /* Field: Content: EC’s priorities */
  $handler->display->display_options['fields']['field_ec_priorities_']['id'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['table'] = 'field_data_field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['field'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['label'] = '';
  $handler->display->display_options['fields']['field_ec_priorities_']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ec_priorities_']['element_label_colon'] = FALSE;
  /* Field: Content: Project location - Country */
  $handler->display->display_options['fields']['field_project_location_country']['id'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['fields']['field_project_location_country']['field'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['label'] = '';
  $handler->display->display_options['fields']['field_project_location_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_location_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_location_country']['display_name'] = 0;
  /* Field: JS path */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'JS path';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'websimple.be/eu_scripts/eu_projects_theme_maps.js';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Funding area */
  $handler->display->display_options['fields']['field_broad_area']['id'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['table'] = 'field_data_field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['field'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['label'] = '';
  $handler->display->display_options['fields']['field_broad_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_broad_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_broad_area']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Please type the project ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
  );
  $handler->display->display_options['path'] = 'jpo';
  $handler->display->display_options['menu']['title'] = 'Map';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'Map';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Block List results */
  $handler = $view->new_display('block', 'Block List results', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '< Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next >';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'path' => 'path',
    'nid' => 'nid',
    'title' => 'title',
    'field_description' => 'field_description',
    'field_project_achievements' => 'field_project_achievements',
    'field_programme_name' => 'field_programme_name',
    'field_ec_priorities_' => 'field_ec_priorities_',
    'field_project_location_country' => 'field_project_location_country',
    'field_broad_area' => 'field_broad_area',
    'field_timeframe' => 'field_timeframe',
    'field_broad_area_1' => 'field_broad_area_1',
    'field_eu_budget_contribution' => 'field_eu_budget_contribution',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'path' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_project_achievements' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_programme_name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ec_priorities_' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_project_location_country' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_broad_area' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_timeframe' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_broad_area_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_eu_budget_contribution' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_1']['id'] = 'title_field_et_1';
  $handler->display->display_options['fields']['title_field_et_1']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_1']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_1']['label'] = '';
  $handler->display->display_options['fields']['title_field_et_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field_et_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field_et_1']['language'] = 'en';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<a  name="Project_[nid]"> </a>';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et']['id'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['label'] = 'Title';
  $handler->display->display_options['fields']['title_field_et']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field_et']['alter']['text'] = '<a href="[path]" id="project_[nid]" data-nid="[nid]" title="[title_field_et]">[title_field_et]</a>';
  $handler->display->display_options['fields']['title_field_et']['empty'] = '<a href="[path]" id="project_[nid]" data-nid="[nid]" data-language="en" title="[title_field_et_1]">[title_field_et_1]</a> [en]';
  $handler->display->display_options['fields']['title_field_et']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title_field_et']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Content: Results */
  $handler->display->display_options['fields']['field_project_achievements']['id'] = 'field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['table'] = 'field_data_field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['field'] = 'field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['label'] = '';
  $handler->display->display_options['fields']['field_project_achievements']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_achievements']['element_label_colon'] = FALSE;
  /* Field: Content: Programme name */
  $handler->display->display_options['fields']['field_programme_name']['id'] = 'field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['table'] = 'field_data_field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['field'] = 'field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['label'] = '';
  $handler->display->display_options['fields']['field_programme_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_programme_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_name']['delta_offset'] = '0';
  /* Field: Content: EC’s priorities */
  $handler->display->display_options['fields']['field_ec_priorities_']['id'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['table'] = 'field_data_field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['field'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['label'] = '';
  $handler->display->display_options['fields']['field_ec_priorities_']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ec_priorities_']['element_label_colon'] = FALSE;
  /* Field: Content: Project location - Country */
  $handler->display->display_options['fields']['field_project_location_country']['id'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['fields']['field_project_location_country']['field'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['label'] = 'Countries';
  $handler->display->display_options['fields']['field_project_location_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_location_country']['display_name'] = 1;
  /* Field: Content: Funding area */
  $handler->display->display_options['fields']['field_broad_area']['id'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['table'] = 'field_data_field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['field'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_broad_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_broad_area']['delta_offset'] = '0';
  /* Field: Content: Timeframe */
  $handler->display->display_options['fields']['field_timeframe']['id'] = 'field_timeframe';
  $handler->display->display_options['fields']['field_timeframe']['table'] = 'field_data_field_timeframe';
  $handler->display->display_options['fields']['field_timeframe']['field'] = 'field_timeframe';
  $handler->display->display_options['fields']['field_timeframe']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Funding area */
  $handler->display->display_options['fields']['field_broad_area_1']['id'] = 'field_broad_area_1';
  $handler->display->display_options['fields']['field_broad_area_1']['table'] = 'field_data_field_broad_area';
  $handler->display->display_options['fields']['field_broad_area_1']['field'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area_1']['label'] = 'Funding areas';
  $handler->display->display_options['fields']['field_broad_area_1']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: EU Budget contribution to the project */
  $handler->display->display_options['fields']['field_eu_budget_contribution']['id'] = 'field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['table'] = 'field_data_field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['field'] = 'field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['label'] = 'EU contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['merge_rows'] = TRUE;
  $handler->display->display_options['field_config'] = array(
    'path' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'nid' => array(
      'merge_option' => 'filter',
      'separator' => ';',
    ),
    'title_field_et' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_achievements' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_programme_name' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_ec_priorities_' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_location_country' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_broad_area' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_timeframe' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_broad_area_1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_eu_budget_contribution' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
  );
  $handler->display->display_options['block_caching'] = '8';

  /* Display: Block Grid results */
  $handler = $view->new_display('block', 'Block Grid results', 'block_2');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et_1']['id'] = 'title_field_et_1';
  $handler->display->display_options['fields']['title_field_et_1']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et_1']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et_1']['label'] = '';
  $handler->display->display_options['fields']['title_field_et_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field_et_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field_et_1']['language'] = 'en';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<div  id="project_[nid]"> </div>';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Visual */
  $handler->display->display_options['fields']['field_visual']['id'] = 'field_visual';
  $handler->display->display_options['fields']['field_visual']['table'] = 'field_data_field_visual';
  $handler->display->display_options['fields']['field_visual']['field'] = 'field_visual';
  $handler->display->display_options['fields']['field_visual']['label'] = '';
  $handler->display->display_options['fields']['field_visual']['alter']['text'] = '[field_visual-display]


';
  $handler->display->display_options['fields']['field_visual']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_visual']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_visual']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_visual']['settings'] = array(
    'file_view_mode' => 'media_crop',
  );
  $handler->display->display_options['fields']['field_visual']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_visual']['delta_offset'] = '0';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et']['id'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['label'] = '';
  $handler->display->display_options['fields']['title_field_et']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field_et']['alter']['text'] = '<a href="[path]" data-nid="[nid_1]">[title_field_et] </a>';
  $handler->display->display_options['fields']['title_field_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field_et']['empty'] = '<a href="[path]" data-nid="[nid_1]" data-language="en">[title_field_et_1]</a> [en]';
  $handler->display->display_options['fields']['title_field_et']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['title_field_et']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Content: Project location - Country */
  $handler->display->display_options['fields']['field_project_location_country']['id'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['fields']['field_project_location_country']['field'] = 'field_project_location_country';
  $handler->display->display_options['fields']['field_project_location_country']['label'] = 'Countries:';
  $handler->display->display_options['fields']['field_project_location_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_location_country']['display_name'] = 1;
  /* Field: Content: Timeframe */
  $handler->display->display_options['fields']['field_timeframe']['id'] = 'field_timeframe';
  $handler->display->display_options['fields']['field_timeframe']['table'] = 'field_data_field_timeframe';
  $handler->display->display_options['fields']['field_timeframe']['field'] = 'field_timeframe';
  $handler->display->display_options['fields']['field_timeframe']['label'] = 'Timeframe:';
  $handler->display->display_options['fields']['field_timeframe']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_timeframe']['settings'] = array(
    'format_type' => 'year',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: EU Budget contribution to the project */
  $handler->display->display_options['fields']['field_eu_budget_contribution']['id'] = 'field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['table'] = 'field_data_field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['field'] = 'field_eu_budget_contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['label'] = 'EU contribution';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['alter']['text'] = 'EUR [field_eu_budget_contribution]';
  $handler->display->display_options['fields']['field_eu_budget_contribution']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Content: Results */
  $handler->display->display_options['fields']['field_project_achievements']['id'] = 'field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['table'] = 'field_data_field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['field'] = 'field_project_achievements';
  $handler->display->display_options['fields']['field_project_achievements']['label'] = '';
  $handler->display->display_options['fields']['field_project_achievements']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_achievements']['element_label_colon'] = FALSE;
  /* Field: Content: Programme name */
  $handler->display->display_options['fields']['field_programme_name']['id'] = 'field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['table'] = 'field_data_field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['field'] = 'field_programme_name';
  $handler->display->display_options['fields']['field_programme_name']['label'] = '';
  $handler->display->display_options['fields']['field_programme_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_programme_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_programme_name']['delta_offset'] = '0';
  /* Field: Content: EC’s priorities */
  $handler->display->display_options['fields']['field_ec_priorities_']['id'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['table'] = 'field_data_field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['field'] = 'field_ec_priorities_';
  $handler->display->display_options['fields']['field_ec_priorities_']['label'] = '';
  $handler->display->display_options['fields']['field_ec_priorities_']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ec_priorities_']['element_label_colon'] = FALSE;
  /* Field: Content: Funding area */
  $handler->display->display_options['fields']['field_broad_area']['id'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['table'] = 'field_data_field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['field'] = 'field_broad_area';
  $handler->display->display_options['fields']['field_broad_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_broad_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_broad_area']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Broad area (field_broad_area) (selective) */
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['id'] = 'field_broad_area_tid_selective';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['table'] = 'field_data_field_broad_area';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['field'] = 'field_broad_area_tid_selective';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['ui_name'] = 'Broad area (field_broad_area) (selective)';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['label'] = 'Funding areas';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['identifier'] = 'im_field_broad_area';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    23 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    28 => 0,
    29 => 0,
    30 => 0,
    31 => 0,
    32 => 0,
    33 => 0,
    34 => 0,
    35 => 0,
    36 => 0,
    37 => 0,
  );
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['selective_display_field'] = 'field_broad_area';
  $handler->display->display_options['filters']['field_broad_area_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Project location - Country (selective) */
  $handler->display->display_options['filters']['field_project_location_country_selective']['id'] = 'field_project_location_country_selective';
  $handler->display->display_options['filters']['field_project_location_country_selective']['table'] = 'field_data_field_project_location';
  $handler->display->display_options['filters']['field_project_location_country_selective']['field'] = 'field_project_location_country_selective';
  $handler->display->display_options['filters']['field_project_location_country_selective']['ui_name'] = 'Project location - Country (selective)';
  $handler->display->display_options['filters']['field_project_location_country_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_project_location_country_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_location_country_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_project_location_country_selective']['expose']['label'] = 'Project location - Country (selective)';
  $handler->display->display_options['filters']['field_project_location_country_selective']['expose']['identifier'] = 'sm_af_country';
  $handler->display->display_options['filters']['field_project_location_country_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    23 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    28 => 0,
    29 => 0,
    30 => 0,
    31 => 0,
    32 => 0,
    33 => 0,
    34 => 0,
    35 => 0,
    36 => 0,
    37 => 0,
  );
  $handler->display->display_options['filters']['field_project_location_country_selective']['selective_display_field'] = 'field_project_location_country';
  $handler->display->display_options['filters']['field_project_location_country_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Programme name (field_programme_name) (selective) */
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['id'] = 'field_programme_name_tid_selective';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['table'] = 'field_data_field_programme_name';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['field'] = 'field_programme_name_tid_selective';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['ui_name'] = 'Programme name (field_programme_name) (selective)';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['label'] = 'Programme name';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['identifier'] = 'im_field_programme_name';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    23 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    28 => 0,
    29 => 0,
    30 => 0,
    31 => 0,
    32 => 0,
    33 => 0,
    34 => 0,
    35 => 0,
    36 => 0,
    37 => 0,
  );
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['selective_display_field'] = 'field_programme_name';
  $handler->display->display_options['filters']['field_programme_name_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'content';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    23 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    28 => 0,
    29 => 0,
    30 => 0,
    31 => 0,
    32 => 0,
    33 => 0,
    34 => 0,
    35 => 0,
    36 => 0,
    37 => 0,
  );
  /* Filter criterion: EC’s priorities (field_ec_priorities_) (selective) */
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['id'] = 'field_ec_priorities__tid_selective_1';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['table'] = 'field_data_field_ec_priorities_';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['field'] = 'field_ec_priorities__tid_selective';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['ui_name'] = 'EC’s priorities (field_ec_priorities_) (selective)';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['group'] = 1;
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['expose']['label'] = 'EC’s priorities (field_ec_priorities_) (selective)';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['expose']['identifier'] = 'im_field_ec_priorities_';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    7 => 0,
    6 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    14 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
    23 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    28 => 0,
    29 => 0,
    30 => 0,
    31 => 0,
    32 => 0,
    33 => 0,
    34 => 0,
    35 => 0,
    36 => 0,
    37 => 0,
  );
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['selective_display_field'] = 'field_ec_priorities_';
  $handler->display->display_options['filters']['field_ec_priorities__tid_selective_1']['selective_items_limit'] = '100';
  /* Filter criterion: Content: EU Budget contribution to the project (field_eu_budget_contribution) */
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['id'] = 'field_eu_budget_contribution_value';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['table'] = 'field_data_field_eu_budget_contribution';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['field'] = 'field_eu_budget_contribution_value';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['expose']['operator_id'] = 'field_eu_budget_contribution_value_op';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['expose']['label'] = 'EU Budget contribution (field_eu_budget_contribution)';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['expose']['operator'] = 'field_eu_budget_contribution_value_op';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['expose']['identifier'] = 'field_eu_budget_contribution_value';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['group_info']['label'] = 'EU Budget contribution (field_eu_budget_contribution)';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['group_info']['identifier'] = 'its_field_eu_budget_contribution';
  $handler->display->display_options['filters']['field_eu_budget_contribution_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => '< 10000',
      'operator' => '<',
      'value' => array(
        'value' => '10000',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => '10000 - 99999',
      'operator' => 'between',
      'value' => array(
        'value' => '',
        'min' => '10000',
        'max' => '99999',
      ),
    ),
    3 => array(
      'title' => '100000 - 999999',
      'operator' => 'between',
      'value' => array(
        'value' => '',
        'min' => '100000',
        'max' => '999999',
      ),
    ),
    4 => array(
      'title' => '>= 1000000',
      'operator' => '>=',
      'value' => array(
        'value' => '1000000',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['merge_rows'] = TRUE;
  $handler->display->display_options['field_config'] = array(
    'nid' => array(
      'merge_option' => 'filter',
      'separator' => ';',
    ),
    'nid_1' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'path' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_visual' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'title_field_et' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_location_country' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_timeframe' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_eu_budget_contribution' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_description' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_project_achievements' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_programme_name' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_ec_priorities_' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
    'field_broad_area' => array(
      'merge_option' => 'merge_unique',
      'separator' => ';',
    ),
  );
  $handler->display->display_options['block_caching'] = '8';
  $export['search_projects'] = $view;

  return $export;
}
