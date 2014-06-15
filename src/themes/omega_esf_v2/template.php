<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * Omega ESF v2 theme.
 */

function omega_esf_v2_theme() {
  $items = array();
  $items['user_login'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'omega_esf_v2') . '/templates/user',
    'template' => 'user-login',
    'preprocess functions' => array(
      'omega_esf_v2_preprocess_user_login'
    ),
  );
  return $items;
}

function omega_esf_v2_preprocess_user_login(&$vars) {
  $vars['intro_text'] = "Pro přístup k portálu se prosím přihlaste.";

  $vars['form']['name']['#description'] = 'Zadejte své unikátní číslo (UČO).';
  $vars['form']['pass']['#description'] = 'Zadejte své sekundární heslo MU.';
}