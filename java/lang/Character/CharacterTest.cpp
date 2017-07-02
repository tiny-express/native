//
// Created by huuphuoc on 28/05/2017.
//

extern "C" {
#include "../../../unit_test.h"
}

#include "../Character/Character.hpp"

using namespace Java::Lang;

TEST (JavaLang, CharacterConstructor) {
    // Create variable to test CharacterConstructor.
    Character variableTest;

    // Test NULL value
    ASSERT_TRUE(variableTest.charValue() == '\0');

    // Test valid case
    variableTest = 'M';
    ASSERT_TRUE(variableTest.charValue() == 'M');

    // Test invalid case
    variableTest= 'M';
    ASSERT_FALSE(variableTest.charValue() == 'm');
}

// TEST int Character::charCount(int codePoint).
TEST (JavaLang, CharacterCharCount) {
    // Create variable to test Character::charCount(int codePoint).
    Character variableTest;
    int expectedRes;

    // Test LATIN CAPITAL LETTER A :  UTF-32 (hex)	0x00000041 (0041)
    expectedRes =1;
    ASSERT_EQUAL(expectedRes, variableTest.charCount(0x00000041));

    // Test Unicode Han Data 香 : UTF-32 (hex)	0x00009999 (9999)
    expectedRes =1;
    ASSERT_EQUAL(expectedRes, variableTest.charCount(0x00009999));

    // Test LINEAR B SYLLABLE B008 A : UTF-32 (hex)	0x00010000 (10000)
    expectedRes =2;
    ASSERT_EQUAL(expectedRes, variableTest.charCount(0x00010000));

    // Test AEGEAN WORD SEPARATOR LINE : UTF-32 (hex)	0x00010100 (10100)
    expectedRes =2;
    ASSERT_EQUAL(expectedRes, variableTest.charCount(0x00010100));
}

// TEST char Character::charValue().
TEST (JavaLang, CharacterCharValue) {
    // Create variable to test Character::charValue().
    Character variableTest;

    // Test NULL value
    ASSERT_TRUE(variableTest.charValue() == '\0');

    // Test valid case
    variableTest = 'M';
    ASSERT_TRUE(variableTest.charValue() == 'M');

    // Test invalid case
    variableTest= 'M';
    ASSERT_FALSE(variableTest.charValue() == 'm');
}

// TEST int Character::codePointBefore(Array<char> seq, int index).
TEST (JavaLang, CharacterCodePointAt) {
    // Create variable to test
    Array<char> seq;
    int index;
    int expectedRes;
    int actualRes;

    // Test valid case
    seq.push('a');
    index  = 0;
    actualRes = Character::codePointAt(seq, index);
    expectedRes = 97;
    ASSERT_EQUAL(expectedRes,actualRes);

    // Test invalid case
    seq.push('w');
    index  = 1;
    actualRes = Character::codePointAt(seq, index);
    expectedRes = 456;
    ASSERT_NOT_EQUAL(expectedRes,actualRes);

    // Test exception index < 0
    index  = -1;
    actualRes = Character::codePointAt(seq, index);
    expectedRes = -1;
    ASSERT_EQUAL(expectedRes,actualRes);

    // Test exception index >= len
    index  = 5;
    actualRes = Character::codePointAt(seq, index);
    expectedRes = -1;
    ASSERT_EQUAL(expectedRes,actualRes);
}

// TEST int Character::codePointBefore(char a[], int index).
TEST (JavaLang, CharacterCodePointAt2){
    // Create variable to test
    char a[30];
    int index;
    int expectedRes;
    int actualRes;

    // Test valid case
    strcpy(a,"This is a test string");
    index = 2 ;
    expectedRes= 105 ;
    actualRes = Character::codePointAt(a,index);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test invalid case
    strcpy(a,"This is a test string");
    index = 3 ;
    expectedRes= 105 ;
    actualRes = Character::codePointAt(a,index);
    ASSERT_NOT_EQUAL(expectedRes , actualRes);
}

