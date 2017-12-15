<?php

/**
 * @file
 * Default theme implementation to format an individual feed item for display
 * on the aggregator page.
 *
 * Available variables:
 * - $feed_url: URL to the originating feed item.
 * - $feed_title: Title of the feed item.
 * - $source_url: Link to the local source section.
 * - $source_title: Title of the remote source.
 * - $source_date: Date the feed was posted on the remote source.
 * - $content: Feed item content.
 * - $categories: Linked categories assigned to the feed.
 *
 * @see template_preprocess()
 * @see template_preprocess_aggregator_item()
 *
 * @ingroup themeable
 *
 * @link http://api.drupal.org/api/drupal/modules--aggregator--aggregator-item.tpl.php/7
 *
 *
 * Wunderkraut changes
 * --------------------------------------------------------------------
 * - Remove title class
 * - Simplify classnames
 * - Put the title in the l-function
 * - 
 */
?>
<div class="feed-item">
  <h3><a href="<?php print $feed_url; ?>"><?php print $feed_title; ?></a></h3>

  <div class="meta">
    <?php if ($source_url): ?>
      <?php print l($source_title, $source_url, array('attributes' => array('class' => ''))); ?>
    <?php endif; ?>
    <span class="date"><?php print $source_date; ?></span>
  </div>

<?php if ($content): ?>
  <div class="body">
    <?php print $content; ?>
  </div>
<?php endif; ?>

<?php if ($categories): ?>
  <div class="categories">
    <?php print t('Categories'); ?>: <?php print implode(', ', $categories); ?>
  </div>
<?php endif ;?>

</div>