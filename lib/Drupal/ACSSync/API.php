<?php

namespace Drupal\ACSSync;

/**
* ACS API Functions
*/
class API {
	protected $site_number;
	protected $username;
	protected $password;

	function __construct($site_number, $username, $password) {
		$this->site_number = $site_number;
		$this->username = $username;
		$this->password = $password;
	}

	public function api_call($endpoint, $params = array()) {
		$headers = [
			'Authorization' => 'Basic ' . base64_encode($this->username . ':' . $this->password),
		];

		// Get the first page of results.
		$result = drupal_http_request('https://secure.accessacs.com/api_accessacs_mobile/v2/' . $this->site_number . '/' . $endpoint . '?' . http_build_query($params), [
			'headers' => $headers,
		]);

		if ($result->code != 200) {
			throw new \Exception('ACS API returned an error ' . $result->code);
			return;
		}

		return json_decode($result->data);
	}

	public function get_people($query, $limit=10, $page=1) {
		return $this->api_call('individuals', [
			'q' => $query,
			'pageSize' => $limit,
			'pageIndex' => $page-1, // 0 indexed.
		]);
	}

	public function get_all_people($limit=10, $page=1) {
		return $this->get_people('%', $limit, $page);
	}

	public function get_person($id) {
		return $this->api_call('individuals/' . $id);
	}

	public function check_credentials() {
		try {
			$res = $this->get_all_people(2,1);
			if (isset($res->Page[0])) {
				return TRUE;
			} else {
				return FALSE;
			}
		} catch (Exception $e) {
			return FALSE;
		}
	}
}