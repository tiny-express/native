/**
 * Copyright 2017-2020 Tiny Express Project. All rights reserved.
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

#include "../../../../Test.hpp"
#include "ConcurrentHashMap.hpp"

using namespace Java::Lang;
using namespace Java::Util::Concurrent;

TEST (JavaUtilConcurrentConcurrentHashMap, Constructor) {
	String expected;
	String actual;

	// Test default constructor
	ConcurrentHashMap<String, String> emptyConcurrentHashMap;

	// Make sure emptyConcurrentHashMap is empty
	assertTrue(emptyConcurrentHashMap.isEmpty());

	// Test copy constructor
	ConcurrentHashMap<String, String> hashMap;
    hashMap.put("sample", "here");
    hashMap.put("key", "value");

    ConcurrentHashMap<String, String> container = hashMap;

	// Test valid size()
    assertFalse(hashMap.isEmpty());
	assertEquals(2, hashMap.size());
    assertEquals(2, container.size());

	// Test valid data between hashMap and container
	assertEquals(hashMap.get("sample"), container.get("sample"));
}

TEST (JavaUtilConcurrentConcurrentHashMap, Clear) {
	// Given valid hashMap to test clear()
	ConcurrentHashMap<Long, Integer> hashMap;
	hashMap.put((long) 100, 25);
	hashMap.put((long) 500, 123);
	assertEquals(2, hashMap.size());

	hashMap.clear();
	assertEquals(0, hashMap.size());
}

TEST (JavaUtilConcurrentConcurrentHashMap, Clone) {
//	String actualKey;
//	String expected;
//	String actual;
//
//	// Create a ConcurrentHashMap to test to test clone()
//	ConcurrentHashMap<String, String> hashMap;
//	hashMap.put("Key1", "Value of Key1");
//	hashMap.put("Key2", "Value of Key2");
//	ConcurrentHashMap<String, String> anotherMap = hashMap.clone();
//
//	// Test actualKey = "Key1" is exist in anotherMap
//	actualKey = "Key1";
//	expected = "Value of Key1";
//	actual = anotherMap.get(actualKey);
//	assertEquals(expected.toString(), actual.toString());
//
//	// Test actualKey = "Key2" is exist in anotherMap
//	actualKey = "Key2";
//	expected = "Value of Key2";
//	actual = anotherMap.get(actualKey);
//	assertEquals(expected.toString(), actual.toString());
//
//	// Test non-exist key
//	actualKey = "wrong key";
//	actual = anotherMap.get(actualKey);
//	assertTrue(actual.isEmpty());
}

TEST (JavaUtilConcurrentConcurrentHashMap, ContainsKey) {
	boolean actual;

	// Create a ConcurrentHashMap to test
	ConcurrentHashMap<Integer, String> hashMap;
	hashMap.put(3, "three");
	hashMap.put(17, "seven teen");
	hashMap.put(-52, "negative fifty two");

	// Valid key
	actual = hashMap.containsKey(-52);
	assertTrue(actual);

	// Invalid key
	actual = hashMap.containsKey(100);
	assertFalse(actual);
}

TEST (JavaUtilConcurrentConcurrentHashMap, ContainsValue) {
	boolean actual;

	// Create a ConcurrentHashMap to test
	ConcurrentHashMap<String, Double> hashMap;
	hashMap.put("15.3", 15.3);
	hashMap.put("30.111", 30.111);

	// Valid key
	actual = hashMap.containsValue(15.3);
	assertTrue(actual);

	// Invalid key
	actual = hashMap.containsValue(30.22);
	assertFalse(actual);
}

TEST (JavaUtilConcurrentConcurrentHashMap, EntrySet) {
//	ConcurrentHashMap<String, String> hashMap;
//	int index = 1;
//	for (index; index <= 100; index++) {
//		hashMap.put("Key " + String::valueOf(index),
//		            "Value " + String::valueOf(index));
//	}
//	int counter = 0;
//	Set<class Map<String, String>::Entry> entrySet = hashMap.entrySet();
//	for (Map<String, String>::Entry entry : entrySet) {
//		counter += 1;
//	}
//
//	// Make sure foreach is working
//	assertEquals(100, counter);
//
//	ConcurrentHashMap<String, String *> hashMapStringPointer;
//	hashMapStringPointer.put("test1", new String("test1"));
//	hashMapStringPointer.put("test2", new String("test1"));
//	hashMapStringPointer.put("test3", new String("test1"));
//	for (Map<String, String *>::Entry entry : hashMapStringPointer.entrySet()) {
//		assertEquals("test1", entry.getValue()->toString());
//		String *stringValue = entry.getValue();
//		delete stringValue;
//	}
}

TEST(JavaUtilConcurrentConcurrentHashMap, ForEach) {
    ConcurrentHashMap<String, String> hashMap;
    int index = 1;
    for (index; index <= 100; index++) {
        hashMap.put("Key " + String::valueOf(index),
                    "Value " + String::valueOf(index));
    }
    int counter = 0;
    hashMap.forEach([&counter](String, String) {
        counter += 1;
        return true;
    });

    // Make sure foreach is working
    assertEquals(100, counter);

    ConcurrentHashMap<String, String *> hashMapStringPointer;
    hashMapStringPointer.put("test1", new String("test1"));
    hashMapStringPointer.put("test2", new String("test1"));
    hashMapStringPointer.put("test3", new String("test1"));
    hashMapStringPointer.forEach([&counter](String key, String *value) {
        assertEquals("test1", value->toString());
        String *stringValue = value;
        delete stringValue;
        return true;
    });
}

TEST (JavaUtilConcurrentConcurrentHashMap, Get) {
	String expected;
	String actual;

	// Create a ConcurrentHashMap to test
	ConcurrentHashMap<String, String> hashMap;
	hashMap.put("key", "value");

	// Valid key
	expected = "value";
	actual = hashMap.get("key");
	assertEquals(expected.toString(), actual.toString());

	// Invalid key
	actual = hashMap.get("wrong_key");
	assertTrue(actual.isEmpty());
}

TEST (JavaUtilConcurrentConcurrentHashMap, IsEmpty) {
	// Create a ConcurrentHashMap to test
	ConcurrentHashMap<String, Float> hashMap;

	// Empty case
	boolean actual = hashMap.isEmpty();
	assertTrue(actual);

	// Not empty case
	hashMap.put("Key1", (float) 123.33);
	assertFalse(hashMap.isEmpty());
}

TEST (JavaUtilConcurrentConcurrentHashMap, Put) {
	String expected;
	String actual;

	// Create a ConcurrentHashMap to test
	ConcurrentHashMap<String, String> hashMap;
	hashMap.put("abc", "Value of Key1");
	hashMap.put("some key here", "456");

	// Make sure hashMap is not null
	assertEquals(2, hashMap.size());

	// Make sure the data is safe
	// Valid key
	expected = "Value of Key1";
	actual = hashMap.get("abc");
	assertEquals(expected.toString(), actual.toString());

	// Valid key
	expected = "456";
	actual = hashMap.get("some key here");
	assertEquals(expected.toString(), actual.toString());
}
//
//TEST (JavaUtilConcurrentConcurrentHashMap, PutAll) {
//	// Create a ConcurrentHashMap to test
//	ConcurrentHashMap<String, String> hashMap;
//	hashMap.put("some string", "Value of Key1");
//	hashMap.put("another key", "777");
//	hashMap.put("#!@#another", "-123");
//
//	// putAll data of hashMap to targetMap
//	ConcurrentHashMap<String, String> targetMap;
//	targetMap.putAll(hashMap);
//
//	// Make sure both are the same size
//	assertEquals(hashMap.size(), targetMap.size());
//
//	// Make sure both have the same data
//	String actualKey = "#!@#another";
//	String expected = hashMap.get(actualKey);
//	String actual = targetMap.get(actualKey);
//	assertEquals(actual.toString(), expected.toString());
//
//	actualKey = "some string";
//	expected = hashMap.get(actualKey);
//	actual = targetMap.get(actualKey);
//	assertEquals(actual.toString(), expected.toString());
//
//	actualKey = "another key";
//	expected = hashMap.get(actualKey);
//	actual = targetMap.get(actualKey);
//	assertEquals(actual.toString(), expected.toString());
//
//	// Invalid case
//	actualKey = "some wrong key here";
//	expected = hashMap.get(actualKey);
//	actual = targetMap.get(actualKey);
//	assertTrue(expected.isEmpty());
//	assertTrue(actual.isEmpty());
//}
//
//TEST (JavaUtilConcurrentConcurrentHashMap, PutIfAbsent) {
//	String actualKey;
//	String expected;
//	String actual;
//
//	// Create a ConcurrentHashMap to test
//	ConcurrentHashMap<String, String> hashMap;
//	hashMap.put("abc", "Value of Key1");
//
//	// Make sure the data is right before test
//	actualKey = "abc";
//	expected = "Value of Key1";
//	actual = hashMap.get(actualKey);
//	assertEquals(expected.toString(), actual.toString());
//
//	// Existent key
//	expected = "Value of Key1";
//	actual = hashMap.putIfAbsent(actualKey, "other value");
//	assertEquals(expected.toString(), actual.toString());
//
//	// Make sure the value is not changed.
//	expected = "Value of Key1";
//	actual = hashMap.get(actualKey);
//	assertEquals(expected.toString(), actual.toString());
//
//	// Non-existent key
//	String wrongKey = "wrong key";
//	expected = "something here";
//	String isSucceedPutIfAbsent = hashMap.putIfAbsent(wrongKey, "something here");
//	actual = hashMap.get(wrongKey);
//	assertTrue(isSucceedPutIfAbsent.isEmpty());
//	assertEquals(expected.toString(), actual.toString());
//}
//
//TEST (JavaUtilConcurrentConcurrentHashMap, RemoveKey) {
//	// Create a ConcurrentHashMap to test
//	ConcurrentHashMap<String, String> hashMap;
//	hashMap.put("Key1", "!@#!@#");
//	hashMap.put("another key", "1111");
//
//	// Make sure the size is right
//	assertEquals(2, hashMap.size());
//
//	// Make sure the data is right
//	String expected = "1111";
//	String actual = hashMap.get("another key");
//	assertEquals(expected.toString(), actual.toString());
//
//	// Data must be removed after removing
//	String isSucceedRemove = hashMap.remove("another key");
//	expected = "1111";
//	assertEquals(expected.toString(), isSucceedRemove.toString());
//
//	// Size must decrease after removing
//	assertEquals(1, hashMap.size());
//
//	// Make sure the old data must not exist any more
//	actual = hashMap.get("another key");
//	assertTrue(actual.isEmpty());
//
//    /* Remove a non-existent key */
//    isSucceedRemove = hashMap.remove("non-existent key");
//    expected = "";
//    assertEquals(expected, isSucceedRemove);
//}
//
//TEST (JavaUtilConcurrentConcurrentHashMap, RemoveKeyValue) {
//	// Create a ConcurrentHashMap to test
//	ConcurrentHashMap<String, String> hashMap;
//	hashMap.put("Key1", "Value of Key1");
//	hashMap.put("another key", "456");
//
//	// Make sure the size is right before removing
//	assertEquals(2, hashMap.size());
//
//	// Make sure the data is right before removing
//	String expectedactual = "Value of Key1";
//	String actual = hashMap.get("Key1");
//	assertEquals(expectedactual.toString(), actual.toString());
//
//	// Invalid case: right case, wrong value
//	boolean isSucceedRemove = hashMap.remove("Key1", "456");
//	assertFalse(isSucceedRemove);
//
//	// Test remove true by key mapped to specified value
//	isSucceedRemove = hashMap.remove("Key1", "Value of Key1");
//	assertTrue(isSucceedRemove);
//}
//
//TEST (JavaUtilConcurrentConcurrentHashMap, ReplaceKeyValue) {
//	// Create a ConcurrentHashMap to test to test
//	ConcurrentHashMap<String, String> hashMap;
//	hashMap.put("Key1", "value");
//	hashMap.put("key !@#", "1000");
//	hashMap.put(".;;',", "ab232");
//
//	// Make sure the data is right before replacing
//	String actualKey = ".;;',";
//	String expected = "ab232";
//	String actual = hashMap.get(actualKey);
//	assertEquals(expected.toString(), actual.toString());
//
//	// Replace the oldValue
//	String oldValue = "ab232";
//	String newValue = "250008";
//	String actualReplace = hashMap.replace(actualKey, newValue);
//	assertEquals(oldValue.toString(), actualReplace.toString());
//
//	// Make sure the old value is replaced by new value
//	expected = newValue;
//	actual = hashMap.get(actualKey);
//	assertEquals(expected.toString(), actual.toString());
//
//	// Test non-existent key
//	actualKey = "Non-existent key";
//	actualReplace = hashMap.replace(actualKey, newValue);
//	assertEquals("", actualReplace.toString());
//
//}
////
//TEST (JavaUtilConcurrentConcurrentHashMap, ReplaceKeyOldValueNewValue) {
//	// Create a ConcurrentHashMap to test to test
//	ConcurrentHashMap<String, String> hashMap;
//	hashMap.put("Key1", "Value of Key1");
//	hashMap.put("key123", "!@#");
//
//	// Make sure the size is right
//	assertEquals(2, hashMap.size());
//
//	// Make sure the data is right
//	String actualKey = "key123";
//	String expected = "!@#";
//	String actual = hashMap.get(actualKey);
//	assertEquals(expected.toString(), actual.toString());
//
//	// Replace the old value
//	String key = "key123";
//	String oldValue = "!@#";
//	String newValue = "456";
//	boolean isSucceedReplace = hashMap.replace(key, oldValue, newValue);
//	assertTrue(isSucceedReplace);
//
//	// Make sure the old value is replace by new value
//	actual = hashMap.get(key);
//	assertEquals(newValue.toString(), actual.toString());
//
//	// Replace with incorrect key/oldValue
//	key = "Key1";
//	oldValue = "wrong value";
//	newValue = "newValue";
//	isSucceedReplace = hashMap.replace(key, oldValue, newValue);
//	assertFalse(isSucceedReplace);
//
//	// Make sure the value is not change if replacing is failed
//	key = "Key1";
//	oldValue = "Value of Key1";
//	actual = hashMap.get(key);
//	assertEquals(oldValue.toString(), actual.toString());
//}
//
//TEST (JavaUtilConcurrentConcurrentHashMap, Size) {
//	// Create a ConcurrentHashMap to test
//	ConcurrentHashMap<Double, String> hashMap;
//	hashMap.put(15.22222, "15.22222");
//	hashMap.put(-50.2222, "50");
//
//// Make sure the size is 2
//	assertEquals(2, hashMap.size());
//
//// Add one more key/value and check size again
//	hashMap.put((double) 123, "some thing here");
//	assertEquals(3, hashMap.size());
//}
//
//TEST (JavaUtilConcurrentConcurrentHashMap, Equals) {
//	// Create a ConcurrentHashMap
//	ConcurrentHashMap<String, String> hashMap;
//	hashMap.put("Key1", "Value of Key1");
//	hashMap.put("Key2", "Value of Key2");
//
//	// Create an other ConcurrentHashMap with the same data
//	ConcurrentHashMap<String, String> sameConcurrentHashMap;
//	sameConcurrentHashMap.put("Key1", "Value of Key1");
//	sameConcurrentHashMap.put("Key2", "Value of Key2");
//
//	// Create an other ConcurrentHashMap with the different key
//	ConcurrentHashMap<String, String> differentKeyConcurrentHashMap;
//	differentKeyConcurrentHashMap.put("different key", "Value of Key1");
//	differentKeyConcurrentHashMap.put("Key2", "Value of Key2");
//
//	// Create an other ConcurrentHashMap with the different value
//	ConcurrentHashMap<String, String> differentValueConcurrentHashMap;
//	differentValueConcurrentHashMap.put("Key1", "different value");
//	differentValueConcurrentHashMap.put("Key2", "Value of Key2");
//
//	// Create an other ConcurrentHashMap with the different size
//	ConcurrentHashMap<String, String> differentSizeConcurrentHashMap;
//	differentSizeConcurrentHashMap.put("different key", "Value of Key1");
//
//	// Test valid case
//	assertTrue(hashMap.equals(sameConcurrentHashMap));
//
//	// Test invalid case
//	assertFalse(hashMap.equals(differentKeyConcurrentHashMap));
//	assertFalse(hashMap.equals(differentValueConcurrentHashMap));
//	assertFalse(hashMap.equals(differentSizeConcurrentHashMap));
//}
//
//TEST (JavaUtilConcurrentConcurrentHashMap, ToString) {
//	// Given some valid key/value to test toString()
//	ConcurrentHashMap<String, String> hashMap;
//	hashMap.put("key1", "value1");
//
//	String expected = R"({"key1": "value1"})";
//    String actual = hashMap.toString();
//	assertEquals(expected, actual);
//
//	// Given empty hash map to test default toString()
//	ConcurrentHashMap<String, Float> emptyConcurrentHashMap;
//	expected = (string) "{}";
//	assertEquals(expected, emptyConcurrentHashMap.toString());
//
//	// Given hash map of array list to test json serialization
//	ConcurrentHashMap<String, ArrayList<String>> hashMapOfArrayList;
//	ArrayList<String> listValue;
//	listValue.add("value1");
//	listValue.add("value2");
//	listValue.add("");
//	hashMapOfArrayList.put("listValue", listValue);
//	expected = (string) "{\"listValue\": [\"value1\", \"value2\", \"\"]}";
//	assertEquals(expected, hashMapOfArrayList.toString());
//
//	// Given hash map of hash map to test json serialization
//	ConcurrentHashMap<String, ConcurrentHashMap<String, String>> hashMapOfConcurrentHashMap;
//	ConcurrentHashMap<String, String> hashMapItem;
//	hashMapItem.put("key1", "value1");
//	hashMapItem.put("key2", "value2");
//	hashMapOfConcurrentHashMap.put("hashmap", hashMapItem);
//	expected = (string) "{\"hashmap\": {\"key2\": \"value2\", \"key1\": \"value1\"}}";
//	assertEquals(expected, hashMapOfConcurrentHashMap.toString());
//}
//
//TEST (JavaUtilConcurrentConcurrentHashMap, Reinitialize) {
//	// Create a ConcurrentHashMap
//	ConcurrentHashMap<String, String> hashMap;
//	hashMap.put("Key1", "Value of Key1");
//	hashMap.put("Key2", "Value of Key2");
//
//	// Reinitialize
//	hashMap.reinitialize();
//
//	// Make sure hashMap has been reinitialized
//	assertTrue(hashMap.isEmpty());
//	assertEquals(0, hashMap.size());
//	assertEquals("{}", hashMap.toString());
//}
//
//TEST(JavaUtilConcurrentConcurrentHashMap, ReplaceAll) {
//    /* Test ConcurrentHashMap<String, Integer> */
//        // Create a ConcurrentHashMap
//    ConcurrentHashMap<String, Integer> hashMap;
//    hashMap.put("key1", 1);
//    hashMap.put("key2", 2);
//
//        // Create function
//    std::function<void(String, Integer, Integer&)> function
//            = [] (String key, Integer value, Integer &result) {
//        result = value * 2;
//    };
//
//        // replaceAll
//    hashMap.replaceAll(function);
//
//        // Make sure the value has changed base on the function
//    assertEquals(2, hashMap.get("key1").intValue());
//    assertEquals(4, hashMap.get("key2").intValue());
//
//    /* Test ConcurrentHashMap<String, String> */
//        // Create a ConcurrentHashMap
//    ConcurrentHashMap<String, String> anotherConcurrentHashMap;
//    anotherConcurrentHashMap.put("key1", "1");
//    anotherConcurrentHashMap.put("key2", "2");
//
//        // Create function
//    std::function<void(String, String, String&)> anotherFunction
//            = [] (String key, String value, String &result) {
//                result = value + (string) " New value";
//            };
//
//        // replaceAll
//    anotherConcurrentHashMap.replaceAll(anotherFunction);
//
//        // Make sure the value has changed base on the anotherFunction
//    assertEquals("1 New value", anotherConcurrentHashMap.get("key1").toString());
//    assertEquals("2 New value", anotherConcurrentHashMap.get("key2").toString());
//}

