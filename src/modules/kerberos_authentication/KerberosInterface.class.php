<?php
/**
 * @file
 * KerberosInterface class definition.
 */
/**
 * KerberosInterface Class
 */
class KerberosInterface {
  const KRB5_CONF = '/etc/krb5.conf';
  private $realm; //Realm Name
  private $credential_cache;

  /**
   * @param $realm_name string Realm to use in this KerberosInterface
   */
  public function __construct($realm_name) {
    $this->realm = $realm_name;
  }

  /**
   * Set realm for this KerberosInterface
   *
   * @param $realm string Realm to use
   */
  public function setRealm($realm) {
    $this->realm = $realm;
  }

  /**
   * Get realm that this KerberosInterface uses
   * @return string Realm that this KerberosInterface uses
   */
  public function getRealm() {
    return $this->realm;
  }

  /**
   * Get all Kerberos tickets for a principal/password combination
   *
   * @param  $principal string Principle for which to get tickets
   * @param  $password  string Password to use to authenticate the principal
   *
   * @return array tickets for the principal

   */
  public function getTickets($principal, $password) {
    $this->credential_cache = new KRB5CCache();
    //$this->credential_cache->setConfig(self::KRB5_CONF); //default config for kerberos
    if ( strpos('@', $principal) === FALSE ) { //Add realm if it's not already part of principal
      $principal = $principal . '@' . $this->realm;
    }
    $this->credential_cache->initPassword($principal, $password);
    $entries = $this->credential_cache->getEntries(); //returns the same as running `klist`
    return $entries;
  }

  /**
   * Check if a principal/password combination is valid
   *
   * @param  $principal string Principle for which to get tickets
   * @param  $password  string Password to use to authenticate the principal
   *
   * @return boolean TRUE if valid principal, FALSE on failure
   */
  public function checkPrinciple($principal, $password) {
    $tickets = $this->getTickets($principal, $password);
    if ( !empty( $tickets ) ) {
      return TRUE;
    }
    return FALSE;
  }

}