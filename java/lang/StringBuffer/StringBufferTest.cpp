/**
 * Copyright (c) 2017 Food Tiny Project. All rights reserved.
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

TEST(JavaLang, StringBufferConstructor) {
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
        StringBuffer negativeCapacityConstructor = StringBuffer(-1);
    }
    catch (NegativeArraySizeException &e) {
        ASSERT_STR("Capacity must be non-negative", e.getMessage().toString());
    }

    // Init a StringBuffer with a charsequence
    CharSequence *sequence = new String("A string to test");
    StringBuffer charSequenceConstructor =  StringBuffer(*sequence);
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
    StringBuffer nullSequenceConstructor = StringBuffer(*nullSequence);
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

    // Copy Constructor
    StringBuffer other = StringBuffer("A string to test");
    StringBuffer copyConstructor = StringBuffer(other);
    ASSERT_EQUAL(expectStringCapacity, stringConstructor.capacity());
    ASSERT_EQUAL(expectStringLength, stringConstructor.length());
    ASSERT_STR(expectStringValue, stringConstructor.getValue());
}

TEST(JavaLang, StringBufferOperater) {
	StringBuffer other = StringBuffer("A string to test");
	StringBuffer stringBuffer;
	stringBuffer = other;
	ASSERT_EQUAL(other.capacity(), stringBuffer.capacity());
	ASSERT_EQUAL(other.length(), stringBuffer.length());
	ASSERT_STR(other.getValue(), stringBuffer.getValue());
	
	StringBufferUnSafe otherUnSafe = StringBufferUnSafe("A string to test");
	StringBufferUnSafe stringBufferUnSafe;
	stringBufferUnSafe = otherUnSafe;
	ASSERT_EQUAL(otherUnSafe.capacity(), stringBufferUnSafe.capacity());
	ASSERT_EQUAL(otherUnSafe.length(), stringBufferUnSafe.length());
	ASSERT_STR(otherUnSafe.getValue(), stringBufferUnSafe.getValue());
}

TEST(JavaLang, StringBufferCapacity) {
	// Init a StringBuffer with specific capacity
	StringBuffer stringBuffer = StringBuffer(16);
	int expectCapacity = 16;
	ASSERT_EQUAL(expectCapacity, stringBuffer.capacity());
}

TEST(JavaLang, StringBufferLength) {
	// Init a StringBuffer with a String
	String aString = "A string to test";
	StringBuffer stringConstructor = StringBuffer(aString);
	int expectLength = 16;
	ASSERT_EQUAL(expectLength, stringConstructor.length());
}

TEST(JavaLang, StringBufferGetValue) {
	// Init a StringBuffer with string
	String aString = "A string to test";
	StringBuffer stringBuffer = StringBuffer(aString);
	string expectValue = aString.toString();
	ASSERT_STR(expectValue, stringBuffer.getValue());
}

TEST(JavaLang, StringBufferAppendSubCharArray) {
	StringBuffer stringAppend = StringBuffer("please");
	
	// Append "add more" to stringAppend
	string stringToAppend = (string) ( "don't add more" );
	stringAppend.append(stringToAppend, 5, 9);
	string expectString = (string) ( "please add more" );
	ASSERT_STR(expectString, stringAppend.getValue());
	
	// TEST(offset + len) > stringBuffer.length()
	try {
		stringAppend.append(stringToAppend, 20, 2);
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR(expectString, stringAppend.getValue());
	}
	
	// Test negative offset
	try {
		stringAppend.append(stringToAppend, -1, 5);
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR(expectString, stringAppend.getValue());
	}
	
	// Test negative len
	try {
		stringAppend.append(stringToAppend, 5, -1);
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR(expectString, stringAppend.getValue());
	}
}

TEST(JavaLang, StringBufferAppend) {
    // Test string
    StringBuffer charArrayAppendStringBuffer = StringBuffer("please");

    string stringToAppend = (string)(" add more");
    charArrayAppendStringBuffer.append(stringToAppend);
    string expectString = (string)("please add more");
    ASSERT_STR(expectString, charArrayAppendStringBuffer.getValue());

    // Test String
    StringBuffer stringAppendStringBuffer = StringBuffer("please");
    String stringObjectToAppend = " add more";
    stringAppendStringBuffer.append(stringObjectToAppend);
    ASSERT_STR(expectString, stringAppendStringBuffer.getValue());

    // Test Object
    StringBuffer objectAppendStringBuffer = StringBuffer();

    Object *objToAppend = new String("object");
    objectAppendStringBuffer.append(*objToAppend);
    string objString = objToAppend->toString();
    ASSERT_STR(objString, objectAppendStringBuffer.getValue());
    String *objToAppendString = dynamic_cast<String *>(objToAppend);
    delete objToAppendString;

    // Test Null object
    StringBuffer nullObjectAppendStringBuffer = StringBuffer();

    Object *nullObjToAppend = nullptr;
    nullObjectAppendStringBuffer.append(*nullObjToAppend);
    string nullObjString = (string)("null");
    ASSERT_STR(nullObjString, nullObjectAppendStringBuffer.getValue());

    // Test number
    StringBuffer numberAppendStringBuffer = StringBuffer("100");

    // float
    float floatToAppend = 9.0;
    numberAppendStringBuffer.append(floatToAppend);
    string expectFloatAppend = (string)("1009");
    ASSERT_STR(expectFloatAppend, numberAppendStringBuffer.getValue());

    // double
    double doubleToAppend = 100.0;
    numberAppendStringBuffer.append(doubleToAppend);
    string expectDoubleAppend = (string)("1009100");
    ASSERT_STR(expectDoubleAppend, numberAppendStringBuffer.getValue());

    // int
    int intToAppend = 9;
    numberAppendStringBuffer.append(intToAppend);
    string expectIntAppend = (string)("10091009");
    ASSERT_STR(expectIntAppend, numberAppendStringBuffer.getValue());

    // long
    long longToAppend = 900L;
    numberAppendStringBuffer.append(longToAppend);
    string expectLongAppend = (string)("10091009900");
    ASSERT_STR(expectLongAppend, numberAppendStringBuffer.getValue());

    // Test boolean
    StringBuffer boolAppendStringBuffer = StringBuffer("bool ");

    boolean boolToAppend = true;
    boolAppendStringBuffer.append(boolToAppend);
    string expectBoolAppend = (string)("bool true");
    ASSERT_STR(expectBoolAppend, boolAppendStringBuffer.getValue());

    boolAppendStringBuffer = StringBuffer("bool ");

    boolToAppend = false;
    boolAppendStringBuffer.append(boolToAppend);
    expectBoolAppend = (string)("bool false");
    ASSERT_STR(expectBoolAppend, boolAppendStringBuffer.getValue());

    // Test char
    StringBuffer charAppendStringBuffer = StringBuffer("Character is : ");

    char charToAppend = 'A';
    charAppendStringBuffer.append(charToAppend);
    string expectCharAppend = (string)("Character is : A");
    ASSERT_STR(expectCharAppend, charAppendStringBuffer.getValue());

    // Test StringBuffer
    StringBuffer stringBufferAppendStringBuffer = StringBuffer("StringBuffer is : ");

    StringBuffer stringBufferToAppend = StringBuffer("not null");
    stringBufferAppendStringBuffer.append(stringBufferToAppend);
    string expectStringBufferAppend = (string)("StringBuffer is : not null");
    ASSERT_STR(expectStringBufferAppend, stringBufferAppendStringBuffer.getValue());

    // Test CharSequence
    StringBuffer charSequenceAppendStringBuffer = StringBuffer("CharSequence is : ");

    CharSequence *charSequenceToAppend = new String("not null");
    charSequenceAppendStringBuffer.append(*charSequenceToAppend);
    string expectCharSequenceAppend = (string)("CharSequence is : not null");
    ASSERT_STR(expectCharSequenceAppend, charSequenceAppendStringBuffer.getValue());

    charSequenceAppendStringBuffer.append(*charSequenceToAppend, 0, 3);
    expectCharSequenceAppend = (string)("CharSequence is : not nullnot");
    ASSERT_STR(expectCharSequenceAppend, charSequenceAppendStringBuffer.getValue());

    // Test start < 0
    try {
        charSequenceAppendStringBuffer.append(*charSequenceToAppend, -1, 3);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR(expectCharSequenceAppend, charSequenceAppendStringBuffer.getValue());
        ASSERT_STR("", e.getMessage().toString());
    }

    // Test start > end
    try {
        charSequenceAppendStringBuffer.append(*charSequenceToAppend, 3, 1);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR(expectCharSequenceAppend, charSequenceAppendStringBuffer.getValue());
        ASSERT_STR("", e.getMessage().toString());
    }

    // Test start > sequence length
    try {
        charSequenceAppendStringBuffer.append(*charSequenceToAppend,
                                              charSequenceToAppend->length() + 1,
                                              charSequenceToAppend->length() + 2);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR(expectCharSequenceAppend, charSequenceAppendStringBuffer.getValue());
        ASSERT_STR("", e.getMessage().toString());
    }

    String *charSequenceString = dynamic_cast<String *>(charSequenceToAppend);
    delete charSequenceString;
    // Test null CharSequence
    StringBuffer nullCharSequenceAppendStringBuffer = StringBuffer("CharSequence is : ");

    CharSequence *nullCharSequenceToAppend = nullptr;
    nullCharSequenceAppendStringBuffer.append(*nullCharSequenceToAppend);
    string expectNullCharSequenceAppend = (string)("CharSequence is : null");
    ASSERT_STR(expectNullCharSequenceAppend, nullCharSequenceAppendStringBuffer.getValue());
}

TEST(JavaLang, StringBufferInsertSubCharArray) {
	// Given a StringBuffer
	StringBuffer stringInsert = StringBuffer("please more");
	
	// Test vaild param
	string stringToInsert = (string) ( "don't insert" );
	stringInsert.insert(6, stringToInsert, 5, 7);
	string expectString = (string) ( "please insert more" );
	ASSERT_STR(expectString, stringInsert.getValue());
	
	// Test negative index
	try {
		stringInsert.insert(-1, stringToInsert, 6, 6);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR(expectString, stringInsert.getValue());
	}
	
	// Test index greater than length
	try {
		stringInsert.insert(stringInsert.length() + 1, stringToInsert, 6, 6);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR(expectString, stringInsert.getValue());
	}
	
	// Test negative offset
	try {
		stringInsert.insert(7, stringToInsert, -6, 6);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR(expectString, stringInsert.getValue());
	}
	
	// Test negative len
	try {
		stringInsert.insert(7, stringToInsert, 6, -1);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR(expectString, stringInsert.getValue());
	}
	
	// Test offset + len > length
	try {
		stringInsert.insert(7, stringToInsert, 20, 10);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR(expectString, stringInsert.getValue());
	}
}

TEST(JavaLang, StringBufferInsert) {
    // Test string
    StringBuffer charArrayInsertStringBuffer = StringBuffer("please more");

    string stringToInsert = (string)("add ");
    charArrayInsertStringBuffer.insert(7, stringToInsert);
    string expectString = (string)("please add more");
    ASSERT_STR(expectString, charArrayInsertStringBuffer.getValue());

    // Test String
    StringBuffer stringInsertStringBuffer = StringBuffer("please more");
    String stringObjectToInsert = "add ";
    stringInsertStringBuffer.insert(7, stringObjectToInsert);
    ASSERT_STR(expectString, stringInsertStringBuffer.getValue());

    // Test Object
    StringBuffer objectInsertStringBuffer = StringBuffer("please more");

    Object *objToInsert = new String("add ");
    objectInsertStringBuffer.insert(7, *objToInsert);
    ASSERT_STR(expectString, objectInsertStringBuffer.getValue());
    String *objToInsertString = dynamic_cast<String *>(objToInsert);
    delete objToInsertString;

    // Test Null object
    StringBuffer nullObjectInsertStringBuffer = StringBuffer("this is  pointer");

    Object *nullObjToInsert = nullptr;
    nullObjectInsertStringBuffer.insert(8, *nullObjToInsert);
    string expectInsertNullObject = (string)("this is null pointer");
    ASSERT_STR(expectInsertNullObject, nullObjectInsertStringBuffer.getValue());

    // Test number
    StringBuffer numberInsertStringBuffer = StringBuffer("100");

    // float
    float floatToInsert = 9.0;
    numberInsertStringBuffer.insert(2, floatToInsert);
    string expectFloatInsert = (string)("1090");
    ASSERT_STR(expectFloatInsert, numberInsertStringBuffer.getValue());

    // double
    double doubleToInsert = 100.0;
    numberInsertStringBuffer.insert(2, doubleToInsert);
    string expectDoubleInsert = (string)("1010090");
    ASSERT_STR(expectDoubleInsert, numberInsertStringBuffer.getValue());

    // int
    int intToInsert = 9;
    numberInsertStringBuffer.insert(2, intToInsert);
    string expectIntInsert = (string)("10910090");
    ASSERT_STR(expectIntInsert, numberInsertStringBuffer.getValue());

    // long
    long longToInsert = 900L;
    numberInsertStringBuffer.insert(2, longToInsert);
    string expectLongInsert = (string)("10900910090");
    ASSERT_STR(expectLongInsert, numberInsertStringBuffer.getValue());

    // Test boolean
    StringBuffer boolInsertStringBuffer = StringBuffer("bool  is good");

    boolean boolToInsert = true;
    boolInsertStringBuffer.insert(5, boolToInsert);
    string expectBoolInsert = (string)("bool true is good");
    ASSERT_STR(expectBoolInsert, boolInsertStringBuffer.getValue());

    boolInsertStringBuffer = StringBuffer("bool  is bad");

    boolToInsert = false;
    boolInsertStringBuffer.insert(5, boolToInsert);
    expectBoolInsert = (string)("bool false is bad");
    ASSERT_STR(expectBoolInsert, boolInsertStringBuffer.getValue());

    // Test char
    StringBuffer charInsertStringBuffer = StringBuffer("Character  is uppercase");

    char charToInsert = 'A';
    charInsertStringBuffer.insert(10, charToInsert);
    string expectCharInsert = (string)("Character A is uppercase");
    ASSERT_STR(expectCharInsert, charInsertStringBuffer.getValue());

    // Test CharSequence
    StringBuffer charSequenceInsertStringBuffer = StringBuffer("CharSequence is : null");

    CharSequence *charSequenceToInsert = new String(" not");
    charSequenceInsertStringBuffer.insert(17, *charSequenceToInsert);
    string expectCharSequenceInsert = (string)("CharSequence is : not null");
    ASSERT_STR(expectCharSequenceInsert, charSequenceInsertStringBuffer.getValue());

    // Test negative offset
    try {
        charSequenceInsertStringBuffer.insert(-1, *charSequenceToInsert);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("offset must be positive", e.getMessage().toString());
    }

    // Test null CharSequence
    StringBuffer nullCharSequenceInsertStringBuffer = StringBuffer("CharSequence is a  pointer");

    CharSequence *nullCharSequenceToInsert = nullptr;
    nullCharSequenceInsertStringBuffer.insert(18, *nullCharSequenceToInsert);
    string expectNullCharSequenceInsert = (string)("CharSequence is a null pointer");
    ASSERT_STR(expectNullCharSequenceInsert, nullCharSequenceInsertStringBuffer.getValue());

    // Test CharSequence
    StringBuffer charSequenceInsertWithOffsetStringBuffer = StringBuffer("CharSequence is : null");

    charSequenceInsertWithOffsetStringBuffer.insert(17, *charSequenceToInsert, 0, 4);
    ASSERT_STR(expectCharSequenceInsert, charSequenceInsertStringBuffer.getValue());

    // Test negative destinationOffset
    try {
        charSequenceInsertWithOffsetStringBuffer.insert(-1, *charSequenceToInsert, 0, 4);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("offset must be positive", e.getMessage().toString());
    }

    // Test destinationOffset > length
    try {
        charSequenceInsertWithOffsetStringBuffer.insert(100, *charSequenceToInsert, 0, 4);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Test negative start
    try {
        charSequenceInsertWithOffsetStringBuffer.insert(17, *charSequenceToInsert, -1, 4);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Test negative end
    try {
        charSequenceInsertWithOffsetStringBuffer.insert(17, *charSequenceToInsert, 0, -1);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Test start > end
    try {
        charSequenceInsertWithOffsetStringBuffer.insert(17, *charSequenceToInsert, 5, 4);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Test end > sequence length
    try {
        charSequenceInsertWithOffsetStringBuffer.insert(17, *charSequenceToInsert, 0, 100);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR("", e.getMessage().toString());
    }

    // Test null CharSequence
    StringBuffer nullCharSequenceInsertWithOffsetStringBuffer = StringBuffer("CharSequence is a  pointer");

    nullCharSequenceInsertWithOffsetStringBuffer.insert(18, *nullCharSequenceToInsert, 0, 3);
    ASSERT_STR(expectNullCharSequenceInsert, nullCharSequenceInsertStringBuffer.getValue());
    String *charSequenceString = dynamic_cast<String *>(charSequenceToInsert);
    delete charSequenceString;
}

TEST(JavaLang, StringBufferEnsureCapacity) {
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

TEST(JavaLang, StringBufferAppendCodePoint) {
	StringBuffer stringBuffer = StringBuffer("Codepoint is : ");
	
	// Test Bmp codePoint
	string expectBmpCodePointResult = (string) ( "Codepoint is : P" );
	stringBuffer.appendCodePoint(80);
	ASSERT_STR(expectBmpCodePointResult, stringBuffer.getValue());
	
	// Test not a codePoint
	try {
		stringBuffer.appendCodePoint(80000000);
	}
	catch (IllegalArgumentException &e) {
		ASSERT_STR(expectBmpCodePointResult, stringBuffer.getValue());
	}
	
	// TODO Test Valid codePoint
	string expectValidCodePointResult = (string) ( "Codepoint is : P�" );
	stringBuffer.appendCodePoint(800000);
	//ASSERT_STR(expectBmpCodePointResult, stringBuffer.getValue());
}

TEST(JavaLang, StringBufferCharAt) {
	StringBuffer stringBuffer = StringBuffer("CharAt");
	
	// Test vaild index
	char expectCharAtResult = 'A';
	ASSERT_EQUAL(expectCharAtResult, stringBuffer.charAt(4));
	
	// Test negative index
	try {
		char expectNegativeIndex = stringBuffer.charAt(-1);
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR("index must be positive", e.getMessage().toString());
	}
	
	// Test equal to length index
	try {
		char expectEqualToLengthIndex = stringBuffer.charAt(stringBuffer.length());
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR("", e.getMessage().toString());
	}
	
	// Test greater than length index
	try {
		char expectGreaterThanLengthIndex = stringBuffer.charAt(stringBuffer.length() + 1);
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR("", e.getMessage().toString());
	}
}

TEST(JavaLang, StringBufferCodePointAt) {
	StringBuffer stringBuffer = StringBuffer("CodePointAt");
	
	// Test vaild index
	char expectCodePointAtResult = 'A';
	ASSERT_EQUAL(expectCodePointAtResult, stringBuffer.codePointAt(9));
	
	// Test negative index
	try {
		char expectNegativeIndex = (char) ( stringBuffer.codePointAt(-1));
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR("index must be positive", e.getMessage().toString());
	}
	
	// Test equal to length index
	try {
		char expectEqualToLengthIndex = (char) ( stringBuffer.codePointAt(stringBuffer.length()));
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR("", e.getMessage().toString());
	}
	
	// Test greater than length index
	try {
		char expectGreaterThanLengthIndex = (char) ( stringBuffer.codePointAt(stringBuffer.length() + 1));
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR("", e.getMessage().toString());
	}
}

TEST(JavaLang, StringBufferCodePointBefore) {
	StringBuffer stringBuffer = StringBuffer("CodePointAt");
	
	// Test vaild index
	char expectCodePointBeforeResult = 'A';
	ASSERT_EQUAL(expectCodePointBeforeResult, stringBuffer.codePointBefore(10));
	
	// Test zero index
	try {
		char expectEqualToLengthIndex = (char) ( stringBuffer.codePointBefore(0));
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR("index must be positive", e.getMessage().toString());
	}
	
	// Test negative index
	try {
		char expectNegativeIndex = (char) ( stringBuffer.codePointBefore(-1));
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR("index must be positive", e.getMessage().toString());
	}
	
	// Test greater than length index
	try {
		char expectGreaterThanLengthIndex = (char) ( stringBuffer.codePointBefore(stringBuffer.length() + 1));
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR("", e.getMessage().toString());
	}
}

TEST(JavaLang, StringBufferCodePointCount) {
	StringBuffer stringBuffer = StringBuffer("CodePointCount");
	
	// Test vaild beginIndex, endIndex
	int expectCodePointCount = 8;
	ASSERT_EQUAL(expectCodePointCount, stringBuffer.codePointCount(1, 9));
	
	// Test negative beginIndex
	try {
		int expectNegativeBegin = stringBuffer.codePointCount(-1, 9);
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR("", e.getMessage().toString());
	}
	
	// Test greater than length endIndex
	try {
		int expectEqualToLengthEnd = stringBuffer.codePointCount(1, stringBuffer.length() + 1);
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR("", e.getMessage().toString());
	}
	
	// Test beginIndex greather than endIndex
	try {
		int expectBeginGreaterThanEnd = stringBuffer.codePointCount(10, 1);
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR("", e.getMessage().toString());
	}
}

TEST(JavaLang, StringBufferDeleteCharAt) {
	StringBuffer stringBuffer = StringBuffer("Delete char at");
	
	// Test vaild index
	string expectDeleteCharResult = (string) ( "Delete cha at" );
	stringBuffer.deleteCharAt(10);
	ASSERT_STR(expectDeleteCharResult, stringBuffer.getValue());
	
	// Test negative index
	try {
		stringBuffer.deleteCharAt(-1);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR(expectDeleteCharResult, stringBuffer.getValue());
		ASSERT_STR("index must be positive", e.getMessage().toString());
	}
	
	// Test equal to length index
	try {
		stringBuffer.deleteCharAt(stringBuffer.length());
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR(expectDeleteCharResult, stringBuffer.getValue());
	}
	
	// Test greater than length index
	try {
		stringBuffer.deleteCharAt(stringBuffer.length() + 1);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR(expectDeleteCharResult, stringBuffer.getValue());
	}
}

TEST(JavaLang, StringBufferDelete) {
	StringBuffer stringBuffer = StringBuffer("Delete char at");
	
	// Test vaild start, end
	string expectDeleteCharResult = (string) ( "Delete at" );
	stringBuffer.deletes(7, 12);
	ASSERT_STR(expectDeleteCharResult, stringBuffer.getValue());
	
	// Test start equal to end
	stringBuffer.deletes(7, 7);
	ASSERT_STR(expectDeleteCharResult, stringBuffer.getValue());
	
	// Test end greater than length
	string expectEndGreaterThanLengthResult = (string) ( "Delete" );
	stringBuffer.deletes(6, 12);
	ASSERT_STR(expectEndGreaterThanLengthResult, stringBuffer.getValue());
	
	// Test start equal to length
	stringBuffer.deletes(6, 10);
	ASSERT_STR(expectEndGreaterThanLengthResult, stringBuffer.getValue());
	
	// Test negative start
	try {
		stringBuffer.deletes(-1, 9);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR("index must be positive", e.getMessage().toString());
		ASSERT_STR(expectEndGreaterThanLengthResult, stringBuffer.getValue());
	}
	
	// Test start greater than length
	try {
		stringBuffer.deletes(7, 10);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR("", e.getMessage().toString());
		ASSERT_STR(expectEndGreaterThanLengthResult, stringBuffer.getValue());
	}
	
	// Test startIndex greather than endIndex
	try {
		stringBuffer.deletes(5, 1);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR(expectEndGreaterThanLengthResult, stringBuffer.getValue());
		ASSERT_STR("", e.getMessage().toString());
	}
}

// TODO need getChar
/*
TEST(JavaLang, StringBufferGetChar) {
    // Given a StringBuffer
    StringBuffer stringBuffer = StringBuffer("StringBuffer");
    // Destination string
    string destinationString = (string)("Copy from : !!!");

    // Test vaild param
    string expectGetCharResult = (string)("Copy from : StringBuffer !!!");
    stringBuffer.getChars(0, 12, destinationString, 11);
    ASSERT_STR(expectGetCharResult, destinationString);

    // Test negative sourceBegin
    try {
        stringBuffer.getChars(-1, 1, destinationString, 6);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR(expectGetCharResult, destinationString);
    }

    // Test negative destinationBegin
    try {
        stringBuffer.getChars(1, 1, destinationString, -6);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR(expectGetCharResult, destinationString);
    }

    // Test sourceBegin greater than sourceEnd
    try {
        stringBuffer.getChars(5, 1, destinationString, 6);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR(expectGetCharResult, destinationString);
    }

    // Test sourceEnd greater than length
    try {
        stringBuffer.getChars(1, stringBuffer.length() + 1, destinationString, 6);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR(expectGetCharResult, destinationString);
    }

    // Test destinationBegin + sourceEnd - sourceBegin greater than destination.length
    try {
        stringBuffer.getChars(1, 10, destinationString, 6);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR(expectGetCharResult, destinationString);
    }
}*/

