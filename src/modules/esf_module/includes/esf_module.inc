<?php

class Session {
  public static function set($name, $value) {
    $_SESSION[$name] = $value;
  }
  
  public static function get($name) {
    return isset($_SESSION[$name]) ? $_SESSION[$name] : null;
  }
}

class Server {
  public static function getUrl() {
    $domain = variable_get('guacamole_server_domain');
    $port = variable_get('guacamole_server_port');
    $path = variable_get('guacamole_server_path');
    
    return $domain
        . ($port != 0 ? $port : '')
        . $path;
  }
}