/**
 * Created by mvantuch on 1/30/14.
 */

(function ($) {

    Drupal.behaviors.esf_home = {
        attach: function (context) {
            $('.map').maphilight();
        }
    }

    $("#quicktabs-navigation .field-content a").mouseover(function(e) {
        $("#map-hospodarska-soutez").mouseover();
        $("#map-dusevni-vlastnictvi").mouseover();
    }).mouseout(function(e) {
        $("#map-hospodarska-soutez").mouseout();
        $("#map-dusevni-vlastnictvi").mouseout();
    })

})(jQuery);