<?php

/**
 * @file
 * svrgc_photo_importer.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function svrgc_photo_importer_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-stanford_slide-field_s_slide_gallery'.
  $field_instances['node-stanford_slide-field_s_slide_gallery'] = array(
    'bundle' => 'stanford_slide',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 9,
      ),
      'stanford_8_col_banner' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_s_slide_gallery',
    'label' => 'Gallery',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 13,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Gallery');

  return $field_instances;
}
