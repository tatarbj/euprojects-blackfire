<?php
/**
 * @file
 * budg_eu_projects.blocks.inc
 */

/**
 * Implements hook_block_info().
 */
function budg_eu_projects_block_info() {
  $blocks = array();

  $blocks['previous_next_button'] = array('info' => t('Previous/next button'));

  $blocks['previous_next_button_mobile'] = array('info' => t('Previous/next button Mobile'));

  $blocks['view_switcher'] = array('info' => t('View switcher'));

  $blocks['sort_switcher'] = array('info' => t('Sort by switcher'));

  $blocks['view_switcher_results'] = array('info' => t('View switcher complete block'));

  $blocks['view_switcher_results_count'] = array('info' => t('Search results counter'));

  $blocks['view_switcher_view_display'] = array('info' => t('Selected view display'));

  $blocks['project_search'] = array('info' => t('Project search'));

  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function budg_eu_projects_block_view($delta = '') {
  $block = array();

  switch ($delta) {
    case 'previous_next_button':
      $block['subject'] = '';
      $block['content'] = _budg_eu_projects_previous_next_button_content();
      break;

    case 'previous_next_button_mobile':
      $block['subject'] = '';
      $block['content'] = _budg_eu_projects_previous_next_button_mobile_content();
      break;

    case 'view_switcher':
      $block['subject'] = '';
      $block['content'] = _budg_eu_projects_view_switcher_content();
      break;

    case 'sort_switcher':
      $block['subject'] = '';
      $block['content'] = _budg_eu_projects_sort_switcher_content();
      break;

    case 'view_switcher_results':
      $block['subject'] = '';
      $block['content'] = _budg_eu_projects_view_switcher_results_content();
      break;

    case 'view_switcher_results_count':
      $block['subject'] = '';
      $block['content'] = _budg_eu_projects_view_switcher_results_count_content();
      break;

    case 'view_switcher_view_display':
      $block['subject'] = '';
      $block['content'] = _budg_eu_projects_view_switcher_view_display_content();
      break;

    case 'budg_eu_project_social_bookmarks':
      $block['subject'] = '';
      $block['content'] = _budg_eu_project_social_bookmarks();
      break;

    case 'project_search':
      $block['subject'] = '';
      $block['content'] = _budg_eu_project_project_search();
      break;
  }

  return $block;
}

/**
 * Generates the content of the block previous_next_button.
 *
 * @return string
 *     Content of the block.
 */
function _budg_eu_projects_previous_next_button_content() {
  include_once 'budg_eu_projects.functions.inc';
  $params = drupal_get_query_parameters();
  $result_display = _budg_eu_projects_result_display($params);
  $view_display = $result_display['view'];
  $url_next = '';
  $url_previous = '';
  $nid_previous = '';
  $nid_next = '';
  $title_previous = '';
  $title_next = '';

  if ($view_display != 'map') {
    $node = '';

    if (isset($params['nid'])) {
      $nid = $params['nid'];

    }
    elseif (!$node = menu_get_object()) {
      $url = $_SERVER['HTTP_REFERER'];
      // @codingStandardsIgnoreLine
      $path = explode('_', preg_replace('/\//', '', parse_url($url, PHP_URL_PATH), 1));
      $action = drupal_get_normal_path("source", $path[0]);
      $org_path = drupal_lookup_path($action, $path[0]);
      $node = menu_get_object("node", 1, $org_path);
    }
    if ($node) {
      $nid = $node->nid;
    }
    $filters = _budg_eu_projects_default_search_values($params);
    $current_page = isset($result_display['page'][$view_display]) ? $result_display['page'][$view_display] : 0;

    $blocks = array(
      'grid' => 'block_2',
      'list' => 'block_1',
    );

    $display = $blocks[$view_display];
    $results = _budg_eu_projects_project_in_results('search_projects', $nid, $display, $filters, $current_page);

    $position = $results['position'];
    $view = $results['view'];
    $items_per_page = $view->query->pager->options['items_per_page'];
    $total_items = $view->query->pager->total_items;
    $pages = floor($total_items / $items_per_page);
    // Get the previous url.
    if (!is_null($position)) {
      $position_previous = $position - 1;
      if (isset($view->result[$position_previous]->nid)) {
        $nid_previous = $view->result[$position_previous]->nid;
        $url_previous = url('node/' . $nid_previous);
        $title = trim($view->result[$position_previous]->node_title);
        $title_previous = t('Previous project "@title"', array('@title' => $title));
      }
      elseif ($current_page >= 1) {
        $new_page = $current_page - 1;

        $results = _budg_eu_projects_project_in_results('search_projects', $nid_previous, $display, $filters, $new_page);
        $position_previous = $items_per_page - 1;
        $previous_view = $results['view'];

        if (isset($previous_view->result[$position_previous]->nid)) {
          $nid_previous = $previous_view->result[$position_previous]->nid;
          $url_previous = url('node/' . $nid_previous, array(
            'query' => array(
              'search_display' => 'ok',
              'page' => $new_page,
            ),
          ));
          $title = trim($previous_view->result[$position_previous]->node_title);
          $title_previous = t('Previous project', array('@title' => $title));
        }
      }

      // Get the next url.
      $position_next = $position + 1;
      if (isset($view->result[$position_next]->nid)) {
        $nid_next = $view->result[$position_next]->nid;
        $url_next = url('node/' . $nid_next);
        $title = trim($view->result[$position_next]->node_title);
        $title_next = t('Next project "@title"', array('@title' => $title));
      }
      elseif ($current_page <= $pages - 1) {
        $new_page = $current_page + 1;
        $results_next = _budg_eu_projects_project_in_results('search_projects', $nid_next, $display, $filters, $new_page);
        $next_view = $results_next['view'];
        $position_next = 0;

        if (isset($next_view->result[$position_next]->nid)) {
          $nid_next = $next_view->result[$position_next]->nid;
          $url_next = url('node/' . $nid_next, array(
            'query' => array(
              'search_display' => 'ok',
              'page' => $new_page,
            ),
          ));
          $title = trim($next_view->result[$position_next]->node_title);
          $title_next = t('Next project "@title"', array('@title' => $title));
        }
      }
      $result_scroll = "#project_$nid";
    }
  }
  else {
    $result_scroll = "#block-budg-eu-projects-view-switcher-results";
  }

  $class = array(
    'grid' => 'glyphicon glyphicon-th-large',
    'map' => 'glyphicon glyphicon-map-marker',
    'list' => 'glyphicon glyphicon-list',
  );

  // Display the buttons.
  $render = array(
    '#type' => 'markup',
    '#prefix' => '<nav id="project-navigation" class="project-navigation">',
    '#suffix' => '</nav>',
  );

  $title_back = t('Back to results');
  $scroll = "    <a class='btn btn-secondary budget-scroll' href='$result_scroll' title='" . $title_back . "'>\n";
  $scroll .= "      <span class='glyphicon " . $class[$view_display] . "'></span>\n";
  $scroll .= "    </a>\n";

  if ($url_previous) {
    $previous = "    <a class='btn btn-primary budg-ajax' href='" . $url_previous . "#main-content' title='" . $title_previous . "' data-nid ='$nid_previous' data-display='$display'>\n";
    $previous .= "      <span class='glyphicon view-glyphicon glyphicon glyphicon-menu-left'></span>\n";
    $previous .= "    </a>\n";
    $render['previous'] = array('#markup' => $previous);
  }
  $render['scroll'] = array('#markup' => $scroll);
  if ($url_next) {
    $next = "    <a class='btn btn-primary budg-ajax' href='" . $url_next . "#main-content' title='" . $title_next . "' data-nid ='$nid_next' data-display='$display'>\n";
    $next .= "      <span class='glyphicon view-glyphicon glyphicon glyphicon-menu-right'></span>\n";
    $next .= "    </a>\n";
    $render['next'] = array('#markup' => $next);
  }

  return render($render);
}

/**
 * Generates the content of the block previous_next_button_mobile.
 *
 * @return string
 *     Content of the block.
 */
function _budg_eu_projects_previous_next_button_mobile_content() {
  include_once 'budg_eu_projects.functions.inc';
  $params = drupal_get_query_parameters();
  $result_display = _budg_eu_projects_result_display($params);
  $view_display = $result_display['view'];
  $blocks = array(
    'grid' => 'block_2',
    'list' => 'block_1',
  );

  $display = $blocks[$view_display];

  if ($view_display != 'map') {
    if (isset($params['nid'])) {
      $nid = $params['nid'];
    }
    elseif (!$node = menu_get_object()) {
      $url = $_SERVER['HTTP_REFERER'];
      // @codingStandardsIgnoreLine
      $path = explode('_', preg_replace('/\//', '', parse_url($url, PHP_URL_PATH), 1));
      $action = drupal_get_normal_path("source", $path[0]);
      $org_path = drupal_lookup_path($action, $path[0]);
      $node = menu_get_object("node", 1, $org_path);
    }
    if ($node) {
      $nid = $node->nid;
    }

    $position = '';
    if ($nid) {
      $params = drupal_get_query_parameters();
      $filters = _budg_eu_projects_default_search_values($params);
      $current_page = isset($result_display['page'][$view_display]) ? $result_display['page'][$view_display] : 0;
      $results = _budg_eu_projects_project_in_results('search_projects', $nid, $display, $filters, $current_page);
      $position = $results['position'];
    }

    // Get the previous url.
    if (!is_null($position)) {
      $result_scroll = "#project_$nid";
    }
  }
  else {
    $result_scroll = "#block-budg-eu-projects-view-switcher-results";
  }

  // Display the buttons.
  $render = array(
    '#type' => 'markup',
    '#prefix' => '<nav id="project-navigation-mobile" class="project-navigation-mobile">',
    '#suffix' => '</nav>',
  );

  $title_back = t('Back to results');
  $scroll = "    <a class='btn btn-secondary budget-scroll' href='$result_scroll' title='$title_back'>\n";
  $scroll .= "      <span class='label'>$title_back</span>\n";
  $scroll .= "    </a>\n";

  $render['scroll'] = array('#markup' => $scroll);

  return render($render);
}

/**
 * Generates the content of the block view_switcher.
 *
 * @return string
 *     Content of the block.
 */
function _budg_eu_projects_view_switcher_content() {
  include_once 'budg_eu_projects.functions.inc';

  $data_nid = '';
  if ($node = menu_get_object()) {
    $nid = $node->nid;
    $data_nid = 'data-nid=' . $nid;
  }

  $result_display = _budg_eu_projects_result_display();

  $view = $result_display['view'];

  $links = array(
    'grid' => array(
      'title' => t('Grid View'),
      'class' => 'glyphicon glyphicon-th-large',
    ),
    'map' => array(
      'title' => t('Map View'),
      'class' => 'glyphicon glyphicon-map-marker',
    ),
    'list' => array(
      'title' => t('List View'),
      'class' => 'glyphicon glyphicon-list',
    ),
  );

  $render = array();

  $map_url = $_GET['q'];
  $a_class = ' class="budg-ajax"';

  // The map Switcher.
  if ($view != 'map') {
    $url_patch = url($map_url, array(
      'query' => array(
        'view' => 'map',
      ),
    ));
    $class = 'map';

  }
  else {
    $url_patch = url($map_url, array(
      'query' => array(
        'view' => 'grid',
      ),
    ));
    $class = 'list';
  }
  $render['map_link'] = array(
    '#prefix' => '<div id="map_switcher" class="' . $class . '">',
    '#suffix' => '</div>',
    '#markup' => '<a' . $a_class . ' href="' . $url_patch . '#block-budg-eu-projects-view-switcher-results"' . $data_nid . '>' . $links['map']['title'] . '</a>',
  );

  // The Switch buttons.
  $render['view_switcher']['#theme'] = 'item_list';
  $render['view_switcher']['#prefix'] = '<nav class="col-lg-10 view-switcher" id="view-switcher">';
  $render['view_switcher']['#suffix'] = '</nav>';
  foreach ($links as $variable => $options) {
    $path = $map_url;

    $class = $options['class'];
    $title = $options['title'];

    if ($variable != 'map') {
      $a_class = 'budg-ajax';
    }
    else {
      $a_class = 'budg-ajax';
      $path = $map_url;
    }

    $url = url($path, array(
      'query' => array(
        'view' => $variable,
      ),
    ));

    if ($view == $variable) {
      $class .= ' icon--yellowbg';
      $tag_begin = '';
      $tag_end = '';
    }
    else {
      $tag_begin = "<a class='$a_class' href='$url" . "#block-budg-eu-projects-view-switcher-results' $data_nid>";
      $tag_end = '</a>';
    }
    $render['view_switcher']['#items'][] = "$tag_begin<span class='$class'> </span> $title$tag_end";
  }

  return render($render);
}

/**
 * Generates the content of the block sort_switcher.
 *
 * @return string
 *     Content of the block.
 */
function _budg_eu_projects_sort_switcher_content() {
  include_once 'budg_eu_projects.functions.inc';
  $result_display = _budg_eu_projects_result_display('');
  $display_view = $result_display['view'];
  // The sort menu.
  if ($display_view != 'map') {
    $render['sort_menu'] = array(drupal_get_form('_budg_eu_projects_search_projects_sort'));
  }

  return render($render);
}

/**
 * Generates the content of the block view_switcher_results_count.
 *
 * @return string
 *    Content of the block.
 */
function _budg_eu_projects_view_switcher_results_count_content() {
  include_once 'budg_eu_projects.functions.inc';
  global $language;
  $params = drupal_get_query_parameters();
  $filters = _budg_eu_projects_default_search_values($params);
  $result_display = _budg_eu_projects_result_display($params);
  $display_view = $result_display['view'];
  $blocks = array(
    'grid' => array(
      'id' => 'search_projects',
      'display' => 'block_2',
    ),
    'map' => array(
      'id' => 'project_geojson',
      'display' => 'feed',
    ),
    'list' => array(
      'id' => 'search_projects',
      'display' => 'block_1',
    ),
  );

  if ($display_view && isset($blocks)) {
    if ($display_view != 'map') {
      $id = $blocks[$display_view]['id'];
      $view_display = $blocks[$display_view]['display'];
      $view = _budg_eu_projects_search_update_view($id, $view_display, $filters);
      $result = $view->total_rows;
      $text = t('!number projects found', array('!number' => $result));
    }
    else {
      // Call the geojson with the same parameters as the map javascript.
      $additional_filters = array(
        'ss_language' => $language->language,
        'view' => $display_view,
      );
      $exceptions = array('ss_language', 'view');
      $filters = _budg_eu_projects_solr_filter_params(array_merge($additional_filters, $filters), $exceptions);
      $filters['valid'] = date('Y') . '_' . date('n') . '_' . date('j');
      $url = url('solr/geojson', array('query' => $filters, 'absolute' => TRUE));
      $response = drupal_http_request($url);

      // Counts the results.
      $geo_array = isset($response->data) ? drupal_json_decode($response->data, TRUE) : array();
      $projects = isset($geo_array['features']) ? $geo_array['features'] : array();
      $result = count($projects);

      $text = t('!number locations found', array('!number' => $result));
    }

    $render['view_switcher_results'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => 'number-results',
        'id' => 'number-results',
        'data-results' => $result,
      ),
      array(
        '#markup' => $text,
      ),
    );
    return render($render);
  }
}

