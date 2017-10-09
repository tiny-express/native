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


#include "../String/String.hpp"
#include "../../Lang.hpp"
#include "../StringIndexOutOfBoundsException/StringIndexOutOfBoundsException.hpp"
#include "../StringBuilder/StringBuilder.hpp"
#include "../StringBuffer/StringBuffer.hpp"
#include "../IllegalArgumentException/IllegalArgumentException.hpp"

using namespace Java::Lang;
using namespace Java::Util;

TEST(JavaLang, StringConstructor) {
// Give NULL for String constructor
String nullString;
assertEquals("", nullString.toString());

// Given value for String constructor and assign value - Return string
String simpleStringConstructor = (string) "Hello world";
assertEquals("Hello world", simpleStringConstructor.toString());

// Given empty value for String constructor and assign value - Return string
String stringConstructor(simpleStringConstructor);
assertEquals("Hello world", stringConstructor.toString());

// Given constant string for String constructor - Return string
String normalString = "Hello world";
assertEquals("Hello world", normalString.toString());

// Given a StringBuilder for String constructor
StringBuilder stringBuilder  = StringBuilder((string) "Hello world");
String stringBuilderConstructor(stringBuilder);
assertEquals("Hello world", stringBuilderConstructor.toString());
ASSERT_EQUAL(stringBuilder.length(), stringBuilderConstructor.length());

// Given a StringBuffer for String constructor
StringBuffer stringBuffer  = StringBuffer("Hello world");
String stringBufferConstructor = String(stringBuffer);
assertEquals("Hello world", stringBufferConstructor.toString());
ASSERT_EQUAL(stringBuffer.length(), stringBufferConstructor.length());

// Given a char Array
Array<char> charArray = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};

String arrayConstructor(charArray);
assertEquals("Hello world", arrayConstructor.toString());
ASSERT_EQUAL(charArray.length, arrayConstructor.length());

String subArrayConstructor(charArray, 6, 5);
assertEquals("world", subArrayConstructor.toString());
ASSERT_EQUAL(5, subArrayConstructor.length());

try {
String exceptionConstructor(charArray, -1, 5);
}
catch (StringIndexOutOfBoundsException &e) {
assertEquals("String index out of range: -1", e.getMessage().toString());
}

try {
String exceptionConstructor(charArray, 5, -1);
}
catch (StringIndexOutOfBoundsException &e) {
assertEquals("String index out of range: -1", e.getMessage().toString());
}

try {
String exceptionConstructor(charArray, 10, 5);
}
catch (StringIndexOutOfBoundsException &e) {
assertEquals("String index out of range: 15", e.getMessage().toString());
}

// Given a byte Array
Array<byte> byteArray = {72, 101, 108, 108, 111, 32, 119, 111, 114, 108, 100};
assertEquals("Hello world", arrayConstructor.toString());
ASSERT_EQUAL(charArray.length, arrayConstructor.length());

String subByteArrayConstructor(byteArray, 6, 5);
assertEquals("world", subByteArrayConstructor.toString());
ASSERT_EQUAL(5, subByteArrayConstructor.length());

try {
String exceptionConstructor(byteArray, -1, 5);
}
catch (StringIndexOutOfBoundsException &e) {
assertEquals("String index out of range: -1", e.getMessage().toString());
}

try {
String exceptionConstructor(byteArray, 5, -1);
}
catch (StringIndexOutOfBoundsException &e) {
assertEquals("String index out of range: -1", e.getMessage().toString());
}

try {
String exceptionConstructor(byteArray, 10, 5);
}
catch (StringIndexOutOfBoundsException &e) {
assertEquals("String index out of range: 15", e.getMessage().toString());
}
}

TEST(JavaLang, StringDestructor) {
// Given data type declaration - Destructor will be called by system
String text = "";

// Given memory allocation for textPointer - Cleanup memory success
String *textPointer = new String("Hello");
delete textPointer;
}

