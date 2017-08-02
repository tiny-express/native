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

#include "../String/String.hpp"
#include "../Long/Long.hpp"
#include "../Integer/Integer.hpp"
#include "../../Lang.hpp"
#include "../StringIndexOutOfBoundsException/StringIndexOutOfBoundsException.hpp"

using namespace Java::Lang;

TEST (JavaLang, StringConstructor) {
	// Give NULL for String constructor
	String nullString;
	ASSERT_STR("", nullString.toString());

	// Given empty value for String constructor and assign value - Return string
	String simpleString;
	simpleString = (string) "Hello world";
	ASSERT_STR("Hello world", simpleString.toString());

	// Given empty value for String constructor and assign value - Return string
	String emptyString;
	emptyString = (string) "Hello world";
	ASSERT_STR("Hello world", emptyString.toString());

	// Given constant string for String constructor - Return string
	String normalString = "Hello world";
	ASSERT_STR("Hello world", normalString.toString());
}

TEST (JavaLang, StringDestructor) {
	// Given data type declaration - Destructor will be called by system
	String text = "";

	// Given memory allocation for textPointer - Cleanup memory success
	String *textPointer = new String("Hello");
	delete textPointer;
}

TEST (JavaLang, StringEquals) {
	// Given two String objects with same value - Return they should equal
	String stringEqual1 = "Hello World";
	String stringEqual2 = "Hello World";
	ASSERT_TRUE(instanceof<String>(stringEqual1));
	ASSERT_TRUE(stringEqual1.equals(stringEqual2));
	ASSERT_TRUE(stringEqual1 == stringEqual2);

	// Compare with another String object - Return they are not equal
	String stringEqual3 = "Food Tiny";
	ASSERT_TRUE(!stringEqual1.equals(stringEqual3));
	ASSERT_TRUE(stringEqual1 != stringEqual3);
}

TEST (JavaLang, StringCharAt) {
	// Given a string - Return first position is exist
	String text = "Hello World";
	char positionIsExist = text.charAt(0);
	ASSERT_TRUE('H' == positionIsExist);

	// Given a string - Return negative position is not exist
	try {
		char negativePositionIsNotExist = text.charAt(-1);
	} catch (StringIndexOutOfBoundsException exception) {
		ASSERT_STR("String index out of range", exception.getMessage().toString());
	}

	// Given a string - Return out of scope position is not exist
	try {
		char outOfScopePositionIsNotExist = text.charAt(1000);
	} catch (StringIndexOutOfBoundsException exception) {
		ASSERT_STR("String index out of range", exception.getMessage().toString());
	}
}

TEST (JavaLang, StringConcat) {
	// Given two strings - Return concatenation result
	String textConcat1 = "Hello ";
	String textConcat2 = "World";
	String concatenationResult = textConcat1.concat(textConcat2);
	ASSERT_STR("Hello World", concatenationResult.toString());

	// Given three strings - Return concatenation result
	String textConcat0 = "Food Tiny ";
	ASSERT_STR("Food Tiny Hello World", ( textConcat0 + textConcat1 + textConcat2 ).toString());
}

TEST (JavaLang, StringContains) {
	return;
	// Gives a valid string a sub string to find
	String validString = "a valid string to test";
	String subString = "valid string";
	String invalidSubString = "text";

	//Test true with correct substring inside
	ASSERT_TRUE(validString.contains(subString));
	//Test with with invalid substring inside
	ASSERT_FALSE(validString.contains(invalidSubString));
}

// FIXME
TEST (JavaLang, StringEndsWith) {
	String textPlus = "Hello welcom to VietNam";
	String String_string = "VietNam";
	ASSERT_TRUE(textPlus.endsWith(String_string));
}

TEST(JavaLang, StringGetBytes) {
	String text = "Sample Text";
	Array<byte> bytes = text.getBytes();
	string result = bytes.toString();
	ASSERT_STR(text.toString(), result);
	free(result);
}

TEST (JavaLang, StringIndexOf) {
	String textPlus = "Hello Hello Hello ";

	int result = textPlus.indexOf('H');
	ASSERT_EQUAL(0, result);

	result = textPlus.indexOf('l', 4);
	ASSERT_EQUAL(8, result);

	result = textPlus.indexOf("llo");
	ASSERT_EQUAL(2, result);

	int result1 = textPlus.lastIndexOf('H');
	ASSERT_EQUAL(12, result1);

	result1 = textPlus.lastIndexOf('H', 2);
	ASSERT_EQUAL(0, result1);

	// Given validString check lastIndexOf(string)
	String validString = "awesome keyword inside this awesome string";
	String subString = "awesome";
	String wrongString = "some thing";


	// Test true first character of subString appear last in validString is position 28th
	ASSERT_EQUAL(28, validString.lastIndexOf(subString));

	// Test true first character of subString appear last in validString is position 16th
	subString = "inside this";
	ASSERT_EQUAL(16, validString.lastIndexOf(subString));

	// Test false with wrong subString
	ASSERT_EQUAL(NOT_FOUND, validString.lastIndexOf(wrongString));

	// Given validString2 check lastIndexOf(string, fromIndex)
	String validString2 = "sometimes you win, sometimes you learn";
	String subString2 = "sometimes";
	String wrongString2 = "abc xyz";

	// Test true by 19th, with correct subString2 and correct fromIndex to find
	ASSERT_EQUAL(19, validString2.lastIndexOf(subString2, 18));

	// Test false by -1, with correct subString2 but out of range that subString2's appeared in validString2
	ASSERT_EQUAL(-1, validString2.lastIndexOf(subString2, 20));

	// Test false by -1, with wrongString2 that's not appeared inside validString2
	ASSERT_EQUAL(-1, validString2.lastIndexOf(wrongString2, 0));
}

