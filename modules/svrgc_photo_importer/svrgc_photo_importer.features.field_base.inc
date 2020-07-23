<?php

/**
 * @file
 * svrgc_photo_importer.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function svrgc_photo_importer_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_s_slide_gallery'.
  $field_bases['field_s_slide_gallery'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_s_slide_gallery',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'gallery',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
