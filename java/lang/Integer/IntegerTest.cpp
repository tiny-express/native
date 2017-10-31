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

#include "../../../kernel/Test.hpp"
#include "Integer.hpp"
#include "../NumberFormatException/NumberFormatException.hpp"
#include "../UnsupportedOperationException/UnsupportedOperationException.hpp"
#include "../ArithmeticException/ArithmeticException.hpp"

using namespace Java::Lang;

TEST (JavaLangInteger, Constructor) {
    // Test Integer::Integer()
    Integer integerConstructorNoneParameter;
    assertEquals(0, integerConstructorNoneParameter.intValue());
    assertEquals((string) "0", integerConstructorNoneParameter.toString());

    // Test Integer::Integer(String stringInput)
    Integer integerConstructorStringParameter((String) "13");
    assertEquals(13, integerConstructorStringParameter.intValue());
    assertEquals((string) "13", integerConstructorStringParameter.toString());

    // Test Integer::Integer(const Integer &integer)
    Integer integerConstructorIntegerParameter = 13;
    assertEquals(13, integerConstructorIntegerParameter.intValue());
    assertEquals((string) "13", integerConstructorIntegerParameter.toString());
}

TEST (JavaLangInteger, Comparision) {
    // Give a valid number and make a comparision
    Integer validNumberComparision = 2;
    Integer targetNumberComparision;

    // Test validNumber is equal targetNumber
    targetNumberComparision = 2;
    assertTrue(validNumberComparision == targetNumberComparision);

    // Test validNumber is not equal targetNumber
    targetNumberComparision = 101;
    assertTrue(validNumberComparision != targetNumberComparision);

    // Test validNumber is less than targetNumber
    targetNumberComparision = 3;
    assertTrue(validNumberComparision < targetNumberComparision);

    // Test validNumber is equal or less than targetNumber
    targetNumberComparision = 3;
    assertTrue(validNumberComparision <= targetNumberComparision);

    // Test validNumber is greater than targetNumber
    targetNumberComparision = 1;
    assertTrue(validNumberComparision > targetNumberComparision);

    // Test validNumber is equal or greater than targetNumber
    targetNumberComparision = 2;
    assertTrue(validNumberComparision >= targetNumberComparision);
}

TEST (JavaLangInteger, Operator) {
    // Create variable
    Integer validNumberOperator = 5;
    Integer targetNumberOperator = 3;
    Integer expectedResult;
    Integer actualResult;

    // Make a summation
    expectedResult = 8;
    actualResult = validNumberOperator + targetNumberOperator;
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    expectedResult = 13;
    actualResult += validNumberOperator;
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    // Make a subtraction
    expectedResult = 2;
    actualResult = validNumberOperator - targetNumberOperator;
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    expectedResult = -3;
    actualResult -= validNumberOperator;
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    // Make a multiplication
    expectedResult = 15;
    actualResult = validNumberOperator * targetNumberOperator;
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    expectedResult = 75;
    actualResult *= validNumberOperator;
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    // Make a division
    expectedResult = 1;
    actualResult = validNumberOperator / targetNumberOperator;
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    try {
        actualResult = validNumberOperator / 0;
    }
    catch (ArithmeticException &e) {
        assertEquals("Divide by zero", e.getMessage());
    }

    expectedResult = 1;
    actualResult = 5;
    actualResult /= targetNumberOperator;
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    try {
        actualResult /= 0;
    }
    catch (ArithmeticException &e) {
        assertEquals("Divide by zero", e.getMessage());
    }

    // Make a modulo
    expectedResult = 2;
    actualResult = validNumberOperator % targetNumberOperator;
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    try {
        actualResult = validNumberOperator % 0;
    }
    catch (ArithmeticException &e) {
        assertEquals("Divide by zero", e.getMessage());
    }

    expectedResult = 2;
    actualResult = 5;
    actualResult %= targetNumberOperator;
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    try {
        actualResult %= 0;
    }
    catch (ArithmeticException &e) {
        assertEquals("Divide by zero", e.getMessage());
    }
}

TEST (JavaLangInteger, CompareTo) {
    // Given valid Integer to compare with target
    Integer validValueCompareTo = 15;
    Integer lessThanValueCompareTo = 12;
    Integer equalValueCompareTo = 15;
    Integer greaterThanValueCompareTo = 20;

    // Return 1 if validValue is greater than lessThanValue
    assertEquals(1, validValueCompareTo.compareTo(lessThanValueCompareTo));

    // Return 0 if validValue is greater than equalValue
    assertEquals(0, validValueCompareTo.compareTo(equalValueCompareTo));

    // Return -1 if validValue is less than greater ThanValue
    assertEquals(-1, validValueCompareTo.compareTo(greaterThanValueCompareTo));

    // TODO - loint@foodtiny.com will review this case again
    Integer integerCompareTo = 1;
    Comparable<Integer> *comparable = &validValueCompareTo;
    assertEquals(1, comparable->compareTo(integerCompareTo));
}

TEST (JavaLangInteger, CharValue) {
    // Input different values of type long int to compare to the result of Integer::charValue
    Integer zeroIntegerCharValue = 0;
    Integer oneIntegerCharValue = 1;
    Integer positiveIntegerCharValue = 10;
    Integer maxIntegerCharValue = 2147483647;
    Integer minIntegerCharValue = -2147483647;

    // Make a comparison between expected result and the real result
    char expectedResultCharValue = '0';
    char realResultCharValue = zeroIntegerCharValue.charValue();
    assertEquals(expectedResultCharValue, realResultCharValue);

    // Make a comparison between expected result and the real result
    expectedResultCharValue = '1';
    realResultCharValue = oneIntegerCharValue.charValue();
    assertEquals(expectedResultCharValue, realResultCharValue);

    // Make a comparison between expected result and the real result
    expectedResultCharValue = '1';
    realResultCharValue = positiveIntegerCharValue.charValue();
    assertEquals(expectedResultCharValue, realResultCharValue);

    // Make a comparison between expected result and the real result
    expectedResultCharValue = '2';
    realResultCharValue = maxIntegerCharValue.charValue();
    assertEquals(expectedResultCharValue, realResultCharValue);

    // Make a comparison between expected result and the real result
    expectedResultCharValue = '-';
    realResultCharValue = minIntegerCharValue.charValue();
    assertEquals(expectedResultCharValue, realResultCharValue);
}