TEST(JavaLang, StringEquals) {
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

// Compare with another object
StringBuilder stringBuilder = StringBuilder((string) "abcd");
ASSERT_FALSE(stringEqual1.equals(stringBuilder));
}

TEST(JavaLang, StringCharAt) {
// Given a string - Return first position is exist
String text = "Hello World";
char positionIsExist = text.charAt(0);

ASSERT_EQUAL('H', positionIsExist);

// Given a string - Return negative position is not exist
try {
char negativePositionIsNotExist = text.charAt(-1);
} catch (StringIndexOutOfBoundsException &exception) {
assertEquals("String index out of range", exception.getMessage().toString());
}

// Given a string - Return out of scope position is not exist
try {
char outOfScopePositionIsNotExist = text.charAt(1000);
} catch (StringIndexOutOfBoundsException &exception) {
assertEquals("String index out of range", exception.getMessage().toString());
}
}

TEST(JavaLang, StringCompareTo) {
String smallerString = "ABCDEF";
String greaterString = "abcdef";
String equalToGreater = "abcdef";

int compareResult = greaterString.compareTo(smallerString);
ASSERT_TRUE(compareResult > 0);

compareResult = greaterString.compareTo(equalToGreater);
ASSERT_TRUE(compareResult == 0);

compareResult = smallerString.compareTo(greaterString);
ASSERT_TRUE(compareResult < 0);

Comparable<String> *comparable = &greaterString;
compareResult = comparable->compareTo(smallerString);
ASSERT_TRUE(compareResult > 0);
}

TEST(JavaLang, StringCompareToIgnoreCase) {
String smallerString = "because";
String greaterString = "hello";
String greaterUpperCase = "HELLO";

int compareResult = greaterString.compareToIgnoreCase(smallerString);
ASSERT_TRUE(compareResult > 0);

compareResult = greaterString.compareToIgnoreCase(greaterUpperCase);
ASSERT_TRUE(compareResult == 0);

compareResult = smallerString.compareToIgnoreCase(greaterString);
ASSERT_TRUE(compareResult < 0);
}

TEST(JavaLang, StringConcat) {
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

TEST(JavaLang, StringContains) {
// Gives a valid string a sub string to find
String validString = "a valid string to test";
String subString = "valid string";
String invalidSubString = "text";

// Test true with correct substring inside
ASSERT_TRUE(validString.contains(subString));
// Test with with invalid substring inside
ASSERT_FALSE(validString.contains(invalidSubString));
}

TEST(JavaLang, StringContentEqual) {
String string = String("Hello world");
CharSequence *charSequence = new StringBuffer("Hello world");
ASSERT_TRUE(string.contentEquals(*charSequence));
StringBuffer *stringBuffer = dynamic_cast<StringBuffer *>(charSequence);
delete stringBuffer;

String stringEqual = String("Hello world");
ASSERT_TRUE(string.contentEquals(stringEqual));

String stringNotEqual = String("hello");
ASSERT_FALSE(string.contentEquals(stringNotEqual));
}

TEST(JavaLang, StringCopyValueOf) {
// Given a char Array
Array<char> charArray = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};

String copyArrayString = String::copyValueOf(charArray);
assertEquals("Hello world", copyArrayString.toString());
ASSERT_EQUAL(charArray.length, copyArrayString.length());

String copySubArrayString = String::copyValueOf(charArray, 6, 5);
assertEquals("world", copySubArrayString.toString());
ASSERT_EQUAL(5, copySubArrayString.length());

try {
String exceptionString = String::copyValueOf(charArray, -1, 5);
}
catch (StringIndexOutOfBoundsException &e) {
assertEquals("String index out of range: -1", e.getMessage().toString());
}

try {
String exceptionString = String::copyValueOf(charArray, 5, -1);
}
catch (StringIndexOutOfBoundsException &e) {
assertEquals("String index out of range: -1", e.getMessage().toString());
}

try {
String exceptionString = String::copyValueOf(charArray, 10, 5);
}
catch (StringIndexOutOfBoundsException &e) {
assertEquals("String index out of range: 15", e.getMessage().toString());
}
}

