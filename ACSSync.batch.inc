<?php
/**
 * @file
 * The ACSSync batch logic
 *
 * Interfaces with the Batch API to run the longer process.
 */


/**
 * Start batch process.
 */
function start_acssync_batch() {
  $batch = [
    'operations' => [
      ['get_initial_acssync_people', []],
      ['truncate_acssync_tables', []],
      ['process_acssync_person', []],
    ],
    'finished' => 'batch_acssync_finished',
    'title' => t('ACS Sync'),
    'init_message' => t('Starting ACS Sync.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('ACS Sync has encountered an error.'),
    'file' => drupal_get_path('module', 'ACSSync') . '/ACSSync.batch.inc',
  ];

  batch_set($batch);
}

/**
 * Gets the master list of people.
 */
function get_initial_acssync_people(&$context) {
  $context['message'] = 'Retrieving master individual list.';

  $site_number = variable_get('acs_site_number');
  $username = variable_get('acs_username');
  $password = variable_get('acs_password');

  if (empty($site_number) || empty($username) || empty($password)) {
    drupal_set_message(t('ACS auth settings not set.'), 'error');
    return;
  }

  $acs_api = new Drupal\ACSSync\API($site_number, $username, $password);

  // TODO: Get by pages.

  try {
    $people = $acs_api->get_all_people(2000);
    $context['results']['pending'] = $people->Page;
    $context['results']['done'] = [];
    $context['results']['acsapi'] = $acs_api;
    $context['finished'] = 1;
    $context['message'] = 'Master individual list retrieved.';
  }
  catch (Exception $e) {
    drupal_set_message(t('ACS API returned an error: @error', array('@error' => $e->getMessage())), 'error');
  }
}

/**
 * Delete old data.
 */
function truncate_acssync_tables(&$context) {
  $context['message'] = 'Removing old data.';

  db_truncate('accessacs_individuals')->execute();
  db_truncate('accessacs_addresses')->execute();
  db_truncate('accessacs_phone')->execute();
  db_truncate('accessacs_email')->execute();
  db_truncate('accessacs_addresses_individual')->execute();
  db_truncate('accessacs_phone_individual')->execute();
  db_truncate('accessacs_email_individual')->execute();

  $context['message'] = 'Done removing old data.';
  $context['finished'] = 1;
}


/**
 * Processes an individual person.
 */
function process_acssync_person(&$context) {
  $simple_person = array_pop($context['results']['pending']);
  $context['results']['done'][] = $simple_person;

  $context['message'] = 'Processing individual ' . (count($context['results']['done']) + 1) . ' of ' . (count($context['results']['done']) + count($context['results']['pending']));

  $individual = $context['results']['acsapi']->get_person($simple_person->IndvId);

  // var_dump($individual);
  db_insert('accessacs_individuals')
    ->fields(array(
      'IndvId' => $individual->IndvId,
      'PrimFamily' => $individual->PrimFamily,
      'MiddleName' => $individual->MiddleName,
      'Title' => $individual->Title,
      'LastName' => $individual->LastName,
      'FirstName' => $individual->FirstName,
      'PictureUrl' => $individual->PictureUrl,
      'FamilyPosition' => $simple_person->FamilyPosition,
      'Suffix' => $individual->Suffix,
      'FullName' => $individual->FullName,
      'FriendlyName' => $individual->FriendlyName,
      'FamilyPictureUrl' => $individual->FamilyPictureUrl,
      'DateOfBirth' => $individual->DateOfBirth,
      'MemberStatus' => $individual->MemberStatus,
    ))
    ->execute();

  if (is_array($individual->Addresses)) {
    foreach ($individual->Addresses as $address) {

      // Check to see if the address is already in the database.
      $res = db_select('accessacs_addresses')
        ->condition('AddrId', $address->AddrId)
        ->fields('accessacs_addresses', ['AddrId'])
        ->range(0, 1)
        ->execute()
        ->fetchField();

      // If the address doesn't exist, stick it in there.
      if ($res === FALSE) {
        db_insert('accessacs_addresses')
          ->fields(array(
            'AddrId' => $address->AddrId,
            'AddrType' => $address->AddrType,
            'MailAddress' => ($address->MailAddress) ? 1 : 0,
            'Address2' => $address->Address2,
            'City' => $address->City,
            'Address' => $address->Address,
            'Longitude' => $address->Longitude,
            'State' => $address->State,
            'ActiveAddress' => ($address->ActiveAddress) ? 1 : 0,
            'Zipcode' => $address->Zipcode,
            'FamilyAddress' => ($address->FamilyAddress) ? 1 : 0,
            'Country' => $address->Country,
            'Company' => $address->Company,
            'StatementAddress' => ($address->StatementAddress) ? 1 : 0,
            'Latitude' => $address->Latitude,
            'CityStateZip' => $address->CityStateZip,
            'AddrTypeId' => $address->AddrTypeId,
          ))
          ->execute();
      }

      // Add to join table.
      db_insert('accessacs_addresses_individual')
        ->fields(array(
          'IndvId' => $individual->IndvId,
          'AddrId' => $address->AddrId,
        ))
        ->execute();
    }
  }
  else {
    watchdog('ACSSync', 'Individual  of ID @id has a invalid Address array.', array('@id' => $individual->IndvId), WATCHDOG_WARNING);
  }

  if (is_array($individual->Phones)) {
    foreach ($individual->Phones as $phone) {

      // Check to see if the phone number is already in the database.
      $res = db_select('accessacs_phone')
        ->condition('PhoneId', $phone->PhoneId)
        ->fields('accessacs_phone', ['PhoneId'])
        ->range(0, 1)
        ->execute()
        ->fetchField();

      // If the phone number doesn't exist, stick it in there.
      if ($res === FALSE) {
        db_insert('accessacs_phone')
          ->fields(array(
            'PhoneId' => $phone->PhoneId,
            'PhoneTypeId' => $phone->PhoneTypeId,
            'PhoneRef' => $phone->PhoneRef,
            'Listed' => ($phone->Listed) ? 1 : 0,
            'PhoneNumber' => $phone->PhoneNumber,
            'Preferred' => ($phone->Preferred) ? 1 : 0,
            'FamilyPhone' => ($phone->FamilyPhone) ? 1 : 0,
            'AddrPhone' => ($phone->AddrPhone) ? 1 : 0,
            'Extension' => $phone->Extension,
            'PhoneType' => $phone->PhoneType,
          ))
          ->execute();
      }

      // Add to join table.
      db_insert('accessacs_phone_individual')
        ->fields(array(
          'IndvId' => $individual->IndvId,
          'PhoneId' => $phone->PhoneId,
        ))
        ->execute();
    }
  }
  else {
    watchdog('ACSSync', 'Individual  of ID @id has a invalid Phone Number array.', array('@id' => $individual->IndvId), WATCHDOG_WARNING);
  }

  if (is_array($individual->Emails)) {
    foreach ($individual->Emails as $email) {

      // Check to see if the email address is already in the database.
      $res = db_select('accessacs_email')
        ->condition('EmailId', $phone->EmailId)
        ->fields('accessacs_email', ['EmailId'])
        ->range(0, 1)
        ->execute()
        ->fetchField();

      // If the email address doesn't exist, stick it in there.
      if ($res === FALSE) {
        db_insert('accessacs_email')
          ->fields(array(
            'EmailId' => $email->EmailId,
            'Listed' => ($email->Listed) ? 1 : 0,
            'Preferred' => ($email->Preferred) ? 1 : 0,
            'EmailType' => $email->EmailType,
            'Email' => $email->Email,
          ))
          ->execute();
      }

      // Add to join table.
      db_insert('accessacs_email_individual')
        ->fields(array(
          'IndvId' => $individual->IndvId,
          'EmailId' => $email->EmailId,
        ))
        ->execute();
    }
  }
  else {
    watchdog('ACSSync', 'Individual  of ID @id has a invalid Email Address array.', array('@id' => $individual->IndvId), WATCHDOG_WARNING);
  }

  $context['finished'] = count($context['results']['done']) / (count($context['results']['done']) + count($context['results']['pending']));
}


/**
 * Batch 'finished' callback.
 * @todo Rewrite this method.
 */
function batch_acssync_finished($success, $results, $operations) {
  if ($success) {
    // Here we do something meaningful with the results.
    $message = count($results['done']) . ' individuals processed.';
    drupal_set_message($message);
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE)
    ));
    drupal_set_message($message, 'error');
  }
}
