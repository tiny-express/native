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
#ifndef NATIVE_STRINGBUFFER_H
#define NATIVE_STRINGBUFFER_H

#include "../StringBuilder/StringBuilder.hpp"

namespace Java {
    namespace Lang {
        class StringBuffer { //: public CharSequence {
        private:
            string original = nullptr;
            string toStringCache = nullptr;
            int currentLength = 0;
            int currentCapacity = 0;

        private:
            //void readObject(ObjectInputStream);

            //void writeObject(ObjectOutputStream);

        public:

            /**
             * Constructs a string buffer with no characters in it and an initial capacity of 16 characters.
             *
             */
            StringBuffer();

            /**
             * Constructs a string buffer that contains the same characters as the specified CharSequence.
             *
             * @param seq
             */
            explicit StringBuffer(CharSequence *seq);

            /**
             * Constructs a string buffer with no characters in it and the specified initial capacity.
             *
             * @param capacity
             * @throw NegativeArraySizeException if capacity is negative
             */
            explicit StringBuffer(int capacity);

            /**
             * Constructs a string buffer initialized to the contents of the specified string.
             *
             * @param str
             */
            explicit StringBuffer(String str);

            /**
             * Copy constructor
             *
             * @param other
             */
            StringBuffer(const StringBuffer &other);

            /**
             * Appends the string representation of the Object argument.
             *
             * @param obj
             * @return reference to this StringBuffer
             */
            StringBuffer append(Object *obj);

            /**
             * Appends the string representation of the float argument
             *
             * @param floatValue
             * @return reference to this StringBuffer
             */
            StringBuffer append(float floatValue);

            //StringBuffer append(AbstractStringBuilder abs);

            /**
             * Appends the string representation of the char array argument to this sequence.
             *
             * @param str
             * @return reference to this StringBuffer
             */
            StringBuffer append(string str);

            /**
             * Appends the string representation of the boolean argument
             *
             * @param boolValue
             * @return reference to this StringBuffer
             */
            StringBuffer append(boolean boolValue);

            /**
             * Appends the specified CharSequence to this sequence.
             *
             * @param seq
             * @return reference to this StringBuffer
             */
            StringBuffer append(CharSequence *seq);

            /**
             * Appends the string representation of the double argument
             *
             * @param doubleValue
             * @return reference to this StringBuffer
             */
            StringBuffer append(double doubleValue);

            /**
             * Appends the string representation of the char argument
             *
             * @param charValue
             * @return reference to this StringBuffer
             */
            StringBuffer append(char charValue);

            /**
             * Appends the string representation of char array argument to this sequence.
             *
             * @param str
             * @return reference to this StringBuffer
             */
            StringBuffer append(String str);

            /**
             * Appends the string representation of the int argument
             *
             * @param intValue
             * @return reference to this StringBuffer
             */
            StringBuffer append(int intValue);

            /**
             * Appends the string representation of the long argument
             *
             * @param longValue
             * @return reference to this StringBuffer
             */
            StringBuffer append(long longValue);

            /**
             * Appends the specified StringBuffer to this sequence.
             *
             * @param stringBuffer
             * @return reference to this StringBuffer
             */
            StringBuffer append(StringBuffer *stringBuffer);

            /**
             * Appends the string representation of a subarray of the char array argument to this sequence.
             * Characters of the char array str, starting at index offset, are appended, in order,
             * the length of subarray is equal to len
             *
             * @param str
             * @param offset
             * @param len
             * @throw IndexOutOfBoundsException  if offset < 0 or len < 0 or offset+len > str.length
             * @return
             */
            StringBuffer append(string str, int offset, int len);

            /**
             * Appends a subsequence of the specified CharSequence to this sequence.
             * starting at index start, are appended, in order,
             * to the contents of this sequence up to the (exclusive) index end.
             * If start is negative or bigger than end or bigger than seq's length,
             * throw IndexOutOfBoundException
             *
             * @param seq
             * @param start
             * @param end
             * @throw IndexOutOfBoundException If start is negative or bigger than end or bigger than seq's length
             * @return reference to this StringBuffer
             */
            StringBuffer append(CharSequence *seq, int start, int end);

