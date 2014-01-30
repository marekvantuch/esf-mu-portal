<?php

/**
 * Page callback for the /aspi page.
 *
 * No page is actually build in here, because no content should be displayed.
 * As instead, all the html is stored in the theme and loaded from the layout.
 *
 * @see omega_esf/layouts/guacamole/guacamole.layout.tpl.php
 *
 * @return array
 *   empty array
 */
function esf_module_page_aspi() {
  $module_path = drupal_get_path('module', 'esf_module');

  // Removes any css added so far.
  drupal_static_reset('drupal_add_css');

  drupal_add_js($module_path . '/js/lib/blob/blob.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/lib/filesaver/filesaver.js', array('group' => JS_LIBRARY));

  drupal_add_js($module_path . '/js/esf-common.js', array('group' => JS_LIBRARY));

  drupal_add_js($module_path . '/js/lib/guacamole.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/lib/keyboard.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/lib/mouse.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/lib/layer.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/lib/tunnel.js', array('group' => JS_LIBRARY));

  drupal_add_js($module_path . '/js/session.js', array('weight' => 0, 'scope' => 'footer'));
  drupal_add_js($module_path . '/js/guac-ui.js', array('weight' => 1, 'scope' => 'footer'));
  drupal_add_js($module_path . '/js/client-ui.js', array('weight' => 2, 'scope' => 'footer'));

  drupal_add_js($module_path . '/js/aspi.js', array('weight' => 3, 'scope' => 'footer'));

  drupal_add_css($module_path . '/css/aspi_remote.css');

  return array();
}

function esf_module_page_home() {
  $module_path = drupal_get_path('module', 'esf_module');

  drupal_add_css($module_path . '/css/home.css');
  drupal_add_js($module_path . '/js/home.js', array('scope' => 'footer'));

  $variables = array(
    'path' => $module_path . '/images/system_prava.png',
    'title' => t('Law system')
  );
  $output = theme('image', $variables);

  $items = array();

  $items[] = array(
    ''
  );

  $variables = array(
    'name' => 'law_system',
    'items' => $items,
  );

  $output .= 'ahoj;';
  $output .= theme('map_area', $variables);

  return $output;
}