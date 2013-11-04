<?php

/**
 * @file
 * Interfaces for classes for the module.
 */

namespace Esf;

/**
 * Interface IProperty
 *
 * Provides common interface for properties and their handling.
 *
 * @package Esf
 */
interface PropertyInterface {
  /**
   * Validate the property data, defaults to true if not overridden.
   *
   * @param array $element
   *   element from the form api
   * @param array $form_state
   *   form_state from the form api function call
   */
  public static function validate($element, &$form_state);

  /**
   * Get id of the property.
   *
   * @return string
   *   id of the property
   */
  public function getId();

  /**
   * Get title of the property.
   *
   * @return string
   *   title of the property to be displayed on the settings page
   */
  public function getTitle();

  /**
   * Get description of the property.
   *
   * @return string
   *   description of the property to be displayed on the settings page
   */
  public function getDescription();

  /**
   * Get type of the property.
   *
   * @return string
   *   type of the property defined in the Property class (TYPE_TEXT,
   *   TYPE_RADIOS, ...)
   */
  public function getType();

  /**
   * Get any extra parameters to be passed to the DRupal Form API.
   *
   * @return array
   *   extra parameters to be passed into the Drupal Form API
   */
  public function getExtraParameters();
}
