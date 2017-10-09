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

#include "../../../kernel/Test.hpp"
#include "Double.hpp"
using namespace Java::Lang;

TEST(JavaLang, DoubleConstructor) {
    // Test Double::Double()
    Double emptyDoubleConstructor;
    emptyDoubleConstructor = 13.02;
    ASSERT_DBL_NEAR(13.02, emptyDoubleConstructor.doubleValue());

    // Test Double::Double(double original)
    Double validDoubleConstructor = 13.02;
    ASSERT_DBL_NEAR(13.02, validDoubleConstructor.doubleValue());

    // Test Double::Double(const Double &doubleNumber)
    Double DoubleConstructor(validDoubleConstructor);
    ASSERT_DBL_NEAR(13.02, validDoubleConstructor.doubleValue());
}

TEST(JavaLang, DoubleArithmeticOperator) {
	// Create variable to test
	Double variableArithmeticOperator1;
	Double variableArithmeticOperator2;
	Double expectedResultOperator;
	Double actualResultOperator;
	
	// Test Operator +
	variableArithmeticOperator1 = 11.11;
	variableArithmeticOperator2 = 22.22;
	expectedResultOperator = 33.33;
	actualResultOperator = variableArithmeticOperator1 + variableArithmeticOperator2;
	ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());
	
	// Test Operator -
	variableArithmeticOperator1 = 33.33;
	variableArithmeticOperator2 = 22.22;
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
	variableArithmeticOperator1 = 26.04;
	variableArithmeticOperator2 = 2.0;
	expectedResultOperator = 13.02;
	actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
	ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());
	
	// Test Operator / . POSITIVE_INFINITY_DOUBLE
	variableArithmeticOperator1 = 26.04;
	variableArithmeticOperator2 = 0;
	expectedResultOperator = POSITIVE_INFINITY_DOUBLE;
	actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
	ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());
	
	// Test Operator / . NEGATIVE_INFINITY_DOUBLE
	variableArithmeticOperator1 = -26.04;
	variableArithmeticOperator2 = 0;
	expectedResultOperator = NEGATIVE_INFINITY_DOUBLE;
	actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
	ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());
	
	// Test Operator / . NaN_NUMBER_DOUBLE
	variableArithmeticOperator1 = 0;
	variableArithmeticOperator2 = 0;
	expectedResultOperator = NaN_NUMBER_DOUBLE;
	actualResultOperator = variableArithmeticOperator1 / variableArithmeticOperator2;
	ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());
}

TEST(JavaLang, DoubleRelationalOperator) {
	// Test Operator ==
	assertTrue((Double) 13.02 == (Double) 13.02);
	assertFalse((Double) 13.03 == (Double) 13.02);
	
	// Test Operator !=
	assertTrue((Double) 13.02 != (Double) 20.31);
	assertFalse((Double) 13.02 != (Double) 13.02);
	
	// Test Operator >
	assertTrue((Double) 20.31 > (Double) 13.02);
	assertFalse((Double) 13.02 > (Double) 13.02);
	assertFalse((Double) 13.02 > (Double) 20.31);
	
	// Test Operator <
	assertTrue((Double) 13.02 < (Double) 20.31);
	assertFalse((Double) 13.02 < (Double) 13.02);
	assertFalse((Double) 20.31 < (Double) 13.02);
	
	// Test Operator >=
	assertTrue((Double) 33.33 >= (Double) 22.22);
	assertTrue((Double) 33.33 >= (Double) 33.33);
	assertFalse((Double) 13.02 >= (Double) 20.31);
	
	// Test Operator <=
	assertTrue((Double) 22.22 <= (Double) 33.33);
	assertTrue((Double) 22.22 <= (Double) 22.22);
	assertFalse((Double) 20.31 <= (Double) 13.02);
}

TEST(JavaLang, DoubleLogicalOperator) {
	// Test Operator && . Case 0   0
	assertFalse((Double)0 && (Double)0);
	
	// Test Operator && . Case 0   1
	assertFalse((Double)0 && (Double)1);
	
	// Test Operator && . Case 1   0
	assertFalse((Double)1 && (Double)0);
	
	// Test Operator && . Case 1   1
	assertTrue((Double)1 && (Double)1);
	
	// Test Operator || . Case 0   0
	assertFalse((Double)0 || (Double)0);
	
	// Test Operator || . Case 0   1
	assertTrue((Double)0 || (Double)1);
	
	// Test Operator || . Case 1   0
	assertTrue((Double)1 || (Double)0);
	
	// Test Operator || . Case 1   1
	assertTrue((Double)1 || (Double)1);
}

TEST(JavaLang, DoubleAssignmentOperator) {
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
	variableAssignmentOperator1 = 11.11;
	variableAssignmentOperator2 = 22.22;
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
	variableAssignmentOperator1 = 13.02;
	variableAssignmentOperator2 = 2.0;
	expectedResultOperator = 26.04;
	actualResultOperator = (variableAssignmentOperator1 *= variableAssignmentOperator2);
	ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());
	
	// Test Operator /=
	variableAssignmentOperator1 = 26.04;
	variableAssignmentOperator2 = 2.0;
	expectedResultOperator = 13.02;
	actualResultOperator = (variableAssignmentOperator1 /= variableAssignmentOperator2);
	ASSERT_DBL_NEAR(expectedResultOperator.doubleValue(), actualResultOperator.doubleValue());
}

TEST(JavaLang, DoubleParseDouble) {
	string stringInput;
	Double expectedResult;
	Double actualResult;
	
	stringInput = (string) "1302.12345678";
	expectedResult = 1302.12345678;
	actualResult = Double::parseDouble(stringInput);
	ASSERT_DBL_NEAR(expectedResult.doubleValue(), actualResult.doubleValue());
	
	stringInput = (string) "-1302.12345678";
	expectedResult = -1302.12345678;
	actualResult = Double::parseDouble(stringInput);
	ASSERT_DBL_NEAR(expectedResult.doubleValue(), actualResult.doubleValue());
}

TEST(JavaLang, DoubleValueOfWithStringInput) {
	string stringInput;
	Double expectedResult;
	Double actualResult;
	
	stringInput = (string) "1302.12345678";
	expectedResult = 1302.12345678;
	actualResult = Double::valueOf(stringInput);
	ASSERT_DBL_NEAR(expectedResult.doubleValue(), actualResult.doubleValue());
	
	stringInput = (string) "-1302.12345678";
	expectedResult = -1302.12345678;
	actualResult = Double::valueOf(stringInput);
	ASSERT_DBL_NEAR(expectedResult.doubleValue(), actualResult.doubleValue());
}

TEST(JavaLang, DoubleValueOfWithDoubleInput) {
	double doubleInput;
	Double expectedResult;
	Double actualResult;
	
	doubleInput = 1302.12345678;
	expectedResult = 1302.12345678;
	actualResult = Double::valueOf(doubleInput);
	ASSERT_DBL_NEAR(expectedResult.doubleValue(), actualResult.doubleValue());
	
	doubleInput = -1302.12345678;
	expectedResult = -1302.12345678;
	actualResult = Double::valueOf(doubleInput);
	ASSERT_DBL_NEAR(expectedResult.doubleValue(), actualResult.doubleValue());
}

TEST(JavaLang, DoubleToString) {
	// Create variable to test
	Double variableTestToString;
	string expectedResultToString;
	string actualResultToString;
	
	// Test POSITIVE_INFINITY_DOUBLE
	variableTestToString = POSITIVE_INFINITY_DOUBLE;
	expectedResultToString = (string) "inf";
	actualResultToString = variableTestToString.toString();
	assertEquals(expectedResultToString , actualResultToString);
	
	// Test NEGATIVE_INFINITY_DOUBLE
	variableTestToString = NEGATIVE_INFINITY_DOUBLE;
	expectedResultToString = (string) "-inf";
	actualResultToString = variableTestToString.toString();
	assertEquals(expectedResultToString , actualResultToString);


//    // Test NaN_NUMBER_DOUBLE
//    variableTestToString = NaN_NUMBER_DOUBLE;
//    expectedResultToString = "-nan";  // "nan" in MacOS
//    actualResultToString = variableTestToString.toString();
//    assertEquals(expectedResultToString , actualResultToString);
// free(actualResultToString);

    // Test MAX_VALUE_DOUBLE
    variableTestToString = MAX_VALUE_DOUBLE;
    expectedResultToString = (string) "1.797693134862316e+308";
    actualResultToString = variableTestToString.toString();
    assertEquals(expectedResultToString , actualResultToString);

    // Test MIN_NORMAL_DOUBLE
    variableTestToString = MIN_NORMAL_DOUBLE;
    expectedResultToString = (string) "4.940656458412465e-324";
    actualResultToString = variableTestToString.toString();
    assertEquals(expectedResultToString , actualResultToString);

    // Test MIN_VALUE_DOUBLE
    variableTestToString = MIN_VALUE_DOUBLE;
    expectedResultToString = (string) "2.225073858507201e-308";
    actualResultToString = variableTestToString.toString();
    assertEquals(expectedResultToString , actualResultToString);
}

