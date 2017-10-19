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

#include "../../../kernel/Test.hpp"

using namespace Java::Lang;

TEST(JavaLang, StringBufferConstructor) {
    // Init a StringBuffer with default constructor
    StringBuffer defaultConstructor;
    int expectCapacity = 16;
    assertEquals(expectCapacity, defaultConstructor.capacity());

    // Init a StringBuffer with specific capacity;
    StringBuffer capacityConstructor = StringBuffer(10);
    int expectSpecificCapacity = 10;
    assertEquals(expectSpecificCapacity, capacityConstructor.capacity());

    // Init a StringBuffer with negative specific capacity;
    try {
        StringBuffer negativeCapacityConstructor = StringBuffer(-1);
    }
    catch (NegativeArraySizeException &e) {
        assertEquals("Capacity must be non-negative", e.getMessage().toString());
    }

    // Init a StringBuffer with a charsequence
    CharSequence *sequence = new String("A String to test");
    StringBuffer charSequenceConstructor =  StringBuffer(*sequence);
    int expectSequenceCapacity = sequence->length() + 16;
    int expectSequenceLength = sequence->length();
    String expectSequenceValue = sequence->toString();
    assertEquals(expectSequenceCapacity, charSequenceConstructor.capacity());
    assertEquals(expectSequenceLength, charSequenceConstructor.length());
    assertEquals(expectSequenceValue, charSequenceConstructor.getValue());
    String *charSequenceString = dynamic_cast<String *>(sequence);
    delete charSequenceString;

    // Init a StringBuffer with a charsequence
    CharSequence *nullSequence = nullptr;
    StringBuffer nullSequenceConstructor = *nullSequence;
    int expectNullSequenceCapacity = 20;
    int expectNullSequenceLength = 4;
    String expectNullSequenceValue = (String)("null");
    assertEquals(expectNullSequenceCapacity, nullSequenceConstructor.capacity());
    assertEquals(expectNullSequenceLength, nullSequenceConstructor.length());
    assertEquals(expectNullSequenceValue, nullSequenceConstructor.getValue());

    // Init a StringBuffer with a String
    String aString = "A String to test";
    StringBuffer StringConstructor = StringBuffer(aString);
    int expectStringCapacity = aString.length() + 16;
    int expectStringLength = aString.length();
    String expectStringValue = aString.toString();
    assertEquals(expectStringCapacity, StringConstructor.capacity());
    assertEquals(expectStringLength, StringConstructor.length());
    assertEquals(expectStringValue, StringConstructor.getValue());

    // Copy Constructor
    StringBuffer other = StringBuffer("A String to test");
    StringBuffer copyConstructor = StringBuffer(other);
    assertEquals(expectStringCapacity, StringConstructor.capacity());
    assertEquals(expectStringLength, StringConstructor.length());
    assertEquals(expectStringValue, StringConstructor.getValue());

    // Given a StringBuilder for String constructor
    StringBuilder stringBuilder = StringBuilder((string) "Hello world");
    String stringBuilderConstructor(stringBuilder);
    assertEquals("Hello world", stringBuilderConstructor.toString());
    assertEquals(stringBuilder.length(), stringBuilderConstructor.length());

    // Given a StringBuffer for String constructor
    StringBuffer stringBuffer = StringBuffer("Hello world");
    String stringBufferConstructor = String(stringBuffer);
    assertEquals("Hello world", stringBufferConstructor.toString());
    assertEquals(stringBuffer.length(), stringBufferConstructor.length());
}

TEST(JavaLang, StringBufferOperater) {
	StringBuffer other = StringBuffer("A String to test");
	StringBuffer stringBuffer;
	assertEquals(other.capacity(), stringBuffer.capacity());
	assertEquals(other.length(), stringBuffer.length());
	assertEquals(other.getValue(), stringBuffer.getValue());
	
	StringBufferUnSafe otherUnSafe = StringBufferUnSafe("A String to test");
	StringBufferUnSafe StringBufferUnSafe;
	StringBufferUnSafe = otherUnSafe;
	assertEquals(otherUnSafe.capacity(), StringBufferUnSafe.capacity());
	assertEquals(otherUnSafe.length(), StringBufferUnSafe.length());
	assertEquals(otherUnSafe.getValue(), StringBufferUnSafe.getValue());
}

TEST(JavaLang, StringBufferCapacity) {
	// Init a StringBuffer with specific capacity
	StringBuffer stringBuffer(16);
	int expectCapacity = 16;
	assertEquals(expectCapacity, stringBuffer.capacity());
}

TEST(JavaLang, StringBufferLength) {
	// Init a StringBuffer with a String
	String aString = "A String to test";
	StringBuffer StringConstructor = StringBuffer(aString);
	int expectLength = 16;
	assertEquals(expectLength, StringConstructor.length());
}

TEST(JavaLang, StringBufferGetValue) {
	// Init a StringBuffer with String
	String aString = "A String to test";
	StringBuffer stringBuffer = aString;
	String expectValue = aString.toString();
	assertEquals(expectValue, stringBuffer.getValue());
}

