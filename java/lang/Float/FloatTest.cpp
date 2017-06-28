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

#define string char*

TEST (JavaLang, FloatConstructor) {
    // Create comparisonFloat contains value of type float. We use this variable to test FloatConstructor
	Float variableFloatConstructor;

    // Create expectedFloatConstructorResult to test Float::floatValueIn case TRUE
    float expectedFloatConstructorResult ;

    // Create expectedFloatConstructorResult to test Float::floatValueIn case FALSE
    float notExpectedFloatConstructorResult;

    // Create variable expectedFloatConstructorResult represent the actual result when use Float::floatValue
    float actualFloatConstructorResult ;

    // Test Float::floatValue.  Case TRUE.
    variableFloatConstructor = 13.02;
    expectedFloatConstructorResult = 13.02;
    actualFloatConstructorResult = variableFloatConstructor.floatValue();
	ASSERT_DBL_NEAR(expectedFloatConstructorResult , actualFloatConstructorResult);

    // Test Float::floatValue.  Case FALSE
    variableFloatConstructor = 13.02;
    notExpectedFloatConstructorResult = 1302.000;
    actualFloatConstructorResult = variableFloatConstructor.floatValue();
    ASSERT_DBL_FAR(notExpectedFloatConstructorResult , actualFloatConstructorResult);

    // Test Float::floatValue.  Immediately . Case TRUE
    Float variableFloatConstructorImmediate = 130.2;
    expectedFloatConstructorResult = 130.2;
    actualFloatConstructorResult = variableFloatConstructorImmediate.floatValue();
    ASSERT_DBL_NEAR(expectedFloatConstructorResult , actualFloatConstructorResult);

    // Test Float::floatValue.  Immediately . Case FALSE
    variableFloatConstructorImmediate = 130.2;
    notExpectedFloatConstructorResult = 1.302;
    actualFloatConstructorResult = variableFloatConstructorImmediate.floatValue();
    ASSERT_DBL_FAR(notExpectedFloatConstructorResult , actualFloatConstructorResult);

    // Test Float::parseFLoat to convert from string to float. Case TRUE
	variableFloatConstructor = Float::parseFloat("13.02");
    expectedFloatConstructorResult = 13.02;
    actualFloatConstructorResult = variableFloatConstructor.floatValue();
	ASSERT_DBL_NEAR(expectedFloatConstructorResult , actualFloatConstructorResult);

    // Test Float::parseFLoat to convert from string to float. Case FALSE
    variableFloatConstructor = Float::parseFloat("13.02");
    notExpectedFloatConstructorResult = 130.2;
    actualFloatConstructorResult = variableFloatConstructor.floatValue();
    ASSERT_DBL_FAR(notExpectedFloatConstructorResult , actualFloatConstructorResult);
}


TEST (JavaLang, FloatComparison) {
    // Create comparisonFloat to test FloatComparison
    Float comparisonFloat = 13.02;

    // Create a variable to test case TRUE of FloatComparison
    Float expectedFloatComparisonResult;

    // Create a variable to test case FALSE of FloatComparison
    Float notExpectedFloatComparisonResult;

    // Test operator == . Case TRUE
    expectedFloatComparisonResult = 13.02;
    ASSERT_TRUE(expectedFloatComparisonResult  == comparisonFloat);

    // Test operator == . Case FALSE
    notExpectedFloatComparisonResult = 130.02;
    ASSERT_FALSE(notExpectedFloatComparisonResult == comparisonFloat);

    // Test operator != . Case TRUE
    expectedFloatComparisonResult = 111.333;
    ASSERT_TRUE(expectedFloatComparisonResult != comparisonFloat);

    // Test operator != . Case FALSE
    notExpectedFloatComparisonResult = 13.02;
    ASSERT_FALSE(notExpectedFloatComparisonResult != comparisonFloat);

    // Test operator < . Case TRUE
    expectedFloatComparisonResult = 1.302;
    ASSERT_TRUE(expectedFloatComparisonResult < comparisonFloat);

    // Test operator < . Case FALSE
    notExpectedFloatComparisonResult = 100.302;
    ASSERT_FALSE(notExpectedFloatComparisonResult < comparisonFloat);

    // Test operator <= . Case TRUE
    expectedFloatComparisonResult = 13.00;
    ASSERT_TRUE(expectedFloatComparisonResult <= comparisonFloat);

    // Test operator <= . Case FALSE
    notExpectedFloatComparisonResult = 130.00;
    ASSERT_FALSE(notExpectedFloatComparisonResult <= comparisonFloat);

    // Test operator > . Case TRUE
    expectedFloatComparisonResult = 100.1302;
    ASSERT_TRUE(expectedFloatComparisonResult > comparisonFloat);

    // Test operator > . Case FALSE
    notExpectedFloatComparisonResult = 1.1302;
    ASSERT_FALSE(notExpectedFloatComparisonResult > comparisonFloat);

    // Test operator >= . Case TRUE
    expectedFloatComparisonResult = 130.02;
    ASSERT_TRUE(expectedFloatComparisonResult >= comparisonFloat);

    // Test operator >= . Case FALSE
    notExpectedFloatComparisonResult = 1.1302;
    ASSERT_FALSE(notExpectedFloatComparisonResult >= comparisonFloat);
}

