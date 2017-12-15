<?php
/**
 * @file
 * Template for a 2 column panel layout.
 *
 * This template provides a two column panel display layout, with
 * additional areas for the top and the bottom.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['banner']: Content in the top row.
 *   - $content['main']: Content in middle row.
 *   - $content['bottom']: Content in the bottom row.
 */
?>
<div class="panel-simple-stacked clearfix panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="panels-inner clearfix">

    <?php if ($content['banner']): ?>
      <div class="panel-col-banner panel-panel">
        <div class="inside"><?php print $content['banner']; ?></div>
      </div>
    <?php endif; ?>

    <?php if ($content['main']): ?>
      <div class="panel-col-main panel-panel">
        <div class="inside"><?php print $content['main']; ?></div>
      </div>
    <?php endif; ?>

    <?php if ($content['bottom']): ?>
      <div class="panel-col-bottom panel-panel">
        <div class="inside"><?php print $content['bottom']; ?></div>
      </div>
    <?php endif; ?>

  </div>

</div>