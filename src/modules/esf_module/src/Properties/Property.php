<?php
/**
 * Created by PhpStorm.
 * User: Marek Vantuch
 * Date: 11/23/2014
 * Time: 9:11 PM
 */
namespace Drupal\esf_module\Properties;

use Drupal\esf_module\Interfaces\PropertyInterface;

abstract class Property implements PropertyInterface {
  const TYPE_TEXT = 'textfield';
  const TYPE_RADIOS = 'radios';
  const TYPE_CHECKBOXES = 'checkboxes';
  const TYPE_SUBMIT = 'submit';
  const TYPE_MARKUP = 'markup';

  protected $id;
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