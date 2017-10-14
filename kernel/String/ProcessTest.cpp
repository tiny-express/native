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

#include "../Kernel.hpp"
#include "../Test.hpp"

TEST (KernelStringProcess, StringReplace) {
    auto target = (string) "Hello World";
    auto find_string = (string) "World";
    auto replace_with = (string) "Food Tiny";
    auto expect = (string) "Hello Food Tiny";
    auto result = stringReplace(target, find_string, replace_with);
	assertEquals(expect, result);
	free(result);

    auto target2 = (string) "Hello World";
    auto find_string2 = (string) "Nothing";
	auto replace_with2 = (string) "Food Tiny";
    auto expect2 = (string) "Hello World";
    auto result2 = stringReplace(target2, find_string2, replace_with2);
	assertEquals(expect2, result2);
	free(result2);
	
	auto target3 = (string) "aaa bbededeb cccccc de dd eeeede";
    auto find_string3 = (string) "de";
    auto replace_with3 = (string) "ff";
    auto expect3 = (string) "aaa bbeffffb cccccc ff dd eeeeff";
    auto result3 = stringReplace(target3, find_string3, replace_with3);
	assertEquals(expect3, result3);
	free(result3);
	
	auto target4 = (string) "aaaaaaaaaaaffffffffffffffffff";
    auto find_string4 = (string) "aa";
    auto replace_with4 = (string) "o";
    auto expect4 = (string) "oooooaffffffffffffffffff";
    auto result4 = stringReplace(target4, find_string4, replace_with4);
	assertEquals(expect4, result4);
	free(result4);

    auto target5 = (string) "a";
    auto find_string5 = (string) "aaaaaaaaaaaaaaaaaaaa";
    auto replace_with5 = (string) "o";
    auto result5 = stringReplace(target5, find_string5, replace_with5);
	assertEquals("a", result5);
	free(result5);
}

TEST (KernelStringProcess, StringTrim) {
    auto expect = (string) "Hello World";
    auto target = (string) "  Hello World  ";
    auto result = stringTrim(target);
	assertEquals(expect, result);
	free(result);

    auto target1 = (string) "  Hello World";
	char *result1 = stringTrim(target1);
	assertEquals(expect, result1);
	free(result1);
	
	auto target2 = (string) "Hello World  ";
	char *result2 = stringTrim(target2);
	assertEquals(expect, result2);
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
		nullptr
	};
	auto delimiter = (string) "|";
	auto expect = (string) "The|quick|brown|fox|jumps|over|the|lazy|dog";
	char *result = stringJoin(target, delimiter);
	assertEquals(expect, result);
	free(result);
}

