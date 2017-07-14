<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_js_alter().
 */
function europa_js_alter(&$js) {
  $base_theme_path = drupal_get_path('theme', 'bootstrap');
  $path_fancybox = libraries_get_path('fancybox');

  unset(
    $js[$base_theme_path . '/js/misc/ajax.js'],
    $js[$path_fancybox . '/jquery.fancybox.pack.js'],
    $js[$path_fancybox . '/helpers/jquery.fancybox-thumbs.js'],
    $js[$path_fancybox . '/helpers/jquery.fancybox-buttons.js'],
    $js[$path_fancybox . '/helpers/jquery.fancybox-media.js'],
    $js['profiles/multisite_drupal_standard/themes/bootstrap/js/bootstrap.js']
  );
}

/**
 * Implements hook_css_alter().
 */
function europa_css_alter(&$css) {
  $path_fancybox = libraries_get_path('fancybox');
  // Prevent our css from being aggregate (ie9 requirement).
  $path_base = drupal_get_path('theme', 'europa') . '/css/style-sass-base.css';
  $css[$path_base]['preprocess'] = FALSE;

  unset(
    $css[drupal_get_path('module', 'date') . '/date_api/date.css'],
    $css[$path_fancybox . '/helpers/jquery.fancybox-buttons.css'],
    $css[$path_fancybox . '/helpers/jquery.fancybox-thumbs.css'],
    $css[$path_fancybox . '/jquery.fancybox.css']
  );
}

/**
 * Implements hook_theme().
 */
function europa_theme($existing, $type, $theme, $path) {
  return [
    'europa_status_message' => [
      'template' => 'status_message',
      'path' => $path . '/templates',
      'variables' => [
        'message_title' => '',
        'message_body' => '',
        'message_type' => '',
        'message_classes' => '',
      ],
    ],
  ];
}

/**
 * Implements hook_preprocess_europa_status_message().
 */
function europa_preprocess_europa_status_message(&$variables) {
  if (isset($variables['message_classes']) && is_array($variables['message_classes'])) {
    $variables['message_classes'] = ' ' . implode(' ', $variables['message_classes']);
  }
}

/**
 * Overrides theme_form_required_marker().
 */
function europa_form_required_marker($variables) {
  // This is also used in the installer, pre-database setup.
  $t = get_t();
  $attributes = array(
    'class' => 'form-required text-danger',
    'title' => $t('This field is required.'),
  );
  return '<span' . drupal_attributes($attributes) . '>*</span>';
}

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function europa_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'views_exposed_form') {
    // Button value change on all the views exposed forms is due to a
    // design/ux requirement which uses the 'Refine results' label for all the
    // filter forms.
    $form['submit']['#value'] = t('Refine results');
    $form['submit']['#attributes']['class'][] = 'btn-primary';
    $form['submit']['#attributes']['class'][] = 'filters__btn-submit';
    $form['reset']['#attributes']['class'][] = 'filters__btn-reset';
    $form['date_before']['value']['#date_format'] = variable_get('date_format_ec_date_j_f_y', "j F Y");
    $form['date_after']['value']['#date_format'] = variable_get('date_format_ec_date_j_f_y', "j F Y");
  }
}

/**
 * Implements hook_date_popup_process_alter().
 */
function europa_date_popup_process_alter(&$element, &$form_state, $context) {
  // Removing the description from the datepicker.
  unset($element['date']['#description']);
  unset($element['time']['#description']);
}

/**
 * Bootstrap theme wrapper function for the primary menu links.
 */
function europa_menu_tree__secondary(&$variables) {
  return '<ul class="menu nav navbar-nav secondary">' . $variables['tree'] . '</ul>';
}

/**
 * Implements hook_bootstrap_colorize_text_alter().
 */
function europa_bootstrap_colorize_text_alter(&$texts) {
  $texts['contains'][t('Save')] = 'primary';
}

/**
 * Overrides theme_form_element().
 */
