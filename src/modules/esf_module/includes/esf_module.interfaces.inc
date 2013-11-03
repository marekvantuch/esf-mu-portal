<?php

namespace Esf;


/**
 * Interface IProperty
 *
 * Provides common interface for properties and their handling.
 *
 * @package Esf
 */
interface IProperty {
  /**
   * Validate the property data, defaults to true if not overridden
   *
   * @param $element array
   * @param $form_state array
   * @return bool
   */
  public static function validate($element, &$form_state);

  /**
   * @return string id of the property
   */
  public function getId();

  /**
   * @return string title of the property to be displayed on the settings page
   */
  public function getTitle();

  /**
   * @return string description of the property to be displayed on the settings
   * page
   */
  public function getDescription();

  /**
   * @return string type of the property defined in the Property class
   * (TYPE_TEXT, TYPE_RADIOS, ...)
   */
  public function getType();

  /**
   * @return array of extra parameters to be passed into the Drupal Form API
   */
  public function getExtraParameters();
}

