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
#include "../IllegalArgumentException/IllegalArgumentException.hpp"

using namespace Java::Lang;

StringBufferUnSafe::StringBufferUnSafe() : StringBufferUnSafe(16) {
}

StringBufferUnSafe::StringBufferUnSafe(int capacity) {
    if (capacity < 0) {
        throw NegativeArraySizeException("Capacity must be non-negative");
    }
    this->currentCapacity = capacity;
    this->original = (string)(calloc((size_t)(currentCapacity), sizeof(char)));
}

StringBufferUnSafe::StringBufferUnSafe(String str) {
    this->currentCapacity = str.length() + 16;
    this->original = (string)(calloc((size_t)(currentCapacity), sizeof(char)));
    append(str);
}

StringBufferUnSafe::StringBufferUnSafe(CharSequence *seq) {
    if (seq == nullptr) {
        this->currentCapacity = 20;
    }
    else {
        this->currentCapacity = seq->length() + 16;
    }
    this->original = (string)(calloc((size_t)(currentCapacity), sizeof(char)));
    append(seq);
}

int StringBufferUnSafe::capacity() {
    return this->currentCapacity;
}

string StringBufferUnSafe::getValue() {
    return this->original;
}

StringBufferUnSafe StringBufferUnSafe::append(CharSequence *seq) {
    int sequenceLength;
    if (seq == nullptr) {
        sequenceLength = 4;
    }
    else {
        sequenceLength = seq->length();
    }
    return this->append(seq, 0, sequenceLength);
}

