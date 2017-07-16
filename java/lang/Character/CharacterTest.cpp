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
    Character variableTestConstructor;

    // Test NULL value
    ASSERT_TRUE(variableTestConstructor.charValue() == '\0');

    // Test valid case
    variableTestConstructor = 'M';
    ASSERT_TRUE(variableTestConstructor.charValue() == 'M');

    // Test invalid case
    variableTestConstructor= 'M';
    ASSERT_FALSE(variableTestConstructor.charValue() == 'm');
}

TEST (JavaLang, CharacterCharCount) {
    // Create variable to test Character::charCount(int codePoint).
    Character variableTestCharCount;
    int expectedResultCharCount;
    int actualResultCharCount;

    // Test LATIN CAPITAL LETTER A :  UTF-32 (hex)	0x00000041 (0041)
    expectedResultCharCount =1;
    actualResultCharCount = variableTestCharCount.charCount(0x00000041);
    ASSERT_EQUAL(expectedResultCharCount, actualResultCharCount);

    // Test Unicode Han Data 香 : UTF-32 (hex)	0x00009999 (9999)
    expectedResultCharCount =1;
    actualResultCharCount = variableTestCharCount.charCount(0x00009999);
    ASSERT_EQUAL(expectedResultCharCount, actualResultCharCount);

    // Test LINEAR B SYLLABLE B008 A : UTF-32 (hex)	0x00010000 (10000)
    expectedResultCharCount =2;
    actualResultCharCount = variableTestCharCount.charCount(0x00010000);
    ASSERT_EQUAL(expectedResultCharCount, actualResultCharCount);

    // Test AEGEAN WORD SEPARATOR LINE : UTF-32 (hex)	0x00010100 (10100)
    expectedResultCharCount =2;
    actualResultCharCount = variableTestCharCount.charCount(0x00010100);
    ASSERT_EQUAL(expectedResultCharCount, actualResultCharCount);
}

TEST (JavaLang, CharacterCharValue) {
    // Create variable to test Character::charValue().
    Character variableTestCharValue;

    // Test NULL value
    ASSERT_TRUE(variableTestCharValue.charValue() == '\0');

    // Test valid case
    variableTestCharValue = 'M';
    ASSERT_TRUE(variableTestCharValue.charValue() == 'M');

    // Test invalid case
    variableTestCharValue= 'M';
    ASSERT_FALSE(variableTestCharValue.charValue() == 'm');
}

TEST (JavaLang, CharacterCodePointAt) {
    // Create variable to test
    Array<char> arrayCodePointAt;
    int index;
    int expectedResultCodePointAt;
    int actualResultCodePointAt;

    // Assign value to arrayCodePointAt
    arrayCodePointAt.push('a');
    arrayCodePointAt.push('w');

    // Test valid case
    index  = 0;
    actualResultCodePointAt = Character::codePointAt(arrayCodePointAt,index);
    expectedResultCodePointAt = 97;
    ASSERT_EQUAL(expectedResultCodePointAt,actualResultCodePointAt);

    // Test invalid case
    index  = 1;
    actualResultCodePointAt = Character::codePointAt(arrayCodePointAt, index);
    expectedResultCodePointAt = 456;
    ASSERT_NOT_EQUAL(expectedResultCodePointAt,actualResultCodePointAt);
}

