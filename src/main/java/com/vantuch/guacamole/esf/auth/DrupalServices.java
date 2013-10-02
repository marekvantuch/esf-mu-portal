/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.vantuch.guacamole.esf.auth;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;
import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.StatusLine;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpResponseException;
import org.apache.http.client.ResponseHandler;
import org.apache.http.client.fluent.Form;
import org.apache.http.client.fluent.Request;
import org.apache.http.client.utils.URIBuilder;
import org.glyptodon.guacamole.GuacamoleException;
import org.glyptodon.guacamole.net.auth.Credentials;
import org.glyptodon.guacamole.properties.GuacamoleProperties;
import org.glyptodon.guacamole.properties.StringGuacamoleProperty;

/**
 *
 * @author marek
 */
public class DrupalServices {
  /**
   * The filename of the XML file to read the user user_mapping from.
   */
  private static final StringGuacamoleProperty AUTH_PORTAL_URL = new StringGuacamoleProperty() {
    @Override
    public String getName() {
      return "auth-portal-url";
    }
  };
  
  private static final String RESOURCE_CONNECT_URL = "service/system/connect";
  private static final String RESOURCE_LOGIN_URL = "service/public/user/login";
  private static final String RESOURCE_SUFFIX = ".json";
  
  public static DrupalSession connect() {
    
    return null;
  }
  
  public static DrupalUser login(Credentials credentials) throws GuacamoleException {
    
    try {
      URI uri = new URIBuilder()
              .setScheme("http")
              .setHost(GuacamoleProperties.getProperty(AUTH_PORTAL_URL))
              .setPath("/")
              .setParameter("q", RESOURCE_LOGIN_URL + RESOURCE_SUFFIX)
              .build();

      // Validate and return info for given user and pass
      Request.Post(uri)
              .bodyForm(Form.form().add("username", credentials.getUsername())
              .add("password", credentials.getPassword()).build())
              .setHeader("Content-Type", "application/json")
              .execute()
              .handleResponse(new ResponseHandler<DrupalUser>() {
                
        @Override
        public DrupalUser handleResponse(HttpResponse response) throws ClientProtocolException, IOException {
          StatusLine statusLine = response.getStatusLine();
          HttpEntity entity = response.getEntity();
          
          if (statusLine.getStatusCode() >= 300) {
            throw new HttpResponseException(
                    statusLine.getStatusCode(),
                    statusLine.getReasonPhrase());
          }
          if (entity == null) {
            throw new ClientProtocolException("Response contains no content");
          }
          
          /* Gson gson = new GsonBuilder().create();
          ContentType contentType = ContentType.getOrDefault(entity);
          Charset charset = contentType.getCharset();
          Reader reader = new InputStreamReader(entity.getContent(), charset);
          return gson.fromJson(reader, MyJsonObject.class);
*/
          return new DrupalUser();
        }
      });

    } catch (URISyntaxException e) {
      throw new GuacamoleException(e.getMessage());
    } catch (ClientProtocolException e) {
      throw new GuacamoleException(e.getMessage());
    } catch (IOException e) {
      throw new GuacamoleException(e.getMessage());
    }
    
    return null;
  }
}
