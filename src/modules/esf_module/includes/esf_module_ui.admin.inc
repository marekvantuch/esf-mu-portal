<?php

module_load_include('inc', 'esf_module', 'includes/esf_module.properties');

use Esf\PropertiesFactory;

/**
 * Page callback for the remote configuration page.
 *
 * This uses the Drupal Forms API.
 *
 * @param array $form
 *   form array from Forms API
 * @param array $form_state
 *   form_state array from Forms API
 *
 * @return array
 *   Form API array to be rendered by Drupal
 */
function esf_module_ui_remote($form, &$form_state) {
  return PropertiesFactory::build()->buildForm();
}

/**
 * Submit function for the remote page.
 *
 * @see esf_module_ui_remote()
 *
 * @param array $form
 *   form array from Forms API
 * @param array $form_state
 *   form_state array from Forms API
 */
function esf_module_ui_remote_submit($form, &$form_state) {
  PropertiesFactory::build()->submitForm($form_state);
}
