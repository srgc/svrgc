<?php

/**
 * Mappings for the Drupal 6 Field Collection migration.
 */
abstract class SVRGCD6D7FieldCollectionMigration extends MigrateDestinationFieldCollection {
  public function __construct(array $arguments) {
    $this->sourceFields['field_photo_photo'] = 'Photo';

    parent::__construct($arguments);

    $this->addFieldMapping('field_s_image_image', 'field_photo_photo');
    $this->addFieldMapping('field_s_image_image:alt', 'field_photo_photo:alt');
    $this->addFieldMapping('host_entity_id', 'source_photo_id')
      ->sourceMigration('Photo');

  }
}
