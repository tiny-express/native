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
 * <a href="http://www.unicode.org/glossary/#high_surrogate_code_unit">
 * Unicode high-surrogate code unit</a>
 * in the UTF-16 encoding, constant {@code '\u005CuD800'}.
 * A high-surrogate is also known as a <i>leading-surrogate</i>.
 */
static wchar_t MIN_HIGH_SURROGATE = '\u000D800';

/**
 * The maximum value of a
 * <a href="http://www.unicode.org/glossary/#high_surrogate_code_unit">
 * Unicode high-surrogate code unit</a>
 * in the UTF-16 encoding, constant {@code '\u005CuDBFF'}.
 * A high-surrogate is also known as a <i>leading-surrogate</i>.
 */
static wchar_t MAX_HIGH_SURROGATE = '\u000DBFF';

/**
 * The minimum value of a
 * <a href="http://www.unicode.org/glossary/#low_surrogate_code_unit">
 * Unicode low-surrogate code unit</a>
 * in the UTF-16 encoding, constant {@code '\u005CuDC00'}.
 * A low-surrogate is also known as a <i>trailing-surrogate</i>.
 */
static wchar_t MIN_LOW_SURROGATE = '\u000DC00';

/**
 * The maximum value of a
 * <a href="http://www.unicode.org/glossary/#low_surrogate_code_unit">
 * Unicode low-surrogate code unit</a>
 * in the UTF-16 encoding, constant {@code '\u005CuDFFF'}.
 * A low-surrogate is also known as a <i>trailing-surrogate</i>.
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
 * <a href="http://www.unicode.org/glossary/#supplementary_code_point">
 * Unicode supplementary code point</a>, constant {@code U+10000}.
 */
static int MIN_SUPPLEMENTARY_CODE_POINT = 0x010000;

/**
 * The minimum value of a
 * <a href="http://www.unicode.org/glossary/#code_point">
 * Unicode code point</a>, constant {@code U+0000}.
 */
static int MIN_CODE_POINT = 0x000000;

/**
 * The maximum value of a
 * <a href="http://www.unicode.org/glossary/#code_point">
 * Unicode code point</a>, constant {@code U+10FFFF}.
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
 * Returns the value of this {@code Character} object.
 * @return  the primitive {@code char} value represented by
 *          this object.
 */
char Character::charValue() {
    return this->original;
}

/**
 * Returns the code point at the given index of the
 * {@code char} array. If the {@code char} value at
 * the given index in the {@code char} array is in the
 * high-surrogate range, the following index is less than the
 * length of the {@code char} array, and the
 * {@code char} value at the following index is in the
 * low-surrogate range, then the supplementary code point
 * corresponding to this surrogate pair is returned. Otherwise,
 * the {@code char} value at the given index is returned.
 *
 * @param a the {@code char} array
 * @param index the index to the {@code char} values (Unicode
 * code units) in the {@code char} array to be converted
 * @return the Unicode code point at the given index
 * @exception NullPointerException if {@code a} is null.
 * @exception IndexOutOfBoundsException if the value
 * {@code index} is negative or not less than
 * the length of the {@code char} array.
 */
int Character::codePointAt(Array<char> seq, int index) {

    if (index < 0 || index >= seq.length)
        return -1;
    char c1 = seq[index];
    if (isHighSurrogate(c1) && ++index < seq.length) {
        char c2 = seq[index];
        if (isLowSurrogate(c2)) {
            return toCodePoint(c1, c2);
        }
    }
    return c1;
}

/**
 * Returns the code point at the given index of the
 * {@code char} array. If the {@code char} value at
 * the given index in the {@code char} array is in the
 * high-surrogate range, the following index is less than the
 * length of the {@code char} array, and the
 * {@code char} value at the following index is in the
 * low-surrogate range, then the supplementary code point
 * corresponding to this surrogate pair is returned. Otherwise,
 * the {@code char} value at the given index is returned.
 *
 * @param a the {@code char} array
 * @param index the index to the {@code char} values (Unicode
 * code units) in the {@code char} array to be converted
 * @return the Unicode code point at the given index
 * @exception NullPointerException if {@code a} is null.
 * @exception IndexOutOfBoundsException if the value
 * {@code index} is negative or not less than
 * the length of the {@code char} array.
 */