TEST(JavaLang, DoubleCharValue) {
	// Create variable to test
	Double variableTestCharValue;
	char expectedResultCharValue;
	char actualResultCharValue;
	
	// Test POSITIVE_INFINITY_DOUBLE
	variableTestCharValue = POSITIVE_INFINITY_DOUBLE;
	expectedResultCharValue = 'i';
	actualResultCharValue = variableTestCharValue.charValue();
	assertEquals(expectedResultCharValue , actualResultCharValue);
	
	// Test NEGATIVE_INFINITY_DOUBLE
	variableTestCharValue = NEGATIVE_INFINITY_DOUBLE;
	expectedResultCharValue = '-';
	actualResultCharValue = variableTestCharValue.charValue();
	assertEquals(expectedResultCharValue , actualResultCharValue);

//    // Test NaN_NUMBER_DOUBLE
//    variableTestCharValue = NaN_NUMBER_DOUBLE;
//    expectedResultCharValue = 45;  // 110 in MacOS
//    actualResultCharValue = variableTestCharValue.charValue();
//    assertEquals(expectedResultCharValue , actualResultCharValue);
	
	// Test MAX_VALUE_DOUBLE
	variableTestCharValue = MAX_VALUE_DOUBLE;
	expectedResultCharValue = '1';
	actualResultCharValue = variableTestCharValue.charValue();
	assertEquals(expectedResultCharValue , actualResultCharValue);
	
	// Test MIN_NORMAL_DOUBLE
	variableTestCharValue = MIN_NORMAL_DOUBLE;
	expectedResultCharValue = '4';
	actualResultCharValue = variableTestCharValue.charValue();
	assertEquals(expectedResultCharValue , actualResultCharValue);
	
	// Test MIN_VALUE_DOUBLE
	variableTestCharValue = MIN_VALUE_DOUBLE;
	expectedResultCharValue = '2';
	actualResultCharValue = variableTestCharValue.charValue();
	assertEquals(expectedResultCharValue , actualResultCharValue);
	
	// Test valid case
	variableTestCharValue = 13.02;
	expectedResultCharValue = '1';
	actualResultCharValue = variableTestCharValue.charValue();
	assertEquals(expectedResultCharValue , actualResultCharValue);
	
	// Test valid case
	variableTestCharValue = 20.31;
	expectedResultCharValue = '2';
	actualResultCharValue = variableTestCharValue.charValue();
	assertEquals(expectedResultCharValue , actualResultCharValue);
	
	// Test invalid case
	variableTestCharValue = 13.02;
	expectedResultCharValue = '5';
	actualResultCharValue = variableTestCharValue.charValue();
	assertNotEquals(expectedResultCharValue , actualResultCharValue);
}

TEST(JavaLang, DoubleStringValue) {
	// Create variable to test
	Double variableTestStringValue;
	string expectedResultStringValue;
	string actualResultStringValue;
	
	// Test POSITIVE_INFINITY_DOUBLE
	variableTestStringValue = POSITIVE_INFINITY_DOUBLE;
	expectedResultStringValue = (string) "inf";
	actualResultStringValue = variableTestStringValue.stringValue();
	assertEquals(expectedResultStringValue , actualResultStringValue);
	
	// Test NEGATIVE_INFINITY_DOUBLE
	variableTestStringValue = NEGATIVE_INFINITY_DOUBLE;
	expectedResultStringValue = (string) "-inf";
	actualResultStringValue = variableTestStringValue.stringValue();
	assertEquals(expectedResultStringValue , actualResultStringValue);

//    // Test NaN_NUMBER_DOUBLE
//    variableTestStringValue = NaN_NUMBER_DOUBLE;
//    expectedResultStringValue = "-nan";  // "nan" in MacOS
//    actualResultStringValue = variableTestStringValue.stringValue();
//    assertEquals(expectedResultStringValue , actualResultStringValue);
//    free(actualResultStringValue);
	
	// Test MAX_VALUE_DOUBLE
	variableTestStringValue = MAX_VALUE_DOUBLE;
	expectedResultStringValue = (string) "1.797693134862316e+308";
	actualResultStringValue = variableTestStringValue.stringValue();
	assertEquals(expectedResultStringValue , actualResultStringValue);
	
	// Test MIN_NORMAL_DOUBLE
	variableTestStringValue = MIN_NORMAL_DOUBLE;
	expectedResultStringValue = (string) "4.940656458412465e-324";
	actualResultStringValue = variableTestStringValue.stringValue();
	assertEquals(expectedResultStringValue , actualResultStringValue);
	
	// Test MIN_VALUE_DOUBLE
	variableTestStringValue = MIN_VALUE_DOUBLE;
	expectedResultStringValue = (string) "2.225073858507201e-308";
	actualResultStringValue = variableTestStringValue.stringValue();
	assertEquals(expectedResultStringValue , actualResultStringValue);
}

TEST(JavaLang, DoubleShortValue) {
	// Create variable to test
	Double variableTestShortValue;
	short expectedResultShortValue;
	short actualResultShortValue;
	
	// Test POSITIVE_INFINITY_DOUBLE
	variableTestShortValue = POSITIVE_INFINITY_DOUBLE;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	assertEquals(expectedResultShortValue , actualResultShortValue);
	
	// Test NEGATIVE_INFINITY_DOUBLE
	variableTestShortValue = NEGATIVE_INFINITY_DOUBLE;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	assertEquals(expectedResultShortValue , actualResultShortValue);
	
	// Test NaN_NUMBER_DOUBLE
	variableTestShortValue = NaN_NUMBER_DOUBLE;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	assertEquals(expectedResultShortValue , actualResultShortValue);
	
	// Test MAX_VALUE_DOUBLE
	variableTestShortValue = MAX_VALUE_DOUBLE;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	assertEquals(expectedResultShortValue , actualResultShortValue);
	
	// Test MIN_NORMAL_DOUBLE
	variableTestShortValue = MIN_NORMAL_DOUBLE;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	assertEquals(expectedResultShortValue , actualResultShortValue);
	
	// Test MIN_VALUE_DOUBLE
	variableTestShortValue = MIN_VALUE_DOUBLE;
	expectedResultShortValue = 0;
	actualResultShortValue = variableTestShortValue.shortValue();
	assertEquals(expectedResultShortValue , actualResultShortValue);
	
	// Test valid case
	variableTestShortValue = 5.9;
	expectedResultShortValue = 5;
	actualResultShortValue = variableTestShortValue.shortValue();
	assertEquals(expectedResultShortValue , actualResultShortValue);
	
	// Test valid case
	variableTestShortValue = 5.4;
	expectedResultShortValue = 5;
	actualResultShortValue = variableTestShortValue.shortValue();
	assertEquals(expectedResultShortValue , actualResultShortValue);
	
	// Test invalid case
	variableTestShortValue = 6;
	expectedResultShortValue = 5;
	actualResultShortValue = variableTestShortValue.shortValue();
	assertNotEquals(expectedResultShortValue , actualResultShortValue);
}


