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

