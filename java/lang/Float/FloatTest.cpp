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
    ASSERT_DBL_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());

    // Test Operator -
    variableArithmeticOperator1 = 33.33 ;
    variableArithmeticOperator2 = 22.22 ;
    expectedResultOperator = 11.11;
    actualResultOperator = variableArithmeticOperator1 - variableArithmeticOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());

    // Test Operator *
    variableArithmeticOperator1 =  2.0;
    variableArithmeticOperator2 =  13.02;
    expectedResultOperator = 26.04;
    actualResultOperator = variableArithmeticOperator1 * variableArithmeticOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());

    // Test Operator /
    variableArithmeticOperator1 = 26.04 ;
    variableArithmeticOperator2 = 2.0 ;
    expectedResultOperator = 13.02;
    actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());

    // Test Operator / . POSITIVE_INFINITY_FLOAT
    variableArithmeticOperator1 = 26.04 ;
    variableArithmeticOperator2 = 0 ;
    expectedResultOperator = POSITIVE_INFINITY_FLOAT;
    actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());

    // Test Operator / . NEGATIVE_INFINITY_FLOAT
    variableArithmeticOperator1 = -26.04 ;
    variableArithmeticOperator2 = 0 ;
    expectedResultOperator = NEGATIVE_INFINITY_FLOAT;
    actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());

    // Test Operator / . NaN_NUMBER_FLOAT
    variableArithmeticOperator1 = 0 ;
    variableArithmeticOperator2 = 0 ;
    expectedResultOperator = NaN_NUMBER_FLOAT;
    actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
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
    ASSERT_DBL_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());

    // Test Operator +=
    variableAssignmentOperator1 = 11.11 ;
    variableAssignmentOperator2 = 22.22 ;
    expectedResultOperator = 33.33;
    actualResultOperator = (variableAssignmentOperator1 += variableAssignmentOperator2);
    ASSERT_DBL_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());

    // Test Operator -=
    variableAssignmentOperator1 =  33.33;
    variableAssignmentOperator2 =  11.11;
    expectedResultOperator = 22.22;
    actualResultOperator = (variableAssignmentOperator1 -= variableAssignmentOperator2);
    ASSERT_DBL_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());

    // Test Operator *=
    variableAssignmentOperator1 = 13.02 ;
    variableAssignmentOperator2 = 2.0 ;
    expectedResultOperator = 26.04;
    actualResultOperator = (variableAssignmentOperator1 *= variableAssignmentOperator2);
    ASSERT_DBL_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());

    // Test Operator /=
    variableAssignmentOperator1 = 26.04 ;
    variableAssignmentOperator2 = 2.0 ;
    expectedResultOperator = 13.02;
    actualResultOperator = (variableAssignmentOperator1 /= variableAssignmentOperator2);
    ASSERT_DBL_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
}

TEST (JavaLang, FloatCharValue){
    // Create variable to test
    Float variableTestCharValue;
    char expectedResultCharValue;
    char actualResultCharValue;

    // Test POSITIVE_INFINITY_FLOAT
    variableTestCharValue = POSITIVE_INFINITY_FLOAT;
    expectedResultCharValue = 'i';
    actualResultCharValue = variableTestCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);

    // Test NEGATIVE_INFINITY_FLOAT
    variableTestCharValue = NEGATIVE_INFINITY_FLOAT;
    expectedResultCharValue = '-';
    actualResultCharValue = variableTestCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);

