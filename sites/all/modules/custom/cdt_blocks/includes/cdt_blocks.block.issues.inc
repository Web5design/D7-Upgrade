<?php

/**
 *  @file
 *  Issues block that displays Parent and Child issues.
 */
 
/**
 *  Display the content of the Issues block.
 *  @return
 *    The content of this block.
 */
function cdt_blocks_view_content_issues() {
  drupal_add_js(drupal_get_path('module', 'cdt_blocks') . '/js/cdt_blocks.issues.js');

  $issues = array();
  
  // Get all parents sorted by weight.
  $parents = db_query(db_rewrite_sql("SELECT n.nid, n.title FROM {node} n INNER JOIN {content_field_weight} w ON n.vid = w.vid WHERE n.status = 1 AND n.type = 'parent' ORDER BY w.field_weight_value ASC, n.title ASC"));
  while ($parent = db_fetch_object($parents)) {
    $child_issues = $grandchild_issues = array();
    $grandchild_child = NULL;
    
    // Get all this parent's children marked as current issue, sorted by weight.
    $children = db_query(db_rewrite_sql("SELECT n.nid, n.title FROM {node} n INNER JOIN {content_type_child} c ON n.vid = c.vid INNER JOIN {content_field_weight} w ON n.vid = w.vid LEFT JOIN {content_field_parents_other} po ON po.vid = n.vid WHERE n.status = 1 AND n.type = 'child' AND c.field_child_current_issue_value = 1 AND (c.field_child_parent_nid = %d OR po.field_parents_other_nid = %d) ORDER BY w.field_weight_value ASC, n.title ASC"), $parent->nid, $parent->nid);
    while ($child = db_fetch_object($children)) {
      $child_issues[$child->nid] = array(
        'link' => l($child->title, 'node/' . $child->nid),
      );
    }
    
    // Set expanded if on parent page or one of its child page.
    $expanded = FALSE;
    if (arg(0) == 'node' && is_numeric(arg(1))) {
      if (arg(1) == $parent->nid) {
        $expanded = TRUE;
      }
      else {
        $n = node_load(arg(1));
        if ($n->type == 'child') {
          if ($n->field_child_parent[0]['nid'] == $parent->nid) {
            $expanded = TRUE;
            // Let's show the grandchildren too.
            $gcs = db_query(db_rewrite_sql("SELECT n.nid, n.title FROM {node} n INNER JOIN {content_type_grandchild} gc ON n.vid = gc.vid WHERE n.status = 1 AND gc.field_grandchild_child_nid = %d ORDER BY n.title ASC"), $n->nid);
            while ($gc = db_fetch_object($gcs)) {
              $child_issues[$n->nid]['grandchildren'][] = l($gc->title, 'node/' . $gc->nid);
            }
          }
        }
      }
    }
    
    $issues[] = array(
      'nid' => $parent->nid,
      'link' => l($parent->title, 'node/' . $parent->nid),
      'children' => $child_issues,
      'expanded' => $expanded,
    );
  }
  
   
  return theme('cdt_blocks_issues', $issues);
}