//TEST(JavaUtilConcurrentConcurrentHashMap, Merge) {
//    /* Test ConcurrentHashMap<String, Integer> */
//        // Create a ConcurrentHashMap
//    ConcurrentHashMap<String, Integer> hashMap;
//    hashMap.put("key1", 1);
//    hashMap.put("key2", 2);
//
//        // Create function
//    std::function<void(Integer, Integer, Integer&)> function
//            = [] (Integer oldValue, Integer value, Integer &newValue) {
//                newValue = oldValue + value;
//            };
//
//        // merge: existent key
//    Integer resultMergeKey1ConcurrentHashMap = hashMap.merge("key1", 10, function);
//    Integer resultMergeKey2ConcurrentHashMap = hashMap.merge("key2", 10, function);
//
//        // Make sure the value has changed base on the function
//    assertEquals(11, hashMap.get("key1").intValue());
//    assertEquals(11, resultMergeKey1ConcurrentHashMap.intValue());
//    assertEquals(12, hashMap.get("key2").intValue());
//    assertEquals(12, resultMergeKey2ConcurrentHashMap.intValue());
//
//        // merge: non-existent key
//    Integer resultMergeNonExistentKeyConcurrentHashMap
//            = hashMap.merge("Invalid Key", 10, function);
//
//        // Make sure the hashMap has NOT changed base on the function
//    assertEquals(11, hashMap.get("key1").intValue());
//    assertEquals(12, hashMap.get("key2").intValue());
//    assertEquals(2, hashMap.size());
//    assertEquals(0, resultMergeNonExistentKeyConcurrentHashMap.intValue());
//
//    /* Test ConcurrentHashMap<String, String> */
//        // Create a ConcurrentHashMap
//    ConcurrentHashMap<String, String> anotherConcurrentHashMap;
//    anotherConcurrentHashMap.put("key1", "1");
//    anotherConcurrentHashMap.put("key2", "2");
//
//        // Create function
//    std::function<void(String, String, String&)> anotherFunction
//            = [] (String oldValue, String value, String &newValue) {
//                newValue = oldValue + value;
//            };
//
//        // merge: existent key
//    String resultMergeKey1AnotherConcurrentHashMap
//            = anotherConcurrentHashMap.merge("key1", " New value", anotherFunction);
//    String resultMergeKey2AnotherConcurrentHashMap
//            = anotherConcurrentHashMap.merge("key2", " New value", anotherFunction);
//
//        // Make sure the value has changed base on the anotherFunction
//    assertEquals("1 New value", anotherConcurrentHashMap.get("key1").toString());
//    assertEquals("1 New value", resultMergeKey1AnotherConcurrentHashMap.toString());
//    assertEquals("2 New value", anotherConcurrentHashMap.get("key2").toString());
//    assertEquals("2 New value", resultMergeKey2AnotherConcurrentHashMap.toString());
//
//        // merge: non-existent key
//    String resultMergeNonExistentKeyAnotherConcurrentHashMap
//            = anotherConcurrentHashMap.merge("Invalid Key", " New value", anotherFunction);
//
//        // Make sure the anotherConcurrentHashMap has NOT changed base on the function
//    assertEquals("1 New value", anotherConcurrentHashMap.get("key1").toString());
//    assertEquals("2 New value", anotherConcurrentHashMap.get("key2").toString());
//    assertEquals(2, anotherConcurrentHashMap.size());
//    assertEquals("", resultMergeNonExistentKeyAnotherConcurrentHashMap.toString());
//}
//
//TEST(JavaUtilConcurrentConcurrentHashMap, Compute) {
//	/* Test ConcurrentHashMap<String, Integer> */
//	    // Create a ConcurrentHashMap
//	ConcurrentHashMap<String, Integer> hashMap;
//	hashMap.put("key1", 1);
//	hashMap.put("key2", 2);
//
//	    // Create function
//	std::function<void(String, Integer, Integer&)> function
//			= [] (String key, Integer value, Integer &newValue) {
//				newValue = value + 10;
//			};
//
//	    // compute: existent key
//	Integer resultComputeKey1ConcurrentHashMap = hashMap.compute("key1", function);
//	Integer resultComputeKey2ConcurrentHashMap = hashMap.compute("key2", function);
//
//	    // Make sure the value has changed base on the function
//	assertEquals(11, hashMap.get("key1").intValue());
//	assertEquals(11, resultComputeKey1ConcurrentHashMap.intValue());
//	assertEquals(12, hashMap.get("key2").intValue());
//	assertEquals(12, resultComputeKey2ConcurrentHashMap.intValue());
//
//	    // compute: non-existent key
//	Integer resultComputeNonExistentKeyConcurrentHashMap
//			= hashMap.compute("Invalid Key", function);
//
//	    // Make sure the hashMap has NOT changed base on the function
//	assertEquals(11, hashMap.get("key1").intValue());
//	assertEquals(12, hashMap.get("key2").intValue());
//	assertEquals(2, hashMap.size());
//	assertEquals(0, resultComputeNonExistentKeyConcurrentHashMap.intValue());
//
//	/* Test ConcurrentHashMap<String, String> */
//	    // Create a ConcurrentHashMap
//	ConcurrentHashMap<String, String> anotherConcurrentHashMap;
//	anotherConcurrentHashMap.put("key1", "1");
//	anotherConcurrentHashMap.put("key2", "2");
//
//	    // Create function
//	std::function<void(String, String, String&)> anotherFunction
//			= [] (String key, String oldValue, String &newValue) {
//                String value = " New value";
//				newValue = oldValue + value;
//			};
//
//	    // compute: existent key
//	String resultComputeKey1AnotherConcurrentHashMap
//			= anotherConcurrentHashMap.compute("key1", anotherFunction);
//	String resultComputeKey2AnotherConcurrentHashMap
//			= anotherConcurrentHashMap.compute("key2", anotherFunction);
//
//	    // Make sure the value has changed base on the anotherFunction
//	assertEquals("1 New value", anotherConcurrentHashMap.get("key1").toString());
//	assertEquals("1 New value", resultComputeKey1AnotherConcurrentHashMap.toString());
//	assertEquals("2 New value", anotherConcurrentHashMap.get("key2").toString());
//	assertEquals("2 New value", resultComputeKey2AnotherConcurrentHashMap.toString());
//
//	    // compute: non-existent key
//	String resultComputeNonExistentKeyAnotherConcurrentHashMap
//			= anotherConcurrentHashMap.compute("Invalid Key", anotherFunction);
//
//	    // Make sure the anotherConcurrentHashMap has NOT changed base on the function
//	assertEquals("1 New value", anotherConcurrentHashMap.get("key1").toString());
//	assertEquals("2 New value", anotherConcurrentHashMap.get("key2").toString());
//	assertEquals(2, anotherConcurrentHashMap.size());
//	assertEquals("", resultComputeNonExistentKeyAnotherConcurrentHashMap.toString());
//
//    /* Test with the function do nothing = notherConcurrentHashMap.remove(key) */
//        // Create function
//    std::function<void(String, String, String&)> nullFunction
//            = [] (String key, String oldValue, String &newValue) {
//            };
//
//        // compute key2 with nullFunction
//    String resultComputeKey1AnotherConcurrentHashMapNullFunction
//            = anotherConcurrentHashMap.compute("key2", nullFunction);
//
//        // Make sure the value of key1 has NOT changed
//    assertEquals("1 New value", anotherConcurrentHashMap.get("key1").toString());
//
//        // Make sure the key2 has been removed
//    assertEquals("", anotherConcurrentHashMap.get("key2").toString());
//    assertEquals(1, anotherConcurrentHashMap.size());
//    assertEquals("", resultComputeKey1AnotherConcurrentHashMapNullFunction.toString());
//}
//
//TEST(JavaUtilConcurrentConcurrentHashMap, ComputeIfAbsent) {
//    /* Test ConcurrentHashMap<String, Integer> */
//        // Create a ConcurrentHashMap
//    ConcurrentHashMap<String, Integer> hashMap;
//    hashMap.put("key1", 1);
//    hashMap.put("key2", 2);
//
//        // Create function
//    std::function<void(String, Integer, Integer&)> function
//            = [] (String key, Integer value, Integer &newValue) {
//                newValue = 10;
//            };
//
//        // computeIfAbsent: existent key
//    Integer resultComputeIfAbsentKey1ConcurrentHashMap
//            = hashMap.computeIfAbsent("key1",function);
//    Integer resultComputeIfAbsentKey2ConcurrentHashMap
//            = hashMap.computeIfAbsent("key2",function);
//
//        // Make sure the value has NOT changed base on the function
//    assertEquals(1, hashMap.get("key1").intValue());
//    assertEquals(1, resultComputeIfAbsentKey1ConcurrentHashMap.intValue());
//    assertEquals(2, hashMap.get("key2").intValue());
//    assertEquals(2, resultComputeIfAbsentKey2ConcurrentHashMap.intValue());
//
//        // computeIfAbsent: non-existent key
//    Integer resultComputeIfAbsentNonExistentKeyConcurrentHashMap
//            = hashMap.computeIfAbsent("Invalid Key", function);
//
//        // Make sure the "Invalid Key" and its value are existent
//    assertEquals(1, hashMap.get("key1").intValue());
//    assertEquals(2, hashMap.get("key2").intValue());
//    assertEquals(10, hashMap.get("Invalid Key").intValue());
//    assertEquals(3, hashMap.size());
//    assertEquals(10, resultComputeIfAbsentNonExistentKeyConcurrentHashMap.intValue());
//
//        // computeIfAbsent: "key3" has default value
//    hashMap.put("key3", 0);
//    Integer resultComputeIfAbsentDefaultValueConcurrentHashMap
//            = hashMap.computeIfAbsent("key3", function);
//
//        // Make sure the value of "key3" has changed
//    assertEquals(1, hashMap.get("key1").intValue());
//    assertEquals(2, hashMap.get("key2").intValue());
//    assertEquals(10, hashMap.get("Invalid Key").intValue());
//    assertEquals(10, hashMap.get("key3").intValue());
//    assertEquals(4, hashMap.size());
//    assertEquals(10, resultComputeIfAbsentDefaultValueConcurrentHashMap.intValue());
//}
//
//TEST(JavaUtilConcurrentConcurrentHashMap, ComputeIfPresent) {
//    /* Test ConcurrentHashMap<String, Integer> */
//        // Create a ConcurrentHashMap
//    ConcurrentHashMap<String, Integer> hashMap;
//    hashMap.put("key1", 1);
//    hashMap.put("key2", 2);
//
//        // Create function
//    std::function<void(String, Integer, Integer&)> function
//            = [] (String key, Integer oldValue, Integer &newValue) {
//                newValue = oldValue + 10;
//            };
//
//        // computeIfPresent: existent key
//    Integer resultComputeIfPresentKey1ConcurrentHashMap
//            = hashMap.computeIfPresent("key1", function);
//    Integer resultComputeIfPresentKey2ConcurrentHashMap
//            = hashMap.computeIfPresent("key2", function);
//
//        // Make sure the value has CHANGED base on the function
//    assertEquals(11, hashMap.get("key1").intValue());
//    assertEquals(11, resultComputeIfPresentKey1ConcurrentHashMap.intValue());
//    assertEquals(12, hashMap.get("key2").intValue());
//    assertEquals(12, resultComputeIfPresentKey2ConcurrentHashMap.intValue());
//
//        // computeIfPresent: non-existent key
//    Integer resultComputeIfPresentNonExistentKeyConcurrentHashMap
//            = hashMap.computeIfPresent("Invalid Key", function);
//
//        // Make sure the data is NOT CHANGED
//    assertEquals(11, hashMap.get("key1").intValue());
//    assertEquals(12, hashMap.get("key2").intValue());
//    assertEquals(0, hashMap.get("Invalid Key").intValue());
//    assertEquals(2, hashMap.size());
//    assertEquals(0, resultComputeIfPresentNonExistentKeyConcurrentHashMap.intValue());
//
//        // computeIfPresent: "key3" has default value
//    hashMap.put("key3", 0);
//    Integer resultComputeIfPresentDefaultValueConcurrentHashMap
//            = hashMap.computeIfPresent("key3", function);
//
//        // Make sure the value of "key3" has NOT CHANGED
//    assertEquals(11, hashMap.get("key1").intValue());
//    assertEquals(12, hashMap.get("key2").intValue());
//    assertEquals(0, hashMap.get("key3").intValue());
//    assertEquals(3, hashMap.size());
//    assertEquals(0, resultComputeIfPresentDefaultValueConcurrentHashMap.intValue());
//
//        // Create nullFunction
//    std::function<void(String, Integer, Integer&)> nullFunction
//            = [] (String key, Integer oldValue, Integer &newValue) {
//            };
//
//        // computeIfPresent: "key2" with nullFunction => hashMap.remove("key3")
//    Integer resultComputeIfPresentNullFunctionConcurrentHashMap
//                = hashMap.computeIfPresent("key2", nullFunction);
//
//        // Make sure the value of "key2" has been REMOVED
//    assertEquals(11, hashMap.get("key1").intValue());
//    assertEquals(0, hashMap.get("key2").intValue());
//    assertEquals(0, hashMap.get("key3").intValue());
//    assertEquals(2, hashMap.size());
//    assertEquals(0, resultComputeIfPresentDefaultValueConcurrentHashMap.intValue());
//}