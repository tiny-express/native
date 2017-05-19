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

TEST(Generic, Boolean) {
    
    double boolean_to_boolean = Boolean(1);
    ASSERT_EQUAL(1, boolean_to_boolean);
        
    double string_to_boolean = Boolean(std::string("True"));
    ASSERT_EQUAL(1, string_to_boolean);

    double string_to_boolean_not_valid = Boolean((char*) "True");
    ASSERT_EQUAL(0, string_to_boolean_not_valid);
    
    double double_to_boolean = Boolean(2.3E-3);
    ASSERT_EQUAL(0, double_to_boolean);
    
    double long_to_boolean = Boolean(2147483647);
    ASSERT_EQUAL(1, long_to_boolean);

    double integer_to_boolean = Boolean(2345);
    ASSERT_EQUAL(1, integer_to_boolean);

    double float_to_boolean = Boolean(234231.234);
    ASSERT_EQUAL(1, float_to_boolean);
}