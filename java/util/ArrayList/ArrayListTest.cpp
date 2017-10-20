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
#include "../List/List.hpp"
#include "../../lang/String/String.hpp"
#include "../../lang/Integer/Integer.hpp"
#include "ArrayList.hpp"

using namespace Java::Lang;

TEST(JavaUtil, ArrayListConstructor) {
	// Standard declaration
	ArrayList<Integer> integerArrayList;
	Integer value = 1324;
	integerArrayList.add(value);
	integerArrayList.add(value);
	integerArrayList.add(value);
	integerArrayList.add(value);
	assertEquals(4, integerArrayList.size());

	// Standard declaration
	ArrayList<String> stringArrayList;
	String element = "Element";
	stringArrayList.add(element);
	stringArrayList.add(element);
	stringArrayList.add(element);
	stringArrayList.add(element);
	assertEquals(4, stringArrayList.size());

	// Standard declaration
	Array<String> arrayString = { "hello", "world" };
	ArrayList<String> stringArrayListCopy = arrayString;
	assertEquals(2, stringArrayListCopy.size());
}

TEST(JavaUtil, ArrayListDestructor) {
	// Give a pointer ArrayList was allocated
    // then delete this pointer - Should not leak memory
	ArrayList<Integer> *intArray = new ArrayList<Integer>(10);
	delete intArray;
}

TEST(JavaUtil, ArrayListSize) {
	// Give an empty ArrayList
    // then compare size of this list - Should equal
	ArrayList<Integer> emptyArray;
	int expect = 0;
	int result = emptyArray.size();
	assertEquals(expect, result);

	// Give an valid ArrayList
    // then compare size of this list - Should equal
	int size = 10;
	ArrayList<Integer> validArray(size);
	expect = size;
	result = validArray.size();
	assertEquals(expect, result);
}

TEST(JavaUtil, ArrayListAdd) {
	// Give an valid ArrayList
    // then add one element - Should equal
	ArrayList<Integer> validArrayList = {1, 2, 3};
	validArrayList.add(4);
	int sizeExpect = 4;
	int sizeResult = validArrayList.size();
	assertEquals(sizeExpect, sizeResult);

	// Compare validArrayList toString
	string stringExpect = (string) "[1, 2, 3, 4]";
	string stringResult = validArrayList.toString();
	assertEquals(stringExpect, stringResult);

	// Add new element at index 0 then compare string - Should equal
	validArrayList.add(0, 0);
	stringExpect = (string) "[0, 1, 2, 3, 4]";
	stringResult = validArrayList.toString();
	assertEquals(stringExpect, stringResult);
}

TEST(JavaUtil, ArrayListContains) {
    // Give a valid ArrayList then test method contains - Should equal
    ArrayList<String> validArrayList = {"nakhoadl", "thuydung",
                                        "loint", "dthongvl", "dquang"};
    boolean result = validArrayList.contains("loint");
    assertTrue(result);
    result = validArrayList.contains("huuphuoc");
    assertFalse(result);
}

TEST(JavaUtil, ArrayListIsEmpty) {
	// Give an empty ArrayList - Should equal
	ArrayList<Long> emptyArrayList;
	boolean result = emptyArrayList.isEmpty();
	assertTrue(result);

	// Give an valid ArrayList - Should equal
	ArrayList<Float> validArrayList = {1.2, 1.4};
	result = validArrayList.isEmpty();
	assertFalse(result);

	// Compare string of validArrayList - Should equal
	string stringExpect = (string) "[1.2, 1.4]";
	string stringResult = validArrayList.toString();
	assertEquals(stringExpect, stringResult);
}

TEST(JavaUtil, ArrayListClear) {
	// Give an valid ArrayList
	ArrayList<String> validArrayList = {"food", "tiny"};
	string stringExpect = (string) R"(["food", "tiny"])";
	string stringResult = validArrayList.toString();
	assertEquals(stringExpect, stringResult);

	// Clear validArrayList - Should equal
	validArrayList.clear();
	int sizeExpect = 0;
	int sizeResult = validArrayList.size();
	assertEquals(sizeExpect, sizeResult);

	stringExpect = (string) "[]";
	stringResult = validArrayList.toString();
	assertEquals(stringExpect, stringResult);
}

TEST(JavaUtil, ArrayListClone) {
    // Give a valid ArrayList
    // then clone this to new object - Should equal
	ArrayList<String> validArrayList = {"food", "tiny"};
	ArrayList<String> cloneArrayList = validArrayList.clone();

	string stringExpect = (string) R"(["food", "tiny"])";
	string stringResult = cloneArrayList.toString();
	assertEquals(stringExpect, stringResult);
	int sizeExpect = 2;
	int sizeResult = cloneArrayList.size();
	assertEquals(sizeExpect, sizeResult);
}

TEST(JavaUtil, ArrayListForEach) {
	ArrayList<Integer> expected;
	ArrayList<Integer> actual;

	int index = 1;
	for (index; index <= 100; ++index) {
		expected.add(index);
	}

	index = 1;
	for (Integer element : expected) {
		actual.add(index++);
	}

	assertArray(expected, actual);
}

TEST(JavaUtil, ArrayListGet) {
    // Give a valid ArrayList and get value some index
	ArrayList<Integer> validArrayList = {1, 2, 3};
	int expect = 1;
	int result = validArrayList.get(0).intValue();
	assertEquals(expect, result);

	try {
		validArrayList.get(-1);
	} catch (IndexOutOfBoundsException exception) {
		string stringExpect = (string) "Index out of range: -1";
		string stringResult = exception.toString();
        assertEquals(stringExpect, stringResult);
	}

	try {
		validArrayList.get(1000);
	} catch (IndexOutOfBoundsException exception) {
		string stringExpect = (string) "Index out of range: 1000";
		string stringResult = exception.toString();
        assertEquals(stringExpect, stringResult);
	}
}