function europa_form_element(&$variables) {
  $element = &$variables['element'];
  $is_checkbox = FALSE;
  $is_radio = FALSE;
  $feedback_message = FALSE;

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Hide datepicker-popup label.
  $datepicker_popup_pattern = '/edit-.*-datepicker-popup-.*/i';
  if (!empty($element['#id']) && preg_match($datepicker_popup_pattern, $element['#id'])) {
    $element['#title_display'] = 'invisible';
  }

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }

  // Check for errors and set correct error class.
  if (isset($element['#parents']) && form_get_error($element)) {
    $attributes['class'][] = 'has-error';

    if (in_array($element['#type'], array('radio', 'checkbox'))) {
      if ($element['#required']) {
        $feedback_message = '<p class="feedback-message is-error">' . form_get_error($element) . '</p>';
      }
    }
    else {
      $feedback_message = '<p class="feedback-message is-error">' . form_get_error($element) . '</p>';
    }
  }

  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(
      ' ' => '-',
      '_' => '-',
      '[' => '-',
      ']' => '',
    ));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  if (!empty($element['#autocomplete_path']) && drupal_valid_path($element['#autocomplete_path'])) {
    $attributes['class'][] = 'form-autocomplete';
  }
  $attributes['class'][] = 'form-item';

  // See https://www.drupal.org/node/154137
  if (isset($element['#id']) && $element['#id'] == 'edit-querytext') {
    $element['#children'] = str_replace('type="text"', 'type="search"', $element['#children']);
  }

  // See http://getbootstrap.com/css/#forms-controls.
  if (isset($element['#type'])) {
    switch ($element['#type']) {
      case "radio":
        $attributes['class'][] = 'radio';
        $is_radio = TRUE;
        break;

      case "checkbox":
        $attributes['class'][] = 'checkbox';
        $is_checkbox = TRUE;
        break;

      default:
        // Check if it is not our search form. Because we don't want the default
        // bootstrap class here.
        if (!in_array('form-item-QueryText', $attributes['class'])) {
          $attributes['class'][] = 'form-group';
          // Apply an extra wrapper class to our select list.
          if ($element['#type'] == 'select') {
            $attributes['class'][] = 'form-select';
          }
        }
    }
  }

  // Putting description into variable since it is not going to change.
  // Here Bootstrap tooltips have been removed since in current implemenation we
  // will use descriptions that are displayed under <label> element.
  if (!empty($element['#description'])) {
    $description = '<p class="help-block">' . $element['#description'] . '</p>';
  }

  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }

  $prefix = '';
  $suffix = '';
  if (isset($element['#field_prefix']) || isset($element['#field_suffix'])) {
    // Determine if "#input_group" was specified.
    if (!empty($element['#input_group'])) {
      $prefix .= '<div class="input-group">';
      $prefix .= isset($element['#field_prefix']) ? '<span class="input-group-addon">' . $element['#field_prefix'] . '</span>' : '';
      $suffix .= isset($element['#field_suffix']) ? '<span class="input-group-addon">' . $element['#field_suffix'] . '</span>' : '';
      $suffix .= '</div>';
    }
    else {
      $prefix .= isset($element['#field_prefix']) ? $element['#field_prefix'] : '';
      $suffix .= isset($element['#field_suffix']) ? $element['#field_suffix'] : '';
    }
  }

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);

      if (!empty($description)) {
        $output .= $description;
      }

      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      $output .= $feedback_message;
      break;

    case 'after':
      if ($is_radio || $is_checkbox) {
        $output .= ' ' . $prefix . $element['#children'] . $suffix;
      }
      else {
        $variables['#children'] = ' ' . $prefix . $element['#children'] . $suffix;
      }

      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      $output .= $feedback_message;
      break;

    default:
      // Output no label and no required marker, only the children.
      if (!empty($description)) {
        $output .= $description;
      }

      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      $output .= $feedback_message;
  }

  // Adding the calendar icon on text fields with JS UI PopUp calendar.
  if ($variables['element']['#type'] == 'date_popup') {
    $prefix = '<div class="date-picker">';
    $suffix = '<span class="icon icon--calendar"></span>';
    $output = ' ' . $prefix . $element['#children'] . $suffix . "\n";
  }

  $output .= "</div>\n";

  return $output;
}

/**
 * Europa theme wrapper function for the service tools menu links.
 */
function europa_menu_tree__menu_dt_service_links(&$variables) {
  return '<ul class="footer__menu footer__menu--separator menu nav list-inline">' . $variables['tree'] . '</ul>';
}

/**
 * Europa theme wrapper function for the EC menu links.
 */
function europa_menu_tree__menu_dt_menu_social_media(&$variables) {
  return '<ul class="footer__menu menu nav list-inline">' . $variables['tree'] . '</ul>';
}

/**
 * Helper applying BEM to footer menu item links.
 *
 * @param array $variables
 *   Link render array.
 *
 * @return string
 *   HTML markup
 */
function _europa_menu_link__footer(array &$variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  $element['#attributes']['class'][] = 'footer__menu-item';

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Override theme_menu_link().
 */
function europa_menu_link__menu_dt_service_links(&$variables) {
  return _europa_menu_link__footer($variables);
}

/**
 * Override theme_menu_link().
 */
function europa_menu_link__menu_dt_menu_social_media(&$variables) {
  return _europa_menu_link__footer($variables);
}

/**
 * Override hook_html_head_alter().
 */
function europa_html_head_alter(&$head_elements) {
  // Creating favicons links and meta tags for the html header.
  $europa_theme_png_path = base_path() . drupal_get_path('theme', 'europa') . '/images/png/favicon/';
  $elements = array(
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '57x57',
        'href' => 'apple-touch-icon-57x57.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '60x60',
        'href' => 'apple-touch-icon-60x60.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '114x114',
        'href' => 'apple-touch-icon-114x114.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '120x120',
        'href' => 'apple-touch-icon-120x120.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '144x144',
        'href' => 'apple-touch-icon-144x144.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '152x152',
        'href' => 'apple-touch-icon-152x152.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'apple-touch-icon',
        'sizes' => '180x180',
        'href' => 'apple-touch-icon-180x180.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'icon',
        'type' => 'image/png',
        'sizes' => '32x32',
        'href' => 'favicon-32x32.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'icon',
        'type' => 'image/png',
        'sizes' => '192x192',
        'href' => 'android-chrome-192x192.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'icon',
        'type' => 'image/png',
        'sizes' => '96x96',
        'href' => 'favicon-96x96.png',
      ),
    ),
    array(
      '#tag' => 'link',
      '#attributes' => array(
        'rel' => 'icon',
        'type' => 'image/png',
        'sizes' => '16x16',
        'href' => 'favicon-16x16.png',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-TileColor',
        'content' => '#034ea1',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-TileImage',
        'content' => $europa_theme_png_path . 'mstile-144x144.png',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'theme-color',
        'content' => '#034ea1',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-square70x70logo',
        'content' => $europa_theme_png_path . 'mstile-70x70.png',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-square150x150logo',
        'content' => $europa_theme_png_path . 'mstile-150x150.png',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-wide310x150logo',
        'content' => $europa_theme_png_path . 'mstile-310x150.png',
      ),
    ),
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-square310x310logo',
        'content' => $europa_theme_png_path . 'mstile-310x310.png',
      ),
    ),

  );
  foreach ($elements as $element) {
    $element['#type'] = 'html_tag';
    if (isset($element['#attributes']['href'])) {
      $element['#attributes']['href'] = $europa_theme_png_path . $element['#attributes']['href'];
    }
    $head_elements[] = $element;
  }
}

