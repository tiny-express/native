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

#include "../../Lang.hpp"
#include <initializer_list>

using namespace Java::IO;

namespace Java {
    namespace Lang {
        class StringBuilder :
//              public Object,
                public virtual Serializable//,
//              public virtual CharSequence
        {
        private:
            string original = NULL;
            int currentLength = 0;
            int currentCapacity = 0;

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
//          StringBuilder(const CharSequence &charSequence);

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
            StringBuilder append(const Boolean &target);

            StringBuilder append(boolean target);

            StringBuilder append(const Character &target);

            StringBuilder append(char target);

            StringBuilder append(const Array<Character> &target);

            StringBuilder append(const Array<char> &target);

            StringBuilder append(const Array<Character> &target, int offset, int length);

            StringBuilder append(const Array<char> &target, int offset, int length);

//          StringBuilder append(const CharSequence &target);

            /**
             * Appends the specified initializer list of char to this character sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder append(const std::initializer_list<char> &target);

            /**
             * Appends the specified string to this character sequence.
             *
             * @param target
             * @return
             */
            StringBuilder append(const string target);

            StringBuilder append(const Double &target);

            StringBuilder append(double target);

            /**
             * Appends the string representation of the Float argument to this sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder append(const Float &target);

            /**
             * Appends the string representation of the float argument to this sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder append(float target);

            /**
             * Appends the string representation of the Integer argument to this sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder append(const Integer &target);

            /**
             * Appends the string representation of the int argument to this sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder append(int target);

            /**
             * Appends the string representation of the Long argument to this sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder append(const Long &target);

            /**
             * Appends the string representation of the long argument to this sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder append(long target);

            /**
             * Appends the string representation of the Object argument.
             *
             * @param target
             * @return StringBuilder
             */
//           StringBuilder append(const Object &target); // FIXME: Object.toString() return hashcode and it changes every time (can not test).

            /**
             * Appends the specified string to this character sequence.
             *
             * @param target
             * @return StringBuilder
             */
            StringBuilder append(const String &target);

            /**
             * Appends the specified StringBuffer to this sequence.
             *
             * @param target
             * @return
             */
//           StringBuilder append(const StringBuffer &target); // FIXME: StringBuffer is not implemented.
            StringBuilder appendCodePoint(int codePoint);

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

            int codePointAt(int index) const;

            int codePointBefore(int index) const;

            int codePointCount(int beginIndex, int endIndex);

            StringBuilder deleteRange(int start, int end);

            StringBuilder deleteCharAt(int index);

            void ensureCapacity(int minimumCapacity);

            void getChars(int sourceBegin, int sourceEnd, Array<char> &target, int targetBegin);

            int indexOf(const String &target);

            int indexOf(const String &target, int fromIndex);

            /**
             * Inserts the string representation of the boolean argument into this sequence.
             * @param offset
             * @param target
             * @return StringBuilder
             */
            StringBuilder insert(int offset, boolean target);

            /**
             * Inserts the string representation of the Boolean argument into this sequence.
             * @param offset
             * @param target
             * @return StringBuilder
             */
            StringBuilder insert(int offset, const Boolean &target);

            /**
             * Inserts the string representation of the char argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             */
            StringBuilder insert(int offset, char target);

            /**
             * Inserts the string representation of the Character argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             */
            StringBuilder insert(int offset, const Character &target);

            /**
             * Inserts the string representation of the char array argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             */
            StringBuilder insert(int offset, const Array<char> &target);

            /**
             * Inserts the string representation of the Character array argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             */
            StringBuilder insert(int offset, const Array<Character> &target);

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
             * @throw StringIndexOutOfBoundsException - if index is negative or greater than length(), or offset or length are negative, or (offset+length) is greater than target.length
             */
            StringBuilder insert(int index, const Array<char> &target, int offset, int length);

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
             * @throw StringIndexOutOfBoundsException - if index is negative or greater than length(), or offset or length are negative, or (offset+length) is greater than target.length
             */
            StringBuilder insert(int index, const Array<Character> &target, int offset, int length);

            StringBuilder insert(int destinationOffset, const CharSequence &target);

            StringBuilder insert(int destinationOffset, const CharSequence &target, int start, int end);

            /**
             * Inserts the string representation of the Double argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             */
            StringBuilder insert(int offset, const Double &target);

            /**
             * Inserts the string representation of the double argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             */
            StringBuilder insert(int offset, double target);

            /**
             * Inserts the string representation of the Float argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             */
            StringBuilder insert(int offset, const Float &target);

            /**
             * Inserts the string representation of the float argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             */
            StringBuilder insert(int offset, float target);

            /**
             * Inserts the string representation of the second int argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             */
            StringBuilder insert(int offset, const Integer &target);

            /**
             * Inserts the string representation of the second int argument into this sequence.
             * @param offset
             * @param target
             * @return StringBuilder
             */
            StringBuilder insert(int offset, int target);

            /**
             * Inserts the string representation of the Long argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             */
            StringBuilder insert(int offset, const Long &target);

            /**
             * Inserts the string representation of the long argument into this sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             */
            StringBuilder insert(int offset, long target);

            /**
             * Inserts the string representation of the Object argument into this character sequence.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             */
//          StringBuilder insert(int offset, const Object &target); // FIXME: String::valueOf(Object) doesn't exist.

            /**
             * Inserts the string into this character sequence.
             * The characters of the String argument are inserted, in order, into this sequence at the indicated offset,
             * moving up any characters originally above that position and increasing the length of this sequence by the length of the argument.
             *
             * @param offset
             * @param target
             * @return StringBuilder
             */
            StringBuilder insert(int offset, const String &target);

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
            StringBuilder insert(int offset, const string target);

            StringBuilder lastIndexOf(const String &target);

            StringBuilder lastIndexOf(const String &target, int fromIndex);

            /**
             * Returns the length (character count).
             *
             * @return int
             */
            int length() const;

            int offsetByCodePoints(int index, int codePointOffset) const;

            StringBuilder replace(int start, int end, const String &str);

            StringBuilder reverse();

            void setCharAt(int index, char target);

            void setCharAt(int index, const Character &target);

            void setLength(int newLength);

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
            String toString() const;

            /**
             * Attempts to reduce storage used for the character sequence.
             * If the buffer is larger than necessary to hold its current sequence of characters,
             * then it may be resized to become more space efficient.
             * Calling this method may, but is not required to, affect the value returned by a subsequent call to the capacity() method.
             */
            void trimToSize();
        };
    }
}

#endif //NATIVE_JAVA_LANG_STRINGBUILDER_HPP
