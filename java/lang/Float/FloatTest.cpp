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

    // Test Float::parseFloat . Case TRUE
    variableFloatConstructor = Float::parseFloat("13.02");
    expectedParseFloatResult = 13.02;
    actualParseFloatResult = variableFloatConstructor.floatValue();
    ASSERT_DBL_NEAR(expectedParseFloatResult , actualParseFloatResult);

    // Test Float::parseFloat . Case FALSE
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

    // Test value NULL
    variableFloatToString;
    expectedFloatToStringResult = (string) "0";
    actualFloatToStringResult = variableFloatToString.toString();
    ASSERT_STR(expectedFloatToStringResult, actualFloatToStringResult);

    // Test value 0
    variableFloatToString = 0.0;
    expectedFloatToStringResult = (string) "0";
    actualFloatToStringResult = variableFloatToString.toString();
    ASSERT_STR(expectedFloatToStringResult, actualFloatToStringResult);

    // Test positive value  .
    variableFloatToString = 1302.13;
    expectedFloatToStringResult = (string) "1302.13";
    actualFloatToStringResult = variableFloatToString.toString();
    ASSERT_STR(expectedFloatToStringResult, actualFloatToStringResult);

    // Test negative value  .
    variableFloatToString = -1302.13;
    expectedFloatToStringResult = (string) "-1302.13";
    actualFloatToStringResult = variableFloatToString.toString();
    ASSERT_STR(expectedFloatToStringResult, actualFloatToStringResult);
    
    // Test Case FALSE
    variableFloatToString = 1.302;
    notExpectedFloatToStringResult = (string) "1302.1";
    actualFloatToStringResult = variableFloatToString.toString();
    ASSERT_FALSE(notExpectedFloatToStringResult == actualFloatToStringResult);
}

TEST (JavaLang, FloatCharValue) {
    // Create variables to test Float::charValue.
    Float variableFloatCharValue ;
    char expectedFloatCharValueResult;
    char actualFloatCharValueResult;

    // Test value NULL .
    variableFloatCharValue;
    expectedFloatCharValueResult = '0';
    actualFloatCharValueResult = variableFloatCharValue.charValue();
    ASSERT_EQUAL(expectedFloatCharValueResult, actualFloatCharValueResult);

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

    // Test case FALSE  . // FIXME: @thoangminh please check this test case
//    variableFloatCharValue = -1302.13;
//    expectedFloatCharValueResult = '-13.023';
//    actualFloatCharValueResult = variableFloatCharValue.charValue();
//    ASSERT_NOT_EQUAL(expectedFloatCharValueResult, actualFloatCharValueResult);
}

