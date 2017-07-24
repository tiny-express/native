/**
 Copyright 2017 Food Tiny Project. All rights reserved.
 *
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 *
 Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 Redistributions in binary form must reproduce the above
 copyright notice, this list of conditions and the following disclaimer
 in the documentation and/or other materials provided with the
 distribution.
 *
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
extern "C" {
#include "../../../kernel/test.h"
}

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
    // Create variable
    Integer validNumberOperator = 5;
    Integer targetNumberOperator = 3;
    Integer expectedResult;
    Integer actualResult;

    // Make a summation with targetNumber
    expectedResult = 8;
    actualResult = validNumberOperator + targetNumberOperator;
    ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // Make a subtraction with targetNumber
    expectedResult = 2;
    actualResult = validNumberOperator - targetNumberOperator;
    ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // Make a multiplication with targetNumber
    expectedResult = 15;
    actualResult = validNumberOperator * targetNumberOperator;
    ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // Make a division with targetNumber
    expectedResult = 1;
    actualResult = validNumberOperator / targetNumberOperator;
    ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // Make a modulo with targetNumber
    expectedResult = 2;
    actualResult = validNumberOperator % targetNumberOperator;
    ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
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
    // Integer integerCompareTo = 1;
    // Comparable<Integer> *comparable = &validValueCompareTo;
    // ASSERT_EQUAL(1, comparable->compareTo(integerCompareTo));
}

TEST(JavaLang, IntegerCharValue) {
    // Input different values of type int to compare to the result of Integer::charValue
    Integer zeroIntegerCharValue        = 0;
    Integer oneIntegerCharValue         = 1;
    Integer positiveIntegerCharValue    = 10;
    Integer maxIntegerCharValue         = 2147483647;
    Integer minIntegerCharValue         = -2147483647;

    // Make a comparison between expected result and the real result
    char expectedResultCharValue = '0';
    char realResultCharValue = zeroIntegerCharValue.charValue();
    ASSERT_EQUAL(expectedResultCharValue, realResultCharValue);

    // Make a comparison between expected result and the real result
    expectedResultCharValue = '1';
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
    // Create variable
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
    ASSERT_STR(expectedResultStringValue, realResultStringValue);

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
    int expectedResultIntValue = 0;
    int realResultIntValue = zeroIntegerIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, realResultIntValue);

    // Make a comparison between expected realResult and the real result
    expectedResultIntValue = 1;
    realResultIntValue = oneIntegerIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, realResultIntValue);

    // Make a comparison between expected realResult and the real result
    expectedResultIntValue = 10;
    realResultIntValue = positiveIntegerIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, realResultIntValue);

    // Make a comparison between expected realResult and the real result
    expectedResultIntValue = 2147483647;
    realResultIntValue = maxIntegerIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, realResultIntValue);

    // Make a comparison between expected realResult and the real result
    expectedResultIntValue = -2147483647;
    realResultIntValue = minIntegerIntValue.intValue();
    ASSERT_EQUAL(expectedResultIntValue, realResultIntValue);

    // Make a comparison between expected realResult and the real result
    int notExpectedResult = 9999;
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
    expectedResultFloatValue = static_cast<float> (-12345.00);
    realResultFloatValue = negativeInteger.floatValue();
    ASSERT_TRUE(expectedResultFloatValue == realResultFloatValue);
}

TEST(JavaLang, IntegerDoubleValue) {
    // Input different values of type int to compare to the realResult of Integer::doubleValue
    Integer positiveIntegerDoubleValue = 123456789;
    double expectedResultDoubleValue = 123456789.0;
    double realResultDoubleValue = positiveIntegerDoubleValue.doubleValue();
    ASSERT_TRUE(expectedResultDoubleValue == realResultDoubleValue);

    Integer negativeInteger = -123456789;
    expectedResultDoubleValue = -123456789.0;
    realResultDoubleValue = negativeInteger.doubleValue();
    ASSERT_TRUE(expectedResultDoubleValue == realResultDoubleValue);
}

TEST(JavaLang, IntegerBitCount) {
    int inputInt;
    int expectedResult;
    int actualResult;

    inputInt = 0;
    expectedResult = 0;
    actualResult = Integer::bitCount(inputInt);
    ASSERT_EQUAL(expectedResult, actualResult);

    inputInt = 1; // 01
    expectedResult = 1;
    actualResult = Integer::bitCount(inputInt);
    ASSERT_EQUAL(expectedResult, actualResult);

    inputInt = -1; // 11
    expectedResult = 2;
    actualResult = Integer::bitCount(inputInt);
    ASSERT_EQUAL(expectedResult, actualResult);

    inputInt = 13;  // 0000 1101
    expectedResult = 3;
    actualResult = Integer::bitCount(inputInt);
    ASSERT_EQUAL(expectedResult, actualResult);

    inputInt = MAX_VALUE; // 2,147,483,647(10) = 0111 1111 1111 1111 1111 1111 1111 1111 (2)
    expectedResult = 31;
    actualResult = Integer::bitCount(inputInt);
    ASSERT_EQUAL(expectedResult, actualResult);
// TODO(thoangminh): Check the case below:
    // inputInt = MIN_VALUE; // -2,147,483,648(10) = 1111 1111 1111 1111 1111 1111 1111 1111 1000 0000 0000 0000 0000 0000 0000 0000
    // expectedResult = 33;
    // actualResult = Integer::bitCount(inputInt);
    // ASSERT_EQUAL(expectedResult, actualResult);
}

TEST(JavaLang, IntegerByteValue) {
    Integer integerInput;

    integerInput = 0;  
    ASSERT_EQUAL((byte) 0, integerInput.byteValue());

    integerInput = 1;  
    ASSERT_EQUAL((byte) 1, integerInput.byteValue());

    integerInput = -1;  
    ASSERT_EQUAL((byte) -1, integerInput.byteValue());

    integerInput = 13;  
    ASSERT_EQUAL((byte) 13, integerInput.byteValue());

    integerInput = MAX_VALUE;  
    ASSERT_EQUAL((byte) -1, integerInput.byteValue());

    integerInput = MIN_VALUE;  
    ASSERT_EQUAL((byte) 0, integerInput.byteValue());
}

TEST(JavaLang, IntegerCompare) {
    ASSERT_EQUAL(Integer::compare(0, 0), 0);
    ASSERT_EQUAL(Integer::compare(0, 1), -1);
    ASSERT_EQUAL(Integer::compare(0, -1), 1);
    ASSERT_EQUAL(Integer::compare(0, 13), -1);
    ASSERT_EQUAL(Integer::compare(0, MAX_VALUE), -1);
    ASSERT_EQUAL(Integer::compare(0, MIN_VALUE), 1);

    ASSERT_EQUAL(Integer::compare(1, 0), 1);
    ASSERT_EQUAL(Integer::compare(1, 1), 0);
    ASSERT_EQUAL(Integer::compare(1, -1), 1);
    ASSERT_EQUAL(Integer::compare(1, 13), -1);
    ASSERT_EQUAL(Integer::compare(1, MAX_VALUE), -1);
    ASSERT_EQUAL(Integer::compare(1, MIN_VALUE), 1);

    ASSERT_EQUAL(Integer::compare(-1 , 0), -1);
    ASSERT_EQUAL(Integer::compare(-1 , 1), -1);
    ASSERT_EQUAL(Integer::compare(-1 , -1), 0);
    ASSERT_EQUAL(Integer::compare(-1 , 13), -1);
    ASSERT_EQUAL(Integer::compare(-1 , MAX_VALUE), -1);
    ASSERT_EQUAL(Integer::compare(-1 , MIN_VALUE), 1);

    ASSERT_EQUAL(Integer::compare(13 , 0), 1);
    ASSERT_EQUAL(Integer::compare(13 , 1), 1);
    ASSERT_EQUAL(Integer::compare(13 , -1), 1);
    ASSERT_EQUAL(Integer::compare(13 , 13), 0);
    ASSERT_EQUAL(Integer::compare(13 , MAX_VALUE), -1);
    ASSERT_EQUAL(Integer::compare(13 , MIN_VALUE), 1);

    ASSERT_EQUAL(Integer::compare(MAX_VALUE , 0), 1);
    ASSERT_EQUAL(Integer::compare(MAX_VALUE , 1), 1);
    ASSERT_EQUAL(Integer::compare(MAX_VALUE , -1), 1);
    ASSERT_EQUAL(Integer::compare(MAX_VALUE , 13), 1);
    ASSERT_EQUAL(Integer::compare(MAX_VALUE , MAX_VALUE), 0);
    ASSERT_EQUAL(Integer::compare(MAX_VALUE , MIN_VALUE), 1);

    ASSERT_EQUAL(Integer::compare(MIN_VALUE , 0), -1);
    ASSERT_EQUAL(Integer::compare(MIN_VALUE , 1), -1);
    ASSERT_EQUAL(Integer::compare(MIN_VALUE , -1), -1);
    ASSERT_EQUAL(Integer::compare(MIN_VALUE , 13), -1);
    ASSERT_EQUAL(Integer::compare(MIN_VALUE , MAX_VALUE), -1);
    ASSERT_EQUAL(Integer::compare(MIN_VALUE , MIN_VALUE), 0);
}

// TEST(JavaLang, IntegerCompareTo) {
//     Integer thisInteger;

//     thisInteger = 0;
//     ASSERT_EQUAL(thisInteger.compareTo(0), 0);
//     ASSERT_EQUAL(thisInteger.compareTo(1), -1);
//     ASSERT_EQUAL(thisInteger.compareTo(-1), 1);
//     ASSERT_EQUAL(thisInteger.compareTo(13), -1);
//     ASSERT_EQUAL(thisInteger.compareTo(MAX_VALUE), -1);
//     ASSERT_EQUAL(thisInteger.compareTo(MIN_VALUE), 1);

//     thisInteger = 1;
//     ASSERT_EQUAL(thisInteger.compareTo(0), 1);
//     ASSERT_EQUAL(thisInteger.compareTo(1), 0);
//     ASSERT_EQUAL(thisInteger.compareTo(-1), 1 );
//     ASSERT_EQUAL(thisInteger.compareTo(13), -1);
//     ASSERT_EQUAL(thisInteger.compareTo(MAX_VALUE), -1);
//     ASSERT_EQUAL(thisInteger.compareTo(MIN_VALUE), 1);

//     thisInteger = -1;
//     ASSERT_EQUAL(thisInteger.compareTo(0), -1);
//     ASSERT_EQUAL(thisInteger.compareTo(1), -1);
//     ASSERT_EQUAL(thisInteger.compareTo(-1), 0);
//     ASSERT_EQUAL(thisInteger.compareTo(13), -1);
//     ASSERT_EQUAL(thisInteger.compareTo(MAX_VALUE), -1);
//     ASSERT_EQUAL(thisInteger.compareTo(MIN_VALUE), 1);

//     thisInteger = 13;
//     ASSERT_EQUAL(thisInteger.compareTo(0), 1);
//     ASSERT_EQUAL(thisInteger.compareTo(1), 1);
//     ASSERT_EQUAL(thisInteger.compareTo(-1), 1);
//     ASSERT_EQUAL(thisInteger.compareTo(13), 0);
//     ASSERT_EQUAL(thisInteger.compareTo(MAX_VALUE), -1);
//     ASSERT_EQUAL(thisInteger.compareTo(MIN_VALUE), 1);

//     thisInteger = MAX_VALUE;
//     ASSERT_EQUAL(thisInteger.compareTo(0), 1);
//     ASSERT_EQUAL(thisInteger.compareTo(1), 1);
//     ASSERT_EQUAL(thisInteger.compareTo(-1), 1);
//     ASSERT_EQUAL(thisInteger.compareTo(13), 1);
//     ASSERT_EQUAL(thisInteger.compareTo(MAX_VALUE), 0);
//     ASSERT_EQUAL(thisInteger.compareTo(MIN_VALUE), 1);

//     thisInteger = MIN_VALUE;
//     ASSERT_EQUAL(thisInteger.compareTo(0), -1);
//     ASSERT_EQUAL(thisInteger.compareTo(1), -1);
//     ASSERT_EQUAL(thisInteger.compareTo(-1), -1);
//     ASSERT_EQUAL(thisInteger.compareTo(13), -1);
//     ASSERT_EQUAL(thisInteger.compareTo(MAX_VALUE), -1);
//     ASSERT_EQUAL(thisInteger.compareTo(MIN_VALUE), 0);

// }

TEST(JavaLang, IntegerCompareUnsigned) {
    ASSERT_EQUAL(Integer::compareUnsigned(0, 0), 0);
    ASSERT_EQUAL(Integer::compareUnsigned(0, 1), -1);
    ASSERT_EQUAL(Integer::compareUnsigned(0, -1), -1);
    ASSERT_EQUAL(Integer::compareUnsigned(0, 13), -1);
    ASSERT_EQUAL(Integer::compareUnsigned(0, MAX_VALUE), -1);
    ASSERT_EQUAL(Integer::compareUnsigned(0, MIN_VALUE), -1);

    ASSERT_EQUAL(Integer::compareUnsigned(1, 0), 1);
    ASSERT_EQUAL(Integer::compareUnsigned(1, 1), 0);
    ASSERT_EQUAL(Integer::compareUnsigned(1, -1), -1);
    ASSERT_EQUAL(Integer::compareUnsigned(1, 13), -1);
    ASSERT_EQUAL(Integer::compareUnsigned(1, MAX_VALUE), -1);
    ASSERT_EQUAL(Integer::compareUnsigned(1, MIN_VALUE), -1);

    ASSERT_EQUAL(Integer::compareUnsigned(-1 , 0), 1);
    ASSERT_EQUAL(Integer::compareUnsigned(-1 , 1), 1);
    ASSERT_EQUAL(Integer::compareUnsigned(-1 , -1), 0);
    ASSERT_EQUAL(Integer::compareUnsigned(-1 , 13), 1);
    ASSERT_EQUAL(Integer::compareUnsigned(-1 , MAX_VALUE), 1);
    ASSERT_EQUAL(Integer::compareUnsigned(-1 , MIN_VALUE), 1);

    ASSERT_EQUAL(Integer::compareUnsigned(13 , 0), 1);
    ASSERT_EQUAL(Integer::compareUnsigned(13 , 1), 1);
    ASSERT_EQUAL(Integer::compareUnsigned(13 , -1), -1);
    ASSERT_EQUAL(Integer::compareUnsigned(13 , 13), 0);
    ASSERT_EQUAL(Integer::compareUnsigned(13 , MAX_VALUE), -1);
    ASSERT_EQUAL(Integer::compareUnsigned(13 , MIN_VALUE), -1);

    ASSERT_EQUAL(Integer::compareUnsigned(MAX_VALUE , 0), 1);
    ASSERT_EQUAL(Integer::compareUnsigned(MAX_VALUE , 1), 1);
    ASSERT_EQUAL(Integer::compareUnsigned(MAX_VALUE , -1), -1);
    ASSERT_EQUAL(Integer::compareUnsigned(MAX_VALUE , 13), 1);
    ASSERT_EQUAL(Integer::compareUnsigned(MAX_VALUE , MAX_VALUE), 0);
    ASSERT_EQUAL(Integer::compareUnsigned(MAX_VALUE , MIN_VALUE), -1);

    ASSERT_EQUAL(Integer::compareUnsigned(MIN_VALUE , 0), 1);
    ASSERT_EQUAL(Integer::compareUnsigned(MIN_VALUE , 1), 1);
    ASSERT_EQUAL(Integer::compareUnsigned(MIN_VALUE , -1), -1);
    ASSERT_EQUAL(Integer::compareUnsigned(MIN_VALUE , 13), 1);
    ASSERT_EQUAL(Integer::compareUnsigned(MIN_VALUE , MAX_VALUE), 1);
    ASSERT_EQUAL(Integer::compareUnsigned(MIN_VALUE , MIN_VALUE), 0);
}

// TEST(JavaLang, IntegerDecode) {
    // String stringInput;
    // Integer expectedResult;
    // Integer actualResult;

    // // Cast all case of inputing a string of type decimal number
    // stringInput = (String) "0";
    // expectedResult = 0;
    // actualResult = Integer:decode(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "1";
    // expectedResult = 1;
    // actualResult = Integer:decode(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "-1";
    // expectedResult = -1;
    // actualResult = Integer:decode(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "13";
    // expectedResult = 13;
    // actualResult = Integer:decode(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "2147483647"; // MAX_VALUE
    // expectedResult = MAX_VALUE;
    // actualResult = Integer:decode(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "-2147483648"; // MIN_VALUE
    // expectedResult = MIN_VALUE;
    // actualResult = Integer:decode(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "Not a Number";
    // expectedResult = ;
    // actualResult = Integer:decode(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "12345678901234567890123456789";
    // expectedResult = ; // out of range
    // actualResult = Integer:decode(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());


//     // Cast all case of inputing a string of type octal numberstringInput = (String) "0";
//     stringInput = (String) "00";
//     expectedResult = 0;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

//     stringInput = (String) "01";
//     expectedResult = 1;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

//     stringInput = (String) "00001101";
//     expectedResult = 13;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

//     stringInput = (String) "01111111111111111111111111111111"; // MAX_VALUE
//     expectedResult = 2147483647;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

//     stringInput = (String) "0111111111111111111111111111111111111111111";
//     expectedResult = ; // out of range 
//     actualResult = Integer:decode(stringInput);
//     ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

//     stringInput = (String) "011111111111111111111111111111111112222222";
//     expectedResult = ; // wrong type
//     actualResult = Integer:decode(stringInput);
//     ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

//     // Cast all case of inputing a string of type hexadecimal number
//     stringInput = (String) "0x00";
//     expectedResult = 0;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

//     stringInput = (String) "#1";
//     expectedResult = 1;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

//     stringInput = (String) "#FFFFFFFFFFFFFFFF";
//     expectedResult = -1;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

//     stringInput = (String) "0xD";
//     expectedResult = 13;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

//     stringInput = (String) "0x7FFFFFFF"; // MAX_VALUE
//     expectedResult = 2147483647;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

//     stringInput = (String) "#FFFFFFFF80000000"; // MIN_VALUE
//     expectedResult = -2147483647;
//     actualResult = Integer:decode(stringInput);
//     ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

//     stringInput = (String) "#Not a Number";
//     expectedResult = ; // Not a number
//     actualResult = Integer:decode(stringInput);
//     ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

//     stringInput = (String) "#213546546";
//     expectedResult = ; // Wrong type
//     actualResult = Integer:decode(stringInput);
//     ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

//     stringInput = (String) "#1111FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
//     expectedResult = ; // Out of range
//     actualResult = Integer:decode(stringInput);
//     ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

// }

// TEST(JavaLang, IntegerDivideUnsigned) {
//     // ASSERT_EQUAL(Integer::divideUnsigned(0, 0), 0);
//     ASSERT_EQUAL(Integer::divideUnsigned(0, 1), 0);
//     ASSERT_EQUAL(Integer::divideUnsigned(0, -1), 0);
//     ASSERT_EQUAL(Integer::divideUnsigned(0, 13), 0);
//     ASSERT_EQUAL(Integer::divideUnsigned(0, MAX_VALUE), 0);
//     ASSERT_EQUAL(Integer::divideUnsigned(0, MIN_VALUE), 0);

//     // ASSERT_EQUAL(Integer::divideUnsigned(1, 0), 1);
//     ASSERT_EQUAL(Integer::divideUnsigned(1, 1), 1);
//     ASSERT_EQUAL(Integer::divideUnsigned(1, -1), 0);
//     ASSERT_EQUAL(Integer::divideUnsigned(1, 13), 0);
//     ASSERT_EQUAL(Integer::divideUnsigned(1, MAX_VALUE), 0);
//     ASSERT_EQUAL(Integer::divideUnsigned(1, MIN_VALUE), 0);

//     // ASSERT_EQUAL(Integer::divideUnsigned(-1 , 0), -1);
//     ASSERT_EQUAL(Integer::divideUnsigned(-1 , 1), -1);
//     ASSERT_EQUAL(Integer::divideUnsigned(-1 , -1), 1);
//     ASSERT_EQUAL(Integer::divideUnsigned(-1 , 13), 330382099);
//     ASSERT_EQUAL(Integer::divideUnsigned(-1 , MAX_VALUE), 2);
//     ASSERT_EQUAL(Integer::divideUnsigned(-1 , MIN_VALUE), 1);

//     // ASSERT_EQUAL(Integer::divideUnsigned(13 , 0), 13);
//     ASSERT_EQUAL(Integer::divideUnsigned(13 , 1), 13);
//     ASSERT_EQUAL(Integer::divideUnsigned(13 , -1), 0);
//     ASSERT_EQUAL(Integer::divideUnsigned(13 , 13), 1);
//     ASSERT_EQUAL(Integer::divideUnsigned(13 , MAX_VALUE), 0);
//     ASSERT_EQUAL(Integer::divideUnsigned(13 , MIN_VALUE), 0);

//     // ASSERT_EQUAL(Integer::divideUnsigned(MAX_VALUE , 0), 2147483647);
//     ASSERT_EQUAL(Integer::divideUnsigned(MAX_VALUE , 1), 2147483647);
//     ASSERT_EQUAL(Integer::divideUnsigned(MAX_VALUE , -1), 0);
//     ASSERT_EQUAL(Integer::divideUnsigned(MAX_VALUE , 13), 165191049);
//     ASSERT_EQUAL(Integer::divideUnsigned(MAX_VALUE , MAX_VALUE), 1);
//     ASSERT_EQUAL(Integer::divideUnsigned(MAX_VALUE , MIN_VALUE), 0);

//     // ASSERT_EQUAL(Integer::divideUnsigned(MIN_VALUE , 0), -2147483648);
//     ASSERT_EQUAL(Integer::divideUnsigned(MIN_VALUE , 1), -2147483648);
//     ASSERT_EQUAL(Integer::divideUnsigned(MIN_VALUE , -1), 0);
//     ASSERT_EQUAL(Integer::divideUnsigned(MIN_VALUE , 13), 165191049);
//     ASSERT_EQUAL(Integer::divideUnsigned(MIN_VALUE , MAX_VALUE), 1);
//     ASSERT_EQUAL(Integer::divideUnsigned(MIN_VALUE , MIN_VALUE), 1);
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

//     integerInput = MAX_VALUE;
//     ASSERT_DBL_NEAR((double)MAX_VALUE, integerInput.doubleValue());

//     integerInput = MIN_VALUE;
//     ASSERT_DBL_NEAR((double)MIN_VALUE, integerInput.doubleValue());

// }

// TEST(JavaLang, IntegerEquals) {
//     Integer thisInteger;

//     thisInteger = 0;
//     ASSERT_TRUE(thisInteger.equals(0));
//     ASSERT_FALSE(thisInteger.equals(1));
//     ASSERT_FALSE(thisInteger.equals(-1));
//     ASSERT_FALSE(thisInteger.equals(13));
//     ASSERT_FALSE(thisInteger.equals(MAX_VALUE));
//     ASSERT_FALSE(thisInteger.equals(MIN_VALUE));

//     thisInteger = 1;
//     ASSERT_FALSE(thisInteger.equals(0));
//     ASSERT_TRUE(thisInteger.equals(1));
//     ASSERT_FALSE(thisInteger.equals(-1));
//     ASSERT_FALSE(thisInteger.equals(13));
//     ASSERT_FALSE(thisInteger.equals(MAX_VALUE));
//     ASSERT_FALSE(thisInteger.equals(MIN_VALUE));

//     thisInteger = -1;
//     ASSERT_FALSE(thisInteger.equals(0));
//     ASSERT_FALSE(thisInteger.equals(1));
//     ASSERT_TRUE(thisInteger.equals(-1));
//     ASSERT_FALSE(thisInteger.equals(13));
//     ASSERT_FALSE(thisInteger.equals(MAX_VALUE));
//     ASSERT_FALSE(thisInteger.equals(MIN_VALUE));

//     thisInteger = 13;
//     ASSERT_FALSE(thisInteger.equals(0));
//     ASSERT_FALSE(thisInteger.equals(1));
//     ASSERT_FALSE(thisInteger.equals(-1));
//     ASSERT_TRUE(thisInteger.equals(13));
//     ASSERT_FALSE(thisInteger.equals(MAX_VALUE));
//     ASSERT_FALSE(thisInteger.equals(MIN_VALUE));

//     thisInteger = MAX_VALUE;
//     ASSERT_FALSE(thisInteger.equals(0));
//     ASSERT_FALSE(thisInteger.equals(1));
//     ASSERT_FALSE(thisInteger.equals(-1));
//     ASSERT_FALSE(thisInteger.equals(13));
//     ASSERT_TRUE(thisInteger.equals(MAX_VALUE));
//     ASSERT_FALSE(thisInteger.equals(MIN_VALUE));

//     thisInteger = MIN_VALUE;
//     ASSERT_FALSE(thisInteger.equals(0));
//     ASSERT_FALSE(thisInteger.equals(1));
//     ASSERT_FALSE(thisInteger.equals(-1));
//     ASSERT_FALSE(thisInteger.equals(13));
//     ASSERT_FALSE(thisInteger.equals(MAX_VALUE));
//     ASSERT_TRUE(thisInteger.equals(MIN_VALUE));

// }

// Test Integer::getInteger(String inputString)
// TEST(JavaLang, IntegerGetInteger1) {
    // String stringInput;
    // Integer expectedResult;
    // Integer actualResult;

    // // Cast all case of inputing a string of type decimal number
    // stringInput = (String) "";
    // expectedResult = ; // NULL string
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "0";
    // expectedResult = 0;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "1";
    // expectedResult = 1;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "-1";
    // expectedResult = -1;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "13";
    // expectedResult = 13;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "2147483647"; // MAX_VALUE
    // expectedResult = MAX_VALUE;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "-2147483648"; // MIN_VALUE
    // expectedResult = MIN_VALUE;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "Not a Number";
    // expectedResult = ;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());


    // // Cast all case of inputing a string of type octal numberstringInput = (String) "0";
    // stringInput = (String) "00";
    // expectedResult = 0;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "01";
    // expectedResult = 1;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "00001101";
    // expectedResult = 13;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "01111111111111111111111111111111"; // MAX_VALUE
    // expectedResult = 2147483647;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "0111111111111111111111111111111111111111111";
    // expectedResult = ; // out of range 
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "011111111111111111111111111111111112222222";
    // expectedResult = ; // wrong type
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // // Cast all case of inputing a string of type hexadecimal number
    // stringInput = (String) "0x00";
    // expectedResult = 0;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#1";
    // expectedResult = 1;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#FFFFFFFFFFFFFFFF";
    // expectedResult = -1;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "0xD";
    // expectedResult = 13;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "0x7FFFFFFF"; // MAX_VALUE
    // expectedResult = 2147483647;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#FFFFFFFF80000000"; // MIN_VALUE
    // expectedResult = -2147483647;
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#Not a Number";
    // expectedResult = ; // Not a number
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#213546546";
    // expectedResult = ; // Wrong type
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#1111FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
    // expectedResult = ; // Out of range
    // actualResult = Integer:getInteger(stringInput);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

// }

// Test Integer::getInteger(String inputString, int inputInt)
// TEST(JavaLang, IntegerGetInteger2) {
    // String stringInput;
    // Integer expectedResult;
    // Integer actualResult;

    // // Cast all case of inputing a string of type decimal number
    // stringInput = (String) "";
    // expectedResult = 9999; // NULL string
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "0";
    // expectedResult = 0;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "1";
    // expectedResult = 1;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "-1";
    // expectedResult = -1;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "13";
    // expectedResult = 13;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "2147483647"; // MAX_VALUE
    // expectedResult = MAX_VALUE;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "-2147483648"; // MIN_VALUE
    // expectedResult = MIN_VALUE;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "Not a Number";
    // expectedResult = ;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());


    // // Cast all case of inputing a string of type octal numberstringInput = (String) "0";
    // stringInput = (String) "00";
    // expectedResult = 0;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "01";
    // expectedResult = 1;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "00001101";
    // expectedResult = 13;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "01111111111111111111111111111111"; // MAX_VALUE
    // expectedResult = 2147483647;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "0111111111111111111111111111111111111111111";
    // expectedResult = ; // out of range 
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "011111111111111111111111111111111112222222";
    // expectedResult = ; // wrong type
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // // Cast all case of inputing a string of type hexadecimal number
    // stringInput = (String) "0x00";
    // expectedResult = 0;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#1";
    // expectedResult = 1;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#FFFFFFFFFFFFFFFF";
    // expectedResult = -1;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "0xD";
    // expectedResult = 13;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "0x7FFFFFFF"; // MAX_VALUE
    // expectedResult = 2147483647;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#FFFFFFFF80000000"; // MIN_VALUE
    // expectedResult = -2147483647;
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#Not a Number";
    // expectedResult = ; // Not a number
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#213546546";
    // expectedResult = ; // Wrong type
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#1111FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
    // expectedResult = ; // Out of range
    // actualResult = Integer:getInteger(stringInput, 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

// }

// Test Integer::getInteger(String inputString, Integer inputInteger)
// TEST(JavaLang, IntegerGetInteger3) {
    // String stringInput;
    // Integer expectedResult;
    // Integer actualResult;

    // // Cast all case of inputing a string of type decimal number
    // stringInput = (String) "";
    // expectedResult = 9999; // NULL string
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "0";
    // expectedResult = 0;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "1";
    // expectedResult = 1;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "-1";
    // expectedResult = -1;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "13";
    // expectedResult = 13;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "2147483647"; // MAX_VALUE
    // expectedResult = MAX_VALUE;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "-2147483648"; // MIN_VALUE
    // expectedResult = MIN_VALUE;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "Not a Number";
    // expectedResult = ;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());


    // // Cast all case of inputing a string of type octal numberstringInput = (String) "0";
    // stringInput = (String) "00";
    // expectedResult = 0;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "01";
    // expectedResult = 1;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "00001101";
    // expectedResult = 13;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "01111111111111111111111111111111"; // MAX_VALUE
    // expectedResult = 2147483647;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "0111111111111111111111111111111111111111111";
    // expectedResult = ; // out of range 
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "011111111111111111111111111111111112222222";
    // expectedResult = ; // wrong type
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // // Cast all case of inputing a string of type hexadecimal number
    // stringInput = (String) "0x00";
    // expectedResult = 0;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#1";
    // expectedResult = 1;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#FFFFFFFFFFFFFFFF";
    // expectedResult = -1;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "0xD";
    // expectedResult = 13;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "0x7FFFFFFF"; // MAX_VALUE
    // expectedResult = 2147483647;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#FFFFFFFF80000000"; // MIN_VALUE
    // expectedResult = -2147483647;
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#Not a Number";
    // expectedResult = ; // Not a number
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#213546546";
    // expectedResult = ; // Wrong type
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

    // stringInput = (String) "#1111FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
    // expectedResult = ; // Out of range
    // actualResult = Integer:getInteger(stringInput, (Integer) 9999);
    // ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

// }

// Test Integer::hashCode()
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

//     inputInteger = MAX_VALUE;
//     ASSERT_EQUAL(MAX_VALUE, inputInteger.hashCode());

//     inputInteger = MIN_VALUE;
//     ASSERT_EQUAL(MIN_VALUE, inputInteger.hashCode());

// }

// Test Integer::hashCode(int inputInt)
// TEST(JavaLang, IntegerHashCode2) {
//     ASSERT_EQUAL(0, Integer::hashCode(0));
//     ASSERT_EQUAL(1, Integer::hashCode(1));
//     ASSERT_EQUAL(-1, Integer::hashCode(-1));
//     ASSERT_EQUAL(13, Integer::hashCode(13));
//     ASSERT_EQUAL(MAX_VALUE, Integer::hashCode(MAX_VALUE));
//     ASSERT_EQUAL(MIN_VALUE, Integer::hashCode(MIN_VALUE));

// }

TEST(JavaLang, IntegerHighestOneBit) {
    ASSERT_EQUAL(0, Integer::highestOneBit(0));
    ASSERT_EQUAL(1, Integer::highestOneBit(1));
    ASSERT_EQUAL(-2147483648, Integer::highestOneBit(-1));
    ASSERT_EQUAL(8, Integer::highestOneBit(13));
    ASSERT_EQUAL(1073741824, Integer::highestOneBit(MAX_VALUE));
    ASSERT_EQUAL(-2147483648, Integer::highestOneBit(MIN_VALUE)); 
}

TEST(JavaLang, IntegerLowestOneBit) {
    ASSERT_EQUAL(0, Integer::lowestOneBit(0));
    ASSERT_EQUAL(1, Integer::lowestOneBit(1));
    ASSERT_EQUAL(1, Integer::lowestOneBit(-1));
    ASSERT_EQUAL(1, Integer::lowestOneBit(13));
    ASSERT_EQUAL(1, Integer::lowestOneBit(MAX_VALUE));
    ASSERT_EQUAL(-2147483648, Integer::lowestOneBit(MIN_VALUE));
}

TEST(JavaLang, IntegerMax) {
    ASSERT_EQUAL(Integer::max(0, 0), 0);
    ASSERT_EQUAL(Integer::max(0, 1), 1);
    ASSERT_EQUAL(Integer::max(0, -1), 0);
    ASSERT_EQUAL(Integer::max(0, 13), 13);
    ASSERT_EQUAL(Integer::max(0, MAX_VALUE), MAX_VALUE);
    ASSERT_EQUAL(Integer::max(0, MIN_VALUE), 0);

    ASSERT_EQUAL(Integer::max(1, 0), 1);
    ASSERT_EQUAL(Integer::max(1, 1), 1);
    ASSERT_EQUAL(Integer::max(1, -1), 1);
    ASSERT_EQUAL(Integer::max(1, 13), 13);
    ASSERT_EQUAL(Integer::max(1, MAX_VALUE), MAX_VALUE);
    ASSERT_EQUAL(Integer::max(1, MIN_VALUE), 1);

    ASSERT_EQUAL(Integer::max(-1 , 0), 0);
    ASSERT_EQUAL(Integer::max(-1 , 1), 1);
    ASSERT_EQUAL(Integer::max(-1 , -1), -1);
    ASSERT_EQUAL(Integer::max(-1 , 13), 13);
    ASSERT_EQUAL(Integer::max(-1 , MAX_VALUE), MAX_VALUE);
    ASSERT_EQUAL(Integer::max(-1 , MIN_VALUE), -1);

    ASSERT_EQUAL(Integer::max(13 , 0), 13);
    ASSERT_EQUAL(Integer::max(13 , 1), 13);
    ASSERT_EQUAL(Integer::max(13 , -1), 13);
    ASSERT_EQUAL(Integer::max(13 , 13), 13);
    ASSERT_EQUAL(Integer::max(13 , MAX_VALUE), MAX_VALUE);
    ASSERT_EQUAL(Integer::max(13 , MIN_VALUE), 13);

    ASSERT_EQUAL(Integer::max(MAX_VALUE , 0), MAX_VALUE);
    ASSERT_EQUAL(Integer::max(MAX_VALUE , 1), MAX_VALUE);
    ASSERT_EQUAL(Integer::max(MAX_VALUE , -1), MAX_VALUE);
    ASSERT_EQUAL(Integer::max(MAX_VALUE , 13), MAX_VALUE);
    ASSERT_EQUAL(Integer::max(MAX_VALUE , MAX_VALUE), MAX_VALUE);
    ASSERT_EQUAL(Integer::max(MAX_VALUE , MIN_VALUE), MAX_VALUE);

    ASSERT_EQUAL(Integer::max(MIN_VALUE , 0), 0);
    ASSERT_EQUAL(Integer::max(MIN_VALUE , 1), 1);
    ASSERT_EQUAL(Integer::max(MIN_VALUE , -1), -1);
    ASSERT_EQUAL(Integer::max(MIN_VALUE , 13), 13);
    ASSERT_EQUAL(Integer::max(MIN_VALUE , MAX_VALUE), MAX_VALUE);
    ASSERT_EQUAL(Integer::max(MIN_VALUE , MIN_VALUE), MIN_VALUE);
}

TEST(JavaLang, IntegerMin) {
    ASSERT_EQUAL(Integer::min(0, 0), 0);
    ASSERT_EQUAL(Integer::min(0, 1), 0);
    ASSERT_EQUAL(Integer::min(0, -1), -1);
    ASSERT_EQUAL(Integer::min(0, 13), 0);
    ASSERT_EQUAL(Integer::min(0, MAX_VALUE), 0);
    ASSERT_EQUAL(Integer::min(0, MIN_VALUE), MIN_VALUE);

    ASSERT_EQUAL(Integer::min(1, 0), 0);
    ASSERT_EQUAL(Integer::min(1, 1), 1);
    ASSERT_EQUAL(Integer::min(1, -1), -1);
    ASSERT_EQUAL(Integer::min(1, 13), 1);
    ASSERT_EQUAL(Integer::min(1, MAX_VALUE), 1);
    ASSERT_EQUAL(Integer::min(1, MIN_VALUE), MIN_VALUE);

    ASSERT_EQUAL(Integer::min(-1 , 0), -1);
    ASSERT_EQUAL(Integer::min(-1 , 1), -1);
    ASSERT_EQUAL(Integer::min(-1 , -1), -1);
    ASSERT_EQUAL(Integer::min(-1 , 13), -1);
    ASSERT_EQUAL(Integer::min(-1 , MAX_VALUE), -1);
    ASSERT_EQUAL(Integer::min(-1 , MIN_VALUE), MIN_VALUE);

    ASSERT_EQUAL(Integer::min(13 , 0), 0);
    ASSERT_EQUAL(Integer::min(13 , 1), 1);
    ASSERT_EQUAL(Integer::min(13 , -1), -1);
    ASSERT_EQUAL(Integer::min(13 , 13), 13);
    ASSERT_EQUAL(Integer::min(13 , MAX_VALUE), 13);
    ASSERT_EQUAL(Integer::min(13 , MIN_VALUE), MIN_VALUE);

    ASSERT_EQUAL(Integer::min(MAX_VALUE , 0), 0);
    ASSERT_EQUAL(Integer::min(MAX_VALUE , 1), 1);
    ASSERT_EQUAL(Integer::min(MAX_VALUE , -1), -1);
    ASSERT_EQUAL(Integer::min(MAX_VALUE , 13), 13);
    ASSERT_EQUAL(Integer::min(MAX_VALUE , MAX_VALUE), MAX_VALUE);
    ASSERT_EQUAL(Integer::min(MAX_VALUE , MIN_VALUE), MIN_VALUE);

    ASSERT_EQUAL(Integer::min(MIN_VALUE , 0), MIN_VALUE);
    ASSERT_EQUAL(Integer::min(MIN_VALUE , 1), MIN_VALUE);
    ASSERT_EQUAL(Integer::min(MIN_VALUE , -1), MIN_VALUE);
    ASSERT_EQUAL(Integer::min(MIN_VALUE , 13), MIN_VALUE);
    ASSERT_EQUAL(Integer::min(MIN_VALUE , MAX_VALUE), MIN_VALUE);
    ASSERT_EQUAL(Integer::min(MIN_VALUE , MIN_VALUE), MIN_VALUE);
}

TEST(JavaLang, IntegerNumberOfLeadingZeros) {
    ASSERT_EQUAL(32, Integer::numberOfLeadingZeros(0));
    ASSERT_EQUAL(31, Integer::numberOfLeadingZeros(1));
    ASSERT_EQUAL(0, Integer::numberOfLeadingZeros(-1));
    ASSERT_EQUAL(28, Integer::numberOfLeadingZeros(13));
    ASSERT_EQUAL(1, Integer::numberOfLeadingZeros(MAX_VALUE));
    ASSERT_EQUAL(0, Integer::numberOfLeadingZeros(MIN_VALUE));
}

TEST(JavaLang, IntegerNumberOfTrailingZeros) {
    ASSERT_EQUAL(32, Integer::numberOfTrailingZeros(0));
    ASSERT_EQUAL(0, Integer::numberOfTrailingZeros(1));
    ASSERT_EQUAL(0, Integer::numberOfTrailingZeros(-1));
    ASSERT_EQUAL(0, Integer::numberOfTrailingZeros(13));
    ASSERT_EQUAL(0, Integer::numberOfTrailingZeros(MAX_VALUE));
    ASSERT_EQUAL(31, Integer::numberOfTrailingZeros(MIN_VALUE));
}

// Test Integer::parseInt(String inputString, int radix)
// TEST(JavaLang, IntegerParseInt) {
    // ASSERT_EQUAL(Integer::parseInt((String)"0", 10), 0);
    // ASSERT_EQUAL(Integer::parseInt((String)"473", 10), 473);
    // ASSERT_EQUAL(Integer::parseInt((String)"+42", 10), 42);
    // ASSERT_EQUAL(Integer::parseInt((String)"-0", 10), 0);
    // ASSERT_EQUAL(Integer::parseInt((String)"-FF", 16), -255);
    // ASSERT_EQUAL(Integer::parseInt((String)"1100110", 2), 102);
    // ASSERT_EQUAL(Integer::parseInt((String)"2147483647", 10), 2147483647);
    // ASSERT_EQUAL(Integer::parseInt((String)"-2147483648", 10), -2147483648);
    // ASSERT_EQUAL(Integer::parseInt((String)"2147483648", 10) throws a NumberFormatException);
    // ASSERT_EQUAL(Integer::parseInt((String)"99", 8) throws a NumberFormatException);
    // ASSERT_EQUAL(Integer::parseInt((String)"Kona", 10) throws a NumberFormatException);
    // ASSERT_EQUAL(Integer::parseInt((String)"Kona", 27), 411787);

// }

// Test Integer::parseInt(String inputString)
// TEST(JavaLang, IntegerParseInt2) {
    // String stringInput;
    // int expectedResult;
    // int actualResult;

    // // Cast all case of inputing a string of type decimal number
    // stringInput = (String) "0";
    // expectedResult = 0;
    // actualResult = Integer::parseInt(stringInput);
    // ASSERT_EQUAL(expectedResult, actualResult);

    // stringInput = (String) "1";
    // expectedResult = 1;
    // actualResult = Integer::parseInt(stringInput);
    // ASSERT_EQUAL(expectedResult, actualResult);

    // stringInput = (String) "-1";
    // expectedResult = -1;
    // actualResult = Integer::parseInt(stringInput);
    // ASSERT_EQUAL(expectedResult, actualResult);

    // stringInput = (String) "13";
    // expectedResult = 13;
    // actualResult = Integer::parseInt(stringInput);
    // ASSERT_EQUAL(expectedResult, actualResult);

    // stringInput = (String) "2147483647"; // MAX_VALUE
    // expectedResult = MAX_VALUE;
    // actualResult = Integer::parseInt(stringInput);
    // ASSERT_EQUAL(expectedResult, actualResult);

    // stringInput = (String) "-2147483648"; // MIN_VALUE
    // expectedResult = MIN_VALUE;
    // actualResult = Integer::parseInt(stringInput);
    // ASSERT_EQUAL(expectedResult, actualResult);

    // stringInput = (String) "Not a Number";
    // expectedResult = ;
    // actualResult = Integer::parseInt(stringInput);
    // ASSERT_EQUAL(expectedResult, actualResult);

    // stringInput = (String) "12345678901234567890123456789";
    // expectedResult = ; // out of range
    // actualResult = Integer::parseInt(stringInput);
    // ASSERT_EQUAL(expectedResult, actualResult);

// }

// Test int Integer::parseUnsignedInt(String inputString, int radix)
// TEST(JavaLang, IntegerParseUnsignedInt) {
//     ASSERT_EQUAL(Integer::parseUnsignedInt((String)"0", 10), 0);
//     ASSERT_EQUAL(Integer::parseUnsignedInt((String)"473", 10), 473);
//     ASSERT_EQUAL(Integer::parseUnsignedInt((String)"+42", 10), 42);
//     ASSERT_EQUAL(Integer::parseUnsignedInt((String)"-0", 10), 0);
//     ASSERT_EQUAL(Integer::parseUnsignedInt((String)"-FF", 16), -255); throws a NumberFormatException
//     ASSERT_EQUAL(Integer::parseUnsignedInt((String)"1100110", 2), 102);
//     ASSERT_EQUAL(Integer::parseUnsignedInt((String)"2147483647", 10), 2147483647);
//     ASSERT_EQUAL(Integer::parseUnsignedInt((String)"-2147483648", 10), -2147483648); throws a NumberFormatException
//     ASSERT_EQUAL(Integer::parseUnsignedInt((String)"2147483648", 10) throws a NumberFormatException);
//     ASSERT_EQUAL(Integer::parseUnsignedInt((String)"99", 8) throws a NumberFormatException);
//     ASSERT_EQUAL(Integer::parseUnsignedInt((String)"Kona", 10) throws a NumberFormatException);
//     ASSERT_EQUAL(Integer::parseUnsignedInt((String)"Kona", 27), 411787);

// }

// Test int Integer::parseUnsignedInt(String inputString)
// TEST(JavaLang, IntegerParseUnsignedInt2) {
//     String stringInput;
//     int expectedResult;
//     int actualResult;

//     // Cast all case of inputing a string of type decimal number
//     stringInput = (String) "0";
//     expectedResult = 0;
//     actualResult = Integer::parseUnsignedInt(stringInput);
//     ASSERT_EQUAL(expectedResult, actualResult);

//     stringInput = (String) "1";
//     expectedResult = 1;
//     actualResult = Integer::parseUnsignedInt(stringInput);
//     ASSERT_EQUAL(expectedResult, actualResult);

//     stringInput = (String) "-1";
//     expectedResult = -1; throws a NumberFormatException
//     actualResult = Integer::parseUnsignedInt(stringInput);
//     ASSERT_EQUAL(expectedResult, actualResult);

//     stringInput = (String) "13";
//     expectedResult = 13;
//     actualResult = Integer::parseUnsignedInt(stringInput);
//     ASSERT_EQUAL(expectedResult, actualResult);

//     stringInput = (String) "2147483647"; // MAX_VALUE
//     expectedResult = MAX_VALUE;
//     actualResult = Integer::parseUnsignedInt(stringInput);
//     ASSERT_EQUAL(expectedResult, actualResult);

//     stringInput = (String) "-2147483648"; // MIN_VALUE
//     expectedResult = MIN_VALUE; throws a NumberFormatException
//     actualResult = Integer::parseUnsignedInt(stringInput);
//     ASSERT_EQUAL(expectedResult, actualResult);

//     stringInput = (String) "Not a Number";
//     expectedResult = ; throws a NumberFormatException
//     actualResult = Integer::parseUnsignedInt(stringInput);
//     ASSERT_EQUAL(expectedResult, actualResult);

//     stringInput = (String) "12345678901234567890123456789";
//     expectedResult = ; // out of range throws a NumberFormatException
//     actualResult = Integer::parseUnsignedInt(stringInput);
//     ASSERT_EQUAL(expectedResult, actualResult);

// }

TEST(JavaLang, IntegerRemainderUnsigned) {
    // TODO(thoangminh): throw exception these cases later
    // ASSERT_EQUAL(Integer::remainderUnsigned(0,aaaa), 9999); // error: cannot find symbol
    // ASSERT_EQUAL(Integer::remainderUnsigned(0,123456789132456789123456), 9999); // integer number too large
    // ASSERT_EQUAL(Integer::remainderUnsigned(0,MAX_VALUE +1), 9999); // out of range
    // ASSERT_EQUAL(Integer::remainderUnsigned(0,MAX_VALUE + 2), 9999); // out of range
    // ASSERT_EQUAL(Integer::remainderUnsigned(0,MIN_VALUE -1), 9999); // out of range
    // ASSERT_EQUAL(Integer::remainderUnsigned(0,MIN_VALUE -2), 9999); // out of range
    // ASSERT_EQUAL(Integer::remainderUnsigned(0,"MIN_VALUE -2"), 9999); // error: incompatible types: String cannot be converted to int
    // ASSERT_EQUAL(Integer::remainderUnsigned(1, 0), 9999);// java.lang.ArithmeticException: / by zero

    ASSERT_EQUAL(Integer::remainderUnsigned(0, 1), 0);
    ASSERT_EQUAL(Integer::remainderUnsigned(0, -1), 0);
    ASSERT_EQUAL(Integer::remainderUnsigned(0, 13), 0);
    ASSERT_EQUAL(Integer::remainderUnsigned(0, MAX_VALUE), 0);
    ASSERT_EQUAL(Integer::remainderUnsigned(0, MIN_VALUE), 0);
    
    ASSERT_EQUAL(Integer::remainderUnsigned(1, 1), 0);
    ASSERT_EQUAL(Integer::remainderUnsigned(1, -1), 1);
    ASSERT_EQUAL(Integer::remainderUnsigned(1, 13), 1);
    ASSERT_EQUAL(Integer::remainderUnsigned(1, MAX_VALUE), 1);
    ASSERT_EQUAL(Integer::remainderUnsigned(1, MIN_VALUE), 1);

    ASSERT_EQUAL(Integer::remainderUnsigned(-1 , 1), 0);
    ASSERT_EQUAL(Integer::remainderUnsigned(-1 , -1), 0);
    ASSERT_EQUAL(Integer::remainderUnsigned(-1 , 13), 8);
    ASSERT_EQUAL(Integer::remainderUnsigned(-1 , MAX_VALUE), 1);
    ASSERT_EQUAL(Integer::remainderUnsigned(-1 , MIN_VALUE), 2147483647);

    ASSERT_EQUAL(Integer::remainderUnsigned(13 , 1), 0);
    ASSERT_EQUAL(Integer::remainderUnsigned(13 , -1), 13);
    ASSERT_EQUAL(Integer::remainderUnsigned(13 , 13), 0);
    ASSERT_EQUAL(Integer::remainderUnsigned(13 , MAX_VALUE), 13);
    ASSERT_EQUAL(Integer::remainderUnsigned(13 , MIN_VALUE), 13);

    ASSERT_EQUAL(Integer::remainderUnsigned(MAX_VALUE , 1), 0);
    ASSERT_EQUAL(Integer::remainderUnsigned(MAX_VALUE , -1), 2147483647);
    ASSERT_EQUAL(Integer::remainderUnsigned(MAX_VALUE , 13), 10);
    ASSERT_EQUAL(Integer::remainderUnsigned(MAX_VALUE , MAX_VALUE), 0);
    ASSERT_EQUAL(Integer::remainderUnsigned(MAX_VALUE , MIN_VALUE), 2147483647);

    ASSERT_EQUAL(Integer::remainderUnsigned(MIN_VALUE , 1), 0);
    ASSERT_EQUAL(Integer::remainderUnsigned(MIN_VALUE , -1), -2147483648);
    ASSERT_EQUAL(Integer::remainderUnsigned(MIN_VALUE , 13), 11);
    ASSERT_EQUAL(Integer::remainderUnsigned(MIN_VALUE , MAX_VALUE), 1);
    ASSERT_EQUAL(Integer::remainderUnsigned(MIN_VALUE , MIN_VALUE), 0);
}

TEST(JavaLang, IntegerReverse) {
    ASSERT_EQUAL(0, Integer::reverse(0));
    ASSERT_EQUAL(-2147483648, Integer::reverse(1));
    ASSERT_EQUAL(-1, Integer::reverse(-1));
    ASSERT_EQUAL(-1342177280, Integer::reverse(13));
    ASSERT_EQUAL(-2, Integer::reverse(MAX_VALUE));
    ASSERT_EQUAL(1, Integer::reverse(MIN_VALUE));
}

TEST(JavaLang, IntegerReverseBytes) {
    ASSERT_EQUAL(0, Integer::reverseBytes(0));
    ASSERT_EQUAL(16777216, Integer::reverseBytes(1));
    ASSERT_EQUAL(-1, Integer::reverseBytes(-1));
    ASSERT_EQUAL(218103808, Integer::reverseBytes(13));
    ASSERT_EQUAL(-129, Integer::reverseBytes(MAX_VALUE));
    ASSERT_EQUAL(128, Integer::reverseBytes(MIN_VALUE));
}

TEST(JavaLang, IntegerRotateLeft) {
    ASSERT_EQUAL(Integer::rotateLeft(0, 0), 0);
    ASSERT_EQUAL(Integer::rotateLeft(0, 1), 0);
    ASSERT_EQUAL(Integer::rotateLeft(0, -1), 0);
    ASSERT_EQUAL(Integer::rotateLeft(0, 13), 0);
    ASSERT_EQUAL(Integer::rotateLeft(0, MAX_VALUE), 0);
    ASSERT_EQUAL(Integer::rotateLeft(0, MIN_VALUE), 0);

    ASSERT_EQUAL(Integer::rotateLeft(1, 0), 1);
    ASSERT_EQUAL(Integer::rotateLeft(1, 1), 2);
    ASSERT_EQUAL(Integer::rotateLeft(1, -1), -2147483648);
    ASSERT_EQUAL(Integer::rotateLeft(1, 13), 8192);
    ASSERT_EQUAL(Integer::rotateLeft(1, MAX_VALUE), -2147483648);
    ASSERT_EQUAL(Integer::rotateLeft(1, MIN_VALUE), 1);

    ASSERT_EQUAL(Integer::rotateLeft(-1 , 0), -1);
    ASSERT_EQUAL(Integer::rotateLeft(-1 , 1), -1);
    ASSERT_EQUAL(Integer::rotateLeft(-1 , -1), -1);
    ASSERT_EQUAL(Integer::rotateLeft(-1 , 13), -1);
    ASSERT_EQUAL(Integer::rotateLeft(-1 , MAX_VALUE), -1);
    ASSERT_EQUAL(Integer::rotateLeft(-1 , MIN_VALUE), -1);

    ASSERT_EQUAL(Integer::rotateLeft(13 , 0), 13);
    ASSERT_EQUAL(Integer::rotateLeft(13 , 1), 26);
    ASSERT_EQUAL(Integer::rotateLeft(13 , -1), -2147483642);
    ASSERT_EQUAL(Integer::rotateLeft(13 , 13), 106496);
    ASSERT_EQUAL(Integer::rotateLeft(13 , MAX_VALUE), -2147483642);
    ASSERT_EQUAL(Integer::rotateLeft(13 , MIN_VALUE), 13);

    ASSERT_EQUAL(Integer::rotateLeft(MAX_VALUE , 0), 2147483647);
    ASSERT_EQUAL(Integer::rotateLeft(MAX_VALUE , 1), -2);
    ASSERT_EQUAL(Integer::rotateLeft(MAX_VALUE , -1), -1073741825);
    ASSERT_EQUAL(Integer::rotateLeft(MAX_VALUE , 13), -4097);
    ASSERT_EQUAL(Integer::rotateLeft(MAX_VALUE , MAX_VALUE), -1073741825);
    ASSERT_EQUAL(Integer::rotateLeft(MAX_VALUE , MIN_VALUE), 2147483647);

    ASSERT_EQUAL(Integer::rotateLeft(MIN_VALUE , 0), -2147483648);
    ASSERT_EQUAL(Integer::rotateLeft(MIN_VALUE , 1), 1);
    ASSERT_EQUAL(Integer::rotateLeft(MIN_VALUE , -1), 1073741824);
    ASSERT_EQUAL(Integer::rotateLeft(MIN_VALUE , 13), 4096);
    ASSERT_EQUAL(Integer::rotateLeft(MIN_VALUE , MAX_VALUE), 1073741824);
    ASSERT_EQUAL(Integer::rotateLeft(MIN_VALUE , MIN_VALUE), -2147483648);
}

TEST(JavaLang, IntegerRotateRight) {
    ASSERT_EQUAL(Integer::rotateRight(0, 0), 0);
    ASSERT_EQUAL(Integer::rotateRight(0, 1), 0);
    ASSERT_EQUAL(Integer::rotateRight(0, -1), 0);
    ASSERT_EQUAL(Integer::rotateRight(0, 13), 0);
    ASSERT_EQUAL(Integer::rotateRight(0, MAX_VALUE), 0);
    ASSERT_EQUAL(Integer::rotateRight(0, MIN_VALUE), 0);

    ASSERT_EQUAL(Integer::rotateRight(1, 0), 1);
    ASSERT_EQUAL(Integer::rotateRight(1, 1), -2147483648);
    ASSERT_EQUAL(Integer::rotateRight(1, -1), 2);
    ASSERT_EQUAL(Integer::rotateRight(1, 13), 524288);
    ASSERT_EQUAL(Integer::rotateRight(1, MAX_VALUE), 2);
    ASSERT_EQUAL(Integer::rotateRight(1, MIN_VALUE), 1);

    ASSERT_EQUAL(Integer::rotateRight(-1 , 0), -1);
    ASSERT_EQUAL(Integer::rotateRight(-1 , 1), -1);
    ASSERT_EQUAL(Integer::rotateRight(-1 , -1), -1);
    ASSERT_EQUAL(Integer::rotateRight(-1 , 13), -1);
    ASSERT_EQUAL(Integer::rotateRight(-1 , MAX_VALUE), -1);
    ASSERT_EQUAL(Integer::rotateRight(-1 , MIN_VALUE), -1);

    ASSERT_EQUAL(Integer::rotateRight(13 , 0), 13);
    ASSERT_EQUAL(Integer::rotateRight(13 , 1), -2147483642);
    ASSERT_EQUAL(Integer::rotateRight(13 , -1), 26);
    ASSERT_EQUAL(Integer::rotateRight(13 , 13), 6815744);
    ASSERT_EQUAL(Integer::rotateRight(13 , MAX_VALUE), 26);
    ASSERT_EQUAL(Integer::rotateRight(13 , MIN_VALUE), 13);

    ASSERT_EQUAL(Integer::rotateRight(MAX_VALUE , 0), 2147483647);
    ASSERT_EQUAL(Integer::rotateRight(MAX_VALUE , 1), -1073741825);
    ASSERT_EQUAL(Integer::rotateRight(MAX_VALUE , -1), -2);
    ASSERT_EQUAL(Integer::rotateRight(MAX_VALUE , 13), -262145);
    ASSERT_EQUAL(Integer::rotateRight(MAX_VALUE , MAX_VALUE), -2);
    ASSERT_EQUAL(Integer::rotateRight(MAX_VALUE , MIN_VALUE), 2147483647);

    ASSERT_EQUAL(Integer::rotateRight(MIN_VALUE , 0), -2147483648);
    ASSERT_EQUAL(Integer::rotateRight(MIN_VALUE , 1), 1073741824);
    ASSERT_EQUAL(Integer::rotateRight(MIN_VALUE , -1), 1);
    ASSERT_EQUAL(Integer::rotateRight(MIN_VALUE , 13), 262144);
    ASSERT_EQUAL(Integer::rotateRight(MIN_VALUE , MAX_VALUE), 1);
    ASSERT_EQUAL(Integer::rotateRight(MIN_VALUE , MIN_VALUE), -2147483648);

    // System.out.println(Integer.rotateRight(0, 0));
    // System.out.println(Integer.rotateRight(0, 1));
    // System.out.println(Integer.rotateRight(0, -1));
    // System.out.println(Integer.rotateRight(0, 13));
    // System.out.println(Integer.rotateRight(0,Integer.MAX_VALUE));
    // System.out.println(Integer.rotateRight(0,Integer.MIN_VALUE));
}

// TEST(JavaLang, IntegerSignum) {
    // ASSERT_EQUAL(0, Integer::signum(0));
    // ASSERT_EQUAL(1, Integer::signum(1));
    // ASSERT_EQUAL(-1, Integer::signum(-1));
    // ASSERT_EQUAL(1, Integer::signum(13));
    // ASSERT_EQUAL(1, Integer::signum(MAX_VALUE));
    // ASSERT_EQUAL(-1, Integer::signum(MIN_VALUE));

    // System.out.println(Integer.signum(0));
    // System.out.println(Integer.signum(1));
    // System.out.println(Integer.signum(-1));
    // System.out.println(Integer.signum(13));
    // System.out.println(Integer.signum(Integer.MAX_VALUE));
    // System.out.println(Integer.signum(Integer.MIN_VALUE));

// }

// TEST(JavaLang, IntegerSum) {
//     ASSERT_EQUAL(Integer::sum(0, 0), 0);
//     ASSERT_EQUAL(Integer::sum(0, 1), 1);
//     ASSERT_EQUAL(Integer::sum(0, -1), -1);
//     ASSERT_EQUAL(Integer::sum(0, 13), 13);
//     ASSERT_EQUAL(Integer::sum(0, MAX_VALUE), MAX_VALUE);
//     ASSERT_EQUAL(Integer::sum(0, MIN_VALUE), MIN_VALUE);

//     ASSERT_EQUAL(Integer::sum(1, 0), 1);
//     ASSERT_EQUAL(Integer::sum(1, 1), 1);
//     ASSERT_EQUAL(Integer::sum(1, -1), 0);
//     ASSERT_EQUAL(Integer::sum(1, 13), 14);
//     ASSERT_EQUAL(Integer::sum(1, MAX_VALUE), -2147483648);
//     ASSERT_EQUAL(Integer::sum(1, MIN_VALUE), -2147483647);

//     ASSERT_EQUAL(Integer::sum(-1 , 0), -1);
//     ASSERT_EQUAL(Integer::sum(-1 , 1), 0);
//     ASSERT_EQUAL(Integer::sum(-1 , -1), -2);
//     ASSERT_EQUAL(Integer::sum(-1 , 13), 12);
//     ASSERT_EQUAL(Integer::sum(-1 , MAX_VALUE), 2147483646);
//     ASSERT_EQUAL(Integer::sum(-1 , MIN_VALUE), 2147483647);

//     ASSERT_EQUAL(Integer::sum(13 , 0), 13);
//     ASSERT_EQUAL(Integer::sum(13 , 1), 14);
//     ASSERT_EQUAL(Integer::sum(13 , -1), 12);
//     ASSERT_EQUAL(Integer::sum(13 , 13), 26);
//     ASSERT_EQUAL(Integer::sum(13 , MAX_VALUE), -2147483636);
//     ASSERT_EQUAL(Integer::sum(13 , MIN_VALUE), -2147483635);

//     ASSERT_EQUAL(Integer::sum(MAX_VALUE , 0), 2147483647);
//     ASSERT_EQUAL(Integer::sum(MAX_VALUE , 1), -2147483648);
//     ASSERT_EQUAL(Integer::sum(MAX_VALUE , -1), 2147483646);
//     ASSERT_EQUAL(Integer::sum(MAX_VALUE , 13), -2147483636);
//     ASSERT_EQUAL(Integer::sum(MAX_VALUE , MAX_VALUE), -2);
//     ASSERT_EQUAL(Integer::sum(MAX_VALUE , MIN_VALUE), -1);

//     ASSERT_EQUAL(Integer::sum(MIN_VALUE , 0), -2147483648);
//     ASSERT_EQUAL(Integer::sum(MIN_VALUE , 1), -2147483647);
//     ASSERT_EQUAL(Integer::sum(MIN_VALUE , -1), 2147483647);
//     ASSERT_EQUAL(Integer::sum(MIN_VALUE , 13), -2147483635);
//     ASSERT_EQUAL(Integer::sum(MIN_VALUE , MAX_VALUE), -1);
//     ASSERT_EQUAL(Integer::sum(MIN_VALUE , MIN_VALUE), 0);

//     System.out.println(Integer.sum(Integer.MIN_VALUE, 0));
//     System.out.println(Integer.sum(Integer.MIN_VALUE, 1));
//     System.out.println(Integer.sum(Integer.MIN_VALUE, -1));
//     System.out.println(Integer.sum(Integer.MIN_VALUE, 13));
//     System.out.println(Integer.sum(Integer.MIN_VALUE,Integer.MAX_VALUE));
//     System.out.println(Integer.sum(Integer.MIN_VALUE,Integer.MIN_VALUE));

// }

// TEST(JavaLang, IntegerToBinaryString) {
    // ASSERT_STR((string) "0", Integer::toBinaryString(0));
    // ASSERT_STR((string) "1", Integer::toBinaryString(1));
    // ASSERT_STR((string) "11111111111111111111111111111111", Integer::toBinaryString(-1));
    // ASSERT_STR((string) "1101", Integer::toBinaryString(13));
    // ASSERT_STR((string) "1111111111111111111111111111111", Integer::toBinaryString(MAX_VALUE));
    // ASSERT_STR((string) "10000000000000000000000000000000", Integer::toBinaryString(MIN_VALUE));

    // System.out.println(Integer.toBinaryString(0));
    // System.out.println(Integer.toBinaryString(1));
    // System.out.println(Integer.toBinaryString(-1));
    // System.out.println(Integer.toBinaryString(13));
    // System.out.println(Integer.toBinaryString(Integer.MAX_VALUE));
    // System.out.println(Integer.toBinaryString(Integer.MIN_VALUE));

// }

// TEST(JavaLang, IntegerToHexString) {
    // ASSERT_STR((string) "0", Integer::toHexString(0));
    // ASSERT_STR((string) "1", Integer::toHexString(1));
    // ASSERT_STR((string) "ffffffff", Integer::toHexString(-1));
    // ASSERT_STR((string) "d", Integer::toHexString(13));
    // ASSERT_STR((string) "7fffffff", Integer::toHexString(MAX_VALUE));
    // ASSERT_STR((string) "80000000", Integer::toHexString(MIN_VALUE));

    // System.out.println(Integer.toHexString(0));
    // System.out.println(Integer.toHexString(1));
    // System.out.println(Integer.toHexString(-1));
    // System.out.println(Integer.toHexString(13));
    // System.out.println(Integer.toHexString(Integer.MAX_VALUE));
    // System.out.println(Integer.toHexString(Integer.MIN_VALUE));

// }

// TEST(JavaLang, IntegerToOctalString) {
//     ASSERT_STR((string) "0", Integer::toOctalString(0));
//     ASSERT_STR((string) "1", Integer::toOctalString(1));
//     ASSERT_STR((string) "37777777777", Integer::toOctalString(-1));
//     ASSERT_STR((string) "15", Integer::toOctalString(13));
//     ASSERT_STR((string) "17777777777", Integer::toOctalString(MAX_VALUE));
//     ASSERT_STR((string) "20000000000", Integer::toOctalString(MIN_VALUE));

    // System.out.println(Integer.toOctalString(0));
    // System.out.println(Integer.toOctalString(1));
    // System.out.println(Integer.toOctalString(-1));
    // System.out.println(Integer.toOctalString(13));
    // System.out.println(Integer.toOctalString(Integer.MAX_VALUE));
    // System.out.println(Integer.toOctalString(Integer.MIN_VALUE));

// }

// Test Integer::toString() const
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

// Test String Integer::toString(int i)
// TEST(JavaLang, IntegerToString2) {
//     ASSERT_STR((string) "0", Integer::toString(0));
//     ASSERT_STR((string) "1", Integer::toString(1));
//     ASSERT_STR((string) "-1", Integer::toString(-1));
//     ASSERT_STR((string) "13", Integer::toString(13));
//     ASSERT_STR((string) "2147483647", Integer::toString(MAX_VALUE));
//     ASSERT_STR((string) "-2147483648", Integer::toString(MIN_VALUE));

//     System.out.println(Integer.toString(0));
//     System.out.println(Integer.toString(1));
//     System.out.println(Integer.toString(-1));
//     System.out.println(Integer.toString(13));
//     System.out.println(Integer.toString(Integer.MAX_VALUE));
//     System.out.println(Integer.toString(Integer.MIN_VALUE));

// }

// Test Integer::toString(int inputInt, int radix)
// TEST(JavaLang, IntegerToString3) {
    // // TODO(thoangminh): check these cases
    // ASSERT_STR((string) "9999", Integer::toString(0,aaaa)); // error: cannot find symbol
    // ASSERT_STR((string) "9999", Integer::toString(0,123456789132456789123456)); // integer number too large
    // ASSERT_STR((string) "9999", Integer::toString(0,MAX_VALUE +1)); // out of range
    // ASSERT_STR((string) "9999", Integer::toString(0,MAX_VALUE + 2)); // out of range
    // ASSERT_STR((string) "9999", Integer::toString(0,MIN_VALUE -1)); // out of range
    // ASSERT_STR((string) "9999", Integer::toString(0,MIN_VALUE -2)); // out of range
    // ASSERT_STR((string) "9999", Integer::toString(0,"MIN_VALUE -2")); // error: incompatible types: String cannot be converted to int

    // ASSERT_STR((string) "0", (string) "", Integer::toString(0, 1));
    // ASSERT_STR((string) "0", Integer::toString(0, -1));
    // ASSERT_STR((string) "0", Integer::toString(0, 13));
    // ASSERT_STR((string) "0", Integer::toString(0, MAX_VALUE));
    // ASSERT_STR((string) "0", Integer::toString(0, MIN_VALUE));

    // ASSERT_STR((string) "1", Integer::toString(1, 0));// java.lang.ArithmeticException: / by zero
    // ASSERT_STR((string) "1", Integer::toString(1, 1));
    // ASSERT_STR((string) "1", Integer::toString(1, -1));
    // ASSERT_STR((string) "1", Integer::toString(1, 13));
    // ASSERT_STR((string) "1", Integer::toString(1, MAX_VALUE));
    // ASSERT_STR((string) "1", Integer::toString(1, MIN_VALUE));

    // ASSERT_STR((string) "-1", Integer::toString(-1 , 0));// java.lang.ArithmeticException: / by zero
    // ASSERT_STR((string) "-1", Integer::toString(-1 , 1));
    // ASSERT_STR((string) "-1", Integer::toString(-1 , -1));
    // ASSERT_STR((string) "-1", Integer::toString(-1 , 13));
    // ASSERT_STR((string) "-1", Integer::toString(-1 , MAX_VALUE));
    // ASSERT_STR((string) "-1", Integer::toString(-1 , MIN_VALUE));

    // ASSERT_STR((string) "13", Integer::toString(13 , 0));// java.lang.ArithmeticException: / by zero
    // ASSERT_STR((string) "13", Integer::toString(13 , 1));
    // ASSERT_STR((string) "13", Integer::toString(13 , -1));
    // ASSERT_STR((string) "10", Integer::toString(13 , 13));
    // ASSERT_STR((string) "13", Integer::toString(13 , MAX_VALUE));
    // ASSERT_STR((string) "13", Integer::toString(13 , MIN_VALUE));

    // ASSERT_STR((string) "2147483647", Integer::toString(MAX_VALUE , 0));// java.lang.ArithmeticException: / by zero
    // ASSERT_STR((string) "2147483647", Integer::toString(MAX_VALUE , 1));
    // ASSERT_STR((string) "2147483647", Integer::toString(MAX_VALUE , -1));
    // ASSERT_STR((string) "282ba4aaa", Integer::toString(MAX_VALUE , 13));
    // ASSERT_STR((string) "2147483647", Integer::toString(MAX_VALUE , MAX_VALUE));
    // ASSERT_STR((string) "2147483647", Integer::toString(MAX_VALUE , MIN_VALUE));

    // ASSERT_STR((string) "-2147483648", Integer::toString(MIN_VALUE , 0));// java.lang.ArithmeticException: / by zero
    // ASSERT_STR((string) "-2147483648", Integer::toString(MIN_VALUE , 1));
    // ASSERT_STR((string) "-2147483648", Integer::toString(MIN_VALUE , -1));
    // ASSERT_STR((string) "-282ba4aab", Integer::toString(MIN_VALUE , 13));
    // ASSERT_STR((string) "-2147483648", Integer::toString(MIN_VALUE , MAX_VALUE));
    // ASSERT_STR((string) "-2147483648", Integer::toString(MIN_VALUE , MIN_VALUE));

    // System.out.println(Integer.toString(Integer.MIN_VALUE,  0));
    // System.out.println(Integer.toString(Integer.MIN_VALUE,  1));
    // System.out.println(Integer.toString(Integer.MIN_VALUE,  -1));
    // System.out.println(Integer.toString(Integer.MIN_VALUE,  13));
    // System.out.println(Integer.toString(Integer.MIN_VALUE,  Integer.MAX_VALUE));
    // System.out.println(Integer.toString(Integer.MIN_VALUE,  Integer.MIN_VALUE));

// }

TEST(JavaLang, IntegerToUnsignedLong) {
    ASSERT_EQUAL(0, Integer::toUnsignedLong(0));
    ASSERT_EQUAL(1, Integer::toUnsignedLong(1));
    ASSERT_EQUAL(4294967295, Integer::toUnsignedLong(-1));
    ASSERT_EQUAL(13, Integer::toUnsignedLong(13));
    ASSERT_EQUAL(2147483647, Integer::toUnsignedLong(MAX_VALUE));
    ASSERT_EQUAL(2147483648, Integer::toUnsignedLong(MIN_VALUE));
}

// TEST(JavaLang, IntegerToUnsignedString) {
//     // TODO(thoangminh): check these cases
//     ASSERT_STR((string) "9999", Integer::toUnsignedString(0,aaaa)); // error: cannot find symbol
//     ASSERT_STR((string) "9999", Integer::toUnsignedString(0,123456789132456789123456)); // integer number too large
//     ASSERT_STR((string) "9999", Integer::toUnsignedString(0,MAX_VALUE +1)); // out of range
//     ASSERT_STR((string) "9999", Integer::toUnsignedString(0,MAX_VALUE + 2)); // out of range
//     ASSERT_STR((string) "9999", Integer::toUnsignedString(0,MIN_VALUE -1)); // out of range
//     ASSERT_STR((string) "9999", Integer::toUnsignedString(0,MIN_VALUE -2)); // out of range
//     ASSERT_STR((string) "9999", Integer::toUnsignedString(0,"MIN_VALUE -2")); // error: incompatible types: String cannot be converted to int

//     ASSERT_STR((string) "0", (string) "", Integer::toUnsignedString(0, 1));
//     ASSERT_STR((string) "0", Integer::toUnsignedString(0, -1));
//     ASSERT_STR((string) "0", Integer::toUnsignedString(0, 13));
//     ASSERT_STR((string) "0", Integer::toUnsignedString(0, MAX_VALUE));
//     ASSERT_STR((string) "0", Integer::toUnsignedString(0, MIN_VALUE));

//     ASSERT_STR((string) "1", Integer::toUnsignedString(1, 0));// java.lang.ArithmeticException: / by zero
//     ASSERT_STR((string) "1", Integer::toUnsignedString(1, 1));
//     ASSERT_STR((string) "1", Integer::toUnsignedString(1, -1));
//     ASSERT_STR((string) "1", Integer::toUnsignedString(1, 13));
//     ASSERT_STR((string) "1", Integer::toUnsignedString(1, MAX_VALUE));
//     ASSERT_STR((string) "1", Integer::toUnsignedString(1, MIN_VALUE));

//     ASSERT_STR((string) "1", Integer::toUnsignedString(-1 , 0));// java.lang.ArithmeticException: / by zero
//     ASSERT_STR((string) "1", Integer::toUnsignedString(-1 , 1));
//     ASSERT_STR((string) "1", Integer::toUnsignedString(-1 , -1));
//     ASSERT_STR((string) "1", Integer::toUnsignedString(-1 , 13));
//     ASSERT_STR((string) "1", Integer::toUnsignedString(-1 , MAX_VALUE));
//     ASSERT_STR((string) "1", Integer::toUnsignedString(-1 , MIN_VALUE));

//     ASSERT_STR((string) "13", Integer::toUnsignedString(13 , 0));// java.lang.ArithmeticException: / by zero
//     ASSERT_STR((string) "13", Integer::toUnsignedString(13 , 1));
//     ASSERT_STR((string) "13", Integer::toUnsignedString(13 , -1));
//     ASSERT_STR((string) "10", Integer::toUnsignedString(13 , 13));
//     ASSERT_STR((string) "13", Integer::toUnsignedString(13 , MAX_VALUE));
//     ASSERT_STR((string) "13", Integer::toUnsignedString(13 , MIN_VALUE));

//     ASSERT_STR((string) "2147483647", Integer::toUnsignedString(MAX_VALUE , 0));// java.lang.ArithmeticException: / by zero
//     ASSERT_STR((string) "2147483647", Integer::toUnsignedString(MAX_VALUE , 1));
//     ASSERT_STR((string) "2147483647", Integer::toUnsignedString(MAX_VALUE , -1));
//     ASSERT_STR((string) "282ba4aaa", Integer::toUnsignedString(MAX_VALUE , 13));
//     ASSERT_STR((string) "2147483647", Integer::toUnsignedString(MAX_VALUE , MAX_VALUE));
//     ASSERT_STR((string) "2147483647", Integer::toUnsignedString(MAX_VALUE , MIN_VALUE));

//     ASSERT_STR((string) "2147483648", Integer::toUnsignedString(MIN_VALUE , 0));// java.lang.ArithmeticException: / by zero
//     ASSERT_STR((string) "2147483648", Integer::toUnsignedString(MIN_VALUE , 1));
//     ASSERT_STR((string) "2147483648", Integer::toUnsignedString(MIN_VALUE , -1));
//     ASSERT_STR((string) "282ba4aab", Integer::toUnsignedString(MIN_VALUE , 13));
//     ASSERT_STR((string) "2147483648", Integer::toUnsignedString(MIN_VALUE , MAX_VALUE));
//     ASSERT_STR((string) "2147483648", Integer::toUnsignedString(MIN_VALUE , MIN_VALUE));

//     System.out.println(Integer.toUnsignedString(Integer.MIN_VALUE,  0));
//     System.out.println(Integer.toUnsignedString(Integer.MIN_VALUE,  1));
//     System.out.println(Integer.toUnsignedString(Integer.MIN_VALUE,  -1));
//     System.out.println(Integer.toUnsignedString(Integer.MIN_VALUE,  13));
//     System.out.println(Integer.toUnsignedString(Integer.MIN_VALUE,  Integer.MAX_VALUE));
//     System.out.println(Integer.toUnsignedString(Integer.MIN_VALUE,  Integer.MIN_VALUE));

// }
// Test Integer::valueOf(String inputString)
// TEST(JavaLang, IntegerValueOf) {
    // ASSERT_EQUAL(0, Integer::valueOf((String) "0").intValue());
    // ASSERT_EQUAL(1, Integer::valueOf((String) "1").intValue());
    // ASSERT_EQUAL(-1, Integer::valueOf((String) "-1").intValue());
    // ASSERT_EQUAL(13, Integer::valueOf((String) "13").intValue());
    // ASSERT_EQUAL(2147483647, Integer::valueOf((String) "2147483647").intValue());
    // ASSERT_EQUAL(-2147483648, Integer::valueOf((String) "-2147483648").intValue());

    // System.out.println(Integer.valueOf("0"));
    // System.out.println(Integer.valueOf( "1"));
    // System.out.println(Integer.valueOf( "-1"));
    // System.out.println(Integer.valueOf( "13"));
    // System.out.println(Integer.valueOf( "2147483647"));
    // System.out.println(Integer.valueOf( "-2147483648"));
// }
// Test Integer::valueOf(int inputInt)
// TEST(JavaLang, IntegerValueOf2) {
//     ASSERT_EQUAL(0, Integer::valueOf(0));
//     ASSERT_EQUAL(1, Integer::valueOf(1));
//     ASSERT_EQUAL(-1, Integer::valueOf(-1));
//     ASSERT_EQUAL(13, Integer::valueOf(13));
//     ASSERT_EQUAL(2147483647, Integer::valueOf(2147483647));
//     ASSERT_EQUAL(-2147483648, Integer::valueOf(-2147483648));

//     System.out.println(Integer.valueOf("0"));
//     System.out.println(Integer.valueOf( "1"));
//     System.out.println(Integer.valueOf( "-1"));
//     System.out.println(Integer.valueOf( "13"));
//     System.out.println(Integer.valueOf( "2147483647"));
//     System.out.println(Integer.valueOf( "-2147483648"));

// }
// Test Integer::valueOf(String inputStringtringInput, int radixIntInput)
// TEST(JavaLang, IntegerValueOf3) {    
//     ASSERT_EQUAL(, Integer::valueOf((String) "0", 0)); // java.lang.NumberFormatException: radix 0 less than Character.MIN_RADIX
//     ASSERT_EQUAL(, Integer::valueOf((String) "0", 1)); // java.lang.NumberFormatException: radix 1 less than Character.MIN_RADIX 
//     ASSERT_EQUAL(, Integer::valueOf((String) "0", -1)); // java.lang.NumberFormatException: radix -1 less than Character.MIN_RADIX 
//     ASSERT_EQUAL(0, Integer::valueOf((String) "0", 13)); 
//     ASSERT_EQUAL(, Integer::valueOf((String) "0", MAX_VALUE)); // java.lang.NumberFormatException: radix 2147483647 greater than Character.MAX_RADIX
//     ASSERT_EQUAL(, Integer::valueOf((String) "0", MIN_VALUE)); // java.lang.NumberFormatException: radix -2147483648 less than Character.MIN_RADIX

//     ASSERT_EQUAL(1, Integer::valueOf((String) "1", 13));
//     ASSERT_EQUAL(-1, Integer::valueOf((String) "-1", 13));
//     ASSERT_EQUAL(16, Integer::valueOf((String) "13", 13));
//     ASSERT_EQUAL(, Integer::valueOf((String) "2147483647", 13)); // java.lang.NumberFormatException: For input string: "2147483647" 
//     ASSERT_EQUAL(, Integer::valueOf((String) "-2147483648", 13)); // java.lang.NumberFormatException: For input string: "-2147483648"    

//     System.out.println(Integer.valueOf("1", 13));
//     System.out.println(Integer.valueOf("-1", 13));
//     System.out.println(Integer.valueOf("13", 13));
//     System.out.println(Integer.valueOf("2147483647", 13));
//     System.out.println(Integer.valueOf("-2147483648", 13));

// }

// TEST(JavaLang, Integer) {


// }

// TEST(JavaLang, Integer) {


// }

// TEST(JavaLang, Integer) {


// }
// TODO(thoangminh): check out of range input for all method later.