int Character::codePointAt(char a[], int index) {
    int aLength = strlen(a);
    return codePointAtImpl(a, index, aLength);
}

/**
 * Returns the code point at the given index of the
 * {@code char} array, where only array elements with
 * {@code index} less than {@code limit} can be used. If
 * the {@code char} value at the given index in the
 * {@code char} array is in the high-surrogate range, the
 * following index is less than the {@code limit}, and the
 * {@code char} value at the following index is in the
 * low-surrogate range, then the supplementary code point
 * corresponding to this surrogate pair is returned. Otherwise,
 * the {@code char} value at the given index is returned.
 *
 * @param a the {@code char} array
 * @param index the index to the {@code char} values (Unicode
 * code units) in the {@code char} array to be converted
 * @param limit the index after the last array element that
 * can be used in the {@code char} array
 * @return the Unicode code point at the given index
 * @exception NullPointerException if {@code a} is null.
 * @exception IndexOutOfBoundsException if the {@code index}
 * argument is negative or not less than the {@code limit}
 * argument, or if the {@code limit} argument is negative or
 * greater than the length of the {@code char} array.
 */
int Character::codePointAt(char a[], int index, int limit) {
    int aLength = strlen(a);
    if (index >= limit || limit < 0 || limit > aLength) {
        return -1;
    }
    return codePointAtImpl(a, index, limit);
}

// throws ArrayIndexOutOfBoundsException if index out of bounds
int Character::codePointAtImpl(char a[], int index, int limit) {
    char c1 = a[index];
    if (isHighSurrogate(c1) && ++index < limit) {
        char c2 = a[index];
        if (isLowSurrogate(c2)) {
            return toCodePoint(c1, c2);
        }
    }
    return c1;
}

/**
 * Returns the code point preceding the given index of the
 * {@code CharSequence}. If the {@code char} value at
 * {@code (index - 1)} in the {@code CharSequence} is in
 * the low-surrogate range, {@code (index - 2)} is not
 * negative, and the {@code char} value at {@code (index - 2)}
 * in the {@code CharSequence} is in the
 * high-surrogate range, then the supplementary code point
 * corresponding to this surrogate pair is returned. Otherwise,
 * the {@code char} value at {@code (index - 1)} is
 * returned.
 *
 * @param seq the {@code CharSequence} instance
 * @param index the index following the code point that should be returned
 * @return the Unicode code point value before the given index.
 * @exception NullPointerException if {@code seq} is null.
 * @exception IndexOutOfBoundsException if the {@code index}
 * argument is less than 1 or greater than {@link
 * CharSequence#length() seq.length()}.
 */
int Character::codePointBefore(Array<char> seq, int index) {
    char c2 = seq[--index];
    if (isLowSurrogate(c2) && index > 0) {
        char c1 = seq[--index];
        if (isHighSurrogate(c1)) {
            return toCodePoint(c1, c2);
        }
    }
    return c2;
}

/**
   * Returns the code point preceding the given index of the
   * {@code char} array. If the {@code char} value at
   * {@code (index - 1)} in the {@code char} array is in
   * the low-surrogate range, {@code (index - 2)} is not
   * negative, and the {@code char} value at {@code (index - 2)}
   * in the {@code char} array is in the
   * high-surrogate range, then the supplementary code point
   * corresponding to this surrogate pair is returned. Otherwise,
   * the {@code char} value at {@code (index - 1)} is
   * returned.
   *
   * @param a the {@code char} array
   * @param index the index following the code point that should be returned
   * @return the Unicode code point value before the given index.
   * @exception NullPointerException if {@code a} is null.
   * @exception IndexOutOfBoundsException if the {@code index}
   * argument is less than 1 or greater than the length of the
   * {@code char} array
   */
int Character::codePointBefore(char a[], int index) {
    return codePointBeforeImpl(a, index, 0);
}