/**
 * Generates the content of the block view_switcher_results.
 *
 * @return string
 *    Content of the block.
 */
function _budg_eu_projects_view_switcher_results_content() {

  // Block displaying the the number of results.
  $block = block_load('budg_eu_projects', 'view_switcher_results_count');
  $block_content = _block_render_blocks(array(
    $block,
  ));
  $render['view_switcher_results_count'] = array(
    _block_get_renderable_array($block_content),
  );

  $render['search-actions'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => 'search-actions clearfix',
    ),
  );

  // Block displaying the view switcher.
  $block = block_load('budg_eu_projects', 'view_switcher');
  $block_content = _block_render_blocks(array(
    $block,
  ));
  $render['search-actions']['view_switcher'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => 'col-lg-8 col-md-8 col-sm-8',
    ),
    'content' => _block_get_renderable_array($block_content),
  );

  // Block displaying the sort by selector.
  $block = block_load('budg_eu_projects', 'sort_switcher');
  $block_content = _block_render_blocks(array(
    $block,
  ));
  $render['search-actions']['sort_switcher'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => 'col-lg-4 clearfix col-md-4 col-sm-4',
      'id' => 'sort-switcher',
    ),
    'content' => _block_get_renderable_array($block_content),
  );

  // Block displaying the results in its chosen view.
  $block = block_load('budg_eu_projects', 'view_switcher_view_display');
  $block_content = _block_render_blocks(array(
    $block,
  ));

  $render['view_switcher_view_display'] = array(
    "#type" => 'markup',
    '#prefix' => '<div id="search-results-display">',
    '#suffix' => '</div>',
    'content' => _block_get_renderable_array($block_content),
  );

  return render($render);
}

