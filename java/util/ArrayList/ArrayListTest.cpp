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
#include "../../../unit_test.h"
}

#include "../List/List.hpp"
#include "../../lang/String/String.hpp"
#include "ArrayList.hpp"

using namespace Java::Lang;

TEST (JavaLang, ArrayListConstructor) {
	ArrayList<String> strings;
	
//	string.
//	strings.add((String&) "Tiny");
//	strings.add((String&) "Hello");
//	strings.add((String&) "World");
//	ASSERT_EQUAL(4, strings.size());
}

//TEST(JavaLang, ArrayListDestructor) {
//    // Test destructor
//    ArrayList<int> *intArray = new ArrayList<int>(10, 10);
//    ArrayList<int> *pointerIntArray = intArray;
//    delete intArray;
//    ASSERT_EQUAL(0, pointerIntArray->size());
//
//    ArrayList<float> *floatArray = new ArrayList<float>(10);
//    ArrayList<float> *pointerFloatArray = floatArray;
//    delete floatArray;
//    ASSERT_EQUAL(0, pointerFloatArray->size());
//
//    intArray = new ArrayList<int>;
//    delete intArray;
//
//    intArray = new ArrayList<int>({1, 2, 3, 4});
//    delete  intArray;
//}

//TEST(JavaLang, ArrayListsize) {
//    // Test size of empty Array
//    ArrayList<int> emptyArray;
//    int expect = 0;
//    int result = emptyArray.size();
//    ASSERT_EQUAL(expect, result);
//
//    // Test is empty
//    boolean isEmpty = emptyArray.isEmpty();
//    ASSERT_TRUE(isEmpty);
//
//    // Test size of empty Array
//    int size = 10;
//    ArrayList<int> validArray(size);
//    result = validArray.size();
//    ASSERT_EQUAL(size, result);
//
//    // Test is not empty
//    boolean notEmpty = validArray.isEmpty();
//    ASSERT_FALSE(notEmpty);
//
//}
//
//TEST(Javalang, ArrayListFunction) {
//    // Test function add with std::initializer_list
//    ArrayList<byte> byteArray = {12, 13, 14};
//    byteArray.addAll({15, 16, 17});
//    int expect = 6;
//    int result = byteArray.size();
//    ASSERT_EQUAL(expect, result);
//
//    //
//    ArrayList<byte> copyArray = byteArray;
//    expect = 6;
//    result = byteArray.size();
//    ASSERT_EQUAL(expect, result);
//
//    // Create new Array from two Array
//    ArrayList<byte> totalArray;
//    totalArray.addAll(byteArray);
//    totalArray.addAll(copyArray);
//    expect = 12;
//    result = totalArray.size();
//    ASSERT_EQUAL(expect, result);
//
//    // Get value out of Array
//    int resultNull = totalArray.get(-1);
//    ASSERT_NULL(resultNull);
//
//    resultNull = totalArray.get(totalArray.size());
//    ASSERT_NULL(resultNull);
//}
