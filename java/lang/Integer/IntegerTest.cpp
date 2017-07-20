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

#include <iostream>
#include "Integer.hpp"

using namespace Java::Lang;

TEST(JavaLang, IntegerConstructor) {
    // Test Integer::Integer()
    Integer integerConstructorNoneParameter = 13;
    ASSERT_EQUAL(13, integerConstructorNoneParameter.intValue() );

    // Test Integer::Integer(int original)
    Integer integerConstructorIntParameter(13);
    ASSERT_EQUAL(13, integerConstructorIntParameter.intValue() );
// TODO(thoangminh): Enable after finish parseInt(String s, int radix)
    // Test Integer::Integer(String stringInput) 
    // Integer integerConstructorStringParameter((string) 13);
    // ASSERT_EQUAL(13, integerConstructorStringParameter.intValue() );

    // Test Integer::Integer(const Integer &integer)
    Integer integerConstructorIntegerParameter = 13;
    ASSERT_EQUAL(13, integerConstructorIntegerParameter.intValue() );

}

TEST(JavaLang, IntegerComparision) {
    // Give a valid number and make a comparision
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

TEST(JavaLang, IntegerOperator) {
    // Given a valid number
    Integer validNumberOperator = 5;
    Integer targetNumberOperator = 3;

    // Make a summation with targetNumber
    Integer summationNumberOperator = 8;
    ASSERT_TRUE(summationNumberOperator == (validNumberOperator + targetNumberOperator));

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

TEST(JavaLang, IntegerParseInt) {
#ifdef __APPLE__
    return;
#endif
    // Given value for Integer constructor and assign value - Return integer
    Integer validIntegerPointerParseInt = Integer::parseInt("6");
    ASSERT_EQUAL(6, validIntegerPointerParseInt.intValue());

}

TEST(JavaLang, IntegerCompareTo) {
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

TEST(JavaLang, IntegerToString) {
    // Input different values of type int to compare to the realResult of Integer::toString
    Integer zeroIntegerToString = 0;
    Integer oneIntegerToString = 1;
    Integer positiveIntegerToString = 10;
    Integer maxIntegerToString = 2147483647;
    Integer minIntegerToString = -2147483647;

    // Make a comparison between expected realResult and the real result
    string expectedResultToString = (string) "0";
    string realResultToString = zeroIntegerToString.toString();
    ASSERT_STR(expectedResultToString, realResultToString);

    // Make a comparison between expected realResult and the real result
    expectedResultToString = (string) "1";
    realResultToString = oneIntegerToString.toString();
    ASSERT_STR(expectedResultToString, realResultToString);

    // Make a comparison between expected realResult and the real result
    expectedResultToString = (string) "10";
    realResultToString = positiveIntegerToString.toString();
    ASSERT_STR(expectedResultToString, realResultToString);

    // Make a comparison between expected realResult and the real result
    expectedResultToString = (string) "2147483647";
    realResultToString = maxIntegerToString.toString();
    ASSERT_STR(expectedResultToString, realResultToString);

    // Make a comparison between expected realResult and the real result
    expectedResultToString = (string) "-2147483647";
    realResultToString = minIntegerToString.toString();
    ASSERT_STR(expectedResultToString, realResultToString);

}

TEST(JavaLang, IntegerCharValue) {
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

TEST(JavaLang, IntegerStringValue) {
    // Input different values of type int to compare to the result of Integer::stringValue
    Integer zeroIntegerStringValue = 0;
    Integer oneIntegerStringValue = 1;
    Integer positiveIntegerStringValue = 10;
    Integer maxIntegerStringValue = 2147483647;
    Integer minIntegerStringValue = -2147483647;

    // Make a comparison between expected result and the real result
    string expectedResultStringValue = (string) "0";
    string realResultStringValue = zeroIntegerStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, realResultStringValue);

    // Make a comparison between expected result and the real result
    expectedResultStringValue = (string) "1";
    realResultStringValue  = oneIntegerStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, realResultStringValue );

    // Make a comparison between expected result and the real result
    expectedResultStringValue = (string) "10";
    realResultStringValue = positiveIntegerStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, realResultStringValue);

    // Make a comparison between expected result and the real result
    expectedResultStringValue = (string) "2147483647";
    realResultStringValue = maxIntegerStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, realResultStringValue);

    // Make a comparison between expected result and the real result
    expectedResultStringValue = (string) "-2147483647";
    realResultStringValue = minIntegerStringValue.stringValue();
    ASSERT_STR(expectedResultStringValue, realResultStringValue);

}

