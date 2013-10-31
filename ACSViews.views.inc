<?php

function acsviews_views_data() {
	$data = [
		'accessacs_individuals' => [
			'table' => [
				'group' => t('AccessACS Individuals'),
				'base' => [
					'field' => 'IndvId',
					'title' => t('Individuals'),
					'help' => t('AccessACS Individuals'),
					'weight' => -10,
				],
			],
		],
	];

	return $data;
}