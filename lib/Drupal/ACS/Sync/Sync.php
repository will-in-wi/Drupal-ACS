<?php

namespace Drupal\drupal_acs\Sync;

/**
* ACS Sync Functions
*/
class Sync
{
	protected $site_number;
	protected $username;
	protected $password;

	function __construct($site_number, $username, $password) {
		$this->site_number = $site_number;
		$this->username = $username;
		$this->password = $password;
	}

	public function api_call($params = array())
	{
		$headers = [
			'Authorization' => 'Basic ' . base64_encode($this->username . ':' . $this->password),
		];

		// Get the first page of results.
		$result = drupal_http_request('https://secure.accessacs.com/api_accessacs_mobile/v2/' . $this->site_number . '/individuals?' . http_build_query($params), [
			'headers' => $headers,
		]);

		if ($result->code != 200) {
			throw new Exception('ACS API returned an error ' . $result->code);
			return;
		}

		return $result->data;
	}
}