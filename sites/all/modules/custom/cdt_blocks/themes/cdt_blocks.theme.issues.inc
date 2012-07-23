<?php

/**
 *  @file
 *  Theme functions for the Issues block.
 */
 
/**
 *  Theme for Issues block.
 *  @param $links
 *    Structured array of issues that appear in the block.
 *  @return
 *    The HTML of this block.
 */
function theme_cdt_blocks_issues($issues) {
  $output .= '<div id="issues"><div id="issues_inner">';
  $output .= '<h2>Issues</h2>';
  foreach ($issues as $parent) {
    $output .= '<div class="issues_item">';
    $output .= '<div' . ($parent['expanded'] ? ' class="expanded"' : '') . '> <a href="' . url($_GET['q']) . '?issue=' . $parent['nid'] . '" class="open">-></a> ' . $parent['link'] . '</div>';

    $output .= '<ul class="children" ' . ($_GET['issue'] == $parent['nid'] || $parent['expanded'] ? '' : 'style="display:none"') . '>';
    foreach ($parent['children'] as $child) {
      $output .= '<li>' . $child['link'] . '</li>';
      if (isset($child['grandchildren'])) {
        $output .= '<ul class="grandchildren">';
        foreach ($child['grandchildren'] as $gclink) {
          $output .= '<li>' . $gclink . '</li>';
        }
        $output .= '</ul>';
      }
    }
    $output .= '</ul>';
    
    $output .= '</div>';
  }
  $output .= '</div></div>';
  return $output;
}
