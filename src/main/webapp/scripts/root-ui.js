
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

/**
 * General set of UI elements and UI-related functions regarding user login and
 * connection management.
 */
var GuacamoleRootUI = {
  "sections": {
      "login_form"         : document.getElementById("login-form"),
      "recent_connections" : document.getElementById("recent-connections"),
      "all_connections"    : document.getElementById("all-connections")
  },
          
  "messages": {
    "login_error": document.getElementById("login-error")
  },
          
  "fields": {
    "username": document.getElementById("username"),
    "password": document.getElementById("password")
  },
          
  "buttons": {
    "login": document.getElementById("login")
  },
          
  "views": {
    "login": document.getElementById("login-ui")
  },
  "session_state": new GuacamoleSessionState(),
  "parameters": null

};

// Get parameters from query string
GuacamoleRootUI.parameters = window.location.search.substring(1) || null;

/**
 * Attempts to login the given user using the given password, throwing an
 * error if the process fails.
 */
GuacamoleRootUI.login = function(username, password) {
 
  // Get username and password from form
  var data =
          "username=" + encodeURIComponent(username)
          + "&password=" + encodeURIComponent(password);

  // Include query parameters in submission data
  if (GuacamoleRootUI.parameters)
    data += "&" + GuacamoleRootUI.parameters;

  // Log in
  var xhr = new XMLHttpRequest();
  xhr.open("POST", "login", false);
  xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
  xhr.send(data);

  // Handle failures
  if (xhr.status !== 200)
    throw new Error("Invalid login");

};

/**
 * Resets the interface such that the login UI is displayed if
 * the user is not authenticated (or authentication fails) and
 * the connection list UI (or the client for the only available
 * connection, if there is only one) is displayed if the user is
 * authenticated.
 */
GuacamoleRootUI.reset = function() {

  // should just redirect to the client page if there is already session opened
  
  // If connections could be retrieved, display list
  GuacamoleRootUI.views.login.style.display = "";

};

/*
 * This window has no name. We need it to have no name. If someone navigates
 * to the root UI within the same window as a previous connection, we need to
 * remove the name from that window such that new attempts to use that previous
 * connection do not replace the contents of this very window.
 */
window.name = "";

/*
 * Initialize the login process
 */

/*
 * Set handler for login
 */

GuacamoleRootUI.sections.login_form.onsubmit = function() {

    try {

        // Attempt login
        GuacamoleRootUI.login(
            GuacamoleRootUI.fields.username.value,
            GuacamoleRootUI.fields.password.value
        );

        // Ensure username/password fields are blurred after login attempt
        GuacamoleRootUI.fields.username.blur();
        GuacamoleRootUI.fields.password.blur();

        // Reset UI
        GuacamoleRootUI.reset();

    }
    catch (e) {

        // Display error, reset and refocus password field
        GuacamoleRootUI.messages.login_error.textContent = e.message;

        // Reset and recofus password field
        GuacamoleRootUI.fields.password.value = "";
        GuacamoleRootUI.fields.password.focus();

    }

    // Always cancel submit
    return false;

};


/*
 * Initialize UI
 */

GuacamoleRootUI.reset();


/*
 * Make sure body has an associated touch event handler such that CSS styles
 * will work in browsers that require this.
 */
document.body.ontouchstart = function() {
};
