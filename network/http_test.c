/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
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

#include "../builtin.h"
#include "../unit_test.h"

TEST(Network, HttpSchema) {
	char *schema_http = http_schema("http://google.com");
	ASSERT_STR(HTTP, schema_http);

	char *schema_https = http_schema("https://facebook.com");
	ASSERT_STR(HTTPS, schema_https);

	char *schemaNull = http_schema("");
	ASSERT_NULL(schemaNull);

	schemaNull = http_schema("ht tp://google.com/");
	ASSERT_NULL(schemaNull);
}

TEST(Network, HttpHostname) {
	char *hostname = "foodtiny.com.vn";
	char *foodtiny = http_hostname("https://foodtiny.com.vn/home/bundaumamtom/");
	ASSERT_STR(hostname, foodtiny);

    hostname = http_hostname("https://127.0.0.1/fanpage/bundaumamtom");
	ASSERT_STR(LOCALHOST, hostname);

	hostname = http_hostname("https://");
	ASSERT_STR(NULL, hostname);

	hostname = http_hostname("");
	ASSERT_STR(NULL, hostname);
}

TEST(Network, HttpPort) {

	int result = http_port("http://localhost:3001");
	ASSERT_EQUAL(3001, result);

    result = http_port("https://localhost:5000/fanpage/bundaumamtom");
	ASSERT_EQUAL(5000, result);

    result = http_port("https://foodtiny.com");
	ASSERT_EQUAL(443, result);

    result = http_port("http://foodtiny.com");
	ASSERT_EQUAL(80, result);

    result = http_port("http://foodtiny.com/asdfasdf:3241243");
	ASSERT_EQUAL(80, result);

    result = http_port("http://foodtiny.com:3000/asdfasdf:3241243");
    ASSERT_EQUAL(3000, result);

    result = http_port("https://foodtiny.com/");
    ASSERT_EQUAL(443, result);

    result = http_port("https://foodtiny.com:1234?file/adsfasdf/aa");
    ASSERT_EQUAL(1234, result);

    result = http_port("http://foodtiny.com");
    ASSERT_EQUAL(80, result);

    result = http_port("alksdjsad");
    ASSERT_EQUAL(-1, result);

    result = http_port(NULL);
    ASSERT_EQUAL(-1, result);

    result = http_port("1");
    ASSERT_EQUAL(-1, result);

    result = http_port("https://foodtiny.com");
    ASSERT_EQUAL(443, result);
}

TEST(Network, HttpQuery) {
	char *url = "http://localhost/index?key1=value1&key2=value2";
	char *result = http_query(url);
	char *expect = "key1=value1&key2=value2";
	ASSERT_STR(expect, result);

	result = http_query("http://localhost/index?key1=value1&key2=value2:3000");
	ASSERT_STR("key1=value1&key2=value2", result);

	result = http_query("http://localhost/index");
	expect = "";
	ASSERT_STR(expect, result);

	result = http_query("http://localhost/index?");
	expect = "";
	ASSERT_STR(expect, result);

    result = http_query("http://localhost/index?");
    expect = "";
    ASSERT_STR(expect, result);
}
TEST(Network, HttpRequest) {
	#ifdef __APPLE__
		return;
	#endif
	char *headers[2] = {
		"\0"
	};
	char *body[2] = {
		"a=b",
		'\0'
	};

	char *response = http_request("POST", "http://localhost:9999/test", headers, body);
    ASSERT_TRUE((string_index(response, "a=b", 1) > 0));

    response = http_request("GET", "http://localhost:9999/test", headers, body);
    ASSERT_TRUE((string_index(response, "a=b", 1) > 0));
}

TEST(Network, HttpProtocol) {
	char *protocol_http = http_protocol("http://google.com");
	ASSERT_STR("http", protocol_http);

	char *protocol_https = http_protocol("https://facebook.com");
	ASSERT_STR("https", protocol_https);

	char *protocol_null = http_protocol("");
	ASSERT_NULL(protocol_null);

	protocol_null = http_protocol("ht tp://google.com/");
	ASSERT_NULL(protocol_null);
}

TEST(Network, HttpPath) {
    char *target = "http://localhost/index/file1/key.pem?key1=value1&key2=value2:3000";
    char *result = http_path(target);
    char *expect = "/index/file1/key.pem";
    ASSERT_STR(expect, result);

    target = "http://localhost:3000?key1=value1&key2=value2:3000";
    result = http_path(target);
    expect = "/";
    ASSERT_STR(expect, result);

    target = "https://google.com";
    result = http_path(target);
    expect = "/";
    ASSERT_STR(expect, result);
}