<?php

define ('METHOD_POST', 'POST');
define ('METHOD_GET', 'GET');
define ('METHOD_PUT', 'PUT');

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
class ServletException extends Exception {

  /**
   * @param Servlet $servlet
   */
  function __construct($servlet) {
    parent::__construct($servlet->statusMessage(), $servlet->statusCode());
  }

  public function __toString() {
    return '[' . $this->code . '] ' . $this->message;
  }

}

/**
 * Description of Servlet
 *
 * @author marek
 */
abstract class Servlet {
  
  private static $_url;

  /**
   * Executes a service login call
   *
   * @return \Servlet
   */
  public function execute() {
    try {
      $this->result = drupal_http_request($this->url(), $this->_buildOptions());
    } catch (Exception $e) {
      $this->result = (object) array('code' => $e->getCode(), 'error' => $e->getMessage());
    }

    return $this;
  }

  /**
   * Check the return code to be 200
   *
   * @throws ServletException
   * @return \ServletStatus
   */
  public function state() {
    switch($this->result->code) {
      case 200:
        return ServletStatus::SUCCESS;
      case 403:
        return ServletStatus::AUTH_FAIL;
      default:
        $e = new ServletException($this);
        watchdog('esf_module', 'Servlet call failed with: %e', array('%e' => (string) $e), WATCHDOG_ERROR);
        throw $e;
    }
  }

  /**
   * Return the error message of the request
   *
   * @return string|null
   */
  public final function statusMessage() {
    return $this->result->error;
  }

  /**
   * Return the status code of the response
   *
   * @return string|null
   */
  public function statusCode() {
    return $this->result->code;
  }

  /**
   * Get the cookies string 
   * 
   * @return string
   */
  protected final function getCookies() {
    return $this->result->headers['set-cookie'];
  }
  
  /**
   * Returns a cookie of a specific name
   * 
   * @param string $cookie_name cookie name
   * @return cookie
   */
  protected final function getCookie($cookie_name) {
    $cookies = parse_cookies($this->result->headers['set-cookie']);
    
    foreach($cookies as $cookie) {
      if ($cookie->name == $cookie_name) {
        return $cookie;
      }
    }
    return null;
  }
  
  /**
   * Returns the server and port part of the url
   * 
   * @return string
   */
  protected static function _urlBase() {
    if (!self::$_url) {
      self::$_url = Server::getUrl();
    }
    
    return self::$_url;
  }
  
  /**
   * Builds the url of the service endpoint
   * 
   * @return string
   */
  private function url() {
    $urlParams = $this->urlParameters();
    
    $options = $urlParams 
        ? array('query' => $urlParams)
        : array();
    
    return url(self::_urlBase() . $this->endPoint(), $options);
  }

  /**
   * Builds the options array.
   *
   * @internal param array $data associative array with data to be posted
   * @return array
   */
  private function _buildOptions() {
    return array(
      'method' => $this->method(),
      'data' => drupal_http_build_query($this->data()),
      'timeout' => 15,
      'headers' => array(
        'Content-Type' => 'application/json',
        'Cookie' => JSESSIONID . '=' . Session::get(JSESSIONID))
    );
  }  
  
  public function __toString() {
    return $this->result->code . (
        property_exists($this->result, 'status_message') 
        ? ' : ' . $this->result->status_message 
        : '');
  }
  
  /**
   * Contains the result of the query 
   * 
   * @var object @see drupal_http_request 
   */
  protected $result;
  
  /**
   * @returns array data to be passed into the request
   */
  protected function data() {
    return array();
  }
  
  protected function urlParameters() {
    return array();
  }
  
  /**
   * @returns string method to be used (METHOD_POST/...)
   */
  protected abstract function method();
  
  
  /**
   * @returns string endpoint to the resource
   */
  protected abstract function endPoint();

  /**
   * Function to be called to process the response from the servlet
   *
   * @return bool result of the processing
   */
  public abstract function processResponse();
}

/**
 * Servlet for connecting to the Guacamole system
 */
class LoginServlet extends Servlet {
  private $_username;
  private $_password;
  
  function __construct($username, $password) {
    $this->_username = $username;
    $this->_password = $password;
  }
  
  protected function urlParameters() {
    return array(
      'username' => $this->_username,
      'password' => $this->_password
    );
  }

  protected function method() {
    return METHOD_POST;
  }

  protected function endPoint() {
    return 'login';
  }

  /**
   * Login servlet must not get an AUTH_FAIL status and therefore must
   * throw an exception in case that happens
   *
   * @throws ServletException
   * @return ServletStatus
   */
  public function state() {
    $state = parent::state();

    if ($state == ServletStatus::AUTH_FAIL) {
      throw new ServletException($this);
    }

    return $state;
  }


  /**
   * Store the java login cookie in the session
   * 
   * @return \LoginServlet
   */
  public function processResponse() {
    $cookie_value = $this->getCookie(JSESSIONID)->value;

    // If session already exists, we don't get any cookie
    if ($cookie_value != null) {

      //dpm('SESSION SAVED: ' . $cookie_value);

      Session::set(JSESSIONID, $cookie_value);

      //user_cookie_save(array(JSESSIONID => $cookie_value));

      $server_domain = Server::getDomain() != 'localhost' ? Server::getDomain() : false;
      $server_path = Server::getPath();

      setcookie(JSESSIONID, $cookie_value, 0, $server_path, $server_domain);
    }
    return $this;
  }

}

/**
 * Servlet for retrieving ASPI connection details
 */
class ConnectionServlet extends Servlet {

  protected function endPoint() {
    return 'connection';
  }

  protected function method() {
    return METHOD_POST;
  }

  /**
   * Stores the connection in the cookie for the website
   *
   * @return bool result of the processing
   */
  public function processResponse() {
    $data = json_decode($this->result->data);
    $identifier = $data->identifier;
    //user_cookie_save(array('C'))
  }
}