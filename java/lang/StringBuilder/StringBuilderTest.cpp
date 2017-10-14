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

#include "../../../kernel/Test.hpp"
#include "../StringBuilder/StringBuilder.hpp"
#include "../NegativeArraySizeException/NegativeArraySizeException.hpp"
#include "../IndexOutOfBoundsException/IndexOutOfBoundsException.hpp"
#include "../StringIndexOutOfBoundsException/StringIndexOutOfBoundsException.hpp"

using namespace Java::Lang;

TEST(JavaLang, StringBuilderConstructor) {
    StringBuilder defaultStringBuilder;
    assertEquals(0, defaultStringBuilder.length());
    assertEquals(StringBuilder::defaultCapacity, defaultStringBuilder.capacity());

    StringBuilder customCapacityStringBuilder(20);
    assertEquals(0, customCapacityStringBuilder.length());
    assertEquals(20, customCapacityStringBuilder.capacity());

    try {
        StringBuilder negativeCapacityStringBuilder(-1);
    }
    catch (NegativeArraySizeException &ex) {
        assertEquals("Capacity is negative", ex.getMessage().toString());
    }

    String aString = "Hello! Welcome to VietNam!";
    int aStringLength = aString.length();
    StringBuilder nullTerminatedStringStringBuilder(aString.toString());
    StringBuilder stringStringBuilder(aString);
    int newCapacity = StringBuilder::defaultCapacity + aStringLength;
    assertEquals(aStringLength, nullTerminatedStringStringBuilder.length());
    assertEquals(newCapacity, nullTerminatedStringStringBuilder.capacity());
    assertEquals(aStringLength, stringStringBuilder.length());
    assertEquals(newCapacity, stringStringBuilder.capacity());

    StringBuilder initializerListStringBuilder({'a', 'b', 'c'});
    assertEquals(3, initializerListStringBuilder.length());
    assertEquals(StringBuilder::defaultCapacity + initializerListStringBuilder.length(),
                 initializerListStringBuilder.capacity());

    CharSequence *charSequence = new String("Hello!");
    StringBuilder charSequenceStringBuilder(*charSequence);
    assertEquals("Hello!", charSequenceStringBuilder.toString());
    String *charSequenceString = dynamic_cast<String *>(charSequence);
    delete charSequenceString;
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
    assertEquals("123", stringBuilder1.toString());
    Array<Character> arrayOfCharacter({Character('4'), Character('5'), Character('6')});
    stringBuilder1.append(arrayOfCharacter);
    assertEquals("123456", stringBuilder1.toString());

    // String and string (const string)
    StringBuilder stringBuilder2;
    String aString = "123";
    stringBuilder2.append(aString);
    assertEquals("123", stringBuilder2.toString());
    stringBuilder2.append((const string)"456");
    assertEquals("123456", stringBuilder2.toString());

    // Double and double, Float and float, Integer and int, Long and long
    StringBuilder stringBuilder3;
    stringBuilder3.append(Double(0.8));
    assertEquals("0.800000000000000", stringBuilder3.toString());
    stringBuilder3.append(0.8);
    assertEquals("0.8000000000000000.800000000000000", stringBuilder3.toString());
    stringBuilder3.append(Float(0.7f));
    assertEquals("0.8000000000000000.8000000000000000.7", stringBuilder3.toString());
    stringBuilder3.append(0.7f);
    assertEquals("0.8000000000000000.8000000000000000.70.7", stringBuilder3.toString());
    stringBuilder3.append(Integer(10));
    assertEquals("0.8000000000000000.8000000000000000.70.710", stringBuilder3.toString());
    stringBuilder3.append(100);
    assertEquals("0.8000000000000000.8000000000000000.70.710100", stringBuilder3.toString());
    stringBuilder3.append(Long(1000l));
    assertEquals("0.8000000000000000.8000000000000000.70.7101001000", stringBuilder3.toString());
    stringBuilder3.append(1001L);
    assertEquals("0.8000000000000000.8000000000000000.70.71010010001001", stringBuilder3.toString());

    // Boolean and boolean
    StringBuilder stringBuilder4;
    stringBuilder4.append(Boolean(true));
    assertEquals("true", stringBuilder4.toString());
    stringBuilder4.append(Boolean(false));
    assertEquals("truefalse", stringBuilder4.toString());
    stringBuilder4.append(true);
    assertEquals("truefalsetrue", stringBuilder4.toString());
    stringBuilder4.append(false);
    assertEquals("truefalsetruefalse", stringBuilder4.toString());

    // Character and char
    StringBuilder stringBuilder5;
    stringBuilder5.append(Character('a'));
    stringBuilder5.append('b');
    assertEquals("ab", stringBuilder5.toString());

    // Array<Character> and Array<char>
    StringBuilder stringBuilder6((const string)"abc");
    stringBuilder6.append(Array<Character> {'1', '2', '3'}, 1, 2);
    assertEquals("abc23", stringBuilder6.toString());
    stringBuilder6.append(Array<char> {'x', 'y', 'z'}, 0, 2);
    assertEquals("abc23xy", stringBuilder6.toString());

    // CharSequence
    CharSequence *charSequence = new String("Hello!");
    StringBuilder stringBuilder7((const string)"123");
    assertEquals("123", stringBuilder7.toString());
    stringBuilder7.append(*charSequence);
    assertEquals("123Hello!", stringBuilder7.toString());
    try {
        // start < 0
        stringBuilder7.append(*charSequence, -1, 3);
    }
    catch (IndexOutOfBoundsException &ex){
        assertEquals("", ex.getMessage().toString());
        assertEquals("123Hello!", stringBuilder7.toString());
    }
    try {
        // start > end
        stringBuilder7.append(*charSequence, 4, 3);
    }
    catch (IndexOutOfBoundsException &ex){
        assertEquals("", ex.getMessage().toString());
        assertEquals("123Hello!", stringBuilder7.toString());
    }
    try {
        // end > current length of StringBuilder instance.
        stringBuilder7.append(*charSequence, 4, 999);
    }
    catch (IndexOutOfBoundsException &ex){
        assertEquals("", ex.getMessage().toString());
        assertEquals("123Hello!", stringBuilder7.toString());
    }
    stringBuilder7.append(*charSequence, 1, 3);
    assertEquals("123Hello!el", stringBuilder7.toString());
    String *charSequenceString = dynamic_cast<String *>(charSequence);
    delete charSequenceString;
}