//    // Test NaN_NUMBER_FLOAT
//    variableTestCharValue = NaN_NUMBER_FLOAT;
//    expectedResultCharValue = 45;  // 110 in MacOS
//    actualResultCharValue = variableTestCharValue.charValue();
//    ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);

    // Test MAX_VALUE_FLOAT
    variableTestCharValue = MAX_VALUE_FLOAT;
    expectedResultCharValue = '3';
    actualResultCharValue = variableTestCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);

    // Test MIN_NORMAL_FLOAT
    variableTestCharValue = MIN_NORMAL_FLOAT;
    expectedResultCharValue = '1';
    actualResultCharValue = variableTestCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);

    // Test MIN_VALUE_FLOAT
    variableTestCharValue = MIN_VALUE_FLOAT;
    expectedResultCharValue = '1';
    actualResultCharValue = variableTestCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);

    // Test valid case
    variableTestCharValue = 13.02;
    expectedResultCharValue = '1';
    actualResultCharValue = variableTestCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);

    // Test valid case
    variableTestCharValue = 20.31;
    expectedResultCharValue = '2';
    actualResultCharValue = variableTestCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);

    // Test invalid case
    variableTestCharValue = 13.02;
    expectedResultCharValue = '5';
    actualResultCharValue = variableTestCharValue.charValue();
    ASSERT_NOT_EQUAL(expectedResultCharValue , actualResultCharValue);
}
//TODO enable after finish toString()
//TEST (JavaLang, FloatStringValue){
//    // Create variable to test
//    Float variableTestStringValue;
//    string expectedResultStringValue;
//    string actualResultStringValue;
//
//    // Test POSITIVE_INFINITY_FLOAT
//    variableTestStringValue = POSITIVE_INFINITY_FLOAT;
//    expectedResultStringValue = (string) "inf";
//    actualResultStringValue = variableTestStringValue.stringValue();
//    ASSERT_STR(expectedResultStringValue , actualResultStringValue);
//
//    // Test NEGATIVE_INFINITY_FLOAT
//    variableTestStringValue = NEGATIVE_INFINITY_FLOAT;
//    expectedResultStringValue = (string) "-inf";
//    actualResultStringValue = variableTestStringValue.stringValue();
//    ASSERT_STR(expectedResultStringValue , actualResultStringValue);
//
////    // Test NaN_NUMBER_FLOAT
////    variableTestStringValue = NaN_NUMBER_FLOAT;
////    expectedResultStringValue = "-nan"; // "nan" in MacOS
////    actualResultStringValue = variableTestStringValue.stringValue();
////    ASSERT_STR(expectedResultStringValue , actualResultStringValue);
////    free(actualResultStringValue);
//
//    // Test MAX_VALUE_FLOAT
//    variableTestStringValue = MAX_VALUE_FLOAT;
//    expectedResultStringValue = (string) "1.797693134862316e+308";
//    actualResultStringValue = variableTestStringValue.stringValue();
//    ASSERT_STR(expectedResultStringValue , actualResultStringValue);
//
//    // Test MIN_NORMAL_FLOAT
//    variableTestStringValue = MIN_NORMAL_FLOAT;
//    expectedResultStringValue = (string) "4.940656458412465e-324";
//    actualResultStringValue = variableTestStringValue.stringValue();
//    ASSERT_STR(expectedResultStringValue , actualResultStringValue);
//
//    // Test MIN_VALUE_FLOAT
//    variableTestStringValue = MIN_VALUE_FLOAT;
//    expectedResultStringValue = (string) "2.225073858507201e-308";
//    actualResultStringValue = variableTestStringValue.stringValue();
//    ASSERT_STR(expectedResultStringValue , actualResultStringValue);
//}

TEST (JavaLang, FloatShortValue){
    // Create variable to test
    Float variableTestShortValue;
    short expectedResultShortValue;
    short actualResultShortValue;

    // Test POSITIVE_INFINITY_FLOAT
    variableTestShortValue = POSITIVE_INFINITY_FLOAT;
    expectedResultShortValue = 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);

    // Test NEGATIVE_INFINITY_FLOAT
    variableTestShortValue = NEGATIVE_INFINITY_FLOAT;
    expectedResultShortValue = 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);

    // Test NaN_NUMBER_FLOAT
    variableTestShortValue = NaN_NUMBER_FLOAT;
    expectedResultShortValue = 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);

    // Test MAX_VALUE_FLOAT
    variableTestShortValue = MAX_VALUE_FLOAT;
    expectedResultShortValue = 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);

    // Test MIN_NORMAL_FLOAT
    variableTestShortValue = MIN_NORMAL_FLOAT;
    expectedResultShortValue = 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);

    // Test MIN_VALUE_FLOAT
    variableTestShortValue = MIN_VALUE_FLOAT;
    expectedResultShortValue= 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);

    // Test valid case
    variableTestShortValue = 5.9;
    expectedResultShortValue= 5;
    actualResultShortValue = variableTestShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);

    // Test valid case
    variableTestShortValue = 5.4;
    expectedResultShortValue= 5;
    actualResultShortValue = variableTestShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);

    // Test invalid case
    variableTestShortValue = 6;
    expectedResultShortValue= 5;
    actualResultShortValue = variableTestShortValue.shortValue();
    ASSERT_NOT_EQUAL(expectedResultShortValue , actualResultShortValue);
}

TEST (JavaLang, FloatIntValue){
    // Create variable to test
    Float variableTestIntValue;
    int expectedResultIntValue;
    int actualResultIntValue;

    // Test POSITIVE_INFINITY_DOUBLE
    variableTestIntValue = POSITIVE_INFINITY_FLOAT;
    expectedResultIntValue = -2147483648;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);

    // Test NEGATIVE_INFINITY_FLOAT
    variableTestIntValue = NEGATIVE_INFINITY_FLOAT;
    expectedResultIntValue = -2147483648;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);

    // Test NaN_NUMBER_FLOAT
    variableTestIntValue = NaN_NUMBER_FLOAT;
    expectedResultIntValue = -2147483648;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);

    // Test MAX_VALUE_FLOAT
    variableTestIntValue = MAX_VALUE_FLOAT;
    expectedResultIntValue = -2147483648;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);

    // Test MIN_NORMAL_FLOAT
    variableTestIntValue = MIN_NORMAL_FLOAT;
    expectedResultIntValue = 0;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);

    // Test MIN_VALUE_FLOAT
    variableTestIntValue = MIN_VALUE_FLOAT;
    expectedResultIntValue= 0;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);

    // Test valid case
    variableTestIntValue = 5.9;
    expectedResultIntValue= 5;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);

    // Test valid case
    variableTestIntValue = 5.4;
    expectedResultIntValue= 5;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);

    // Test invalid case
    variableTestIntValue = 6;
    expectedResultIntValue= 5;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_NOT_EQUAL(expectedResultIntValue , actualResultIntValue);
}