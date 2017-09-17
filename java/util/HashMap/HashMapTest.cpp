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

TEST(JavaUtil, HashMapConstructor) {
	String expected;
	String actual;

	// Test default constructor
	HashMap<String, Integer> emptyHashMap;

	// Make sure emptyHashMap is empty
	ASSERT_TRUE(emptyHashMap.isEmpty());

	// Test copy constructor
	HashMap<String, String> container;
	container.put("sample", "here");
	container.put("key", "value");

	HashMap<String, String> hashMap = container;

	// Test valid size()
	ASSERT_EQUAL(2, hashMap.size());
	ASSERT_FALSE(hashMap.isEmpty());

	// Test valid data between hashMap and container
	expected = container.get("sample");
	actual = hashMap.get("sample");

	ASSERT_FALSE(expected.isEmpty());
	ASSERT_FALSE(actual.isEmpty());
	ASSERT_STR(expected.toString(), actual.toString());

	expected = container.get("key");
	actual= hashMap.get("key");

	ASSERT_FALSE(expected.isEmpty());
	ASSERT_FALSE(actual.isEmpty());
	ASSERT_STR(expected.toString(), actual.toString());
}

TEST(JavaUtil, HashMapClear) {
	// Given valid hashMap to test clear()
	HashMap<Long, Integer> hashMap;
	hashMap.put((long) 100, 25);
	hashMap.put((long) 500, 123);
	ASSERT_EQUAL(2, hashMap.size());

	hashMap.clear();
	ASSERT_EQUAL(0, hashMap.size());
}

TEST(JavaUtil, HashMapClone) {
	String actualKey;
	String expected;
	String actual;

	// Create a HashMap to test to test clone()
	HashMap<String, String> hashMap;
	hashMap.put("some key", "123");
	hashMap.put("another thing and key", "-44444");
	HashMap<String, String> anotherMap = (HashMap<String, String>) hashMap.clone();

	// Test actualKey = "some key" is exist in anotherMap
	actualKey = "some key";
	expected = "123";
	actual = anotherMap.get(actualKey);
	ASSERT_STR(expected.toString(), actual.toString());

	// Test actualKey = "another thing and key" is exist in anotherMap
	actualKey = "another thing and key";
	expected = "-44444";
	actual = anotherMap.get(actualKey);
	ASSERT_STR(expected.toString(), actual.toString());

	// Test invalid key
	actualKey = "wrong key";
	actual = anotherMap.get(actualKey);
	ASSERT_TRUE(actual.isEmpty());
}

TEST(JavaUtil, HashMapContainsKey) {
	boolean actual;

	// Create a HashMap to test
	HashMap<Integer, String> hashMap;
	hashMap.put(3, "three");
	hashMap.put(17, "seven teen");
	hashMap.put(-52, "negative fifty two");

	// Valid key
	actual = hashMap.containsKey(-52);
	ASSERT_TRUE(actual);

	// Invalid key
	actual = hashMap.containsKey(100);
	ASSERT_FALSE(actual);
}

TEST(JavaUtil, HashMapContainsValue) {
	boolean actual;

	// Create a HashMap to test
	HashMap<String, Double> hashMap;
	hashMap.put("15.3", 15.3);
	hashMap.put("30.111", 30.111);

	// Valid key
	actual = hashMap.containsValue(15.3);
	ASSERT_TRUE(actual);

	// Invalid key
	actual = hashMap.containsValue(30.22);
	ASSERT_FALSE(actual);
}

