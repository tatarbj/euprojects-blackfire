<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header']:         Displayed in the right part of the
 *                            header -> logo, search box, ...
 * - $page['header_bottom']:  Displayed below the header, take full width of
 *                            site -> main menu, global information,
 *                            breadcrumb...
 * - $page['highlighted']:    Displayed in a big visible
 *                            box -> important message, contextual information,
 *                            ...
 * - $page['help']:           Displayed between page title and
 *                            content -> information about the page,
 *                            contextual help, ...
 * - $page['sidebar_first']:  Small sidebar displayed on left of the content,
 *                            if not empty -> navigation, pictures, ...
 * - $page['sidebar_second']: Large sidebar displayed on right of the content,
 *                            if not empty -> two column layout
 * - $page['content']:        The main content of the current page.
 * - $page['footer']:         Displayed at bottom of the page, on full
 *                            width -> latest update, copyright, ...
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>

<?php if (!empty($page['header_top'])): ?>
<section class="header-top">
  <div class="container-fluid">
    <?php print render($page['header_top']); ?>
  </div>
</section>
<?php endif; ?>

<header class="site-header" role="banner">
  <div class="container-fluid">
    <a href="<?php print $front_page; ?>" class="<?php print $logo_classes; ?>" title="<?php print $page_logo_title; ?>"><span class="sr-only"><?php print $page_logo_title; ?></span></a>
    <?php if ($is_front && !empty($site_slogan)): ?>
      <p class="site-slogan"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php if (!empty($page['header'])): ?>
      <section class="top-bar" aria-label="Site tools">
        <div>
          <div class="top-bar__wrapper">
            <?php if ($is_front): ?>
              <h1 class="sr-only"><?php print $site_name; ?></h1>
              <h2 class="sr-only"><?php print t('Classes'); ?></h2>
            <?php endif; ?>
            <?php print render($page['header']); ?>
          </div>
        </div>
      </section>
    <?php endif; ?>
  </div>
</header>

<?php if (!empty($page['header_bottom'])): ?>
<nav class="page-navigation" role="navigation">
  <div class="container-fluid">
    <?php print render($page['header_bottom']); ?>
  </div>
</nav>
<?php endif; ?>

<?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
  <section id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
    <div class="container-fluid">
      <div class="navbar-header">
        <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
          <span class="sr-only">Toggle navigation</span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
        </button>
      </div>

      <div class="navbar-collapse collapse">
        <nav role="navigation">
          <?php if (!empty($primary_nav)): ?>
            <?php print render($primary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($secondary_nav)): ?>
            <?php print render($secondary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($page['navigation'])): ?>
            <?php print render($page['navigation']); ?>
          <?php endif; ?>
        </nav>
      </div>
    </div>
  </section>
<?php endif; ?>

<?php if (!empty($page['utility'])): ?>
  <div class="utility">
    <div class="container-fluid">
      <?php print render($page['utility']); ?>
    </div>
  </div>
<?php endif; ?>

<section class="main-content">
  <!-- Generic sections -->
  <div class="container-fluid">
    <?php if (!empty($page['help'])): ?>
      <?php print render($page['help']); ?>
    <?php endif; ?>

    <?php if (!empty($action_links)): ?>
      <ul class="action-links"><?php print render($action_links); ?></ul>
    <?php endif; ?>
  </div>

  <?php print render($page['content']); ?>

  <div class="container-fluid">
    <?php print render($page['content_bottom']); ?>
  </div>
</section>

<?php if (!empty($page['footer_top'])): ?>
  <section class="footer-top">
    <div class="container-fluid">
      <?php print render($page['footer_top']); ?>
    </div>
  </section>
<?php endif; ?>

<footer class="footer">
  <div class="container-fluid">
    <div class="row">
      <?php if (!empty($page['footer_right'])): ?>
        <aside class="col-sm-4 footer__column-right">
          <?php print render($page['footer_right']); ?>
        </aside>
      <?php endif; ?>
      <section class="<?php print $footer_column_class; ?> footer__column-main">
        <?php print render($page['footer']); ?>
      </section>
    </div>
  </div>
</footer>
