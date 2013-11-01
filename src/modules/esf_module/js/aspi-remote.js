(function ($) {
  var Esf = Esf || {};

  Drupal.behaviors.esf_aspi = {
    attach: function(context) {
      Esf.Servlets.login(Esf.Tunnel.init);
    }
  }

  Esf.Servlets = {
    login: function(success_callback) {
      GuacUI.Client.showStatus('Logging in...')

      $.ajax({
        url: '?q=aspi/ajax/login',
        // Check for error. Note that Drupal is not capable of sending
        // errors via JSON response so we need to send a valid JSON
        // in case error happens
        error: function(xhr, status, message) {
          GuacUI.Client.showError("Login failed: " + xhr.statusText);
        },
        success: function(data, status) {
          if (data != null && "error" in data) {
            GuacUI.Client.showError("Login failed: " + data.error);
          } else {
            success_callback();
          }
        }
      });
    }
  }

  Esf.Tunnel = {
    /**
     * Initializes the tunnel by creating Tunnel object and then connecting
     * to the Guacamole server.
     *
     * If exception is caught, it is displayed in the main window of the site.
     */
    init: function() {
      var tunnel = Esf.Tunnel.getTunnel();
      var guac = Esf.Tunnel.getClient(tunnel);

      try {
        guac.connect(Esf.Tunnel.getConnectString());
      }
      catch (e) {
        GuacUI.Client.showError(e.message);
      }
    },

    /**
     * Initializes the tunnel object depending on technogies supported by
     * the browser
     *
     * @returns {*} ChainedTunnel or Tunnel
     */
    getTunnel: function () {
      // If WebSocket available, try to use it.
      if (window.WebSocket) {
        var url = Drupal.settings.esf.server_url;
        return new Guacamole.ChainedTunnel(
            //new Guacamole.WebSocketTunnel(url.replace("http", "ws") + "websocket-tunnel"),
            new Guacamole.HTTPTunnel(url + "tunnel")
        );
      }

      // If no WebSocket, then use HTTP.
      return new Guacamole.HTTPTunnel("tunnel");
    },

    /**
     * Initializes the client object with the tunnel parameter and binds
     * it to the site
     *
     * @param tunnel
     * @returns {Client}
     */
    getClient: function (tunnel) {
    // Instantiate client
      var guac = new Guacamole.Client(tunnel);

      // Add client to UI
      guac.getDisplay().className = "software-cursor";
      GuacUI.Client.display.appendChild(guac.getDisplay());

      // Tie UI to client
      GuacUI.Client.attach(guac);
      return guac;
    },

    /**
     * Initializes the connection string used to initialize the Guacamole
     * server connection settings
     *
     * @returns {string}
     */
    getConnectString: function () {
      // Calculate optimal width/height for display
      var optimal_width = window.innerWidth;
      var optimal_height = window.innerHeight;

      // Scale width/height to be at least 600x600
      if (optimal_width < 600 || optimal_height < 600) {
        var scale = Math.max(600 / optimal_width, 600 / optimal_height);
        optimal_width = Math.floor(optimal_width * scale);
        optimal_height = Math.floor(optimal_height * scale);
      }

      // Get entire query string, and pass to connect().
      var connect_string = "width=" + optimal_width + "&height=" + optimal_height;

      // Add audio mimetypes to connect_string
      GuacUI.Audio.supported.forEach(function (mimetype) {
        connect_string += "&audio=" + encodeURIComponent(mimetype);
      });

      // Add video mimetypes to connect_string
      GuacUI.Video.supported.forEach(function (mimetype) {
        connect_string += "&video=" + encodeURIComponent(mimetype);
      });

      return connect_string;
    }
  }

})(jQuery);