TEST(JavaLang, StringBufferIndexOf) {
	// Given a StringBuffer
	StringBuffer stringBuffer = StringBuffer("This is a StringBuffer");
	// Given 2 subString
	String isSubString = "is a";
	String notSubString = "is not";
	
	// Test isSubString
	int expectIsSubStringResult = 5;
	int actualIsSubStringResult = stringBuffer.indexOf(isSubString);
	ASSERT_EQUAL(expectIsSubStringResult, actualIsSubStringResult);
	
	// Test notSubString
	int expectNotSubStringResult = -1;
	int actualNotSubStringResult = stringBuffer.indexOf(notSubString);
	ASSERT_EQUAL(expectNotSubStringResult, actualNotSubStringResult);
}

TEST(JavaLang, StringBufferIndexOfFromIndex) {
	// Given a StringBuffer
	StringBuffer stringBuffer = StringBuffer("This is a StringBuffer. This is a StringBuffer");
	// Given 2 subString
	String isSubString = "is a";
	String notSubString = "is not";
	
	// Test isSubString
	int expectIsSubStringResult = 29;
	int actualIsSubStringResult = stringBuffer.indexOf(isSubString, 10);
	ASSERT_EQUAL(expectIsSubStringResult, actualIsSubStringResult);
	
	// Test notSubString
	int expectNotSubStringResult = -1;
	int actualNotSubStringResult = stringBuffer.indexOf(notSubString, 10);
	ASSERT_EQUAL(expectNotSubStringResult, actualNotSubStringResult);
}

