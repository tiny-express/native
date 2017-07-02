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
			 * Determines the number of {@code char} values needed to
			 * represent the specified character (Unicode code point). If the
			 * specified character is equal to or greater than 0x10000, then
			 * the method returns 2. Otherwise, the method returns 1.
			 *
			 * @param   codePoint the character (Unicode code point) to be tested.
			 * @return  2 if the character is a valid supplementary character; 1 otherwise.
			 */
			int charCount(int codePoint);

            /**
			 * Returns the value of this {@code Character} object.
			 * @return  the primitive {@code char} value represented by
			 *          this object.
			 */
            char charValue();

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
            static int codePointAt(Array<char> a, int index);

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
            static boolean isHighSurrogate(wchar_t ch);

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
            static boolean isLowSurrogate(wchar_t ch);

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
            static int toCodePoint(wchar_t high, wchar_t low);

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
			static int codePointAt(Array<char> a, int index, int limit);

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
             * @since  1.5
             */
            static int codePointAt(char a[], int index);

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
             * @since  1.5
             */
            static int codePointAt(char a[], int index, int limit);

            // throws ArrayIndexOutOfBoundsException if index out of bounds
            static int codePointAtImpl(char a[], int index, int limit);

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
            static int codePointBefore(Array<char> seq, int index);

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
            static int codePointBefore(char a[], int index);

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
            static int codePointBefore(char a[], int index, int start);

            // throws ArrayIndexOutOfBoundsException if index-1 out of bounds
            static int codePointBeforeImpl(char a[], int index, int start);


			static int digit(int codePoint, int radix);

			/**
			 * Compares this object against the specified object.
			 * @param target
			 * @return boolean
			 */

		};
	}
}

#endif//NATIVE_JAVA_LANG_CHARACTER_HPP