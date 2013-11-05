<?php

/**
 * @file
 * Guacamole properties file related classes
 */

namespace Esf;

/**
 * Class PropertiesFactory
 * @package Esf
 */
class PropertiesFactory {
  /**
   * Builds the \Esf\Properties object.
   *
   * Object needs filename passed into it's constructor. In our case that is
   * a properties file and we load it's filename from the variables.
   *
   * For list of all the properties see define statements:
   * @see esf_module.inc
   *
   * @return Properties
   *   Newly created \Esf\Properties object.
   */
  public static function build() {
    return (new Properties(new \SplFileObject(variable_get(ESF_MODULE_GUACAMOLE_HOME) . variable_get(ESF_MODULE_GUACAMOLE_PROPERTIES_FILE), 'r+')));
  }
}

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
   * @var \Esf\PropertyInterface[]
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
   * @param PropertyInterface $property
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
   * @param PropertyInterface $property
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

abstract class Property implements PropertyInterface {
  const TYPE_TEXT = 'textfield';
  const TYPE_RADIOS = 'radios';
  const TYPE_CHECKBOXES = 'checkboxes';
  const TYPE_SUBMIT = 'submit';
  const TYPE_MARKUP = 'markup';

  protected  $id;
  protected $title;
  protected $description;

  /**
   * Creates a new Property object with typical parameters.
   *
   * @param string $id
   *   id of the property
   * @param string $title
   *   title to be displayed on the configuration page
   * @param string $description
   *   description to be displayed on the configuration page
   */
  public function __construct($id, $title, $description) {
    $this->id = $id;
    $this->title = $title;
    $this->description = $description;
  }

  /**
   * {@inheritdoc}
   */
  public function getId() {
    return $this->id;
  }

  /**
   * {@inheritdoc}
   */
  public function getTitle() {
    return $this->title;
  }

  /**
   * {@inheritdoc}
   */
  public function getDescription() {
    return $this->description;
  }

  /**
   * {@inheritdoc}
   */
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

/**
 * Class NumberProperty
 *
 * Captures number and therefore validates the result for it.
 *
 * @package Esf
 */
class NumberProperty extends TextProperty {

  /**
   * {@inheritdoc}
   */
  public static function validate($element, &$form_state) {
    parent::validate($element, $form_state);

    if (!is_numeric($element['#value'])) {
      form_error($element, t('The "!name" option must be a number.',
        array('!name' => t($element['#title']))));
    }
  }

  /**
   * {@inheritdoc}
   */
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
class RadioProperty extends Property {
  protected $options;

  /**
   * Builds the object with options.
   *
   * Parent is created in the same way, but options for the
   * radio buttons are included in this constructor.
   *
   * @param string $id
   *   id of the property
   * @param string $title
   *   title of the property
   * @param string $description
   *   description of the property
   * @param array $options
   *   options defining the values of the radio buttons
   */
  public function __construct($id, $title, $description, $options) {
    parent::__construct($id, $title, $description);
    $this->options = array();

    foreach ($options as $option) {
      $this->options[strtolower($option)] = t($option);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getType() {
    return Property::TYPE_RADIOS;
  }

  /**
   * {@inheritdoc}
   */
  public function getExtraParameters() {
    return array(
      '#options' => $this->options,
    );
  }

  /**
   * {@inheritdoc}
   */
  public static function validate($element, &$form_state) {

  }
}
