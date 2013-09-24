<?php
/**
 * @file
 * esf_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function esf_feature_user_default_roles() {
  $roles = array();

  // Exported role: moderátor.
  $roles['moderátor'] = array(
    'name' => 'moderátor',
    'weight' => 0,
  );

  // Exported role: student.
  $roles['student'] = array(
    'name' => 'student',
    'weight' => 0,
  );

  return $roles;
}
