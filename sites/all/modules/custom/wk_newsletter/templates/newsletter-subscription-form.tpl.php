<?php
 /**
  * newsletter subscription form
  *
  * copied the code from the mailchimp site
  */
?>

<div id="mc_embed_signup">
  <form action="//ceps.us8.list-manage.com/subscribe/post?u=460b4a613a59740c36d24a4d6&amp;id=dbb56e549f" method="post" id="mc-embedded-subscribe-form" name="mc-embedded-subscribe-form" class="validate" target="_blank" novalidate>
    <h2>Subscribe to our mailing lists</h2>
    <div class="indicates-required description"><span class="asterisk">*</span> indicates required</div>
    <div class="mc-field-group form-item">
      <label for="mce-EMAIL">Email Address  <span class="asterisk">*</span></label>
      <input type="email" value="" name="EMAIL" class="required email" id="mce-EMAIL">
    </div>
    <div class="mc-field-group form-item">
      <label for="mce-FNAME">First Name </label>
      <input type="text" value="" name="FNAME" class="" id="mce-FNAME">
    </div>
    <div class="mc-field-group form-item">
      <label for="mce-LNAME">Last Name </label>
      <input type="text" value="" name="LNAME" class="" id="mce-LNAME">
    </div>
    <div class="mc-field-group input-group form-item">
      <div class="type">
        <h2><?php print t("Publications Newsletter"); ?></h2>
        <p class="description"><?php print t("Areas of Interest"); ?>:</p>
        <ul>
          <li>
            <input type="checkbox" value="2" name="group[13685][2]" id="mce-group[13685]-13685-1">
            <label for="mce-group[13685]-13685-1"><?php print t("Economy"); ?></label>
          </li>
          <li>
            <input type="checkbox" value="4" name="group[13685][4]" id="mce-group[13685]-13685-2">
            <label for="mce-group[13685]-13685-2"><?php print t("Regulation"); ?></label>
          </li>
          <li>
            <input type="checkbox" value="8" name="group[13685][8]" id="mce-group[13685]-13685-3">
            <label for="mce-group[13685]-13685-3"><?php print t("Rights"); ?></label>
          </li>
          <li>
            <input type="checkbox" value="16" name="group[13685][16]" id="mce-group[13685]-13685-4">
            <label for="mce-group[13685]-13685-4"><?php print t("Europe in the World"); ?></label>
          </li>
          <li>
            <input type="checkbox" value="32" name="group[13685][32]" id="mce-group[13685]-13685-5">
            <label for="mce-group[13685]-13685-5"><?php print t("Energy and Climate Change"); ?></label>
          </li>
          <li>
            <input type="checkbox" value="64" name="group[13685][64]" id="mce-group[13685]-13685-6">
            <label for="mce-group[13685]-13685-6"><?php print t("Institutions"); ?></label>
          </li>
          <li>
            <p class="description">
              <?php print t('When you choose more than 2 research areas, you will receive the extended weekly newsletter, with news about all topics.'); ?>
            </p>
          </li>
          <li class="extended">
            <input type="checkbox" value="8192" name="group[13685][8192]" id="mce-group[13685]-13685-13">
            <label for="mce-group[13685]-13685-13"><?php print t("All Topics"); ?></label>
          </li>
        </ul>
      </div>
      <div class="type">
        <h2><?php print t("Events Newsletter"); ?></h2>
        <p class="description"><?php print t("Areas of Interest"); ?>:</p>
        <ul>
          <li>
            <input type="checkbox" value="128" name="group[13685][128]" id="mce-group[13685]-13685-7">
            <label for="mce-group[13685]-13685-7"><?php print t("Economy"); ?></label>
          </li>
          <li>
            <input type="checkbox" value="256" name="group[13685][256]" id="mce-group[13685]-13685-8">
            <label for="mce-group[13685]-13685-8"><?php print t("Regulation"); ?></label>
          </li>
          <li>
            <input type="checkbox" value="512" name="group[13685][512]" id="mce-group[13685]-13685-9">
            <label for="mce-group[13685]-13685-9"><?php print t("Rights"); ?></label>
          </li>
          <li>
            <input type="checkbox" value="1024" name="group[13685][1024]" id="mce-group[13685]-13685-10">
            <label for="mce-group[13685]-13685-10"><?php print t("Europe in the World"); ?></label>
          </li>
          <li>
            <input type="checkbox" value="2048" name="group[13685][2048]" id="mce-group[13685]-13685-11">
            <label for="mce-group[13685]-13685-11"><?php print t("Energy and Climate Change"); ?></label>
          </li>
          <li>
            <input type="checkbox" value="4096" name="group[13685][4096]" id="mce-group[13685]-13685-12">
            <label for="mce-group[13685]-13685-12"><?php print t("Institutions"); ?></label>
          </li>
          <li>
            <p class="description">
              <?php print t('When you choose more than 2 research areas, you will receive the extended weekly newsletter, with news about all topics.'); ?>
            </p>
          </li>
          <li class="extended">
            <input type="checkbox" value="16384" name="group[13685][16384]" id="mce-group[13685]-13685-14">
            <label for="mce-group[13685]-13685-14"><?php print t("All Topics"); ?></label>
          </li>
        </ul>
      </div>
      <div class="type">
        <h2><?php print t("Monthly newsletter"); ?></h2>
        <ul>
          <li>
            <input checked type="checkbox" value="1" name="group[13685][1]" id="mce-group[13685]-13685-0">
            <label for="mce-group[13685]-13685-0"><?php print t("Monthly newsletter"); ?></label>
          </li>
        </ul>
      </div>
    </div>
    <div id="mce-responses" class="clear">
      <div class="response" id="mce-error-response" style="display:none"></div>
      <div class="response" id="mce-success-response" style="display:none"></div>
    </div>    <!-- real people should not fill this in and expect good things - do not remove this or risk form bot signups-->
    <div style="position: absolute; left: -5000px;">
      <input type="text" name="b_460b4a613a59740c36d24a4d6_dbb56e549f" tabindex="-1" value="">
    </div>
    <div class="clear">
      <input type="submit" value="<?php print t('Subscribe'); ?>" name="<?php print t('subscribe'); ?>" id="mc-embedded-subscribe" class="button">
    </div>
  </form>
</div>

<?php /*
<script type='text/javascript' src='http://s3.amazonaws.com/downloads.mailchimp.com/js/mc-validate.js'></script>
<script type='text/javascript'>(function($) {window.fnames = new Array(); window.ftypes = new Array();fnames[0]='EMAIL';ftypes[0]='email';fnames[1]='FNAME';ftypes[1]='text';fnames[2]='LNAME';ftypes[2]='text';}(jQuery));var $mcj = jQuery.noConflict(true);</script>
<!--End mc_embed_signup-->*/ ?>