// FIXME
TEST(JavaLang, StringEndsWith) {
String textPlus = "Hello welcome to VietNam";
String String_string = "VietNam";
ASSERT_TRUE(textPlus.endsWith(String_string));
}

TEST(JavaLang, StringEqualIgnoreCase) {
String smallerString = "because";
String greaterString = "hello";
String greaterUpperCase = "HELLO";

ASSERT_FALSE(greaterString.equalsIgnoreCase(smallerString));
ASSERT_TRUE(greaterString.equalsIgnoreCase(greaterUpperCase));
ASSERT_FALSE(smallerString.equalsIgnoreCase(greaterString));
}

TEST(JavaLang, StringGetBytes) {
String text = "Sample Text";
Array<byte> bytes = text.getBytes();
string result = bytes.toString();
assertEquals(text.toString(), result);
free(result);
}

TEST(JavaLang, StringGetStringFromIndex) {
String aString = "Hello Hello Hello";
String result = aString.getStringFromIndex(6);
assertEquals("Hello Hello", result.toString());

try {
result = aString.getStringFromIndex(-1);
}
catch (StringIndexOutOfBoundsException &e) {
assertEquals("String index out of range: -1", e.getMessage().toString());
}

try {
result = aString.getStringFromIndex(20);
}
catch (StringIndexOutOfBoundsException &e) {
assertEquals("String index out of range: 20", e.getMessage().toString());
}
}

TEST(JavaLang, StringIndexOf) {
String textPlus = "Hello Hello Hello ";

int result = textPlus.indexOf('H');
ASSERT_EQUAL(0, result);

result = textPlus.indexOf('k');
ASSERT_EQUAL(-1, result);

result = textPlus.indexOf('k');
ASSERT_EQUAL(-1, result);

result = textPlus.indexOf('l', 4);
ASSERT_EQUAL(8, result);

result = textPlus.indexOf('k', 4);
ASSERT_EQUAL(-1, result);

result = textPlus.indexOf('l', -1);
ASSERT_EQUAL(2, result);

result = textPlus.indexOf('l', 100);
ASSERT_EQUAL(-1, result);

result = textPlus.indexOf("llo");
ASSERT_EQUAL(2, result);

result = textPlus.indexOf("llo", 4);
ASSERT_EQUAL(8, result);

result = textPlus.indexOf("llok");
ASSERT_EQUAL(-1, result);

result = textPlus.indexOf("llo", -1);
ASSERT_EQUAL(2, result);

result = textPlus.indexOf("llo", 100);
ASSERT_EQUAL(-1, result);

result = textPlus.indexOf("lli", 10);
ASSERT_EQUAL(-1, result);
}

