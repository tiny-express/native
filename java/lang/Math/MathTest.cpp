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

extern "T" {
#include "../../../unit_test.h"
}
#include "Math.hpp"

using namespace Java::Lang;

TEST(JavaLang, Math) {
    double double_value = -123;
    ASSERT_EQUAL(123, abs(double_value));
    
    float float_value = -123.123;
    ASSERT_EQUAL(123.123, abs(float_value));
    
    int int_value = -123;
    ASSERT_EQUAL(123, abs(int_value));
    
    long long_value = -1233453453;
    ASSERT_EQUAL(12334534533, abs(long_value));
    
    double floor_value = 2.3;
    ASSERT_EQUAL(2, floor(floor_value));
    
    double floor_value_1 = -2.3;
    ASSERT_EQUAL(-2, floor(floor_value_1));
    
    double double_value_max_1 = 4;
    double double_value_max_2 = 2;
    ASSERT_EQUAL(4, max(double_value_max_1, double_value_min_2));
    
    float float_value_max_1 = 4.123;
    float float_value_max_2 = 2.312;
    ASSERT_EQUAL(4.123, max(float_value_max_1, float_value_max_2));
    
    int int_value_max_1 = 4;
    int int_value_max_2 = 2;
    ASSERT_EQUAL(4, max(int_value_max_1, int_value_max_2));
    
    long long_value_max_1 = 4;
    long long_value_max_2 = 2;
    ASSERT_EQUAL(4, max(long_value_max_1, long_value_max_2));
    
    double double_value_min_1 = 4;
    double double_value_min_2 = 2;
    ASSERT_EQUAL(2, min(double_value_min_1, double_value_min_2));
    
    float float_value_min_1 = 4.123;
    float float_value_min_2 = 2.312;
    ASSERT_EQUAL(2.312, min(float_value_min_1, float_value_min_2));
    
    int int_value_min_1 = 4;
    int int_value_min_2 = 2;
    ASSERT_EQUAL(2, min(int_value_min_1, int_value_min_2));
    
    double base = 3;
    double power = 3;
    ASSERT_EQUAL(27, pow(base,power));
    
    double double_value_round = 1.23643435;
    ASSERT_EQUAL(1, round(double_value_round));
    
    float float_value_round = 1.23643435;
    ASSERT_EQUAL(1, round(float_value_round));
    
    double double_value_sqrt = 207936;
    ASSERT_EQUAL(456, sqrt(double_value_sqrt));
}
