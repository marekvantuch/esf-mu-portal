<?php
/**
 * Created by PhpStorm.
 * User: Marek Vantuch
 * Date: 11/23/2014
 * Time: 9:16 PM
 */
namespace Drupal\esf_module\Servlets;
use Exception;


/**
 * Class ServletException is to be raised during the execution of servlets
 */
class ServletException extends \Exception {

  /**
   * Creates a new ServletException.
   *
   * The parameter is then used to form a standardized exception string.
   *
   * @param Servlet $servlet
   *   servlet this exception relates to
   */
  public function __construct($servlet) {
    parent::__construct($servlet->statusMessage(), $servlet->statusCode());
  }

  /**
   * {@inheritdoc}
   */
  public function __toString() {
    return '[' . $this->code . '] ' . $this->message;
  }
}