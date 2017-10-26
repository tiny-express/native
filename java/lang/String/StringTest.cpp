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
#include "../StringIndexOutOfBoundsException/StringIndexOutOfBoundsException.hpp"
#include "../StringBuilder/StringBuilder.hpp"
#include "../StringBuffer/StringBuffer.hpp"
#include "../IllegalArgumentException/IllegalArgumentException.hpp"
#include "../../util/ArrayList/ArrayList.hpp"

using namespace Java::Lang;
using namespace Java::Util;

TEST (JavaLangString, Constructor) {
	// Give NULL for String constructor
	String nullString;
	assertEquals("", nullString.toString().toCharPointer());
	
	// Given value for String constructor and assign value - Return string
	String simpleStringConstructor = (string) "Hello world";
	assertEquals("Hello world", simpleStringConstructor.toString());
	
	// Given empty value for String constructor and assign value - Return string
	String stringConstructor = simpleStringConstructor;
	assertEquals("Hello world", stringConstructor.toString());
	
	// Given constant string value for String constructor
	String stringConstStringConstructor("Hello world");
	assertEquals("Hello world", stringConstructor.toString());
	
	// Given String value for String constructor
	String objectString = "Hello world";
	String stringStringConstructor = objectString;
	assertEquals("Hello world", stringConstructor.toString());
	
	// Given constant string for String constructor - Return string
	String normalString = "Hello world";
	assertEquals("Hello world", normalString.toString());
	
	// Given a char Array
	Array<char> charArray = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd' };
	
	String arrayConstructor(charArray);
	assertEquals("Hello world", arrayConstructor.toString());
	assertEquals(charArray.length, arrayConstructor.length());
	
	String subArrayConstructor(charArray, 6, 5);
	assertEquals("world", subArrayConstructor.toString());
	assertEquals(5, subArrayConstructor.length());
	
	try {
		String exceptionConstructor(charArray, -1, 5);
	} catch (StringIndexOutOfBoundsException &e) {
		assertEquals("String index out of range: -1",
		             e.getMessage().toString());
	}
	
	try {
		String exceptionConstructor(charArray, 5, -1);
	} catch (StringIndexOutOfBoundsException &e) {
		assertEquals("String index out of range: -1",
		             e.getMessage().toString());
	}
	
	try {
		String exceptionConstructor(charArray, 10, 5);
	} catch (StringIndexOutOfBoundsException &e) {
		assertEquals("String index out of range: 15",
		             e.getMessage().toString());
	}
	
	// Given a byte Array
	Array<byte> byteArray = { 72, 101, 108, 108, 111, 32, 119, 111, 114, 108, 100 };
	assertEquals("Hello world", arrayConstructor.toString());
	assertEquals(charArray.length, arrayConstructor.length());
	
	String subByteArrayConstructor(byteArray, 6, 5);
	assertEquals("world", subByteArrayConstructor.toString());
	assertEquals(5, subByteArrayConstructor.length());
	
	try {
		String exceptionConstructor(byteArray, -1, 5);
	} catch (StringIndexOutOfBoundsException &e) {
		assertEquals("String index out of range: -1",
		             e.getMessage().toString());
	}
	
	try {
		String exceptionConstructor(byteArray, 5, -1);
	} catch (StringIndexOutOfBoundsException &e) {
		assertEquals("String index out of range: -1",
		             e.getMessage().toString());
	}
	
	try {
		String exceptionConstructor(byteArray, 10, 5);
	} catch (StringIndexOutOfBoundsException &e) {
		assertEquals("String index out of range: 15",
		             e.getMessage().toString());
	}
}

TEST (JavaLangString, Destructor) {
	// Given data type declaration - Destructor will be called by system
	String text = "";
	
	// Given memory allocation for textPointer - Cleanup memory success
	auto textPointer = new String("Hello");
	delete textPointer;
}

TEST (JavaLangString, Equals) {
	// Given two String objects with same value - Return they should equal
	String stringEqual1 = "Hello World";
	String stringEqual2 = "Hello World";
	assertTrue(instanceof<String>(stringEqual1));
	assertTrue(stringEqual1.equals(stringEqual2));
	assertTrue(stringEqual1 == stringEqual2);
	
	// Compare with another String object - Return they are not equal
	String stringEqual3 = "Food Tiny";
	assertTrue(!stringEqual1.equals(stringEqual3));
	assertTrue(stringEqual1 != stringEqual3);
}

