<?php

define ('METHOD_POST', 'POST');
define ('METHOD_GET', 'GET');
define ('METHOD_PUT', 'PUT');

define('JSESSIONID', 'JSESSIONID');

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
   * @param string $username
   * @param string $password
   * @return \Servlet
   */
  public function execute() {
    $this->result = drupal_http_request($this->url(), $this->_buildOptions());
    return $this;
  }
  
  /**
   * Check the return code to be 200
   * 
   * @return \Servlet
   */
  public final function successful() {
    return $this->result->code == 200;
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
   * @param $cookie_name cookie name
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
   * @param array $data associative array with data to be posted
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
   * Store the java login cookie in the session
   * 
   * @return \LoginServlet
   */
  public function saveSession() {
    $cookie_value = $this->getCookie(JSESSIONID)->value;
    
    Session::set(JSESSIONID, $cookie_value);
    
    user_cookie_save(array(JSESSIONID => $cookie_value));
    
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
}