TEST (KernelStringProcess, StringSplit) {
    auto target = (string) "The|quick|brown|fox|jumps|over|the|lazy|dog";
    auto delimiter = (string) "|";
	char **result = stringSplit(target, delimiter);
	assertEquals("The", result[ 0 ]);
	assertEquals("quick", result[ 1 ]);
	assertEquals("brown", result[ 2 ]);
	assertEquals("fox", result[ 3 ]);
	assertEquals("jumps", result[ 4 ]);
	assertEquals("over", result[ 5 ]);
	assertEquals("the", result[ 6 ]);
	assertEquals("lazy", result[ 7 ]);
	assertEquals("dog", result[ 8 ]);
	freePointerPointerChar(result);
	
	target = (string) "Nothing to split";
	result = stringSplit(target, delimiter);
	assertEquals("Nothing to split", result[ 0 ]);
	freePointerPointerChar(result);
	
	auto url = (string) "/abc?username=loint&password=123&firstName=Loi&lastName=Nguyen";
	char **url_components = stringSplit(url, (string) "?");
	assertEquals(2, lengthPointerPointerChar(url_components));
	assertEquals("/abc", url_components[ 0 ]);
	assertEquals("username=loint&password=123&firstName=Loi&lastName=Nguyen", url_components[ 1 ]);
	freePointerPointerChar(url_components);
	
	target = (string) "HTTP/1.1 200 OK\n"
		"Content-Type: application/json; charset=UTF-8\n"
		"Content-Length: 1498\r\n"
		"\r\n"
		"{\"took\":26,\"timed_out\":false,\"_shards\":{\"total\":2,\"successful\":2,\"failed\":0},\"hits\":{\"total\":1,\"max_score\":4.495634,\"hits\":[{\"_index\":\"db_foodtiny_test\",\"_type\":\"food_with_shop\",\"_id\":\"[\\\"ebc0aa50-3a26-11e7-9d38-8f725678c689\\\",\\\"05b05ff0-3a27-11e7-9d38-8f725678c689\\\"]\",\"_score\":4.495634,\"_source\":{\"food_discount\":0.0,\"food_name\":{\"en_EN\":\"Noodles with deep fried tofu, shrimp paste\",\"vi_VN\":\"Bún đậu mắm tôm\"},\"food_menu_name\":{\"en_EN\":\"Noodles\",\"vi_VN\":\"Bún\"},\"food_shop_online_status\":false,\"food_shop_type\":{\"en_EN\":\"Diner\",\"vi_VN\":\"Quán Ăn\"},\"food_shop_id\":\"ebc0aa50-3a26-11e7-9d38-8f725678c689\",\"food_shop_rating\":4.0,\"food_id\":\"05b05ff0-3a27-11e7-9d38-8f725678c689\",\"food_image\":\"http://healthplus.vn/Images/Uploaded/Share/2013/08/25/e9020130521111500eP8Qt3fV2.jpg\",\"food_shop_logo\":\"http://thpt.daytot.vn/files/thpt/chi-pheo.jpg\",\"food_shop_phone_number\":\"0112\",\"food_ingredient_1\":{\"en_EN\":\"Noodles\",\"vi_VN\":\"Bún\"},\"food_price\":45000.0,\"food_shop_address\":{\"en_EN\":\"818 Nguyen Kiem, Ward 3, Go Vap District, HCMC\",\"vi_VN\":\"818 Nguyễn Kiệm, Phường 3, Gò Vấp, Hồ Chí Minh\"},\"food_ingredient_2\":{\"en_EN\":\"tofu\",\"vi_VN\":\"Đậu hũ\"},\"food_ingredient_3\":{\"en_EN\":\"Shrimp paste\",\"vi_VN\":\"Mắm tôm\"},\"food_shop_name\":\"Bún đậu Thị Nở\",\"food_shop_start_time\":\"08:00\",\"location\":\"10.817053, 106.678834\",\"food_shop_delivery_status\":false,\"food_cooking_method\":{\"en_EN\":\"None\",\"vi_VN\":\"None\"},\"food_shop_quota_shipping\":100000.0,\"food_shop_finish_time\":\"21:00\"}}]}}";
	
	result = stringSplit(target, (string) "\r\n\r\n");
	assertEquals(4, lengthPointerPointerChar(result));
	freePointerPointerChar(result);
}

TEST (KernelStringProcess, StringStartsWith) {
	auto target = (string) "Hello World";
	auto prefix = (string) "Hello";
	assertTrue(stringStartswith(target, prefix));
	
	prefix = (string) "Nope";
	assertFalse(stringStartswith(target, prefix));
	
	prefix = (string) "Prefix is longer than target";
	assertFalse(stringStartswith(target, prefix));
}

TEST (KernelStringProcess, StringEndsWith) {
	auto target = (string) "Hello World";
	auto suffix = (string) "World";
	assertTrue(stringEndswith(target, suffix));
	
	suffix = (string) "Nope";
	assertFalse(stringEndswith(target, suffix));
	
	suffix = (string) "Suffix is longer than target";
	assertFalse(stringEndswith(target, suffix));
	
	suffix = (string) "Suffix is longer than target";
	assertFalse(stringEndswith(target, suffix));
}

