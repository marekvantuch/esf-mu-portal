<?php
/**
 * Created by PhpStorm.
 * User: Marek Vantuch
 * Date: 11/23/2014
 * Time: 9:12 PM
 */
namespace Drupal\esf_module\Properties;

/**
 * Class NumberProperty
 *
 * Captures number and therefore validates the result for it.
 *
 * @package Esf
 */
class NumberProperty extends TextProperty {

  /**
   * {@inheritdoc}
   */
  public static function validate($element, &$form_state) {
    \Drupal\esf_module\Properties\parent::validate($element, $form_state);

    if (!is_numeric($element['#value'])) {
      form_error($element, t('The "!name" option must be a number.',
        array('!name' => t($element['#title']))));
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getExtraParameters() {
    return array('#size' => 10);
  }
}