TEST (JavaLang, StringIsEmpty) {
	String textPlus = "Hello Hello Hello ";
	ASSERT_TRUE(!textPlus.isEmpty());

	textPlus = "";
	ASSERT_TRUE(textPlus.isEmpty());
}

TEST (JavaLang, StringLength) {
	String textPlus = "Hello Hello Hello ";

	ASSERT_EQUAL(18, textPlus.length());

	textPlus = "";
	ASSERT_EQUAL(0, textPlus.length());
}

/** This test case is made based on pattern_test.c */
TEST (JavaLang, StringMatches) {
//	// Init params for test string matches
//	String emailPattern = EMAIL_PATTERN;
//	String phoneNumberPattern = PHONE_PATTERN;
//
//	// Test true with correct email format
//	String correctEmail = "neacao@gmail.com";
//	ASSERT_TRUE(correctEmail.matches(emailPattern));
//
//	// Test fail with wrong email format
//	String wrongEmail = "something@notcorrect";
//	ASSERT_FALSE(wrongEmail.matches(emailPattern));
//
//	// Test true with correct phone number format
//	String correctPhoneNumber = "+15005550006";
//	ASSERT_TRUE(correctPhoneNumber.matches(phoneNumberPattern));
//
//	// Test fail with wrong email format
//	String wrongPhoneNumber = "001678080147";
//	ASSERT_FALSE(wrongPhoneNumber.matches(phoneNumberPattern));
//}
//
//TEST (JavaLang, StringReplace) {
//	String textPlus = "Hello Hello Hello ";
//
//	String result = textPlus.replace('e', 'i');
//	ASSERT_STR("Hillo Hillo Hillo ", result.toString());

//	String String_string1 = "Hello";
//	String String_string2 = "Phuoc";
//	result = textPlus.replaceAll(String_string1, String_string2);
//	ASSERT_STR("Phuoc Phuoc Phuoc ", result.toString());
}

TEST (JavaLang, StringSplit) {
	// Give an Array<String> then asert each element - Should equal
	String stringToSplit = "Hello Hello Hello";
	Array<String> strings = stringToSplit.split(" ");
	for (String item : strings) {
		ASSERT_STR("Hello", item.toString());
	}
}

TEST (JavaLang, StringStartsWith) {
	String textPlus = "Hello Hello Hello ";

	String String_string = "Hello";
	ASSERT_TRUE(textPlus.startsWith(String_string));

	String textPlus1 = "Welcom to VietNam";
	String String_string1 = "to";
	ASSERT_TRUE(textPlus1.startsWith(String_string1, 7));
}

TEST (JavaLang, StringToLowerCase) {
	String textPlus = "Hello HELLO Hello ";

	String result = textPlus.toLowerCase();
	ASSERT_STR("hello hello hello ", result.toString());
}

TEST (JavaLang, StringToUpperCase) {
	String textPlus = "Hello HELLO Hello ";

	String result = textPlus.toUpperCase();
	ASSERT_STR("HELLO HELLO HELLO ", result.toString());
}

TEST (JavaLang, StringTrim) {
	String textPlus = " Hello HELLO Hello ";

	String result = textPlus.trim();
	ASSERT_STR("Hello HELLO Hello", result.toString());
}

TEST (JavaLang, StringValueOf) {
	// Value of boolean
	boolean isChecked = true;
	String valueOfBoolean = String::valueOf(isChecked);
	ASSERT_STR((string) "1", valueOfBoolean.toString());

	// Value of single character
	char givenChar = '\0';
	String valueOfChar = String::valueOf(givenChar);
	ASSERT_STR((string) "\0", valueOfChar.toString());

	// Value of string
	string givenString = (string) "Hello world";
	String valueOfString = String::valueOf(givenString);
	ASSERT_STR(givenString, valueOfString.toString());

	// Value of short number
	short givenShortNumber = 5;
	String valueOfShort = String::valueOf(givenShortNumber);
	ASSERT_STR("5", valueOfShort.toString());

	// Value of integer number
	int givenIntegerNumber = 34567;
	String valueOfInt = String::valueOf(givenIntegerNumber);
	ASSERT_STR("34567", valueOfInt.toString());

	// Value of long number
	long givenLongNumber = (long) 12345678893;
	String valueOfLong = String::valueOf(givenLongNumber);
	ASSERT_STR("12345678893", valueOfLong.toString());

	// Value of float number
	float givenFloatNumber = (float) 5.68;
	String valueOfFloat = String::valueOf(givenFloatNumber);
	ASSERT_STR("5.68", valueOfFloat.toString());

	// Value of double number
	double givenDoubleNumber = (double) 456.32423423424;
	String valueOfDouble = String::valueOf(givenDoubleNumber);
	ASSERT_STR("456.32423423424", valueOfDouble.toString());
}

