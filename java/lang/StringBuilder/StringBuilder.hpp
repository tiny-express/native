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

#ifndef NATIVE_JAVA_LANG_STRINGBUILDER_HPP
#define NATIVE_JAVA_LANG_STRINGBUILDER_HPP

#include "../../../kernel/Common.hpp"
#include "../../Lang.hpp"
#include <initializer_list>

using namespace Java::IO;

namespace Java {
    namespace Lang {
        class StringBuilder :
                public Object,
                public virtual Serializable,
                public virtual CharSequence
        {
        private:
            string original = nullptr;
            mutable String backupOriginalForToString;
            int currentLength = 0;
            int currentCapacity = 0;

        public:
            static const int defaultCapacity = 16;

        public:
            /**
             * StringBuilder Constructor
             * Constructs a string builder with no characters in it and an initial capacity of 16 characters.
             */
            StringBuilder();

            /**
             * StringBuilder Constructor
             * Constructs a string builder with no characters in it and an initial capacity specified by the capacity argument.
             *
             * @param capacity
             * @throw NegativeArraySizeException - if the capacity argument is less than 0.
             */
            StringBuilder(int capacity);

            /**
             * StringBuilder Constructor
             * Constructs a string builder initialized to the contents of the specified string.
             * The initial capacity of the string builder is 16 plus the length of the nullTerminatedString argument.
             *
             * @param nullTerminatedString
             */
            StringBuilder(const string target);

            /**
             * StringBuilder Constructor
             * Constructs a string builder initialized to the contents of the specified string.
             * The initial capacity of the string builder is 16 plus the length of the string argument.
             *
             * @param string
             */
            StringBuilder(const String &target);

            /**
             * StringBuilder Constructor
             * Constructs a string builder initialized to the contents of the specified initializer list.
             * The initial capacity of the string builder is 16 plus the length of the list argument.
             *
             * @param list
             */
            StringBuilder(const std::initializer_list<char> &target);

            /**
             * StringBuilder Constructor
             * Constructs a string builder that contains the same characters as the specified CharSequence.
             *
             * @param charSequence
             */
            StringBuilder(const CharSequence &charSequence);

            /**
             * StringBuilder Constructor
             * Constructs a string builder that contains the same characters as the specified StringBuilder.
             *
             * @param stringBuilder
             */
            StringBuilder(const StringBuilder &target);

            /**
             * StringBuilder Destructor
             */
            virtual ~StringBuilder();

        public:
            /**
             * Appends the string representation of the Boolean argument to the sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(const Boolean &target);

            /**
             * Appends the string representation of the boolean argument to the sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(boolean target);

            /**
             * Appends the string representation of the Character argument to this sequence.
             * The argument is appended to the contents of this sequence. The length of this sequence increases by 1.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(const Character &target);

            /**
             * Appends the string representation of the char argument to this sequence.
             * The argument is appended to the contents of this sequence. The length of this sequence increases by 1.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(char target);

            /**
             * Appends the string representation of the Character array argument to this sequence.
             * The characters of the array argument are appended, in order, to the contents of this sequence.
             * The length of this sequence increases by the length of the argument.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(const Array<Character> &target);

            /**
             * Appends the string representation of the char array argument to this sequence.
             * The characters of the array argument are appended, in order, to the contents of this sequence.
             * The length of this sequence increases by the length of the argument.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(const Array<char> &target);

            /**
             * Appends the string representation of a subarray of the Character array argument to this sequence.
             * Characters of the char array target, starting at index offset, are appended, in order, to the contents of this sequence.
             * The length of this sequence increases by the value of length.
             *
             * @param target
             * @param offset
             * @param length
             * @return StringBuilder
             * @throw IndexOutOfBoundsException - if offset < 0 or length < 0 or offset+length > target.length
             */
            StringBuilder &append(const Array<Character> &target, int offset, int length);

            /**
             * Appends the string representation of a subarray of the char array argument to this sequence.
             * Characters of the char array target, starting at index offset, are appended, in order, to the contents of this sequence.
             * The length of this sequence increases by the value of length.
             *
             * @param target
             * @param offset
             * @param length
             * @return StringBuilder
             * @throw IndexOutOfBoundsException - if offset < 0 or length < 0 or offset+length > target.length
             */
            StringBuilder &append(const Array<char> &target, int offset, int length);

            /**
             * Appends the specified character sequence to this sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(const CharSequence &target);

            /**
             * Appends a subsequence of the specified CharSequence to this sequence.
             *
             * @param target
             * @param start
             * @param end
             * @return StringBuilder
             * @throw IndexOutOfBoundsException - if start is negative, or start is greater than end or end is greater than target.length()
             */
            StringBuilder &append(const CharSequence &target, int start, int end);

            /**
             * Appends the specified initializer list of char to this character sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(const std::initializer_list<char> &target);

            /**
             * Appends the specified string to this character sequence.
             *
             * @param target
             * @return
             */
            StringBuilder &append(const string target);

            /**
             * Appends the string representation of the Double argument to this sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(const Double &target);

            /**
             * Appends the string representation of the double argument to this sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(double target);

            /**
             * Appends the string representation of the Float argument to this sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(const Float &target);

            /**
             * Appends the string representation of the float argument to this sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(float target);

            /**
             * Appends the string representation of the Integer argument to this sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(const Integer &target);

            /**
             * Appends the string representation of the int argument to this sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(int target);

            /**
             * Appends the string representation of the Long argument to this sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(const Long &target);

            /**
             * Appends the string representation of the long argument to this sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(long target);

            /**
             * Appends the string representation of the Object argument.
             *
             * @param target
             * @return StringBuilder
             */
//           StringBuilder &append(const Object &target); // FIXME: Object.toString() return hashcode and it changes every time (can not test).

            /**
             * Appends the specified string to this character sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder &append(const String &target);

            /**
             * Appends the specified StringBuffer to this sequence.
             *
             * @param target
             * @return
             */
//          StringBuilder &append(const StringBuffer &target); // FIXME: StringBuffer doesn't implemented.

            /**
             * Appends the string representation of the codePoint argument to this sequence.
             *
             * @param codePoint
             * @return StringBuilder
             */
            StringBuilder &appendCodePoint(int codePoint);

            /**
             * Returns the current capacity.
             * The capacity is the amount of storage available for newly inserted characters, beyond which an allocation will occur.
             *
             * @return int
             */
            int capacity() const;

            /**
             * Returns the char value in this sequence at the specified index.
             * The first char value is at index 0, the next at index 1, and so on, as in array indexing.
             * The index argument must be greater than or equal to 0, and less than the length of this sequence.
             * If the char value specified by the index is a surrogate, the surrogate value is returned.
             *
             * @param index
             * @return char
             * @throw IndexOutOfBoundsException - if index is negative or greater than or equal to length()
             */
            char charAt(int index) const;

            /**
             * Returns the character (Unicode code point) at the specified index.
             * The index refers to char values (Unicode code units) and ranges from 0 to length() - 1.
             * If the char value specified at the given index is in the high-surrogate range,
             * the following index is less than the length of this sequence,
             * and the char value at the following index is in the low-surrogate range,
             * then the supplementary code point corresponding to this surrogate pair is returned.
             * Otherwise, the char value at the given index is returned.
             *
             * @param index - the index to the char values.
             * @return int - the code point value of the character at the index.
             * @throw IndexOutOfBoundsException - if the index argument is negative or not less than the length of this sequence.
             */
            int codePointAt(int index) const;

            /**
             * Returns the character (Unicode code point) before the specified index.
             * The index refers to char values (Unicode code units) and ranges from 1 to length().
             * If the char value at (index - 1) is in the low-surrogate range, (index - 2) is not negative,
             * and the char value at (index - 2) is in the high-surrogate range,
             * then the supplementary code point value of the surrogate pair is returned.
             * If the char value at index - 1 is an unpaired low-surrogate or a high-surrogate, the surrogate value is returned.
             *
             * @param index - the index following the code point that should be returned.
             * @return int - the Unicode code point value before the given index.
             * @throw IndexOutOfBoundsException - if the index argument is less than 1 or greater than the length of this sequence.
             */
            int codePointBefore(int index) const;

            /**
             * Returns the number of Unicode code points in the specified text range of this sequence.
             * The text range begins at the specified beginIndex and extends to the char at index endIndex - 1.
             * Thus the length (in chars) of the text range is endIndex - beginIndex.
             * Unpaired surrogates within this sequence count as one code point each.
             *
             * @param beginIndex - the index to the first char of the text range.
             * @param endIndex - the index after the last char of the text range.
             * @return int - the number of Unicode code points in the specified text range
             * @throw IndexOutOfBoundsException - if the beginIndex is negative, or endIndex is larger than the length of this sequence, or beginIndex is larger than endIndex.
             */
            int codePointCount(int beginIndex, int endIndex);

            /**
             * @see deleteRange
             */
//          StringBuilder delete(int start, int end);

            /**
             * Removes the characters in a substring of this sequence.
             * The substring begins at the specified start and extends to the character at index end - 1
             * or to the end of the sequence if no such character exists.
             * If start is equal to end, no changes are made.
             *
             * @param start
             * @param end
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if start is negative, greater than length(), or greater than end.
             */
            StringBuilder deleteRange(int start, int end);

            /**
             * Removes the char at the specified position in this sequence.
             * This sequence is shortened by one char.
             *
             * @param index
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the index is negative or greater than or equal to length().
             */
            StringBuilder deleteCharAt(int index);

            /**
             * Ensures that the capacity is at least equal to the specified minimum.
             * If the current capacity is less than the argument, then a new internal array is allocated with greater capacity.
             *
             * @param minimumCapacity
             */
            void ensureCapacity(int minimumCapacity);

            /**
             * Characters are copied from this sequence into the destination character array target.
             * The first character to be copied is at index sourceBegin; the last character to be copied is at index sourceEnd - 1.
             * The total number of characters to be copied is sourceEnd - sourceBegin
             * The characters are copied into the subarray of target starting at index targetBegin
             * and ending at index targetBegin + (sourceEnd-sourceBegin) - 1.
             *
             * @param sourceBegin
             * @param sourceEnd
             * @param target
             * @param targetBegin
             * @throw IndexOutOfBoundsException - if any of the following is true:
             *        sourceBegin is negative;
             *        targetBegin is negative;
             *        the sourceBegin argument is greater than the sourceEnd argument;
             *        srcEnd is greater than this.length();
             *        targetBegin+sourceEnd-sourceBegin is greater than target.length.
             */
            void getChars(int sourceBegin, int sourceEnd, Array<Character> &target, int targetBegin) const;

            /**
             * Returns the index within this string of the first occurrence of the specified substring.
             *
             * @param target
             * @return int
             */
            int indexOf(const String &target) const;

            /**
             * Returns the index within this string of the first occurrence of the specified substring.
             *
             * @param target
             * @return int
             */
            int indexOf(const string target) const;

            /**
             * Returns the index within this string of the first occurrence of the specified substring, starting at the specified index.
             *
             * @param target
             * @param fromIndex
             * @return int
             */
            int indexOf(const String &target, int fromIndex) const;

            /**
             * Returns the index within this string of the first occurrence of the specified substring, starting at the specified index.
             *
             * @param target
             * @param fromIndex
             * @return int
             */
            int indexOf(const string target, int fromIndex) const;

            /**
             * Inserts the string representation of the boolean argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             */
            StringBuilder &insert(int offset, boolean target);

            /**
             * Inserts the string representation of the Boolean argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             */
            StringBuilder &insert(int offset, const Boolean &target);

            /**
             * Inserts the string representation of the char argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw IndexOutOfBoundsException - if the offset is invalid.
             */
            StringBuilder &insert(int offset, char target);

            /**
             * Inserts the string representation of the Character argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             */
            StringBuilder &insert(int offset, const Character &target);

            /**
             * Inserts the string representation of the char array argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             */
            StringBuilder &insert(int offset, const Array<char> &target);

            /**
             * Inserts the string representation of the Character array argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             */
            StringBuilder &insert(int offset, const Array<Character> &target);

            /**
             * Inserts the string representation of a subarray of the target array argument into this sequence.
             * The subarray begins at the specified offset and extends length chars.
             * The characters of the subarray are inserted into this sequence at the position indicated by index.
             * The length of this sequence increases by length chars.
             *
             * @param index
             * @param target
             * @param offset
             * @param length
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if index is negative or greater than length(), or offset or length are negative, or (offset+length) is greater than target.length().
             */
            StringBuilder &insert(int index, const Array<char> &target, int offset, int length);

            /**
             * Inserts the string representation of a subarray of the 'target' array argument into this sequence.
             * The subarray begins at the specified 'offset' and extends 'length' chars.
             * The characters of the subarray are inserted into this sequence at the position indicated by 'index'.
             * The length of this sequence increases by 'length' chars.
             *
             * @param index
             * @param target
             * @param offset
             * @param length
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if index is negative or greater than length(),
             * or offset or length are negative, or (offset+length) is greater than target.length
             */
            StringBuilder &insert(int index, const Array<Character> &target, int offset, int length);

            /**
             * Inserts the specified CharSequence into this sequence.
             * The characters of the CharSequence argument are inserted, in order, into this sequence at the indicated offset,
             * moving up any characters originally above that position and increasing the length of this sequence by the length of the argument target.
             *
             * @param destinationOffset
             * @param target
             * @return StringBuilder
             * @throw IndexOutOfBoundsException - if the destinationOffset is invalid.
             */
            StringBuilder &insert(int destinationOffset, const CharSequence &target);

            /**
             * Inserts a subsequence of the specified CharSequence into this sequence.
             * The subsequence of the argument target specified by start and end are inserted,
             * in order, into this sequence at the specified destination offset, moving up any characters originally above that position.
             * The length of this sequence is increased by end - start.
             *
             * @param destinationOffset
             * @param target
             * @param start
             * @param end
             * @return StringBuilder
             * @throw IndexOutOfBoundsException - if destinationOffset is negative or greater than length(),
             * or start or end are negative, or start is greater than end or end is greater than target.length()
             */
            StringBuilder &insert(int destinationOffset, const CharSequence &target, int start, int end);

            /**
             * Inserts the string representation of the Double argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             */
            StringBuilder &insert(int offset, const Double &target);

            /**
             * Inserts the string representation of the double argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             */
            StringBuilder &insert(int offset, double target);

            /**
             * Inserts the string representation of the Float argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             */
            StringBuilder &insert(int offset, const Float &target);

            /**
             * Inserts the string representation of the float argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             */
            StringBuilder &insert(int offset, float target);

            /**
             * Inserts the string representation of the second int argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             */
            StringBuilder &insert(int offset, const Integer &target);

            /**
             * Inserts the string representation of the second int argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             */
            StringBuilder &insert(int offset, int target);

            /**
             * Inserts the string representation of the Long argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             */
            StringBuilder &insert(int offset, const Long &target);

            /**
             * Inserts the string representation of the long argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             */
            StringBuilder &insert(int offset, long target);

            /**
             * Inserts the string representation of the Object argument into this character sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             */
//          StringBuilder &insert(int offset, const Object &target); // FIXME: String::valueOf(Object) doesn't exist.

            /**
             * Inserts the string into this character sequence.
             * The characters of the String argument are inserted, in order, into this sequence at the indicated offset,
             * moving up any characters originally above that position and increasing the length of this sequence by the length of the argument.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             */
            StringBuilder &insert(int offset, const String &target);

            /**
             * Inserts the string representation of the string argument into this sequence.
             * The characters of the string argument are inserted into the contents of this sequence at the position indicated by offset.
             * The length of this sequence increases by the length of the argument.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             */
            StringBuilder &insert(int offset, const string target);

            /**
             * This method accepts a String as an argument, if the string argument occurs one or more times as a substring within this object,
             * then it returns the index of the first character of the last such substring is returned.
             * If it does not occur as a substring, -1 is returned.
             *
             * @param target
             * @return int
             */
            int lastIndexOf(const String &target) const;

            /**
             * This method accepts a string as an argument, if the string argument occurs one or more times as a substring within this object,
             * then it returns the index of the first character of the last such substring is returned.
             * If it does not occur as a substring, -1 is returned.
             *
             * @param target
             * @return int
             */
            int lastIndexOf(const string target) const;

            /**
             * This method returns the index within this string of the last occurrence of the specified substring,
             * searching backward starting at the specified index.
             *
             * @param target
             * @param fromIndex
             * @return int
             */
            int lastIndexOf(const String &target, int fromIndex) const;

            /**
             * This method returns the index within this string of the last occurrence of the specified substring,
             * searching backward starting at the specified index.
             *
             * @param target
             * @param fromIndex
             * @return int
             */
            int lastIndexOf(const string target, int fromIndex) const;

            /**
             * Returns the length (character count).
             *
             * @return int
             */
            int length() const override;

            /**
             * Returns the index within this sequence that is offset from the given index by codePointOffset code points.
             * Unpaired surrogates within the text range given by index and codePointOffset count as one code point each.
             *
             * @param index
             * @param codePointOffset
             * @return int
             * @throw IndexOutOfBoundsException - if index is negative or larger then the length of this sequence,
             * or if codePointOffset is positive and the subsequence starting with index has fewer than codePointOffset code points,
             * or if codePointOffset is negative and the subsequence before index has fewer than the absolute value of codePointOffset code points.
             */
            int offsetByCodePoints(int index, int codePointOffset) const;

            /**
             * Replaces the characters in a substring of this sequence with characters in the specified String.
             * The substring begins at the specified start and extends to the character at index end - 1
             * or to the end of the sequence if no such character exists.
             * First the characters in the substring are removed and then the specified String is inserted at start.
             * (This sequence will be lengthened to accommodate the specified String if necessary.)
             *
             * @param start
             * @param end
             * @param target
             * @return StringBuilder
             */
            StringBuilder replace(int start, int end, const String &target);

            /**
             * Replaces the characters in a substring of this sequence with characters in the specified string.
             * The substring begins at the specified start and extends to the character at index end - 1
             * or to the end of the sequence if no such character exists.
             * First the characters in the substring are removed and then the specified string is inserted at start.
             * (This sequence will be lengthened to accommodate the specified string if necessary.)
             *
             * @param start
             * @param end
             * @param target
             * @return StringBuilder
             * @throw StringIndexOutOfBoundsException - if start is negative, greater than length(), or greater than end.
             */
            StringBuilder replace(int start, int end, const string target);

            /**
             * Causes this character sequence to be replaced by the reverse of the sequence.
             * If there are any surrogate pairs included in the sequence, these are treated as single characters for the reverse operation.
             *
             * @return StringBuilder
             */
            StringBuilder reverse();

            /**
             * The character at the specified index is set to target.
             * This sequence is altered to represent a new character sequence that is identical to the old character sequence,
             * except that it contains the character target at position index.
             *
             * @param index
             * @param target
             * @throw IndexOutOfBoundsException - if index is negative or greater than or equal to length().
             */
            void setCharAt(int index, char target);

            /**
             * The character at the specified index is set to target.
             * This sequence is altered to represent a new character sequence that is identical to the old character sequence,
             * except that it contains the character target at position index.
             *
             * @param index
             * @param target
             * @throw IndexOutOfBoundsException - if index is negative or greater than or equal to length().
             */
            void setCharAt(int index, const Character &target);

            /**
             * Sets the length of the character sequence.
             *
             * @param newLength
             * @throw IndexOutOfBoundsException - if the newLength argument is negative.
             */
            void setLength(int newLength);

            /**
             * Returns a new String that contains a subsequence of characters currently contained in this sequence.
             * The substring begins at the specified start and extends to the character at index end - 1.
             *
             * @param start
             * @param end
             * @return CharSequence
             * @throw IndexOutOfBoundsException - if start or end are negative, if end is greater than length(), or if start is greater than end.
             */
//          CharSequence subSequence(int start, int end) const;

            /**
             * Returns a new String that contains a subsequence of characters currently contained in this character sequence.
             * The substring begins at the specified index and extends to the end of this sequence.
             *
             * @param start
             * @return String
             * @throw StringIndexOutOfBoundsException - if start is less than zero, or greater than the length of this object.
             */
            String substring(int start) const;

            /**
             * Returns a new String that contains a subsequence of characters currently contained in this sequence.
             * The substring begins at the specified start and extends to the character at index end - 1.
             *
             * @param start
             * @param end
             * @return String
             * @throw StringIndexOutOfBoundsException - if start or end are negative or greater than length(), or start is greater than end.
             */
            String substring(int start, int end) const;

            /**
             * Returns a string representing the data in this sequence.
             * A new string object is allocated and initialized to contain the character sequence currently represented by this object.
             * This string is then returned. Subsequent changes to this sequence do not affect the contents of the string.
             *
             * @return string
             */
            string toString() const override;

            /**
             * Attempts to reduce storage used for the character sequence.
             * If the buffer is larger than necessary to hold its current sequence of characters,
             * then it may be resized to become more space efficient.
             * Calling this method may, but is not required to, affect the value returned by a subsequent call to the capacity() method.
             */
            void trimToSize();

        private:

            /**
             * This method builds a "Next Table" that depending on a specified 'pattern'.
             * "Next Table" is a friendly name of "partial match" table (also known as "failure function") in Knuth-Morris-Pratt algorithm.
             *
             * @param pattern
             * @return int *
             */
            int *initializeNextTable(const string pattern) const;

            /**
             * This method returns the index within this string of the first occurrence of the specified substring,
             * starting at the specified index by using Knuth-Morris-Pratt algorithm.
             *
             * @param target
             * @param pattern
             * @param startIndex
             * @return int
             */
            int stringMatches(const string target, const string pattern, int startIndex) const;

            /**
             * This method returns the index within this string of the last occurrence of the specified substring,
             * searching backward starting at the specified index by using Knuth-Morris-Pratt algorithm.
             *
             * @param target
             * @param pattern
             * @param startIndex
             * @return int
             */
            int stringMatchesReverse(const string target, const string pattern, int startIndex) const;

            /**
             * This method helps reverses all valid surrogate pairs are produced by reverse method.
             */
            void reverseAllValidSurrogatePairs();
        };
    }
}

#endif //NATIVE_JAVA_LANG_STRINGBUILDER_HPP
