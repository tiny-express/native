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

#include "../../../kernel/Test.hpp"
#include "../../Lang.hpp"
#include "HashMap.hpp"
#include "../ArrayList/ArrayList.hpp"

using namespace Java::Lang;
using namespace Java::Util;

TEST (JavaUtil, HashMapConstructor) {
    String expected;
    String actual;

    // Test default constructor
    HashMap<String, Integer> emptyHashMap;

    // Make sure emptyHashMap is empty
    assertTrue(emptyHashMap.isEmpty());

    // Test copy constructor
    HashMap<String, String> container;
    container.put("sample", "here");
    container.put("key", "value");

    HashMap<String, String> hashMap = container;

    // Test valid size()
    assertEquals(2, hashMap.size());
    assertFalse(hashMap.isEmpty());

    // Test valid data between hashMap and container
    expected = container.get("sample");
    actual = hashMap.get("sample");

    assertFalse(expected.isEmpty());
    assertFalse(actual.isEmpty());
    assertEquals(expected.toString(), actual.toString());

    expected = container.get("key");
    actual = hashMap.get("key");

    assertFalse(expected.isEmpty());
    assertFalse(actual.isEmpty());
    assertEquals(expected.toString(), actual.toString());
}

TEST (JavaUtil, HashMapClear) {
    // Given valid hashMap to test clear()
    HashMap<Long, Integer> hashMap;
    hashMap.put((long) 100, 25);
    hashMap.put((long) 500, 123);
    assertEquals(2, hashMap.size());

    hashMap.clear();
    assertEquals(0, hashMap.size());
}

TEST (JavaUtil, HashMapClone) {
    String actualKey;
    String expected;
    String actual;

    // Create a HashMap to test to test clone()
    HashMap<String, String> hashMap;
    hashMap.put("Key1", "Value of Key1");
    hashMap.put("Key2", "Value of Key2");
    HashMap<String, String> anotherMap = hashMap.clone();

    // Test actualKey = "Key1" is exist in anotherMap
    actualKey = "Key1";
    expected = "Value of Key1";
    actual = anotherMap.get(actualKey);
    assertEquals(expected.toString(), actual.toString());

    // Test actualKey = "Key2" is exist in anotherMap
    actualKey = "Key2";
    expected = "Value of Key2";
    actual = anotherMap.get(actualKey);
    assertEquals(expected.toString(), actual.toString());

    // Test non-exist key
    actualKey = "wrong key";
    actual = anotherMap.get(actualKey);
    assertTrue(actual.isEmpty());
}

