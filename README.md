ESF MU Portal
==============

This project is a combination of several diploma thesis on **Masaryk University** (http://www.muni.cz/) in 
Brno, Czech Republic. It's aim is to create an information portal for students of
*Faculty of Economics and Administration*, providing them with valuable information and references. 
Whole website had to be reinvented and redesigned and will provide connection to an law information system
ASPI (http://www.systemaspi.cz/).

**Drupal Website** (PHP) <=> **Guacamole Servlets** (JAVA) <=> **Guacamole Proxy** (C) <=> **ASPI** (RDP)

**Apache** <=> **Apache Tomcat** <=> **Linux Service** <=> **ASPI**

***

Drupal Website
---------------------

Whole site is build on Drupal CMS, using as much of it's features as possible. To make the whole process easier, Features module (https://drupal.org/project/features) is used to export configuration and content and then keep it in source control. This way, all the development can happen on a development environment and then be migrated into production.

Remote desktop connection
-------------------------------------

To connect to the third-party servers (ASPI), Guacamole (http://guac-dev.org/) is used. Being an open-source library designed to connect to remote desktop from any HTML5 compatible web browser, it allows us to minimize the requirements for the client environment and almost eliminates any client-side installation steps. It comes with it's own client, which was ported into a Drupal module. To enable it work this way, Guacamole's core JavaScript libraries had to be modified to support CORS (http://www.w3.org/TR/cors/).

Source structure
----------------

- */doc* - documentation of the project
- */src/main* - java application sources
- */src/modules* - Drupal modules and features modules
- */src/themes* - Drupal theme for the project 
- *build.xml* - Phing build file
- *pom.xml* - Maven build file

Theme development instructions
------------------------------

Because theme is based on the Omega v.4 Drupal base theme, it uses it's ideas and therefore SCSS. In order to be able to make any changes to the CSS files, instead of changing them directly, the SCSS files must be amended instead. The easiest way to compile them is using Compass. To install all the required libraries, install Bundler (*http://bundler.io/*), navigate to the theme folder (*src/themes/omega_esf_v2*) and run *$ bundle install*. Then start *$ compass watch*, which will start a process monitoring your .scss files and compiling them automatically to the resulting css.

***
 
Whare next?
-----------

* [Installation instructions](INSTALL.md)
* [Changelog and Roadmap](CHANGELOG.md)
* [Licence](LICENCE.md)