TEST (KernelStringProcess, StringIndexOf) {
	auto target = (string) "Hello World";
	auto subTarget = (string) "World";
	int result = stringIndex(target, subTarget, 1);
	assertEquals(6, result);
	
	target = (string) "Hello World World World World";
	subTarget = (string) "World";
	result = stringIndex(target, subTarget, 3);
	assertEquals(18, result);
	
	target = (string) "Hello World World World World";
	subTarget = (string) "orl";
	result = stringIndex(target, subTarget, 2);
	assertEquals(13, result);
	
	target = (string) "###############";
	subTarget = (string) "##";
	result = stringIndex(target, subTarget, 4);
	assertEquals(3, result);
	
	subTarget = (string) "Substring is longer than target";
	result = stringIndex(target, subTarget, 1);
	assertEquals(-1, result);
	
	subTarget = (string) "Hello";
	result = stringIndex(target, subTarget, 1);
	assertEquals(-1, result);
	
	subTarget = (string) "Nope";
	result = stringIndex(target, subTarget, 1);
	assertEquals(-1, result);
	
	subTarget = (string) "xxx";
	target = (string) "";
	result = stringIndex(target, subTarget, 1);
	assertEquals(-1, result);
	
	subTarget = (string) "";
	target = (string) "";
	result = stringIndex(target, subTarget, 2);
	assertEquals(-1, result);
	
	subTarget = (string) "";
	target = nullptr;
	result = stringIndex(target, subTarget, 2);
	assertEquals(-1, result);
	
	subTarget = nullptr;
	target = nullptr;
	result = stringIndex(target, subTarget, 2);
	assertEquals(-1, result);
	
	subTarget = (string) "\0";
	target = (string) "\0";
	result = stringIndex(target, subTarget, -1);
	assertEquals(-1, result);
	
	subTarget = (string) "\0";
	target = nullptr;
	result = stringIndex(target, subTarget, -1);
	assertEquals(-1, result);
	
	subTarget = nullptr;
	target = (string) "\0";
	result = stringIndex(target, subTarget, -1);
	assertEquals(-1, result);
}

TEST (KernelStringProcess, StringRandom) {
	auto target = (string) "ABCXYZ";
	int size = 4;
	char *result = stringRandom(target, size);
	
	assertEquals(4, lengthPointerChar(result));
	free(result);
}

TEST (KernelStringProcess, StringAppend) {
	auto target = (string) "Hello ";
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
	
	assertEquals("Hello World", target);
	free(target);
}

TEST (KernelStringProcess, StringConcat) {
	auto target = (string) "Hello";
    auto subTarget = (string) "World";

    auto result = stringConcat(target, subTarget);
	assertEquals("HelloWorld", result);
	assertEquals(10, lengthPointerChar(result));
	free(result);
	
	subTarget = (string) "";
	result = stringConcat(target, subTarget);
	assertEquals("Hello", result);
	assertEquals(5, lengthPointerChar(result));
	free(result);
}

TEST (KernelStringProcess, StringFromTo) {
	auto target = (string) "Hello World";
	int from = 6;
	int to = 11;
	char *result = stringFromTo(target, from, to);
	auto expect = (string) "World";
	assertEquals(expect, result);
	free(result);
	
	from = 11;
	to = 6;
	result = stringFromTo(target, from, to);
	expect = (string) "";
	assertEquals(expect, result);
	free(result);
	
	from = -1;
	to = 11;
	result = stringFromTo(target, from, to);
	expect = (string) "";
	assertEquals(expect, result);
	free(result);
	
	from = 0;
	to = 20;
	result = stringFromTo(target, from, to);
	expect = (string) "Hello World";
	assertEquals(expect, result);
	free(result);
	
	target = (string) "HTTP/1.0 200 OK\n"
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
	expect = (string) "text/html; charset=utf-8";
	assertEquals(expect, result);
	free(result);
}

TEST (KernelStringProcess, StringFrom) {
	auto target = (string) "Hello World";
	int from = 6;
	char *result = stringFrom(target, from);
	auto expect = (string) "World";
	assertEquals(expect, result);
	free(result);
	
	from = -1;
	expect = (string) "";
	result = stringFrom(target, from);
	assertEquals(expect, result);
	free(result);
	
	from = 20;
	expect = (string) "";
	result = stringFrom(target, from);
	assertEquals(expect, result);
	free(result);
}

TEST (KernelStringProcess, StringTo) {
	auto target = (string) "Hello World";
	int to = 4;
	char *result = stringTo(target, to);
	auto expect = (string) "Hello";
	assertEquals(expect, result);
	free(result);
	
	to = -1;
	expect = (string) "";
	result = stringTo(target, to);
	assertEquals(expect, result);
	free(result);
	
	to = 20;
	expect = (string) "Hello World";
	result = stringTo(target, to);
	assertEquals(expect, result);
	free(result);
}

