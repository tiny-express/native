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
	
	String invalidNumberString = "0x23xx";
	result = Long::decode(invalidNumberString);
	
	expectedResult = -1;
	ASSERT_EQUAL(expectedResult, result.longValue());
}

TEST (JavaLang, LongNumberOfLeadingZeros) {
    ASSERT_EQUAL(0, Long::numberOfLeadingZeros(-1L));
    ASSERT_EQUAL(33, Long::numberOfLeadingZeros(1234567890L));

    ASSERT_EQUAL(64, Long::numberOfLeadingZeros(0L));
    ASSERT_EQUAL(63, Long::numberOfLeadingZeros(1L));
    ASSERT_EQUAL(62, Long::numberOfLeadingZeros(2L));
    ASSERT_EQUAL(61, Long::numberOfLeadingZeros(4L));
    ASSERT_EQUAL(60, Long::numberOfLeadingZeros(8L));
    ASSERT_EQUAL(59, Long::numberOfLeadingZeros(16L));
    ASSERT_EQUAL(58, Long::numberOfLeadingZeros(32L));
    ASSERT_EQUAL(57, Long::numberOfLeadingZeros(64L));
    ASSERT_EQUAL(56, Long::numberOfLeadingZeros(128L));
    ASSERT_EQUAL(55, Long::numberOfLeadingZeros(256L));
    ASSERT_EQUAL(54, Long::numberOfLeadingZeros(512L));
    ASSERT_EQUAL(53, Long::numberOfLeadingZeros(1024L));
    ASSERT_EQUAL(52, Long::numberOfLeadingZeros(2048L));
    ASSERT_EQUAL(51, Long::numberOfLeadingZeros(4096L));
    ASSERT_EQUAL(50, Long::numberOfLeadingZeros(8192L));
    ASSERT_EQUAL(49, Long::numberOfLeadingZeros(16384L));
    ASSERT_EQUAL(48, Long::numberOfLeadingZeros(32768L));
    ASSERT_EQUAL(47, Long::numberOfLeadingZeros(65536L));
    ASSERT_EQUAL(46, Long::numberOfLeadingZeros(131072L));
    ASSERT_EQUAL(45, Long::numberOfLeadingZeros(262144L));
    ASSERT_EQUAL(44, Long::numberOfLeadingZeros(524288L));
    ASSERT_EQUAL(43, Long::numberOfLeadingZeros(1048576L));
    ASSERT_EQUAL(42, Long::numberOfLeadingZeros(2097152L));
    ASSERT_EQUAL(41, Long::numberOfLeadingZeros(4194304L));
    ASSERT_EQUAL(40, Long::numberOfLeadingZeros(8388608L));
    ASSERT_EQUAL(39, Long::numberOfLeadingZeros(16777216L));
    ASSERT_EQUAL(38, Long::numberOfLeadingZeros(33554432L));
    ASSERT_EQUAL(37, Long::numberOfLeadingZeros(67108864L));
    ASSERT_EQUAL(36, Long::numberOfLeadingZeros(134217728L));
    ASSERT_EQUAL(35, Long::numberOfLeadingZeros(268435456L));
    ASSERT_EQUAL(34, Long::numberOfLeadingZeros(536870912L));
    ASSERT_EQUAL(33, Long::numberOfLeadingZeros(1073741824L));
    ASSERT_EQUAL(32, Long::numberOfLeadingZeros(2147483648L));
    ASSERT_EQUAL(31, Long::numberOfLeadingZeros(4294967296L));
    ASSERT_EQUAL(30, Long::numberOfLeadingZeros(8589934592L));
    ASSERT_EQUAL(29, Long::numberOfLeadingZeros(17179869184L));
    ASSERT_EQUAL(28, Long::numberOfLeadingZeros(34359738368L));
    ASSERT_EQUAL(27, Long::numberOfLeadingZeros(68719476736L));
    ASSERT_EQUAL(26, Long::numberOfLeadingZeros(137438953472L));
    ASSERT_EQUAL(25, Long::numberOfLeadingZeros(274877906944L));
    ASSERT_EQUAL(24, Long::numberOfLeadingZeros(549755813888L));
    ASSERT_EQUAL(23, Long::numberOfLeadingZeros(1099511627776L));
    ASSERT_EQUAL(22, Long::numberOfLeadingZeros(2199023255552L));
    ASSERT_EQUAL(21, Long::numberOfLeadingZeros(4398046511104L));
    ASSERT_EQUAL(20, Long::numberOfLeadingZeros(8796093022208L));
    ASSERT_EQUAL(19, Long::numberOfLeadingZeros(17592186044416L));
    ASSERT_EQUAL(18, Long::numberOfLeadingZeros(35184372088832L));
    ASSERT_EQUAL(17, Long::numberOfLeadingZeros(70368744177664L));
    ASSERT_EQUAL(16, Long::numberOfLeadingZeros(140737488355328L));
    ASSERT_EQUAL(15, Long::numberOfLeadingZeros(281474976710656L));
    ASSERT_EQUAL(14, Long::numberOfLeadingZeros(562949953421312L));
    ASSERT_EQUAL(13, Long::numberOfLeadingZeros(1125899906842624L));
    ASSERT_EQUAL(12, Long::numberOfLeadingZeros(2251799813685248L));
    ASSERT_EQUAL(11, Long::numberOfLeadingZeros(4503599627370496L));
    ASSERT_EQUAL(10, Long::numberOfLeadingZeros(9007199254740992L));
    ASSERT_EQUAL(9, Long::numberOfLeadingZeros(18014398509481984L));
    ASSERT_EQUAL(8, Long::numberOfLeadingZeros(36028797018963968L));
    ASSERT_EQUAL(7, Long::numberOfLeadingZeros(72057594037927936L));
    ASSERT_EQUAL(6, Long::numberOfLeadingZeros(144115188075855872L));
    ASSERT_EQUAL(5, Long::numberOfLeadingZeros(288230376151711744L));
    ASSERT_EQUAL(4, Long::numberOfLeadingZeros(576460752303423488L));
    ASSERT_EQUAL(3, Long::numberOfLeadingZeros(1152921504606846976L));
    ASSERT_EQUAL(2, Long::numberOfLeadingZeros(2305843009213693952L));
    ASSERT_EQUAL(1, Long::numberOfLeadingZeros(4611686018427387904L));
    ASSERT_EQUAL(0, Long::numberOfLeadingZeros(9223372036854775808uL));
}