TEST (JavaLangInteger, StringValue) {
    // Create variable
    Integer zeroIntegerStringValue = 0;
    Integer oneIntegerStringValue = 1;
    Integer positiveIntegerStringValue = 10;
    Integer maxIntegerStringValue = 2147483647;
    Integer minIntegerStringValue = -2147483647;

    // Make a comparison between expected result and the real result
    string expectedResultStringValue = (string) "0";
    string realResultStringValue = zeroIntegerStringValue.stringValue();
    assertEquals(expectedResultStringValue, realResultStringValue);

    // Make a comparison between expected result and the real result
    expectedResultStringValue = (string) "1";
    realResultStringValue = oneIntegerStringValue.stringValue();
    assertEquals(expectedResultStringValue, realResultStringValue);

    // Make a comparison between expected result and the real result
    expectedResultStringValue = (string) "10";
    realResultStringValue = positiveIntegerStringValue.stringValue();
    assertEquals(expectedResultStringValue, realResultStringValue);

    // Make a comparison between expected result and the real result
    expectedResultStringValue = (string) "2147483647";
    realResultStringValue = maxIntegerStringValue.stringValue();
    assertEquals(expectedResultStringValue, realResultStringValue);

    // Make a comparison between expected result and the real result
    expectedResultStringValue = (string) "-2147483647";
    realResultStringValue = minIntegerStringValue.stringValue();
    assertEquals(expectedResultStringValue, realResultStringValue);
}

TEST (JavaLangInteger, ShortValue) {
    // Input different values of type long int to compare to the result of Integer::shortValue
    Integer positiveIntegerShortValue = 1302;
    Integer negativeIntegerShortValue = -1302;
    Integer notExpectedIntegerShortValue = 9999;

    // Make a comparison between expected result and the real result
    int expectedResultShortValue = 1302;
    int realResultShortValue = positiveIntegerShortValue.shortValue();
    assertEquals(expectedResultShortValue, realResultShortValue);

    // Make a comparison between expected result and the real result
    expectedResultShortValue = -1302;
    realResultShortValue = negativeIntegerShortValue.shortValue();
    assertEquals(expectedResultShortValue, realResultShortValue);

    // Make a comparison between expected result and the real result
    int notExpectedResultShortValue = -1111;
    realResultShortValue = notExpectedIntegerShortValue.shortValue();
    assertNotEquals(notExpectedResultShortValue, realResultShortValue);
}

TEST (JavaLangInteger, IntValue) {
    // Input different values of type long int to compare to the realResult of Integer::intValue
    Integer zeroIntegerIntValue = 0;
    Integer oneIntegerIntValue = 1;
    Integer positiveIntegerIntValue = 10;
    Integer maxIntegerIntValue = 2147483647;
    Integer minIntegerIntValue = -2147483647;
    Integer notExpectedIntegerIntValue = 1111;

    // Make a comparison between expected realResult and the real result
    long int expectedResultIntValue = 0;
    long int realResultIntValue = zeroIntegerIntValue.intValue();
    assertEquals(expectedResultIntValue, realResultIntValue);

    // Make a comparison between expected realResult and the real result
    expectedResultIntValue = 1;
    realResultIntValue = oneIntegerIntValue.intValue();
    assertEquals(expectedResultIntValue, realResultIntValue);

    // Make a comparison between expected realResult and the real result
    expectedResultIntValue = 10;
    realResultIntValue = positiveIntegerIntValue.intValue();
    assertEquals(expectedResultIntValue, realResultIntValue);

    // Make a comparison between expected realResult and the real result
    expectedResultIntValue = 2147483647;
    realResultIntValue = maxIntegerIntValue.intValue();
    assertEquals(expectedResultIntValue, realResultIntValue);

    // Make a comparison between expected realResult and the real result
    expectedResultIntValue = -2147483647;
    realResultIntValue = minIntegerIntValue.intValue();
    assertEquals(expectedResultIntValue, realResultIntValue);

    // Make a comparison between expected realResult and the real result
    long int notExpectedResult = 9999;
    realResultIntValue = minIntegerIntValue.intValue();
    assertNotEquals(notExpectedResult, realResultIntValue);
}

TEST (JavaLangInteger, LongValue) {
    // Input different values of type long int to compare to the realResult of Integer::longValue
    Integer positiveIntegerLongValue = 1302321013;
    Integer negativeIntegerLongValue = -1302321013;
    Integer notExpectedIntegerLongValue = -12345;

    // Make a comparison between expected realResult and the real result
    long long expectedResultLongValue = 1302321013;
    long long realResultLongValue = positiveIntegerLongValue.longValue();
    assertEquals(expectedResultLongValue, realResultLongValue);

    // Make a comparison between expected realResult and the real result
    expectedResultLongValue = -1302321013;
    realResultLongValue = negativeIntegerLongValue.longValue();
    assertEquals(expectedResultLongValue, realResultLongValue);

    // Make a comparison between the not expected realResult and the real result
    long long notExpectedResult = -11111;
    realResultLongValue = notExpectedIntegerLongValue.longValue();
    assertFalse(notExpectedResult == realResultLongValue);
}

TEST (JavaLangInteger, FloatValue) {
    // Input different values of type long int to compare to the realResult of Integer::floatValue
    Integer positiveIntegerFloatValue = 12345;
    float expectedResultFloatValue = 12345.00;
    float realResultFloatValue = positiveIntegerFloatValue.floatValue();
    assertTrue(expectedResultFloatValue == realResultFloatValue);


    Integer negativeInteger = -12345;
    expectedResultFloatValue = (float) -12345.0;
    realResultFloatValue = negativeInteger.floatValue();
    assertTrue(expectedResultFloatValue == realResultFloatValue);
}

