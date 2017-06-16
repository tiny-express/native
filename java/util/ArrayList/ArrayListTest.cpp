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
    // Standard declaration
	ArrayList<int> stringArrayList;
    int value = 1324;
	stringArrayList.add(value);
	stringArrayList.add(value);
	stringArrayList.add(value);
	stringArrayList.add(value);
	ASSERT_EQUAL(4, stringArrayList.size());

    ArrayList<int> intArrayList;
    ASSERT_EQUAL(0, intArrayList.size());
}

TEST(JavaLang, ArrayListDestructor) {
    // Test destructor
    ArrayList<int> *intArray = new ArrayList<int>(10);
    delete intArray;
    intArray = NULL;
    ASSERT_NULL(intArray);
}

TEST(JavaLang, ArrayListSize) {
    // Test size of empty Array
    ArrayList<int> emptyArray;
    int expect = 0;
    int result = emptyArray.size();
    ASSERT_EQUAL(expect, result);

    // Test is empty
    boolean isEmpty = emptyArray.isEmpty();
    ASSERT_TRUE(isEmpty);

    // Test size of empty Array
    int size = 10;
    ArrayList<int> validArray(size);
    result = validArray.size();
    ASSERT_EQUAL(size, result);

    // Test is not empty
    boolean notEmpty = validArray.isEmpty();
    ASSERT_FALSE(notEmpty);
}

TEST(Javalang, ArrayListFunction) {
    // Test function add with
    ArrayList<int> intArray;

    register int index;
    for (index = 0; index < 6; ++index) {
        intArray.add(index);
    }
    int expect = 6;
    int result = intArray.size();
    ASSERT_EQUAL(expect, result);

    // Get value out of Array
    intArray.get(-1);
    ASSERT_EQUAL(0 ,intArray.get(-1));
    ASSERT_EQUAL(5 ,intArray.get(intArray.size()));
}

TEST(JavaLang, ArrayListForEach) {
    //
    ArrayList<int> validArrayList;

    int index;
    for (index = 0; index < 100; ++index) {
        validArrayList.add(index);
    }

    int expect = 0;
    for (int element : validArrayList) {
        ASSERT_EQUAL(expect, element);
        expect++;
    }
}
