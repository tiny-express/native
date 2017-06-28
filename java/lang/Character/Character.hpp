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
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef NATIVE_JAVA_LANG_CHARACTER_HPP
#define NATIVE_JAVA_LANG_CHARACTER_HPP

#include "../Number/Number.hpp"

namespace Java {
	namespace Lang {
		class Character : public Object {
		private:
			char original;
		public:
            Character();
			Character(char original);
			~Character();
		public:
			/**
			 * Determines the number of char values needed to represent the specified character (Unicode code point).
			 * @param codePoint
			 * @return int
			 */
			static int charCount(int codePoint);

			/**
			 * Returns the value of this Character object.
			 * @return char
			 */
			char charValue();

			/**
			 * Returns the code point at the given index of the char array.
			 * @param index
			 * @return int
			 */
			static int codePointAt(Array<char> a, int index);

			/**
			 * Returns the code point at the given index of the char array,
			 * where only array elements with index less than limit can be used.
			 * @param index
			 * @param limit
			 * @return int
			 */
			static int codePointAt(Array<char> a, int index, int limit);

			/**
			 * Returns the code point at the given index of the CharSequence.
			 * @param seq
			 * @param index
			 * @return int
			 */
			static int codePointAt(CharSequence &seq, int index);

			/**
			 * Returns the code point preceding the given index of the char array.
			 * @param index
			 * @return int
			 */
			static int codePointBefore(Array<char> a, int index);

			/**
			 * Returns the code point preceding the given index of the char array,
			 * where only array elements with index greater than or equal to start can be used.
			 * @param index
			 * @param start
			 * @return int
			 */
			static int codePointBefore(Array<char> a, int index, int start);

			/**
			 * Returns the code point preceding the given index of the CharSequence.
			 * @param seq
			 * @param index
			 * @return int
			 */
			static int codePointBefore(CharSequence &seq, int index);

			/**
			 * Returns the number of Unicode code points in a subarray of the char array argument.
			 * @param offset
			 * @param count
			 * @return int
			 */
			static int codePointCount(Array<char> a, int offset, int count);

			/**
			 * Returns the number of Unicode code points in the text range of the specified char sequence.
			 * @param seq
			 * @param beginIndex
			 * @param endIndex
			 * @return int
			 */
			static int codePointCount(CharSequence &seq, int beginIndex, int endIndex);

			/**
			 * Compares two char values numerically.
			 * @param x
			 * @param y
			 * @return int
			 */
			static int compare(char x, char y);

			/**
			 * Compares two Character objects numerically.
			 * @param anotherCharacter
			 * @return int
			 */
			int	compareTo(Character anotherCharacter);

			/**
			 * Returns the numeric value of the specified character (Unicode code point) in the specified radix.
			 * @param codePoint
			 * @param radix
			 * @return int
			 */
			static int digit(int codePoint, int radix);

			/**
			 * Compares this object against the specified object.
			 * @param target
			 * @return boolean
			 */
			boolean	equals(Character target);

			/**
			 * Determines the character representation for a specific digit in the specified radix.
			 * @param digit
			 * @param radix
			 * @return char
			 */
			static char	forDigit(int digit, int radix);

			/**
			 * Returns the Unicode directionality property for the given character.
			 * @param ch
			 * @return byte
			 */
			static byte	getDirectionality(char ch);

			/**
			 * Returns the Unicode directionality property for the given character (Unicode code point).
			 * @param codePoint
			 * @return byte
			 */
			static byte	getDirectionality(int codePoint);

			/**
			 * Returns the Unicode name of the specified character codePoint, or null if the code point is unassigned.
			 * @param codePoint
			 * @return String
			 */
			static String getName(int codePoint);

			/**
			 * Returns the int value that the specified Unicode character represents.
			 * @param ch
			 * @return int
			 */
			static int getNumericValue(char ch);

			/**
			 * Returns the int value that the specified character (Unicode code point) represents.
			 * @param codePoint
			 * @return int
			 */
			static int getNumericValue(int codePoint);

			/**
			 * Returns a value indicating a character's general category.
			 * @param ch
			 * @return int
			 */
			static int getType(char ch);

			/**
			 * Returns a value indicating a character's general category.
			 * @param codePoint
			 * @return int
			 */
			static int getType(int codePoint);

			/**
			 * Returns a hash code for this Character; equal to the result of invoking charValue().
			 * @return int
			 */
			int	hashCode();

			/**
			 * Returns the leading surrogate (a high surrogate code unit) of the surrogate pair
			 * representing the specified supplementary character (Unicode code point) in the UTF-16 encoding.
			 * @param codePoint
			 * @return char
			 */
			static char	highSurrogate(int codePoint);

