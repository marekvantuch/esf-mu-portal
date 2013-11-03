<?php

module_load_include('inc', 'esf_module', 'includes/esf_module.properties');

use Esf\PropertiesFactory;

function esf_module_ui_remote($form, &$form_state) {
  return PropertiesFactory::build()->buildForm();
}

function esf_module_ui_remote_submit($form, &$form_state) {
  PropertiesFactory::build()->submitForm($form_state);
}
