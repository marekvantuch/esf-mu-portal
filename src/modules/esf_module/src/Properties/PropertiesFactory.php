<?php
/**
 * Created by PhpStorm.
 * User: Marek Vantuch
 * Date: 11/23/2014
 * Time: 9:08 PM
 */
namespace Drupal\esf_module\Properties;

/**
 * Class PropertiesFactory
 * @package Esf
 */
class PropertiesFactory {
  /**
   * Builds the \Esf\Properties object.
   *
   * Object needs filename passed into it's constructor. In our case that is
   * a properties file and we load it's filename from the variables.
   *
   * For list of all the properties see define statements:
   * @see esf_module.inc
   *
   * @return Properties
   *   Newly created \Esf\Properties object.
   */
  public static function build() {
    return (new Properties(new \SplFileObject(variable_get(ESF_MODULE_GUACAMOLE_HOME) . variable_get(ESF_MODULE_GUACAMOLE_PROPERTIES_FILE), 'r+')));
  }
}