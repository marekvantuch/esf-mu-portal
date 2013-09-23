<?php
/**
 * @file
 * esf_feature.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function esf_feature_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'navigation';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Navigation Tabs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'school_subjects',
      'display' => 'default',
      'args' => '',
      'title' => 'Předměty',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'legal_subjects',
      'display' => 'default',
      'args' => '',
      'title' => 'Obory práva',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Navigation Tabs');
  t('Obory práva');
  t('Předměty');

  $export['navigation'] = $quicktabs;

  return $export;
}