TEST(JavaLang, StringBuilderAppendCodePoint) {
	// TODO
}

TEST(JavaLang, StringBuilderCapacity) {
	StringBuilder stringBuilder(100);
	assertEquals(100, stringBuilder.capacity());
}

TEST(JavaLang, StringBuilderCharAt) {
    StringBuilder stringBuilder({'a', 'b', 'c'});
    assertEquals('a', stringBuilder.charAt(0));
    assertEquals('b', stringBuilder.charAt(1));
    assertEquals('c', stringBuilder.charAt(2));
    try {
        stringBuilder.charAt(999);
    }
    catch (IndexOutOfBoundsException &ex) {
        assertEquals("999", ex.getMessage().toString());
    }
}

TEST(JavaLang, StringBuilderCodePointAt) {
	// TODO
}

TEST(JavaLang, StringBuilderCodePointBefore) {
	// TODO
}

TEST(JavaLang, StringBuilderCodePointCount) {
	// TODO
}

TEST(JavaLang, StringBuilderDeleteRange) {
    StringBuilder stringBuilder((const string)"ABCXYZ");
    assertEquals("ABCXYZ", stringBuilder.toString());
    try {
        // start < 0
        stringBuilder.deleteRange(-1, 3);
    }
    catch (StringIndexOutOfBoundsException &ex) {
        assertEquals("ABCXYZ", stringBuilder.toString());
    }
    try {
        // end < 0
        stringBuilder.deleteRange(1, -1);
    }
    catch (StringIndexOutOfBoundsException &ex) {
        assertEquals("ABCXYZ", stringBuilder.toString());
    }
    try {
        // start > end
        stringBuilder.deleteRange(3, 1);
    }
    catch (StringIndexOutOfBoundsException &ex){
        assertEquals("ABCXYZ", stringBuilder.toString());
    }
    stringBuilder.deleteRange(1, 3); // valid start, valid end
    assertEquals("AXYZ", stringBuilder.toString());
    stringBuilder.deleteRange(0, 0);
    assertEquals("AXYZ", stringBuilder.toString());
    stringBuilder.deleteRange(0, 999);
    assertEquals("", stringBuilder.toString());
}