TEST(JavaLang, StringBufferLastIndexOf) {
	// Given a StringBuffer
	StringBuffer stringBuffer = StringBuffer("This is a StringBuffer. This is a StringBuffer. This is a StringBuffer");
	// Given 2 subString
	String isSubString = "is a";
	String notSubString = "is not";
	
	// Test isSubString
	int expectIsSubStringResult = 53;
	int actualIsSubStringResult = stringBuffer.lastIndexOf(isSubString);
	ASSERT_EQUAL(expectIsSubStringResult, actualIsSubStringResult);
	
	// Test notSubString
	int expectNotSubStringResult = -1;
	int actualNotSubStringResult = stringBuffer.lastIndexOf(notSubString);
	ASSERT_EQUAL(expectNotSubStringResult, actualNotSubStringResult);
}

TEST(JavaLang, StringBufferLastIndexOfFromIndex) {
	// Given a StringBuffer
	StringBuffer stringBuffer = StringBuffer("This is a StringBuffer. This is a StringBuffer. This is a StringBuffer");
	// Given 2 subString
	String isSubString = "is a";
	String notSubString = "is not";
	
	// Test isSubString
	int expectIsSubStringFromIndexResult = 29;
	int actualIsSubStringFromIndexResult = stringBuffer.lastIndexOf(isSubString, 29);
	ASSERT_EQUAL(expectIsSubStringFromIndexResult, actualIsSubStringFromIndexResult);
	
	// Test isSubString
	int expectNotSubStringFromIndexResult = -1;
	int actualNotSubStringFromIndexResult = stringBuffer.lastIndexOf(isSubString, 4);
	ASSERT_EQUAL(expectNotSubStringFromIndexResult, actualNotSubStringFromIndexResult);
	
	// Test notSubString
	int expectNotSubStringResult = -1;
	int actualNotSubStringResult = stringBuffer.lastIndexOf(notSubString, 30);
	ASSERT_EQUAL(expectNotSubStringResult, actualNotSubStringResult);
}

