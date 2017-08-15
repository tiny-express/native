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

TEST(JavaLang, FloatConstructor) {
	// Test Float::Float()
	Float emptyFloatConstructor;
	emptyFloatConstructor = 13.02;
	ASSERT_FLOAT_NEAR(13.02, emptyFloatConstructor.floatValue());
	
	// Test Float::Float(float original)
	Float floatConstructor = 13.02;
	ASSERT_FLOAT_NEAR(13.02, floatConstructor.floatValue());
	
	floatConstructor = 13.02;
	ASSERT_FLOAT_FAR(13.33, floatConstructor.floatValue());
	
	floatConstructor = -0.0f;
	ASSERT_FLOAT_NEAR(-0.0f, floatConstructor.floatValue());
	
	// Test Float::Float(const Float &floatNumber)
	floatConstructor = 13.02;
	Float FloatConstructor(floatConstructor);
	ASSERT_FLOAT_NEAR(13.02, floatConstructor.floatValue());
}

TEST(JavaLang, FloatArithmeticOperator) {
	// Create variable to test
	Float variableArithmeticOperator1;
	Float variableArithmeticOperator2;
	Float expectedResultOperator;
	Float actualResultOperator;
	
	// Test Operator +
	variableArithmeticOperator1 = 1.1;
	variableArithmeticOperator2 = 2.2;
	expectedResultOperator = 3.3;
	actualResultOperator = variableArithmeticOperator1 + variableArithmeticOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator -
	variableArithmeticOperator1 = 3.3;
	variableArithmeticOperator2 = 2.2;
	expectedResultOperator = 1.1;
	actualResultOperator = variableArithmeticOperator1 - variableArithmeticOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator *
	variableArithmeticOperator1 =  2.0;
	variableArithmeticOperator2 =  13.02;
	expectedResultOperator = 26.04;
	actualResultOperator = variableArithmeticOperator1 * variableArithmeticOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator /
	variableArithmeticOperator1 = 26.04;
	variableArithmeticOperator2 = 2.0;
	expectedResultOperator = 13.02;
	actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator / . POSITIVE_INFINITY
	variableArithmeticOperator1 = 26.04;
	variableArithmeticOperator2 = 0;
	expectedResultOperator = POSITIVE_INFINITY;
	actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator / . NEGATIVE_INFINITY
	variableArithmeticOperator1 = -26.04;
	variableArithmeticOperator2 = 0;
	expectedResultOperator = NEGATIVE_INFINITY;
	actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator / . NaN_NUMBER
	variableArithmeticOperator1 = 0;
	variableArithmeticOperator2 = 0;
	expectedResultOperator = NaN_NUMBER;
	actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
}

// TODO(thoangminh): enable after finish method equals , compare
//TEST (JavaLang, FloatRelationalOperator) {
//    // Create variable to test
//    Float variableRelationalOperator1;
//    Float variableRelationalOperator2;
//    boolean expectedResultOperator;
//    boolean actualResultOperator;
//
//    ASSERT_FLOAT_NEAR(1.123,1.123);
//    // Test Operator ==
//    variableRelationalOperator1 = 13.12;
//    variableRelationalOperator2 = 13.12;
//    expectedResultOperator = TRUE;
//    actualResultOperator = variableRelationalOperator1 == variableRelationalOperator2;
//    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);
//
//    // Test Operator !=
//    variableRelationalOperator1 = 13.02;
//    variableRelationalOperator2 = 99.02;
//    expectedResultOperator = TRUE;
//    actualResultOperator = variableRelationalOperator1 != variableRelationalOperator2;
//    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);
//
//    // Test Operator >
//    variableRelationalOperator1 = 13.02;
//    variableRelationalOperator2 = 1.1f;
//    expectedResultOperator = TRUE;
//    actualResultOperator = variableRelationalOperator1 > variableRelationalOperator2;
//    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);
//
//    // Test Operator <
//    variableRelationalOperator1 = 1.11;
//    variableRelationalOperator2 = 13.02;
//    expectedResultOperator = TRUE;
//    actualResultOperator = variableRelationalOperator1 < variableRelationalOperator2;
//    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);
//
//    // Test Operator >=
//    variableRelationalOperator1 = 15.00;
//    variableRelationalOperator2 = 13.02;
//    expectedResultOperator = TRUE;
//    actualResultOperator = variableRelationalOperator1 >= variableRelationalOperator2;
//    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);
//
//    // Test Operator <=
//    variableRelationalOperator1 = 1.11;
//    variableRelationalOperator2 = 13.02;
//    expectedResultOperator = TRUE;
//    actualResultOperator = variableRelationalOperator1 <= variableRelationalOperator2;
//    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);
//}

