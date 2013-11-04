<?php

/**
 * Implements hook_preprocess_html().
 */
function omega_esf_preprocess_html(&$variables) {
  
  if (arg(0) == 'aspi' && arg(1) == 'remote') {
    //key-words
    $page_keywords = array(
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'viewport',
        'content' => 'width=device-width, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0, user-scalable=no, target-densitydpi=device-dpi',
      )
    );
    
    drupal_add_html_head($page_keywords, 'page_keywords');
  }
}