/**
 * Generates the content of the block view_switcher_view_display.
 *
 * @return string
 *    Content of the block.
 */
function _budg_eu_projects_view_switcher_view_display_content() {
  include_once 'budg_eu_projects.functions.inc';
  $params = drupal_get_query_parameters();
  $result_display = _budg_eu_projects_result_display($params);
  $display_view = $result_display['view'];
  $current_page = isset($result_display['page'][$display_view]) ? $result_display['page'][$display_view] : 0;
  $filters = _budg_eu_projects_default_search_values($params);

  $blocks = array(
    'grid' => array(
      'block' => 'block_2',
      'type' => 'view_block',
    ),
    'map' => array(
      'block' => 'map',
      'type' => 'block',
    ),
    'list' => array(
      'block' => 'block_1',
      'type' => 'view_block',
    ),
  );
  $block_type = isset($blocks[$display_view]['type']) ? $blocks[$display_view]['type'] : 'grid';
  switch ($block_type) {
    case 'view_block':
      $view = _budg_eu_projects_search_update_view('search_projects', $blocks[$display_view]['block'], $filters, $current_page);
      $output = $view->render();
      break;

    case 'block':
      $block = block_load('Bean', $blocks[$display_view]['block']);
      $block_content = _block_render_blocks(array(
        $block,
      ));
      $map = _block_get_renderable_array($block_content);
      $output = render($map);
      break;
  }
  return $output;
}

/**
 * Generates the content of the block search_projects.
 *
 * @return string
 *     Content of the block.
 */
function _budg_eu_project_project_search() {

  $render['search_projects'] = array(drupal_get_form('_budg_eu_projects_search_projects'));

  return render($render);
}
