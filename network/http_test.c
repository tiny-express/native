#include "../builtin.h"
#include "../unit_test.h"
#include "../network.h"


TEST(Builtin_Network, HttpSchema) {
	char *schemaHttp = http_schema("http://google.com");
	ASSERT_STR(schemaHttp, HTTP);

	char *schemaHtpps = http_schema("https://facebook.com");
	ASSERT_STR(schemaHtpps, HTTPS);

	char *schemaNull = http_schema("");
	ASSERT_EQUAL(schemaNull, NULL);
}

TEST(Builtin_Network, HttpHostname) {
	char *hostname = "foodtiny.com.vn";
	char *foodtiny = http_hostname("https://foodtiny.com.vn/home/bundaumamtom/");
	ASSERT_STR(hostname, foodtiny);


    hostname = http_hostname("http://localhost:3000");
	ASSERT_STR(hostname, LOCALHOST);

    hostname = http_hostname("https://127.0.0.1/fanpage/bundaumamtom");
	ASSERT_STR(hostname, LOCALHOST);
}

TEST(Builtin_Network, HttpPort) {
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
}

TEST(Builtin_Network, HttpQuery) {
	char *url = "http://localhost/index?key1=value1&key2=value2";
	char *result1 = http_query(url);
	ASSERT_STR("key1=value1&key2=value2", result1);

	char *result2 = http_query("http://localhost/index?key1=value1&key2=value2:3000");
	ASSERT_STR("key1=value1&key2=value2", result2);
}


TEST(Builtin_Network, HttpRequest) {
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

    // NOTE: https tests depend on host cert
}

TEST(Builtin_String, HttpPath) {
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