TEST(JavaLang, FloatLogicalOperator) {
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
	ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);
	
	// Test Operator && . Case 0   1
	variableLogicalOperator1 = 0;
	variableLogicalOperator2 = 1;
	expectedResultOperator = FALSE;
	actualResultOperator = variableLogicalOperator1 && variableLogicalOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);
	
	// Test Operator && . Case 1   0
	variableLogicalOperator1 = 1;
	variableLogicalOperator2 = 0;
	expectedResultOperator = FALSE;
	actualResultOperator = variableLogicalOperator1 && variableLogicalOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);
	
	// Test Operator && . Case 1   1
	variableLogicalOperator1 = 1;
	variableLogicalOperator2 = 1;
	expectedResultOperator = TRUE;
	actualResultOperator = variableLogicalOperator1 && variableLogicalOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);
	
	// Test Operator || . Case 0   0
	variableLogicalOperator1 = 0;
	variableLogicalOperator2 = 0;
	expectedResultOperator = FALSE;
	actualResultOperator = variableLogicalOperator1 || variableLogicalOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);
	
	// Test Operator || . Case 0   1
	variableLogicalOperator1 = 0;
	variableLogicalOperator2 = 1;
	expectedResultOperator = TRUE;
	actualResultOperator = variableLogicalOperator1 || variableLogicalOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);
	
	// Test Operator || . Case 1   0
	variableLogicalOperator1 = 1;
	variableLogicalOperator2 = 0;
	expectedResultOperator = TRUE;
	actualResultOperator = variableLogicalOperator1 || variableLogicalOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);
	
	// Test Operator || . Case 1   1
	variableLogicalOperator1 = 1;
	variableLogicalOperator2 = 1;
	expectedResultOperator = TRUE;
	actualResultOperator = variableLogicalOperator1 || variableLogicalOperator2;
	ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);
}

TEST(JavaLang, FloatAssignmentOperator) {
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
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator +=
	variableAssignmentOperator1 = 1.1;
	variableAssignmentOperator2 = 2.2;
	expectedResultOperator = 3.3;
	actualResultOperator = (variableAssignmentOperator1 += variableAssignmentOperator2);
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	
	// Test Operator -=
	variableAssignmentOperator1 =   3.3;
	variableAssignmentOperator2 =  1.1;
	expectedResultOperator = 2.2;
	actualResultOperator = (variableAssignmentOperator1 -= variableAssignmentOperator2);
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator *=
	variableAssignmentOperator1 = 13.02;
	variableAssignmentOperator2 = 2.0;
	expectedResultOperator = 26.04;
	actualResultOperator = (variableAssignmentOperator1 *= variableAssignmentOperator2);
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
	
	// Test Operator /=
	variableAssignmentOperator1 = 26.04;
	variableAssignmentOperator2 = 2.0;
	expectedResultOperator = 13.02;
	actualResultOperator = (variableAssignmentOperator1 /= variableAssignmentOperator2);
	ASSERT_FLOAT_NEAR(expectedResultOperator.floatValue(), actualResultOperator.floatValue());
}

TEST(JavaLang, FloatCharValue) {
	// Create variable to test
	Float variableTestCharValue;
	char expectedResultCharValue;
	char actualResultCharValue;
	
	// Test POSITIVE_INFINITY
	variableTestCharValue = POSITIVE_INFINITY;
	expectedResultCharValue = 'i';
	actualResultCharValue = variableTestCharValue.charValue();
	ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);
	
	// Test NEGATIVE_INFINITY
	variableTestCharValue = NEGATIVE_INFINITY;
	expectedResultCharValue = '-';
	actualResultCharValue = variableTestCharValue.charValue();
	ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);