TEST (JavaLang, CharacterCodePointAt2){
    // Create variable to test
    Array<char> arrayCodePointAt2;
    int indexCodePointAt2;
    int limitCodePointAt2;
    int expectedResultCodePointAt2;
    int actualResultCodePointAt2;

    // Assign value to arrayCodePointAt2
    arrayCodePointAt2.push('a');
    arrayCodePointAt2.push('b');
    arrayCodePointAt2.push('c');

    // Test valid case.
    indexCodePointAt2 = 0 ;
    limitCodePointAt2 = 3 ;
    expectedResultCodePointAt2= 'a';
    actualResultCodePointAt2 = Character::codePointAt(arrayCodePointAt2,indexCodePointAt2,limitCodePointAt2);
    ASSERT_EQUAL(expectedResultCodePointAt2 , actualResultCodePointAt2);

    // Test valid case.
    indexCodePointAt2 = 1 ;
    limitCodePointAt2 = 3 ;
    expectedResultCodePointAt2= 'b';
    actualResultCodePointAt2 = Character::codePointAt(arrayCodePointAt2,indexCodePointAt2,limitCodePointAt2);
    ASSERT_EQUAL(expectedResultCodePointAt2 , actualResultCodePointAt2);

    // Test invalid case.
    indexCodePointAt2 = 2;
    limitCodePointAt2 = 3 ;
    expectedResultCodePointAt2= 'b';
    actualResultCodePointAt2 = Character::codePointAt(arrayCodePointAt2,indexCodePointAt2,limitCodePointAt2);
    ASSERT_NOT_EQUAL(expectedResultCodePointAt2 , actualResultCodePointAt2);

    // Test exception index >= limit.
    indexCodePointAt2 = 3;
    limitCodePointAt2 = 3 ;
    expectedResultCodePointAt2= -1;
    actualResultCodePointAt2 = Character::codePointAt(arrayCodePointAt2,indexCodePointAt2,limitCodePointAt2);
    ASSERT_EQUAL(expectedResultCodePointAt2 , actualResultCodePointAt2);

    // Test exception limit < 0.
    indexCodePointAt2 = 2;
    limitCodePointAt2 = -1 ;
    expectedResultCodePointAt2= -1;
    actualResultCodePointAt2 = Character::codePointAt(arrayCodePointAt2,indexCodePointAt2,limitCodePointAt2);
    ASSERT_EQUAL(expectedResultCodePointAt2 , actualResultCodePointAt2);

    // Test exception limit > length.
    indexCodePointAt2 = 2;
    limitCodePointAt2 = 5 ;
    expectedResultCodePointAt2= -1;
    actualResultCodePointAt2 = Character::codePointAt(arrayCodePointAt2,indexCodePointAt2,limitCodePointAt2);
    ASSERT_EQUAL(expectedResultCodePointAt2 , actualResultCodePointAt2);
}

TEST (JavaLang, CharacterCodePointBefore){
    // Create variable to test
    Array<char> arrayCodePointBefore;
    int indexCodePointBefore;
    int expectedResultCodePointBefore;
    int actualResultCodePointBefore;
    arrayCodePointBefore.push('a');
    arrayCodePointBefore.push('b');
    arrayCodePointBefore.push('c');

    // Test valid case
    indexCodePointBefore  = 2;
    actualResultCodePointBefore = Character::codePointBefore(arrayCodePointBefore, indexCodePointBefore);
    expectedResultCodePointBefore = 'b';
    ASSERT_EQUAL(expectedResultCodePointBefore,actualResultCodePointBefore);

    // Test invalid case
    indexCodePointBefore  = 2;
    actualResultCodePointBefore = Character::codePointBefore(arrayCodePointBefore, indexCodePointBefore);
    expectedResultCodePointBefore = 'c';
    ASSERT_NOT_EQUAL(expectedResultCodePointBefore,actualResultCodePointBefore);
}

