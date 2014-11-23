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
  drupal_add_js($module_path . '/js/lib/jquery.maphilight.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/home.js', array('scope' => 'footer'));

  $variables = array(
    'path' => $module_path . '/images/system_prava_752.png',
    'width' => 752,
    'height' => 601,
    'title' => t('Law system'),
    'attributes' => array(
      'class' => 'map',
      'usemap' => '#law_system',
    ),
  );
  $output = theme('image', $variables);

  $items = array(
    'obchodni-pravo' => array(
      'shape' => 'circle',
      'coords' => '106,164,102',
      'fillcolor' => 'aee733',
      'fillopacity' => '0.7',
      'title' => 'Obchodní právo'
    ),
    'financni-pravo' => array(
      'shape' => 'circle',
      'coords' => '567,354,101',
      'fillcolor' => 'aee733',
      'fillopacity' => '0.7',
      'title' => 'Finanční právo'
    ),
    'mezinarodni-pravo' => array(
      'shape' => 'circle',
      'coords' => '199,400,50',
      'fillcolor' => 'f028a7',
      'fillopacity' => '0.7',
      'title' => 'Mezinárodní právo soukromé'
    ),
//    'mezinarodni-pravo' => array(
//      'shape' => 'circle',
//      'coords' => '654,92,49',
//      'fillcolor' => 'f028a7',
//      'fillopacity' => '0.7',
//      'title' => 'Mezinárodní právo veřejné'
//    ),
    'obcanske-pravo' => array(
      'shape' => 'circle',
      'coords' => '232,248,136',
      'fillcolor' => '2298fc',
      'fillopacity' => '0.7',
      'title' => 'Občanské právo hmotné'
    ),
    'pracovni-pravo' => array(
      'shape' => 'circle',
      'coords' => '75,349,74',
      'fillcolor' => 'f0ac29',
      'fillopacity' => '0.7',
      'title' => 'Pracovní právo'
    ),
    'pravo-dusevniho-vlastnictvi' => array(
      'shape' => 'circle',
      'coords' => '217,107,54',
      'fillcolor' => '28f0d2',
      'fillopacity' => '0.7',
      'title' => 'Pracovní právo'
    ),
    'trestni-pravo' => array(
      'shape' => 'circle',
      'coords' => '680,214,71',
      'fillcolor' => '28f0d2',
      'fillopacity' => '0.7',
      'title' => 'Pracovní právo'
    ),
    'spravni-pravo' => array(
      'shape' => 'circle',
      'coords' => '482,217,101',
      'fillcolor' => '2298fc',
      'fillopacity' => '0.7',
      'title' => 'Pracovní právo'
    ),
    'ustavni-pravo' => array(
      'shape' => 'circle',
      'coords' => '544,24,74',
      'fillcolor' => 'f0ac29',
      'fillopacity' => '0.7',
      'title' => 'Pracovní právo'
    ),

  );

  $variables = array(
    'name' => 'law_system',
    'items' => $items,
  );

  $output .= theme('map_area', $variables);

  return $output;
}

function esf_module_get_related_subjects($subject) {

}