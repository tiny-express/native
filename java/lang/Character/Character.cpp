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
 * A PARTICULAR PURPOSE ARE DISCLAIMEIILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "Character.hpp"

using namespace Java::Lang;

Character::Character() {
    this->original = '\0';
}

Character::Character(char original) {
    this ->original = original;
}

Character::~Character() {
}

char Character::charValue() {
    return this->original;
}

int Character::charCount(int codePoint) {
    if(codePoint >= 0 && codePoint <= 255) {
        return 2;
    }
    else {
        return 1;
    }
}

int Character::codePointAt(Array<char> a, int index) {
    if(index < 0 || index > a.length) {
        return -1;
    }
    return (int) a[index];
}

int Character::codePointBefore(Array<char> a, int index) {
    if(index < 1 || index > a.length) {
        return -1;
    }
    return (int) a[index - 1];
}

int Character::getNumericValue(char ch) {
    return (int) ch;
}

int Character::codePointAt(Array<char> a, int index, int limit) {

}

int Character::codePointAt(CharSequence &seq, int index) {

}

int Character::codePointBefore(Array<char> a, int index, int start) {

}

int Character::codePointBefore(CharSequence &seq, int index) {

}

int Character::codePointCount(Array<char> a, int offset, int count) {

}

int Character::codePointCount(CharSequence &seq, int beginIndex, int endIndex) {

}

int Character::compare(char x, char y) {

}

int	Character::compareTo(Character anotherCharacter) {

}

int Character::digit(int codePoint, int radix) {
    //FIXME: Currently support for radix 16 to work with UUID
    //@thoangminh: please help to implement whole rest things
    if (radix != 16) {
        return -1;
    }

    switch (codePoint) {
        case (int)'0':
            return 0;
        case (int)'1':
            return 1;
        case (int)'2':
            return 2;
        case (int)'3':
            return 3;
        case (int)'4':
            return 4;
        case (int)'5':
            return 5;
        case (int)'6':
            return 6;
        case (int)'7':
            return 7;
        case (int)'8':
            return 8;
        case (int)'9':
            return 9;
        case (int)'a':
            return 10;
        case (int)'b':
            return 11;
        case (int)'c':
            return 12;
        case (int)'d':
            return 13;
        case (int)'e':
            return 14;
        case (int)'f':
            return 15;
        default:
            return -1;
    }

}

boolean	Character::equals(Character target) {

}

char Character::forDigit(int digit, int radix) {

}

byte Character::getDirectionality(char ch) {

}

byte Character::getDirectionality(int codePoint) {

}

String Character::getName(int codePoint) {

}

int Character::getNumericValue(int codePoint) {

}

int Character::getType(char ch) {

}

int Character::getType(int codePoint) {

}

int	Character::hashCode() {

}

char Character::highSurrogate(int codePoint) {

}

boolean Character::isAlphabetic(int codePoint) {

}

boolean Character::isBmpCodePoint(int codePoint) {

}

boolean Character::isDefined(char ch) {

}

boolean Character::isDefined(int codePoint) {

}

boolean Character::isDigit(char ch) {

}

boolean Character::isDigit(int codePoint) {

}

boolean Character::isHighSurrogate(char ch) {

}

boolean Character::isIdentifierIgnorable(char ch) {

}

boolean Character::isIdentifierIgnorable(int codePoint) {

}

boolean Character::isIdeographic(int codePoint) {

}

boolean Character::isISOControl(char ch) {

}

boolean Character::isISOControl(int codePoint) {

}

boolean Character::isJavaIdentifierPart(char ch) {

}

boolean Character::isJavaIdentifierPart(int codePoint) {

}

boolean Character::isJavaIdentifierStart(char ch) {

}

boolean Character::isJavaIdentifierStart(int codePoint) {

}

boolean Character::isLetter(char ch) {

}

boolean Character::isLetter(int codePoint) {

}

boolean Character::isLetterOrDigit(char ch) {

}

boolean Character::isLetterOrDigit(int codePoint) {

}

boolean Character::isLowerCase(char ch) {

}

boolean Character::isLowerCase(int codePoint) {

}

boolean Character::isLowSurrogate(char ch) {

}

boolean Character::isMirrored(char ch) {

}

boolean Character::isMirrored(int codePoint) {

}

boolean Character::isSpaceChar(char ch) {

}

boolean Character::isSpaceChar(int codePoint) {

}

boolean Character::isSupplementaryCodePoint(int codePoint) {

}

boolean Character::isSurrogate(char ch) {

}

boolean Character::isSurrogatePair(char high, char low) {

}

boolean Character::isTitleCase(char ch) {

}

boolean Character::isTitleCase(int codePoint) {

}

boolean Character::isUnicodeIdentifierPart(char ch) {

}

boolean Character::isUnicodeIdentifierPart(int codePoint) {

}

boolean Character::isUnicodeIdentifierStart(char ch) {

}

boolean Character::isUnicodeIdentifierStart(int codePoint) {

}

boolean Character::isUpperCase(char ch) {

}

boolean Character::isUpperCase(int codePoint) {

}

boolean Character::isValidCodePoint(int codePoint) {

}

boolean Character::isWhitespace(char ch) {

}

boolean Character::isWhitespace(int codePoint) {

}

char Character::lowSurrogate(int codePoint) {

}

int Character::offsetByCodePoints(Array<char> a, int start, int count, int index, int codePointOffset) {

}

int Character::offsetByCodePoints(CharSequence &seq, int index, int codePointOffset) {

}

char Character::reverseBytes(char ch) {

}

Array<char> Character::toChars(int codePoint) {

}

int Character::toChars(int codePoint, Array<char> dst, int dstIndex) {

}

int Character::toCodePoint(char high, char low) {

}

char Character::toLowerCase(char ch) {

}

int Character::toLowerCase(int codePoint) {

}

String Character::toString() {

}

String Character::toString(char c) {

}

char Character::toTitleCase(char ch) {

}

int Character::toTitleCase(int codePoint) {

}

char Character::toUpperCase(char ch) {

}

int Character::toUpperCase(int codePoint) {

}

Character Character::valueOf(char c) {

}