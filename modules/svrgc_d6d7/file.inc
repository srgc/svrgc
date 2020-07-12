<?php

/**
 * Common mappings for the Drupal 6 file migrations.
 */


class svrgcd6d7FileMigration extends DrupalFile6Migration
{
  public function __construct(array $arguments)
  {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    if (preg_match('/members|private/', $arguments['source_dir'])) {
      $arguments['destination_dir'] = 'private://';
      variable_set('jbickar_destinationdir', $arguments['destination_dir']);
    }
//    echo '<pre>';
    variable_set('jbickar_sourcedir', $arguments['source_dir']);
//    echo '</pre>';

    parent::__construct($arguments);
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
//    echo '<pre>';
//    var_dump($row);
//    exit;
//    echo '</pre>';
    $filepath = $row->filepath;
    if (preg_match('/private|members/', $filepath)) {
      $row->destination_dir = "private://";
      variable_set('jbickar_preparerow', $row);
    }
  }
}