TEST (JavaLang, CharacterCodePointBefore2){
    // Create variable to test
    Array<char> arrayCodePointBefore2;
    int indexCodePointBefore2;
    int startCodePointBefore2;
    int expectedResultCodePointBefore2;
    int actualResultCodePointBefore2;

    // Assign value to a
    arrayCodePointBefore2.push('a');
    arrayCodePointBefore2.push('b');
    arrayCodePointBefore2.push('c');

    // Test valid case.
    indexCodePointBefore2 = 1 ;
    startCodePointBefore2 = 0 ;
    expectedResultCodePointBefore2= 'a';
    actualResultCodePointBefore2 = Character::codePointBefore(arrayCodePointBefore2,indexCodePointBefore2,startCodePointBefore2);
    ASSERT_EQUAL(expectedResultCodePointBefore2 , actualResultCodePointBefore2);

    // Test valid case.
    indexCodePointBefore2 = 2 ;
    startCodePointBefore2 = 0 ;
    expectedResultCodePointBefore2= 'b';
    actualResultCodePointBefore2 = Character::codePointBefore(arrayCodePointBefore2,indexCodePointBefore2,startCodePointBefore2);
    ASSERT_EQUAL(expectedResultCodePointBefore2 , actualResultCodePointBefore2);

    // Test invalid case.
    indexCodePointBefore2 = 3;
    startCodePointBefore2 = 0 ;
    expectedResultCodePointBefore2= 'b';
    actualResultCodePointBefore2 = Character::codePointBefore(arrayCodePointBefore2,indexCodePointBefore2,startCodePointBefore2);
    ASSERT_NOT_EQUAL(expectedResultCodePointBefore2 , actualResultCodePointBefore2);

    // Test exception index < start.
    indexCodePointBefore2 = 0;
    startCodePointBefore2 = 1 ;
    expectedResultCodePointBefore2= -1;
    actualResultCodePointBefore2 = Character::codePointBefore(arrayCodePointBefore2,indexCodePointBefore2,startCodePointBefore2);
    ASSERT_EQUAL(expectedResultCodePointBefore2 , actualResultCodePointBefore2);

    // Test exception start > length.
    indexCodePointBefore2 = 2;
    startCodePointBefore2 = 4 ;
    expectedResultCodePointBefore2= -1;
    actualResultCodePointBefore2 = Character::codePointBefore(arrayCodePointBefore2,indexCodePointBefore2,startCodePointBefore2);
    ASSERT_EQUAL(expectedResultCodePointBefore2 , actualResultCodePointBefore2);

    // Test exception start < 0.
    indexCodePointBefore2 = 2;
    startCodePointBefore2 = -1 ;
    expectedResultCodePointBefore2= -1;
    actualResultCodePointBefore2 = Character::codePointBefore(arrayCodePointBefore2,indexCodePointBefore2,startCodePointBefore2);
    ASSERT_EQUAL(expectedResultCodePointBefore2 , actualResultCodePointBefore2);
}

TEST (JavaLang,CharacterCodePointCount ){
    // Create variable to test
    Array<char> arrayCodePointCount;
    int offsetCodePointCount;
    int countCodePointCount;
    int expectedResultCodePointCount;
    int actualResultCodePointCount;

    // Assign value to a
    arrayCodePointCount.push('a');
    arrayCodePointCount.push('b');
    arrayCodePointCount.push('c');

    // Test valid case
    offsetCodePointCount = 0;
    countCodePointCount = 1;
    expectedResultCodePointCount = 1;
    actualResultCodePointCount = Character::codePointCount(arrayCodePointCount,offsetCodePointCount,countCodePointCount);
    ASSERT_EQUAL(expectedResultCodePointCount, actualResultCodePointCount);

    // Test valid case
    offsetCodePointCount = 0;
    countCodePointCount = 2;
    expectedResultCodePointCount = 2;
    actualResultCodePointCount = Character::codePointCount(arrayCodePointCount,offsetCodePointCount,countCodePointCount);
    ASSERT_EQUAL(expectedResultCodePointCount, actualResultCodePointCount);

    // Test invalid case
    offsetCodePointCount = 0;
    countCodePointCount = 3;
    expectedResultCodePointCount = 2;
    actualResultCodePointCount = Character::codePointCount(arrayCodePointCount,offsetCodePointCount,countCodePointCount);
    ASSERT_NOT_EQUAL(expectedResultCodePointCount, actualResultCodePointCount);

    // Test exception offset < 0
    offsetCodePointCount = -1;
    countCodePointCount = 3;
    expectedResultCodePointCount = -1;
    actualResultCodePointCount = Character::codePointCount(arrayCodePointCount,offsetCodePointCount,countCodePointCount);
    ASSERT_EQUAL(expectedResultCodePointCount, actualResultCodePointCount);

    // Test exception count < 0
    offsetCodePointCount = 0;
    countCodePointCount = -1;
    expectedResultCodePointCount = -1;
    actualResultCodePointCount = Character::codePointCount(arrayCodePointCount,offsetCodePointCount,countCodePointCount);
    ASSERT_EQUAL(expectedResultCodePointCount, actualResultCodePointCount);

    // Test exception count > length - offset
    offsetCodePointCount = 2;
    countCodePointCount = 5;
    expectedResultCodePointCount = -1;
    actualResultCodePointCount = Character::codePointCount(arrayCodePointCount,offsetCodePointCount,countCodePointCount);
    ASSERT_EQUAL(expectedResultCodePointCount, actualResultCodePointCount);
}

