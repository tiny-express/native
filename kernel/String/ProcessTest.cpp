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

#include "../Builtin.hpp"
#include "../Test.hpp"

TEST (KernelStringProcess, StringReplace) {
    auto target = (char*) "Hello World";
    auto find_string = (char*) "World";
    auto replace_with = (char*) "Food Tiny";
    auto expect = (char*) "Hello Food Tiny";
    auto result = stringReplace(target, find_string, replace_with);
	ASSERT_STR(expect, result);
	free(result);

    auto target2 = (char*) "Hello World";
    auto find_string2 = (char*) "Nothing";
	auto replace_with2 = (char*) "Food Tiny";
    auto expect2 = (char*) "Hello World";
    auto result2 = stringReplace(target2, find_string2, replace_with2);
	ASSERT_STR(expect2, result2);
	free(result2);
	
	auto target3 = (char*) "aaa bbededeb cccccc de dd eeeede";
    auto find_string3 = (char*) "de";
    auto replace_with3 = (char*) "ff";
    auto expect3 = (char*) "aaa bbeffffb cccccc ff dd eeeeff";
    auto result3 = stringReplace(target3, find_string3, replace_with3);
	ASSERT_STR(expect3, result3);
	free(result3);
	
	auto target4 = (char*) "aaaaaaaaaaaffffffffffffffffff";
    auto find_string4 = (char*) "aa";
    auto replace_with4 = (char*) "o";
    auto expect4 = (char*) "oooooaffffffffffffffffff";
    auto result4 = stringReplace(target4, find_string4, replace_with4);
	ASSERT_STR(expect4, result4);
	free(result4);

    auto target5 = (char*) "a";
    auto find_string5 = (char*) "aaaaaaaaaaaaaaaaaaaa";
    auto replace_with5 = (char*) "o";
    auto result5 = stringReplace(target5, find_string5, replace_with5);
	ASSERT_STR("a", result5);
	free(result5);
}

TEST (KernelStringProcess, StringTrim) {
    auto expect = (char*) "Hello World";
    auto target = (char*) "  Hello World  ";
    auto result = stringTrim(target);
	ASSERT_STR(expect, result);
	free(result);

    auto target1 = (char*) "  Hello World";
	char *result1 = stringTrim(target1);
	ASSERT_STR(expect, result1);
	free(result1);
	
	auto target2 = (char*) "Hello World  ";
	char *result2 = stringTrim(target2);
	ASSERT_STR(expect, result2);
	free(result2);
}

TEST (KernelStringProcess, StringJoin) {
	char *target[] = {
		(char *) "The",
		(char *) "quick",
		(char *) "brown",
		(char *) "fox",
		(char *) "jumps",
		(char *) "over",
		(char *) "the",
		(char *) "lazy",
		(char *) "dog",
		'\0'
	};
	auto delimiter = (char*) "|";
	auto expect = (char*) "The|quick|brown|fox|jumps|over|the|lazy|dog";
	char *result = stringJoin(target, delimiter);
	ASSERT_STR(expect, result);
	free(result);
}

