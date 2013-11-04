<?php

/**
 * @file
 * Ajax related functions.
 */

use Esf\LoginServlet;
use Esf\ServletException;
use Esf\ServletStatus;
use Esf\Settings;

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
  $username = Settings::username();
  $password = Settings::password();

  if (empty($username)) {
    return json_error('Username is not set');
  }

  if (empty($password)) {
    return json_error('Password is not set');
  }

  $login_servlet = new LoginServlet($username, $password);

  try {
    $state = $login_servlet->execute()->state();
  }
  catch (ServletException $e) {
    return json_error($e->getMessage());
  }

  switch ($state) {
    case ServletStatus::SUCCESS:
      $login_servlet->processResponse();
      drupal_json_output();
      break;

    case ServletStatus::AUTH_FAIL:
      return MENU_ACCESS_DENIED;
  }
}

/**
 * Returns error message by json and provides a return value.
 *
 * @param string $message
 *   message to be returned
 *
 * @return null
 *   always returns null
 */
function json_error($message) {
  drupal_json_output(array('error' => $message));
}