TEST (JavaUtil, HashMapContainsKey) {
    boolean actual;

    // Create a HashMap to test
    HashMap<Integer, String> hashMap;
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

TEST (JavaUtil, HashMapContainsValue) {
    boolean actual;

    // Create a HashMap to test
    HashMap<String, Double> hashMap;
    hashMap.put("15.3", 15.3);
    hashMap.put("30.111", 30.111);

    // Valid key
    actual = hashMap.containsValue(15.3);
    assertTrue(actual);

    // Invalid key
    actual = hashMap.containsValue(30.22);
    assertFalse(actual);
}

TEST (JavaUtil, HashMapEntrySet) {
    HashMap<String, String> hashMap;

    int index = 1;

    for (index; index <= 100; index++) {
        hashMap.put("Key " + String::valueOf(index),
                    "Value " + String::valueOf(index));
    }

    int counter = 0;
    Set<class Map<String, String>::Entry> entrySet = hashMap.entrySet();

    // TODO - loint@foodtiny.com will improve entrySet
    // then we can put it inside foreach without any performance issue
    for (Map<String, String>::Entry entry : entrySet) {
        counter += 1;
        if (counter == 1) {
            assertEquals("Key 99", entry.getKey().toString());
            assertEquals("Value 99", entry.getValue().toString());
        }
        if (counter == 2) {
            assertEquals("Key 98", entry.getKey().toString());
            assertEquals("Value 98", entry.getValue().toString());
        }
    }

    // Make sure foreach is working
    assertEquals(100, counter);
}

TEST (JavaUtil, HashMapGet) {
    String expected;
    String actual;

    // Create a HashMap to test
    HashMap<String, String> hashMap;
    hashMap.put("key", "value");

    // Valid key
    expected = "value";
    actual = hashMap.get("key");
    assertEquals(expected.toString(), actual.toString());

    // Invalid key
    actual = hashMap.get("wrong_key");
    assertTrue(actual.isEmpty());
}

TEST (JavaUtil, HashMapIsEmpty) {
    // Create a HashMap to test
    HashMap<String, Float> hashMap;

    // Empty case
    boolean actual = hashMap.isEmpty();
    assertTrue(actual);

    // Not empty case
    hashMap.put("Key1", (float) 123.33);
    assertFalse(hashMap.isEmpty());
}

TEST (JavaUtil, HashMapPut) {
    String expected;
    String actual;

    // Create a HashMap to test
    HashMap<String, String> hashMap;
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

TEST (JavaUtil, HashMapPutAll) {
    // Create a HashMap to test
    HashMap<String, String> hashMap;
    hashMap.put("some string", "Value of Key1");
    hashMap.put("another key", "777");
    hashMap.put("#!@#another", "-123");

    // putAll data of hashMap to targetMap
    HashMap<String, String> targetMap;
    targetMap.putAll(hashMap);

    // Make sure both are the same size
    assertEquals(hashMap.size(), targetMap.size());

    // Make sure both have the same data
    String actualKey = "#!@#another";
    String expected = hashMap.get(actualKey);
    String actual = targetMap.get(actualKey);
    assertEquals(actual.toString(), expected.toString());

    actualKey = "some string";
    expected = hashMap.get(actualKey);
    actual = targetMap.get(actualKey);
    assertEquals(actual.toString(), expected.toString());

    actualKey = "another key";
    expected = hashMap.get(actualKey);
    actual = targetMap.get(actualKey);
    assertEquals(actual.toString(), expected.toString());

    // Invalid case
    actualKey = "some wrong key here";
    expected = hashMap.get(actualKey);
    actual = targetMap.get(actualKey);
    assertTrue(expected.isEmpty());
    assertTrue(actual.isEmpty());
}

TEST (JavaUtil, HashMapPutIfAbsent) {
    String actualKey;
    String expected;
    String actual;

    // Create a HashMap to test
    HashMap<String, String> hashMap;
    hashMap.put("abc", "Value of Key1");

    // Make sure the data is right before test
    actualKey = "abc";
    expected = "Value of Key1";
    actual = hashMap.get(actualKey);
    assertEquals(expected.toString(), actual.toString());

    // Existent key
    expected = "Value of Key1";
    actual = hashMap.putIfAbsent(actualKey, "other value");
    assertEquals(expected.toString(), actual.toString());

    // Make sure the value is not changed.
    expected = "Value of Key1";
    actual = hashMap.get(actualKey);
    assertEquals(expected.toString(), actual.toString());

    // Non-existent key
    String wrongKey = "wrong key";
    expected = "something here";
    String isSucceedPutIfAbsent = hashMap.putIfAbsent(wrongKey, "something here");
    actual = hashMap.get(wrongKey);
    assertTrue(isSucceedPutIfAbsent.isEmpty());
    assertEquals(expected.toString(), actual.toString());
}

TEST (JavaUtil, HashMapRemoveKey) {
    // Create a HashMap to test
    HashMap<String, String> hashMap;
    hashMap.put("Key1", "!@#!@#");
    hashMap.put("another key", "1111");

    // Make sure the size is right
    assertEquals(2, hashMap.size());

    // Make sure the data is right
    String expected = "1111";
    String actual = hashMap.get("another key");
    assertEquals(expected.toString(), actual.toString());

    // Data must be removed after removing
    String isSucceedRemove = hashMap.remove("another key");
    expected = "1111";
    assertEquals(expected.toString(), isSucceedRemove.toString());

    // Size must decrease after removing
    assertEquals(1, hashMap.size());

    // Make sure the old data must not exist any more
    actual = hashMap.get("another key");
    assertTrue(actual.isEmpty());
}

TEST (JavaUtil, HashMapRemoveKeyValue) {
    // Create a HashMap to test
    HashMap<String, String> hashMap;
    hashMap.put("Key1", "Value of Key1");
    hashMap.put("another key", "456");

    // Make sure the size is right before removing
    assertEquals(2, hashMap.size());

    // Make sure the data is right before removing
    String expectedactual = "Value of Key1";
    String actual = hashMap.get("Key1");
    assertEquals(expectedactual.toString(), actual.toString());

    // Invalid case: right case, wrong value
    boolean isSucceedRemove = hashMap.remove("Key1", "456");
    assertFalse(isSucceedRemove);

    // Test remove true by key mapped to specified value
    isSucceedRemove = hashMap.remove("Key1", "Value of Key1");
    assertTrue(isSucceedRemove);
}

TEST (JavaUtil, HashMapReplaceKeyValue) {
    // Create a HashMap to test to test
    HashMap<String, String> hashMap;
    hashMap.put("Key1", "value");
    hashMap.put("key !@#", "1000");
    hashMap.put(".;;',", "ab232");

    // Make sure the data is right before replacing
    String actualKey = ".;;',";
    String expected = "ab232";
    String actual = hashMap.get(actualKey);
    assertEquals(expected.toString(), actual.toString());

    // Replace the oldValue
    String oldValue = "ab232";
    String newValue = "250008";
    String actualReplace = hashMap.replace(actualKey, newValue);
    assertEquals(oldValue.toString(), actualReplace.toString());

    // Make sure the old value is replaced by new value
    expected = newValue;
    actual = hashMap.get(actualKey);
    assertEquals(expected.toString(), actual.toString());

    // Test non-existent key
    actualKey = "Non-existent key";
    actualReplace = hashMap.replace(actualKey, newValue);
    assertEquals("", actualReplace.toString());

}

TEST (JavaUtil, HashMapReplaceKeyOldValueNewValue) {
    // Create a HashMap to test to test
    HashMap<String, String> hashMap;
    hashMap.put("Key1", "Value of Key1");
    hashMap.put("key123", "!@#");

    // Make sure the size is right
    assertEquals(2, hashMap.size());

    // Make sure the data is right
    String actualKey = "key123";
    String expected = "!@#";
    String actual = hashMap.get(actualKey);
    assertEquals(expected.toString(), actual.toString());

    // Replace the old value
    String key = "key123";
    String oldValue = "!@#";
    String newValue = "456";
    boolean isSucceedReplace = hashMap.replace(key, oldValue, newValue);
    assertTrue(isSucceedReplace);

    // Make sure the old value is replace by new value
    actual = hashMap.get(key);
    assertEquals(newValue.toString(), actual.toString());

    // Replace with incorrect key/oldValue
    key = "Key1";
    oldValue = "wrong value";
    newValue = "newValue";
    isSucceedReplace = hashMap.replace(key, oldValue, newValue);
    assertFalse(isSucceedReplace);

    // Make sure the value is not change if replacing is failed
    key = "Key1";
    oldValue = "Value of Key1";
    actual = hashMap.get(key);
    assertEquals(oldValue.toString(), actual.toString());
}

TEST (JavaUtil, HashMapSize) {
    // Create a HashMap to test
    HashMap<Double, String> hashMap;
    hashMap.put(15.22222, "15.22222");
    hashMap.put(-50.2222, "50");

    // Make sure the size is 2
    assertEquals(2, hashMap.size());

    // Add one more key/value and check size again
    hashMap.put((double) 123, "some thing here");
    assertEquals(3, hashMap.size());
}

TEST (JavaUtil, HashMapToString) {
    // Given some valid key/value to test toString()
    HashMap<String, String> hashMap;
    hashMap.put("key1", "value1");
    hashMap.put("key16", "value16");
    hashMap.put("key02", "value02");

    string expectedResult = (string) R"({"key02": "value02", "key1": "value1", "key16": "value16"})";
    string result = hashMap.toString();
    assertEquals(expectedResult, result);

    // Given another hash map type to test
    HashMap<Integer, Integer> anotherHashMap;
    anotherHashMap.put(1, 12313);
    anotherHashMap.put(2, 76767);

    expectedResult = (string) R"({1: 12313, 2: 76767})";
    result = anotherHashMap.toString();
    assertEquals(expectedResult, result);

    // Given empty hash map to test default toString()
    HashMap<String, Float> emptyHashMap;
    expectedResult = (string) "{}";
    result = emptyHashMap.toString();
    assertEquals(expectedResult, result);

    ArrayList<Integer> validArrayListInteger1 = {1, 2, 3, 4, 5};
    ArrayList<Integer> validArrayListInteger2 = {100, 100, 100, 100, 1};
    HashMap<String, ArrayList<Integer>> arrayListInHashMap;
    arrayListInHashMap.put("ArrayList1", validArrayListInteger1);
    arrayListInHashMap.put("ArrayList2", validArrayListInteger2);
    expectedResult = (string) R"({"ArrayList1": [1, 2, 3, 4, 5], "ArrayList2": [100, 100, 100, 100, 1]})";
    result = arrayListInHashMap.toString();
    assertEquals(expectedResult, result);

    // Test HashMap::toString with HashMap has String (key or value) that come from another HashMap::toString()
    HashMap<String, String> result2;

    result2.put("firstName", "firstName");
    result2.put("lastName", "lastName");
    result2.put("birthday", "birthday");
    result2.put("avatar", "avatar");
    result2.put("gender", "gender");
    result2.put("email", "email");

    HashMap<String, String> result3;

    result3.put("Status", "true");
    result3.put("Infor", result2.toString());

    expectedResult = (string) R"({"Infor": {"avatar": "avatar", "birthday": "birthday", "email": "email", "firstName": "firstName", "gender": "gender", "lastName": "lastName"}, "Status": "true"})";
    assertEquals(expectedResult, result3.toString());
}

TEST (JavaUtil, HashMapEquals) {
    // Create a HashMap
    HashMap<String, String> hashMap;
    hashMap.put("Key1", "Value of Key1");
    hashMap.put("Key2", "Value of Key2");

    // Create an other HashMap with the same data
    HashMap<String, String> sameHashMap;
    sameHashMap.put("Key1", "Value of Key1");
    sameHashMap.put("Key2", "Value of Key2");

    // Create an other HashMap with the different key
    HashMap<String, String> differentKeyHashMap;
    differentKeyHashMap.put("different key", "Value of Key1");
    differentKeyHashMap.put("Key2", "Value of Key2");

    // Create an other HashMap with the different value
    HashMap<String, String> differentValueHashMap;
    differentValueHashMap.put("Key1", "different value");
    differentValueHashMap.put("Key2", "Value of Key2");

    // Create an other HashMap with the different size
    HashMap<String, String> differentSizeHashMap;
    differentSizeHashMap.put("different key", "Value of Key1");

    // Test valid case
    assertTrue(hashMap.equals(sameHashMap));

    // Test invalid case
    assertFalse(hashMap.equals(differentKeyHashMap));
    assertFalse(hashMap.equals(differentValueHashMap));
    assertFalse(hashMap.equals(differentSizeHashMap));
}

TEST (JavaUtil, HashMapReinitialize) {
    // Create a HashMap
    HashMap<String, String> hashMap;
    hashMap.put("Key1", "Value of Key1");
    hashMap.put("Key2", "Value of Key2");

    // Reinitialize
    hashMap.reinitialize();

    // Make sure hashMap has been reinitialized
    assertTrue(hashMap.isEmpty());
    assertEquals(0, hashMap.size());
    assertEquals("{}", hashMap.toString());
}

//TEST(JavaUtil, HashMapReplaceAll) {
//    /* Test HashMap<String, Integer> */
//        // Create a HashMap
//    HashMap<String, Integer> hashMap;
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
//    /* Test HashMap<String, String> */
//        // Create a HashMap
//    HashMap<String, String> anotherHashMap;
//    anotherHashMap.put("key1", "1");
//    anotherHashMap.put("key2", "2");
//
//        // Create function
//    std::function<void(String, String, String&)> anotherFunction
//            = [] (String key, String value, String &result) {
//                result = value + (string) " New value";
//            };
//
//        // replaceAll
//    anotherHashMap.replaceAll(anotherFunction);
//
//        // Make sure the value has changed base on the anotherFunction
//    assertEquals("1 New value", anotherHashMap.get("key1").toString());
//    assertEquals("2 New value", anotherHashMap.get("key2").toString());
//}
//
//TEST(JavaUtil, HashMapMerge) {
//    /* Test HashMap<String, Integer> */
//        // Create a HashMap
//    HashMap<String, Integer> hashMap;
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
//    Integer resultMergeKey1HashMap = hashMap.merge("key1", 10, function);
//    Integer resultMergeKey2HashMap = hashMap.merge("key2", 10, function);
//
//        // Make sure the value has changed base on the function
//    assertEquals(11, hashMap.get("key1").intValue());
//    assertEquals(11, resultMergeKey1HashMap.intValue());
//    assertEquals(12, hashMap.get("key2").intValue());
//    assertEquals(12, resultMergeKey2HashMap.intValue());
//
//        // merge: non-existent key
//    Integer resultMergeNonExistentKeyHashMap
//            = hashMap.merge("Invalid Key", 10, function);
//
//        // Make sure the hashMap has NOT changed base on the function
//    assertEquals(11, hashMap.get("key1").intValue());
//    assertEquals(12, hashMap.get("key2").intValue());
//    assertEquals(2, hashMap.size());
//    assertEquals(0, resultMergeNonExistentKeyHashMap.intValue());
//
//    /* Test HashMap<String, String> */
//        // Create a HashMap
//    HashMap<String, String> anotherHashMap;
//    anotherHashMap.put("key1", "1");
//    anotherHashMap.put("key2", "2");
//
//        // Create function
//    std::function<void(String, String, String&)> anotherFunction
//            = [] (String oldValue, String value, String &newValue) {
//                newValue = oldValue + value;
//            };
//
//        // merge: existent key
//    String resultMergeKey1AnotherHashMap
//            = anotherHashMap.merge("key1", " New value", anotherFunction);
//    String resultMergeKey2AnotherHashMap
//            = anotherHashMap.merge("key2", " New value", anotherFunction);
//
//        // Make sure the value has changed base on the anotherFunction
//    assertEquals("1 New value", anotherHashMap.get("key1").toString());
//    assertEquals("1 New value", resultMergeKey1AnotherHashMap.toString());
//    assertEquals("2 New value", anotherHashMap.get("key2").toString());
//    assertEquals("2 New value", resultMergeKey2AnotherHashMap.toString());
//
//        // merge: non-existent key
//    String resultMergeNonExistentKeyAnotherHashMap
//            = anotherHashMap.merge("Invalid Key", " New value", anotherFunction);
//
//        // Make sure the anotherHashMap has NOT changed base on the function
//    assertEquals("1 New value", anotherHashMap.get("key1").toString());
//    assertEquals("2 New value", anotherHashMap.get("key2").toString());
//    assertEquals(2, anotherHashMap.size());
//    assertEquals("", resultMergeNonExistentKeyAnotherHashMap.toString());
//}
//
//TEST(JavaUtil, HashMapCompute) {
//	/* Test HashMap<String, Integer> */
//	    // Create a HashMap
//	HashMap<String, Integer> hashMap;
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
//	Integer resultComputeKey1HashMap = hashMap.compute("key1", function);
//	Integer resultComputeKey2HashMap = hashMap.compute("key2", function);
//
//	    // Make sure the value has changed base on the function
//	assertEquals(11, hashMap.get("key1").intValue());
//	assertEquals(11, resultComputeKey1HashMap.intValue());
//	assertEquals(12, hashMap.get("key2").intValue());
//	assertEquals(12, resultComputeKey2HashMap.intValue());
//
//	    // compute: non-existent key
//	Integer resultComputeNonExistentKeyHashMap
//			= hashMap.compute("Invalid Key", function);
//
//	    // Make sure the hashMap has NOT changed base on the function
//	assertEquals(11, hashMap.get("key1").intValue());
//	assertEquals(12, hashMap.get("key2").intValue());
//	assertEquals(2, hashMap.size());
//	assertEquals(0, resultComputeNonExistentKeyHashMap.intValue());
//
//	/* Test HashMap<String, String> */
//	    // Create a HashMap
//	HashMap<String, String> anotherHashMap;
//	anotherHashMap.put("key1", "1");
//	anotherHashMap.put("key2", "2");
//
//	    // Create function
//	std::function<void(String, String, String&)> anotherFunction
//			= [] (String key, String oldValue, String &newValue) {
//                String value = " New value";
//				newValue = oldValue + value;
//			};
//
//	    // compute: existent key
//	String resultComputeKey1AnotherHashMap
//			= anotherHashMap.compute("key1", anotherFunction);
//	String resultComputeKey2AnotherHashMap
//			= anotherHashMap.compute("key2", anotherFunction);
//
//	    // Make sure the value has changed base on the anotherFunction
//	assertEquals("1 New value", anotherHashMap.get("key1").toString());
//	assertEquals("1 New value", resultComputeKey1AnotherHashMap.toString());
//	assertEquals("2 New value", anotherHashMap.get("key2").toString());
//	assertEquals("2 New value", resultComputeKey2AnotherHashMap.toString());
//
//	    // compute: non-existent key
//	String resultComputeNonExistentKeyAnotherHashMap
//			= anotherHashMap.compute("Invalid Key", anotherFunction);
//
//	    // Make sure the anotherHashMap has NOT changed base on the function
//	assertEquals("1 New value", anotherHashMap.get("key1").toString());
//	assertEquals("2 New value", anotherHashMap.get("key2").toString());
//	assertEquals(2, anotherHashMap.size());
//	assertEquals("", resultComputeNonExistentKeyAnotherHashMap.toString());
//
//    /* Test with the function do nothing = notherHashMap.remove(key) */
//        // Create function
//    std::function<void(String, String, String&)> nullFunction
//            = [] (String key, String oldValue, String &newValue) {
//            };
//
//        // compute key2 with nullFunction
//    String resultComputeKey1AnotherHashMapNullFunction
//            = anotherHashMap.compute("key2", nullFunction);
//
//        // Make sure the value of key1 has NOT changed
//    assertEquals("1 New value", anotherHashMap.get("key1").toString());
//
//        // Make sure the key2 has been removed
//    assertEquals("", anotherHashMap.get("key2").toString());
//    assertEquals(1, anotherHashMap.size());
//    assertEquals("", resultComputeKey1AnotherHashMapNullFunction.toString());
//}
//
//TEST(JavaUtil, HashMapComputeIfAbsent) {
//    /* Test HashMap<String, Integer> */
//        // Create a HashMap
//    HashMap<String, Integer> hashMap;
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
//    Integer resultComputeIfAbsentKey1HashMap
//            = hashMap.computeIfAbsent("key1",function);
//    Integer resultComputeIfAbsentKey2HashMap
//            = hashMap.computeIfAbsent("key2",function);
//
//        // Make sure the value has NOT changed base on the function
//    assertEquals(1, hashMap.get("key1").intValue());
//    assertEquals(1, resultComputeIfAbsentKey1HashMap.intValue());
//    assertEquals(2, hashMap.get("key2").intValue());
//    assertEquals(2, resultComputeIfAbsentKey2HashMap.intValue());
//
//        // computeIfAbsent: non-existent key
//    Integer resultComputeIfAbsentNonExistentKeyHashMap
//            = hashMap.computeIfAbsent("Invalid Key", function);
//
//        // Make sure the "Invalid Key" and its value are existent
//    assertEquals(1, hashMap.get("key1").intValue());
//    assertEquals(2, hashMap.get("key2").intValue());
//    assertEquals(10, hashMap.get("Invalid Key").intValue());
//    assertEquals(3, hashMap.size());
//    assertEquals(10, resultComputeIfAbsentNonExistentKeyHashMap.intValue());
//
//        // computeIfAbsent: "key3" has default value
//    hashMap.put("key3", 0);
//    Integer resultComputeIfAbsentDefaultValueHashMap
//            = hashMap.computeIfAbsent("key3", function);
//
//        // Make sure the value of "key3" has changed
//    assertEquals(1, hashMap.get("key1").intValue());
//    assertEquals(2, hashMap.get("key2").intValue());
//    assertEquals(10, hashMap.get("Invalid Key").intValue());
//    assertEquals(10, hashMap.get("key3").intValue());
//    assertEquals(4, hashMap.size());
//    assertEquals(10, resultComputeIfAbsentDefaultValueHashMap.intValue());
//}
//
//TEST(JavaUtil, HashMapComputeIfPresent) {
//    /* Test HashMap<String, Integer> */
//        // Create a HashMap
//    HashMap<String, Integer> hashMap;
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
//    Integer resultComputeIfPresentKey1HashMap
//            = hashMap.computeIfPresent("key1", function);
//    Integer resultComputeIfPresentKey2HashMap
//            = hashMap.computeIfPresent("key2", function);
//
//        // Make sure the value has CHANGED base on the function
//    assertEquals(11, hashMap.get("key1").intValue());
//    assertEquals(11, resultComputeIfPresentKey1HashMap.intValue());
//    assertEquals(12, hashMap.get("key2").intValue());
//    assertEquals(12, resultComputeIfPresentKey2HashMap.intValue());
//
//        // computeIfPresent: non-existent key
//    Integer resultComputeIfPresentNonExistentKeyHashMap
//            = hashMap.computeIfPresent("Invalid Key", function);
//
//        // Make sure the data is NOT CHANGED
//    assertEquals(11, hashMap.get("key1").intValue());
//    assertEquals(12, hashMap.get("key2").intValue());
//    assertEquals(0, hashMap.get("Invalid Key").intValue());
//    assertEquals(2, hashMap.size());
//    assertEquals(0, resultComputeIfPresentNonExistentKeyHashMap.intValue());
//
//        // computeIfPresent: "key3" has default value
//    hashMap.put("key3", 0);
//    Integer resultComputeIfPresentDefaultValueHashMap
//            = hashMap.computeIfPresent("key3", function);
//
//        // Make sure the value of "key3" has NOT CHANGED
//    assertEquals(11, hashMap.get("key1").intValue());
//    assertEquals(12, hashMap.get("key2").intValue());
//    assertEquals(0, hashMap.get("key3").intValue());
//    assertEquals(3, hashMap.size());
//    assertEquals(0, resultComputeIfPresentDefaultValueHashMap.intValue());
//
//        // Create nullFunction
//    std::function<void(String, Integer, Integer&)> nullFunction
//            = [] (String key, Integer oldValue, Integer &newValue) {
//            };
//
//        // computeIfPresent: "key2" with nullFunction => hashMap.remove("key3")
//    Integer resultComputeIfPresentNullFunctionHashMap
//                = hashMap.computeIfPresent("key2", nullFunction);
//
//        // Make sure the value of "key2" has been REMOVED
//    assertEquals(11, hashMap.get("key1").intValue());
//    assertEquals(0, hashMap.get("key2").intValue());
//    assertEquals(0, hashMap.get("key3").intValue());
//    assertEquals(2, hashMap.size());
//    assertEquals(0, resultComputeIfPresentDefaultValueHashMap.intValue());
//}
//
//TEST(JavaUtil, HashMapForEach) {
//    /* Test HashMap<String, Integer> */
//        // Create a HashMap
//    HashMap<String, Integer> hashMap;
//    hashMap.put("key1", 1);
//    hashMap.put("key2", 2);
//    Integer result;
//
//        // Create function
//    std::function<void(String, Integer)> function
//            = [] (String key, Integer value) {
//                printf("TEST(JavaUtil, HashMapForEach) is OK");
//            };
//
//        // foreach
//    hashMap.forEach(function);
//}