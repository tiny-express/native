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

#include "../../Lang.hpp"
#include "HashMap.hpp"

using namespace Java::Lang;
using namespace Java::Util;

TEST (JavaUtil, HashMapConstructor) {
    // Test default constructor
    HashMap<String, Integer> emptyHashMap;

    int expectedSize = 0;
    ASSERT_EQUAL(expectedSize, emptyHashMap.size());
    ASSERT_TRUE(emptyHashMap.isEmpty());

    // Test copy constructor
    HashMap<String, String> container;
    container.put("sample", "here");
    container.put("key", "value");

    HashMap<String, String> hashMap = container;

    // Test valid size()
    expectedSize = 2;
    ASSERT_EQUAL(expectedSize, hashMap.size());
    ASSERT_FALSE(hashMap.isEmpty());

    // Test valid data between hashMap and container
    String *expectedValue = container.get("sample");
    String *actualValue = hashMap.get("sample");

//    ASSERT_NOT_NULL(expectedValue);
//    ASSERT_NOT_NULL(actualValue);
//    ASSERT_STR(expectedValue->toString(), actualValue->toString());
//
//    expectedValue = container.get("key");
//    actualValue = hashMap.get("key");
//
//    ASSERT_NOT_NULL(expectedValue);
//    ASSERT_NOT_NULL(actualValue);
//    ASSERT_STR(expectedValue->toString(), actualValue->toString());
}

