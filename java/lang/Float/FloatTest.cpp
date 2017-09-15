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

TEST(JavaLang, FloatRelationalOperator) {
    // Create variable to test
    Float variableRelationalOperator1;
    Float variableRelationalOperator2;
    boolean actual;

    // Test Operator ==
    variableRelationalOperator1 = 13.12;
    variableRelationalOperator2 = 13.12;
    actual = variableRelationalOperator1 == variableRelationalOperator2;
    ASSERT_TRUE(actual);

    variableRelationalOperator1 = 13.12345;
    variableRelationalOperator2 = 13.12344;
    actual = variableRelationalOperator1 == variableRelationalOperator2;
    ASSERT_FALSE(actual);

    // Test Operator !=
    variableRelationalOperator1 = 13.02;
    variableRelationalOperator2 = 99.02;
    actual = variableRelationalOperator1 != variableRelationalOperator2;
    ASSERT_TRUE(actual);

    variableRelationalOperator1 = 13.12345;
    variableRelationalOperator2 = 13.12344;
    actual = variableRelationalOperator1 != variableRelationalOperator2;
    ASSERT_TRUE(actual);

    // Test Operator >
    variableRelationalOperator1 = 13.02;
    variableRelationalOperator2 = 1.1f;
    actual = variableRelationalOperator1 > variableRelationalOperator2;
    ASSERT_TRUE(actual);

    variableRelationalOperator1 = 13.22;
    variableRelationalOperator2 = 13.99;
    actual = variableRelationalOperator1 > variableRelationalOperator2;
    ASSERT_FALSE(actual);

    // Test Operator <
    variableRelationalOperator1 = 1.11;
    variableRelationalOperator2 = 13.02;
    actual = variableRelationalOperator1 < variableRelationalOperator2;
    ASSERT_TRUE(actual);

    variableRelationalOperator1 = 13.02;
    variableRelationalOperator2 = 13.01;
    actual = variableRelationalOperator1 < variableRelationalOperator2;
    ASSERT_FALSE(actual);

    // Test Operator >=
    variableRelationalOperator1 = 15.00;
    variableRelationalOperator2 = 13.02;
    actual = variableRelationalOperator1 >= variableRelationalOperator2;
    ASSERT_TRUE(actual);

    variableRelationalOperator1 = 10.11;
    variableRelationalOperator2 = 13.02;
    actual = variableRelationalOperator1 >= variableRelationalOperator2;
    ASSERT_FALSE(actual);

    // Test Operator <=
    variableRelationalOperator1 = 1.11;
    variableRelationalOperator2 = 13.02;
    actual = variableRelationalOperator1 <= variableRelationalOperator2;
    ASSERT_TRUE(actual);

    variableRelationalOperator1 = 13.99;
    variableRelationalOperator2 = 13.11;
    actual = variableRelationalOperator1 <= variableRelationalOperator2;
    ASSERT_FALSE(actual);
}

TEST(JavaLang, FloatLogicalOperator) {
    // Create variable to test
    Float variableLogicalOperator1;
    Float variableLogicalOperator2;
    boolean expectedResultOperator;
    boolean actualResultOperator;

    // Test Operator && . Case 0   0
    variableLogicalOperator1 = 0;
    variableLogicalOperator2 = 0;
    expectedResultOperator = false;
    actualResultOperator = variableLogicalOperator1 && variableLogicalOperator2;
    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator && . Case 0   1
    variableLogicalOperator1 = 0;
    variableLogicalOperator2 = 1;
    expectedResultOperator = false;
    actualResultOperator = variableLogicalOperator1 && variableLogicalOperator2;
    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator && . Case 1   0
    variableLogicalOperator1 = 1;
    variableLogicalOperator2 = 0;
    expectedResultOperator = false;
    actualResultOperator = variableLogicalOperator1 && variableLogicalOperator2;
    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator && . Case 1   1
    variableLogicalOperator1 = 1;
    variableLogicalOperator2 = 1;
    expectedResultOperator = true;
    actualResultOperator = variableLogicalOperator1 && variableLogicalOperator2;
    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator || . Case 0   0
    variableLogicalOperator1 = 0;
    variableLogicalOperator2 = 0;
    expectedResultOperator = false;
    actualResultOperator = variableLogicalOperator1 || variableLogicalOperator2;
    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator || . Case 0   1
    variableLogicalOperator1 = 0;
    variableLogicalOperator2 = 1;
    expectedResultOperator = true;
    actualResultOperator = variableLogicalOperator1 || variableLogicalOperator2;
    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator || . Case 1   0
    variableLogicalOperator1 = 1;
    variableLogicalOperator2 = 0;
    expectedResultOperator = true;
    actualResultOperator = variableLogicalOperator1 || variableLogicalOperator2;
    ASSERT_FLOAT_NEAR(expectedResultOperator, actualResultOperator);

    // Test Operator || . Case 1   1
    variableLogicalOperator1 = 1;
    variableLogicalOperator2 = 1;
    expectedResultOperator = true;
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

TEST(JavaLang, FloatStringValue) {
    // Create variable to test
    Float variableTestStringValue;
    string expectedResultStringValue;
    string actualResultStringValue;

    // Test POSITIVE_INFINITY
    variableTestStringValue = POSITIVE_INFINITY;
    expectedResultStringValue = (string) "inf";
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue , actualResultStringValue);

    // Test NEGATIVE_INFINITY
    variableTestStringValue = NEGATIVE_INFINITY;
    expectedResultStringValue = (string) "-inf";
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue , actualResultStringValue);

    // Test NaN_NUMBER
    variableTestStringValue = NaN_NUMBER;
    expectedResultStringValue = (string) "-nan";  // "nan" in MacOS
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue , actualResultStringValue);

    // Test MAX_VALUE
    variableTestStringValue = MAX_VALUE;
    expectedResultStringValue = (string) "3.40282e+38";
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue , actualResultStringValue);

    // Test MIN_NORMAL
    variableTestStringValue = MIN_NORMAL;
    expectedResultStringValue = (string) "1.4013e-45";
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue , actualResultStringValue);

    // Test MIN_VALUE
    variableTestStringValue = MIN_VALUE;
    expectedResultStringValue = (string) "1.17549e-38";
    actualResultStringValue = variableTestStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue , actualResultStringValue);
}

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

    // Test POSITIVE_INFINITY
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

    // Test POSITIVE_INFINITY
    variableTestLongValue = POSITIVE_INFINITY;
    expectedResultLongValue = -9223372036854775808u;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);

    // Test NEGATIVE_INFINITY
    variableTestLongValue = NEGATIVE_INFINITY;
    expectedResultLongValue = -9223372036854775808u;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);

    // Test NaN_NUMBER
    variableTestLongValue = NaN_NUMBER;
    expectedResultLongValue = -9223372036854775808u;
    actualResultLongValue = variableTestLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue , actualResultLongValue);

    // Test MAX_VALUE
    variableTestLongValue = MAX_VALUE;
    expectedResultLongValue = -9223372036854775808u;
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