// TEST int Character::codePointAt(char a[], int index, int limit);
TEST (JavaLang, CharacterCodePointAt3){
    // Create variable to test
    char a[30];
    int index;
    int limit;
    int expectedRes;
    int actualRes;

    // Test valid case.
    strcpy(a,"abc");
    index = 0 ;
    limit = 3 ;
    expectedRes= 'a';
    actualRes = Character::codePointAt(a,index,limit);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test valid case.
    strcpy(a,"abc");
    index = 1 ;
    limit = 3 ;
    expectedRes= 'b';
    actualRes = Character::codePointAt(a,index,limit);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test invalid case.
    strcpy(a,"abc");
    index = 1;
    limit = 3 ;
    expectedRes= 'c';
    actualRes = Character::codePointAt(a,index,limit);
    ASSERT_NOT_EQUAL(expectedRes , actualRes);

    // Test exception NULL.
    strcpy(a,"");
    index = 0;
    limit = 1 ;
    expectedRes= -1;
    actualRes = Character::codePointAt(a,index,limit);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test exception index < 0.
    strcpy(a,"abc");
    index = -1;
    limit = 3 ;
    expectedRes= -1;
    actualRes = Character::codePointAt(a,index,limit);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test exception index > limit.
    strcpy(a,"abc");
    index = 4;
    limit = 3 ;
    expectedRes= -1;
    actualRes = Character::codePointAt(a,index,limit);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test exception limit < 0.
    strcpy(a,"abc");
    index = 4;
    limit = -1 ;
    expectedRes= -1;
    actualRes = Character::codePointAt(a,index,limit);
    ASSERT_EQUAL(expectedRes , actualRes);
}

// TEST int Character::codePointAtImpl(char a[], int index, int limit).
TEST (JavaLang, CharacterCodePointAtImpl){
    // Create variable to test
    char a[30];
    int index;
    int limit;
    int expectedRes;
    int actualRes;

    // Test valid case.
    strcpy(a,"abc");
    index = 0 ;
    limit = 3 ;
    expectedRes= 'a';
    actualRes = Character::codePointAtImpl(a,index,limit);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test valid case.
    strcpy(a,"abc");
    index = 1 ;
    limit = 3 ;
    expectedRes= 'b';
    actualRes = Character::codePointAtImpl(a,index,limit);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test invalid case.
    strcpy(a,"abc");
    index = 1;
    limit = 3 ;
    expectedRes= 'c';
    actualRes = Character::codePointAtImpl(a,index,limit);
    ASSERT_NOT_EQUAL(expectedRes , actualRes);
}

// TEST int Character::codePointBefore(Array<char> seq, int index).
TEST (JavaLang, CharacterCodePointBefore){
    // Create variable to test
    Array<char> seq;
    int index;
    int expectedRes;
    int actualRes;
    seq.push('a');
    seq.push('b');
    seq.push('c');

    // Test valid case
    index  = 2;
    actualRes = Character::codePointBefore(seq, index);
    expectedRes = 'b';
    ASSERT_EQUAL(expectedRes,actualRes);

    // Test invalid case
    index  = 2;
    actualRes = Character::codePointBefore(seq, index);
    expectedRes = 'c';
    ASSERT_NOT_EQUAL(expectedRes,actualRes);
}

// TEST int Character::codePointBefore(char a[], int index).
TEST (JavaLang, CharacterCodePointBefore2){
    // Create variable to test
    char a[30];
    int index;
    int expectedRes;
    int actualRes;

    // Test valid case.
    strcpy(a,"abc");
    index = 1 ;
    expectedRes= 'a';
    actualRes = Character::codePointBefore(a,index);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test valid case.
    strcpy(a,"abc");
    index = 2 ;
    expectedRes= 'b';
    actualRes = Character::codePointBefore(a,index);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test invalid case.
    strcpy(a,"abc");
    index = 2;
    expectedRes= 'c';
    actualRes = Character::codePointBefore(a,index);
    ASSERT_NOT_EQUAL(expectedRes , actualRes);
}

// TEST int Character::codePointBefore(char a[], int index, int start).
TEST (JavaLang, CharacterCodePointBefore3){
    // Create variable to test
    char a[30];
    int index;
    int start;
    int expectedRes;
    int actualRes;

    // Test valid case.
    strcpy(a,"abc");
    index = 1 ;
    start = 0 ;
    expectedRes= 'a';
    actualRes = Character::codePointBefore(a,index,start);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test valid case.
    strcpy(a,"abc");
    index = 2 ;
    start = 0 ;
    expectedRes= 'b';
    actualRes = Character::codePointBefore(a,index,start);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test invalid case.
    strcpy(a,"abc");
    index = 3;
    start = 0 ;
    expectedRes= 'b';
    actualRes = Character::codePointBefore(a,index,start);
    ASSERT_NOT_EQUAL(expectedRes , actualRes);

    // Test exception NULL.
    strcpy(a,"");
    index = 1;
    start = 0 ;
    expectedRes= -1;
    actualRes = Character::codePointBefore(a,index,start);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test exception index < start.
    strcpy(a,"abc");
    index = 0;
    start = 1 ;
    expectedRes= -1;
    actualRes = Character::codePointBefore(a,index,start);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test exception start > length.
    strcpy(a,"abc");
    index = 2;
    start = 4 ;
    expectedRes= -1;
    actualRes = Character::codePointBefore(a,index,start);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test exception start < 0.
    strcpy(a,"abc");
    index = 2;
    start = -1 ;
    expectedRes= -1;
    actualRes = Character::codePointBefore(a,index,start);
    ASSERT_EQUAL(expectedRes , actualRes);
}

