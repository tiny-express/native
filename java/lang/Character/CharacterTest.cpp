//
// Created by huuphuoc on 28/05/2017.
//

extern "C" {
#include "../../../unit_test.h"
}

#include "../Character/Character.hpp"

using namespace Java::Lang;

TEST (JavaLang, CharacterConstructor) {
    // Create variable to test on CharacterConstructor
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
    // Create variable to test on CharacterCharCount
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

TEST (JavaLang, CharacterCharValue) {
    Character testCharacter = 'P';
    ASSERT_TRUE(testCharacter.charValue() == 'P');
}

TEST (JavaLang, CharacterCodePointAt) {
    Character testCharacter;
    Array<char> a;
    a.push('w');
    a.push('a');
    ASSERT_EQUAL(97, testCharacter.codePointAt(a,1));
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