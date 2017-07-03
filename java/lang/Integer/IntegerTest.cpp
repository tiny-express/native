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

#include "Integer.hpp"

using namespace Java::Lang;

/// TEST IntegerConstructor
TEST (JavaLang, IntegerConstructor) {
    // Input an empty value to Integer constructor and assign value - Return integer
    Integer emptyIntegerConstructor;
    emptyIntegerConstructor = 3;
    ASSERT_EQUAL(3, emptyIntegerConstructor.intValue());

    // Given value for Integer constructor and assign value - Return integer
    Integer validIntegerConstructor = 3;
    ASSERT_EQUAL(3, validIntegerConstructor.intValue());

    // Given string value for Integer constructor and assign value - Return integer
    Integer validIntegerPointerConstructor = Integer::parseInt("13");
    ASSERT_EQUAL(13, validIntegerPointerConstructor.intValue());
}

/// TEST IntegerComparision
TEST (JavaLang, IntegerComparision) {
    //Give a valid number and make a comparision
    Integer validNumberComparision = 2;
    Integer targetNumberComparision;

    // Test validNumber is equal targetNumber
    targetNumberComparision = 2;
    ASSERT_TRUE(validNumberComparision == targetNumberComparision);

    // Test validNumber is not equal targetNumber
    targetNumberComparision = 101;
    ASSERT_TRUE(validNumberComparision != targetNumberComparision);

    // Test validNumber is less than targetNumber
    targetNumberComparision = 3;
    ASSERT_TRUE(validNumberComparision < targetNumberComparision);

    // Test validNumber is equal or less than targetNumber
    targetNumberComparision = 3;
    ASSERT_TRUE(validNumberComparision <= targetNumberComparision);

    // Test validNumber is more than targetNumber
    targetNumberComparision = 1;
    ASSERT_TRUE(validNumberComparision> targetNumberComparision);

    // Test validNumber is equal or more than targetNumber
    targetNumberComparision = 2;
    ASSERT_TRUE(validNumberComparision >= targetNumberComparision);
}

/// TEST IntegerOperator
TEST (JavaLang, IntegerOperator) {
    // Given a valid number
    Integer validNumberOperator = 5;
    Integer targetNumberOperator = 3;

    // Make a summation with targetNumber
    Integer summationNumberOperator = 8;
    ASSERT_TRUE(summationNumberOperator == ( validNumberOperator + targetNumberOperator ));

    // Make a subtraction with targetNumber
    Integer subtractionNumberOperator = 2;
    ASSERT_TRUE(subtractionNumberOperator == ( validNumberOperator - targetNumberOperator ));

    // Make a multiplication with targetNumber
    Integer multiplicationNumberOperator = 15;
    ASSERT_TRUE(multiplicationNumberOperator == ( validNumberOperator * targetNumberOperator ));

    // Make a division with targetNumber
    Integer divisionNumberOperator = 1;
    ASSERT_TRUE(divisionNumberOperator == ( validNumberOperator / targetNumberOperator ));

    // Make a modulo with targetNumber
    Integer modNumberOperator = 2;
    ASSERT_TRUE(modNumberOperator == ( validNumberOperator % targetNumberOperator ));
}

/// TEST IntegerParseInt
TEST (JavaLang, IntegerParseInt) {
#ifdef __APPLE__
    return;
#endif
    // Given value for Integer constructor and assign value - Return integer
    Integer validIntegerPointerParseInt = Integer::parseInt("6");
    ASSERT_EQUAL(6, validIntegerPointerParseInt.intValue());
}

/// TEST IntegerCompareTo
TEST (JavaLang, IntegerCompareTo) {
    /// Given valid Integer to compare with target
    Integer validValueCompareTo = 15;
    Integer lessThanValueCompareTo = 12;
    Integer equalValueCompareTo = 15;
    Integer moreThanValueCompareTo = 20;

    // Return 1 if validValue is more than lessThanValue
    ASSERT_EQUAL(1, validValueCompareTo.compareTo(lessThanValueCompareTo));

    // Return 0 if validValue is more than equalValue
    ASSERT_EQUAL(0, validValueCompareTo.compareTo(equalValueCompareTo));

    // Return -1 if validValue is less than moreThanValue
    ASSERT_EQUAL(-1, validValueCompareTo.compareTo(moreThanValueCompareTo));

    // TODO - loint@foodtiny.com will review this case again
    Integer integerCompareTo = 1;
    Comparable<Integer> *comparable = &validValueCompareTo;
    ASSERT_EQUAL(1, comparable->compareTo(integerCompareTo));
}