TEST(JavaLang, FloatDoubleValue) {
    Float variableTest;

    variableTest = 0.0;
    ASSERT_DBL_NEAR(0.0, variableTest.doubleValue());

    variableTest = NaN_NUMBER;
    ASSERT_DBL_NEAR(NaN_NUMBER, variableTest.doubleValue());

    variableTest = POSITIVE_INFINITY;
    ASSERT_DBL_NEAR(POSITIVE_INFINITY, variableTest.doubleValue());

    variableTest = NEGATIVE_INFINITY;
    ASSERT_DBL_NEAR(NEGATIVE_INFINITY, variableTest.doubleValue());

    variableTest = MIN_NORMAL;
    ASSERT_DBL_NEAR(MIN_NORMAL, variableTest.doubleValue());

    variableTest = MIN_VALUE;
    ASSERT_DBL_NEAR(MIN_VALUE, variableTest.doubleValue());

    variableTest = MAX_VALUE;
    ASSERT_DBL_NEAR(MAX_VALUE, variableTest.doubleValue());
}

TEST(JavaLang, FloatToString) {
    // Create variable to test
    Float variableTestToString;
    string expectedResultToString;
    string actualResultToString;

    // Test POSITIVE_INFINITY
    variableTestToString = POSITIVE_INFINITY;
    expectedResultToString = (string) "inf";
    actualResultToString = variableTestToString.toString();
    ASSERT_STR(expectedResultToString , actualResultToString);

    // Test NEGATIVE_INFINITY
    variableTestToString = NEGATIVE_INFINITY;
    expectedResultToString = (string) "-inf";
    actualResultToString = variableTestToString.toString();
    ASSERT_STR(expectedResultToString , actualResultToString);

    // Test NaN_NUMBER
    variableTestToString = NaN_NUMBER;
    expectedResultToString = (string) "-nan";  // "nan" in MacOS
    actualResultToString = variableTestToString.toString();
    ASSERT_STR(expectedResultToString , actualResultToString);

    // Test MAX_VALUE
    variableTestToString = MAX_VALUE;
    expectedResultToString = (string) "3.40282e+38";
    actualResultToString = variableTestToString.toString();
    ASSERT_STR(expectedResultToString , actualResultToString);

    // Test MIN_NORMAL
    variableTestToString = MIN_NORMAL;
    expectedResultToString = (string) "1.4013e-45";
    actualResultToString = variableTestToString.toString();
    ASSERT_STR(expectedResultToString , actualResultToString);

    // Test MIN_VALUE
    variableTestToString = MIN_VALUE;
    expectedResultToString = (string) "1.17549e-38";
    actualResultToString = variableTestToString.toString();
    ASSERT_STR(expectedResultToString , actualResultToString);
}

TEST(JavaLang, FloatParseFloat) {
    // Test POSITIVE_INFINITY
    ASSERT_FLOAT_NEAR(POSITIVE_INFINITY, Float::parseFloat((String) "inf").floatValue());

    // Test NEGATIVE_INFINITY
    ASSERT_FLOAT_NEAR(NEGATIVE_INFINITY, Float::parseFloat((String) "-inf").floatValue());

    // Test NaN_NUMBER
    ASSERT_FLOAT_NEAR(-NaN_NUMBER, Float::parseFloat((String) "nan").floatValue());

    // Test MAX_VALUE
    ASSERT_FLOAT_NEAR(MAX_VALUE,
                      Float::parseFloat((String) "340282346638528859811704183484516925440.0").floatValue());

    // Test MIN_NORMAL
    ASSERT_FLOAT_NEAR(MIN_NORMAL, Float::parseFloat((String) "1.4013e-45").floatValue());

    // Test MIN_VALUE
    ASSERT_FLOAT_NEAR(MIN_VALUE, Float::parseFloat((String) "1.17549e-38").floatValue());
}

TEST(JavaLang, FloatValueOf) {
    // Test POSITIVE_INFINITY
    ASSERT_FLOAT_NEAR(POSITIVE_INFINITY, Float::valueOf((String) "inf").floatValue());

    // Test NEGATIVE_INFINITY
    ASSERT_FLOAT_NEAR(NEGATIVE_INFINITY, Float::valueOf((String) "-inf").floatValue());

    // Test NaN_NUMBER
    ASSERT_FLOAT_NEAR(-NaN_NUMBER, Float::valueOf((String) "nan").floatValue());

    // Test MAX_VALUE
    ASSERT_FLOAT_NEAR(MAX_VALUE,
                      Float::valueOf((String) "340282346638528859811704183484516925440.0").floatValue());

    // Test MIN_NORMAL
    ASSERT_FLOAT_NEAR(MIN_NORMAL, Float::valueOf((String) "1.4013e-45").floatValue());

    // Test MIN_VALUE
    ASSERT_FLOAT_NEAR(MIN_VALUE, Float::valueOf((String) "1.17549e-38").floatValue());
}

TEST(JavaLang, FloatValueOf2) {
    // Test POSITIVE_INFINITY
    ASSERT_FLOAT_NEAR(POSITIVE_INFINITY, Float::valueOf(POSITIVE_INFINITY).floatValue());

    // Test NEGATIVE_INFINITY
    ASSERT_FLOAT_NEAR(NEGATIVE_INFINITY, Float::valueOf(NEGATIVE_INFINITY).floatValue());

    // Test NaN_NUMBER
    ASSERT_FLOAT_NEAR(-NaN_NUMBER, Float::valueOf(-NaN_NUMBER).floatValue());

    // Test MAX_VALUE
    ASSERT_FLOAT_NEAR(MAX_VALUE,
                      Float::valueOf(340282346638528859811704183484516925440.0f).floatValue());

    // Test MIN_NORMAL
    ASSERT_FLOAT_NEAR(MIN_NORMAL, Float::valueOf(1.4013e-45).floatValue());

    // Test MIN_VALUE
    ASSERT_FLOAT_NEAR(MIN_VALUE, Float::valueOf(1.17549e-38).floatValue());
}