TEST(JavaLang, StringBufferAppendSubCharArray) {
	StringBuffer StringAppend = StringBuffer("please");
	
	// Append "add more" to StringAppend
	String StringToAppend = "don't add more";
	StringAppend.append(StringToAppend, 5, 9);
	String expectString = "please add more";
	assertEquals(expectString, StringAppend.getValue());
	
	// TEST(offset + len) > stringBuffer.length()
	try {
		StringAppend.append(StringToAppend, 20, 2);
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals(expectString, StringAppend.getValue());
	}
	
	// Test negative offset
	try {
		StringAppend.append(StringToAppend, -1, 5);
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals(expectString, StringAppend.getValue());
	}
	
	// Test negative len
	try {
		StringAppend.append(StringToAppend, 5, -1);
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals(expectString, StringAppend.getValue());
	}
}

TEST(JavaLang, StringBufferAppend) {
    // Test String
    StringBuffer charArrayAppendStringBuffer = "please";

    String StringToAppend = (String)(" add more");
    charArrayAppendStringBuffer.append(StringToAppend);
    String expectString = (String)("please add more");
    assertEquals(expectString, charArrayAppendStringBuffer.getValue());

    // Test String
    StringBuffer stringAppendStringBuffer = StringBuffer("please");
    String StringObjectToAppend = " add more";
    stringAppendStringBuffer.append(StringObjectToAppend);
    assertEquals(expectString, stringAppendStringBuffer.getValue());

    // Test Object
    StringBuffer objectAppendStringBuffer = StringBuffer();

    auto objToAppend = new String("object");
    objectAppendStringBuffer.append(*objToAppend);
    String objString = objToAppend->toString();
    assertEquals(objString, objectAppendStringBuffer.getValue());
    auto objToAppendString = dynamic_cast<String *>(objToAppend);
    delete objToAppendString;

    // Test Null object
    StringBuffer nullObjectAppendStringBuffer;

    String *nullObjToAppend = nullptr;
    nullObjectAppendStringBuffer.append(*nullObjToAppend);
    String nullObjString = "null";
    assertEquals(nullObjString, nullObjectAppendStringBuffer.getValue());

    // Test number
    StringBuffer numberAppendStringBuffer = StringBuffer("100");

    // float
    float floatToAppend = 9.0;
    numberAppendStringBuffer.append(floatToAppend);
    String expectFloatAppend = "1009";
    assertEquals(expectFloatAppend, numberAppendStringBuffer.getValue());

    // TODO(thoangminh): @anhnt, please check leak error for this double case
//    // double
//    double doubleToAppend = 100.0;
//    String expectedDoubleAppend = (String)("1009100.000000000000000");
//    numberAppendstringBuffer.append(doubleToAppend);
//    assertEquals(expectedDoubleAppend, numberAppendstringBuffer.getValue());


//    // int
//    int intToAppend = 9;
//    numberAppendstringBuffer.append(intToAppend);
//    String expectIntAppend = (String)("1009100.0000000000000009");
//    assertEquals(expectIntAppend, numberAppendstringBuffer.getValue());
//
//    // long
//    long longToAppend = 900L;
//    numberAppendstringBuffer.append(longToAppend);
//    String expectLongAppend = (String)("1009100.0000000000000009900");
//    assertEquals(expectLongAppend, numberAppendstringBuffer.getValue());
//
//    // Test boolean
//    StringBuffer boolAppendStringBuffer = StringBuffer("bool ");
//
//    boolean boolToAppend = true;
//    boolAppendstringBuffer.append(boolToAppend);
//    String expectBoolAppend = (String)("bool true");
//    assertEquals(expectBoolAppend, boolAppendstringBuffer.getValue());
//
//    boolAppendStringBuffer = StringBuffer("bool ");
//
//    boolToAppend = false;
//    boolAppendstringBuffer.append(boolToAppend);
//    expectBoolAppend = (String)("bool false");
//    assertEquals(expectBoolAppend, boolAppendstringBuffer.getValue());
//
//    // Test char
//    StringBuffer charAppendStringBuffer = StringBuffer("Character is : ");
//
//    char charToAppend = 'A';
//    charAppendstringBuffer.append(charToAppend);
//    String expectCharAppend = (String)("Character is : A");
//    assertEquals(expectCharAppend, charAppendstringBuffer.getValue());
//
//    // Test StringBuffer
//    StringBuffer StringBufferAppendStringBuffer = StringBuffer("StringBuffer is : ");
//
//    StringBuffer StringBufferToAppend = StringBuffer("not null");
//    StringBufferAppendstringBuffer.append(StringBufferToAppend);
//    String expectStringBufferAppend = (String)("StringBuffer is : not null");
//    assertEquals(expectStringBufferAppend, StringBufferAppendstringBuffer.getValue());
//
//    // Test CharSequence
//    StringBuffer charSequenceAppendStringBuffer = StringBuffer("CharSequence is : ");
//
//    CharSequence *charSequenceToAppend = new String("not null");
//    charSequenceAppendstringBuffer.append(*charSequenceToAppend);
//    String expectCharSequenceAppend = (String)("CharSequence is : not null");
//    assertEquals(expectCharSequenceAppend, charSequenceAppendstringBuffer.getValue());
//
//    charSequenceAppendstringBuffer.append(*charSequenceToAppend, 0, 3);
//    expectCharSequenceAppend = (String)("CharSequence is : not nullnot");
//    assertEquals(expectCharSequenceAppend, charSequenceAppendstringBuffer.getValue());
//
//    // Test start < 0
//    try {
//        charSequenceAppendstringBuffer.append(*charSequenceToAppend, -1, 3);
//    }
//    catch (IndexOutOfBoundsException &e) {
//        assertEquals(expectCharSequenceAppend, charSequenceAppendstringBuffer.getValue());
//        assertEquals("", e.getMessage().toString());
//    }
//
//    // Test start > end
//    try {
//        charSequenceAppendstringBuffer.append(*charSequenceToAppend, 3, 1);
//    }
//    catch (IndexOutOfBoundsException &e) {
//        assertEquals(expectCharSequenceAppend, charSequenceAppendstringBuffer.getValue());
//        assertEquals("", e.getMessage().toString());
//    }
//
//    // Test start > sequence length
//    try {
//        charSequenceAppendstringBuffer.append(*charSequenceToAppend,
//                                              charSequenceToAppend->length() + 1,
//                                              charSequenceToAppend->length() + 2);
//    }
//    catch (IndexOutOfBoundsException &e) {
//        assertEquals(expectCharSequenceAppend, charSequenceAppendstringBuffer.getValue());
//        assertEquals("", e.getMessage().toString());
//    }
//
//    String *charSequenceString = dynamic_cast<String *>(charSequenceToAppend);
//    delete charSequenceString;
//    // Test null CharSequence
//    StringBuffer nullCharSequenceAppendStringBuffer = StringBuffer("CharSequence is : ");
//
//    CharSequence *nullCharSequenceToAppend = nullptr;
//    nullCharSequenceAppendstringBuffer.append(*nullCharSequenceToAppend);
//    String expectNullCharSequenceAppend = (String)("CharSequence is : null");
//    assertEquals(expectNullCharSequenceAppend, nullCharSequenceAppendstringBuffer.getValue());
}