TEST (JavaLangInteger, DoubleValue) {
    // Input different values of type long int to compare to the realResult of Integer::doubleValue
    Integer positiveIntegerDoubleValue = 123456789;
    double expectedResultDoubleValue = 123456789.0;
    double realResultDoubleValue = positiveIntegerDoubleValue.doubleValue();
    assertTrue(expectedResultDoubleValue == realResultDoubleValue);

    Integer negativeInteger = -123456789;
    expectedResultDoubleValue = -123456789.0;
    realResultDoubleValue = negativeInteger.doubleValue();
    assertTrue(expectedResultDoubleValue == realResultDoubleValue);
}

TEST (JavaLangInteger, BitCount) {
    long int inputInt;
    long int expectedResult;
    long int actualResult;

    inputInt = 0;
    expectedResult = 0;
    actualResult = Integer::bitCount(inputInt);
    assertEquals(expectedResult, actualResult);

    inputInt = 1;  // 01
    expectedResult = 1;
    actualResult = Integer::bitCount(inputInt);
    assertEquals(expectedResult, actualResult);

    inputInt = -1;  // 11
    expectedResult = 32;
    actualResult = Integer::bitCount(inputInt);
    assertEquals(expectedResult, actualResult);

    inputInt = 13;  // 0000 1101
    expectedResult = 3;
    actualResult = Integer::bitCount(inputInt);
    assertEquals(expectedResult, actualResult);

    inputInt = Integer::MAX_VALUE;  // 2, 147, 483, 647(10) = 0111 1111 1111 1111 1111 1111 1111 1111 (2)
    expectedResult = 31;
    actualResult = Integer::bitCount(inputInt);
    assertEquals(expectedResult, actualResult);

    inputInt = Integer::MIN_VALUE; // -2, 147, 483, 648(10) = 1000 0000 0000 0000 0000 0000 0000 0000
    expectedResult = 1;
    actualResult = Integer::bitCount(inputInt);
    assertEquals(expectedResult, actualResult);
}

TEST (JavaLangInteger, ByteValue) {
    Integer integerInput;

    integerInput = 0;
    assertEquals((byte) 0, integerInput.byteValue());

    integerInput = 1;
    assertEquals((byte) 1, integerInput.byteValue());

    integerInput = -1;
    assertEquals((byte) -1, integerInput.byteValue());

    integerInput = 13;
    assertEquals((byte) 13, integerInput.byteValue());

    integerInput = Integer::MAX_VALUE;
    assertEquals((byte) -1, integerInput.byteValue());

    integerInput = Integer::MIN_VALUE;
    assertEquals((byte) 0, integerInput.byteValue());
}

TEST (JavaLangInteger, Compare) {
    // Given 2 int
    long int greater = 10;
    long int smaller = 5;

    // Compare 2 equal value;
    assertEquals(0, Integer::compare(greater, greater));

    // Compare different value
    assertEquals(-1, Integer::compare(smaller, greater));
    assertEquals(1, Integer::compare(greater, smaller));
}

TEST (JavaLangInteger, CompareUnsigned) {
    // Given 3 int
    long int greater = 10;
    long int smaller = 5;
    long int negative = -10;

    // Compare 2 equal value;
    assertEquals(0, Integer::compareUnsigned(greater, greater));
    assertEquals(0, Integer::compareUnsigned(negative, negative));

    // Compare different value
    assertEquals(-1, Integer::compareUnsigned(smaller, greater));
    assertEquals(1, Integer::compareUnsigned(greater, smaller));

    // Compare negative value
    assertEquals(-1, Integer::compareUnsigned(greater, negative));
    assertEquals(1, Integer::compareUnsigned(negative, greater));
}

TEST (JavaLangInteger, Decode) {
    String stringInput;
    Integer expectedResult;
    Integer actualResult;
    Integer exceptionResult;

    stringInput = "";
    try {
        exceptionResult = Integer::decode(stringInput);
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage());
    }

    // Cast all case of input a string of type decimal number
    stringInput = "0";
    expectedResult = 0;
    actualResult = Integer::decode(stringInput);
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    stringInput = (String) "1";
    expectedResult = 1;
    actualResult = Integer::decode(stringInput);
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    stringInput = (String) "-1";
    expectedResult = -1;
    actualResult = Integer::decode(stringInput);
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    stringInput = (String) "13";
    expectedResult = 13;
    actualResult = Integer::decode(stringInput);
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    // Test out of range
    stringInput = (String) "2147483650";
    try {
        exceptionResult = Integer::decode(stringInput);
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage());
    }

    stringInput = (String) "-2147483650";
    try {
        exceptionResult = Integer::decode(stringInput);
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage());
    }


    stringInput = (String) "Not a Number";
    try {
        exceptionResult = Integer::decode(stringInput);
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage());
    }

    // Cast all case of input a string of type octal
    stringInput = "0";
    expectedResult = 0;
    actualResult = Integer::decode(stringInput);
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    stringInput = (String) "01";
    expectedResult = 1;
    actualResult = Integer::decode(stringInput);
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    stringInput = (String) "-01";
    expectedResult = -1;
    actualResult = Integer::decode(stringInput);
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    stringInput = (String) "015";
    expectedResult = 13;
    actualResult = Integer::decode(stringInput);
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    // Test out of range
    stringInput = (String) "020000000002";
    try {
        exceptionResult = Integer::decode(stringInput);
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage());
    }

    stringInput = (String) "-020000000002";
    try {
        exceptionResult = Integer::decode(stringInput);
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage());
    }

    // Cast all case of input a string of type hexadecimal number
    stringInput = "0x0";
    expectedResult = 0;
    actualResult = Integer::decode(stringInput);
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    stringInput = (String) "0x1";
    expectedResult = 1;
    actualResult = Integer::decode(stringInput);
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    stringInput = (String) "-0x1";
    expectedResult = -1;
    actualResult = Integer::decode(stringInput);
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    stringInput = (String) "0X1";
    expectedResult = 1;
    actualResult = Integer::decode(stringInput);
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    stringInput = (String) "-0X1";
    expectedResult = -1;
    actualResult = Integer::decode(stringInput);
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    stringInput = (String) "0xD";
    expectedResult = 13;
    actualResult = Integer::decode(stringInput);
    assertEquals(expectedResult.intValue(), actualResult.intValue());

    // Test out of range
    stringInput = (String) "0x80000002";
    try {
        exceptionResult = Integer::decode(stringInput);
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage());
    }

    stringInput = (String) "-0x80000002";
    try {
        exceptionResult = Integer::decode(stringInput);
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage());
    }
}