TEST (JavaLang, FloatOperator) {
	// Create variableFloatOperatorA, variableFloatOperatorB to test FloatOperator.
	Float variableFloatOperatorA = 33.00;
    Float variableFloatOperatorB = 11.00;

    // Create actualFloatOperatorResult contains actual result of the function we want to test
    Float actualFloatOperatorResult ;

    // Create expectedFloatOperatorResult to test case TRUE of FloatOperator
    Float expectedFloatOperatorResult;

    // Create notExpectedFloatOperatorResult to test case FALSE of FloatOperator
    Float notExpectedFloatOperatorResult;

	// Test Float::operator     +   . Case TRUE
	actualFloatOperatorResult = variableFloatOperatorA + variableFloatOperatorB;
    expectedFloatOperatorResult = 44.00;
	ASSERT_DBL_NEAR(expectedFloatOperatorResult.floatValue() , actualFloatOperatorResult.floatValue());

    // Test Float::operator     +   . Case FALSE
    actualFloatOperatorResult = variableFloatOperatorA + variableFloatOperatorB;
    notExpectedFloatOperatorResult = 555.666 ;
    ASSERT_DBL_FAR(notExpectedFloatOperatorResult.floatValue() , actualFloatOperatorResult.floatValue());

    // Test Float::operator     -   . Case TRUE
    actualFloatOperatorResult = variableFloatOperatorA - variableFloatOperatorB;
    expectedFloatOperatorResult = 22.00 ;
    ASSERT_DBL_NEAR(expectedFloatOperatorResult.floatValue() , actualFloatOperatorResult.floatValue());

    // Test Float::operator     -   . Case FALSE
    actualFloatOperatorResult = variableFloatOperatorA - variableFloatOperatorB;
    notExpectedFloatOperatorResult = 123.321 ;
    ASSERT_DBL_FAR(notExpectedFloatOperatorResult.floatValue() , actualFloatOperatorResult.floatValue());

    // Test Float::operator     *   . Case TRUE
    actualFloatOperatorResult = variableFloatOperatorA * variableFloatOperatorB;
    expectedFloatOperatorResult = 363.00 ;
    ASSERT_DBL_NEAR(expectedFloatOperatorResult.floatValue() , actualFloatOperatorResult.floatValue());

    // Test Float::operator     *   . Case FALSE
    actualFloatOperatorResult = variableFloatOperatorA * variableFloatOperatorB;
    notExpectedFloatOperatorResult = 5678.123 ;
    ASSERT_DBL_FAR(notExpectedFloatOperatorResult.floatValue() , actualFloatOperatorResult.floatValue());

    // Test Float::operator     /   . Case TRUE
    actualFloatOperatorResult = variableFloatOperatorA / variableFloatOperatorB;
    expectedFloatOperatorResult = 3.00 ;
    ASSERT_DBL_NEAR(expectedFloatOperatorResult.floatValue() , actualFloatOperatorResult.floatValue());

    // Test Float::operator     /   . Case FALSE
    actualFloatOperatorResult = variableFloatOperatorA / variableFloatOperatorB;
    notExpectedFloatOperatorResult = 123.321 ;
    ASSERT_DBL_FAR(notExpectedFloatOperatorResult.floatValue() , actualFloatOperatorResult.floatValue());
}

