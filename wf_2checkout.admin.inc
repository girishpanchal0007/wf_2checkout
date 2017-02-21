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
    '#title' => t('2checkout Config Detail'),
    '#description' => t('The test or live detail from <a href="!url">your dashboard</a>.',
      array('!url' => 'https://sandbox.2checkout.com/sandbox/home/dashboard/')
    ),
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
    '#title' => t('Payment for what?'),
    '#description' => t('The payment is making for what?.'),
    '#default_value' => variable_get('wf_2checkout_li_0_name', ''),
  );
  $form['wf_2checkout_info']['wf_2checkout_payment_mode'] = array(
    "#type" => 'select',
    '#title' => t('Choose the payment mode.'),
    '#options' => array(
      'https://www.2checkout.com/checkout/purchase' => t('Live'),
      'https://sandbox.2checkout.com/checkout/purchase' => t('Testing/Sandbox'),
    ),
    '#description' => t('To check Testing/Sandbox payment, you must have a <a href="https://sandbox.2checkout.com/sandbox/">Sandbox Account</a> set up with 2Checkout.'),
    '#required' => TRUE,
    '#default_value' => variable_get('wf_2checkout_payment_mode', ''),
  );
  $form['wf_2checkout_info']['wf_2checkout_currency_code'] = array(
    '#type' => 'select',
    '#title' => t('Currency Code'),
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
    '#title' => t('Language'),
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
  $form['wf_2checkout_info']['wf_2checkout_thankyou'] = array(
    '#type' => 'textfield',
    '#title' => t('Success Page Description'),
    '#description' => t('This is your thank you page description.'),
    '#default_value' => variable_get('wf_2checkout_thankyou', ''),
  );
  return system_settings_form($form);
}