TEST (JavaLangInteger, DivideUnsigned) {
    // Given 4 int
    long int positiveDividend = 10;
    long int positiveDivisor = 5;
    long int negativeDividend = -10;
    long int negativeDivisor = -5;

    // Divide by zero
    try {
        long int exceptionResult = Integer::divideUnsigned(positiveDividend, 0);
    }
    catch (ArithmeticException &e) {
        assertEquals("Divide by zero", e.getMessage());
    }

    // Positive divide
    assertEquals(0, Integer::divideUnsigned(0, positiveDivisor));
    assertEquals(2, Integer::divideUnsigned(positiveDividend, positiveDivisor));
    assertEquals(0, Integer::divideUnsigned(positiveDivisor, positiveDividend));

    // Negative divide
    assertEquals(0, Integer::divideUnsigned(0, negativeDivisor));
    assertEquals(0, Integer::divideUnsigned(negativeDividend, negativeDivisor));
    assertEquals(1, Integer::divideUnsigned(negativeDivisor, negativeDividend));

    // Mix divide
    assertEquals(0, Integer::divideUnsigned(0, positiveDivisor));
    assertEquals(858993457, Integer::divideUnsigned(negativeDividend, positiveDivisor));
    assertEquals(429496729, Integer::divideUnsigned(negativeDivisor, positiveDividend));
}

TEST (JavaLangInteger, Equals) {
    Integer thisInteger;

    thisInteger = 13;
    assertFalse(thisInteger.equals(0));
    assertFalse(thisInteger.equals(1));
    assertFalse(thisInteger.equals(-1));
    assertTrue(thisInteger.equals(13));
}

// Test Integer::getInteger(String inputString)
// TEST(JavaLangInteger, GetIntegerWithString) {
// String stringInput;
// Integer expectedResult;
// Integer actualResult;

// // Cast all case of input a string of type decimal number
// stringInput = (String) "";
// expectedResult = ; // NULL string
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "0";
// expectedResult = 0;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "1";
// expectedResult = 1;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "-1";
// expectedResult = -1;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "13";
// expectedResult = 13;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "2147483647"; // Integer::MAX_VALUE
// expectedResult = Integer::MAX_VALUE;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "-2147483648"; // Integer::MIN_VALUE
// expectedResult = Integer::MIN_VALUE;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "Not a Number";
// expectedResult = ;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());


// // Cast all case of input a string of type octal numberStringInput = (String) "0";
// stringInput = (String) "00";
// expectedResult = 0;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "01";
// expectedResult = 1;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "00001101";
// expectedResult = 13;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "01111111111111111111111111111111"; // Integer::MAX_VALUE
// expectedResult = 2147483647;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "0111111111111111111111111111111111111111111";
// expectedResult = ; // out of range
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "011111111111111111111111111111111112222222";
// expectedResult = ; // wrong type
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// // Cast all case of input a string of type hexadecimal number
// stringInput = (String) "0x00";
// expectedResult = 0;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#1";
// expectedResult = 1;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#FFFFFFFFFFFFFFFF";
// expectedResult = -1;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "0xD";
// expectedResult = 13;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "0x7FFFFFFF"; // Integer::MAX_VALUE
// expectedResult = 2147483647;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#FFFFFFFF80000000"; // Integer::MIN_VALUE
// expectedResult = -2147483647;
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#Not a Number";
// expectedResult = ; // Not a number
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#213546546";
// expectedResult = ; // Wrong type
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#1111FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
// expectedResult = ; // Out of range
// actualResult = Integer:getInteger(stringInput);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// }

// Test Integer::getInteger(String inputString, long int inputInt)
// TEST(JavaLangInteger, GetIntegerWithStringAndInt) {
// String stringInput;
// Integer expectedResult;
// Integer actualResult;

// // Cast all case of input a string of type decimal number
// stringInput = (String) "";
// expectedResult = 9999; // NULL string
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "0";
// expectedResult = 0;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "1";
// expectedResult = 1;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "-1";
// expectedResult = -1;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "13";
// expectedResult = 13;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "2147483647"; // Integer::MAX_VALUE
// expectedResult = Integer::MAX_VALUE;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "-2147483648"; // Integer::MIN_VALUE
// expectedResult = Integer::MIN_VALUE;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "Not a Number";
// expectedResult = ;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());


// // Cast all case of input a string of type octal numberStringInput = (String) "0";
// stringInput = (String) "00";
// expectedResult = 0;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "01";
// expectedResult = 1;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "00001101";
// expectedResult = 13;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "01111111111111111111111111111111"; // Integer::MAX_VALUE
// expectedResult = 2147483647;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "0111111111111111111111111111111111111111111";
// expectedResult = ; // out of range
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "011111111111111111111111111111111112222222";
// expectedResult = ; // wrong type
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// // Cast all case of input a string of type hexadecimal number
// stringInput = (String) "0x00";
// expectedResult = 0;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#1";
// expectedResult = 1;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#FFFFFFFFFFFFFFFF";
// expectedResult = -1;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "0xD";
// expectedResult = 13;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "0x7FFFFFFF"; // Integer::MAX_VALUE
// expectedResult = 2147483647;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#FFFFFFFF80000000"; // Integer::MIN_VALUE
// expectedResult = -2147483647;
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#Not a Number";
// expectedResult = ; // Not a number
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#213546546";
// expectedResult = ; // Wrong type
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#1111FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
// expectedResult = ; // Out of range
// actualResult = Integer:getInteger(stringInput, 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// }

// Test Integer::getInteger(String inputString, Integer inputInteger)
// TEST(JavaLangInteger, GetIntegerWithStringAndInteger) {
// String stringInput;
// Integer expectedResult;
// Integer actualResult;

