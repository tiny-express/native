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
    // Create comparisonFloat contains value of type float.
    // We use this variable to test FloatConstructor
	Float variableFloatConstructor;

    // Create variable expectedFloatConstructorResult represent the target we want when use Float::floatValue
    // In case TRUE
    float expectedFloatConstructorResult ;

    // Create variable notExpectedFloatConstructorResult represent the target we want when use Float::floatValue
    // In case FALSE
    float notExpectedFloatConstructorResult;

    // Create variable expectedFloatConstructorResult represent the real result when use Float::floatValue
    float realFloatConstructorResult ;

    // Test Float::floatValue.  Case TRUE
    // Assign value to variableFloatConstructor.
    // Than make a comparison with expectedFloatConstructorResult.
    variableFloatConstructor = 13.02;
    expectedFloatConstructorResult = 13.02;
    realFloatConstructorResult = variableFloatConstructor.floatValue();
	ASSERT_TRUE(expectedFloatConstructorResult == realFloatConstructorResult);

    // Test Float::floatValue.  Case FALSE
    // Assign value to variableFloatConstructor.
    // Than make a comparison with expectedFloatConstructorResult.
    variableFloatConstructor = 13.02;
    notExpectedFloatConstructorResult = 1302.000;
    realFloatConstructorResult = variableFloatConstructor.floatValue();
    ASSERT_FALSE(notExpectedFloatConstructorResult == realFloatConstructorResult);

    // Test Float::floatValue.  Immediately . Case TRUE
    // Create a variableFloatConstructorImmediate and assign value to it immediately.
    // Than make a comparison with expectedFloatConstructorResult.
    Float variableFloatConstructorImmediate = 130.2;
    expectedFloatConstructorResult = 130.2;
    realFloatConstructorResult = variableFloatConstructorImmediate.floatValue();
    ASSERT_TRUE(expectedFloatConstructorResult == realFloatConstructorResult);

    // Test Float::floatValue.  Immediately . Case FALSE
    // Create a variableFloatConstructorImmediate and assign value to it immediately.
    // Than make a comparison with expectedFloatConstructorResult.
    variableFloatConstructorImmediate = 130.2;
    notExpectedFloatConstructorResult = 1.302;
    realFloatConstructorResult = variableFloatConstructorImmediate.floatValue();
    ASSERT_FALSE(notExpectedFloatConstructorResult == realFloatConstructorResult);

    // Test Float::parseFLoat to convert from string to float. Case TRUE
    // Use Float::parseFloat to assign float value to variableFloatConstructor
    // Than make a comparison with expectedFloatConstructor
	variableFloatConstructor = Float::parseFloat("13.02");
    expectedFloatConstructorResult = 13.02;
    realFloatConstructorResult = variableFloatConstructor.floatValue();
	ASSERT_TRUE(expectedFloatConstructorResult == realFloatConstructorResult);

    // Test Float::parseFLoat to convert from string to float. Case FALSE
    // Use Float::parseFloat to assign float value to variableFloatConstructor
    // Than make a comparison with notExpectedFloatConstructor
    variableFloatConstructor = Float::parseFloat("13.02");
    notExpectedFloatConstructorResult = 130.2;
    realFloatConstructorResult = variableFloatConstructor.floatValue();
    ASSERT_FALSE(notExpectedFloatConstructorResult == realFloatConstructorResult);
}

