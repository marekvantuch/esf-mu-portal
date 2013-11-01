(function($) {
  var Esf = Esf || {};



  Drupal.behaviors.esf = {
    attach: function(context) {
      $('article a').each(function(index, element){
        var protocol = Drupal.settings.esf.protocol;
        var re = new RegExp("(" + protocol + ":\/\/).*","g");
        if (element.href.match(re)) {
          var url = Drupal.settings.esf.url + ':' + Drupal.settings.esf.port;
          this.href= url;
        }
        //console.log(element.href);
      });
    }
  };

})(jQuery);