<?php

/**
 * @file
 * Display Suite NE Bootstrap Two Columns Stacked.
 */

  // Add sidebar classes so that we can apply the correct width in css.
  // Second block is needed to activate display suite support on forms.
?>

<<?php print $layout_wrapper . $layout_attributes; ?> class="<?php print $classes; ?>">
  <?php if (isset($title_suffix['contextual_links'])) : ?>
    <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
  <?php if (!isset($hidelink) || (isset($hidelink) && $hidelink == FALSE)) : ?>
    <a href="<?php print $node_url; ?>" class="listing__item-link">
  <?php endif; ?>
    <<?php print $main_wrapper; ?> class="listing__column-main column-main <?php print $main_classes; ?>">
      <?php print $main; ?>
    </<?php print $main_wrapper; ?>>
  <?php if (!isset($hidelink) || (isset($hidelink) && $hidelink == FALSE)) : ?>
    </a>
  <?php endif; ?>
</<?php print $layout_wrapper; ?>>

<?php if (!empty($drupal_render_children)) : ?>
  <?php print $drupal_render_children; ?>
<?php endif; ?>
