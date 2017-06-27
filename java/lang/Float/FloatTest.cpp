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

#include "Float.hpp"

using namespace Java::Lang;

TEST (JavaLang, FloatConstructor) {
    // Create an empty variable. Assign value to it.
    // Than make a comparison bettween the expected result and the real result
	Float emptyFloat;
	emptyFloat = 3.0;
    float expectedResult = 3.0;
    float realResult = emptyFloat.floatValue();
	ASSERT_TRUE(expectedResult == realResult);

    // Create an empty variable. Assign value to it.
    // Than make a comparison bettween the NOT expected result and the real result
    Float notExpectedEmptyFloat;
    notExpectedEmptyFloat = 3.0;
    float notExpectedResult = 3.6;
    realResult = notExpectedEmptyFloat.floatValue();
    ASSERT_FALSE(notExpectedResult == realResult);

    // Input a value of type float to variableFloat.
    // Than make a comparison bettween the expected result and the real result
    Float variableFloat = 9.0;
    expectedResult = 9.0;
    realResult = variableFloat.floatValue();
    ASSERT_EQUAL(expectedResult, realResult);

    // Input a value of type float to variableFloat.
    // Than make a comparison bettween the NOT expected result and the real result
    Float notVariableFloat = 9.0;
    notExpectedResult = 9.9;
    realResult = notVariableFloat.floatValue();
    ASSERT_EQUAL(notExpectedResult , realResult);

    // Use Float::parseFLoat to convert from string to float
    // Than make a comparison bettween the expected result and the real result
	Float testParseFloat = Float::parseFloat("13.02");
    expectedResult = 13.02;
    realResult = testParseFloat.floatValue();
	ASSERT_EQUAL(expectedResult, realResult);

    // Use Float::parseFLoat to convert from string to float
    // Than make a comparison bettween the NOT expected result and the real result
    testParseFloat = Float::parseFloat("13.02");
    notExpectedResult = 130.2;
    realResult = testParseFloat.floatValue();
    ASSERT_NOT_EQUAL(notExpectedResult, realResult);
}

TEST (JavaLang, FloatComparision) {
	// Give a valid number and make a comparision
	Float validNumber = 4.2;
	Float targetNumber;

	// Test validNumber is equal targetNumber
	targetNumber = 4.2;
	ASSERT_TRUE(validNumber == targetNumber);

	// Test validNumber is not equal targetNumber
	targetNumber = 2.1;
	ASSERT_TRUE(validNumber != targetNumber);

	// Test validNumber is less than targetNumber
	targetNumber = 6.8;
	ASSERT_TRUE(validNumber < targetNumber);

	// Test validNumber is equal or less than targetNumber
	targetNumber = 5.5;
	ASSERT_TRUE(validNumber <= targetNumber);

	// Test valid number is more than targetNumber
	targetNumber = 4.0;
	ASSERT_TRUE(validNumber > targetNumber);

	// Test valid number is equal or more than targetNumber
	targetNumber = 1.2;
	ASSERT_TRUE(validNumber >= targetNumber);
}

TEST (JavaLang, FloatOperator) {
	// Given a valid number
	Float validNumber = 4.1;
	Float targetNumber = 2.0;

	// Make a summation with targetNumber
	Float summationNumber = 6.1;
	ASSERT_TRUE(summationNumber == ( validNumber + targetNumber ));

	// Make a subtraction with targetNumber
	Float subtractionNumber = 2.1;
	ASSERT_TRUE(subtractionNumber == ( validNumber - targetNumber ));

	// Make a multiplication with targetNumber
	Float multiplicationNumber = 8.2;
	ASSERT_TRUE(multiplicationNumber == ( validNumber * targetNumber ));

	// Make a division with targetNumber
	Float divisionNumber = 2.05;
	ASSERT_TRUE(divisionNumber == ( validNumber / targetNumber ));
}

TEST (JavaLang, FloatParseFloat) {
	#ifdef __APPLE__
		return;
	#endif
	// Given value for Float constructor and assign value - Return float
	Float validFloatPointer = Float::parseFloat("6");
	float expect = 6;
	ASSERT_EQUAL(expect, validFloatPointer.floatValue());
}


TEST (JavaLang, FloatToString) {
	// Input different values of t-
    // ype float to compare to the result of Float::toString
	Float positiveFloat = 13.02;
	char *expectedResult = "13.02";
	char *realResult = positiveFloat.toString();
	ASSERT_STR(expectedResult,realResult);
	free(realResult);

    Float negativeFloat = -13.02;
    expectedResult = "-13.02";
    realResult = negativeFloat.toString();
    ASSERT_STR(expectedResult,realResult);
    free(realResult);
}