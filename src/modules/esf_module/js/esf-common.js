(function ($) {
    var Esf = Esf || {};

    Drupal.behaviors.esf_common = {
        attach: function (context) {
            var is_enabled = Drupal.settings.esf.is_guacamole_enabled;

            if (is_enabled) {
                $('article a').each(function (index, element) {
                    var protocol = Drupal.settings.esf.protocol;
                    var re = new RegExp("(" + protocol + ":\/\/)(.*)", "g");
                    if (element.href.match(re)) {
                        var res = re.exec(element.href);
                        this.href = Drupal.settings.basePath + '?q=aspi';
                        // append the rest of ASPI connection string
                        if (res[2]) {
                            this.href += '&' + res[2];
                        }
                    }
                    //console.log(element.href);
                });
            }
        }
    };

})(jQuery);