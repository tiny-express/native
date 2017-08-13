/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
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
#include "../../../kernel/test.h"
}

#include "../../Lang.hpp"
#include "HashMap.hpp"
#include "../ArrayList/ArrayList.hpp"

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
	String expectedValue = container.get("sample");
	String actualValue = hashMap.get("sample");

//    ASSERT_FALSE(expectedValue.isNull());
//    ASSERT_FALSE(actualValue.isNull());
	ASSERT_STR(expectedValue.toString(), actualValue.toString());
	
	expectedValue = container.get("key");
	actualValue = hashMap.get("key");

//    ASSERT_FALSE(expectedValue.isNull());
//    ASSERT_FALSE(actualValue.isNull());
	ASSERT_STR(expectedValue.toString(), actualValue.toString());
}

TEST (JavaUtil, HashMapClear) {
	// Given valid hashMap to test clear()
	HashMap<Long, Integer> hashMap;
	hashMap.put(100, 25);
	hashMap.put(500, 123);
	
	hashMap.clear();
	int expectedSizeAfterClear = 0;
	ASSERT_EQUAL(expectedSizeAfterClear, hashMap.size());
}

TEST (JavaUtil, HashMapClone) {
	// Given valid hash map to test clone()
	HashMap<String, String> hashMap;
	hashMap.put("some key", "123");
	hashMap.put("another thing and key", "-44444");
	HashMap<String, String> anotherMap = hashMap.clone();
	
	// Given valid key/value to test and make sure that result is not null
	String expectedKey = "some key";
	String expectedValue = "123";
	String result = anotherMap.get(expectedKey);
	ASSERT_STR(expectedValue.toString(), result.toString());
	
	// Given valid key/value to test and make sure that result is not null
	expectedKey = "another thing and key";
	expectedValue = "-44444";
	result = anotherMap.get(expectedKey);
	ASSERT_STR(expectedValue.toString(), result.toString());
	
	// Given invalid key and make result is null
	String notExpectedKey = "wrong key";
	result = anotherMap.get(notExpectedKey);
}

TEST (JavaUtil, HashMapContainsKey) {
	// Given valid hash map to test containsKey()
	HashMap<Integer, String> hashMap;
	hashMap.put(3, "three");
	hashMap.put(17, "seven teen");
	hashMap.put(-52, "negative fifty two");
	
	boolean exist = hashMap.containsKey(-52);
	ASSERT_TRUE(exist);
	
	boolean notFound = hashMap.containsKey(100);
	ASSERT_FALSE(notFound);
}

TEST (JavaUtil, HashMapContainsValue) {
	// Given valid hash map to test containsValue()
	HashMap<String, Double> hashMap;
	hashMap.put("15.3", 15.3);
	hashMap.put("30.111", 30.111);
	
	boolean exist = hashMap.containsValue(15.3);
	ASSERT_TRUE(exist);
	
	boolean notFound = hashMap.containsValue(30.22);
	ASSERT_FALSE(notFound);
}

TEST (JavaUtil, HashMapEntrySet) {
	HashMap<String, String> hashMap;
	for (int index=1; index<=100; index++) {
		hashMap.put("Key "+ String::valueOf(index), "Value " + String::valueOf(index));
	}
	int counter = 0;
	Set<class Map<String, String>::Entry> entrySet = hashMap.entrySet();
	// TODO - loint@foodtiny.com will improve entrySet
	// then we can put it inside foreach without any performance issue
	for (Map<String, String>::Entry entry : entrySet) {
		counter += 1;
		if (counter == 1) {
			ASSERT_STR("Key 99", entry.getKey().toString());
			ASSERT_STR("Value 99", entry.getValue().toString());
		}
		if (counter == 2) {
			ASSERT_STR("Key 98", entry.getKey().toString());
			ASSERT_STR("Value 98", entry.getValue().toString());
		}
	}
	// Make sure foreach is working
	ASSERT_EQUAL(100, counter);
}

TEST (JavaUtil, HashMapGet) {
	// Given valid hash map to test get()
	HashMap<String, String> hashMap;
	hashMap.put("key", "value");
	
	// Given valid key/value to test and make sure that result is not null
	String result = hashMap.get("key");
	String expectedValue = "value";
	ASSERT_STR(expectedValue.toString(), result.toString());
	
	String defaultResult = hashMap.get("wrong_key");
	ASSERT_TRUE(defaultResult.isEmpty());
}

TEST (JavaUtil, HashMapIsEmpty) {
	// Given valid hash map to test isEmpty()
	HashMap<String, Float> hashMap;
	
	boolean result = hashMap.isEmpty();
	ASSERT_TRUE(result);
	
	// Add one more param into hash map to test not empty
	hashMap.put("some key", 123.33);
	ASSERT_FALSE(hashMap.isEmpty());
}

TEST (JavaUtil, HashMapPut) {
	// Given valid hash map
	HashMap<String, String> hashMap;
	hashMap.put("abc", "123");
	hashMap.put("some key here", "456");
	
	// Test size after putted()
	int expectedSize = 2;
	int actualSize = hashMap.size();
	ASSERT_EQUAL(expectedSize, actualSize);
	
	// Test data inside after putted()
	String expectedValue = "123";
	String result = hashMap.get("abc");
	ASSERT_STR(expectedValue.toString(), result.toString());
}

