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

    // Test Float::Float()
    Float emptyFloatConstructor;
    emptyFloatConstructor = 13.02;
    ASSERT_DBL_NEAR(13.02, emptyFloatConstructor.floatValue());

    // Test Float::Float(float original)
    Float validFloatConstructor = 13.02;
    ASSERT_DBL_NEAR(13.02, validFloatConstructor.floatValue());

    // Test Float::Float(const Float &floatNumber)
    Float FloatConstructor(validFloatConstructor);
    ASSERT_DBL_NEAR(13.02, validFloatConstructor.floatValue());
}

TEST (JavaLang, FloatArithmeticOperator) {
    // Create variable to test
    Float variableArithmeticOperator1;
    Float variableArithmeticOperator2;
    Float expectedResultOperator;
    Float actualResultOperator;

    // Test Operator +
    variableArithmeticOperator1 = 11.11  ;
    variableArithmeticOperator2 = 22.22;
    expectedResultOperator = 33.33;
    actualResultOperator = variableArithmeticOperator1 + variableArithmeticOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());

    // Test Operator -
    variableArithmeticOperator1 = 33.33 ;
    variableArithmeticOperator2 = 22.22 ;
    expectedResultOperator = 11.11;
    actualResultOperator = variableArithmeticOperator1 - variableArithmeticOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());

    // Test Operator *
    variableArithmeticOperator1 =  2.0;
    variableArithmeticOperator2 =  13.02;
    expectedResultOperator = 26.04;
    actualResultOperator = variableArithmeticOperator1 * variableArithmeticOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());

    // Test Operator /
    variableArithmeticOperator1 = 26.04 ;
    variableArithmeticOperator2 = 2.0 ;
    expectedResultOperator = 13.02;
    actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());

    // Test Operator / . POSITIVE_INFINITY_FLOAT
    variableArithmeticOperator1 = 26.04 ;
    variableArithmeticOperator2 = 0 ;
    expectedResultOperator = POSITIVE_INFINITY_FLOAT;
    actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());

    // Test Operator / . NEGATIVE_INFINITY_FLOAT
    variableArithmeticOperator1 = -26.04 ;
    variableArithmeticOperator2 = 0 ;
    expectedResultOperator = NEGATIVE_INFINITY_FLOAT;
    actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());

    // Test Operator / . NaN_NUMBER_FLOAT
    variableArithmeticOperator1 = 0 ;
    variableArithmeticOperator2 = 0 ;
    expectedResultOperator = NaN_NUMBER_FLOAT;
    actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());
}

//TODO enable after finish method equals , compare
//TEST (JavaLang, FloatRelationalOperator) {
//    // Create variable to test
//    Float variableRelationalOperator1;
//    Float variableRelationalOperator2;
//    boolean expectedResultOperator;
//    boolean actualResultOperator;
//
//    ASSERT_DBL_NEAR(1.123,1.123);
//    // Test Operator ==
//    variableRelationalOperator1 = 13.12;
//    variableRelationalOperator2 = 13.12;
//    expectedResultOperator = TRUE;
//    actualResultOperator = variableRelationalOperator1 == variableRelationalOperator2;
//    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);
//
//    // Test Operator !=
//    variableRelationalOperator1 = 13.02;
//    variableRelationalOperator2 = 99.02;
//    expectedResultOperator = TRUE;
//    actualResultOperator = variableRelationalOperator1 != variableRelationalOperator2;
//    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);
//
//    // Test Operator >
//    variableRelationalOperator1 = 13.02;
//    variableRelationalOperator2 = 11.11;
//    expectedResultOperator = TRUE;
//    actualResultOperator = variableRelationalOperator1 > variableRelationalOperator2;
//    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);
//
//    // Test Operator <
//    variableRelationalOperator1 = 1.11;
//    variableRelationalOperator2 = 13.02;
//    expectedResultOperator = TRUE;
//    actualResultOperator = variableRelationalOperator1 < variableRelationalOperator2;
//    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);
//
//    // Test Operator >=
//    variableRelationalOperator1 = 15.00;
//    variableRelationalOperator2 = 13.02;
//    expectedResultOperator = TRUE;
//    actualResultOperator = variableRelationalOperator1 >= variableRelationalOperator2;
//    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);
//
//    // Test Operator <=
//    variableRelationalOperator1 = 1.11;
//    variableRelationalOperator2 = 13.02;
//    expectedResultOperator = TRUE;
//    actualResultOperator = variableRelationalOperator1 <= variableRelationalOperator2;
//    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);
//}

