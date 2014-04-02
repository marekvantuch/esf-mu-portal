<?php
/**
 * @file
 * esf_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function esf_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-footer-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-footer-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'omega_esf_v2' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'omega_esf_v2',
        'weight' => -9,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['quicktabs-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'navigation',
    'module' => 'quicktabs',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'authenticated user' => 2,
      'moderator' => 3,
    ),
    'themes' => array(
      'omega_esf_v2' => array(
        'region' => 'sidebar',
        'status' => 1,
        'theme' => 'omega_esf_v2',
        'weight' => -15,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['system-main'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'omega_esf_v2' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'omega_esf_v2',
        'weight' => -15,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'omega_esf_v2' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_esf_v2',
        'weight' => -15,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-management'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'management',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'omega_esf_v2' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_esf_v2',
        'weight' => -11,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-navigation'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'navigation',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'omega_esf_v2' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_esf_v2',
        'weight' => -10,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-powered-by'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'powered-by',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'omega_esf_v2' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_esf_v2',
        'weight' => -17,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-user-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'user-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'omega_esf_v2' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'omega_esf_v2',
        'weight' => -13,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'omega_esf_v2' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_esf_v2',
        'weight' => 4,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-jokes-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'jokes-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'omega_esf_v2' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'omega_esf_v2',
        'weight' => -15,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['views-news-block'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'news-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'omega_esf_v2' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega_esf_v2',
        'weight' => -9,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