TEST(JavaUtil, ArrayListIndexOf) {
    // Give a valid ArrayList
    // then test method indexOf - Should equal
    ArrayList<Integer> validArrayList = {1, 2, 3};
    int expect = 2;
    int result = validArrayList.indexOf(3);
    assertEquals(expect, result);

    expect = -1;
    result = validArrayList.indexOf(31);
    assertEquals(expect, result);
}

TEST(JavaUtil, ArrayListLastIndexOf) {
    // Give a valid ArrayList
    // then test method indexOf - Should equal
    ArrayList<Integer> validArrayList = {1, 2, 3, 4, 1, 2, 3, 3, 1, 4};
    int expect = 7;
    int result = validArrayList.lastIndexOf(3);
    assertEquals(expect, result);

    expect = -1;
    result = validArrayList.lastIndexOf(31);
    assertEquals(expect, result);
}

TEST(JavaUtil, ArrayListRemoveIndex) {
    // Give a valid ArrayList
    // then test method with index remove - Should equal
    ArrayList<Long> validArrayList = {1, 2, 3, 4, 1, 2, 3, 3, 1, 4};
    int expect = 3;
    int result = validArrayList.remove(7).intValue();
    assertEquals(expect, result);

    string stringExpect = (string) "[1, 2, 3, 4, 1, 2, 3, 1, 4]";
    string stringResult = validArrayList.toString();
    assertEquals(stringExpect, stringResult);

    try {
        validArrayList.remove(-1);
    } catch (IndexOutOfBoundsException exception) {
        assertEquals("Index out of range: -1", exception.getMessage().toString());
    }
}

TEST(JavaUtil, ArrayListRemoveElement) {
    // Give a valid ArrayList
    // then test method remove with element - Should equal
    ArrayList<String> validArrayList = {"123", "456", "789"};
    boolean result = validArrayList.remove("456");
    string stringExpect = (string) R"(["123", "789"])";
    string stringResult = validArrayList.toString();
    assertTrue(result);
    assertEquals(stringExpect, stringResult);

    // Test case false
    result = validArrayList.remove("012");
    stringExpect = (string) R"(["123", "789"])";
    stringResult = validArrayList.toString();
    assertFalse(result);
    assertEquals(stringExpect, stringResult);
}

TEST(JavaUtil, ArrayListSet) {
    // Give a valid ArrayList
    // then test method set - Should equal
    ArrayList<String> validArrayList = {"String", "String", "Integer", "String"};
    validArrayList.set(2, "String");
    string stringExpect = (string) R"(["String", "String", "String", "String"])";
    string stringResult = validArrayList.toString();
    assertEquals(stringExpect, stringResult);

    try {
        validArrayList.set(-1, "String");
    } catch (IndexOutOfBoundsException exception) {
        assertEquals("Index out of range: -1", exception.getMessage().toString());
    }
}

TEST(JavaUtil, ArrayListHashCode) {
    ArrayList<String> validArrayList = {"String", "String", "Integer", "String"};
    assertNotEquals(validArrayList.hashCode(), 0);
}

TEST(JavaUtil, ArrayListToString) {
    // Give an empty ArrayList<Integer>
    // then compare toString() - Should equal
    ArrayList<Integer> inValidArrayListInteger;
    string result = inValidArrayListInteger.toString();
    string expect = (string) "[]";
    assertEquals(result, expect);

    // Give an ArrayList<Integer>
    // then compare toString() - Should equal
	ArrayList<Integer> validArrayListInteger = {1, 2, 4, 5};
	result = validArrayListInteger.toString();
	expect = (string) "[1, 2, 4, 5]";
	assertEquals(result, expect);

    // Give an ArrayList<ArrayList<Integer>>
    // then compare toString() - Should equal
    ArrayList<ArrayList<Integer>> arrayListInArrayList;
    arrayListInArrayList.add(validArrayListInteger);
    arrayListInArrayList.add(validArrayListInteger);
    arrayListInArrayList.add(inValidArrayListInteger);
    result = arrayListInArrayList.toString();
    expect = (string) "[[1, 2, 4, 5], [1, 2, 4, 5], []]";
    assertEquals(expect, result);

    // Test ArrayList<String> with element from another ArrayList.toString();
	ArrayList<String> arrayListStringInArrayList;
	arrayListStringInArrayList.add("String");
	arrayListStringInArrayList.add(validArrayListInteger.toString());
	arrayListStringInArrayList.add("ArrayList");
	result = arrayListStringInArrayList.toString();
    expect = (string) R"(["String", [1, 2, 4, 5], "ArrayList"])";
	assertEquals(expect, result);

//    // Give an ArrayList<String> with Json control character
//	ArrayList<String> arrayListString;
//    arrayListString.add("He\"llo\"");
//    arrayListString.add("I\b");
//    arrayListString.add("am\t");
//    arrayListString.add("Le\ngend");
//    arrayListString.add("Acher\ry");
//    arrayListString.add("from\f");
//    arrayListString.add("Food\\Tiny");
//    result = arrayListString.toString();
//    expect = (string) R"([He\"llo\", I\b, am\t, Le\ngend, Acher\ry, from\f, Food\\Tiny])";
//    assertEquals(expect, result);
}
