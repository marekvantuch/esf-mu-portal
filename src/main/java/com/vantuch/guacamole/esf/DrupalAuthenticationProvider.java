package com.vantuch.guacamole.esf;

/*
 *  Guacamole - Clientless Remote Desktop
 *  Copyright (C) 2010  Michael Jumper
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
import com.vantuch.guacamole.esf.auth.DrupalServices;
import com.vantuch.guacamole.esf.auth.DrupalSession;
import java.util.Map;
import java.util.TreeMap;
import java.util.logging.Logger;
import org.glyptodon.guacamole.GuacamoleException;
import org.glyptodon.guacamole.net.auth.Credentials;
import org.glyptodon.guacamole.net.auth.simple.SimpleAuthenticationProvider;
import org.glyptodon.guacamole.properties.GuacamoleProperties;
import org.glyptodon.guacamole.properties.StringGuacamoleProperty;
import org.glyptodon.guacamole.protocol.GuacamoleConfiguration;

/**
 * Authenticates users against a static list of username/password pairs. Each
 * username/password may be associated with multiple configurations. This list
 * is stored in an XML file which is reread if modified.
 *
 * @author Michael Jumper, Michal Kotas
 */
public class DrupalAuthenticationProvider extends SimpleAuthenticationProvider {

  private static final Logger LOG = Logger.getLogger(DrupalAuthenticationProvider.class.getName());
  
  /**
   * The name of the connection
   */
  private static final StringGuacamoleProperty CONNECTION_NAME = new StringGuacamoleProperty() {
    @Override
    public String getName() {
      return "connection-name";
    }
  };
  /**
   * Protocol of the connection, defaults to rdp
   */
  private static final StringGuacamoleProperty CONNECTION_PROTOCOL = new StringGuacamoleProperty() {
    @Override
    public String getName() {
      return "connection-protocol";
    }
  };
  /**
   * Host name of the connection
   */
  private static final StringGuacamoleProperty CONNECTION_HOSTNAME = new StringGuacamoleProperty() {
    @Override
    public String getName() {
      return "connection-hostname";
    }
  };
  /**
   * Host name of the connection
   */
  private static final StringGuacamoleProperty CONNECTION_PORT = new StringGuacamoleProperty() {
    @Override
    public String getName() {
      return "connection-port";
    }
  };

  private GuacamoleConfiguration getConfigurationBase() throws GuacamoleException {
    GuacamoleConfiguration configuration = new GuacamoleConfiguration();

    configuration.setProtocol(GuacamoleProperties.getProperty(CONNECTION_PROTOCOL, "rdp"));

    configuration.setParameter("hostname", GuacamoleProperties.getRequiredProperty(CONNECTION_HOSTNAME));
    configuration.setParameter("port", GuacamoleProperties.getRequiredProperty(CONNECTION_PORT));

    return configuration;
  }

  @Override
  public Map<String, GuacamoleConfiguration> getAuthorizedConfigurations(Credentials credentials)
          throws GuacamoleException {

    DrupalSession session = DrupalServices.login(credentials);

    Map<String, GuacamoleConfiguration> map = new TreeMap<String, GuacamoleConfiguration>();

    GuacamoleConfiguration configuration = getConfigurationBase();

    map.put(GuacamoleProperties.getProperty(CONNECTION_NAME, "Default"), configuration);

    // Unauthorized
    return null;

  }
}