TEST (KernelStringProcess, StringSplit) {
    auto target = (char*) "The|quick|brown|fox|jumps|over|the|lazy|dog";
    auto delimiter = (char*) "|";
	char **result = stringSplit(target, delimiter);
	ASSERT_STR("The", result[ 0 ]);
	ASSERT_STR("quick", result[ 1 ]);
	ASSERT_STR("brown", result[ 2 ]);
	ASSERT_STR("fox", result[ 3 ]);
	ASSERT_STR("jumps", result[ 4 ]);
	ASSERT_STR("over", result[ 5 ]);
	ASSERT_STR("the", result[ 6 ]);
	ASSERT_STR("lazy", result[ 7 ]);
	ASSERT_STR("dog", result[ 8 ]);
	freePointerPointerChar(result);
	
	target = (char*) "Nothing to split";
	result = stringSplit(target, delimiter);
	ASSERT_STR("Nothing to split", result[ 0 ]);
	freePointerPointerChar(result);
	
	auto url = (char*) "/abc?username=loint&password=123&firstName=Loi&lastName=Nguyen";
	char **url_components = stringSplit(url, (char*) "?");
	ASSERT_EQUAL(2, lengthPointerPointerChar(url_components));
	ASSERT_STR("/abc", url_components[ 0 ]);
	ASSERT_STR("username=loint&password=123&firstName=Loi&lastName=Nguyen", url_components[ 1 ]);
	freePointerPointerChar(url_components);
	
	target = (char*) "HTTP/1.1 200 OK\n"
		"Content-Type: application/json; charset=UTF-8\n"
		"Content-Length: 1498\r\n"
		"\r\n"
		"{\"took\":26,\"timed_out\":false,\"_shards\":{\"total\":2,\"successful\":2,\"failed\":0},\"hits\":{\"total\":1,\"max_score\":4.495634,\"hits\":[{\"_index\":\"db_foodtiny_test\",\"_type\":\"food_with_shop\",\"_id\":\"[\\\"ebc0aa50-3a26-11e7-9d38-8f725678c689\\\",\\\"05b05ff0-3a27-11e7-9d38-8f725678c689\\\"]\",\"_score\":4.495634,\"_source\":{\"food_discount\":0.0,\"food_name\":{\"en_EN\":\"Noodles with deep fried tofu, shrimp paste\",\"vi_VN\":\"Bún đậu mắm tôm\"},\"food_menu_name\":{\"en_EN\":\"Noodles\",\"vi_VN\":\"Bún\"},\"food_shop_online_status\":false,\"food_shop_type\":{\"en_EN\":\"Diner\",\"vi_VN\":\"Quán Ăn\"},\"food_shop_id\":\"ebc0aa50-3a26-11e7-9d38-8f725678c689\",\"food_shop_rating\":4.0,\"food_id\":\"05b05ff0-3a27-11e7-9d38-8f725678c689\",\"food_image\":\"http://healthplus.vn/Images/Uploaded/Share/2013/08/25/e9020130521111500eP8Qt3fV2.jpg\",\"food_shop_logo\":\"http://thpt.daytot.vn/files/thpt/chi-pheo.jpg\",\"food_shop_phone_number\":\"0112\",\"food_ingredient_1\":{\"en_EN\":\"Noodles\",\"vi_VN\":\"Bún\"},\"food_price\":45000.0,\"food_shop_address\":{\"en_EN\":\"818 Nguyen Kiem, Ward 3, Go Vap District, HCMC\",\"vi_VN\":\"818 Nguyễn Kiệm, Phường 3, Gò Vấp, Hồ Chí Minh\"},\"food_ingredient_2\":{\"en_EN\":\"tofu\",\"vi_VN\":\"Đậu hũ\"},\"food_ingredient_3\":{\"en_EN\":\"Shrimp paste\",\"vi_VN\":\"Mắm tôm\"},\"food_shop_name\":\"Bún đậu Thị Nở\",\"food_shop_start_time\":\"08:00\",\"location\":\"10.817053, 106.678834\",\"food_shop_delivery_status\":false,\"food_cooking_method\":{\"en_EN\":\"None\",\"vi_VN\":\"None\"},\"food_shop_quota_shipping\":100000.0,\"food_shop_finish_time\":\"21:00\"}}]}}";
	
	result = stringSplit(target, (char*) "\r\n\r\n");
	ASSERT_EQUAL(4, lengthPointerPointerChar(result));
	freePointerPointerChar(result);
}

TEST (KernelStringProcess, StringStartsWith) {
	auto target = (char*) "Hello World";
	auto prefix = (char*) "Hello";
	ASSERT_TRUE(stringStartswith(target, prefix));
	
	prefix = (char*) "Nope";
	ASSERT_FALSE(stringStartswith(target, prefix));
	
	prefix = (char*) "Prefix is longer than target";
	ASSERT_FALSE(stringStartswith(target, prefix));
}

TEST (KernelStringProcess, StringEndsWith) {
	auto target = (char*) "Hello World";
	auto suffix = (char*) "World";
	ASSERT_TRUE(stringEndswith(target, suffix));
	
	suffix = (char*) "Nope";
	ASSERT_FALSE(stringEndswith(target, suffix));
	
	suffix = (char*) "Suffix is longer than target";
	ASSERT_FALSE(stringEndswith(target, suffix));
	
	suffix = (char*) "Suffix is longer than target";
	ASSERT_FALSE(stringEndswith(target, suffix));
}

