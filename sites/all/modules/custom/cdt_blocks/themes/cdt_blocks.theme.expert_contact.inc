<?php

/**
 *  @file
 *  Theme functions for expert contact block.
 */
 
/**
 *  Theme for expert contact block.
 *  @param $title
 *    Title of contact block.
 *  @param $form
 *    Rendered contact form.
 *  @return
 *    The HTML of this block.
 */
function theme_cdt_blocks_expert_contact($title, $form) {
  $output .= '<h2>' . $title . '</h2>';
  $output .= $form;
  return $output;
}