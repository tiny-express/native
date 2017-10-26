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
#include "../../../kernel/Platform.hpp"
#include "Double.hpp"

using namespace Java::Lang;

TEST (JavaLang, DoubleConstructor) {
    // Test Double::Double()
    Double emptyDoubleConstructor;
    emptyDoubleConstructor = 13.02;
    assertEquals(13.02, emptyDoubleConstructor.doubleValue());

    // Test Double::Double(double original)
    Double validDoubleConstructor = 13.02;
    assertEquals(13.02, validDoubleConstructor.doubleValue());

    // Test Double::Double(const Double &doubleNumber)
    Double DoubleConstructor(validDoubleConstructor);
    assertEquals(13.02, validDoubleConstructor.doubleValue());
}

TEST (JavaLang, DoubleArithmeticOperator) {
    // Create variable to test
    Double variableFirst;
    Double variableSecond;
    Double expected;
    Double actual;

    // Test Operator +
    variableFirst = 11.11;
    variableSecond = 22.22;
    expected = 33.33;
    actual = variableFirst + variableSecond;
    assertEquals(expected.doubleValue(), actual.doubleValue());

    // Test Operator -
    variableFirst = 33.33;
    variableSecond = 22.22;
    expected = 11.11;
    actual = variableFirst - variableSecond;
    assertEquals(expected.doubleValue(), actual.doubleValue());

    // Test Operator *
    variableFirst = 2.0;
    variableSecond = 13.02;
    expected = 26.04;
    actual = variableFirst * variableSecond;
    assertEquals(expected.doubleValue(), actual.doubleValue());

    // Test Operator /
    variableFirst = 26.04;
    variableSecond = 2.0;
    expected = 13.02;
    actual = variableFirst / variableSecond;
    assertEquals(expected.doubleValue(), actual.doubleValue());

    // Test Operator / . Double::POSITIVE_INFINITY
    variableFirst = 26.04;
    variableSecond = 0;
    expected = Double::POSITIVE_INFINITY;
    actual = variableFirst / variableSecond;
    assertEquals(expected.doubleValue(), actual.doubleValue());

    // Test Operator / . Double::NEGATIVE_INFINITY
    variableFirst = -26.04;
    variableSecond = 0;
    expected = Double::NEGATIVE_INFINITY;
    actual = variableFirst / variableSecond;
    assertEquals(expected.doubleValue(), actual.doubleValue());

    // Test Operator / . Double::NaN
    variableFirst = 0;
    variableSecond = 0;
    expected = -Double::NaN;
    actual = variableFirst / variableSecond;
    assertEquals(expected.doubleValue(), actual.doubleValue());
}