// TODO(thoangminh): need to pass test case in comment block
TEST(JavaLang, FloatToBinary32StringType) {
    float floatInput;
    string expectedResult;
    string actualResult;

//    floatInput = 123456789.12345;
//    expectedResult = (string) "01001100111010110111100110100010";
//    actualResult = Float::floatToBinary32StringType(floatInput);
//    ASSERT_STR(expectedResult, actualResult);
//    free(actualResult);

//    floatInput = 123456788.1234;
//    expectedResult = (string) "01001100111010110111100110100010";
//    actualResult = Float::floatToBinary32StringType(floatInput);
//    ASSERT_STR(expectedResult, actualResult);
//    free(actualResult);

//    // Must be different
//    ASSERT_STR(Float::floatToBinary32StringType(123.1234567), Float::floatToBinary32StringType(123.1234566));

    floatInput = 0;
    expectedResult = (string) "00000000000000000000000000000000";
    actualResult = Float::floatToBinary32StringType(floatInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    floatInput = POSITIVE_INFINITY;
    expectedResult = (string) "01111111100000000000000000000000";
    actualResult = Float::floatToBinary32StringType(floatInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    floatInput = NEGATIVE_INFINITY;
    expectedResult = (string) "11111111100000000000000000000000";
    actualResult = Float::floatToBinary32StringType(floatInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    floatInput = NaN_NUMBER;
    expectedResult = (string) "01111111111111111111111111111111";
    actualResult = Float::floatToBinary32StringType(floatInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    floatInput = -0.7f;
    expectedResult = (string) "10111111001100110011001100110011";
    actualResult = Float::floatToBinary32StringType(floatInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    floatInput = 12.375;
    expectedResult = (string) "01000001010001100000000000000000";
    actualResult = Float::floatToBinary32StringType(floatInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    floatInput = 1.0;
    expectedResult = (string) "00111111100000000000000000000000";
    actualResult = Float::floatToBinary32StringType(floatInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    floatInput = 0.375;
    expectedResult = (string) "00111110110000000000000000000000";
    actualResult = Float::floatToBinary32StringType(floatInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    floatInput = -2.0f;
    expectedResult = (string) "11000000000000000000000000000000";
    actualResult = Float::floatToBinary32StringType(floatInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    floatInput = 83.0;
    expectedResult = (string) "01000010101001100000000000000000";
    actualResult = Float::floatToBinary32StringType(floatInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    floatInput = -2625.0f;
    expectedResult = (string) "11000101001001000001000000000000";
    actualResult = Float::floatToBinary32StringType(floatInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    floatInput = 0.5;
    expectedResult = (string) "00111111000000000000000000000000";
    actualResult = Float::floatToBinary32StringType(floatInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    floatInput = -1302.123456f;
    expectedResult = (string) "11000100101000101100001111110011";
    actualResult = Float::floatToBinary32StringType(floatInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);
}

TEST(JavaLang, FloatBinary32StringTypeToFloat) {
    string Binary32StringTypeInput;
    float expectedResult;
    float actualResult;

    Binary32StringTypeInput = (string) "00000000000000000000000000000000";
    expectedResult = 0;
    actualResult = Float::binary32StringTypeToFloat(Binary32StringTypeInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    Binary32StringTypeInput = (string) "01111111100000000000000000000000";
    expectedResult = POSITIVE_INFINITY;
    actualResult = Float::binary32StringTypeToFloat(Binary32StringTypeInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    Binary32StringTypeInput = (string) "11111111100000000000000000000000";
    expectedResult = NEGATIVE_INFINITY;
    actualResult = Float::binary32StringTypeToFloat(Binary32StringTypeInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    Binary32StringTypeInput = (string) "01111111111111111111111111111111";
    expectedResult = NaN_NUMBER;
    actualResult = Float::binary32StringTypeToFloat(Binary32StringTypeInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    Binary32StringTypeInput = (string) "10111111001100110011001100110011";
    expectedResult = -0.7f;
    actualResult = Float::binary32StringTypeToFloat(Binary32StringTypeInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    Binary32StringTypeInput = (string) "01000001010001100000000000000000";
    expectedResult = 12.375;
    actualResult = Float::binary32StringTypeToFloat(Binary32StringTypeInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    Binary32StringTypeInput = (string) "00111111100000000000000000000000";
    expectedResult = 1.0;
    actualResult = Float::binary32StringTypeToFloat(Binary32StringTypeInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    Binary32StringTypeInput = (string) "00111110110000000000000000000000";
    expectedResult = 0.375;
    actualResult = Float::binary32StringTypeToFloat(Binary32StringTypeInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    Binary32StringTypeInput = (string) "11000000000000000000000000000000";
    expectedResult = -2.0f;
    actualResult = Float::binary32StringTypeToFloat(Binary32StringTypeInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    Binary32StringTypeInput = (string) "01000010101001100000000000000000";
    expectedResult = 83.0;
    actualResult = Float::binary32StringTypeToFloat(Binary32StringTypeInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    Binary32StringTypeInput = (string) "11000101001001000001000000000000";
    expectedResult = -2625.0f;
    actualResult = Float::binary32StringTypeToFloat(Binary32StringTypeInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    Binary32StringTypeInput = (string) "00111111000000000000000000000000";
    expectedResult = 0.5;
    actualResult = Float::binary32StringTypeToFloat(Binary32StringTypeInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    Binary32StringTypeInput = (string) "11000100101000101100001111110011";
    expectedResult = -1302.123456f;
    actualResult = Float::binary32StringTypeToFloat(Binary32StringTypeInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);
}

TEST(JavaLang, FloatToRawIntBits) {
    // Create variable to test
    float input;
    int expectedResult;
    int actualResult;

    // Input 0.0
    input = 0.0;
    expectedResult = 0;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input POSITIVE_INFINITY
    input = POSITIVE_INFINITY;
    expectedResult = 2139095040;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input NEGATIVE_INFINITY
    input = NEGATIVE_INFINITY;
    expectedResult = -2139095040;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input NaN_NUMBER
    input = NaN_NUMBER;
    expectedResult = 2147483647;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -0.7
    input = -0.7f;
    expectedResult =  -1060320051;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 12.375
    input = 12.375;
    expectedResult = 1095106560;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 1.0
    input = 1.0;
    expectedResult = 1065353216;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 0.375
    input = 0.375;
    expectedResult = 1052770304;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -2
    input = -2.0f;
    expectedResult = -1073741824;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 83
    input = 83.0;
    expectedResult = 1118175232;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -2625
    input = -2625.0f;
    expectedResult = -1159991296;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 0.5
    input = 0.5;
    expectedResult = 1056964608;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -1302.12345678
    input = -1302.12345678f;
    expectedResult = -1151517683;
    actualResult = Float::floatToRawIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);
}

TEST(JavaLang, FloatToIntBits) {
    // Create variable to test
    float input;
    int expectedResult;
    int actualResult;

    // Input 0.0
    input = 0.0;
    expectedResult = 0;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input POSITIVE_INFINITY
    input = POSITIVE_INFINITY;
    expectedResult = 2139095040;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input NEGATIVE_INFINITY
    input = NEGATIVE_INFINITY;
    expectedResult = -2139095040;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input NaN_NUMBER
    input = NaN_NUMBER;
    expectedResult = 2147483647;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -0.7
    input = -0.7f;
    expectedResult = -1060320051;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 12.375
    input = 12.375;
    expectedResult = 1095106560;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 1.0
    input = 1.0;
    expectedResult = 1065353216;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 0.375
    input = 0.375;
    expectedResult = 1052770304;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -2
    input = -2.0f;
    expectedResult = -1073741824;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 83
    input = 83.0;
    expectedResult = 1118175232;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -2625
    input = -2625.0f;
    expectedResult = -1159991296;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 0.5
    input = 0.5;
    expectedResult = 1056964608;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -1302.12345678
    input = -1302.12345678f;
    expectedResult = -1151517683;
    actualResult = Float::floatToIntBits(input);
    ASSERT_EQUAL(expectedResult, actualResult);
}

TEST(JavaLang, FloatIntBitsToBinary32StringType) {
    int intBitsInput;
    string expectedResult;
    string actualResult;

    // IntBits of 0
    intBitsInput = 0;
    expectedResult = (string) "00000000000000000000000000000000";
    actualResult = Float::intBitsToBinary32StringType(intBitsInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    // IntBits of POSITIVE_INFINITY;
    intBitsInput = 2139095040;
    expectedResult = (string) "01111111100000000000000000000000";
    actualResult = Float::intBitsToBinary32StringType(intBitsInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    // IntBits of NEGATIVE_INFINITY
    intBitsInput = -2139095040;
    expectedResult = (string) "11111111100000000000000000000000";
    actualResult = Float::intBitsToBinary32StringType(intBitsInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    // IntBits of NaN_NUMBER
    intBitsInput = 2147483647;
    expectedResult = (string) "01111111111111111111111111111111";
    actualResult = Float::intBitsToBinary32StringType(intBitsInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    // IntBits of -0.7
    intBitsInput = -1060320051;
    expectedResult = (string) "10111111001100110011001100110011";
    actualResult = Float::intBitsToBinary32StringType(intBitsInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    // IntBits of 12.375
    intBitsInput = 1095106560;
    expectedResult = (string) "01000001010001100000000000000000";
    actualResult = Float::intBitsToBinary32StringType(intBitsInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    // IntBits of 1.0
    intBitsInput = 1065353216;
    expectedResult = (string) "00111111100000000000000000000000";
    actualResult = Float::intBitsToBinary32StringType(intBitsInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    // IntBits of 0.375
    intBitsInput = 1052770304;
    expectedResult = (string) "00111110110000000000000000000000";
    actualResult = Float::intBitsToBinary32StringType(intBitsInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    // IntBits of -2
    intBitsInput = -1073741824;
    expectedResult = (string) "11000000000000000000000000000000";
    actualResult = Float::intBitsToBinary32StringType(intBitsInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    // IntBits of 83
    intBitsInput = 1118175232;
    expectedResult = (string) "01000010101001100000000000000000";
    actualResult = Float::intBitsToBinary32StringType(intBitsInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    // IntBits of -2625
    intBitsInput = -1159991296;
    expectedResult = (string) "11000101001001000001000000000000";
    actualResult = Float::intBitsToBinary32StringType(intBitsInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    // IntBits of 0.5
    intBitsInput = 1056964608;
    expectedResult = (string) "00111111000000000000000000000000";
    actualResult = Float::intBitsToBinary32StringType(intBitsInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);

    // IntBits of -1302.12345678
    intBitsInput = -1151517683;
    expectedResult = (string) "11000100101000101100001111110011";
    actualResult = Float::intBitsToBinary32StringType(intBitsInput);
    ASSERT_STR(expectedResult, actualResult);
    free(actualResult);
}

TEST(JavaLang , FloatIsNaN) {
    ASSERT_TRUE(Float::isNaN(NaN_NUMBER));
    ASSERT_FALSE(Float::isNaN(NEGATIVE_INFINITY));
    ASSERT_FALSE(Float::isNaN(13.02));
    ASSERT_FALSE(Float::isNaN(130.2));
}

TEST(JavaLang , FloatIsNaN2) {
    Float variableIsInfinite2;

    variableIsInfinite2 = NaN_NUMBER;
    ASSERT_TRUE(variableIsInfinite2.isNaN());

    variableIsInfinite2 = NEGATIVE_INFINITY;
    ASSERT_FALSE(variableIsInfinite2.isNaN());

    variableIsInfinite2 = 13.02;
    ASSERT_FALSE(variableIsInfinite2.isNaN());
}

TEST(JavaLang, FloatFloatValue) {
    // Create variable to test
    Float variableTestFloatValue;
    float expectedResultFloatValue;
    float actualResultFloatValue;

    // Test POSITIVE_INFINITY
    variableTestFloatValue = POSITIVE_INFINITY;
    expectedResultFloatValue = POSITIVE_INFINITY;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test NEGATIVE_INFINITY
    variableTestFloatValue = NEGATIVE_INFINITY;
    expectedResultFloatValue = NEGATIVE_INFINITY;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test NaN_NUMBER
    variableTestFloatValue = NaN_NUMBER;
    expectedResultFloatValue = NaN_NUMBER;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test MAX_VALUE
    variableTestFloatValue = MAX_VALUE;
    expectedResultFloatValue = MAX_VALUE;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test MIN_NORMAL
    variableTestFloatValue = MIN_NORMAL;
    expectedResultFloatValue = MIN_NORMAL;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test MIN_VALUE
    variableTestFloatValue = MIN_VALUE;
    expectedResultFloatValue = MIN_VALUE;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test valid case
    variableTestFloatValue = 13.02;
    expectedResultFloatValue = 13.02;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test valid case
    variableTestFloatValue = 1.302;
    expectedResultFloatValue = 1.302;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test invalid case
    variableTestFloatValue = 130.2;
    expectedResultFloatValue = 130.0;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_FLOAT_FAR(expectedResultFloatValue , actualResultFloatValue);
}

// TODO(thoangminh): Need to pass all test cases in comment block
TEST(JavaLang, FloatCompare) {
    // Test NaN_NUMBER
    ASSERT_EQUAL(0, Float::compare(NaN_NUMBER, NaN_NUMBER));
    ASSERT_EQUAL(1, Float::compare(NaN_NUMBER, POSITIVE_INFINITY));
//    ASSERT_EQUAL(1, Float::compare(NaN_NUMBER, MAX_VALUE));
    ASSERT_EQUAL(1, Float::compare(NaN_NUMBER, 1.2));
    ASSERT_EQUAL(1, Float::compare(NaN_NUMBER, 0.0));
    ASSERT_EQUAL(1, Float::compare(NaN_NUMBER, -0.0f));
    ASSERT_EQUAL(1, Float::compare(NaN_NUMBER, -1.2f));
    ASSERT_EQUAL(1, Float::compare(NaN_NUMBER, MIN_VALUE));
    ASSERT_EQUAL(1, Float::compare(NaN_NUMBER, NEGATIVE_INFINITY));

    // Test POSITIVE_INFINITY
    ASSERT_EQUAL(-1, Float::compare(POSITIVE_INFINITY, NaN_NUMBER));
    ASSERT_EQUAL(0, Float::compare(POSITIVE_INFINITY, POSITIVE_INFINITY));
//    ASSERT_EQUAL(-1, Float::compare(POSITIVE_INFINITY, MAX_VALUE), -9999);
    ASSERT_EQUAL(1, Float::compare(POSITIVE_INFINITY, 1.2));
    ASSERT_EQUAL(1, Float::compare(POSITIVE_INFINITY, 0.0));
    ASSERT_EQUAL(1, Float::compare(POSITIVE_INFINITY, -0.0f));
    ASSERT_EQUAL(1, Float::compare(POSITIVE_INFINITY, -1.2f));
    ASSERT_EQUAL(1, Float::compare(POSITIVE_INFINITY, MIN_VALUE));
    ASSERT_EQUAL(1, Float::compare(POSITIVE_INFINITY, NEGATIVE_INFINITY));

    // Test NEGATIVE_INFINITY
    ASSERT_EQUAL(-1, Float::compare(NEGATIVE_INFINITY, NaN_NUMBER));
    ASSERT_EQUAL(-1, Float::compare(NEGATIVE_INFINITY, POSITIVE_INFINITY));
//    ASSERT_EQUAL(-1, Float::compare(NEGATIVE_INFINITY, MAX_VALUE), -9999);
    ASSERT_EQUAL(-1, Float::compare(NEGATIVE_INFINITY, 1.2));
    ASSERT_EQUAL(-1, Float::compare(NEGATIVE_INFINITY, 0.0));
    ASSERT_EQUAL(-1, Float::compare(NEGATIVE_INFINITY, -0.0f));
    ASSERT_EQUAL(-1, Float::compare(NEGATIVE_INFINITY, -1.2f));
    ASSERT_EQUAL(-1, Float::compare(NEGATIVE_INFINITY, MIN_VALUE));
    ASSERT_EQUAL(0, Float::compare(NEGATIVE_INFINITY, NEGATIVE_INFINITY));

//    // Test MAX_VALUE
//    ASSERT_EQUAL(Float::compare(MAX_VALUE, NaN_NUMBER), -9999);
//    ASSERT_EQUAL(Float::compare(MAX_VALUE, POSITIVE_INFINITY), -9999);
//    ASSERT_EQUAL(Float::compare(MAX_VALUE, MAX_VALUE));
//    ASSERT_EQUAL(Float::compare(MAX_VALUE, 1.2));
//    ASSERT_EQUAL(Float::compare(MAX_VALUE, 0.0));
//    ASSERT_EQUAL(Float::compare(MAX_VALUE, -0.0f));
//    ASSERT_EQUAL(Float::compare(MAX_VALUE, -1.2f));
//    ASSERT_EQUAL(Float::compare(MAX_VALUE, MIN_VALUE));
//    ASSERT_EQUAL(Float::compare(MAX_VALUE, NEGATIVE_INFINITY), -9999);

    // Test MIN_VALUE
    ASSERT_EQUAL(-1, Float::compare(MIN_VALUE, NaN_NUMBER));
    ASSERT_EQUAL(-1, Float::compare(MIN_VALUE, POSITIVE_INFINITY));
//    ASSERT_EQUAL(Float::compare(MIN_VALUE, MAX_VALUE));
    ASSERT_EQUAL(-1, Float::compare(MIN_VALUE, 1.2));
    ASSERT_EQUAL(1, Float::compare(MIN_VALUE, 0.0));
    ASSERT_EQUAL(1, Float::compare(MIN_VALUE, -0.0f));
    ASSERT_EQUAL(1, Float::compare(MIN_VALUE, -1.2f));
    ASSERT_EQUAL(0, Float::compare(MIN_VALUE, MIN_VALUE));
    ASSERT_EQUAL(1, Float::compare(MIN_VALUE, NEGATIVE_INFINITY));

    // Test value 1.2
    ASSERT_EQUAL(-1, Float::compare(1.2, NaN_NUMBER));
    ASSERT_EQUAL(-1, Float::compare(1.2, POSITIVE_INFINITY));
//    ASSERT_EQUAL(-1, Float::compare(1.2, MAX_VALUE));
    ASSERT_EQUAL(0, Float::compare(1.2, 1.2));
    ASSERT_EQUAL(1, Float::compare(1.2, 0.0));
    ASSERT_EQUAL(1, Float::compare(1.2, -0.0f));
    ASSERT_EQUAL(1, Float::compare(1.2, -1.2f));
    ASSERT_EQUAL(1, Float::compare(1.2, MIN_VALUE));
    ASSERT_EQUAL(1, Float::compare(1.2, NEGATIVE_INFINITY));

    // Test value 0.0
    ASSERT_EQUAL(-1, Float::compare(0.0, NaN_NUMBER));
    ASSERT_EQUAL(-1, Float::compare(0.0, POSITIVE_INFINITY));
//    ASSERT_EQUAL(Float::compare(0.0, MAX_VALUE));
    ASSERT_EQUAL(-1, Float::compare(0.0, 1.2));
    ASSERT_EQUAL(0, Float::compare(0.0, 0.0));
    ASSERT_EQUAL(0, Float::compare(0.0, -0.0f));  // error in OSX
    ASSERT_EQUAL(1, Float::compare(0.0, -1.2f));
    ASSERT_EQUAL(-1, Float::compare(0.0, MIN_VALUE));
    ASSERT_EQUAL(1, Float::compare(0.0, NEGATIVE_INFINITY));

    // Test value -0.0f
    ASSERT_EQUAL(-1, Float::compare(-0.0f, NaN_NUMBER));
    ASSERT_EQUAL(-1, Float::compare(-0.0f, POSITIVE_INFINITY));
//    ASSERT_EQUAL(Float::compare(-0.0f, MAX_VALUE));
    ASSERT_EQUAL(-1, Float::compare(-0.0f, 1.2));
    ASSERT_EQUAL(0, Float::compare(-0.0f, 0.0));  // error in OSX
    ASSERT_EQUAL(0, Float::compare(-0.0f, -0.0f));   // error in OSX
    ASSERT_EQUAL(1, Float::compare(-0.0f, -1.2f));
    ASSERT_EQUAL(-1, Float::compare(-0.0f, MIN_VALUE));
    ASSERT_EQUAL(1, Float::compare(-0.0f, NEGATIVE_INFINITY));

    // Test value -1.2f
    ASSERT_EQUAL(-1, Float::compare(-1.2f, NaN_NUMBER));
    ASSERT_EQUAL(-1, Float::compare(-1.2f, POSITIVE_INFINITY));
//    ASSERT_EQUAL(Float::compare(-1.2f, MAX_VALUE));
    ASSERT_EQUAL(-1, Float::compare(-1.2f, 1.2));
    ASSERT_EQUAL(-1, Float::compare(-1.2f, 0.0));
    ASSERT_EQUAL(-1, Float::compare(-1.2f, -0.0f));
    ASSERT_EQUAL(0, Float::compare(-1.2f, -1.2f));
    ASSERT_EQUAL(-1, Float::compare(-1.2f, MIN_VALUE));
    ASSERT_EQUAL(1, Float::compare(-1.2f, NEGATIVE_INFINITY));
}

// TODO(thoangminh): Need to pass all test cases in comment block
TEST(JavaLang, FloatEquals) {
    // Create variable to test
    Float variableFloatEquals;
    Float FLOAT_NaN = NaN_NUMBER;
    Float FLOAT_POSITIVE_INFINITY = POSITIVE_INFINITY;
    Float FLOAT_NEGATIVE_INFINITY = NEGATIVE_INFINITY;
    Float FLOAT_MAX_VALUE = MAX_VALUE;
    Float FLOAT_MIN_VALUE = MIN_VALUE;

    // Test NaN_NUMBER
    variableFloatEquals = NaN_NUMBER;
    ASSERT_EQUAL(1, variableFloatEquals.equals(FLOAT_NaN));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MAX_VALUE));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)1.2));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));

    // Test FLOAT_POSITIVE_INFINITY
    variableFloatEquals = FLOAT_POSITIVE_INFINITY;
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NaN));
    ASSERT_EQUAL(1, variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableFloatEquals.equals( FLOAT_MAX_VALUE), -9999);
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)1.2));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0), -9999);
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE), -9999);
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));

//    // Test FLOAT_MAX_VALUE
//    variableFloatEquals = FLOAT_MAX_VALUE;
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_NaN));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MAX_VALUE));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));
//
//    // Test FLOAT_MIN_VALUE
//    variableFloatEquals = FLOAT_MIN_VALUE;
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_NaN), -9999);
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY), -9999);
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MAX_VALUE));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));

    // Test FLOAT_NEGATIVE_INFINITY
    variableFloatEquals = FLOAT_NEGATIVE_INFINITY;
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NaN));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MAX_VALUE), -9999);
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)1.2));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0), -9999);
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE), -9999);
    ASSERT_EQUAL(1, variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));

    // Test value (Float)1.2
    variableFloatEquals = (Float)1.2;
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NaN));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MAX_VALUE));
    ASSERT_EQUAL(1, variableFloatEquals.equals((Float)1.2));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));

    // Test value (Float)0.0
    variableFloatEquals = (Float)0.0;
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NaN));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MAX_VALUE));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)1.2));
    ASSERT_EQUAL(1, variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));

    // Test value (Float)-0.0