/**
 * Returns the code point preceding the given index of the
 * {@code char} array, where only array elements with
 * {@code index} greater than or equal to {@code start}
 * can be used. If the {@code char} value at {@code (index - 1)}
 * in the {@code char} array is in the
 * low-surrogate range, {@code (index - 2)} is not less than
 * {@code start}, and the {@code char} value at
 * {@code (index - 2)} in the {@code char} array is in
 * the high-surrogate range, then the supplementary code point
 * corresponding to this surrogate pair is returned. Otherwise,
 * the {@code char} value at {@code (index - 1)} is
 * returned.
 *
 * @param a the {@code char} array
 * @param index the index following the code point that should be returned
 * @param start the index of the first array element in the
 * {@code char} array
 * @return the Unicode code point value before the given index.
 * @exception NullPointerException if {@code a} is null.
 * @exception IndexOutOfBoundsException if the {@code index}
 * argument is not greater than the {@code start} argument or
 * is greater than the length of the {@code char} array, or
 * if the {@code start} argument is negative or not less than
 * the length of the {@code char} array.
 */
int Character::codePointBefore(char a[], int index, int start) {
    int aLength = strlen(a);
    if (index <= start || start < 0 || start >= aLength) {
        return -1;
    }
    return codePointBeforeImpl(a, index, start);
}

// throws ArrayIndexOutOfBoundsException if index-1 out of bounds
int Character::codePointBeforeImpl(char a[], int index, int start) {
    char c2 = a[--index];
    if (isLowSurrogate(c2) && index > start) {
        char c1 = a[--index];
        if (isHighSurrogate(c1)) {
            return toCodePoint(c1, c2);
        }
    }
    return c2;
}

/**
 * Returns the number of Unicode code points in the text range of
 * the specified char sequence. The text range begins at the
 * specified {@code beginIndex} and extends to the
 * {@code char} at index {@code endIndex - 1}. Thus the
 * length (in {@code char}s) of the text range is
 * {@code endIndex-beginIndex}. Unpaired surrogates within
 * the text range count as one code point each.
 *
 * @param seq the char sequence
 * @param beginIndex the index to the first {@code char} of
 * the text range.
 * @param endIndex the index after the last {@code char} of
 * the text range.
 * @return the number of Unicode code points in the specified text
 * range
 * @exception NullPointerException if {@code seq} is null.
 * @exception IndexOutOfBoundsException if the
 * {@code beginIndex} is negative, or {@code endIndex}
 * is larger than the length of the given sequence, or
 * {@code beginIndex} is larger than {@code endIndex}.
 */
int Character::codePointCount(Array<char> seq, int beginIndex,
                              int endIndex) {
    int length = seq.length;
    if (beginIndex < 0 || endIndex > length || beginIndex > endIndex) {
        return -1;
    }
    int n = endIndex - beginIndex;
    for (int i = beginIndex; i < endIndex;) {
        if (isHighSurrogate(seq[i++]) && i < endIndex
            && isLowSurrogate(seq[i])) {
            n--;
            i++;
        }
    }
    return n;
}

/**
 * Returns the number of Unicode code points in a subarray of the
 * {@code char} array argument. The {@code offset}
 * argument is the index of the first {@code char} of the
 * subarray and the {@code count} argument specifies the
 * length of the subarray in {@code char}s. Unpaired
 * surrogates within the subarray count as one code point each.
 *
 * @param a the {@code char} array
 * @param offset the index of the first {@code char} in the
 * given {@code char} array
 * @param count the length of the subarray in {@code char}s
 * @return the number of Unicode code points in the specified subarray
 * @exception NullPointerException if {@code a} is null.
 * @exception IndexOutOfBoundsException if {@code offset} or
 * {@code count} is negative, or if {@code offset +
 * count} is larger than the length of the given array.
 */
int Character::codePointCount(char a[], int offset, int count) {
    int aLength = strlen(a);
    if (count > aLength - offset || offset < 0 || count < 0) {
        return -1;
    }
    return codePointCountImpl(a, offset, count);
}