// TEST int Character::codePointBeforeImpl(char a[], int index, int start).
TEST (JavaLang, CharacterCodePointBeforeImpl){
    // Create variable to test
    char a[30];
    int index;
    int start;
    int expectedRes;
    int actualRes;

    // Test valid case.
    strcpy(a,"abc");
    index = 1 ;
    start = 0 ;
    expectedRes= 'a';
    actualRes = Character::codePointBeforeImpl(a,index,start);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test valid case.
    strcpy(a,"abc");
    index = 2 ;
    start = 0 ;
    expectedRes= 'b';
    actualRes = Character::codePointBeforeImpl(a,index,start);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test invalid case.
    strcpy(a,"abc");
    index = 3;
    start = 0 ;
    expectedRes= 'b';
    actualRes = Character::codePointBeforeImpl(a,index,start);
    ASSERT_NOT_EQUAL(expectedRes , actualRes);
}

// TEST int Character::codePointCount(Array<char> seq, int beginIndex,
// int endIndex).
TEST (JavaLang,CharacterCodePointCount ){
    // Create variable to test
    Array<char> seq;
    int beginIndex;
    int endIndex;
    int expectedRes;
    int actualRes;

    // Assign value to seq
    seq.push('a');
    seq.push('b');
    seq.push('c');

    // Test valid case
    beginIndex = 0;
    endIndex = 1;
    expectedRes = 1;
    actualRes = Character::codePointCount(seq,beginIndex,endIndex);
    ASSERT_EQUAL(expectedRes, actualRes);

    // Test valid case
    beginIndex = 0;
    endIndex = 2;
    expectedRes = 2;
    actualRes = Character::codePointCount(seq,beginIndex,endIndex);
    ASSERT_EQUAL(expectedRes, actualRes);

    // Test invalid case
    beginIndex = 0;
    endIndex = 3;
    expectedRes = 2;
    actualRes = Character::codePointCount(seq,beginIndex,endIndex);
    ASSERT_NOT_EQUAL(expectedRes, actualRes);

    // Test exception start < 0
    beginIndex = -1;
    endIndex = 3;
    expectedRes = -1;
    actualRes = Character::codePointCount(seq,beginIndex,endIndex);
    ASSERT_EQUAL(expectedRes, actualRes);

    // Test exception endIndex > length
    beginIndex = 0;
    endIndex = 4;
    expectedRes = -1;
    actualRes = Character::codePointCount(seq,beginIndex,endIndex);
    ASSERT_EQUAL(expectedRes, actualRes);

    // Test exception beginIndex > endIndex
    beginIndex = 2;
    endIndex = 1;
    expectedRes = -1;
    actualRes = Character::codePointCount(seq,beginIndex,endIndex);
    ASSERT_EQUAL(expectedRes, actualRes);
}

// TEST int Character::codePointCount(char a[], int offset, int count).
TEST (JavaLang,CharacterCodePointCount2 ){
    // Create variable to test
    char a[30];
    int offset;
    int count;
    int expectedRes;
    int actualRes;

    // Test valid case
    strcpy(a,"abc");
    offset = 0;
    count = 1;
    expectedRes = 1;
    actualRes = Character::codePointCount(a,offset,count);
    ASSERT_EQUAL(expectedRes, actualRes);

    // Test valid case
    strcpy(a,"abc");
    offset = 0;
    count = 2;
    expectedRes = 2;
    actualRes = Character::codePointCount(a,offset,count);
    ASSERT_EQUAL(expectedRes, actualRes);

    // Test invalid case
    strcpy(a,"abc");
    offset = 0;
    count = 2;
    expectedRes = 3;
    actualRes = Character::codePointCount(a,offset,count);
    ASSERT_NOT_EQUAL(expectedRes, actualRes);

    // Test exception NULL
    strcpy(a,"");
    offset = 0;
    count = 1;
    expectedRes = -1;
    actualRes = Character::codePointCount(a,offset,count);
    ASSERT_EQUAL(expectedRes, actualRes);

    // Test exception offset < 0
    offset = -1;
    count = 3;
    expectedRes = -1;
    actualRes = Character::codePointCount(a,offset,count);
    ASSERT_EQUAL(expectedRes, actualRes);

    // Test exception count > length
    offset = 0;
    count = 4;
    expectedRes = -1;
    actualRes = Character::codePointCount(a,offset,count);
    ASSERT_EQUAL(expectedRes, actualRes);

    // Test exception offset > count
    offset = 2;
    count = 1;
    expectedRes = -1;
    actualRes = Character::codePointCount(a,offset,count);
    ASSERT_EQUAL(expectedRes, actualRes);
}

