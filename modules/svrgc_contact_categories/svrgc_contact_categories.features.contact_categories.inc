<?php

/**
 * @file
 * svrgc_contact_categories.features.contact_categories.inc
 */

/**
 * Implements hook_contact_categories_defaults().
 */
function svrgc_contact_categories_contact_categories_defaults() {
  return array(
    'General Questions' => array(
      'category' => 'General Questions',
      'recipients' => 'webmaster@sunnyvalegunclub.com',
      'reply' => '',
      'weight' => -10,
      'selected' => 1,
    ),
    'Membership' => array(
      'category' => 'Membership',
      'recipients' => 'webmaster@sunnyvalegunclub.com',
      'reply' => '',
      'weight' => 0,
      'selected' => 0,
    ),
    'Website Questions' => array(
      'category' => 'Website Questions',
      'recipients' => 'webmaster@sunnyvalegunclub.com',
      'reply' => '',
      'weight' => 10,
      'selected' => 0,
    ),
  );
}
