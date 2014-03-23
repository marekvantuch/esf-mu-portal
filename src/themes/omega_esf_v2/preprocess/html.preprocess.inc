<?php

/**
 * Implements hook_preprocess_html().
 */
function omega_esf_v2_preprocess_html(&$variables) {

  if (arg(0) == 'aspi') {
    // Set key-words for Guacamole.
    $page_keywords = array(
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'viewport',
        'content' => 'width=device-width, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0, user-scalable=no, target-densitydpi=device-dpi',
      ),
    );

    // Remove the admin menu & navbar from the guacamole page.
    if (isset($variables['page']['page_bottom']['admin_menu'])) {
      unset($variables['page']['page_bottom']['admin_menu']);
    }

    if (isset($variables['page']['page_top']['navbar'])) {
      unset($variables['page']['page_top']['navbar']);
    }

    drupal_add_html_head($page_keywords, 'page_keywords');
  }
}