TEST(JavaLang, StringBufferInsertSubCharArray) {
	// Given a StringBuffer
	StringBuffer StringInsert = StringBuffer("please more");
	
	// Test vaild param
	String StringToInsert = (String) ( "don't insert" );
	StringInsert.insert(6, StringToInsert, 5, 7);
	String expectString = (String) ( "please insert more" );
	assertEquals(expectString, StringInsert.getValue());
	
	// Test negative index
	try {
		StringInsert.insert(-1, StringToInsert, 6, 6);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals(expectString, StringInsert.getValue());
	}
	
	// Test index greater than length
	try {
		StringInsert.insert(StringInsert.length() + 1, StringToInsert, 6, 6);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals(expectString, StringInsert.getValue());
	}
	
	// Test negative offset
	try {
		StringInsert.insert(7, StringToInsert, -6, 6);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals(expectString, StringInsert.getValue());
	}
	
	// Test negative len
	try {
		StringInsert.insert(7, StringToInsert, 6, -1);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals(expectString, StringInsert.getValue());
	}
	
	// Test offset + len > length
	try {
		StringInsert.insert(7, StringToInsert, 20, 10);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals(expectString, StringInsert.getValue());
	}
}

TEST(JavaLang, StringBufferInsert) {
    // Test String
    StringBuffer charArrayInsertStringBuffer = "please more";

    String StringToInsert = (String)("add ");
    charArrayInsertStringBuffer.insert(7, StringToInsert);
    String expectString = (String)("please add more");
    assertEquals(expectString, charArrayInsertStringBuffer.getValue());

    // Test String
    StringBuffer stringInsertStringBuffer = StringBuffer("please more");
    String StringObjectToInsert = "add ";
    stringInsertStringBuffer.insert(7, StringObjectToInsert);
    assertEquals(expectString, stringInsertStringBuffer.getValue());

    // Test Object
    StringBuffer objectInsertStringBuffer = StringBuffer("please more");
    auto objToInsert = new String("add ");
    objectInsertStringBuffer.insert(7, *objToInsert);
    assertEquals(expectString, objectInsertStringBuffer.getValue());
    auto objToInsertString = dynamic_cast<String *>(objToInsert);
    delete objToInsertString;

    // Test Null object
    StringBuffer nullObjectInsertStringBuffer = StringBuffer("this is  pointer");

    String *nullObjToInsert = nullptr;
    nullObjectInsertStringBuffer.insert(8, *nullObjToInsert);
    String expectInsertNullObject = (String)("this is null pointer");
    assertEquals(expectInsertNullObject, nullObjectInsertStringBuffer.getValue());

    // Test number
    StringBuffer numberInsertStringBuffer = StringBuffer("100");

    // float
    float floatToInsert = 9.0;
    nullObjectInsertStringBuffer.insert(2, floatToInsert);
    String expectFloatInsert = (String)("1090");
    assertEquals(expectFloatInsert, nullObjectInsertStringBuffer.getValue());

    // TODO(thoangminh): @anhnt please check leak error for this double case
//    // double
//    double doubleToInsert = 100.0;
//    numberInsertstringBuffer.insert(2, doubleToInsert);
//    String expectDoubleInsert = (String)("10100.00000000000000090");
//    assertEquals(expectDoubleInsert, numberInsertstringBuffer.getValue());

//    // int
//    int intToInsert = 13;
//    numberInsertstringBuffer.insert(2, intToInsert);
//    String expectIntInsert = "1013100.00000000000000090";
//    assertEquals(expectIntInsert, numberInsertstringBuffer.getValue());
//
//    // long
//    long longToInsert = 900L;
//    numberInsertstringBuffer.insert(2, longToInsert);
//    String expectLongInsert = (String)("1090013100.00000000000000090");
//    assertEquals(expectLongInsert, numberInsertstringBuffer.getValue());
//
//    // Test boolean
//    StringBuffer boolInsertStringBuffer = StringBuffer("bool  is good");
//
//    boolean boolToInsert = true;
//    boolInsertstringBuffer.insert(5, boolToInsert);
//    String expectBoolInsert = (String)("bool true is good");
//    assertEquals(expectBoolInsert, boolInsertstringBuffer.getValue());
//
//    boolInsertStringBuffer = StringBuffer("bool  is bad");
//
//    boolToInsert = false;
//    boolInsertstringBuffer.insert(5, boolToInsert);
//    expectBoolInsert = (String)("bool false is bad");
//    assertEquals(expectBoolInsert, boolInsertstringBuffer.getValue());
//
//    // Test char
//    StringBuffer charInsertStringBuffer = StringBuffer("Character  is uppercase");
//
//    char charToInsert = 'A';
//    charInsertstringBuffer.insert(10, charToInsert);
//    String expectCharInsert = (String)("Character A is uppercase");
//    assertEquals(expectCharInsert, charInsertstringBuffer.getValue());
//
//    // Test CharSequence
//    StringBuffer charSequenceInsertStringBuffer = StringBuffer("CharSequence is : null");
//
//    CharSequence *charSequenceToInsert = new String(" not");
//    charSequenceInsertstringBuffer.insert(17, *charSequenceToInsert);
//    String expectCharSequenceInsert = (String)("CharSequence is : not null");
//    assertEquals(expectCharSequenceInsert, charSequenceInsertstringBuffer.getValue());
//
//    // Test negative offset
//    try {
//        charSequenceInsertstringBuffer.insert(-1, *charSequenceToInsert);
//    }
//    catch (IndexOutOfBoundsException &e) {
//        assertEquals("offset must be positive", e.getMessage().toString());
//    }
//
//    // Test null CharSequence
//    StringBuffer nullCharSequenceInsertStringBuffer = StringBuffer("CharSequence is a  pointer");
//
//    CharSequence *nullCharSequenceToInsert = nullptr;
//    nullCharSequenceInsertstringBuffer.insert(18, *nullCharSequenceToInsert);
//    String expectNullCharSequenceInsert = (String)("CharSequence is a null pointer");
//    assertEquals(expectNullCharSequenceInsert, nullCharSequenceInsertstringBuffer.getValue());
//
//    // Test CharSequence
//    StringBuffer charSequenceInsertWithOffsetStringBuffer = StringBuffer("CharSequence is : null");
//
//    charSequenceInsertWithOffsetstringBuffer.insert(17, *charSequenceToInsert, 0, 4);
//    assertEquals(expectCharSequenceInsert, charSequenceInsertstringBuffer.getValue());
//
//    // Test negative destinationOffset
//    try {
//        charSequenceInsertWithOffsetstringBuffer.insert(-1, *charSequenceToInsert, 0, 4);
//    }
//    catch (IndexOutOfBoundsException &e) {
//        assertEquals("offset must be positive", e.getMessage().toString());
//    }
//
//    // Test destinationOffset > length
//    try {
//        charSequenceInsertWithOffsetstringBuffer.insert(100, *charSequenceToInsert, 0, 4);
//    }
//    catch (IndexOutOfBoundsException &e) {
//        assertEquals("", e.getMessage().toString());
//    }
//
//    // Test negative start
//    try {
//        charSequenceInsertWithOffsetstringBuffer.insert(17, *charSequenceToInsert, -1, 4);
//    }
//    catch (IndexOutOfBoundsException &e) {
//        assertEquals("", e.getMessage().toString());
//    }
//
//    // Test negative end
//    try {
//        charSequenceInsertWithOffsetstringBuffer.insert(17, *charSequenceToInsert, 0, -1);
//    }
//    catch (IndexOutOfBoundsException &e) {
//        assertEquals("", e.getMessage().toString());
//    }
//
//    // Test start > end
//    try {
//        charSequenceInsertWithOffsetstringBuffer.insert(17, *charSequenceToInsert, 5, 4);
//    }
//    catch (IndexOutOfBoundsException &e) {
//        assertEquals("", e.getMessage().toString());
//    }
//
//    // Test end > sequence length
//    try {
//        charSequenceInsertWithOffsetstringBuffer.insert(17, *charSequenceToInsert, 0, 100);
//    }
//    catch (IndexOutOfBoundsException &e) {
//        assertEquals("", e.getMessage().toString());
//    }
//
//    // Test null CharSequence
//    StringBuffer nullCharSequenceInsertWithOffsetStringBuffer = StringBuffer("CharSequence is a  pointer");
//
//    nullCharSequenceInsertWithOffsetstringBuffer.insert(18, *nullCharSequenceToInsert, 0, 3);
//    assertEquals(expectNullCharSequenceInsert, nullCharSequenceInsertstringBuffer.getValue());
//    String *charSequenceString = dynamic_cast<String *>(charSequenceToInsert);
//    delete charSequenceString;
}