//TEST (JavaUtil, HashMapClear) {
//    // Given valid hashMap to test clear()
//    HashMap<Long, Integer> hashMap;
//    hashMap.put(100, 25);
//    hashMap.put(500, 123);
//
//    hashMap.clear();
//    int expectedSizeAfterClear = 0;
//    ASSERT_EQUAL(expectedSizeAfterClear, hashMap.size());
//}
//
//TEST(JavaUtil, HashMapClone) {
//	// Given valid hash map to test clone()
//	HashMap<String, Integer> hashMap;
//	hashMap.put("some key", 123);
//	hashMap.put("another thing and key", -44444);
//	HashMap<String, Integer> anotherMap = hashMap.clone();
//
//    // Given valid key/value to test and make sure that result is not null
//    String expectedKey = "some key";
//    Integer expectedValue = 123;
//    Integer *result = anotherMap.get(expectedKey);
//    ASSERT_NOT_NULL(result);
//    ASSERT_EQUAL(expectedValue.intValue(), result->intValue());
//
//    // Given valid key/value to test and make sure that result is not null
//    expectedKey = "another thing and key";
//    expectedValue = -44444;
//    result = anotherMap.get(expectedKey);
//    ASSERT_NOT_NULL(result);
//    ASSERT_EQUAL(expectedValue.intValue(), result->intValue());
//
//    // Given invalid key and make result is null
//    String notExpectedKey = "wrong key";
//    result = anotherMap.get(notExpectedKey);
//    ASSERT_NULL(result);
//}
//
//TEST (JavaUtil, HashMapContainsKey) {
//    // Given valid hash map to test containsKey()
//    HashMap<Integer, String> hashMap;
//    hashMap.put(3, "three");
//    hashMap.put(17, "seven teen");
//    hashMap.put(-52, "negative fifty two");
//
//    boolean exist = hashMap.containsKey(-52);
//    ASSERT_TRUE(exist);
//
//    boolean notFound = hashMap.containsKey(100);
//    ASSERT_FALSE(notFound);
//}
//
//TEST (JavaUtil, HashMapContainsValue) {
//    // Given valid hash map to test containsValue()
//    HashMap<String, Double> hashMap;
//    hashMap.put("15.3", 15.3);
//    hashMap.put("30.111", 30.111);
//
//    boolean exist = hashMap.containsValue(15.3);
//    ASSERT_TRUE(exist);
//
//    boolean notFound = hashMap.containsValue(30.22);
//    ASSERT_FALSE(notFound);
//}
//
//TEST (JavaUtil, HashMapGet) {
//	// Given valid hash map to test get()
//	HashMap<String, String> hashMap;
//	hashMap.put("key", "value");
//
//    // Given valid key/value to test and make sure that result is not null
//	String *result = hashMap.get("key");
//	String expectedValue = "value";
//	ASSERT_NOT_NULL(result);
//	ASSERT_STR(expectedValue.toString(), (*result).toString());
//	ASSERT_STR(expectedValue.toString(), result->toString()); //another way to deal
//
//	String *nullableResult = hashMap.get("wrong_key");
//	ASSERT_NULL(nullableResult);
//}
//
//TEST (JavaUtil, HashMapIsEmpty) {
//    // Given valid hash map to test isEmpty()
//    HashMap<String, Float> hashMap;
//
//    boolean result = hashMap.isEmpty();
//    ASSERT_TRUE(result);
//
//    // Add one more param into hash map to test not empty
//    hashMap.put("some key", 123.33);
//    ASSERT_FALSE(hashMap.isEmpty());
//}
//
//TEST (JavaUtil, HashMapPut) {
//    HashMap<String, Long> hashMap;
//    hashMap.put("abc", 123);
//    hashMap.put("some key here", 456);
//
//    int expectedSize = 2;
//    int actualSize = hashMap.size();
//    ASSERT_EQUAL(expectedSize, actualSize);
//
//    Long expectedValue = 123;
//    Long* result = hashMap.get("abc");
//    ASSERT_NOT_NULL(result);
//    ASSERT_EQUAL(expectedValue.longValue(), result->longValue());
//
//    expectedValue = 456;
//    result = hashMap.get("some key here");
//    ASSERT_NOT_NULL(result);
//    ASSERT_EQUAL(expectedValue.longValue(), result->longValue());
//}
//
//TEST (JavaUtil, HashMapPutAll) {
//    HashMap<String, Short> hashMap;
//    hashMap.put("some string", 123);
//    hashMap.put("another key", 777);
//    hashMap.put("#!@#another", -123);
//
//    // Given empty hash map to test putAll() with hashMap above
//    HashMap<String, Short> targetMap;
//    targetMap.putAll(hashMap);
//
//    int hashMapSize = hashMap.size();
//    int targetSize = targetMap.size();
//    ASSERT_EQUAL(targetSize, hashMapSize);
//
//    // Test valid key/value inside both of hashMap and targetMap
//    String expectedKey = "#!@#another";
//    Short *hashMapValue = hashMap.get(expectedKey);
//    Short *targetValue = targetMap.get(expectedKey);
//    ASSERT_NOT_NULL(hashMapValue);
//    ASSERT_NOT_NULL(targetValue);
//    ASSERT_EQUAL(targetValue->shortValue(), hashMapValue->shortValue());
//
//    expectedKey = "some string";
//    hashMapValue = hashMap.get(expectedKey);
//    targetValue = targetMap.get(expectedKey);
//    ASSERT_NOT_NULL(hashMapValue);
//    ASSERT_NOT_NULL(targetValue);
//    ASSERT_EQUAL(targetValue->shortValue(), hashMapValue->shortValue());
//
//    expectedKey = "another key";
//    hashMapValue = hashMap.get(expectedKey);
//    targetValue = targetMap.get(expectedKey);
//    ASSERT_NOT_NULL(hashMapValue);
//    ASSERT_NOT_NULL(targetValue);
//    ASSERT_EQUAL(targetValue->shortValue(), hashMapValue->shortValue());
//
//    // Test invalid key and get null data
//    String notExpectedKey = "some wrong key here";
//    hashMapValue = hashMap.get(notExpectedKey);
//    targetValue = targetMap.get(notExpectedKey);
//    ASSERT_NULL(hashMapValue);
//    ASSERT_NULL(targetValue);
//}
//
//TEST (JavaUtil, HashMapRemoveKey) {
//    HashMap<String, String> hashMap;
//    hashMap.put("some key", "!@#!@#");
//    hashMap.put("another thing", "1111");
//
//    // Valid data inside hash map
//    int expectedSize = 2;
//    ASSERT_EQUAL(expectedSize, hashMap.size());
//
//    String expectedResult = "1111";
//    String *result = hashMap.get("another thing");
//    ASSERT_NOT_NULL(result);
//    ASSERT_STR(expectedResult.toString(), result->toString());
//
//    // Test remove() through value return, size() and get() also
//    String *removeResult = hashMap.remove("another thing");
//    expectedResult = "1111";
//
//    ASSERT_NOT_NULL(removeResult);
//    ASSERT_STR(expectedResult.toString(), removeResult->toString());
//
//    expectedSize = 1;
//    ASSERT_EQUAL(expectedSize, hashMap.size());
//
//    result = hashMap.get("another thing");
//    ASSERT_NULL(result);
//}
//
//TEST (JavaUtil, HashMapRemoveKeyValue) {
//    HashMap<String, Integer> hashMap;
//    hashMap.put("some key", 123);
//    hashMap.put("another key", 456);
//
//    // Valid data inside hash map
//    int expectedSize = 2;
//    ASSERT_EQUAL(expectedSize, hashMap.size());
//
//    Integer expectedResult = 123;
//    Integer *result = hashMap.get("some key");
//    ASSERT_NOT_NULL(result);
//    ASSERT_EQUAL(expectedResult.intValue(), result->intValue());
//
//    // Test remove fail by key is not mapped to the correct value.
//    boolean removeResult = hashMap.remove("some key", 456);
//    ASSERT_FALSE(removeResult);
//
//    // Test remove true by key mapped to specified value
//    removeResult = hashMap.remove("some key", 123);
//    ASSERT_TRUE(removeResult);
//}
//
//TEST (JavaUtil, HashMapReplace) {
//    // Given valid hash map to test
//    HashMap<String, String> hashMap;
//    hashMap.put("some key", "value");
//    hashMap.put("key !@#", "1000");
//    hashMap.put(".;;',", "ab232");
//
//    // Valid data before test
//    String expectedKey = ".;;',";
//    String expectedValue = "ab232";
//    String *result = hashMap.get(expectedKey);
//
//    ASSERT_NOT_NULL(result);
//    ASSERT_STR(expectedValue.toString(), result->toString());
//
//    // Test replace(key, value)
//    String oldValue = "ab232";
//    String newValue = "250008";
//    String replaceResult = *hashMap.replace("abc", newValue);
//
    //ASSERT_NOT_NULL(replaceResult);
    //ASSERT_STR(oldValue.toString(), temp.toString());

    // Valid data after test