TEST (JavaLang, FloatShortValue) {
    // Create variables to test Float::shortValue.
    Float variableFloatShortValue ;
    short expectedFloatShortValue = 0;
    short actualFloatShortValue = 0;

    // Test value NULL .
    variableFloatShortValue = 0;
    expectedFloatShortValue = 0;
    actualFloatShortValue = variableFloatShortValue .shortValue();
    ASSERT_DBL_NEAR(expectedFloatShortValue, actualFloatShortValue);

    // Test value 0 .
    variableFloatShortValue = 0.0;
    expectedFloatShortValue = 0;
    actualFloatShortValue = variableFloatShortValue .shortValue();
    ASSERT_DBL_NEAR(expectedFloatShortValue, actualFloatShortValue);

    // Test positive value  .
    variableFloatShortValue = 1302.13;
    expectedFloatShortValue = 1302;
    actualFloatShortValue = variableFloatShortValue .shortValue();
    ASSERT_DBL_NEAR(expectedFloatShortValue, actualFloatShortValue);

    // Test negative value  .
    variableFloatShortValue = -1302.13;
    expectedFloatShortValue = -1302;
    actualFloatShortValue = variableFloatShortValue .shortValue();
    ASSERT_DBL_NEAR(expectedFloatShortValue, actualFloatShortValue);

    // Test case FALSE  .
    variableFloatShortValue = -1302.13;
    expectedFloatShortValue = -130;
    actualFloatShortValue = variableFloatShortValue .shortValue();
    ASSERT_DBL_FAR(expectedFloatShortValue, actualFloatShortValue);
}
TEST (JavaLang, FloatIntValue) {
    // Create variables to test Float::intValue.
    Float variableFloatIntValue;
    int expectedFloatIntValue = 0;
    int actualFloatIntValue = 0;

    // Test value NULL .
    variableFloatIntValue = 0;
    expectedFloatIntValue = 0;
    actualFloatIntValue = variableFloatIntValue .intValue();
    ASSERT_DBL_NEAR(expectedFloatIntValue, actualFloatIntValue);

    // Test value 0 .
    variableFloatIntValue = 0.0;
    expectedFloatIntValue = 0;
    actualFloatIntValue = variableFloatIntValue  .intValue();
    ASSERT_DBL_NEAR(expectedFloatIntValue, actualFloatIntValue);

    // Test positive value  .
    variableFloatIntValue = 1302.13;
    expectedFloatIntValue = 1302;
    actualFloatIntValue = variableFloatIntValue  .intValue();
    ASSERT_DBL_NEAR(expectedFloatIntValue, actualFloatIntValue);

    // Test negative value  .
    variableFloatIntValue = -1302.13;
    expectedFloatIntValue = -1302;
    actualFloatIntValue = variableFloatIntValue  .intValue();
    ASSERT_DBL_NEAR(expectedFloatIntValue, actualFloatIntValue);

    // Test case FALSE .
    variableFloatIntValue = -1302.13;
    expectedFloatIntValue = -130;
    actualFloatIntValue = variableFloatIntValue  .intValue();
    ASSERT_DBL_FAR(expectedFloatIntValue, actualFloatIntValue);

}
TEST (JavaLang, FloatLongValue) {
    // Create variables to test Float::longValue.
    Float variableFloatLongValue;
    long expectedFloatLongValue = 0;
    long actualFloatLongValue = 0;

    // Test value NULL .
    variableFloatLongValue = 0;
    expectedFloatLongValue = 0;
    actualFloatLongValue= variableFloatLongValue .longValue();
    ASSERT_DBL_NEAR(expectedFloatLongValue, actualFloatLongValue);

    // Test value 0 .
    variableFloatLongValue = 0.0;
    expectedFloatLongValue = 0;
    actualFloatLongValue = variableFloatLongValue .longValue();
    ASSERT_DBL_NEAR(expectedFloatLongValue, actualFloatLongValue);

    // Test positive value  .
    variableFloatLongValue = 1302.13;
    expectedFloatLongValue = 1302;
    actualFloatLongValue = variableFloatLongValue .longValue();
    ASSERT_DBL_NEAR(expectedFloatLongValue, actualFloatLongValue);

    // Test negative value  .
    variableFloatLongValue = -1302.13;
    expectedFloatLongValue = -1302;
    actualFloatLongValue = variableFloatLongValue .longValue();
    ASSERT_DBL_NEAR(expectedFloatLongValue, actualFloatLongValue);

    // Test case FALSE .
    variableFloatLongValue = -1302.13;
    expectedFloatLongValue = -130;
    actualFloatLongValue = variableFloatLongValue .longValue();
    ASSERT_DBL_FAR(expectedFloatLongValue, actualFloatLongValue);
}
TEST (JavaLang, FloatFloatValue) {
    // Create variables to test Float::floatValue.
    Float variableFloatFloatValue;
    float expectedFloatFloatValue = 0;
    float actualFloatFloatValue = 0;

    // Test value NULL .
    variableFloatFloatValue = 0;
    expectedFloatFloatValue = 0;
    actualFloatFloatValue = variableFloatFloatValue .floatValue();
    ASSERT_DBL_NEAR(expectedFloatFloatValue, actualFloatFloatValue);

    // Test value 0 .
    variableFloatFloatValue = 0.0;
    expectedFloatFloatValue = 0;
    actualFloatFloatValue = variableFloatFloatValue .floatValue();
    ASSERT_DBL_NEAR(expectedFloatFloatValue, actualFloatFloatValue);

    // Test positive value  .
    variableFloatFloatValue = 1302.13;
    expectedFloatFloatValue = 1302.13;
    actualFloatFloatValue = variableFloatFloatValue .floatValue();
    ASSERT_DBL_NEAR(expectedFloatFloatValue, actualFloatFloatValue);

    // Test negative value  .
    variableFloatFloatValue = -1302.13;
    expectedFloatFloatValue = -1302.13;
    actualFloatFloatValue = variableFloatFloatValue .floatValue();
    ASSERT_DBL_NEAR(expectedFloatFloatValue, actualFloatFloatValue);

    // Test case FALSE .
    variableFloatFloatValue = -1355.132;
    expectedFloatFloatValue = -1302.1;
    actualFloatFloatValue = variableFloatFloatValue .floatValue();
    ASSERT_DBL_FAR(expectedFloatFloatValue, actualFloatFloatValue);
}
TEST (JavaLang, FloatDoubleValue) {
    // Create variables to test Float::doubleValue.
    Float variableFloatDoubleValue;
    double expectedFloatDoubleValue = 0;
    double actualFloatDoubleValue = 0;

    // Test value NULL .
    variableFloatDoubleValue = 0;
    expectedFloatDoubleValue = 0;
    actualFloatDoubleValue = variableFloatDoubleValue .doubleValue();
    ASSERT_DBL_NEAR(expectedFloatDoubleValue, actualFloatDoubleValue);

    // Test value 0 .
    variableFloatDoubleValue = 0.0;
    expectedFloatDoubleValue = 0;
    actualFloatDoubleValue = variableFloatDoubleValue .doubleValue();
    ASSERT_DBL_NEAR(expectedFloatDoubleValue, actualFloatDoubleValue);

    // Test positive value  .
    variableFloatDoubleValue = 1302.13;
    expectedFloatDoubleValue = 1302.13;
    actualFloatDoubleValue = variableFloatDoubleValue .doubleValue();
    ASSERT_DBL_NEAR(expectedFloatDoubleValue, actualFloatDoubleValue);

    // Test negative value  .
    variableFloatDoubleValue = -1302.13;
    expectedFloatDoubleValue = -1302.13;
    actualFloatDoubleValue = variableFloatDoubleValue .doubleValue();
    ASSERT_DBL_NEAR(expectedFloatDoubleValue, actualFloatDoubleValue);

    // Test case FALSE  .
    variableFloatDoubleValue = -1300.132;
    expectedFloatDoubleValue = -1302.555;
    actualFloatDoubleValue = variableFloatDoubleValue .doubleValue();
    ASSERT_DBL_FAR(expectedFloatDoubleValue, actualFloatDoubleValue);

    // TODO Check it
//    // Test case FALSE  .
//    variableFloatDoubleValue = -1302.15;
//    expectedFloatDoubleValue= -1302.1;
//    actualFloatDoubleValue= variableFloatDoubleValue .doubleValue();
//    ASSERT_DBL_FAR(expectedFloatDoubleValue, actualFloatDoubleValue);
}