TEST(JavaLang, IntegerShortValue) {
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

TEST(JavaLang, IntegerIntValue) {
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

TEST(JavaLang, IntegerLongValue) {
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

TEST(JavaLang, IntegerFloatValue) {
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

TEST(JavaLang, IntegerDoubleValue) {
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

TEST(JavaLang, IntegerBitCount) {
    int intInput;
    int expectedResult;
    int actualResult;    

    intInput = 0;
    expectedResult = 0;
    actualResult = Integer::bitCount(intInput);
    ASSERT_EQUAL(expectedResult, actualResult);

    intInput = 1; // 01
    expectedResult = 1;
    actualResult = Integer::bitCount(intInput);
    ASSERT_EQUAL(expectedResult, actualResult);

    intInput = -1; // 11
    expectedResult = 2;
    actualResult = Integer::bitCount(intInput);
    ASSERT_EQUAL(expectedResult, actualResult);

    intInput = 13;  // 0000 1101
    expectedResult = 3;
    actualResult = Integer::bitCount(intInput);
    ASSERT_EQUAL(expectedResult, actualResult);

    intInput = MAX_VALUE_INTEGER; // 2,147,483,647(10) = 0111 1111 1111 1111 1111 1111 1111 1111 (2)
    expectedResult = 31;
    actualResult = Integer::bitCount(intInput);
    ASSERT_EQUAL(expectedResult, actualResult);
// TODO(thoangminh): Check the case below:
    // intInput = MIN_VALUE_INTEGER; // -2,147,483,648(10) = 1111 1111 1111 1111 1111 1111 1111 1111 1000 0000 0000 0000 0000 0000 0000 0000
    // expectedResult = 33;
    // actualResult = Integer::bitCount(intInput);
    // ASSERT_EQUAL(expectedResult, actualResult);

}

// TEST(JavaLang, IntegerByteValue) {
    // Integer integerInput;
    // int expectedResult;
    // int actualResult;

    // integerInput = 0;  
    // expectedResult = 0;
    // actualResult = integerInput.byteValue();
    // ASSERT_EQUAL(expectedResult, actualResult);

    // integerInput = 1;  
    // expectedResult = 1;
    // actualResult = integerInput.byteValue();
    // ASSERT_EQUAL(expectedResult, actualResult);

    // integerInput = -1;  
    // expectedResult = -1;
    // actualResult = integerInput.byteValue();
    // ASSERT_EQUAL(expectedResult, actualResult);

    // integerInput = 13;  
    // expectedResult = 13;
    // actualResult = integerInput.byteValue();
    // ASSERT_EQUAL(expectedResult, actualResult);

    // integerInput = MAX_VALUE_INTEGER;  
    // expectedResult = 0;
    // actualResult = integerInput.byteValue();
    // ASSERT_EQUAL(expectedResult, actualResult);

    // integerInput = MIN_VALUE_INTEGER;  
    // expectedResult = 0;
    // actualResult = integerInput.byteValue();
    // ASSERT_EQUAL(expectedResult, actualResult);

// }

// TEST(JavaLang, IntegerCompare) {

    // ASSERT_EQUAL(Integer::compare(0 ,0), 0);
    // ASSERT_EQUAL(Integer::compare(0 ,1), -1);
    // ASSERT_EQUAL(Integer::compare(0 ,-1), 1);
    // ASSERT_EQUAL(Integer::compare(0 ,13), -1);
    // ASSERT_EQUAL(Integer::compare(0 ,MAX_VALUE_INTEGER), -1);
    // ASSERT_EQUAL(Integer::compare(0 ,MIN_VALUE_INTEGER), 1);

    // ASSERT_EQUAL(Integer::compare(1 ,0), 1);
    // ASSERT_EQUAL(Integer::compare(1 ,1), 0);
    // ASSERT_EQUAL(Integer::compare(1 ,-1),1 );
    // ASSERT_EQUAL(Integer::compare(1 ,13), -1);
    // ASSERT_EQUAL(Integer::compare(1 ,MAX_VALUE_INTEGER), -1);
    // ASSERT_EQUAL(Integer::compare(1 ,MIN_VALUE_INTEGER), 1);

    // ASSERT_EQUAL(Integer::compare(-1 ,0), -1);
    // ASSERT_EQUAL(Integer::compare(-1 ,1), -1);
    // ASSERT_EQUAL(Integer::compare(-1 ,-1), 0);
    // ASSERT_EQUAL(Integer::compare(-1 ,13), -1);
    // ASSERT_EQUAL(Integer::compare(-1 ,MAX_VALUE_INTEGER), -1);
    // ASSERT_EQUAL(Integer::compare(-1 ,MIN_VALUE_INTEGER), 1);

    // ASSERT_EQUAL(Integer::compare(13 ,0), 1);
    // ASSERT_EQUAL(Integer::compare(13 ,1), 1);
    // ASSERT_EQUAL(Integer::compare(13 ,-1),1 );
    // ASSERT_EQUAL(Integer::compare(13 ,13), 0);
    // ASSERT_EQUAL(Integer::compare(13 ,MAX_VALUE_INTEGER), -1);
    // ASSERT_EQUAL(Integer::compare(13 ,MIN_VALUE_INTEGER), 1);

    // ASSERT_EQUAL(Integer::compare(MAX_VALUE_INTEGER ,0), 1);
    // ASSERT_EQUAL(Integer::compare(MAX_VALUE_INTEGER ,1), 1);
    // ASSERT_EQUAL(Integer::compare(MAX_VALUE_INTEGER ,-1), 1);
    // ASSERT_EQUAL(Integer::compare(MAX_VALUE_INTEGER ,13), 1);
    // ASSERT_EQUAL(Integer::compare(MAX_VALUE_INTEGER ,MAX_VALUE_INTEGER), 0);
    // ASSERT_EQUAL(Integer::compare(MAX_VALUE_INTEGER ,MIN_VALUE_INTEGER), 1);

    // ASSERT_EQUAL(Integer::compare(MIN_VALUE_INTEGER ,0), -1);
    // ASSERT_EQUAL(Integer::compare(MIN_VALUE_INTEGER ,1), -1);
    // ASSERT_EQUAL(Integer::compare(MIN_VALUE_INTEGER ,-1), -1);
    // ASSERT_EQUAL(Integer::compare(MIN_VALUE_INTEGER ,13), -1);
    // ASSERT_EQUAL(Integer::compare(MIN_VALUE_INTEGER ,MAX_VALUE_INTEGER), -1);
    // ASSERT_EQUAL(Integer::compare(MIN_VALUE_INTEGER ,MIN_VALUE_INTEGER), 0);

// }

// TEST(JavaLang, IntegerCompareTo) {
    // Integer thisInteger;

    // thisInteger = 0;
    // ASSERT_EQUAL(thisInteger.compareTo(0), 0);
    // ASSERT_EQUAL(thisInteger.compareTo(1), -1);
    // ASSERT_EQUAL(thisInteger.compareTo(-1), 1);
    // ASSERT_EQUAL(thisInteger.compareTo(13), -1);
    // ASSERT_EQUAL(thisInteger.compareTo(MAX_VALUE_INTEGER), -1);
    // ASSERT_EQUAL(thisInteger.compareTo(MIN_VALUE_INTEGER), 1);

    // thisInteger = 1;
    // ASSERT_EQUAL(thisInteger.compareTo(0), 1);
    // ASSERT_EQUAL(thisInteger.compareTo(1), 0);
    // ASSERT_EQUAL(thisInteger.compareTo(-1), 1 );
    // ASSERT_EQUAL(thisInteger.compareTo(13), -1);
    // ASSERT_EQUAL(thisInteger.compareTo(MAX_VALUE_INTEGER), -1);
    // ASSERT_EQUAL(thisInteger.compareTo(MIN_VALUE_INTEGER), 1);

    // thisInteger = -1;
    // ASSERT_EQUAL(thisInteger.compareTo(0), -1);
    // ASSERT_EQUAL(thisInteger.compareTo(1), -1);
    // ASSERT_EQUAL(thisInteger.compareTo(-1), 0);
    // ASSERT_EQUAL(thisInteger.compareTo(13), -1);
    // ASSERT_EQUAL(thisInteger.compareTo(MAX_VALUE_INTEGER), -1);
    // ASSERT_EQUAL(thisInteger.compareTo(MIN_VALUE_INTEGER), 1);

    // thisInteger = 13;
    // ASSERT_EQUAL(thisInteger.compareTo(0), 1);
    // ASSERT_EQUAL(thisInteger.compareTo(1), 1);
    // ASSERT_EQUAL(thisInteger.compareTo(-1),1 );
    // ASSERT_EQUAL(thisInteger.compareTo(13), 0);
    // ASSERT_EQUAL(thisInteger.compareTo(MAX_VALUE_INTEGER), -1);
    // ASSERT_EQUAL(thisInteger.compareTo(MIN_VALUE_INTEGER), 1);

    // thisInteger = MAX_VALUE_INTEGER;
    // ASSERT_EQUAL(thisInteger.compareTo(0), 1);
    // ASSERT_EQUAL(thisInteger.compareTo(1), 1);
    // ASSERT_EQUAL(thisInteger.compareTo(-1), 1);
    // ASSERT_EQUAL(thisInteger.compareTo(13), 1);
    // ASSERT_EQUAL(thisInteger.compareTo(MAX_VALUE_INTEGER), 0);
    // ASSERT_EQUAL(thisInteger.compareTo(MIN_VALUE_INTEGER), 1);

    // thisInteger = MIN_VALUE_INTEGER;
    // ASSERT_EQUAL(thisInteger.compareTo(0), -1);
    // ASSERT_EQUAL(thisInteger.compareTo(1), -1);
    // ASSERT_EQUAL(thisInteger.compareTo(-1), -1);
    // ASSERT_EQUAL(thisInteger.compareTo(13), -1);
    // ASSERT_EQUAL(thisInteger.compareTo(MAX_VALUE_INTEGER), -1);
    // ASSERT_EQUAL(thisInteger.compareTo(MIN_VALUE_INTEGER), 0);

// }

// TEST(JavaLang, IntegerCompareUnsigned) {
//     ASSERT_EQUAL(Integer::compareUnsigned(0 ,0), 0);
//     ASSERT_EQUAL(Integer::compareUnsigned(0 ,1), -1);
//     ASSERT_EQUAL(Integer::compareUnsigned(0 ,-1), 1);
//     ASSERT_EQUAL(Integer::compareUnsigned(0 ,13), -1);
//     ASSERT_EQUAL(Integer::compareUnsigned(0 ,MAX_VALUE_INTEGER), -1);
//     ASSERT_EQUAL(Integer::compareUnsigned(0 ,MIN_VALUE_INTEGER), 1);

//     ASSERT_EQUAL(Integer::compareUnsigned(1 ,0), 1);
//     ASSERT_EQUAL(Integer::compareUnsigned(1 ,1), 0);
//     ASSERT_EQUAL(Integer::compareUnsigned(1 ,-1),0 );
//     ASSERT_EQUAL(Integer::compareUnsigned(1 ,13), -1);
//     ASSERT_EQUAL(Integer::compareUnsigned(1 ,MAX_VALUE_INTEGER), -1);
//     ASSERT_EQUAL(Integer::compareUnsigned(1 ,MIN_VALUE_INTEGER), 1);

//     ASSERT_EQUAL(Integer::compareUnsigned(-1 ,0), -1);
//     ASSERT_EQUAL(Integer::compareUnsigned(-1 ,1), 0);
//     ASSERT_EQUAL(Integer::compareUnsigned(-1 ,-1), 0);
//     ASSERT_EQUAL(Integer::compareUnsigned(-1 ,13), -1);
//     ASSERT_EQUAL(Integer::compareUnsigned(-1 ,MAX_VALUE_INTEGER), -1);
//     ASSERT_EQUAL(Integer::compareUnsigned(-1 ,MIN_VALUE_INTEGER), 1);

//     ASSERT_EQUAL(Integer::compareUnsigned(13 ,0), 1);
//     ASSERT_EQUAL(Integer::compareUnsigned(13 ,1), 1);
//     ASSERT_EQUAL(Integer::compareUnsigned(13 ,-1),1 );
//     ASSERT_EQUAL(Integer::compareUnsigned(13 ,13), 0);
//     ASSERT_EQUAL(Integer::compareUnsigned(13 ,MAX_VALUE_INTEGER), -1);
//     ASSERT_EQUAL(Integer::compareUnsigned(13 ,MIN_VALUE_INTEGER), 1);

//     ASSERT_EQUAL(Integer::compareUnsigned(MAX_VALUE_INTEGER ,0), 1);
//     ASSERT_EQUAL(Integer::compareUnsigned(MAX_VALUE_INTEGER ,1), 1);
//     ASSERT_EQUAL(Integer::compareUnsigned(MAX_VALUE_INTEGER ,-1), 1);
//     ASSERT_EQUAL(Integer::compareUnsigned(MAX_VALUE_INTEGER ,13), 1);
//     ASSERT_EQUAL(Integer::compareUnsigned(MAX_VALUE_INTEGER ,MAX_VALUE_INTEGER), 0);
//     ASSERT_EQUAL(Integer::compareUnsigned(MAX_VALUE_INTEGER ,MIN_VALUE_INTEGER), 1);

//     ASSERT_EQUAL(Integer::compareUnsigned(MIN_VALUE_INTEGER ,0), -1);
//     ASSERT_EQUAL(Integer::compareUnsigned(MIN_VALUE_INTEGER ,1), -1);
//     ASSERT_EQUAL(Integer::compareUnsigned(MIN_VALUE_INTEGER ,-1), -1);
//     ASSERT_EQUAL(Integer::compareUnsigned(MIN_VALUE_INTEGER ,13), -1);
//     ASSERT_EQUAL(Integer::compareUnsigned(MIN_VALUE_INTEGER ,MAX_VALUE_INTEGER), -1);
//     ASSERT_EQUAL(Integer::compareUnsigned(MIN_VALUE_INTEGER ,MIN_VALUE_INTEGER), 0);

// }

// TEST(JavaLang, IntegerDecode) {
//     String stringInput;
//     Integer expectedResult;
//     Integer actualResult;

//     stringInput = (String) "0";
//     expectedResult = 0;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_TRUE(expectedResult == actualResult);

//     stringInput = (String) "1";
//     expectedResult = 1;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_TRUE(expectedResult == actualResult);

//     stringInput = (String) "-1";
//     expectedResult = -1;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_TRUE(expectedResult == actualResult);

//     stringInput = (String) "13";
//     expectedResult = 13;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_TRUE(expectedResult == actualResult);

//     stringInput = (String) "2147483647"; // MAX_VALUE_INTEGER
//     expectedResult = 2147483647;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_TRUE(expectedResult == actualResult);

//     stringInput = (String) "-2147483647"; // MIN_VALUE_INTEGER
//     expectedResult = -2147483647;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_TRUE(expectedResult == actualResult);

//     stringInput = (String) "Not a Number";
//     expectedResult = ;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_TRUE(expectedResult == actualResult);

// }

// TEST(JavaLang, IntegerDivideUnsigned) {
//     int dividend;
//     int divisor;
//     int expectedResult;
//     int actualResult;

//     dividend = 10;
//     divisor = 2;
//     expectedResult = 5;
//     actualResult = Integer::divideUnsigned(dividend, divisor);
//     ASSERT_EQUAL(expectedResult, actualResult);

//     dividend = -10;
//     divisor = 5;
//     expectedResult = 2;
//     actualResult = ;
//     ASSERT_EQUAL(expectedResult, actualResult);

//     dividend = 10;
//     divisor = -5;
//     expectedResult = 2;
//     actualResult = Integer::divideUnsigned(dividend, divisor);
//     ASSERT_EQUAL(expectedResult, actualResult);

//     dividend = -10;
//     divisor = -5;
//     expectedResult = 2;
//     actualResult = Integer::divideUnsigned(dividend, divisor);
//     ASSERT_EQUAL(expectedResult, actualResult);

//     dividend = -10.7;
//     divisor = 5.6;
//     expectedResult = 2;
//     actualResult = Integer::divideUnsigned(dividend, divisor);
//     ASSERT_EQUAL(expectedResult, actualResult);

//     dividend = MAX_VALUE_INTEGER;
//     divisor = -2;
//     expectedResult = MAX_VALUE_INTEGER / 2;
//     actualResult = Integer::divideUnsigned(dividend, divisor);
//     ASSERT_EQUAL(expectedResult, actualResult);

//     dividend = MIN_VALUE_INTEGER;
//     divisor = 2;
//     expectedResult = -MIN_VALUE_INTEGER / 2;
//     actualResult = Integer::divideUnsigned(dividend, divisor);
//     ASSERT_EQUAL(expectedResult, actualResult);

//     dividend = 10;
//     divisor = 0;
//     expectedResult = ;
//     actualResult = Integer::divideUnsigned(dividend, divisor);
//     ASSERT_EQUAL(expectedResult, actualResult);

//     dividend = -10;
//     divisor = 0;
//     expectedResult = ;
//     actualResult = Integer::divideUnsigned(dividend, divisor);
//     ASSERT_EQUAL(expectedResult, actualResult);

//     dividend = 0;
//     divisor = 0;
//     expectedResult = 0;
//     actualResult = Integer::divideUnsigned(dividend, divisor);
//     ASSERT_EQUAL(expectedResult, actualResult);

// }

// TEST(JavaLang, IntegerDoubleValue) {
//     Integer integerInput;

//     integerInput = 0;
//     ASSERT_DBL_NEAR(0.0, integerInput.doubleValue());

//     integerInput = 1;
//     ASSERT_DBL_NEAR(1.0, integerInput.doubleValue());

//     integerInput = -1;
//     ASSERT_DBL_NEAR(-1.0, integerInput.doubleValue());

//     integerInput = 13;
//     ASSERT_DBL_NEAR(13.0, integerInput.doubleValue());

//     integerInput = MAX_VALUE_INTEGER;
//     ASSERT_DBL_NEAR((double)MAX_VALUE_INTEGER, integerInput.doubleValue());

//     integerInput = MIN_VALUE_INTEGER;
//     ASSERT_DBL_NEAR((double)MIN_VALUE_INTEGER, integerInput.doubleValue());

// }

// TEST(JavaLang, IntegerEquals) {
//     Integer thisInteger;

//     thisInteger = 0;
//     ASSERT_TRUE(thisInteger.equals(0));
//     ASSERT_FALSE(thisInteger.equals(1));
//     ASSERT_FALSE(thisInteger.equals(-1));
//     ASSERT_FALSE(thisInteger.equals(13));
//     ASSERT_FALSE(thisInteger.equals(MAX_VALUE_INTEGER));
//     ASSERT_FALSE(thisInteger.equals(MIN_VALUE_INTEGER));

//     thisInteger = 1;
//     ASSERT_FALSE(thisInteger.equals(0));
//     ASSERT_TRUE(thisInteger.equals(1));
//     ASSERT_FALSE(thisInteger.equals(-1));
//     ASSERT_FALSE(thisInteger.equals(13));
//     ASSERT_FALSE(thisInteger.equals(MAX_VALUE_INTEGER));
//     ASSERT_FALSE(thisInteger.equals(MIN_VALUE_INTEGER));

//     thisInteger = -1;
//     ASSERT_FALSE(thisInteger.equals(0));
//     ASSERT_FALSE(thisInteger.equals(1));
//     ASSERT_TRUE(thisInteger.equals(-1));
//     ASSERT_FALSE(thisInteger.equals(13));
//     ASSERT_FALSE(thisInteger.equals(MAX_VALUE_INTEGER));
//     ASSERT_FALSE(thisInteger.equals(MIN_VALUE_INTEGER));

//     thisInteger = 13;
//     ASSERT_FALSE(thisInteger.equals(0));
//     ASSERT_FALSE(thisInteger.equals(1));
//     ASSERT_FALSE(thisInteger.equals(-1));
//     ASSERT_TRUE(thisInteger.equals(13));
//     ASSERT_FALSE(thisInteger.equals(MAX_VALUE_INTEGER));
//     ASSERT_FALSE(thisInteger.equals(MIN_VALUE_INTEGER));

//     thisInteger = MAX_VALUE_INTEGER;
//     ASSERT_FALSE(thisInteger.equals(0));
//     ASSERT_FALSE(thisInteger.equals(1));
//     ASSERT_FALSE(thisInteger.equals(-1));
//     ASSERT_FALSE(thisInteger.equals(13));
//     ASSERT_TRUE(thisInteger.equals(MAX_VALUE_INTEGER));
//     ASSERT_FALSE(thisInteger.equals(MIN_VALUE_INTEGER));

//     thisInteger = MIN_VALUE_INTEGER;
//     ASSERT_FALSE(thisInteger.equals(0));
//     ASSERT_FALSE(thisInteger.equals(1));
//     ASSERT_FALSE(thisInteger.equals(-1));
//     ASSERT_FALSE(thisInteger.equals(13));
//     ASSERT_FALSE(thisInteger.equals(MAX_VALUE_INTEGER));
//     ASSERT_TRUE(thisInteger.equals(MIN_VALUE_INTEGER));

// }

// TEST(JavaLang, IntegerHashCode) {
//     Integer inputInteger;

//     inputInteger = 0;
//     ASSERT_EQUAL(0, inputInteger.hashCode());

//     inputInteger = 1;
//     ASSERT_EQUAL(1, inputInteger.hashCode());

//     inputInteger = -1;
//     ASSERT_EQUAL(-1, inputInteger.hashCode());

//     inputInteger = 13;
//     ASSERT_EQUAL(13, inputInteger.hashCode());

//     inputInteger = MAX_VALUE_INTEGER;
//     ASSERT_EQUAL(MAX_VALUE_INTEGER, inputInteger.hashCode());

//     inputInteger = MIN_VALUE_INTEGER;
//     ASSERT_EQUAL(MIN_VALUE_INTEGER, inputInteger.hashCode());

// }

// TEST(JavaLang, Integer) {


// }

// TEST(JavaLang, Integer) {


// }

// TEST(JavaLang, Integer) {


// }

// TEST(JavaLang, Integer) {


// }

// TEST(JavaLang, Integer) {


// }

// TEST(JavaLang, Integer) {


// }

// TEST(JavaLang, Integer) {


// }

// TEST(JavaLang, Integer) {


// }