TEST (JavaLang, FloatLogicalOperator) {
    // Create variable to test
    Float variableLogicalOperator1;
    Float variableLogicalOperator2;
    boolean expectedResultOperator;
    boolean actualResultOperator;

    // Test Operator && . Case 0   0
    variableLogicalOperator1 = 0;
    variableLogicalOperator2 = 0;
    expectedResultOperator = FALSE;
    actualResultOperator = variableLogicalOperator1 && variableLogicalOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator && . Case 0   1
    variableLogicalOperator1 = 0;
    variableLogicalOperator2 = 1;
    expectedResultOperator = FALSE;
    actualResultOperator = variableLogicalOperator1 && variableLogicalOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator && . Case 1   0
    variableLogicalOperator1 = 1;
    variableLogicalOperator2 = 0;
    expectedResultOperator = FALSE;
    actualResultOperator = variableLogicalOperator1 && variableLogicalOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator && . Case 1   1
    variableLogicalOperator1 = 1;
    variableLogicalOperator2 = 1;
    expectedResultOperator = TRUE;
    actualResultOperator = variableLogicalOperator1 && variableLogicalOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator || . Case 0   0
    variableLogicalOperator1 = 0;
    variableLogicalOperator2 = 0;
    expectedResultOperator = FALSE;
    actualResultOperator = variableLogicalOperator1 || variableLogicalOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator || . Case 0   1
    variableLogicalOperator1 = 0;
    variableLogicalOperator2 = 1;
    expectedResultOperator = TRUE;
    actualResultOperator = variableLogicalOperator1 || variableLogicalOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator || . Case 1   0
    variableLogicalOperator1 = 1;
    variableLogicalOperator2 = 0;
    expectedResultOperator = TRUE;
    actualResultOperator = variableLogicalOperator1 || variableLogicalOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator || . Case 1   1
    variableLogicalOperator1 = 1;
    variableLogicalOperator2 = 1;
    expectedResultOperator = TRUE;
    actualResultOperator = variableLogicalOperator1 || variableLogicalOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);
}

TEST (JavaLang, FloatAssignmentOperator) {
    // Create variable to test
    Float variableAssignmentOperator1;
    Float variableAssignmentOperator2;
    Float expectedResultOperator;
    Float actualResultOperator;

    // Test Operator =
    variableAssignmentOperator1 = 0.0;
    variableAssignmentOperator2 = 1.1;
    expectedResultOperator = 1.1;
    actualResultOperator = (variableAssignmentOperator1 = variableAssignmentOperator2);
    ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());

    // Test Operator +=
    variableAssignmentOperator1 = 11.11 ;
    variableAssignmentOperator2 = 22.22 ;
    expectedResultOperator = 33.33;
    actualResultOperator = (variableAssignmentOperator1 += variableAssignmentOperator2);
    ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());

    // Test Operator -=
    variableAssignmentOperator1 =  33.33;
    variableAssignmentOperator2 =  11.11;
    expectedResultOperator = 22.22;
    actualResultOperator = (variableAssignmentOperator1 -= variableAssignmentOperator2);
    ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());

    // Test Operator *=
    variableAssignmentOperator1 = 13.02 ;
    variableAssignmentOperator2 = 2.0 ;
    expectedResultOperator = 26.04;
    actualResultOperator = (variableAssignmentOperator1 *= variableAssignmentOperator2);
    ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());

    // Test Operator /=
    variableAssignmentOperator1 = 26.04 ;
    variableAssignmentOperator2 = 2.0 ;
    expectedResultOperator = 13.02;
    actualResultOperator = (variableAssignmentOperator1 /= variableAssignmentOperator2);
    ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());
}

