<?php

/**
 * @file
 * Admin interface settings form for 2checkout.
 */

/**
 * Implements hook_settings_form().
 */
function wf_2checkout_admin_settings_form() {
  $form['wf_2checkout_info'] = array(
    '#type' => 'fieldset',
    '#title' => t('2checkout Configuration Detail.'),
  );
  $form['wf_2checkout_info']['wf_2checkout_sid'] = array(
    '#type' => 'textfield',
    '#title' => t('Account Number'),
    '#description' => t('Your 2Checkout account number.'),
    '#default_value' => variable_get('wf_2checkout_sid', ''),
    '#required' => TRUE,
  );
  $form['wf_2checkout_info']['wf_2checkout_hashsecretword'] = array(
    '#type' => 'textfield',
    '#title' => t('Secret Word'),
    '#description' => t('Your 2Checkout hashSecretWord. There is a 64 character limit on the Secret Word.'),
    '#default_value' => variable_get('wf_2checkout_hashsecretword', ''),
    '#required' => TRUE,
  );
  $form['wf_2checkout_info']['wf_2checkout_li_0_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('The name of your company/website/NGO.'),
    '#default_value' => variable_get('wf_2checkout_li_0_name', ''),
  );
  $form['wf_2checkout_info']['wf_2checkout_payment_mode'] = array(
    "#type" => 'select',
    '#title' => t('Choose the payment mode.'),
    '#options' => array(
      'https://www.2checkout.com/checkout/purchase' => t('Live'),
      'https://sandbox.2checkout.com/checkout/purchase' => t('Testing/Sandbox'),
    ),
    '#description' => t('To check Testing/Sandbox payment, you must have a <a href="https://sandbox.2checkout.com/sandbox/home/dashboard/" target="_blank">Sandbox Account</a> set up with 2Checkout.'),
    '#required' => TRUE,
    '#default_value' => variable_get('wf_2checkout_payment_mode', ''),
  );
  $form['wf_2checkout_info']['wf_2checkout_currency_code'] = array(
    '#type' => 'select',
    '#title' => t('Currency code'),
    '#description' => t('This is your payment currency.'),
    '#options' => array(
      'USD' => t('USD'),
      'EGP' => t('EGP'),
      'DKK' => t('DKK'),
      'INR' => t('INR'),
      'EUR' => t('EUR'),
      'JPY' => t('JPY'),
    ),
    '#required' => TRUE,
    '#default_value' => variable_get('wf_2checkout_currency_code', ''),
  );
  $form['wf_2checkout_info']['wf_2checkout_lang'] = array(
    '#type' => 'select',
    '#title' => t('Payment language'),
    '#description' => t('This is your payment language.'),
    '#options' => array(
      'en' => t('English'),
      'nl' => t('Dutch'),
      'da' => t('Danish'),
      'it' => t('Italian'),
      'sl' => t('Spanish'),
      'jp' => t('Japanese'),
      'de' => t('German'),
    ),
    '#required' => TRUE,
    '#default_value' => variable_get('wf_2checkout_lang', ''),
  );
  $form['wf_2checkout_info']['wf_2checkout_cancel_msg'] = array(
    '#type' => 'textfield',
    '#title' => t('Payment cancel message.'),
    '#description' => t('This is your thank you page payment cancel message.'),
    '#default_value' => variable_get('wf_2checkout_cancel_msg', ''),
  );
  $form['wf_2checkout_info']['wf_2checkout_success_msg'] = array(
    '#type' => 'textfield',
    '#title' => t('Payment success message.'),
    '#description' => t('This is your thank you page payment success message.'),
    '#default_value' => variable_get('wf_2checkout_success_msg', ''),
  );
  return system_settings_form($form);
}
