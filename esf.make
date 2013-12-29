; esf_profile make file for local development
core = "7.x"
api = "2"

projects[drupal][version] = "7.x"
; include the d.o. profile base
includes[] = "src/profiles/esf_profile/esf_profile.make"

; +++++ Libraries +++++

; modernizr
libraries[modernizr][directory_name] = "modernizr"
libraries[modernizr][type] = "library"
libraries[modernizr][destination] = "libraries"
libraries[modernizr][download][type] = "get"
libraries[modernizr][download][url] = http://modernizr.com/downloads/modernizr-latest.js

; backbone
libraries[backbone][directory_name] = "backbone"
libraries[backbone][type] = "library"
libraries[backbone][destination] = "libraries"
libraries[backbone][download][type] = "get"
libraries[backbone][download][url] = https://github.com/documentcloud/backbone/archive/master.zip

; html5shiv
libraries[html5shiv][directory_name] = "html5shiv"
libraries[html5shiv][type] = "library"
libraries[html5shiv][destination] = "libraries"
libraries[html5shiv][download][type] = "get"
libraries[html5shiv][download][url] = https://github.com/aFarkas/html5shiv/archive/master.zip

; underscore
libraries[underscore][directory_name] = "underscore"
libraries[underscore][type] = "library"
libraries[underscore][destination] = "libraries"
libraries[underscore][download][type] = "get"
libraries[underscore][download][url] = https://github.com/documentcloud/underscore/archive/master.zip