			/**
			 * Determines if the specified character (Unicode code point) is an alphabet.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isAlphabetic(int codePoint);

			/**
			 * Determines whether the specified character (Unicode code point) is in the Basic Multilingual Plane (BMP).
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isBmpCodePoint(int codePoint);

			/**
			 * Determines if a character is defined in Unicode.
			 * @param ch
			 * @return boolean
			 */
			static boolean isDefined(char ch);

			/**
			 * Determines if a character (Unicode code point) is defined in Unicode.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isDefined(int codePoint);

			/**
			 * Determines if the specified character is a digit.
			 * @param ch
			 * @return boolean
			 */
			static boolean isDigit(char ch);

			/**
			 * Determines if the specified character (Unicode code point) is a digit.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isDigit(int codePoint);

			/**
			 * Determines if the given char value is a Unicode high-surrogate code unit (also known as leading-surrogate code unit).
			 * @param ch
			 * @return boolean
			 */
			static boolean isHighSurrogate(char ch);

			/**
			 * Determines if the specified character should be regarded as an ignorable character in a Java identifier or a Unicode identifier.
			 * @param ch
			 * @return boolean
			 */
			static boolean isIdentifierIgnorable(char ch);

			/**
			 * Determines if the specified character (Unicode code point) should be regarded as an ignorable character in a Java identifier or a Unicode identifier.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isIdentifierIgnorable(int codePoint);

			/**
			 * Determines if the specified character (Unicode code point) is a CJKV
			 * (Chinese, Japanese, Korean and Vietnamese) ideograph, as defined by the Unicode Standard.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isIdeographic(int codePoint);

			/**
			 * Determines if the specified character is an ISO control character.
			 * @param ch
			 * @return boolean
			 */
			static boolean isISOControl(char ch);

			/**
			 * Determines if the referenced character (Unicode code point) is an ISO control character.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isISOControl(int codePoint);

			/**
			 * Determines if the specified character may be part of a Java identifier as other than the first character.
			 * @param ch
			 * @return boolean
			 */
			static boolean isJavaIdentifierPart(char ch);

			/**
			 * Determines if the character (Unicode code point) may be part of a Java identifier as other than the first character.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isJavaIdentifierPart(int codePoint);

			/**
			 * Determines if the specified character is permissible as the first character in a Java identifier.
			 * @param ch
			 * @return boolean
			 */
			static boolean isJavaIdentifierStart(char ch);

			/**
			 * Determines if the character (Unicode code point) is permissible as the first character in a Java identifier.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isJavaIdentifierStart(int codePoint);

			/**
			 * Determines if the specified character is a letter.
			 * @param ch
			 * @return boolean
			 */
			static boolean isLetter(char ch);

			/**
			 * Determines if the specified character (Unicode code point) is a letter.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isLetter(int codePoint);

			/**
			 * Determines if the specified character is a letter or digit.
			 * @param ch
			 * @return boolean
			 */
			static boolean isLetterOrDigit(char ch);

			/**
			 * Determines if the specified character (Unicode code point) is a letter or digit.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isLetterOrDigit(int codePoint);

			/**
			 * Determines if the specified character is a lowercase character.
			 * @param ch
			 * @return boolean
			 */
			static boolean isLowerCase(char ch);

			/**
			 * Determines if the specified character (Unicode code point) is a lowercase character.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isLowerCase(int codePoint);

			/**
			 * Determines if the given char value is a Unicode low-surrogate code unit (also known as trailing-surrogate code unit).
			 * @param ch
			 * @return boolean
			 */
			static boolean isLowSurrogate(char ch);

			/**
			 * Determines whether the character is mirrored according to the Unicode specification.
			 * @param ch
			 * @return boolean
			 */
			static boolean isMirrored(char ch);

			/**
			 * Determines whether the specified character (Unicode code point) is mirrored according to the Unicode specification.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isMirrored(int codePoint);

			/**
			 * Determines if the specified character is a Unicode space character.
			 * @param ch
			 * @return boolean
			 */
			static boolean isSpaceChar(char ch);

			/**
			 * Determines if the specified character (Unicode code point) is a Unicode space character.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isSpaceChar(int codePoint);

			/**
			 * Determines whether the specified character (Unicode code point) is in the supplementary character range.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isSupplementaryCodePoint(int codePoint);

			/**
			 * Determines if the given char value is a Unicode surrogate code unit.
			 * @param ch
			 * @return boolean
			 */
			static boolean isSurrogate(char ch);

			/**
			 * Determines whether the specified pair of char values is a valid Unicode surrogate pair.
			 * @param high
			 * @param low
			 * @return boolean
			 */
			static boolean isSurrogatePair(char high, char low);

			/**
			 * Determines if the specified character is a titlecase character.
			 * @param ch
			 * @return boolean
			 */
			static boolean isTitleCase(char ch);

