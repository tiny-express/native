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

/// A constant holding the positive infinity of type
static double POSITIVE_INFINITY_DOUBLE = 1.0 / 0.0; // inf

/// A constant holding the negative infinity of type
static double NEGATIVE_INFINITY_DOUBLE = -1.0 / 0.0; // -inf

/// A constant holding a Not-a-Number (NaN) value of type
static double NaN_DOUBLE = 0.0 / 0.0; // -nan

/// A constant holding the largest positive finite value of type
static double MAX_VALUE_DOUBLE = 0x1.fffffffffffffP+1023; // 1.797693134862316e+308

/// A constant holding the smallest positive normal value of type
static double MIN_NORMAL_DOUBLE = 0x1.0p-1022; // 2.225073858507201e-308

/// A constant holding the smallest positive nonzero value of type
static double MIN_VALUE_DOUBLE = 0x0.0000000000001P-1022; // 4.940656458412465e-324

TEST (JavaLang, DoubleConstructor) {
    // Given empty value for Double constructor and assign value - Return Double
    Double emptyDoubleConstructor;
    emptyDoubleConstructor = 3;
    ASSERT_EQUAL(3, emptyDoubleConstructor.doubleValue());

    // Given value for Double constructor and assign value - Return integer
    Double validDoubleConstructor = 3;
    ASSERT_EQUAL(3, validDoubleConstructor.doubleValue());
}

TEST (JavaLang, DoubleArithmeticOperator) {
    // Create variable to test
    Double variableArithmeticOperator1;
    Double variableArithmeticOperator2;
    Double expectedResultOperator;
    Double actualResultOperator;

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
}

TEST (JavaLang, DoubleRelationalOperator) {
    // Create variable to test
    Double variableRelationalOperator1;
    Double variableRelationalOperator2;
    boolean expectedResultOperator;
    boolean actualResultOperator;

    // Test Operator ==
    variableRelationalOperator1 = 13.02;
    variableRelationalOperator2 = 13.02;
    expectedResultOperator = TRUE;
    actualResultOperator = variableRelationalOperator1 == variableRelationalOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator !=
    variableRelationalOperator1 = 13.02;
    variableRelationalOperator2 = 99.02;
    expectedResultOperator = TRUE;
    actualResultOperator = variableRelationalOperator1 != variableRelationalOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator >
    variableRelationalOperator1 = 13.02;
    variableRelationalOperator2 = 11.11;
    expectedResultOperator = TRUE;
    actualResultOperator = variableRelationalOperator1 > variableRelationalOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator <
    variableRelationalOperator1 = 1.11;
    variableRelationalOperator2 = 13.02;
    expectedResultOperator = TRUE;
    actualResultOperator = variableRelationalOperator1 < variableRelationalOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator >=
    variableRelationalOperator1 = 15.00;
    variableRelationalOperator2 = 13.02;
    expectedResultOperator = TRUE;
    actualResultOperator = variableRelationalOperator1 >= variableRelationalOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator <=
    variableRelationalOperator1 = 1.11;
    variableRelationalOperator2 = 13.02;
    expectedResultOperator = TRUE;
    actualResultOperator = variableRelationalOperator1 <= variableRelationalOperator2;
    ASSERT_DBL_NEAR(expectedResultOperator, actualResultOperator);
}

TEST (JavaLang, DoubleLogicalOperator) {
    // Create variable to test
    Double variableLogicalOperator1;
    Double variableLogicalOperator2;
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

TEST (JavaLang, DoubleAssignmentOperator) {
    // Create variable to test
    Double variableAssignmentOperator1;
    Double variableAssignmentOperator2;
    Double expectedResultOperator;
    Double actualResultOperator;

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

    // Test NEGATIVE_INFINITY_DOUBLE
    variableTestToString = NEGATIVE_INFINITY_DOUBLE;
    expectedResultToString = "-inf";
    actualResultToString = variableTestToString.toString();
    ASSERT_STR(expectedResultToString , actualResultToString);

//    // Test NaN_DOUBLE
//    variableTestToString = NaN_DOUBLE;
//    expectedResultToString = "-nan"; // "nan" in MacOS
//    actualResultToString = variableTestToString.toString();
//    ASSERT_STR(expectedResultToString , actualResultToString);
//	free(actualResultToString);

    // Test MAX_VALUE_DOUBLE
    variableTestToString = MAX_VALUE_DOUBLE;
    expectedResultToString = "1.797693134862316e+308";
    actualResultToString = variableTestToString.toString();
    ASSERT_STR(expectedResultToString , actualResultToString);

    // Test MIN_NORMAL_DOUBLE
    variableTestToString = MIN_NORMAL_DOUBLE;
    expectedResultToString = "2.225073858507201e-308";
    actualResultToString = variableTestToString.toString();
    ASSERT_STR(expectedResultToString , actualResultToString);

    // Test MIN_VALUE_DOUBLE
    variableTestToString = MIN_VALUE_DOUBLE;
    expectedResultToString = "4.940656458412465e-324";
    actualResultToString = variableTestToString.toString();
    ASSERT_STR(expectedResultToString , actualResultToString);
}

TEST (JavaLang, DoubleCharValue){
    // Create variable to test
    Double variableTestCharValue;
    char expectedResultCharValue;
    char actualResultCharValue;

    // Test POSITIVE_INFINITY_DOUBLE
    variableTestCharValue = POSITIVE_INFINITY_DOUBLE;
    expectedResultCharValue = 'i';
    actualResultCharValue = variableTestCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);

    // Test NEGATIVE_INFINITY_DOUBLE
    variableTestCharValue = NEGATIVE_INFINITY_DOUBLE;
    expectedResultCharValue = '-';
    actualResultCharValue = variableTestCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);

