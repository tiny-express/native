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

#include "../StringBuilder/StringBuilder.hpp"

using namespace Java::Lang;

TEST(JavaLang, StringBuilderConstructor) {
    const int defaultOriginalCapacity = 16;
    StringBuilder defaultStringBuilder;
    ASSERT_EQUAL(0, defaultStringBuilder.length());
    ASSERT_EQUAL(defaultOriginalCapacity, defaultStringBuilder.capacity());

    StringBuilder customCapacityStringBuilder(20);
    ASSERT_EQUAL(0, customCapacityStringBuilder.length());
    ASSERT_EQUAL(20, customCapacityStringBuilder.capacity());

    String aString = "Hello! Welcome to VietNam!";
    int aStringLength = aString.length();
    StringBuilder nullTerminatedStringStringBuilder(aString.toString());
    StringBuilder stringStringBuilder(aString);
    int newCapacity = defaultOriginalCapacity + aStringLength;
    ASSERT_EQUAL(aStringLength, nullTerminatedStringStringBuilder.length());
    ASSERT_EQUAL(newCapacity, nullTerminatedStringStringBuilder.capacity());
    ASSERT_EQUAL(aStringLength, stringStringBuilder.length());
    ASSERT_EQUAL(newCapacity, stringStringBuilder.capacity());

    StringBuilder initializerListStringBuilder({'a', 'b', 'c'});
    ASSERT_EQUAL(3, initializerListStringBuilder.length());
    ASSERT_EQUAL(defaultOriginalCapacity + initializerListStringBuilder.length(), initializerListStringBuilder.capacity());
}

TEST(JavaLang, StringBuilderDestructor) {
    // Destructor will be called automatically.
    StringBuilder stringBuilder;

    // Destructor will be called by delete operator.
    StringBuilder *pStringBuilder = new StringBuilder();
    delete pStringBuilder;
}

TEST(JavaLang, StringBuilderAppend) {
    // Array of Character or char
    StringBuilder stringBuilder1;
    Array<char> arrayOfChar({'1','2','3'});
    stringBuilder1.append(arrayOfChar);
    ASSERT_STR("123", stringBuilder1.toString().toString());
    Array<Character> arrayOfCharacter({Character('4'), Character('5'), Character('6')});
    stringBuilder1.append(arrayOfCharacter);
    ASSERT_STR("123456", stringBuilder1.toString().toString());

    // String and string (const string)
    StringBuilder stringBuilder2;
    String aString = "123";
    stringBuilder2.append(aString);
    ASSERT_STR("123", stringBuilder2.toString().toString());
    stringBuilder2.append((const string)"456");
    ASSERT_STR("123456", stringBuilder2.toString().toString());

    // Double and double, Float and float, Integer and int, Long and long
    StringBuilder stringBuilder3;
    stringBuilder3.append(Double(0.8));
    ASSERT_STR("0.8", stringBuilder3.toString().toString());
    stringBuilder3.append(0.8);
    ASSERT_STR("0.80.8", stringBuilder3.toString().toString());
    stringBuilder3.append(Float(0.7f));
    ASSERT_STR("0.80.80.7", stringBuilder3.toString().toString());
    stringBuilder3.append(0.7f);
    ASSERT_STR("0.80.80.70.7", stringBuilder3.toString().toString());
    stringBuilder3.append(Integer(10));
    ASSERT_STR("0.80.80.70.710", stringBuilder3.toString().toString());
    stringBuilder3.append(100);
    ASSERT_STR("0.80.80.70.710100", stringBuilder3.toString().toString());
    stringBuilder3.append(Long(1000l));
    ASSERT_STR("0.80.80.70.7101001000", stringBuilder3.toString().toString());
    stringBuilder3.append(1001L);
    ASSERT_STR("0.80.80.70.71010010001001", stringBuilder3.toString().toString());

    // Boolean and boolean
    StringBuilder stringBuilder4;
    stringBuilder4.append(Boolean(true));
    ASSERT_STR("true", stringBuilder4.toString().toString());
    stringBuilder4.append(Boolean(false));
    ASSERT_STR("truefalse", stringBuilder4.toString().toString());
    stringBuilder4.append(true);
    ASSERT_STR("truefalsetrue", stringBuilder4.toString().toString());
    stringBuilder4.append(false);
    ASSERT_STR("truefalsetruefalse", stringBuilder4.toString().toString());

    StringBuilder stringBuilder5;
    stringBuilder5.append(Character('a'));
    stringBuilder5.append('b');
    ASSERT_STR("ab", stringBuilder5.toString().toString());

    StringBuilder stringBuilder6((const string)"abc");
    stringBuilder6.append(Array<Character> {'1', '2', '3'}, 1, 2);
    ASSERT_STR("abc23", stringBuilder6.toString().toString());
    stringBuilder6.append(Array<char> {'x', 'y', 'z'}, 0, 2);
    ASSERT_STR("abc23xy", stringBuilder6.toString().toString());
}