TEST(JavaLang, DoubleIntValue) {
	// Create variable to test
	Double variableTestIntValue;
	int expectedResultIntValue;
	int actualResultIntValue;
	
	// Test POSITIVE_INFINITY_DOUBLE
	variableTestIntValue = POSITIVE_INFINITY_DOUBLE;
	expectedResultIntValue = -2147483648;
	actualResultIntValue = variableTestIntValue.intValue();
	assertEquals(expectedResultIntValue , actualResultIntValue);
	
	// Test NEGATIVE_INFINITY_DOUBLE
	variableTestIntValue = NEGATIVE_INFINITY_DOUBLE;
	expectedResultIntValue = -2147483648;
	actualResultIntValue = variableTestIntValue.intValue();
	assertEquals(expectedResultIntValue , actualResultIntValue);
	
	// Test NaN_NUMBER_DOUBLE
	variableTestIntValue = NaN_NUMBER_DOUBLE;
	expectedResultIntValue = -2147483648;
	actualResultIntValue = variableTestIntValue.intValue();
	assertEquals(expectedResultIntValue , actualResultIntValue);
	
	// Test MAX_VALUE_DOUBLE
	variableTestIntValue = MAX_VALUE_DOUBLE;
	expectedResultIntValue = -2147483648;
	actualResultIntValue = variableTestIntValue.intValue();
	assertEquals(expectedResultIntValue , actualResultIntValue);
	
	// Test MIN_NORMAL_DOUBLE
	variableTestIntValue = MIN_NORMAL_DOUBLE;
	expectedResultIntValue = 0;
	actualResultIntValue = variableTestIntValue.intValue();
	assertEquals(expectedResultIntValue , actualResultIntValue);
	
	// Test MIN_VALUE_DOUBLE
	variableTestIntValue = MIN_VALUE_DOUBLE;
	expectedResultIntValue = 0;
	actualResultIntValue = variableTestIntValue.intValue();
	assertEquals(expectedResultIntValue , actualResultIntValue);
	
	// Test valid case
	variableTestIntValue = 5.9;
	expectedResultIntValue = 5;
	actualResultIntValue = variableTestIntValue.intValue();
	assertEquals(expectedResultIntValue , actualResultIntValue);
	
	// Test valid case
	variableTestIntValue = 5.4;
	expectedResultIntValue = 5;
	actualResultIntValue = variableTestIntValue.intValue();
	assertEquals(expectedResultIntValue , actualResultIntValue);
	
	// Test invalid case
	variableTestIntValue = 6;
	expectedResultIntValue = 5;
	actualResultIntValue = variableTestIntValue.intValue();
	assertNotEquals(expectedResultIntValue , actualResultIntValue);
}

TEST(JavaLang, DoubleLongValue) {
    // Create variable to test
    Double variableTestLongValue;
    long expectedResultLongValue;
    long actualResultLongValue;

    // Test POSITIVE_INFINITY_DOUBLE
    variableTestLongValue = POSITIVE_INFINITY_DOUBLE;
    expectedResultLongValue = -9223372036854775808u;
    actualResultLongValue = variableTestLongValue.longValue();
    assertEquals(expectedResultLongValue , actualResultLongValue);

    // Test NEGATIVE_INFINITY_DOUBLE
    variableTestLongValue = NEGATIVE_INFINITY_DOUBLE;
    expectedResultLongValue = -9223372036854775808u;
    actualResultLongValue = variableTestLongValue.longValue();
    assertEquals(expectedResultLongValue , actualResultLongValue);

    // Test NaN_NUMBER_DOUBLE
    variableTestLongValue = NaN_NUMBER_DOUBLE;
    expectedResultLongValue = -9223372036854775808u;
    actualResultLongValue = variableTestLongValue.longValue();
    assertEquals(expectedResultLongValue , actualResultLongValue);

    // Test MAX_VALUE_DOUBLE
    variableTestLongValue = MAX_VALUE_DOUBLE;
    expectedResultLongValue = -9223372036854775808u;
    actualResultLongValue = variableTestLongValue.longValue();
    assertEquals(expectedResultLongValue , actualResultLongValue);

    // Test MIN_NORMAL_DOUBLE
    variableTestLongValue = MIN_NORMAL_DOUBLE;
    expectedResultLongValue = 0;
    actualResultLongValue = variableTestLongValue.longValue();
    assertEquals(expectedResultLongValue , actualResultLongValue);

    // Test MIN_VALUE_DOUBLE
    variableTestLongValue = MIN_VALUE_DOUBLE;
    expectedResultLongValue = 0;
    actualResultLongValue = variableTestLongValue.longValue();
    assertEquals(expectedResultLongValue , actualResultLongValue);

    // Test valid case
    variableTestLongValue = 5.9;
    expectedResultLongValue = 5;
    actualResultLongValue = variableTestLongValue.longValue();
    assertEquals(expectedResultLongValue , actualResultLongValue);

    // Test valid case
    variableTestLongValue = 5.4;
    expectedResultLongValue = 5;
    actualResultLongValue = variableTestLongValue.longValue();
    assertEquals(expectedResultLongValue , actualResultLongValue);

    // Test invalid case
    variableTestLongValue = 6;
    expectedResultLongValue = 5;
    actualResultLongValue = variableTestLongValue.longValue();
    assertNotEquals(expectedResultLongValue , actualResultLongValue);
}