TEST (JavaLang, FloatParseFloat) {
	#ifdef __APPLE__
		return;
    #endif

    // Create variable to test Float::parseFloat
    Float variableFloatConstructor;

    float expectedParseFloatResult ;
    float notExpectedParseFloatResult;
    float actualParseFloatResult ;

    // Test Float::parseFLoat . Case TRUE
    variableFloatConstructor = Float::parseFloat("13.02");
    expectedParseFloatResult = 13.02;
    actualParseFloatResult = variableFloatConstructor.floatValue();
    ASSERT_DBL_NEAR(expectedParseFloatResult , actualParseFloatResult);

    // Test Float::parseFLoat . Case FALSE
    variableFloatConstructor = Float::parseFloat("13.02");
    notExpectedParseFloatResult = 130.2;
    actualParseFloatResult = variableFloatConstructor.floatValue();
    ASSERT_DBL_FAR(notExpectedParseFloatResult , actualParseFloatResult);
}


TEST (JavaLang, FloatToString) {
    // Create variables to test Float::toString.
    Float variableFloatToString ;
    string expectedFloatToStringResult;
    string notExpectedFloatToStringResult;
    string actualFloatToStringResult;

    // Test value 0 . Case TRUE
    variableFloatToString = 0.0;
    expectedFloatToStringResult = "0";
    actualFloatToStringResult = variableFloatToString.toString();
    ASSERT_STR(expectedFloatToStringResult, actualFloatToStringResult);
    free(actualFloatToStringResult);

//    // Test value 0 . Case FALSE
//    variableFloatToString = 0.0;
//    notExpectedFloatToStringResult = "1302.1";
//    actualFloatToStringResult = variableFloatToString.toString();
//    ASSERT_STR(notExpectedFloatToStringResult, actualFloatToStringResult);
//    free(actualFloatToStringResult);

    // Test positive value  . Case TRUE
    variableFloatToString = 1302.13;
    expectedFloatToStringResult = "1302.13";
    actualFloatToStringResult = variableFloatToString.toString();
    ASSERT_STR(expectedFloatToStringResult, actualFloatToStringResult);
    free(actualFloatToStringResult);

    // Test negative value  .
    variableFloatToString = -1302.13;
    expectedFloatToStringResult = "-1302.13";
    actualFloatToStringResult = variableFloatToString.toString();
    ASSERT_STR(expectedFloatToStringResult, actualFloatToStringResult);
    free(actualFloatToStringResult);

}

TEST (JavaLang, FloatCharValue) {
    // Create variables to test Float::charValue.
    Float variableFloatCharValue ;
    char expectedFloatCharValueResult;
    char actualFloatCharValueResult;

    // Test value 0 .
    variableFloatCharValue = 0.0;
    expectedFloatCharValueResult = '0';
    actualFloatCharValueResult = variableFloatCharValue.charValue();
    ASSERT_EQUAL(expectedFloatCharValueResult, actualFloatCharValueResult);

    // Test positive value  .
    variableFloatCharValue = 1302.13;
    expectedFloatCharValueResult = '1';
    actualFloatCharValueResult = variableFloatCharValue.charValue();
    ASSERT_EQUAL(expectedFloatCharValueResult, actualFloatCharValueResult);

    // Test negative value  .
    variableFloatCharValue = -1302.13;
    expectedFloatCharValueResult = '-';
    actualFloatCharValueResult = variableFloatCharValue.charValue();
    ASSERT_EQUAL(expectedFloatCharValueResult, actualFloatCharValueResult);

}

