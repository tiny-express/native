/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
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