TEST (JavaLangString, CharAt) {
	// Given a string - Return first position is exist
	String text = "Hello World";
	char positionIsExist = text.charAt(0);
	
	assertEquals('H', positionIsExist);
	
	// Given a string - Return negative position is not exist
	try {
		char negativePositionIsNotExist = text.charAt(-1);
	} catch (StringIndexOutOfBoundsException &exception) {
		assertEquals("String index out of range",
		             exception.getMessage().toString());
	}
	
	// Given a string - Return out of scope position is not exist
	try {
		char outOfScopePositionIsNotExist = text.charAt(1000);
	} catch (StringIndexOutOfBoundsException &exception) {
		assertEquals("String index out of range",
		             exception.getMessage().toString());
	}
}

TEST (JavaLangString, CompareTo) {
	String smallerString = "ABCDEF";
	String greaterString = "abcdef";
	String equalToGreater = "abcdef";
	
	int compareResult = greaterString.compareTo(smallerString);
	assertTrue(compareResult > 0);
	
	compareResult = greaterString.compareTo(equalToGreater);
	assertTrue(compareResult == 0);
	
	compareResult = smallerString.compareTo(greaterString);
	assertTrue(compareResult < 0);
	
	Comparable<String> *comparable = &greaterString;
	compareResult = comparable->compareTo(smallerString);
	assertTrue(compareResult > 0);
}

TEST (JavaLangString, CompareToIgnoreCase) {
	String smallerString = "because";
	String greaterString = "hello";
	String greaterUpperCase = "HELLO";
	
	int compareResult = greaterString.compareToIgnoreCase(smallerString);
	assertTrue(compareResult > 0);
	
	compareResult = greaterString.compareToIgnoreCase(greaterUpperCase);
	assertTrue(compareResult == 0);
	
	compareResult = smallerString.compareToIgnoreCase(greaterString);
	assertTrue(compareResult < 0);
}

TEST (JavaLangString, Concat) {
	// Given three strings - Return concatenation result
	String textConcat0 = "Food Tiny ";
	String textConcat1 = "Hello ";
	String textConcat2 = "World";
	String concatenationResult = textConcat0 + textConcat1 + textConcat2;
	assertEquals("Food Tiny Hello World", concatenationResult.toString());
	
	// Given two strings - Return concatenation result
	concatenationResult = textConcat1.concat(textConcat2);
	assertEquals("Hello World", concatenationResult.toString());
}

TEST (JavaLangString, Contains) {
	// Gives a valid string a sub string to find
	String validString = "a valid string to test";
	String subString = "valid string";
	String invalidSubString = "text";
	
	// Test true with correct substring inside
	assertTrue(validString.contains(subString));
	// Test with with invalid substring inside
	assertFalse(validString.contains(invalidSubString));
}

TEST (JavaLangString, ContentEqual) {
	String string = String("Hello world");
	CharSequence *charSequence = new StringBuffer("Hello world");
	assertTrue(string.contentEquals(*charSequence));
	auto stringBuffer = dynamic_cast<StringBuffer *>(charSequence);
	delete stringBuffer;
	
	String stringEqual = String("Hello world");
	assertTrue(string.contentEquals(stringEqual));
	
	String stringNotEqual = String("hello");
	assertFalse(string.contentEquals(stringNotEqual));
}

TEST (JavaLangString, CopyValueOf) {
	// Given a char Array
	Array<char> charArray = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd' };
	String copyArrayString = String::copyValueOf(charArray);
	assertEquals("Hello world", copyArrayString.toString());
	assertEquals(charArray.length, copyArrayString.length());
	
	String copySubArrayString = String::copyValueOf(charArray, 6, 5);
	assertEquals("world", copySubArrayString.toString());
	assertEquals(5, copySubArrayString.length());
	
	try {
		String exceptionString = String::copyValueOf(charArray, -1, 5);
	} catch (StringIndexOutOfBoundsException &e) {
		assertEquals("String index out of range: -1",
		             e.getMessage().toString());
	}
	
	try {
		String exceptionString = String::copyValueOf(charArray, 5, -1);
	} catch (StringIndexOutOfBoundsException &e) {
		assertEquals("String index out of range: -1",
		             e.getMessage().toString());
	}
	
	try {
		String exceptionString = String::copyValueOf(charArray, 10, 5);
	} catch (StringIndexOutOfBoundsException &e) {
		assertEquals("String index out of range: 15",
		             e.getMessage().toString());
	}
}