// // Cast all case of input a string of type decimal number
// stringInput = (String) "";
// expectedResult = 9999; // NULL string
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "0";
// expectedResult = 0;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "1";
// expectedResult = 1;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "-1";
// expectedResult = -1;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "13";
// expectedResult = 13;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "2147483647"; // Integer::MAX_VALUE
// expectedResult = Integer::MAX_VALUE;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "-2147483648"; // Integer::MIN_VALUE
// expectedResult = Integer::MIN_VALUE;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "Not a Number";
// expectedResult = ;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());


// // Cast all case of input a string of type octal numberStringInput = (String) "0";
// stringInput = (String) "00";
// expectedResult = 0;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "01";
// expectedResult = 1;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "00001101";
// expectedResult = 13;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "01111111111111111111111111111111"; // Integer::MAX_VALUE
// expectedResult = 2147483647;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "0111111111111111111111111111111111111111111";
// expectedResult = ; // out of range
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "011111111111111111111111111111111112222222";
// expectedResult = ; // wrong type
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// // Cast all case of input a string of type hexadecimal number
// stringInput = (String) "0x00";
// expectedResult = 0;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#1";
// expectedResult = 1;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#FFFFFFFFFFFFFFFF";
// expectedResult = -1;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "0xD";
// expectedResult = 13;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "0x7FFFFFFF"; // Integer::MAX_VALUE
// expectedResult = 2147483647;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#FFFFFFFF80000000"; // Integer::MIN_VALUE
// expectedResult = -2147483647;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#Not a Number";
// expectedResult = ; // Not a number
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#213546546";
// expectedResult = ; // Wrong type
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#1111FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
// expectedResult = ; // Out of range
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// assertEquals(expectedResult.intValue(), actualResult.intValue());

// }

TEST (JavaLangInteger, StaticHashCode) {
    assertEquals(0, Integer::hashCode(0));
    assertEquals(1, Integer::hashCode(1));
    assertEquals(-1, Integer::hashCode(-1));
    assertEquals(13, Integer::hashCode(13));
}

TEST (JavaLangInteger, HashCode) {
    {
        Integer integer = Integer(0);
        assertEquals(0, integer.hashCode());
    }

    {
        Integer integer = Integer(1);
        assertEquals(1, integer.hashCode());
    }

    {
        Integer integer = Integer(-1);
        assertEquals(-1, integer.hashCode());
    }

    {
        Integer integer = Integer(13);
        assertEquals(13, integer.hashCode());
    }
}

TEST (JavaLangInteger, HighestOneBit) {
    assertEquals(0, Integer::highestOneBit(0));
    assertEquals(1, Integer::highestOneBit(1));
    assertEquals(-2147483648, Integer::highestOneBit(-1));
    assertEquals(8, Integer::highestOneBit(13));
    assertEquals(1073741824, Integer::highestOneBit(Integer::MAX_VALUE));
    assertEquals(-2147483648, Integer::highestOneBit(Integer::MIN_VALUE));
}

TEST (JavaLangInteger, LowestOneBit) {
    assertEquals(0, Integer::lowestOneBit(0));
    assertEquals(1, Integer::lowestOneBit(1));
    assertEquals(1, Integer::lowestOneBit(-1));
    assertEquals(1, Integer::lowestOneBit(13));
    assertEquals(1, Integer::lowestOneBit(Integer::MAX_VALUE));
    assertEquals(-2147483648, Integer::lowestOneBit(Integer::MIN_VALUE));
}

TEST (JavaLangInteger, Max) {
    assertEquals(0, Integer::max(0, 0));
    assertEquals(1, Integer::max(0, 1));
    assertEquals(0, Integer::max(0, -1));
    assertEquals(13, Integer::max(0, 13));
}

TEST (JavaLangInteger, Min) {
    assertEquals(0, Integer::min(0, 0));
    assertEquals(0, Integer::min(0, 1));
    assertEquals(-1, Integer::min(0, -1));
}

TEST (JavaLangInteger, NumberOfLeadingZeros) {
    assertEquals(32, Integer::numberOfLeadingZeros(0));
    assertEquals(31, Integer::numberOfLeadingZeros(1));
    assertEquals(0, Integer::numberOfLeadingZeros(-1));
    assertEquals(28, Integer::numberOfLeadingZeros(13));
    assertEquals(1, Integer::numberOfLeadingZeros(Integer::MAX_VALUE));
    assertEquals(0, Integer::numberOfLeadingZeros(Integer::MIN_VALUE));
}

TEST (JavaLangInteger, NumberOfTrailingZeros) {
    assertEquals(32, Integer::numberOfTrailingZeros(0));
    assertEquals(0, Integer::numberOfTrailingZeros(1));
    assertEquals(0, Integer::numberOfTrailingZeros(-1));
    assertEquals(0, Integer::numberOfTrailingZeros(-113));
    assertEquals(1, Integer::numberOfTrailingZeros(1314));
    assertEquals(31, Integer::numberOfTrailingZeros(Integer::MIN_VALUE));
}


TEST (JavaLangInteger, ParseIntWithRadix) {
    assertEquals(Integer::parseInt((String) "0", 10), 0);
    assertEquals(Integer::parseInt((String) "473", 10), 473);
    assertEquals(Integer::parseInt((String) "+42", 10), 42);
    assertEquals(Integer::parseInt((String) "-0", 10), 0);
    assertEquals(Integer::parseInt((String) "-FF", 16), -255);
    assertEquals(Integer::parseInt((String) "1100110", 2), 102);
    assertEquals(Integer::parseInt((String) "2147483647", 10), 2147483647);
    assertEquals(Integer::parseInt((String) "-2147483648", 10), -2147483648);
    Integer exceptionResult;
    try {
        exceptionResult = Integer::parseInt((String) "2147483648", 10);
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage());
    }

    try {
        exceptionResult = Integer::parseInt((String) "99999999999999999999", 10);
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage());
    }

    try {
        exceptionResult = Integer::parseInt((String) "99", 8);
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage());
    }

    try {
        exceptionResult = Integer::parseInt((String) "Kona", 10);
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage());
    }

    assertEquals(Integer::parseInt((String) "Kona", 27), 411787);

    try {
        exceptionResult = Integer::parseInt((String) "Kona", 33);
    }
    catch (NumberFormatException &e) {
        assertEquals("radix out of range", e.getMessage());
    }

    try {
        exceptionResult = Integer::parseInt((String) "Kona", 1);
    }
    catch (NumberFormatException &e) {
        assertEquals("radix out of range", e.getMessage());
    }

    try {
        exceptionResult = Integer::parseInt((String) "", 2);
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage());
    }
}