/**
 * A search_form alteration.
 */
function europa_form_nexteuropa_europa_search_search_form_alter(&$form, &$form_state, $form_id) {
  $form['search_input_group']['europa_search_submit']['#prefix'] = '<span class="input-group-btn search-form__btn-wrapper">';
  $form['search_input_group']['europa_search_submit']['#suffix'] = '</span>';
  $form['search_input_group']['europa_search_submit']['#attributes']['class'][] = 'search-form__btn';
  $form['search_input_group']['QueryText']['#prefix'] = '<label class="search-form__textfield-wrapper"><span class="sr-only">' . t('Search this website') . '</span>';
  $form['search_input_group']['QueryText']['#suffix'] = '</label>';
  $form['search_input_group']['QueryText']['#attributes']['class'][] = 'search-form__textfield';
  $form['search_input_group']['QueryText']['#attributes']['title'] = t('Search');

  unset($form['search_input_group']['QueryText']['#attributes']['placeholder']);
  unset($form['search_input_group']['europa_search_submit']['#attributes']['tabindex']);
}

/**
 * Generate the first breadcrumb items basing on a custom menu.
 */
function _europa_breadcrumb_menu(&$variables) {
  $menu_links = menu_tree('menu-dt-breadcrumb-menu');
  $new_items = array();
  global $language;
  $front = drupal_is_front_page();

  if (!empty($menu_links)) {
    $i = 0;
    foreach ($menu_links as $key => $menu_item) {
      if (is_numeric($key)) {
        // We don't want to show the home link in the home page.
        if (!($front && $menu_item['#href'] == '<front>')) {
          $options = array('language' => $language);
          $title = token_replace($menu_item['#title'], $menu_item, $options);
          $new_items[] = _easy_breadcrumb_build_item($title, array(), $menu_item['#href']);
          $i++;
        }
      }
    }

    if (!empty($new_items)) {
      // The menu is used as the starting point of the breadcrumb.
      $variables['breadcrumb'] = array_merge($new_items, $variables['breadcrumb']);
      // Alter the number of segments in the breadcrumb.
      $variables['segments_quantity'] += $i;
    }
  }
}

/**
 * Override theme_easy_breadcrumb().
 */
function europa_easy_breadcrumb(&$variables) {
  _europa_breadcrumb_menu($variables);
  $breadcrumb = $variables['breadcrumb'];
  $segments_quantity = $variables['segments_quantity'];
  $html = '';

  if ($segments_quantity > 0) {
    $html .= '<nav id="breadcrumb" class="breadcrumb" role="navigation" aria-label="breadcrumbs">';
    $html .= '<span class="element-invisible">' . t('You are here') . ':</span>';
    $html .= '<ol class="breadcrumb__segments-wrapper">';

    for ($i = 0, $s = $segments_quantity; $i < $segments_quantity; ++$i) {
      $item = $breadcrumb[$i];

      // Removing classes from $item['class'] array and adding BEM classes.
      $classes = $item['class'];
      $classes[] = 'breadcrumb__segment';

      $attributes = array(
        'class' => array('breadcrumb__link'),
      );

      if ($i == 0) {
        $classes[] = 'breadcrumb__segment--first';
        $attributes['class'][] = 'is-internal';
        $attributes += array('rel' => 'home');
      }
      elseif ($i == ($s - 1)) {
        $classes[] = 'breadcrumb__segment--last';
      }

      $content = '<span class="breadcrumb__text">' . check_plain(decode_entities($item['content'])) . '</span>';
      $class = implode(' ', $classes);
      if (isset($item['url'])) {
        $full_item = l($content, $item['url'], array(
          'attributes' => $attributes,
          'html' => TRUE,
        ));
      }
      else {
        $full_item = '<span class="' . $class . '">' . $content . '</span>';
      }

      // TODO: Check if the active class actually appears.
      $element_visibility = in_array('active', $classes) ? ' element-invisible' : '';
      $html .= '<li class="' . $class . $element_visibility . '">' . $full_item . '</li>';
    }

    $html .= '</ol></nav>';

    drupal_add_js(drupal_get_path('theme', 'europa') . '/js/components/breadcrumb.js');
  }
  return $html;
}