TEST(JavaLang, StringBuilderDeleteCharAt) {
    StringBuilder stringBuilder((const string)"ABCXYZ");
    assertEquals("ABCXYZ", stringBuilder.toString());
    stringBuilder.deleteCharAt(0);
    assertEquals("BCXYZ", stringBuilder.toString());
    stringBuilder.deleteCharAt(1);
    assertEquals("BXYZ", stringBuilder.toString());
}

TEST(JavaLang, StringBuilderEnsureCapacity) {
	// Default capacity.
	StringBuilder stringBuilder;
	assertEquals(0, stringBuilder.length());
	assertEquals(16, stringBuilder.capacity());
	// New capacity is not positive.
	stringBuilder.ensureCapacity(-1);
	assertEquals(16, stringBuilder.capacity());
	stringBuilder.ensureCapacity(0);
	assertEquals(16, stringBuilder.capacity());
	// New capacity less than current capacity.
	stringBuilder.ensureCapacity(10);
	assertEquals(16, stringBuilder.capacity());
	// New capacity larger than current capacity but less than (2 * current + 2).
	stringBuilder.ensureCapacity(17);
	assertEquals(2 * 16 + 2, stringBuilder.capacity());
	// New capacity larget than current capacity but larger than (2 * current + 2).
	stringBuilder.ensureCapacity(100);
	assertEquals(100, stringBuilder.capacity());
}

TEST(JavaLang, StringBuilderGetChars) {
	// TODO
}

TEST(JavaLang, StringBuilderIndexOf) {
    StringBuilder stringBuilder((const string)"Welcome to Vietnam");
    assertEquals(0, stringBuilder.indexOf((const string)"Welcome"));
    assertEquals(0, stringBuilder.indexOf(String("Welcome")));
    assertEquals(11, stringBuilder.indexOf((const string)"Vietnam"));
    assertEquals(11, stringBuilder.indexOf(String("Vietnam")));
    assertEquals(-1, stringBuilder.indexOf((const string)"Hello"));
    assertEquals(-1, stringBuilder.indexOf(String("Hello")));
    stringBuilder.append((const string)" Vietnam");
    assertEquals("Welcome to Vietnam Vietnam", stringBuilder.toString());
    assertEquals(11, stringBuilder.indexOf((const string)"Vietnam", 10));
    assertEquals(11, stringBuilder.indexOf(String("Vietnam"), 10));
    assertEquals(11, stringBuilder.indexOf((const string)"Vietnam", 11));
    assertEquals(11, stringBuilder.indexOf(String("Vietnam"), 11));
    assertEquals(19, stringBuilder.indexOf((const string)"Vietnam", 12));
    assertEquals(19, stringBuilder.indexOf(String("Vietnam"), 12));
    assertEquals(-1, stringBuilder.indexOf((const string)"Vietnam", 20));
    assertEquals(-1, stringBuilder.indexOf(String("Vietnam"), 20));
}

