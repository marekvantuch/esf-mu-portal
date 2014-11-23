<?php
/**
 * Created by PhpStorm.
 * User: Marek Vantuch
 * Date: 11/23/2014
 * Time: 9:10 PM
 */
namespace Drupal\esf_module\Properties;

/**
 * Class Properties
 * @package Esf
 */
class Properties {
  /**
   * @var array
   */
  protected $data;

  /**
   * Hostname and port of guacamole proxy
   */
  const GUACD_HOSTNAME = 'guacd-hostname';
  const GUACD_PORT = 'guacd-port';

  /**
   * Auth provider class (authenticates user/pass combination, needed if using
   * the provided login screen)
   */
  const AUTH_PROVIDER = 'auth-provider';

  /**
   * Connection details for the Drupal Auth method
   */
  const CONNECTION_NAME = 'connection-name';
  const CONNECTION_PROTOCOL = 'connection-protocol';
  const CONNECTION_HOSTNAME = 'connection-hostname';
  const CONNECTION_PORT = 'connection-port';

  /**
   * Stores all the properties
   *
   * @var \Drupal\esf_module\Interfaces\PropertyInterface[]
   */
  protected $properties;

  /**
   * @var bool
   */
  protected $propertiesFileExists = FALSE;

  /**
   * @var \SplFileObject
   */
  protected $propertiesFile;

  /**
   * Constructs the Properties object.
   *
   * Uses file containing the java style properties.
   *
   * @param \SplFileObject $properties_file
   *   File containing the properties
   */
  public function __construct($properties_file) {
    $this->propertiesFile = $properties_file;

    $this->initPropertiesFile();
    $this->initProperties();
  }

  /**
   * Return all the properties loaded from the file.
   *
   * @return array
   *   associative array of property_id->property_value
   */
  public function getAll() {
    if ($this->propertiesFileExists) {
      return $this->data;
    }

    return array();
  }

  /**
   * Get value of a property.
   *
   * @param string $property_id
   *   id of the property
   *
   * @return string
   *   value of the property
   */
  public function get($property_id) {
    if ($this->propertiesFileExists && array_key_exists($property_id, $this->data)) {
      return $this->data[$property_id];
    }

    return '';
  }

  /**
   * Set value of a property.
   *
   * @param string $property_id
   *   id of the property
   * @param string $property_value
   *   value of the property
   */
  public function set($property_id, $property_value) {
    $this->data[$property_id] = $property_value;
  }

  /**
   * Updates the properties file with current values.
   *
   * @param array $form_state
   *   form_state array from the Drupal Forms API
   */
  public function submitForm($form_state) {
    foreach ($this->properties as $property) {
      $property_id = $property->getId();
      if (array_key_exists($property_id, $form_state['values'])) {
        $this->set($property_id, $form_state['values'][$property_id]);
      }
    }

    $string = implode("\r\n", array_map(function ($v, $k) {
      return $k . "\t:\t" . $v;
    }, $this->data, array_keys($this->data)));

    $this->propertiesFile->rewind();
    $length = $this->propertiesFile->fwrite($string);
    $this->propertiesFile->ftruncate($length);
    $this->propertiesFile->fflush();
  }

  /**
   * Builds an array in Drupal Forms API for all registered properties.
   *
   * @return array
   *   associative array with Drupal Forms API objects
   */
  public function buildForm() {
    $result = array();

    foreach ($this->properties as $property_id => $property) {
      $result[$property_id] = $this->buildFormProperty($property);
    }

    $result['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save'),
    );

    return $result;
  }

  /**
   * Builds an array in Drupal Forms API for a single property.
   *
   * @param \Drupal\esf_module\Interfaces\PropertyInterface $property
   *   property to be used
   *
   * @return array
   *   drupal Form API array
   */
  protected function buildFormProperty($property) {
    return array_merge(array(
      '#type' => $property->getType(),
      '#title' => t($property->getTitle()),
      '#description' => t($property->getDescription()),
      '#default_value' => $this->get($property->getId()),
      // @TODO Find out why this doesn't work and resolve it again
      //'#element_validate' => array(array($property, 'validate')),
      //'#element_validate' => array(get_class($property) . '::validate'),
      '#required' => TRUE,
      '#disabled' => !$this->propertiesFileExists,
    ), $property->getExtraParameters());
  }

  /**
   * Init the properties file and load the properties.
   */
  protected function initPropertiesFile() {

    if ($this->propertiesFile->isReadable()) {
      $this->data = $this->parseProperties();
      $this->propertiesFileExists = TRUE;
    }
    else {
      $this->propertiesFileExists = FALSE;
    }
  }

  /**
   * Sets the properties object.
   *
   * Uses all the properties used in the module.
   */
  protected function initProperties() {
    $this->add(new TextProperty(
      self::GUACD_HOSTNAME,
      'Guacd hostname',
      'Hostname of the Guacamole Proxy'));

    $this->add(new NumberProperty(
      self::GUACD_PORT,
      'Guacd port',
      'Port of the Guacamole Proxy'));

    $this->add(new TextProperty(
      self::CONNECTION_NAME,
      'Connection name',
      'Identifier of the connection'));

    $this->add(new TextProperty(
      self::CONNECTION_HOSTNAME,
      'Connection hostname',
      'Hostname of the Remote Machine'));

    $this->add(new NumberProperty(
      self::CONNECTION_PORT,
      'Connection port',
      'Hostname of the Remote Machine'));

    $this->add(new RadioProperty(
      self::CONNECTION_PROTOCOL,
      'Connection protocol',
      'Protocol to be used in the remote connection',
      array('RDP', 'VNC')));
  }

  /**
   * Adds a property into the internal properties object.
   *
   * @param \Drupal\esf_module\Interfaces\PropertyInterface $property
   *   property to be added
   */
  protected function add($property) {
    $this->properties[$property->getId()] = $property;
  }

  /**
   * Parses the properties file into an associative array.
   *
   * @return array
   *   properties in an associative array
   */
  protected function parseProperties() {
    $result = $lines = array();

    foreach ($this->propertiesFile as $line) {

      if (preg_match('/([\w-]+)[\s]*:[\s]*(.*)/', $line, $matches)) {
        $key = trim($matches[1]);
        $value = trim($matches[2]);

        $result[$key] = $value;
      }
    }

    return $result;
  }
}