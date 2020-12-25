<?php

/**
 * @file
 * svrgc_contact_categories.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function svrgc_contact_categories_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