TEST (JavaLang, CharacterCompare){
    // Create variable to test
    char xCompare;
    char yCompare;
    int expectedResultCompare;
    int actualResultCompare;

    // Test valid case
    xCompare='d';
    yCompare='d';
    expectedResultCompare= 0;
    actualResultCompare = Character::compare(xCompare,yCompare);
    ASSERT_EQUAL(expectedResultCompare,actualResultCompare);

    // Test valid case
    xCompare='d';
    yCompare='a';
    expectedResultCompare= 3;
    actualResultCompare = Character::compare(xCompare,yCompare);
    ASSERT_EQUAL(expectedResultCompare,actualResultCompare);

    // Test valid case
    xCompare='d';
    yCompare='e';
    expectedResultCompare= -1;
    actualResultCompare = Character::compare(xCompare,yCompare);
    ASSERT_EQUAL(expectedResultCompare,actualResultCompare);
}

TEST (JavaLang, CharacterCompareTo){
    // Create variable to test
    Character variableTestCompareTo;
    Character anotherCharacterCompareTo;
    int expectedResultCompareTo;
    int actualResultCompareTo;

    // Test valid case
    variableTestCompareTo = 'd';
    anotherCharacterCompareTo='d';
    expectedResultCompareTo=0;
    actualResultCompareTo= variableTestCompareTo.compareTo(anotherCharacterCompareTo);
    ASSERT_EQUAL(expectedResultCompareTo,actualResultCompareTo);

    // Test valid case
    variableTestCompareTo = 'd';
    anotherCharacterCompareTo='a';
    expectedResultCompareTo=3;
    actualResultCompareTo= variableTestCompareTo.compareTo(anotherCharacterCompareTo);
    ASSERT_EQUAL(expectedResultCompareTo,actualResultCompareTo);

    // Test valid case
    variableTestCompareTo = 'd';
    anotherCharacterCompareTo='e';
    expectedResultCompareTo=-1;
    actualResultCompareTo= variableTestCompareTo.compareTo(anotherCharacterCompareTo);
    ASSERT_EQUAL(expectedResultCompareTo,actualResultCompareTo);
}

// TEST sample
TEST (JavaLang, CharacterTestSample){
    // Create variable to test
    int expectedResultTestSample;
    int actualResultTestSample;

    // Test valid case

    // Test invalid case

    // Test exception
}

