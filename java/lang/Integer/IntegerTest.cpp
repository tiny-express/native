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
#define string char*
TEST (JavaLang, IntegerConstructor) {
    // Given empty value for Integer constructor and assign value - Return integer
    Integer emptyInteger;
    emptyInteger = 3;
    ASSERT_EQUAL(3, emptyInteger.intValue());

    // Given value for Integer constructor and assign value - Return string
    Integer validInteger = 3;
    ASSERT_EQUAL(3, validInteger.intValue());
}
TEST (JavaLang, IntegerComparision) {
    //Give a valid number and make a comparision
    Integer validNumber = 2;
    Integer targetNumber;

    // Test validNumber is equal targetNumber
    targetNumber = 2;
    ASSERT_TRUE(validNumber == targetNumber);

    // Test validNumber is not equal targetNumber
    targetNumber = 101;
    ASSERT_TRUE(validNumber != targetNumber);

    // Test validNumber is less than targetNumber
    targetNumber = 3;
    ASSERT_TRUE(validNumber < targetNumber);

    // Test validNumber is equal or less than targetNumber
    targetNumber = 3;
    ASSERT_TRUE(validNumber <= targetNumber);

    // Test validNumber is more than targetNumber
    targetNumber = 1;
    ASSERT_TRUE(validNumber > targetNumber);

    // Test validNumber is equal or more than targetNumber
    targetNumber = 2;
    ASSERT_TRUE(validNumber >= targetNumber);
}
TEST (JavaLang, IntegerOperator) {
    // Given a valid number
    Integer validNumber = 5;
    Integer targetNumber = 3;

    // Make a summation with targetNumber
    Integer summationNumber = 8;
    ASSERT_TRUE(summationNumber == ( validNumber + targetNumber ));

    // Make a subtraction with targetNumber
    Integer subtractionNumber = 2;
    ASSERT_TRUE(subtractionNumber == ( validNumber - targetNumber ));

    // Make a multiplication with targetNumber
    Integer multiplicationNumber = 15;
    ASSERT_TRUE(multiplicationNumber == ( validNumber * targetNumber ));

    // Make a division with targetNumber
    Integer divisionNumber = 1;
    ASSERT_TRUE(divisionNumber == ( validNumber / targetNumber ));

    // Make a modulo with targetNumber
    Integer modNumber = 2;
    ASSERT_TRUE(modNumber == ( validNumber % targetNumber ));
}
TEST (JavaLang, IntegerParseInt) {
#ifdef __APPLE__
    return;
#endif
    // Given value for Integer constructor and assign value - Return integer
    Integer validIntegerPointer = Integer::parseInt("6");
    ASSERT_EQUAL(6, validIntegerPointer.intValue());
}
TEST (JavaLang, IntegerCompareTo) {
    /// Given valid Integer to compare with target
    Integer validValue = 15;
    Integer lessThanValue = 12;
    Integer equalValue = 15;
    Integer moreThanValue = 20;

    // Return 1 if validValue is more than lessThanValue
    ASSERT_EQUAL(1, validValue.compareTo(lessThanValue));

    // Return 0 if validValue is more than equalValue
    ASSERT_EQUAL(0, validValue.compareTo(equalValue));

    // Return -1 if validValue is less than moreThanValue
    ASSERT_EQUAL(-1, validValue.compareTo(moreThanValue));

    // TODO - loint@foodtiny.com will review this case again
    Integer integer = 1;
    Comparable<Integer> *comparable = &validValue;
    ASSERT_EQUAL(1, comparable->compareTo(integer));
}
TEST (JavaLang, IntegerToString) {
    // Input different values of type int to compare to the realResult of Integer::toString
    Integer zeroInteger = 0;
    Integer oneInteger = 1;
    Integer positiveInteger = 10;
    Integer maxInteger = 2147483647;
    Integer minInteger = -2147483647;

    // Make a comparison between expected realResult and the real result
    string expectedResult= "0";
    string realResult = zeroInteger.toString();
    ASSERT_STR(expectedResult, realResult);
    free(realResult);

    // Make a comparison between expected realResult and the real result
    expectedResult= "1";
    realResult = oneInteger.toString();
    ASSERT_STR(expectedResult, realResult);
    free(realResult);

    // Make a comparison between expected realResult and the real result
    expectedResult= "10";
    realResult = positiveInteger.toString();
    ASSERT_STR(expectedResult, realResult);
    free(realResult);

    // Make a comparison between expected realResult and the real result
    expectedResult= "2147483647";
    realResult = maxInteger.toString();
    ASSERT_STR(expectedResult, realResult);
    free(realResult);

    // Make a comparison between expected realResult and the real result
    expectedResult= "-2147483647";
    realResult = minInteger.toString();
    ASSERT_STR(expectedResult, realResult);
    free(realResult);

}
TEST (JavaLang, IntegerCharValue) {
    // Input different values of type int to compare to the result of Integer::charValue
    Integer zeroInteger = 0;
    Integer oneInteger = 1;
    Integer positiveInteger = 10;
    Integer maxInteger = 2147483647;
    Integer minInteger = -2147483647;

    // Make a comparison between expected result and the real result
    char expectedResult = '0';
    char realResult = zeroInteger.charValue();
    ASSERT_EQUAL(expectedResult, realResult);

    // Make a comparison between expected result and the real result
    expectedResult= '1';
    realResult = oneInteger.charValue();
    ASSERT_EQUAL(expectedResult, realResult);

    // Make a comparison between expected result and the real result
    expectedResult = '1';
    realResult = positiveInteger.charValue();
    ASSERT_EQUAL(expectedResult, realResult);

    // Make a comparison between expected result and the real result
    expectedResult = '2';
    realResult = maxInteger.charValue();
    ASSERT_EQUAL(expectedResult, realResult);

    // Make a comparison between expected result and the real result
    expectedResult = '-';
    realResult = minInteger.charValue();
    ASSERT_EQUAL(expectedResult, realResult);

}
TEST (JavaLang, IntegerStringValue) {
    // Input different values of type int to compare to the result of Integer::stringValue
    Integer zeroInteger = 0;
    Integer oneInteger = 1;
    Integer positiveInteger = 10;
    Integer maxInteger = 2147483647;
    Integer minInteger = -2147483647;

    // Make a comparison between expected result and the real result
    string expectedResult = "0";
    string realResult = zeroInteger.stringValue();
    ASSERT_STR(expectedResult, realResult);
    free(realResult);

    // Make a comparison between expected result and the real result
    expectedResult = "1";
    realResult  = oneInteger.stringValue();
    ASSERT_STR(expectedResult, realResult );
    free(realResult);

    // Make a comparison between expected result and the real result
    expectedResult = "10";
    realResult = positiveInteger.stringValue();
    ASSERT_STR(expectedResult, realResult);
    free(realResult);

    // Make a comparison between expected result and the real result
    expectedResult = "2147483647";
    realResult = maxInteger.stringValue();
    ASSERT_STR(expectedResult, realResult);
    free(realResult);

    // Make a comparison between expected result and the real result
    expectedResult = "-2147483647";
    realResult = minInteger.stringValue();
    ASSERT_STR(expectedResult, realResult);
    free(realResult);


}
TEST (JavaLang, IntegerShortValue) {
    // Input different values of type int to compare to the result of Integer::shortValue
    Integer positiveInteger = 1302;
    Integer negativeInteger = -1302;
    Integer notExpectedInteger = 9999;

    // Make a comparison between expected result and the real result
    short expectedResult = 1302;
    short realResult = positiveInteger.shortValue();
    ASSERT_EQUAL(expectedResult, realResult);

    // Make a comparison between expected result and the real result
    expectedResult = -1302;
    realResult = negativeInteger.shortValue();
    ASSERT_EQUAL(expectedResult, realResult);

    // Make a comparison between expected result and the real result
    short notExpectedResult = -1111;
    realResult = notExpectedInteger.shortValue();
    ASSERT_NOT_EQUAL(notExpectedResult, realResult);
}
TEST (JavaLang, IntegerIntValue) {
    // Input different values of type int to compare to the realResult of Integer::intValue
    Integer zeroInteger = 0;
    Integer oneInteger = 1;
    Integer positiveInteger = 10;
    Integer maxInteger = 2147483647;
    Integer minInteger = -2147483647;
    Integer notExpectedInteger = 1111;

    // Make a comparison between expected realResult and the real result
    int expectedResult= 0;
    int realResult = zeroInteger.intValue();
    ASSERT_EQUAL(expectedResult, realResult);

    // Make a comparison between expected realResult and the real result
    expectedResult= 1;
    realResult = oneInteger.intValue();
    ASSERT_EQUAL(expectedResult, realResult);

    // Make a comparison between expected realResult and the real result
    expectedResult= 10;
    realResult = positiveInteger.intValue();
    ASSERT_EQUAL(expectedResult, realResult);

    // Make a comparison between expected realResult and the real result
    expectedResult= 2147483647;
    realResult = maxInteger.intValue();
    ASSERT_EQUAL(expectedResult, realResult);

    // Make a comparison between expected realResult and the real result
    expectedResult= -2147483647;
    realResult = minInteger.intValue();
    ASSERT_EQUAL(expectedResult, realResult);

    // Make a comparison between expected realResult and the real result
    int notExpectedResult= 9999;
    realResult = minInteger.intValue();
    ASSERT_NOT_EQUAL(notExpectedResult, realResult);
}
TEST (JavaLang, IntegerLongValue) {
    // Input different values of type int to compare to the realResult of Integer::longValue
    Integer positiveInteger = 1302321013;
    Integer negativeInteger = -1302321013;
    Integer notExpectedInteger = -12345;

    // Make a comparison between expected realResult and the real result
    long expectedResult = 1302321013;
    long realResult = positiveInteger.longValue();
    ASSERT_EQUAL(expectedResult, realResult);

    // Make a comparison between expected realResult and the real result
    expectedResult = -1302321013;
    realResult = negativeInteger.longValue();
    ASSERT_EQUAL(expectedResult, realResult);

    // Make a comparison between the not expected realResult and the real result
    long notExpectedResult = -11111;
    realResult = notExpectedInteger.longValue();
    ASSERT_FALSE(notExpectedResult == realResult);
}
TEST (JavaLang, IntegerFloatValue) {
    // Input different values of type int to compare to the realResult of Integer::floatValue
    Integer positiveInteger = 12345;
    Integer negativeInteger = -12345;
    Integer notExpectedInteger = -12345;

    // Make a comparison between expected realResult and the real result
    float expectedResult = 12345.00;
    float realResult = positiveInteger.floatValue();
    ASSERT_TRUE(expectedResult == realResult);

    // Make a comparison between expected realResult and the real result
    expectedResult = -12345.00;
    realResult = negativeInteger.floatValue();
    ASSERT_TRUE(expectedResult == realResult);

    // Make a comparison between the not expected realResult and the real result
    float notExpectedResult = -12345.10;
    realResult = negativeInteger.floatValue();
    ASSERT_FALSE(notExpectedResult == realResult);
}
TEST (JavaLang, IntegerDoubleValue) {
    // Input different values of type int to compare to the realResult of Integer::doubleValue
    Integer positiveInteger = 123456789;
    Integer negativeInteger = -123456789;
    Integer notExpectedInteger = -12345;

    // Make a comparison between expected realResult and the real result
    double expectedResult = 123456789.0000000;
    double realResult = positiveInteger.doubleValue();
    ASSERT_TRUE(expectedResult == realResult);

    // Make a comparison between expected realResult and the real result
    expectedResult = -123456789.0000000;
    realResult = negativeInteger.doubleValue();
    ASSERT_TRUE(expectedResult == realResult);

    // Make a comparison between the not expected realResult and the real result
    double notExpectedResult = -12345.10;
    realResult = negativeInteger.floatValue();
    ASSERT_FALSE(notExpectedResult == realResult);
}
