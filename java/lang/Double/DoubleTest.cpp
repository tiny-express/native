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

#include "Double.hpp"
using namespace Java::Lang;

TEST (JavaLang, DoubleConstructor) {
	// Given empty value for Double constructor and assign value - Return Double
	Double emptyDouble;
	emptyDouble = 3;
	ASSERT_EQUAL(3, emptyDouble.doubleValue());

	// Given value for Double constructor and assign value - Return integer
	Double validDouble = 3;
	ASSERT_EQUAL(3, validDouble.doubleValue());
}

TEST (JavaLang, DoubleComparision) {
	//Give a valid number and make a comparision
	Double validNumber = 2;
	Double targetNumber;

	// Test validNumber is equal targetNumber
	targetNumber = 2;
	ASSERT_TRUE(validNumber == targetNumber);

	// Test validNumber is not equal targetNumber
	targetNumber = 101;
	ASSERT_TRUE(validNumber != targetNumber);

	// Test validNumber is less than targetNumber
	targetNumber = 3;
	ASSERT_TRUE(validNumber < targetNumber);

	// Test validNumber is equal or less than targetNumber
	targetNumber = 3;
	ASSERT_TRUE(validNumber <= targetNumber);

	// Test validNumber is more than targetNumber
	targetNumber = 1;
	ASSERT_TRUE(validNumber > targetNumber);

	// Test validNumber is equal or more than targetNumber
	targetNumber = 2;
	ASSERT_TRUE(validNumber >= targetNumber);
}

TEST (JavaLang, DoubleOperator) {
	// Given a valid number
	Double validNumber = 6;
	Double targetNumber = 3;

	// Make a summation with targetNumber
	Double summationNumber = 9;
	ASSERT_TRUE(summationNumber == ( validNumber + targetNumber ));

	// Make a subtraction with targetNumber
	Double subtractionNumber = 3;
	ASSERT_TRUE(subtractionNumber == ( validNumber - targetNumber ));

	// Make a multiplication with targetNumber
	Double multiplicationNumber = 18;
	ASSERT_TRUE(multiplicationNumber == ( validNumber * targetNumber ));

	// Make a division with targetNumber
	Double divisionNumber = 2;
	ASSERT_TRUE(divisionNumber == ( validNumber / targetNumber ));
}

TEST (JavaLang, DoubleParseDouble) {
	// Given value for Double constructor and assign value - Return double
	Double validDoublePointer = Double::parseDouble("6");
	ASSERT_EQUAL(6, validDoublePointer.doubleValue());
}

TEST(JavaLang, DoubleToString) {
	// Give a valid object Double - Should be equal
	Double validDouble = 134.123434;
	string expect = (string) "134.123434";
	string result = validDouble.toString();
	ASSERT_STR(expect, result);
}