//    // Test NaN_DOUBLE
//    variableTestCharValue = NaN_DOUBLE;
//    expectedResultCharValue = 45;  // 110 in MacOS
//    actualResultCharValue = variableTestCharValue.charValue();
//    ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);

    // Test MAX_VALUE_DOUBLE
    variableTestCharValue = MAX_VALUE_DOUBLE;
    expectedResultCharValue = '1';
    actualResultCharValue = variableTestCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);

    // Test MIN_NORMAL_DOUBLE
    variableTestCharValue = MIN_NORMAL_DOUBLE;
    expectedResultCharValue = '2';
    actualResultCharValue = variableTestCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);

    // Test MIN_VALUE_DOUBLE
    variableTestCharValue = MIN_VALUE_DOUBLE;
    expectedResultCharValue = '4';
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

TEST (JavaLang, DoubleStringValue){
    // Create variable to test
    Double variableTestStringValue;
    string expectedResultStringValue;
    string actualResultStringValue;

    // Test POSITIVE_INFINITY_DOUBLE
    variableTestStringValue = POSITIVE_INFINITY_DOUBLE;
    expectedResultStringValue = "inf";
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue , actualResultStringValue);

    // Test NEGATIVE_INFINITY_DOUBLE
    variableTestStringValue = NEGATIVE_INFINITY_DOUBLE;
    expectedResultStringValue = "-inf";
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue , actualResultStringValue);

//    // Test NaN_DOUBLE
//    variableTestStringValue = NaN_DOUBLE;
//    expectedResultStringValue = "-nan"; // "nan" in MacOS
//    actualResultStringValue = variableTestStringValue.stringValue();
//    ASSERT_STR(expectedResultStringValue , actualResultStringValue);
//    free(actualResultStringValue);

    // Test MAX_VALUE_DOUBLE
    variableTestStringValue = MAX_VALUE_DOUBLE;
    expectedResultStringValue = "1.797693134862316e+308";
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue , actualResultStringValue);

    // Test MIN_NORMAL_DOUBLE
    variableTestStringValue = MIN_NORMAL_DOUBLE;
    expectedResultStringValue = "2.225073858507201e-308";
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue , actualResultStringValue);

    // Test MIN_VALUE_DOUBLE
    variableTestStringValue = MIN_VALUE_DOUBLE;
    expectedResultStringValue = "4.940656458412465e-324";
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue , actualResultStringValue);
}

TEST (JavaLang, DoubleShortValue){
    // Create variable to test
    Double variableTestShortValue;
    short expectedResultShortValue;
    short actualResultShortValue;

    // Test POSITIVE_INFINITY_DOUBLE
    variableTestShortValue = POSITIVE_INFINITY_DOUBLE;
    expectedResultShortValue = 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);

    // Test NEGATIVE_INFINITY_DOUBLE
    variableTestShortValue = NEGATIVE_INFINITY_DOUBLE;
    expectedResultShortValue = 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);

    // Test NaN_DOUBLE
    variableTestShortValue = NaN_DOUBLE;
    expectedResultShortValue = 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);

    // Test MAX_VALUE_DOUBLE
    variableTestShortValue = MAX_VALUE_DOUBLE;
    expectedResultShortValue = 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);

    // Test MIN_NORMAL_DOUBLE
    variableTestShortValue = MIN_NORMAL_DOUBLE;
    expectedResultShortValue = 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);

    // Test MIN_VALUE_DOUBLE
    variableTestShortValue = MIN_VALUE_DOUBLE;
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

