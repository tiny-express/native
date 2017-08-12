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

#include "Integer.hpp"
#include "../NumberFormatException/NumberFormatException.hpp"
#include "../UnsupportedOperationException/UnsupportedOperationException.hpp"
#include "../ArithmeticException/ArithmeticException.hpp"

using namespace Java::Lang;

TEST (JavaLang, IntegerConstructor) {
	// Test Integer::Integer()
	Integer integerConstructorNoneParameter;
	ASSERT_EQUAL(0, integerConstructorNoneParameter.intValue());
	ASSERT_STR((string) "0", integerConstructorNoneParameter.toString());
	
	// Test Integer::Integer(String stringInput)
	Integer integerConstructorStringParameter((String) "13");
	ASSERT_EQUAL(13, integerConstructorStringParameter.intValue());
	ASSERT_STR((string) "13", integerConstructorStringParameter.toString());
	
	// Test Integer::Integer(const Integer &integer)
	Integer integerConstructorIntegerParameter = 13;
	ASSERT_EQUAL(13, integerConstructorIntegerParameter.intValue());
	ASSERT_STR((string) "13", integerConstructorIntegerParameter.toString());
}

TEST (JavaLang, IntegerComparision) {
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
	
	// Test validNumber is greater than targetNumber
	targetNumberComparision = 1;
	ASSERT_TRUE(validNumberComparision > targetNumberComparision);
	
	// Test validNumber is equal or greater than targetNumber
	targetNumberComparision = 2;
	ASSERT_TRUE(validNumberComparision >= targetNumberComparision);
}

TEST (JavaLang, IntegerOperator) {
	// Create variable
	Integer validNumberOperator = 5;
	Integer targetNumberOperator = 3;
	Integer expectedResult;
	Integer actualResult;
	
	// Make a summation
	expectedResult = 8;
	actualResult = validNumberOperator + targetNumberOperator;
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	expectedResult = 13;
	actualResult += validNumberOperator;
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	// Make a subtraction
	expectedResult = 2;
	actualResult = validNumberOperator - targetNumberOperator;
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	expectedResult = -3;
	actualResult -= validNumberOperator;
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	// Make a multiplication
	expectedResult = 15;
	actualResult = validNumberOperator * targetNumberOperator;
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	expectedResult = 75;
	actualResult *= validNumberOperator;
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	// Make a division
	expectedResult = 1;
	actualResult = validNumberOperator / targetNumberOperator;
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	try {
		actualResult = validNumberOperator / 0;
	}
	catch (ArithmeticException &e) {
		ASSERT_STR("Divide by zero", e.getMessage().toString());
	}
	
	expectedResult = 1;
	actualResult = 5;
	actualResult /= targetNumberOperator;
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	try {
		actualResult /= 0;
	}
	catch (ArithmeticException &e) {
		ASSERT_STR("Divide by zero", e.getMessage().toString());
	}
	
	// Make a modulo
	expectedResult = 2;
	actualResult = validNumberOperator % targetNumberOperator;
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	try {
		actualResult = validNumberOperator % 0;
	}
	catch (ArithmeticException &e) {
		ASSERT_STR("Divide by zero", e.getMessage().toString());
	}
	
	expectedResult = 2;
	actualResult = 5;
	actualResult %= targetNumberOperator;
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	try {
		actualResult %= 0;
	}
	catch (ArithmeticException &e) {
		ASSERT_STR("Divide by zero", e.getMessage().toString());
	}
}

TEST (JavaLang, IntegerCompareTo) {
	// Given valid Integer to compare with target
	Integer validValueCompareTo = 15;
	Integer lessThanValueCompareTo = 12;
	Integer equalValueCompareTo = 15;
	Integer greaterThanValueCompareTo = 20;
	
	// Return 1 if validValue is greater than lessThanValue
	ASSERT_EQUAL(1, validValueCompareTo.compareTo(lessThanValueCompareTo));
	
	// Return 0 if validValue is greater than equalValue
	ASSERT_EQUAL(0, validValueCompareTo.compareTo(equalValueCompareTo));
	
	// Return -1 if validValue is less than greater ThanValue
	ASSERT_EQUAL(-1, validValueCompareTo.compareTo(greaterThanValueCompareTo));
	
	// TODO - loint@foodtiny.com will review this case again
	Integer integerCompareTo = 1;
	Comparable<Integer> *comparable = &validValueCompareTo;
	ASSERT_EQUAL(1, comparable->compareTo(integerCompareTo));
}

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