// TODO waiting for java.lang.string
//TEST (JavaLang, FloatStringValue) {
//    // Create variables to test Float::StringValue.
//    Float variableFloatStringValue ;
//    string expectedFloatStringValueResult;
//    string actualFloatStringValueResult;
//
//    // Test value 0 .
//    variableFloatStringValue = 0.0;
//    expectedFloatStringValueResult = "0";
//    actualFloatStringValueResult = variableFloatStringValue.stringValue();
//    ASSERT_STR(expectedFloatStringValueResult, actualFloatStringValueResult);
//    free(actualFloatStringValueResult);
//
//    // Test positive value  .
//    variableFloatStringValue = 1302.13;
//    expectedFloatStringValueResult = "1302.13";
//    actualFloatStringValueResult = variableFloatStringValue.stringValue();
//    ASSERT_STR(expectedFloatStringValueResult, actualFloatStringValueResult);
//    free(actualFloatStringValueResult);
//
//    // Test negative value  .
//    variableFloatStringValue = -1302.13;
//    expectedFloatStringValueResult = "-1302.13";
//    actualFloatStringValueResult = variableFloatStringValue.stringValue();
//    ASSERT_STR(expectedFloatStringValueResult, actualFloatStringValueResult);
//    free(actualFloatStringValueResult);
//}

//TEST (JavaLang, FloatShortValue) {
//    // Input different values of type int to compare to the result of Float::shortValue
//    Float positiveFloat = 1302;
//    Float negativeFloat = -1302;
//    // Make a comparison between expected result and the actual result
//    int expectedResult = 1302;
//    int actualResult = positiveFloat.shortValue();
//    ASSERT_EQUAL(expectedResult, actualResult);
//    // Make a comparison between expected result and the actual result
//    expectedResult = -1302;
//    actualResult = negativeFloat.shortValue();
//    ASSERT_EQUAL(expectedResult, actualResult);
//}
//TEST (JavaLang, FloatIntValue) {
//    // Input different values of type int to compare to the actualResult of Float::intValue
//    Float zeroFloat = 0;
//    Float oneFloat = 1;
//    Float positiveFloat = 10;
//
//    // Make a comparison between expected actualResult and the actual result
//    int expectedResult= 0;
//    int actualResult = zeroFloat.intValue();
//    ASSERT_EQUAL(expectedResult, actualResult);
//    // Make a comparison between expected actualResult and the actual result
//    expectedResult= 1;
//    actualResult = oneFloat.intValue();
//    ASSERT_EQUAL(expectedResult, actualResult);
//    // Make a comparison between expected actualResult and the actual result
//    expectedResult= 10;
//    actualResult = positiveFloat.intValue();
//    ASSERT_EQUAL(expectedResult, actualResult);
//
//}
//TEST (JavaLang, FloatLongValue) {
//    // Input different values of type int to compare to the actualResult of Float::longValue
//    Float positiveFloat = 1302.00;
//    int expectedResult = 1302.00;
//    int actualResult = positiveFloat.longValue();
//    ASSERT_EQUAL(expectedResult, actualResult);
//    positiveFloat = -1302.00;
//    expectedResult = -1302.00;
//    actualResult = positiveFloat.longValue();
//    ASSERT_EQUAL(expectedResult, actualResult);
//}
//TEST (JavaLang, FloatFloatValue) {
//    // Input different values of type int to compare to the actualResult of Float::floatValue
//    Float positiveFloat = 12345;
//    float expectedResult = 12345.00;
//    float actualResult = positiveFloat.floatValue();
//    ASSERT_TRUE(expectedResult == actualResult);
//    Float negativeFloat = -12345;
//    expectedResult = -12345.00;
//    actualResult = negativeFloat.floatValue();
//    ASSERT_TRUE(expectedResult == actualResult);
//}
//TEST (JavaLang, FloatDoubleValue) {
//    // Input different values of type int to compare to the actualResult of Float::doubleValue
//    Float positiveFloat = 123456.00;
//    double expectedResult = 123456.00;
//    double actualResult = positiveFloat.doubleValue();
//    ASSERT_TRUE(expectedResult == actualResult);
//    Float negativeFloat = -123456.00;
//    expectedResult = -123456.00;
//    actualResult = negativeFloat.doubleValue();
//    ASSERT_TRUE(expectedResult == actualResult);
//}