TEST (JavaLang, DoubleIntValue){
    // Create variable to test
    Double variableTestIntValue;
    int expectedResultIntValue;
    int actualResultIntValue;

    // Test POSITIVE_INFINITY_DOUBLE
    variableTestIntValue = POSITIVE_INFINITY_DOUBLE;
    expectedResultIntValue = -2147483648;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);

    // Test NEGATIVE_INFINITY_DOUBLE
    variableTestIntValue = NEGATIVE_INFINITY_DOUBLE;
    expectedResultIntValue = -2147483648;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);

    // Test NaN_DOUBLE
    variableTestIntValue = NaN_DOUBLE;
    expectedResultIntValue = -2147483648;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);

    // Test MAX_VALUE_DOUBLE
    variableTestIntValue = MAX_VALUE_DOUBLE;
    expectedResultIntValue = -2147483648;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);

    // Test MIN_NORMAL_DOUBLE
    variableTestIntValue = MIN_NORMAL_DOUBLE;
    expectedResultIntValue = 0;
    actualResultIntValue = variableTestIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);

    // Test MIN_VALUE_DOUBLE
    variableTestIntValue = MIN_VALUE_DOUBLE;
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

TEST (JavaLang, DoubleLongValue){
    // Create variable to test
    Double variableTestLongValue;
    long expectedResultLongValue;
    long actualResultLongValue;

    // Test POSITIVE_INFINITY_DOUBLE
    variableTestLongValue = POSITIVE_INFINITY_DOUBLE;
    expectedResultLongValue = -9223372036854775808;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);

    // Test NEGATIVE_INFINITY_DOUBLE
    variableTestLongValue = NEGATIVE_INFINITY_DOUBLE;
    expectedResultLongValue = -9223372036854775808;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);

    // Test NaN_DOUBLE
    variableTestLongValue = NaN_DOUBLE;
    expectedResultLongValue = -9223372036854775808;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);

    // Test MAX_VALUE_DOUBLE
    variableTestLongValue = MAX_VALUE_DOUBLE;
    expectedResultLongValue = -9223372036854775808;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);

    // Test MIN_NORMAL_DOUBLE
    variableTestLongValue = MIN_NORMAL_DOUBLE;
    expectedResultLongValue = 0;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);

    // Test MIN_VALUE_DOUBLE
    variableTestLongValue = MIN_VALUE_DOUBLE;
    expectedResultLongValue= 0;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);

    // Test valid case
    variableTestLongValue = 5.9;
    expectedResultLongValue= 5;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);

    // Test valid case
    variableTestLongValue = 5.4;
    expectedResultLongValue= 5;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);

    // Test invalid case
    variableTestLongValue = 6;
    expectedResultLongValue= 5;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_NOT_EQUAL(expectedResultLongValue , actualResultLongValue);
}

TEST (JavaLang, DoubleFloatValue){
    // Create variable to test
    Double variableTestFloatValue;
    float expectedResultFloatValue;
    float actualResultFloatValue;

    // Test POSITIVE_INFINITY_DOUBLE
    variableTestFloatValue = POSITIVE_INFINITY_DOUBLE;
    expectedResultFloatValue = 1.0 / 0.0;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_DBL_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test NEGATIVE_INFINITY_DOUBLE
    variableTestFloatValue = NEGATIVE_INFINITY_DOUBLE;
    expectedResultFloatValue = -1.0/0.0;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_DBL_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test NaN_DOUBLE
    variableTestFloatValue = NaN_DOUBLE;
    expectedResultFloatValue = 0.0/0.0;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_DBL_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test MAX_VALUE_DOUBLE
    variableTestFloatValue = MAX_VALUE_DOUBLE;
    expectedResultFloatValue = 1.0/0.0;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_DBL_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test MIN_NORMAL_DOUBLE
    variableTestFloatValue = MIN_NORMAL_DOUBLE;
    expectedResultFloatValue = 0;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_DBL_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test MIN_VALUE_DOUBLE
    variableTestFloatValue = MIN_VALUE_DOUBLE;
    expectedResultFloatValue = 0;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_DBL_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test valid case
    variableTestFloatValue = 13.02;
    expectedResultFloatValue = 13.02;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_DBL_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test valid case
    variableTestFloatValue = 1.302;
    expectedResultFloatValue = 1.302;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_DBL_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test invalid case
    variableTestFloatValue = 130.2;
    expectedResultFloatValue = 130.0;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_DBL_FAR(expectedResultFloatValue , actualResultFloatValue);
}