			/**
			 * Determines if the specified character (Unicode code point) is a titlecase character.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isTitleCase(int codePoint);

			/**
			 * Determines if the specified character may be part of a Unicode identifier as other than the first character.
			 * @param ch
			 * @return boolean
			 */
			static boolean isUnicodeIdentifierPart(char ch);

			/**
			 * Determines if the specified character (Unicode code point) may be part of a Unicode identifier as other than the first character.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isUnicodeIdentifierPart(int codePoint);

			/**
			 * Determines if the specified character is permissible as the first character in a Unicode identifier.
			 * @param ch
			 * @return boolean
			 */
			static boolean isUnicodeIdentifierStart(char ch);

			/**
			 * Determines if the specified character (Unicode code point) is permissible as the first character in a Unicode identifier.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isUnicodeIdentifierStart(int codePoint);

			/**
			 * Determines if the specified character is an uppercase character.
			 * @param ch
			 * @return boolean
			 */
			static boolean isUpperCase(char ch);

			/**
			 * Determines if the specified character (Unicode code point) is an uppercase character.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isUpperCase(int codePoint);

			/**
			 * Determines whether the specified code point is a valid Unicode code point value.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isValidCodePoint(int codePoint);

			/**
			 * Determines if the specified character is white space according to Java.
			 * @param ch
			 * @return boolean
			 */
			static boolean isWhitespace(char ch);

			/**
			 * Determines if the specified character (Unicode code point) is white space according to Java.
			 * @param codePoint
			 * @return boolean
			 */
			static boolean isWhitespace(int codePoint);

			/**
			 * Returns the trailing surrogate (a low surrogate code unit) of the surrogate pair
			 * representing the specified supplementary character (Unicode code point) in the UTF-16 encoding.
			 * @param codePoint
			 * @return char
			 */
			static char	lowSurrogate(int codePoint);

			/**
			 * Returns the index within the given char subarray that is offset from the given index by codePointOffset code points.
			 * @param start
			 * @param count
			 * @param index
			 * @param codePointOffset
			 * @return int
			 */
			static int offsetByCodePoints(Array<char> a, int start, int count, int index, int codePointOffset);

			/**
			 * Returns the index within the given char sequence that is offset from the given index by codePointOffset code points.
			 * @param seq
			 * @param index
			 * @param codePointOffset
			 * @return int
			 */
			static int offsetByCodePoints(CharSequence &seq, int index, int codePointOffset);

			/**
			 * Returns the value obtained by reversing the order of the bytes in the specified char value.
			 * @param ch
			 * @return char
			 */
			static char	reverseBytes(char ch);

			/**
			 * Converts the specified character (Unicode code point) to its UTF-16 representation stored in a char array.
			 * @param codePoint
			 * @return Array<char>
			 */
			static Array<char> toChars(int codePoint);

			/**
			 * Converts the specified character (Unicode code point) to its UTF-16 representation.
			 * @param codePoint
			 * @param dstIndex
			 * @return int
			 */
			static int toChars(int codePoint, Array<char> dst, int dstIndex);

			/**
			 * Converts the specified surrogate pair to its supplementary code point value.
			 * @param high
			 * @param low
			 * @return int
			 */
			static int toCodePoint(char high, char low);

			/**
			 * Converts the character argument to lowercase using case mapping information from the UnicodeData file.
			 * @param ch
			 * @return char
			 */
			static char	toLowerCase(char ch);

			/**
			 * Converts the character (Unicode code point) argument to lowercase using case mapping information from the UnicodeData file.
			 * @param codePoint
			 * @return int
			 */
			static int toLowerCase(int codePoint);

			/**
			 * Returns a String object representing this Character's value.
			 * @return String
			 */
			String toString();

			/**
			 * Returns a String object representing the specified char.
			 * @param c
			 * @return String
			 */
			static String toString(char c);

			/**
			 * Converts the character argument to titlecase using case mapping information from the UnicodeData file.
			 * @param ch
			 * @return char
			 */
			static char	toTitleCase(char ch);

			/**
			 * Converts the character (Unicode code point) argument to titlecase using case mapping information from the UnicodeData file.
			 * @param codePoint
			 * @return int
			 */
			static int toTitleCase(int codePoint);

			/**
			 * Converts the character argument to uppercase using case mapping information from the UnicodeData file.
			 * @param ch
			 * @return char
			 */
			static char	toUpperCase(char ch);

			/**
			 * Converts the character (Unicode code point) argument to uppercase using case mapping information from the UnicodeData file.
			 * @param codePoint
			 * @return int
			 */
			static int toUpperCase(int codePoint);

			/**
			 * Returns a Character instance representing the specified char value.
			 * @param c
			 * @return Character
			 */
			static Character valueOf(char c);
		};
	}
}

#endif//NATIVE_JAVA_LANG_CHARACTER_HPP