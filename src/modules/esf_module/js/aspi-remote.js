// Start connect after control returns from onload (allow browser
// to consider the page loaded).
window.onload = function() {
  window.setTimeout(function() {

    var tunnel;

    // If WebSocket available, try to use it.
    if (window.WebSocket) {
      var url = Drupal.settings.esf.server_url;
      tunnel = new Guacamole.ChainedTunnel(
              //new Guacamole.WebSocketTunnel(url.replace("http", "ws") + "websocket-tunnel"),
              new Guacamole.HTTPTunnel(url + "tunnel")
              );

    }
    // If no WebSocket, then use HTTP.
    else
      tunnel = new Guacamole.HTTPTunnel("tunnel")

    // Instantiate client
    var guac = new Guacamole.Client(tunnel);

    // Add client to UI
    guac.getDisplay().className = "software-cursor";
    GuacUI.Client.display.appendChild(guac.getDisplay());

    // Tie UI to client
    GuacUI.Client.attach(guac);

    try {

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
      // Normally, only the "id" parameter is required, but
      // all parameters should be preserved and passed on for
      // the sake of authentication.

      var connect_string =
              "id=" + "c/" + encodeURIComponent("VirtualBox XP")
              + "&width=" + optimal_width
              + "&height=" + optimal_height;

      // Add audio mimetypes to connect_string
      GuacUI.Audio.supported.forEach(function(mimetype) {
        connect_string += "&audio=" + encodeURIComponent(mimetype);
      });

      // Add video mimetypes to connect_string
      GuacUI.Video.supported.forEach(function(mimetype) {
        connect_string += "&video=" + encodeURIComponent(mimetype);
      });

      guac.connect(connect_string);

    }
    catch (e) {
      GuacUI.Client.showError(e.message);
    }

  }, 0);
};