//    variableFloatEquals = (Float)-0.0;
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_NaN));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MAX_VALUE));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));

    // Test value (Float)-1.2
    variableFloatEquals = (Float)-1.2;
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NaN));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MAX_VALUE));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)1.2));
    ASSERT_EQUAL(0, variableFloatEquals.equals((Float)0.0));
//    ASSERT_EQUAL(variableFloatEquals.equals((Float)-0.0));
    ASSERT_EQUAL(1, variableFloatEquals.equals((Float)-1.2));
//    ASSERT_EQUAL(variableFloatEquals.equals(FLOAT_MIN_VALUE));
    ASSERT_EQUAL(0, variableFloatEquals.equals(FLOAT_NEGATIVE_INFINITY));
}

TEST(JavaLang , FloatIsFinite) {
    ASSERT_TRUE(Float::isFinite(13.02));
    ASSERT_TRUE(Float::isFinite(130.2));
    ASSERT_FALSE(Float::isFinite(POSITIVE_INFINITY));
    ASSERT_FALSE(Float::isFinite(NEGATIVE_INFINITY));
}

TEST(JavaLang , FloatIsInfinite) {
    ASSERT_TRUE(Float::isInfinite(POSITIVE_INFINITY));
    ASSERT_TRUE(Float::isInfinite(NEGATIVE_INFINITY));
    ASSERT_FALSE(Float::isInfinite(13.02));
    ASSERT_FALSE(Float::isInfinite(130.2));
}

