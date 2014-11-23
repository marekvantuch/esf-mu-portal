<?php
/**
 * Created by PhpStorm.
 * User: Marek Vantuch
 * Date: 11/23/2014
 * Time: 9:07 PM
 */
namespace Drupal\esf_module;
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