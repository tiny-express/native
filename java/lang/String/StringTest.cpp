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
    // Given empty value for String constructor and assign value - Return string
    String emptyString;
    emptyString = (string) "Hello world";
    ASSERT_STR("Hello world", emptyString.toCharArray());

    // Given byte array for String constructor - Return string
//    Array<byte> bytes = {65, 66, 67, 0};
//    String byteString = bytes;
//    ASSERT_STR("ABC", byteString.toCharArray());

    // Given constant string for String constructor - Return string
    String normalString ="Hello world";
    ASSERT_STR("Hello world", normalString.toCharArray());
}

TEST(JavaLang, StringCharAt) {
    String text = "Hello Hello Hello ";

    char positionIsExist = text.charAt(0);
    ASSERT_TRUE('H' == positionIsExist);

    char positionIsNotExist = text.charAt(-1);
    ASSERT_TRUE('\0' == positionIsNotExist);
}

TEST(JavaLang, StringConcat) {
    String textPlus1 = "Hello Hello Hello ";
    String textPlus2 = "phuoc";
    String result1 = textPlus1.concat(textPlus2);
    ASSERT_STR("Hello Hello Hello phuoc", result1.toCharArray());

    textPlus2 = "";
    result1 = textPlus1.concat(textPlus2);
    ASSERT_STR("Hello Hello Hello ", result1.toCharArray());
}

TEST(JavaLang, StringEndsWith) {
    String textPlus = "Hello welcom to VietNam";

    String String_string = "VietNam";
    ASSERT_TRUE(textPlus.endsWith(String_string));
}


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

TEST(JavaLang, StringReplace) {
    String textPlus = "Hello Hello Hello ";

    String result = textPlus.replace('e', 'i');
    ASSERT_STR("Hillo Hillo Hillo ", result.toCharArray());

    String String_string1 = "Hello";
    String String_string2 = "Phuoc";
    result = textPlus.replaceAll(String_string1, String_string2);
    ASSERT_STR("Phuoc Phuoc Phuoc ", result.toCharArray());
}

TEST(JavaLang, StringSplit) {

}

TEST(JavaLang, StringStartsWith) {
    String textPlus = "Hello Hello Hello ";

    String String_string = "Hello";
    ASSERT_TRUE(textPlus.startsWith(String_string));
}

TEST(JavaLang, StringToLowerCase) {
    String textPlus = "Hello HELLO Hello ";

    String result = textPlus.toLowerCase();
    ASSERT_STR("hello hello hello ", result.toCharArray());
}

TEST(JavaLang, StringToUpperCase) {
    String textPlus = "Hello HELLO Hello ";

    String result = textPlus.toUpperCase();
    ASSERT_STR("HELLO HELLO HELLO ", result.toCharArray());
}

TEST(JavaLang, StringTrim) {
    String textPlus = " Hello HELLO Hello ";

    String result = textPlus.trim();
    ASSERT_STR("Hello HELLO Hello", result.toCharArray());
}

TEST(JavaLang, StringValueOf) {
    // Value of boolean
    boolean isChecked = true;
    String valueOfBoolean = String::valueOf(isChecked);
    ASSERT_STR((string) "1", valueOfBoolean.toCharArray());

    // Value of single character
    char givenChar = '\0';
    String valueOfChar = String::valueOf(givenChar);
    ASSERT_STR((string) "\0", valueOfChar.toCharArray());

    // Value of string
    string givenString = "Hello world";
    String valueOfString = String::valueOf(givenString);
    ASSERT_STR(givenString, valueOfString.toCharArray());

    // Value of short number
    short givenShortNumber = 5;
    String valueOfShort = String::valueOf(givenShortNumber);
    ASSERT_STR("5", valueOfShort.toCharArray());

    // Value of integer number
    int givenIntegerNumber = 34567;
    String valueOfInt = String::valueOf(givenIntegerNumber);
    ASSERT_STR("34567", valueOfInt.toCharArray());

    // Value of long number
    long givenLongNumber = (long) 12345678893;
    String valueOfLong = String::valueOf(givenLongNumber);
    ASSERT_STR("12345678893", valueOfLong.toCharArray());

    // Value of float number
    float givenFloatNumber = (float) 5.68;
    String valueOfFloat = String::valueOf(givenFloatNumber);
    ASSERT_STR("5.68", valueOfFloat.toCharArray());

    // Value of double number
    double givenDoubleNumber = (double) 456.32423423424;
    String valueOfDouble = String::valueOf(givenDoubleNumber);
    ASSERT_STR("456.32423423424", valueOfDouble.toCharArray());
}

TEST(JavaLang, StringOperator) {
    // Given two strings and concatenate them - Return string
    String textPlus1 = "Hello ";
    String textPlus2 = "World";
    String textResult = textPlus1 + textPlus2;
    ASSERT_STR("Hello World", textResult.toCharArray());

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
}

TEST(JavaLang, StringTestFail) {

    // Test delete a Object String is fail
    String *text1 = new String("Anhkhoa");
    String *text2 = new String(*text1);
    delete text1;

    // puts(text1->toCharArray()); // DO NOT PUTS IN HERE - text1 is deleted !
    puts(text2->toCharArray());
    delete text2;


    // Test memory
    char *givetest = new char[10];

    int index;
    for (index = 0; index < 9; ++index) {
        givetest[index] = 'a';
    }
    givetest[9] = '\0';

    String str1 = givetest;
    String str2(str1);

    char *resultStr1 = str1.toCharArray();
    char *resultStr2 = str2.toCharArray();

    std::cout << "To char array str1: ";
    puts(resultStr1);
    std::cout << "To char array str2: ";
    puts(resultStr2);

    // Change data of givetest but data of str1 and str2 also changed
    for (index = 0; index < 9; ++index) {
        givetest[index] = 'b';
    }

    resultStr1 = str1.toCharArray();
    resultStr2 = str2.toCharArray();

    ASSERT_STR("aaaaaaaaa\0", resultStr1);

    std::cout << "To char array str1: ";
    puts(resultStr1);
    std::cout << "To char array str2: ";
    puts(resultStr2);

    // Delete data of givetest but str1 and str2 also deleted
    delete givetest;
    puts(str1.toCharArray());
    puts(str2.toCharArray());
}

