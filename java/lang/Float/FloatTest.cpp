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
    // Create comparisonFloat contains value of type float.
    // We use this variable to test FloatConstructor
	Float variableFloatConstructor;

    // Create variable expectedFloatConstructorResult represent the target we want when use Float::floatValue
    // In case TRUE
    float expectedFloatConstructorResult ;

    // Create variable notExpectedFloatConstructorResult represent the target we want when use Float::floatValue
    // In case FALSE
    float notExpectedFloatConstructorResult;

    // Create variable expectedFloatConstructorResult represent the actual result when use Float::floatValue
    float actualFloatConstructorResult ;

    // Test Float::floatValue.  Case TRUE
    // Assign value to variableFloatConstructor.
    // Than make a comparison with expectedFloatConstructorResult.
    variableFloatConstructor = 13.02;
    expectedFloatConstructorResult = 13.02;
    actualFloatConstructorResult = variableFloatConstructor.floatValue();
	ASSERT_DBL_NEAR(expectedFloatConstructorResult , actualFloatConstructorResult);

    // Test Float::floatValue.  Case FALSE
    // Assign value to variableFloatConstructor.
    // Than make a comparison with expectedFloatConstructorResult.
    variableFloatConstructor = 13.02;
    notExpectedFloatConstructorResult = 1302.000;
    actualFloatConstructorResult = variableFloatConstructor.floatValue();
    ASSERT_DBL_FAR(notExpectedFloatConstructorResult , actualFloatConstructorResult);

    // Test Float::floatValue.  Immediately . Case TRUE
    // Create a variableFloatConstructorImmediate and assign value to it immediately.
    // Than make a comparison with expectedFloatConstructorResult.
    Float variableFloatConstructorImmediate = 130.2;
    expectedFloatConstructorResult = 130.2;
    actualFloatConstructorResult = variableFloatConstructorImmediate.floatValue();
    ASSERT_DBL_NEAR(expectedFloatConstructorResult , actualFloatConstructorResult);

    // Test Float::floatValue.  Immediately . Case FALSE
    // Create a variableFloatConstructorImmediate and assign value to it immediately.
    // Than make a comparison with expectedFloatConstructorResult.
    variableFloatConstructorImmediate = 130.2;
    notExpectedFloatConstructorResult = 1.302;
    actualFloatConstructorResult = variableFloatConstructorImmediate.floatValue();
    ASSERT_DBL_FAR(notExpectedFloatConstructorResult , actualFloatConstructorResult);

    // Test Float::parseFLoat to convert from string to float. Case TRUE
    // Use Float::parseFloat to assign float value to variableFloatConstructor
    // Than make a comparison with expectedFloatConstructor
	variableFloatConstructor = Float::parseFloat("13.02");
    expectedFloatConstructorResult = 13.02;
    actualFloatConstructorResult = variableFloatConstructor.floatValue();
	ASSERT_DBL_NEAR(expectedFloatConstructorResult , actualFloatConstructorResult);

    // Test Float::parseFLoat to convert from string to float. Case FALSE
    // Use Float::parseFloat to assign float value to variableFloatConstructor
    // Than make a comparison with notExpectedFloatConstructor
    variableFloatConstructor = Float::parseFloat("13.02");
    notExpectedFloatConstructorResult = 130.2;
    actualFloatConstructorResult = variableFloatConstructor.floatValue();
    ASSERT_DBL_FAR(notExpectedFloatConstructorResult , actualFloatConstructorResult);
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

    // Create actualFloatOperatorResult contains actual result of the function we want to test
    Float actualFloatOperatorResult ;

    // Create expectedFloatOperatorResult contains the expected result . To test case TRUE of FloatOperator
    // We will use that variable to make a comparison with actualFloatOperatorResult
    Float expectedFloatOperatorResult;

    // Create notExpectedFloatOperatorResult contains the not expected result . To test case FALSE of FloatOperator
    // We will use that variable to make a comparison with actualFloatOperatorResult
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
    // Make a comparison with expectedFloatConstructor
    variableFloatConstructor = Float::parseFloat("13.02");
    expectedParseFloatResult = 13.02;
    actualParseFloatResult = variableFloatConstructor.floatValue();
    ASSERT_DBL_NEAR(expectedParseFloatResult , actualParseFloatResult);

    // Test Float::parseFLoat . Case FALSE
    // Make a comparison with expectedFloatConstructor
    variableFloatConstructor = Float::parseFloat("13.02");
    notExpectedParseFloatResult = 130.2;
    actualParseFloatResult = variableFloatConstructor.floatValue();
    ASSERT_DBL_FAR(notExpectedParseFloatResult , actualParseFloatResult);
}


TEST (JavaLang, FloatToString) {
    // Create variables to test Float::toString.
    Float variableFloatToString ;
    string expectedFloatToStringResult;
    string actualFloatToStringResult;

    // Test value 0 .
    variableFloatToString = 0.0;
    expectedFloatToStringResult = "0";
    actualFloatToStringResult = variableFloatToString.toString();
    ASSERT_STR(expectedFloatToStringResult, actualFloatToStringResult);
    free(actualFloatToStringResult);

    // Test positive value  .
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

//TEST (JavaLang, FloatCharValue) {
//    // Create variables to test Float::charValue.
//    Float variableFloatCharValue ;
//    char expectedFloatCharValueResult;
//    char actualFloatCharValueResult;
//
//    // Test value 0 .
//    variableFloatCharValue = 0.0;
//    expectedFloatCharValueResult = '0';
//    actualFloatCharValueResult = variableFloatCharValue.charValue();
//    ASSERT_EQUAL(expectedFloatCharValueResult, actualFloatCharValueResult);
//
//    // Test positive value  .
//    variableFloatCharValue = 1302.13;
//    expectedFloatCharValueResult = '1';
//    actualFloatCharValueResult = variableFloatCharValue.charValue();
//    ASSERT_EQUAL(expectedFloatCharValueResult, actualFloatCharValueResult);
//
//    // Test negative value  .
//    variableFloatCharValue = -1302.13;
//    expectedFloatCharValueResult = '-';
//    actualFloatCharValueResult = variableFloatCharValue.charValue();
//    ASSERT_EQUAL(expectedFloatCharValueResult, actualFloatCharValueResult);
//
//}

//TEST (JavaLang, FloatStringValue) {
//    // Input different values of type int to compare to the result of Float::stringValue
//    Float zeroFloat = 0;
//    Float oneFloat = 1;
//    Float positiveFloat = 10;
//    Float maxFloat = 2147483647;
//    Float minFloat = -2147483647;
//    // Make a comparison between expected result and the actual result
//    char *expect = "0";
//    char *result = zeroFloat.stringValue();
//    ASSERT_STR(expect, result);
//    free(result);
//    // Make a comparison between expected result and the actual result
//    expect = "1";
//    char *result1 = oneFloat.stringValue();
//    ASSERT_STR(expect, result1);
//    free(result1);
//    // Make a comparison between expected result and the actual result
//    expect = "10";
//    char *result2 = positiveFloat.stringValue();
//    ASSERT_STR(expect, result2);
//    free(result2);
//    // Make a comparison between expected result and the actual result
//    expect = "2147483647";
//    char *result3 = maxFloat.stringValue();
//    ASSERT_STR(expect, result3);
//    free(result3);
//    // Make a comparison between expected result and the actual result
//    expect = "-2147483647";
//    char *result4 = minFloat.stringValue();
//    ASSERT_STR(expect, result4);
//    free(result4);
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


