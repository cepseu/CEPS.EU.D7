<?php
/**
 * @file
 * Botanique Newsletter html file.
 */
header("Cache-Control: no-cache, must-revalidate"); // HTTP/1.1

$text  = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">';
$text .= '<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="' .  $language->language .'" dir="'.  $language->dir .'">';
$text .= '<head profile="'. $grddl_profile .'">';
$text .= '<meta content="text/html; charset=utf-8" http-equiv="Content-Type" />';
  		 '<meta name="viewport" content="width=device-width, initial-scale=1.0" />';
$text .= $head; 
$text .= '<title>'. $head_title .'</title>';
$text .= '<style type="text/css">';
ob_start();
include DRUPAL_ROOT . base_path() . drupal_get_path('module', 'wk_newsletter') . '/css/newsletter.css.php';
$text .= ob_get_clean();
$text .=  '</style></head>';
$text .= '<body class="' . $classes . '" ' . $attributes . '>';
$text .= $page;
$text .= "</body></html>";

$domdoc = new DOMDocument();
$domdoc->loadHTML($text);
$tables = $domdoc->getElementsByTagName('table');

foreach ($tables as $table) {
	$last = $table->childNodes->item($table->childNodes->length - 1);
	if ($last) {
		$attr = $last->getAttribute('class');
		if (empty($attr)) {
			$last->setAttribute('class', 'row-last');
		}
		else {
			$attr = explode(' ', $attr);
			if (!in_array('row-last', $attr)) {
				$attr[] = 'row-last';
				$attr = implode(' ', $attr);
				$last->setAttribute('class', $attr);
			}
		}	
	}
}
$lists = $domdoc->getElementsByTagName('ul');
$elements = array();
foreach ($lists as $list) {
	$attr = $list->getAttribute('class');
	if (strpos($attr, "action-links") !== FALSE) {
		$elements[] = $list;
	}
	else if (strpos($attr, "field-collection-view-links") !== FALSE) {
		$elements[] = $list;
	}
	else if (strpos($attr, "contextual-links") !== FALSE) {
		$elements[] = $list;
	}
}
foreach ($elements as $element) {
	$element->parentNode->removeChild($element);
}
// convert relative addresses to absolute
global $base_url;
$arr = $domdoc->getElementsByTagName('body')->item(0)->getElementsByTagName('a');
foreach ($arr as $a) {
	$url = $a->getAttribute("href");
	if (strpos($url, "mailto:") !== FALSE) {
		continue;
	}
	else if (strpos($url, "tel:") !== FALSE) {
		continue;
	}
	else if (strpos($url, "unsubscribe") !== FALSE) {
		continue;
	}
	else if (valid_url($url, TRUE)) {
		continue;
	}
	else {
		$a->setAttribute("href", $base_url . $url);
	}	
}
$text = $domdoc->saveHTML();
$text = str_replace("<dl>", "<div>", $text);
$text = str_replace("</dl>", "</div>", $text);
$text = _emogrifier_process($text, '', '', '', '', '');
print $text;

?>