TEST(JavaLang, StringBuilderCapacity) {
    StringBuilder stringBuilder(100);
    ASSERT_EQUAL(100, stringBuilder.capacity());
}

TEST(JavaLang, StringBuilderCharAt) {
    StringBuilder stringBuilder({'a', 'b', 'c'});
    ASSERT_EQUAL('a', stringBuilder.charAt(0));
    ASSERT_EQUAL('b', stringBuilder.charAt(1));
    ASSERT_EQUAL('c', stringBuilder.charAt(2));
    try {
        stringBuilder.charAt(999);
    }
    catch (Exception e) {
        ASSERT_STR("String index out of range: 999", e.getMessage().toString());
    }
}

TEST(JavaLang, StringBuilderEnsureCapacity) {
    StringBuilder stringBuilder;
    ASSERT_EQUAL(0, stringBuilder.length());
    ASSERT_EQUAL(16, stringBuilder.capacity());
    stringBuilder.ensureCapacity(10);
    ASSERT_EQUAL(16, stringBuilder.capacity());
    stringBuilder.ensureCapacity(17);
    ASSERT_EQUAL(2 * 16 + 2, stringBuilder.capacity());
    stringBuilder.ensureCapacity(100);
    ASSERT_EQUAL(100, stringBuilder.capacity());
}

TEST(JavaLang, StringBuilderIndexOf) {
    StringBuilder stringBuilder((const string)"Welcome to Vietnam");
    ASSERT_EQUAL(0, stringBuilder.indexOf((const string)"Welcome"));
    ASSERT_EQUAL(0, stringBuilder.indexOf(String("Welcome")));
    ASSERT_EQUAL(11, stringBuilder.indexOf((const string)"Vietnam"));
    ASSERT_EQUAL(11, stringBuilder.indexOf(String("Vietnam")));
    ASSERT_EQUAL(-1, stringBuilder.indexOf((const string)"Hello"));
    ASSERT_EQUAL(-1, stringBuilder.indexOf(String("Hello")));
    stringBuilder.append((const string)" Vietnam");
    ASSERT_STR("Welcome to Vietnam Vietnam", stringBuilder.toString().toString());
    ASSERT_EQUAL(11, stringBuilder.indexOf((const string)"Vietnam", 10));
    ASSERT_EQUAL(11, stringBuilder.indexOf(String("Vietnam"), 10));
    ASSERT_EQUAL(11, stringBuilder.indexOf((const string)"Vietnam", 11));
    ASSERT_EQUAL(11, stringBuilder.indexOf(String("Vietnam"), 11));
    ASSERT_EQUAL(19, stringBuilder.indexOf((const string)"Vietnam", 12));
    ASSERT_EQUAL(19, stringBuilder.indexOf(String("Vietnam"), 12));
    ASSERT_EQUAL(-1, stringBuilder.indexOf((const string)"Vietnam", 20));
    ASSERT_EQUAL(-1, stringBuilder.indexOf(String("Vietnam"), 20));
}

