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
#include "../native.hpp"

TEST(Generic, String) {

    char given_char = '\0';
    char *expect_string_char_pointer_0 = (char*) "\0";
    ASSERT_STR(expect_string_char_pointer_0, String(given_char));

    const char* given_constant_pointer_char = "hello world";
    char *expect_string_char_pointer_1 = (char*) "hello world";
    ASSERT_STR(expect_string_char_pointer_1, String(given_constant_pointer_char));

    std::string given_std_string = std::string("hello world");
    char *expect_string_char_pointer_2 = (char*) "hello world";
    ASSERT_STR(expect_string_char_pointer_2, String(given_std_string));

    char *result1 = String(3);
    const char *expect1 = "3";
    ASSERT_STR(expect1, result1);

    char *result2 = String(4039249.5023);
    const char *expect2 = "4039249.5023";
    ASSERT_STR(expect2, result2);

    std::vector<int> vectorInt(4, 2000);
    char *result4 = String(vectorInt);
    const char *expect4 = "[2000, 2000, 2000, 2000]";
    ASSERT_STR(expect4, result4);
    delete result4;

    std::vector<double> vectorDouble(4, 12.3457);
    char *result5 = String(vectorDouble);
    const char *expect5 = "[12.3457, 12.3457, 12.3457, 12.3457]";
    ASSERT_STR(expect5, result5);
    delete result5;

}