TEST (JavaLang, StringOperatorPlusStringObject) {
	// Given two strings and concatenate them - Return string
	String textPlus1 = "Hello ";
	String textPlus2 = "World";
	String textResult = textPlus1 + textPlus2;
	ASSERT_STR("Hello World", textResult.toString());

	// Concat a string with valueOf(number) - Return string
	textPlus1 = "Hello ";
	int aNumber = 1;
	textResult = textPlus1 + String::valueOf(aNumber);
	ASSERT_STR("Hello 1", textResult.toString());

	// Concat 2 Strings with valueOf(number) - Return string
	textPlus1 = "Hello";
	aNumber = 1;
	textResult = textPlus1 + (string) " Galaxy " + String::valueOf(aNumber);
	ASSERT_STR("Hello Galaxy 1", textResult.toString());
}

TEST (JavaLang, StringOperatorPlusStringDataType) {
	string world = (string) " World";
	String hello = "Hello";
	hello += world;
	ASSERT_STR("Hello World", hello.toString());

	String food = "Food";
	string tiny = (string) " Tiny";
	String foodTiny = food + tiny;
	ASSERT_STR("Food Tiny", foodTiny.toString());
}

TEST (JavaLang, StringOperatorEquals) {
	// Given two string and compare equal them - Return comparable
	String textCompare1 = "Hello";
	String textCompare2 = "Hello";
	int comparable = FALSE;
	if (textCompare1 == textCompare2) {
		comparable = TRUE;
	}
	ASSERT_TRUE(comparable);
}

TEST (JavaLang, StringOperatorNotEquals) {
	// Given two Strings and compare not equal them - Return comparable
	String textCompare1 = "Hello1";
	String textCompare2 = "Hello2";
	int comparable = FALSE;
	if (textCompare1 != textCompare2) {
		comparable = TRUE;
	}
	ASSERT_TRUE(comparable);
}

TEST (JavaLang, StringOperatorPlusEqualsChar) {
	// Given a string and append a char  - Return result of the concatenation
	String text = "Hello";
	text += ' ';
	text += 'W';
	text += 'o';
	text += 'r';
	text += 'l';
	text += 'd';
	ASSERT_STR("Hello World", text.toString());
}

TEST (JavaLang, StringOperatorPlusEqualsString) {
	// Given 2 Strings to check "+=" operator
	String leftString = "hello";
	String rightString = " world";

	leftString += rightString;
	ASSERT_STR("hello world", leftString.toString());

	// Given 2 Strings to check "+=" operator
	String stringTest = "";
	String stringTest1 = "Hello";
	String stringTest2 = " Galaxy";
	stringTest += stringTest1 + stringTest2 + (string) "!";
	ASSERT_STR("Hello Galaxy!", stringTest.toString());

	// Check a String concat with valueOf(number) use "+=" operator
	int number = 1;
	stringTest = "Hello ";
	stringTest += String::valueOf(number);
	ASSERT_STR("Hello 1", stringTest.toString());

	// Check a String concat with valueOf(number) use "+=" operator
	number = 1;
	stringTest += "" + String::valueOf(number);
	ASSERT_STR("Hello 11", stringTest.toString());
}

TEST (JavaLang, StringMemoryCheck) {
	// Test create object String with validString and change data of validString
	string validString = strdup("foodtiny");
	String stringTest = validString;
	free(validString);

	int expect = 8;
	int result = stringTest.length();
	ASSERT_EQUAL(expect, result);

	// Test copy String and change data of stringTest
	String stringCopyStringTest(stringTest);
	stringTest = "";
	expect = 8;
	result = stringCopyStringTest.length();
	ASSERT_EQUAL(expect, result);
}

TEST(JavaLang, StringClone) {
	// Given two string and compare - Should equal
	String validString("Hello world");
	String cloneString = validString.clone();
	ASSERT_STR(validString.toString(), cloneString.toString());

	// Give two empty string and compare - Should equal
	String emptyString;
	String cloneEmptyString = emptyString.clone();
	ASSERT_STR(emptyString.toString(), cloneEmptyString.toString());

	// Clone new data for cloneEmptyString
	// Give two string and compare - Should equal
	cloneEmptyString = validString.clone();
	ASSERT_STR(validString.toString(), cloneEmptyString.toString());
}

TEST(JavaLang, StringSubString) {
	String validString = "Hello world";
	String subString = validString.subString(6);
	string result = subString.toString();
	string expect = (string) "world";
	ASSERT_STR(expect, result);

	subString = validString.subString(1, 5);
	result = subString.toString();
//	expect = (string) "ello w"; // Wrong case
    expect = (string) "ello ";
	ASSERT_STR(expect, result);
}