TEST(JavaLang, DoubleFloatValue) {
    // Create variable to test
    Double variableTestFloatValue;
    float expectedResultFloatValue;
    float actualResultFloatValue;

    // Test POSITIVE_INFINITY_DOUBLE
    variableTestFloatValue = POSITIVE_INFINITY_DOUBLE;
    expectedResultFloatValue = static_cast<float> (1.0 / 0.0);
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_DBL_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test NEGATIVE_INFINITY_DOUBLE
    variableTestFloatValue = NEGATIVE_INFINITY_DOUBLE;
    expectedResultFloatValue = static_cast<float> (-1.0/0.0);
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_DBL_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test NaN_NUMBER_DOUBLE
    variableTestFloatValue = NaN_NUMBER_DOUBLE;
    expectedResultFloatValue = static_cast<float> (0.0/0.0);
    actualResultFloatValue = variableTestFloatValue.floatValue();
    ASSERT_DBL_NEAR(expectedResultFloatValue , actualResultFloatValue);

    // Test MAX_VALUE_DOUBLE
    variableTestFloatValue = MAX_VALUE_DOUBLE;
    expectedResultFloatValue = static_cast<float> (1.0/0.0);
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


TEST(JavaLang, DoubleDoubleValue) {
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
	
	// Test NaN_NUMBER_DOUBLE
	variableTestDoubleValue = NaN_NUMBER_DOUBLE;
	expectedResultDoubleValue = NaN_NUMBER_DOUBLE;
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

TEST(JavaLang, DoubleByteValue) {
	// Create variable to test
	Double variableTestByteValue;
	byte expectedResultByteValue;
	byte actualResultByteValue;
	
	// Test POSITIVE_INFINITY_DOUBLE
	variableTestByteValue = POSITIVE_INFINITY_DOUBLE;
	expectedResultByteValue = 0;
	actualResultByteValue = variableTestByteValue.byteValue();
	assertEquals(expectedResultByteValue , actualResultByteValue);
	
	// Test NEGATIVE_INFINITY_DOUBLE
	variableTestByteValue = NEGATIVE_INFINITY_DOUBLE;
	expectedResultByteValue = 0;
	actualResultByteValue = variableTestByteValue.byteValue();
	assertEquals(expectedResultByteValue , actualResultByteValue);
	
	//// Error in OSX
//    // Test NaN_NUMBER_DOUBLE
//    variableTestByteValue = NaN_NUMBER_DOUBLE;
//    expectedResultByteValue = 45;  // 110 in MacOS
//    actualResultByteValue = variableTestByteValue.byteValue();
//    assertEquals(expectedResultByteValue , actualResultByteValue);
	
	// Test MAX_VALUE_DOUBLE
	variableTestByteValue = MAX_VALUE_DOUBLE;
	expectedResultByteValue = 0;
	actualResultByteValue = variableTestByteValue.byteValue();
	assertEquals(expectedResultByteValue , actualResultByteValue);
	
	// Test MIN_NORMAL_DOUBLE
	variableTestByteValue = MIN_NORMAL_DOUBLE;
	expectedResultByteValue = 0;
	actualResultByteValue = variableTestByteValue.byteValue();
	assertEquals(expectedResultByteValue , actualResultByteValue);
	
	// Test MIN_VALUE_DOUBLE
	variableTestByteValue = MIN_VALUE_DOUBLE;
	expectedResultByteValue = 0;
	actualResultByteValue = variableTestByteValue.byteValue();
	assertEquals(expectedResultByteValue , actualResultByteValue);
	
	// Test valid case
	variableTestByteValue = 13.02;
	expectedResultByteValue = 13;
	actualResultByteValue = variableTestByteValue.byteValue();
	assertEquals(expectedResultByteValue , actualResultByteValue);
	
	// Test valid case
	variableTestByteValue = 20.31;
	expectedResultByteValue = 20;
	actualResultByteValue = variableTestByteValue.byteValue();
	assertEquals(expectedResultByteValue , actualResultByteValue);
	
	// Test invalid case
	variableTestByteValue = 13.02;
	expectedResultByteValue = 5;
	actualResultByteValue = variableTestByteValue.byteValue();
	assertNotEquals(expectedResultByteValue , actualResultByteValue);
}

// TODO(thoangminh): Need to pass all test cases in comment block
TEST(JavaLang, DoubleCompare) {
    // Test NaN_NUMBER_DOUBLE
    assertEquals(0, Double::compare(NaN_NUMBER_DOUBLE, NaN_NUMBER_DOUBLE));
    assertEquals(1, Double::compare(NaN_NUMBER_DOUBLE, POSITIVE_INFINITY_DOUBLE));
//    assertEquals(Double::compare(NaN_NUMBER_DOUBLE, MAX_VALUE_DOUBLE));
    assertEquals(1, Double::compare(NaN_NUMBER_DOUBLE, 1.2));
    assertEquals(1, Double::compare(NaN_NUMBER_DOUBLE, 0.0));
    assertEquals(1, Double::compare(NaN_NUMBER_DOUBLE, -0.0));
    assertEquals(1, Double::compare(NaN_NUMBER_DOUBLE, -1.2));
    assertEquals(1, Double::compare(NaN_NUMBER_DOUBLE, MIN_VALUE_DOUBLE));
    assertEquals(1, Double::compare(NaN_NUMBER_DOUBLE, NEGATIVE_INFINITY_DOUBLE));

    // Test POSITIVE_INFINITY_DOUBLE
    assertEquals(-1, Double::compare(POSITIVE_INFINITY_DOUBLE, NaN_NUMBER_DOUBLE));
    assertEquals(0, Double::compare(POSITIVE_INFINITY_DOUBLE, POSITIVE_INFINITY_DOUBLE));
//    assertEquals(Double::compare(POSITIVE_INFINITY_DOUBLE, MAX_VALUE_DOUBLE), -9999);
    assertEquals(1, Double::compare(POSITIVE_INFINITY_DOUBLE, 1.2));
    assertEquals(1, Double::compare(POSITIVE_INFINITY_DOUBLE, 0.0));
    assertEquals(1, Double::compare(POSITIVE_INFINITY_DOUBLE, -0.0));
    assertEquals(1, Double::compare(POSITIVE_INFINITY_DOUBLE, -1.2));
    assertEquals(1, Double::compare(POSITIVE_INFINITY_DOUBLE, MIN_VALUE_DOUBLE));
    assertEquals(1, Double::compare(POSITIVE_INFINITY_DOUBLE, NEGATIVE_INFINITY_DOUBLE));

    // Test NEGATIVE_INFINITY_DOUBLE
    assertEquals(-1, Double::compare(NEGATIVE_INFINITY_DOUBLE, NaN_NUMBER_DOUBLE));
    assertEquals(-1, Double::compare(NEGATIVE_INFINITY_DOUBLE, POSITIVE_INFINITY_DOUBLE));
//    assertEquals(Double::compare(NEGATIVE_INFINITY_DOUBLE, MAX_VALUE_DOUBLE), -9999);
    assertEquals(-1, Double::compare(NEGATIVE_INFINITY_DOUBLE, 1.2));
    assertEquals(-1, Double::compare(NEGATIVE_INFINITY_DOUBLE, 0.0));
    assertEquals(-1, Double::compare(NEGATIVE_INFINITY_DOUBLE, -0.0));
    assertEquals(-1, Double::compare(NEGATIVE_INFINITY_DOUBLE, -1.2));
    assertEquals(-1, Double::compare(NEGATIVE_INFINITY_DOUBLE, MIN_VALUE_DOUBLE));
    assertEquals(0, Double::compare(NEGATIVE_INFINITY_DOUBLE, NEGATIVE_INFINITY_DOUBLE));

//    // Test MAX_VALUE_DOUBLE
//    assertEquals(Double::compare(MAX_VALUE_DOUBLE, NaN_NUMBER_DOUBLE), -9999);
//    assertEquals(Double::compare(MAX_VALUE_DOUBLE, POSITIVE_INFINITY_DOUBLE), -9999);
//    assertEquals(Double::compare(MAX_VALUE_DOUBLE, MAX_VALUE_DOUBLE));
//    assertEquals(Double::compare(MAX_VALUE_DOUBLE, 1.2));
//    assertEquals(Double::compare(MAX_VALUE_DOUBLE, 0.0));
//    assertEquals(Double::compare(MAX_VALUE_DOUBLE, -0.0));
//    assertEquals(Double::compare(MAX_VALUE_DOUBLE, -1.2));
//    assertEquals(Double::compare(MAX_VALUE_DOUBLE, MIN_VALUE_DOUBLE));
//    assertEquals(Double::compare(MAX_VALUE_DOUBLE, NEGATIVE_INFINITY_DOUBLE), -9999);

    // Test MIN_VALUE_DOUBLE
    assertEquals(-1, Double::compare(MIN_VALUE_DOUBLE, NaN_NUMBER_DOUBLE));
    assertEquals(-1, Double::compare(MIN_VALUE_DOUBLE, POSITIVE_INFINITY_DOUBLE));
//    assertEquals(Double::compare(MIN_VALUE_DOUBLE, MAX_VALUE_DOUBLE));
    assertEquals(-1, Double::compare(MIN_VALUE_DOUBLE, 1.2));
    assertEquals(1, Double::compare(MIN_VALUE_DOUBLE, 0.0));
    assertEquals(1, Double::compare(MIN_VALUE_DOUBLE, -0.0));
    assertEquals(1, Double::compare(MIN_VALUE_DOUBLE, -1.2));
    assertEquals(0, Double::compare(MIN_VALUE_DOUBLE, MIN_VALUE_DOUBLE));
    assertEquals(1, Double::compare(MIN_VALUE_DOUBLE, NEGATIVE_INFINITY_DOUBLE));

    // Test value 1.2
    assertEquals(-1, Double::compare(1.2, NaN_NUMBER_DOUBLE));
    assertEquals(-1, Double::compare(1.2, POSITIVE_INFINITY_DOUBLE));
//    assertEquals(Double::compare(1.2, MAX_VALUE_DOUBLE));
    assertEquals(0, Double::compare(1.2, 1.2));
    assertEquals(1, Double::compare(1.2, 0.0));
    assertEquals(1, Double::compare(1.2, -0.0));
    assertEquals(1, Double::compare(1.2, -1.2));
    assertEquals(1, Double::compare(1.2, MIN_VALUE_DOUBLE));
    assertEquals(1, Double::compare(1.2, NEGATIVE_INFINITY_DOUBLE));

    // Test value 0.0
    assertEquals(-1, Double::compare(0.0, NaN_NUMBER_DOUBLE));
    assertEquals(-1, Double::compare(0.0, POSITIVE_INFINITY_DOUBLE));
//    assertEquals(Double::compare(0.0, MAX_VALUE_DOUBLE));
    assertEquals(-1, Double::compare(0.0, 1.2));
    assertEquals(0, Double::compare(0.0, 0.0));
    assertEquals(0, Double::compare(0.0, -0.0));  // error in OSX
    assertEquals(1, Double::compare(0.0, -1.2));
    assertEquals(-1, Double::compare(0.0, MIN_VALUE_DOUBLE));
    assertEquals(1, Double::compare(0.0, NEGATIVE_INFINITY_DOUBLE));

    // Test value -0.0
    assertEquals(-1, Double::compare(-0.0, NaN_NUMBER_DOUBLE));
    assertEquals(-1, Double::compare(-0.0, POSITIVE_INFINITY_DOUBLE));
//    assertEquals(Double::compare(-0.0, MAX_VALUE_DOUBLE));
    assertEquals(-1, Double::compare(-0.0, 1.2));
    assertEquals(0, Double::compare(-0.0, 0.0));  // error in OSX
    assertEquals(0, Double::compare(-0.0, -0.0));  // error in OSX
    assertEquals(1, Double::compare(-0.0, -1.2));
    assertEquals(-1, Double::compare(-0.0, MIN_VALUE_DOUBLE));
    assertEquals(1, Double::compare(-0.0, NEGATIVE_INFINITY_DOUBLE));

    // Test value -1.2
    assertEquals(-1, Double::compare(-1.2, NaN_NUMBER_DOUBLE));
    assertEquals(-1, Double::compare(-1.2, POSITIVE_INFINITY_DOUBLE));
//    assertEquals(Double::compare(-1.2, MAX_VALUE_DOUBLE));
    assertEquals(-1, Double::compare(-1.2, 1.2));
    assertEquals(-1, Double::compare(-1.2, 0.0));
    assertEquals(-1, Double::compare(-1.2, -0.0));
    assertEquals(0, Double::compare(-1.2, -1.2));
    assertEquals(-1, Double::compare(-1.2, MIN_VALUE_DOUBLE));
    assertEquals(1, Double::compare(-1.2, NEGATIVE_INFINITY_DOUBLE));
}

TEST(JavaLang, DoubleCompareTo) {
	Double variableCompareTo;
	
	// Test NaN_NUMBER_DOUBLE
	variableCompareTo = NaN_NUMBER_DOUBLE;
	assertEquals(0, variableCompareTo.compareTo(NaN_NUMBER_DOUBLE));
	assertEquals(1, variableCompareTo.compareTo(POSITIVE_INFINITY_DOUBLE));
//    assertEquals(variableCompareTo.compareTo(MAX_VALUE_DOUBLE), -9999);
    assertEquals(1, variableCompareTo.compareTo(1.2));
    assertEquals(1, variableCompareTo.compareTo(0.0));
    assertEquals(1, variableCompareTo.compareTo(-0.0));
    assertEquals(1, variableCompareTo.compareTo(-1.2));
//    assertEquals(variableCompareTo.compareTo(MIN_VALUE_DOUBLE), -9999);
	assertEquals(1, variableCompareTo.compareTo(NEGATIVE_INFINITY_DOUBLE));
	
	// Test POSITIVE_INFINITY_DOUBLE
	variableCompareTo = POSITIVE_INFINITY_DOUBLE;
	assertEquals(-1, variableCompareTo.compareTo(NaN_NUMBER_DOUBLE));
	assertEquals(0, variableCompareTo.compareTo(POSITIVE_INFINITY_DOUBLE));
//    assertEquals(variableCompareTo.compareTo( MAX_VALUE_DOUBLE), -9999);
    assertEquals(1, variableCompareTo.compareTo(1.2));
    assertEquals(1, variableCompareTo.compareTo(0.0));
    assertEquals(1, variableCompareTo.compareTo(-0.0));
    assertEquals(1, variableCompareTo.compareTo(-1.2));
//    assertEquals(variableCompareTo.compareTo(MIN_VALUE_DOUBLE), -9999);
	assertEquals(1, variableCompareTo.compareTo(NEGATIVE_INFINITY_DOUBLE));
	
	// Test NEGATIVE_INFINITY_DOUBLE
	variableCompareTo = NEGATIVE_INFINITY_DOUBLE;
	assertEquals(-1, variableCompareTo.compareTo(NaN_NUMBER_DOUBLE));
	assertEquals(-1, variableCompareTo.compareTo(POSITIVE_INFINITY_DOUBLE));
//    assertEquals(variableCompareTo.compareTo(MAX_VALUE_DOUBLE), -9999);
    assertEquals(-1, variableCompareTo.compareTo(1.2));
    assertEquals(-1, variableCompareTo.compareTo(0.0));
    assertEquals(-1, variableCompareTo.compareTo(-0.0));
    assertEquals(-1, variableCompareTo.compareTo(-1.2));
//    assertEquals(variableCompareTo.compareTo(MIN_VALUE_DOUBLE), -9999);
	assertEquals(0, variableCompareTo.compareTo(NEGATIVE_INFINITY_DOUBLE));
	
	// Test MAX_VALUE_DOUBLE
//    variableCompareTo = MAX_VALUE_DOUBLE;
//    assertEquals(variableCompareTo.compareTo(NaN_NUMBER_DOUBLE), -9999);
//    assertEquals(variableCompareTo.compareTo(POSITIVE_INFINITY_DOUBLE), -9999);
//    assertEquals(variableCompareTo.compareTo(MAX_VALUE_DOUBLE));
//    assertEquals(variableCompareTo.compareTo(1.2));
//    assertEquals(variableCompareTo.compareTo(0.0));
//    assertEquals(variableCompareTo.compareTo(-0.0));
//    assertEquals(variableCompareTo.compareTo(-1.2));
//    assertEquals(variableCompareTo.compareTo(MIN_VALUE_DOUBLE));
//    assertEquals(variableCompareTo.compareTo(NEGATIVE_INFINITY_DOUBLE), -9999);

    // Test MIN_VALUE_DOUBLE
    variableCompareTo = MIN_VALUE_DOUBLE;
    assertEquals(-1, variableCompareTo.compareTo(NaN_NUMBER_DOUBLE));
    assertEquals(-1, variableCompareTo.compareTo(POSITIVE_INFINITY_DOUBLE));
//    assertEquals(variableCompareTo.compareTo(MAX_VALUE_DOUBLE));
    assertEquals(-1, variableCompareTo.compareTo(1.2));
//    assertEquals(variableCompareTo.compareTo(0.0));
//    assertEquals(variableCompareTo.compareTo(-0.0));
//    assertEquals(variableCompareTo.compareTo(-1.2));
    assertEquals(0, variableCompareTo.compareTo(MIN_VALUE_DOUBLE));
    assertEquals(1, variableCompareTo.compareTo(NEGATIVE_INFINITY_DOUBLE));

    // Test value 1.2
    variableCompareTo = 1.2;
    assertEquals(-1, variableCompareTo.compareTo(NaN_NUMBER_DOUBLE));
    assertEquals(-1, variableCompareTo.compareTo(POSITIVE_INFINITY_DOUBLE));
//    assertEquals(variableCompareTo.compareTo(MAX_VALUE_DOUBLE));
	assertEquals(0, variableCompareTo.compareTo(1.2));
	assertEquals(1, variableCompareTo.compareTo(0.0));
//    assertEquals(variableCompareTo.compareTo(-0.0));
	assertEquals(1, variableCompareTo.compareTo(-1.2));
//    assertEquals(variableCompareTo.compareTo(MIN_VALUE_DOUBLE));
	assertEquals(1, variableCompareTo.compareTo(NEGATIVE_INFINITY_DOUBLE));
	
	// Test value 0.0
	variableCompareTo = 0.0;
	assertEquals(-1, variableCompareTo.compareTo(NaN_NUMBER_DOUBLE));
	assertEquals(-1, variableCompareTo.compareTo(POSITIVE_INFINITY_DOUBLE));
//    assertEquals(variableCompareTo.compareTo(MAX_VALUE_DOUBLE));
    assertEquals(-1, variableCompareTo.compareTo(1.2));
    assertEquals(0, variableCompareTo.compareTo(0.0));
//    assertEquals(variableCompareTo.compareTo(-0.0));  // error in OSX
    assertEquals(1, variableCompareTo.compareTo(-1.2));
//    assertEquals(variableCompareTo.compareTo(MIN_VALUE_DOUBLE));
    assertEquals(1, variableCompareTo.compareTo(NEGATIVE_INFINITY_DOUBLE));

    // Test value -0.0
    variableCompareTo = -0.0;
    assertEquals(-1, variableCompareTo.compareTo(NaN_NUMBER_DOUBLE));
    assertEquals(-1, variableCompareTo.compareTo(POSITIVE_INFINITY_DOUBLE));
//    assertEquals(variableCompareTo.compareTo(MAX_VALUE_DOUBLE));
    assertEquals(-1, variableCompareTo.compareTo(1.2));
    assertEquals(0, variableCompareTo.compareTo(0.0));  // error in OSX
    assertEquals(0, variableCompareTo.compareTo(-0.0));
    assertEquals(1, variableCompareTo.compareTo(-1.2));
    assertEquals(-1, variableCompareTo.compareTo(MIN_VALUE_DOUBLE));
    assertEquals(1, variableCompareTo.compareTo(NEGATIVE_INFINITY_DOUBLE));

    // Test value -1.2
    variableCompareTo = -1.2;
    assertEquals(-1, variableCompareTo.compareTo(NaN_NUMBER_DOUBLE));
    assertEquals(-1, variableCompareTo.compareTo(POSITIVE_INFINITY_DOUBLE));
//    assertEquals(variableCompareTo.compareTo(MAX_VALUE_DOUBLE));
    assertEquals(-1, variableCompareTo.compareTo(1.2));
    assertEquals(-1, variableCompareTo.compareTo(0.0));
    assertEquals(-1, variableCompareTo.compareTo(-0.0));
    assertEquals(0, variableCompareTo.compareTo(-1.2));
//    assertEquals(variableCompareTo.compareTo(MIN_VALUE_DOUBLE));
	assertEquals(1, variableCompareTo.compareTo(NEGATIVE_INFINITY_DOUBLE));
}

TEST(JavaLang, DoubleToRawLongBits) {
	// Create variable to test
	double input;
	long expectedResult;
	long actualResult;
	
	// Input 0.0
	input = 0.0;
	expectedResult = 0;
	actualResult = Double::doubleToRawLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input POSITIVE_INFINITY_DOUBLE
	input = POSITIVE_INFINITY_DOUBLE;
	expectedResult = 9218868437227405312;
	actualResult = Double::doubleToRawLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input NEGATIVE_INFINITY_DOUBLE
	input = NEGATIVE_INFINITY_DOUBLE;
	expectedResult = -9218868437227405312;
	actualResult = Double::doubleToRawLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input NaN_NUMBER_DOUBLE
	input = NaN_NUMBER_DOUBLE;
	expectedResult = 9223372036854775807;
	actualResult = Double::doubleToRawLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input -0.7
	input = -0.7;
	expectedResult =  -4604480259023595110;
	actualResult = Double::doubleToRawLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input 12.375
	input = 12.375;
	expectedResult = 4623156123728347136;
	actualResult = Double::doubleToRawLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input 1.0
	input = 1.0;
	expectedResult = 4607182418800017408;
	actualResult = Double::doubleToRawLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input 0.375
	input = 0.375;
	expectedResult = 4600427019358961664;
	actualResult = Double::doubleToRawLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input -2
	input = -2.0;
	expectedResult = -4611686018427387904;
	actualResult = Double::doubleToRawLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input 83
	input = 83.0;
	expectedResult = 4635541022703616000;
	actualResult = Double::doubleToRawLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input -2625
	input = -2625.0;
	expectedResult = -4657990851119546368;
	actualResult = Double::doubleToRawLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input 0.5
	input = 0.5;
	expectedResult = 4602678819172646912;
	actualResult = Double::doubleToRawLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input -1302.12345678
	input = -1302.12345678;
	expectedResult = -4653441614972469831;
	actualResult = Double::doubleToRawLongBits(input);
	assertEquals(expectedResult, actualResult);
}

TEST(JavaLang, DoubleToLongBits) {
	// Create variable to test
	double input;
	long expectedResult;
	long actualResult;
	
	// Input 0.0
	input = 0.0;
	expectedResult = 0;
	actualResult = Double::doubleToLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input POSITIVE_INFINITY_DOUBLE
	input = POSITIVE_INFINITY_DOUBLE;
	expectedResult = 9218868437227405312;
	actualResult = Double::doubleToLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input NEGATIVE_INFINITY_DOUBLE
	input = NEGATIVE_INFINITY_DOUBLE;
	expectedResult = -9218868437227405312;
	actualResult = Double::doubleToLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input NaN_NUMBER_DOUBLE
	input = NaN_NUMBER_DOUBLE;
	expectedResult = 9223372036854775807;
	actualResult = Double::doubleToLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input -0.7
	input = -0.7;
	expectedResult =  -4604480259023595110;
	actualResult = Double::doubleToLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input 12.375
	input = 12.375;
	expectedResult = 4623156123728347136;
	actualResult = Double::doubleToLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input 1.0
	input = 1.0;
	expectedResult = 4607182418800017408;
	actualResult = Double::doubleToLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input 0.375
	input = 0.375;
	expectedResult = 4600427019358961664;
	actualResult = Double::doubleToLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input -2
	input = -2.0;
	expectedResult = -4611686018427387904;
	actualResult = Double::doubleToLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input 83
	input = 83.0;
	expectedResult = 4635541022703616000;
	actualResult = Double::doubleToLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input -2625
	input = -2625.0;
	expectedResult = -4657990851119546368;
	actualResult = Double::doubleToLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input 0.5
	input = 0.5;
	expectedResult = 4602678819172646912;
	actualResult = Double::doubleToLongBits(input);
	assertEquals(expectedResult, actualResult);
	
	// Input -1302.12345678
	input = -1302.12345678;
	expectedResult = -4653441614972469831;
	actualResult = Double::doubleToLongBits(input);
	assertEquals(expectedResult, actualResult);
}

// TODO(thoangminh): Wait for instanceof <> , check later: max, min , -0
TEST(JavaLang, DoubleEquals) {
    // Create variable to test
    Double variableDoubleEquals;
    Double DOUBLE_NaN = NaN_NUMBER_DOUBLE;
    Double DOUBLE_POSITIVE_INFINITY = POSITIVE_INFINITY_DOUBLE;
    Double DOUBLE_NEGATIVE_INFINITY = NEGATIVE_INFINITY_DOUBLE;
    Double DOUBLE_MAX_VALUE = MAX_VALUE_DOUBLE;
    Double DOUBLE_MIN_VALUE = MIN_VALUE_DOUBLE;

    // Test NaN_NUMBER_DOUBLE
    variableDoubleEquals = NaN_NUMBER_DOUBLE;
    assertEquals(1, variableDoubleEquals.equals(DOUBLE_NaN));
    assertEquals(0, variableDoubleEquals.equals(DOUBLE_POSITIVE_INFINITY));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MAX_VALUE));
	assertEquals(0, variableDoubleEquals.equals((Double)1.2));
	assertEquals(0, variableDoubleEquals.equals((Double)0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-0.0));
	assertEquals(0, variableDoubleEquals.equals((Double)-1.2));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MIN_VALUE));
	assertEquals(0, variableDoubleEquals.equals(DOUBLE_NEGATIVE_INFINITY));
	
	// Test DOUBLE_POSITIVE_INFINITY
	variableDoubleEquals = DOUBLE_POSITIVE_INFINITY;
	assertEquals(0, variableDoubleEquals.equals(DOUBLE_NaN));
	assertEquals(1, variableDoubleEquals.equals(DOUBLE_POSITIVE_INFINITY));
