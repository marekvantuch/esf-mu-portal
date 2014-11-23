<?php
/**
 * Created by PhpStorm.
 * User: Marek Vantuch
 * Date: 11/23/2014
 * Time: 9:16 PM
 */
namespace Drupal\esf_module\Servlets;

class ServletStatus {
  /**
   * Successful response
   * @var int
   */
  const SUCCESS = 0;

  /**
   * Failure of authentication
   * @var int
   */
  const AUTH_FAIL = 1;
}