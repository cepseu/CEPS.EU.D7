<?php
/**
 * @file
 * Template for a 4 column panel layout.
 *
 * This template provides a four column panel display layout, with
 * each column roughly equal in width.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['left']: Content in the left column.
 *   - $content['midleft']: Content in the middle left column.
 *   - $content['midright']: Content in the middle right column.
 *   - $content['right']: Content in the right column.
 */
?>

<div class="panel-display panel-4col-stacked clearfix"
<?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
	<?php if ($content['top']): ?>
	<div class="panel-panel panel-col-top">
		<div class="inside">
			<?php print $content['top']; ?>
		</div>
	</div>
	<?php endif ?>

	<div class="center-wrapper">
		<div class="panel-panel panel-col-left">
			<div class="inside">
				<?php print $content['left']; ?>
			</div>
		</div>

		<div class="panel-panel panel-col-midleft">
			<div class="inside">
				<?php print $content['midleft']; ?>
			</div>
		</div>

		<div class="panel-panel panel-col-midright">
			<div class="inside">
				<?php print $content['midright']; ?>
			</div>
		</div>

		<div class="panel-panel panel-col-right">
			<div class="inside">
				<?php print $content['right']; ?>
			</div>
		</div>
	</div>

	<?php if ($content['bottom']): ?>
	<div class="panel-panel panel-col-bottom">
		<div class="inside">
			<?php print $content['bottom']; ?>
		</div>
	</div>
	<?php endif ?>
</div>
