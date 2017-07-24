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

StringBuffer::StringBufferUnSafe::StringBufferUnSafe() : StringBufferUnSafe(16){
}

StringBuffer::StringBufferUnSafe::StringBufferUnSafe(int capacity) {
    if (capacity < 0) {
        throw NegativeArraySizeException("Capacity must be non-negative");
    }
    this->currentCapacity = capacity;
    this->original = (string)(calloc((size_t)(currentCapacity), sizeof(char)));
}

StringBuffer::StringBufferUnSafe::StringBufferUnSafe(String str) {
    this->currentCapacity = str.length() + 16;
    this->original = (string)(calloc((size_t)(currentCapacity), sizeof(char)));
    append(str);
}

StringBuffer::StringBufferUnSafe::StringBufferUnSafe(CharSequence *seq) {
    if (seq == nullptr) {
        this->currentCapacity = 20;
    }
    else {
        this->currentCapacity = seq->length() + 16;
    }
    this->original = (string)(calloc((size_t)(currentCapacity), sizeof(char)));
    append(seq);
}

int StringBuffer::StringBufferUnSafe::capacity() {
    return this->currentCapacity;
}

string StringBuffer::StringBufferUnSafe::getValue() {
    return this->original;
}

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::append(CharSequence *seq) {
    int sequenceLength;
    if (seq == nullptr) {
        sequenceLength = 4;
    }
    else {
        sequenceLength = seq->length();
    }
    return this->append(seq, 0, sequenceLength);
}

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::append(CharSequence *seq, int start, int end) {
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

void StringBuffer::StringBufferUnSafe::ensureCapacity(int minimumCapacity) {
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

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::append(String str) {
    return this->append(str.toString(), 0, str.length());
}

int StringBuffer::StringBufferUnSafe::length() {
    return this->currentLength;
}

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::append(string str, int offset, int len) {
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

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::insert(int index, string str, int offset, int len) {
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

StringBuffer::StringBufferUnSafe::StringBufferUnSafe(const StringBufferUnSafe &other) {
    this->original = (string) calloc((size_t) other.currentCapacity, sizeof(char));
    int index;
    for (index = 0; index < other.currentLength; index++) {
        this->original[index] = other.original[index];
    }
    this->currentLength = other.currentLength;
    this->currentCapacity = other.currentCapacity;
}

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::append(string str) {
    return this->append(str, 0, length_pointer_char(str));
}

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::append(Object *obj) {
    if (obj == nullptr) {
        return this->append((string)"null");    }
    else {
        return this->append(obj->toString());
    }
}

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::append(float floatValue) {
    return this->append(String::valueOf(floatValue).toString());
}

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::append(double doubleValue) {
    return this->append(String::valueOf(doubleValue).toString());
}

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::append(int intValue) {
    return this->append(String::valueOf(intValue).toString());
}

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::append(long longValue) {
    return this->append(String::valueOf(longValue).toString());
}

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::append(boolean boolValue) {
    if (boolValue) {
        return this->append((string)"true");
    }
    else {
        return this->append((string)"false");
    }
}

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::append(char charValue) {
    return this->append(String::valueOf(charValue).toString());
}

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::append(StringBufferUnSafe *stringBuffer) {
    if (stringBuffer == nullptr) {
        return this->append((string)"null");
    }
    else {
        return this->append(stringBuffer->getValue());
    }

}

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::appendCodePoint(int codePoint) {
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

char StringBuffer::StringBufferUnSafe::charAt(int index) {
    if (index < 0) {
        throw IndexOutOfBoundsException("index must be positive");
    }

    if (index >= currentLength) {
        throw IndexOutOfBoundsException();
    }

    return this->original[index];
}

int StringBuffer::StringBufferUnSafe::codePointAt(int index) {
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

int StringBuffer::StringBufferUnSafe::codePointBefore(int index) {
   return codePointAt(index - 2);
}

int StringBuffer::StringBufferUnSafe::codePointCount(int beginIndex, int endIndex) {
    if (beginIndex < 0 || endIndex > currentLength || beginIndex > endIndex) {
        throw IndexOutOfBoundsException();
    }

    int codePointCount = endIndex - beginIndex;
    for (int index = beginIndex; index < endIndex; index++ ) {
        if (Character::isHighSurrogate(this->original[index + 1]) && index < endIndex
            && Character::isLowSurrogate(this->original[index])) {
            codePointCount--;
            index++;
        }
    }
    return codePointCount;
}

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::deletes(int start, int end) {
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

StringBuffer::StringBufferUnSafe StringBuffer::StringBufferUnSafe::deleteCharAt(int index) {
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

void StringBuffer::StringBufferUnSafe::freeMemory() {
    free(this->original);
}

StringBuffer::StringBufferUnSafe::~StringBufferUnSafe() {
    //free(this->original);
}


StringBuffer::StringBuffer() {
    this->stringBufferUnSafe = StringBufferUnSafe();
}

StringBuffer::StringBuffer(CharSequence *seq) {
    this->stringBufferUnSafe = StringBufferUnSafe(seq);
}

StringBuffer::StringBuffer(int capacity) {
    this->stringBufferUnSafe = StringBufferUnSafe(capacity);
}

StringBuffer::StringBuffer(String str) {
    this->stringBufferUnSafe = StringBufferUnSafe(str);
}

StringBuffer::StringBuffer(const StringBuffer &other) {
    this->stringBufferUnSafe = StringBufferUnSafe(other.stringBufferUnSafe);
}

StringBuffer StringBuffer::append(Object *obj) {
    if (obj == nullptr) {
        return this->append((string)"null");    }
    else {
        return this->append(obj->toString());
    }
}

StringBuffer StringBuffer::append(float floatValue) {
    this->stringBufferUnSafe.append(floatValue);
    return *this;
}

StringBuffer StringBuffer::append(string str) {
    this->stringBufferUnSafe.append(str);
    return *this;
}

StringBuffer StringBuffer::append(boolean boolValue) {
    this->stringBufferUnSafe.append(boolValue);
    return *this;
}

StringBuffer StringBuffer::append(CharSequence *seq) {
    this->stringBufferUnSafe.append(seq);
    return *this;
}

StringBuffer StringBuffer::append(double doubleValue) {
    this->stringBufferUnSafe.append(doubleValue);
    return *this;
}

StringBuffer StringBuffer::append(char charValue) {
    this->stringBufferUnSafe.append(charValue);
    return *this;
}

StringBuffer StringBuffer::append(String str) {
    this->stringBufferUnSafe.append(str);
    return *this;
}

StringBuffer StringBuffer::append(int intValue) {
    this->stringBufferUnSafe.append(intValue);
    return *this;
}

StringBuffer StringBuffer::append(long longValue) {
    this->stringBufferUnSafe.append(longValue);
    return *this;
}

StringBuffer StringBuffer::append(string str, int offset, int len) {
    std::lock_guard<std::mutex> guard(mutex);
    this->stringBufferUnSafe.append(str, offset, len);
    return *this;
}

StringBuffer StringBuffer::append(StringBuffer *stringBuffer) {
    if (stringBuffer == nullptr) {
        return this->append((string)"null");
    }
    else {
        return this->append(stringBuffer->getValue());
    }
}

StringBuffer StringBuffer::append(CharSequence *seq, int start, int end) {
    if (seq == nullptr) {
        return this->append((string) "null");
    }
    this->stringBufferUnSafe.append(seq, start, end);
    return *this;
}

StringBuffer StringBuffer::appendCodePoint(int codePoint) {
    std::lock_guard<std::mutex> guard(mutex);
    this->stringBufferUnSafe.appendCodePoint(codePoint);
    return *this;
}

int StringBuffer::capacity() {
    std::lock_guard<std::mutex> guard(mutex);
    return this->stringBufferUnSafe.capacity();
}

char StringBuffer::charAt(int index) {
    std::lock_guard<std::mutex> guard(mutex);
    return this->stringBufferUnSafe.charAt(index);
}

int StringBuffer::codePointAt(int index) {
    std::lock_guard<std::mutex> guard(mutex);
    return this->stringBufferUnSafe.codePointAt(index);
}

int StringBuffer::codePointBefore(int index) {
    std::lock_guard<std::mutex> guard(mutex);
    return this->stringBufferUnSafe.codePointBefore(index);
}

int StringBuffer::codePointCount(int beginIndex, int endIndex) {
    std::lock_guard<std::mutex> guard(mutex);
    return this->stringBufferUnSafe.codePointCount(beginIndex, endIndex);
}

StringBuffer StringBuffer::deletes(int start, int end) {
    std::lock_guard<std::mutex> guard(mutex);
    this->stringBufferUnSafe.deletes(start, end);
    return *this;
}

StringBuffer StringBuffer::deleteCharAt(int index) {
    std::lock_guard<std::mutex> guard(mutex);
    this->stringBufferUnSafe.deleteCharAt(index);
    return *this;
}

void StringBuffer::ensureCapacity(int minimumCapacity) {
    std::lock_guard<std::mutex> guard(mutex);
    this->stringBufferUnSafe.ensureCapacity(minimumCapacity);
}

string StringBuffer::getValue() {
    std::lock_guard<std::mutex> guard(mutex);
    return this->stringBufferUnSafe.getValue();
}

int StringBuffer::length() {
    std::lock_guard<std::mutex> guard(mutex);
    return this->stringBufferUnSafe.length();
}

StringBuffer StringBuffer::insert(int index, string str, int offset, int len) {
    std::lock_guard<std::mutex> guard(mutex);
    this->stringBufferUnSafe.insert(index, str, offset, len);
    return *this;
}

StringBuffer::~StringBuffer() {
    this->stringBufferUnSafe.freeMemory();
}


