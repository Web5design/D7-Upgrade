<?php

/**
 *  @file
 *  Block that displays header image on issue page.
 */
 
/**
 *  Display the content of the Issue header block.
 *  @return
 *    The content of this block.
 */
function cdt_blocks_view_content_issue_header() {
  $n = node_load(arg(1));
  
  if ($n->type == 'parent') {
    $image = $n->field_issue_header[0];
  }
  elseif ($n->type == 'child') {
    if ($n->field_issue_header[0]['filepath']) {
      $image = $n->field_issue_header[0];
    }
    else {
      $parent = node_load($n->field_child_parent[0]['nid']);
      $image = $parent->field_issue_header[0];
    }
  }
   
  return theme('cdt_blocks_issue_header', $image);
}