TEST(JavaLang, StringBufferEnsureCapacity) {
	StringBuffer stringBuffer;
	
	// Test minimum capacity = 20
	int expectMinimumTwentyCapacity = 34;
	stringBuffer.ensureCapacity(20);
	assertEquals(expectMinimumTwentyCapacity, stringBuffer.capacity());
	
	// Tets minimum capacity < current capacity
	int expectMinimumEightyCapacity = 34;
	stringBuffer.ensureCapacity(30);
	assertEquals(expectMinimumEightyCapacity, stringBuffer.capacity());
	
	// Test negative minimum capacity
	int expectMinNonPositiveCapacity = 34;
	stringBuffer.ensureCapacity(-1);
	assertEquals(expectMinNonPositiveCapacity, stringBuffer.capacity());
}

TEST(JavaLang, StringBufferAppendCodePoint) {
	StringBuffer stringBuffer("Codepoint is : ");
	
	// Test Bmp codePoint
	String expectBmpCodePointResult = (String) ( "Codepoint is : P" );
	stringBuffer.appendCodePoint(80);
	assertEquals(expectBmpCodePointResult, stringBuffer.getValue());
	
	// Test not a codePoint
	try {
		stringBuffer.appendCodePoint(80000000);
	}
	catch (IllegalArgumentException &e) {
		assertEquals(expectBmpCodePointResult, stringBuffer.getValue());
	}
	
	// TODO Test Valid codePoint
	String expectValidCodePointResult = (String) ( "Codepoint is : P�" );
	stringBuffer.appendCodePoint(800000);
	//assertEquals(expectBmpCodePointResult, stringBuffer.getValue());
}

