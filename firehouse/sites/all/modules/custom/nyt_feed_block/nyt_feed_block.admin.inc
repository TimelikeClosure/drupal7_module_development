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

  return system_settings_form($form);
}

/**
 * stub
 */
function nyt_feed_block_posts() {

}
