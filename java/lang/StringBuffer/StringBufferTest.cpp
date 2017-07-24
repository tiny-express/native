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
#include "../NegativeArraySizeException/NegativeArraySizeException.hpp"
#include "../IllegalArgumentException/IllegalArgumentException.hpp"

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

    // Init a StringBuffer with negative specific capacity;
    try {
        StringBuffer negetiveCapacityConstructor = StringBuffer(-1);
    }
    catch (NegativeArraySizeException e) {
        ASSERT_STR("Capacity must be non-negative", e.getMessage().toString());
    }

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
    CharSequence *nullSequence = nullptr;
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

TEST (JavaLang, StringBufferAppendSubCharArray) {
    StringBuffer stringAppend = StringBuffer("please");
    // Append "add more" to stringAppend
    string stringToAppend = (string)("don't add more");
    stringAppend.append(stringToAppend, 5, 9);
    string expectString = (string)"please add more";
    ASSERT_STR(expectString, stringAppend.getValue());

    // Test (offset + len) > stringBuffer.length()
    try {
        stringAppend.append(stringToAppend, 20, 2);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR(expectString, stringAppend.getValue());
    }

    // Test negative offset
    try {
        stringAppend.append(stringToAppend, -1, 5);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR(expectString, stringAppend.getValue());
    }

    // Test negative len
    try {
        stringAppend.append(stringToAppend, 5, -1);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR(expectString, stringAppend.getValue());
    }
}

TEST (JavaLang, StringBufferAppend) {
    // Test string
    StringBuffer charArrayAppendStringBuffer = StringBuffer("please");

    string stringToAppend = (string)(" add more");
    charArrayAppendStringBuffer.append(stringToAppend);
    string expectString = (string)"please add more";
    ASSERT_STR(expectString, charArrayAppendStringBuffer.getValue());

    // Test String
    StringBuffer stringAppendStringBuffer = StringBuffer("please");
    stringAppendStringBuffer.append(stringToAppend);
    ASSERT_STR(expectString, stringAppendStringBuffer.getValue());

    // Test Object
    StringBuffer objectAppendStringBuffer = StringBuffer();

    Object *objToAppend = new String("object");
    objectAppendStringBuffer.append(objToAppend);
    string objString = objToAppend->toString();
    ASSERT_STR(objString, objectAppendStringBuffer.getValue());
    String *objToAppendString = dynamic_cast<String *>(objToAppend);
    delete objToAppendString;

    // Test Null object
    StringBuffer nullObjectAppendStringBuffer = StringBuffer();

    Object *nullObjToAppend = nullptr;
    nullObjectAppendStringBuffer.append(nullObjToAppend);
    string nullObjString = (string)"null";
    ASSERT_STR(nullObjString, nullObjectAppendStringBuffer.getValue());

    // Test number
    StringBuffer numberAppendStringBuffer = StringBuffer("100");

    // float
    float floatToAppend = 9.0;
    numberAppendStringBuffer.append(floatToAppend);
    string expectFloatAppend = (string)"1009";
    ASSERT_STR(expectFloatAppend, numberAppendStringBuffer.getValue());

    // double
    double doubleToAppend = 100.0;
    numberAppendStringBuffer.append(doubleToAppend);
    string expectDoubleAppend = (string)"1009100";
    ASSERT_STR(expectDoubleAppend, numberAppendStringBuffer.getValue());

    // int
    int intToAppend = 9;
    numberAppendStringBuffer.append(intToAppend);
    string expectIntAppend = (string)"10091009";
    ASSERT_STR(expectIntAppend, numberAppendStringBuffer.getValue());

    // long
    long longToAppend = 900L;
    numberAppendStringBuffer.append(longToAppend);
    string expectLongAppend = (string)"10091009900";
    ASSERT_STR(expectLongAppend, numberAppendStringBuffer.getValue());

    // Test boolean
    StringBuffer boolAppendStringBuffer = StringBuffer("bool ");

    boolean boolToAppend = true;
    boolAppendStringBuffer.append(boolToAppend);
    string expectBoolAppend = (string)"bool true";
    ASSERT_STR(expectBoolAppend, boolAppendStringBuffer.getValue());

    // Test boolean
    StringBuffer charAppendStringBuffer = StringBuffer("Character is : ");

    char charToAppend = 'A';
    charAppendStringBuffer.append(charToAppend);
    string expectCharAppend = (string)"Character is : A";
    ASSERT_STR(expectCharAppend, charAppendStringBuffer.getValue());

    // Test StringBuffer
    StringBuffer stringBufferAppendStringBuffer = StringBuffer("StringBuffer is : ");

    StringBuffer *stringBufferToAppend = new StringBuffer("not null");
    stringBufferAppendStringBuffer.append(stringBufferToAppend);
    string expectStringBufferAppend = (string)"StringBuffer is : not null";
    ASSERT_STR(expectStringBufferAppend, stringBufferAppendStringBuffer.getValue());
    delete stringBufferToAppend;

    // Test null StringBuffer
    StringBuffer nullStringBufferAppendStringBuffer = StringBuffer("StringBuffer is : ");

    StringBuffer *nullStringBufferToAppend = nullptr;
    nullStringBufferAppendStringBuffer.append(nullStringBufferToAppend);
    string expectNullStringBufferAppend = (string)"StringBuffer is : null";
    ASSERT_STR(expectNullStringBufferAppend, nullStringBufferAppendStringBuffer.getValue());
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

    // Test minimum capacity = 20
    int expectMinimumTwentyCapacity = 34;
    stringBuffer.ensureCapacity(20);
    ASSERT_EQUAL(expectMinimumTwentyCapacity, stringBuffer.capacity());

    // Tets minimum capacity < current capacity
    int expectMinimumEightyCapacity = 34;
    stringBuffer.ensureCapacity(30);
    ASSERT_EQUAL(expectMinimumEightyCapacity, stringBuffer.capacity());

    // Test negative minimum capacity
    int expectMinNonPositiveCapacity = 34;
    stringBuffer.ensureCapacity(-1);
    ASSERT_EQUAL(expectMinNonPositiveCapacity, stringBuffer.capacity());
}

