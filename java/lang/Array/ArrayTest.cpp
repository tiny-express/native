///**
// * Copyright (c) 2016 Food Tiny Project. All rights reserved.
// *
// * Redistribution and use in source and binary forms, with or without
// * modification, are permitted provided that the following conditions are met:
// *
// * Redistributions of source code must retain the above copyright
// * notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above
// * copyright notice, this list of conditions and the following disclaimer
// * in the documentation and/or other materials provided with the
// * distribution.
// *
// * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// */
//
//extern "C" {
//#include "../../../unit_test.h"
//}
//
//#include "Array.hpp"
//
//using namespace Java::Lang;
//
//TEST(JavaLang, ArrayConstructor) {
////    // Test constructor no argument
////    Array<int> validArray;
////    int expect = 0;
////    int result = validArray.length();
////    ASSERT_EQUAL(expect, result);
////
////    // Test constructor with length
////    Array<int> validArray1(10);
////    expect = 10;
////    result = validArray1.length();
////    ASSERT_EQUAL(expect, result );
////
////    // Test constructor with length and default value
////    int length = 10;
////    Array<int> validArray2(length, 1);
////
////    int index;
////    for (index = 0; index < length; ++index) {
////        ASSERT_EQUAL(validArray2[index], 1);
////    }
////
////    // Test copy constructor
////    Array<int> validArray3(validArray2);
////
////    expect = 10;
////    result = validArray3.length();
////    ASSERT_EQUAL(expect, result);
////
////    for (index = 0; index < length; ++index) {
////        ASSERT_EQUAL(validArray3[index], 1);
////    }
//}
//
//
//TEST(JavaLang, ArrayLength) {
////    // Test length of empty Array
////    Array<int> emptyArray;
////    int expect = 0;
////    int result = emptyArray.length();
////    ASSERT_EQUAL(expect, result);
////
////    // Test is empty
////    boolean isEmpty = emptyArray.isEmpty();
////    ASSERT_TRUE(isEmpty);
////
////    // Test length of empty Array
////    int length = 10;
////    Array<int> validArray(length);
////    result = validArray.length();
////    ASSERT_EQUAL(length, result);
////
////    // Test is not empty
////    boolean notEmpty = validArray.isEmpty();
////    ASSERT_FALSE(notEmpty);
////
////    // Test length of validArray after push one element
////    validArray.push(123);
////    expect = 11;
////    result = validArray.length();
////    ASSERT_EQUAL(expect, result);
//}
//
//TEST(Javalang, ArrayFunction) {
////    Array<int> validArray;
////
////    int length = 10;
////    int index;
////
////    // Test push element to Array
////    for (index = 0; index < length; ++index) {
////        validArray.push(index);
////    }
////
////    // Test get value of Array with operator[]
////    for (index = 0; index < length; ++index) {
////        ASSERT_EQUAL(index, validArray[index]);
////    }
////
////    // Test change value of Array with function `at(int index)'
////    int expect = 1000;
////    validArray.at(0) = expect;
////    int resutl = validArray.at(0);
////    ASSERT_EQUAL(expect, resutl);
////
////    // Test change value of Array with operator[]
////    expect = 99999;
////    validArray[0] = expect;
////    resutl = validArray[0];
////    ASSERT_EQUAL(expect, resutl);
//}
