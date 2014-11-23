<?php

/**
 * @file
 * Guacamole properties file related classes
 */

namespace Drupal\esf_module\Properties;



/**
 * Class RadioProperty
 *
 * Displays options to be chosen from. Those options are captured from the
 * constructor.
 *
 * @package Esf
 */
class RadioProperty extends Property {
  protected $options;

  /**
   * Builds the object with options.
   *
   * Parent is created in the same way, but options for the
   * radio buttons are included in this constructor.
   *
   * @param string $id
   *   id of the property
   * @param string $title
   *   title of the property
   * @param string $description
   *   description of the property
   * @param array $options
   *   options defining the values of the radio buttons
   */
  public function __construct($id, $title, $description, $options) {
    parent::__construct($id, $title, $description);
    $this->options = array();

    foreach ($options as $option) {
      $this->options[strtolower($option)] = t($option);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getType() {
    return Property::TYPE_RADIOS;
  }

  /**
   * {@inheritdoc}
   */
  public function getExtraParameters() {
    return array(
      '#options' => $this->options,
    );
  }

  /**
   * {@inheritdoc}
   */
  public static function validate($element, &$form_state) {

  }
}
