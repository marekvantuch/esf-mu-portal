<?php
/*
Ben's quick and dirty HTTP cookie header parser

HTTP cookie headers are actually quite tricky to parse, because the expiry date often contains a comma, and commas are supposed to be the delimiter between individual cookies.

This parser cheats by splitting the cookie header based on the equals sign, and reconstructing the key pairs in a loop.

This sample code doesn't support all cookie properties, but it ought to be trivial to add more. It hasn't been tested a great deal, so use at your own risk.

I originally wrote this in Objective-C for ASIHTTPRequest (http://allseeing-i.com/asi-http-request) before I discovered Apple's function that does this for you (DOH!), but I'd guess this PHP port is likely to be more useful to more people. Even if you hate PHP with a passion, you ought to be able to read it well enough to port it to whatever language you like.

More random stuff at:

http://www.allseeing-i.com

*/

function parse_cookies($header) {
	
	$cookies = array();
	
	$cookie = new cookie();
	
	$parts = explode("=",$header);
	for ($i=0; $i< count($parts); $i++) {
		$part = $parts[$i];
		if ($i==0) {
			$key = $part;
			continue;
		} elseif ($i== count($parts)-1) {
			$cookie->set_value($key,$part);
			$cookies[] = $cookie;
			continue;
		}
		$comps = explode(" ",$part);
		$new_key = $comps[count($comps)-1];
		$value = substr($part,0,strlen($part)-strlen($new_key)-1);
		$terminator = substr($value,-1);
		$value = substr($value,0,strlen($value)-1);
		$cookie->set_value($key,$value);
		if ($terminator == ",") {
			$cookies[] = $cookie;
			$cookie = new cookie();
		}
		
		$key = $new_key;
	}
	return $cookies;
}

class cookie {
	public $name = "";
	public $value = "";
	public $expires = "";
	public $domain = "";
	public $path = "";
	public $secure = false;
	
	public function set_value($key,$value) {
		switch (strtolower($key)) {
			case "expires":
				$this->expires = $value;
				return;
			case "domain":
				$this->domain = $value;
				return;
			case "path":
				$this->path = $value;
				return;
			case "secure":
				$this->secure = ($value == true);
				return;
		}
		if ($this->name == "" && $this->value == "") {
			$this->name = $key;
			$this->value = $value;
		}
	}
}