TEST (JavaUtil, HashMapPutAll) {
	// Given valid hash map
	HashMap<String, String> hashMap;
	hashMap.put("some string", "123");
	hashMap.put("another key", "777");
	hashMap.put("#!@#another", "-123");
	
	// Given empty hash map to test putAll() with hashMap above
	HashMap<String, String> targetMap;
	targetMap.putAll(hashMap);
	
	int hashMapSize = hashMap.size();
	int targetSize = targetMap.size();
	ASSERT_EQUAL(targetSize, hashMapSize);
	
	// Test valid key/value inside both of hashMap and targetMap
	String expectedKey = "#!@#another";
	String hashMapValue = hashMap.get(expectedKey);
	String targetValue = targetMap.get(expectedKey);
	ASSERT_STR(targetValue.toString(), hashMapValue.toString());
	
	expectedKey = "some string";
	hashMapValue = hashMap.get(expectedKey);
	targetValue = targetMap.get(expectedKey);
	ASSERT_STR(targetValue.toString(), hashMapValue.toString());
	
	expectedKey = "another key";
	hashMapValue = hashMap.get(expectedKey);
	targetValue = targetMap.get(expectedKey);
	ASSERT_STR(targetValue.toString(), hashMapValue.toString());
	
	// Test invalid key and get null data
	String notExpectedKey = "some wrong key here";
	hashMapValue = hashMap.get(notExpectedKey);
	targetValue = targetMap.get(notExpectedKey);
}

TEST (JavaUtil, HashMapPutIfAbsent) {
	// Given valid hashMap
	HashMap<String, String> hashMap;
	hashMap.put("abc", "123");
	
	// Valid data inside before run putIfAbsent
	String expectedKey = "abc";
	String expectedValue = "123";
	String actualValue = hashMap.get(expectedKey);
	ASSERT_STR(expectedValue.toString(), actualValue.toString());
	
	// Make putIfAbsent with correct key, result's returned must equal to old value
	String oldValue = "123";
	String newValue = "other value";
	String putResult = hashMap.putIfAbsent(expectedKey, newValue);
	ASSERT_STR(oldValue.toString(), putResult.toString());
	
	// Valid data inside after putted
	String getResult = hashMap.get(expectedKey);
	ASSERT_STR(newValue.toString(), getResult.toString());
	
	// Make putIfAbsent with incorrect key, result's returned must be null
	String wrongKey = "wrong key";
	newValue = "something here";
	putResult = hashMap.putIfAbsent(wrongKey, newValue);
}

TEST (JavaUtil, HashMapRemoveKey) {
	// Given valid hash map
	HashMap<String, String> hashMap;
	hashMap.put("some key", "!@#!@#");
	hashMap.put("another thing", "1111");
	
	// Valid data inside hash map
	int expectedSize = 2;
	ASSERT_EQUAL(expectedSize, hashMap.size());
	
	String expectedResult = "1111";
	String result = hashMap.get("another thing");
	ASSERT_STR(expectedResult.toString(), result.toString());
	
	// Test valid data return after removed
	String removeResult = hashMap.remove("another thing");
	expectedResult = "1111";
	ASSERT_STR(expectedResult.toString(), removeResult.toString());
	
	// Test size after removed
	expectedSize = 1;
	ASSERT_EQUAL(expectedSize, hashMap.size());
	
	// Test old key must not be in hash map
	String getOldKeyResult = hashMap.get("another thing");
	ASSERT_TRUE(getOldKeyResult.isEmpty());
}

TEST (JavaUtil, HashMapRemoveKeyValue) {
	HashMap<String, String> hashMap;
	hashMap.put("some key", "123");
	hashMap.put("another key", "456");
	
	// Valid size before remove
	int expectedSize = 2;
	ASSERT_EQUAL(expectedSize, hashMap.size());
	
	// Valid data before remove
	String expectedResult = "123";
	String result = hashMap.get("some key");
	ASSERT_STR(expectedResult.toString(), result.toString());
	
	// Test remove fail by key is not mapped to the correct value.
	boolean removeResult = hashMap.remove("some key", "456");
	ASSERT_FALSE(removeResult);
	
	// Test remove true by key mapped to specified value
	removeResult = hashMap.remove("some key", "123");
	ASSERT_TRUE(removeResult);
}

TEST (JavaUtil, HashMapReplace) {
	// Given valid hash map to test
	HashMap<String, String> hashMap;
	hashMap.put("some key", "value");
	hashMap.put("key !@#", "1000");
	hashMap.put(".;;',", "ab232");
	
	// Valid data inside before replace
	String expectedKey = ".;;',";
	String expectedValue = "ab232";
	String result = hashMap.get(expectedKey);
	ASSERT_STR(expectedValue.toString(), result.toString());
	
	// Test replace(expectedKey, value)
	String oldValue = "ab232";
	String newValue = "250008";
	String replaceResult = hashMap.replace(expectedKey, newValue);
	ASSERT_STR(oldValue.toString(), replaceResult.toString());
	
	// Valid new data inside mapped expectedKey
	expectedValue = newValue;
	result = hashMap.get(expectedKey);
	ASSERT_STR(expectedValue.toString(), result.toString());
}