/// TEST IntegerToString
TEST (JavaLang, IntegerToString) {
    // Input different values of type int to compare to the realResult of Integer::toString
    Integer zeroIntegerToString = 0;
    Integer oneIntegerToString = 1;
    Integer positiveIntegerToString = 10;
    Integer maxIntegerToString = 2147483647;
    Integer minIntegerToString = -2147483647;

    // Make a comparison between expected realResult and the real result
    string expectedResultToString= "0";
    string realResultToString = zeroIntegerToString.toString();
    ASSERT_STR(expectedResultToString, realResultToString);

    // Make a comparison between expected realResult and the real result
    expectedResultToString= "1";
    realResultToString = oneIntegerToString.toString();
    ASSERT_STR(expectedResultToString, realResultToString);

    // Make a comparison between expected realResult and the real result
    expectedResultToString= "10";
    realResultToString = positiveIntegerToString.toString();
    ASSERT_STR(expectedResultToString, realResultToString);

    // Make a comparison between expected realResult and the real result
    expectedResultToString= "2147483647";
    realResultToString = maxIntegerToString.toString();
    ASSERT_STR(expectedResultToString, realResultToString);

    // Make a comparison between expected realResult and the real result
    expectedResultToString= "-2147483647";
    realResultToString = minIntegerToString.toString();
    ASSERT_STR(expectedResultToString, realResultToString);
}

/// TEST IntegerCharValue
TEST (JavaLang, IntegerCharValue) {
    // Input different values of type int to compare to the result of Integer::charValue
    Integer zeroIntegerCharValue = 0;
    Integer oneIntegerCharValue = 1;
    Integer positiveIntegerCharValue = 10;
    Integer maxIntegerCharValue = 2147483647;
    Integer minIntegerCharValue = -2147483647;

    // Make a comparison between expected result and the real result
    char expectedResultCharValue = '0';
    char realResultCharValue = zeroIntegerCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue, realResultCharValue);

    // Make a comparison between expected result and the real result
    expectedResultCharValue= '1';
    realResultCharValue = oneIntegerCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue, realResultCharValue);

    // Make a comparison between expected result and the real result
    expectedResultCharValue = '1';
    realResultCharValue = positiveIntegerCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue, realResultCharValue);

    // Make a comparison between expected result and the real result
    expectedResultCharValue = '2';
    realResultCharValue = maxIntegerCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue, realResultCharValue);

    // Make a comparison between expected result and the real result
    expectedResultCharValue = '-';
    realResultCharValue = minIntegerCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue, realResultCharValue);

}

/// TEST IntegerStringValue
TEST (JavaLang, IntegerStringValue) {
    // Input different values of type int to compare to the result of Integer::stringValue
    Integer zeroIntegerStringValue = 0;
    Integer oneIntegerStringValue = 1;
    Integer positiveIntegerStringValue = 10;
    Integer maxIntegerStringValue = 2147483647;
    Integer minIntegerStringValue = -2147483647;

    // Make a comparison between expected result and the real result
    string expectedResultStringValue = "0";
    string realResultStringValue = zeroIntegerStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, realResultStringValue);

    // Make a comparison between expected result and the real result
    expectedResultStringValue = "1";
    realResultStringValue  = oneIntegerStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, realResultStringValue );

    // Make a comparison between expected result and the real result
    expectedResultStringValue = "10";
    realResultStringValue = positiveIntegerStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, realResultStringValue);

    // Make a comparison between expected result and the real result
    expectedResultStringValue = "2147483647";
    realResultStringValue = maxIntegerStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, realResultStringValue);

    // Make a comparison between expected result and the real result
    expectedResultStringValue = "-2147483647";
    realResultStringValue = minIntegerStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, realResultStringValue);
}

