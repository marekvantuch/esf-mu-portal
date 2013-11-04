<?php

/**
 * @file
 * Ajax related functions.
 */

use Esf\LoginServlet;
use Esf\ServletException;
use Esf\ServletStatus;

module_load_include('inc', 'esf_module', 'includes/esf_module.servlets');
module_load_include('inc', 'esf_module', 'lib/cookie_parser');

/**
 * Function for the ajax response for login.
 *
 * No exceptions are thrown, while rather the function returns JSON
 * with the error description, to be displayed on the page.
 *
 * @return int|null
 *   response for the calling page
 */
function esf_module_ajax_login() {
  $login_servlet = new LoginServlet('Marek', 'Pass');

  try {
    $state = $login_servlet->execute()->state();
  }
  catch (ServletException $e) {
    drupal_json_output(array('error' => $e->getMessage()));

    return NULL;
  }

  switch ($state) {
    case ServletStatus::SUCCESS:
      $login_servlet->processResponse();
      drupal_json_output();
      break;

    case ServletStatus::AUTH_FAIL:
      return MENU_ACCESS_DENIED;
  }

  return NULL;
}
