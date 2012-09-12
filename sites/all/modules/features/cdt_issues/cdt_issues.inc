<?php

/**
 * File of helper functions for migrating issue data.  Used by cdt_issues.install
 */

/**
 * Create a taxonomy term and return the term.
 */
function _cdt_issues_create_taxonomy_term($vid, $name, $parent = NULL) {
  $term = new stdClass();
  $term->name = $name;
  $term->vid = $vid;
  if (isset($parent)) {
    $term->parent = $parent;
  }
  taxonomy_term_save($term);
  return $term;
}

/**
 * Search for a taxonomy issue term with the given name
 */
function _cdt_issues_find_term($vid, $name, $parent = NULL) {
  $tid = false;
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'taxonomy_term');
  $query->propertyCondition('name', $name);
  $query->propertyCondition('vid', $vid);
  $result = $query->execute();
  if (isset($result['taxonomy_term'])) {
    foreach ($result['taxonomy_term'] as $id => $row) {
      $current_parent = db_select('taxonomy_term_hierarchy', 't')
        ->fields('t', array('parent'))
        ->condition('tid', $id)
        ->execute()
        ->fetchField();
      if (isset($parent)) {
        if ($parent == $current_parent) {
          $tid = $id;
          break;
        }
      }
      else {
        if ($current_parent == 0) {
          $tid = $id;
          break;
        }
      }
    }
  }
  return $tid;
}

/**
 * Helper function to set the field in $term from a field in $node
 * @param  Taxonomy object &$term - object to modify
 * @param  Node $node  - node to extract field from
 * @param  string $field - name of field to copy
 * @param  string $dest  - optional field name destination
 */
function _cdt_issues_set_field(&$term, $node, $field, $dest = NULL) {
  if (isset($node->{$field}['und'][0]['value'])) {
    if (isset($dest)) {
      $term->{$dest} = $node->{$field}['und'][0]['value'];
      $term->format = $node->{$field}['und'][0]['format'];
    }
    else {
      $term->{$field}['und'][0]['value'] = $node->{$field}['und'][0]['value'];
      $term->{$field}['und'][0]['format'] = $node->{$field}['und'][0]['format'];
    }
  }
  elseif (isset($node->{$field}['und'][0]['fid'])) {
    $term->{$field}['und'][0]['fid'] = $node->{$field}['und'][0]['fid'];
  }
}

/**
 * Populate the Issue vocabulary with terms taken from parent/child/grandchild nodes
 * Also populates the mapping table between old nid and new tid values
 */
function cdt_issues_populate_parent($vid, $nid) {
  $output = '';

  $node = node_load($nid);
  $tid = _cdt_issues_find_term($vid, $node->title);
  if ($tid) {
    $term = taxonomy_term_load($tid);
  }
  else {
    // create a new parent term
    $term = _cdt_issues_create_taxonomy_term($vid, $node->title);
  }
  _cdt_issues_set_field($term, $node, 'field_intro', 'description');
  $fields = array('field_all_about', 'field_issue_header', 'field_issue_placeholder', 'field_parent_video');
  foreach ($fields as $field) {
    _cdt_issues_set_field($term, $node, $field);
  }
  $output .= "Updated Parent term: " . $node->title . "<br>\n";
  taxonomy_term_save($term);
  _cdt_issues_set_mapping($node->nid, $term->tid);
  $output .= _cdt_issues_child_issues($vid, $node->nid, $term->tid);

  return $output;
}

/**
 * Migrate Child issues
 * @param  int $vid - id of vocabulary
 * @param  int $parent_nid - ID of old parent node
 * @param  int $parent_tid - TID of parent term
 */