TEST (JavaLang, FloatComparison) {
    // Create comparisonFloat contains value of type float.
    // We use this variable to test FloatComparison
    Float comparisonFloat = 13.02;

    // Create a variable to test case TRUE of FloatComparison
    // We will use that variable to make a comparison between it and comparisonFloat
    Float expectedFloatComparisonResult;

    // Create a variable to test case FALSE of FloatComparison
    // We will use that variable to make a comparison between it and comparisonFloat
    Float notExpectedFloatComparisonResult;

    // Test operator == . Case TRUE
    // Make a comparison between the comparisonFloat and the expectedFloatComparisonResult
    expectedFloatComparisonResult = 13.02;
    ASSERT_TRUE(expectedFloatComparisonResult  == comparisonFloat);

    // Test operator == . Case FALSE
    // Make a comparison between the comparisonFloat and the notExpectedFloatComparisonResult
    notExpectedFloatComparisonResult = 130.02;
    ASSERT_FALSE(notExpectedFloatComparisonResult == comparisonFloat);

    // Test operator != . Case TRUE
    // Make a comparison between the comparisonFloat and the expectedFloatComparisonResult
    expectedFloatComparisonResult = 111.333;
    ASSERT_TRUE(expectedFloatComparisonResult != comparisonFloat);

    // Test operator != . Case FALSE
    // Make a comparison between the comparisonFloat and the notExpectedFloatComparisonResult
    notExpectedFloatComparisonResult = 13.02;
    ASSERT_FALSE(notExpectedFloatComparisonResult != comparisonFloat);

    // Test operator < . Case TRUE
    // Make a comparison between the comparisonFloat and the expectedFloatComparisonResult
    expectedFloatComparisonResult = 1.302;
    ASSERT_TRUE(expectedFloatComparisonResult < comparisonFloat);

    // Test operator < . Case FALSE
    // Make a comparison between the comparisonFloat and the notExpectedFloatComparisonResult
    notExpectedFloatComparisonResult = 100.302;
    ASSERT_FALSE(notExpectedFloatComparisonResult < comparisonFloat);

    // Test operator <= . Case TRUE
    // Make a comparison between the comparisonFloat and the expectedFloatComparisonResult
    expectedFloatComparisonResult = 13.00;
    ASSERT_TRUE(expectedFloatComparisonResult <= comparisonFloat);

    // Test operator <= . Case FALSE
    // Make a comparison between the comparisonFloat and the notExpectedFloatComparisonResult
    notExpectedFloatComparisonResult = 130.00;
    ASSERT_FALSE(notExpectedFloatComparisonResult <= comparisonFloat);

    // Test operator > . Case TRUE
    // Make a comparison between the comparisonFloat and the expectedFloatComparisonResult
    expectedFloatComparisonResult = 100.1302;
    ASSERT_TRUE(expectedFloatComparisonResult > comparisonFloat);

    // Test operator > . Case FALSE
    // Make a comparison between the comparisonFloat and the notExpectedFloatComparisonResult
    notExpectedFloatComparisonResult = 1.1302;
    ASSERT_FALSE(notExpectedFloatComparisonResult > comparisonFloat);

    // Test operator >= . Case TRUE
    // Make a comparison between the comparisonFloat and the expectedFloatComparisonResult
    expectedFloatComparisonResult = 130.02;
    ASSERT_TRUE(expectedFloatComparisonResult >= comparisonFloat);

    // Test operator >= . Case FALSE
    // Make a comparison between the comparisonFloat and the notExpectedFloatComparisonResult
    notExpectedFloatComparisonResult = 1.1302;
    ASSERT_FALSE(notExpectedFloatComparisonResult >= comparisonFloat);
}

TEST (JavaLang, FloatOperator) {
	// Create variableFloatOperatorA, variableFloatOperatorB and assign value of type float to them.
    // We use this variable to test FloatOperator.
	Float variableFloatOperatorA = 33.00;
    Float variableFloatOperatorB = 11.00;

    // Create realFloatOperatorResult contains real result of the function we want to test
    Float realFloatOperatorResult ;

    // Create expectedFloatOperatorResult contains the expected result . To test case TRUE of FloatOperator
    // We will use that variable to make a comparison with realFloatOperatorResult
    Float expectedFloatOperatorResult;

    // Create notExpectedFloatOperatorResult contains the not expected result . To test case FALSE of FloatOperator
    // We will use that variable to make a comparison with realFloatOperatorResult
    Float notExpectedFloatOperatorResult;

	// Test Float::operator     +   . Case TRUE
	realFloatOperatorResult = variableFloatOperatorA + variableFloatOperatorB;
    expectedFloatOperatorResult = 44.00;
	ASSERT_TRUE(expectedFloatOperatorResult == realFloatOperatorResult);

    // Test Float::operator     +   . Case FALSE
    realFloatOperatorResult = variableFloatOperatorA + variableFloatOperatorB;
    notExpectedFloatOperatorResult = 555.666 ;
    ASSERT_FALSE(notExpectedFloatOperatorResult == realFloatOperatorResult);

    // Test Float::operator     -   . Case TRUE
    realFloatOperatorResult = variableFloatOperatorA - variableFloatOperatorB;
    expectedFloatOperatorResult = 22.00 ;
    ASSERT_TRUE(expectedFloatOperatorResult == realFloatOperatorResult);

    // Test Float::operator     -   . Case FALSE
    realFloatOperatorResult = variableFloatOperatorA - variableFloatOperatorB;
    notExpectedFloatOperatorResult = 123.321 ;
    ASSERT_FALSE(notExpectedFloatOperatorResult == realFloatOperatorResult);

    // Test Float::operator     *   . Case TRUE
    realFloatOperatorResult = variableFloatOperatorA * variableFloatOperatorB;
    expectedFloatOperatorResult = 363.00 ;
    ASSERT_TRUE(expectedFloatOperatorResult == realFloatOperatorResult);

    // Test Float::operator     *   . Case FALSE
    realFloatOperatorResult = variableFloatOperatorA * variableFloatOperatorB;
    notExpectedFloatOperatorResult = 5678.123 ;
    ASSERT_FALSE(notExpectedFloatOperatorResult == realFloatOperatorResult);

    // Test Float::operator     /   . Case TRUE
    realFloatOperatorResult = variableFloatOperatorA / variableFloatOperatorB;
    expectedFloatOperatorResult = 3.00 ;
    ASSERT_TRUE(expectedFloatOperatorResult == realFloatOperatorResult);

    // Test Float::operator     /   . Case FALSE
    realFloatOperatorResult = variableFloatOperatorA / variableFloatOperatorB;
    notExpectedFloatOperatorResult = 123.321 ;
    ASSERT_FALSE(notExpectedFloatOperatorResult == realFloatOperatorResult);
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
	// Input different values of type float to compare to the result of Float::toString
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