//    assertEquals(variableDoubleEquals.equals( DOUBLE_MAX_VALUE), -9999);
	assertEquals(0, variableDoubleEquals.equals((Double)1.2));
	assertEquals(0, variableDoubleEquals.equals((Double)0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-0.0), -9999);
	assertEquals(0, variableDoubleEquals.equals((Double)-1.2));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MIN_VALUE), -9999);
	assertEquals(0, variableDoubleEquals.equals(DOUBLE_NEGATIVE_INFINITY));

//    // Test DOUBLE_MAX_VALUE
//    variableDoubleEquals = DOUBLE_MAX_VALUE;
//    assertEquals(variableDoubleEquals.equals(DOUBLE_NaN));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_POSITIVE_INFINITY));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MAX_VALUE));
//    assertEquals(variableDoubleEquals.equals((Double)1.2));
//    assertEquals(variableDoubleEquals.equals((Double)0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-1.2));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MIN_VALUE));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_NEGATIVE_INFINITY));
//
//    // Test DOUBLE_MIN_VALUE
//    variableDoubleEquals = DOUBLE_MIN_VALUE;
//    assertEquals(variableDoubleEquals.equals(DOUBLE_NaN), -9999);
//    assertEquals(variableDoubleEquals.equals(DOUBLE_POSITIVE_INFINITY), -9999);
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MAX_VALUE));
//    assertEquals(variableDoubleEquals.equals((Double)1.2));
//    assertEquals(variableDoubleEquals.equals((Double)0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-1.2));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MIN_VALUE));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_NEGATIVE_INFINITY));
	
	// Test DOUBLE_NEGATIVE_INFINITY
	variableDoubleEquals = DOUBLE_NEGATIVE_INFINITY;
	assertEquals(0, variableDoubleEquals.equals(DOUBLE_NaN));
	assertEquals(0, variableDoubleEquals.equals(DOUBLE_POSITIVE_INFINITY));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MAX_VALUE), -9999);
	assertEquals(0, variableDoubleEquals.equals((Double)1.2));
	assertEquals(0, variableDoubleEquals.equals((Double)0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-0.0), -9999);
	assertEquals(0, variableDoubleEquals.equals((Double)-1.2));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MIN_VALUE), -9999);
    assertEquals(1, variableDoubleEquals.equals(DOUBLE_NEGATIVE_INFINITY));

    // Test value (Double)1.2
    variableDoubleEquals = (Double)1.2;
    assertEquals(0, variableDoubleEquals.equals(DOUBLE_NaN));
    assertEquals(0, variableDoubleEquals.equals(DOUBLE_POSITIVE_INFINITY));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MAX_VALUE));
	assertEquals(1, variableDoubleEquals.equals((Double)1.2));
	assertEquals(0, variableDoubleEquals.equals((Double)0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-0.0));
	assertEquals(0, variableDoubleEquals.equals((Double)-1.2));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MIN_VALUE));
	assertEquals(0, variableDoubleEquals.equals(DOUBLE_NEGATIVE_INFINITY));
	
	// Test value (Double)0.0
	variableDoubleEquals = (Double)0.0;
	assertEquals(0, variableDoubleEquals.equals(DOUBLE_NaN));
	assertEquals(0, variableDoubleEquals.equals(DOUBLE_POSITIVE_INFINITY));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MAX_VALUE));
	assertEquals(0, variableDoubleEquals.equals((Double)1.2));
	assertEquals(1, variableDoubleEquals.equals((Double)0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-0.0));
	assertEquals(0, variableDoubleEquals.equals((Double)-1.2));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MIN_VALUE));
	assertEquals(0, variableDoubleEquals.equals(DOUBLE_NEGATIVE_INFINITY));
	
	// Test value (Double)-0.0