            /**
             * Appends the string representation of the codePoint argument to this sequence.             *
             *
             * @param codePoint
             * @return reference to this StringBuffer
             */
            StringBuffer appendCodePoint(int codePoint);

            /**
             * Return current capacity of this StringBuffer
             *
             * @return int
             */
            int capacity();

            /**
             * Return character ai specified index
             *
             * @param index
             * @throw IndexOutOfBoundsException - if index is negative or greater than or equal to length().
             * @return character at specified index
             */
            char charAt(int index);

            //IntStream codePoint();

            /**
             * Returns the character (Unicode code point) at the specified index.
             * If the char value specified at the given index is in the high-surrogate range,
             * the following index is less than the length of this sequence,
             * and the char value at the following index is in the low-surrogate range,
             * then the supplementary code point corresponding to this surrogate pair is returned.
             * Otherwise, the char value at the given index is returned.
             *
             * @param index
             * @throw IndexOutOfBoundException if index is negative or greater than or equal to length().
             * @return
             */
            int codePointAt(int index);

            /**
             * Returns the character (Unicode code point) before the specified index.
             * If the char value at (index - 1) is in the low-surrogate range,
             * (index - 2) is not negative, and the char value at (index - 2) is in the high-surrogate range,
             * then the supplementary code point value of the surrogate pair is returned.
             * If the char value at index - 1 is an unpaired low-surrogate or a high-surrogate,
             * the surrogate value is returned.
             *
             * @param index
             * @throw IndexOutOfBoundException if index is negative or greater than or equal to length().
             * @return the character (Unicode code point) before the specified index
             */
            int codePointBefore(int index);

            int codePointCount(int beginIndex);

            //IntStream codePoint();

            StringBuffer deletes(int start, int end);

            StringBuffer deleteCharAt(int index);

            /**
             * Ensures that the capacity is at least equal to the specified minimum.
             * The new capacity is the larger than the minimumCapacity argument and twice the old capacity plus 2.
             * If minimumCapacity is non-positive or less or equal to this capacity, return
             *
             * @param minimumCapacity
             */
            void ensureCapacity(int minimumCapacity);

            void getChars(int srcBegin, int srcEnd, string dts, int dstBgin);

            /**
             * Return the string value of this StringBuffer
             *
             * @return string
             */
            string getValue();

            int indexOf(String str);

            int indexOf(String str, int fromIndex);

            StringBuffer insert(int offset, float floatValue);

            StringBuffer insert(int offset, boolean boolValue);

            StringBuffer insert(int offset, string str);

            StringBuffer insert(int offset, char charValue);

            StringBuffer insert(int offset, String str);

            StringBuffer insert(int offset, long longValue);

            StringBuffer insert(int offset, Object obj);

            StringBuffer insert(int offset, int intValue);

            StringBuffer insert(int offset, double doubleValue);

            StringBuffer insert(int dstOffset, CharSequence *seq, int start, int end);

            /**
             * Inserts the string representation of a subarray of the str array argument into this sequence.
             * The subarray begins at the specified offset and extends len chars.
             * The subarray is insert at position index
             *
             * @param index
             * @param str
             * @param offset
             * @param len
             * @throw StringIndexOutOfBoundsException - if index is negative or greater than length(),
             * or offset or len are negative, or (offset+len) is greater than str.length.
             * @return
             */
            StringBuffer insert(int index, string str, int offset, int len);

            int lastIndexOf(String str);

            int lastIndexOf(String str, int fromIndex);

            /**
             * Return the current munber of used char of this sequence
             *
             * @return int
             */
            int length();

            int offsetByCodePoints(int index, int codePointOffset);

            StringBuffer replace(int start, int end, String str);

            StringBuffer reverse();

            void setCharAt(int index, char charValue);

            void setLength(int newLength);

            CharSequence *subSequence(int start, int end);

            String subString(int start);

            String subString(int start, int end);

            String toString();

            void trimToSize();

            /**
             * Destructor, free memory alocated for original
             */
            ~StringBuffer();

        };
    }
}



#endif //NATIVE_STRINGBUFFER_H
