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
#include "../String/String.hpp"

using namespace Java::Lang;

TEST(JavaLang, StringConstructor) {
    // Give NULL for String constructor
    String nullString;
    ASSERT_STR("", nullString.toString());

    // Given empty value for String constructor and assign value - Return string
    String emptyString;
    emptyString = (string) "Hello world";
    ASSERT_STR("Hello world", emptyString.toString());

    // Given byte array for String constructor - Return string
    Array<byte> bytes = {65, 66, 67};
    String byteString = bytes;
    ASSERT_STR("ABC", byteString.toString());

    // Given constant string for String constructor - Return string
    String normalString ="Hello world";
    ASSERT_STR("Hello world", normalString.toString());
}

TEST(JavaLang, StringDestructor) {
    // Given data type declaration - Destructor will be called by system
    String text = "";

    // Given memory allocation for textPointer - Cleanup memory success
    String *textPointer = new String("Hello");
    delete textPointer;
}

TEST(JavaLang, StringCharAt) {
    // Given a string - Return first position is exist
    String text = "Hello World";
    char positionIsExist = text.charAt(0);
    ASSERT_TRUE('H' == positionIsExist);

    // Given a string - Return negative position is not exist
    char negativePositionIsNotExist = text.charAt(-1);
    ASSERT_TRUE(negativePositionIsNotExist == '\0');

    // Given a string - Return out of scope position is not exist
    char outOfScopePositionIsNotExist = text.charAt(1000);
    ASSERT_TRUE(outOfScopePositionIsNotExist == '\0');
}

TEST(JavaLang, StringCompareTo) {
}

TEST(JavaLang, StringCompareToIgnoreCase) {

}

TEST(JavaLang, StringConcat) {
    // Given two strings - Return concatenation result
    String textConcat1 = "Hello ";
    String textConcat2 = "World";
    String concatenationResult = textConcat1.concat(textConcat2);
    ASSERT_STR("Hello World", concatenationResult.toString());

    // Given three strings - Return concatenation result
    String textConcat0 = "Food Tiny ";
    ASSERT_STR("Food Tiny Hello World", (textConcat0 + textConcat1 + textConcat2).toString());
}

// FIXME
TEST(JavaLang, StringEndsWith) {
    String textPlus = "Hello welcom to VietNam";
    String String_string = "VietNam";
    ASSERT_TRUE(textPlus.endsWith(String_string));
}

// FIXME
TEST(JavaLang, StringIndexOf) {
    String textPlus = "Hello Hello Hello ";

    int result = textPlus.indexOf('H');
    ASSERT_EQUAL(0, result);

    result = textPlus.indexOf('l', 4);
    ASSERT_EQUAL(8, result);

    result = textPlus.indexOf("llo");
    ASSERT_EQUAL(2, result);

//    result2 = textPlus1.indexOf("llo", 3);
//    ASSERT_EQUAL(14, result2);

    int result1 = textPlus.lastIndexOf('H');
    ASSERT_EQUAL(12, result1);

    result1 = textPlus.lastIndexOf('H', 2);
    ASSERT_EQUAL(0, result1);
}

// FIXME
TEST(JavaLang, StringIsEmpty) {
    String textPlus = "Hello Hello Hello ";
    ASSERT_TRUE(!textPlus.isEmpty());

    textPlus = "";
    ASSERT_TRUE(textPlus.isEmpty());
}

// FIXME
TEST(JavaLang, StringLength) {
    String textPlus = "Hello Hello Hello ";

    ASSERT_EQUAL(18, textPlus.length());

    textPlus = "";
    ASSERT_EQUAL(0, textPlus.length());
}

//FIXME
TEST(JavaLang, StringReplace) {
    String textPlus = "Hello Hello Hello ";

    String result = textPlus.replace('e', 'i');
    ASSERT_STR("Hillo Hillo Hillo ", result.toString());

    String String_string1 = "Hello";
    String String_string2 = "Phuoc";
    result = textPlus.replaceAll(String_string1, String_string2);
    ASSERT_STR("Phuoc Phuoc Phuoc ", result.toString());
}

