<?php

/**
 * @file
 * Classes and functions related to the guacamole JAVA application.
 *
 * Connection to the servlets running on the Guacamole server is
 * handled in these classes.
 */

namespace Esf;

define('JSESSIONID', 'JSESSIONID');

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

abstract class Servlet {
  const METHOD_POST = 'POST';
  const METHOD_GET = 'GET';
  const METHOD_PUT = 'PUT';

  protected static $url;

  /**
   * Executes a service login call.
   *
   * @return \Esf\Servlet
   *   the same object
   */
  public function execute() {
    try {
      $this->result = drupal_http_request($this->url(), $this->buildOptions());
    }
    catch (\Exception $e) {
      $this->result = (object) array('code' => $e->getCode(), 'error' => $e->getMessage());
    }

    return $this;
  }

  /**
   * Check the return code to be 200.
   *
   * @throws ServletException
   * @return \Esf\ServletStatus
   *   state of the servlet object
   */
  public function state() {
    switch ($this->result->code) {
      case 200:
        return ServletStatus::SUCCESS;

      case 403:
        return ServletStatus::AUTH_FAIL;

      default:
        $e = new ServletException($this);
        watchdog('esf_module', 'Servlet call failed with: %e url: %url',
          array(
            '%e' => (string) $e,
            '%url' => $this->url(),
          ),
          WATCHDOG_ERROR);
        throw $e;
    }
  }

  /**
   * Return the error message of the request.
   *
   * @return string|null
   *   eventual error
   */
  public final function statusMessage() {
    return $this->result->error;
  }

  /**
   * Return the status code of the response.
   *
   * @return string|null
   *   status code
   */
  public function statusCode() {
    return $this->result->code;
  }

  /**
   * Get the cookies string.
   *
   * @return string
   *   raw cookies string
   */
  protected final function getCookies() {
    return $this->result->headers['set-cookie'];
  }

  /**
   * Returns a cookie of a specific name.
   *
   * @param string $cookie_name
   *   cookie name
   *
   * @return \Cookie
   *   name of the cookie
   */
  protected final function getCookie($cookie_name) {
    $cookies = parse_cookies($this->result->headers['set-cookie']);

    foreach ($cookies as $cookie) {
      if ($cookie->name == $cookie_name) {
        return $cookie;
      }
    }
    return NULL;
  }

  /**
   * Returns the server and port part of the url.
   *
   * @return string
   *   base url
   */
  protected static function urlBase() {
    if (!self::$url) {
      self::$url = Server::getUrl();
    }

    return self::$url;
  }

  /**
   * Builds the url of the service endpoint.
   *
   * @return string
   *   complete url of the servlet
   */
  protected function url() {
    $url_params = $this->urlParameters();

    $options = $url_params ?
      array('query' => $url_params) :
      array();

    return url(self::urlBase() . $this->endPoint(), $options);
  }

  /**
   * Builds the options array.
   *
   * @return array
   *   array with options
   */
  protected function buildOptions() {
    return array(
      'method' => $this->method(),
      'data' => drupal_http_build_query($this->data()),
      'timeout' => 15,
      'headers' => array(
        'Content-Type' => 'application/json',
        'Cookie' => JSESSIONID . '=' . Session::get(JSESSIONID),
      ),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function __toString() {
    return $this->result->code . (
    property_exists($this->result, 'status_message') ?
      ' : ' . $this->result->status_message :
      ''
    );
  }

  /**
   * Contains the result of the query
   *
   * @var object @see drupal_http_request
   */
  protected $result;

  /**
   * Returns data to be passed into the request.
   *
   * @returns array
   *   data to be passed into the request
   */
  protected function data() {
    return array();
  }

  /**
   * Gets parameters to be passed to the request.
   *
   * @return array
   *   parameters to be passed into the request
   */
  protected function urlParameters() {
    return array();
  }

  /**
   * Returns the method to be used in connection.
   *
   * Constants from the class should be used.
   * (METHOD_POST/...)
   *
   * @returns string
   *   method to be used
   */
  protected abstract function method();


  /**
   * Returns endpoint for the resource.
   *
   * @returns string
   *   endpoint to the resource
   */
  protected abstract function endPoint();

  /**
   * Function to be called to process the response from the servlet.
   *
   * @return bool
   *   result of the processing
   */
  public abstract function processResponse();
}

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
   * @return \Esf\LoginServlet
   *   the same object
   */
  public function processResponse() {
    $cookie_value = $this->getCookie(JSESSIONID)->value;

    // If session already exists, we don't get any cookie.
    if ($cookie_value != NULL) {

      Session::set(JSESSIONID, $cookie_value);

      $server_domain = Server::getDomain() != 'localhost' ? Server::getDomain() : FALSE;
      $server_path = Server::getPath();

      setcookie(JSESSIONID, $cookie_value, 0, $server_path, $server_domain);
    }
    return $this;
  }
}
