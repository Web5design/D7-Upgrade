<?php
/**
 * @file
 * cdt_news_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cdt_news_view_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'news_events';
  $view->description = '';
  $view->tag = 'News & Events Tab';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'News & Events';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 5;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'title',
    'type' => 'title',
    'field_blog_author' => 'field_blog_author',
    'field_author' => 'field_blog_author',
    'field_issues' => 'field_issues',
    'field_date' => 'field_date',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' <br/>',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_blog_author' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_author' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_issues' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'text';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['empty'] = TRUE;
  $handler->display->display_options['header']['text']['content'] = 'Follow the latest CDT news with Press Releases, Events, and where we\'ve been featured around the Internet.';
  $handler->display->display_options['header']['text']['format'] = '2';
  $handler->display->display_options['header']['text']['tokenize'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['empty'] = FALSE;
  $handler->display->display_options['empty']['text']['content'] = '<div class="view-content"></div>';
  $handler->display->display_options['empty']['text']['format'] = '2';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['teaser']['id'] = 'teaser';
  $handler->display->display_options['fields']['teaser']['table'] = 'node_revision';
  $handler->display->display_options['fields']['teaser']['field'] = 'teaser';
  $handler->display->display_options['fields']['teaser']['label'] = '';
  $handler->display->display_options['fields']['teaser']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['teaser']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['teaser']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['teaser']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['teaser']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['teaser']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['teaser']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['teaser']['alter']['html'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['label'] = 'Issues';
  $handler->display->display_options['fields']['title_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_2']['link_to_node'] = 1;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['fields']['field_date_value']['table'] = 'node_data_field_date';
  $handler->display->display_options['fields']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['fields']['field_date_value']['label'] = 'Date';
  $handler->display->display_options['fields']['field_date_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_date_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_date_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_date_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_date_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_date_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_date_value']['alter']['html'] = 0;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
    'planted_press' => 'planted_press',
    'press_hit' => 'press_hit',
    'pr_statement' => 'pr_statement',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_parent_nid']['id'] = 'field_parent_nid';
  $handler->display->display_options['filters']['field_parent_nid']['table'] = 'node_data_field_parent';
  $handler->display->display_options['filters']['field_parent_nid']['field'] = 'field_parent_nid';
  $handler->display->display_options['filters']['field_parent_nid']['operator'] = 'or';
  $handler->display->display_options['filters']['field_parent_nid']['value'] = array();
  $handler->display->display_options['filters']['field_parent_nid']['group'] = '0';
  $handler->display->display_options['filters']['field_parent_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_parent_nid']['expose']['operator_id'] = 'field_parent_nid_op';
  $handler->display->display_options['filters']['field_parent_nid']['expose']['label'] = 'Filter by:';
  $handler->display->display_options['filters']['field_parent_nid']['expose']['operator'] = 'field_parent_nid_op';
  $handler->display->display_options['filters']['field_parent_nid']['expose']['identifier'] = 'field_parent_nid';
  $handler->display->display_options['filters']['field_parent_nid']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['field_parent_nid']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = '0';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter_1']['group'] = '0';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['date_filter_1']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter_1']['default_to_date'] = 'now +2 day';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node_data_field_event_date.field_event_date_value2' => 'node_data_field_event_date.field_event_date_value2',
  );
  $handler->display->display_options['filters']['date_filter_1']['date_method'] = 'AND';
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_2']['id'] = 'date_filter_2';
  $handler->display->display_options['filters']['date_filter_2']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_2']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_2']['operator'] = 'empty';
  $handler->display->display_options['filters']['date_filter_2']['group'] = '0';
  $handler->display->display_options['filters']['date_filter_2']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['date_filter_2']['date_fields'] = array(
    'node_data_field_event_date.field_event_date_value2' => 'node_data_field_event_date.field_event_date_value2',
  );

  /* Display: News & Events Block (Home) */
  $handler = $view->new_display('block', 'News & Events Block (Home)', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'News & Events';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<em>[type]:</em>[body]';
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Issues */
  $handler->display->display_options['fields']['field_issues_1']['id'] = 'field_issues_1';
  $handler->display->display_options['fields']['field_issues_1']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues_1']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_issues_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_issues_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_issues_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_issues_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_issues_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_issues_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_issues_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_issues_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_issues_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_issues_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_issues_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_issues_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_issues_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_issues_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_issues_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_issues_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_issues_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_issues_1']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_issues_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_issues_1']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_issues_1']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_issues_1']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
    'event' => 'event',
    'planted_press' => 'planted_press',
    'press_hit' => 'press_hit',
    'pr_statement' => 'pr_statement',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter_1']['group'] = '0';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['date_filter_1']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter_1']['default_to_date'] = 'now +2 day';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node_data_field_event_date.field_event_date_value2' => 'node_data_field_event_date.field_event_date_value2',
  );
  $handler->display->display_options['filters']['date_filter_1']['date_method'] = 'AND';
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_2']['id'] = 'date_filter_2';
  $handler->display->display_options['filters']['date_filter_2']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_2']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_2']['operator'] = 'empty';
  $handler->display->display_options['filters']['date_filter_2']['group'] = '0';
  $handler->display->display_options['filters']['date_filter_2']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['date_filter_2']['date_fields'] = array(
    'node_data_field_event_date.field_event_date_value2' => 'node_data_field_event_date.field_event_date_value2',
  );
  $handler->display->display_options['block_description'] = 'News & Events (Home)';

  /* Display: News & Events Block (Parent) */
  $handler = $view->new_display('block', 'News & Events Block (Parent)', 'block_2');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_blog_author']['id'] = 'field_blog_author';
  $handler->display->display_options['fields']['field_blog_author']['table'] = 'field_data_field_blog_author';
  $handler->display->display_options['fields']['field_blog_author']['field'] = 'field_blog_author';
  $handler->display->display_options['fields']['field_blog_author']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_blog_author']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_blog_author']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_blog_author']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_blog_author']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_blog_author']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_blog_author']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_blog_author']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_blog_author']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_blog_author']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_blog_author']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_blog_author']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_blog_author']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_blog_author']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_blog_author']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_blog_author']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_blog_author']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_blog_author']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_blog_author']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_blog_author']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_blog_author']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_blog_author']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_blog_author']['field_api_classes'] = 0;
  /* Field: Content: Author */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_author']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_author']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_author']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_author']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_author']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_author']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_author']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_author']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_author']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_author']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_author']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_author']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_author']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_author']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_author']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_author']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_author']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_author']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_author']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_author']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_author']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_author']['field_api_classes'] = 0;
  /* Field: Content: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_issues']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_issues']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_issues']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_issues']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_issues']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_issues']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_issues']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_issues']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_issues']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_issues']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_issues']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_issues']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_issues']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_issues']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_issues']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_issues']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_issues']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_issues']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_issues']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_issues']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_issues']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_issues']['field_api_classes'] = 0;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_date']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'date_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_date']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '10';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['set_breadcrumb'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['use_taxonomy_term_path'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
    'event' => 'event',
    'planted_press' => 'planted_press',
    'press_hit' => 'press_hit',
    'pr_statement' => 'pr_statement',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter']['group'] = '0';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['date_filter']['granularity'] = 'second';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now +2 day';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node_data_field_date.field_date_value' => 'node_data_field_date.field_date_value',
  );
  /* Filter criterion: Content: Issues (field_issues) */
  $handler->display->display_options['filters']['field_issues_tid']['id'] = 'field_issues_tid';
  $handler->display->display_options['filters']['field_issues_tid']['table'] = 'field_data_field_issues';
  $handler->display->display_options['filters']['field_issues_tid']['field'] = 'field_issues_tid';
  $handler->display->display_options['filters']['field_issues_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_issues_tid']['expose']['operator_id'] = 'field_issues_tid_op';
  $handler->display->display_options['filters']['field_issues_tid']['expose']['label'] = 'Issues';
  $handler->display->display_options['filters']['field_issues_tid']['expose']['operator'] = 'field_issues_tid_op';
  $handler->display->display_options['filters']['field_issues_tid']['expose']['identifier'] = 'field_issues_tid';
  $handler->display->display_options['filters']['field_issues_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_issues_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_issues_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_issues_tid']['vocabulary'] = 'issues';
  $handler->display->display_options['filters']['field_issues_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_issues_tid']['error_message'] = 1;
  $handler->display->display_options['block_description'] = 'News & Events (Parent)';

  /* Display: News & Events Block (Child) */
  $handler = $view->new_display('block', 'News & Events Block (Child)', 'block_3');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_author_nid']['id'] = 'field_author_nid';
  $handler->display->display_options['relationships']['field_author_nid']['table'] = 'node_data_field_author';
  $handler->display->display_options['relationships']['field_author_nid']['field'] = 'field_author_nid';
  $handler->display->display_options['relationships']['field_author_nid']['label'] = 'Author';
  $handler->display->display_options['relationships']['field_author_nid']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['teaser']['id'] = 'teaser';
  $handler->display->display_options['fields']['teaser']['table'] = 'node_revision';
  $handler->display->display_options['fields']['teaser']['field'] = 'teaser';
  $handler->display->display_options['fields']['teaser']['label'] = '';
  $handler->display->display_options['fields']['teaser']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['teaser']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['teaser']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['teaser']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['teaser']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['teaser']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['teaser']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['teaser']['alter']['html'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_grandchild_nid']['id'] = 'field_grandchild_nid';
  $handler->display->display_options['fields']['field_grandchild_nid']['table'] = 'node_data_field_grandchild';
  $handler->display->display_options['fields']['field_grandchild_nid']['field'] = 'field_grandchild_nid';
  $handler->display->display_options['fields']['field_grandchild_nid']['label'] = 'Issues';
  $handler->display->display_options['fields']['field_grandchild_nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_grandchild_nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_grandchild_nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_grandchild_nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_grandchild_nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_grandchild_nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_grandchild_nid']['alter']['html'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['fields']['field_date_value']['table'] = 'node_data_field_date';
  $handler->display->display_options['fields']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['fields']['field_date_value']['label'] = 'Date';
  $handler->display->display_options['fields']['field_date_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_date_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_date_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_date_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_date_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_date_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_date_value']['alter']['html'] = 0;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_pr_statement_type_value']['id'] = 'field_pr_statement_type_value';
  $handler->display->display_options['fields']['field_pr_statement_type_value']['table'] = 'node_data_field_pr_statement_type';
  $handler->display->display_options['fields']['field_pr_statement_type_value']['field'] = 'field_pr_statement_type_value';
  $handler->display->display_options['fields']['field_pr_statement_type_value']['label'] = '';
  $handler->display->display_options['fields']['field_pr_statement_type_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pr_statement_type_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_pr_statement_type_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_pr_statement_type_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_pr_statement_type_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_pr_statement_type_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_pr_statement_type_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_pr_statement_type_value']['alter']['html'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_child_nid']['id'] = 'field_child_nid';
  $handler->display->display_options['arguments']['field_child_nid']['table'] = 'node_data_field_child';
  $handler->display->display_options['arguments']['field_child_nid']['field'] = 'field_child_nid';
  $handler->display->display_options['arguments']['field_child_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_child_nid']['exception']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_child_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_child_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_child_nid']['specify_validation'] = 1;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
    'event' => 'event',
    'planted_press' => 'planted_press',
    'press_hit' => 'press_hit',
    'pr_statement' => 'pr_statement',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = '0';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_grandchild_nid']['id'] = 'field_grandchild_nid';
  $handler->display->display_options['filters']['field_grandchild_nid']['table'] = 'node_data_field_grandchild';
  $handler->display->display_options['filters']['field_grandchild_nid']['field'] = 'field_grandchild_nid';
  $handler->display->display_options['filters']['field_grandchild_nid']['operator'] = 'or';
  $handler->display->display_options['filters']['field_grandchild_nid']['value'] = array();
  $handler->display->display_options['filters']['field_grandchild_nid']['group'] = '0';
  $handler->display->display_options['filters']['field_grandchild_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_grandchild_nid']['expose']['operator_id'] = 'field_grandchild_nid_op';
  $handler->display->display_options['filters']['field_grandchild_nid']['expose']['label'] = 'Filter by:';
  $handler->display->display_options['filters']['field_grandchild_nid']['expose']['operator'] = 'field_grandchild_nid_op';
  $handler->display->display_options['filters']['field_grandchild_nid']['expose']['identifier'] = 'field_grandchild_nid';
  $handler->display->display_options['filters']['field_grandchild_nid']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['field_grandchild_nid']['expose']['multiple'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter']['group'] = '0';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['date_filter']['granularity'] = 'second';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now +2 day';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node_data_field_date.field_date_value' => 'node_data_field_date.field_date_value',
  );
  $handler->display->display_options['block_description'] = 'News & Events (Child)';

  /* Display: News & Events Home */
  $handler = $view->new_display('block', 'News & Events Home', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['label'] = 'Issues';
  $handler->display->display_options['fields']['title_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_2']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_2']['link_to_node'] = 1;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  /* Field: Content: Parent */
  $handler->display->display_options['fields']['field_parent']['id'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['table'] = 'field_data_field_parent';
  $handler->display->display_options['fields']['field_parent']['field'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['label'] = 'Issues';
  $handler->display->display_options['fields']['field_parent']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_parent']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_parent']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_parent']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_parent']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_parent']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_parent']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_parent']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_parent']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_parent']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_parent']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_parent']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_parent']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
    'event' => 'event',
    'planted_press' => 'planted_press',
    'press_hit' => 'press_hit',
    'pr_statement' => 'pr_statement',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = '0';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter_1']['group'] = '0';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['date_filter_1']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter_1']['default_to_date'] = 'now +2 day';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node_data_field_event_date.field_event_date_value2' => 'node_data_field_event_date.field_event_date_value2',
  );
  $handler->display->display_options['filters']['date_filter_1']['date_method'] = 'AND';
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_2']['id'] = 'date_filter_2';
  $handler->display->display_options['filters']['date_filter_2']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_2']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_2']['operator'] = 'empty';
  $handler->display->display_options['filters']['date_filter_2']['group'] = '0';
  $handler->display->display_options['filters']['date_filter_2']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['date_filter_2']['date_fields'] = array(
    'node_data_field_event_date.field_event_date_value2' => 'node_data_field_event_date.field_event_date_value2',
  );
  $handler->display->display_options['block_description'] = 'News & Events (Home)';
  $export['news_events'] = $view;

  return $export;
}