TEST(JavaUtil, HashMapEntrySet) {
	HashMap<String, String> hashMap;

	for (int index = 1; index <= 100; index++) {
		hashMap.put("Key "+ String::valueOf(index),
					"Value " + String::valueOf(index));
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

TEST(JavaUtil, HashMapGet) {
	String expected;
	String actual;

	// Create a HashMap to test
	HashMap<String, String> hashMap;
	hashMap.put("key", "value");

	// Valid key
	expected = "value";
	actual = hashMap.get("key");
	ASSERT_STR(expected.toString(), actual.toString());

	// Invalid key
	actual = hashMap.get("wrong_key");
	ASSERT_TRUE(actual.isEmpty());
}

TEST(JavaUtil, HashMapIsEmpty) {
	// Create a HashMap to test
	HashMap<String, Float> hashMap;

	// Empty case
	boolean actual = hashMap.isEmpty();
	ASSERT_TRUE(actual);

	// Not empty case
	hashMap.put("some key", (float) 123.33);
	ASSERT_FALSE(hashMap.isEmpty());
}

TEST(JavaUtil, HashMapPut) {
	String expected;
	String actual;

	// Create a HashMap to test
	HashMap<String, String> hashMap;
	hashMap.put("abc", "123");
	hashMap.put("some key here", "456");

	// Make sure hashMap is not null
	ASSERT_EQUAL(2, hashMap.size());

	// Make sure the data is safe
	// Valid key
	expected = "123";
	actual = hashMap.get("abc");
	ASSERT_STR(expected.toString(), actual.toString());

	// Valid key
	expected = "456";
	actual = hashMap.get("some key here");
	ASSERT_STR(expected.toString(), actual.toString());
}

TEST(JavaUtil, HashMapPutAll) {
	// Create a HashMap to test
	HashMap<String, String> hashMap;
	hashMap.put("some string", "123");
	hashMap.put("another key", "777");
	hashMap.put("#!@#another", "-123");

	// putAll data of hashMap to targetMap
	HashMap<String, String> targetMap;
	targetMap.putAll(hashMap);

	// Make sure both are the same size
	ASSERT_EQUAL(hashMap.size(), targetMap.size());

	// Make sure both have the same data
	String actualKey = "#!@#another";
	String expected = hashMap.get(actualKey);
	String actual = targetMap.get(actualKey);
	ASSERT_STR(actual.toString(), expected.toString());

	actualKey = "some string";
	expected = hashMap.get(actualKey);
	actual = targetMap.get(actualKey);
	ASSERT_STR(actual.toString(), expected.toString());

	actualKey = "another key";
	expected = hashMap.get(actualKey);
	actual = targetMap.get(actualKey);
	ASSERT_STR(actual.toString(), expected.toString());

	// Invalid case
	actualKey = "some wrong key here";
	expected = hashMap.get(actualKey);
	actual = targetMap.get(actualKey);
	ASSERT_TRUE(expected.isEmpty());
	ASSERT_TRUE(actual.isEmpty());
}

TEST(JavaUtil, HashMapPutIfAbsent) {
	String actualKey;
	String expected;
	String actual;

	// Create a HashMap to test
	HashMap<String, String> hashMap;
	hashMap.put("abc", "123");

	// Make sure the data is right before test
	actualKey = "abc";
	expected = "123";
	actual = hashMap.get(actualKey);
	ASSERT_STR(expected.toString(), actual.toString());

	// Existent key
	expected = "123";
	actual = hashMap.putIfAbsent(actualKey, "other value");
	ASSERT_STR(expected.toString(), actual.toString());

	// Make sure the value is not changed.
	expected = "123";
	actual = hashMap.get(actualKey);
	ASSERT_STR(expected.toString(), actual.toString());

	// Non-existent key
	String wrongKey = "wrong key";
	expected = "something here";
	String isSucceedPutIfAbsent = hashMap.putIfAbsent(wrongKey, "something here");
	actual = hashMap.get(wrongKey);
	ASSERT_TRUE(isSucceedPutIfAbsent.isEmpty());
	ASSERT_STR(expected.toString(), actual.toString());
}

TEST(JavaUtil, HashMapRemoveKey) {
	// Create a HashMap to test
	HashMap<String, String> hashMap;
	hashMap.put("some key", "!@#!@#");
	hashMap.put("another key", "1111");

	// Make sure the size is right
	ASSERT_EQUAL(2, hashMap.size());

	// Make sure the data is right
	String expected = "1111";
	String actual = hashMap.get("another key");
	ASSERT_STR(expected.toString(), actual.toString());

	// Data must be removed after removing
	String isSucceedRemove = hashMap.remove("another key");
	expected = "1111";
	ASSERT_STR(expected.toString(), isSucceedRemove.toString());

	// Size must decrease after removing
	ASSERT_EQUAL(1, hashMap.size());

	// Make sure the old data must not exist any more
	actual = hashMap.get("another key");
	ASSERT_TRUE(actual.isEmpty());
}

TEST(JavaUtil, HashMapRemoveKeyValue) {
	// Create a HashMap to test
	HashMap<String, String> hashMap;
	hashMap.put("some key", "123");
	hashMap.put("another key", "456");

	// Make sure the size is right before removing
	ASSERT_EQUAL(2, hashMap.size());

	// Make sure the data is right before removing
	String expectedactual = "123";
	String actual = hashMap.get("some key");
	ASSERT_STR(expectedactual.toString(), actual.toString());

	// Invalid case: right case, wrong value
	boolean isSucceedRemove = hashMap.remove("some key", "456");
	ASSERT_FALSE(isSucceedRemove);

	// Test remove true by key mapped to specified value
	isSucceedRemove = hashMap.remove("some key", "123");
	ASSERT_TRUE(isSucceedRemove);
}

TEST(JavaUtil, HashMapReplace) {
	// Create a HashMap to test to test
	HashMap<String, String> hashMap;
	hashMap.put("some key", "value");
	hashMap.put("key !@#", "1000");
	hashMap.put(".;;',", "ab232");

	// Make sure the data is right before replacing
	String actualKey = ".;;',";
	String expected = "ab232";
	String actual = hashMap.get(actualKey);
	ASSERT_STR(expected.toString(), actual.toString());

	// Replace the oldValue
	String oldValue = "ab232";
	String newValue = "250008";
	String replaceactual = hashMap.replace(actualKey, newValue);
	ASSERT_STR(oldValue.toString(), replaceactual.toString());

	// Make sure the old value is replaced by new value
	expected = newValue;
	actual = hashMap.get(actualKey);
	ASSERT_STR(expected.toString(), actual.toString());
}

TEST(JavaUtil, HashMapReplace2) {
	// Create a HashMap to test to test
	HashMap<String, String> hashMap;
	hashMap.put("some key", "123");
	hashMap.put("key123", "!@#");

	// Make sure the size is right
	ASSERT_EQUAL(2, hashMap.size());

	// Make sure the data is right
	String actualKey = "key123";
	String expected = "!@#";
	String actual = hashMap.get(actualKey);
	ASSERT_STR(expected.toString(), actual.toString());

	// Replace the old value
	String key = "key123";
	String oldValue = "!@#";
	String newValue = "456";
	boolean isSucceedReplace = hashMap.replace(key, oldValue, newValue);
	ASSERT_TRUE(isSucceedReplace);

	// Make sure the old value is replace by new value
	actual = hashMap.get(key);
	ASSERT_STR(newValue.toString(), actual.toString());

	// Replace with incorrect key/oldValue
	key = "some key";
	oldValue = "wrong value";
	newValue = "newValue";
	isSucceedReplace = hashMap.replace(key, oldValue, newValue);
	ASSERT_FALSE(isSucceedReplace);

	// Make sure the value is not change if replacing is failed
	key = "some key";
	oldValue = "123";
	actual = hashMap.get(key);
	ASSERT_STR(oldValue.toString(), actual.toString());
}

TEST(JavaUtil, HashMapReplaceAll) {
	// Create a HashMap to test
	HashMap<String, String> hashMap;
	hashMap.put("key1", "1000");
	hashMap.put("key2", "2000");

	// Make sure the data is right before test
	String expected = "1000";
	String actual = hashMap.get("key1");
	ASSERT_STR(expected.toString(), actual.toString());

	expected = "2000";
	actual = hashMap.get("key2");
	ASSERT_STR(expected.toString(), actual.toString());

	// Replace all values
	String newValue = "3000";

	hashMap.replaceAll(newValue);
	// Make sure all values was replaced
	actual = hashMap.get("key1");
	ASSERT_STR(newValue.toString(), actual.toString());

	actual = hashMap.get("key2");
	ASSERT_STR(newValue.toString(), actual.toString());
}

TEST(JavaUtil, HashMapSize) {
	// Create a HashMap to test
	HashMap<Double, String> hashMap;
	hashMap.put(15.22222, "15.22222");
	hashMap.put(-50.2222, "50");

	// Make sure the size is 2
	ASSERT_EQUAL(2, hashMap.size());

	// Add one more key/value and check size again
	hashMap.put((double) 123, "some thing here");
	ASSERT_EQUAL(3, hashMap.size());
}

TEST(JavaUtil, HashMapToString) {
	// Given some valid key/value to test toString()
	HashMap<String, String> hashMap;
	hashMap.put("key1", "value1");
	hashMap.put("key16", "value16");
	hashMap.put("key02", "value02");

	string expectedResult = (string) R"({"key02": "value02", "key1": "value1", "key16": "value16"})";
	string result = hashMap.toString();
	ASSERT_STR(expectedResult, result);

	// Given another hash map type to test
	HashMap<Integer, Integer> anotherHashMap;
	anotherHashMap.put(1, 12313);
	anotherHashMap.put(2, 76767);

	expectedResult = (string) R"({1: 12313, 2: 76767})";
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
	expectedResult = (string) R"({"ArrayList1": [1, 2, 3, 4, 5], "ArrayList2": [100, 100, 100, 100, 1]})";
	result = arrayListInHashMap.toString();
	ASSERT_STR(expectedResult, result);

	HashMap<String, String> hashMapWithSpecialCharacter;
	hashMapWithSpecialCharacter.put("key\"1", "va\"lu\"e1");
	hashMapWithSpecialCharacter.put("key\\16", "val\nue\t16");
	hashMapWithSpecialCharacter.put("k\fey\b02", "val\rue02");

	expectedResult = (string) R"({"k\fey\b02": "val\rue02", "key\"1": "va\"lu\"e1", "key\\16": "val\nue\t16"})";
	result = hashMapWithSpecialCharacter.toString();
	ASSERT_STR(expectedResult, result);
}