TEST (JavaLang, IntegerStringValue) {
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
	realResultStringValue = oneIntegerStringValue.stringValue();
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

TEST (JavaLang, IntegerIntValue) {
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

TEST (JavaLang, IntegerFloatValue) {
	// Input different values of type int to compare to the realResult of Integer::floatValue
	Integer positiveIntegerFloatValue = 12345;
	float expectedResultFloatValue = 12345.00;
	float realResultFloatValue = positiveIntegerFloatValue.floatValue();
	ASSERT_TRUE(expectedResultFloatValue == realResultFloatValue);
	
	
	Integer negativeInteger = -12345;
	expectedResultFloatValue = (float) -12345.0;
	realResultFloatValue = negativeInteger.floatValue();
	ASSERT_TRUE(expectedResultFloatValue == realResultFloatValue);
}

TEST (JavaLang, IntegerDoubleValue) {
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

TEST (JavaLang, IntegerBitCount) {
	int inputInt;
	int expectedResult;
	int actualResult;
	
	inputInt = 0;
	expectedResult = 0;
	actualResult = Integer::bitCount(inputInt);
	ASSERT_EQUAL(expectedResult, actualResult);
	
	inputInt = 1;  // 01
	expectedResult = 1;
	actualResult = Integer::bitCount(inputInt);
	ASSERT_EQUAL(expectedResult, actualResult);
	
	inputInt = -1;  // 11
	expectedResult = 32;
	actualResult = Integer::bitCount(inputInt);
	ASSERT_EQUAL(expectedResult, actualResult);
	
	inputInt = 13;  // 0000 1101
	expectedResult = 3;
	actualResult = Integer::bitCount(inputInt);
	ASSERT_EQUAL(expectedResult, actualResult);
	
	inputInt = Integer::MAX_VALUE;  // 2, 147, 483, 647(10) = 0111 1111 1111 1111 1111 1111 1111 1111 (2)
	expectedResult = 31;
	actualResult = Integer::bitCount(inputInt);
	ASSERT_EQUAL(expectedResult, actualResult);
	
	inputInt = Integer::MIN_VALUE; // -2, 147, 483, 648(10) = 1000 0000 0000 0000 0000 0000 0000 0000
	expectedResult = 1;
	actualResult = Integer::bitCount(inputInt);
	ASSERT_EQUAL(expectedResult, actualResult);
}

TEST (JavaLang, IntegerByteValue) {
	Integer integerInput;
	
	integerInput = 0;
	ASSERT_EQUAL((byte) 0, integerInput.byteValue());
	
	integerInput = 1;
	ASSERT_EQUAL((byte) 1, integerInput.byteValue());
	
	integerInput = -1;
	ASSERT_EQUAL((byte) -1, integerInput.byteValue());
	
	integerInput = 13;
	ASSERT_EQUAL((byte) 13, integerInput.byteValue());
	
	integerInput = Integer::MAX_VALUE;
	ASSERT_EQUAL((byte) -1, integerInput.byteValue());
	
	integerInput = Integer::MIN_VALUE;
	ASSERT_EQUAL((byte) 0, integerInput.byteValue());
}

TEST (JavaLang, IntegerCompare) {
	// Given 2 int
	int greater = 10;
	int smaller = 5;
	
	// Compare 2 equal value;
	ASSERT_EQUAL(0, Integer::compare(greater, greater));
	
	// Compare different value
	ASSERT_EQUAL(-1, Integer::compare(smaller, greater));
	ASSERT_EQUAL(1, Integer::compare(greater, smaller));
}

TEST (JavaLang, IntegerCompareUnsigned) {
	// Given 3 int
	int greater = 10;
	int smaller = 5;
	int negative = -10;
	
	// Compare 2 equal value;
	ASSERT_EQUAL(0, Integer::compareUnsigned(greater, greater));
	ASSERT_EQUAL(0, Integer::compareUnsigned(negative, negative));
	
	// Compare different value
	ASSERT_EQUAL(-1, Integer::compareUnsigned(smaller, greater));
	ASSERT_EQUAL(1, Integer::compareUnsigned(greater, smaller));
	
	// Compare negative value
	ASSERT_EQUAL(-1, Integer::compareUnsigned(greater, negative));
	ASSERT_EQUAL(1, Integer::compareUnsigned(negative, greater));
}

TEST (JavaLang, IntegerDecode) {
	String stringInput;
	Integer expectedResult;
	Integer actualResult;
	Integer exceptionResult;
	
	stringInput = "";
	try {
		exceptionResult = Integer::decode(stringInput);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("input string is null", e.getMessage().toString());
	}
	
	// Cast all case of input a string of type decimal number
	stringInput = "0";
	expectedResult = 0;
	actualResult = Integer::decode(stringInput);
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	stringInput = (String) "1";
	expectedResult = 1;
	actualResult = Integer::decode(stringInput);
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	stringInput = (String) "-1";
	expectedResult = -1;
	actualResult = Integer::decode(stringInput);
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	stringInput = (String) "13";
	expectedResult = 13;
	actualResult = Integer::decode(stringInput);
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	// Test out of range
	stringInput = (String) "2147483650";
	try {
		exceptionResult = Integer::decode(stringInput);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Integer out of range", e.getMessage().toString());
	}
	
	stringInput = (String) "-2147483650";
	try {
		exceptionResult = Integer::decode(stringInput);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Integer out of range", e.getMessage().toString());
	}
	
	
	stringInput = (String) "Not a Number";
	try {
		exceptionResult = Integer::decode(stringInput);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Not a number", e.getMessage().toString());
	}
	
	// Cast all case of input a string of type octal
	stringInput = "0";
	expectedResult = 0;
	actualResult = Integer::decode(stringInput);
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	stringInput = (String) "01";
	expectedResult = 1;
	actualResult = Integer::decode(stringInput);
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	stringInput = (String) "-01";
	expectedResult = -1;
	actualResult = Integer::decode(stringInput);
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	stringInput = (String) "015";
	expectedResult = 13;
	actualResult = Integer::decode(stringInput);
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	// Test out of range
	stringInput = (String) "020000000002";
	try {
		exceptionResult = Integer::decode(stringInput);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Integer out of range", e.getMessage().toString());
	}
	
	stringInput = (String) "-020000000002";
	try {
		exceptionResult = Integer::decode(stringInput);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Integer out of range", e.getMessage().toString());
	}
	
	// Cast all case of input a string of type hexadecimal number
	stringInput = "0x0";
	expectedResult = 0;
	actualResult = Integer::decode(stringInput);
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	stringInput = (String) "0x1";
	expectedResult = 1;
	actualResult = Integer::decode(stringInput);
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	stringInput = (String) "-0x1";
	expectedResult = -1;
	actualResult = Integer::decode(stringInput);
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	stringInput = (String) "0X1";
	expectedResult = 1;
	actualResult = Integer::decode(stringInput);
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	stringInput = (String) "-0X1";
	expectedResult = -1;
	actualResult = Integer::decode(stringInput);
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	stringInput = (String) "0xD";
	expectedResult = 13;
	actualResult = Integer::decode(stringInput);
	ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());
	
	// Test out of range
	stringInput = (String) "0x80000002";
	try {
		exceptionResult = Integer::decode(stringInput);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Integer out of range", e.getMessage().toString());
	}
	
	stringInput = (String) "-0x80000002";
	try {
		exceptionResult = Integer::decode(stringInput);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Integer out of range", e.getMessage().toString());
	}
}

TEST (JavaLang, IntegerDivideUnsigned) {
	// Given 4 int
	int positiveDividend = 10;
	int positiveDivisor = 5;
	int negativeDividend = -10;
	int negativeDivisor = -5;
	
	// Divide by zero
	try {
		int exceptionResult = Integer::divideUnsigned(positiveDividend, 0);
	}
	catch (ArithmeticException &e) {
		ASSERT_STR("Divide by zero", e.getMessage().toString());
	}
	
	// Positive divide
	ASSERT_EQUAL(0, Integer::divideUnsigned(0, positiveDivisor));
	ASSERT_EQUAL(2, Integer::divideUnsigned(positiveDividend, positiveDivisor));
	ASSERT_EQUAL(0, Integer::divideUnsigned(positiveDivisor, positiveDividend));
	
	// Negative divide
	ASSERT_EQUAL(0, Integer::divideUnsigned(0, negativeDivisor));
	ASSERT_EQUAL(0, Integer::divideUnsigned(negativeDividend, negativeDivisor));
	ASSERT_EQUAL(1, Integer::divideUnsigned(negativeDivisor, negativeDividend));
	
	// Mix divide
	ASSERT_EQUAL(0, Integer::divideUnsigned(0, positiveDivisor));
	ASSERT_EQUAL(858993457, Integer::divideUnsigned(negativeDividend, positiveDivisor));
	ASSERT_EQUAL(429496729, Integer::divideUnsigned(negativeDivisor, positiveDividend));
}

TEST (JavaLang, IntegerEquals) {
	Integer thisInteger;
	
	thisInteger = 13;
	ASSERT_FALSE(thisInteger.equals(0));
	ASSERT_FALSE(thisInteger.equals(1));
	ASSERT_FALSE(thisInteger.equals(-1));
	ASSERT_TRUE(thisInteger.equals(13));
}

// Test Integer::getInteger(String inputString)
// TEST(JavaLang, IntegerGetIntegerWithString) {
// String stringInput;
// Integer expectedResult;
// Integer actualResult;

// // Cast all case of input a string of type decimal number
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

// stringInput = (String) "2147483647"; // Integer::MAX_VALUE
// expectedResult = Integer::MAX_VALUE;
// actualResult = Integer:getInteger(stringInput);
// ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "-2147483648"; // Integer::MIN_VALUE
// expectedResult = Integer::MIN_VALUE;
// actualResult = Integer:getInteger(stringInput);
// ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "Not a Number";
// expectedResult = ;
// actualResult = Integer:getInteger(stringInput);
// ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());


// // Cast all case of input a string of type octal numberStringInput = (String) "0";
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

// stringInput = (String) "01111111111111111111111111111111"; // Integer::MAX_VALUE
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

// // Cast all case of input a string of type hexadecimal number
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

// stringInput = (String) "0x7FFFFFFF"; // Integer::MAX_VALUE
// expectedResult = 2147483647;
// actualResult = Integer:getInteger(stringInput);
// ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#FFFFFFFF80000000"; // Integer::MIN_VALUE
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
// TEST(JavaLang, IntegerGetIntegerWithStringAndInt) {
// String stringInput;
// Integer expectedResult;
// Integer actualResult;

// // Cast all case of input a string of type decimal number
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

// stringInput = (String) "2147483647"; // Integer::MAX_VALUE
// expectedResult = Integer::MAX_VALUE;
// actualResult = Integer:getInteger(stringInput, 9999);
// ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "-2147483648"; // Integer::MIN_VALUE
// expectedResult = Integer::MIN_VALUE;
// actualResult = Integer:getInteger(stringInput, 9999);
// ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "Not a Number";
// expectedResult = ;
// actualResult = Integer:getInteger(stringInput, 9999);
// ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());


// // Cast all case of input a string of type octal numberStringInput = (String) "0";
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

// stringInput = (String) "01111111111111111111111111111111"; // Integer::MAX_VALUE
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

// // Cast all case of input a string of type hexadecimal number
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

// stringInput = (String) "0x7FFFFFFF"; // Integer::MAX_VALUE
// expectedResult = 2147483647;
// actualResult = Integer:getInteger(stringInput, 9999);
// ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#FFFFFFFF80000000"; // Integer::MIN_VALUE
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
// TEST(JavaLang, IntegerGetIntegerWithStringAndInteger) {
// String stringInput;
// Integer expectedResult;
// Integer actualResult;

// // Cast all case of input a string of type decimal number
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

// stringInput = (String) "2147483647"; // Integer::MAX_VALUE
// expectedResult = Integer::MAX_VALUE;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "-2147483648"; // Integer::MIN_VALUE
// expectedResult = Integer::MIN_VALUE;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "Not a Number";
// expectedResult = ;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());


// // Cast all case of input a string of type octal numberStringInput = (String) "0";
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

// stringInput = (String) "01111111111111111111111111111111"; // Integer::MAX_VALUE
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

// // Cast all case of input a string of type hexadecimal number
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

// stringInput = (String) "0x7FFFFFFF"; // Integer::MAX_VALUE
// expectedResult = 2147483647;
// actualResult = Integer:getInteger(stringInput, (Integer) 9999);
// ASSERT_EQUAL(expectedResult.intValue(), actualResult.intValue());

// stringInput = (String) "#FFFFFFFF80000000"; // Integer::MIN_VALUE
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

TEST (JavaLang, IntegerHashCode) {
	Integer inputInteger;
	
	inputInteger = 0;
	ASSERT_EQUAL(0, inputInteger.hashCode());
	
	inputInteger = 1;
	ASSERT_EQUAL(1, inputInteger.hashCode());
	
	inputInteger = -1;
	ASSERT_EQUAL(-1, inputInteger.hashCode());
	
	inputInteger = 13;
	ASSERT_EQUAL(13, inputInteger.hashCode());
}

TEST (JavaLang, IntegerHashCodeOfInt) {
	ASSERT_EQUAL(0, Integer::hashCode(0));
	ASSERT_EQUAL(1, Integer::hashCode(1));
	ASSERT_EQUAL(-1, Integer::hashCode(-1));
	ASSERT_EQUAL(13, Integer::hashCode(13));
}

TEST (JavaLang, IntegerHighestOneBit) {
	ASSERT_EQUAL(0, Integer::highestOneBit(0));
	ASSERT_EQUAL(1, Integer::highestOneBit(1));
	ASSERT_EQUAL(-2147483648, Integer::highestOneBit(-1));
	ASSERT_EQUAL(8, Integer::highestOneBit(13));
	ASSERT_EQUAL(1073741824, Integer::highestOneBit(Integer::MAX_VALUE));
	ASSERT_EQUAL(-2147483648, Integer::highestOneBit(Integer::MIN_VALUE));
}

TEST (JavaLang, IntegerLowestOneBit) {
	ASSERT_EQUAL(0, Integer::lowestOneBit(0));
	ASSERT_EQUAL(1, Integer::lowestOneBit(1));
	ASSERT_EQUAL(1, Integer::lowestOneBit(-1));
	ASSERT_EQUAL(1, Integer::lowestOneBit(13));
	ASSERT_EQUAL(1, Integer::lowestOneBit(Integer::MAX_VALUE));
	ASSERT_EQUAL(-2147483648, Integer::lowestOneBit(Integer::MIN_VALUE));
}

TEST (JavaLang, IntegerMax) {
	ASSERT_EQUAL(0, Integer::max(0, 0));
	ASSERT_EQUAL(1, Integer::max(0, 1));
	ASSERT_EQUAL(0, Integer::max(0, -1));
	ASSERT_EQUAL(13, Integer::max(0, 13));
}

TEST (JavaLang, IntegerMin) {
	ASSERT_EQUAL(0, Integer::min(0, 0));
	ASSERT_EQUAL(0, Integer::min(0, 1));
	ASSERT_EQUAL(-1, Integer::min(0, -1));
}

TEST (JavaLang, IntegerNumberOfLeadingZeros) {
	ASSERT_EQUAL(32, Integer::numberOfLeadingZeros(0));
	ASSERT_EQUAL(31, Integer::numberOfLeadingZeros(1));
	ASSERT_EQUAL(0, Integer::numberOfLeadingZeros(-1));
	ASSERT_EQUAL(28, Integer::numberOfLeadingZeros(13));
	ASSERT_EQUAL(1, Integer::numberOfLeadingZeros(Integer::MAX_VALUE));
	ASSERT_EQUAL(0, Integer::numberOfLeadingZeros(Integer::MIN_VALUE));
}

TEST (JavaLang, IntegerNumberOfTrailingZeros) {
	ASSERT_EQUAL(32, Integer::numberOfTrailingZeros(0));
	ASSERT_EQUAL(0, Integer::numberOfTrailingZeros(1));
	ASSERT_EQUAL(0, Integer::numberOfTrailingZeros(-1));
	ASSERT_EQUAL(0, Integer::numberOfTrailingZeros(-113));
	ASSERT_EQUAL(1, Integer::numberOfTrailingZeros(1314));
	ASSERT_EQUAL(31, Integer::numberOfTrailingZeros(Integer::MIN_VALUE));
}


TEST (JavaLang, IntegerParseIntWithRadix) {
	ASSERT_EQUAL(Integer::parseInt((String) "0", 10), 0);
	ASSERT_EQUAL(Integer::parseInt((String) "473", 10), 473);
	ASSERT_EQUAL(Integer::parseInt((String) "+42", 10), 42);
	ASSERT_EQUAL(Integer::parseInt((String) "-0", 10), 0);
	ASSERT_EQUAL(Integer::parseInt((String) "-FF", 16), -255);
	ASSERT_EQUAL(Integer::parseInt((String) "1100110", 2), 102);
	ASSERT_EQUAL(Integer::parseInt((String) "2147483647", 10), 2147483647);
	ASSERT_EQUAL(Integer::parseInt((String) "-2147483648", 10), -2147483648);
	Integer exceptionResult;
	try {
		exceptionResult = Integer::parseInt((String) "2147483648", 10);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Integer out of range", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::parseInt((String) "99999999999999999999", 10);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Integer out of range", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::parseInt((String) "99", 8);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Not a number", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::parseInt((String) "Kona", 10);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Not a number", e.getMessage().toString());
	}
	
	ASSERT_EQUAL(Integer::parseInt((String) "Kona", 27), 411787);
	
	try {
		exceptionResult = Integer::parseInt((String) "Kona", 33);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("radix out of range", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::parseInt((String) "Kona", 1);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("radix out of range", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::parseInt((String) "", 2);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("input string is null", e.getMessage().toString());
	}
}

TEST (JavaLang, IntegerParseInt) {
	String stringInput;
	int expectedResult;
	int actualResult;
	int exceptionResult;
	
	stringInput = "";
	try {
		exceptionResult = Integer::parseInt(stringInput);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("input string is null", e.getMessage().toString());
	}
	
	// Cast all case of input a string of type decimal number
	stringInput = (String) "0";
	expectedResult = 0;
	actualResult = Integer::parseInt(stringInput);
	ASSERT_EQUAL(expectedResult, actualResult);
	
	stringInput = (String) "1";
	expectedResult = 1;
	actualResult = Integer::parseInt(stringInput);
	ASSERT_EQUAL(expectedResult, actualResult);
	
	stringInput = (String) "-1";
	expectedResult = -1;
	actualResult = Integer::parseInt(stringInput);
	ASSERT_EQUAL(expectedResult, actualResult);
	
	stringInput = (String) "13";
	expectedResult = 13;
	actualResult = Integer::parseInt(stringInput);
	ASSERT_EQUAL(expectedResult, actualResult);
	
	stringInput = (String) "Not a Number";
	try {
		exceptionResult = Integer::parseInt(stringInput);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Not a number", e.getMessage().toString());
	}
	
	// Test out of range
	stringInput = (String) "2147483650";
	try {
		exceptionResult = Integer::parseInt(stringInput);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Integer out of range", e.getMessage().toString());
	}
	
	stringInput = (String) "-21474834650";
	try {
		exceptionResult = Integer::parseInt(stringInput);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Integer out of range", e.getMessage().toString());
	}
}

TEST (JavaLang, IntegerParseUnsignedIntWithRadix) {
	Integer exceptionResult;
	
	ASSERT_EQUAL(Integer::parseUnsignedInt((String) "0", 10), 0);
	ASSERT_EQUAL(Integer::parseUnsignedInt((String) "473", 10), 473);
	ASSERT_EQUAL(Integer::parseUnsignedInt((String) "+42", 10), 42);
	try {
		exceptionResult = Integer::parseUnsignedInt((String) "-0", 10);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Illegal leading minus sign", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::parseUnsignedInt((String) "-FF", 16);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Illegal leading minus sign", e.getMessage().toString());
	}
	
	ASSERT_EQUAL(Integer::parseUnsignedInt((String) "1100110", 2), 102);
	ASSERT_EQUAL(Integer::parseUnsignedInt((String) "2147483647", 10), 2147483647);
	
	try {
		exceptionResult = Integer::parseUnsignedInt((String) "-2147483648", 10);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Illegal leading minus sign", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::parseUnsignedInt((String) "99", 8);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Not a number", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::parseUnsignedInt((String) "Kona", 10);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Not a number", e.getMessage().toString());
	}
	
	ASSERT_EQUAL(Integer::parseUnsignedInt((String) "Kona", 27), 411787);
	
	try {
		exceptionResult = Integer::parseUnsignedInt((String) "Kona", 33);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("radix out of range", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::parseUnsignedInt((String) "Kona", 1);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("radix out of range", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::parseUnsignedInt((String) "", 2);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("input string is null", e.getMessage().toString());
	}
	
	// Test out of range
	try {
		exceptionResult = Integer::parseUnsignedInt((String) "4294967297", 10);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Unsigned integer out of range", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::parseUnsignedInt((String) "12345678901234567890123456789", 10);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Unsigned integer out of range", e.getMessage().toString());
	}
}

TEST (JavaLang, IntegerParseUnsignedInt) {
	String stringInput;
	int expectedResult;
	int actualResult;
	int exceptionResult;
	
	// Cast all case of inputString a string of type decimal number
	stringInput = (String) "0";
	expectedResult = 0;
	actualResult = Integer::parseUnsignedInt(stringInput);
	ASSERT_EQUAL(expectedResult, actualResult);
	
	stringInput = (String) "1";
	expectedResult = 1;
	actualResult = Integer::parseUnsignedInt(stringInput);
	ASSERT_EQUAL(expectedResult, actualResult);
	
	stringInput = (String) "-1";
	try {
		exceptionResult = Integer::parseUnsignedInt(stringInput);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Illegal leading minus sign", e.getMessage().toString());
	}
	
	stringInput = (String) "13";
	expectedResult = 13;
	actualResult = Integer::parseUnsignedInt(stringInput);
	ASSERT_EQUAL(expectedResult, actualResult);
	
	stringInput = (String) "Not a Number";
	try {
		exceptionResult = Integer::parseUnsignedInt(stringInput);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Not a number", e.getMessage().toString());
	}
	
	// Test out of range
	stringInput = (String) "4294967297";
	try {
		exceptionResult = Integer::parseUnsignedInt(stringInput);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Unsigned integer out of range", e.getMessage().toString());
	}
	
	stringInput = (String) "12345678901234567890123456789";
	try {
		exceptionResult = Integer::parseUnsignedInt(stringInput);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Unsigned integer out of range", e.getMessage().toString());
	}
}

TEST (JavaLang, IntegerRemainderUnsigned) {
	// Given 4 int
	int positiveDividend = 10;
	int positiveDivisor = 4;
	int negativeDividend = -10;
	int negativeDivisor = -4;
	
	// Divide by zero
	try {
		int exceptionResult = Integer::remainderUnsigned(positiveDividend, 0);
	}
	catch (ArithmeticException &e) {
		ASSERT_STR("Divide by zero", e.getMessage().toString());
	}
	
	// Positive divide
	ASSERT_EQUAL(0, Integer::remainderUnsigned(0, positiveDivisor));
	ASSERT_EQUAL(2, Integer::remainderUnsigned(positiveDividend, positiveDivisor));
	ASSERT_EQUAL(4, Integer::remainderUnsigned(positiveDivisor, positiveDividend));
	
	// Negative divide
	ASSERT_EQUAL(0, Integer::remainderUnsigned(0, negativeDivisor));
	ASSERT_EQUAL(-10, Integer::remainderUnsigned(negativeDividend, negativeDivisor));
	ASSERT_EQUAL(6, Integer::remainderUnsigned(negativeDivisor, negativeDividend));
	
	// Mix divide
	ASSERT_EQUAL(0, Integer::remainderUnsigned(0, positiveDivisor));
	ASSERT_EQUAL(2, Integer::remainderUnsigned(negativeDividend, positiveDivisor));
	ASSERT_EQUAL(2, Integer::remainderUnsigned(negativeDivisor, positiveDividend));
}

TEST (JavaLang, IntegerReverse) {
	ASSERT_EQUAL(0, Integer::reverse(0));
	ASSERT_EQUAL(-2147483648, Integer::reverse(1));
	ASSERT_EQUAL(-1, Integer::reverse(-1));
	ASSERT_EQUAL(-1342177280, Integer::reverse(13));
	ASSERT_EQUAL(-2, Integer::reverse(Integer::MAX_VALUE));
	ASSERT_EQUAL(1, Integer::reverse(Integer::MIN_VALUE));
}

TEST (JavaLang, IntegerReverseBytes) {
	ASSERT_EQUAL(0, Integer::reverseBytes(0));
	ASSERT_EQUAL(16777216, Integer::reverseBytes(1));
	ASSERT_EQUAL(-1, Integer::reverseBytes(-1));
	ASSERT_EQUAL(218103808, Integer::reverseBytes(13));
	ASSERT_EQUAL(-129, Integer::reverseBytes(Integer::MAX_VALUE));
	ASSERT_EQUAL(128, Integer::reverseBytes(Integer::MIN_VALUE));
}

TEST (JavaLang, IntegerRotateLeft) {
	ASSERT_EQUAL(-2147483648, Integer::rotateLeft(1, -1));
	ASSERT_EQUAL(8192, Integer::rotateLeft(1, 13));
	ASSERT_EQUAL(1, Integer::rotateLeft(1, Integer::MIN_VALUE));
}

TEST (JavaLang, IntegerRotateRight) {
	ASSERT_EQUAL(1, Integer::rotateRight(1, 0));
	ASSERT_EQUAL(-2147483648, Integer::rotateRight(1, 1));
	ASSERT_EQUAL(2, Integer::rotateRight(1, -1));
	ASSERT_EQUAL(524288, Integer::rotateRight(1, 13));
	ASSERT_EQUAL(2, Integer::rotateRight(1, Integer::MAX_VALUE));
	ASSERT_EQUAL(1, Integer::rotateRight(1, Integer::MIN_VALUE));
}

TEST (JavaLang, IntegerSignum) {
	ASSERT_EQUAL(0, Integer::signum(0));
	ASSERT_EQUAL(1, Integer::signum(1));
	ASSERT_EQUAL(-1, Integer::signum(-1));
}

TEST (JavaLang, IntegerSum) {
	ASSERT_EQUAL(13, Integer::sum(13, 0));
	ASSERT_EQUAL(12, Integer::sum(13, -1));
	ASSERT_EQUAL(26, Integer::sum(13, 13));
	ASSERT_EQUAL(-2147483636, Integer::sum(13, Integer::MAX_VALUE));
}

TEST (JavaLang, IntegerToBinaryString) {
	ASSERT_STR((string) "0", Integer::toBinaryString(0).toString());
	ASSERT_STR((string) "1", Integer::toBinaryString(1).toString());
	ASSERT_STR((string) "11111111111111111111111111111111", Integer::toBinaryString(-1).toString());
	ASSERT_STR((string) "1101", Integer::toBinaryString(13).toString());
	ASSERT_STR((string) "1111111111111111111111111111111", Integer::toBinaryString(Integer::MAX_VALUE).toString());
	ASSERT_STR((string) "10000000000000000000000000000000", Integer::toBinaryString(Integer::MIN_VALUE).toString());
}

TEST (JavaLang, IntegerToHexString) {
	ASSERT_STR((string) "0", Integer::toHexString(0).toString());
	ASSERT_STR((string) "1", Integer::toHexString(1).toString());
	ASSERT_STR((string) "ffffffff", Integer::toHexString(-1).toString());
	ASSERT_STR((string) "d", Integer::toHexString(13).toString());
	ASSERT_STR((string) "7fffffff", Integer::toHexString(Integer::MAX_VALUE).toString());
	ASSERT_STR((string) "80000000", Integer::toHexString(Integer::MIN_VALUE).toString());
}

TEST (JavaLang, IntegerToOctalString) {
	ASSERT_STR((string) "0", Integer::toOctalString(0).toString());
	ASSERT_STR((string) "1", Integer::toOctalString(1).toString());
	ASSERT_STR((string) "37777777777", Integer::toOctalString(-1).toString());
	ASSERT_STR((string) "15", Integer::toOctalString(13).toString());
	ASSERT_STR((string) "17777777777", Integer::toOctalString(Integer::MAX_VALUE).toString());
	ASSERT_STR((string) "20000000000", Integer::toOctalString(Integer::MIN_VALUE).toString());
}

TEST (JavaLang, IntegerToString) {
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

TEST(JavaLang, IntegerToStringFromInt) {
    ASSERT_STR((string) "0", Integer::toString(0).toString());
    ASSERT_STR((string) "1", Integer::toString(1).toString());
    ASSERT_STR((string) "-1", Integer::toString(-1).toString());
    ASSERT_STR((string) "13", Integer::toString(13).toString());
}

TEST (JavaLang, IntegerToStringWithRadix) {
	ASSERT_STR("0", Integer::toString(0, 10).toString());
	ASSERT_STR("473", Integer::toString(473, 10).toString());
	ASSERT_STR("-ff", Integer::toString(-255, 16).toString());
	ASSERT_STR("-1100110", Integer::toString(-102, 2).toString());
	ASSERT_STR("106", Integer::toString(70, 8).toString());
	
	// Radix out of range
	ASSERT_STR("473", Integer::toString(473, 100).toString());
	try {
		String exceptionString = Integer::toString(100, 20);
	}
	catch (UnsupportedOperationException &e) {
		ASSERT_STR("Haven't support this radix yet", e.getMessage().toString());
	}
}

TEST (JavaLang, IntegerToUnsignedLong) {
	ASSERT_EQUAL(0, Integer::toUnsignedLong(0));
	ASSERT_EQUAL(1, Integer::toUnsignedLong(1));
	ASSERT_EQUAL(4294967295, Integer::toUnsignedLong(-1));
	ASSERT_EQUAL(13, Integer::toUnsignedLong(13));
	ASSERT_EQUAL(2147483647, Integer::toUnsignedLong(Integer::MAX_VALUE));
	ASSERT_EQUAL(2147483648, Integer::toUnsignedLong(Integer::MIN_VALUE));
}

TEST (JavaLang, IntegerToUnsignedString) {
	ASSERT_STR("0", Integer::toUnsignedString(0, 10).toString());
	ASSERT_STR("473", Integer::toUnsignedString(473, 10).toString());
	ASSERT_STR("ffffff01", Integer::toUnsignedString(-255, 16).toString());
	ASSERT_STR("1100110", Integer::toUnsignedString(102, 2).toString());
	ASSERT_STR("106", Integer::toUnsignedString(70, 8).toString());
	
	// Radix out of range
	ASSERT_STR("473", Integer::toUnsignedString(473, 100).toString());
	
	// Radix is not 2, 8, 16, 10
	try {
		String exceptionString = Integer::toUnsignedString(100, 20);
	}
	catch (UnsupportedOperationException &e) {
		ASSERT_STR("Haven't support this radix yet", e.getMessage().toString());
	}
}

TEST (JavaLang, IntegerToUnsignedDecimalString) {
	ASSERT_STR("0", Integer::toUnsignedString(0).toString());
	ASSERT_STR("473", Integer::toUnsignedString(473).toString());
	ASSERT_STR("4294967041", Integer::toUnsignedString(-255).toString());
}

TEST (JavaLang, IntegerValueOfFromString) {
	ASSERT_EQUAL(0, Integer::valueOf((String) "0").intValue());
	ASSERT_EQUAL(1, Integer::valueOf((String) "1").intValue());
	ASSERT_EQUAL(13, Integer::valueOf((String) "13").intValue());
	
	Integer exceptionResult;
	try {
		exceptionResult = Integer::parseInt((String) "", 2);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("input string is null", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::valueOf((String) "-FF");
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Not a number", e.getMessage().toString());
	}
	
	// Test out of range
	try {
		exceptionResult = Integer::valueOf((String) "21474836450");
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Integer out of range", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::valueOf((String) "-21474836458");
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Integer out of range", e.getMessage().toString());
	}
}

TEST (JavaLang, IntegerValueOfFromInt) {
	ASSERT_EQUAL(0, Integer::valueOf(0).intValue());
	ASSERT_EQUAL(1, Integer::valueOf(1).intValue());
	ASSERT_EQUAL(-1, Integer::valueOf(-1).intValue());
	ASSERT_EQUAL(13, Integer::valueOf(13).intValue());
	ASSERT_EQUAL(2147483647, Integer::valueOf(2147483647).intValue());
	ASSERT_EQUAL(-2147483648, Integer::valueOf(-2147483648).intValue());
}

TEST (JavaLang, IntegerValueOfWithRadix) {
	ASSERT_EQUAL(0, Integer::valueOf((String) "0", 10).intValue());
	ASSERT_EQUAL(473, Integer::valueOf((String) "473", 10).intValue());
	ASSERT_EQUAL(42, Integer::valueOf((String) "+42", 10).intValue());
	ASSERT_EQUAL(0, Integer::valueOf((String) "-0", 10).intValue());
	ASSERT_EQUAL(-255, Integer::valueOf((String) "-FF", 16).intValue());
	ASSERT_EQUAL(102, Integer::valueOf((String) "1100110", 2).intValue());
	ASSERT_EQUAL(2147483647, Integer::valueOf((String) "2147483647", 10).intValue());
	ASSERT_EQUAL(-2147483648, Integer::valueOf((String) "-2147483648", 10).intValue());
	Integer exceptionResult;
	try {
		exceptionResult = Integer::valueOf((String) "2147483648", 10);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Integer out of range", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::valueOf((String) "99", 8);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Not a number", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::valueOf((String) "Kona", 10);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("Not a number", e.getMessage().toString());
	}
	
	ASSERT_EQUAL(411787, Integer::valueOf((String) "Kona", 27).intValue());
	
	try {
		exceptionResult = Integer::valueOf((String) "Kona", 33);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("radix out of range", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::valueOf((String) "Kona", 1);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("radix out of range", e.getMessage().toString());
	}
	
	try {
		exceptionResult = Integer::valueOf((String) "", 2);
	}
	catch (NumberFormatException &e) {
		ASSERT_STR("input string is null", e.getMessage().toString());
	}
}