function _cdt_issues_child_issues($vid, $parent_nid, $parent_tid) {
  $output = '';
  // Get list of Child nodes
  $children = db_query("SELECT nid, title FROM {node} WHERE type = 'child'");
  foreach ($children as $child) {
    $node = node_load($child->nid);
    if (isset($node->field_child_parent['und'][0]['nid']) && ($node->field_child_parent['und'][0]['nid'] == $parent_nid)) {
      $tid = _cdt_issues_find_term($vid, $child->title, $parent_tid);
      if ($tid) {
        $term = taxonomy_term_load($tid);
        $term->parent = $parent_tid;
      }
      else {
        // create a new parent term
        $term = _cdt_issues_create_taxonomy_term($vid, $child->title, $parent_tid);
      }
      _cdt_issues_set_field($term, $node, 'field_intro', 'description');
      $fields = array('field_issue_header', 'field_issue_placeholder', 'field_parent_video');
      foreach ($fields as $field) {
        _cdt_issues_set_field($term, $node, $field);
      }
      $output .= "&nbsp;&nbsp;Updated Child term: " . $child->title . "<br>\n";
      taxonomy_term_save($term);
      _cdt_issues_set_mapping($node->nid, $term->tid);
      $output .= _cdt_issues_grandchild_issues($vid, $node->nid, $term->tid);
    }
  }
  return $output;
}

/**
 * Migrate Grandchild issues
 * @param  int $vid - id of vocabulary
 * @param  int $parent_nid - ID of old parent node
 * @param  int $parent_tid - TID of parent term
 */
function _cdt_issues_grandchild_issues($vid, $parent_nid, $parent_tid) {
  $output = '';
  // Get list of Grandchild nodes
  $children = db_query("SELECT nid, title FROM {node} WHERE type = 'grandchild'");
  foreach ($children as $child) {
    $node = node_load($child->nid);
    if (isset($node->field_grandchild_child['und'][0]['nid']) && ($node->field_grandchild_child['und'][0]['nid'] == $parent_nid)) {
      $tid = _cdt_issues_find_term($vid, $child->title, $parent_tid);
      if ($tid) {
        $term = taxonomy_term_load($tid);
        $term->parent = $parent_tid;
      }
      else {
        // create a new parent term
        $term = _cdt_issues_create_taxonomy_term($vid, $child->title, $parent_tid);
      }
      _cdt_issues_set_field($term, $node, 'body', 'description');
      $output .= "&nbsp;&nbsp;&nbsp;&nbsp;Updated Grandchild term: " . $child->title . "<br>\n";
      taxonomy_term_save($term);
      _cdt_issues_set_mapping($node->nid, $term->tid);
    }
  }
  return $output;
}

/**
 * Save a new mapping between old nid and new tid
 * @param  int $nid - old issue parent/child/grandchild node id
 * @param  int $tid - new issue term id
 */
function _cdt_issues_set_mapping($nid, $tid) {
  db_insert('cdt_mapping')
    ->fields(array(
      'nid' => $nid,
      'tid' => $tid,
    ))
    ->execute();
}

/**
 * Migrate node references to taxonomy references
 * Must run cdt_issues_issues first to create taxonomy terms
 */
function cdt_issues_taxonomy($map, $nid) {
  $output = '';
  $node = node_load($nid);
  $issues = array();
  _cdt_issues_add_tid($issues, $map, $node, 'field_parent');
  _cdt_issues_add_tid($issues, $map, $node, 'field_child');
  _cdt_issues_add_tid($issues, $map, $node, 'field_grandchild');
  if (count($issues) > 0) {
    $node->field_issues['und'] = $issues;
    node_save($node);
    $output .= "Fixing reference in nid " . $node->nid . " : " . $node->title . "<br>\n";
  }
  return $output;
}

/**
 * Look up a node field value nid and add the corresponding tid to issue array
 * @param  array &$issues - issue array to be appended to
 * @param  array $map - mapping array between nid and tid
 * @param  object $node    - node object
 * @param  string $field   - name of field in node
 */
function _cdt_issues_add_tid(&$issues, $map, $node, $field) {
  if (isset($node->{$field}['und'][0]['nid']) &&
      isset($map[$node->{$field}['und'][0]['nid']])) {
    $issues[] = array('tid' => $map[$node->{$field}['und'][0]['nid']]);
  }
}

/**
 * Retrieve the mapping between old node id and new taxonomy id
 * @return array - key is nid, value is tid
 */
function cdt_issues_get_mapping() {
  $map = array();
  $result = db_select('cdt_mapping', 'm')
    ->fields('m', array('nid', 'tid'))
    ->execute();
  while ($row = $result->fetchAssoc()) {
    $map[$row['nid']] = $row['tid'];
  }
  return $map;
}