TEST (JavaLang, DoubleDoubleValue){
    // Create variable to test
    Double variableTestDoubleValue;
    double expectedResultDoubleValue;
    double actualResultDoubleValue;

    // Test POSITIVE_INFINITY_DOUBLE
    variableTestDoubleValue = POSITIVE_INFINITY_DOUBLE;
    expectedResultDoubleValue = POSITIVE_INFINITY_DOUBLE;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    ASSERT_DBL_NEAR(expectedResultDoubleValue , actualResultDoubleValue);

    // Test NEGATIVE_INFINITY_DOUBLE
    variableTestDoubleValue = NEGATIVE_INFINITY_DOUBLE;
    expectedResultDoubleValue = NEGATIVE_INFINITY_DOUBLE;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    ASSERT_DBL_NEAR(expectedResultDoubleValue , actualResultDoubleValue);

    // Test NaN_DOUBLE
    variableTestDoubleValue = NaN_DOUBLE;
    expectedResultDoubleValue = NaN_DOUBLE;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    ASSERT_DBL_NEAR(expectedResultDoubleValue , actualResultDoubleValue);

    // Test MAX_VALUE_DOUBLE
    variableTestDoubleValue = MAX_VALUE_DOUBLE;
    expectedResultDoubleValue = MAX_VALUE_DOUBLE;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    ASSERT_DBL_NEAR(expectedResultDoubleValue , actualResultDoubleValue);

    // Test MIN_NORMAL_DOUBLE
    variableTestDoubleValue = MIN_NORMAL_DOUBLE;
    expectedResultDoubleValue = MIN_NORMAL_DOUBLE;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    ASSERT_DBL_NEAR(expectedResultDoubleValue , actualResultDoubleValue);

    // Test MIN_VALUE_DOUBLE
    variableTestDoubleValue = MIN_VALUE_DOUBLE;
    expectedResultDoubleValue = MIN_VALUE_DOUBLE;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    ASSERT_DBL_NEAR(expectedResultDoubleValue , actualResultDoubleValue);

    // Test valid case
    variableTestDoubleValue = 13.02;
    expectedResultDoubleValue = 13.02;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    ASSERT_DBL_NEAR(expectedResultDoubleValue , actualResultDoubleValue);

    // Test valid case
    variableTestDoubleValue = 1.302;
    expectedResultDoubleValue = 1.302;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    ASSERT_DBL_NEAR(expectedResultDoubleValue , actualResultDoubleValue);

    // Test invalid case
    variableTestDoubleValue = 130.2;
    expectedResultDoubleValue = 130.0;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    ASSERT_DBL_FAR(expectedResultDoubleValue , actualResultDoubleValue);
}

TEST (JavaLang, DoubleByteValue){
    // Create variable to test
    Double variableTestByteValue;
    byte expectedResultByteValue;
    byte actualResultByteValue;

    // Test POSITIVE_INFINITY_DOUBLE
    variableTestByteValue = POSITIVE_INFINITY_DOUBLE;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue , actualResultByteValue);

    // Test NEGATIVE_INFINITY_DOUBLE
    variableTestByteValue = NEGATIVE_INFINITY_DOUBLE;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue , actualResultByteValue);

//    // Test NaN_DOUBLE
//    variableTestByteValue = NaN_DOUBLE;
//    expectedResultByteValue = 45;  // 110 in MacOS
//    actualResultByteValue = variableTestByteValue.byteValue();
//    ASSERT_EQUAL(expectedResultByteValue , actualResultByteValue);

    // Test MAX_VALUE_DOUBLE
    variableTestByteValue = MAX_VALUE_DOUBLE;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue , actualResultByteValue);

    // Test MIN_NORMAL_DOUBLE
    variableTestByteValue = MIN_NORMAL_DOUBLE;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue , actualResultByteValue);

    // Test MIN_VALUE_DOUBLE
    variableTestByteValue = MIN_VALUE_DOUBLE;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue , actualResultByteValue);

    // Test valid case
    variableTestByteValue = 13.02;
    expectedResultByteValue = 13;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue , actualResultByteValue);

    // Test valid case
    variableTestByteValue = 20.31;
    expectedResultByteValue = 20;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue , actualResultByteValue);

    // Test invalid case
    variableTestByteValue = 13.02;
    expectedResultByteValue = 5;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_NOT_EQUAL(expectedResultByteValue , actualResultByteValue);
}