/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "URL.hpp"

using namespace Java::Net;

URL::URL() {
	this->protocol = "";
	this->host = "";
	this->port = -1;
	this->query = "";
	this->path = "";
}

URL::URL(const URL &target) {
	this->protocol = target.protocol;
	this->port = target.port;
	this->host = target.host;
	this->path = target.path;
	this->query = target.query;
}

URL::URL(String spec) {
	String url = spec.toString();

//    string _protocol = http_protocol(url.toString());
//	this->protocol = string_default(_protocol);
//    free(_protocol);
//
//    string _host = http_hostname(url.toString());
//	this->host = string_default(_host);
//    free(_host);
//
//	this->port = number_default(url_port(url.toString()));
//
//    string _query = http_query(url.toString());
//	this->query = string_default(_query);
//    free(_query);
//
//    string _path = http_path(url.toString());
//	this->path = string_default(_path);
//    free(_path);
}

URL::~URL() {

}

String URL::getHost() {
	return this->host;
}

String URL::getPath() {
	return this->path;
}

int URL::getPort() {
	return this->port;
}

String URL::getProtocol() {
	return this->protocol;
}

String URL::getQuery() {
	return this->query;
}

string URL::toString() const {
	String protocol = this->protocol;
	String host = this->host;
	int port = this->port;
	String path = this->path;
	String query = this->query;
	
	String url = protocol + (string) "://" + host;
	
	if (port > -1) {
		url = url + (string) ":" + String::valueOf(port);
	}
	
	if (path != "/") {
		url += path;
	}
	
	if (!query.isEmpty()) {
		url += "?";
	}
	
	url += query;
	
	string result = url.toString();
	return strdup(result);
}