//    expectedValue = "250008";
//    result = hashMap.get(expectedKey);
//
//    ASSERT_NOT_NULL(result);
//    ASSERT_STR(expectedKey.toString(), result->toString());
//}

//TEST (JavaUtil, HashMapSize) {
//	// Given valid hash map to test size()
//	HashMap<Double, String> hashMap;
//	hashMap.put(15.22222, "15.22222");
//	hashMap.put(-50.2222, "50");
//
//	int expectedSize = 2;
//	ASSERT_EQUAL(expectedSize, hashMap.size());
//
//    hashMap.put(123, "some thing here");
//    expectedSize = 3;
//    ASSERT_EQUAL(expectedSize, hashMap.size());
//}
//
//TEST (JavaUtil, HashMapToString) {
//	// Given some valid key/value to test toString()
//	HashMap<string, String> hashMap;
//	hashMap.put((string)"key1", "value1");
//	hashMap.put((string)"key16", "value16");
//	hashMap.put((string)"key02", "value02");
//
//	string expectedResult = (string)"{key1=value1, key16=value16, key02=value02}";
//	string result = hashMap.toString();
//	ASSERT_STR(expectedResult, result);
//    free(result);
//
//    // Given another hash map type to test
//    HashMap<string, Integer> anotherHashMap;
//    anotherHashMap.put((string)"some key", 12313);
//    anotherHashMap.put((string)"anotherKey", 76767);
//
//    expectedResult = (string)"{some key=12313, anotherKey=76767}";
//    result = anotherHashMap.toString();
//    ASSERT_STR(expectedResult, result);
//    free(result);
//
//    // Given empty hash map to test default toString()
//    HashMap<string, Float> emptyHashMap;
//
//    expectedResult = (string)"{}";
//    result = emptyHashMap.toString();
//    ASSERT_STR(expectedResult, result);
//    free(result);
//}