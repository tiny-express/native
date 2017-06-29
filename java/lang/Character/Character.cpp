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

/**
 * The minimum value of a Unicode high-surrogate code unit
 * in the UTF-16 encoding, constant {@code '\u005CuD800'}.
 */
static wchar_t MIN_HIGH_SURROGATE = '\u000D800';


/**
 * The maximum value of a Unicode high-surrogate code unit
 * in the UTF-16 encoding, constant {@code '\u005CuDBFF'}.
 */
static wchar_t MAX_HIGH_SURROGATE = '\u000DBFF';

/**
 * The minimum value of a Unicode low-surrogate code unit
 * in the UTF-16 encoding, constant {@code '\u005CuDC00'}.
 */
static wchar_t MIN_LOW_SURROGATE  = '\u000DC00';

/**
 * The maximum value of a Unicode low-surrogate code unit
 * in the UTF-16 encoding, constant {@code '\u005CuDFFF'}.
 */
static wchar_t MAX_LOW_SURROGATE  = '\u000DFFF';

/**
* The minimum value of a Unicode supplementary code point</a>, constant {@code U+10000}.
*/
static int MIN_SUPPLEMENTARY_CODE_POINT = 0x010000;

/**
 * Character initialization
 *
 * @param original
 */
Character::Character() {
    this->original = '\0';
}

/**
 * Character initialization
 *
 * @param original
 */
Character::Character(char original) {
    this ->original = original;
}

Character::~Character() {
}

/**
 * Returns the value of this {@code Character} object.
 * @return  the primitive {@code char} value represented by
 *          this object.
 */
char Character::charValue() {
    return this->original;
}

/**
 * Determines the number of {@code char} values needed to
 * represent the specified character (Unicode code point). If the
 * specified character is equal to or greater than 0x10000, then
 * the method returns 2. Otherwise, the method returns 1.
 *
 * @param   codePoint the character (Unicode code point) to be tested.
 * @return  2 if the character is a valid supplementary character; 1 otherwise.
 */
int Character::charCount(int codePoint) {
    // The minimum value of Unicode supplementary code point, constant {@code U+10000}.
    int MIN_SUPPLEMENTARY_CODE_POINT = 0x010000;
    if(codePoint >= MIN_SUPPLEMENTARY_CODE_POINT) {
        return 2;
    }
    return 1;
}

/**
 * Determines if the given {@code char} value is a
 * <a href="http://www.unicode.org/glossary/#high_surrogate_code_unit">
 * Unicode high-surrogate code unit</a>
 * (also known as <i>leading-surrogate code unit</i>).
 *
 * <p>Such values do not represent characters by themselves,
 * but are used in the representation of
 * <a href="#supplementary">supplementary characters</a>
 * in the UTF-16 encoding.
 *
 * @param  ch the {@code char} value to be tested.
 * @return {@code true} if the {@code char} value is between
 *         {@link #MIN_HIGH_SURROGATE} and
 *         {@link #MAX_HIGH_SURROGATE} inclusive;
 *         {@code false} otherwise.
 * @see    Character::isLowSurrogate(char)
 * @see    Character.UnicodeBlock#of(int)
 */

boolean Character::isHighSurrogate(wchar_t ch) {
    // Help VM constant-fold; MAX_HIGH_SURROGATE + 1 == MIN_LOW_SURROGATE
    return (ch >= MIN_HIGH_SURROGATE) && (ch < (MAX_HIGH_SURROGATE + 1));
}

/**
 * Determines if the given {@code char} value is a
 * <a href="http://www.unicode.org/glossary/#low_surrogate_code_unit">
 * Unicode low-surrogate code unit</a>
 * (also known as <i>trailing-surrogate code unit</i>).
 *
 * <p>Such values do not represent characters by themselves,
 * but are used in the representation of
 * <a href="#supplementary">supplementary characters</a>
 * in the UTF-16 encoding.
 *
 * @param  ch the {@code char} value to be tested.
 * @return {@code true} if the {@code char} value is between
 *         {@link #MIN_LOW_SURROGATE} and
 *         {@link #MAX_LOW_SURROGATE} inclusive;
 *         {@code false} otherwise.
 * @see    Character#isHighSurrogate(char)
 */

boolean Character::isLowSurrogate(wchar_t ch) {
    return ch >= MIN_LOW_SURROGATE && ch < (MAX_LOW_SURROGATE + 1);
}

/**
 * Converts the specified surrogate pair to its supplementary code
 * point value. This method does not validate the specified
 * surrogate pair. The caller must validate it using {@link
 * #isSurrogatePair(char, char) isSurrogatePair} if necessary.
 *
 * @param  high the high-surrogate code unit
 * @param  low the low-surrogate code unit
 * @return the supplementary code point composed from the
 *         specified surrogate pair.
 */

int Character::toCodePoint(wchar_t high, wchar_t low) {
    return ((high << 10) + low) + (MIN_SUPPLEMENTARY_CODE_POINT - (MIN_HIGH_SURROGATE << 10) - MIN_LOW_SURROGATE);
}

/**
 * Returns the code point at the given index of the
 * {@code CharSequence}. If the {@code char} value at
 * the given index in the {@code CharSequence} is in the
 * high-surrogate range, the following index is less than the
 * length of the {@code CharSequence}, and the
 * {@code char} value at the following index is in the
 * low-surrogate range, then the supplementary code point
 * corresponding to this surrogate pair is returned. Otherwise,
 * the {@code char} value at the given index is returned.
 *
 * @param seq a sequence of {@code char} values (Unicode code
 * units)
 * @param index the index to the {@code char} values (Unicode
 * code units) in {@code seq} to be converted
 * @return the Unicode code point at the given index
 * @exception NullPointerException if {@code seq} is null.
 * @exception IndexOutOfBoundsException if the value
 * {@code index} is negative or not less than
 * {@link CharSequence#length() seq.length()}.
 */

// TODO check leak error
//int Character::codePointAt(Array<char> seq, int index) {
//    char c1 = seq[index];
//    if (isHighSurrogate(c1) && ++index < seq.length) {
//        char c2 = seq[index];
//        if (isLowSurrogate(c2)) {
//            return toCodePoint(c1, c2);
//        }
//    }
//    return c1;
//}


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