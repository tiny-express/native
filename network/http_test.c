#include "../builtin.h"
#include "../unit_test.h"

TEST(Network, HttpSchema) {
	char *schema_http = http_schema("http://google.com");
	ASSERT_STR(schema_http, HTTP);

	char *schema_https = http_schema("https://facebook.com");
	ASSERT_STR(schema_https, HTTPS);

	char *schemaNull = http_schema("");
	ASSERT_EQUAL(schemaNull, NULL);

	schemaNull = http_schema("ht tp://google.com/");
	ASSERT_EQUAL(schemaNull, NULL);
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

    result = http_port("https://foodtiny.com\n");
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
	char *headers[2] = {
		"\0"
	};
	char *body[2] = {
		"a=b",
		'\0'
	};

	char *response = http_request("POST", "http://httpbin.org/post", headers, body);
    ASSERT_TRUE((string_index(response, "\"data\": \"a=b\"", 1) > 0));

    response = http_request("GET", "http://httpbin.org/get", headers, body);
    ASSERT_TRUE((string_index(response, "\"a\": \"b\"", 1) > 0));
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