<?php
/**
 * @file
 * cdt_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function cdt_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-issues.
  $menus['menu-issues'] = array(
    'menu_name' => 'menu-issues',
    'title' => 'Issues',
    'description' => 'Menu of issue hierarchy',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Issues');
  t('Menu of issue hierarchy');


  return $menus;
}
