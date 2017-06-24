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

int codePointAt(Array<char> a, int index, int limit) {

}

int codePointAt(CharSequence seq, int index) {

}

int codePointBefore(Array<char> a, int index) {

}

int codePointBefore(Array<char> a, int index, int start) {

}

int codePointBefore(CharSequence seq, int index) {

}

static int codePointCount(Array<char> a, int offset, int count) {

}

static int codePointCount(CharSequence seq, int beginIndex, int endIndex) {

}

static int compare(char x, char y) {

}

int	compareTo(Character anotherCharacter) {

}

static int digit(char ch, int radix) {

}

static int digit(int codePoint, int radix) {

}

boolean	equals(Character target) {

}

static char	forDigit(int digit, int radix) {

}

static byte	getDirectionality(char ch) {

}

static byte	getDirectionality(int codePoint) {

}

static String getName(int codePoint) {

}

static int getNumericValue(char ch) {

}

static int getNumericValue(int codePoint) {

}

static int getType(char ch) {

}

static int getType(int codePoint) {

}

int	hashCode() {

}

static char	highSurrogate(int codePoint) {

}

static boolean isAlphabetic(int codePoint) {

}

static boolean isBmpCodePoint(int codePoint) {

}

static boolean isDefined(char ch) {

}

static boolean isDefined(int codePoint) {

}

static boolean isDigit(char ch) {

}

static boolean isDigit(int codePoint) {

}

static boolean isHighSurrogate(char ch) {

}

static boolean isIdentifierIgnorable(char ch) {

}

static boolean isIdentifierIgnorable(int codePoint) {

}

static boolean isIdeographic(int codePoint) {

}

static boolean isISOControl(char ch) {

}

static boolean isISOControl(int codePoint) {

}

static boolean isJavaIdentifierPart(char ch) {

}

static boolean isJavaIdentifierPart(int codePoint) {

}

static boolean isJavaIdentifierStart(char ch) {

}

static boolean isJavaIdentifierStart(int codePoint) {

}

static boolean isLetter(char ch) {

}

static boolean isLetter(int codePoint) {

}

static boolean isLetterOrDigit(char ch) {

}

static boolean isLetterOrDigit(int codePoint) {

}

static boolean isLowerCase(char ch) {

}

static boolean isLowerCase(int codePoint) {

}

static boolean isLowSurrogate(char ch) {

}

static boolean isMirrored(char ch) {

}

static boolean isMirrored(int codePoint) {

}

static boolean isSpaceChar(char ch) {

}

static boolean isSpaceChar(int codePoint) {

}

static boolean isSupplementaryCodePoint(int codePoint) {

}

static boolean isSurrogate(char ch) {

}

static boolean isSurrogatePair(char high, char low) {

}

static boolean isTitleCase(char ch) {

}

static boolean isTitleCase(int codePoint) {

}

static boolean isUnicodeIdentifierPart(char ch) {

}

static boolean isUnicodeIdentifierPart(int codePoint) {

}

static boolean isUnicodeIdentifierStart(char ch) {

}

static boolean isUnicodeIdentifierStart(int codePoint) {

}

static boolean isUpperCase(char ch) {

}

static boolean isUpperCase(int codePoint) {

}

static boolean isValidCodePoint(int codePoint) {

}

static boolean isWhitespace(char ch) {

}

static boolean isWhitespace(int codePoint) {

}

static char	lowSurrogate(int codePoint) {

}

static int offsetByCodePoints(Array<char> a, int start, int count, int index, int codePointOffset) {

}

static int offsetByCodePoints(CharSequence seq, int index, int codePointOffset) {

}

static char	reverseBytes(char ch) {

}

static Array<char> toChars(int codePoint) {

}

static int toChars(int codePoint, Array<char> dst, int dstIndex) {

}

static int toCodePoint(char high, char low) {

}

static char	toLowerCase(char ch) {

}

static int toLowerCase(int codePoint) {

}

String toString() {

}

static String toString(char c) {

}

static char	toTitleCase(char ch) {

}

static int toTitleCase(int codePoint) {

}

static char	toUpperCase(char ch) {

}

static int toUpperCase(int codePoint) {

}

static Character valueOf(char c) {

}