/// TEST IntegerShortValue
TEST (JavaLang, IntegerShortValue) {
    // Input different values of type int to compare to the result of Integer::shortValue
    Integer positiveIntegerShortValue = 1302;
    Integer negativeIntegerShortValue = -1302;
    Integer notExpectedIntegerShortValue = 9999;

    // Make a comparison between expected result and the real result
    short expectedResultShortValue = 1302;
    short realResultShortValue = positiveIntegerShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue, realResultShortValue);

    // Make a comparison between expected result and the real result
    expectedResultShortValue = -1302;
    realResultShortValue = negativeIntegerShortValue.shortValue();
    ASSERT_EQUAL(expectedResultShortValue, realResultShortValue);

    // Make a comparison between expected result and the real result
    short notExpectedResultShortValue = -1111;
    realResultShortValue = notExpectedIntegerShortValue.shortValue();
    ASSERT_NOT_EQUAL(notExpectedResultShortValue, realResultShortValue);
}

/// TEST IntegerIntValue
TEST (JavaLang, IntegerIntValue) {
    // Input different values of type int to compare to the realResult of Integer::intValue
    Integer zeroIntegerIntValue = 0;
    Integer oneIntegerIntValue = 1;
    Integer positiveIntegerIntValue = 10;
    Integer maxIntegerIntValue = 2147483647;
    Integer minIntegerIntValue = -2147483647;
    Integer notExpectedIntegerIntValue = 1111;

    // Make a comparison between expected realResult and the real result
    int expectedResultIntValue= 0;
    int realResultIntValue = zeroIntegerIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, realResultIntValue);

    // Make a comparison between expected realResult and the real result
    expectedResultIntValue= 1;
    realResultIntValue = oneIntegerIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, realResultIntValue);

    // Make a comparison between expected realResult and the real result
    expectedResultIntValue= 10;
    realResultIntValue = positiveIntegerIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, realResultIntValue);

    // Make a comparison between expected realResult and the real result
    expectedResultIntValue= 2147483647;
    realResultIntValue = maxIntegerIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, realResultIntValue);

    // Make a comparison between expected realResult and the real result
    expectedResultIntValue= -2147483647;
    realResultIntValue = minIntegerIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, realResultIntValue);

    // Make a comparison between expected realResult and the real result
    int notExpectedResult= 9999;
    realResultIntValue = minIntegerIntValue.intValue();
    ASSERT_NOT_EQUAL(notExpectedResult, realResultIntValue);
}

/// TEST IntegerLongValue
TEST (JavaLang, IntegerLongValue) {
    // Input different values of type int to compare to the realResult of Integer::longValue
    Integer positiveIntegerLongValue = 1302321013;
    Integer negativeIntegerLongValue = -1302321013;
    Integer notExpectedIntegerLongValue = -12345;

    // Make a comparison between expected realResult and the real result
    long expectedResultLongValue = 1302321013;
    long realResultLongValue = positiveIntegerLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue, realResultLongValue);

    // Make a comparison between expected realResult and the real result
    expectedResultLongValue = -1302321013;
    realResultLongValue = negativeIntegerLongValue.longValue();
    ASSERT_EQUAL(expectedResultLongValue, realResultLongValue);

    // Make a comparison between the not expected realResult and the real result
    long notExpectedResult = -11111;
    realResultLongValue = notExpectedIntegerLongValue.longValue();
    ASSERT_FALSE(notExpectedResult == realResultLongValue);
}

/// TEST IntegerFloatValue
TEST (JavaLang, IntegerFloatValue) {
    // Input different values of type int to compare to the realResult of Integer::floatValue
    Integer positiveIntegerFloatValue = 12345;
    float expectedResultFloatValue = 12345.00;
    float realResultFloatValue = positiveIntegerFloatValue.floatValue();
    ASSERT_TRUE(expectedResultFloatValue == realResultFloatValue);


    Integer negativeInteger = -12345;
    expectedResultFloatValue = -12345.00;
    realResultFloatValue = negativeInteger.floatValue();
    ASSERT_TRUE(expectedResultFloatValue == realResultFloatValue);
}

/// TEST IntegerDoubleValue
TEST (JavaLang, IntegerDoubleValue) {
    // Input different values of type int to compare to the realResult of Integer::doubleValue
    Integer positiveIntegerDoubleValue = 123456789;
    double expectedResultDoubleValue = 123456789.0000000;
    double realResultDoubleValue = positiveIntegerDoubleValue.doubleValue();
    ASSERT_TRUE(expectedResultDoubleValue == realResultDoubleValue);

    Integer negativeInteger = -123456789;
    expectedResultDoubleValue = -123456789.0000000;
    realResultDoubleValue = negativeInteger.doubleValue();
    ASSERT_TRUE(expectedResultDoubleValue == realResultDoubleValue);
}