<?php
/**
 * Created by PhpStorm.
 * User: Marek Vantuch
 * Date: 11/23/2014
 * Time: 9:14 PM
 */
namespace Drupal\esf_module\Servlets;

use Drupal\esf_module\Session;
use Drupal\esf_module\Server;

/**
 * Servlet for connecting to the Guacamole system
 */
class LoginServlet extends Servlet {
  protected $username;
  protected $password;

  /**
   * Creates new LoginServlet with it's required parameters.
   *
   * We need to supply username and password to be able to login
   * to the Guacamole system.
   *
   * @param string $username
   *   username
   * @param string $password
   *   password
   */
  public function __construct($username, $password) {
    $this->username = $username;
    $this->password = $password;
  }

  /**
   * {@inheritdoc}
   */
  protected function urlParameters() {
    return array(
      'username' => $this->username,
      'password' => $this->password,
    );
  }

  /**
   * {@inheritdoc}
   */
  protected function method() {
    return Servlet::METHOD_POST;
  }

  /**
   * {@inheritdoc}
   */
  protected function endPoint() {
    return 'login';
  }

  /**
   * Returns the state of the Login Servlet.
   *
   * Login servlet must not get an AUTH_FAIL status and therefore must
   * throw an exception in case that happens
   *
   * @throws ServletException
   * @return ServletStatus
   *   status of the response from servlet
   */
  public function state() {
    $state = parent::state();

    if ($state == ServletStatus::AUTH_FAIL) {
      throw new ServletException($this);
    }

    return $state;
  }


  /**
   * Store the java login cookie in the session.
   *notificationArea
   * @return LoginServlet
   *   the same object
   */
  public function processResponse() {
    $cookie_value = $this->getCookie(Servlet::JSESSIONID)->value;

    // If session already exists, we don't get any cookie.
    if ($cookie_value != NULL) {

      Session::set(Servlet::JSESSIONID, $cookie_value);

      $server_domain = Server::getDomain() != 'localhost' ? Server::getDomain() : FALSE;
      $server_path = Server::getPath();

      setcookie(Servlet::JSESSIONID, $cookie_value, 0, $server_path, $server_domain);
    }
    return $this;
  }
}