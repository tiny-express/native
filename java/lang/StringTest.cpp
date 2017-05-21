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

extern "C" {
#include "../../unit_test.h"
}
#include "String.hpp"

using namespace Java::Lang;

TEST(JavaLang, String) {

    String string_empty;
    string_empty = "Hello world";
    ASSERT_STR("Hello world", string_empty.cstringValue());

    byte bytes[3] = {65, 66, 67};
    String string_bytes = bytes;
    ASSERT_STR("ABC", string_bytes.cstringValue());

    String string_text_with_length = "Hello world";
    ASSERT_STR("Hello world", string_text_with_length.cstringValue());

    String string_text_plus_1 = "Hello ";
    String string_text_plus_2 = "World";
    String string_result_plus = string_text_plus_1 + string_text_plus_2;
    ASSERT_STR("Hello World", string_result_plus.cstringValue());

    String string_text_compare_equal_1 = "Hello";
    String string_text_compare_equal_2 = "Hello";
    int comparable_equal = FALSE;
    if (string_text_compare_equal_1 == string_text_compare_equal_2) {
        comparable_equal = TRUE;
    }
    ASSERT_TRUE(comparable_equal);

    String string_text_compare_not_equal_1 = "Hello1";
    String string_text_compare_not_equal_2 = "Hello2";
    int comparable_not_equal = FALSE;
    if (string_text_compare_not_equal_1 != string_text_compare_not_equal_2) {
        comparable_not_equal = TRUE;
    }
    ASSERT_TRUE(comparable_not_equal);

    char *given_string_with_length = "Hello world";
    String string_with_length = given_string_with_length;
    ASSERT_STR(given_string_with_length, string_with_length.cstringValue());
    ASSERT_EQUAL(11, string_with_length.length());

    char given_char = '\0';
    String *string_from_char = String::parseChar(given_char);
    ASSERT_STR((char*) "\0", string_from_char->cstringValue());

    char *given_char_pointer = (char*) "Hello world";
    String *string_from_char_pointer = String::parseCString(given_char_pointer);
    ASSERT_STR(given_char_pointer, string_from_char_pointer->cstringValue());

    std::string given_std_string = std::string("hello world");
    String *string_from_std_string = String::parseString(given_std_string);
    ASSERT_STR(given_std_string.c_str(), string_from_std_string->cstringValue());

    short given_short = 5;
    String *string_from_short = String::parseShort(given_short);
    ASSERT_EQUAL(given_short, string_from_short->shortValue());

    int given_int = 34567;
    String *string_from_int = String::parseInt(given_int);
    ASSERT_EQUAL(given_int, string_from_int->intValue());

    long given_long = (long) 10000000000;
    String *string_from_long = String::parseLong(given_long);
    ASSERT_EQUAL(given_long, string_from_long->longValue());

    float given_float = (float) 5.68;
    String *string_from_float = String::parseFloat(given_float);
    ASSERT_EQUAL(given_float, string_from_float->floatValue());

    long given_double = (long) 456.324234234234234234234234234234;
    String *string_from_double = String::parseDouble(given_double);
    ASSERT_EQUAL(given_double, string_from_double->doubleValue());
}