TEST(JavaLang, StringBufferOffSetByCodePoint) {
	// Given a StringBuffer
	StringBuffer stringBuffer = StringBuffer("This is a string buffer");
	
	// Test vaild param
	int expectOffsetByCodePointsResult = 0; // 5
	int actualOffsetByCodePointsResult = stringBuffer.offsetByCodePoints(1, 4);
	ASSERT_EQUAL(expectOffsetByCodePointsResult, actualOffsetByCodePointsResult);
	
	// Test index < 0
	try {
		int negativeIndexResult = stringBuffer.offsetByCodePoints(-1, 4);
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR("", e.getMessage().toString());
	}
	
	// Test index > length()
	try {
		int greaterThanLengthIndexResult = stringBuffer.offsetByCodePoints(stringBuffer.length() + 1, 4);
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR("", e.getMessage().toString());
	}
}

TEST(JavaLang, StringBufferReplace) {
	// Given a stringBuffer
	StringBuffer stringBuffer = StringBuffer("This is a StringBuffer");
	
	// Given a string
	String stringToReplace = (string) ( "Butter" );
	
	// Test vaild param
	string expectReplaceResult = (string) ( "This is a StringButter" );
	stringBuffer.replace(16, 22, stringToReplace);
	ASSERT_STR(expectReplaceResult, stringBuffer.getValue());
	
	// Test end greater than length
	string expectEndGreaterThanLength = (string) ( "This is a StringButButter" );
	stringBuffer.replace(19, 30, stringToReplace);
	ASSERT_STR(expectEndGreaterThanLength, stringBuffer.getValue());
	
	// Test end - start > str length
	string expectReplaceRangeGreaterThanStringLength = (string) ( "This is a StringButter" );
	stringBuffer.replace(16, 25, stringToReplace);
	ASSERT_STR(expectReplaceRangeGreaterThanStringLength, stringBuffer.getValue());
	
	// Test end - start < str length
	string expectReplaceRangeSmallerThanStringLength = (string) ( "This is a StringButterutter" );
	stringBuffer.replace(16, 17, stringToReplace);
	ASSERT_STR(expectReplaceRangeSmallerThanStringLength, stringBuffer.getValue());
	
	string expectNotChangeResult = (string) ( "This is a StringButterutter" );
	
	// Test negative start
	try {
		stringBuffer.replace(-1, 10, stringToReplace);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR("start must be positive", e.getMessage().toString());
		ASSERT_STR(expectNotChangeResult, stringBuffer.getValue());
	}
	
	// Test start greater than length
	try {
		stringBuffer.replace(stringBuffer.length() + 1, 10, stringToReplace);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR("", e.getMessage().toString());
		ASSERT_STR(expectNotChangeResult, stringBuffer.getValue());
	}
	
	// Test start greater than end
	try {
		stringBuffer.replace(10, 1, stringToReplace);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR("", e.getMessage().toString());
		ASSERT_STR(expectNotChangeResult, stringBuffer.getValue());
	}
}