//    variableDoubleEquals = (Double)-0.0;
//    assertEquals(variableDoubleEquals.equals(DOUBLE_NaN));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_POSITIVE_INFINITY));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MAX_VALUE));
//    assertEquals(variableDoubleEquals.equals((Double)1.2));
//    assertEquals(variableDoubleEquals.equals((Double)0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-1.2));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MIN_VALUE));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_NEGATIVE_INFINITY));
	
	// Test value (Double)-1.2
	variableDoubleEquals = (Double)-1.2;
	assertEquals(0, variableDoubleEquals.equals(DOUBLE_NaN));
	assertEquals(0, variableDoubleEquals.equals(DOUBLE_POSITIVE_INFINITY));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MAX_VALUE));
	assertEquals(0, variableDoubleEquals.equals((Double)1.2));
	assertEquals(0, variableDoubleEquals.equals((Double)0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-0.0));
	assertEquals(1, variableDoubleEquals.equals((Double)-1.2));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MIN_VALUE));
	assertEquals(0, variableDoubleEquals.equals(DOUBLE_NEGATIVE_INFINITY));
}

TEST(JavaLang , DoubleHashCode) {
	// Create variable to test
	double input;
	long expectedResult;
	long actualResult;
	
	// Input 0.0
	input = 0.0;
	expectedResult = 0;
	actualResult = Double::hashCode(input);
	assertEquals(expectedResult, actualResult);
	
	// Input POSITIVE_INFINITY_DOUBLE
	input = POSITIVE_INFINITY_DOUBLE;
	expectedResult = 9218868439373840384;
	actualResult = Double::hashCode(input);
	assertEquals(expectedResult, actualResult);
	
	// Input NEGATIVE_INFINITY_DOUBLE
	input = NEGATIVE_INFINITY_DOUBLE;
	expectedResult = 9218868435080970240;
	actualResult = Double::hashCode(input);
	assertEquals(expectedResult, actualResult);
	
	// Input NaN_NUMBER_DOUBLE
	input = NaN_NUMBER_DOUBLE;
	expectedResult = 9223372034707292160;
	actualResult = Double::hashCode(input);
	assertEquals(expectedResult, actualResult);
	
	// Input -0.7
	input = -0.7;
	expectedResult =  4604480258807169027;
	actualResult = Double::hashCode(input);
	assertEquals(expectedResult, actualResult);
	
	// Input 12.375
	input = 12.375;
	expectedResult = 4623156124804759552;
	actualResult = Double::hashCode(input);
	assertEquals(expectedResult, actualResult);
	
	// Input 1.0
	input = 1.0;
	expectedResult = 4607182419872710656;
	actualResult = Double::hashCode(input);
	assertEquals(expectedResult, actualResult);
	
	// Input 0.375
	input = 0.375;
	expectedResult = 4600427020430082048;
	actualResult = Double::hashCode(input);
	assertEquals(expectedResult, actualResult);
	
	// Input -2
	input = -2.0;
	expectedResult = 4611686017353646080;
	actualResult = Double::hashCode(input);
	assertEquals(expectedResult, actualResult);
	
	// Input 83
	input = 83.0;
	expectedResult = 4635541023782912000;
	actualResult = Double::hashCode(input);
	assertEquals(expectedResult, actualResult);
	
	// Input -2625
	input = -2625.0;
	expectedResult = 4657990850035023360;
	actualResult = Double::hashCode(input);
	assertEquals(expectedResult, actualResult);
	
	// Input 0.5
	input = 0.5;
	expectedResult = 4602678820244291584;
	actualResult = Double::hashCode(input);
	assertEquals(expectedResult, actualResult);
	
	// Input -1302.12345678
	input = -1302.12345678;
	expectedResult = 4653441613905795640;
	actualResult = Double::hashCode(input);
	assertEquals(expectedResult, actualResult);
}