int Character::codePointCountImpl(char a[], int offset, int count) {
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

/**
 * Compares two {@code char} values numerically.
 * The value returned is identical to what would be returned by:
 * <pre>
 *    Character.valueOf(x).compareTo(Character.valueOf(y))
 * </pre>
 *
 * @param  x the first {@code char} to compare
 * @param  y the second {@code char} to compare
 * @return the value {@code 0} if {@code x == y};
 *         a value less than {@code 0} if {@code x < y}; and
 *         a value greater than {@code 0} if {@code x > y}
 */
int Character::compare(char x, char y) {
    return x - y;
}

/**
 * Compares two {@code Character} objects numerically.
 *
 * @param   anotherCharacter   the {@code Character} to be compared.

 * @return  the value {@code 0} if the argument {@code Character}
 *          is equal to this {@code Character}; a value less than
 *          {@code 0} if this {@code Character} is numerically less
 *          than the {@code Character} argument; and a value greater than
 *          {@code 0} if this {@code Character} is numerically greater
 *          than the {@code Character} argument (unsigned comparison).
 *          Note that this is strictly a numerical comparison; it is not
 *          locale-dependent.
 */
int Character::compareTo(Character anotherCharacter) {
    return compare(this->charValue(), anotherCharacter.charValue());
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
 * @see    Character#isLowSurrogate(char)
 * @see    Character.UnicodeBlock#of(int)
 */
boolean Character::isHighSurrogate(wchar_t ch) {
    // Help VM constant-fold; MAX_HIGH_SURROGATE + 1 == MIN_LOW_SURROGATE
    return ch >= MIN_HIGH_SURROGATE && ch < (MAX_HIGH_SURROGATE + 1);
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
    return ((high << 10) + low) + (MIN_SUPPLEMENTARY_CODE_POINT
                                   - (MIN_HIGH_SURROGATE << 10)
                                   - MIN_LOW_SURROGATE);
}

/**
 * Returns the numeric value of the specified character (Unicode
 * code point) in the specified radix.
 *
 * <p>If the radix is not in the range {@code MIN_RADIX} &le;
 * {@code radix} &le; {@code MAX_RADIX} or if the
 * character is not a valid digit in the specified
 * radix, {@code -1} is returned. A character is a valid digit
 * if at least one of the following is true:
 * <ul>
 * <li>The method {@link #isDigit(int) isDigit(codePoint)} is {@code true} of the character
 *     and the Unicode decimal digit value of the character (or its
 *     single-character decomposition) is less than the specified radix.
 *     In this case the decimal digit value is returned.
 * <li>The character is one of the uppercase Latin letters
 *     {@code 'A'} through {@code 'Z'} and its code is less than
 *     {@code radix + 'A' - 10}.
 *     In this case, {@code codePoint - 'A' + 10}
 *     is returned.
 * <li>The character is one of the lowercase Latin letters
 *     {@code 'a'} through {@code 'z'} and its code is less than
 *     {@code radix + 'a' - 10}.
 *     In this case, {@code codePoint - 'a' + 10}
 *     is returned.
 * <li>The character is one of the fullwidth uppercase Latin letters A
 *     ({@code '\u005CuFF21'}) through Z ({@code '\u005CuFF3A'})
 *     and its code is less than
 *     {@code radix + '\u005CuFF21' - 10}.
 *     In this case,
 *     {@code codePoint - '\u005CuFF21' + 10}
 *     is returned.
 * <li>The character is one of the fullwidth lowercase Latin letters a
 *     ({@code '\u005CuFF41'}) through z ({@code '\u005CuFF5A'})
 *     and its code is less than
 *     {@code radix + '\u005CuFF41'- 10}.
 *     In this case,
 *     {@code codePoint - '\u005CuFF41' + 10}
 *     is returned.
 * </ul>
 *
 * @param   codePoint the character (Unicode code point) to be converted.
 * @param   radix   the radix.
 * @return  the numeric value represented by the character in the
 *          specified radix.
 * @see     Character#forDigit(int, int)
 * @see     Character#isDigit(int)
 */
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