/**
 * Helper for providing markup to file component.
 *
 * @param object $file
 *   File object.
 * @param array $url
 *   Url depending on field type.
 * @param string $modifier
 *   Class modefier for the file block element.
 * @param bool $subfile
 *   True/False parameter to set if it is a subfile.
 *
 * @return string
 *   HTML markup.
 */
function _europa_file_markup($file, array $url, $modifier = NULL, $subfile = FALSE) {
  switch ($file->type) {
    case 'image':
      $file_icon_class = 'icon--image';
      break;

    case 'audio':
      $file_icon_class = 'icon--audio';
      break;

    case 'video':
      $file_icon_class = 'icon--video';
      break;

    default:
      $file_icon_class = 'icon--file';
      break;
  }

  // If we have a modifier, just append it to the class.
  $file_class = (!empty($modifier) ? ' ' . $modifier : '');

  $file_icon = '<span class="file__icon icon ' . $file_icon_class . '"></span>';
  $file_size = format_size($file->filesize);
  $file_name = $file->uri;
  $file_extension = drupal_strtoupper(pathinfo($file_name, PATHINFO_EXTENSION));

  // Get our full language string.
  if (isset($file->entity->language) || isset($file->language)) {
    include_once drupal_get_path('module', 'budg_eu_projects') . '/inc/budg_eu_projects.functions.inc';
    $language_to_use = isset($file->entity->language) ? entity_translation_get_existing_language('node', $file->entity) : $file->language;
    $file_language_string = _budg_eu_projects_shared_functions_get_language_obj($language_to_use, 'native');
    if (!$subfile && module_exists('locale') && isset($GLOBALS['language_content']->language)) {
      $file_language_string = locale($file_language_string, NULL, $GLOBALS['language_content']->language);
    }
  }

  // If we have a full language string and it's not a subfile, we add it to the
  // file information.
  $file_language = '';
  if (isset($file_language_string) && !$subfile) {
    $file_language = '<span class="file__contentlanguage">' . $file_language_string . ' </span>';
  }

  // File information and title setter.
  if ($subfile && isset($file_language_string)) {
    $file_info_string = $file_size . ' - ' . $file_extension;
    $title_string = $file_language_string . ' ' . t('version');
  }
  else {
    $file_info_string = $file_language . '(' . $file_size . ' - ' . $file_extension . ')';

    // Use the description as the link text if available.
    if (isset($file->entity)) {
      // We have access to the entity, so we can use that title.
      // If the file entity is different form the current node we use that
      // title.
      $file_wrapper = entity_metadata_wrapper('node', $file->entity);
      $title_string = $file_wrapper->title->value();
    }
    else {
      if (!empty($file->description)) {
        $title_string = $file->description;
        $options['attributes']['title'] = check_plain($file->filename);
      }
      else {
        $title_string = $file->filename;
      }
    }
  }

  // File markup parts.
  $file_info = '<div class="file__info">' . $file_info_string . '</div>';

  $file_title = '<span class="file__title">' . $title_string . '</span>';

  $file_metadata = '<div class="file__metadata">' . $file_title . $file_info . '</div>';

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
      'class' => array('file__btn', 'btn', 'btn-default'),
      'title' => check_plain($file->filename),
    ),
    'html' => TRUE,
  );

  $file_text = t('Download') . '<span class="sr-only">' . $file_extension . ' - ' . format_size($file->filesize) . '</span>';

  $file_btn = l($file_text, $url['path'], array_merge($options, $url['options']));

  return '<div class="file file--widebar' . $file_class . '">' . $file_icon . $file_metadata . $file_btn . '</div>';
}

/**
 * Override theme_file_link().
 */
function europa_file_link($variables) {
  $file = $variables['file'];

  // Submit the language along witht the file.
  $langcode = $GLOBALS['language_content']->language;
  if (!empty($langcode)) {
    $file->language = $langcode;
  }

  $url['path'] = file_create_url($file->uri);
  $url['options'] = array();

  return _europa_file_markup($file, $url);
}

/**
 * Override theme_file_entity_download_link().
 */
function europa_file_entity_download_link($variables) {
  $file = $variables['file'];

  // Submit the language along witht the file.
  $langcode = $GLOBALS['language_content']->language;
  if (!empty($langcode)) {
    $file->language = $langcode;
  }

  $uri = file_entity_download_uri($file);

  return _europa_file_markup($file, $uri);
}

/**
 * Overrides theme_link().
 */
function europa_link($variables) {
  // Link module creates absolute URLs for internal links as well, resulting
  // in having the external link icon on these internal links. We attempt to
  // re-convert these to relative.
  global $base_url;
  $internal_url = explode($base_url, $variables['path']);
  if (count($internal_url) > 1) {
    $variables['options']['attributes']['class'][] = 'is-internal';
  }

  // @codingStandardsIgnoreLine : MULTISITE-16656
  return theme_link($variables);
}

/**
 * Implements hook_preprocess_block().
 */
