<?php
/**
 * @file
 * esf_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function esf_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'guacamole';
  $context->description = 'Change the page layout to Guacamole.';
  $context->tag = 'layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'aspi/remote' => 'aspi/remote',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(),
      'layout' => 'guacamole',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Change the page layout to Guacamole.');
  t('layout');
  $export['guacamole'] = $context;

  return $export;
}
