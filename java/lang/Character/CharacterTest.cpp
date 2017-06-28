//
// Created by huuphuoc on 28/05/2017.
//

extern "C" {
#include "../../../unit_test.h"
}

#include "../Character/Character.hpp"

using namespace Java::Lang;

TEST (JavaLang, CharacterConstructor) {
    Character nullCharacter;
    ASSERT_TRUE(nullCharacter.charValue() == '\0');
}

TEST (JavaLang, CharacterCharCount) {
    Character testCharacter;
    ASSERT_EQUAL(2, testCharacter.charCount('p'));
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