TEST(JavaLang, StringBuilderInsert) {
    // String and string
    StringBuilder stringBuilder1((const string)"123");
    stringBuilder1.insert(1, (const string)"xxx");
    ASSERT_STR("1xxx23", stringBuilder1.toString().toString());
    stringBuilder1.insert(1, String("yyy"));
    ASSERT_STR("1yyyxxx23", stringBuilder1.toString().toString());

    // Boolean and boolean
    StringBuilder stringBuilder2((const string)"1 = 1 is ");
    stringBuilder2.insert(stringBuilder2.length(), Boolean(true));
    ASSERT_STR("1 = 1 is true", stringBuilder2.toString().toString());
    stringBuilder2.insert(0, false);
    ASSERT_STR("false1 = 1 is true", stringBuilder2.toString().toString());

    // Long and long, Integer and int,
    StringBuilder stringBuilder3((const string)"0");
    stringBuilder3.insert(1, 1000l);
    ASSERT_STR("01000", stringBuilder3.toString().toString());
    stringBuilder3.insert(1, Long(10l));
    ASSERT_STR("0101000", stringBuilder3.toString().toString());
    stringBuilder3.insert(0, 10);
    ASSERT_STR("100101000", stringBuilder3.toString().toString());
    stringBuilder3.insert(0, Integer(100));
    ASSERT_STR("100100101000", stringBuilder3.toString().toString());

    // Float and float, Double and double
    StringBuilder stringBuilder4((const string)"abc");
    stringBuilder4.insert(1, 0.8f);
    ASSERT_STR("a0.8bc", stringBuilder4.toString().toString());
    stringBuilder4.insert(0, 0.7f);
    ASSERT_STR("0.7a0.8bc", stringBuilder4.toString().toString());
    stringBuilder4.insert(0, 0.1);
    ASSERT_STR("0.10.7a0.8bc", stringBuilder4.toString().toString());
    stringBuilder4.insert(1, Double(0.2));
    ASSERT_STR("00.2.10.7a0.8bc", stringBuilder4.toString().toString());

    // Character and char
    StringBuilder stringBuilder5((const string)"abc");
    stringBuilder5.insert(1, 'x');
    ASSERT_STR("axbc", stringBuilder5.toString().toString());
    stringBuilder5.insert(1, Character('y'));
    ASSERT_STR("ayxbc", stringBuilder5.toString().toString());

    // Array<Character> and Array<char>
    StringBuilder stringBuilder6((const string)"abc");
    stringBuilder6.insert(0, Array<char>{'1', '2', '3'});
    ASSERT_STR("123abc", stringBuilder6.toString().toString());
    stringBuilder6.insert(1, Array<Character> {Character('x'), Character('y'), Character('z')});
    ASSERT_STR("1xyz23abc", stringBuilder6.toString().toString());

    // Sub array of Array<Character> and Array<char>
    StringBuilder stringBuilder7((const string)"abc");
    stringBuilder7.insert(1, Array<char>{'1', '2', '3'}, 1, 2);
    ASSERT_STR("a23bc", stringBuilder7.toString().toString());
    stringBuilder7.insert(1, Array<Character> {Character('x'), Character('y'), Character('z')}, 1, 1);
    ASSERT_STR("ay23bc", stringBuilder7.toString().toString());
}

