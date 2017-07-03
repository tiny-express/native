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

#include "Long.hpp"

using namespace Java::Lang;

TEST (JavaLang, LongConstructor) {
	// Given empty value for Long constructor and assign value - Return Long
	Long emptyLong;
	emptyLong = 3;
	ASSERT_EQUAL(3, emptyLong.longValue());

	// Given value for Integer constructor and assign value - Return string
	Long validLong = 3;
	ASSERT_EQUAL(3, validLong.longValue());

	Long test = 3;
	ASSERT_EQUAL(3, test.intValue());
}

TEST (JavaLang, LongBitCount) {
	// Given valid long number to test bit count based on java source code and result
	long validValue = 393459834753422L;
	int result = Long::bitCount(validValue);

	int expectedResult = 24;
	ASSERT_EQUAL(expectedResult, result);

	validValue = 4547830931350L;
	result = Long::bitCount(validValue);

	expectedResult = 25;
	ASSERT_EQUAL(expectedResult, result);
}

TEST (JavaLang, LongByteValue) {
    // Given valid long value to test byteValue() based on java source code result
	Long validValue = 393239259234023474L;
    int result = validValue.byteValue();

    int expectedResult = 50;
    ASSERT_EQUAL(expectedResult, result);

    validValue = 200L;
    result = validValue.byteValue();

    expectedResult = -56;
    ASSERT_EQUAL(expectedResult, result);
}

TEST (JavaLang, LongCompare) {
    // Given valid long value to test compare()
	long validValue = 79473043431L;
	long lessValue = 7947304343L;
	long equalValue = 79473043431L;
	long moreValue = 794730534312L;

	int result = Long::compare(validValue, lessValue);
	int expectedResult = 1;
	ASSERT_EQUAL(expectedResult, result);

	result = Long::compare(validValue, equalValue);
	expectedResult = 0;
	ASSERT_EQUAL(expectedResult, result);

	result = Long::compare(validValue, moreValue);
	expectedResult = -1;
	ASSERT_EQUAL(expectedResult, result);
}

TEST (JavaLang, LongCompareTo) {
    // Given valid Long value to test compareTo()
	Long validValue = 857503832954L;
	Long lessValue = 23932827534L;
	Long equalValue = 857503832954L;
	Long moreValue = 857503832954222L;

	int result = validValue.compareTo(lessValue);
	int expectedValue = 1;
	ASSERT_EQUAL(expectedValue, result);

	result = validValue.compareTo(equalValue);
	expectedValue = 0;
	ASSERT_EQUAL(expectedValue, result);

	result = validValue.compareTo(moreValue);
	expectedValue = -1;
	ASSERT_EQUAL(expectedValue, result);
}

TEST (JavaLang, LongComparision) {
	// Give a valid number and make a comparision
	Long validNumber = 123000000000;
	Long targetNumber;

	// Test validNumber is equal targetNumber
	targetNumber = 123000000000;
	ASSERT_TRUE(validNumber == targetNumber);

	// Test validNumber is not equal targetNumber
	targetNumber = 113000000000;
	ASSERT_TRUE(validNumber != targetNumber);

	// Test validNumber is less than targetNumber
	targetNumber = 124000000000;
	ASSERT_TRUE(validNumber < targetNumber);

	// Test validNumber is equal or less then targetNumber
	targetNumber = 125000000000;
	ASSERT_TRUE(validNumber <= targetNumber);

	// Test validNumber is more than targetNumber
	targetNumber = 122000000000;
	ASSERT_TRUE(validNumber > targetNumber);

	// Test validNumber is equal or more than targetNumber
	targetNumber = 121000000000;
	ASSERT_TRUE(validNumber >= targetNumber);
}

TEST (JavaLang, LongOperator) {
	// Given a valid number
	Long validNumber = 5;
	Long targetNumber = 3;

	// Make a summation with targetNumber
	Long summationNumber = 8;
	ASSERT_TRUE(summationNumber == ( validNumber + targetNumber ));

	// Make a subtraction with targetNumber
	Long subtractionNumber = 2;
	ASSERT_TRUE(subtractionNumber == ( validNumber - targetNumber ));

	// Make a multiplication with targetNumber
	Long multiplicationNumber = 15;
	ASSERT_TRUE(multiplicationNumber == ( validNumber * targetNumber ));

	// Make a division with targetNumber
	Long divisionNumber = 1;
	ASSERT_TRUE(divisionNumber == ( validNumber / targetNumber ));

	// Make a modulo with targetNumber
	Long modNumber = 2;
	ASSERT_TRUE(modNumber == ( validNumber % targetNumber ));
}

TEST (JavaLang, LongParseLong) {
	// Given value for Long constructor and assign value - Return long
	Long validLong = Long::parseLong("6");
	long expectedResult = 6;
	ASSERT_EQUAL(expectedResult, validLong.longValue());

    // Given valid string to test parseLong with radix 16
    String validNumberString = "1b";
    Long result = Long::parseLong(validNumberString, 16);

	expectedResult = 27;
    ASSERT_EQUAL(expectedResult, result.longValue());

	String invalidNumbeString = "122q3";
	result = Long::parseLong(invalidNumbeString, 16);

	expectedResult = -1;
	ASSERT_EQUAL(expectedResult, result.longValue());
}

TEST (JavaLang, LongEquals) {
    // Given valid Long value to test equals()
	Long validValue = 1231372934234234L;
	Long anotherValue = 2434234234234L;

	ASSERT_TRUE(validValue.equals(validValue));

	ASSERT_FALSE(validValue.equals(anotherValue));
}

TEST (JavaLang, LongGetLong) {
    // Given valid hexString and decimalString to test getLong through those String
    // The result is based on java code result
	String hexString = "0x23";
	String decimalString = "123";

	Long result = Long::getLong(hexString);
	long expectedResult = 35;
	ASSERT_EQUAL(expectedResult, result.longValue());

	result = Long::getLong(decimalString);
	expectedResult = 123;
	ASSERT_EQUAL(expectedResult, result.longValue());
}

TEST (JavaLang, LongDecode) {
	// Given valid numberString to test decode value
	String validNumberString = "0x1b";
	Long result = Long::decode(validNumberString);

	long expectedResult = 27;
	ASSERT_EQUAL(expectedResult, result.longValue());

	String invalidNumbeString = "0x23xx";
	result = Long::decode(invalidNumbeString);

	expectedResult = -1;
	ASSERT_EQUAL(expectedResult, result.longValue());
}

TEST (JavaLang, LongNumberOfLeadingZeros) {
	// Given valid long number to test leading
    // The result is based on java code result
	long validValue = 4053239666997989821L;
	int result = Long::numberOfLeadingZeros(validValue);

	int expectedResult = 2;
	ASSERT_EQUAL(expectedResult, result);

	validValue = 40532396L;
	result = Long::numberOfLeadingZeros(validValue);

	expectedResult = 38;
	ASSERT_EQUAL(expectedResult, result);
}

TEST (JavaLang, LongToHexString) {
	// Given valid long value to test toHexString()
    // The result is based on java code result
	long validValue = 4053239666997989821;
	String result = Long::toHexString(validValue);

	String expectedString = "384000008cf011bd";
	ASSERT_STR(expectedString.toString(), result.toString());

	validValue = -5603022497796657139;
	result = Long::toHexString(validValue);

	expectedString = "b23e10b96e4ef00d";
	ASSERT_STR(expectedString.toString(), result.toString());
}