function europa_preprocess_block(&$variables) {
  $block = $variables['block'];

  switch ($block->delta) {
    case 'nexteuropa_feedback':
      $variables['classes_array'][] = 'block--full-width';
      break;

    case 'menu-dt-menu-social-media':
      $block->subject = t('The European Commission on:');
      break;

    case 'menu-dt-service-links':
      $block->subject = '';
      break;
  }

  // Page-level language switcher.
  if (isset($block->bid) && $block->bid === 'language_selector_page-language_selector_page') {
    global $language;

    // selectify.js is the library to convert between ul and select.
    drupal_add_js(drupal_get_path('theme', 'europa') . '/js/selectify.js');
    drupal_add_js(drupal_get_path('theme', 'europa') . '/js/components/lang-switcher.js');

    // Initialize variables.
    $not_available = '';
    $served = '';
    $other = '';

    if (!empty($variables['elements']['not_available']['#markup'])) {
      $not_available = '<li class="lang-select-page__option lang-select-page__unavailable">' . $variables['elements']['not_available']['#markup']->native . '</li>';
    }

    if (!empty($variables['elements']['served']['#markup'])) {
      $served = '<li class="lang-select-page__option is-selected">' . $variables['elements']['served']['#markup']->native . '</li>';
    }

    if (!empty($variables['elements']['other']['#markup'])) {
      foreach ($variables['elements']['other']['#markup'] as $code => $lang) {
        $options = array();
        $options['query'] = drupal_get_query_parameters();
        $options['query']['2nd-language'] = $code;
        $options['attributes']['lang'] = $code;
        $options['attributes']['hreflang'] = $code;
        $options['attributes']['rel'] = 'alternate';
        $options['language'] = $language;

        $other .= '<li class="lang-select-page__option lang-select-page__other">' . l($lang->native, current_path(), $options) . '</li>';
      }
    }

    // Add class to block.
    $variables['classes_array'][] = 'lang-select-page lang-select-page--transparent';

    // Add content to block.
    $content = "<span class='lang-select-page__icon icon icon--generic-lang'></span>";
    $content .= "<ul class='lang-select-page__list'>" . $not_available . $served . $other . '</ul>';

    $variables['content'] = $content;
  }

  // Site-level language switcher.
  if (isset($block->bid) && $block->bid === 'language_selector_site-language_selector_site') {
    // Add the js to make it function.
    drupal_add_js(drupal_get_path('theme', 'europa') . '/js/components/lang-select-site.js');
  }

  // Replace block-title class with block__title in order to keep BEM structure
  // of classes.
  $block_title_class = array_search('block-title', $variables['title_attributes_array']['class']);
  if ($block_title_class !== FALSE) {
    unset($variables['title_attributes_array']['class'][$block_title_class]);
  }
  $variables['title_attributes_array']['class'][] = 'block__title';

  if (isset($block->bid)) {
    // Check if the block is a exposed form.
    // This is checked by looking at the $block->bid which in case
    // of views exposed filters, always contains 'views--exp-' string.
    if (strpos($block->bid, 'views--exp-') !== FALSE) {
      if (isset($block->context) && $context = context_load($block->context)) {
        // If our block is the first, we set the subject. This way, if we expose
        // a second block for the same view, we will not duplicate the title.
        if (array_search($block->bid, array_keys($context->reactions['block']['blocks'])) === 0) {
          $variables['classes_array'][] = 'filters';
          $variables['title_attributes_array']['class'][] = 'filters__title';
          $block->subject = t('Refine results');

          // Passing block id to Drupal.settings in order to pass it through
          // data attribute in the collapsible panel.
          drupal_add_js(array('europa' => array('exposedBlockId' => $variables['block_html_id'])), 'setting');

          // Adding filters.js file.
          drupal_add_js(drupal_get_path('theme', 'europa') . '/js/components/filters.js');
        }
      }
    }
  }

  if ($block->delta == 'inline_navigation') {
    $variables['classes_array'][] = 'inpage-nav__wrapper';
    $variables['title_attributes_array']['class'][] = 'inpage-nav__block-title';
  }
}

/**
 * Implements hook_preprocess_bootstrap_tabs().
 */
function europa_preprocess_bootstrap_fieldgroup_nav(&$variables) {
  drupal_add_js(drupal_get_path('theme', 'europa') . '/js/libraries/jquery-accessible-tabs.js');
  $group = &$variables['group'];

  $variables['nav_classes'] = '';

  switch ($group->format_settings['instance_settings']['bootstrap_nav_type']) {
    case 'tabs':
      $variables['nav_classes'] .= ' nav-tabs nav-tabs--with-content';
      break;

    case 'pills':
      $variables['nav_classes'] .= ' nav-pills';
      break;

    default:
  }

  if ($group->format_settings['instance_settings']['bootstrap_stacked']) {
    $variables['nav_classes'] .= ' nav-stacked';
  }

  $i = 0;
  foreach ($variables['items'] as $item) {
    // Check if item is not empty and we have access to it.
    if ($item && (!isset($item['#access']) || $item['#access'])) {

      $id = 'bootstrap-fieldgroup-nav-item--' . drupal_html_id($item['#title']);

      // Is an explicit nav item?
      if (!empty($item['#type']) && 'bootstrap_fieldgroup_nav_item' == $item['#type']) {
        $classes = $item['#group']->classes;
      }
      // Otherwise, just a regular field under the nav.
      else {
        $classes = '';
      }

      $variables['navs'][$i] = array(
        'content' => l(
          $item['#title'],
          NULL,
          array(
            'attributes' => array(
              'data-toggle' => 'tab',
              'class' => ['js-tablist__link'],
            ),
            'fragment' => $id,
            'external' => TRUE,
            'html' => TRUE,
          )
        ),
        'classes' => $classes,
      );

      $variables['panes'][$i]['id'] = $id;
      $variables['panes'][$i]['title'] = check_plain($item['#title']);
      $i++;
    }
  }
}

