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
        var nid = get_nid($(this).parent());
        var subjects = get_related_subjects(nid);

        for (var key in subjects) {
            if (subjects.hasOwnProperty(key)) {
                $("#map-" + subjects[key]).mouseover();
            }
        }
    }).mouseout(function(e) {
        var nid = get_nid($(this).parent());
        var subjects = get_related_subjects(nid);

        for (var key in subjects) {
            if (subjects.hasOwnProperty(key)) {
                $("#map-" + subjects[key]).mouseout();
            }
        }
    })

    function get_related_subjects(nid) {
        return Drupal.settings.esf.subject_map[nid];
    }

    function get_nid(object) {
        var classes = object.attr("class").split(/\s+/);

        for (var key in classes) {
            if (classes.hasOwnProperty(key) && isNumber(classes[key])) {
                return classes[key];
            }
        }
    }

    function isNumber(n) {
        return !isNaN(parseFloat(n)) && isFinite(n);
    }

})(jQuery);