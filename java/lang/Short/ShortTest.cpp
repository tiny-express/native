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

#include "Short.hpp"
#include "../Long/Long.hpp"

using namespace Java::Lang;

TEST (JavaLang, ShortConstructor) {
	
	// 	Given empty value for Short constructor and assign value - Return Long
	Short emptyShort;
	emptyShort = 3;
	ASSERT_EQUAL(3, emptyShort.longValue());
	
	// Given value for Short constructor and assign value - Return Integer
	Short validShort = 3;
	ASSERT_EQUAL(3, validShort.intValue());
	
}

TEST (JavaLang, ShortComparision) {
	// Give a valid number and make a comparision
	Short validNumber = 30000;
	Short targetNumber;
	
	// Test validNumber is equal targetNumber
	targetNumber = 30000;
	ASSERT_TRUE(validNumber == targetNumber);
	
	// Test validNumber is not equal targetNumber
	targetNumber = 13000;
	ASSERT_TRUE(validNumber != targetNumber);
	
	// Test validNumber is less than targetNumber
	targetNumber = 31000;
	ASSERT_TRUE(validNumber < targetNumber);
	
	// Test validNumber is equal or less then targetNumber
	targetNumber = 31300;
	ASSERT_TRUE(validNumber <= targetNumber);
	
	// Test validNumber is more than targetNumber
	targetNumber = 29000;
	ASSERT_TRUE(validNumber > targetNumber);
	
	// Test validNumber is equal or more than targetNumber
	targetNumber = 23777;
	ASSERT_TRUE(validNumber >= targetNumber);
}

TEST (JavaLang, ShortOperator) {
	// 	Given a valid number
	Long validNumber = 5;
	Long targetNumber = 3;
	
	// Make a summation with targetNumber
	Long summationNumber = 8;
	ASSERT_TRUE(summationNumber == ( validNumber + targetNumber ));
	
	// Make a subtraction with targetNumber
	Long subtractionNumber = 2;
	ASSERT_TRUE(subtractionNumber == ( validNumber - targetNumber ));
	
	// Make a multiplication with targetNumber
	Long multiplicationNumber = 15;
	ASSERT_TRUE(multiplicationNumber == ( validNumber * targetNumber ));
	
	// Make a division with targetNumber
	Long divisionNumber = 1;
	ASSERT_TRUE(divisionNumber == ( validNumber / targetNumber ));
	
	// Make a modulo with targetNumber
	Long modNumber = 2;
	ASSERT_TRUE(modNumber == ( validNumber % targetNumber ));
}

TEST (JavaLang, ShortParseShort) {
	// Given value for Long constructor and assign value - Return long
	Short validShortPointer = Short::parseShort("6");
	ASSERT_EQUAL(6, validShortPointer.shortValue());
}

TEST (JavaLang, ShortToString) {
	// Give a valid Short object then compare result of method toString - Should be equals
	Short validShort = 12344;
	
	string expect = (string) "12344";
	string result = validShort.toString();
	ASSERT_STR(expect, result);
}
