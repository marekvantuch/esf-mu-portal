<?php

module_load_include('inc', 'esf_module', 'includes/esf_module.servlets');
module_load_include('inc', 'esf_module', 'lib/cookie_parser');

function esf_module_page_aspi() {
  
  $connection = new ConnectionServlet();
  
  if (!$connection->execute()->successful()) {
    
    $login = new LoginServlet('Marek', 'Pass');
    
    if (!$login->execute()->successful()) {
      return 'FAILURE';
    } else {
      $login->saveSession();
    }
  }
  dpm(JSESSIONID);
  dpm(Session::get(JSESSIONID));
  //user_cookie_save(array(SESSION_ID => Session::get(JSESSIONID)));
  $server_url = 
  $domain = ($_SERVER['HTTP_HOST'] != 'localhost') ? $_SERVER['HTTP_HOST'] : false;
  
  setcookie(JSESSIONID, Session::get(JSESSIONID), 0, '/guacamole-esf/', "localhost:8080");
  
  return 'SUCCESS';
}

function esf_module_page_aspi_remote() {
  $module_path = drupal_get_path('module', 'esf_module'); 
  drupal_add_js($module_path . '/js/lib/guacamole.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/lib/oskeyboard.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/lib/keyboard.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/lib/mouse.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/lib/layer.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/lib/tunnel.js', array('group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/esf-common.js', array('weight' => -1, 'group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/session.js', array('weight' => 0, 'scope' => 'footer'));
  drupal_add_js($module_path . '/js/guac-ui.js', array('weight' => 1, 'scope' => 'footer'));
  drupal_add_js($module_path . '/js/client-ui.js', array('weight' => 2, 'scope' => 'footer'));
  drupal_add_js($module_path . '/js/aspi-remote.js', array('weight' => 3, 'scope' => 'footer'));
  drupal_add_css($module_path. '/css/aspi_remote.css');
  
  return array();
}