StringBufferUnSafe StringBufferUnSafe::append(CharSequence *seq, int start, int end) {
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

void StringBufferUnSafe::ensureCapacity(int minimumCapacity) {
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

StringBufferUnSafe StringBufferUnSafe::append(String str) {
    return this->append(str.toString(), 0, str.length());
}

int StringBufferUnSafe::length() {
    return this->currentLength;
}

StringBufferUnSafe StringBufferUnSafe::append(string str, int offset, int len) {
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

StringBufferUnSafe StringBufferUnSafe::insert(int index, string str, int offset, int len) {
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

StringBufferUnSafe::StringBufferUnSafe(const StringBufferUnSafe &other) {
    this->original = (string) calloc((size_t) other.currentCapacity, sizeof(char));
    int index;
    for (index = 0; index < other.currentLength; index++) {
        this->original[index] = other.original[index];
    }
    this->currentLength = other.currentLength;
    this->currentCapacity = other.currentCapacity;
}

StringBufferUnSafe StringBufferUnSafe::append(string str) {
    return this->append(str, 0, length_pointer_char(str));
}

StringBufferUnSafe StringBufferUnSafe::append(Object *obj) {
    if (obj == nullptr) {
        return this->append((string)"null");    }
    else {
        return this->append(obj->toString());
    }
}

StringBufferUnSafe StringBufferUnSafe::append(float floatValue) {
    return this->append(String::valueOf(floatValue).toString());
}

StringBufferUnSafe StringBufferUnSafe::append(double doubleValue) {
    return this->append(String::valueOf(doubleValue).toString());
}

StringBufferUnSafe StringBufferUnSafe::append(int intValue) {
    return this->append(String::valueOf(intValue).toString());
}

StringBufferUnSafe StringBufferUnSafe::append(long longValue) {
    return this->append(String::valueOf(longValue).toString());
}

StringBufferUnSafe StringBufferUnSafe::append(boolean boolValue) {
    if (boolValue) {
        return this->append((string)"true");
    }
    else {
        return this->append((string)"false");
    }
}

StringBufferUnSafe StringBufferUnSafe::append(char charValue) {
    return this->append(String::valueOf(charValue).toString());
}

StringBufferUnSafe StringBufferUnSafe::append(StringBufferUnSafe *stringBuffer) {
    if (stringBuffer == nullptr) {
        return this->append((string)"null");
    }
    else {
        return this->append(stringBuffer->getValue());
    }

}

StringBufferUnSafe StringBufferUnSafe::appendCodePoint(int codePoint) {
    int plane = ((unsigned) codePoint) >> 16;
    boolean isBmpCodePoint = (plane == 0);
    boolean isValidCodePoint = (plane < (((unsigned) (0X10FFFF + 1)) >> 16));

    if (isBmpCodePoint) {
        this->append((char) codePoint);
    }
    else if (isValidCodePoint) {
        unicode MIN_HIGH_SURROGATE = (unicode) '\u000D800';
        unsigned int MIN_SUPPLEMENTARY_CODE_POINT = 0x010000;
        unicode MIN_LOW_SURROGATE = (unicode) '\u000DC00';

        char lowSurrogate = (char) ((codePoint & 0x3ff) + MIN_LOW_SURROGATE);
        char highSurrogate = (char) ((((unsigned)codePoint) >> 10) + (MIN_HIGH_SURROGATE - (MIN_SUPPLEMENTARY_CODE_POINT >> 10)));
        this->append(highSurrogate);
        this->append(lowSurrogate);
    }
    else {
        throw IllegalArgumentException();
    }
    return *this;
}

char StringBufferUnSafe::charAt(int index) {
    if (index < 0) {
        throw IndexOutOfBoundsException("index must be positive");
    }

    if (index >= currentLength) {
        throw IndexOutOfBoundsException();
    }

    return this->original[index];
}

int StringBufferUnSafe::codePointAt(int index) {
    if (index < 0) {
        throw IndexOutOfBoundsException("index must be positive");
    }

    if (index >= currentLength) {
        throw IndexOutOfBoundsException();
    }

    char charAtIndex = this->original[index];
    int followingIndex = index + 1;
    if (Character::isHighSurrogate(charAtIndex) && (followingIndex < currentLength)) {
        char charAtFollowingIndex = this->original[followingIndex];
        if (Character::isLowSurrogate(charAtFollowingIndex)) {
            return Character::toCodePoint(charAtIndex, charAtFollowingIndex);
        }
    }
    return charAtIndex;
}

int StringBufferUnSafe::codePointBefore(int index) {
   return codePointAt(index - 2);
}

int StringBufferUnSafe::codePointCount(int beginIndex, int endIndex) {
    if (beginIndex < 0 || endIndex > currentLength || beginIndex > endIndex) {
        throw IndexOutOfBoundsException();
    }

    int codePointCount = endIndex - beginIndex;
    for (int index = beginIndex; index < endIndex; index++) {
        if (Character::isHighSurrogate(this->original[index + 1]) && index < endIndex
            && Character::isLowSurrogate(this->original[index])) {
            codePointCount--;
            index++;
        }
    }
    return codePointCount;
}

StringBufferUnSafe StringBufferUnSafe::deletes(int start, int end) {
    if (start < 0) {
        throw IndexOutOfBoundsException("index must be positive");

    }

    if (start > end || start > this->currentLength) {
        throw IndexOutOfBoundsException();
    }

    if (start == end || start == currentLength) {
        return *this;
    }

    char *fromPosition;
    int memorySizeToMove;

    if (end > this->currentLength) {
        fromPosition = this->original + this-> currentLength;
        memorySizeToMove = this->currentLength * sizeof(char);
        this->currentLength = start;
    }
    else {
        fromPosition = this->original + end;
        memorySizeToMove = (this->currentLength - start) * sizeof(char);
        this->currentLength -= (end - start);
    }
    char *toPosition = this->original + start;
    memmove(toPosition, fromPosition, (size_t) memorySizeToMove);
    return *this;
}

StringBufferUnSafe StringBufferUnSafe::deleteCharAt(int index) {
    if (index < 0) {
        throw IndexOutOfBoundsException("index must be positive");
    }

    if (index >= currentLength) {
        throw IndexOutOfBoundsException();
    }

    // move block of memory from index + 1 to index
    char *fromPosition = this->original + index + 1;
    char *toPosition = this->original + index;
    int memorySizeToMove = (this->currentLength - index) * sizeof(char);
    memmove(toPosition, fromPosition, (size_t) memorySizeToMove);
    this->currentLength--;
    return *this;
}

StringBufferUnSafe::~StringBufferUnSafe() {
    free(this->original);
}

StringBuffer::StringBuffer() : StringBufferUnSafe() {

}

StringBuffer::StringBuffer(CharSequence *seq) : StringBufferUnSafe(seq) {

}

StringBuffer::StringBuffer(int capacity) : StringBufferUnSafe(capacity) {

}

StringBuffer::StringBuffer(String str) : StringBufferUnSafe(str) {

}

StringBuffer::StringBuffer(const StringBuffer &other) {

}

StringBuffer StringBuffer::append(Object *obj) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::append(obj);
    return *this;
}

StringBuffer StringBuffer::append(float floatValue) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::append(floatValue);
    return *this;
}

StringBuffer StringBuffer::append(string str) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::append(str);
    return *this;
}

StringBuffer StringBuffer::append(boolean boolValue) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::append(boolValue);
    return *this;
}