TEST (KernelStringProcess, StringIndexOf) {
	char *target = (char*) "Hello World";
	char *subtarget = (char*) "World";
	int result = stringIndex(target, subtarget, 1);
	ASSERT_EQUAL(6, result);
	
	target = (char*) "Hello World World World World";
	subtarget = (char*) "World";
	result = stringIndex(target, subtarget, 3);
	ASSERT_EQUAL(18, result);
	
	target = (char*) "Hello World World World World";
	subtarget = (char*) "orl";
	result = stringIndex(target, subtarget, 2);
	ASSERT_EQUAL(13, result);
	
	target = (char*) "###############";
	subtarget = (char*) "##";
	result = stringIndex(target, subtarget, 4);
	ASSERT_EQUAL(3, result);
	
	subtarget = (char*) "Substring is longer than target";
	result = stringIndex(target, subtarget, 1);
	ASSERT_EQUAL(-1, result);
	
	subtarget = (char*) "Hello";
	result = stringIndex(target, subtarget, 1);
	ASSERT_EQUAL(-1, result);
	
	subtarget = (char*) "Nope";
	result = stringIndex(target, subtarget, 1);
	ASSERT_EQUAL(-1, result);
	
	subtarget = (char*) "xxx";
	target = (char*) "";
	result = stringIndex(target, subtarget, 1);
	ASSERT_EQUAL(-1, result);
	
	subtarget = (char*) "";
	target = (char*) "";
	result = stringIndex(target, subtarget, 2);
	ASSERT_EQUAL(-1, result);
	
	subtarget = (char*) "";
	target = nullptr;
	result = stringIndex(target, subtarget, 2);
	ASSERT_EQUAL(-1, result);
	
	subtarget = NULL;
	target = NULL;
	result = stringIndex(target, subtarget, 2);
	ASSERT_EQUAL(-1, result);
	
	subtarget = (char*) "\0";
	target = (char*) "\0";
	result = stringIndex(target, subtarget, -1);
	ASSERT_EQUAL(-1, result);
	
	subtarget = (char*) "\0";
	target = NULL;
	result = stringIndex(target, subtarget, -1);
	ASSERT_EQUAL(-1, result);
	
	subtarget = NULL;
	target = (char*) "\0";
	result = stringIndex(target, subtarget, -1);
	ASSERT_EQUAL(-1, result);
}

TEST (KernelStringProcess, StringRandom) {
	char *target = (char*) "ABCXYZ";
	int size = 4;
	char *result = stringRandom(target, size);
	
	ASSERT_EQUAL(4, lengthPointerChar(result));
	free(result);
}

// TODO fix this @dquang
TEST (KernelStringProcess, StringAppend) {
	char *target = (char*) "Hello ";
	stringAppend(&target, 'W');
	
	void *pointer = target; // use pointer to keep old address on heap
	stringAppend(&target, 'o');
	free(pointer);
	
	pointer = target;
	stringAppend(&target, 'r');
	free(pointer);
	
	pointer = target;
	stringAppend(&target, 'l');
	free(pointer);
	
	pointer = target;
	stringAppend(&target, 'd');
	free(pointer);
	
	ASSERT_STR("Hello World", target);
	free(target);
}

TEST (KernelStringProcess, StringConcat) {
	auto target = (char*) "Hello";
    auto subtarget = (char*) "World";

    auto result = stringConcat(target, subtarget);
	ASSERT_STR("HelloWorld", result);
	ASSERT_EQUAL(10, lengthPointerChar(result));
	free(result);
	
	subtarget = (char*) "";
	result = stringConcat(target, subtarget);
	ASSERT_STR("Hello", result);
	ASSERT_EQUAL(5, lengthPointerChar(result));
	free(result);
}

TEST (KernelStringProcess, StringFromTo) {
	auto target = (char*) "Hello World";
	int from = 6;
	int to = 11;
	char *result = stringFromTo(target, from, to);
	char *expect = (char*) "World";
	ASSERT_STR(expect, result);
	free(result);
	
	from = 11;
	to = 6;
	result = stringFromTo(target, from, to);
	expect = (char*) "";
	ASSERT_STR(expect, result);
	free(result);
	
	from = -1;
	to = 11;
	result = stringFromTo(target, from, to);
	expect = (char*) "";
	ASSERT_STR(expect, result);
	free(result);
	
	from = 0;
	to = 20;
	result = stringFromTo(target, from, to);
	expect = (char*) "Hello World";
	ASSERT_STR(expect, result);
	free(result);
	
	target = (char*) "HTTP/1.0 200 OK\n"
		"Content-Type: text/html; charset=utf-8\n"
		"Content-Length: 122\n"
		"Server: Werkzeug/0.12.2 Python/2.7.12\n"
		"Date: Wed, 24 May 2017 19:14:29 GMT\n"
		"\n"
		"{\"multicast_id\":5160844598332076776,\"success\":0,"
		"\"failure\":1,\"canonical_ids\":0,"
		"\"results\":[{\"error\":\"InvalidRegistration\"}]}";
	from = 30;
	to = 53;
	result = stringFromTo(target, from, to);
	expect = (char*) "text/html; charset=utf-8";
	ASSERT_STR(expect, result);
	free(result);
}

TEST (KernelStringProcess, StringFrom) {
	char *target = (char*) "Hello World";
	int from = 6;
	char *result = stringFrom(target, from);
	char *expect = (char*) "World";
	ASSERT_STR(expect, result);
	free(result);
	
	from = -1;
	expect = (char*) "";
	result = stringFrom(target, from);
	ASSERT_STR(expect, result);
	free(result);
	
	from = 20;
	expect = (char*) "";
	result = stringFrom(target, from);
	ASSERT_STR(expect, result);
	free(result);
}

