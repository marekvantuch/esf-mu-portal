<?php
  /**
   * @file
   * Module admin page callbacks.
   */
  /**
   * Implements the settings page.
   * @return
   *   The form structure.
   */
  function kerberos_authentication_admin_settings() {
    $options_login_process = array(
      KERBEROS_AUTHENTICATION_AUTH_MIXED     => t('Mixed mode.  Kerberos authentication is performed only if Drupal authentication fails'),
      KERBEROS_AUTHENTICATION_AUTH_EXCLUSIVE => t('Kerberos Authentication only')
    );
    $options_login_conflict = array(
      KERBEROS_AUTHENTICATION_CONFLICT_LOG     => t('Disallow login and log the conflict'),
      KERBEROS_AUTHENTICATION_CONFLICT_RESOLVE => t('Associate local account with the Kerberos principal')
    );
    $form['system-options'] = array(
      '#type'        => 'fieldset',
      '#title'       => t('Authentication mode'),
      '#description' => t('<strong>NOTE:</strong> These settings have no effect on Drupal user with uid 1. The admin account never uses Kerberos.'),
      '#collapsible' => TRUE,
      '#collapsed'   => FALSE,
    );
    $form['system-options']['kerberos_authentication_login_process'] = array(
      '#type'          => 'radios',
      '#title'         => t('Choose authentication mode'),
      '#description'   => t('Pick the mode based on the types of user accounts and other configuration decisions. If <i>Kerberos only</i> option is activated some UI modifications will be applied.'),
      '#default_value' => variable_get('kerberos_authentication_login_process', KERBEROS_AUTHENTICATION_AUTH_MIXED),
      '#options'       => $options_login_process,
      '#required'      => TRUE,
    );
    $form['system-options']['kerberos_authentication_login_conflict'] = array(
      '#type'          => 'radios',
      '#title'         => t('Choose user conflict resolve procedure'),
      '#description'   => t('Pick what should be done if the local Drupal account already exists with the same login name.'),
      '#default_value' => variable_get('kerberos_authentication_login_conflict', KERBEROS_AUTHENTICATION_CONFLICT_LOG),
      '#options'       => $options_login_conflict,
      '#required'      => TRUE,
    );
    $form['system-options']['kerberos_authentication_default_role'] = array(
      '#type'          => 'select',
      '#title'         => t('Default role for new accounts'),
      '#description'   => t('The role that new users should be placed in on first login.'),
      '#default_value' => variable_get('kerberos_authentication_default_role', ''),
      '#options'       => user_roles(TRUE),
      '#required'      => TRUE,
    );
    $form['realms'] = array(
      '#type'        => 'fieldset',
      '#title'       => t('Realm Configuration'),
      '#collapsible' => TRUE,
      '#collapsed'   => FALSE,
    );
    $form['realms']['kerberos_authentication_realms'] = array(
      '#type'          => 'textarea',
      '#title'         => t('Kerberos Realm(s)'),
      '#default_value' => implode('', variable_get('kerberos_authentication_realms', array())),
      '#description'   => t('List kerberos realms to attempt to authenticate against, one per line.'),
    );
    $form['security-options'] = array(
      '#type'        => 'fieldset',
      '#title'       => t('Security Options'),
      '#collapsible' => TRUE,
      '#collapsed'   => TRUE,
    );
    $form['security-options']['kerberos_authentication_sync_passwords'] = array(
      '#type'          => 'checkbox',
      '#title'         => t('Sync Kerberos password with the Drupal password'),
      '#default_value' => variable_get('kerberos_authentication_sync_passwords', FALSE),
      '#description'   => t('If checked, Kerberos passwords will be saved in the Drupal database.<br />
      This might be useful if some other modules need to authenticate against the user password hash stored in Drupal.  It only works in Mixed mode.<br /><br />
      <em>This setting might introduce security issues when using Mixed mode.<br />
      After deletion of a Kerberos principal the user would still be able to login to the Drupal site with their password, until their Drupal account was deleted.</em><br /><br />
      <strong>If you\'re unsure if you need this, leave it unchecked.</strong>'),
    );
    $form['submit'] = array(
      '#type'  => 'submit',
      '#value' => t('Save configuration'),
    );
    $form['reset'] = array(
      '#type'  => 'submit',
      '#value' => t('Reset to defaults'),
    );
    return $form;
  }

  /**
   * Submit hook for the settings form.
   */
  function kerberos_authentication_admin_settings_submit($form, &$form_state) {
    $op = $form_state['clicked_button']['#value'];
    $values = $form_state['values'];
    switch ( $op ) {
      case t('Save configuration'):
        variable_set('kerberos_authentication_login_process', $values['kerberos_authentication_login_process']);
        variable_set('kerberos_authentication_login_conflict', $values['kerberos_authentication_login_conflict']);
        variable_set('kerberos_authentication_sync_passwords', $values['kerberos_authentication_sync_passwords']);
        variable_set('kerberos_authentication_default_role', $values['kerberos_authentication_default_role']);
        $realms = empty( $values['kerberos_authentication_realms'] ) ? array() : explode('<br />', nl2br($values['kerberos_authentication_realms']));
        variable_set('kerberos_authentication_realms', $realms);
        drupal_set_message(t('The configuration options have been saved.'));
        break;
      case t('Reset to defaults'):
        variable_del('kerberos_authentication_login_process');
        variable_del('kerberos_authentication_login_conflict');
        variable_del('kerberos_authentication_sync_passwords');
        variable_del('kerberos_authentication_default_role');
        variable_del('kerberos_authentication_realms');
        drupal_set_message(t('The configuration options have been reset to their default values.'));
        break;
    }
  }

