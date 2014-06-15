<?php
/**
 * @file
 * Main content for the Guacamole layout. This had been ported from the
 * Guacamole project.
 */
?>

<!-- Display -->
<div class="displayOuter">
  <div class="displayMiddle">
    <div id="display">
    </div>
  </div>
</div>

<!-- Dimensional clone of viewport -->
<div id="viewportClone"/>

<!-- Notification area -->
<div id="notificationArea"/>

<!-- Images which should be preloaded -->
<div id="preload">
  <img src="<?php echo drupal_get_path('theme', 'omega_esf_v2')?>/images/guac-close.png"/>
  <img src="<?php echo drupal_get_path('theme', 'omega_esf_v2')?>/images/progress.png"/>
</div>
