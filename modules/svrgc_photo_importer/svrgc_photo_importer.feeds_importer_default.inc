<?php

/**
 * @file
 * svrgc_photo_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function svrgc_photo_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'svrgc_photo_importer';
  $feeds_importer->config = array(
    'name' => 'SRGC Photo Importer',
    'description' => 'Import photos from https://www.sunnyvalegunclub.com/club/photos',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
        'cache_http_result' => TRUE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'Nid',
          'xpathparser:1' => 'title',
          'xpathparser:2' => 'PhotoAltText',
          'xpathparser:3' => 'PhotoTitleText',
          'xpathparser:4' => 'Photo',
          'xpathparser:5' => 'AllTaxonomyTerms',
        ),
        'rawXML' => array(
          'xpathparser:2' => 'xpathparser:2',
          'xpathparser:3' => 'xpathparser:3',
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
        ),
        'context' => '//xml/node',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_s_image_info:field_s_image_image:alt',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_s_image_info:field_s_image_image:title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_s_image_info:field_s_image_image:uri',
            'file_exists' => '3',
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'field_s_slide_gallery',
            'term_search' => '0',
            'autocreate' => 1,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'unpublish',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'stanford_slide',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['svrgc_photo_importer'] = $feeds_importer;

  return $export;
}
