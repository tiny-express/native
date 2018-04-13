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

#include "../../../Test.hpp"
#include "Long.hpp"

using namespace Java::Lang;

TEST (JavaLangLong, Constructor) {
	// Given empty value for Long constructor and assign value - Return Long
	Long emptyLong;
	emptyLong = 3;
	assertEquals(3, emptyLong.longValue());
	
	// Given value for Integer constructor and assign value - Return string
	Long validLong = 3;
	assertEquals(3, validLong.longValue());
	
	Long test = 3;
	assertEquals(3, test.intValue());
}

TEST (JavaLangLong, BitCount) {
	// Given valid long number to test bit count based on java source code and result
	long validValue = 393459834753422L;
	int result = Long::bitCount(validValue);
	
	int expectedResult = 24;
	assertEquals(expectedResult, result);
	
	validValue = 4547830931350L;
	result = Long::bitCount(validValue);
	
	expectedResult = 25;
	assertEquals(expectedResult, result);
}

TEST (JavaLangLong, ByteValue) {
	// Given valid long value to test byteValue() based on java source code result
	Long validValue = 393239259234023474L;
	int result = validValue.byteValue();
	
	int expectedResult = 50;
	assertEquals(expectedResult, result);
	
	validValue = 200L;
	result = validValue.byteValue();
	
	expectedResult = -56;
	assertEquals(expectedResult, result);
}

TEST (JavaLangLong, Compare) {
	// Given valid long value to test compare()
	long validValue = 79473043431L;
	long lessValue = 7947304343L;
	long equalValue = 79473043431L;
	long moreValue = 794730534312L;
	
	int result = Long::compare(validValue, lessValue);
	int expectedResult = 1;
	assertEquals(expectedResult, result);
	
	result = Long::compare(validValue, equalValue);
	expectedResult = 0;
	assertEquals(expectedResult, result);
	
	result = Long::compare(validValue, moreValue);
	expectedResult = -1;
	assertEquals(expectedResult, result);
}

TEST (JavaLangLong, CompareTo) {
	// Given valid Long value to test compareTo()
	Long validValue = 857503832954L;
	Long lessValue = 23932827534L;
	Long equalValue = 857503832954L;
	Long moreValue = 857503832954222L;
	
	int result = validValue.compareTo(lessValue);
	int expectedValue = 1;
	assertEquals(expectedValue, result);
	
	result = validValue.compareTo(equalValue);
	expectedValue = 0;
	assertEquals(expectedValue, result);
	
	result = validValue.compareTo(moreValue);
	expectedValue = -1;
	assertEquals(expectedValue, result);
}

TEST (JavaLangLong, Comparision) {
	// Give a valid number and make a comparision
	Long validNumber = 123000000000;
	Long targetNumber;
	
	// Test validNumber is equal targetNumber
	targetNumber = 123000000000;
	assertTrue(validNumber == targetNumber);
	
	// Test validNumber is not equal targetNumber
	targetNumber = 113000000000;
	assertTrue(validNumber != targetNumber);
	
	// Test validNumber is less than targetNumber
	targetNumber = 124000000000;
	assertTrue(validNumber < targetNumber);
	
	// Test validNumber is equal or less then targetNumber
	targetNumber = 125000000000;
	assertTrue(validNumber <= targetNumber);
	
	// Test validNumber is more than targetNumber
	targetNumber = 122000000000;
	assertTrue(validNumber > targetNumber);
	
	// Test validNumber is equal or more than targetNumber
	targetNumber = 121000000000;
	assertTrue(validNumber >= targetNumber);
}

TEST (JavaLangLong, Operator) {
	// Given a valid number
	Long validNumber = 5;
	Long targetNumber = 3;
	
	// Make a summation with targetNumber
	Long summationNumber = 8;
	assertTrue(summationNumber == ( validNumber + targetNumber ));
	
	// Make a subtraction with targetNumber
	Long subtractionNumber = 2;
	assertTrue(subtractionNumber == ( validNumber - targetNumber ));
	
	// Make a multiplication with targetNumber
	Long multiplicationNumber = 15;
	assertTrue(multiplicationNumber == ( validNumber * targetNumber ));
	
	// Make a division with targetNumber
	Long divisionNumber = 1;
	assertTrue(divisionNumber == ( validNumber / targetNumber ));
	
	// Make a modulo with targetNumber
	Long modNumber = 2;
	assertTrue(modNumber == ( validNumber % targetNumber ));
}