TEST(JavaLang , FloatIsInfinite2) {
    Float variableIsInfinite2;

    variableIsInfinite2 = POSITIVE_INFINITY;
    ASSERT_TRUE(variableIsInfinite2.isInfinite());

    variableIsInfinite2 = NEGATIVE_INFINITY;
    ASSERT_TRUE(variableIsInfinite2.isInfinite());

    variableIsInfinite2 = 13.02;
    ASSERT_FALSE(variableIsInfinite2.isInfinite());
}

TEST(JavaLang , FloatHashCode) {
    // Create variable to test
    float input;
    int expectedResult;
    int actualResult;

    // Input 0.0
    input = 0.0;
    expectedResult = 0;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input POSITIVE_INFINITY
    input = POSITIVE_INFINITY;
    expectedResult = 2139095040;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input NEGATIVE_INFINITY
    input = NEGATIVE_INFINITY;
    expectedResult = -2139095040;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input NaN_NUMBER
    input = NaN_NUMBER;
    expectedResult = 2147483647;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -0.7
    input = -0.7f;
    expectedResult = -1060320051;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 12.375
    input = 12.375;
    expectedResult = 1095106560;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 1.0
    input = 1.0;
    expectedResult = 1065353216;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 0.375
    input = 0.375;
    expectedResult = 1052770304;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -2
    input = -2.0f;
    expectedResult = -1073741824;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 83
    input = 83.0;
    expectedResult = 1118175232;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -2625
    input = -2625.0f;
    expectedResult = -1159991296;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 0.5
    input = 0.5;
    expectedResult = 1056964608;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -1302.12345678
    input = -1302.12345678f;
    expectedResult = -1151517683;
    actualResult = Float::hashCode(input);
    ASSERT_EQUAL(expectedResult, actualResult);
}

