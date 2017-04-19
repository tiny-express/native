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
	ASSERT_STR(foodtiny, hostname);


	char *localhost = http_hostname("http://localhost:3000");
	ASSERT_STR(localhost, LOCALHOST);


	ASSERT_STR(http_hostname("https://127.0.0.1/fanpage/bundaumamtom"), LOCALHOST);
}

//TEST(Builtin_Network, HttpPort) {
//	int result = http_port("http://localhost:3001");
//	ASSERT_EQUAL(result, 3001);
//
//    result = http_port("https://localhost:5000/fanpage/bundaumamtom");
//	ASSERT_EQUAL(result, 5000);
//
//    result = http_port("https://foodtiny.com");
//	ASSERT_EQUAL(result, 443);
//
//    result = http_port("http://foodtiny.com");
//	ASSERT_EQUAL(result, 80);
//
//    result = http_port("foodtiny.com");
//	ASSERT_EQUAL(result, -1);
//}

TEST(Builtin_Network, HttpQuery) {
	char *url = "http://localhost/index?key1=value1&key2=value2";
	char *result1 = http_query(url);
	ASSERT_STR(result1, "key1=value1&key2=value2");

	char *result2 = http_query("http://localhost/index?key1=value1&key2=value2:3000");
	ASSERT_STR(result2, "key1=value1&key2=value2");
}