TEST (JavaLangLong, ParseLong) {
	// Given value for Long constructor and assign value - Return long
	Long validLong = Long::parseLong("6");
	long expectedResult = 6;
	assertEquals(expectedResult, validLong.longValue());
	
	// Given valid string to test parseLong with radix 16
	String validNumberString = "1b";
	Long result = Long::parseLong(validNumberString, 16);
	
	expectedResult = 27;
	assertEquals(expectedResult, result.longValue());
	
	String invalidNumbeString = "122q3";
	result = Long::parseLong(invalidNumbeString, 16);
	
	expectedResult = -1;
	assertEquals(expectedResult, result.longValue());
}

TEST (JavaLangLong, Equals) {
	// Given valid Long value to test equals()
	Long validValue = 1231372934234234L;
	Long anotherValue = 2434234234234L;
	
	assertTrue(validValue.equals(validValue));
	
	assertFalse(validValue.equals(anotherValue));
}

TEST (JavaLangLong, GetLong) {
	// Given valid hexString and decimalString to test getLong through those String
	// The result is based on java code result
	String hexString = "0x23";
	String decimalString = "123";
	
	Long result = Long::getLong(hexString);
	long expectedResult = 35;
	assertEquals(expectedResult, result.longValue());
	
	result = Long::getLong(decimalString);
	expectedResult = 123;
	assertEquals(expectedResult, result.longValue());
}

TEST (JavaLangLong, Decode) {
	// Given valid numberString to test decode value
	String validNumberString = "0x1b";
	Long result = Long::decode(validNumberString);
	
	long expectedResult = 27;
	assertEquals(expectedResult, result.longValue());
	
	String invalidNumberString = "0x23xx";
	result = Long::decode(invalidNumberString);
	
	expectedResult = -1;
	assertEquals(expectedResult, result.longValue());
}

TEST (JavaLangLong, NumberOfLeadingZeros) {
    assertEquals(0, Long::numberOfLeadingZeros(-1L));
    assertEquals(33, Long::numberOfLeadingZeros(1234567890L));

    assertEquals(64, Long::numberOfLeadingZeros(0L));
    assertEquals(63, Long::numberOfLeadingZeros(1L));
    assertEquals(62, Long::numberOfLeadingZeros(2L));
    assertEquals(61, Long::numberOfLeadingZeros(4L));
    assertEquals(60, Long::numberOfLeadingZeros(8L));
    assertEquals(59, Long::numberOfLeadingZeros(16L));
    assertEquals(58, Long::numberOfLeadingZeros(32L));
    assertEquals(57, Long::numberOfLeadingZeros(64L));
    assertEquals(56, Long::numberOfLeadingZeros(128L));
    assertEquals(55, Long::numberOfLeadingZeros(256L));
    assertEquals(54, Long::numberOfLeadingZeros(512L));
    assertEquals(53, Long::numberOfLeadingZeros(1024L));
    assertEquals(52, Long::numberOfLeadingZeros(2048L));
    assertEquals(51, Long::numberOfLeadingZeros(4096L));
    assertEquals(50, Long::numberOfLeadingZeros(8192L));
    assertEquals(49, Long::numberOfLeadingZeros(16384L));
    assertEquals(48, Long::numberOfLeadingZeros(32768L));
    assertEquals(47, Long::numberOfLeadingZeros(65536L));
    assertEquals(46, Long::numberOfLeadingZeros(131072L));
    assertEquals(45, Long::numberOfLeadingZeros(262144L));
    assertEquals(44, Long::numberOfLeadingZeros(524288L));
    assertEquals(43, Long::numberOfLeadingZeros(1048576L));
    assertEquals(42, Long::numberOfLeadingZeros(2097152L));
    assertEquals(41, Long::numberOfLeadingZeros(4194304L));
    assertEquals(40, Long::numberOfLeadingZeros(8388608L));
    assertEquals(39, Long::numberOfLeadingZeros(16777216L));
    assertEquals(38, Long::numberOfLeadingZeros(33554432L));
    assertEquals(37, Long::numberOfLeadingZeros(67108864L));
    assertEquals(36, Long::numberOfLeadingZeros(134217728L));
    assertEquals(35, Long::numberOfLeadingZeros(268435456L));
    assertEquals(34, Long::numberOfLeadingZeros(536870912L));
    assertEquals(33, Long::numberOfLeadingZeros(1073741824L));
    assertEquals(32, Long::numberOfLeadingZeros(2147483648L));
    assertEquals(31, Long::numberOfLeadingZeros(4294967296L));
    assertEquals(30, Long::numberOfLeadingZeros(8589934592L));
    assertEquals(29, Long::numberOfLeadingZeros(17179869184L));
    assertEquals(28, Long::numberOfLeadingZeros(34359738368L));
    assertEquals(27, Long::numberOfLeadingZeros(68719476736L));
    assertEquals(26, Long::numberOfLeadingZeros(137438953472L));
    assertEquals(25, Long::numberOfLeadingZeros(274877906944L));
    assertEquals(24, Long::numberOfLeadingZeros(549755813888L));
    assertEquals(23, Long::numberOfLeadingZeros(1099511627776L));
    assertEquals(22, Long::numberOfLeadingZeros(2199023255552L));
    assertEquals(21, Long::numberOfLeadingZeros(4398046511104L));
    assertEquals(20, Long::numberOfLeadingZeros(8796093022208L));
    assertEquals(19, Long::numberOfLeadingZeros(17592186044416L));
    assertEquals(18, Long::numberOfLeadingZeros(35184372088832L));
    assertEquals(17, Long::numberOfLeadingZeros(70368744177664L));
    assertEquals(16, Long::numberOfLeadingZeros(140737488355328L));
    assertEquals(15, Long::numberOfLeadingZeros(281474976710656L));
    assertEquals(14, Long::numberOfLeadingZeros(562949953421312L));
    assertEquals(13, Long::numberOfLeadingZeros(1125899906842624L));
    assertEquals(12, Long::numberOfLeadingZeros(2251799813685248L));
    assertEquals(11, Long::numberOfLeadingZeros(4503599627370496L));
    assertEquals(10, Long::numberOfLeadingZeros(9007199254740992L));
    assertEquals(9, Long::numberOfLeadingZeros(18014398509481984L));
    assertEquals(8, Long::numberOfLeadingZeros(36028797018963968L));
    assertEquals(7, Long::numberOfLeadingZeros(72057594037927936L));
    assertEquals(6, Long::numberOfLeadingZeros(144115188075855872L));
    assertEquals(5, Long::numberOfLeadingZeros(288230376151711744L));
    assertEquals(4, Long::numberOfLeadingZeros(576460752303423488L));
    assertEquals(3, Long::numberOfLeadingZeros(1152921504606846976L));
    assertEquals(2, Long::numberOfLeadingZeros(2305843009213693952L));
    assertEquals(1, Long::numberOfLeadingZeros(4611686018427387904L));
    assertEquals(0, Long::numberOfLeadingZeros(9223372036854775808uL));
}

