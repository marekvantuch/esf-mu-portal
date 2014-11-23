<?php
/**
 * Created by PhpStorm.
 * User: Marek Vantuch
 * Date: 11/23/2014
 * Time: 9:11 PM
 */
namespace Drupal\esf_module\Properties;
/**
 * Class TextProperty
 *
 * Can capture text only and provides only validation not to be empty.
 *
 * @package Esf
 */
class TextProperty extends Property {

  /**
   * {@inheritdoc}
   */
  public function getType() {
    return Property::TYPE_TEXT;
  }

  /**
   * {@inheritdoc}
   */
  public function getExtraParameters() {
    return array('#size' => 20);
  }

  /**
   * {@inheritdoc}
   */
  public static function validate($element, &$form_state) {
    if (empty($element['#value'])) {
      form_error($element, t('The "!name" option must not be empty.',
        array('!name' => t($element['#title']))));
    }
  }
}