<?php

/**
 * @file
 * Classes and code common to the whole module.
 */

namespace Esf;

module_load_include('inc', 'esf_module', 'includes/esf_module.interfaces');

class Settings {
  /**
   * Returns the ASPI username for the currently logged user.
   *
   * Username is set on the user profile page.
   *
   * @return string
   *   ASPI username
   */
  public static function username() {
    global $user;

    return user_load($user->uid)->field_aspi_username[LANGUAGE_NONE][0]['value'];
  }

  /**
   * Returns the ASPI password for the currently logged user.
   *
   * Password is set on the user profile page and is encrypted in db.
   *
   * @return string
   *   ASPI password
   */
  public static function password() {
    global $user;

    $user_object = user_load($user->uid);

    $field_aspi_password = $user_object->field_aspi_password[LANGUAGE_NONE][0];

    $value = array_key_exists('value', $field_aspi_password) ?
      $field_aspi_password['value'] :
      $field_aspi_password['password_field'];

    return password_field_decrypt($value);
  }
}

/**
 * Class Session
 * @package Esf
 */
class Session {
  /**
   * Sets the session by it's name and value.
   *
   * @param string $name
   *   name of the session
   * @param string $value
   *   value to be set
   */
  public static function set($name, $value) {
    $_SESSION[$name] = $value;
  }

  /**
   * Gets the value from session.
   *
   * @param string $name
   *   name of the session parameter
   *
   * @return string
   *   value of the session parameter
   */
  public static function get($name) {
    return isset($_SESSION[$name]) ? $_SESSION[$name] : NULL;
  }
}

/**
 * Class Server for handling the server url from the variables
 * set in the drupal configuration pages
 * @package Esf
 */
class Server {
  /**
   * Returns the formatted string with the url of the server.
   *
   * @param bool $include_path
   *   include or exclude the final path on the server
   *
   * @return string
   *   url of the server to connect to
   */
  public static function getUrl($include_path = TRUE) {
    $domain = self::getDomain();
    $port = self::getPort();
    $path = self::getPath();

    return (!strncmp($domain, 'http', strlen('http')) ? $domain : 'http://' . $domain)
    . ($port != 0 ? ':' . $port : '')
    . ($include_path ? $path : '');
  }

  /**
   * Loads the server path from variable storage.
   *
   * @return string
   *   server path
   */
  public static function getPath() {
    return variable_get(ESF_MODULE_GUACAMOLE_SERVER_PATH);
  }

  /**
   * Loads the domain from variable storage.
   *
   * @return string
   *   domain
   */
  public static function getDomain() {
    return variable_get(ESF_MODULE_GUACAMOLE_SERVER_DOMAIN);
  }

  /**
   * Loads the port from variable storage.
   *
   * @return string
   *   port
   */
  public static function getPort() {
    return variable_get(ESF_MODULE_GUACAMOLE_SERVER_PORT);
  }
}
