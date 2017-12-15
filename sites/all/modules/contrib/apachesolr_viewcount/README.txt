
This module allows you to index the node view count to Apache solr index as a custom field. The module requires Apache solr search module. The Apachesolr Viewcount module depends on either of the following modules to fetch the node view count:
Statistics module (Core module)
Node view count module
The user needs to select one of above choices to make the module start working. So one would be redirected to the Apachesolr Viewcount module configuration page after installing or enabling the module.
There is another feature provided by the module: the node view count field can be used for sorting. For this purpose, you need to install Apachesolr Sort module.

For the first time, you need to initiate the module to record the node view count (drush initiate-solr-count). To update the solr index with view count values, use ‘drush update-solr-count’ in crontab and setup the timing accordingly.