TEST(JavaLang, StringBufferCharAt) {
	StringBuffer stringBuffer = "CharAt";
	
	// Test vaild index
	char expectCharAtResult = 'A';
	assertEquals(expectCharAtResult, stringBuffer.charAt(4));
	
	// Test negative index
	try {
		char expectNegativeIndex = stringBuffer.charAt(-1);
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals("index must be positive", e.getMessage().toString());
	}
	
	// Test equal to length index
	try {
		char expectEqualToLengthIndex = stringBuffer.charAt(stringBuffer.length());
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals("", e.getMessage().toString());
	}
	
	// Test greater than length index
	try {
		char expectGreaterThanLengthIndex = stringBuffer.charAt(stringBuffer.length() + 1);
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals("", e.getMessage().toString());
	}
}

TEST(JavaLang, StringBufferCodePointAt) {
	StringBuffer stringBuffer = String("CodePointAt");
	
	// Test vaild index
	char expectCodePointAtResult = 'A';
	assertEquals(expectCodePointAtResult, stringBuffer.codePointAt(9));
	
	// Test negative index
	try {
		char expectNegativeIndex = (char) (stringBuffer.codePointAt(-1));
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals("index must be positive", e.getMessage().toString());
	}
	
	// Test equal to length index
	try {
		auto expectEqualToLengthIndex = (char) (stringBuffer.codePointAt(stringBuffer.length()));
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals("", e.getMessage().toString());
	}
	
	// Test greater than length index
	try {
		auto expectGreaterThanLengthIndex = (char) (stringBuffer.codePointAt(stringBuffer.length() + 1));
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals("", e.getMessage().toString());
	}
}

TEST(JavaLang, StringBufferCodePointBefore) {
	StringBuffer stringBuffer = "CodePointAt";
	
	// Test vaild index
	char expectCodePointBeforeResult = 'A';
	assertEquals(expectCodePointBeforeResult, stringBuffer.codePointBefore(10));
	
	// Test zero index
	try {
		auto expectEqualToLengthIndex = (char) (stringBuffer.codePointBefore(0));
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals("index must be positive", e.getMessage().toString());
	}
	
	// Test negative index
	try {
		auto expectNegativeIndex = (char) (stringBuffer.codePointBefore(-1));
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals("index must be positive", e.getMessage().toString());
	}
	
	// Test greater than length index
	try {
		auto expectGreaterThanLengthIndex = (char) (stringBuffer.codePointBefore(stringBuffer.length() + 1));
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals("", e.getMessage().toString());
	}
}

TEST(JavaLang, StringBufferCodePointCount) {
	StringBuffer stringBuffer = "CodePointCount";
	
	// Test vaild beginIndex, endIndex
	int expectCodePointCount = 8;
	assertEquals(expectCodePointCount, stringBuffer.codePointCount(1, 9));
	
	// Test negative beginIndex
	try {
		int expectNegativeBegin = stringBuffer.codePointCount(-1, 9);
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals("", e.getMessage().toString());
	}
	
	// Test greater than length endIndex
	try {
		int expectEqualToLengthEnd = stringBuffer.codePointCount(1, stringBuffer.length() + 1);
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals("", e.getMessage().toString());
	}
	
	// Test beginIndex greather than endIndex
	try {
		int expectBeginGreaterThanEnd = stringBuffer.codePointCount(10, 1);
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals("", e.getMessage().toString());
	}
}

TEST(JavaLang, StringBufferDeleteCharAt) {
	StringBuffer stringBuffer = "Delete char at";
	
	// Test vaild index
	String expectDeleteCharResult = (String) ( "Delete cha at" );
    stringBuffer.deleteCharAt(10);
	assertEquals(expectDeleteCharResult, stringBuffer.getValue());
	
	// Test negative index
	try {
        stringBuffer.deleteCharAt(-1);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals(expectDeleteCharResult, stringBuffer.getValue());
		assertEquals("index must be positive", e.getMessage().toString());
	}
	
	// Test equal to length index
	try {
        stringBuffer.deleteCharAt(stringBuffer.length());
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals(expectDeleteCharResult, stringBuffer.getValue());
	}
	
	// Test greater than length index
	try {
        stringBuffer.deleteCharAt(stringBuffer.length() + 1);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals(expectDeleteCharResult, stringBuffer.getValue());
	}
}

