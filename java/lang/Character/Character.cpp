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
#include <stdexcept>

using namespace Java::Lang;

/**
 * The minimum radix available for conversion to and from strings.
 * The constant value of this field is the smallest value permitted
 * for the radix argument in radix-conversion methods such as the
 * {@code digit} method, the {@code forDigit} method, and the
 * {@code toString} method of class {@code Integer}.
 *
 * @see     Character#digit(char, int)
 * @see     Character#forDigit(int, int)
 * @see     Integer#toString(int, int)
 * @see     Integer#valueOf(String)
 */
static int MIN_RADIX = 2;

/**
 * The maximum radix available for conversion to and from strings.
 * The constant value of this field is the largest value permitted
 * for the radix argument in radix-conversion methods such as the
 * {@code digit} method, the {@code forDigit} method, and the
 * {@code toString} method of class {@code Integer}.
 *
 * @see     Character#digit(char, int)
 * @see     Character#forDigit(int, int)
 * @see     Integer#toString(int, int)
 * @see     Integer#valueOf(String)
 */
static int MAX_RADIX = 36;

/**
 * The constant value of this field is the smallest value of type
 * {@code char}, {@code '\u005Cu0000'}.
 */
static wchar_t MIN_VALUE = '\u0000000';

/**
 * The constant value of this field is the largest value of type
 * {@code wchar_t}, {@code '\u005CuFFFF'}.
 */
static wchar_t MAX_VALUE = '\u000FFFF';

/**
 * General category "Cn" in the Unicode specification.
 */
static byte UNASSIGNED = 0;

/**
 * General category "Lu" in the Unicode specification.
 */
static byte UPPERCASE_LETTER = 1;

/**
 * General category "Ll" in the Unicode specification.
 */
static byte LOWERCASE_LETTER = 2;

/**
 * General category "Lt" in the Unicode specification.
 */
static byte TITLECASE_LETTER = 3;

/**
 * General category "Lm" in the Unicode specification.
 */
static byte MODIFIER_LETTER = 4;

/**
 * General category "Lo" in the Unicode specification.
 */
static byte OTHER_LETTER = 5;

/**
 * General category "Mn" in the Unicode specification.
 */
static byte NON_SPACING_MARK = 6;

/**
 * General category "Me" in the Unicode specification.
 */
static byte ENCLOSING_MARK = 7;

/**
 * General category "Mc" in the Unicode specification.
 */
static byte COMBINING_SPACING_MARK = 8;

/**
 * General category "Nd" in the Unicode specification.
 */
static byte DECIMAL_DIGIT_NUMBER = 9;

/**
 * General category "Nl" in the Unicode specification.
 */
static byte LETTER_NUMBER = 10;

/**
 * General category "No" in the Unicode specification.
 */
static byte OTHER_NUMBER = 11;

/**
 * General category "Zs" in the Unicode specification.
 */
static byte SPACE_SEPARATOR = 12;

/**
 * General category "Zl" in the Unicode specification.
 */
static byte LINE_SEPARATOR = 13;

/**
 * General category "Zp" in the Unicode specification.
 */
static byte PARAGRAPH_SEPARATOR = 14;

/**
 * General category "Cc" in the Unicode specification.
 */
static byte CONTROL = 15;

/**
 * General category "Cf" in the Unicode specification.
 */
static byte FORMAT = 16;

/**
 * General category "Co" in the Unicode specification.
 */
static byte PRIVATE_USE = 18;

/**
 * General category "Cs" in the Unicode specification.
 */
static byte SURROGATE = 19;

/**
 * General category "Pd" in the Unicode specification.
 */
static byte DASH_PUNCTUATION = 20;

/**
 * General category "Ps" in the Unicode specification.
 */
static byte START_PUNCTUATION = 21;

/**
 * General category "Pe" in the Unicode specification.
 */
static byte END_PUNCTUATION = 22;

/**
 * General category "Pc" in the Unicode specification.
 */
static byte CONNECTOR_PUNCTUATION = 23;

/**
 * General category "Po" in the Unicode specification.
 */
static byte OTHER_PUNCTUATION = 24;

/**
 * General category "Sm" in the Unicode specification.
 */
static byte MATH_SYMBOL = 25;

/**
 * General category "Sc" in the Unicode specification.
 */
static byte CURRENCY_SYMBOL = 26;

/**
 * General category "Sk" in the Unicode specification.
 */
static byte MODIFIER_SYMBOL = 27;

/**
 * General category "So" in the Unicode specification.
 */
static byte OTHER_SYMBOL = 28;

/**
 * General category "Pi" in the Unicode specification.
 */
static byte INITIAL_QUOTE_PUNCTUATION = 29;

/**
 * General category "Pf" in the Unicode specification.
 */
static byte FINAL_QUOTE_PUNCTUATION = 30;

