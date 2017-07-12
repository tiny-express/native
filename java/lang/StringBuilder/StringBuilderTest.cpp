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
    int numberOfCharacters = 0;
    StringBuilder stringBuilder;
    Array<Character> arrayOfCharacters({'1', '2', '3'});
    numberOfCharacters = numberOfCharacters + arrayOfCharacters.length;
    stringBuilder.append(arrayOfCharacters);
    ASSERT_EQUAL(numberOfCharacters, stringBuilder.length());
    String aString = "123";
    stringBuilder.append(aString);
    numberOfCharacters = numberOfCharacters + aString.length();
    ASSERT_EQUAL(numberOfCharacters, stringBuilder.length());
    stringBuilder.append(aString.toString());
    numberOfCharacters = numberOfCharacters + aString.length();
    ASSERT_EQUAL(numberOfCharacters, stringBuilder.length());
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
        ASSERT_STR("index is out of range", e.getMessage().toString());
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

TEST(JavaLang, StringBuilderLength) {
    String aString("Hello! I'm a String");
    StringBuilder stringBuilder(aString);
    ASSERT_EQUAL(aString.length(), stringBuilder.length());
}

TEST(JavaLang, StringBuilderSubString) {
    StringBuilder stringBuilder((const string)"Hello Vietnam");
    ASSERT_STR("Vietnam", stringBuilder.substring(6).toString());
}

TEST(JavaLang, StringBuilderToString) {
    String aString = "Hello!";
    StringBuilder stringBuilder(aString.toString());
    string cString = stringBuilder.toString();
    ASSERT_TRUE(aString == String(cString));
    free(cString);
}

TEST(JavaLang, StringBuilderTrimToSize) {
    StringBuilder stringBuilder(100);
    ASSERT_EQUAL(100, stringBuilder.capacity());
    stringBuilder.trimToSize();
    ASSERT_EQUAL(0, stringBuilder.capacity());
    stringBuilder.append({'1', '2', '3'});
    stringBuilder.trimToSize();
    ASSERT_EQUAL(3, stringBuilder.capacity());
}
