<?php


/**
 * @file
 * Variable integration for MUNI Guacamole module.
 */

/**
 * Implements hook_variable_info().
 */
function muni_guacamole_variable_info($options) {

  $variables['muni_guacamole_server_url'] = array(
    'type' => 'string',
    'title' => t('Guacamole TomCat JAVA servlet URL', array(), $options),
    'description' => t('URL of the server running the remote desktop Guacamole software.'),
    'default' => 'FILL IN',
    'localize' => FALSE,
    'group' => 'muni_guacamole',
  );

  $variables['muni_guacamole_server_port'] = array(
    'type' => 'integer',
    'title' => t('Guacamole TomCat servlet port', array(), $options),
    'description' => t('Port of the server running the remote desktop Guacamole software.'),
    'default' => 100,
    'group' => 'muni_guacamole',
  );
  
  return $variables;
}

/**
 * Implements hook_variable_group_info().
 */
function muni_guacamole_variable_group_info() {

  $groups['muni_guacamole'] = array(
    'title' => t('MUNI guacamole'),
    'description' => t('Variables for MUNI Guacamole configuration.'),
    'access' => 'administer muni guacamole',
    'path' => array('admin/config/guacamole'),
  );

  return $groups;
}
