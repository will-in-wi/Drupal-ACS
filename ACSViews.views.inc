<?php
/**
 * @file
 * The ACS views integration.
 */

/**
 * Implements hook_views_data().
 */
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
        'title' => t('Individual ID'),
        'help' => t('Individual ID'),
        'field' => [
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ],
        'filter' => [
          'handler' => 'views_handler_filter_numeric',
        ],
        'sort' => [
          'handler' => 'views_handler_sort',
        ],
      ],
      'FamId' => [
        'title' => t('Family ID'),
        'help' => t('Family ID'),
        'field' => [
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ],
        'filter' => [
          'handler' => 'views_handler_filter_numeric',
        ],
        'sort' => [
          'handler' => 'views_handler_sort',
        ],
      ],
      'MiddleName' => [
        'title' => t('Middle Name'),
        'help' => t('Middle Name'),
        'field' => [
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
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
        'title' => t('Goes By Name'),
        'help' => t('Goes By Name'),
        'field' => [
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
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
          'click sortable' => TRUE,
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
        'title' => t('Last Name'),
        'help' => t('Last Name'),
        'field' => [
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
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
        'title' => t('First Name'),
        'help' => t('First Name'),
        'field' => [
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
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
        'title' => t('Picture URL'),
        'help' => t('Picture URL'),
        'field' => [
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
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
        'title' => t('Family Position'),
        'help' => t('Family Position'),
        'field' => [
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
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
          'click sortable' => TRUE,
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