TEST(JavaLangLong, NumberOfTrailingZeros) {
    assertEquals(0, Long::numberOfTrailingZeros(-1L));
    assertEquals(2, Long::numberOfTrailingZeros(100L));

    assertEquals(64, Long::numberOfTrailingZeros(0L));
    assertEquals(0, Long::numberOfTrailingZeros(1L));
    assertEquals(1, Long::numberOfTrailingZeros(2L));
    assertEquals(0, Long::numberOfTrailingZeros(3L));
    assertEquals(2, Long::numberOfTrailingZeros(4L));
    assertEquals(0, Long::numberOfTrailingZeros(7L));
    assertEquals(3, Long::numberOfTrailingZeros(8L));
    assertEquals(0, Long::numberOfTrailingZeros(15L));
    assertEquals(4, Long::numberOfTrailingZeros(16L));
    assertEquals(0, Long::numberOfTrailingZeros(31L));
    assertEquals(5, Long::numberOfTrailingZeros(32L));
    assertEquals(0, Long::numberOfTrailingZeros(63L));
    assertEquals(6, Long::numberOfTrailingZeros(64L));
    assertEquals(0, Long::numberOfTrailingZeros(127L));
    assertEquals(7, Long::numberOfTrailingZeros(128L));
    assertEquals(0, Long::numberOfTrailingZeros(255L));
    assertEquals(8, Long::numberOfTrailingZeros(256L));
    assertEquals(0, Long::numberOfTrailingZeros(511L));
    assertEquals(9, Long::numberOfTrailingZeros(512L));
    assertEquals(0, Long::numberOfTrailingZeros(1023L));
    assertEquals(10, Long::numberOfTrailingZeros(1024L));
    assertEquals(0, Long::numberOfTrailingZeros(2047L));
    assertEquals(11, Long::numberOfTrailingZeros(2048L));
    assertEquals(0, Long::numberOfTrailingZeros(4095L));
    assertEquals(12, Long::numberOfTrailingZeros(4096L));
    assertEquals(0, Long::numberOfTrailingZeros(8191L));
    assertEquals(13, Long::numberOfTrailingZeros(8192L));
    assertEquals(0, Long::numberOfTrailingZeros(16383L));
    assertEquals(14, Long::numberOfTrailingZeros(16384L));
    assertEquals(0, Long::numberOfTrailingZeros(32767L));
    assertEquals(15, Long::numberOfTrailingZeros(32768L));
    assertEquals(0, Long::numberOfTrailingZeros(65535L));
    assertEquals(16, Long::numberOfTrailingZeros(65536L));
    assertEquals(0, Long::numberOfTrailingZeros(131071L));
    assertEquals(17, Long::numberOfTrailingZeros(131072L));
    assertEquals(0, Long::numberOfTrailingZeros(262143L));
    assertEquals(18, Long::numberOfTrailingZeros(262144L));
    assertEquals(0, Long::numberOfTrailingZeros(524287L));
    assertEquals(19, Long::numberOfTrailingZeros(524288L));
    assertEquals(0, Long::numberOfTrailingZeros(1048575L));
    assertEquals(20, Long::numberOfTrailingZeros(1048576L));
    assertEquals(0, Long::numberOfTrailingZeros(2097151L));
    assertEquals(21, Long::numberOfTrailingZeros(2097152L));
    assertEquals(0, Long::numberOfTrailingZeros(4194303L));
    assertEquals(22, Long::numberOfTrailingZeros(4194304L));
    assertEquals(0, Long::numberOfTrailingZeros(8388607L));
    assertEquals(23, Long::numberOfTrailingZeros(8388608L));
    assertEquals(0, Long::numberOfTrailingZeros(16777215L));
    assertEquals(24, Long::numberOfTrailingZeros(16777216L));
    assertEquals(0, Long::numberOfTrailingZeros(33554431L));
    assertEquals(25, Long::numberOfTrailingZeros(33554432L));
    assertEquals(0, Long::numberOfTrailingZeros(67108863L));
    assertEquals(26, Long::numberOfTrailingZeros(67108864L));
    assertEquals(0, Long::numberOfTrailingZeros(134217727L));
    assertEquals(27, Long::numberOfTrailingZeros(134217728L));
    assertEquals(0, Long::numberOfTrailingZeros(268435455L));
    assertEquals(28, Long::numberOfTrailingZeros(268435456L));
    assertEquals(0, Long::numberOfTrailingZeros(536870911L));
    assertEquals(29, Long::numberOfTrailingZeros(536870912L));
    assertEquals(0, Long::numberOfTrailingZeros(1073741823L));
    assertEquals(30, Long::numberOfTrailingZeros(1073741824L));
    assertEquals(0, Long::numberOfTrailingZeros(2147483647L));
    assertEquals(31, Long::numberOfTrailingZeros(2147483648L));
    assertEquals(0, Long::numberOfTrailingZeros(4294967295L));
    assertEquals(32, Long::numberOfTrailingZeros(4294967296L));
    assertEquals(0, Long::numberOfTrailingZeros(8589934591L));
    assertEquals(33, Long::numberOfTrailingZeros(8589934592L));
    assertEquals(0, Long::numberOfTrailingZeros(17179869183L));
    assertEquals(34, Long::numberOfTrailingZeros(17179869184L));
    assertEquals(0, Long::numberOfTrailingZeros(34359738367L));
    assertEquals(35, Long::numberOfTrailingZeros(34359738368L));
    assertEquals(0, Long::numberOfTrailingZeros(68719476735L));
    assertEquals(36, Long::numberOfTrailingZeros(68719476736L));
    assertEquals(0, Long::numberOfTrailingZeros(137438953471L));
    assertEquals(37, Long::numberOfTrailingZeros(137438953472L));
    assertEquals(0, Long::numberOfTrailingZeros(274877906943L));
    assertEquals(38, Long::numberOfTrailingZeros(274877906944L));
    assertEquals(0, Long::numberOfTrailingZeros(549755813887L));
    assertEquals(39, Long::numberOfTrailingZeros(549755813888L));
    assertEquals(0, Long::numberOfTrailingZeros(1099511627775L));
    assertEquals(40, Long::numberOfTrailingZeros(1099511627776L));
    assertEquals(0, Long::numberOfTrailingZeros(2199023255551L));
    assertEquals(41, Long::numberOfTrailingZeros(2199023255552L));
    assertEquals(0, Long::numberOfTrailingZeros(4398046511103L));
    assertEquals(42, Long::numberOfTrailingZeros(4398046511104L));
    assertEquals(0, Long::numberOfTrailingZeros(8796093022207L));
    assertEquals(43, Long::numberOfTrailingZeros(8796093022208L));
    assertEquals(0, Long::numberOfTrailingZeros(17592186044415L));
    assertEquals(44, Long::numberOfTrailingZeros(17592186044416L));
    assertEquals(0, Long::numberOfTrailingZeros(35184372088831L));
    assertEquals(45, Long::numberOfTrailingZeros(35184372088832L));
    assertEquals(0, Long::numberOfTrailingZeros(70368744177663L));
    assertEquals(46, Long::numberOfTrailingZeros(70368744177664L));
    assertEquals(0, Long::numberOfTrailingZeros(140737488355327L));
    assertEquals(47, Long::numberOfTrailingZeros(140737488355328L));
    assertEquals(0, Long::numberOfTrailingZeros(281474976710655L));
    assertEquals(48, Long::numberOfTrailingZeros(281474976710656L));
    assertEquals(0, Long::numberOfTrailingZeros(562949953421311L));
    assertEquals(49, Long::numberOfTrailingZeros(562949953421312L));
    assertEquals(0, Long::numberOfTrailingZeros(1125899906842623L));
    assertEquals(50, Long::numberOfTrailingZeros(1125899906842624L));
    assertEquals(0, Long::numberOfTrailingZeros(2251799813685247L));
    assertEquals(51, Long::numberOfTrailingZeros(2251799813685248L));
    assertEquals(0, Long::numberOfTrailingZeros(4503599627370495L));
    assertEquals(52, Long::numberOfTrailingZeros(4503599627370496L));
    assertEquals(0, Long::numberOfTrailingZeros(9007199254740991L));
    assertEquals(53, Long::numberOfTrailingZeros(9007199254740992L));
    assertEquals(0, Long::numberOfTrailingZeros(18014398509481983L));
    assertEquals(54, Long::numberOfTrailingZeros(18014398509481984L));
    assertEquals(0, Long::numberOfTrailingZeros(36028797018963967L));
    assertEquals(55, Long::numberOfTrailingZeros(36028797018963968L));
    assertEquals(0, Long::numberOfTrailingZeros(72057594037927935L));
    assertEquals(56, Long::numberOfTrailingZeros(72057594037927936L));
    assertEquals(0, Long::numberOfTrailingZeros(144115188075855871L));
    assertEquals(57, Long::numberOfTrailingZeros(144115188075855872L));
    assertEquals(0, Long::numberOfTrailingZeros(288230376151711743L));
    assertEquals(58, Long::numberOfTrailingZeros(288230376151711744L));
    assertEquals(0, Long::numberOfTrailingZeros(576460752303423487L));
    assertEquals(59, Long::numberOfTrailingZeros(576460752303423488L));
    assertEquals(0, Long::numberOfTrailingZeros(1152921504606846975L));
    assertEquals(60, Long::numberOfTrailingZeros(1152921504606846976L));
    assertEquals(0, Long::numberOfTrailingZeros(2305843009213693951L));
    assertEquals(61, Long::numberOfTrailingZeros(2305843009213693952L));
    assertEquals(0, Long::numberOfTrailingZeros(4611686018427387903L));
    assertEquals(62, Long::numberOfTrailingZeros(4611686018427387904L));
    assertEquals(0, Long::numberOfTrailingZeros(9223372036854775807L));
    assertEquals(63, Long::numberOfTrailingZeros(9223372036854775808uL));
}

TEST (JavaLangLong, ToHexString) {
	// Given valid long value to test toHexString() - this test case was confirm by java source code
	long validValue = 4053239666997989821;
	String result = Long::toHexString(validValue);
	
	String expectedString = "384000008cf011bd";
	assertEquals(expectedString.toString(), result.toString());
	
	validValue = -5603022497796657139;
	result = Long::toHexString(validValue);
	
	expectedString = "b23e10b96e4ef00d";
	assertEquals(expectedString.toString(), result.toString());
}

TEST (JavaLangLong, StaticToString) {
	// Give valid string covert from static function toString of class Long - Should equal
	long longNumber = 999738373833883736;
	String expect = "999738373833883736";
	String result = Long::toString(longNumber);
	assertEquals(expect, result);
}