TEST(JavaLang, StringBuilderInsert) {
    // String and string
    StringBuilder stringBuilder1((const string)"123");
    assertEquals("123", stringBuilder1.toString());
    try {
        // offset is negative
        stringBuilder1.insert(-1, (const string)"xxx");
    }
    catch (StringIndexOutOfBoundsException &ex) {
        assertEquals("123", stringBuilder1.toString());
    }
    try {
        // offset is larger than length of StringBuilder
        stringBuilder1.insert(999, (const string)"xxx");
    }
    catch (StringIndexOutOfBoundsException &ex) {
        assertEquals("123", stringBuilder1.toString());
    }
    stringBuilder1.insert(1, (const string)"xxx");
    assertEquals("1xxx23", stringBuilder1.toString());
    stringBuilder1.insert(1, String("yyy"));
    assertEquals("1yyyxxx23", stringBuilder1.toString());

    // Boolean and boolean
    StringBuilder stringBuilder2((const string)"1 = 1 is ");
    stringBuilder2.insert(stringBuilder2.length(), Boolean(true));
    assertEquals("1 = 1 is true", stringBuilder2.toString());
    stringBuilder2.insert(0, false);
    assertEquals("false1 = 1 is true", stringBuilder2.toString());

    // Long and long, Integer and int
    StringBuilder stringBuilder3((const string)"0");
    stringBuilder3.insert(1, 1000l);
    assertEquals("01000", stringBuilder3.toString());
    stringBuilder3.insert(1, Long(10l));
    assertEquals("0101000", stringBuilder3.toString());
    stringBuilder3.insert(0, 10);
    assertEquals("100101000", stringBuilder3.toString());
    stringBuilder3.insert(0, Integer(100));
    assertEquals("100100101000", stringBuilder3.toString());

    // Float and float, Double and double
    StringBuilder stringBuilder4((const string)"abc");
    stringBuilder4.insert(1, 0.8f);
    assertEquals("a0.8bc", stringBuilder4.toString());
    stringBuilder4.insert(0, 0.7f);
    assertEquals("0.7a0.8bc", stringBuilder4.toString());
    stringBuilder4.insert(0, 0.1);
    assertEquals("0.1000000000000000.7a0.8bc", stringBuilder4.toString());
    stringBuilder4.insert(1, Double(0.2));
    assertEquals("00.200000000000000.1000000000000000.7a0.8bc", stringBuilder4.toString());

    // Character and char
    StringBuilder stringBuilder5((const string)"abc");
    assertEquals("abc", stringBuilder5.toString());
    try {
        // offset < 0
        stringBuilder5.insert(-1, 'x');
    }
    catch (IndexOutOfBoundsException &ex) {
        assertEquals("abc", stringBuilder5.toString());
    }
    try {
        // offset > length of StringBuilder
        stringBuilder5.insert(999, 'x');
    }
    catch (IndexOutOfBoundsException &ex) {
        assertEquals("abc", stringBuilder5.toString());
    }
    stringBuilder5.insert(1, 'x');
    assertEquals("axbc", stringBuilder5.toString());
    try {
        // offset < 0
        stringBuilder5.insert(-1, Character('y'));
    }
    catch (IndexOutOfBoundsException &ex) {
        assertEquals("axbc", stringBuilder5.toString());
    }
    try {
        // offset > length of StringBuilder
        stringBuilder5.insert(999, Character('y'));
    }
    catch (IndexOutOfBoundsException &ex) {
        assertEquals("axbc", stringBuilder5.toString());
    }
    stringBuilder5.insert(1, Character('y'));
    assertEquals("ayxbc", stringBuilder5.toString());

    // Array<Character> and Array<char>
    StringBuilder stringBuilder6((const string)"abc");
    stringBuilder6.insert(0, Array<char>{'1', '2', '3'});
    assertEquals("123abc", stringBuilder6.toString());
    stringBuilder6.insert(1, Array<Character> {Character('x'), Character('y'), Character('z')});
    assertEquals("1xyz23abc", stringBuilder6.toString());

    // Sub array of Array<Character> and Array<char>
    StringBuilder stringBuilder7((const string)"abc");
    Array<char> anArray1 {'1', '2', '3'};
    assertEquals("abc", stringBuilder7.toString());
    try {
        // index < 0
        stringBuilder7.insert(-1, anArray1, 1, 2);
    }
    catch (StringIndexOutOfBoundsException &ex){
        assertEquals("abc", stringBuilder7.toString());
    }
    try {
        // index > currentLength
        stringBuilder7.insert(999, anArray1, 1, 2);
    }
    catch (StringIndexOutOfBoundsException &ex){
        assertEquals("abc", stringBuilder7.toString());
    }
    try {
        // offset < 0
        stringBuilder7.insert(1, anArray1, -1, 2);
    }
    catch (StringIndexOutOfBoundsException &ex) {
        assertEquals("abc", stringBuilder7.toString());
    }
    try {
        // length < 0
        stringBuilder7.insert(1, anArray1, 1, -1);
    }
    catch (StringIndexOutOfBoundsException &ex) {
        assertEquals("abc", stringBuilder7.toString());
    }
    try {
        // offset + length > lengthOfArray
        stringBuilder7.insert(1, anArray1, 1, 100);
    }
    catch (StringIndexOutOfBoundsException &ex){
        assertEquals("abc", stringBuilder7.toString());
    }
    stringBuilder7.insert(1, anArray1, 1, 2); // valid index, offset, length
    assertEquals("a23bc", stringBuilder7.toString());
    Array<Character> anArray2 {Character('x'), Character('y'), Character('z')};
    try {
        // index < 0
        stringBuilder7.insert(-1, anArray2 , 1, 1);
    }
    catch (StringIndexOutOfBoundsException &ex){
        assertEquals("a23bc", stringBuilder7.toString());
    }
    try {
        // index > currentLength
        stringBuilder7.insert(999, anArray2 , 1, 1);
    }
    catch (StringIndexOutOfBoundsException &ex){
        assertEquals("a23bc", stringBuilder7.toString());
    }
    try {
        // offset < 0
        stringBuilder7.insert(1, anArray2 , -1, 1);
    }
    catch (StringIndexOutOfBoundsException &ex) {
        assertEquals("a23bc", stringBuilder7.toString());
    }
    try {
        // length < 0
        stringBuilder7.insert(1, anArray2 , 1, -1);
    }
    catch (StringIndexOutOfBoundsException &ex) {
        assertEquals("a23bc", stringBuilder7.toString());
    }
    try {
        // offset + length > lengthOfArray
        stringBuilder7.insert(1, anArray2 , 1, 999);
    }
    catch (StringIndexOutOfBoundsException &ex){
        assertEquals("a23bc", stringBuilder7.toString());
    }
    stringBuilder7.insert(1, anArray2 , 1, 1); // valid index, offset, length
    assertEquals("ay23bc", stringBuilder7.toString());

    // CharSequence
    StringBuilder stringBuilder8((const string)"abc");
    assertEquals("abc", stringBuilder8.toString());
    CharSequence *charSequence = (CharSequence *)new String("xyz");
    stringBuilder8.insert(1, *charSequence);
    assertEquals("axyzbc", stringBuilder8.toString());

    try {
        // destinationOffset < 0
        stringBuilder8.insert(-1, *charSequence, 1, 1);
    }
    catch (IndexOutOfBoundsException &ex) {
        assertEquals("axyzbc", stringBuilder8.toString());
    }
    try {
        // destinationOffset > length of this StringBuilder
        stringBuilder8.insert(999, *charSequence, 1, 1);
    }
    catch (IndexOutOfBoundsException &ex) {
        assertEquals("axyzbc", stringBuilder8.toString());
    }
    try {
        // start < 0
        stringBuilder8.insert(1, *charSequence, -1, 1);
    }
    catch (IndexOutOfBoundsException &ex) {
        assertEquals("axyzbc", stringBuilder8.toString());
    }
    try {
        // end < 0
        stringBuilder8.insert(1, *charSequence, 1, -1);
    }
    catch (IndexOutOfBoundsException &ex) {
        assertEquals("axyzbc", stringBuilder8.toString());
    }
    try {
        // start > end
        stringBuilder8.insert(1, *charSequence, 2, 1);
    }
    catch (IndexOutOfBoundsException &ex) {
        assertEquals("axyzbc", stringBuilder8.toString());
    }
    try {
        // end > length of target (charSequence)
        stringBuilder8.insert(1, *charSequence, 1, 999);
    }
    catch (IndexOutOfBoundsException &ex){
        assertEquals("axyzbc", stringBuilder8.toString());
    }
    stringBuilder8.insert(1, *charSequence, 1, 1);
    assertEquals("axyzbc", stringBuilder8.toString());
    stringBuilder8.insert(1, *charSequence, 1, 2);
    assertEquals("ayxyzbc", stringBuilder8.toString());
    stringBuilder8.insert(1, *charSequence, 1, 3);
    assertEquals("ayzyxyzbc", stringBuilder8.toString());
    String *charSequenceString = dynamic_cast<String *>(charSequence); // FIXME: Must use this 'dynamic_cast' operator because CharSequence class doesn't have virtual destructor.
    delete charSequenceString;
}

