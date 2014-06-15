<?php
/**
 * Created by PhpStorm.
 * User: Marek Vantuch
 * Date: 6/13/14
 * Time: 10:14 PM
 */
?>

<p><?php print render($intro_text); ?></p>
<div class="esf-user-login-form-wrapper">
  <?php print drupal_render_children($form) ?>
</div>