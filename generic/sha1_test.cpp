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
#include "../library.hpp"

TEST(Generic, Sha1) {
    char *result1 = sha1(NULL);
    const char *expect1 = "b6589fc6ab0dc82cf12099d1c2d40ab994e8410c";
    ASSERT_STR(expect1, result1);

    short shortNumber = 1234;
    char *result2 = sha1(shortNumber);
    const char *expect2 = "7110eda4d09e062aa5e4a390b0a572ac0d2c0220";
    ASSERT_STR(expect2, result2);

    long longNumber = 0;
    char *result3 = sha1(longNumber);
    const char *expect3 = "b6589fc6ab0dc82cf12099d1c2d40ab994e8410c";
    ASSERT_STR(expect3, result3);

    double doubleNumber = 132412.341234;
    char *result4 = sha1(doubleNumber);
    const char *expect4 = "40c745a7a3890bf3dde11e88464e20638d229ef4";
    ASSERT_STR(expect4, result4);

    std::string str = "happy";
    char *result5 = sha1(str);
    const char *expect5 = "3978d009748ef54ad6ef7bf851bd55491b1fe6bb";
    ASSERT_STR(expect5, result5);

    char *pointerChar = (char *)"";
    char *result6 = sha1(pointerChar);
    const char *expect6 = "da39a3ee5e6b4b0d3255bfef95601890afd80709";
    ASSERT_STR(expect6, result6);
}

