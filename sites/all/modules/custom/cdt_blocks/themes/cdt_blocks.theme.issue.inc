<?php

/**
 *  @file
 *  Theme functions for blocks on Issue pages.
 */
 
/**
 *  Theme for Issue Header block.
 *  @param $image
 *    Array of data for image to be displayed.
 *  @return
 *    The HTML of this block.
 */
function theme_cdt_blocks_issue_header($image) {
  $output .= theme('imagecache','issue_header',$image['filepath']);
  return $output;
}

/**
 *  Theme for Issue Placeholder block.
 *  @param $image
 *    Array of data for image to be displayed.
 *  @return
 *    The HTML of this block.
 */
function theme_cdt_blocks_issue_placeholder($image) {
  $output .= theme('imagecache','why_care',$image['filepath']);
  return $output;
}