/**
 * Error flag. Use int (code point) to avoid confusion with U+FFFF.
 */
static int ERROR = 0xFFFFFFFF;

/**
 * Undefined bidirectional character type. Undefined {@code char}
 * values have undefined directionality in the Unicode specification.
 */
static byte DIRECTIONALITY_UNDEFINED = -1;

/**
 * Strong bidirectional character type "L" in the Unicode specification.
 */
static byte DIRECTIONALITY_LEFT_TO_RIGHT = 0;

/**
 * Strong bidirectional character type "R" in the Unicode specification.
 */
static byte DIRECTIONALITY_RIGHT_TO_LEFT = 1;

/**
 * Strong bidirectional character type "AL" in the Unicode specification.
 */
static byte DIRECTIONALITY_RIGHT_TO_LEFT_ARABIC = 2;

/**
 * Weak bidirectional character type "EN" in the Unicode specification.
 */
static byte DIRECTIONALITY_EUROPEAN_NUMBER = 3;

/**
 * Weak bidirectional character type "ES" in the Unicode specification.
 */
static byte DIRECTIONALITY_EUROPEAN_NUMBER_SEPARATOR = 4;

/**
 * Weak bidirectional character type "ET" in the Unicode specification.
 */
static byte DIRECTIONALITY_EUROPEAN_NUMBER_TERMINATOR = 5;

/**
 * Weak bidirectional character type "AN" in the Unicode specification.
 */
static byte DIRECTIONALITY_ARABIC_NUMBER = 6;

/**
 * Weak bidirectional character type "CS" in the Unicode specification.
 */
static byte DIRECTIONALITY_COMMON_NUMBER_SEPARATOR = 7;

/**
 * Weak bidirectional character type "NSM" in the Unicode specification.
 */
static byte DIRECTIONALITY_NONSPACING_MARK = 8;

/**
 * Weak bidirectional character type "BN" in the Unicode specification.
 */
static byte DIRECTIONALITY_BOUNDARY_NEUTRAL = 9;

/**
 * Neutral bidirectional character type "B" in the Unicode specification.
 */
static byte DIRECTIONALITY_PARAGRAPH_SEPARATOR = 10;

/**
 * Neutral bidirectional character type "S" in the Unicode specification.
 */
static byte DIRECTIONALITY_SEGMENT_SEPARATOR = 11;

/**
 * Neutral bidirectional character type "WS" in the Unicode specification.
 */
static byte DIRECTIONALITY_WHITESPACE = 12;

/**
 * Neutral bidirectional character type "ON" in the Unicode specification.
 */
static byte DIRECTIONALITY_OTHER_NEUTRALS = 13;

/**
 * Strong bidirectional character type "LRE" in the Unicode specification.
 */
static byte DIRECTIONALITY_LEFT_TO_RIGHT_EMBEDDING = 14;

/**
 * Strong bidirectional character type "LRO" in the Unicode specification.
 */
static byte DIRECTIONALITY_LEFT_TO_RIGHT_OVERRIDE = 15;

/**
 * Strong bidirectional character type "RLE" in the Unicode specification.
 */
static byte DIRECTIONALITY_RIGHT_TO_LEFT_EMBEDDING = 16;

/**
 * Strong bidirectional character type "RLO" in the Unicode specification.
*/
static byte DIRECTIONALITY_RIGHT_TO_LEFT_OVERRIDE = 17;

/**
 * Weak bidirectional character type "PDF" in the Unicode specification.
 */
static byte DIRECTIONALITY_POP_DIRECTIONAL_FORMAT = 18;

/**
 * The minimum value of a
 * "http://www.unicode.org/glossary/#high_surrogate_code_unit"
 * Unicode high-surrogate code unit
 * in the UTF-16 encoding, constant {@code '\u005CuD800'}.
 * A high-surrogate is also known as a leading-surrogate.
 */
static wchar_t MIN_HIGH_SURROGATE = '\u000D800';

/**
 * The maximum value of a
 * "http://www.unicode.org/glossary/#high_surrogate_code_unit"
 * Unicode high-surrogate code unit
 * in the UTF-16 encoding, constant {@code '\u005CuDBFF'}.
 * A high-surrogate is also known as a leading-surrogate.
 */
static wchar_t MAX_HIGH_SURROGATE = '\u000DBFF';

/**
 * The minimum value of a
 * "http://www.unicode.org/glossary/#low_surrogate_code_unit"
 * Unicode low-surrogate code unit
 * in the UTF-16 encoding, constant {@code '\u005CuDC00'}.
 * A low-surrogate is also known as a trailing-surrogate.
 */
static wchar_t MIN_LOW_SURROGATE = '\u000DC00';