TEST (KernelStringProcess, StringCopy) {
	auto target = (string) "Hello World";
	char *result = stringCopy(target);
	assertEquals(target, result);
	free(result);
	
	target = (string) "";
	result = stringCopy(target);
	assertEquals(target, result);
	free(result);
}

TEST (KernelStringProcess, StringUpper) {
	auto target = (string) "Hello World";
	char *result = stringUpper(target);
	auto expect = (string) "HELLO WORLD";
	assertEquals(expect, result);
	free(result);
	
	target = (string) "&*^&%&";
	result = stringUpper(target);
	assertEquals(target, result);
	free(result);
	
	target = (string) "JIJjifje&*^";
	result = stringUpper(target);
	expect = (string) "JIJJIFJE&*^";
	assertEquals(expect, result);
	free(result);
}

TEST (KernelStringProcess, StringLower) {
	auto target = (string) "HELLO WORLD";
	char *result = stringLower(target);
	auto expect = (string) "hello world";
	assertEquals(expect, result);
	free(result);
	
	target = (string) "&*%&*";
	result = stringLower(target);
	assertEquals(target, result);
	free(result);
	
	target = (string) "HIhahaHI!@#";
	result = stringLower(target);
	expect = (string) "hihahahi!@#";
	assertEquals(expect, result);
	free(result);
	
	target = (string) "1";
	result = stringLower(target);
	expect = (string) "1";
	assertEquals(expect, result);
	free(result);
}

TEST (KernelStringProcess, StringTitle) {
	auto target = (string) "hello world";
	char *result = stringTitle(target);
	auto expect = (string) "Hello World";
	assertEquals(expect, result);
	free(result);
	
	target = (string) "#hi";
	expect = (string) "#hi";
	result = stringTitle(target);
	assertEquals(expect, result);
	free(result);
	
	target = (string) "abcd";
	expect = (string) "Abcd";
	result = stringTitle(target);
	assertEquals(expect, result);
	free(result);
}

TEST (KernelStringProcess, StringStandardized) {
	auto target = (string) "  hello  world ";
	auto expect = (string) "hello world";
	char *result = stringStandardized(target);
	assertEquals(expect, result);
	free(result);
	
	target = (string) "     hello      world      world     ";
	expect = (string) "hello world world";
	result = stringStandardized(target);
	assertEquals(expect, result);
	free(result);
}

TEST (KernelStringProcess, StringEquals) {
	char *target1 = nullptr;
	char *target2 = nullptr;
	assertTrue(stringEquals(target1, target2));
	
	target1 = (char *) "hello";
	target2 = nullptr;
	assertFalse(stringEquals(target1, target2));
	
	target1 = nullptr;
	target2 = (char *) "hello";
	assertFalse(stringEquals(target1, target2));
	
	target1 = (string) "hello  world ";
	target2 = (string) "  hello world";
	assertFalse(stringEquals(target1, target2));
	
	target1 = (string) "abcd";
	target2 = (string) "abcd";
	assertTrue(stringEquals(target1, target2));
}

TEST (KernelStringProcess, StringReverse) {
	auto target = (string) "hello from other side";
	auto correctReverse = (string) "edis rehto morf olleh";
	auto wrongReverse = (string) "something here";
	
	char *reverseOfTarget = stringReverse(target);

	// Test true with correct reverse string
	assertTrue(stringEquals(correctReverse, reverseOfTarget));
	
	// Test fail with wrong reverse string
	assertFalse(stringEquals(wrongReverse, reverseOfTarget));
	
	free(reverseOfTarget);
}

TEST (KernelStringProcess, StringMatches) {
	auto target = (string) "hello from other side";
	auto correctReverse = (string) "edis rehto morf olleh";
	auto wrongReverse = (string) "something here";
	
	char *reverseOfTarget = stringReverse(target);
	
	// Test true with correct reverse string
	assertTrue(stringEquals(correctReverse, reverseOfTarget));
	
	// Test fail with wrong reverse string
	assertFalse(stringEquals(wrongReverse, reverseOfTarget));
	free(reverseOfTarget);
}