TEST (JavaLang, CharacterToCodePoint){
    // Create variable to test
    wchar_t variableTest1ToCodePoint;
    wchar_t variableTest2ToCodePoint;
    int expectedResultToCodePoint;
    int actualResultToCodePoint;

    // Test valid case
    variableTest1ToCodePoint = '\u000D800' ;
    variableTest2ToCodePoint = '\u000DC00' ;
    expectedResultToCodePoint= 65536 ;
    actualResultToCodePoint = Character::toCodePoint(variableTest1ToCodePoint, variableTest2ToCodePoint);
    ASSERT_EQUAL(expectedResultToCodePoint , actualResultToCodePoint);

    // Test invalid case
    variableTest1ToCodePoint = '\u000d800' ;
    variableTest2ToCodePoint = '\u000dc11' ;
    expectedResultToCodePoint= 60000 ;
    actualResultToCodePoint = Character::toCodePoint(variableTest1ToCodePoint, variableTest2ToCodePoint);
    ASSERT_NOT_EQUAL(expectedResultToCodePoint , actualResultToCodePoint);
}

TEST (JavaLang, CharacterIsHighSurrogate){
    // Create variable to test
    wchar_t variableTestIsHighSurrogate;
    boolean actualResultIsHighSurrogate;

    // Test valid case
    variableTestIsHighSurrogate = '\u000D800' ;
    actualResultIsHighSurrogate = Character::isHighSurrogate(variableTestIsHighSurrogate);
    ASSERT_TRUE(actualResultIsHighSurrogate);

    // Test invalid case
    variableTestIsHighSurrogate = '\u000D777' ;
    actualResultIsHighSurrogate = Character::isHighSurrogate(variableTestIsHighSurrogate);
    ASSERT_FALSE(actualResultIsHighSurrogate);
}

TEST (JavaLang, CharacterisLowSurrogate){
    // Create variable to test
    wchar_t variableTestisLowSurrogate;
    boolean expectedResultisLowSurrogate;
    boolean actualResultisLowSurrogate;

    // Test valid case
    variableTestisLowSurrogate = '\u000DC00' ;
    expectedResultisLowSurrogate= 1 ;
    actualResultisLowSurrogate = Character::isLowSurrogate(variableTestisLowSurrogate);
    ASSERT_TRUE(expectedResultisLowSurrogate == actualResultisLowSurrogate);

    // Test invalid case
    variableTestisLowSurrogate = '\u000DB00' ;
    expectedResultisLowSurrogate= 0 ;
    actualResultisLowSurrogate = Character::isLowSurrogate(variableTestisLowSurrogate);
    ASSERT_TRUE(expectedResultisLowSurrogate == actualResultisLowSurrogate);
}

TEST(JavaLang, CharacterIsSurrogate) {
    // Create variable to test
    wchar_t variableTestIsSurrogate;
    boolean expectedResultIsSurrogate;
    boolean actualResultIsSurrogate;

    // Test valid case
    variableTestIsSurrogate = '\u000DC00' ;
    expectedResultIsSurrogate = true;
    actualResultIsSurrogate = Character::isSurrogate(variableTestIsSurrogate);
    ASSERT_TRUE(expectedResultIsSurrogate == actualResultIsSurrogate);

    // Test invalid case
    variableTestIsSurrogate = L'A';
    expectedResultIsSurrogate = false;
    actualResultIsSurrogate = Character::isSurrogate(variableTestIsSurrogate);
    ASSERT_TRUE(expectedResultIsSurrogate == actualResultIsSurrogate);
}

TEST (JavaLang, CharacterDigit) {
    //Given valid and invalid value to test with digit(char char, int radix)
    char hexValueDigit = 'b';
    char hexValue2Digit= 'd';
    char hexValue3Digit = '5';

    char wrongValueDigit = 'q';

    int expectedResultDigit = 11;
    ASSERT_EQUAL(expectedResultDigit, Character::digit(hexValueDigit, 16));

    expectedResultDigit = 13;
    ASSERT_EQUAL(expectedResultDigit, Character::digit(hexValue2Digit, 16));

    expectedResultDigit = 5;
    ASSERT_EQUAL(expectedResultDigit, Character::digit(hexValue3Digit, 16));

    expectedResultDigit = -1;
    ASSERT_EQUAL(expectedResultDigit, Character::digit(wrongValueDigit, 16));
}