TEST(JavaLang , FloatHashCode2) {
    // Create variable to test
    Float input;
    int expectedResult;
    int actualResult;

    // Input 0.0
    input = 0.0;
    expectedResult = 0;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input POSITIVE_INFINITY
    input = POSITIVE_INFINITY;
    expectedResult = 2139095040;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input NEGATIVE_INFINITY
    input = NEGATIVE_INFINITY;
    expectedResult = -2139095040;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input NaN_NUMBER
    input = NaN_NUMBER;
    expectedResult = 2147483647;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -0.7
    input = -0.7f;
    expectedResult =  -1060320051;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 12.375
    input = 12.375;
    expectedResult = 1095106560;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 1.0
    input = 1.0;
    expectedResult = 1065353216;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 0.375
    input = 0.375;
    expectedResult = 1052770304;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -2
    input = -2.0f;
    expectedResult = -1073741824;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 83
    input = 83.0;
    expectedResult = 1118175232;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -2625
    input = -2625.0f;
    expectedResult = -1159991296;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input 0.5
    input = 0.5;
    expectedResult = 1056964608;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);

    // Input -1302.12345678
    input = -1302.12345678f;
    expectedResult = -1151517683;
    actualResult = input.hashCode();
    ASSERT_EQUAL(expectedResult, actualResult);
}

