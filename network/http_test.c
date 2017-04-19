#include "../builtin.h"
#include "../unit_test.h"

#define HTTPS "https"
#define HTTP "http"
#define LOCALHOST "localhost"


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
	ASSERT_STR(foodtiny, hostname);


	char *localhost = http_hostname("http://localhost:3000");
	ASSERT_STR(localhost, LOCALHOST);


	ASSERT_STR(http_hostname("https://127.0.0.1/fanpage/bundaumamtom"), LOCALHOST);
}

TEST(Builtin_Network, HttpPort) {
	int resutl = http_port("localhost:3001");
	ASSERT_EQUAL(resutl, 3001);

	resutl = http_port("localhost:5000/fanpage/bundaumamtom");
	ASSERT_EQUAL(resutl, 5000);

	resutl = http_port("https://foodtiny.com");
	ASSERT_EQUAL(resutl, 443);

	resutl = http_port("http://foodtiny.com");
	ASSERT_EQUAL(resutl, 80);

	resutl = http_port("foodtiny.com");
	ASSERT_EQUAL(resutl, -1000);
}

TEST(Builtin_Network, HttpQuery) {
	char *url = "http://localhost/index?key1=value1&key2=value2";
	char *result1 = http_query(url);
	ASSERT_STR("key1=value1&key2=value2", result1);

	char *result2 = http_query("http://localhost/index?key1=value1&key2=value2:3000");
	ASSERT_STR("key1=value1&key2=value2", result2);
}