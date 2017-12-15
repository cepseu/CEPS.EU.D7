  <!-- Wrapper/Container Table: Use a wrapper table to control the width and the background color consistently of your email. Use this approach instead of setting attributes on the body tag. -->
  <table cellpadding="0" cellspacing="0" border="0" id="backgroundTable" width="100%">
  <tr>
    <td>

      <?php if($messages){ ?>
      <div class="drupal-messages">
        <?php print $messages; ?>
      </div>
    <?php } ?>

  <table cellpadding="0" cellspacing="0" border="0" width="100%">
    <tr>
      <td align="center">
        <div class="container">
          <table class="header" cellpadding="0" cellspacing="0" border="0">
            <tr>
              <td class="first">
                <div class="newsletter-logo">
                  <a href="<?php print url("", array('absolute' => TRUE)); ?>" title="<?php print t('Home'); ?>" rel="home">
                    <img src="<?php print url("/sites/all/themes/custom/wundertheme/images/logo_newsletter.png", array('absolute' => TRUE)); ?>" alt="<?php print t('Home'); ?>" />
                  </a>
                </div>

              </td>
              <td class="second">
                <?php if($site_name OR $site_slogan ): ?>
                  <div class="site-name-slogan">
                    <p class="site-name"><a href="<?php print url("", array('absolute' => TRUE)); ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a></p>
                    <?php if ($site_slogan): ?>
                      <p class="slogan"><?php print $site_slogan; ?></p>
                    <?php endif; ?>
                    <h1 class="page-title"><?php print $title; ?></h1>
                  </div>
                <?php endif; ?>
              </td>
            <tr>
          </table>
        </div>
      </td>
    </tr>
  </table>

  <?php print render($page['content']); ?>

      </td>
    </tr>
  </table>
  <!-- End of wrapper table -->



