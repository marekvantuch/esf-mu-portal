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
