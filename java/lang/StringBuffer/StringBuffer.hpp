/**
 * Copyright (c) 2017 Food Tiny Project. All rights reserved.
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

#include "../../../kernel/String.hpp"
#include <mutex>
#include "../StringBuilder/StringBuilder.hpp"

namespace Java {
    namespace Lang {
        class StringBufferUnSafe :
                public Object,
                public virtual CharSequence {
        protected:
            string original = nullptr;
            int currentLength = 0;
            int currentCapacity = 0;

        private:
            // TODO need ObjectInputStream
            // void readObject(ObjectInputStream);

            // TODO need ObjectOutPutStream
            // void writeObject(ObjectOutputStream);

        public:
            /**
             * Constructs a string buffer with no characters in it and an initial capacity of 16 characters.
             *
             */
            StringBufferUnSafe();

            /**
             * Constructs a string buffer that contains the same characters as the specified CharSequence.
             *
             * @param sequence
             */
            explicit StringBufferUnSafe(CharSequence &sequence);

            /**
             * Constructs a string buffer with no characters in it and the specified initial capacity.
             *
             * @param capacity
             * @throw NegativeArraySizeException if capacity is negative
             */
            explicit StringBufferUnSafe(int capacity);

            /**
             * Constructs a string buffer initialized to the contents of the specified string.
             *
             * @param originalString
             */
            explicit StringBufferUnSafe(String originalString);

            /**
             * Copy constructor
             *
             * @param other
             */
            StringBufferUnSafe(const StringBufferUnSafe &other);

            /**
             * Appends the string representation of the Object argument.
             * If object is null then four character "null" will be append
             *
             * @param object
             * @return reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &append(Object *object);

            /**
             * Appends the string representation of the float argument
             *
             * @param floatValue
             * @return reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &append(float floatValue);

            // StringBuffer append(AbstractStringBuilder abs);

            /**
             * Appends the string representation of the char array argument to this sequence.
             *
             * @param stringToAppend
             * @return reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &append(string stringToAppend);

            /**
             * Appends the string representation of the boolean argument
             *
             * @param boolValue
             * @return reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &append(boolean boolValue);

            /**
             * Appends the specified CharSequence to this sequence.
             * If sequence is null then four character "null" will be append
             *
             * @param sequence
             * @return reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &append(CharSequence &sequence);

            /**
             * Appends the string representation of the double argument
             *
             * @param doubleValue
             * @return reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &append(double doubleValue);

            /**
             * Appends the string representation of the char argument
             *
             * @param charValue
             * @return reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &append(char charValue);

            /**
             * Appends the string representation of char array argument to this sequence.
             *
             * @param stringToAppend
             * @return reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &append(String stringToAppend);

            /**
             * Appends the string representation of the int argument
             *
             * @param intValue
             * @return reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &append(int intValue);

            /**
             * Appends the string representation of the long argument
             *
             * @param longValue
             * @return reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &append(long longValue);

            /**
             * Appends the specified StringBuffer to this sequence.
             * If stringBuffer is null then four character "null" will be append
             *
             * @param stringBufferUnSafe
             * @return reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &append(StringBufferUnSafe stringBufferUnSafe);

            /**
             * Appends the string representation of a subarray of the char array argument to this sequence.
             * Characters of the char array str, starting at index offset, are appended, in order,
             * the length of subarray is equal to len
             *
             * @param stringToAppend
             * @param offset
             * @param len
             * @throw IndexOutOfBoundsException  if offset < 0 or len < 0 or offset+len > str.length
             * @return reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &append(string stringToAppend, int offset, int len);

            /**
             * Appends a subsequence of the specified CharSequence to this sequence.
             * starting at index start, are appended, in order,
             * to the contents of this sequence up to the (exclusive) index end.
             * If sequence is null then four character "null" will be append
             *
             * @param sequence
             * @param start
             * @param end
             * @throw IndexOutOfBoundException If start is negative or bigger than end or bigger than seq's length
             * @return reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &append(CharSequence &sequence, int start, int end);

            /**
             * Appends the string representation of the codePoint argument to this sequence.             *
             *
             * @param codePoint
             * @return reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &appendCodePoint(int codePoint);

            /**
             * Return current capacity of this StringBuffer
             *
             * @return int
             */
            int capacity() const;

            /**
             * Return character at specified index
             *
             * @param index
             * @throw IndexOutOfBoundsException - if index is negative or greater than or equal to length().
             * @return character at specified index
             */
            char charAt(int index) const override;

            // TODO need IntStream
            // IntStream codePoint();

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
             * @return the character (Unicode code point) at the specified index
             */
            int codePointAt(int index) const;

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
            int codePointBefore(int index) const;

            /**
             * Returns the number of Unicode code points in the specified text range of this sequence.
             * The text range begins at the specified beginIndex and extends to the char at index endIndex - 1
             *
             * @param beginIndex
             * @param endIndex
             * @return the number of Unicode code points in the specified text range of this sequence
             */
            int codePointCount(int beginIndex, int endIndex) const;

            /**
             * Removes the characters in a substring of this sequence.
             * The substring begins at the specified start and extends to the character at index end - 1 or
             * to the end of the sequence if no such character exists. If start is equal to end, no changes are made.
             *
             * @param start, inclusive
             * @param end, exclusive
             * @throw StringIndexOutOfBound -  if start is negative, greater than length(), or greater than end.
             * @return a reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &deletes(int start, int end);

            /**
             * Removes the char at the specified position in this sequence.
             *
             * @param index
             * @throw StringIndexOutOfBoundsException - if the index is negative or greater than or equal to length().
             * @return a reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &deleteCharAt(int index);

            /**
             * Ensures that the capacity is at least equal to the specified minimum.
             * The new capacity is the larger than the minimumCapacity argument and twice the old capacity plus 2.
             * If minimumCapacity is non-positive or less or equal to this capacity, return
             *
             * @param minimumCapacity
             */
            void ensureCapacity(int minimumCapacity);

            /**
             * Characters are copied from this sequence into the destination character array.
             *
             * @param sourceBegin
             * @param sourceEnd
             * @param destination
             * @param destinationBegin
             * @throw IndexOutOfBoundsException - if :
             * sourceBegin is negative
             * destinationBegin is negative
             * the sourceBegin argument is greater than the sourceEnd argument.
             * sourceEnd is greater than this.length().
             * destinationBegin+sourceEnd-sourceBegin is greater than destination length
             */
            // TODO need arrayCopy
            // void getChars(int sourceBegin, int sourceEnd, string destination, int destinationBegin);

            /**
             * Return the string value of this StringBuffer
             *
             * @return string
             */
            string getValue() const;

            /**
             * Returns the index within this string of the first occurrence of the specified substring.
             * The integer returned is the smallest value
             *
             * @param stringToGetIndex
             * @return the index of the first character of the first such substring is returned;
             * if it does not occur as a substring, -1 is returned.
             */
            int indexOf(String stringToGetIndex) const;

            /**
             * Returns the index within this string of the first occurrence of the specified substring,
             * starting at the specified index. The integer returned is the smallest value
             *
             * @param stringToGetIndex
             * @param fromIndex
             * @return the index within this string of the first occurrence of the specified substring,
             * starting at the specified index. -1 if str is not a substring
             */
            int indexOf(String stringToGetIndex, int fromIndex) const;

            /**
             * Inserts the string representation of the float argument into this sequence.
             * The offset argument must be greater than or equal to 0,
             * and less than or equal to the length of this sequence.
             * @param offset
             * @param floatValue
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &insert(int offset, float floatValue);

            /**
             * Inserts the specified CharSequence into this sequence.
             * The characters of the CharSequence argument are inserted, in order,
             * into this sequence at the indicated offset, moving up any characters originally above that position
             * If charSequence is null, then the four characters "null" are inserted into this sequence.
             *
             * @param offset
             * @param charSequence
             * @throw IndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &insert(int offset, CharSequence *charSequence);

            /**
             * Inserts the string representation of the bool argument into this sequence.
             * The offset argument must be greater than or equal to 0,
             * and less than or equal to the length of this sequence.
             *
             * @param offset
             * @param boolValue
             * @throw IndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &insert(int offset, boolean boolValue);

            /**
             * Inserts the string representation of the char array argument into this sequence.
             * The characters of the array argument are inserted into the contents of this sequence
             * at the position indicated by offset.
             * The length of this sequence increases by the length of the argument.
             *
             * @param offset
             * @param stringToInsert
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &insert(int offset, string stringToInsert);

            /**
             * Inserts the string representation of the char argument into this sequence.
             * The offset argument must be greater than or equal to 0,
             * and less than or equal to the length of this sequence.
             *
             * @param offset
             * @param charValue
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &insert(int offset, char charValue);

            /**
             * Inserts the string into this character sequence.
             * The characters of the String argument are inserted, in order,
             * into this sequence at the indicated offset, moving up any
             * characters originally above that position and increasing
             * the length of this sequence by the length of the argument.
             * If str is null, then the four characters "null" are inserted into this sequence.
             *
             * @param offset
             * @param stringToInsert
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &insert(int offset, String stringToInsert);

            /**
             * Inserts the string representation of the long argument into this sequence.
             * The offset argument must be greater than or equal to 0,
             * and less than or equal to the length of this sequence.
             *
             * @param offset
             * @param longValue
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &insert(int offset, long longValue);

            /**
             * Inserts the string representation of the Object argument into this character sequence.
             * The offset argument must be greater than or equal to 0,
             * and less than or equal to the length of this sequence.
             *
             * @param offset
             * @param object
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &insert(int offset, Object &object);

            /**
             * Inserts the string representation of the int argument into this sequence.
             * The offset argument must be greater than or equal to 0,
             * and less than or equal to the length of this sequence.
             *
             * @param offset
             * @param intValue
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &insert(int offset, int intValue);

            /**
             * Inserts the string representation of the double argument into this sequence.
             * The offset argument must be greater than or equal to 0,
             * and less than or equal to the length of this sequence.
             *
             * @param offset
             * @param doubleValue
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &insert(int offset, double doubleValue);

            /**
             * The subsequence of the argument s specified by start and end are inserted, in order, into this sequence
             * at the specified destination offset, moving up any characters originally above that position.
             * The destinationOffset argument must be greater than or equal to 0, and less than or equal to length
             * The start argument must be nonnegative, and not greater than end.
             * The end argument must be greater than or equal to start, and less than or equal to the length of seq.
             * If s is null, four characters "null" will be inserted
             *
             * @param destinationOffset
             * @param sequence
             * @param start
             * @param end
             * @throw IndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &insert(int destinationOffset, CharSequence &sequence, int start, int end);

            /**
             * Inserts the string representation of a subarray of the str array argument into this sequence.
             * The subarray begins at the specified offset and extends len chars.
             * The subarray is insert at position index
             *
             * @param index
             * @param stringToInsert
             * @param offset
             * @param len
             * @throw StringIndexOutOfBoundsException - if index is negative or greater than length(),
             * or offset or len are negative, or (offset+len) is greater than str.length.
             * @return a reference to this StringBufferUnSafe
             */

            StringBufferUnSafe &insert(int index, string stringToInsert, int offset, int len);

            /**
             * Returns the index within this string of the rightmost occurrence of the specified substring.
             * The rightmost empty string "" is considered to occur at the index value this.length(). T
             * he returned index is the largest value
             * If no such value of stringToGetIndex exists, then -1 is returned.
             *
             * @param stringToGetIndex
             * @return the index within this string of the rightmost occurrence of the specified substring.
             */
            int lastIndexOf(String stringToGetIndex) const;

            /**
             * Returns the index within this string of the last occurrence of the specified substring.
             * The integer returned is the largest value
             * If no such value of stringToGetIndex exists, then -1 is returned.
             *
             * @param stringToGetIndex
             * @param fromIndex
             * @return the index within this string of the rightmost occurrence of
             * the specified substring start fromIndex
             */
            int lastIndexOf(String stringToGetIndex, int fromIndex) const;

            /**
             * Return the current number of used char of this sequence
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
             * @throw IndexOutOfBoundsException
             * @return the index within this sequence
             */
            int offsetByCodePoints(int index, int codePointOffset) const;

            /**
             * Replaces the characters in a substring of this sequence with characters in the specified String.
             * The substring begins at the specified start and extends to the character at index end - 1
             * or to the end of the sequence if no such character exists. First the characters in the substring
             * are removed and then the specified String is inserted at start.
             *
             * @param start
             * @param end
             * @param stringToReplace
             * @throw StringIndexOutOfBoundsException - if start is negative greater than length(), or greater than end.
             * @return a reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &replace(int start, int end, String stringToReplace);

            /**
             * Causes this character sequence to be replaced by the reverse of the sequence.
             * If there are any surrogate pairs included in the sequence,
             * these are treated as single characters for the reverse operation.
             *
             * @return a reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &reverse();

            /**
             * Set the character at the specified index to charValue.
             *
             * @param index
             * @param charValue
             * @throw IndexOutOfBoundsException - if index is negative or greater than or equal to length().
             */
            void setCharAt(int index, char charValue);

            /**
             * Sets the length of the character sequence.
             * The sequence is changed to a new character sequence whose length is specified by the argument.
             *
             * @param newLength
             */
            void setLength(int newLength);

            /**
             * Returns a new character sequence that is a subsequence of this sequence.
             * An invocation of this method of the form
             *
             * @param start
             * @param end
             * @throw IndexOutOfBoundsException - if start or end are negative, if end is greater than length(),
             * or if start is greater than end
             * @return the specified subsequence.
             */
            // CharSequence *subSequence(int start, int end);

            /**
             * Returns a new String that contains a subsequence of characters currently
             * contained in this character sequence. The substring begins at the specified
             * index and extends to the end of this sequence.
             *
             * @param start
             * @throw StringIndexOutOfBoundsException - if start is less than zero,
             * or greater than the length of this object.
             * @return the specified String
             */
            String subString(int start) const;

            /**
             * Returns a new String that contains a subsequence of characters currently contained in this sequence.
             * The substring begins at the specified start and extends to the character at index end - 1.
             *
             * @param start
             * @param end
             * @throw StringIndexOutOfBoundsException - if start or end are negative or greater than length(),
             * or start is greater than end.
             * @return the specified String
             */
            String subString(int start, int end) const;

            /**
             * Returns a string representing the data in this sequence.
             * A new String object is allocated and initialized to contain the character represented by this object.
             *
             * @return a string representing the data in this sequence
             */
            string toString() const override ;

            /**
             * Attempts to reduce storage used for the character sequence.
             * If the buffer is larger than necessary to hold its current sequence of characters,
             * then it may be resized to become more space efficient.
             *
             */
            void trimToSize();

            /**
             * Overload operator =
             * @return a reference to this StringBufferUnSafe
             */
            StringBufferUnSafe &operator=(const StringBufferUnSafe &other);

            /**
             * Destructor, free memory allocated for original
             */
            ~StringBufferUnSafe();
        };

        /**
         * An inheritance class with thread-safe
         */
        class StringBuffer : public StringBufferUnSafe{
        private:
            mutable std::mutex mutex;

        public:
            /**
             * Constructs a string buffer with no characters in it and an initial capacity of 16 characters.
             *
             */
            StringBuffer();

            /**
             * Constructs a string buffer that contains the same characters as the specified CharSequence.
             *
             * @param sequence
             */
            explicit StringBuffer(CharSequence &sequence);

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
             * @param originalString
             */
            explicit StringBuffer(String originalString);

            /**
             * Copy constructor
             *
             * @param other
             */
            StringBuffer(const StringBuffer &other);

            /**
             * Appends the string representation of the Object argument.
             *
             * @param object
             * @return reference to this StringBuffer
             */
            StringBuffer &append(Object &object);

            /**
             * Appends the string representation of the float argument
             *
             * @param floatValue
             * @return reference to this StringBuffer
             */
            StringBuffer &append(float floatValue);

            /**
             * Appends the string representation of the char array argument to this sequence.
             *
             * @param stringToAppend
             * @return reference to this StringBuffer
             */
            StringBuffer &append(string stringToAppend);

            /**
             * Appends the string representation of the boolean argument
             *
             * @param boolValue
             * @return reference to this StringBuffer
             */
            StringBuffer &append(boolean boolValue);

            /**
             * Appends the specified CharSequence to this sequence.
             *
             * @param sequence
             * @return reference to this StringBuffer
             */
            StringBuffer &append(CharSequence &sequence);

            /**
             * Appends the string representation of the double argument
             *
             * @param doubleValue
             * @return reference to this StringBuffer
             */
            StringBuffer &append(double doubleValue);

            /**
             * Appends the string representation of the char argument
             *
             * @param charValue
             * @return reference to this StringBuffer
             */
            StringBuffer &append(char charValue);

            /**
             * Appends the string representation of char array argument to this sequence.
             *
             * @param stringToAppend
             * @return reference to this StringBuffer
             */
            StringBuffer &append(String stringToAppend);

            /**
             * Appends the string representation of the int argument
             *
             * @param intValue
             * @return reference to this StringBuffer
             */
            StringBuffer &append(int intValue);

            /**
             * Appends the string representation of the long argument
             *
             * @param longValue
             * @return reference to this StringBuffer
             */
            StringBuffer &append(long longValue);

            /**
             * Appends the specified StringBuffer to this sequence.
             *
             * @param stringBuffer
             * @return reference to this StringBuffer
             */
            StringBuffer &append(StringBuffer stringBuffer);

            /**
             * Appends the string representation of a subarray of the char array argument to this sequence.
             * Characters of the char array str, starting at index offset, are appended, in order,
             * the length of subarray is equal to len
             *
             * @param stringToAppend
             * @param offset
             * @param len
             * @throw IndexOutOfBoundsException  if offset < 0 or len < 0 or offset+len > str.length
             * @return reference to this StringBuffer
             */
            StringBuffer &append(string stringToAppend, int offset, int len);

            /**
             * Appends a subsequence of the specified CharSequence to this sequence.
             * starting at index start, are appended, in order,
             * to the contents of this sequence up to the (exclusive) index end.
             * If start is negative or bigger than end or bigger than seq's length,
             * throw IndexOutOfBoundException
             *
             * @param sequence
             * @param start
             * @param end
             * @throw IndexOutOfBoundException If start is negative or bigger than end or bigger than seq's length
             * @return reference to this StringBuffer
             */
            StringBuffer &append(CharSequence &sequence, int start, int end);

            /**
             * Appends the string representation of the codePoint argument to this sequence.             *
             *
             * @param codePoint
             * @return reference to this StringBuffer
             */
            StringBuffer &appendCodePoint(int codePoint);

            /**
             * Return current capacity of this StringBuffer
             *
             * @return int
             */
            int capacity() const;

            /**
             * Return character at specified index
             *
             * @param index
             * @throw IndexOutOfBoundsException - if index is negative or greater than or equal to length().
             * @return character at specified index
             */
            char charAt(int index) const;

            // TODO need IntStream
            // IntStream codePoint();

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
             * @return Returns the character (Unicode code point) at the specified index.
             */
            int codePointAt(int index) const;

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
            int codePointBefore(int index) const;

            /**
             * Returns the number of Unicode code points in the specified text range of this sequence.
             * The text range begins at the specified beginIndex and extends to the char at index endIndex - 1
             *
             * @param beginIndex
             * @param endIndex
             * @return the number of Unicode code points in the specified text range of this sequence
             */
            int codePointCount(int beginIndex, int endIndex) const;

            // IntStream codePoint();

            /**
             * Removes the characters in a substring of this sequence.
             * The substring begins at the specified start and extends to the character at index end - 1 or
             * to the end of the sequence if no such character exists. If start is equal to end, no changes are made.
             *
             * @param start, inclusive
             * @param end, exclusive
             * @throw StringIndexOutOfBound -  if start is negative, greater than length(), or greater than end.
             * @return a reference to this StringBuffer
             */
            StringBuffer &deletes(int start, int end);

            /**
             * Removes the char at the specified position in this sequence.
             *
             * @param index
             * @throw StringIndexOutOfBoundsException - if the index is negative or greater than or equal to length().
             * @return a reference to this StringBuffer
             */
            StringBuffer &deleteCharAt(int index);

            /**
             * Ensures that the capacity is at least equal to the specified minimum.
             * The new capacity is the larger than the minimumCapacity argument and twice the old capacity plus 2.
             * If minimumCapacity is non-positive or less or equal to this capacity, return
             *
             * @param minimumCapacity
             */
            void ensureCapacity(int minimumCapacity);

            /**
             * Characters are copied from this sequence into the destination character array.
             *
             * @param sourceBegin
             * @param sourceEnd
             * @param destination
             * @param destinationBegin
             * @throw IndexOutOfBoundsException - if :
             * sourceBegin is negative
             * destinationBegin is negative
             * the sourceBegin argument is greater than the sourceEnd argument.
             * sourceEnd is greater than this.length().
             * destinationBegin+sourceEnd-sourceBegin is greater than destination length
             */
            // TODO need arrayCopy
            // void getChars(int sourceBegin, int sourceEnd, string destination, int destinationBegin);

            /**
             * Return the string value of this StringBuffer
             *
             * @return string
             */
            string getValue() const;

            /**
             * Returns the index within this string of the first occurrence of the specified substring.
             * The integer returned is the smallest value
             *
             * @param stringToGetIndex
             * @return the index of the first character of the first such substring is returned;
             * if it does not occur as a substring, -1 is returned.
             */
            int indexOf(String stringToGetIndex) const;

            /**
             * Returns the index within this string of the first occurrence of the specified substring,
             * starting at the specified index. The integer returned is the smallest value
             *
             * @param stringToGetIndex
             * @param fromIndex
             * @return the index within this string of the first occurrence of the specified substring,
             * starting at the specified index. -1 if str is not a substring
             */
            int indexOf(String stringToGetIndex, int fromIndex) const;

            /**
             * Inserts the string representation of the float argument into this sequence.
             * The offset argument must be greater than or equal to 0,
             * and less than or equal to the length of this sequence.
             *
             * @param offset
             * @param floatValue
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBuffer
             */
            StringBuffer &insert(int offset, float floatValue);

            /**
             * Inserts the specified CharSequence into this sequence.
             * The characters of the CharSequence argument are inserted, in order,
             * into this sequence at the indicated offset, moving up any characters originally above that position
             * If charSequence is null, then the four characters "null" are inserted into this sequence.
             *
             * @param offset
             * @param charSequence
             * @throw IndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBuffer
             */
            StringBuffer &insert(int offset, CharSequence &charSequence);

            /**
             * Inserts the string representation of the bool argument into this sequence.
             * The offset argument must be greater than or equal to 0,
             * and less than or equal to the length of this sequence.
             *
             * @param offset
             * @param boolValue
             * @throw IndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBuffer
             */
            StringBuffer &insert(int offset, boolean boolValue);

            /**
             * Inserts the string representation of the char array argument into this sequence.
             * The characters of the array argument are inserted into the contents of this sequence
             * at the position indicated by offset.
             * The length of this sequence increases by the length of the argument.
             *
             * @param offset
             * @param stringToInsert
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBuffer
             */
            StringBuffer &insert(int offset, string stringToInsert);

            /**
             * Inserts the string representation of the char argument into this sequence.
             * The offset argument must be greater than or equal to 0,
             * and less than or equal to the length of this sequence.
             *
             * @param offset
             * @param charValue
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBuffer
             */
            StringBuffer &insert(int offset, char charValue);

            /**
             * Inserts the string into this character sequence.
             * The characters of the String argument are inserted, in order,
             * into this sequence at the indicated offset, moving up any
             * characters originally above that position and increasing
             * the length of this sequence by the length of the argument.
             * If str is null, then the four characters "null" are inserted into this sequence.
             *
             * @param offset
             * @param stringToInsert
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBuffer
             */
            StringBuffer &insert(int offset, String stringToInsert);

            /**
             * Inserts the string representation of the long argument into this sequence.
             * The offset argument must be greater than or equal to 0,
             * and less than or equal to the length of this sequence.
             *
             * @param offset
             * @param longValue
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBuffer
             */
            StringBuffer &insert(int offset, long longValue);

            /**
             * Inserts the string representation of the Object argument into this character sequence.
             * The offset argument must be greater than or equal to 0,
             * and less than or equal to the length of this sequence.
             *
             * @param offset
             * @param object
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBuffer
             */
            StringBuffer &insert(int offset, Object &object);

            /**
             * Inserts the string representation of the int argument into this sequence.
             * The offset argument must be greater than or equal to 0,
             * and less than or equal to the length of this sequence.
             *
             * @param offset
             * @param intValue
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBuffer
             */
            StringBuffer &insert(int offset, int intValue);

            /**
             * Inserts the string representation of the double argument into this sequence.
             * The offset argument must be greater than or equal to 0,
             * and less than or equal to the length of this sequence.
             *
             * @param offset
             * @param doubleValue
             * @throw StringIndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBuffer
             */
            StringBuffer &insert(int offset, double doubleValue);

            /**
             * The subsequence of the argument s specified by start and end are inserted, in order, into this sequence
             * at the specified destination offset, moving up any characters originally above that position.
             * The destinationOffset argument must be greater than or equal to 0, and less than or equal to length
             * The start argument must be non negative, and not greater than end.
             * The end argument must be greater than or equal to start, and less than or equal to the length of sequence.
             * If sequence is null, four characters "null" will be inserted
             *
             * @param destinationOffset
             * @param sequence
             * @param start
             * @param end
             * @throw IndexOutOfBoundsException - if the offset is invalid.
             * @return a reference to this StringBuffer
             */
            StringBuffer &insert(int destinationOffset, CharSequence &sequence, int start, int end);

            /**
             * Inserts the string representation of a subarray of the str array argument into this sequence.
             * The subarray begins at the specified offset and extends len chars.
             * The subarray is insert at position index
             *
             * @param index
             * @param stringToInsert
             * @param offset
             * @param len
             * @throw StringIndexOutOfBoundsException - if index is negative or greater than length(),
             * or offset or len are negative, or (offset+len) is greater than str.length.
             * @return a reference to this StringBuffer
             */

            StringBuffer &insert(int index, string stringToInsert, int offset, int len);

            /**
             * Returns the index within this string of the rightmost occurrence of the specified substring.
             * The rightmost empty string "" is considered to occur at the index value this.length(). T
             * he returned index is the largest value
             * If no such value of stringToGetIndex exists, then -1 is returned.
             *
             * @param stringToGetIndex
             * @return the index within this string of the rightmost occurrence of the specified substring.
             */
            int lastIndexOf(String stringToGetIndex) const;

            /**
             * Returns the index within this string of the last occurrence of the specified substring.
             * The integer returned is the largest value
             * If no such value exists, then -1 is returned.
             *
             * @param stringToGetIndex
             * @param fromIndex
             * @return the index within this string of the rightmost occurrence of
             * the specified substring start fromIndex
             */
            int lastIndexOf(String stringToGetIndex, int fromIndex) const;

            /**
             * Return the current number of used char of this sequence
             *
             * @return int
             */
            int length() const;

            /**
             * Returns the index within this sequence that is offset from the given index by codePointOffset code points.
             * Unpaired surrogates within the text range given by index and codePointOffset count as one code point each.
             *
             * @param index
             * @param codePointOffset
             * @throw IndexOutOfBoundsException
             * @return the index within this sequence
             */
            int offsetByCodePoints(int index, int codePointOffset) const;

            /**
             * Replaces the characters in a substring of this sequence with characters in the specified String.
             * The substring begins at the specified start and extends to the character at index end - 1
             * or to the end of the sequence if no such character exists. First the characters in the substring
             * are removed and then the specified String is inserted at start.
             *
             * @param start
             * @param end
             * @param stringToReplace
             * @throw StringIndexOutOfBoundsException - if start is negative, greater than length(), or greater than end.
             * @return a reference to this StringBuffer
             */
            StringBuffer &replace(int start, int end, String stringToReplace);

            /**
             * Causes this character sequence to be replaced by the reverse of the sequence.
             * If there are any surrogate pairs included in the sequence,
             * these are treated as single characters for the reverse operation.
             *
             * @return a reference to this StringBuffer
             */
            StringBuffer &reverse();

            /**
             * Set the character at the specified index to charValue.
             *
             * @param index
             * @param charValue
             * @throw IndexOutOfBoundsException - if index is negative or greater than or equal to length().
             */
            void setCharAt(int index, char charValue);

            /**
             * Sets the length of the character sequence.
             * The sequence is changed to a new character sequence whose length is specified by the argument.
             *
             * @param newLength
             */
            void setLength(int newLength);

            /**
             * Returns a new character sequence that is a subsequence of this sequence.
             * An invocation of this method of the form
             *
             * @param start
             * @param end
             * @throw IndexOutOfBoundsException - if start or end are negative, if end is greater than length(),
             * or if start is greater than end
             * @return the specified subsequence.
             */
            // TODO
            // CharSequence *subSequence(int start, int end);

            /**
             * Returns a new String that contains a subsequence of characters currently
             * contained in this character sequence. The substring begins at the specified i
             * ndex and extends to the end of this sequence.
             *
             * @param start
             * @throw StringIndexOutOfBoundsException - if start is less than zero,
             * or greater than the length of this object.
             * @return the specified String
             */
            String subString(int start) const;

            /**
             * Returns a new String that contains a subsequence of characters currently contained in this sequence.
             * The substring begins at the specified start and extends to the character at index end - 1.
             *
             * @param start
             * @param end
             * @throw StringIndexOutOfBoundsException - if start or end are negative or greater than length(),
             * or start is greater than end.
             * @return the specified String
             */
            String subString(int start, int end) const;

            /**
             * Returns a string representing the data in this sequence.
             * A new String object is allocated and initialized to contain the character represented by this object.
             *
             * @return a string representing the data in this sequence
             */
            string toString() const override;

            /**
             * Attempts to reduce storage used for the character sequence.
             * If the buffer is larger than necessary to hold its current sequence of characters, 
             * then it may be resized to become more space efficient.
             *
             */
            void trimToSize();

            /**
             * Overload operator =
             * @return a reference to this StringBufferUnSafe
             */
            StringBuffer &operator=(const StringBuffer &other);

            /**
             * Destructor, free memory allocated for original
             */
            ~StringBuffer();

        };
    }
}


#endif  // NATIVE_STRINGBUFFER_H
