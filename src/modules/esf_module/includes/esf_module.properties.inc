<?php

namespace Esf;

/**
 * Class PropertiesFactory
 * @package Esf
 */
class PropertiesFactory {
  /**
   * @return Properties
   */
  public static function build() {
    return (new Properties(new \SplFileObject(variable_get(GUACAMOLE_HOME) . variable_get(GUACAMOLE_PROPERTIES_FILE), 'r+')));
  }
}

/**
 * Class Properties
 * @package Esf
 */
class Properties {
  private $data;

  /**
   * Hostname and port of guacamole proxy
   */
  const GUACD_HOSTNAME = 'guacd-hostname';
  const GUACD_PORT = 'guacd-port';

  /**
   * Auth provider class (authenticates user/pass combination, needed if using the provided login screen)
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
   * @var \Esf\IProperty[]
   */
  private $properties;

  /**
   * @var bool
   */
  private $properties_file_exists = false;

  /**
   * @var \SplFileObject
   */
  private $properties_file;

  /**
   * @param $properties_file \SplFileObject
   */
  function __construct($properties_file) {
    $this->properties_file = $properties_file;

    $this->initPropertiesFile();
    $this->initProperties();
  }

  /**
   * Return all the properties loaded from the file
   *
   * @return array
   */
  public function getAll() {
    if ($this->properties_file_exists) {
      return $this->data;
    }

    return array();
  }

  /**
   * Get value of a property
   *
   * @param $property_id string
   * @return mixed
   */
  public function get($property_id) {
    if ($this->properties_file_exists && array_key_exists($property_id, $this->data)) {
      return $this->data[$property_id];
    }

    return '';
  }

  /**
   * Set value of a property
   *
   * @param $property_id string
   * @param $property_value mixed
   */
  public function set($property_id, $property_value) {
    $this->data[$property_id] = $property_value;
  }

  /**
   * Updates the properties file with current values.
   */
  public function submitForm($form_state) {
    foreach ($this->properties as $property) {
      $property_id = $property->getId();
      if (array_key_exists($property_id, $form_state['values'])) {
        $this->set($property_id, $form_state['values'][$property_id]);
      }
    }

    $string = implode("\r\n", array_map(function ($v, $k) { return $k . "\t:\t" . $v; }, $this->data, array_keys($this->data)));

    $this->properties_file->rewind();
    $length = $this->properties_file->fwrite($string);
    $this->properties_file->ftruncate($length);
    $this->properties_file->fflush();
  }

  /**
   * Builds an array in Drupal Forms API for all registered properties
   *
   * @return array
   */
  public function buildForm() {
    $result = array();

    foreach ($this->properties as $property_id => $property) {
      $result[$property_id] = $this->buildFormProperty($property);
    }

    $result['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save')
    );

    return $result;
  }

  /**
   * Builds an array in Drupal Forms API for a single property
   *
   * @param $property IProperty
   * @return array drupal Form API array
   */
  private function buildFormProperty($property) {
    return array_merge(array(
      '#type' => $property->getType(),
      '#title' => t($property->getTitle()),
      '#description' => t($property->getDescription()),
      '#default_value' => $this->get($property->getId()),
      '#element_validate' => array(array($property , 'validate')),
      '#required' => TRUE,
      '#disabled' => !$this->properties_file_exists,
    ), $property->getExtraParameters());
  }

  /**
   * Init the properties file and load the properties.
   */
  private function initPropertiesFile() {

    if ($this->properties_file->isReadable()) {
      $this->data = $this->parseProperties();
      $this->properties_file_exists = true;
    } else {
      $this->properties_file_exists = false;
    }
  }

  private function initProperties() {
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
   * @param $property IProperty
   */
  private function add($property) {
    $this->properties[$property->getId()] = $property;
  }

  /**
   * Parses the properties file into an associative array
   *
   * @return array
   */
  private function parseProperties() {
    $result = $lines = array();

    foreach($this->properties_file as $line) {

      if (preg_match('/([\w-]+)[\s]*:[\s]*(.*)/', $line, $matches)) {
        $key = trim($matches[1]);
        $value = trim($matches[2]);

        $result[$key] = $value;
      }
    }

    return $result;
  }
}

abstract class Property Implements IProperty{
  const TYPE_TEXT = 'textfield';
  const TYPE_RADIOS = 'radios';
  const TYPE_CHECKBOXES = 'checkboxes';
  const TYPE_SUBMIT = 'submit';
  const TYPE_MARKUP = 'markup';

  private $id;
  private $title;
  private $description;

  function __construct($id, $title, $description) {
    $this->id = $id;
    $this->title = $title;
    $this->description = $description;
  }

  public function getId() {
    return $this->id;
  }

  public function getTitle() {
    return $this->title;
  }

  public function getDescription() {
    return $this->description;
  }

  public function getExtraParameters() {
    return array();
  }
}

/**
 * Class TextProperty
 *
 * Can capture text only and provides only validation not to be empty.
 *
 * @package Esf
 */
class TextProperty Extends Property {

  public function getType() {
    return Property::TYPE_TEXT;
  }

  public function getExtraParameters() {
    return array('#size' => 20);
  }

  public static function validate($element, &$form_state) {
    if (empty($element['#value'])) {
      form_error($element, t('The "!name" option must not be empty.',
        array('!name' => t($element['#title']))));
    }
  }
}

/**
 * Class NumberProperty
 *
 * Captures number and therefore validates the result for it.
 *
 * @package Esf
 */
class NumberProperty Extends TextProperty {

  public static function validate($element, &$form_state) {
    parent::validate($element, $form_state);

    if (!is_numeric($element['#value'])) {
      form_error($element, t('The "!name" option must be a number.',
        array('!name' => t($element['#title']))));
    }
  }

  public function getExtraParameters() {
    return array('#size' => 10);
  }
}

/**
 * Class RadioProperty
 *
 * Displays options to be chosen from. Those options are captured from the
 * constructor.
 *
 * @package Esf
 */
class RadioProperty Extends Property {
  private $options;

  /**
   * @param $id string
   * @param $title string
   * @param $description string
   * @param $options array
   */
  function __construct($id, $title, $description, $options) {
    parent::__construct($id, $title, $description);
    $this->options = array();

    foreach ($options as $option) {
      $this->options[strtolower($option)] = t($option);
    }
  }

  public function getType() {
    return Property::TYPE_RADIOS;
  }

  public function getExtraParameters() {
    return array(
      '#options' => $this->options
    );
  }

  public static function validate($element, &$form_state) {

  }
}