/**
 * Implements hook_preprocess_field().
 */
function europa_preprocess_field(&$variables) {
  // Changing label for the field to display stripped out values.
  switch ($variables['element']['#field_name']) {
    case 'field_core_social_network_links':
      $variables['element']['before'] = t('Follow the latest progress and get involved.');
      $variables['element']['after'] = l(t('Other social networks'), variable_get('dt_core_other_social_networks_link', 'http://europa.eu/contact/social-networks/index_en.htm'));
      break;
  }

  if ($variables['element']['#field_type'] <> 'ds') {
    // Get more field information.
    $field = field_info_field($variables['element']['#field_name']);
    // Inintialize parameter.
    $allow_attribute = TRUE;
    // If it is not a tranlateable entityreference field we should continue.
    if ($field['type'] == "entityreference" && $field['translatable'] == 0) {
      $allow_attribute = FALSE;
    }

    if ($allow_attribute) {
      // The default language code.
      $content_langcode = $GLOBALS['language_content']->language;
      // When the language is different from content.
      if (isset($variables['element']['#language']) && $variables['element']['#language'] <> LANGUAGE_NONE && $variables['element']['#language'] <> $content_langcode) {
        $variables['attributes_array']['lang'] = $variables['element']['#language'];
      }
    }
  }
  // Set the attributes to the element.
  $variables['attributes'] = empty($variables['attributes_array']) ? '' : drupal_attributes($variables['attributes_array']);
}

/**
 * Implements hook_preprocess_image().
 */
function europa_preprocess_image(&$variables) {
  // Fix issue between print module and bootstrap theme, print module put a
  // string instead of an array in $variables['attributes']['class'].
  if (theme_get_setting('bootstrap_image_responsive')) {
    if (isset($variables['attributes']['class'])) {
      if (is_array($variables['attributes']['class'])) {
        $variables['attributes']['class'][] = 'img-responsive';
      }
      else {
        $variables['attributes']['class'] = array(
          $variables['attributes']['class'],
          'img-responsive',
        );
      }
    }
  }
}

/**
 * Implements hook_preprocess_html().
 */
function europa_preprocess_html(&$variables) {
  $this_theme_path = drupal_get_path('theme', 'europa');
  $variables['theme_path'] = base_path() . $this_theme_path;
  $language = $variables['language'];
  if (isset($language->prefix)) {
    $variables['classes_array'][] = 'language-' . $language->prefix;
  }

  // Add site information. This is just a temporary solution.
  if (module_exists('dt_core_pol')) {
    $variables['classes_array'][] = 'site-political';
  }
  elseif (module_exists('dt_core_info')) {
    $variables['classes_array'][] = 'site-information';
  }

  // Add the ie9 only css.
  drupal_add_css(
    $this_theme_path . '/css/ie9.css',
    array(
      'browsers' => array(
        'IE' => 'IE 9',
        '!IE' => FALSE,
      ),
    )
  );
  // Add conditional js.
  $ie9_js = array(
    '#tag' => 'script',
    '#attributes' => array(
      'src' => $this_theme_path . '/js/ie9.js',
    ),
    '#prefix' => '<!--[if IE 9]>',
    '#suffix' => '</script><![endif]-->',
  );
  drupal_add_html_head($ie9_js, 'ie9_js');

  // For some reason, the front page handles tokens different.
  if (drupal_is_front_page()) {
    $data = ['node' => menu_get_object('node')];
    $last_modified = [
      '#tag' => 'meta',
      '#attributes' => [
        'name' => 'last-modified',
        'content' => token_replace('[dt_tokens:dt_update_date]', $data),
      ],
    ];
    drupal_add_html_head($last_modified, 'last_modified');
  }

  // Override splash screen title.
  $menu_item = menu_get_item();
  if (isset($menu_item['path']) && $menu_item['path'] == 'splash' && !variable_get('splash_screen_title_value', FALSE)) {
    $site_name = variable_get('site_name');
    $variables['head_title'] = $site_name;
    drupal_set_title($site_name);
  }

}

/**
 * Implements hook_preprocess_node().
 */
function europa_preprocess_node(&$variables) {
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['view_mode'];
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'];
  $variables['submitted'] = '';
  if (theme_get_setting('display_submitted')) {
    $variables['submitted'] = t('Submitted by !username on !datetime', array(
      '!username' => $variables['name'],
      '!datetime' => $variables['date'],
    ));
  }
  $variables['messages'] = theme('status_messages');

  // Override node_url if Legacy Link is set.
  if (isset($variables['legacy'])) {
    $variables['node_url'] = $variables['legacy'];
  }

  // Add the language attribute.
  $variables['attributes_array']['lang'] = entity_translation_get_existing_language('node', $variables['node']);
}