TEST (JavaLangInteger, ParseInt) {
    String stringInput;
    long int expectedResult;
    long int actualResult;
    long int exceptionResult;

    stringInput = "";
    try {
        exceptionResult = Integer::parseInt(stringInput);
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage());
    }

    // Cast all case of input a string of type decimal number
    stringInput = (String) "0";
    expectedResult = 0;
    actualResult = Integer::parseInt(stringInput);
    assertEquals(expectedResult, actualResult);

    stringInput = (String) "1";
    expectedResult = 1;
    actualResult = Integer::parseInt(stringInput);
    assertEquals(expectedResult, actualResult);

    stringInput = (String) "-1";
    expectedResult = -1;
    actualResult = Integer::parseInt(stringInput);
    assertEquals(expectedResult, actualResult);

    stringInput = (String) "13";
    expectedResult = 13;
    actualResult = Integer::parseInt(stringInput);
    assertEquals(expectedResult, actualResult);

    stringInput = (String) "Not a Number";
    try {
        exceptionResult = Integer::parseInt(stringInput);
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage());
    }

    // Test out of range
    stringInput = (String) "2147483650";
    try {
        exceptionResult = Integer::parseInt(stringInput);
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage());
    }

    stringInput = (String) "-21474834650";
    try {
        exceptionResult = Integer::parseInt(stringInput);
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage());
    }
}

TEST (JavaLangInteger, ParseUnsignedIntWithRadix) {
    Integer exceptionResult;

    assertEquals(Integer::parseUnsignedInt((String) "0", 10), 0);
    assertEquals(Integer::parseUnsignedInt((String) "473", 10), 473);
    assertEquals(Integer::parseUnsignedInt((String) "+42", 10), 42);
    try {
        exceptionResult = Integer::parseUnsignedInt((String) "-0", 10);
    }
    catch (NumberFormatException &e) {
        assertEquals("Illegal leading minus sign", e.getMessage());
    }

    try {
        exceptionResult = Integer::parseUnsignedInt((String) "-FF", 16);
    }
    catch (NumberFormatException &e) {
        assertEquals("Illegal leading minus sign", e.getMessage());
    }

    assertEquals(Integer::parseUnsignedInt((String) "1100110", 2), 102);
    assertEquals(Integer::parseUnsignedInt((String) "2147483647", 10), 2147483647);

    try {
        exceptionResult = Integer::parseUnsignedInt((String) "-2147483648", 10);
    }
    catch (NumberFormatException &e) {
        assertEquals("Illegal leading minus sign", e.getMessage());
    }

    try {
        exceptionResult = Integer::parseUnsignedInt((String) "99", 8);
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage());
    }

    try {
        exceptionResult = Integer::parseUnsignedInt((String) "Kona", 10);
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage());
    }

    assertEquals(Integer::parseUnsignedInt((String) "Kona", 27), 411787);

    try {
        exceptionResult = Integer::parseUnsignedInt((String) "Kona", 33);
    }
    catch (NumberFormatException &e) {
        assertEquals("radix out of range", e.getMessage());
    }

    try {
        exceptionResult = Integer::parseUnsignedInt((String) "Kona", 1);
    }
    catch (NumberFormatException &e) {
        assertEquals("radix out of range", e.getMessage());
    }

    try {
        exceptionResult = Integer::parseUnsignedInt((String) "", 2);
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage());
    }

    // Test out of range
    try {
        exceptionResult = Integer::parseUnsignedInt((String) "4294967297", 10);
    }
    catch (NumberFormatException &e) {
        assertEquals("Unsigned integer out of range", e.getMessage());
    }

    try {
        exceptionResult = Integer::parseUnsignedInt((String) "12345678901234567890123456789", 10);
    }
    catch (NumberFormatException &e) {
        assertEquals("Unsigned integer out of range", e.getMessage());
    }
}

TEST (JavaLangInteger, ParseUnsignedInt) {
    String stringInput;
    long int expectedResult;
    long int actualResult;
    long int exceptionResult;

    // Cast all case of inputString a string of type decimal number
    stringInput = (String) "0";
    expectedResult = 0;
    actualResult = Integer::parseUnsignedInt(stringInput);
    assertEquals(expectedResult, actualResult);

    stringInput = (String) "1";
    expectedResult = 1;
    actualResult = Integer::parseUnsignedInt(stringInput);
    assertEquals(expectedResult, actualResult);

    stringInput = (String) "-1";
    try {
        exceptionResult = Integer::parseUnsignedInt(stringInput);
    }
    catch (NumberFormatException &e) {
        assertEquals("Illegal leading minus sign", e.getMessage());
    }

    stringInput = (String) "13";
    expectedResult = 13;
    actualResult = Integer::parseUnsignedInt(stringInput);
    assertEquals(expectedResult, actualResult);

    stringInput = (String) "Not a Number";
    try {
        exceptionResult = Integer::parseUnsignedInt(stringInput);
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage());
    }

    // Test out of range
    stringInput = (String) "4294967297";
    try {
        exceptionResult = Integer::parseUnsignedInt(stringInput);
    }
    catch (NumberFormatException &e) {
        assertEquals("Unsigned integer out of range", e.getMessage());
    }

    stringInput = (String) "12345678901234567890123456789";
    try {
        exceptionResult = Integer::parseUnsignedInt(stringInput);
    }
    catch (NumberFormatException &e) {
        assertEquals("Unsigned integer out of range", e.getMessage());
    }
}

