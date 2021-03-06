<?php

/**
 * Common mappings for the Drupal 6 user migrations.
 */
class svrgcd6d7UserMigration extends DrupalUser6Migration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    $this->sourceFields['field_profile_fullname'] = 'Full Name';
    $this->sourceFields['field_profile_firstname'] = 'First Name';
    $this->sourceFields['field_profile_lastname'] = 'Last Name';
    $this->sourceFields['field_profile_membership_type'] = 'Membership Type';
    $this->sourceFields['field_profile_phone'] = 'Phone Number';
    parent::__construct($arguments);
    $this->addFieldMapping('roles', 'roles')
      ->sourceMigration('Roles');
    $this->addFieldMapping('is_new')->defaultValue('TRUE');
    // Keep the same UID's
	  $this->addFieldMapping('uid', 'uid');
    $this->addFieldMapping('field_user_first_name', 'field_profile_firstname');
    $this->addFieldMapping('field_user_last_name', 'field_profile_lastname');
    $this->addFieldMapping('field_user_membership_type', 'field_profile_membership_type');
    $this->addFieldMapping('field_user_phone_number', 'field_profile_phone');
  }

}
