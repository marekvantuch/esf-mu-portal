/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.vantuch.guacamole.muni;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import net.sourceforge.guacamole.GuacamoleException;
import net.sourceforge.guacamole.net.GuacamoleSocket;
import net.sourceforge.guacamole.net.GuacamoleTunnel;
import net.sourceforge.guacamole.net.InetGuacamoleSocket;
import net.sourceforge.guacamole.protocol.ConfiguredGuacamoleSocket;
import net.sourceforge.guacamole.protocol.GuacamoleConfiguration;
import net.sourceforge.guacamole.servlet.GuacamoleHTTPTunnelServlet;
import net.sourceforge.guacamole.servlet.GuacamoleSession;

/**
 *
 * @author Marek
 */
public class Tunnel extends GuacamoleHTTPTunnelServlet {

  @Override
  protected GuacamoleTunnel doConnect(HttpServletRequest hsr) throws GuacamoleException {
      // Create our configuration
        GuacamoleConfiguration config = new GuacamoleConfiguration();
        config.setProtocol("rdp");
        config.setParameter("hostname", "192.168.1.97");
        
        // Connect to guacd - everything is hard-coded here.
        GuacamoleSocket socket = new ConfiguredGuacamoleSocket(
                new InetGuacamoleSocket("localhost", 4822),
                config
        );

        // Establish the tunnel using the connected socket
        GuacamoleTunnel tunnel = new GuacamoleTunnel(socket);

        // Attach tunnel to session
        HttpSession httpSession = hsr.getSession(true);
        GuacamoleSession session = new GuacamoleSession(httpSession);
        session.attachTunnel(tunnel);

        // Return pre-attached tunnel
        return tunnel;
  }
}
