/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.vantuch.guacamole.esf;

import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.glyptodon.guacamole.GuacamoleException;
import org.glyptodon.guacamole.net.auth.UserContext;

/**
 *
 * @author marek
 */
public class Login extends AuthenticatingHttpServlet {
  private static final Logger logger = Logger.getLogger(Login.class.getName());
    
  @Override
  protected void authenticatedService(UserContext context, HttpServletRequest request, HttpServletResponse response) throws GuacamoleException {
    logger.log(Level.INFO, "Login was successful.");
  }
  
}
