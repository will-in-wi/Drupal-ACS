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
    'accessacs_addresses' => [
      'table' => [
        'group' => t('AccessACS Individuals'),
        'base' => [
          'field' => 'AddrId',
          'title' => t('AccessACS Addresses'),
          'help' => t('AccessACS Addresses'),
          'weight' => -10,
        ],
      ],
      'AddrId' => [
        'title' => t('AddrId'),
        'help' => t('AddrId'),
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
      'AddrType' => [
        'title' => t('AddrType'),
        'help' => t('AddrType'),
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
      'MailAddress' => [
        'title' => t('MailAddress'),
        'help' => t('MailAddress'),
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
      'Address2' => [
        'title' => t('Address2'),
        'help' => t('Address2'),
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
      'City' => [
        'title' => t('City'),
        'help' => t('City'),
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
      'Address' => [
        'title' => t('Address'),
        'help' => t('Address'),
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
      'Longitude' => [
        'title' => t('Longitude'),
        'help' => t('Longitude'),
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
      'State' => [
        'title' => t('State'),
        'help' => t('State'),
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
      'ActiveAddress' => [
        'title' => t('ActiveAddress'),
        'help' => t('ActiveAddress'),
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
      'Zipcode' => [
        'title' => t('Zipcode'),
        'help' => t('Zipcode'),
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
      'FamilyAddress' => [
        'title' => t('FamilyAddress'),
        'help' => t('FamilyAddress'),
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
      'Country' => [
        'title' => t('Country'),
        'help' => t('Country'),
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
      'Company' => [
        'title' => t('Company'),
        'help' => t('Company'),
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
      'StatementAddress' => [
        'title' => t('StatementAddress'),
        'help' => t('StatementAddress'),
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
      'Latitude' => [
        'title' => t('Latitude'),
        'help' => t('Latitude'),
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
      'CityStateZip' => [
        'title' => t('CityStateZip'),
        'help' => t('CityStateZip'),
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
      'AddrTypeId' => [
        'title' => t('AddrTypeId'),
        'help' => t('AddrTypeId'),
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
    'accessacs_addresses_individual' => [
      'table' => [
        'group' => t('AccessACS Individuals'),
        'base' => [
          'field' => 'AddrId',
          'title' => t('AccessACS Addresses'),
          'help' => t('AccessACS Addresses'),
          'weight' => -10,
        ],
      ],
      'AddrId' => [
        'title' => t('AddrId'),
        'help' => t('AddrId'),
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
