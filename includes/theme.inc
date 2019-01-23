<?php
/**
 * @file
 * Theme Suggestion functions.
 */

/**
 * Block Theme Suggestions
 * @param $suggestions
 * @param $variables
 */
function chief_theme_suggestions_block_alter(&$suggestions, $variables) {
  // Create a blank block template for general use
  if ($variables['elements']['#plugin_id'] == 'system_main_block') {
    $suggestions[] = 'block__no_wrapper';
  }
}

/**
 * Region Theme Suggestions
 * @param $suggestions
 * @param $variables
 */
function chief_theme_suggestions_region_alter(&$suggestions, $variables) {
  // Create a blank region template for general use
  if ($variables['elements']['#region'] == 'content') {
    $suggestions[] = 'region__no_wrapper';
  }
}