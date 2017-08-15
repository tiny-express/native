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

#include "UUID.hpp"

TEST (JavaUtil, UUIDClockSequence) {
	// Given valid uuid and expectedResult based on result of java code
	UUID uuid = UUID::fromString("38400000-8cf0-11bd-b23e-10b96e4ef00d");
	int expectedResult = 12862;
	
	ASSERT_EQUAL(expectedResult, uuid.clockSequence());
}

TEST (JavaUtil, UUIDConstructor) {
	// Given valid construct to test
	UUID uuid = UUID(123, 456);
	
	long result = uuid.getMostSignificantBits();
	long expectedValue = 123;
	ASSERT_EQUAL(expectedValue, result);
	
	result = uuid.getLeastSignificantBits();
	expectedValue = 456;
	ASSERT_EQUAL(expectedValue, result);
	
	// Given valid static constructor with randomUUID
	String expectedString = "38400000-8cf0-11bd-b23e-10b96e4ef00d";
	uuid = UUID::fromString(expectedString);
	long expectedMostSigBits = 4053239666997989821;
	long expectedLeastSigBits = -5603022497796657139;
	
	ASSERT_EQUAL(expectedMostSigBits, uuid.getMostSignificantBits());
	ASSERT_EQUAL(expectedLeastSigBits, uuid.getLeastSignificantBits());
}

TEST (JavaUtil, UUIDCompare) {
	// Given valid 2 UUIDs, both of them will never be equal if different instance
	
	UUID uuid = UUID(123, 456);
	
	UUID targetLessThan = UUID(123, 455);
	UUID targetEqual = UUID(123, 456);
	UUID targetMoreThan = UUID(345, 345);
	
	long result = uuid.compareTo(targetLessThan);
	long expectedValue = 1;
	ASSERT_EQUAL(expectedValue, result);
	
	result = uuid.compareTo(targetEqual);
	expectedValue = 0;
	ASSERT_EQUAL(expectedValue, result);
	
	result = uuid.compareTo(targetMoreThan);
	expectedValue = -1;
	ASSERT_EQUAL(expectedValue, result);
}

TEST (JavaUtil, UUIDEquals) {
	// Given valid an instance of UUID, test equals with ifself
	UUID uuid = UUID::randomUUID();
	
	ASSERT_TRUE(uuid.equals(uuid));
}

TEST (JavaUtil, UUIDGetSignificantBits) {
	// Given valid UUID to test getLeast and getMost of significant bits inside this class
	long expectedMost = 100000000;
	long expectedLeast = 5000000;
	UUID uuid = UUID(expectedMost, expectedLeast);
	
	ASSERT_EQUAL(expectedMost, uuid.getMostSignificantBits());
	
	ASSERT_EQUAL(expectedLeast, uuid.getLeastSignificantBits());
}

TEST (JavaUtil, UUIDToString) {
	// Given valid uuid to test toString() - this test case was based on java's result
	UUID uuid = UUID(4053239666997989821, -5603022497796657139);
	
	String expectedString = "38400000-8cf0-11bd-b23e-10b96e4ef00d";
	ASSERT_STR(expectedString.toString(), uuid.toString().toString());
}