// FIXME
TEST (JavaLangString, EndsWith) {
	String textPlus = "Hello welcome to VietNam";
	String String_string = "VietNam";
	assertTrue(textPlus.endsWith(String_string));
}

TEST (JavaLangString, EqualIgnoreCase) {
	String smallerString = "because";
	String greaterString = "hello";
	String greaterUpperCase = "HELLO";
	
	assertFalse(greaterString.equalsIgnoreCase(smallerString));
	assertTrue(greaterString.equalsIgnoreCase(greaterUpperCase));
	assertFalse(smallerString.equalsIgnoreCase(greaterString));
}

TEST (JavaLangString, GetBytes) {
	String text = "Sample Text";
	Array<byte> bytes = text.getBytes();
	assertEquals(11, bytes.length);
}

TEST (JavaLangString, GetStringFromIndex) {
	String aString = "Hello Hello Hello";
	String result = aString.getStringFromIndex(6);
	assertEquals("Hello Hello", result.toString());
	
	try {
		result = aString.getStringFromIndex(-1);
	} catch (StringIndexOutOfBoundsException &e) {
		assertEquals("String index out of range: -1",
		             e.getMessage().toString());
	}
	
	try {
		result = aString.getStringFromIndex(20);
	} catch (StringIndexOutOfBoundsException &e) {
		assertEquals("String index out of range: 20",
		             e.getMessage().toString());
	}
}

TEST (JavaLangString, IndexOf) {
	String textPlus = "Hello Hello Hello ";
	
	int result = textPlus.indexOf('H');
	assertEquals(0, result);
	
	result = textPlus.indexOf('k');
	assertEquals(-1, result);
	
	result = textPlus.indexOf('k');
	assertEquals(-1, result);
	
	result = textPlus.indexOf('l', 4);
	assertEquals(8, result);
	
	result = textPlus.indexOf('k', 4);
	assertEquals(-1, result);
	
	result = textPlus.indexOf('l', -1);
	assertEquals(2, result);
	
	result = textPlus.indexOf('l', 100);
	assertEquals(-1, result);
	
	result = textPlus.indexOf("llo");
	assertEquals(2, result);
	
	result = textPlus.indexOf("llo", 4);
	assertEquals(8, result);
	
	result = textPlus.indexOf("llok");
	assertEquals(-1, result);
	
	result = textPlus.indexOf("llo", -1);
	assertEquals(2, result);
	
	result = textPlus.indexOf("llo", 100);
	assertEquals(-1, result);
	
	result = textPlus.indexOf("lli", 10);
	assertEquals(-1, result);
}

TEST (JavaLangString, LastIndexOf) {
	// Given validString check lastIndexOf(string)
	String textPlus = "Hello Hello Hello ";
	String validString = "awesome keyword inside this awesome string";
	String subString = "awesome";
	String wrongString = "some thing";
	
	int result = textPlus.lastIndexOf('H');
	assertEquals(12, result);
	
	result = textPlus.lastIndexOf('a');
	assertEquals(-1, result);
	
	result = textPlus.lastIndexOf('H', 2);
	assertEquals(0, result);
	
	result = textPlus.lastIndexOf('H', 100);
	assertEquals(12, result);
	
	result = textPlus.lastIndexOf('H', -1);
	assertEquals(-1, result);
	
	result = textPlus.lastIndexOf('a', 10);
	assertEquals(-1, result);
	
	// Test true first character of subString appear last in validString is position 28th
	result = validString.lastIndexOf(subString);
	assertEquals(28, result);
	
	// Test false with wrong subString
	result = validString.lastIndexOf(wrongString);
	assertEquals(NOT_FOUND, result);
	
	// Given validString2 check lastIndexOf(string, fromIndex)
	String validString2 = "sometimes you win, sometimes you learn";
	String subString2 = "sometimes";
	String wrongString2 = "abc xyz";
	
	// Test true by 19th, with correct subString2 and correct fromIndex to find
	result = validString2.lastIndexOf(subString2, 19);
	assertEquals(19, result);
	
	result = validString2.lastIndexOf(subString2, 18);
	assertEquals(0, result);
	
	result = validString2.lastIndexOf(subString2, 0);
	assertEquals(0, result);
	
	result = validString2.lastIndexOf(subString2, 1);
	assertEquals(0, result);
	
	result = validString2.lastIndexOf(subString2, 100);
	assertEquals(19, result);
	
	result = validString2.lastIndexOf(subString2, -1);
	assertEquals(-1, result);
	
	result = validString2.lastIndexOf(subString2, 20);
	assertEquals(19, result);
	
	result = validString2.lastIndexOf(wrongString2, 20);
	assertEquals(-1, result);
}

