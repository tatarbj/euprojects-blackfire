<?php
/**
 * @file
 * budg_eu_projects.views.inc
 */

/**
 * Implements hook_views_pre_render().
 */
function budg_eu_projects_views_pre_render(&$view) {

  // Inserts a default image when no or too small visual.
  if ($view->name == 'search_projects' and $view->current_display == 'block_2') {
    $default_image_object = _budg_eu_projects_default_visual();
    $image_entity = file_view($default_image_object, "default");
    $default_copyright = check_plain('©  ' . $image_entity['file']['#item']['field_copyright_notice'][LANGUAGE_NONE][0]['value']);

    $image_entity['field_copyright_notice'] = array(
      '#items' => array(
        0 => array(
          'value' => $default_copyright ,
          'format' => '',
          'safe_value' => $default_copyright,
        ),
      ),
      '0' => array(
        '#markup' => '<div class="field field--field-copyright-notice "><div class="field__items">' . $default_copyright . '</div></div>',
      ),
    );

    drupal_render($image_entity);

    $default_visual = $image_entity['#children'] ? $image_entity['#children'] : '';
    $rendered_fields = $view->style_plugin->render_fields($view->result);
    foreach ($rendered_fields as $index => $row) {
      if (empty($row['field_visual'])) {
        $view->style_plugin->rendered_fields[$index]['field_visual'] = $default_visual;
      }
      elseif ($view->result[$index]->field_field_visual[0]['raw']['width'] < 768) {
        $view->style_plugin->rendered_fields[$index]['field_visual'] = $default_visual;
      }
      else {
        $original = $view->style_plugin->rendered_fields[$index]['field_visual'];
        preg_match("/<div[^>]*class=\"field field--field-copyright-notice[^>]*\"><div[^>]*>(.*?)<\\/div><\\/div>/si",
            $original,
            $match);
        if (isset($match[1])) {
          $copyright = $match[1];
          $copyright_new = '© ' . trim(str_replace('©', '', $match[1]));
          $view->style_plugin->rendered_fields[$index]['field_visual'] = str_replace($copyright, $copyright_new, $original);
        }

      }
    }
  }
}

/**
 * Implements hook_views_query_alter().
 */
function budg_eu_projects_views_query_alter(&$view, &$query) {

  // Sort the results.
  if ($view->name == 'search_projects' and in_array($view->current_display, array(
    'block_1',
    'block_2',
  ))) {
    include_once 'budg_eu_projects.functions.inc';
    $params = drupal_get_query_parameters();
    $result_display = _budg_eu_projects_result_display($params);
    $sort = $result_display['sort'];
    $order = $result_display['order'];

    $fields = array(
      'title' => 'node_title',
      'field_eu_budget_contribution' => 'field_data_field_eu_budget_contribution.field_eu_budget_contribution_value',
    );

    if (isset($fields[$order])) {
      $order = $fields[$order];
    }
    unset($query->orderby);
    $query->orderby[0] = array(
      'field' => $order,
      'direction' => $sort,
    );
  }
}