//    // Test NaN_NUMBER
//    variableTestCharValue = NaN_NUMBER;
//    expectedResultCharValue = 45;  // 110 in MacOS
//    actualResultCharValue = variableTestCharValue.charValue();
//    ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);
	
	// Test MAX_VALUE
	variableTestCharValue = MAX_VALUE;
	expectedResultCharValue = '3';
	actualResultCharValue = variableTestCharValue.charValue();
	ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);
	
	// Test MIN_NORMAL
	variableTestCharValue = MIN_NORMAL;
	expectedResultCharValue = '1';
	actualResultCharValue = variableTestCharValue.charValue();
	ASSERT_EQUAL(expectedResultCharValue , actualResultCharValue);
	
	// Test MIN_VALUE
	variableTestCharValue = MIN_VALUE;
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

// TODO(thoangminh): enable after finish toString()
//TEST (JavaLang, FloatStringValue){
//    // Create variable to test
//    Float variableTestStringValue;
//    string expectedResultStringValue;
//    string actualResultStringValue;
//
//    // Test POSITIVE_INFINITY
//    variableTestStringValue = POSITIVE_INFINITY;
//    expectedResultStringValue = (string) "inf";
//    actualResultStringValue = variableTestStringValue.stringValue();
//    ASSERT_STR(expectedResultStringValue , actualResultStringValue);
//
//    // Test NEGATIVE_INFINITY
//    variableTestStringValue = NEGATIVE_INFINITY;
//    expectedResultStringValue = (string) "-inf";
//    actualResultStringValue = variableTestStringValue.stringValue();
//    ASSERT_STR(expectedResultStringValue , actualResultStringValue);
//
////    // Test NaN_NUMBER
////    variableTestStringValue = NaN_NUMBER;
////    expectedResultStringValue = "-nan"; // "nan" in MacOS
////    actualResultStringValue = variableTestStringValue.stringValue();
////    ASSERT_STR(expectedResultStringValue , actualResultStringValue);
////    free(actualResultStringValue);
//
//    // Test MAX_VALUE
//    variableTestStringValue = MAX_VALUE;
//    expectedResultStringValue = (string) "1.797693134862316e+308";
//    actualResultStringValue = variableTestStringValue.stringValue();
//    ASSERT_STR(expectedResultStringValue , actualResultStringValue);
//
//    // Test MIN_NORMAL
//    variableTestStringValue = MIN_NORMAL;
//    expectedResultStringValue = (string) "4.940656458412465e-324";
//    actualResultStringValue = variableTestStringValue.stringValue();
//    ASSERT_STR(expectedResultStringValue , actualResultStringValue);
//
//    // Test MIN_VALUE
//    variableTestStringValue = MIN_VALUE;
//    expectedResultStringValue = (string) "2.225073858507201e-308";
//    actualResultStringValue = variableTestStringValue.stringValue();
//    ASSERT_STR(expectedResultStringValue , actualResultStringValue);
//}

TEST(JavaLang, FloatShortValue) {
	// Create variable to test
	Float variableTestShortValue;
	short expectedResultShortValue;
	short actualResultShortValue;
	
	// Test POSITIVE_INFINITY
	variableTestShortValue = POSITIVE_INFINITY;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);
	
	// Test NEGATIVE_INFINITY
	variableTestShortValue = NEGATIVE_INFINITY;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);
	
	// Test NaN_NUMBER
	variableTestShortValue = NaN_NUMBER;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);
	
	// Test MAX_VALUE
	variableTestShortValue = MAX_VALUE;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);
	
	// Test MIN_NORMAL
	variableTestShortValue = MIN_NORMAL;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);
	
	// Test MIN_VALUE
	variableTestShortValue = MIN_VALUE;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);
	
	// Test valid case
	variableTestShortValue = 5.9;
	expectedResultShortValue = 5;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);
	
	// Test valid case
	variableTestShortValue = 5.4;
	expectedResultShortValue = 5;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_EQUAL(expectedResultShortValue , actualResultShortValue);
	
	// Test invalid case
	variableTestShortValue = 6;
	expectedResultShortValue = 5;
	actualResultShortValue = variableTestShortValue.shortValue();
	ASSERT_NOT_EQUAL(expectedResultShortValue , actualResultShortValue);
}

