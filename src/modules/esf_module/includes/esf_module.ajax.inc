<?php

module_load_include('inc', 'esf_module', 'includes/esf_module.servlets');
module_load_include('inc', 'esf_module', 'lib/cookie_parser');

function esf_module_ajax_login() {
  $loginServlet = new LoginServlet('Marek', 'Pass');

  try {
    $state = $loginServlet->execute()->state();
  } catch (ServletException $e) {
    drupal_json_output(array('error' => $e->getMessage()));

    return null;
  }

  switch($state) {
    case ServletStatus::SUCCESS:
      $loginServlet->processResponse();
      drupal_json_output();
      break;
    case ServletStatus::AUTH_FAIL:
      return MENU_ACCESS_DENIED;
  }

  return null;
}
