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
#include "StringBuffer.hpp"
#include "../StringIndexOutOfBoundsException/StringIndexOutOfBoundsException.hpp"
#include "../NegativeArraySizeException/NegativeArraySizeException.hpp"

using namespace Java::Lang;

/**
 * Constructs a string buffer with no characters in it and an initial capacity of 16 characters.
 *
 */
StringBuffer::StringBuffer() : StringBuffer(16){
}

/**
 * Constructs a string buffer with no characters in it and the specified initial capacity.
 *
 * @param capacity
 * @throw NegativeArraySizeException if capacity is negative
 */
StringBuffer::StringBuffer(int capacity) {
    if (capacity < 0) {
        throw NegativeArraySizeException("Capacity must be non-negative");
    }

    this->currentCapacity = capacity;
    this->original = (string)(calloc((size_t)(currentCapacity), sizeof(char)));
}

/**
 * Constructs a string buffer initialized to the contents of the specified string.
 *
 * @param str
 */
StringBuffer::StringBuffer(String str) {
    this->currentCapacity = str.length() + 16;
    this->original = (string)(calloc((size_t)(currentCapacity), sizeof(char)));
    append(str);
}

/**
 * Constructs a string buffer that contains the same characters as the specified CharSequence.
 *
 * @param seq
 */
StringBuffer::StringBuffer(CharSequence *seq) {
    if (seq == nullptr) {
        this->currentCapacity = 20;
    }
    else {
        this->currentCapacity = seq->length() + 16;
    }
    this->original = (string)(calloc((size_t)(currentCapacity), sizeof(char)));
    append(seq);
}

/**
 * Return current capacity of this StringBuffer
 *
 * @return int
 */
int StringBuffer::capacity() {
    return this->currentCapacity;
}

/**
 * Return the string value of this StringBuffer
 *
 * @return string
 */
string StringBuffer::getValue() {
    return this->original;
}

/**
 * Appends the specified CharSequence to this sequence.
 *
 * @param seq
 * @return reference to this StringBuffer
 */
StringBuffer StringBuffer::append(CharSequence *seq) {
    int sequenceLength;
    if (seq == nullptr) {
        sequenceLength = 4;
    }
    else {
        sequenceLength = seq->length();
    }
    return this->append(seq, 0, sequenceLength);
}

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
StringBuffer StringBuffer::append(CharSequence *seq, int start, int end) {
    if (seq == nullptr) {
        return this->append((string) "null");
    }
    else {
        if (start < 0 || start > end || start > seq->length()) {
            throw IndexOutOfBoundsException();
        }
        return append(seq->toString(), start, end - start);
    }
}

/**
 * Ensures that the capacity is at least equal to the specified minimum.
 * The new capacity is the larger than the minimumCapacity argument and twice the old capacity plus 2.
 * If minimumCapacity is non-positive or less or equal to this capacity, return
 *
 * @param minimumCapacity
 */
void StringBuffer::ensureCapacity(int minimumCapacity) {
    if (minimumCapacity <= 0) {
        return;
    }

    if (minimumCapacity <= capacity()) {
        return;
    }

    int newCapacity = 0;
    do {
        newCapacity = capacity() * 2 + 2;
        this->currentCapacity = newCapacity;
    } while (newCapacity < minimumCapacity);

    int newSize = newCapacity * sizeof(char);
    this->original = (string)(realloc(this->original, (size_t)(newSize)));
}

/**
 * Destructor, free memory alocated for original
 */
StringBuffer::~StringBuffer() {
    free(this->original);
}

/**
 * Appends the string representation of char array argument to this sequence.
 *
 * @param str
 * @return reference to this StringBuffer
 */
StringBuffer StringBuffer::append(String str) {
    return this->append(str.toString(), 0, str.length());
}

/**
 * Return the current munber of used char of this sequence
 *
 * @return int
 */
int StringBuffer::length() {
    return this->currentLength;
}

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
StringBuffer StringBuffer::append(string str, int offset, int len) {
    if (offset < 0 || len < 0 || (offset + len) > length_pointer_char(str)) {
        throw IndexOutOfBoundsException();
    }

    ensureCapacity(this->length() + length_pointer_char(str));
    std::string string(this->original);
    std::string stringToAdd(str);
    stringToAdd = stringToAdd.substr(offset, len);
    string.append(stringToAdd);
    strcpy(this->original, string.c_str());
    this->currentLength += len;
    return *this;
}

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
StringBuffer StringBuffer::insert(int index, string str, int offset, int len) {
    if (index < 0 || index > length() || offset < 0
        || len < 0 || (offset + len) > length_pointer_char(str)) {
        throw StringIndexOutOfBoundsException();
    }

    ensureCapacity(this->length() + length_pointer_char(str));
    std::string string(this->original);
    string.insert(index, str, offset, len);
    strcpy(this->original, string.c_str());
    this->currentLength += len;
    return *this;
}

/**
 * Copy constructor
 *
 * @param other
 */
StringBuffer::StringBuffer(const StringBuffer &other) {
    this->original = (string) calloc((size_t) other.currentCapacity, sizeof(char));
    int index;
    for (index = 0; index < other.currentLength; index++) {
        this->original[index] = other.original[index];
    }
    this->currentLength = other.currentLength;
    this->currentCapacity = other.currentCapacity;
}

/**
 * Appends the string representation of the char array argument to this sequence.
 *
 * @param str
 * @return reference to this StringBuffer
 */
StringBuffer StringBuffer::append(string str) {
    return this->append(str, 0, length_pointer_char(str));
}

/**
 * Appends the string representation of the Object argument.
 *
 * @param obj
 * @return reference to this StringBuffer
 */
StringBuffer StringBuffer::append(Object *obj) {
    if (obj == nullptr) {
        return this->append((string)"null");    }
    else {
        return this->append(obj->toString());
    }
}

/**
 * Appends the string representation of the float argument
 *
 * @param floatValue
 * @return reference to this StringBuffer
 */
StringBuffer StringBuffer::append(float floatValue) {
    return this->append(String::valueOf(floatValue).toString());
}

/**
 * Appends the string representation of the double argument
 *
 * @param doubleValue
 * @return reference to this StringBuffer
 */
StringBuffer StringBuffer::append(double doubleValue) {
    return this->append(String::valueOf(doubleValue).toString());
}

/**
 * Appends the string representation of the int argument
 *
 * @param intValue
 * @return reference to this StringBuffer
 */
StringBuffer StringBuffer::append(int intValue) {
    return this->append(String::valueOf(intValue).toString());
}

/**
 * Appends the string representation of the long argument
 *
 * @param longValue
 * @return reference to this StringBuffer
 */
StringBuffer StringBuffer::append(long longValue) {
    return this->append(String::valueOf(longValue).toString());
}

/**
 * Appends the string representation of the boolean argument
 *
 * @param boolValue
 * @return reference to this StringBuffer
 */
StringBuffer StringBuffer::append(boolean boolValue) {
    if (boolValue) {
        return this->append((string)"true");
    }
    else {
        return this->append((string)"false");
    }
}

/**
 * Appends the string representation of the char argument
 *
 * @param charValue
 * @return reference to this StringBuffer
 */
StringBuffer StringBuffer::append(char charValue) {
    return this->append(String::valueOf(charValue).toString());
}

/**
 * Appends the specified StringBuffer to this sequence.
 *
 * @param stringBuffer
 * @return reference to this StringBuffer
 */
StringBuffer StringBuffer::append(StringBuffer *stringBuffer) {
    if (stringBuffer == nullptr) {
        return this->append((string)"null");
    }
    else {
        return this->append(stringBuffer->getValue());
    }

}





