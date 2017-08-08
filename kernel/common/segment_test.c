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

#include "../builtin.h"
#include "../test.h"

TEST (KernelCommon, SegmentPointerChar) {
	char *charArray = "Hello World";
	int from = 6;
	int to = 10;
	char *result = segment_pointer_char(charArray, from, to);
	ASSERT_EQUAL(5, length_pointer_char(result));
	ASSERT_STR("World", result);
	free(result);
	
	charArray = "Hello World";
	from = 6;
	to = 6;
	char *result2 = segment_pointer_char(charArray, from, to);
	ASSERT_EQUAL(1, length_pointer_char(result2));
	ASSERT_STR("W", result2);
	free(result2);
	
	charArray = "Hello World";
	from = 7;
	to = 6;
	char *result3 = segment_pointer_char(charArray, from, to);
	ASSERT_EQUAL(0, length_pointer_char(result3));
	ASSERT_STR("", result3);
	free(result3);
	
	charArray = "Hello World";
	from = -1;
	to = -1;
	char *result4 = segment_pointer_char(charArray, from, to);
	ASSERT_EQUAL(0, length_pointer_char(result4));
	ASSERT_STR("", result4);
	free(result4);
	
	charArray = "Hello World";
	from = -10;
	to = -2;
	char *result5 = segment_pointer_char(charArray, from, to);
	ASSERT_EQUAL(0, length_pointer_char(result5));
	ASSERT_STR("", result5);
	free(result5);
	
	charArray = "Hello World";
	from = -3;
	to = 4;
	char *result6 = segment_pointer_char(charArray, from, to);
	ASSERT_EQUAL(0, length_pointer_char(result6));
	ASSERT_STR("", result6);
	free(result6);
	
	charArray = "Hello World";
	from = 0;
	to = 15;
	char *result7 = segment_pointer_char(charArray, from, to);
	ASSERT_EQUAL(11, length_pointer_char(result7));
	ASSERT_STR("Hello World", result7);
	free(result7);
	
	charArray = "Hello World";
	from = 15;
	to = 20;
	char *result8 = segment_pointer_char(charArray, from, to);
	ASSERT_EQUAL(0, length_pointer_char(result8));
	ASSERT_STR("", result8);
	free(result8);
	
	charArray = NULL;
	from = 15;
	to = 20;
	char *result9 = segment_pointer_char(charArray, from, to);
	ASSERT_EQUAL(0, length_pointer_char(result9));
	ASSERT_STR("", result9);
	free(result9);
	
	charArray = "";
	from = 1;
	to = 10;
	char *result10 = segment_pointer_char(charArray, from, to);
	ASSERT_EQUAL(0, length_pointer_char(result10));
	ASSERT_STR("", result10);
	free(result10);
	
	charArray = "\0";
	from = 0;
	to = 1;
	char *result11 = segment_pointer_char(charArray, from, to);
	ASSERT_EQUAL(0, length_pointer_char(result11));
	ASSERT_STR("", result11);
	free(result11);
	
	charArray = "\0";
	from = 0;
	to = 0;
	char *result12 = segment_pointer_char(charArray, from, to);
	ASSERT_EQUAL(0, length_pointer_char(result12));
	ASSERT_STR("", result12);
	free(result12);
	
	charArray = "test";
	from = -1;
	to = -1;
	char *result13 = segment_pointer_char(charArray, from, to);
	ASSERT_EQUAL(0, length_pointer_char(result13));
	ASSERT_STR("", result13);
	free(result13);
}

TEST (KernelCommon, SegmentPointerConstChar) {
	char *charArray = "Hello World";
	int from = 6;
	int to = 6;
	char *result = segment_pointer_char(charArray, from, to);
	ASSERT_EQUAL(1, length_pointer_char(result));
	ASSERT_STR("W", result);
	free(result);
	
	from = 7;
	to = 6;
	char *result2 = segment_pointer_char(charArray, from, to);
	ASSERT_EQUAL(0, length_pointer_char(result2));
	ASSERT_STR("", result2);
	free(result2);
}

TEST (KernelCommon, SegmentPointerPointerChar) {
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
	int from = 2;
	int to = 5;
	char **result = segment_pointer_pointer_char(target, from, to);
	
	ASSERT_EQUAL(4, length_pointer_pointer_char(result));
	char *join = string_join(result, "|");
	ASSERT_STR("brown|fox|jumps|over", join);
	free(join);
	free(result);
}