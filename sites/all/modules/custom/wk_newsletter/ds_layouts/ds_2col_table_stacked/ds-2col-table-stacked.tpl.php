<?php

/**
 * @file
 * Display Suite 2 column template.
 */
?>
<table width="100%" <?php print $layout_attributes; ?> class="ds-2col-table-stacked <?php print $classes;?> clearfix">
  <tr>

  <td class="group-left<?php print $left_classes; ?>">
    <?php print $left; ?>
  </td>

  <td width="100" class="group-right<?php print $right_classes; ?>">
    <?php print $right; ?>
  </td>

  </tr>
  <tr>
  <td class="group-bottom<?php print $right_classes; ?>" colspan="2">
    <?php print $bottom; ?>
  </td>
  </tr>
</table>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