TEST(JavaLang, StringBuilderLastIndexOf) {
    StringBuilder stringBuilder((const string)"Welcome to Vietnam");
    assertEquals("Welcome to Vietnam", stringBuilder.toString());
    assertEquals(11, stringBuilder.lastIndexOf((const string)"Vietnam"));
    assertEquals(11, stringBuilder.lastIndexOf(String("Vietnam")));
    assertEquals(0, stringBuilder.lastIndexOf((const string)"Welcome"));
    assertEquals(0, stringBuilder.lastIndexOf(String("Welcome")));
    assertEquals(-1, stringBuilder.lastIndexOf((const string)"Vietnam", 11));
    assertEquals(-1, stringBuilder.lastIndexOf(String("Vietnam"), 11));
    assertEquals(-1, stringBuilder.lastIndexOf((const string)"Vietnam", 12));
    assertEquals(-1, stringBuilder.lastIndexOf(String("Vietnam"), 12));
    assertEquals(11, stringBuilder.lastIndexOf((const string)"Vietnam", stringBuilder.length()));
    assertEquals(11, stringBuilder.lastIndexOf(String("Vietnam"), stringBuilder.length()));
}

TEST(JavaLang, StringBuilderLength) {
	String aString("Hello! I'm a String");
	StringBuilder stringBuilder(aString);
	assertEquals(aString.length(), stringBuilder.length());
}

