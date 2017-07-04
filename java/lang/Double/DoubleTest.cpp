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

/**
 * A constant holding the positive infinity of type
 * {@code double}. It is equal to the value returned by
 * {@code Double.longBitsToDouble(0x7ff0000000000000L)}.
 */
static double POSITIVE_INFINITY_DOUBLE = 1.0 / 0.0;

/**
 * A constant holding the negative infinity of type
 * {@code double}. It is equal to the value returned by
 * {@code Double.longBitsToDouble(0xfff0000000000000L)}.
 */
static double NEGATIVE_INFINITY_DOUBLE = -1.0 / 0.0;

/**
 * A constant holding a Not-a-Number (NaN) value of type
 * {@code double}. It is equivalent to the value returned by
 * {@code Double.longBitsToDouble(0x7ff8000000000000L)}.
 */
static double NaN_DOUBLE = 0.0 / 0.0;

/**
 * A constant holding the largest positive finite value of type
 * {@code double},
 * (2-2<sup>-52</sup>)&middot;2<sup>1023</sup>.  It is equal to
 * the hexadecimal floating-point literal
 * {@code 0x1.fffffffffffffP+1023} and also equal to
 * {@code Double.longBitsToDouble(0x7fefffffffffffffL)}.
 */
static double MAX_VALUE_DOUBLE = 0x1.fffffffffffffP+1023; // 1.7976931348623157e+308

/**
 * A constant holding the smallest positive normal value of type
 * {@code double}, 2<sup>-1022</sup>.  It is equal to the
 * hexadecimal floating-point literal {@code 0x1.0p-1022} and also
 * equal to {@code Double.longBitsToDouble(0x0010000000000000L)}.
 */
static double MIN_NORMAL_DOUBLE = 0x1.0p-1022; // 2.2250738585072014E-308

/**
 * A constant holding the smallest positive nonzero value of type
 * {@code double}, 2<sup>-1074</sup>. It is equal to the
 * hexadecimal floating-point literal
 * {@code 0x0.0000000000001P-1022} and also equal to
 * {@code Double.longBitsToDouble(0x1L)}.
 */
static double MIN_VALUE_DOUBLE = 0x0.0000000000001P-1022; // 4.9e-324

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
    #ifdef __APPLE__
        return;
    #endif
	// Given value for Double constructor and assign value - Return double
	Double validDoublePointer = Double::parseDouble("6");
	ASSERT_EQUAL(6, validDoublePointer.doubleValue());
}

TEST (JavaLang, DoubleToString){
	// Create variable to test
	Double variableTestToString;
	string expectedResultToString;
	string actualResultToString;

	// Test POSITIVE_INFINITY_DOUBLE
	variableTestToString = POSITIVE_INFINITY_DOUBLE;
	expectedResultToString = "inf";
	actualResultToString = variableTestToString.toString();
	ASSERT_STR(expectedResultToString , actualResultToString);
    free(actualResultToString);

	// Test NEGATIVE_INFINITY_DOUBLE
	variableTestToString = NEGATIVE_INFINITY_DOUBLE;
	expectedResultToString = "-inf";
	actualResultToString = variableTestToString.toString();
	ASSERT_STR(expectedResultToString , actualResultToString);
	free(actualResultToString);

	// Test NaN_DOUBLE
//    variableTestToString = NaN_DOUBLE;
//    expectedResultToString = "-nan";
//    actualResultToString = variableTestToString.toString();
//    ASSERT_STR(expectedResultToString , actualResultToString);
//	free(actualResultToString);

	// Test MAX_VALUE_DOUBLE
//    variableTestToString = MAX_VALUE_DOUBLE;
//    expectedResultToString = "1.797693134862316e+308";
//    actualResultToString = variableTestToString.toString();
//    ASSERT_STR(expectedResultToString , actualResultToString);
//	free(actualResultToString);

	// Test MIN_NORMAL_DOUBLE
//    variableTestToString = MIN_NORMAL_DOUBLE;
//    expectedResultToString = "2.2250738585072014E-308";
//    actualResultToString = variableTestToString.toString();
//    ASSERT_STR(expectedResultToString , actualResultToString);
//	free(actualResultToString);

	// Test MIN_VALUE_DOUBLE
}

TEST (JavaLang, DoubleTestSample){
	// Create variable to test
	//variableTestTestSample;
	//expectedResultTestSample;
	//actualResultTestSample;

	// Test POSITIVE_INFINITY

	// Test NEGATIVE_INFINITY

	// Test NaN

	// Test MAX_VALUE

	// Test MIN_NORMAL

	// Test MIN_VALUE
}
