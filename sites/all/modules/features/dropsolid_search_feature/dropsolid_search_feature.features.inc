<?php
/**
 * @file
 * dropsolid_search_feature.features.inc
 */

/**
 * Implements hook_default_search_api_index().
 */
function dropsolid_search_feature_default_search_api_index() {
  $items = array();
  $items['apache_solr_index'] = entity_import('search_api_index', '{
    "name" : "Apache solr Index",
    "machine_name" : "apache_solr_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "apache_solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "search_api_aggregation_1" : {
                "name" : "full Search",
                "type" : "fulltext",
                "fields" : [
                  "title",
                  "author",
                  "search_api_aggregation_1",
                  "body:value",
                  "body:summary",
                  "body:format"
                ],
                "description" : "A Fulltext aggregation of the following fields: Title, Author, Clients, Consultants, Tags, Date, Category, Forums, Find a solution for your domain, Related Services, Cases, Find a solution for your domain, Related Services, Cases, Related Project Types, Cases, Project types for your domain, Services, Find a solution for your domain, Other Cases, Client, Find a solution for your domain, Related Services, Related Project Types, Date, Tags, Date, Tags, Consultant Type, Date, Place, Training, full Search, The main body text \\u00bb Text, The main body text \\u00bb Summary, The main body text \\u00bb Text format."
              }
            }
          }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      },
      "fields" : {
        "type" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "8.0" },
        "status" : { "type" : "integer" },
        "promote" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },        
        "search_api_language" : { "type" : "string" },
        "search_api_aggregation_1" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "body:summary" : { "type" : "text" },
        "body:format" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function dropsolid_search_feature_default_search_api_server() {
  $items = array();
  $items['apache_solr'] = entity_import('search_api_server', '{
    "name" : "apache solr",
    "machine_name" : "apache_solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "host" : "92.243.15.236",
      "port" : "8983",
      "path" : "\\/solr/platform_dev",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 1,
      "retrieve_data" : 1,
      "highlight_data" : 1,
      "http_method" : "POST"
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
