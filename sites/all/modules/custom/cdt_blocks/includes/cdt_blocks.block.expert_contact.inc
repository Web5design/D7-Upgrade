<?php

/**
 *  @file
 *  Content function for the expert Contact block.
 */
 
/**
 *  Display the content of the expert Contact block.
 *  @return
 *    The content of this block.
 */
function cdt_blocks_view_content_expert_contact() {
  $n = node_load(arg(1));
  $title = 'Contact ' . $n->title;
  $form = drupal_get_form('cdt_blocks_expert_contact_form');
  return theme('cdt_blocks_expert_contact', $title, $form);
}

/**
 *  Contact form on expert page.
 *  @return $form
 *    The FormAPI array representing the form.
 */
function cdt_blocks_expert_contact_form() {
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Your Name'),
    '#size' => 20,
    '#required' => TRUE,
  );
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('email'),
    '#description' => t('this is private and will not be shared'),
    '#size' => 20,
    '#required' => TRUE,
  );
  $form['contact_comment'] = array(
    '#type' => 'textarea',
    '#title' => t('Comment'),
    '#required' => TRUE,
  );
  $form['send'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
  );
  return $form;
}

/**
 * Implementation of hook_submit().
 */
function cdt_blocks_expert_contact_form_submit(&$form, &$form_state) {
  // TODO send to the proper email address
  $from = $form_state['values']['email'];
  $params['subject'] = t('!recipient has sent you a message via the CDT website', array('!recipient' => $form_state['values']['name']));
  $params['message'] = t("!recipient has sent you a message using the comment form on the CDT website:\n\n!message", array('!recipient' => $form_state['values']['name'], '!message' => $form_state['values']['contact_comment']));

  drupal_mail('cdt_blocks', 'cdt_blocks_expert_contact_send_email', 'cyrus@cdt.org', 'en', $params, $from);
  drupal_set_message(t('Your message has been sent.'));
}

/**
 * Implementation of hook_mail().
 */
function cdt_blocks_mail($key, &$message, $params) {
  $subject = $params['subject'];
  $message_body = $params['message'];

  $message['subject'] = $subject;
  $message['body'] = $message_body;
}