TEST(JavaLang, StringBufferDelete) {
	StringBuffer stringBuffer = "Delete char at";
	
	// Test vaild start, end
	String expectDeleteCharResult = "Delete at";
	stringBuffer.deletes(7, 12);
	assertEquals(expectDeleteCharResult, stringBuffer.getValue());
	
	// Test start equal to end
	stringBuffer.deletes(7, 7);
	assertEquals(expectDeleteCharResult, stringBuffer.getValue());
	
	// Test end greater than length
	String expectEndGreaterThanLengthResult = (String) ( "Delete" );
	stringBuffer.deletes(6, 12);
	assertEquals(expectEndGreaterThanLengthResult, stringBuffer.getValue());
	
	// Test start equal to length
	stringBuffer.deletes(6, 10);
	assertEquals(expectEndGreaterThanLengthResult, stringBuffer.getValue());
	
	// Test negative start
	try {
		stringBuffer.deletes(-1, 9);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals("index must be positive", e.getMessage().toString());
		assertEquals(expectEndGreaterThanLengthResult, stringBuffer.getValue());
	}
	
	// Test start greater than length
	try {
		stringBuffer.deletes(7, 10);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals("", e.getMessage().toString());
		assertEquals(expectEndGreaterThanLengthResult, stringBuffer.getValue());
	}
	
	// Test startIndex greather than endIndex
	try {
		stringBuffer.deletes(5, 1);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals(expectEndGreaterThanLengthResult, stringBuffer.getValue());
		assertEquals("", e.getMessage().toString());
	}
}

// TODO need getChar
/*
TEST(JavaLang, StringBufferGetChar) {
    // Given a StringBuffer
    StringBuffer stringBuffer = StringBuffer("StringBuffer");
    // Destination String
    String destinationString = (String)("Copy from : !!!");

    // Test vaild param
    String expectGetCharResult = (String)("Copy from : StringBuffer !!!");
    stringBuffer.getChars(0, 12, destinationString, 11);
    assertEquals(expectGetCharResult, destinationString);

    // Test negative sourceBegin
    try {
        stringBuffer.getChars(-1, 1, destinationString, 6);
    }
    catch (IndexOutOfBoundsException &e) {
        assertEquals(expectGetCharResult, destinationString);
    }

    // Test negative destinationBegin
    try {
        stringBuffer.getChars(1, 1, destinationString, -6);
    }
    catch (IndexOutOfBoundsException &e) {
        assertEquals(expectGetCharResult, destinationString);
    }

    // Test sourceBegin greater than sourceEnd
    try {
        stringBuffer.getChars(5, 1, destinationString, 6);
    }
    catch (IndexOutOfBoundsException &e) {
        assertEquals(expectGetCharResult, destinationString);
    }

    // Test sourceEnd greater than length
    try {
        stringBuffer.getChars(1, stringBuffer.length() + 1, destinationString, 6);
    }
    catch (IndexOutOfBoundsException &e) {
        assertEquals(expectGetCharResult, destinationString);
    }

    // Test destinationBegin + sourceEnd - sourceBegin greater than destination.length
    try {
        stringBuffer.getChars(1, 10, destinationString, 6);
    }
    catch (IndexOutOfBoundsException &e) {
        assertEquals(expectGetCharResult, destinationString);
    }
}*/

TEST(JavaLang, StringBufferIndexOf) {
	// Given a StringBuffer
	StringBuffer stringBuffer = "This is a StringBuffer";
	// Given 2 subString
	String isSubString = "is a";
	String notSubString = "is not";
	
	// Test isSubString
	int expectIsSubStringResult = 5;
	int actualIsSubStringResult = stringBuffer.indexOf(isSubString);
	assertEquals(expectIsSubStringResult, actualIsSubStringResult);
	
	// Test notSubString
	int expectNotSubStringResult = -1;
	int actualNotSubStringResult = stringBuffer.indexOf(notSubString);
	assertEquals(expectNotSubStringResult, actualNotSubStringResult);
}

TEST(JavaLang, StringBufferIndexOfFromIndex) {
	// Given a StringBuffer
	StringBuffer stringBuffer = "This is a stringBuffer. This is a StringBuffer";
	// Given 2 subString
	String isSubString = "is a";
	String notSubString = "is not";
	
	// Test isSubString
	int expectIsSubStringResult = 29;
	int actualIsSubStringResult = stringBuffer.indexOf(isSubString, 10);
	assertEquals(expectIsSubStringResult, actualIsSubStringResult);
	
	// Test notSubString
	int expectNotSubStringResult = -1;
	int actualNotSubStringResult = stringBuffer.indexOf(notSubString, 10);
	assertEquals(expectNotSubStringResult, actualNotSubStringResult);
}

TEST(JavaLang, StringBufferLastIndexOf) {
	// Given a StringBuffer
	StringBuffer stringBuffer = "This is a stringBuffer. This is a stringBuffer. This is a StringBuffer";
	// Given 2 subString
	String isSubString = "is a";
	String notSubString = "is not";
	
	// Test isSubString
	int expectIsSubStringResult = 53;
	int actualIsSubStringResult = stringBuffer.lastIndexOf(isSubString);
	assertEquals(expectIsSubStringResult, actualIsSubStringResult);
	
	// Test notSubString
	int expectNotSubStringResult = -1;
	int actualNotSubStringResult = stringBuffer.lastIndexOf(notSubString);
	assertEquals(expectNotSubStringResult, actualNotSubStringResult);
}

