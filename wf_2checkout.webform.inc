<?php

/**
 * @file
 * Webform module wf_2checkout component.
 */

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_wf_2checkout() {
  return array(
    'name' => '',
    'form_key' => NULL,
    'pid' => 0,
    'weight' => 0,
    'value' => '',
    'extra' => array(
      'amount' => 0,
      'amount_component' => '',
      'select_email' => '',
      'email_component' => '',
      'pay_button' => '',
    ),
  );
}

/**
 * Implements _webform_edit_component().
 */
function _webform_edit_wf_2checkout($component) {
  $node = node_load($component['nid']);
  $form = array();
  // Mapping exists field of amount.
  $form['amount'] = array(
    '#type' => 'fieldset',
    '#title' => t('Amount'),
    '#collapsible' => TRUE,
    '#tree' => TRUE,
    '#parents' => array('extra'),
  );
  // Checking exists fields for amount.
  $amount_components = array();
  foreach ($node->webform['components'] as $other_component) {
    $component_type = $other_component['type'];
    if (in_array($component_type, array('textfield', 'number', 'select'))) {
      if ($component_type === 'select') {
        continue;
      }
      $amount_components[$other_component['cid']] = check_plain($other_component['name']);
    }
  }
  // Dynamic component.
  $form['amount']['amount_component'] = array(
    '#type' => 'select',
    '#title' => t('Amount Field'),
    '#description' => t("Here you can select dynamic amount field using previously fields and this component which will determine the amount. Include(Textfield, Number, Select)."),
    '#options' => $amount_components,
    '#empty_option' => t('Select a component'),
    '#default_value' => $component['extra']['amount_component'],
  );
  // Email field.
  $form['email'] = array(
    '#type' => 'fieldset',
    '#title' => t('E-mail'),
    '#collapsible' => TRUE,
    '#tree' => TRUE,
    '#parents' => array('extra'),
  );
  // Select email options.
  $form['email']['select_email'] = array(
    '#type' => 'radios',
    '#title' => t('E-mail address'),
    '#options' => array(
      'user' => t('Logged-in user email address'),
      'component' => t('Dynamic email address'),
    ),
    '#default_value' => $component['extra']['select_email'],
    '#required' => TRUE,
  );
  // Dynamic email component.
  $email_component = array();
  foreach ($node->webform['components'] as $related_component) {
    if (in_array($related_component['type'], array('email'))) {
      $email_component[$related_component['cid']] = $related_component['name'];
    }
  }
  $form['email']['email_component'] = array(
    '#type' => 'select',
    '#title' => t('Dynamic email address'),
    '#description' => t("Sets the email component which uses for the email address. Eligible components include: Email."),
    '#options' => $email_component,
    '#empty_option' => t('Select component'),
    '#default_value' => $component['extra']['email_component'],
    '#states' => array(
      'visible' => array(
        ':input[name="extra[select_email]"]' => array('value' => 'component'),
      ),
    ),
  );
  // Pay button.
  $form['form_button'] = array(
    '#type' => 'fieldset',
    '#title' => t('Form Button'),
    '#collapsible' => TRUE,
    '#tree' => TRUE,
    '#parents' => array('extra'),
  );
  $form['form_button']['pay_button'] = array(
    '#type' => 'textfield',
    '#title' => t('Pay button label'),
    '#description' => t('This is used for the button which opens the 2checkout payment form. Default: <em>%default</em>',
      array('%default' => '')
    ),
    '#default_value' => $component['extra']['pay_button'],
    '#parents' => array('extra', 'pay_button'),
  );
  return $form;
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_wf_2checkout($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  // This is a hidden field which will store Order Number for success payment.
  $element = array(
    '#type' => 'hidden',
    '#attributes' => array('class' => 'wf_2checkout_order_number'),
    '#theme_wrappers' => array('webform_element'),
    '#default_value' => $component['value'],
    '#webform_component' => $component,
  );
  return $element;
}

/**
 * Implements _webform_display_component().
 */
function _webform_display_wf_2checkout($component, $value, $format = 'html', $submission = array()) {
  if (isset($value[0])) {
    return array(
      '#type' => 'markup',
      '#title' => $component['name'] . ' ' . t('Invoice ID'),
      '#markup' => $value[0],
      '#weight' => $component['weight'],
      '#theme_wrappers' => $format == 'html' ? array('webform_element') : array('webform_element_text'),
      '#translatable' => array('title'),
    );
  }
}

/**
 * Implements _webform_table_component().
 */
function _webform_table_wf_2checkout($component, $value) {
  if (empty($value[0])) {
    return;
  }
  else {
    return ucfirst($value[0]);
  }
}

/**
 * Implements _webform_csv_headers_component().
 */
function _webform_csv_headers_wf_2checkout($component, $export_options) {
  $header = array();
  $header[0] = '';
  $header[1] = '';
  $header[2] = $component['name'];
  return $header;
}

/**
 * Implements _webform_csv_data_component().
 */
function _webform_csv_data_wf_2checkout($component, $export_options, $value) {
  if (empty($value[0])) {
    return;
  }
  else {
    return ucfirst($value[0]);
  }
}