TEST (KernelStringProcess, StringTo) {
	char *target = (char*) "Hello World";
	int to = 4;
	char *result = stringTo(target, to);
	char *expect = (char*) "Hello";
	ASSERT_STR(expect, result);
	free(result);
	
	to = -1;
	expect = (char*) "";
	result = stringTo(target, to);
	ASSERT_STR(expect, result);
	free(result);
	
	to = 20;
	expect = (char*) "Hello World";
	result = stringTo(target, to);
	ASSERT_STR(expect, result);
	free(result);
}

TEST (KernelStringProcess, StringCopy) {
	char *target = (char*) "Hello World";
	char *result = strdup(target);
	ASSERT_STR(target, result);
	free(result);
	
	target = (char*) "";
	result = strdup(target);
	ASSERT_STR(target, result);
	free(result);
}

TEST (KernelStringProcess, StringUpper) {
	char *target = (char*) "Hello World";
	char *result = stringUpper(target);
	char *expect = (char*) "HELLO WORLD";
	ASSERT_STR(expect, result);
	free(result);
	
	target = (char*) "&*^&%&";
	result = stringUpper(target);
	ASSERT_STR(target, result);
	free(result);
	
	target = (char*) "JIJjifje&*^";
	result = stringUpper(target);
	expect = (char*) "JIJJIFJE&*^";
	ASSERT_STR(expect, result);
	free(result);
}

TEST (KernelStringProcess, StringLower) {
	char *target = (char*) "HELLO WORLD";
	char *result = stringLower(target);
	char *expect = (char*) "hello world";
	ASSERT_STR(expect, result);
	free(result);
	
	target = (char*) "&*%&*";
	result = stringLower(target);
	ASSERT_STR(target, result);
	free(result);
	
	target = (char*) "HIhahaHI!@#";
	result = stringLower(target);
	expect = (char*) "hihahahi!@#";
	ASSERT_STR(expect, result);
	free(result);
	
	target = (char*) "1";
	result = stringLower(target);
	expect = (char*) "1";
	ASSERT_STR(expect, result);
	free(result);
}

TEST (KernelStringProcess, StringTitle) {
	char *target = (char*) "hello world";
	char *result = stringTitle(target);
	char *expect = (char*) "Hello World";
	ASSERT_STR(expect, result);
	free(result);
	
	target = (char*) "#hi";
	expect = (char*) "#hi";
	result = stringTitle(target);
	ASSERT_STR(expect, result);
	free(result);
	
	target = (char*) "abcd";
	expect = (char*) "Abcd";
	result = stringTitle(target);
	ASSERT_STR(expect, result);
	free(result);
}

TEST (KernelStringProcess, StringStandardized) {
	char *target = (char*) "  hello  world ";
	char *expect = (char*) "hello world";
	char *result = stringStandardized(target);
	ASSERT_STR(expect, result);
	free(result);
	
	target = (char*) "     hello      world      world     ";
	expect = (char*) "hello world world";
	result = stringStandardized(target);
	ASSERT_STR(expect, result);
	free(result);
}

TEST (KernelStringProcess, StringEquals) {
	char *target1 = NULL;
	char *target2 = NULL;
	ASSERT_TRUE(stringEquals(target1, target2));
	
	target1 = (char *) "hello";
	target2 = NULL;
	ASSERT_FALSE(stringEquals(target1, target2));
	
	target1 = NULL;
	target2 = (char *) "hello";
	ASSERT_FALSE(stringEquals(target1, target2));
	
	target1 = (char*) "hello  world ";
	target2 = (char*) "  hello world";
	ASSERT_FALSE(stringEquals(target1, target2));
	
	target1 = (char*) "abcd";
	target2 = (char*) "abcd";
	ASSERT_TRUE(stringEquals(target1, target2));
}

TEST (KernelStringProcess, StringReverse) {
	char *target = (char*) "hello from other side";
	char *correct_reverse = (char*) "edis rehto morf olleh";
	char *wrong_reverse = (char*) "something here";
	
	char *reverse_of_target = stringReverse(target);
	
	
	// Test true with correct reverse string
	ASSERT_TRUE(stringEquals(correct_reverse, reverse_of_target));
	
	// Test fail with wrong reverse string
	ASSERT_FALSE(stringEquals(wrong_reverse, reverse_of_target));
	
	free(reverse_of_target);
}

TEST (KernelStringProcess, StringMatches) {
	char *target = (char*) "hello from other side";
	char *correct_reverse = (char*) "edis rehto morf olleh";
	char *wrong_reverse = (char*) "something here";
	
	char *reverse_of_target = stringReverse(target);
	
	// Test true with correct reverse string
	ASSERT_TRUE(stringEquals(correct_reverse, reverse_of_target));
	
	// Test fail with wrong reverse string
	ASSERT_FALSE(stringEquals(wrong_reverse, reverse_of_target));
	free(reverse_of_target);
}