TEST (JavaLangInteger, RemainderUnsigned) {
    // Given 4 int
    long int positiveDividend = 10;
    long int positiveDivisor = 4;
    long int negativeDividend = -10;
    long int negativeDivisor = -4;

    // Divide by zero
    try {
        long int exceptionResult = Integer::remainderUnsigned(positiveDividend, 0);
    }
    catch (ArithmeticException &e) {
        assertEquals("Divide by zero", e.getMessage());
    }

    // Positive divide
    assertEquals(0, Integer::remainderUnsigned(0, positiveDivisor));
    assertEquals(2, Integer::remainderUnsigned(positiveDividend, positiveDivisor));
    assertEquals(4, Integer::remainderUnsigned(positiveDivisor, positiveDividend));

    // Negative divide
    assertEquals(0, Integer::remainderUnsigned(0, negativeDivisor));
    assertEquals(-10, Integer::remainderUnsigned(negativeDividend, negativeDivisor));
    assertEquals(6, Integer::remainderUnsigned(negativeDivisor, negativeDividend));

    // Mix divide
    assertEquals(0, Integer::remainderUnsigned(0, positiveDivisor));
    assertEquals(2, Integer::remainderUnsigned(negativeDividend, positiveDivisor));
    assertEquals(2, Integer::remainderUnsigned(negativeDivisor, positiveDividend));
}

TEST (JavaLangInteger, Reverse) {
    assertEquals(0, Integer::reverse(0));
    assertEquals(-2147483648, Integer::reverse(1));
    assertEquals(-1, Integer::reverse(-1));
    assertEquals(-1342177280, Integer::reverse(13));
    assertEquals(-2, Integer::reverse(Integer::MAX_VALUE));
    assertEquals(1, Integer::reverse(Integer::MIN_VALUE));
}

TEST (JavaLangInteger, ReverseBytes) {
    assertEquals(0, Integer::reverseBytes(0));
    assertEquals(16777216, Integer::reverseBytes(1));
    assertEquals(-1, Integer::reverseBytes(-1));
    assertEquals(218103808, Integer::reverseBytes(13));
    assertEquals(-129, Integer::reverseBytes(Integer::MAX_VALUE));
    assertEquals(128, Integer::reverseBytes(Integer::MIN_VALUE));
}

TEST (JavaLangInteger, RotateLeft) {
    assertEquals(-2147483648, Integer::rotateLeft(1, -1));
    assertEquals(8192, Integer::rotateLeft(1, 13));
    assertEquals(1, Integer::rotateLeft(1, Integer::MIN_VALUE));
}

TEST (JavaLangInteger, RotateRight) {
    assertEquals(1, Integer::rotateRight(1, 0));
    assertEquals(-2147483648, Integer::rotateRight(1, 1));
    assertEquals(2, Integer::rotateRight(1, -1));
    assertEquals(524288, Integer::rotateRight(1, 13));
    assertEquals(2, Integer::rotateRight(1, Integer::MAX_VALUE));
    assertEquals(1, Integer::rotateRight(1, Integer::MIN_VALUE));
}

TEST (JavaLangInteger, Signum) {
    assertEquals(0, Integer::signum(0));
    assertEquals(1, Integer::signum(1));
    assertEquals(-1, Integer::signum(-1));
}

TEST (JavaLangInteger, Sum) {
    assertEquals(13, Integer::sum(13, 0));
    assertEquals(12, Integer::sum(13, -1));
    assertEquals(26, Integer::sum(13, 13));
    assertEquals(-2147483636, Integer::sum(13, Integer::MAX_VALUE));
}

TEST (JavaLangInteger, ToBinaryString) {
    assertEquals((string) "0", Integer::toBinaryString(0).toString());
    assertEquals((string) "1", Integer::toBinaryString(1).toString());
    assertEquals((string) "11111111111111111111111111111111", Integer::toBinaryString(-1).toString());
    assertEquals((string) "1101", Integer::toBinaryString(13).toString());
    assertEquals((string) "1111111111111111111111111111111", Integer::toBinaryString(Integer::MAX_VALUE).toString());
    assertEquals((string) "10000000000000000000000000000000", Integer::toBinaryString(Integer::MIN_VALUE).toString());
}

TEST (JavaLangInteger, ToHexString) {
    assertEquals((string) "0", Integer::toHexString(0).toString());
    assertEquals((string) "1", Integer::toHexString(1).toString());
    assertEquals((string) "ffffffff", Integer::toHexString(-1).toString());
    assertEquals((string) "d", Integer::toHexString(13).toString());
    assertEquals((string) "7fffffff", Integer::toHexString(Integer::MAX_VALUE).toString());
    assertEquals((string) "80000000", Integer::toHexString(Integer::MIN_VALUE).toString());
}

TEST (JavaLangInteger, ToOctalString) {
    assertEquals((string) "0", Integer::toOctalString(0).toString());
    assertEquals((string) "1", Integer::toOctalString(1).toString());
    assertEquals((string) "37777777777", Integer::toOctalString(-1).toString());
    assertEquals((string) "15", Integer::toOctalString(13).toString());
    assertEquals((string) "17777777777", Integer::toOctalString(Integer::MAX_VALUE).toString());
    assertEquals((string) "20000000000", Integer::toOctalString(Integer::MIN_VALUE).toString());
}

TEST (JavaLangInteger, ToString) {
    // Input different values of type long int to compare to the realResult of Integer::toString
    Integer zeroIntegerToString = 0;
    Integer oneIntegerToString = 1;
    Integer positiveIntegerToString = 10;
    Integer maxIntegerToString = 2147483647;
    Integer minIntegerToString = -2147483647;

    // Make a comparison between expected realResult and the real result
    auto expectedResultToString = (string) "0";
    assertEquals(expectedResultToString, zeroIntegerToString.toString());

    // Make a comparison between expected realResult and the real result
    expectedResultToString = (string) "1";
    assertEquals(expectedResultToString, oneIntegerToString.toString());

    // Make a comparison between expected realResult and the real result
    expectedResultToString = (string) "10";
    assertEquals(expectedResultToString, positiveIntegerToString.toString());

    // Make a comparison between expected realResult and the real result
    expectedResultToString = (string) "2147483647";
    assertEquals(expectedResultToString, maxIntegerToString.toString());

    // Make a comparison between expected realResult and the real result
    expectedResultToString = (string) "-2147483647";
    assertEquals(expectedResultToString, minIntegerToString.toString());
}