/**
 * The maximum value of a
 * "http://www.unicode.org/glossary/#low_surrogate_code_unit
 * Unicode low-surrogate code unit
 * in the UTF-16 encoding, constant {@code '\u005CuDFFF'}.
 * A low-surrogate is also known as a trailing-surrogate.
 */
static wchar_t MAX_LOW_SURROGATE = '\u000DFFF';

/**
 * The minimum value of a Unicode surrogate code unit in the
 * UTF-16 encoding, constant {@code '\u005CuD800'}.
 */
static wchar_t MIN_SURROGATE = MIN_HIGH_SURROGATE;

/**
 * The maximum value of a Unicode surrogate code unit in the
 * UTF-16 encoding, constant {@code '\u005CuDFFF'}.
 */
static wchar_t MAX_SURROGATE = MAX_LOW_SURROGATE;

/**
 * The minimum value of a
 * "http://www.unicode.org/glossary/#supplementary_code_point
 * Unicode supplementary code point, constant {@code U+10000}.
 */
static int MIN_SUPPLEMENTARY_CODE_POINT = 0x010000;

/**
 * The minimum value of a
 * "http://www.unicode.org/glossary/#code_point
 * Unicode code point, constant {@code U+0000}.
 */
static int MIN_CODE_POINT = 0x000000;

/**
 * The maximum value of a
 * "http://www.unicode.org/glossary/#code_point
 * Unicode code point, constant {@code U+10FFFF}.
 */
static int MAX_CODE_POINT = 0X10FFFF;


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

int Character::charCount(int codePoint) {
    if(codePoint >= MIN_SUPPLEMENTARY_CODE_POINT) {
        return 2;
    }
    return 1;
}

char Character::charValue() {
    return this->original;
}

int Character::codePointAt(Array<char> a, int index) {
    return codePointAtImpl(a, index, a.length);
}

int Character::codePointAt(Array<char> a, int index, int limit) {
    if (index >= limit || limit < 0 || limit > a.length) {
        return -1;
    }
    return codePointAtImpl(a, index, limit);
}

// throws ArrayIndexOutOfBoundsException if index out of bounds
int Character::codePointAtImpl(Array<char> a, int index, int limit) {
    char c1 = a[index];
    if (isHighSurrogate(c1) && ++index < limit) {
        char c2 = a[index];
        if (isLowSurrogate(c2)) {
            return toCodePoint(c1, c2);
        }
    }
    return c1;
}

int Character::codePointBefore(Array<char> a, int index) {
    return codePointBeforeImpl(a, index, 0);
}

int Character::codePointBefore(Array<char> a, int index, int start) {
    if (index <= start || start < 0 || start >= a.length) {
        return -1;
    }
    return codePointBeforeImpl(a, index, start);
}

// throws ArrayIndexOutOfBoundsException if index-1 out of bounds
int Character::codePointBeforeImpl(Array<char> a, int index, int start) {
    char c2 = a[--index];
    if (isLowSurrogate(c2) && index > start) {
        char c1 = a[--index];
        if (isHighSurrogate(c1)) {
            return toCodePoint(c1, c2);
        }
    }
    return c2;
}

int Character::codePointCount(Array<char> a, int offset, int count) {
    if (count > a.length - offset || offset < 0 || count < 0) {
        return -1;
    }
    return codePointCountImpl(a, offset, count);
}

int Character::codePointCountImpl(Array<char> a, int offset, int count) {
    int endIndex = offset + count;
    int n = count;
    for (int i = offset; i < endIndex;) {
        if (isHighSurrogate(a[i++]) && i < endIndex
            && isLowSurrogate(a[i])) {
            n--;
            i++;
        }
    }
    return n;
}

int Character::compare(char x, char y) {
    return x - y;
}

int Character::compareTo(Character anotherCharacter) {
    return compare(this->charValue(), anotherCharacter.charValue());
}

boolean Character::isHighSurrogate(wchar_t ch) {
    // Help VM constant-fold; MAX_HIGH_SURROGATE + 1 == MIN_LOW_SURROGATE
    return ch >= MIN_HIGH_SURROGATE && ch < (MAX_HIGH_SURROGATE + 1);
}

boolean Character::isLowSurrogate(wchar_t ch) {
    return ch >= MIN_LOW_SURROGATE && ch < (MAX_LOW_SURROGATE + 1);
}

boolean Character::isSurrogate(wchar_t ch) {
    return ch >= MIN_SURROGATE && ch < (MAX_SURROGATE + 1);
}

int Character::toCodePoint(wchar_t high, wchar_t low) {
    return ((high << 10) + low) + (MIN_SUPPLEMENTARY_CODE_POINT
                                   - (MIN_HIGH_SURROGATE << 10)
                                   - MIN_LOW_SURROGATE);
}

int Character::digit(int codePoint, int radix) {
    if (radix == 10) {
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
            default:
                return -1;
        }
    }
    if (radix == 16) {
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
}