TEST(JavaLang, StringBuilderReplace) {
    StringBuilder stringBuilder((const string)"ABCXYZ");
    assertEquals("ABCXYZ", stringBuilder.toString());
    stringBuilder.replace(1, 2, (const string)"123");
    assertEquals("A123CXYZ", stringBuilder.toString());
    stringBuilder.replace(0, 100, String("Clear!"));
    assertEquals("Clear!", stringBuilder.toString());
}

TEST(JavaLang, StringBuilderReverse) {
    StringBuilder stringBuilder1((const string)"ABCXYZ");
    stringBuilder1.reverse();
    assertEquals("ZYXCBA", stringBuilder1.toString());

    // Reverses all valid surrogate pairs are produced in reverse process.
    StringBuilder stringBuilder2((const string)"\u000DC00\u000D800");
    assertEquals("\u000DC00\u000D800", stringBuilder2.toString());
    stringBuilder1.reverse();
    assertEquals("\u000DC00\u000D800", stringBuilder2.toString());
}

TEST(JavaLang, StringBuilderSetCharAt) {
    StringBuilder stringBuilder((const string)"ABCXYZ");
    assertEquals("ABCXYZ", stringBuilder.toString());
    stringBuilder.setCharAt(0, 'T');
    assertEquals("TBCXYZ", stringBuilder.toString());
    stringBuilder.setCharAt(1, Character('V'));
    assertEquals("TVCXYZ", stringBuilder.toString());
}

TEST(JavaLang, StringBuilderSetLength) {
    StringBuilder stringBuilder((const string)"Hello! I'm a StringBuilder");
    assertEquals("Hello! I'm a StringBuilder", stringBuilder.toString());
    assertEquals(26, stringBuilder.length());
    stringBuilder.setLength(30);
    assertEquals(30, stringBuilder.length());
    assertEquals("Hello! I'm a StringBuilder", stringBuilder.toString());
    stringBuilder.setLength(6);
    assertEquals(6, stringBuilder.length());
    assertEquals("Hello!", stringBuilder.toString());
}

TEST(JavaLang, StringBuilderSubString) {
    StringBuilder stringBuilder((const string)"Hello Vietnam");
    assertEquals("Vietnam", stringBuilder.substring(6).toString());
    assertEquals("llo", stringBuilder.substring(2, 5).toString());
    try {
        stringBuilder.substring(-999);
    }
    catch (StringIndexOutOfBoundsException &ex) {
        assertEquals("String index out of range: -999", ex.getMessage().toString());
    }
}

TEST(JavaLang, StringBuilderToString) {
    String aString = "Hello!";
    StringBuilder stringBuilder(aString.toString());
    assertEquals(aString.toString(), stringBuilder.toString());
}

TEST(JavaLang, StringBuilderTrimToSize) {
	StringBuilder stringBuilder(100);
	assertEquals(100, stringBuilder.capacity());
	stringBuilder.trimToSize();
	assertEquals(0, stringBuilder.capacity());
	stringBuilder.append((const string) "123");
	stringBuilder.trimToSize();
	assertEquals(3, stringBuilder.capacity());
}