TEST(JavaLang , DoubleHashCodeNotInput) {
	// Create variable to test
	Double variableDouble;
	long expectedResult;
	long actualResult;
	
	// Input 0.0
	variableDouble = 0.0;
	expectedResult = 0;
	actualResult = variableDouble.hashCode();
	assertEquals(expectedResult, actualResult);
	
	// Input POSITIVE_INFINITY_DOUBLE
	variableDouble = POSITIVE_INFINITY_DOUBLE;
	expectedResult = 9218868439373840384;
	actualResult = variableDouble.hashCode();
	assertEquals(expectedResult, actualResult);
	
	// Input NEGATIVE_INFINITY_DOUBLE
	variableDouble = NEGATIVE_INFINITY_DOUBLE;
	expectedResult = 9218868435080970240;
	actualResult = variableDouble.hashCode();
	assertEquals(expectedResult, actualResult);
	
	// Input NaN_NUMBER_DOUBLE
	variableDouble = NaN_NUMBER_DOUBLE;
	expectedResult = 9223372034707292160;
	actualResult = variableDouble.hashCode();
	assertEquals(expectedResult, actualResult);
	
	// Input -0.7
	variableDouble = -0.7;
	expectedResult =  4604480258807169027;
	actualResult = variableDouble.hashCode();
	assertEquals(expectedResult, actualResult);
	
	// Input 12.375
	variableDouble = 12.375;
	expectedResult = 4623156124804759552;
	actualResult = variableDouble.hashCode();
	assertEquals(expectedResult, actualResult);
	
	// Input 1.0
	variableDouble = 1.0;
	expectedResult = 4607182419872710656;
	actualResult = variableDouble.hashCode();
	assertEquals(expectedResult, actualResult);
	
	// Input 0.375
	variableDouble = 0.375;
	expectedResult = 4600427020430082048;
	actualResult = variableDouble.hashCode();
	assertEquals(expectedResult, actualResult);
	
	// Input -2
	variableDouble = -2.0;
	expectedResult = 4611686017353646080;
	actualResult = variableDouble.hashCode();
	assertEquals(expectedResult, actualResult);
	
	// Input 83
	variableDouble = 83.0;
	expectedResult = 4635541023782912000;
	actualResult = variableDouble.hashCode();
	assertEquals(expectedResult, actualResult);
	
	// Input -2625
	variableDouble = -2625.0;
	expectedResult = 4657990850035023360;
	actualResult = variableDouble.hashCode();
	assertEquals(expectedResult, actualResult);
	
	// Input 0.5
	variableDouble = 0.5;
	expectedResult = 4602678820244291584;
	actualResult = variableDouble.hashCode();
	assertEquals(expectedResult, actualResult);
	
	// Input -1302.12345678
	variableDouble = -1302.12345678;
	expectedResult = 4653441613905795640;
	actualResult = variableDouble.hashCode();
	assertEquals(expectedResult, actualResult);
}