// TODO (anhnt) getChar run right but need Arrays.toString() to test
TEST (JavaLangString, GetChars) {
	Array<char> charArray(30);
	String testString = "This is a String";
	testString.getChars(10, 16, charArray, 0);
	string charArrayString = charArray.toCharPointer();
	assertEquals("String", charArrayString);
	
	try {
		testString.getChars(-1, 16, charArray, 0);
	} catch (StringIndexOutOfBoundsException &e) {
		assertEquals("String index out of range: -1",
		             e.getMessage().toString());
	}
	
	try {
		testString.getChars(10, 5, charArray, 0);
	} catch (StringIndexOutOfBoundsException &e) {
		assertEquals("String index out of range: -5",
		             e.getMessage().toString());
	}
	
	try {
		testString.getChars(10, 50, charArray, 0);
	} catch (StringIndexOutOfBoundsException &e) {
		assertEquals("String index out of range: 50",
		             e.getMessage().toString());
	}
	
	try {
		testString.getChars(10, 16, charArray, -1);
	} catch (StringIndexOutOfBoundsException &e) {
		assertEquals("String index out of range: -1",
		             e.getMessage().toString());
	}
	
	try {
		testString.getChars(10, 16, charArray, 29);
	} catch (StringIndexOutOfBoundsException &e) {
		assertEquals("String index out of range: 35",
		             e.getMessage().toString());
	}
	
	testString.getChars(10, 16, charArray, 10);
	charArrayString = charArray.toCharPointer();
	assertEquals("StringString", charArrayString);
	
	testString.getChars(10, 16, charArray, 3);
	charArrayString = charArray.toCharPointer();
	assertEquals("StrStringString", charArrayString);
}

TEST (JavaLangString, IsEmpty) {
	String textPlus = "Hello Hello Hello ";
	assertTrue(!textPlus.isEmpty());
	
	textPlus = "";
	assertTrue(textPlus.isEmpty());
}

TEST (JavaLangString, Length) {
	String textPlus = "Hello Hello Hello ";
	
	assertEquals(18, textPlus.length());
	
	textPlus = "";
	assertEquals(0, textPlus.length());
}

TEST (JavaLangString, HashCode) {
	String string = "Hello world";
	assertEquals(-832992604, string.hashCode());
}

TEST (JavaLangString, RegionMatch) {
	String string1 = "Collection of tutorials";
	String string2 = "Consists of different tutorials";
	String string3 = "CONSISTS OF DIFFERENT TUTORIALS";
	
	// Case considering
	boolean match = string1.regionMatches(14, string2, 22, 9);
	assertTrue(match);
	
	match = string1.regionMatches(14, string2, 20, 9);
	assertFalse(match);
	
	match = string1.regionMatches(14, string3, 22, 9);
	assertFalse(match);
	
	// Ignore case
	match = string1.regionMatches(true, 14, string2, 22, 9);
	assertTrue(match);
	
	match = string1.regionMatches(true, 14, string2, 20, 9);
	assertFalse(match);
	
	match = string1.regionMatches(true, 14, string3, 22, 9);
	assertTrue(match);
	
	match = string1.regionMatches(false, 14, string3, 22, 9);
	assertFalse(match);
	
	match = string1.regionMatches(true, -1, string2, 22, 9);
	assertFalse(match);
	
	match = string1.regionMatches(true, 14, string2, -1, 9);
	assertFalse(match);
	
	match = string1.regionMatches(true, 14, string2, 22, 100);
	assertTrue(match);
	
	match = string1.regionMatches(true, 14, string2, 100, 9);
	assertFalse(match);
}