// TEST int Character::codePointCountImpl(char a[], int offset, int count).
TEST (JavaLang,CharacterCodePointCountImpl ){
    // Create variable to test
    char a[30];
    int offset;
    int count;
    int expectedRes;
    int actualRes;

    // Test valid case
    strcpy(a,"abc");
    offset = 0;
    count = 1;
    expectedRes = 1;
    actualRes = Character::codePointCountImpl(a,offset,count);
    ASSERT_EQUAL(expectedRes, actualRes);

    // Test valid case
    strcpy(a,"abc");
    offset = 0;
    count = 2;
    expectedRes = 2;
    actualRes = Character::codePointCountImpl(a,offset,count);
    ASSERT_EQUAL(expectedRes, actualRes);

    // Test invalid case
    strcpy(a,"abc");
    offset = 0;
    count = 2;
    expectedRes = 3;
    actualRes = Character::codePointCountImpl(a,offset,count);
    ASSERT_NOT_EQUAL(expectedRes, actualRes);
}

TEST (JavaLang, CharactertoCodePoint){
    // Create variable to test
    wchar_t variableTest1;
    wchar_t variableTest2;
    int expectedRes;
    int actualRes;

    // Test valid case
    variableTest1 = '\u000D800' ;
    variableTest2 = '\u000DC00' ;
    expectedRes= 65536 ;
    actualRes = Character::toCodePoint(variableTest1, variableTest2);
    ASSERT_EQUAL(expectedRes , actualRes);

    // Test invalid case
    variableTest1 = '\u000d800' ;
    variableTest2 = '\u000dc11' ;
    expectedRes= 60000 ;
    actualRes = Character::toCodePoint(variableTest1, variableTest2);
    ASSERT_NOT_EQUAL(expectedRes , actualRes);
}

TEST (JavaLang, CharacterisHighSurrogate){
    // Create variable to test
    wchar_t variableTest;
    boolean expectedRes;
    boolean actualRes;

    // Test valid case
    variableTest = '\u000D800' ;
    expectedRes= 1 ;
    actualRes = Character::isHighSurrogate(variableTest);
    ASSERT_TRUE(expectedRes == actualRes);

    // Test invalid case
    variableTest = '\u000D777' ;
    expectedRes= 0 ;
    actualRes = Character::isHighSurrogate(variableTest);
    ASSERT_TRUE(expectedRes == actualRes);
}

TEST (JavaLang, CharacterisLowSurrogate){
    // Create variable to test
    wchar_t variableTest;
    boolean expectedRes;
    boolean actualRes;

    // Test valid case
    variableTest = '\u000DC00' ;
    expectedRes= 1 ;
    actualRes = Character::isLowSurrogate(variableTest);
    ASSERT_TRUE(expectedRes == actualRes);

    // Test invalid case
    variableTest = '\u000DB00' ;
    expectedRes= 0 ;
    actualRes = Character::isLowSurrogate(variableTest);
    ASSERT_TRUE(expectedRes == actualRes);
}

TEST (JavaLang, CharacterDigit) {
    //Given valid and invalid value to test with digit(char char, int radix)
    char hexValue = 'b';
    char hexValue2 = 'd';
    char hexValue3 = '5';

    char wrongValue = 'q';

    int expectedResult = 11;
    ASSERT_EQUAL(expectedResult, Character::digit(hexValue, 16));

    expectedResult = 13;
    ASSERT_EQUAL(expectedResult, Character::digit(hexValue2, 16));

    expectedResult = 5;
    ASSERT_EQUAL(expectedResult, Character::digit(hexValue3, 16));

    expectedResult = -1;
    ASSERT_EQUAL(expectedResult, Character::digit(wrongValue, 16));
}