/**
 * Implements hook_preprocess_page().
 */
function europa_preprocess_page(&$variables) {
  // Small fix to maxe the link to the start page use the alias with language.
  $variables['front_page'] = url('<front>');
  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = 'col-md-6';
  }
  elseif (!empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = 'col-md-9';
  }
  else {
    $variables['content_column_class'] = 'col-md-12';
  }

  // Set footer region column classes.
  if (!empty($variables['page']['footer_right'])) {
    $variables['footer_column_class'] = 'col-sm-8';
  }
  else {
    $variables['footer_column_class'] = 'col-sm-12';
  }

  $variables['page_logo_title'] = t('Home - @sitename', array('@sitename' => variable_get('site_name', 'European Commission')));

  $node = &$variables['node'];

  if (isset($node)) {
    // Adding generic introduction field to be later rendered in page template.
    $variables['field_core_introduction'] = isset($node->field_core_introduction) ?
      field_view_field('node', $node, 'field_core_introduction', array('label' => 'hidden')) :
      NULL;

    // Check if Display Suite is handling node.
    if (module_exists('ds')) {
      $layout = ds_get_layout('node', $node->type, 'full');
      if ($layout && isset($layout['is_nexteuropa']) && $layout['is_nexteuropa'] == TRUE) {
        // If our display suite layout has a header region.
        if (isset($layout['regions']['left_header'])) {
          // Move the header_bottom to the node.
          $variables['node']->header_bottom = $variables['page']['header_bottom'];
          unset($variables['page']['header_bottom']);
        }
        ctools_class_add($layout['layout']);

        if (isset($node->ds_switch) && $node->ds_switch != 'college') {
          $variables['node']->header_bottom_modifier = 'page-bottom-header--full-grey';
        }

        // This disables message-printing on ALL page displays.
        $variables['show_messages'] = FALSE;

        // Add tabs to node object so we can put it in the DS template instead.
        if (isset($variables['tabs'])) {
          $node->local_tabs = drupal_render($variables['tabs']);
        }

        $variables['theme_hook_suggestions'][] = 'page__ds_node';
      }
    }
  }
  $variables['logo_classes'] = 'logo site-header__logo';
}

/**
 * Implements hook_preprocess_views_view().
 */
function europa_preprocess_views_view(&$variables) {
  // Checking if exposed filters are set and add variable that stores active
  // filters.
  if (module_exists('dt_exposed_filter_data')) {
    $variables['active_filters'] = _dt_exposed_filter_data_get_exposed_filter_output();
  }
}

/**
 * Implements theme_pager().
 */
function europa_pager($variables) {
  drupal_add_js(drupal_get_path('theme', 'europa') . '/js/components/pager.js');

  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // $pager_middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // $pager_current is the page we are currently paged to.
  $pager_current = $pager_page_array[$element] + 1;
  // $pager_first is the first page listed by this pager piece (re quantity).
  $pager_first = $pager_current - $pager_middle + 1;
  // $pager_last is the last page listed by this pager piece (re quantity).
  $pager_last = $pager_current + $quantity - $pager_middle;
  // $pager_max is the maximum page number.
  $pager_max = $pager_total[$element];

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }

  $li_first = theme('pager_first', array(
    'text' => t('first'),
    'element' => $element,
    'parameters' => $parameters,
  ));
  $li_previous = theme('pager_previous', array(
    'text' => '<span class="pager__back-arrow icon icon--left"></span><span class="pager__back-text">' . t('Previous') . '</span>',
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
    'attributes' => array('class' => 'pager__btn'),
  ));
  $li_next = theme('pager_next', array(
    'text' => '<span class="pager__forward-text">' . t('Next') . "</span><span class='pager__forward-arrow icon icon--right'></span>",
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
    'attributes' => array('class' => 'pager__btn'),
  ));
  $li_last = theme('pager_last', array(
    'text' => t('last'),
    'element' => $element,
    'parameters' => $parameters,
    'attributes' => array('class' => 'pager__btn'),
  ));

  if ($pager_total[$element] > 1) {
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager__item pager__back'),
        'data' => $li_previous,
      );
    }

    $items[] = array(
      'class' => array('pager__item pager__middle'),
      'data' => "<span class='pager__combo-container'><span class='pager__combo-current'>" . t('Page !page', array('!page' => $pager_current)) . '&nbsp;</span>' .
      '<span class="pager__combo-total">' . t('of !total', array('!total' => $pager_max)) . '</span>' .
      '</span>',
    );
    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($li_first && $i > 1) {
        $items[] = array(
          'class' => array('pager__item select'),
          'data' => $li_first,
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager__item select'),
            'data' => theme('pager_previous', array(
              'text' => $i,
              'element' => $element,
              'interval' => ($pager_current - $i),
              'parameters' => $parameters,
            )),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager__item is-current select'),
            'data' => $i,
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager__item select'),
            'data' => theme('pager_next', array(
              'text' => $i,
              'element' => $element,
              'interval' => ($i - $pager_current),
              'parameters' => $parameters,
            )),
          );
        }
      }
    }
    if ($li_last && $i < $pager_max) {
      $items[] = array(
        'class' => array('pager__item select'),
        'data' => $li_last,
      );
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager__item pager__forward'),
        'data' => $li_next,
      );
    }

    $pager_markup = '<h2 class="sr-only">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager')),
    ));

    return '<div class="pager__wrapper">' . $pager_markup . '</div>';
  }
}

