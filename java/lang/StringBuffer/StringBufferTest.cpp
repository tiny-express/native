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


#include "../../Lang.hpp"
#include "StringBuffer.hpp"
#include "../IndexOutOfBoundsException/IndexOutOfBoundsException.hpp"
#include "../StringIndexOutOfBoundsException/StringIndexOutOfBoundsException.hpp"

extern "C" {
#include "../../../kernel/test.h"
}

using namespace Java::Lang;

TEST (JavaLang, StringBufferConstructor) {
    // Init a StringBuffer with default constructor
    StringBuffer defaultConstructor;
    int expectCapacity = 16;
    ASSERT_EQUAL(expectCapacity, defaultConstructor.capacity());

    // Init a StringBuffer with specific capacity;
    StringBuffer capacityConstructor = StringBuffer(10);
    int expectSpecificCapacity = 10;
    ASSERT_EQUAL(expectSpecificCapacity, capacityConstructor.capacity());

    // Init a StringBuffer with a charsequence
    CharSequence *sequence = new String("A string to test");
    StringBuffer charSequenceConstructor =  StringBuffer(sequence);
    int expectSequenceCapacity = sequence->length() + 16;
    int expectSequenceLength = sequence->length();
    string expectSequenceValue = sequence->toString();
    ASSERT_EQUAL(expectSequenceCapacity, charSequenceConstructor.capacity());
    ASSERT_EQUAL(expectSequenceLength, charSequenceConstructor.length());
    ASSERT_STR(expectSequenceValue, charSequenceConstructor.getValue());
    String *charSequenceString = dynamic_cast<String *>(sequence);
    delete charSequenceString;

    // Init a StringBuffer with a charsequence
    CharSequence *nullSequence = NULL;
    StringBuffer nullSequenceConstructor =  StringBuffer(nullSequence);
    int expectNullSequenceCapacity = 20;
    int expectNullSequenceLength = 4;
    string expectNullSequenceValue = (string)("null");
    ASSERT_EQUAL(expectNullSequenceCapacity, nullSequenceConstructor.capacity());
    ASSERT_EQUAL(expectNullSequenceLength, nullSequenceConstructor.length());
    ASSERT_STR(expectNullSequenceValue, nullSequenceConstructor.getValue());

    // Init a StringBuffer with a String
    String aString = "A string to test";
    StringBuffer stringConstructor = StringBuffer(aString);
    int expectStringCapacity = aString.length() + 16;
    int expectStringLength = aString.length();
    string expectStringValue = aString.toString();
    ASSERT_EQUAL(expectStringCapacity, stringConstructor.capacity());
    ASSERT_EQUAL(expectStringLength, stringConstructor.length());
    ASSERT_STR(expectStringValue, stringConstructor.getValue());

}

TEST (JavaLang, StringBufferCapacity) {
    // Init a StringBuffer with specific capacity
    StringBuffer stringBuffer = StringBuffer(16);
    int expectCapacity = 16;
    ASSERT_EQUAL(expectCapacity, stringBuffer.capacity());
}

TEST (JavaLang, StringBufferLength) {
    // Init a StringBuffer with a String
    String aString = "A string to test";
    StringBuffer stringConstructor = StringBuffer(aString);
    int expectLength = 16;
    ASSERT_EQUAL(expectLength, stringConstructor.length());
}

TEST (JavaLang, StringBufferGetValue) {
    // Init a StringBuffer with specific capacity
    String aString = "A string to test";
    StringBuffer stringBuffer = StringBuffer(aString);
    string expectValue = aString.toString();
    ASSERT_STR(expectValue, stringBuffer.getValue());
}

TEST (JavaLang, StringBufferAppendBase) {
    StringBuffer stringAppend = StringBuffer("please");

    string stringToAppend = (string)("don't add more");
    stringAppend.append(stringToAppend, 5, 9);
    string expectString = (string)"please add more";
    ASSERT_STR(expectString, stringAppend.getValue());

    try {
        stringAppend.append(stringToAppend, 20, 2);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR(expectString, stringAppend.getValue());
    }

    try {
        stringAppend.append(stringToAppend, -1, 5);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR(expectString, stringAppend.getValue());
    }

    try {
        stringAppend.append(stringToAppend, 5, -1);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR(expectString, stringAppend.getValue());
    }
}

TEST (JavaLang, StringBufferAppend) {
    StringBuffer stringAppend = StringBuffer("please");

    string stringToAppend = (string)(" add more");
    stringAppend.append(stringToAppend);
    string expectString = (string)"please add more";
    ASSERT_STR(expectString, stringAppend.getValue());

    try {
        stringAppend.append(stringToAppend, 20, 2);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR(expectString, stringAppend.getValue());
    }

    try {
        stringAppend.append(stringToAppend, -1, 5);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR(expectString, stringAppend.getValue());
    }

    try {
        stringAppend.append(stringToAppend, 5, -1);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR(expectString, stringAppend.getValue());
    }
}

TEST (JavaLang, StringBufferInsert) {
    StringBuffer stringInsert = StringBuffer("please more");

    string stringToInsert = (string)"don't insert";
    stringInsert.insert(6, stringToInsert, 5, 7);
    string expectString = (string)"please insert more";
    ASSERT_STR(expectString, stringInsert.getValue());

    try {
        stringInsert.insert(-1, stringToInsert, 6, 6);
    }
    catch (StringIndexOutOfBoundsException e) {
        ASSERT_STR(expectString, stringInsert.getValue());
    }

    try {
        stringInsert.insert(stringInsert.length() + 1, stringToInsert, 6, 6);
    }
    catch (StringIndexOutOfBoundsException e) {
        ASSERT_STR(expectString, stringInsert.getValue());
    }

    try {
        stringInsert.insert(7, stringToInsert, -6, 6);
    }
    catch (StringIndexOutOfBoundsException  e) {
        ASSERT_STR(expectString, stringInsert.getValue());
    }

    try {
        stringInsert.insert(7, stringToInsert, 6, -1);
    }
    catch (StringIndexOutOfBoundsException  e) {
        ASSERT_STR(expectString, stringInsert.getValue());
    }

    try {
        stringInsert.insert(7, stringToInsert, 20, 10);
    }
    catch (StringIndexOutOfBoundsException  e) {
        ASSERT_STR(expectString, stringInsert.getValue());
    }

}

TEST (JavaLang, StringBufferEnsureCapacity) {
    StringBuffer stringBuffer;

    int expectMinTwentyCapacity = 34;
    stringBuffer.ensureCapacity(20);
    ASSERT_EQUAL(expectMinTwentyCapacity, stringBuffer.capacity());

    int expectMinEightyCapacity = 142;
    stringBuffer.ensureCapacity(80);
    ASSERT_EQUAL(expectMinEightyCapacity, stringBuffer.capacity());

    int expectMinNonPositiveCapacity = 142;
    stringBuffer.ensureCapacity(-1);
    ASSERT_EQUAL(expectMinNonPositiveCapacity, stringBuffer.capacity());

}