TEST (JavaLang, DoubleRelationalOperator) {
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

TEST (JavaLang, DoubleLogicalOperator) {
    // Test Operator && . Case 0   0
    assertFalse((Double) 0 && (Double) 0);

    // Test Operator && . Case 0   1
    assertFalse((Double) 0 && (Double) 1);

    // Test Operator && . Case 1   0
    assertFalse((Double) 1 && (Double) 0);

    // Test Operator && . Case 1   1
    assertTrue((Double) 1 && (Double) 1);

    // Test Operator || . Case 0   0
    assertFalse((Double) 0 || (Double) 0);

    // Test Operator || . Case 0   1
    assertTrue((Double) 0 || (Double) 1);

    // Test Operator || . Case 1   0
    assertTrue((Double) 1 || (Double) 0);

    // Test Operator || . Case 1   1
    assertTrue((Double) 1 || (Double) 1);
}

TEST (JavaLang, DoubleAssignmentOperator) {
    // Create variable to test
    Double variableAssignmentOperator1;
    Double variableAssignmentOperator2;
    Double expected;
    Double actual;

    // Test Operator =
    variableAssignmentOperator1 = 0.0;
    variableAssignmentOperator2 = 1.1;
    expected = 1.1;
    actual = (variableAssignmentOperator1 = variableAssignmentOperator2);
    assertEquals(expected.doubleValue(), actual.doubleValue());

    // Test Operator +=
    variableAssignmentOperator1 = 11.11;
    variableAssignmentOperator2 = 22.22;
    expected = 33.33;
    actual = (variableAssignmentOperator1 += variableAssignmentOperator2);
    assertEquals(expected.doubleValue(), actual.doubleValue());

    // Test Operator -=
    variableAssignmentOperator1 = 33.33;
    variableAssignmentOperator2 = 11.11;
    expected = 22.22;
    actual = (variableAssignmentOperator1 -= variableAssignmentOperator2);
    assertEquals(expected.doubleValue(), actual.doubleValue());

    // Test Operator *=
    variableAssignmentOperator1 = 13.02;
    variableAssignmentOperator2 = 2.0;
    expected = 26.04;
    actual = (variableAssignmentOperator1 *= variableAssignmentOperator2);
    assertEquals(expected.doubleValue(), actual.doubleValue());

    // Test Operator /=
    variableAssignmentOperator1 = 26.04;
    variableAssignmentOperator2 = 2.0;
    expected = 13.02;
    actual = (variableAssignmentOperator1 /= variableAssignmentOperator2);
    assertEquals(expected.doubleValue(), actual.doubleValue());
}

TEST (JavaLang, DoubleParseDouble) {
    string stringInput;
    Double expectedResult;
    Double actualResult;

    stringInput = (string) "1302.12345678";
    expectedResult = 1302.12345678;
    actualResult = Double::parseDouble(stringInput);
    assertEquals(expectedResult.doubleValue(), actualResult.doubleValue());

    stringInput = (string) "-1302.12345678";
    expectedResult = -1302.12345678;
    actualResult = Double::parseDouble(stringInput);
    assertEquals(expectedResult.doubleValue(), actualResult.doubleValue());
}

TEST (JavaLang, DoubleValueOfWithStringInput) {
    string stringInput;
    Double expectedResult;
    Double actualResult;

    stringInput = (string) "1302.12345678";
    expectedResult = 1302.12345678;
    actualResult = Double::valueOf(stringInput);
    assertEquals(expectedResult.doubleValue(), actualResult.doubleValue());

    stringInput = (string) "-1302.12345678";
    expectedResult = -1302.12345678;
    actualResult = Double::valueOf(stringInput);
    assertEquals(expectedResult.doubleValue(), actualResult.doubleValue());
}

TEST (JavaLang, DoubleValueOfWithDoubleInput) {
    double doubleInput;
    Double expectedResult;
    Double actualResult;

    doubleInput = 1302.12345678;
    expectedResult = 1302.12345678;
    actualResult = Double::valueOf(doubleInput);
    assertEquals(expectedResult.doubleValue(), actualResult.doubleValue());

    doubleInput = -1302.12345678;
    expectedResult = -1302.12345678;
    actualResult = Double::valueOf(doubleInput);
    assertEquals(expectedResult.doubleValue(), actualResult.doubleValue());
}

TEST (JavaLang, DoubleToString) {
    // Create variable to test
    Double variableTestToString;
    String expected;
    String actual;

    // Test Double::POSITIVE_INFINITY
    variableTestToString = Double::POSITIVE_INFINITY;
    expected = "inf";
    actual = variableTestToString.toString();
    assertEquals(expected, actual);

    // Test Double::NEGATIVE_INFINITY
    variableTestToString = Double::NEGATIVE_INFINITY;
    expected = "-inf";
    actual = variableTestToString.toString();
    assertEquals(expected, actual);


//    // Test Double::NaN
//    variableTestToString = Double::NaN;
//    expected = "-nan";  // "nan" in MacOS
//    actual = variableTestToString.toString();
//    assertEquals(expected , actual);
// free(actual);

    // Test Double::MAX_VALUE
    variableTestToString = Double::MAX_VALUE;
    expected = "179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000000000000";
#ifdef WIN
    expected = "179769313486231570814527423731704356798070600000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.000000000000000";
#endif
    actual = variableTestToString.toString();
    assertEquals(expected, actual);

    // Test Double::MIN_NORMAL
    variableTestToString = Double::MIN_NORMAL;
    expected = "0.000000000000000";
    actual = variableTestToString.toString();
    assertEquals(expected, actual);

    // Test Double::MIN_VALUE
    variableTestToString = Double::MIN_VALUE;
    expected = "0.000000000000000";
    actual = variableTestToString.toString();
    assertEquals(expected, actual);
}

TEST (JavaLang, DoubleCharValue) {
    // Create variable to test
    Double variableTestCharValue;
    char expectedResultCharValue;
    char actualResultCharValue;

    // Test Double::POSITIVE_INFINITY
    variableTestCharValue = Double::POSITIVE_INFINITY;
    expectedResultCharValue = 'i';
    actualResultCharValue = variableTestCharValue.charValue();
    assertEquals(expectedResultCharValue, actualResultCharValue);

    // Test Double::NEGATIVE_INFINITY
    variableTestCharValue = Double::NEGATIVE_INFINITY;
    expectedResultCharValue = '-';
    actualResultCharValue = variableTestCharValue.charValue();
    assertEquals(expectedResultCharValue, actualResultCharValue);

//    // Test Double::NaN
//    variableTestCharValue = Double::NaN;
//    expectedResultCharValue = 45;  // 110 in MacOS
//    actualResultCharValue = variableTestCharValue.charValue();
//    assertEquals(expectedResultCharValue , actualResultCharValue);

    // Test Double::MAX_VALUE
    variableTestCharValue = Double::MAX_VALUE;
    expectedResultCharValue = '1';
    actualResultCharValue = variableTestCharValue.charValue();
    assertEquals(expectedResultCharValue, actualResultCharValue);

    // Test Double::MIN_NORMAL
    variableTestCharValue = Double::MIN_NORMAL;
    expectedResultCharValue = '4';
    actualResultCharValue = variableTestCharValue.charValue();
    assertEquals(expectedResultCharValue, actualResultCharValue);

    // Test Double::MIN_VALUE
    variableTestCharValue = Double::MIN_VALUE;
    expectedResultCharValue = '2';
    actualResultCharValue = variableTestCharValue.charValue();
    assertEquals(expectedResultCharValue, actualResultCharValue);

    // Test valid case
    variableTestCharValue = 13.02;
    expectedResultCharValue = '1';
    actualResultCharValue = variableTestCharValue.charValue();
    assertEquals(expectedResultCharValue, actualResultCharValue);

    // Test valid case
    variableTestCharValue = 20.31;
    expectedResultCharValue = '2';
    actualResultCharValue = variableTestCharValue.charValue();
    assertEquals(expectedResultCharValue, actualResultCharValue);

    // Test invalid case
    variableTestCharValue = 13.02;
    expectedResultCharValue = '5';
    actualResultCharValue = variableTestCharValue.charValue();
    assertNotEquals(expectedResultCharValue, actualResultCharValue);
}

TEST (JavaLang, DoubleShortValue) {
    // Create variable to test
    Double variableTestShortValue;
    short expectedResultShortValue;
    short actualResultShortValue;

    // Test Double::POSITIVE_INFINITY
    variableTestShortValue = Double::POSITIVE_INFINITY;
    expectedResultShortValue = 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    assertEquals(expectedResultShortValue, actualResultShortValue);

    // Test Double::NEGATIVE_INFINITY
    variableTestShortValue = Double::NEGATIVE_INFINITY;
    expectedResultShortValue = 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    assertEquals(expectedResultShortValue, actualResultShortValue);

    // Test Double::NaN
    variableTestShortValue = Double::NaN;
    expectedResultShortValue = 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    assertEquals(expectedResultShortValue, actualResultShortValue);

    // Test Double::MAX_VALUE
    variableTestShortValue = Double::MAX_VALUE;
    expectedResultShortValue = 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    assertEquals(expectedResultShortValue, actualResultShortValue);

    // Test Double::MIN_NORMAL
    variableTestShortValue = Double::MIN_NORMAL;
    expectedResultShortValue = 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    assertEquals(expectedResultShortValue, actualResultShortValue);

    // Test Double::MIN_VALUE
    variableTestShortValue = Double::MIN_VALUE;
    expectedResultShortValue = 0;
    actualResultShortValue = variableTestShortValue.shortValue();
    assertEquals(expectedResultShortValue, actualResultShortValue);

    // Test valid case
    variableTestShortValue = 5.9;
    expectedResultShortValue = 5;
    actualResultShortValue = variableTestShortValue.shortValue();
    assertEquals(expectedResultShortValue, actualResultShortValue);

    // Test valid case
    variableTestShortValue = 5.4;
    expectedResultShortValue = 5;
    actualResultShortValue = variableTestShortValue.shortValue();
    assertEquals(expectedResultShortValue, actualResultShortValue);

    // Test invalid case
    variableTestShortValue = 6;
    expectedResultShortValue = 5;
    actualResultShortValue = variableTestShortValue.shortValue();
    assertNotEquals(expectedResultShortValue, actualResultShortValue);
}


TEST (JavaLang, DoubleIntValue) {
    // Create variable to test
    Double variableTestIntValue;
    int expectedResultIntValue;
    int actualResultIntValue;

    // Test Double::POSITIVE_INFINITY
    variableTestIntValue = Double::POSITIVE_INFINITY;
    expectedResultIntValue = -2147483648;
    actualResultIntValue = variableTestIntValue.intValue();
    assertEquals(expectedResultIntValue, actualResultIntValue);

    // Test Double::NEGATIVE_INFINITY
    variableTestIntValue = Double::NEGATIVE_INFINITY;
    expectedResultIntValue = -2147483648;
    actualResultIntValue = variableTestIntValue.intValue();
    assertEquals(expectedResultIntValue, actualResultIntValue);

    // Test Double::NaN
    variableTestIntValue = Double::NaN;
    expectedResultIntValue = -2147483648;
    actualResultIntValue = variableTestIntValue.intValue();
    assertEquals(expectedResultIntValue, actualResultIntValue);

    // Test Double::MAX_VALUE
    variableTestIntValue = Double::MAX_VALUE;
    expectedResultIntValue = -2147483648;
    actualResultIntValue = variableTestIntValue.intValue();
    assertEquals(expectedResultIntValue, actualResultIntValue);

    // Test Double::MIN_NORMAL
    variableTestIntValue = Double::MIN_NORMAL;
    expectedResultIntValue = 0;
    actualResultIntValue = variableTestIntValue.intValue();
    assertEquals(expectedResultIntValue, actualResultIntValue);

    // Test Double::MIN_VALUE
    variableTestIntValue = Double::MIN_VALUE;
    expectedResultIntValue = 0;
    actualResultIntValue = variableTestIntValue.intValue();
    assertEquals(expectedResultIntValue, actualResultIntValue);

    // Test valid case
    variableTestIntValue = 5.9;
    expectedResultIntValue = 5;
    actualResultIntValue = variableTestIntValue.intValue();
    assertEquals(expectedResultIntValue, actualResultIntValue);

    // Test valid case
    variableTestIntValue = 5.4;
    expectedResultIntValue = 5;
    actualResultIntValue = variableTestIntValue.intValue();
    assertEquals(expectedResultIntValue, actualResultIntValue);

    // Test invalid case
    variableTestIntValue = 6;
    expectedResultIntValue = 5;
    actualResultIntValue = variableTestIntValue.intValue();
    assertNotEquals(expectedResultIntValue, actualResultIntValue);
}

TEST (JavaLang, DoubleLongValue) {
    // Create variable to test
    Double variableTestLongValue;
    long expectedResultLongValue;
    long actualResultLongValue;

    // Test Double::POSITIVE_INFINITY
    variableTestLongValue = Double::POSITIVE_INFINITY;
    expectedResultLongValue = -9223372036854775808u;
    actualResultLongValue = variableTestLongValue.longValue();
    assertEquals(expectedResultLongValue, actualResultLongValue);

    // Test Double::NEGATIVE_INFINITY
    variableTestLongValue = Double::NEGATIVE_INFINITY;
    expectedResultLongValue = -9223372036854775808u;
    actualResultLongValue = variableTestLongValue.longValue();
    assertEquals(expectedResultLongValue, actualResultLongValue);

    // Test Double::NaN
    variableTestLongValue = Double::NaN;
    expectedResultLongValue = -9223372036854775808u;
    actualResultLongValue = variableTestLongValue.longValue();
    assertEquals(expectedResultLongValue, actualResultLongValue);

    // Test Double::MAX_VALUE
    variableTestLongValue = Double::MAX_VALUE;
    expectedResultLongValue = -9223372036854775808u;
    actualResultLongValue = variableTestLongValue.longValue();
    assertEquals(expectedResultLongValue, actualResultLongValue);

    // Test Double::MIN_NORMAL
    variableTestLongValue = Double::MIN_NORMAL;
    expectedResultLongValue = 0;
    actualResultLongValue = variableTestLongValue.longValue();
    assertEquals(expectedResultLongValue, actualResultLongValue);

    // Test Double::MIN_VALUE
    variableTestLongValue = Double::MIN_VALUE;
    expectedResultLongValue = 0;
    actualResultLongValue = variableTestLongValue.longValue();
    assertEquals(expectedResultLongValue, actualResultLongValue);

    // Test valid case
    variableTestLongValue = 5.9;
    expectedResultLongValue = 5;
    actualResultLongValue = variableTestLongValue.longValue();
    assertEquals(expectedResultLongValue, actualResultLongValue);

    // Test valid case
    variableTestLongValue = 5.4;
    expectedResultLongValue = 5;
    actualResultLongValue = variableTestLongValue.longValue();
    assertEquals(expectedResultLongValue, actualResultLongValue);

    // Test invalid case
    variableTestLongValue = 6;
    expectedResultLongValue = 5;
    actualResultLongValue = variableTestLongValue.longValue();
    assertNotEquals(expectedResultLongValue, actualResultLongValue);
}

TEST (JavaLang, DoubleFloatValue) {
    // Create variable to test
    Double variableTestFloatValue;
    float expectedResultFloatValue;
    float actualResultFloatValue;

    // Test Double::POSITIVE_INFINITY
    variableTestFloatValue = Double::POSITIVE_INFINITY;
    expectedResultFloatValue = static_cast<float> (1.0 / 0.0);
    actualResultFloatValue = variableTestFloatValue.floatValue();
    assertEquals(expectedResultFloatValue, actualResultFloatValue);

    // Test Double::NEGATIVE_INFINITY
    variableTestFloatValue = Double::NEGATIVE_INFINITY;
    expectedResultFloatValue = static_cast<float> (-1.0 / 0.0);
    actualResultFloatValue = variableTestFloatValue.floatValue();
    assertEquals(expectedResultFloatValue, actualResultFloatValue);

    // Test Double::NaN
    variableTestFloatValue = Double::NaN;
    expectedResultFloatValue = static_cast<float> (0.0 / 0.0);
    actualResultFloatValue = variableTestFloatValue.floatValue();
    assertEquals(expectedResultFloatValue, actualResultFloatValue);

    // Test Double::MAX_VALUE
    variableTestFloatValue = Double::MAX_VALUE;
    expectedResultFloatValue = static_cast<float> (1.0 / 0.0);
    actualResultFloatValue = variableTestFloatValue.floatValue();
    assertEquals(expectedResultFloatValue, actualResultFloatValue);

    // Test Double::MIN_NORMAL
    variableTestFloatValue = Double::MIN_NORMAL;
    expectedResultFloatValue = 0;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    assertEquals(expectedResultFloatValue, actualResultFloatValue);

    // Test Double::MIN_VALUE
    variableTestFloatValue = Double::MIN_VALUE;
    expectedResultFloatValue = 0;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    assertEquals(expectedResultFloatValue, actualResultFloatValue);

    // Test valid case
    variableTestFloatValue = 13.02;
    expectedResultFloatValue = 13.02;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    assertEquals(expectedResultFloatValue, actualResultFloatValue);

    // Test valid case
    variableTestFloatValue = 1.302;
    expectedResultFloatValue = 1.302;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    assertEquals(expectedResultFloatValue, actualResultFloatValue);

    // Test invalid case
    variableTestFloatValue = 130.2;
    expectedResultFloatValue = 130.0;
    actualResultFloatValue = variableTestFloatValue.floatValue();
    assertNotEquals(expectedResultFloatValue, actualResultFloatValue);
}


TEST (JavaLang, DoubleDoubleValue) {
    // Create variable to test
    Double variableTestDoubleValue;
    double expectedResultDoubleValue;
    double actualResultDoubleValue;

    // Test Double::POSITIVE_INFINITY
    variableTestDoubleValue = Double::POSITIVE_INFINITY;
    expectedResultDoubleValue = Double::POSITIVE_INFINITY;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    assertEquals(expectedResultDoubleValue, actualResultDoubleValue);

    // Test Double::NEGATIVE_INFINITY
    variableTestDoubleValue = Double::NEGATIVE_INFINITY;
    expectedResultDoubleValue = Double::NEGATIVE_INFINITY;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    assertEquals(expectedResultDoubleValue, actualResultDoubleValue);

    // Test Double::NaN
    variableTestDoubleValue = Double::NaN;
    expectedResultDoubleValue = Double::NaN;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    assertEquals(expectedResultDoubleValue, actualResultDoubleValue);

    // Test Double::MAX_VALUE
    variableTestDoubleValue = Double::MAX_VALUE;
    expectedResultDoubleValue = Double::MAX_VALUE;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    assertEquals(expectedResultDoubleValue, actualResultDoubleValue);

    // Test Double::MIN_NORMAL
    variableTestDoubleValue = Double::MIN_NORMAL;
    expectedResultDoubleValue = Double::MIN_NORMAL;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    assertEquals(expectedResultDoubleValue, actualResultDoubleValue);

    // Test Double::MIN_VALUE
    variableTestDoubleValue = Double::MIN_VALUE;
    expectedResultDoubleValue = Double::MIN_VALUE;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    assertEquals(expectedResultDoubleValue, actualResultDoubleValue);

    // Test valid case
    variableTestDoubleValue = 13.02;
    expectedResultDoubleValue = 13.02;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    assertEquals(expectedResultDoubleValue, actualResultDoubleValue);

    // Test valid case
    variableTestDoubleValue = 1.302;
    expectedResultDoubleValue = 1.302;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    assertEquals(expectedResultDoubleValue, actualResultDoubleValue);

    // Test invalid case
    variableTestDoubleValue = 130.2;
    expectedResultDoubleValue = 130.0;
    actualResultDoubleValue = variableTestDoubleValue.doubleValue();
    assertNotEquals(expectedResultDoubleValue, actualResultDoubleValue);
}

TEST (JavaLang, DoubleByteValue) {
    // Create variable to test
    Double variableTestByteValue;
    byte expectedResultByteValue;
    byte actualResultByteValue;

    // Test Double::POSITIVE_INFINITY
    variableTestByteValue = Double::POSITIVE_INFINITY;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    assertEquals(expectedResultByteValue, actualResultByteValue);

    // Test Double::NEGATIVE_INFINITY
    variableTestByteValue = Double::NEGATIVE_INFINITY;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    assertEquals(expectedResultByteValue, actualResultByteValue);

    //// Error in OSX
//    // Test Double::NaN
//    variableTestByteValue = Double::NaN;
//    expectedResultByteValue = 45;  // 110 in MacOS
//    actualResultByteValue = variableTestByteValue.byteValue();
//    assertEquals(expectedResultByteValue , actualResultByteValue);

    // Test Double::MAX_VALUE
    variableTestByteValue = Double::MAX_VALUE;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    assertEquals(expectedResultByteValue, actualResultByteValue);

    // Test Double::MIN_NORMAL
    variableTestByteValue = Double::MIN_NORMAL;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    assertEquals(expectedResultByteValue, actualResultByteValue);

    // Test Double::MIN_VALUE
    variableTestByteValue = Double::MIN_VALUE;
    expectedResultByteValue = 0;
    actualResultByteValue = variableTestByteValue.byteValue();
    assertEquals(expectedResultByteValue, actualResultByteValue);

    // Test valid case
    variableTestByteValue = 13.02;
    expectedResultByteValue = 13;
    actualResultByteValue = variableTestByteValue.byteValue();
    assertEquals(expectedResultByteValue, actualResultByteValue);

    // Test valid case
    variableTestByteValue = 20.31;
    expectedResultByteValue = 20;
    actualResultByteValue = variableTestByteValue.byteValue();
    assertEquals(expectedResultByteValue, actualResultByteValue);

    // Test invalid case
    variableTestByteValue = 13.02;
    expectedResultByteValue = 5;
    actualResultByteValue = variableTestByteValue.byteValue();
    assertNotEquals(expectedResultByteValue, actualResultByteValue);
}

// TODO(thoangminh): Need to pass all test cases in comment block
TEST (JavaLang, DoubleCompare) {
    // Test Double::NaN
    assertEquals(0, Double::compare(Double::NaN, Double::NaN));
    assertEquals(1, Double::compare(Double::NaN, Double::POSITIVE_INFINITY));
//    assertEquals(Double::compare(Double::NaN, Double::MAX_VALUE));
    assertEquals(1, Double::compare(Double::NaN, 1.2));
    assertEquals(1, Double::compare(Double::NaN, 0.0));
    assertEquals(1, Double::compare(Double::NaN, -0.0));
    assertEquals(1, Double::compare(Double::NaN, -1.2));
    assertEquals(1, Double::compare(Double::NaN, Double::MIN_VALUE));
    assertEquals(1, Double::compare(Double::NaN, Double::NEGATIVE_INFINITY));

    // Test Double::POSITIVE_INFINITY
    assertEquals(-1, Double::compare(Double::POSITIVE_INFINITY, Double::NaN));
    assertEquals(0, Double::compare(Double::POSITIVE_INFINITY, Double::POSITIVE_INFINITY));
//    assertEquals(Double::compare(Double::POSITIVE_INFINITY, Double::MAX_VALUE), -9999);
    assertEquals(1, Double::compare(Double::POSITIVE_INFINITY, 1.2));
    assertEquals(1, Double::compare(Double::POSITIVE_INFINITY, 0.0));
    assertEquals(1, Double::compare(Double::POSITIVE_INFINITY, -0.0));
    assertEquals(1, Double::compare(Double::POSITIVE_INFINITY, -1.2));
    assertEquals(1, Double::compare(Double::POSITIVE_INFINITY, Double::MIN_VALUE));
    assertEquals(1, Double::compare(Double::POSITIVE_INFINITY, Double::NEGATIVE_INFINITY));

    // Test Double::NEGATIVE_INFINITY
    assertEquals(-1, Double::compare(Double::NEGATIVE_INFINITY, Double::NaN));
    assertEquals(-1, Double::compare(Double::NEGATIVE_INFINITY, Double::POSITIVE_INFINITY));
//    assertEquals(Double::compare(Double::NEGATIVE_INFINITY, Double::MAX_VALUE), -9999);
    assertEquals(-1, Double::compare(Double::NEGATIVE_INFINITY, 1.2));
    assertEquals(-1, Double::compare(Double::NEGATIVE_INFINITY, 0.0));
    assertEquals(-1, Double::compare(Double::NEGATIVE_INFINITY, -0.0));
    assertEquals(-1, Double::compare(Double::NEGATIVE_INFINITY, -1.2));
    assertEquals(-1, Double::compare(Double::NEGATIVE_INFINITY, Double::MIN_VALUE));
    assertEquals(0, Double::compare(Double::NEGATIVE_INFINITY, Double::NEGATIVE_INFINITY));

//    // Test Double::MAX_VALUE
//    assertEquals(Double::compare(Double::MAX_VALUE, Double::NaN), -9999);
//    assertEquals(Double::compare(Double::MAX_VALUE, Double::POSITIVE_INFINITY), -9999);
//    assertEquals(Double::compare(Double::MAX_VALUE, Double::MAX_VALUE));
//    assertEquals(Double::compare(Double::MAX_VALUE, 1.2));
//    assertEquals(Double::compare(Double::MAX_VALUE, 0.0));
//    assertEquals(Double::compare(Double::MAX_VALUE, -0.0));
//    assertEquals(Double::compare(Double::MAX_VALUE, -1.2));
//    assertEquals(Double::compare(Double::MAX_VALUE, Double::MIN_VALUE));
//    assertEquals(Double::compare(Double::MAX_VALUE, Double::NEGATIVE_INFINITY), -9999);

    // Test Double::MIN_VALUE
    assertEquals(-1, Double::compare(Double::MIN_VALUE, Double::NaN));
    assertEquals(-1, Double::compare(Double::MIN_VALUE, Double::POSITIVE_INFINITY));
//    assertEquals(Double::compare(Double::MIN_VALUE, Double::MAX_VALUE));
    assertEquals(-1, Double::compare(Double::MIN_VALUE, 1.2));
    assertEquals(1, Double::compare(Double::MIN_VALUE, 0.0));
    assertEquals(1, Double::compare(Double::MIN_VALUE, -0.0));
    assertEquals(1, Double::compare(Double::MIN_VALUE, -1.2));
    assertEquals(0, Double::compare(Double::MIN_VALUE, Double::MIN_VALUE));
    assertEquals(1, Double::compare(Double::MIN_VALUE, Double::NEGATIVE_INFINITY));

    // Test value 1.2
    assertEquals(-1, Double::compare(1.2, Double::NaN));
    assertEquals(-1, Double::compare(1.2, Double::POSITIVE_INFINITY));
//    assertEquals(Double::compare(1.2, Double::MAX_VALUE));
    assertEquals(0, Double::compare(1.2, 1.2));
    assertEquals(1, Double::compare(1.2, 0.0));
    assertEquals(1, Double::compare(1.2, -0.0));
    assertEquals(1, Double::compare(1.2, -1.2));
    assertEquals(1, Double::compare(1.2, Double::MIN_VALUE));
    assertEquals(1, Double::compare(1.2, Double::NEGATIVE_INFINITY));

    // Test value 0.0
    assertEquals(-1, Double::compare(0.0, Double::NaN));
    assertEquals(-1, Double::compare(0.0, Double::POSITIVE_INFINITY));
//    assertEquals(Double::compare(0.0, Double::MAX_VALUE));
    assertEquals(-1, Double::compare(0.0, 1.2));
    assertEquals(0, Double::compare(0.0, 0.0));
    assertEquals(0, Double::compare(0.0, -0.0));  // error in OSX
    assertEquals(1, Double::compare(0.0, -1.2));
    assertEquals(-1, Double::compare(0.0, Double::MIN_VALUE));
    assertEquals(1, Double::compare(0.0, Double::NEGATIVE_INFINITY));

    // Test value -0.0
    assertEquals(-1, Double::compare(-0.0, Double::NaN));
    assertEquals(-1, Double::compare(-0.0, Double::POSITIVE_INFINITY));
//    assertEquals(Double::compare(-0.0, Double::MAX_VALUE));
    assertEquals(-1, Double::compare(-0.0, 1.2));
    assertEquals(0, Double::compare(-0.0, 0.0));  // error in OSX
    assertEquals(0, Double::compare(-0.0, -0.0));  // error in OSX
    assertEquals(1, Double::compare(-0.0, -1.2));
    assertEquals(-1, Double::compare(-0.0, Double::MIN_VALUE));
    assertEquals(1, Double::compare(-0.0, Double::NEGATIVE_INFINITY));

    // Test value -1.2
    assertEquals(-1, Double::compare(-1.2, Double::NaN));
    assertEquals(-1, Double::compare(-1.2, Double::POSITIVE_INFINITY));
//    assertEquals(Double::compare(-1.2, Double::MAX_VALUE));
    assertEquals(-1, Double::compare(-1.2, 1.2));
    assertEquals(-1, Double::compare(-1.2, 0.0));
    assertEquals(-1, Double::compare(-1.2, -0.0));
    assertEquals(0, Double::compare(-1.2, -1.2));
    assertEquals(-1, Double::compare(-1.2, Double::MIN_VALUE));
    assertEquals(1, Double::compare(-1.2, Double::NEGATIVE_INFINITY));
}

TEST (JavaLang, DoubleCompareTo) {
    Double variableCompareTo;

    // Test Double::NaN
    variableCompareTo = Double::NaN;
    assertEquals(0, variableCompareTo.compareTo(Double::NaN));
    assertEquals(1, variableCompareTo.compareTo(Double::POSITIVE_INFINITY));
//    assertEquals(variableCompareTo.compareTo(Double::MAX_VALUE), -9999);
    assertEquals(1, variableCompareTo.compareTo(1.2));
    assertEquals(1, variableCompareTo.compareTo(0.0));
    assertEquals(1, variableCompareTo.compareTo(-0.0));
    assertEquals(1, variableCompareTo.compareTo(-1.2));
//    assertEquals(variableCompareTo.compareTo(Double::MIN_VALUE), -9999);
    assertEquals(1, variableCompareTo.compareTo(Double::NEGATIVE_INFINITY));

    // Test Double::POSITIVE_INFINITY
    variableCompareTo = Double::POSITIVE_INFINITY;
    assertEquals(-1, variableCompareTo.compareTo(Double::NaN));
    assertEquals(0, variableCompareTo.compareTo(Double::POSITIVE_INFINITY));
//    assertEquals(variableCompareTo.compareTo( Double::MAX_VALUE), -9999);
    assertEquals(1, variableCompareTo.compareTo(1.2));
    assertEquals(1, variableCompareTo.compareTo(0.0));
    assertEquals(1, variableCompareTo.compareTo(-0.0));
    assertEquals(1, variableCompareTo.compareTo(-1.2));
//    assertEquals(variableCompareTo.compareTo(Double::MIN_VALUE), -9999);
    assertEquals(1, variableCompareTo.compareTo(Double::NEGATIVE_INFINITY));

    // Test Double::NEGATIVE_INFINITY
    variableCompareTo = Double::NEGATIVE_INFINITY;
    assertEquals(-1, variableCompareTo.compareTo(Double::NaN));
    assertEquals(-1, variableCompareTo.compareTo(Double::POSITIVE_INFINITY));
//    assertEquals(variableCompareTo.compareTo(Double::MAX_VALUE), -9999);
    assertEquals(-1, variableCompareTo.compareTo(1.2));
    assertEquals(-1, variableCompareTo.compareTo(0.0));
    assertEquals(-1, variableCompareTo.compareTo(-0.0));
    assertEquals(-1, variableCompareTo.compareTo(-1.2));
//    assertEquals(variableCompareTo.compareTo(Double::MIN_VALUE), -9999);
    assertEquals(0, variableCompareTo.compareTo(Double::NEGATIVE_INFINITY));

    // Test Double::MAX_VALUE
//    variableCompareTo = Double::MAX_VALUE;
//    assertEquals(variableCompareTo.compareTo(Double::NaN), -9999);
//    assertEquals(variableCompareTo.compareTo(Double::POSITIVE_INFINITY), -9999);
//    assertEquals(variableCompareTo.compareTo(Double::MAX_VALUE));
//    assertEquals(variableCompareTo.compareTo(1.2));
//    assertEquals(variableCompareTo.compareTo(0.0));
//    assertEquals(variableCompareTo.compareTo(-0.0));
//    assertEquals(variableCompareTo.compareTo(-1.2));
//    assertEquals(variableCompareTo.compareTo(Double::MIN_VALUE));
//    assertEquals(variableCompareTo.compareTo(Double::NEGATIVE_INFINITY), -9999);

    // Test Double::MIN_VALUE
    variableCompareTo = Double::MIN_VALUE;
    assertEquals(-1, variableCompareTo.compareTo(Double::NaN));
    assertEquals(-1, variableCompareTo.compareTo(Double::POSITIVE_INFINITY));
//    assertEquals(variableCompareTo.compareTo(Double::MAX_VALUE));
    assertEquals(-1, variableCompareTo.compareTo(1.2));
//    assertEquals(variableCompareTo.compareTo(0.0));
//    assertEquals(variableCompareTo.compareTo(-0.0));
//    assertEquals(variableCompareTo.compareTo(-1.2));
    assertEquals(0, variableCompareTo.compareTo(Double::MIN_VALUE));
    assertEquals(1, variableCompareTo.compareTo(Double::NEGATIVE_INFINITY));

    // Test value 1.2
    variableCompareTo = 1.2;
    assertEquals(-1, variableCompareTo.compareTo(Double::NaN));
    assertEquals(-1, variableCompareTo.compareTo(Double::POSITIVE_INFINITY));
//    assertEquals(variableCompareTo.compareTo(Double::MAX_VALUE));
    assertEquals(0, variableCompareTo.compareTo(1.2));
    assertEquals(1, variableCompareTo.compareTo(0.0));
//    assertEquals(variableCompareTo.compareTo(-0.0));
    assertEquals(1, variableCompareTo.compareTo(-1.2));
//    assertEquals(variableCompareTo.compareTo(Double::MIN_VALUE));
    assertEquals(1, variableCompareTo.compareTo(Double::NEGATIVE_INFINITY));

    // Test value 0.0
    variableCompareTo = 0.0;
    assertEquals(-1, variableCompareTo.compareTo(Double::NaN));
    assertEquals(-1, variableCompareTo.compareTo(Double::POSITIVE_INFINITY));
//    assertEquals(variableCompareTo.compareTo(Double::MAX_VALUE));
    assertEquals(-1, variableCompareTo.compareTo(1.2));
    assertEquals(0, variableCompareTo.compareTo(0.0));
//    assertEquals(variableCompareTo.compareTo(-0.0));  // error in OSX
    assertEquals(1, variableCompareTo.compareTo(-1.2));
//    assertEquals(variableCompareTo.compareTo(Double::MIN_VALUE));
    assertEquals(1, variableCompareTo.compareTo(Double::NEGATIVE_INFINITY));

    // Test value -0.0
    variableCompareTo = -0.0;
    assertEquals(-1, variableCompareTo.compareTo(Double::NaN));
    assertEquals(-1, variableCompareTo.compareTo(Double::POSITIVE_INFINITY));
//    assertEquals(variableCompareTo.compareTo(Double::MAX_VALUE));
    assertEquals(-1, variableCompareTo.compareTo(1.2));
    assertEquals(0, variableCompareTo.compareTo(0.0));  // error in OSX
    assertEquals(0, variableCompareTo.compareTo(-0.0));
    assertEquals(1, variableCompareTo.compareTo(-1.2));
    assertEquals(-1, variableCompareTo.compareTo(Double::MIN_VALUE));
    assertEquals(1, variableCompareTo.compareTo(Double::NEGATIVE_INFINITY));

    // Test value -1.2
    variableCompareTo = -1.2;
    assertEquals(-1, variableCompareTo.compareTo(Double::NaN));
    assertEquals(-1, variableCompareTo.compareTo(Double::POSITIVE_INFINITY));
//    assertEquals(variableCompareTo.compareTo(Double::MAX_VALUE));
    assertEquals(-1, variableCompareTo.compareTo(1.2));
    assertEquals(-1, variableCompareTo.compareTo(0.0));
    assertEquals(-1, variableCompareTo.compareTo(-0.0));
    assertEquals(0, variableCompareTo.compareTo(-1.2));
//    assertEquals(variableCompareTo.compareTo(Double::MIN_VALUE));
    assertEquals(1, variableCompareTo.compareTo(Double::NEGATIVE_INFINITY));
}

TEST (JavaLang, DoubleToRawLongBits) {
    // Create variable to test
    double input;
    long expectedResult;
    long actualResult;

    // Input 0.0
    input = 0.0;
    expectedResult = 0;
    actualResult = Double::doubleToRawLongBits(input);
    assertEquals(expectedResult, actualResult);

    // Input Double::POSITIVE_INFINITY
    input = Double::POSITIVE_INFINITY;
    expectedResult = 9218868437227405312;
    actualResult = Double::doubleToRawLongBits(input);
    assertEquals(expectedResult, actualResult);

    // Input Double::NEGATIVE_INFINITY
    input = Double::NEGATIVE_INFINITY;
    expectedResult = -9218868437227405312;
    actualResult = Double::doubleToRawLongBits(input);
    assertEquals(expectedResult, actualResult);

    // Input Double::NaN
    input = Double::NaN;
    expectedResult = 9223372036854775807;
    actualResult = Double::doubleToRawLongBits(input);
    assertEquals(expectedResult, actualResult);

    // Input -0.7
    input = -0.7;
    expectedResult = -4604480259023595110;
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

TEST (JavaLang, DoubleToLongBits) {
    // Create variable to test
    double input;
    long expectedResult;
    long actualResult;

    // Input 0.0
    input = 0.0;
    expectedResult = 0;
    actualResult = Double::doubleToLongBits(input);
    assertEquals(expectedResult, actualResult);

    // Input Double::POSITIVE_INFINITY
    input = Double::POSITIVE_INFINITY;
    expectedResult = 9218868437227405312;
    actualResult = Double::doubleToLongBits(input);
    assertEquals(expectedResult, actualResult);

    // Input Double::NEGATIVE_INFINITY
    input = Double::NEGATIVE_INFINITY;
    expectedResult = -9218868437227405312;
    actualResult = Double::doubleToLongBits(input);
    assertEquals(expectedResult, actualResult);

    // Input Double::NaN
    input = Double::NaN;
    expectedResult = 9223372036854775807;
    actualResult = Double::doubleToLongBits(input);
    assertEquals(expectedResult, actualResult);

    // Input -0.7
    input = -0.7;
    expectedResult = -4604480259023595110;
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
TEST (JavaLang, DoubleEquals) {
    // Create variable to test
    Double variableDoubleEquals;
    Double DOUBLE_NaN = Double::NaN;
    Double DOUBLE_POSITIVE_INFINITY = Double::POSITIVE_INFINITY;
    Double DOUBLE_NEGATIVE_INFINITY = Double::NEGATIVE_INFINITY;
    Double DOUBLE_MAX_VALUE = Double::MAX_VALUE;
    Double DOUBLE_MIN_VALUE = Double::MIN_VALUE;

    // Test Double::NaN
    variableDoubleEquals = Double::NaN;
    assertEquals(1, variableDoubleEquals.equals(DOUBLE_NaN));
    assertEquals(0, variableDoubleEquals.equals(DOUBLE_POSITIVE_INFINITY));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MAX_VALUE));
    assertEquals(0, variableDoubleEquals.equals((Double) 1.2));
    assertEquals(0, variableDoubleEquals.equals((Double) 0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-0.0));
    assertEquals(0, variableDoubleEquals.equals((Double) -1.2));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MIN_VALUE));
    assertEquals(0, variableDoubleEquals.equals(DOUBLE_NEGATIVE_INFINITY));

    // Test DOUBLE_POSITIVE_INFINITY
    variableDoubleEquals = DOUBLE_POSITIVE_INFINITY;
    assertEquals(0, variableDoubleEquals.equals(DOUBLE_NaN));
    assertEquals(1, variableDoubleEquals.equals(DOUBLE_POSITIVE_INFINITY));
