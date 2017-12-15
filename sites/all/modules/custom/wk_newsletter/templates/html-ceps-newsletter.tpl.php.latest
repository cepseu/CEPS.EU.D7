<?php
/**
 * @file
 * Botanique Newsletter html file.
 */
header("Cache-Control: no-cache, must-revalidate"); // HTTP/1.1


$doc = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">';

$doc .= '<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="' .  $language->language .'" dir="'.  $language->dir .'">';

$doc .= '<head profile="'. $grddl_profile .'">';
$doc .=  '<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>';
$doc .= $head; 
$doc .=  '<title>'. $head_title .'</title>

  <style type="text/css">';
ob_start();

    include DRUPAL_ROOT . base_path() . drupal_get_path('module', 'wk_newsletter') . '/css/newsletter.css.php';
$doc .= ob_get_clean();
$doc .=  '</style>

</head>';
$doc .= '<body class="' . $classes .'" '. $attributes .'>';
$doc .= $page;
$doc .= "
</body>
</html>";

$url = "http://premailer.dialect.ca/api/0.1/documents";
global $base_url;
$premailer_fields = array(
  'html' => urlencode($doc),
  'base_url' => $base_url,
);

//url-ify the data for the POST
foreach($premailer_fields as $key=>$value) { $fields_string .= $key.'='.$value.'&'; }
rtrim($fields_string, '&');

//open connection
$ch = curl_init();

//set the url, number of POST vars, POST data
curl_setopt($ch,CURLOPT_URL, $url);
curl_setopt($ch,CURLOPT_POST, count($fields));
curl_setopt($ch,CURLOPT_POSTFIELDS, $fields_string);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
//execute post
$result = curl_exec($ch);
//close connection
curl_close($ch);
$decoded = json_decode($result, true);

$ch = curl_init();
curl_setopt($ch, CURLOPT_URL, $decoded['documents']['html']);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

$html = curl_exec($ch);
curl_close($ch);

//print $html;

$domdoc = new DOMDocument();
$domdoc->loadHTML($html);

$selector = new DOMXPath($domdoc);
foreach($selector->query('//p[contains(attribute::class, "site-name")]') as $e ) {
    $e->parentNode->removeChild($e);
}
foreach($selector->query('//img[contains(attribute::class, "desktop")]') as $e ) {
    $e->parentNode->removeChild($e);
}

print $domdoc->saveHTML();
//print $domdoc->saveHTML($domdoc->documentElement);
?>