TEST(JavaLang, FloatMin) {
    float variableFloatMin1;
    float variableFloatMin2;
    float expectedResultFloatMin;
    float actualResultFloatMin;

    variableFloatMin1 = 13.02;
    variableFloatMin2 = 1.302;
    expectedResultFloatMin = 1.302;
    actualResultFloatMin = Float::min(variableFloatMin1 , variableFloatMin2);
    ASSERT_FLOAT_NEAR(expectedResultFloatMin , actualResultFloatMin);

    variableFloatMin1 = 13.02;
    variableFloatMin2 = 1.302;
    expectedResultFloatMin = 13.02;
    actualResultFloatMin = Float::min(variableFloatMin1 , variableFloatMin2);
    ASSERT_FLOAT_FAR(expectedResultFloatMin , actualResultFloatMin);
}

TEST(JavaLang, FloatIntBitsToFloat) {
    // Create variable to test
    int intBitsInput;
    float expectedResult;
    float actualResult;

    // Input 0.0
    intBitsInput = 0;
    expectedResult = 0.0;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input POSITIVE_INFINITY
    intBitsInput = 2139095040;
    expectedResult = POSITIVE_INFINITY;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input NEGATIVE_INFINITY
    intBitsInput = -2139095040;
    expectedResult = NEGATIVE_INFINITY;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);


    // Input -0.7
    intBitsInput = -1060320051;
    expectedResult = -0.7f;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input 12.375
    intBitsInput = 1095106560;
    expectedResult = 12.375;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input 1.0
    intBitsInput = 1065353216;
    expectedResult = 1.0;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input 0.375
    intBitsInput = 1052770304;
    expectedResult = 0.375;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input -2
    intBitsInput = -1073741824;
    expectedResult = -2.0f;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input 83
    intBitsInput = 1118175232;
    expectedResult = 83.0;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input -2625
    intBitsInput = -1159991296;
    expectedResult = -2625.0f;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input 0.5
    intBitsInput = 1056964608;
    expectedResult = 0.5;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);

    // Input -1302.12345678
    intBitsInput = -1151517683;
    expectedResult = -1302.12345678f;
    actualResult = Float::intBitsToFloat(intBitsInput);
    ASSERT_FLOAT_NEAR(expectedResult, actualResult);
}

TEST(JavaLang, FloatCompareTo) {
    Float variableCompareTo;

    // Test NaN_NUMBER
    variableCompareTo = NaN_NUMBER;
    ASSERT_EQUAL(0, variableCompareTo.compareTo(NaN_NUMBER));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableCompareTo.compareTo(MAX_VALUE), -9999);
    ASSERT_EQUAL(1, variableCompareTo.compareTo(1.2));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(0.0));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(-0.0f));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(-1.2f));