TEST (JavaLang, StringBufferAppendCodePoint) {
    StringBuffer stringBuffer = StringBuffer("Codepoint is : ");

    // Test normal codePoint
    string expectBmpCodePointResult = (string) "Codepoint is : P";
    stringBuffer.appendCodePoint(80);
    ASSERT_STR(expectBmpCodePointResult, stringBuffer.getValue());

   /* StringBuilder expectValidCodePointResultBuilder("Codepoint is : P");
    unicode MIN_HIGH_SURROGATE = (unicode) '\u000D800';
    unsigned int MIN_SUPPLEMENTARY_CODE_POINT = 0x010000;
    unicode MIN_LOW_SURROGATE = (unicode) '\u000DC00';
    char lowSurrogate = (char) ((800000 & 0x3ff) + MIN_LOW_SURROGATE);
    char highSurrogate = (char) ((((unsigned)800000) >> 10) + (MIN_HIGH_SURROGATE - (MIN_SUPPLEMENTARY_CODE_POINT >> 10)));
    expectValidCodePointResultBuilder.append(highSurrogate);
    expectValidCodePointResultBuilder.append(lowSurrogate);

    stringBuffer.appendCodePoint(800000);
    ASSERT_STR(expectValidCodePointResultBuilder.toString().toString(), stringBuffer.getValue());*/

    // Test not a codePoint
    try {
        stringBuffer.appendCodePoint(80000000);
    }
    catch (IllegalArgumentException e) {
        ASSERT_STR(expectBmpCodePointResult, stringBuffer.getValue());
    }
}

