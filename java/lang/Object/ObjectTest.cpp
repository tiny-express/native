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

#include "../String/String.hpp"
#include "../Integer/Integer.hpp"
#include "../Long/Long.hpp"
#include "../System/System.hpp"

using namespace Java::Lang;

TEST (JavaLang, JavaInstanceOf) {
	// Given a String instance - Return it should be an instance of String
	String stringInstanceWithSameClass = "test";
	String string2 = "abcd";
	ASSERT_TRUE(instanceof<String>(stringInstanceWithSameClass));
	ASSERT_FALSE(stringInstanceWithSameClass.equals(string2));
	
	// Given a String instance - Return it should be an instance of Object
	String stringInstanceWithSameBaseClass;
	ASSERT_TRUE(instanceof<Object>(stringInstanceWithSameBaseClass));
	
	// Given a Integer instance - Return it should not be an instance of String
	Integer integer = 1;
	ASSERT_FALSE(instanceof<String>(integer));
	
	// Given a Long instance but casted with Object - Return it should be an instance of Long
	Long longNumber = 1;
	Object objectLongNumber = longNumber;
	ASSERT_FALSE(instanceof<Long>(objectLongNumber));
}

TEST (JavaLang, DataTypeBoolean) {
	// Verify syntax of boolean
	boolean a = true;
	ASSERT_TRUE(a);
}

TEST (JavaLang, DataTypeByte) {
	// Verify syntax of byte
	byte a = 65;
	char A = (char) a;
	ASSERT_TRUE(A == 'A');
}

TEST (JavaLang, DataTypeArray) {
	// Array empty initialization
	Array<String> emptyStrings;
	emptyStrings.push("Food Tiny");
	emptyStrings.push("Hello World");
	ASSERT_EQUAL(2, emptyStrings.length);
	
	// Array from initialize list and length property
	Array<byte> bytes = { 64, 65, 66 };
	ASSERT_EQUAL(3, bytes.length);
	
	// Push new element and loop in array
	bytes.push(67);
	bytes.push(68);
	int length = 0;
	for (byte byte : bytes) {
		length++;
	}
	ASSERT_EQUAL(5, length);
	
	// Modify an element in array
	bytes[ 0 ] = 63;
	ASSERT_EQUAL(63, bytes[ 0 ]);
	
	// Merge two arrays with appendable
	Array<String> initializedStrings = { "Food", "Tiny" };
	initializedStrings += { "Hello", "World" };
	ASSERT_EQUAL(4, initializedStrings.length);
	
	// Loop in string array
	int totalCharacters = 0;
	for (String element : initializedStrings) {
		totalCharacters += element.length();
	}
	ASSERT_EQUAL(18, totalCharacters);
	
	// Retrieve  elements from an existing array
	ASSERT_STR("Food", initializedStrings.get(0).toString());
	ASSERT_STR("Tiny", initializedStrings.get(1).toString());
}

TEST (JavaLang, ArrayConstructorWithSize) {
	// Give an Array use constructor with contain size then assert size - Should equal
	Array<int> validArray(10);
	int expect = 10;
	int result = validArray.length;
	ASSERT_EQUAL(expect, result);
	
	int index;
	for (index = 10; index < 20; index++) {
		validArray.push(index);
		expect = index + 1;
		result = validArray.length;
		ASSERT_EQUAL(expect, result);
	}
}

TEST (JavaLang, ArrayConstructorWithCharPointerPointer) {
	// Give an Array use constructor with contain size then assert size - Should equal
	char *stringArray[3] = {
		(char *) "hello",
		(char *) "world",
		nullptr
	};
	char **stringList = (char **) stringArray;
	Array<String> arrayString = stringList;
	ASSERT_EQUAL(2, arrayString.length);
}

TEST (JavaLang, ObjectConstructor) {
	// Normal declaration
	Object objectNormalDeclaration;
	objectNormalDeclaration.hashCode();
	
	// New object with pointer declaration
	Object *objectPointerDeclaration = new Object();
	objectPointerDeclaration->hashCode();
	delete objectPointerDeclaration;
}

TEST (JavaLang, ObjectEquals) {
	// Given two difference instances of Object - Return instances are not equal
	Object object1;
	Object object2;
	ASSERT_FALSE(object1.equals(object2));
	// Supported for == & != operator
	ASSERT_FALSE(object1 == object2);
	ASSERT_TRUE(object1 != object2);
	
	// Given one instance of Object - Return equal with itself
	Object object3;
	ASSERT_TRUE(object3.equals(object3));
	// Supported for == & != operator
	ASSERT_TRUE(object3 == object3);
	ASSERT_FALSE(object3 != object3);
}

TEST (JavaLang, ObjectHashCode) {
	// Given two difference instances of Object - Return memory addresses are not equal
	Object object;
	Object object2;
	ASSERT_NOT_EQUAL(object.hashCode(), object2.hashCode());
	
	// Given one instance of Object - Return it and itself is the same
	Object object3;
	ASSERT_EQUAL(object3.hashCode(), object3.hashCode());
}
