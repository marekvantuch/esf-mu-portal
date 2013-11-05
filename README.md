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
----------------------

- */doc* - documentation of the project
- */src/main* - java application sources
- */src/modules* - Drupal modules and features modules
- */src/themes* - Drupal theme for the project 
- *build.xml* - Phing build file
- *pom.xml* - Maven build file

***

Roadmap
-------

Version 0.1

- [x] First functional version, ability to log in into remote machine from web using custom HTML5 client. 
- [x] Only running locally from one Virtual Machine to another. 

Version 0.2

- [x] Drupal integration module is created.
- [x] Remote client server running on a standalone server with designated port so that multiple computers can connect to it.

Version 0.3

- [x] Correct privilegies settings for the drupal module so that it can be integrated into the existing website
- [x] Styling of the module to align with the page which it integrates with.

Version 0.4

- [x] Migration of client application from Guacamole to Drupal module.
- [x] Connection between the various parts of the system are functional.

Version 0.5

- [ ] Translations of UI to czech language.
- [ ] Automated deployment scripts

Version 0.6

- [ ] Ability to execute commands on the Remote Connection client page from Drupal site.

***

Instalation
-----------

I have ever really tested this working on linux, but there should theoretically not be any problem running it on windows. 
I am not going to write the installation tutorial for it though, so if you'd like to try it, please go ahead. Steps 
should be fairly similar.

Requirements: Maven (http://maven.apache.org/), Tomcat (http://tomcat.apache.org), JAVA (https://java.com), JAVA JDK, Phing (http://www.phing.info/)

To verify that your environment is ready for the installation, please check that following commands return valid results.
Also make sure you have the manager webapp contained in your tomcat installation.

Maven ```mvn --version``` 
JAVA ```java -version``` version should be at least 1.5.x
JAVA JDK ```echo $JAVA_HOME``` should display the location of the JAVA SDK

Build JAVA Servlet application

1. Navigate into a folder where you'd like to install this piece of software
2. Clone this repository ```git clone git@github.com:kanei/ESF-MU-Portal.git```
3. Enter the cloned repository ```cd ESF-MU-Portal```
4. Build the application ```mvn clean install```
5. Check the ```target``` folder and make sure it contains the built application (war)

Deploy the JAVA Servlet application

I am using the Apache Tomcat Maven Plugin, so deployment should be very simple. All what is really needed is a setup
for the plugin, which is done by creating user credentials for the Manager and use them in Maven. 
Edit file ```%TOMCAT_PATH%/conf/tomcat-users.xml``` and setup your admin user.

```xml 
<?xml version='1.0' encoding='utf-8'?>
<tomcat-users>
  <role rolename="manager"/>
  <role rolename="admin"/>
  <user username="admin" password="password" roles="admin,manager"/>
</tomcat-users>
```

Then edit file ```%MAVEN_PATH%/conf/settings.xml``` and add the same credentials. Also make sure that the id stays 
TomcatServer, otherwise it's not going to work (must be the same as in the pom.xml file).

```xml
<server>
	<id>TomcatServer</id>
	<username>admin</username>
	<password>password</password>
</server>
```

Then you can simply (re)deploy your project by running ```mvn tomcat7:(re)deploy```