TEST(JavaLang, StringBuilderLastIndexOf) {
    StringBuilder stringBuilder((const string)"Welcome to Vietnam");
    ASSERT_STR("Welcome to Vietnam", stringBuilder.toString().toString());
    ASSERT_EQUAL(11, stringBuilder.lastIndexOf((const string)"Vietnam"));
    ASSERT_EQUAL(11, stringBuilder.lastIndexOf(String("Vietnam")));
    ASSERT_EQUAL(0, stringBuilder.lastIndexOf((const string)"Welcome"));
    ASSERT_EQUAL(0, stringBuilder.lastIndexOf(String("Welcome")));
    ASSERT_EQUAL(-1, stringBuilder.lastIndexOf((const string)"Vietnam", 11));
    ASSERT_EQUAL(-1, stringBuilder.lastIndexOf(String("Vietnam"), 11));
    ASSERT_EQUAL(-1, stringBuilder.lastIndexOf((const string)"Vietnam", 12));
    ASSERT_EQUAL(-1, stringBuilder.lastIndexOf(String("Vietnam"), 12));
    ASSERT_EQUAL(11, stringBuilder.lastIndexOf((const string)"Vietnam", stringBuilder.length()));
    ASSERT_EQUAL(11, stringBuilder.lastIndexOf(String("Vietnam"), stringBuilder.length()));
}

TEST(JavaLang, StringBuilderLength) {
    String aString("Hello! I'm a String");
    StringBuilder stringBuilder(aString);
    ASSERT_EQUAL(aString.length(), stringBuilder.length());
}

TEST(JavaLang, StringBuilderReverse) {
    StringBuilder stringBuilder1((const string)"ABCXYZ");
    stringBuilder1.reverse();
    ASSERT_STR("ZYXCBA", stringBuilder1.toString().toString());

    // Reverses all valid surrogate pairs are produced in reverse process.
    StringBuilder stringBuilder2((const string)"\u000DC00\u000D800");
    ASSERT_STR("\u000DC00\u000D800", stringBuilder2.toString().toString());
    stringBuilder1.reverse();
    ASSERT_STR("\u000DC00\u000D800", stringBuilder2.toString().toString());
}

TEST(JavaLang, StringBuilderSetCharAt) {
    StringBuilder stringBuilder((const string)"ABCXYZ");
    ASSERT_STR("ABCXYZ", stringBuilder.toString().toString());
    stringBuilder.setCharAt(0, 'T');
    ASSERT_STR("TBCXYZ", stringBuilder.toString().toString());
    stringBuilder.setCharAt(1, Character('V'));
    ASSERT_STR("TVCXYZ", stringBuilder.toString().toString());
}

TEST(JavaLang, StringBuilderSetLength) {
    StringBuilder stringBuilder((const string)"Hello! I'm a StringBuilder");
    ASSERT_STR("Hello! I'm a StringBuilder", stringBuilder.toString().toString());
    ASSERT_EQUAL(26, stringBuilder.length());
    stringBuilder.setLength(30);
    ASSERT_EQUAL(30, stringBuilder.length());
    ASSERT_STR("Hello! I'm a StringBuilder", stringBuilder.toString().toString());
    stringBuilder.setLength(6);
    ASSERT_EQUAL(6, stringBuilder.length());
    ASSERT_STR("Hello!", stringBuilder.toString().toString());
}

TEST(JavaLang, StringBuilderSubString) {
    StringBuilder stringBuilder((const string)"Hello Vietnam");
    ASSERT_STR("Vietnam", stringBuilder.substring(6).toString());
    ASSERT_STR("llo", stringBuilder.substring(2, 5).toString());
    try {
        stringBuilder.substring(-999);
    }
    catch (Exception e) {
        ASSERT_STR("String index out of range: -999", e.getMessage().toString());
    }
}

TEST(JavaLang, StringBuilderToString) {
    String aString = "Hello!";
    StringBuilder stringBuilder(aString.toString());
    ASSERT_TRUE(aString == stringBuilder.toString());
}

TEST(JavaLang, StringBuilderTrimToSize) {
    StringBuilder stringBuilder(100);
    ASSERT_EQUAL(100, stringBuilder.capacity());
    stringBuilder.trimToSize();
    ASSERT_EQUAL(0, stringBuilder.capacity());
    stringBuilder.append((const string)"123");
    stringBuilder.trimToSize();
    ASSERT_EQUAL(3, stringBuilder.capacity());
}