StringBuffer StringBuffer::append(CharSequence *seq) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::append(seq);
    return *this;
}

StringBuffer StringBuffer::append(char charValue) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::append(charValue);
    return *this;
}

StringBuffer StringBuffer::append(String str) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::append(str);
    return *this;
}

StringBuffer StringBuffer::append(int intValue) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::append(intValue);
    return *this;}

StringBuffer StringBuffer::append(long longValue) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::append(longValue);
    return *this;}

StringBuffer StringBuffer::append(string str, int offset, int len) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::append(str, offset, len);
    return *this;
}

StringBuffer StringBuffer::append(CharSequence *seq, int start, int end) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::append(seq, start, end);
    return *this;}

StringBuffer StringBuffer::appendCodePoint(int codePoint) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::appendCodePoint(codePoint);
    return *this;
}

StringBuffer StringBuffer::append(StringBuffer *stringBuffer) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::append(stringBuffer);
    return *this;
}

int StringBuffer::capacity() {
    std::lock_guard<std::mutex> guard(mutex);
    return StringBufferUnSafe::capacity();
}

char StringBuffer::charAt(int index) {
    std::lock_guard<std::mutex> guard(mutex);
    return StringBufferUnSafe::charAt(index);
}

int StringBuffer::codePointAt(int index) {
    std::lock_guard<std::mutex> guard(mutex);
    return StringBufferUnSafe::codePointAt(index);
}

int StringBuffer::codePointBefore(int index) {
    std::lock_guard<std::mutex> guard(mutex);
    return StringBufferUnSafe::codePointBefore(index);
}

int StringBuffer::codePointCount(int beginIndex, int endIndex) {
    std::lock_guard<std::mutex> guard(mutex);
    return StringBufferUnSafe::codePointCount(beginIndex, endIndex);
}

StringBuffer StringBuffer::deletes(int start, int end) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::deletes(start, end);
    return *this;
}

void StringBuffer::ensureCapacity(int minimumCapacity) {
    StringBufferUnSafe::ensureCapacity(minimumCapacity);
}

string StringBuffer::getValue() {
    return StringBufferUnSafe::getValue();
}

StringBuffer StringBuffer::insert(int index, string str, int offset, int len) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::insert(index, str, offset, len);
    return *this;
}

StringBuffer StringBuffer::append(double doubleValue) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::append(doubleValue);
    return *this;
}

StringBuffer StringBuffer::deleteCharAt(int index) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::deleteCharAt(index);
    return *this;
}

int StringBuffer::length() {
    return StringBufferUnSafe::length();
}

StringBuffer::~StringBuffer() {

}
