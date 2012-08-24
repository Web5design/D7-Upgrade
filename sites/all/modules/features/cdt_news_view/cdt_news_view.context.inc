<?php
/**
 * @file
 * cdt_news_view.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cdt_news_view_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'issue_context';
  $context->description = 'Context for Issue landing pages';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'issues/*' => 'issues/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-news_events-block_2' => array(
          'module' => 'views',
          'delta' => 'news_events-block_2',
          'region' => 'content',
          'weight' => '-10',
        ),
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => 1,
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for Issue landing pages');
  $export['issue_context'] = $context;

  return $export;
}
