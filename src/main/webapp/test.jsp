<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
      <div id="login-ui" style="display: none">
            <div id="login-dialog-middle">

                <div id="login-dialog">
                    <p id="login-error"></p>
                </div>
            </div>
      </div>
       

        <!-- Display -->
        <div id="display"></div>
        
        <div id="loading">Please wait, loading...</div>

        <!-- Init -->
        <script type="text/javascript"> /* <![CDATA[ */

            // Get display div from document
            var display = document.getElementById("display");

            // Instantiate client, using an HTTP tunnel for communications.
            var guac = new Guacamole.Client(
                new Guacamole.HTTPTunnel("tunnel")
            );

            // Add client to display div
            display.appendChild(guac.getDisplay());
            
            // Error handler
            guac.onerror = function(error) {
                alert(error);
            };

            // Connect
            guac.connect();

            // Disconnect on close
            window.onunload = function() {
                guac.disconnect();
            }

        /* ]]> */ </script>
        
        <!-- Client core scripts -->
        <script type="text/javascript" src="guacamole-common-js/layer.js"></script>
        <script type="text/javascript" src="guacamole-common-js/tunnel.js"></script>
        <script type="text/javascript" src="guacamole-common-js/guacamole.js"></script>
        
        <script type="text/javascript" src="scripts/root-ui.js"></script>
    </body>
</html>
