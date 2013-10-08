package com.vantuch.guacamole.esf.servlets;

import com.google.gson.Gson;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Set;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.glyptodon.guacamole.GuacamoleException;
import org.glyptodon.guacamole.net.auth.Connection;
import org.glyptodon.guacamole.net.auth.ConnectionGroup;
import org.glyptodon.guacamole.net.auth.Directory;
import org.glyptodon.guacamole.net.auth.UserContext;

/**
 * Servlet which returns details about the one connection related to a user.
 * It ignores any groups or permissions and would return only single entry.
 * 
 * @author marek
 */
public class ConnectionServlet extends AuthenticatingHttpServlet {

  @Override
  protected void authenticatedService(UserContext context, HttpServletRequest request, HttpServletResponse response) throws GuacamoleException {
    // Do not cache
        response.setHeader("Cache-Control", "no-cache");

        // Write XML content type
        response.setHeader("Content-Type", "application/json");
        
        // Set encoding
        response.setCharacterEncoding("UTF-8");

        try {
          
          Gson gson = new Gson();

          PrintWriter writer = response.getWriter();
          
          ConnectionGroup root = context.getRootConnectionGroup();
          Directory<String, Connection> connectionDirectory = root.getConnectionDirectory();
          Set<String> identifiers = connectionDirectory.getIdentifiers();
          
          for (String identifier : identifiers) {
            writer.append(gson.toJson(connectionDirectory.get(identifier)));
            break;
          }
          
          writer.close();

        } catch(IOException e) {
          throw new GuacamoleException(e.getMessage());
        }
    
  }

}
