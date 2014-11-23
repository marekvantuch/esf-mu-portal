<?php

/**
 * @file
 * Classes and code common to the whole module.
 */

namespace Drupal\esf_module;

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
