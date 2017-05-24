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

#include "HashMap.hpp"

using namespace Java::Lang;
using namespace Java::Util;

/**
 *  Basic funtions such as constructor, get, put
 * */
TEST(JavaUtil, HashMapBasic) {
    // Given empty hash map - return NULL
    HashMap<string, string> emptyHashMap;
    ASSERT_NULL(emptyHashMap.get((string) "key"));

    // Given <int, String> hash map - return value is exist
    HashMap<int, String> intStringHashMap;
    intStringHashMap.put(1, (String) "value");
    ASSERT_TRUE((String) "value" == intStringHashMap.get(1));

    // Given <Integer, string> hash map - return value is exist
    HashMap<Integer, string> integerStringHashMap;
    Integer integerNumber = 1;
    integerStringHashMap.put(integerNumber, (string) "value");
    ASSERT_STR((string) "value", integerStringHashMap.get(1));

    // Give wrong Integer to get NULL value
    HashMap<Integer, string> nullValueHashMap;
    ASSERT_NULL(nullValueHashMap.get(123));

    // More test cases
}

/**
 *  Basic funtions such as constains, size, remove, clear, empty ..
 * */
TEST(JavaUtil, HashMapAdvance) {
    // Give some params to run test case below
    string key = (string)"key";
    string wrongKey = (string)"wrongKey";
    string removeKey = (string)"removeKey";
    string value = (string)"value";
    string wrongValue = (string)"wrongValue";
    string removeValue = (string)"removeValue";

    // Given valid HashMap<string, string> to check contains
    HashMap<string, string> containsHashMap;
    containsHashMap.put(key, value);

    // Test true containsKey with correct key
    ASSERT_TRUE(containsHashMap.containsKey(key));

    // Test false containsKey with wrong key
    ASSERT_FALSE(containsHashMap.containsKey(wrongKey));

    // Test true containsValue with correct value
    ASSERT_TRUE(containsHashMap.containsValue(value));

    // Test false containsValue with wrong key
    ASSERT_FALSE(containsHashMap.containsValue(wrongValue));

    // Given valid removeHashMap<string, string> to check remove
    HashMap<string, string> removeHashMap;
    removeHashMap.put(key, value);
    removeHashMap.put(removeKey, removeValue);

    // Test true remove with correct key
    ASSERT_TRUE(removeHashMap.remove(key));

    // Test false remove through recall remove function with same key
    ASSERT_FALSE(removeHashMap.remove(key));

    // Test true remove with correct removeKey and removeValue
    ASSERT_TRUE(removeHashMap.remove(removeKey, removeValue));

    // Given valid clearHashMap<string, string> to check clear (removeAll() also works on clear())
    HashMap<string, string> clearHashMap;
    clearHashMap.put(key, value);

    // Test true clear() with clearHashMap's size should be 0 after (isEmpty() also works on size() == 0)
    clearHashMap.clear();
    ASSERT_EQUAL(0, clearHashMap.size());

    // Given valid sizeHashMap<string, string> to test size
    HashMap<string, string> sizeHashMap;
    sizeHashMap.put(key, value);
    sizeHashMap.put(wrongKey, wrongValue);

    // Test true size() with those data putted into sizeHashMap above
    ASSERT_EQUAL(2, sizeHashMap.size());

    // More test case
}