TEST(JavaLang, StringLastIndexOf) {
// Given validString check lastIndexOf(string)
String textPlus = "Hello Hello Hello ";
String validString = "awesome keyword inside this awesome string";
String subString = "awesome";
String wrongString = "some thing";

int result = textPlus.lastIndexOf('H');
ASSERT_EQUAL(12, result);

result = textPlus.lastIndexOf('a');
ASSERT_EQUAL(-1, result);

result = textPlus.lastIndexOf('H', 2);
ASSERT_EQUAL(0, result);

result = textPlus.lastIndexOf('H', 100);
ASSERT_EQUAL(12, result);

result = textPlus.lastIndexOf('H', -1);
ASSERT_EQUAL(-1, result);

result = textPlus.lastIndexOf('a', 10);
ASSERT_EQUAL(-1, result);

// Test true first character of subString appear last in validString is position 28th
result = validString.lastIndexOf(subString);
ASSERT_EQUAL(28, result);

// Test false with wrong subString
result = validString.lastIndexOf(wrongString);
ASSERT_EQUAL(NOT_FOUND, result);

// Given validString2 check lastIndexOf(string, fromIndex)
String validString2 = "sometimes you win, sometimes you learn";
String subString2 = "sometimes";
String wrongString2 = "abc xyz";

// Test true by 19th, with correct subString2 and correct fromIndex to find
result = validString2.lastIndexOf(subString2, 19);
ASSERT_EQUAL(19, result);

result = validString2.lastIndexOf(subString2, 18);
ASSERT_EQUAL(0, result);

result = validString2.lastIndexOf(subString2, 0);
ASSERT_EQUAL(0, result);

result = validString2.lastIndexOf(subString2, 1);
ASSERT_EQUAL(0, result);

result = validString2.lastIndexOf(subString2, 100);
ASSERT_EQUAL(19, result);

result = validString2.lastIndexOf(subString2, -1);
ASSERT_EQUAL(-1, result);

result = validString2.lastIndexOf(subString2, 20);
ASSERT_EQUAL(19, result);

result = validString2.lastIndexOf(wrongString2, 20);
ASSERT_EQUAL(-1, result);
}
// TODO (anhnt) getChar run right but need Arrays.toString() to test
TEST(JavaLang, StringGetChars) {
Array<char> charArray(30);
String testString = "This is a String";
testString.getChars(10, 16, charArray, 0);
string charArrayString = charArray.toString();
assertEquals("String", charArrayString);
free(charArrayString);

try {
testString.getChars(-1, 16, charArray, 0);
}
catch (StringIndexOutOfBoundsException &e) {
assertEquals("String index out of range: -1", e.getMessage().toString());
}

try {
testString.getChars(10, 5, charArray, 0);
}
catch (StringIndexOutOfBoundsException &e) {
assertEquals("String index out of range: -5", e.getMessage().toString());
}

try {
testString.getChars(10, 50, charArray, 0);
}
catch (StringIndexOutOfBoundsException &e) {
assertEquals("String index out of range: 50", e.getMessage().toString());
}

try {
testString.getChars(10, 16, charArray, -1);
}
catch (StringIndexOutOfBoundsException &e) {
assertEquals("String index out of range: -1", e.getMessage().toString());
}

try {
testString.getChars(10, 16, charArray, 29);
}
catch (StringIndexOutOfBoundsException &e) {
assertEquals("String index out of range: 35", e.getMessage().toString());
}

testString.getChars(10, 16, charArray, 10);
charArrayString = charArray.toString();
assertEquals("StringString", charArrayString);
free(charArrayString);

testString.getChars(10, 16, charArray, 3);
charArrayString = charArray.toString();
assertEquals("StrStringString", charArrayString);
free(charArrayString);
}

TEST(JavaLang, StringIsEmpty) {
String textPlus = "Hello Hello Hello ";
ASSERT_TRUE(!textPlus.isEmpty());

textPlus = "";
ASSERT_TRUE(textPlus.isEmpty());
}

TEST(JavaLang, StringLength) {
String textPlus = "Hello Hello Hello ";

ASSERT_EQUAL(18, textPlus.length());

textPlus = "";
ASSERT_EQUAL(0, textPlus.length());
}

TEST(JavaLang, StringHashCode) {
String string = "Hello world";
ASSERT_EQUAL(-832992604, string.hashCode());
}

