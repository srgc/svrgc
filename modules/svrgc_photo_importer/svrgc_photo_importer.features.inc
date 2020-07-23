<?php

/**
 * @file
 * svrgc_photo_importer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function svrgc_photo_importer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