TEST (JavaLangString, Join) {
	String delimiter = "->";
	String duck1 = "Duck1";
	String test1 = "test1";
	String result1 = String::join(delimiter, duck1, test1);
	assertEquals("Duck1->test1", result1.toString());
	
	String duck2 = "Duck2";
	String result2 = String::join(delimiter, duck2);
	assertEquals("Duck2", result2.toString());
}

/** This test case is made based on pattern_test.c */
// TEST(JavaLangString, Matches) {
// 	    // Init params for test string matches
// 	String emailPattern = EMAIL_PATTERN;
// 	String phoneNumberPattern = PHONE_PATTERN;
//
// 	    // Test true with correct email format
// 	String correctEmail = "neacao@gmail.com";
// 	assertTrue(correctEmail.matches(emailPattern));
//
// 	    // Test fail with wrong email format
// 	String wrongEmail = "something@notcorrect";
// 	assertFalse(wrongEmail.matches(emailPattern));
//
// 	    // Test true with correct phone number format
// 	String correctPhoneNumber = "+15005550006";
// 	assertTrue(correctPhoneNumber.matches(phoneNumberPattern));
//
// 	    // Test fail with wrong email format
// 	String wrongPhoneNumber = "001678080147";
// 	assertFalse(wrongPhoneNumber.matches(phoneNumberPattern));
// }
//
TEST (JavaLangString, Replace) {
	String textPlus = "Hello Hello Hello ";
	
	String result = textPlus.replace('e', 'i');
	assertEquals("Hillo Hillo Hillo ", result.toString());
	
	String target = "llo";
	String replacement = "llu";
	result = textPlus.replace(target, replacement);
	assertEquals("Hellu Hellu Hellu ", result.toString());
	
	target = "Hello";
	replacement = "Phuoc";
	result = textPlus.replaceAll(target, replacement);
	assertEquals("Phuoc Phuoc Phuoc ", result.toString());
	
	result = textPlus.replaceFirst(target, replacement);
	assertEquals("Phuoc Hello Hello ", result.toString());
}

TEST (JavaLangString, Split) {
	// Give an Array<String> then asert each element - Should equal
	String stringToSplit = "Hello Hello Hello Hello";
	Array<String> strings = stringToSplit.split(" ");
	for (String item : strings) {
		assertEquals("Hello", item.toString());
	}
	
	Array<String> splitWithLimit1 = stringToSplit.split(" ", 3);
	int index;
	for (index = 0; index < splitWithLimit1.length - 1; index++) {
		assertEquals("Hello", splitWithLimit1[ index ].toString());
	}
	assertEquals("Hello Hello",
	             splitWithLimit1[ splitWithLimit1.length - 1 ].toString());
	
	// Split with limit greater than number of regex occurrence time
	Array<String> splitWithLimit2 = stringToSplit.split(" ", 10);
	for (index = 0; index < splitWithLimit2.length - 1; index++) {
		assertEquals("Hello", splitWithLimit2[ index ].toString());
	}
	
	Array<String> splitWithLimitOne = stringToSplit.split(" ", 1);
	assertEquals(stringToSplit.toString(), splitWithLimitOne[ 0 ].toString());
	
	Array<String> splitWithLimitZero = stringToSplit.split(" ", 0);
	for (index = 0; index < splitWithLimitZero.length - 1; index++) {
		assertEquals("Hello", splitWithLimitZero[ index ].toString());
	}
	
	Array<String> splitWithLimitNegative = stringToSplit.split(" ", -1);
	for (index = 0; index < splitWithLimitNegative.length - 1; index++) {
		assertEquals("Hello", splitWithLimitNegative[ index ].toString());
	}
}

TEST (JavaLangString, StartsWith) {
	String textPlus;
	// textPlus == ""
	assertFalse(textPlus.startsWith(String("abc"), 10));
	
	textPlus = "Hello Hello Hello ";
	// prefix == ""
	String nullString;
	assertTrue(textPlus.startsWith(nullString, 10));
	
	// thisOffset < 0
	assertFalse(textPlus.startsWith(String("Hello"), -1));
	
	// textPlus.length < prefix.length
	assertFalse(textPlus.startsWith(String("Hello Hello Hello H")));
	
	// thisOffset > (textPlus.length - prefix.length)
	assertFalse(( textPlus.startsWith(String("Hello"), 20)));
	
	// valid case
	assertTrue(textPlus.startsWith(String(""), 7));
	
	assertTrue(textPlus.startsWith(String("Hello")));
	
	assertFalse(textPlus.startsWith(String("ello")));
}

