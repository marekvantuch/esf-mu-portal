ESF MU Portal
==============

A project to implement a portal for ESF MU

Technologies
------------
Core functionality will be covered by implementing Guacamole (http://guac-dev.org/). 
It is an open-source library designed to connect to remote desktop from any HTML5 compatible web browser
through a JAVA based server running on Apache TomCat. This highly lowers the requirements for client computer
and software, eliminating any required instalation steps for end users and providing seamless connection to 
the remote machine. 

Overview

Client -> Tunnel -> Remote Desktop

Client

HTML5 Client (Browser) implemented as a Drupal module on the site (independend on client operating system, 
possibly usable on Android and IOS too).

Tunnel

JAVA based tunnel application running on Linux which provides the tunneling functionality for the HTML5 client. 
It runs as a service on Apache TomCat server.

Remote Desktop

Any kind of VNC or RDP protocol based server, which provides the end point we are connecting to.

Roadmap
-------

Version 0.1 *(May 2013)*

- [x] First functional version, ability to log in into remote machine from web using custom HTML5 client. 
- [x] Only running locally from one Virtual Machine to another. 

Version 0.2 *(June 2013)*

- [x] Drupal integration module is created.
- [x] Remote client server running on a standalone server with designated port so that multiple computers can connect to it.

Version 0.3 *(July 2013)*

- [x] Correct privilegies settings for the drupal module so that it can be integrated into the existing website
- [x] Styling of the module to align with the page which it integrates with.

Instalation
-----------

I have ever really tested this working on linux, but there should theoretically not be any problem running it on windows. 
I am not going to write the installation tutorial for it though, so if you'd like to try it, please go ahead. Steps 
should be fairly similar.

Requirements: Maven (http://maven.apache.org/), Tomcat, JAVA, JAVA JDK

To verify that your environment is ready for the installation, please check that following commands return valid results.

Maven ```mvn --version``` 
JAVA ```java -version``` version should be at least 1.5.x
JAVA JDK ```echo $JAVA_HOME``` should display the location of 

Build JAVA Servlet application

Navigate into a folder where you'd like to install this piece of software
Clone this repository ```git clone git@github.com:kanei/ESF-MU-Portal.git```
Enter the cloned repository ```cd ESF-MU-Portal```
Build the application ```mvn clean install```
Check the ```target``` folder and make sure it contains the built application (war)