//    ASSERT_EQUAL(variableCompareTo.compareTo(MIN_VALUE), -9999);
    ASSERT_EQUAL(1, variableCompareTo.compareTo(NEGATIVE_INFINITY));

    // Test POSITIVE_INFINITY
    variableCompareTo = POSITIVE_INFINITY;
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(NaN_NUMBER));
    ASSERT_EQUAL(0, variableCompareTo.compareTo(POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableCompareTo.compareTo( MAX_VALUE), -9999);
    ASSERT_EQUAL(1, variableCompareTo.compareTo(1.2));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(0.0));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(-0.0f));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(-1.2f));
//    ASSERT_EQUAL(variableCompareTo.compareTo(MIN_VALUE), -9999);
    ASSERT_EQUAL(1, variableCompareTo.compareTo(NEGATIVE_INFINITY));

    // Test NEGATIVE_INFINITY
    variableCompareTo = NEGATIVE_INFINITY;
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(NaN_NUMBER));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableCompareTo.compareTo(MAX_VALUE), -9999);
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(1.2));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(0.0));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(-0.0f));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(-1.2f));
//    ASSERT_EQUAL(variableCompareTo.compareTo(MIN_VALUE), -9999);
    ASSERT_EQUAL(0, variableCompareTo.compareTo(NEGATIVE_INFINITY));

    // Test MAX_VALUE
//    variableCompareTo = MAX_VALUE;
//    ASSERT_EQUAL(variableCompareTo.compareTo(NaN_NUMBER), -9999);
//    ASSERT_EQUAL(variableCompareTo.compareTo(POSITIVE_INFINITY), -9999);
//    ASSERT_EQUAL(variableCompareTo.compareTo(MAX_VALUE));
//    ASSERT_EQUAL(variableCompareTo.compareTo(1.2));
//    ASSERT_EQUAL(variableCompareTo.compareTo(0.0));
//    ASSERT_EQUAL(variableCompareTo.compareTo(-0.0));
//    ASSERT_EQUAL(variableCompareTo.compareTo(-1.2));
//    ASSERT_EQUAL(variableCompareTo.compareTo(MIN_VALUE));
//    ASSERT_EQUAL(variableCompareTo.compareTo(NEGATIVE_INFINITY), -9999);

    // Test MIN_VALUE
    variableCompareTo = MIN_VALUE;
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(NaN_NUMBER));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableCompareTo.compareTo(MAX_VALUE));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(1.2));
//    ASSERT_EQUAL(variableCompareTo.compareTo(0.0));
//    ASSERT_EQUAL(variableCompareTo.compareTo(-0.0));
//    ASSERT_EQUAL(variableCompareTo.compareTo(-1.2));
    ASSERT_EQUAL(0, variableCompareTo.compareTo(MIN_VALUE));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(NEGATIVE_INFINITY));

    // Test value 1.2
    variableCompareTo = 1.2;
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(NaN_NUMBER));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableCompareTo.compareTo(MAX_VALUE));
    ASSERT_EQUAL(0, variableCompareTo.compareTo(1.2));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(0.0));
//    ASSERT_EQUAL(variableCompareTo.compareTo(-0.0));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(-1.2f));
//    ASSERT_EQUAL(variableCompareTo.compareTo(MIN_VALUE));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(NEGATIVE_INFINITY));

    // Test value 0.0
    variableCompareTo = 0.0;
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(NaN_NUMBER));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableCompareTo.compareTo(MAX_VALUE));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(1.2));
    ASSERT_EQUAL(0, variableCompareTo.compareTo(0.0));
//    ASSERT_EQUAL(variableCompareTo.compareTo(-0.0)); // error in OSX
    ASSERT_EQUAL(1, variableCompareTo.compareTo(-1.2f));
//    ASSERT_EQUAL(variableCompareTo.compareTo(MIN_VALUE));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(NEGATIVE_INFINITY));

    // Test value -0.0
    variableCompareTo = -0.0;
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(NaN_NUMBER));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableCompareTo.compareTo(MAX_VALUE));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(1.2));
    ASSERT_EQUAL(0, variableCompareTo.compareTo(0.0));  // error in OSX
    ASSERT_EQUAL(0, variableCompareTo.compareTo(-0.0f));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(-1.2f));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(MIN_VALUE));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(NEGATIVE_INFINITY));

    // Test value -1.2
    variableCompareTo = -1.2;
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(NaN_NUMBER));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(POSITIVE_INFINITY));
//    ASSERT_EQUAL(variableCompareTo.compareTo(MAX_VALUE));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(1.2));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(0.0));
    ASSERT_EQUAL(-1, variableCompareTo.compareTo(-0.0));
    ASSERT_EQUAL(0, variableCompareTo.compareTo(-1.2f));
//    ASSERT_EQUAL(variableCompareTo.compareTo(MIN_VALUE));
    ASSERT_EQUAL(1, variableCompareTo.compareTo(NEGATIVE_INFINITY));
}

TEST(JavaLang, FloatByteValue) {
    // Create variable to test
    Float variableTestByteValue;
    byte expectedResultByteValue;
    byte actualResultByteValue;

    // Test POSITIVE_INFINITY
    variableTestByteValue = POSITIVE_INFINITY;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue , actualResultByteValue);

    // Test NEGATIVE_INFINITY
    variableTestByteValue = NEGATIVE_INFINITY;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue , actualResultByteValue);

    //// Error in OSX
//    // Test NaN_NUMBER
//    variableTestByteValue = NaN_NUMBER;
//    expectedResultByteValue = 45;  // 110 in MacOS
//    actualResultByteValue = variableTestByteValue.byteValue();
//    ASSERT_EQUAL(expectedResultByteValue , actualResultByteValue);

    // Test MAX_VALUE
    variableTestByteValue = MAX_VALUE;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue , actualResultByteValue);

    // Test MIN_NORMAL
    variableTestByteValue = MIN_NORMAL;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    ASSERT_EQUAL(expectedResultByteValue , actualResultByteValue);

    // Test MIN_VALUE
    variableTestByteValue = MIN_VALUE;
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