TEST (JavaLangString, ToLowerCase) {
	String textPlus = "Hello HELLO Hello ";
	
	String result = textPlus.toLowerCase();
	assertEquals("hello hello hello ", result.toString());
}

TEST (JavaLangString, ToUpperCase) {
	String textPlus = "Hello HELLO Hello ";
	
	String result = textPlus.toUpperCase();
	assertEquals("HELLO HELLO HELLO ", result.toString());
}

TEST (JavaLangString, Trim) {
	String textPlus = " Hello HELLO Hello ";
	
	String result = textPlus.trim();
	assertEquals("Hello HELLO Hello", result.toString());
}

TEST (JavaLangString, ValueOf) {
	// Value of boolean
	boolean isChecked = true;
	String valueOfBoolean = String::valueOf(isChecked);
	assertEquals((string) "true", valueOfBoolean.toString());
	
	// Value of single character
	char givenChar = '\0';
	String valueOfChar = String::valueOf(givenChar);
	assertEquals((string) "\0", valueOfChar.toString());
	
	// Value of string
	auto givenString = (string) "Hello world";
	String valueOfString = String::valueOf(givenString);
	assertEquals(givenString, valueOfString.toString());
	
	// Value of string
	auto givenEmptyString = (string) "";
	valueOfString = String::valueOf(givenEmptyString);
	assertEquals(givenEmptyString, valueOfString.toString());
	
	// Value of const_string
	auto givenConstString = (string) "Hello world";
	valueOfString = String::valueOf(givenConstString);
	assertEquals(givenConstString, valueOfString.toString());
	
	// Value of const_string
	givenConstString = (string) "";
	valueOfString = String::valueOf(givenConstString);
	assertEquals(givenConstString, valueOfString.toString());
	
	// Value of String
	auto givenObjectString = (string) "Hello world";
	valueOfString = String::valueOf(givenObjectString);
	assertEquals(givenObjectString, valueOfString.toString());
	
	// Value of short number
	short givenShortNumber = 5;
	String valueOfShort = String::valueOf(givenShortNumber);
	assertEquals("5", valueOfShort.toString());
	
	// Value of integer number
	int givenIntegerNumber = 34567;
	String valueOfInt = String::valueOf(givenIntegerNumber);
	assertEquals("34567", valueOfInt.toString());
	
	// Value of long number
	auto givenLongNumber = (long) 12345678893;
	String valueOfLong = String::valueOf(givenLongNumber);
	assertEquals("12345678893", valueOfLong.toString());
	
	// Value of float number
	auto givenFloatNumber = (float) 5.68;
	String valueOfFloat = String::valueOf(givenFloatNumber);
	assertEquals("5.68", valueOfFloat.toString());
	
	// Value of double number
	auto givenDoubleNumber = (double) 456.324234234240009;
	String valueOfDouble = String::valueOf(givenDoubleNumber);
	assertEquals("456.324234234240009", valueOfDouble.toString());
}

TEST (JavaLangString, OperatorPlusStringObject) {
	// Given two strings and concatenate them - Return string
	String textPlus1 = "Hello ";
	String textPlus2 = "World";
	String textResult = textPlus1 + textPlus2;
	assertEquals("Hello World", textResult.toString());
	
	// Concat a string with valueOf(number) - Return string
	textPlus1 = "Hello ";
	int aNumber = 1;
	textResult = textPlus1 + String::valueOf(aNumber);
	assertEquals("Hello 1", textResult.toString());
	
	// Concat 2 Strings with valueOf(number) - Return string
	textPlus1 = "Hello";
	aNumber = 1;
	textResult = textPlus1 + (string) " Galaxy " + String::valueOf(aNumber);
	assertEquals("Hello Galaxy 1", textResult.toString());
}

TEST (JavaLangString, OperatorPlusStringDataType) {
	auto world = (string) " World";
	String hello = "Hello";
	hello += world;
	assertEquals("Hello World", hello.toString());
	
	String food = "Food";
	auto tiny = (string) " Tiny";
	String foodTiny = food + tiny;
	assertEquals("Food Tiny", foodTiny.toString());
}

