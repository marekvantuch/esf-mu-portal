<?php

/**
 * Implements hook_variable_info().
 */
function esf_module_variable_info($options) {

  $variables[ESF_MODULE_GUACAMOLE_ENABLED] = array(
    'type' => 'boolean',
    'title' => t('Enable Guacamole Remote Desktop'),
    'description' => t('If enabled, users are able to connect to remote desktop through their browsers.'),
    'default' => FALSE,
    'localize' => FALSE,
    'group' => 'esf');

  $variables[ESF_MODULE_GUACAMOLE_SERVER_DOMAIN] = array(
    'type' => 'string',
    'title' => t('Guacamole TomCat Servlet domain'),
    'description' => t('Domain URL of the server running the remote desktop Guacamole software. Must not contain trailing slash.'),
    'default' => 'localhost',
    'localize' => FALSE,
    'group' => 'esf',
  );

  $variables[ESF_MODULE_GUACAMOLE_SERVER_PORT] = array(
    'type' => 'number',
    'title' => t('Guacamole Servlet port'),
    'description' => t('Port of the server running the remote desktop Guacamole
      software.'),
    'default' => 0,
    'localize' => FALSE,
    'group' => 'esf',
  );

  $variables[ESF_MODULE_GUACAMOLE_SERVER_PATH] = array(
    'type' => 'string',
    'title' => t('Guacamole Servlet path'),
    'description' => t('Path on the server running the remote desktop Guacamole
      software. Must start and end with a slash (defaults to \'/guacamole/\').'),
    'default' => '/guacamole/',
    'localize' => FALSE,
    'group' => 'esf',
  );

  $variables[ESF_MODULE_GUACAMOLE_HOME] = array(
    'type' => 'string',
    'title' => t('Guacamole home'),
    'description' => t('Location of the guacamole settings file, typically
      stored in the GUACAMOLE_HOME system environment property. Trailing slash
      must be included (defaults to \'/srv/guacamole/\').'),
    'default' => '/srv/guacamole/',
    'localize' => FALSE,
    'group' => 'esf',
  );

  $variables[ESF_MODULE_GUACAMOLE_PROPERTIES_FILE] = array(
    'type' => 'string',
    'title' => t('Guacamole properties filename'),
    'description' => t('Name of the file which stores the properties of the
      guacamole program (typically guacamole.properties)'),
    'default' => 'guacamole.properties',
    'localize' => FALSE,
    'group' => 'esf',
  );

  $variables[ESF_MODULE_ASPI_PROTOCOL] = array(
    'type' => 'string',
    'title' => t('ASPI protocol'),
    'description' => t('The URL protocol prefix ([protocol]://) used in the links to ASPI'),
    'default' => 'aspi',
    'localize' => FALSE,
    'group' => 'esf',
  );

  return $variables;
}

/**
 * Implements hook_variable_group_info().
 */
function esf_module_variable_group_info() {

  $groups['esf_guacamole_server'] = array(
    'title' => t('Guacamole server'),
    'description' => t('Variables for configuration of connection to the Guacamole Server.'),
    'access' => 'administer esf',
    'path' => array('admin/config/esf/settings'),
  );

  $groups['esf_guacamole_properties'] = array(
    'title' => t('Guacamole properties'),
    'description' => t('Variables for the Guacamole properties file.'),
    'access' => 'administer esf',
    'path' => array('admin/config/esf/settings'),
  );

  return $groups;
}
