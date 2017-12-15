SparkPost email extension for CiviCRM
=====================================

This extension allows CiviCRM to send emails and process bounces through the SparkPost service.

It was designed with the following goals and/or features:
* be trivial to install and configure, even for the novice users
* self-configure when possible and check that everything is appropriately setup
* integrate as seamlessly as possible within CiviCRM, neatly replacing other email options
* be nimble and fast, and in particular use the REST API rather than SMTP, and use real-time callbacks
* have a 'service provider' mode in which the same SparkPost account can be used for multiple clients
* accurate processing of bounces with in-depth analysis and translation of all bounce codes

It sends both transactional and CiviMail emails through the SparkPost service. Bounces are processed through a callback (no need for an email account dedicated to bounce processing), but CiviCRM only processes bounces for CiviMail-originated emails. We are planning to extend bounce processing to transactional emails in the short term.

Opens and click-throughs as still tracked by CiviCRM as there is no added-value in having these tracked by SparkPost.



Installation instructions
=========================

* Configure CiviCRM extensions parameters (if not done already)
  * go to Administer >> System Settings >> Directories, set the CiviCRM Extensions Directory to a folder that is writable by your web server process
  * go to Administer >> System Settings >> Resource URLs, enter the URL to the above directory

* Install the Sparkpost email extension
  * download the latest release of the extensions in your extensions folder
    * we suggest using: git clone https://github.com/cividesk/com.cividesk.email.sparkpost.git
  * go to Administer >> Customize Data and Screens >> Manage Extensions, and click install for this extension

* Sign-up for a SparkPost account, then:
  * create and verify your sending domain(s) at: https://app.sparkpost.com/account/sending-domains. Within CiviCRM, sending email adresses are managed at:
    * Administer >> Communications >> Organization Address and Contact Info,
    * and Administer >> CiviMail >> From Email Address.

    So if you define 'info@my-nonprofit.org' as a sending address in CiviCRM, you would need to create and verify the domain 'my-nonprofit.org' in SparkPost.

  * create an API key at: https://app.sparkpost.com/account/credentials
    * ATTENTION: the API key you create should at minimum be granted the following persmissions: Transmissions (Read/Write), Sending Domains (Read/Write), Event Webhooks (Read/Write), Metrics (Read-only) and Suppression Lists (Read/Write).
    * However, for the sake of simplicity and in order to account for future updates, we advice you simply grant all permissions to the API key created.

* Setup the SparkPost email extension
  * go to Administer >> System Settings >> Outbound Email (SparkPost)
  * enter the API key created above and click 'Save and Send test email'
  * check the on-screen messages for any error you would need to resolve

Requirements
============

This extension requires:
* CiviCRM 4.4, 4.6 or higher
* PHP version 5.4 or higher, with the curl extension enabled

Limitations / known issues
==========================

As of April 2016, a free SparkPost account allow you to send 100,000 emails per month, but with a quota of 10,000 emails per day. CiviCRM does not have an elegant way to deal with the errors SparkPost will return if you exceed this limit. So if there is any chance you might send more than 10,000 emails in any 24 hours period, please upgrade to a paid SparkPost account.

Mails sent from a Forward Mailing link bounce - this is a core issue, see #21 and [CRM-18458](https://issues.civicrm.org/jira/browse/CRM-18458).

Show your support!
==================

Development of this extension was fully self-funded by Cividesk and equated to about 30 hours of work.

You can show your support and appreciation for our work by making a donation at https://www.cividesk.com/pay and indicating 'SparkPost support' as the invoice id.

Suggested donation amounts are _$40 for end-users_, and _$40 per client_ using this extension for service providers. With these suggested amounts, we would need 90 donations just to recoup our development costs.

These donations will fund maintenance and updates for this extension, as well as production of other extensions in the future.

Thanks!