TEST (JavaLangInteger, ToStringFromInt) {
    assertEquals((string) "0", Integer::toString(0).toString());
    assertEquals((string) "1", Integer::toString(1).toString());
    assertEquals((string) "-1", Integer::toString(-1).toString());
    assertEquals((string) "13", Integer::toString(13).toString());
}

TEST (JavaLangInteger, ToStringWithRadix) {
    assertEquals("0", Integer::toString(0, 10).toString());
    assertEquals("473", Integer::toString(473, 10).toString());
    assertEquals("-ff", Integer::toString(-255, 16).toString());
    assertEquals("-1100110", Integer::toString(-102, 2).toString());
    assertEquals("106", Integer::toString(70, 8).toString());

    // Radix out of range
    assertEquals("473", Integer::toString(473, 100).toString());
    try {
        String exceptionString = Integer::toString(100, 20);
    }
    catch (UnsupportedOperationException &e) {
        assertEquals("Haven't support this radix yet", e.getMessage());
    }
}

TEST (JavaLangInteger, ToUnsignedLong) {
    assertEquals(0, Integer::toUnsignedLong(0));
    assertEquals(1, Integer::toUnsignedLong(1));
    assertEquals(4294967295, Integer::toUnsignedLong(-1));
    assertEquals(13, Integer::toUnsignedLong(13));
    assertEquals(2147483647, Integer::toUnsignedLong(Integer::MAX_VALUE));
    assertEquals(2147483648, Integer::toUnsignedLong(Integer::MIN_VALUE));
}

TEST (JavaLangInteger, ToUnsignedString) {
    assertEquals("0", Integer::toUnsignedString(0, 10).toString());
    assertEquals("473", Integer::toUnsignedString(473, 10).toString());
    assertEquals("ffffff01", Integer::toUnsignedString(-255, 16).toString());
    assertEquals("1100110", Integer::toUnsignedString(102, 2).toString());
    assertEquals("106", Integer::toUnsignedString(70, 8).toString());

    // Radix out of range
    assertEquals("473", Integer::toUnsignedString(473, 100).toString());

    // Radix is not 2, 8, 16, 10
    try {
        String exceptionString = Integer::toUnsignedString(100, 20);
    }
    catch (UnsupportedOperationException &e) {
        assertEquals("Haven't support this radix yet", e.getMessage());
    }
}

TEST (JavaLangInteger, ToUnsignedDecimalString) {
    assertEquals("0", Integer::toUnsignedString(0).toString());
    assertEquals("473", Integer::toUnsignedString(473).toString());
    assertEquals("4294967041", Integer::toUnsignedString(-255).toString());
}

TEST (JavaLangInteger, ValueOfFromString) {
    assertEquals(0, Integer::valueOf((String) "0").intValue());
    assertEquals(1, Integer::valueOf((String) "1").intValue());
    assertEquals(13, Integer::valueOf((String) "13").intValue());

    Integer exceptionResult;
    try {
        exceptionResult = Integer::parseInt((String) "", 2);
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage());
    }

    try {
        exceptionResult = Integer::valueOf((String) "-FF");
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage());
    }

    // Test out of range
    try {
        exceptionResult = Integer::valueOf((String) "21474836450");
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage());
    }

    try {
        exceptionResult = Integer::valueOf((String) "-21474836458");
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage());
    }
}

TEST (JavaLangInteger, ValueOfFromInt) {
    assertEquals(0, Integer::valueOf(0).intValue());
    assertEquals(1, Integer::valueOf(1).intValue());
    assertEquals(-1, Integer::valueOf(-1).intValue());
    assertEquals(13, Integer::valueOf(13).intValue());
    assertEquals(2147483647, Integer::valueOf(2147483647).intValue());
    assertEquals(-2147483648, Integer::valueOf(-2147483648).intValue());
}

TEST (JavaLangInteger, ValueOfWithRadix) {
    assertEquals(0, Integer::valueOf((String) "0", 10).intValue());
    assertEquals(473, Integer::valueOf((String) "473", 10).intValue());
    assertEquals(42, Integer::valueOf((String) "+42", 10).intValue());
    assertEquals(0, Integer::valueOf((String) "-0", 10).intValue());
    assertEquals(-255, Integer::valueOf((String) "-FF", 16).intValue());
    assertEquals(102, Integer::valueOf((String) "1100110", 2).intValue());
    assertEquals(2147483647, Integer::valueOf((String) "2147483647", 10).intValue());
    assertEquals(-2147483648, Integer::valueOf((String) "-2147483648", 10).intValue());
    Integer exceptionResult;
    try {
        exceptionResult = Integer::valueOf((String) "2147483648", 10);
    }
    catch (NumberFormatException &e) {
        assertEquals("Integer out of range", e.getMessage());
    }

    try {
        exceptionResult = Integer::valueOf((String) "99", 8);
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage());
    }

    try {
        exceptionResult = Integer::valueOf((String) "Kona", 10);
    }
    catch (NumberFormatException &e) {
        assertEquals("Not a number", e.getMessage());
    }

    assertEquals(411787, Integer::valueOf((String) "Kona", 27).intValue());

    try {
        exceptionResult = Integer::valueOf((String) "Kona", 33);
    }
    catch (NumberFormatException &e) {
        assertEquals("radix out of range", e.getMessage());
    }

    try {
        exceptionResult = Integer::valueOf((String) "Kona", 1);
    }
    catch (NumberFormatException &e) {
        assertEquals("radix out of range", e.getMessage());
    }

    try {
        exceptionResult = Integer::valueOf((String) "", 2);
    }
    catch (NumberFormatException &e) {
        assertEquals("input string is null", e.getMessage());
    }
}
