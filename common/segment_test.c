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

TEST(Common, SegmentPointerType) {
    char *charArray = "Hello World";
    int from = 6;
    int to = 10;
    char *result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(5, length_pointer_char(result));
    ASSERT_STR("World", result);

    from = 6;
    to = 6;
    result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(1, length_pointer_char(result));
    ASSERT_STR("W", result);

    from = 7;
    to = 6;
    result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(0, length_pointer_char(result));
    ASSERT_STR("", result);

    from = -1;
    to = -1;
    result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(0, length_pointer_char(result));
    ASSERT_STR("", result);


    from = -10;
    to = -2;
    result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(0, length_pointer_char(result));
    ASSERT_STR("", result);

    from = -3;
    to = 4;
    result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(0, length_pointer_char(result));
    ASSERT_STR("", result);

    from = 0;
    to = 15;
    result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(11, length_pointer_char(result));
    ASSERT_STR("Hello World", result);

    from = 15;
    to = 20;
    result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(0, length_pointer_char(result));
    ASSERT_STR("", result);

    charArray = NULL;
    from = 15;
    to = 20;
    result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(0, length_pointer_char(result));
    ASSERT_STR("", result);

    from = 15;
    to = 20;
    result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(0, length_pointer_char(result));
    ASSERT_STR("", result);

    charArray = "";
    from = 1;
    to = 10;
    result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(0, length_pointer_char(result));
    ASSERT_STR("", result);

    charArray = "\0";
    from = 0;
    to = 1;
    result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(0, length_pointer_char(result));
    ASSERT_STR("", result);

    charArray = "\0";
    from = 0;
    to = 0;
    result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(0, length_pointer_char(result));
    ASSERT_STR("", result);
}

TEST(Common, SegmentPointerConstChar) {
    char *charArray = "Hello World";
    int from = 6;
    int to = 6;
    char *result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(1, length_pointer_char(result));
    ASSERT_STR("W", result);

    from = 7;
    to = 6;
    result = segment_pointer_char(charArray, from, to);
    ASSERT_EQUAL(0, length_pointer_char(result));
    ASSERT_STR("", result);
}

TEST(Common, SegmentPointerPointerChar) {
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
    ASSERT_STR("brown|fox|jumps|over", string_join(result, "|"));
}