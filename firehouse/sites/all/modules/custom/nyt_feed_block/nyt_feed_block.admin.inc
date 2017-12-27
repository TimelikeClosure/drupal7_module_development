<?php

/**
 * @file
 * Provides the administrative related functions for the New York Times Feed Block module.
*/

/**
 * Defines the New York Times Feeds Block admin settings form
 */
function nyt_feed_block_settings_form() {
  $form = array();

  $setting = 'nyt_feed_block_maxposts';
  $form[$setting] = array(
    '#type' => 'textfield',
    '#title' => t('Number of New York Times Feed Items to show'),
    '#description' => t('The maximum number of New York Times Feed item nodes to show in the New York Times Feed Block.'),
    '#default_value' => variable_get($setting, 3),
    '#size' => 2,
    '#maxlength' => 2,
    '#required' => TRUE,
  );

  $setting = 'nyt_feed_block_types';
  $form[$setting] = array(
    '#type' => 'checkboxes',
    '#title' => t('The content types to enable NYT Feed Block for'),
    '#description' => t('On the specified content types a NYT Feed Block option will be enabled.'),
    '#options' => node_type_get_names(),
    '#default_value' => variable_get($setting, array()),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

function nyt_feed_block_settings_form_validate($form, &$form_state) {

  $setting = 'nyt_feed_block_maxposts';
  $maxposts = $form_state['values'][$setting];
  if (!is_numeric($maxposts)) {
    form_set_error($setting,
      t('You must enter an integer for the maximum number of links.'));
  }
  else if ($maxposts <= 0) {
    form_set_error($setting, t('Maximum number of links must be positive.'));
  }
}

/**
 * stub
 */
function nyt_feed_block_posts() {

}