TEST(JavaLang, StringRegionMatch) {
String string1 = "Collection of tutorials";
String string2 = "Consists of different tutorials";
String string3 = "CONSISTS OF DIFFERENT TUTORIALS";

// Case considering
boolean match = string1.regionMatches(14, string2, 22, 9);
ASSERT_TRUE(match);

match = string1.regionMatches(14, string2, 20, 9);
ASSERT_FALSE(match);

match = string1.regionMatches(14, string3, 22, 9);
ASSERT_FALSE(match);

// Ignore case
match = string1.regionMatches(true, 14, string2, 22, 9);
ASSERT_TRUE(match);

match = string1.regionMatches(true, 14, string2, 20, 9);
ASSERT_FALSE(match);

match = string1.regionMatches(true, 14, string3, 22, 9);
ASSERT_TRUE(match);

match = string1.regionMatches(false, 14, string3, 22, 9);
ASSERT_FALSE(match);

match = string1.regionMatches(true, -1, string2, 22, 9);
ASSERT_FALSE(match);

match = string1.regionMatches(true, 14, string2, -1, 9);
ASSERT_FALSE(match);

match = string1.regionMatches(true, 14, string2, 22, 100);
ASSERT_TRUE(match);

match = string1.regionMatches(true, 14, string2, 100, 9);
ASSERT_FALSE(match);
}

TEST(JavaLang, StringJoin) {
String delimiter = "->";
String duck = "Duck";
StringBuffer dog("Dog");
StringBuilder pig((string) "Pig");
String result = String::join(delimiter, duck, dog, pig);
assertEquals("Duck->Dog->Pig", result.toString());
}

