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
#include "../unit_test.h"
}
#include "../native.h"
#include <iostream>

TEST(Generic, Integer) {

    int integer_to_integer = Integer(2345);
    ASSERT_EQUAL(2345, integer_to_integer);

    int float_to_integer = Integer(1.234);
    ASSERT_EQUAL(1, float_to_integer);

    int string_to_integer = Integer(std::string("123456"));
    ASSERT_EQUAL(123456, string_to_integer);

    int string_to_integer_not_valid = Integer((char*) "Hello world");
    ASSERT_EQUAL(0, string_to_integer_not_valid);

    int string_to_integer_valid_1 = Integer((char*) "-12345");
    ASSERT_EQUAL(-12345, string_to_integer_valid_1);

    int string_to_integer_valid_2 = Integer((char*) "-123.45");
    ASSERT_EQUAL(-123, string_to_integer_valid_2);

}