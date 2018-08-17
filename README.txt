INTRODUCTION
------------

This is a Webform based module that provides the standard 2checkout
payment facility. This module can handle every part of the buyer’s
checkout process on a single page. It is best suited for the charity
and fundraising forms. Users can fill out the form and make
the payment through the webform only.

We have added ‘2checkout Pay’ button component at the end of the form.
It will let users select the payment amount through the amount mapping
component and submit the payment on the standard 2checkout portal.
Admin can also customise the form fields and labels as the standard
web form feature.

We have also added the custom payment success page.
Once user will complete the payment, he will get redirected to that page.
For this, You will need to enter success page URL into your
2checkout account.
Admin can set the custom message for the payment success
and payment failure. It will help admin to verify the payment details.

Important Information
 * Drupal version: 7.X
 * Web form version: 3.x and 4.x

Supported Features
 * 2checkout payment facility
 * Integration with webform
 * Custom payment success page

REQUIREMENTS
------------

This module requires the following modules:

 * Webform (https://www.drupal.org/project/webform)

INSTALLATION
------------

- Download wf_2checkout module form drupal.org and put 
  in sites/all/modules directory.
  (https://www.drupal.org/project/wf_2checkout)

- Login as an administrator. Enable the module from Administer » Modules.

CONFIGURATION
-------------

- You can config necessary information like
  (Account No, Secret Word, Payment for what etc.) at:
  Configuring » Web servers » Webform 2checkout.

- Create webform and add necessary component.
	For wf_2checkout you need to add "2checkout Pay" button
	and select amount mapping component from previously added component
	for amount(This can be textfield, number, select) and save it.

- We have created payment success page which URL is:
  http://www.example.com/2checkout-success.
  You need to paste this URL in your 2checkout account at site management
  Direct Return » Approved URL.

- You can change thank you page message using config setting.

MAINTAINERS
-----------
 * KrishaWeb Technologies (https://www.drupal.org/u/krishaweb)
 * Girish Panchal (https://www.drupal.org/u/girishpanchal)
