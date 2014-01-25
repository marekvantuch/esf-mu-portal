<div<?php print $attributes; ?>>
  <header class="l-header" role="banner">
    <div class="l-constrained">
      <div class="l-branding site-branding">
        <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-branding__logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
        <?php endif; ?>
        <?php if ($site_name): ?>
          <a href="<?php print $front_page; ?>" class="site-branding__name" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
        <?php endif; ?>
        <?php if ($site_slogan): ?>
          <h2 class="site-branding__slogan"><?php print $site_slogan; ?></h2>
        <?php endif; ?>
      </div>
      <?php print render($page['header']); ?>
    </div>
  </header>

  <div class="l-main l-constrained">

    <?php print render($tabs); ?>
    <?php print $breadcrumb; ?>
    <?php print $messages; ?>

    <?php print render($page['sidebar']); ?>

    <div class="l-content" role="main">
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </div>

    <?php print render($page['postscript']); ?>
  </div>
</div>

<footer class="l-footer-wrapper" role="contentinfo">
  <div class="l-footer l-constrained">
    <?php print render($page['footer']); ?>
  </div>
</footer>