/**
 * Implements theme_pager_link().
 */
function europa_pager_link($variables) {
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];
  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title.
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  // @todo l() cannot be used here, since it adds an 'active' class based on the
  //   path only (which is always the current path for pager links). Apparently,
  //   none of the pager links is active at any time - but it should still be
  //   possible to use l() here.
  // @see http://drupal.org/node/1410574
  $attributes['href'] = url($_GET['q'], array('query' => $query));
  return '<a' . drupal_attributes($attributes) . '>' . $text . '</a>';
}

/**
 * Implements theme_pager_first().
 */
function europa_pager_first($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = isset($variables['attributes']) ? $variables['attributes'] : array();
  global $pager_page_array;
  $output = '';

  // If we are anywhere but the first page.
  if ($pager_page_array[$element] > 0) {
    $output = theme('pager_link', array(
      'text' => $text,
      'page_new' => pager_load_array(0, $element, $pager_page_array),
      'element' => $element,
      'parameters' => $parameters,
      'attributes' => $attributes,
    ));
  }

  return $output;
}

/**
 * Implements theme_pager_previous().
 */
function europa_pager_previous($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $interval = $variables['interval'];
  $parameters = $variables['parameters'];
  $attributes = isset($variables['attributes']) ? $variables['attributes'] : array();
  global $pager_page_array;
  $output = '';

  // If we are anywhere but the first page.
  if ($pager_page_array[$element] > 0) {
    $page_new = pager_load_array($pager_page_array[$element] - $interval, $element, $pager_page_array);

    // If the previous page is the first page, mark the link as such.
    if ($page_new[$element] == 0) {
      $output = theme('pager_first', array(
        'text' => $text,
        'element' => $element,
        'parameters' => $parameters,
        'attributes' => $attributes,
      ));
    }
    // The previous page is not the first page.
    else {
      $output = theme('pager_link', array(
        'text' => $text,
        'page_new' => $page_new,
        'element' => $element,
        'parameters' => $parameters,
        'attributes' => $attributes,
      ));
    }
  }

  return $output;
}

/**
 * Implements theme_pager_next().
 */
function europa_pager_next($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $interval = $variables['interval'];
  $parameters = $variables['parameters'];
  $attributes = isset($variables['attributes']) ? $variables['attributes'] : array();
  global $pager_page_array, $pager_total;
  $output = '';

  // If we are anywhere but the last page.
  if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
    $page_new = pager_load_array($pager_page_array[$element] + $interval, $element, $pager_page_array);
    // If the next page is the last page, mark the link as such.
    if ($page_new[$element] == ($pager_total[$element] - 1)) {
      $output = theme('pager_last', array(
        'text' => $text,
        'element' => $element,
        'parameters' => $parameters,
        'attributes' => $attributes,
      ));
    }
    // The next page is not the last page.
    else {
      $output = theme('pager_link', array(
        'text' => $text,
        'page_new' => $page_new,
        'element' => $element,
        'parameters' => $parameters,
        'attributes' => $attributes,
      ));
    }
  }

  return $output;
}

/**
 * Implements theme_pager_last().
 */
function europa_pager_last($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = isset($variables['attributes']) ? $variables['attributes'] : array();
  global $pager_page_array, $pager_total;
  $output = '';

  // If we are anywhere but the last page.
  if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
    $output = theme('pager_link', array(
      'text' => $text,
      'page_new' => pager_load_array($pager_total[$element] - 1, $element, $pager_page_array),
      'element' => $element,
      'parameters' => $parameters,
      'attributes' => $attributes,
    ));
  }

  return $output;
}

/**
 * Implements form_alter().
 */
function europa_form_alter(&$form, &$form_state, $form_id) {
  if (isset($form['views_bulk_operations'])) {
    $children = element_children($form['views_bulk_operations']);
    foreach ($children as $child) {
      if ($form['views_bulk_operations'][$child]['#type'] == 'checkbox') {
        $form['views_bulk_operations'][$child]['#title'] = ' ';
      }
    }
  }
}

/**
 * Implements hook_status_messages().
 */
function europa_status_messages($variables) {
  $display = $variables['display'];
  $output = [];

  foreach (drupal_get_messages($display) as $type => $messages) {
    $body = '';
    foreach ($messages as $message) {
      $body .= '  <p>' . $message . "</p>\n";
    }

    $output[] = [
      '#theme' => 'europa_status_message',
      '#message_classes' => [
        'alert',
        'alert-block',
        $type,
        count($messages) > 1 ?: 'messages--icon-center',
      ],
      '#message_type' => $type . ' message',
      '#message_body' => $body,
    ];
  }

  return drupal_render($output);
}