TEST (JavaLang, StringBufferCharAt) {
    StringBuffer stringBuffer = StringBuffer("CharAt");

    // Test vaild index
    char expectCharAtResult = 'A';
    ASSERT_EQUAL(expectCharAtResult, stringBuffer.charAt(4));

    // Test negative index
    try {
        char expectNegativeIndex = stringBuffer.charAt(-1);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR("index must be positive", e.getMessage().toString());
    }

    // Test equal to length index
    try {
        char expectEqualToLengthIndex = stringBuffer.charAt(stringBuffer.length());
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Test greater than length index
    try {
        char expectGreaterThanLengthIndex = stringBuffer.charAt(stringBuffer.length() + 1);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR("", e.getMessage().toString());
    }
}

TEST (JavaLang, StringBufferCodePointAt) {
    StringBuffer stringBuffer = StringBuffer("CodePointAt");

    // Test vaild index
    char expectCodePointAtResult = 'A';
    ASSERT_EQUAL(expectCodePointAtResult, stringBuffer.codePointAt(9));

    // Test negative index
    try {
        char expectNegativeIndex = stringBuffer.codePointAt(-1);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR("index must be positive", e.getMessage().toString());
    }

    // Test equal to length index
    try {
        char expectEqualToLengthIndex = stringBuffer.codePointAt(stringBuffer.length());
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Test greater than length index
    try {
        char expectGreaterThanLengthIndex = stringBuffer.codePointAt(stringBuffer.length() + 1);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR("", e.getMessage().toString());
    }
}

TEST (JavaLang, StringBufferCodePointBefore) {
    StringBuffer stringBuffer = StringBuffer("CodePointAt");

    // Test vaild index
    char expectCodePointBeforeResult = 'A';
    ASSERT_EQUAL(expectCodePointBeforeResult, stringBuffer.codePointBefore(11));

    // Test negative index
    try {
        char expectNegativeIndex = stringBuffer.codePointBefore(-1);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR("index must be positive", e.getMessage().toString());
    }

    // Test equal to length index
    try {
        char expectEqualToLengthIndex = stringBuffer.codePointBefore(stringBuffer.length());
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Test greater than length index
    try {
        char expectGreaterThanLengthIndex = stringBuffer.codePointBefore(stringBuffer.length() + 1);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR("", e.getMessage().toString());
    }
}

TEST (JavaLang, StringBufferCodePointCount) {
    StringBuffer stringBuffer = StringBuffer("CodePointCount");

    // Test vaild beginIndex, endIndex
    int expectCodePointCount = 8;
    ASSERT_EQUAL(expectCodePointCount, stringBuffer.codePointCount(1, 9));

    // Test negative beginIndex
    try {
        char expectNegativeBegin = stringBuffer.codePointCount(-1, 9);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Test equal to length endIndex
    try {
        char expectEqualToLengthEnd = stringBuffer.codePointCount(1, stringBuffer.length());
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Test beginIndex greather than endIndex
    try {
        char expectBeginGreaterThanEnd = stringBuffer.codePointCount(10, 1);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR("", e.getMessage().toString());
    }
}

TEST (JavaLang, StringBufferDeleteCharAt) {
    StringBuffer stringBuffer = StringBuffer("Delete char at");

    // Test vaild index
    string expectDeleteCharResult = (string) "Delete cha at";
    stringBuffer.deleteCharAt(10);
    ASSERT_STR(expectDeleteCharResult, stringBuffer.getValue());

    // Test negative index
    try {
        stringBuffer.deleteCharAt(-1);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR(expectDeleteCharResult, stringBuffer.getValue());
        ASSERT_STR("index must be positive", e.getMessage().toString());
    }

    // Test equal to length index
    try {
        stringBuffer.deleteCharAt(stringBuffer.length());
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR(expectDeleteCharResult, stringBuffer.getValue());
    }

    // Test greater than length index
    try {
        stringBuffer.deleteCharAt(stringBuffer.length() + 1);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR(expectDeleteCharResult, stringBuffer.getValue());
    }
}

TEST (JavaLang, StringBufferDelete) {
    StringBuffer stringBuffer = StringBuffer("Delete char at");

    // Test vaild start, end
    string expectDeleteCharResult = (string) "Delete at";
    stringBuffer.deletes(7, 12);
    ASSERT_STR(expectDeleteCharResult, stringBuffer.getValue());

    // Test start equal to end
    stringBuffer.deletes(7, 7);
    ASSERT_STR(expectDeleteCharResult, stringBuffer.getValue());

    // Test end greater than length
    string expectEndGreaterThanLengthResult = (string) "Delete";
    stringBuffer.deletes(6, 12);
    ASSERT_STR(expectEndGreaterThanLengthResult, stringBuffer.getValue());

    // Test start equal to length
    stringBuffer.deletes(6, 10);
    ASSERT_STR(expectEndGreaterThanLengthResult, stringBuffer.getValue());

    // Test negative start
    try {
        stringBuffer.deletes(-1, 9);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR("index must be positive", e.getMessage().toString());
        ASSERT_STR(expectEndGreaterThanLengthResult, stringBuffer.getValue());
    }

    // Test start greater than length
    try {
        stringBuffer.deletes(7, 10);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR("", e.getMessage().toString());
        ASSERT_STR(expectEndGreaterThanLengthResult, stringBuffer.getValue());

    }

    // Test startIndex greather than endIndex
    try {
        stringBuffer.deletes(5, 1);
    }
    catch (IndexOutOfBoundsException e) {
        ASSERT_STR(expectEndGreaterThanLengthResult, stringBuffer.getValue());
        ASSERT_STR("", e.getMessage().toString());
    }
}