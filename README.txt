INTRODUCTION
------------

This is a webform based module which provides 2checkout Standard Checkout
facility that can handle every part of the buyer’s checkout process
on a single page.

We have added "2checkout pay" webform button component which will help
to select your amount using amount mapping component for submitting
your payment amount on the 2checkout portal.

Also, we have added custom payment success page which helps to verify
the payment detail that was a success or not.

REQUIREMENTS
------------

This module requires the following modules:

 * Webform (https://www.drupal.org/project/webform)

INSTALLATION
------------

- Download wf_2checkout module form drupal.org.

- Login as an administrator. Enable the module in the "Administer" -> "Modules".

CONFIGURATION
-------------

- You can config necessary information like 
  (Account No, Secret Word, Payment for what etc.) at:
  "Configuring" -> "Web servers" -> "Webform 2checkout".

- Create webform and add necessary component.
	For wf_2checkout you need to add "2checkout Pay" button
	and select amount mapping component from previously added component
	for amount(This can be textfield, number, select) and save it.

- We have created payment success page which URL is:
  http://www.example.com/2checout-success. 
  You need to paste this URL in your 2checkout account at site management
  "Direct Return" -> "Approved URL".

- You can change thank you page message using config setting.