TEST (JavaUtil, HashMapReplaceSpecifiedValue) {
	// Given valid hash map to test
	HashMap<String, String> hashMap;
	hashMap.put("some key", "123");
	hashMap.put("key123", "!@#");
	
	// Valid size before replace
	int expectedSize = 2;
	ASSERT_EQUAL(expectedSize, hashMap.size());
	
	// Valid data inside before replace
	String expectedKey = "key123";
	String expectedValue = "!@#";
	String getResult = hashMap.get(expectedKey);
	ASSERT_STR(expectedValue.toString(), getResult.toString());
	
	// Replace with correct key/oldValue - result must equal to TRUE
	String key = "key123";
	String oldValue = "!@#";
	String newValue = "456";
	boolean replaceResult = hashMap.replace(key, oldValue, newValue);
	ASSERT_TRUE(replaceResult);
	
	// Valid data inside after replace succeed - key must be mapped with newValue
	String valueAfterReplaced = hashMap.get(key);
	ASSERT_STR(newValue.toString(), valueAfterReplaced.toString());
	
	// Replace with incorrect key/oldValue - result must equal to FALSE
	key = "some key";
	oldValue = "wrong value";
	newValue = "newValue";
	replaceResult = hashMap.replace(key, oldValue, newValue);
	ASSERT_FALSE(replaceResult);
	
	// Valid data inside after replace failed - key must be mapped previous value before replace
	key = "some key";
	oldValue = "123";
	getResult = hashMap.get(key);
	ASSERT_STR(oldValue.toString(), getResult.toString());
}

TEST (JavaUtil, HashMapReplaceAll) {
	// Given valid hash map
	HashMap<String, String> hashMap;
	hashMap.put("key1", "1000");
	hashMap.put("key2", "2000");
	
	// Valid data inside before replace
	String expectedValue = "1000";
	String result = hashMap.get("key1");
	ASSERT_STR(expectedValue.toString(), result.toString());
	
	expectedValue = "2000";
	result = hashMap.get("key2");
	ASSERT_STR(expectedValue.toString(), result.toString());
	
	// Replace all value inside hash map that mapped with key to newValue
	String newValue = "3000";
	hashMap.replaceAll(newValue);
	
	// Valid data after replaced, all value inside must equal to newValue
	result = hashMap.get("key1");
	ASSERT_STR(newValue.toString(), result.toString());
	
	result = hashMap.get("key2");
	ASSERT_STR(newValue.toString(), result.toString());
}

TEST (JavaUtil, HashMapSize) {
	// Given valid hash map to test size()
	HashMap<Double, String> hashMap;
	hashMap.put(15.22222, "15.22222");
	hashMap.put(-50.2222, "50");
	
	int expectedSize = 2;
	ASSERT_EQUAL(expectedSize, hashMap.size());
	
	// Add more param to valid size
	hashMap.put(123, "some thing here");
	expectedSize = 3;
	ASSERT_EQUAL(expectedSize, hashMap.size());
}

TEST (JavaUtil, HashMapToString) {
	// Given some valid key/value to test toString()
	HashMap<String, String> hashMap;
	hashMap.put("key1", "value1");
	hashMap.put("key16", "value16");
	hashMap.put("key02", "value02");
	
	string expectedResult = (string) "{\"key02\": \"value02\", \"key1\": \"value1\", \"key16\": \"value16\"}";
	string result = hashMap.toString();
	ASSERT_STR(expectedResult, result);
	
	// Given another hash map type to test
	HashMap<String, Integer> anotherHashMap;
	anotherHashMap.put("some key", 12313);
	anotherHashMap.put("anotherKey", 76767);
	
	expectedResult = (string) "{\"anotherKey\": 76767, \"some key\": 12313}";
	result = anotherHashMap.toString();
	ASSERT_STR(expectedResult, result);
	
	// Given empty hash map to test default toString()
	HashMap<String, Float> emptyHashMap;
	expectedResult = (string) "{}";
	result = emptyHashMap.toString();
	ASSERT_STR(expectedResult, result);
	
	ArrayList<Integer> validArrayListInteger1 = { 1, 2, 3, 4, 5 };
	ArrayList<Integer> validArrayListInteger2 = { 100, 100, 100, 100, 1 };
	HashMap<String, ArrayList<Integer>> arrayListInHashMap;
	arrayListInHashMap.put("ArrayList1", validArrayListInteger1);
	arrayListInHashMap.put("ArrayList2", validArrayListInteger2);
	expectedResult = (string) "{\"ArrayList1\": [1, 2, 3, 4, 5], \"ArrayList2\": [100, 100, 100, 100, 1]}";
	result = arrayListInHashMap.toString();
	ASSERT_STR(expectedResult, result);
}

