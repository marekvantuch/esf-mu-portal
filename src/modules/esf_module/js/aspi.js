(function ($) {
    var Esf = Esf || {};

    Drupal.behaviors.esf_aspi = {
        attach: function (context) {
            Esf.Servlets.login();
            if (Esf.Servlets.loginResult) {
                Esf.Tunnel.init();
            }
        }
    }

    Esf.Servlets = {
        loginResult: null,

        login: function () {
            GuacUI.Client.showStatus(Drupal.t('Logging in...'));
            GuacUI.Client.titlePrefix = "[" + Drupal.t("Logging in...") + "]";
            GuacUI.Client.updateTitle();

            $.ajax({
                url: '?q=aspi/ajax/login',
                async: false,
                // Check for error. Note that Drupal is not capable of sending
                // errors via JSON response so we need to send a valid JSON
                // in case error happens
                error: function (xhr, status, message) {
                    var error = Drupal.t("Login failed: !err", { '!err': xhr.statusText });
                    GuacUI.Client.showError(error);
                },
                success: function (data, status) {
                    if (data != null && (typeof data === 'string' || "error" in data)) {
                        var error = Drupal.t("Login failed: !err", {'!err': data.error });
                        GuacUI.Client.showError(error);
                        GuacUI.Client.titlePrefix = "[" + Drupal.t("Login failed") + "]";
                        GuacUI.Client.updateTitle();
                    } else {
                        Esf.Servlets.loginResult = true;
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
        init: function () {
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
                var url;

                // In case we are connecting to localhost, we need to
                // amend it's URL.
                if (Drupal.settings.esf.server_domain == 'localhost') {
                    var port = Drupal.settings.esf.server_port;
                    var path = Drupal.settings.esf.server_path;
                    url = "http://" + window.location.hostname +
                        (port != null && port != 0 ? ':' + port : '') +
                        path;
                } else {
                    url = Drupal.settings.esf.server_url;
                }
                //return new Guacamole.ChainedTunnel(
                    //new Guacamole.WebSocketTunnel(url.replace("http", "ws") + "websocket-tunnel"),
                    //new Guacamole.HTTPTunnel(url + "tunnel")
                //);

                return new Guacamole.HTTPTunnel(url + "tunnel");
            }

            // If no WebSocket, then use HTTP.
            return new Guacamole.HTTPTunnel(url + "tunnel");
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
            var query_string = this.getQueryString();

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

            for (var connect_param in query_string) {
                if (connect_param == 'q') {
                    continue;
                }
                if(query_string.hasOwnProperty(connect_param)){
                    connect_string += "&" + connect_param + "=" + decodeURI(query_string[connect_param]);
                }
            }

            return connect_string;
        },

        getQueryString: function () {
            var query_string = {};
            var query = window.location.search.substring(1);
            var vars = query.split("&");
            for (var i=0;i<vars.length;i++) {
                var pair = vars[i].split("=");
                // If first entry with this name
                if (typeof query_string[pair[0]] === "undefined") {
                    query_string[pair[0]] = pair[1];
                    // If second entry with this name
                } else if (typeof query_string[pair[0]] === "string") {
                    query_string[pair[0]] = [query_string[pair[0]], pair[1]];
                    // If third or later entry with this name
                } else {
                    query_string[pair[0]].push(pair[1]);
                }
            }
            return query_string;
        }
    }

})(jQuery);
