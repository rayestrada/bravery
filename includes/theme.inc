<?php

/**
 * @file
 * Theme Suggestion functions.
 */

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
  $current_route = \Drupal::service('current_route_match');
  $current_route_name = $current_route->getRouteName();
  $taxonomy_term = $current_route->getParameter('taxonomy_term');
  if (!empty($taxonomy_term)) {
    $variables['taxonomy_term_type'] = $taxonomy_term->bundle();
  }

  // Add body class to identify view pages.
  if (substr($current_route_name, 0, 5) == 'view.') {
    $variables['attributes']['class'][] = 'path-view';
  }
}