TEST(JavaLang , DoubleIsFinite) {
    assertTrue(Double::isFinite(13.02));
    assertTrue(Double::isFinite(130.2));
    assertFalse(Double::isFinite(POSITIVE_INFINITY_DOUBLE));
    assertFalse(Double::isFinite(NEGATIVE_INFINITY_DOUBLE));
}

TEST(JavaLang , DoubleIsInfinite) {
	assertTrue(Double::isInfinite(POSITIVE_INFINITY_DOUBLE));
	assertTrue(Double::isInfinite(NEGATIVE_INFINITY_DOUBLE));
	assertFalse(Double::isInfinite(13.02));
	assertFalse(Double::isInfinite(130.2));
}

TEST(JavaLang , DoubleIsInfinite2) {
	Double variableIsInfinite2;
	
	variableIsInfinite2 = POSITIVE_INFINITY_DOUBLE;
	assertTrue(variableIsInfinite2.isInfinite());
	
	variableIsInfinite2 = NEGATIVE_INFINITY_DOUBLE;
	assertTrue(variableIsInfinite2.isInfinite());
	
	variableIsInfinite2 = 13.02;
	assertFalse(variableIsInfinite2.isInfinite());
}

TEST(JavaLang , DoubleIsNaN) {
    assertTrue(Double::isNaN(NaN_NUMBER_DOUBLE));
    assertFalse(Double::isNaN(NEGATIVE_INFINITY_DOUBLE));
    assertFalse(Double::isNaN(13.02));
    assertFalse(Double::isNaN(130.2));
}

TEST(JavaLang , DoubleIsNaN2) {
	Double variableIsInfinite2;
	
	variableIsInfinite2 = NaN_NUMBER_DOUBLE;
	assertTrue(variableIsInfinite2.isNaN());
	
	variableIsInfinite2 = NEGATIVE_INFINITY_DOUBLE;
	assertFalse(variableIsInfinite2.isNaN());
	
	variableIsInfinite2 = 13.02;
	assertFalse(variableIsInfinite2.isNaN());
}

TEST(JavaLang, DoubleMin) {
	double variableDoubleMin1;
	double variableDoubleMin2;
	double expectedResultDoubleMin;
	double actualResultDoubleMin;

	variableDoubleMin1 = 13.02;
	variableDoubleMin2 = 1.302;
	expectedResultDoubleMin = 1.302;
	actualResultDoubleMin = Double::min(variableDoubleMin1, variableDoubleMin2);
	ASSERT_DBL_NEAR(expectedResultDoubleMin, actualResultDoubleMin);

	variableDoubleMin1 = 13.02;
	variableDoubleMin2 = 1.302;
	expectedResultDoubleMin = 13.02;
	actualResultDoubleMin = Double::min(variableDoubleMin1, variableDoubleMin2);
	ASSERT_DBL_FAR(expectedResultDoubleMin, actualResultDoubleMin);
}

TEST(JavaLang, DoubleLongBitsToDouble) {
	// Create variable to test
	long longBitsInput;
	double expectedResult;
	double actualResult;
	
	// Input 0.0
	longBitsInput = 0;
	expectedResult = 0.0;
	actualResult = Double::longBitsToDouble(longBitsInput);
	ASSERT_DBL_NEAR(expectedResult, actualResult);
	
	// Input POSITIVE_INFINITY_DOUBLE
	longBitsInput = 9218868437227405312;
	expectedResult = POSITIVE_INFINITY_DOUBLE;
	actualResult = Double::longBitsToDouble(longBitsInput);
	ASSERT_DBL_NEAR(expectedResult, actualResult);
	
	// Input NEGATIVE_INFINITY_DOUBLE
	longBitsInput = -9218868437227405312;
	expectedResult = NEGATIVE_INFINITY_DOUBLE;
	actualResult = Double::longBitsToDouble(longBitsInput);
	ASSERT_DBL_NEAR(expectedResult, actualResult);
	
	
	// Input -0.7
	longBitsInput = -4604480259023595110;
	expectedResult = -0.7;
	actualResult = Double::longBitsToDouble(longBitsInput);
	ASSERT_DBL_NEAR(expectedResult, actualResult);
	
	// Input 12.375
	longBitsInput = 4623156123728347136;
	expectedResult = 12.375;
	actualResult = Double::longBitsToDouble(longBitsInput);
	ASSERT_DBL_NEAR(expectedResult, actualResult);
	
	// Input 1.0
	longBitsInput = 4607182418800017408;
	expectedResult = 1.0;
	actualResult = Double::longBitsToDouble(longBitsInput);
	ASSERT_DBL_NEAR(expectedResult, actualResult);
	
	// Input 0.375
	longBitsInput = 4600427019358961664;
	expectedResult = 0.375;
	actualResult = Double::longBitsToDouble(longBitsInput);
	ASSERT_DBL_NEAR(expectedResult, actualResult);
	
	// Input -2
	longBitsInput = -4611686018427387904;
	expectedResult = -2.0;
	actualResult = Double::longBitsToDouble(longBitsInput);
	ASSERT_DBL_NEAR(expectedResult, actualResult);
	
	// Input 83
	longBitsInput = 4635541022703616000;
	expectedResult = 83.0;
	actualResult = Double::longBitsToDouble(longBitsInput);
	ASSERT_DBL_NEAR(expectedResult, actualResult);
	
	// Input -2625
	longBitsInput = -4657990851119546368;
	expectedResult = -2625.0;
	actualResult = Double::longBitsToDouble(longBitsInput);
	ASSERT_DBL_NEAR(expectedResult, actualResult);
	
	// Input 0.5
	longBitsInput = 4602678819172646912;
	expectedResult = 0.5;
	actualResult = Double::longBitsToDouble(longBitsInput);
	ASSERT_DBL_NEAR(expectedResult, actualResult);
	
	// Input -1302.12345678
	longBitsInput = -4653441614972469831;
	expectedResult = -1302.12345678;
	actualResult = Double::longBitsToDouble(longBitsInput);
	ASSERT_DBL_NEAR(expectedResult, actualResult);
}

// TODO(thoangminh):  Check later all value of Java ( Double Format IEEE 754) in C++:
//TABLE 2-5   Bit Patterns in Double-Storage Format and their IEEE Values
//        Common Name	    Bit Pattern (Hex)	    Decimal Value
//+ 0	00000000 00000000	0.0
//- 0	80000000 00000000	-0.0
//1	3ff00000 00000000	1.0
//2	40000000 00000000	2.0
//max normal number	7fefffff ffffffff	1.7976931348623157e+308
//min positive normal number	00100000 00000000	2.2250738585072014e-308
//max subnormal number	000fffff ffffffff	2.2250738585072009e-308
//min positive subnormal number	00000000 00000001	4.9406564584124654e-324
//+inf	7ff00000 00000000	Infinity
//-inf	fff00000 00000000	-Infinity
//Not-a-Number	7ff80000 00000000	NaN