TEST (JavaLangString, OperatorPlusConstantStringDataType) {
	String input = "Food";
	String result = input + String("tiny");
	String expected = "Foodtiny";
	assertTrue(expected.equals(result));
	
	String input1 = "Hello";
	String result1 = input1 + String("");
	String expected1 = "Hello";
	assertTrue(expected1.equals(result1));
	
	String input2 = "";
	String result2 = input2 + String("World");
	String expected2 = "World";
	assertTrue(expected2.equals(result2));
}

TEST (JavaLangString, OperatorEquals) {
	// Given two string and compare equal them - Return comparable
	String textCompare1 = "Hello";
	String textCompare2 = "Hello";
	int comparable = false;
	if (textCompare1 == textCompare2) {
		comparable = true;
	}
	assertTrue(comparable);
}

TEST (JavaLangString, OperatorNotEquals) {
	// Given two Strings and compare not equal them - Return comparable
	String textCompare1 = "Hello1";
	String textCompare2 = "Hello2";
	int comparable = false;
	if (textCompare1 != textCompare2) {
		comparable = true;
	}
	assertTrue(comparable);
}

TEST (JavaLangString, OperatorPlusEqualsChar) {
	// Given a string and append a char  - Return result of the concatenation
	String text = "Hello";
	text += ' ';
	text += 'W';
	text += 'o';
	text += 'r';
	text += 'l';
	text += 'd';
	assertEquals("Hello World", text.toString());
}

TEST (JavaLangString, OperatorPlusEqualsString) {
	// Given 2 Strings to check "+=" operator
	String leftString = "hello";
	String rightString = " world";
	
	leftString += rightString;
	assertEquals("hello world", leftString.toString());
	
	// Given 2 Strings to check "+=" operator
	String stringTest = "";
	String stringTest1 = "Hello";
	String stringTest2 = " Galaxy";
	stringTest += stringTest1 + stringTest2 + (string) "!";
	assertEquals("Hello Galaxy!", stringTest.toString());
	
	// Check a String concat with valueOf(number) use "+=" operator
	int number = 1;
	stringTest = "Hello ";
	stringTest += String::valueOf(number);
	assertEquals("Hello 1", stringTest.toString());
	
	// Check a String concat with valueOf(number) use "+=" operator
	number = 1;
	stringTest += "" + String::valueOf(number);
	assertEquals("Hello 11", stringTest.toString());
}

TEST (JavaLangString, MemoryCheck) {
	// Test create object String with validString and change data of validString
	string validString = stringCopy("foodtiny");
	String stringTest = validString;
	free(validString);
	
	int expect = 8;
	int result = stringTest.length();
	assertEquals(expect, result);
	
	// Test copy String and change data of stringTest
	String stringCopyStringTest(stringTest);
	stringTest = "";
	expect = 8;
	result = stringCopyStringTest.length();
	assertEquals(expect, result);
}

TEST (JavaLangString, Clone) {
	// Given two string and compare - Should equal
	String validString("Hello world");
	String cloneString = validString.clone();
	assertEquals(validString.toString(), cloneString.toString());
	
	// Give two empty string and compare - Should equal
	String emptyString;
	String cloneEmptyString = emptyString.clone();
	assertEquals(emptyString.toString(), cloneEmptyString.toString());
	
	// Clone new data for cloneEmptyString
	// Give two string and compare - Should equal
	cloneEmptyString = validString.clone();
	assertEquals(validString.toString(), cloneEmptyString.toString());
}

TEST (JavaLangString, SubString) {
	String validString = "Hello world";
	String subString = validString.subString(6);
	auto expect = (string) "world";
	assertEquals(expect, subString);
	
	subString = validString.subString(1, 5);
	expect = (string) "ello";
	assertEquals(expect, subString);
}

TEST (JavaLangString, CompareOperater) {
	String greaterString = "acde";
	String smallerString = "ACDE";
	String equalToGreaterString = "acde";
	
	assertTrue(greaterString > smallerString);
	assertTrue(smallerString <= greaterString);
	assertTrue(greaterString <= equalToGreaterString);
	assertTrue(greaterString >= equalToGreaterString);
	assertFalse(smallerString > greaterString);
	assertFalse(smallerString >= greaterString);
	assertFalse(greaterString <= smallerString);
}

