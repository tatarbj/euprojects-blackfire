<?php

/**
 * @file
 * Agenda items.
 */
?>
<?php if (!empty($items)): ?>
    <div class="listing__wrapper">
        <ul class="listing listing--agenda listing--column-left">
            <li class="listing__item">
                <div class="listing__item__wrapper">
                  <?php echo $date; ?>

                    <div class="listing__column-main">
                        <div class="listing__wrapper">
                            <ul class="listing listing--no-border">
                              <?php foreach ($items as $item): ?>
                                  <li class="listing__item">
                                      <div class="listing__item__wrapper">
                                          <div class="listing__column-main">
                                              <div class="meta">
                                                  <span class="meta__item meta__item--type"><?php echo $item->name; ?></span>
                                                  <span class="meta__item">
                                                      <?php echo t('From @start_date', ['@start_date' => $item->prepared_start_date]); ?>
                                                      <?php if (!empty($item->end_date)): ?>
                                                        <?php echo t('to @end_date', ['@end_date' => $item->prepared_end_date]); ?>
                                                      <?php endif; ?>
                                                  </span>
                                              </div>
                                            <?php $prefix = $item->new ? '<span class="itemFlag flagHot newItem">New</span> ' : NULL; ?>
                                              <h3 class="listing__title">
                                                <?php $title_text = $prefix . check_plain($item->title); ?>
                                                <?php echo l($title_text, $item->url, [
                                                  'html' => TRUE,
                                                  'absolute' => TRUE,
                                                ]); ?>
                                              </h3>
                                          </div>
                                      </div>
                                  </li>
                              <?php endforeach; ?>
                            </ul>
                        </div>
                    </div>
            </li>
        </ul>
    </div>
<?php endif; ?>
