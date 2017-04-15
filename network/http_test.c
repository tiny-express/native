//
// Created by dquang on 15/04/2017.
//

#include "../builtin.h"
#include "../unit_test.h"

TEST(Builtin_Network, HttpGet) {
	char *charArray = "127.0.0.1:2379";
	int from = 6;
	int to = 10;
	char *result = http_get(charArray);
//	ASSERT_EQUAL(5, length_pointer_char(result));
//	ASSERT_STR("Worl", result);
}