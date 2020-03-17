<?php

/**
 * @file
 * Theme Suggestion functions.
 */

/**
 * Implements theme_suggestions_block_alter() for block types theming.
 */
function bravery_theme_suggestions_block_alter(array &$suggestions, array $variables) {
  $elements = $variables['elements'];
  if (isset($elements['content']['#block_content'])) {
    $bundle = $elements['content']['#block_content']->bundle();
    $id = $elements['content']['#block_content']->id();
    array_splice($suggestions, 1, 0, 'block__block_content__' . $bundle);
    array_splice($suggestions, 1, 0, 'block__block_content__' . $id);
  }
}

/**
 * Implements theme_suggestions_user_alter() for user theming.
 */
function bravery_theme_suggestions_user_alter(array &$suggestions, array $variables) {
  $elements = $variables['elements'];
  if (isset($elements['#user'])) {
    array_splice($suggestions, 1, 0, 'user__' . $elements['#view_mode']);
  }
}

/**
 * Implements hook_preprocess_html() for html.html.twig.
 */
function bravery_preprocess_html(&$variables) {
  $current_route_name = \Drupal::service('current_route_match')->getRouteName();

  // Add body class to identify view pages.
  if (substr($current_route_name, 0, 5) == 'view.') {
    $variables['attributes']['class'][] = 'type-view-page';
  }
}