TEST(JavaLang, LongNumberOfTrailingZeros) {
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(-1L));
    ASSERT_EQUAL(2, Long::numberOfTrailingZeros(100L));

    ASSERT_EQUAL(64, Long::numberOfTrailingZeros(0L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(1L));
    ASSERT_EQUAL(1, Long::numberOfTrailingZeros(2L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(3L));
    ASSERT_EQUAL(2, Long::numberOfTrailingZeros(4L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(7L));
    ASSERT_EQUAL(3, Long::numberOfTrailingZeros(8L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(15L));
    ASSERT_EQUAL(4, Long::numberOfTrailingZeros(16L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(31L));
    ASSERT_EQUAL(5, Long::numberOfTrailingZeros(32L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(63L));
    ASSERT_EQUAL(6, Long::numberOfTrailingZeros(64L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(127L));
    ASSERT_EQUAL(7, Long::numberOfTrailingZeros(128L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(255L));
    ASSERT_EQUAL(8, Long::numberOfTrailingZeros(256L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(511L));
    ASSERT_EQUAL(9, Long::numberOfTrailingZeros(512L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(1023L));
    ASSERT_EQUAL(10, Long::numberOfTrailingZeros(1024L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(2047L));
    ASSERT_EQUAL(11, Long::numberOfTrailingZeros(2048L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(4095L));
    ASSERT_EQUAL(12, Long::numberOfTrailingZeros(4096L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(8191L));
    ASSERT_EQUAL(13, Long::numberOfTrailingZeros(8192L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(16383L));
    ASSERT_EQUAL(14, Long::numberOfTrailingZeros(16384L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(32767L));
    ASSERT_EQUAL(15, Long::numberOfTrailingZeros(32768L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(65535L));
    ASSERT_EQUAL(16, Long::numberOfTrailingZeros(65536L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(131071L));
    ASSERT_EQUAL(17, Long::numberOfTrailingZeros(131072L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(262143L));
    ASSERT_EQUAL(18, Long::numberOfTrailingZeros(262144L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(524287L));
    ASSERT_EQUAL(19, Long::numberOfTrailingZeros(524288L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(1048575L));
    ASSERT_EQUAL(20, Long::numberOfTrailingZeros(1048576L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(2097151L));
    ASSERT_EQUAL(21, Long::numberOfTrailingZeros(2097152L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(4194303L));
    ASSERT_EQUAL(22, Long::numberOfTrailingZeros(4194304L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(8388607L));
    ASSERT_EQUAL(23, Long::numberOfTrailingZeros(8388608L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(16777215L));
    ASSERT_EQUAL(24, Long::numberOfTrailingZeros(16777216L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(33554431L));
    ASSERT_EQUAL(25, Long::numberOfTrailingZeros(33554432L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(67108863L));
    ASSERT_EQUAL(26, Long::numberOfTrailingZeros(67108864L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(134217727L));
    ASSERT_EQUAL(27, Long::numberOfTrailingZeros(134217728L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(268435455L));
    ASSERT_EQUAL(28, Long::numberOfTrailingZeros(268435456L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(536870911L));
    ASSERT_EQUAL(29, Long::numberOfTrailingZeros(536870912L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(1073741823L));
    ASSERT_EQUAL(30, Long::numberOfTrailingZeros(1073741824L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(2147483647L));
    ASSERT_EQUAL(31, Long::numberOfTrailingZeros(2147483648L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(4294967295L));
    ASSERT_EQUAL(32, Long::numberOfTrailingZeros(4294967296L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(8589934591L));
    ASSERT_EQUAL(33, Long::numberOfTrailingZeros(8589934592L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(17179869183L));
    ASSERT_EQUAL(34, Long::numberOfTrailingZeros(17179869184L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(34359738367L));
    ASSERT_EQUAL(35, Long::numberOfTrailingZeros(34359738368L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(68719476735L));
    ASSERT_EQUAL(36, Long::numberOfTrailingZeros(68719476736L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(137438953471L));
    ASSERT_EQUAL(37, Long::numberOfTrailingZeros(137438953472L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(274877906943L));
    ASSERT_EQUAL(38, Long::numberOfTrailingZeros(274877906944L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(549755813887L));
    ASSERT_EQUAL(39, Long::numberOfTrailingZeros(549755813888L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(1099511627775L));
    ASSERT_EQUAL(40, Long::numberOfTrailingZeros(1099511627776L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(2199023255551L));
    ASSERT_EQUAL(41, Long::numberOfTrailingZeros(2199023255552L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(4398046511103L));
    ASSERT_EQUAL(42, Long::numberOfTrailingZeros(4398046511104L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(8796093022207L));
    ASSERT_EQUAL(43, Long::numberOfTrailingZeros(8796093022208L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(17592186044415L));
    ASSERT_EQUAL(44, Long::numberOfTrailingZeros(17592186044416L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(35184372088831L));
    ASSERT_EQUAL(45, Long::numberOfTrailingZeros(35184372088832L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(70368744177663L));
    ASSERT_EQUAL(46, Long::numberOfTrailingZeros(70368744177664L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(140737488355327L));
    ASSERT_EQUAL(47, Long::numberOfTrailingZeros(140737488355328L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(281474976710655L));
    ASSERT_EQUAL(48, Long::numberOfTrailingZeros(281474976710656L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(562949953421311L));
    ASSERT_EQUAL(49, Long::numberOfTrailingZeros(562949953421312L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(1125899906842623L));
    ASSERT_EQUAL(50, Long::numberOfTrailingZeros(1125899906842624L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(2251799813685247L));
    ASSERT_EQUAL(51, Long::numberOfTrailingZeros(2251799813685248L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(4503599627370495L));
    ASSERT_EQUAL(52, Long::numberOfTrailingZeros(4503599627370496L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(9007199254740991L));
    ASSERT_EQUAL(53, Long::numberOfTrailingZeros(9007199254740992L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(18014398509481983L));
    ASSERT_EQUAL(54, Long::numberOfTrailingZeros(18014398509481984L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(36028797018963967L));
    ASSERT_EQUAL(55, Long::numberOfTrailingZeros(36028797018963968L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(72057594037927935L));
    ASSERT_EQUAL(56, Long::numberOfTrailingZeros(72057594037927936L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(144115188075855871L));
    ASSERT_EQUAL(57, Long::numberOfTrailingZeros(144115188075855872L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(288230376151711743L));
    ASSERT_EQUAL(58, Long::numberOfTrailingZeros(288230376151711744L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(576460752303423487L));
    ASSERT_EQUAL(59, Long::numberOfTrailingZeros(576460752303423488L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(1152921504606846975L));
    ASSERT_EQUAL(60, Long::numberOfTrailingZeros(1152921504606846976L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(2305843009213693951L));
    ASSERT_EQUAL(61, Long::numberOfTrailingZeros(2305843009213693952L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(4611686018427387903L));
    ASSERT_EQUAL(62, Long::numberOfTrailingZeros(4611686018427387904L));
    ASSERT_EQUAL(0, Long::numberOfTrailingZeros(9223372036854775807L));
    ASSERT_EQUAL(63, Long::numberOfTrailingZeros(9223372036854775808uL));
}

TEST (JavaLang, LongToHexString) {
	// Given valid long value to test toHexString() - this test case was confirm by java source code
	long validValue = 4053239666997989821;
	String result = Long::toHexString(validValue);
	
	String expectedString = "384000008cf011bd";
	ASSERT_STR(expectedString.toString(), result.toString());
	
	validValue = -5603022497796657139;
	result = Long::toHexString(validValue);
	
	expectedString = "b23e10b96e4ef00d";
	ASSERT_STR(expectedString.toString(), result.toString());
}

TEST (JavaLang, LongStaticToString) {
	// Give valid string covert from static function toString of class Long - Should equal
	long longNumber = 999738373833883736;
	string expect = (string) "999738373833883736";
	string result = Long::toString(longNumber);
	ASSERT_STR(expect, result);
}