TEST(JavaLang, FloatIntValue) {
	// Create variable to test
	Float variableTestIntValue;
	int expectedResultIntValue;
	int actualResultIntValue;
	
	// Test POSITIVE_INFINITY_DOUBLE
	variableTestIntValue = POSITIVE_INFINITY;
	expectedResultIntValue = -2147483648;
	actualResultIntValue = variableTestIntValue.intValue();
	ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);
	
	// Test NEGATIVE_INFINITY
	variableTestIntValue = NEGATIVE_INFINITY;
	expectedResultIntValue = -2147483648;
	actualResultIntValue = variableTestIntValue.intValue();
	ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);
	
	// Test NaN_NUMBER
	variableTestIntValue = NaN_NUMBER;
	expectedResultIntValue = -2147483648;
	actualResultIntValue = variableTestIntValue.intValue();
	ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);
	
	// Test MAX_VALUE
	variableTestIntValue = MAX_VALUE;
	expectedResultIntValue = -2147483648;
	actualResultIntValue = variableTestIntValue.intValue();
	ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);
	
	// Test MIN_NORMAL
	variableTestIntValue = MIN_NORMAL;
	expectedResultIntValue = 0;
	actualResultIntValue = variableTestIntValue.intValue();
	ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);
	
	// Test MIN_VALUE
	variableTestIntValue = MIN_VALUE;
	expectedResultIntValue = 0;
	actualResultIntValue = variableTestIntValue.intValue();
	ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);
	
	// Test valid case
	variableTestIntValue = 5.9;
	expectedResultIntValue = 5;
	actualResultIntValue = variableTestIntValue.intValue();
	ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);
	
	// Test valid case
	variableTestIntValue = 5.4;
	expectedResultIntValue = 5;
	actualResultIntValue = variableTestIntValue.intValue();
	ASSERT_EQUAL(expectedResultIntValue , actualResultIntValue);
	
	// Test invalid case
	variableTestIntValue = 6;
	expectedResultIntValue = 5;
	actualResultIntValue = variableTestIntValue.intValue();
	ASSERT_NOT_EQUAL(expectedResultIntValue , actualResultIntValue);
}

TEST(JavaLang, FloatLongValue) {
	// Create variable to test
	Float variableTestLongValue;
	long expectedResultLongValue;
	long actualResultLongValue;
	
	// Test POSITIVE_INFINITY_DOUBLE
	variableTestLongValue = POSITIVE_INFINITY;
	expectedResultLongValue = -9223372036854775808;
	actualResultLongValue = variableTestLongValue.longValue();
	ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);
	
	// Test NEGATIVE_INFINITY
	variableTestLongValue = NEGATIVE_INFINITY;
	expectedResultLongValue = -9223372036854775808;
	actualResultLongValue = variableTestLongValue.longValue();
	ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);
	
	// Test NaN_NUMBER
	variableTestLongValue = NaN_NUMBER;
	expectedResultLongValue = -9223372036854775808;
	actualResultLongValue = variableTestLongValue.longValue();
	ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);
	
	// Test MAX_VALUE
	variableTestLongValue = MAX_VALUE;
	expectedResultLongValue = -9223372036854775808;
	actualResultLongValue = variableTestLongValue.longValue();
	ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);
	
	// Test MIN_NORMAL
	variableTestLongValue = MIN_NORMAL;
	expectedResultLongValue = 0;
	actualResultLongValue = variableTestLongValue.longValue();
	ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);
	
	// Test MIN_VALUE
	variableTestLongValue = MIN_VALUE;
	expectedResultLongValue = 0;
	actualResultLongValue = variableTestLongValue.longValue();
	ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);
	
	// Test valid case
	variableTestLongValue = 5.9;
	expectedResultLongValue = 5;
	actualResultLongValue = variableTestLongValue.longValue();
	ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);
	
	// Test valid case
	variableTestLongValue = 5.4;
	expectedResultLongValue = 5;
	actualResultLongValue = variableTestLongValue.longValue();
	ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);
	
	// Test invalid case
	variableTestLongValue = 6;
	expectedResultLongValue = 5;
	actualResultLongValue = variableTestLongValue.longValue();
	ASSERT_NOT_EQUAL(expectedResultLongValue , actualResultLongValue);
	
}