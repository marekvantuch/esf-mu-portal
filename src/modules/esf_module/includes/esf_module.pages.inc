<?php

module_load_include('inc', 'esf_module', 'includes/esf_module.servlets');
module_load_include('inc', 'esf_module', 'lib/cookie_parser');

function esf_module_page_aspi() {

  try {
    if(!connect()) {
      login();
      if (!connect()) {
        return 'FAILURE: Connection error.';
      }
    }
  } catch(Exception $e) {
    return 'FAILURE: ' . $e;
  }

  return l('REMOTE', 'aspi/remote');
}

/**
 * Execute the LoginServlet
 *
 * @return bool
 */
function login() {
  $loginServlet = new LoginServlet('Marek', 'Pass');

  $state = $loginServlet->execute()->state();

  if ($state == ServletStatus::SUCCESS) {
    $loginServlet->processResponse();
    return true;
  }

  return false;
}

/**
 * Try connecting to the Guacamole server
 * @return bool
 */
function connect() {
  $connectionServlet = new ConnectionServlet();

  $state = $connectionServlet->execute()->state();

  switch ($state) {
    case ServletStatus::SUCCESS:
      dpm('SESSION ACTIVE: ' . Session::get(JSESSIONID));
      $connectionServlet->processResponse();
      return true;
    case ServletStatus::AUTH_FAIL:
    default:
      return false;
  }
}

function esf_module_page_aspi_remote() {
  $module_path = drupal_get_path('module', 'esf_module');

  // remove any javascript added so far
  //drupal_static_reset('drupal_add_js');

  drupal_add_js($module_path . '/js/lib/blob/blob.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/lib/filesaver/filesaver.js', array('group' => JS_LIBRARY));

  drupal_add_js($module_path . '/js/esf-common.js', array('group' => JS_LIBRARY));

  drupal_add_js($module_path . '/js/lib/guacamole.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/lib/oskeyboard.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/lib/keyboard.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/lib/mouse.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/lib/layer.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/lib/tunnel.js', array('group' => JS_LIBRARY));

  drupal_add_js($module_path . '/js/session.js', array('weight' => 0, 'scope' => 'footer'));
  drupal_add_js($module_path . '/js/guac-ui.js', array('weight' => 1, 'scope' => 'footer'));
  drupal_add_js($module_path . '/js/client-ui.js', array('weight' => 2, 'scope' => 'footer'));

  drupal_add_js($module_path . '/js/aspi-remote.js', array('weight' => 3, 'scope' => 'footer'));

  drupal_add_css($module_path. '/css/aspi_remote.css');

  return array();
}