TEST(JavaLang, StringBufferLastIndexOfFromIndex) {
	// Given a StringBuffer
	StringBuffer stringBuffer = "This is a stringBuffer. This is a stringBuffer. This is a StringBuffer";
	// Given 2 subString
	String isSubString = "is a";
	String notSubString = "is not";
	
	// Test isSubString
	int expectIsSubStringFromIndexResult = 29;
	int actualIsSubStringFromIndexResult = stringBuffer.lastIndexOf(isSubString, 29);
	assertEquals(expectIsSubStringFromIndexResult, actualIsSubStringFromIndexResult);
	
	// Test isSubString
	int expectNotSubStringFromIndexResult = -1;
	int actualNotSubStringFromIndexResult = stringBuffer.lastIndexOf(isSubString, 4);
	assertEquals(expectNotSubStringFromIndexResult, actualNotSubStringFromIndexResult);
	
	// Test notSubString
	int expectNotSubStringResult = -1;
	int actualNotSubStringResult = stringBuffer.lastIndexOf(notSubString, 30);
	assertEquals(expectNotSubStringResult, actualNotSubStringResult);
}

TEST(JavaLang, StringBufferOffSetByCodePoint) {
	// Given a StringBuffer
	StringBuffer stringBuffer = "This is a String buffer";
	
	// Test vaild param
	int expectOffsetByCodePointsResult = 0; // 5
	int actualOffsetByCodePointsResult = stringBuffer.offsetByCodePoints(1, 4);
	assertEquals(expectOffsetByCodePointsResult, actualOffsetByCodePointsResult);
	
	// Test index < 0
	try {
		int negativeIndexResult = stringBuffer.offsetByCodePoints(-1, 4);
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals("", e.getMessage().toString());
	}
	
	// Test index > length()
	try {
		int greaterThanLengthIndexResult = stringBuffer.offsetByCodePoints(stringBuffer.length() + 1, 4);
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals("", e.getMessage().toString());
	}
}

TEST(JavaLang, StringBufferReplace) {
	// Given a StringBuffer
	StringBuffer stringBuffer = "This is a StringBuffer";
	
	// Given a String
	String StringToReplace = (String) ( "Butter" );
	
	// Test vaild param
	String expectReplaceResult = (String) ( "This is a StringButter" );
	stringBuffer.replace(16, 22, StringToReplace);
	assertEquals(expectReplaceResult, stringBuffer.getValue());
	
	// Test end greater than length
	String expectEndGreaterThanLength = (String) ( "This is a StringButButter" );
	stringBuffer.replace(19, 30, StringToReplace);
	assertEquals(expectEndGreaterThanLength, stringBuffer.getValue());
	
	// Test end - start > str length
	String expectReplaceRangeGreaterThanStringLength = (String) ( "This is a StringButter" );
	stringBuffer.replace(16, 25, StringToReplace);
	assertEquals(expectReplaceRangeGreaterThanStringLength, stringBuffer.getValue());
	
	// Test end - start < str length
	String expectReplaceRangeSmallerThanStringLength = (String) ( "This is a StringButterutter" );
	stringBuffer.replace(16, 17, StringToReplace);
	assertEquals(expectReplaceRangeSmallerThanStringLength, stringBuffer.getValue());
	
	String expectNotChangeResult = (String) ( "This is a StringButterutter" );
	
	// Test negative start
	try {
		stringBuffer.replace(-1, 10, StringToReplace);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals("start must be positive", e.getMessage().toString());
		assertEquals(expectNotChangeResult, stringBuffer.getValue());
	}
	
	// Test start greater than length
	try {
		stringBuffer.replace(stringBuffer.length() + 1, 10, StringToReplace);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals("", e.getMessage().toString());
		assertEquals(expectNotChangeResult, stringBuffer.getValue());
	}
	
	// Test start greater than end
	try {
        stringBuffer.replace(10, 1, StringToReplace);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals("", e.getMessage().toString());
		assertEquals(expectNotChangeResult, stringBuffer.getValue());
	}
}

TEST(JavaLang, StringBufferReverse) {
	// Given a StringBuffer
	StringBuffer stringBuffer = "ABCDEFGH";
	
	// Test nomal String
    stringBuffer.reverse();
	String expectNomalStringReverse = "HGFEDCBA";
	assertEquals(expectNomalStringReverse, stringBuffer.getValue());
	
	// TODO handle surrogate as one char
	/* // Test surrogate String
	 StringBuffer surrogateStringBuffer = StringBuffer("\u000DC00\u000D800");
	 surrogatestringBuffer.reverse();
	 String expectSurrogateStringReverse = (String)("\u000D800\u000DC00");
	 assertEquals(expectSurrogateStringReverse, surrogatestringBuffer.getValue());*/
}

TEST(JavaLang, StringBufferSetCharAt) {
	// Given a StringBuffer
	StringBuffer stringBuffer = "ABCDEFGH";
	
	// Test vaild index
    stringBuffer.setCharAt(3, 'd');
	String expectSetCharAtResult = (String) ( "ABCdEFGH" );
	assertEquals(expectSetCharAtResult, stringBuffer.getValue());
	
	// Test negative Index
	try {
        stringBuffer.setCharAt(-1, 'd');
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals(expectSetCharAtResult, stringBuffer.getValue());
		assertEquals("index must be positive", e.getMessage().toString());
	}
	
	// Test index greater than length
	try {
        stringBuffer.setCharAt(stringBuffer.length() + 1, 'd');
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals(expectSetCharAtResult, stringBuffer.getValue());
		assertEquals("", e.getMessage().toString());
	}
	
	// Test index equal to length
	try {
        stringBuffer.setCharAt(stringBuffer.length(), 'd');
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals(expectSetCharAtResult, stringBuffer.getValue());
		assertEquals("", e.getMessage().toString());
	}
}