//    assertEquals(variableDoubleEquals.equals( DOUBLE_MAX_VALUE), -9999);
    assertEquals(0, variableDoubleEquals.equals((Double) 1.2));
    assertEquals(0, variableDoubleEquals.equals((Double) 0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-0.0), -9999);
    assertEquals(0, variableDoubleEquals.equals((Double) -1.2));
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
    assertEquals(0, variableDoubleEquals.equals((Double) 1.2));
    assertEquals(0, variableDoubleEquals.equals((Double) 0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-0.0), -9999);
    assertEquals(0, variableDoubleEquals.equals((Double) -1.2));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MIN_VALUE), -9999);
    assertEquals(1, variableDoubleEquals.equals(DOUBLE_NEGATIVE_INFINITY));

    // Test value (Double)1.2
    variableDoubleEquals = (Double) 1.2;
    assertEquals(0, variableDoubleEquals.equals(DOUBLE_NaN));
    assertEquals(0, variableDoubleEquals.equals(DOUBLE_POSITIVE_INFINITY));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MAX_VALUE));
    assertEquals(1, variableDoubleEquals.equals((Double) 1.2));
    assertEquals(0, variableDoubleEquals.equals((Double) 0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-0.0));
    assertEquals(0, variableDoubleEquals.equals((Double) -1.2));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MIN_VALUE));
    assertEquals(0, variableDoubleEquals.equals(DOUBLE_NEGATIVE_INFINITY));

    // Test value (Double)0.0
    variableDoubleEquals = (Double) 0.0;
    assertEquals(0, variableDoubleEquals.equals(DOUBLE_NaN));
    assertEquals(0, variableDoubleEquals.equals(DOUBLE_POSITIVE_INFINITY));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MAX_VALUE));
    assertEquals(0, variableDoubleEquals.equals((Double) 1.2));
    assertEquals(1, variableDoubleEquals.equals((Double) 0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-0.0));
    assertEquals(0, variableDoubleEquals.equals((Double) -1.2));
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
    variableDoubleEquals = (Double) -1.2;
    assertEquals(0, variableDoubleEquals.equals(DOUBLE_NaN));
    assertEquals(0, variableDoubleEquals.equals(DOUBLE_POSITIVE_INFINITY));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MAX_VALUE));
    assertEquals(0, variableDoubleEquals.equals((Double) 1.2));
    assertEquals(0, variableDoubleEquals.equals((Double) 0.0));
