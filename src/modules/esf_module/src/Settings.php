<?php
/**
 * Created by PhpStorm.
 * User: Marek Vantuch
 * Date: 11/23/2014
 * Time: 9:00 PM
 */

namespace Drupal\esf_module;


class Settings {
  /**
   * Returns the ASPI username for the currently logged user.
   *
   * Username is set on the user profile page.
   *
   * @return string
   *   ASPI username
   */
  public static function username() {
    global $user;

    $user = user_load($user->uid);
    $wrapper = \EbtWrapperUser::factory($user);
    return $wrapper->field_aspi_username->value();
  }

  /**
   * Returns the ASPI password for the currently logged user.
   *
   * Password is set on the user profile page and is encrypted in db.
   *
   * @return string
   *   ASPI password
   */
  public static function password() {
    global $user;

    $user_object = user_load($user->uid);

    $field_aspi_password = $user_object->field_aspi_password[LANGUAGE_NONE][0];

    $value = array_key_exists('value', $field_aspi_password) ?
      $field_aspi_password['value'] :
      $field_aspi_password['password_field'];

    return password_field_decrypt($value);
  }

  public static function prefers_guacamole() {
    global $user;

    $user_object = user_load($user->uid);

    if (!property_exists($user_object, 'field_use_aspi_client')) {
      return false;
    }

    $field_use_aspi_client = $user_object->field_use_aspi_client;

    if (array_key_exists(LANGUAGE_NONE, $field_use_aspi_client)) {
      return $field_use_aspi_client[LANGUAGE_NONE][0]['value'];
    }

    return false;
  }
} 