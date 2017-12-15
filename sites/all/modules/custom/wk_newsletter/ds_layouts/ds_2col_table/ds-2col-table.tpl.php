<?php

/**
 * @file
 * Display Suite 2 column template.
 */
?>
<table <?php print $layout_attributes; ?> class="ds-2col-table <?php print $classes;?> clearfix">
  <tr>

  <td class="group-left<?php print $left_classes; ?>">
    <?php print $left; ?>
  </td>

  <td class="group-right<?php print $right_classes; ?>">
    <?php print $right; ?>
  </td>

  </tr>
</table>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
