(function($) {
  var Esf = Esf || {};

  Esf.CORS = {
    createRequest: function(method, url) {
      var xhr = new XMLHttpRequest();
      
      if ("withCredentials" in xhr) {

        // Check if the XMLHttpRequest object has a "withCredentials" property.
        // "withCredentials" only exists on XMLHTTPRequest2 objects.
        xhr.open(method, url, true);
        xhr.withCredentials = true;

      } else if (typeof XDomainRequest != "undefined") {

        // Otherwise, check if XDomainRequest.
        // XDomainRequest only exists in IE, and is IE's way of making CORS requests.
        xhr = new XDomainRequest();
        xhr.open(method, url);

      } else {

        // Otherwise, CORS is not supported by the browser.
        xhr = null;

      }
      return xhr;
    }
  };
  
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