// FIXME
TEST(JavaLang, StringSplit) {

}

//FIXME
TEST(JavaLang, StringStartsWith) {
    String textPlus = "Hello Hello Hello ";

    String String_string = "Hello";
    ASSERT_TRUE(textPlus.startsWith(String_string));
}

//FIXME
TEST(JavaLang, StringToLowerCase) {
    String textPlus = "Hello HELLO Hello ";

    String result = textPlus.toLowerCase();
    ASSERT_STR("hello hello hello ", result.toString());
}

//FIXME
TEST(JavaLang, StringToUpperCase) {
    String textPlus = "Hello HELLO Hello ";

    String result = textPlus.toUpperCase();
    ASSERT_STR("HELLO HELLO HELLO ", result.toString());
}

//FIXME
TEST(JavaLang, StringTrim) {
    String textPlus = " Hello HELLO Hello ";

    String result = textPlus.trim();
    ASSERT_STR("Hello HELLO Hello", result.toString());
}

TEST(JavaLang, StringValueOf) {
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

TEST(JavaLang, StringOperator) {
    // Given two strings and concatenate them - Return string
    String textPlus1 = "Hello ";
    String textPlus2 = "World";
    String textResult = textPlus1 + textPlus2;
    ASSERT_STR("Hello World", textResult.toString());

    // Concat a String with valueOf(number) - Return string
    textPlus1 = "Hello ";
    int aNumber = 1;
    textResult = textPlus1 + String::valueOf(aNumber);
    ASSERT_STR("Hello 1", textResult.toString());

    // Concat a String with valueOf(number) - Return string
//    textResult = "Hello " + String::valueOf(aNumber);
    ASSERT_STR("Hello 1", textResult.toString());

    // Concat 2 Strings with valueOf(number) - Return string
    textPlus1 = "Hello";
    aNumber = 1;
    textResult = textPlus1 + " Galaxy " + String::valueOf(aNumber);
    ASSERT_STR("Hello Galaxy 1", textResult.toString());

    // Given two string and compare equal them - Return comparable
    String textCompare1 = "Hello";
    String textCompare2 = "Hello";
    int comparable = FALSE;
    if (textCompare1 == textCompare2) {
        comparable = TRUE;
    }
    ASSERT_TRUE(comparable);

    // Given two Strings and compare not equal them - Return comparable
    textCompare1 = "Hello1";
    textCompare2 = "Hello2";
    comparable = FALSE;
    if (textCompare1 != textCompare2) {
        comparable = TRUE;
    }
    ASSERT_TRUE(comparable);

    // Given 2 Strings to check "+=" operator
    String leftString = "hello";
    String rightString = " world";

    leftString += rightString;
    ASSERT_STR("hello world", leftString.toString());

    // Given 2 Strings to check "+=" operator
    String stringTest = "";
    String stringTest1 = "Hello";
    String stringTest2 = " Galaxy";

    stringTest += stringTest1 + stringTest2 + "!";
    ASSERT_STR("Hello Galaxy!", stringTest.toString());

    // Check a String concat with valueOf(number) use "+=" operator
    aNumber = 1;
    stringTest = "Hello ";
    stringTest += String::valueOf(aNumber);
    ASSERT_STR("Hello 1", stringTest.toString());

    // Check a String concat with valueOf(number) use "+=" operator
    aNumber = 1;
    stringTest += "" + String::valueOf(aNumber);
    ASSERT_STR("Hello 11", stringTest.toString());
}

TEST(JavaLang, StringMemoryCheck) {
    // Test create object String with validString and change data of validString
    string validString = string_copy((char*)"foodtiny");
    String stringTest = validString;
    validString = string_copy((char*)"");

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