TEST (JavaLangString, Format) {
	unsigned short ushortValue = 1;
	short shortValue = -1;
	int intValue = -123;
	unsigned int uintValue = 123;
	long longValue = 123;
	unsigned long ulongValue = 123456;
	float floatValue = 123.456;
	double doubleValue = 123.456789;
	auto stringValue = (string) "string";
	Short shortObject = 123;
	Integer integerObject = -123;
	Long longObject = 123456;
	Float floatObject = 123.456;
	Double doubleObject = 123.456789;
	String stringObject = "String";
	
	{
		String expect = "%% the quick -123 123 brown -123 123456 fox 123.456 123.456789 jumps 123.456 123.456789 over the lazy %% string dog String %d";
		String format = "%%%% the quick %d %d brown %d %d fox %.3f %.6f jumps %.3f %.6f over the lazy %%%% %s dog %s %%d";
		String result = String::format(format, intValue, longValue,
		                               integerObject, longObject, floatValue,
		                               doubleValue,
		                               floatObject, doubleObject, stringValue,
		                               stringObject);
		assertEquals(expect.toString(), result.toString());
	}
	
	{
		String expect = "%% hello %D %S %d world";
		String format = "%%% hello %D %S %%d world";
		String result = String::format(format);
		assertEquals(expect.toString(), result.toString());
	}
	
	{
		String expect = "123.46 +1e+02 1.234568E+02";
		String format = "%4.2f %+.0e %E";
		String result = String::format(format, doubleObject, doubleObject,
		                               doubleValue);
		assertEquals(expect.toString(), result.toString());
	}
	
	{
		String expect = "Preceding with zeros: 0000000123";
		String format = "Preceding with zeros: %010d";
		String result = String::format(format, longValue);
		assertEquals(expect.toString(), result.toString());
	}
	
	{
		String expect = "1 123 123456 123";
		String format = "%u %u %u %d";
		String result = String::format(format, ushortValue, uintValue,
		                               ulongValue, shortObject);
		assertEquals(expect.toString(), result.toString());
	}
	
	{
		integerObject = 65;
		String expect = "Characters: a A";
		String format = "Characters: %c %c";
		String result = String::format(format, 'a', integerObject);
		assertEquals(expect.toString(), result.toString());
	}
	
	{
		String format = "%d %d";
		try {
			String result = String::format(format, shortObject);
		} catch (IllegalArgumentException &e) {
			assertEquals("Missing arguments.", e.getMessage().toString());
		}
	}
	
	{
		String format = "%%% d";
		try {
			String result = String::format(format);
		} catch (IllegalArgumentException &e) {
			assertEquals("Missing arguments.", e.getMessage().toString());
		}
	}
	
	{
		auto key = (string) "Nhà hàng";
		double latitude = 10.824093;
		double longitude = 106.683844;
		string url = urlDecode(key);
		auto queryFormat = "{\"query\": {\"bool\" : {\"must\" : [{\"nested\":{\"path\":\"shop_type\",\"query\":{ \"match\":{\"shop_type.vi_VN\":\"%s\" } }}},{\"filtered\": {\"filter\": {\"geo_distance\": {\"distance\": \"5km\",\"distance_type\": \"plane\", \"shop_location\": {\"lat\": %f,\"lon\": %f}}}}}]}}}";
		String body = String::format(queryFormat, url, latitude, longitude);
		
		String REQUEST_TEMPLATE = "%s %s%s %s\r\n"
			"%s\r\n\r\n"
			"%s";
		
		String result = String::format(REQUEST_TEMPLATE,
		                               "POST",
		                               "CASSANDRA",
		                               "_test",
		                               "http1.1",
		                               "HEADER:HEADER",
		                               body);
		
		string expected;
		int length = asprintf(&expected,
		                      REQUEST_TEMPLATE.toCharPointer(),
		                      "POST",
		                      "CASSANDRA",
		                      "_test",
		                      "http1.1",
		                      "HEADER:HEADER",
		                      body.toCharPointer());
		
		assertTrue(length > 0);
		assertEquals(expected, result.toString());
		free(expected);
		free(url);
	}
	
	{
		string expected;
		String result;
		unsigned long ul = timestamp();
		
		int length = asprintf(&expected, "%lu", ul);
		assertTrue(length > 0);
		result = String::format("%lu", ul);
		assertEquals(expected, result.toString());
		free(expected);
	}
}