TEST(JavaLang, StringBufferReverse) {
	// Given a stringBuffer
	StringBuffer stringBuffer = StringBuffer("ABCDEFGH");
	
	// Test nomal string
	stringBuffer.reverse();
	string expectNomalStringReverse = (string) ( "HGFEDCBA" );
	ASSERT_STR(expectNomalStringReverse, stringBuffer.getValue());
	
	// TODO handle surrogate as one char
	/* // Test surrogate string
	 StringBuffer surrogateStringBuffer = StringBuffer("\u000DC00\u000D800");
	 surrogateStringBuffer.reverse();
	 string expectSurrogateStringReverse = (string)("\u000D800\u000DC00");
	 ASSERT_STR(expectSurrogateStringReverse, surrogateStringBuffer.getValue());*/
}

TEST(JavaLang, StringBufferSetCharAt) {
	// Given a stringBuffer
	StringBuffer stringBuffer = StringBuffer("ABCDEFGH");
	
	// Test vaild index
	stringBuffer.setCharAt(3, 'd');
	string expectSetCharAtResult = (string) ( "ABCdEFGH" );
	ASSERT_STR(expectSetCharAtResult, stringBuffer.getValue());
	
	// Test negative Index
	try {
		stringBuffer.setCharAt(-1, 'd');
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR(expectSetCharAtResult, stringBuffer.getValue());
		ASSERT_STR("index must be positive", e.getMessage().toString());
	}
	
	// Test index greater than length
	try {
		stringBuffer.setCharAt(stringBuffer.length() + 1, 'd');
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR(expectSetCharAtResult, stringBuffer.getValue());
		ASSERT_STR("", e.getMessage().toString());
	}
	
	// Test index equal to length
	try {
		stringBuffer.setCharAt(stringBuffer.length(), 'd');
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR(expectSetCharAtResult, stringBuffer.getValue());
		ASSERT_STR("", e.getMessage().toString());
	}
}