//    assertEquals(variableDoubleEquals.equals((Double)-0.0));
    assertEquals(1, variableDoubleEquals.equals((Double) -1.2));
//    assertEquals(variableDoubleEquals.equals(DOUBLE_MIN_VALUE));
    assertEquals(0, variableDoubleEquals.equals(DOUBLE_NEGATIVE_INFINITY));
}

TEST (JavaLang, DoubleHashCode) {
    // Create variable to test
    double input;
    long expectedResult;
    long actualResult;

    // Input 0.0
    input = 0.0;
    expectedResult = 0;
    actualResult = Double::hashCode(input);
    assertEquals(expectedResult, actualResult);

    // Input Double::POSITIVE_INFINITY
    input = Double::POSITIVE_INFINITY;
    expectedResult = 9218868439373840384;
    actualResult = Double::hashCode(input);
    assertEquals(expectedResult, actualResult);

    // Input Double::NEGATIVE_INFINITY
    input = Double::NEGATIVE_INFINITY;
    expectedResult = 9218868435080970240;
    actualResult = Double::hashCode(input);
    assertEquals(expectedResult, actualResult);

    // Input Double::NaN
    input = Double::NaN;
    expectedResult = 9223372034707292160;
    actualResult = Double::hashCode(input);
    assertEquals(expectedResult, actualResult);

    // Input -0.7
    input = -0.7;
    expectedResult = 4604480258807169027;
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

TEST (JavaLang, DoubleHashCodeNotInput) {
    // Create variable to test
    Double variableDouble;
    long expectedResult;
    long actualResult;

    // Input 0.0
    variableDouble = 0.0;
    expectedResult = 0;
    actualResult = variableDouble.hashCode();
    assertEquals(expectedResult, actualResult);

    // Input Double::POSITIVE_INFINITY
    variableDouble = Double::POSITIVE_INFINITY;
    expectedResult = 9218868439373840384;
    actualResult = variableDouble.hashCode();
    assertEquals(expectedResult, actualResult);

    // Input Double::NEGATIVE_INFINITY
    variableDouble = Double::NEGATIVE_INFINITY;
    expectedResult = 9218868435080970240;
    actualResult = variableDouble.hashCode();
    assertEquals(expectedResult, actualResult);

    // Input Double::NaN
    variableDouble = Double::NaN;
    expectedResult = 9223372034707292160;
    actualResult = variableDouble.hashCode();
    assertEquals(expectedResult, actualResult);

    // Input -0.7
    variableDouble = -0.7;
    expectedResult = 4604480258807169027;
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

TEST (JavaLang, DoubleIsFinite) {
    assertTrue(Double::isFinite(13.02));
    assertTrue(Double::isFinite(130.2));
    assertFalse(Double::isFinite(Double::POSITIVE_INFINITY));
    assertFalse(Double::isFinite(Double::NEGATIVE_INFINITY));
}

TEST (JavaLang, DoubleIsInfinite) {
    assertTrue(Double::isInfinite(Double::POSITIVE_INFINITY));
    assertTrue(Double::isInfinite(Double::NEGATIVE_INFINITY));
    assertFalse(Double::isInfinite(13.02));
    assertFalse(Double::isInfinite(130.2));
}

TEST (JavaLang, DoubleIsInfinite2) {
    Double variableIsInfinite2;

    variableIsInfinite2 = Double::POSITIVE_INFINITY;
    assertTrue(variableIsInfinite2.isInfinite());

    variableIsInfinite2 = Double::NEGATIVE_INFINITY;
    assertTrue(variableIsInfinite2.isInfinite());

    variableIsInfinite2 = 13.02;
    assertFalse(variableIsInfinite2.isInfinite());
}

TEST (JavaLang, DoubleIsNaN) {
    assertTrue(Double::isNaN(Double::NaN));
    assertFalse(Double::isNaN(Double::NEGATIVE_INFINITY));
    assertFalse(Double::isNaN(13.02));
    assertFalse(Double::isNaN(130.2));
}

TEST (JavaLang, DoubleIsNaN2) {
    Double variableIsInfinite2;

    variableIsInfinite2 = Double::NaN;
    assertTrue(variableIsInfinite2.isNaN());

    variableIsInfinite2 = Double::NEGATIVE_INFINITY;
    assertFalse(variableIsInfinite2.isNaN());

    variableIsInfinite2 = 13.02;
    assertFalse(variableIsInfinite2.isNaN());
}

TEST (JavaLang, DoubleMin) {
    double variableDoubleMin1;
    double variableDoubleMin2;
    double expectedResultDoubleMin;
    double actualResultDoubleMin;

    variableDoubleMin1 = 13.02;
    variableDoubleMin2 = 1.302;
    expectedResultDoubleMin = 1.302;
    actualResultDoubleMin = Double::min(variableDoubleMin1, variableDoubleMin2);
    assertEquals(expectedResultDoubleMin, actualResultDoubleMin);

    variableDoubleMin1 = 13.02;
    variableDoubleMin2 = 1.302;
    expectedResultDoubleMin = 13.02;
    actualResultDoubleMin = Double::min(variableDoubleMin1, variableDoubleMin2);
    assertNotEquals(expectedResultDoubleMin, actualResultDoubleMin);
}

TEST (JavaLang, DoubleLongBitsToDouble) {
    // Create variable to test
    long longBitsInput;
    double expectedResult;
    double actualResult;

    // Input 0.0
    longBitsInput = 0;
    expectedResult = 0.0;
    actualResult = Double::longBitsToDouble(longBitsInput);
    assertEquals(expectedResult, actualResult);

    // Input Double::POSITIVE_INFINITY
    longBitsInput = 9218868437227405312;
    expectedResult = Double::POSITIVE_INFINITY;
    actualResult = Double::longBitsToDouble(longBitsInput);
    assertEquals(expectedResult, actualResult);

    // Input Double::NEGATIVE_INFINITY
    longBitsInput = -9218868437227405312;
    expectedResult = Double::NEGATIVE_INFINITY;
    actualResult = Double::longBitsToDouble(longBitsInput);
    assertEquals(expectedResult, actualResult);


    // Input -0.7
    longBitsInput = -4604480259023595110;
    expectedResult = -0.7;
    actualResult = Double::longBitsToDouble(longBitsInput);
    assertEquals(expectedResult, actualResult);

    // Input 12.375
    longBitsInput = 4623156123728347136;
    expectedResult = 12.375;
    actualResult = Double::longBitsToDouble(longBitsInput);
    assertEquals(expectedResult, actualResult);

    // Input 1.0
    longBitsInput = 4607182418800017408;
    expectedResult = 1.0;
    actualResult = Double::longBitsToDouble(longBitsInput);
    assertEquals(expectedResult, actualResult);

    // Input 0.375
    longBitsInput = 4600427019358961664;
    expectedResult = 0.375;
    actualResult = Double::longBitsToDouble(longBitsInput);
    assertEquals(expectedResult, actualResult);

    // Input -2
    longBitsInput = -4611686018427387904;
    expectedResult = -2.0;
    actualResult = Double::longBitsToDouble(longBitsInput);
    assertEquals(expectedResult, actualResult);

    // Input 83
    longBitsInput = 4635541022703616000;
    expectedResult = 83.0;
    actualResult = Double::longBitsToDouble(longBitsInput);
    assertEquals(expectedResult, actualResult);

    // Input -2625
    longBitsInput = -4657990851119546368;
    expectedResult = -2625.0;
    actualResult = Double::longBitsToDouble(longBitsInput);
    assertEquals(expectedResult, actualResult);

    // Input 0.5
    longBitsInput = 4602678819172646912;
    expectedResult = 0.5;
    actualResult = Double::longBitsToDouble(longBitsInput);
    assertEquals(expectedResult, actualResult);

    // Input -1302.12345678
    longBitsInput = -4653441614972469831;
    expectedResult = -1302.12345678;
    actualResult = Double::longBitsToDouble(longBitsInput);
    assertEquals(expectedResult, actualResult);
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