<?php

/**
 * @file
 * Linked 1 column template.
 */
?>

<?php
  $link = '';
  if (isset($variables['node_url'])) {
    $link = $variables['node_url'];
  } else if (isset($variables['vocabulary_machine_name'])) {
    $link = url('taxonomy/term/' . $variables['tid']);
  }
?>

<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="1col-linked <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <?php if (!empty($link)): ?>
    <a class="wrap-link" href="<?php print $link; ?>">
  <?php endif; ?>

    <?php print $ds_content; ?>

  <?php if (!empty($link)): ?>
    </a>
  <?php endif; ?>
</<?php print $ds_content_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>