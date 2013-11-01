<?php

class Session {
  public static function set($name, $value) {
    $_SESSION[$name] = $value;
  }
  
  public static function get($name) {
    return isset($_SESSION[$name]) ? $_SESSION[$name] : null;
  }
}

/**
 * Class Server for handling the server url from the variables
 * set in the drupal configuration pages
 */
class Server {
  /**
   * Returns the formatted string with the url of the server
   *
   * @param bool $include_path include or exclude the final path on the server
   * @return string url of the server to connect to
   */
  public static function getUrl($include_path = TRUE) {
    $domain = self::getDomain();
    $port = self::getPort();
    $path = self::getPath();
    
    return (!strncmp($domain, 'http', strlen('http')) ? $domain : 'http://' . $domain )
        . ($port != 0 ? ':' . $port : '')
        . ($include_path ? $path : '');
  }

  public static function getPath() {
    return variable_get(GUACAMOLE_SERVER_PATH);
  }

  public static function getDomain() {
    return variable_get(GUACAMOLE_SERVER_DOMAIN);
  }

  public static function getPort() {
    return variable_get(GUACAMOLE_SERVER_PORT);
  }
}