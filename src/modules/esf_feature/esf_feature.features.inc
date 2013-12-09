<?php
/**
 * @file
 * esf_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function esf_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function esf_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function esf_feature_eck_bundle_info() {
  $items = array(
  'law_law' => array(
  'machine_name' => 'law_law',
  'entity_type' => 'law',
  'name' => 'law',
  'label' => 'Law',
),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function esf_feature_eck_entity_type_info() {
$items = array(
       'law' => array(
  'name' => 'law',
  'label' => 'Law',
  'properties' => array(
    'title' => array(
      'label' => 'Title',
      'type' => 'text',
      'behavior' => 'title',
    ),
    'changed' => array(
      'label' => 'Changed',
      'type' => 'integer',
      'behavior' => 'changed',
    ),
  ),
),
  );
  return $items;
}

/**
 * Implements hook_node_info().
 */
function esf_feature_node_info() {
  $items = array(
    'joke' => array(
      'name' => t('Joke'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Nadpis'),
      'help' => '',
    ),
    'legal_subject' => array(
      'name' => t('Legal Subject'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Nadpis'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('Novinka'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Nadpis'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Stránka'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Nadpis'),
      'help' => '',
    ),
    'school_subject' => array(
      'name' => t('School Subject'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Nadpis'),
      'help' => '',
    ),
    'story' => array(
      'name' => t('Příběh'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Nadpis'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function esf_feature_weight_features_default_settings() {
  $settings = array();

  $settings['legal_subject'] = array(
    'enabled' => 1,
    'range' => 50,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 1,
  );

  return $settings;
}