//TEST (JavaLang, FloatParseFloat) {
//	#ifdef __APPLE__
//		return;
//    #endif
//
//    // Create variable to test Float::parseFloat
//    Float variableFloatConstructor;
//
//    float expectedParseFloatResult ;
//    float notExpectedParseFloatResult;
//    float actualParseFloatResult ;
//
//    // Test Float::parseFloat . Case TRUE
//    variableFloatConstructor = Float::parseFloat("13.02");
//    expectedParseFloatResult = 13.02;
//    actualParseFloatResult = variableFloatConstructor.floatValue();
//    ASSERT_DBL_NEAR(expectedParseFloatResult , actualParseFloatResult);
//
//    // Test Float::parseFloat . Case FALSE
//    variableFloatConstructor = Float::parseFloat("13.02");
//    notExpectedParseFloatResult = 130.2;
//    actualParseFloatResult = variableFloatConstructor.floatValue();
//    ASSERT_DBL_FAR(notExpectedParseFloatResult , actualParseFloatResult);
//}
//
//
//TEST (JavaLang, FloatToString) {
//    // Create variables to test Float::toString.
//    Float variableFloatToString ;
//    string expectedFloatToStringResult;
//    string notExpectedFloatToStringResult;
//    string actualFloatToStringResult;
//
//    // Test value NULL
//    variableFloatToString;
//    expectedFloatToStringResult = (string) "0";
//    actualFloatToStringResult = variableFloatToString.toString();
//    ASSERT_STR(expectedFloatToStringResult, actualFloatToStringResult);
//
//    // Test value 0
//    variableFloatToString = 0.0;
//    expectedFloatToStringResult = (string) "0";
//    actualFloatToStringResult = variableFloatToString.toString();
//    ASSERT_STR(expectedFloatToStringResult, actualFloatToStringResult);
//
//    // Test positive value  .
//    variableFloatToString = 1302.13;
//    expectedFloatToStringResult = (string) "1302.13";
//    actualFloatToStringResult = variableFloatToString.toString();
//    ASSERT_STR(expectedFloatToStringResult, actualFloatToStringResult);
//
//    // Test negative value  .
//    variableFloatToString = -1302.13;
//    expectedFloatToStringResult = (string) "-1302.13";
//    actualFloatToStringResult = variableFloatToString.toString();
//    ASSERT_STR(expectedFloatToStringResult, actualFloatToStringResult);
//
//    // Test Case FALSE
//    variableFloatToString = 1.302;
//    notExpectedFloatToStringResult = (string) "1302.1";
//    actualFloatToStringResult = variableFloatToString.toString();
//    ASSERT_FALSE(notExpectedFloatToStringResult == actualFloatToStringResult);
//}
//
//TEST (JavaLang, FloatCharValue) {
//    // Create variables to test Float::charValue.
//    Float variableFloatCharValue ;
//    char expectedFloatCharValueResult;
//    char actualFloatCharValueResult;
//
//    // Test value NULL .
//    variableFloatCharValue;
//    expectedFloatCharValueResult = '0';
//    actualFloatCharValueResult = variableFloatCharValue.charValue();
//    ASSERT_EQUAL(expectedFloatCharValueResult, actualFloatCharValueResult);
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
//    // Test case FALSE  .
//    variableFloatCharValue = -1302.13;
//    expectedFloatCharValueResult = '-13.023';
//    actualFloatCharValueResult = variableFloatCharValue.charValue();
//    ASSERT_NOT_EQUAL(expectedFloatCharValueResult, actualFloatCharValueResult);
//}
//
//TEST (JavaLang, FloatShortValue) {
//    // Create variables to test Float::shortValue.
//    Float variableFloatShortValue ;
//    short expectedFloatShortValue = 0;
//    short actualFloatShortValue = 0;
//
//    // Test value NULL .
//    variableFloatShortValue = 0;
//    expectedFloatShortValue = 0;
//    actualFloatShortValue = variableFloatShortValue .shortValue();
//    ASSERT_DBL_NEAR(expectedFloatShortValue, actualFloatShortValue);
//
//    // Test value 0 .
//    variableFloatShortValue = 0.0;
//    expectedFloatShortValue = 0;
//    actualFloatShortValue = variableFloatShortValue .shortValue();
//    ASSERT_DBL_NEAR(expectedFloatShortValue, actualFloatShortValue);
//
//    // Test positive value  .
//    variableFloatShortValue = 1302.13;
//    expectedFloatShortValue = 1302;
//    actualFloatShortValue = variableFloatShortValue .shortValue();
//    ASSERT_DBL_NEAR(expectedFloatShortValue, actualFloatShortValue);
//
//    // Test negative value  .
//    variableFloatShortValue = -1302.13;
//    expectedFloatShortValue = -1302;
//    actualFloatShortValue = variableFloatShortValue .shortValue();
//    ASSERT_DBL_NEAR(expectedFloatShortValue, actualFloatShortValue);
//
//    // Test case FALSE  .
//    variableFloatShortValue = -1302.13;
//    expectedFloatShortValue = -130;
//    actualFloatShortValue = variableFloatShortValue .shortValue();
//    ASSERT_DBL_FAR(expectedFloatShortValue, actualFloatShortValue);
//}
//TEST (JavaLang, FloatIntValue) {
//    // Create variables to test Float::intValue.
//    Float variableFloatIntValue;
//    int expectedFloatIntValue = 0;
//    int actualFloatIntValue = 0;
//
//    // Test value NULL .
//    variableFloatIntValue = 0;
//    expectedFloatIntValue = 0;
//    actualFloatIntValue = variableFloatIntValue .intValue();
//    ASSERT_DBL_NEAR(expectedFloatIntValue, actualFloatIntValue);
//
//    // Test value 0 .
//    variableFloatIntValue = 0.0;
//    expectedFloatIntValue = 0;
//    actualFloatIntValue = variableFloatIntValue  .intValue();
//    ASSERT_DBL_NEAR(expectedFloatIntValue, actualFloatIntValue);
//
//    // Test positive value  .
//    variableFloatIntValue = 1302.13;
//    expectedFloatIntValue = 1302;
//    actualFloatIntValue = variableFloatIntValue  .intValue();
//    ASSERT_DBL_NEAR(expectedFloatIntValue, actualFloatIntValue);
//
//    // Test negative value  .
//    variableFloatIntValue = -1302.13;
//    expectedFloatIntValue = -1302;
//    actualFloatIntValue = variableFloatIntValue  .intValue();
//    ASSERT_DBL_NEAR(expectedFloatIntValue, actualFloatIntValue);
//
//    // Test case FALSE .
//    variableFloatIntValue = -1302.13;
//    expectedFloatIntValue = -130;
//    actualFloatIntValue = variableFloatIntValue  .intValue();
//    ASSERT_DBL_FAR(expectedFloatIntValue, actualFloatIntValue);
//
//}
//TEST (JavaLang, FloatLongValue) {
//    // Create variables to test Float::longValue.
//    Float variableFloatLongValue;
//    long expectedFloatLongValue = 0;
//    long actualFloatLongValue = 0;
//
//    // Test value NULL .
//    variableFloatLongValue = 0;
//    expectedFloatLongValue = 0;
//    actualFloatLongValue= variableFloatLongValue .longValue();
//    ASSERT_DBL_NEAR(expectedFloatLongValue, actualFloatLongValue);
//
//    // Test value 0 .
//    variableFloatLongValue = 0.0;
//    expectedFloatLongValue = 0;
//    actualFloatLongValue = variableFloatLongValue .longValue();
//    ASSERT_DBL_NEAR(expectedFloatLongValue, actualFloatLongValue);
//
//    // Test positive value  .
//    variableFloatLongValue = 1302.13;
//    expectedFloatLongValue = 1302;
//    actualFloatLongValue = variableFloatLongValue .longValue();
//    ASSERT_DBL_NEAR(expectedFloatLongValue, actualFloatLongValue);
//
//    // Test negative value  .
//    variableFloatLongValue = -1302.13;
//    expectedFloatLongValue = -1302;
//    actualFloatLongValue = variableFloatLongValue .longValue();
//    ASSERT_DBL_NEAR(expectedFloatLongValue, actualFloatLongValue);
//
//    // Test case FALSE .
//    variableFloatLongValue = -1302.13;
//    expectedFloatLongValue = -130;
//    actualFloatLongValue = variableFloatLongValue .longValue();
//    ASSERT_DBL_FAR(expectedFloatLongValue, actualFloatLongValue);
//}
//TEST (JavaLang, FloatFloatValue) {
//    // Create variables to test Float::floatValue.
//    Float variableFloatFloatValue;
//    float expectedFloatFloatValue = 0;
//    float actualFloatFloatValue = 0;
//
//    // Test value NULL .
//    variableFloatFloatValue = 0;
//    expectedFloatFloatValue = 0;
//    actualFloatFloatValue = variableFloatFloatValue .floatValue();
//    ASSERT_DBL_NEAR(expectedFloatFloatValue, actualFloatFloatValue);
//
//    // Test value 0 .
//    variableFloatFloatValue = 0.0;
//    expectedFloatFloatValue = 0;
//    actualFloatFloatValue = variableFloatFloatValue .floatValue();
//    ASSERT_DBL_NEAR(expectedFloatFloatValue, actualFloatFloatValue);
//
//    // Test positive value  .
//    variableFloatFloatValue = 1302.13;
//    expectedFloatFloatValue = 1302.13;
//    actualFloatFloatValue = variableFloatFloatValue .floatValue();
//    ASSERT_DBL_NEAR(expectedFloatFloatValue, actualFloatFloatValue);
//
//    // Test negative value  .
//    variableFloatFloatValue = -1302.13;
//    expectedFloatFloatValue = -1302.13;
//    actualFloatFloatValue = variableFloatFloatValue .floatValue();
//    ASSERT_DBL_NEAR(expectedFloatFloatValue, actualFloatFloatValue);
//
//    // Test case FALSE .
//    variableFloatFloatValue = -1355.132;
//    expectedFloatFloatValue = -1302.1;
//    actualFloatFloatValue = variableFloatFloatValue .floatValue();
//    ASSERT_DBL_FAR(expectedFloatFloatValue, actualFloatFloatValue);
//}
//TEST (JavaLang, FloatDoubleValue) {
//    // Create variables to test Float::doubleValue.
//    Float variableFloatDoubleValue;
//    double expectedFloatDoubleValue = 0;
//    double actualFloatDoubleValue = 0;
//
//    // Test value NULL .
//    variableFloatDoubleValue = 0;
//    expectedFloatDoubleValue = 0;
//    actualFloatDoubleValue = variableFloatDoubleValue .doubleValue();
//    ASSERT_DBL_NEAR(expectedFloatDoubleValue, actualFloatDoubleValue);
//
//    // Test value 0 .
//    variableFloatDoubleValue = 0.0;
//    expectedFloatDoubleValue = 0;
//    actualFloatDoubleValue = variableFloatDoubleValue .doubleValue();
//    ASSERT_DBL_NEAR(expectedFloatDoubleValue, actualFloatDoubleValue);
//
//    // Test positive value  .
//    variableFloatDoubleValue = 1302.13;
//    expectedFloatDoubleValue = 1302.13;
//    actualFloatDoubleValue = variableFloatDoubleValue .doubleValue();
//    ASSERT_DBL_NEAR(expectedFloatDoubleValue, actualFloatDoubleValue);
//
//    // Test negative value  .
//    variableFloatDoubleValue = -1302.13;
//    expectedFloatDoubleValue = -1302.13;
//    actualFloatDoubleValue = variableFloatDoubleValue .doubleValue();
//    ASSERT_DBL_NEAR(expectedFloatDoubleValue, actualFloatDoubleValue);
//
//    // Test case FALSE  .
//    variableFloatDoubleValue = -1300.132;
//    expectedFloatDoubleValue = -1302.555;
//    actualFloatDoubleValue = variableFloatDoubleValue .doubleValue();
//    ASSERT_DBL_FAR(expectedFloatDoubleValue, actualFloatDoubleValue);
//
//    // TODO Check it
////    // Test case FALSE  .
////    variableFloatDoubleValue = -1302.15;
////    expectedFloatDoubleValue= -1302.1;
////    actualFloatDoubleValue= variableFloatDoubleValue .doubleValue();
////    ASSERT_DBL_FAR(expectedFloatDoubleValue, actualFloatDoubleValue);
//}