TEST(JavaLang, StringBufferSetLength) {
	// Given a StringBuffer
	StringBuffer stringBuffer = "ABCDEFGH";
	
	// Test new length < current length
    stringBuffer.setLength(6);
	String expectSetCharAtResult = (String) ( "ABCDEF" );
	assertEquals(expectSetCharAtResult, stringBuffer.getValue());
	
	// Test new length < current length
    stringBuffer.setLength(10);
	assertEquals(expectSetCharAtResult, stringBuffer.getValue());
	
	// Test negative newLength
	try {
		stringBuffer.setLength(-1);
	}
	catch (IndexOutOfBoundsException &e) {
		assertEquals(expectSetCharAtResult, stringBuffer.getValue());
		assertEquals("newLength must be positive", e.getMessage().toString());
	}
}

TEST(JavaLang, StringBufferSubString) {
	// Given a StringBuffer
	StringBuffer stringBuffer = "This is a StringBuffer";
	
	// Test valid param
	String expectSubStringResult = "a String";
	String result = stringBuffer.subString(8, 16);
	assertEquals(expectSubStringResult, result.toString());
	
	// Test negative start
	try {
		result = stringBuffer.subString(-1, 16);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals(expectSubStringResult, result.toString());
		assertEquals("start and end must be positive", e.getMessage().toString());
	}
	
	// Test negative end
	try {
		result = stringBuffer.subString(8, -15);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals(expectSubStringResult, result.toString());
		assertEquals("start and end must be positive", e.getMessage().toString());
	}
	
	// Test start greater than length
	try {
		result = stringBuffer.subString(stringBuffer.length() + 1, 15);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals(expectSubStringResult, result.toString());
		assertEquals("", e.getMessage().toString());
	}
	
	// Test end greater than length
	try {
		result = stringBuffer.subString(1, stringBuffer.length() + 1);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals(expectSubStringResult, result.toString());
		assertEquals("", e.getMessage().toString());
	}
	
	// Test start greater than end
	try {
		result = stringBuffer.subString(10, 7);
	}
	catch (StringIndexOutOfBoundsException &e) {
		assertEquals(expectSubStringResult, result.toString());
		assertEquals("", e.getMessage().toString());
	}
	
	// Test subString(start)
	String expectSubStringStartResult = "a StringBuffer";
	result = stringBuffer.subString(8);
	assertEquals(expectSubStringStartResult, result.toString());
}

// TODO need subSequence
/*TEST(JavaLang, StringBufferSubSequence) {
    // Given a StringBuffer
    StringBuffer stringBuffer = StringBuffer("This is a StringBuffer");

    // Test valid param
    String expectSubStringResult = (String)("a String");
    CharSequence *result = stringBuffer.subSequence(8, 16);
    assertEquals(expectSubStringResult, result->toString());

    // Test negative start
    try {
        result = stringBuffer.subSequence(-1, 16);
    }
    catch (IndexOutOfBoundsException &e) {
        assertEquals(expectSubStringResult, result->toString());
        assertEquals("start and end must be positive", e.getMessage().toString());
    }

    // Test negative end
    try {
        result = stringBuffer.subSequence(8, -15);
    }
    catch (IndexOutOfBoundsException &e) {
        assertEquals(expectSubStringResult, result->toString());
        assertEquals("start and end must be positive", e.getMessage().toString());
    }

    // Test start greater than length
    try {
        result = stringBuffer.subSequence(stringBuffer.length() + 1, 15);
    }
    catch (IndexOutOfBoundsException &e) {
        assertEquals(expectSubStringResult, result->toString());
        assertEquals("", e.getMessage().toString());
    }

    // Test end greater than length
    try {
        result = stringBuffer.subSequence(1, stringBuffer.length() + 1);
    }
    catch (IndexOutOfBoundsException &e) {
        assertEquals(expectSubStringResult, result->toString());
        assertEquals("", e.getMessage().toString());
    }

    // Test start greater than end
    try {
        result = stringBuffer.subSequence(10, 7);
    }
    catch (IndexOutOfBoundsException &e) {
        assertEquals(expectSubStringResult, result->toString());
        assertEquals("", e.getMessage().toString());
    }
    String *charSequenceString = dynamic_cast<String *>(result);
    delete charSequenceString;
}*/

TEST(JavaLang, StringBufferToString) {
    // Given a StringBuffer
    StringBuffer stringBuffer = "This is a StringBuffer";
    String expectSubStringResult = "This is a StringBuffer";
    String result = stringBuffer.toString();
    assertEquals(expectSubStringResult, result);
}

TEST(JavaLang, StringBufferTrimToSize) {
	// Given a StringBuffer
	StringBuffer stringBuffer(50);
	String stringToAppend = "This is a StringBuffer";
    stringBuffer.append(stringToAppend);
	int expectCapacity = 22;
    stringBuffer.trimToSize();
	assertEquals(expectCapacity, stringBuffer.capacity());
}