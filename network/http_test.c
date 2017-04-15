#include "../builtin.h"
#include "../unit_test.h"

TEST(Builtin_Network, HttpQuery) {
	char *url = (char*) "http://localhost?key1=value1&key2=value2";
	char *query = http_query(url);
	//ASSERT_EQUAL(query, "key1=value1&key2=value2");
}