TEST(JavaLang, StringBufferSetLength) {
	// Given a stringBuffer
	StringBuffer stringBuffer = StringBuffer("ABCDEFGH");
	
	// Test new length < current length
	stringBuffer.setLength(6);
	string expectSetCharAtResult = (string) ( "ABCDEF" );
	ASSERT_STR(expectSetCharAtResult, stringBuffer.getValue());
	
	// Test new length < current length
	stringBuffer.setLength(10);
	ASSERT_STR(expectSetCharAtResult, stringBuffer.getValue());
	
	// Test negative newLength
	try {
		stringBuffer.setLength(-1);
	}
	catch (IndexOutOfBoundsException &e) {
		ASSERT_STR(expectSetCharAtResult, stringBuffer.getValue());
		ASSERT_STR("newLength must be positive", e.getMessage().toString());
	}
}

TEST(JavaLang, StringBufferSubString) {
	// Given a stringBuffer
	StringBuffer stringBuffer = StringBuffer("This is a StringBuffer");
	
	// Test valid param
	string expectSubStringResult = (string) ( "a String" );
	String result = stringBuffer.subString(8, 16);
	ASSERT_STR(expectSubStringResult, result.toString());
	
	// Test negative start
	try {
		result = stringBuffer.subString(-1, 16);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR(expectSubStringResult, result.toString());
		ASSERT_STR("start and end must be positive", e.getMessage().toString());
	}
	
	// Test negative end
	try {
		result = stringBuffer.subString(8, -15);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR(expectSubStringResult, result.toString());
		ASSERT_STR("start and end must be positive", e.getMessage().toString());
	}
	
	// Test start greater than length
	try {
		result = stringBuffer.subString(stringBuffer.length() + 1, 15);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR(expectSubStringResult, result.toString());
		ASSERT_STR("", e.getMessage().toString());
	}
	
	// Test end greater than length
	try {
		result = stringBuffer.subString(1, stringBuffer.length() + 1);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR(expectSubStringResult, result.toString());
		ASSERT_STR("", e.getMessage().toString());
	}
	
	// Test start greater than end
	try {
		result = stringBuffer.subString(10, 7);
	}
	catch (StringIndexOutOfBoundsException &e) {
		ASSERT_STR(expectSubStringResult, result.toString());
		ASSERT_STR("", e.getMessage().toString());
	}
	
	// Test subString(start)
	string expectSubStringStartResult = (string) ( "a StringBuffer" );
	result = stringBuffer.subString(8);
	ASSERT_STR(expectSubStringStartResult, result.toString());
}

