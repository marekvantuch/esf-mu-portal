<?php
/**
 * @file
 * esf_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function esf_feature_taxonomy_default_vocabularies() {
  return array(
    'legal_subject' => array(
      'name' => 'Legal Subject',
      'machine_name' => 'legal_subject',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'school_subject' => array(
      'name' => 'School Subject',
      'machine_name' => 'school_subject',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
