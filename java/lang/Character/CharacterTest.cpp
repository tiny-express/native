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
}

TEST (JavaLang, CharacterCodePointBefore) {
    Character testCharacter;
    Array<char> a;
    a.push('w');
    a.push('a');
    ASSERT_EQUAL(97, testCharacter.codePointBefore(a,2));
}

TEST (JavaLang, CharacterGetNumericValue) {
    Character testCharacter;
    ASSERT_EQUAL(97, testCharacter.getNumericValue('a'));
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