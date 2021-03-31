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
 * Implements hook_theme_suggestions_container_alter().
 */
function bravery_theme_suggestions_container_alter(&$suggestions, array $variables) {
  $element = $variables['element'];

  if (isset($element['#type']) && $element['#type'] == 'view') {
    $suggestions[] = 'container__' . $element['#name'];
    $suggestions[] = 'container__' . $element['#name'] . '__' . $element['#display_id'];
  }

  if (isset($element['#type']) && $element['#type'] == 'container' && isset($element['children']['#type'])) {
    $suggestions[] = 'container__' . $element['children']['#type'];
  }
}

/**
 * Implements hook_preprocess_html() for html.html.twig.
 */
function bravery_preprocess_html(&$variables) {
  $current_route = \Drupal::service('current_route_match');
  $current_route_name = $current_route->getRouteName();
  $taxonomy_term = $current_route->getParameter('taxonomy_term');
  $node = $current_route->getParameter('node');

  // Taxonomy route.
  if (!empty($taxonomy_term)) {
    $variables['taxonomy_term_type'] = $taxonomy_term->bundle();
  }

  // View route.
  if (substr($current_route_name, 0, 5) == 'view.') {
    $variables['attributes']['class'][] = 'path-view';
  }

  // Node route.
  if (!empty($node)) {
    // Add node id class
    $variables['attributes']['class'][] = 'page-node--' . $node->id();
  }
}
