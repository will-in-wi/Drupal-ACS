<?php

function acsviews_views_data() {
	return [
		'accessacs_individuals' => [
			'table' => [
				'group' => t('AccessACS Individuals'),
				'base' => [
					'field' => 'IndvId',
					'title' => t('AccessACS Individuals'),
					'help' => t('AccessACS Individuals'),
					'weight' => -10,
				],
			],
			'IndvId' => [
				'title' => t('IndvId'),
				'help' => t('IndvId'),
				'field' => [
					'handler' => 'views_handler_field_numeric',
					'click sortable' => true,
				],
				'filter' => [
					'handler' => 'views_handler_filter_numeric',
				],
				'sort' => [
					'handler' => 'views_handler_sort',
				],
			],
			'FamId' => [
				'title' => t('FamId'),
				'help' => t('FamId'),
				'field' => [
					'handler' => 'views_handler_field_numeric',
					'click sortable' => true,
				],
				'filter' => [
					'handler' => 'views_handler_filter_numeric',
				],
				'sort' => [
					'handler' => 'views_handler_sort',
				],
			],
			'MiddleName' => [
				'title' => t('MiddleName'),
				'help' => t('MiddleName'),
				'field' => [
					'handler' => 'views_handler_field',
					'click sortable' => true,
				],
				'filter' => [
					'handler' => 'views_handler_filter_string',
				],
				'sort' => [
					'handler' => 'views_handler_sort',
				],
				'argument' => [
					'handler' => 'views_handler_argument_string',
				],
			],
			'GoesByName' => [
				'title' => t('GoesByName'),
				'help' => t('GoesByName'),
				'field' => [
					'handler' => 'views_handler_field',
					'click sortable' => true,
				],
				'filter' => [
					'handler' => 'views_handler_filter_string',
				],
				'sort' => [
					'handler' => 'views_handler_sort',
				],
				'argument' => [
					'handler' => 'views_handler_argument_string',
				],
			],
			'Title' => [
				'title' => t('Title'),
				'help' => t('Title'),
				'field' => [
					'handler' => 'views_handler_field',
					'click sortable' => true,
				],
				'filter' => [
					'handler' => 'views_handler_filter_string',
				],
				'sort' => [
					'handler' => 'views_handler_sort',
				],
				'argument' => [
					'handler' => 'views_handler_argument_string',
				],
			],
			'LastName' => [
				'title' => t('LastName'),
				'help' => t('LastName'),
				'field' => [
					'handler' => 'views_handler_field',
					'click sortable' => true,
				],
				'filter' => [
					'handler' => 'views_handler_filter_string',
				],
				'sort' => [
					'handler' => 'views_handler_sort',
				],
				'argument' => [
					'handler' => 'views_handler_argument_string',
				],
			],
			'FirstName' => [
				'title' => t('FirstName'),
				'help' => t('FirstName'),
				'field' => [
					'handler' => 'views_handler_field',
					'click sortable' => true,
				],
				'filter' => [
					'handler' => 'views_handler_filter_string',
				],
				'sort' => [
					'handler' => 'views_handler_sort',
				],
				'argument' => [
					'handler' => 'views_handler_argument_string',
				],
			],
			'PictureUrl' => [
				'title' => t('PictureUrl'),
				'help' => t('PictureUrl'),
				'field' => [
					'handler' => 'views_handler_field',
					'click sortable' => true,
				],
				'filter' => [
					'handler' => 'views_handler_filter_string',
				],
				'sort' => [
					'handler' => 'views_handler_sort',
				],
				'argument' => [
					'handler' => 'views_handler_argument_string',
				],
			],
			'FamilyPosition' => [
				'title' => t('FamilyPosition'),
				'help' => t('FamilyPosition'),
				'field' => [
					'handler' => 'views_handler_field',
					'click sortable' => true,
				],
				'filter' => [
					'handler' => 'views_handler_filter_string',
				],
				'sort' => [
					'handler' => 'views_handler_sort',
				],
				'argument' => [
					'handler' => 'views_handler_argument_string',
				],
			],
			'Suffix' => [
				'title' => t('Suffix'),
				'help' => t('Suffix'),
				'field' => [
					'handler' => 'views_handler_field',
					'click sortable' => true,
				],
				'filter' => [
					'handler' => 'views_handler_filter_string',
				],
				'sort' => [
					'handler' => 'views_handler_sort',
				],
				'argument' => [
					'handler' => 'views_handler_argument_string',
				],
			],
		],
	];
}