<?php
/**
 * @file
 * budg_eu_projects.callbacks.inc
 */

/**
 * Loads the node view.
 *
 * @param int $nid
 *   The nid of the node.
 *
 * @return array
 *    Array containing nid, title and renderable node array.
 */
function _budg_eu_projects_ajax_node_get_ajax($nid) {

  if (intval($nid)) {
    include_once 'budg_eu_projects.functions.inc';

    // Adapts the language.
    _budg_adapt_language();

    // Pass the original url.
    $_GET['q'] = 'node/' . $nid;

    if ($node = node_load($nid)) {
      return array(
        // @codingStandardsIgnoreLine: MULTISITE-16646
        'nid' => $nid,
        'title' => $node->title,
        'node' => node_view($node, 'default'),
      );
    }
  }
}

/**
 * Loads a block.
 *
 * @param string $variable
 *   The block definition.
 *
 * @return array
 *    Renderable array.
 */
function _budg_eu_projects_ajax_block_get_ajax($variable) {
  include_once 'budg_eu_projects.functions.inc';
  $variables = explode('?', $variable);
  $parameters = $variables[0];
  list($module, $block_id, $nid) = explode('|', $parameters);

  // Adapts the language.
  _budg_adapt_language();

  // Pass the original url.
  if (is_int($nid)) {
    $_GET['q'] = 'node/' . $nid;
  }
  else {
    $_GET['q'] = variable_get('site_frontpage', 'node');
  }

  $block = block_load($module, $block_id);
  $block_content = _block_render_blocks(array($block));

  return _block_get_renderable_array($block_content);
}

/**
 * Loads the solr response.
 */
function _budg_eu_projects_solr_geojson() {
  include_once 'budg_eu_projects.functions.inc';
  drupal_page_is_cacheable(TRUE);
  $params = _budg_eu_projects_default_search_values();
  print drupal_json_encode(_budg_eu_projects_solr_prepare_geojson(array('q' => $params)));
}

/**
 * Call back for view switcher.
 */
function _budg_eu_projects_ajax_view_switcher_callback($type = '') {
  drupal_page_is_cacheable(FALSE);
  if ($type == 'ajax') {
    $variables = explode('?', $_SERVER['HTTP_REFERER']);
    $path = $variables[0];
    $view_switcher = _budg_eu_projects_ajax_search_results_block_load('view_switcher');
    $sort_switcher = _budg_eu_projects_ajax_search_results_block_load('sort_switcher');
    $previous_next_button = _budg_eu_projects_ajax_search_results_block_load('previous_next_button');

    $view_switcher_view_display = _budg_eu_projects_ajax_search_results_block_load('view_switcher_view_display');
    $result_display = _budg_eu_projects_result_display();
    $display_view = $result_display['view'];
    $commands = array();
    $commands[] = ajax_command_replace('#block-budg-eu-projects-view-switcher',
        '<section id="block-budg-eu-projects-view-switcher" class="block block-budg-eu-projects contextual-links-region clearfix">' . $view_switcher . '</section>');
    $commands[] = ajax_command_replace('#sort-switcher',
        '<div id="sort-switcher"  class="col-lg-4 clearfix">' . $sort_switcher . '</div>');
    $commands[] = ajax_command_replace('#search-results-display',
        '<section id="search-results-display">' . $view_switcher_view_display . '</div>');
    $commands[] = ajax_command_replace('#project-navigation',
        '<nav id="project-navigation" class="project-navigation">' . $previous_next_button . '</nav>');
    $commands[] = ajax_command_invoke(NULL, 'scroll', array('#block-budg-eu-projects-view-switcher-results'));
    $commands[] = ajax_command_invoke(NULL, 'viewClass', array($display_view));
    $commands[] = ajax_command_invoke(NULL, 'adaptDom');
    $commands[] = ajax_command_invoke(NULL, 'adaptHistory', array($path));
    if ($display_view == 'map') {
      $commands[] = ajax_command_invoke(NULL, 'WtRefresh');
    }
    $page = array(
      '#type' => 'ajax',
      '#commands' => $commands,
    );
    ajax_deliver($page);
  }
  else {
    return '';
  }
}

/**
 * Call back for node loader.
 */
function _budg_eu_projects_ajax_node_callback($page_callback_result) {
  // Only render content.
  $content = drupal_render($page_callback_result['node']);
  $title = $page_callback_result['title'];
  $block = block_load('budg_eu_projects', 'previous_next_button_mobile');
  $block_content = _block_render_blocks(array($block));
  $previous_next_button_mobile = _block_get_renderable_array($block_content);

  $block = block_load('budg_eu_projects', 'previous_next_button');
  $block_content = _block_render_blocks(array($block));
  $previous_next_button = _block_get_renderable_array($block_content);

  $render = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'project-content',
    ),
    'header' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => 'container-fluid page-header__hero-title',
      ),
      'padding' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => 'row padding-reset',
        ),
        'left' => array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => 'col-lg-9',
          ),
          'content' => array(
            'previous_next_button_mobile' => array(
              '#markup' => drupal_render($previous_next_button_mobile),
            ),
            'title' => array(
              '#type' => 'markup',
              '#prefix' => '<h1>',
              '#suffix' => '</h1>',
              '#markup' => $title,
            ),
          ),
        ),
        'right' => array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => 'col-lg-3',
          ),
          'content' => array(
            '#markup' => drupal_render($previous_next_button),
          ),
        ),
      ),
    ),
    'content' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => 'region region-content',
      ),
      'block' => array(
        '#type' => 'container',
        '#attributes' => array(
          'class' => 'block__content',
        ),
        'content' => array(
          '#markup' => $content,
        ),
      ),
    ),
  );

  print render($render);

  // Perform end-of-request tasks.
  drupal_page_footer();
}

/**
 * Call back for block loader.
 */
function _budg_eu_projects_ajax_block_callback($page_callback_result) {
  // Only render content.
  print render($page_callback_result);

  // Perform end-of-request tasks.
  drupal_page_footer();
}

/**
 * Loads the block.
 *
 * @param string $block_name
 *    Name of the block.
 *
 * @return string
 *    Block content.
 */
function _budg_eu_projects_ajax_search_results_block_load($block_name) {
  $block = block_load('budg_eu_projects', $block_name);
  $block_content = _block_render_blocks(array($block));
  $content = _block_get_renderable_array($block_content);
  return render($content);
}
