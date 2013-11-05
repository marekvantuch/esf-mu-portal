I have ever really tested this working on linux, but there should theoretically not be any problem running it on windows. 
I am not going to write the installation tutorial for it though, so if you'd like to try it, please go ahead. Steps 
should be fairly similar.

Requirements: Maven (http://maven.apache.org/), Tomcat (http://tomcat.apache.org), JAVA (https://java.com), JAVA JDK, 
Phing (http://www.phing.info/), Drupal(https://drupal.org)

To verify that your environment is ready for the installation, please check that following commands return valid results.
Also make sure you have the manager webapp contained in your tomcat installation.

Maven ```$ mvn --version``` 
JAVA ```$ java -version``` version should be at least 1.5.x
JAVA JDK ```$ echo $JAVA_HOME``` should display the location of the JAVA SDK

JAVA Servlet application
------------------------

**Build**

1. Navigate into a folder where you'd like to install this piece of software
2. Clone this repository ```$ git clone git@github.com:kanei/ESF-MU-Portal.git```
3. Enter the cloned repository ```$ cd ESF-MU-Portal```
4. Build the application ```$ mvn clean install```
5. Check the ```target``` folder and make sure it contains the built application (war)

**Deploy**

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

Deploy your project by running ```$ mvn tomcat7:(re)deploy```. 

Now you need to set up the
location of the `build.properties` file. To make your life easier, let's say it's going ot be ```/srv/guacamole/```
because that's where next step is going to automatically put that file. We will just need to let Guacamole
know that that's where it should be expecting it. We can do it by two ways - either setting up an environment
variable ```$GUACAMOLE_HOME``` or passing it as a system property (preferred). Edit file 
```%TOMCAT_PATH%/conf/catalina.properties``` and add line with:

``` 
guacamole.home = /srv/guacamole/
```


Drupal modules and features
---------------------------

First of all, we need to have a running drupal instance, please refer to their documentation. 

1. copy the *build.properties.default* file into *build.properties* 
2. fill in the correct location of the drupal installation
3. execute command ```$ phing``` and it will take care of everything else
4. fix any eventual issues (usualy there is a problem or two with permissioning)
 
Script will automatically copy a guacamole.properties file into '''/srv/guacamole/guacamole.properties'''. 
There is no need to edit it manually, all changes can be done from Drupal on the */admin/config/esf/settings*
page. 

Guacd service
-------------

Please refer to http://guac-dev.org/doc/gug/installing-guacamole.html where are details about building on various
distributions. I am using OpenSuse and therefore had to build it from source. 

1. download extra libraries 
	``` 
	$ sudo zypper install libpng-devel cairo-devel freerdp-devel libpulse-devel libvorbis-devel
	```

1. if needed for any reason, maybe just peace of mind that you have everything, you can download the rest of 
the libraries
	```
	$ sudo zypper install libopenssl-devel pango-devel libssh-devel LibVNCServer-devel
	```

2. configure the program 
    ```
    $ sudo ./configure --with-init-dir=/etc/init.d
    ```

3. make sure following line appears:
	```
   	Protocol support:
	
      		RDP ....... yes
	```
1. if you downloaded all the libraries, you should see no *.... no*
2. make and install - guacd will now automatically start as a service
    ```
    $ make
    $ make install
    ```