// TODO need subSequence
/*TEST(JavaLang, StringBufferSubSequence) {
    // Given a stringBuffer
    StringBuffer stringBuffer = StringBuffer("This is a StringBuffer");

    // Test valid param
    string expectSubStringResult = (string)("a String");
    CharSequence *result = stringBuffer.subSequence(8, 16);
    ASSERT_STR(expectSubStringResult, result->toString());

    // Test negative start
    try {
        result = stringBuffer.subSequence(-1, 16);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR(expectSubStringResult, result->toString());
        ASSERT_STR("start and end must be positive", e.getMessage().toString());
    }

    // Test negative end
    try {
        result = stringBuffer.subSequence(8, -15);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR(expectSubStringResult, result->toString());
        ASSERT_STR("start and end must be positive", e.getMessage().toString());
    }

    // Test start greater than length
    try {
        result = stringBuffer.subSequence(stringBuffer.length() + 1, 15);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR(expectSubStringResult, result->toString());
        ASSERT_STR("", e.getMessage().toString());
    }

    // Test end greater than length
    try {
        result = stringBuffer.subSequence(1, stringBuffer.length() + 1);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR(expectSubStringResult, result->toString());
        ASSERT_STR("", e.getMessage().toString());
    }

    // Test start greater than end
    try {
        result = stringBuffer.subSequence(10, 7);
    }
    catch (IndexOutOfBoundsException &e) {
        ASSERT_STR(expectSubStringResult, result->toString());
        ASSERT_STR("", e.getMessage().toString());
    }
    String *charSequenceString = dynamic_cast<String *>(result);
    delete charSequenceString;
}*/

TEST(JavaLang, StringBufferToString) {
    // Given a stringBuffer
    StringBuffer stringBuffer = StringBuffer("This is a StringBuffer");
    string expectSubStringResult = (string)("This is a StringBuffer");
    string result = stringBuffer.toString();
    ASSERT_STR(expectSubStringResult, result);
}

TEST(JavaLang, StringBufferTrimToSize) {
	// Given a stringBuffer
	StringBuffer stringBuffer = StringBuffer(50);
	string stringToAppend = (string) ( "This is a StringBuffer" );
	stringBuffer.append(stringToAppend);
	int expectCapacity = 22;
	stringBuffer.trimToSize();
	ASSERT_EQUAL(expectCapacity, stringBuffer.capacity());
}