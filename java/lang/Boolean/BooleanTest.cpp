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

#include "Boolean.hpp"

TEST (JavaLang, BooleanConstructor) {
	// Give a object Boolean with value true - Should be true
	Boolean objectBoolean1(true);
	ASSERT_TRUE(objectBoolean1.booleanValue());
	
	// Give a object Boolean with value false - Should be false
	Boolean objectBoolean2(false);
	ASSERT_FALSE(objectBoolean2.booleanValue());
	
	// Give a object Boolean with String - Should be true
	Boolean objectBoolean3("True");
	ASSERT_TRUE(objectBoolean3.booleanValue());
	
	// Give a object Boolean with String - Should be false
	Boolean objectBoolean4("False");
	ASSERT_FALSE(objectBoolean4.booleanValue());
}

TEST (JavaLang, BooleanDestructor) {
	// Create new object Boolean, then delete - Should not leak memory
	Boolean *newBoolean = new Boolean(true);
	boolean result = newBoolean->booleanValue();
	ASSERT_TRUE(result);
	delete newBoolean;
}

TEST (JavaLang, BooleanCompare) {
	boolean booleanTrue = true;
	boolean booleanFalse = false;
	
	// Give two boolean (true - true) to compare - Should be equal
	int expect = 0;
	int result = Boolean::compare(booleanTrue, booleanTrue);
	ASSERT_EQUAL(expect, result);
	
	// Give two boolean (true - false) to compare - Should equal
	expect = 1;
	result = Boolean::compare(booleanTrue, booleanFalse);
	ASSERT_EQUAL(expect, result);
	
	// Give two boolean (false - true) to compare - Should equal
	expect = -1;
	result = Boolean::compare(booleanFalse, booleanTrue);
	ASSERT_EQUAL(expect, result);
}

TEST (JavaLang, BooleanCompareTo) {
	Boolean objectBooleanTrue(true);
	Boolean objectBooleanFalse(false);
	
	// Give two object Boolean (true - true) to compare - Should be equal
	int expect = 0;
	int result = objectBooleanTrue.compareTo(objectBooleanTrue);
	ASSERT_EQUAL(expect, result);
	
	// Give two object Boolean (true - false) to compare - Should equal
	expect = 1;
	result = objectBooleanTrue.compareTo(objectBooleanFalse);
	ASSERT_EQUAL(expect, result);
	
	// Give two object Boolean (false - true) to compare - Should equal
	expect = -1;
	result = objectBooleanFalse.compareTo(objectBooleanTrue);
	ASSERT_EQUAL(expect, result);
}

TEST (JavaLang, BooleanGetBoolean) {
	// Give two value boolean (true - true) - Should equal
	boolean expect = true;
	boolean result = Boolean::getBoolean("True");
	ASSERT_EQUAL(expect, result);
	
	// Give two value boolean (false - false) - Should equal
	expect = false;
	result = Boolean::getBoolean("False");
	ASSERT_EQUAL(expect, result);
}

TEST (JavaLang, BooleanParseBoolean) {
	// Give two value boolean (true - true) - Should equal
	boolean expect = true;
	boolean result = Boolean::parseBoolean("True");
	ASSERT_EQUAL(expect, result);
	
	// Give two value boolean (false - false) - Should equal
	expect = false;
	result = Boolean::parseBoolean("False");
	ASSERT_EQUAL(expect, result);
}

TEST (JavaLang, BooleanToString) {
	// Give two string - Should equal
	Boolean objectBooleanTrue(true);
	string expect = (string) "true";
	string result = objectBooleanTrue.toString();
	ASSERT_STR(expect, result);
	
	// Give two string - Should equal
	Boolean objectBooleanFalse(false);
	expect = (string) "false";
	result = objectBooleanFalse.toString();
	ASSERT_STR(expect, result);
	
	// Give two string - Should equal
	expect = (string) "true";
	result = Boolean::toString(true);
	ASSERT_STR(expect, result);
}

TEST (JavaLang, BooleanStaticValueOf) {
	// Give two value boolean (true - true) - Should equal
	boolean expect = true;
	boolean result = Boolean::valueOf("True");
	ASSERT_EQUAL(expect, result);
	
	// Give two value boolean (false - false) - Should equal
	expect = false;
	result = Boolean::valueOf("False");
	ASSERT_EQUAL(expect, result);
}

TEST (JavaLang, BooleanValueOf) {
	// Give two boolean - Should equal
	boolean expect = true;
	boolean result = Boolean::valueOf(expect).booleanValue();
	ASSERT_EQUAL(expect, result);
	
	// Give two boolean - Should equal
	expect = false;
	result = Boolean::valueOf(expect).booleanValue();
	ASSERT_EQUAL(expect, result);
}