/** This test case is made based on pattern_test.c */
// TEST(JavaLang, StringMatches) {
// 	// Init params for test string matches
// 	String emailPattern = EMAIL_PATTERN;
// 	String phoneNumberPattern = PHONE_PATTERN;
//
// 	// Test true with correct email format
// 	String correctEmail = "neacao@gmail.com";
// 	ASSERT_TRUE(correctEmail.matches(emailPattern));
//
// 	// Test fail with wrong email format
// 	String wrongEmail = "something@notcorrect";
// 	ASSERT_FALSE(wrongEmail.matches(emailPattern));
//
// 	// Test true with correct phone number format
// 	String correctPhoneNumber = "+15005550006";
// 	ASSERT_TRUE(correctPhoneNumber.matches(phoneNumberPattern));
//
// 	// Test fail with wrong email format
// 	String wrongPhoneNumber = "001678080147";
// 	ASSERT_FALSE(wrongPhoneNumber.matches(phoneNumberPattern));
// }
//
TEST(JavaLang, StringReplace) {
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

TEST(JavaLang, StringSplit) {
// Give an Array<String> then asert each element - Should equal
String stringToSplit = "Hello Hello Hello Hello";
Array<String> strings = stringToSplit.split(" ");
for (String item : strings) {
assertEquals("Hello", item.toString());
}

Array<String> splitWithLimit1 = stringToSplit.split(" ", 3);
int index;
for (index = 0; index < splitWithLimit1.length - 1; index++) {
assertEquals("Hello", splitWithLimit1[index].toString());
}
assertEquals("Hello Hello", splitWithLimit1[splitWithLimit1.length - 1].toString());

// Split with limit greater than number of regex occurrence time
Array<String> splitWithLimit2 = stringToSplit.split(" ", 10);
for (index = 0; index < splitWithLimit2.length - 1; index++) {
assertEquals("Hello", splitWithLimit2[index].toString());
}

Array<String> splitWithLimitOne = stringToSplit.split(" ", 1);
assertEquals(stringToSplit.toString(), splitWithLimitOne[0].toString());

Array<String> splitWithLimitZero = stringToSplit.split(" ", 0);
for (index = 0; index < splitWithLimitZero.length - 1; index++) {
assertEquals("Hello", splitWithLimitZero[index].toString());
}

Array<String> splitWithLimitNegative = stringToSplit.split(" ", -1);
for (index = 0; index < splitWithLimitNegative.length - 1; index++) {
assertEquals("Hello", splitWithLimitNegative[index].toString());
}
}

TEST(JavaLang, StringStartsWith) {
String textPlus;
// textPlus == ""
ASSERT_FALSE(textPlus.startsWith(String("abc"), 10));

textPlus = "Hello Hello Hello ";
// prefix == ""
String nullString;
ASSERT_TRUE(textPlus.startsWith(nullString, 10));

// thisOffset < 0
ASSERT_FALSE(textPlus.startsWith(String("Hello"), -1));

// textPlus.length < prefix.length
ASSERT_FALSE(textPlus.startsWith(String("Hello Hello Hello H")));

// thisOffset > (textPlus.length - prefix.length)
ASSERT_FALSE((textPlus.startsWith(String("Hello"), 20)));

// valid case
ASSERT_TRUE(textPlus.startsWith(String(""), 7));

ASSERT_TRUE(textPlus.startsWith(String("Hello")));

ASSERT_FALSE(textPlus.startsWith(String("ello")));
}

TEST(JavaLang, StringToLowerCase) {
String textPlus = "Hello HELLO Hello ";

String result = textPlus.toLowerCase();
assertEquals("hello hello hello ", result.toString());
}

TEST(JavaLang, StringToUpperCase) {
String textPlus = "Hello HELLO Hello ";

String result = textPlus.toUpperCase();
assertEquals("HELLO HELLO HELLO ", result.toString());
}

TEST(JavaLang, StringTrim) {
String textPlus = " Hello HELLO Hello ";

String result = textPlus.trim();
assertEquals("Hello HELLO Hello", result.toString());
}

TEST(JavaLang, StringValueOf) {
// Value of boolean
boolean isChecked = true;
String valueOfBoolean = String::valueOf(isChecked);
assertEquals((string) "true", valueOfBoolean.toString());

// Value of single character
char givenChar = '\0';
String valueOfChar = String::valueOf(givenChar);
assertEquals((string) "\0", valueOfChar.toString());

// Value of string
string givenString = (string) "Hello world";
String valueOfString = String::valueOf(givenString);
assertEquals(givenString, valueOfString.toString());

// Value of string
string givenEmptyString = (string) "";
valueOfString = String::valueOf(givenEmptyString);
assertEquals(givenEmptyString, valueOfString.toString());

// Value of short number
short givenShortNumber = 5;
String valueOfShort = String::valueOf(givenShortNumber);
assertEquals("5", valueOfShort.toString());

// Value of integer number
int givenIntegerNumber = 34567;
String valueOfInt = String::valueOf(givenIntegerNumber);
assertEquals("34567", valueOfInt.toString());

// Value of long number
long givenLongNumber = (long) 12345678893;
String valueOfLong = String::valueOf(givenLongNumber);
assertEquals("12345678893", valueOfLong.toString());

// Value of float number
float givenFloatNumber = (float) 5.68;
String valueOfFloat = String::valueOf(givenFloatNumber);
assertEquals("5.68", valueOfFloat.toString());

// Value of double number
double givenDoubleNumber = (double) 456.32423423424;
String valueOfDouble = String::valueOf(givenDoubleNumber);
assertEquals("456.32423423424", valueOfDouble.toString());
}

TEST(JavaLang, StringOperatorPlusStringObject) {
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

TEST(JavaLang, StringOperatorPlusStringDataType) {
string world = (string) " World";
String hello = "Hello";
hello += world;
assertEquals("Hello World", hello.toString());

String food = "Food";
string tiny = (string) " Tiny";
String foodTiny = food + tiny;
assertEquals("Food Tiny", foodTiny.toString());
}

TEST(JavaLang, StringOperatorPlusConstantStringDataType) {
String input = "Food";
String result = input + String("tiny");
String expected = "Foodtiny";
ASSERT_TRUE(expected.equals(result));

String input1 = "Hello";
String result1 = input1 + String("");
String expected1 = "Hello";
ASSERT_TRUE(expected1.equals(result1));

String input2 = "";
String result2 = input2 + String("World");
String expected2 = "World";
ASSERT_TRUE(expected2.equals(result2));
}

TEST(JavaLang, StringOperatorEquals) {
// Given two string and compare equal them - Return comparable
String textCompare1 = "Hello";
String textCompare2 = "Hello";
int comparable = false;
if (textCompare1 == textCompare2) {
comparable = true;
}
ASSERT_TRUE(comparable);
}

TEST(JavaLang, StringOperatorNotEquals) {
// Given two Strings and compare not equal them - Return comparable
String textCompare1 = "Hello1";
String textCompare2 = "Hello2";
int comparable = false;
if (textCompare1 != textCompare2) {
comparable = true;
}
ASSERT_TRUE(comparable);
}

TEST(JavaLang, StringOperatorPlusEqualsChar) {
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

TEST(JavaLang, StringOperatorPlusEqualsString) {
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

TEST(JavaLang, StringMemoryCheck) {
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

TEST(JavaLang, StringSubString) {
String validString = "Hello world";
String subString = validString.subString(6);
string result = subString.toString();
string expect = (string) "world";
assertEquals(expect, result);

subString = validString.subString(1, 5);
result = subString.toString();
expect = (string) "ello";
assertEquals(expect, result);
}

TEST(JavaLang, StringCompareOperater) {
String greaterString = "acde";
String smallerString = "ACDE";
String equalToGreaterString = "acde";

ASSERT_TRUE(greaterString > smallerString);
ASSERT_TRUE(smallerString <= greaterString);
ASSERT_TRUE(greaterString <= equalToGreaterString);
ASSERT_TRUE(greaterString >= equalToGreaterString);
ASSERT_FALSE(smallerString > greaterString);
ASSERT_FALSE(smallerString >= greaterString);
ASSERT_FALSE(greaterString <= smallerString);
}
TEST(JavaLang, StringFormat) {
unsigned short ushortValue = 1;
short shortValue = -1;
int intValue = -123;
unsigned int uintValue = 123;
long longValue = 123;
unsigned long ulongValue = 123456;
float floatValue = 123.456;
double doubleValue = 123.456789;
string stringValue = (string)"string";
Short shortObject = 123;
Integer integerObject = -123;
Long longObject = 123456;
Float floatObject = 123.456;
Double doubleObject = 123.456789;
String stringObject = "String";

{
String expect = "%% the quick -123 123 brown -123 123456 fox 123.456 123.456789 jumps 123.456 123.456789 over the lazy %% string dog String %d";
String format = "%%%% the quick %d %d brown %d %d fox %.3f %.6f jumps %.3f %.6f over the lazy %%%% %s dog %s %%d";
String result = String::format(format, intValue, longValue, integerObject, longObject, floatValue, doubleValue,
                               floatObject, doubleObject, stringValue, stringObject);
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
String result = String::format(format, doubleObject, doubleObject, doubleValue);
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
String result = String::format(format, ushortValue, uintValue, ulongValue, shortObject);
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
} catch (IllegalArgumentException& e) {
assertEquals("Missing arguments.", e.getMessage().toString());
}
}

{
String format = "%%% d";
try {
String result = String::format(format);
} catch (IllegalArgumentException& e) {
assertEquals("Missing arguments.", e.getMessage().toString());
}
}

{
string key = (string)"Nhà hàng";
double latitude = 10.824093;
double longitude = 106.683844;
string url = urlDecode(key);
String queryFormat = "{\"query\": {\"bool\" : {\"must\" : [{\"nested\":{\"path\":\"shop_type\",\"query\":{ \"match\":{\"shop_type.vi_VN\":\"%s\" } }}},{\"filtered\": {\"filter\": {\"geo_distance\": {\"distance\": \"5km\",\"distance_type\": \"plane\", \"shop_location\": {\"lat\": %f,\"lon\": %f}}}}}]}}}";
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
asprintf(&expected,
        REQUEST_TEMPLATE.toString(),
"POST", "CASSANDRA",
"_test",
"http1.1",
"HEADER:HEADER",
body.toString());

assertEquals(expected, result.toString());
free(expected);
free(url);
}

{
string expected;
String result;
unsigned long ul = timestamp();

asprintf(&expected, "%lu", ul);
result = String::format("%lu", ul);
assertEquals(expected, result.toString());
free(expected);
}
}