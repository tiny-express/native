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
    } else {
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
    } else {
        sequenceLength = seq->length();
    }

    return this->append(seq, 0, sequenceLength);
}

StringBufferUnSafe StringBufferUnSafe::append(CharSequence *seq, int start, int end) {
    if (seq == nullptr) {
        return this->append((string) "null");
    }

    if (start < 0 || start > end || start > seq->length()) {
        throw IndexOutOfBoundsException();
    }

    return append(seq->toString(), start, end - start);
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
        return this->append((string)"null");
    }

    return this->append(obj->toString());
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

    return this->append((string)"false");
}

StringBufferUnSafe StringBufferUnSafe::append(char charValue) {
    return this->append(String::valueOf(charValue).toString());
}

StringBufferUnSafe StringBufferUnSafe::append(StringBufferUnSafe *stringBuffer) {
    if (stringBuffer == nullptr) {
        return this->append((string)"null");
    }

    return this->append(stringBuffer->getValue());
}

StringBufferUnSafe StringBufferUnSafe::appendCodePoint(int codePoint) {
    int plane = ((unsigned) codePoint) >> 16;
    boolean isBmpCodePoint = (plane == 0);
    boolean isValidCodePoint = (plane < (((unsigned) (0X10FFFF + 1)) >> 16));

    if (isBmpCodePoint) {
        this->append((char) codePoint);
    } else if (isValidCodePoint) {
        unicode MIN_HIGH_SURROGATE = (unicode) '\u000D800';
        unsigned int MIN_SUPPLEMENTARY_CODE_POINT = 0x010000;
        unicode MIN_LOW_SURROGATE = (unicode) '\u000DC00';

        char lowSurrogate = (char) ((codePoint & 0x3ff) + MIN_LOW_SURROGATE);
        char highSurrogate = (char) ((((unsigned)codePoint) >> 10) + (MIN_HIGH_SURROGATE - (MIN_SUPPLEMENTARY_CODE_POINT >> 10)));
        this->append(highSurrogate);
        this->append(lowSurrogate);
    } else {
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
        throw StringIndexOutOfBoundsException("index must be positive");
    }

    if (start > end || start > this->currentLength) {
        throw StringIndexOutOfBoundsException();
    }

    if (start == end || start == currentLength) {
        return *this;
    }

    string fromPosition;
    int memorySizeToMove;

    if (end > this->currentLength) {
        fromPosition = this->original + this-> currentLength;
        memorySizeToMove = this->currentLength * sizeof(char);
        this->currentLength = start;
    } else {
        fromPosition = this->original + end;
        memorySizeToMove = (this->currentLength - start) * sizeof(char);
        this->currentLength -= (end - start);
    }

    string toPosition = this->original + start;
    memmove(toPosition, fromPosition, (size_t) memorySizeToMove);
    return *this;
}

StringBufferUnSafe StringBufferUnSafe::deleteCharAt(int index) {
    if (index < 0) {
        throw StringIndexOutOfBoundsException("index must be positive");
    }

    if (index >= currentLength) {
        throw StringIndexOutOfBoundsException();
    }

    // move block of memory from index + 1 to index
    string fromPosition = this->original + index + 1;
    string toPosition = this->original + index;
    int memorySizeToMove = (this->currentLength - index) * sizeof(char);
    memmove(toPosition, fromPosition, (size_t) memorySizeToMove);
    this->currentLength--;
    return *this;
}

StringBufferUnSafe::~StringBufferUnSafe() {
    free(this->original);
}

void StringBufferUnSafe::getChars(int sourceBegin, int sourceEnd, string destination, int destinationBegin) {
    if (sourceBegin < 0 || destinationBegin < 0 || sourceBegin > sourceEnd
        || (destinationBegin + sourceEnd - sourceEnd) > this->currentLength
        || sourceEnd > this->currentLength ) {

        throw IndexOutOfBoundsException();
    }
     // TODO need arrayCopy
}

int StringBufferUnSafe::indexOf(String str) {
    return string_index(this->original, str.toString(), 1);
}

int StringBufferUnSafe::indexOf(String str, int fromIndex) {
    int time = 0;
    int indexOfString = 0;
    do {
        time++;
        indexOfString = string_index(this->original, str.toString(), time);
    } while (indexOfString < fromIndex && indexOfString != -1);

    return indexOfString;
}

StringBufferUnSafe StringBufferUnSafe::insert(int offset, float floatValue) {
    int valueLength = String::valueOf(floatValue).length();
    return this->insert(offset, String::valueOf(floatValue).toString(), 0, valueLength);
}

StringBufferUnSafe StringBufferUnSafe::insert(int offset, CharSequence *charSequence) {
    if (offset < 0) {
        throw IndexOutOfBoundsException("offset must be positive");
    }

    if (charSequence == nullptr) {
        return this->insert(offset, const_cast<string>("null"), 0, 4);
    }

    return this->insert(offset, charSequence->toString(), 0, charSequence->length());
}

StringBufferUnSafe StringBufferUnSafe::insert(int offset, boolean boolValue) {
    if (boolValue) {
        return this->insert(offset, const_cast<string>("true"), 0, 4);
    }

    return this->insert(offset, const_cast<string>("false"), 0, 5);
}

StringBufferUnSafe StringBufferUnSafe::insert(int offset, string str) {
    return this->insert(offset, str, 0, length_pointer_char(str));
}

StringBufferUnSafe StringBufferUnSafe::insert(int offset, char charValue) {
    int valueLength = String::valueOf(charValue).length();
    return this->insert(offset, String::valueOf(charValue).toString(), 0, valueLength);
}

StringBufferUnSafe StringBufferUnSafe::insert(int offset, String str) {
    return this->insert(offset, str.toString(), 0, str.length());
}

StringBufferUnSafe StringBufferUnSafe::insert(int offset, long longValue) {
    int valueLength = String::valueOf(longValue).length();
    return this->insert(offset, String::valueOf(longValue).toString(), 0, valueLength);
}

StringBufferUnSafe StringBufferUnSafe::insert(int offset, Object *obj) {
    if (obj == nullptr) {
        return this->insert(offset, const_cast<string>("null"), 0, 4);
    }

    return this->insert(offset, obj->toString(), 0, length_pointer_char(obj->toString()));
}

StringBufferUnSafe StringBufferUnSafe::insert(int offset, int intValue) {
    int valueLength = String::valueOf(intValue).length();
    return this->insert(offset, String::valueOf(intValue).toString(), 0, valueLength);
}

StringBufferUnSafe StringBufferUnSafe::insert(int offset, double doubleValue) {
    int valueLength = String::valueOf(doubleValue).length();
    return this->insert(offset, String::valueOf(doubleValue).toString(), 0, valueLength);
}

StringBufferUnSafe StringBufferUnSafe::insert(int dstOffset, CharSequence *seq, int start, int end) {

    if (dstOffset < 0) {
        throw IndexOutOfBoundsException("offset must be positive");
    }

    if (seq == nullptr) {
        return this->insert(dstOffset, const_cast<string>("null"), 0, 4);
    }

    if (dstOffset > this->currentLength || start < 0 || end < 0
            || start > end || end > seq->length()) {

        throw IndexOutOfBoundsException();
    }

    return this->insert(dstOffset, seq->toString(), start, end - start);
}

int StringBufferUnSafe::lastIndexOf(String str) {
    int time = 0;
    int index = -1;
    int lastIndex;
    do {
        time++;
        lastIndex = index;
        index = string_index(this->original, str.toString(), time);
    } while (index != -1);
    return lastIndex;
}

int StringBufferUnSafe::lastIndexOf(String str, int fromIndex) {
    int time = 0;
    int index = -1;
    int lastIndex;
    do {
        time++;
        lastIndex = index;
        index = string_index(this->original, str.toString(), time);
    } while (index != -1 && index <= fromIndex);
    return lastIndex;
}

int StringBufferUnSafe::offsetByCodePoints(int index, int codePointOffset) {
    if (index < 0 || index > this->currentLength) {
        throw IndexOutOfBoundsException();
    }
    // TODO need Character::offsetByCodePoints
    // return Character::offsetByCodePoints(this->original, 0, this->currentLength, index, codePointOffset);
    return 0;
}

StringBufferUnSafe StringBufferUnSafe::replace(int start, int end, String str) {
    if (start < 0) {
        throw StringIndexOutOfBoundsException("start must be positive");
    }
    if (start > this->currentLength || start > end) {
        throw StringIndexOutOfBoundsException();
    }

    if (end > this->currentLength) {
        end = this->currentLength;
    }

    int newLength = currentLength + str.length() - end + start;
    ensureCapacity(newLength);
    this->currentLength = newLength;

    string fromPosition = this->original + end;
    string toPosition = this->original + start +str.length();
    int memorySizeToMove = str.length() * sizeof(char);
    memmove(toPosition, fromPosition, static_cast<size_t>(memorySizeToMove));

    string insertPosition = this->original + start;
    memcpy(insertPosition, str.toString(), static_cast<size_t>(memorySizeToMove));

    return *this;
}

StringBufferUnSafe StringBufferUnSafe::reverse() {
    boolean hasSurrogates = false;
    int index;
    int oppositeIndex;
    int stopIndex = this->currentLength / 2;
    char temp;
    for (index = 0; index < stopIndex; index++) {
        oppositeIndex = (this->currentLength - 1) - index;
        temp = this->original[index];
        this->original[index] = this->original[oppositeIndex];
        this->original[oppositeIndex] = temp;
        if (Character::isSurrogate((this->original[index])) || Character::isSurrogate(this->original[oppositeIndex])) {
            hasSurrogates = true;
        }
    }
    if (hasSurrogates) {
        stopIndex = this->currentLength - 1;
        index;
        char ch1;
        char ch2;
        for (index = 0; index < stopIndex; index++) {
            ch2 = this->original[index];
            if (Character::isLowSurrogate(ch2)) {
                ch1 = this->original[index + 1];
                if (Character::isHighSurrogate(ch1)) {
                    this->original[index] = ch1;
                    index = index + 1;
                    this->original[index] = ch2;
                }
            }
        }
    }
    return *this;
}

void StringBufferUnSafe::setCharAt(int index, char charValue) {
    if (index < 0) {
        throw IndexOutOfBoundsException("index must be positive");
    }
    if (index >= this->currentLength) {
        throw IndexOutOfBoundsException();
    }

    this->original[index] = charValue;
}

void StringBufferUnSafe::setLength(int newLength) {
    if (newLength < 0) {
        throw IndexOutOfBoundsException("newLength must be positive");
    }

    int oldLength = this->currentLength;
    if (newLength > this->currentLength) {
        ensureCapacity(newLength);
        for (oldLength; oldLength <= newLength; oldLength++) {
            this->original[oldLength] = '\0';
        }
    } else {
        for (oldLength; oldLength >= newLength; oldLength--) {
            this->original[oldLength] = '\0';
        }
    }
    this->currentLength = newLength;
}

CharSequence *StringBufferUnSafe::subSequence(int start, int end) {
    if (start < 0 || end < 0) {
        throw IndexOutOfBoundsException("start and end must be positive");
    }

    if (start >= this->currentLength || end > this->currentLength || start > end) {
        throw IndexOutOfBoundsException();
    }

    String *result = new String(this->subString(start, end));
    return result;
}

String StringBufferUnSafe::subString(int start) {
    return this->subString(start, this->currentLength);
}

String StringBufferUnSafe::subString(int start, int end) {
    if (start < 0 || end < 0) {
        throw StringIndexOutOfBoundsException("start and end must be positive");
    }

    if (start >= this->currentLength || end > this->currentLength || start > end) {
        throw StringIndexOutOfBoundsException();
    }

    std::string string(this->original);
    string = string.substr(start, end - start);
    String result = String(string.c_str());
    return result;
}

String StringBufferUnSafe::toString() {
    return String(this->original);
}

void StringBufferUnSafe::trimToSize() {
    if (this->currentCapacity > this->currentLength) {
        int newSize = this->currentLength * sizeof(char);
        this->original = (string)realloc(this->original, (size_t)newSize);
        this->currentCapacity = this->currentLength;
    }
}


// StringBuffer
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
    return *this;
}

StringBuffer StringBuffer::append(long longValue) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::append(longValue);
    return *this;
}

StringBuffer StringBuffer::append(string str, int offset, int len) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::append(str, offset, len);
    return *this;
}

StringBuffer StringBuffer::append(CharSequence *seq, int start, int end) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::append(seq, start, end);
    return *this;
}

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

void StringBuffer::getChars(int sourceBegin, int sourceEnd, string destination, int destinationBegin) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::getChars(sourceBegin, sourceEnd, destination, destinationBegin);
}

int StringBuffer::indexOf(String str) {
    std::lock_guard<std::mutex> guard(mutex);
    return StringBufferUnSafe::indexOf(str);
}

int StringBuffer::indexOf(String str, int fromIndex) {
    std::lock_guard<std::mutex> guard(mutex);
    return StringBufferUnSafe::indexOf(str, fromIndex);
}

StringBuffer StringBuffer::insert(int offset, float floatValue) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::insert(offset, floatValue);
    return *this;
}

StringBuffer StringBuffer::insert(int offset, boolean boolValue) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::insert(offset, boolValue);
    return *this;
}

StringBuffer StringBuffer::insert(int offset, string str) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::insert(offset, str);
    return *this;
}

StringBuffer StringBuffer::insert(int offset, char charValue) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::insert(offset, charValue);
    return *this;
}

StringBuffer StringBuffer::insert(int offset, String str) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::insert(offset, str);
    return *this;
}

StringBuffer StringBuffer::insert(int offset, Object *obj) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::insert(offset, obj);
    return *this;
}

StringBuffer StringBuffer::insert(int offset, double doubleValue) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::insert(offset, doubleValue);
    return *this;
}

StringBuffer StringBuffer::insert(int dstOffset, CharSequence *seq, int start, int end) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::insert(dstOffset, seq, start, end);
    return *this;
}

StringBuffer StringBuffer::insert(int offset, long longValue) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::insert(offset, longValue);
    return *this;
}

StringBuffer StringBuffer::insert(int offset, int intValue) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::insert(offset, intValue);
    return *this;
}


StringBuffer StringBuffer::insert(int offset, CharSequence *charSequence) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::insert(offset, charSequence);
    return *this;
}

StringBuffer StringBuffer::insert(int index, string str, int offset, int len) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::insert(index, str, offset, len);
    return *this;
}

int StringBuffer::lastIndexOf(String str) {
    std::lock_guard<std::mutex> guard(mutex);
    return StringBufferUnSafe::lastIndexOf(str);
}

int StringBuffer::lastIndexOf(String str, int fromIndex) {
    std::lock_guard<std::mutex> guard(mutex);
    return StringBufferUnSafe::lastIndexOf(str, fromIndex);
}

int StringBuffer::offsetByCodePoints(int index, int codePointOffset) {
    std::lock_guard<std::mutex> guard(mutex);
    return StringBufferUnSafe::offsetByCodePoints(index, codePointOffset);
}

StringBuffer StringBuffer::replace(int start, int end, String str) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::replace(start, end, str);
    return *this;
}

StringBuffer StringBuffer::reverse() {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::reverse();
    return *this;
}

void StringBuffer::setCharAt(int index, char charValue) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::setCharAt(index, charValue);
}

void StringBuffer::setLength(int newLength) {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::setLength(newLength);
}

CharSequence *StringBuffer::subSequence(int start, int end) {
    std::lock_guard<std::mutex> guard(mutex);
    return StringBufferUnSafe::subSequence(start, end);
}

String StringBuffer::subString(int start) {
    std::lock_guard<std::mutex> guard(mutex);
    return StringBufferUnSafe::subString(start);
}

String StringBuffer::subString(int start, int end) {
    std::lock_guard<std::mutex> guard(mutex);
    return StringBufferUnSafe::subString(start, end);
}

String StringBuffer::toString() {
    std::lock_guard<std::mutex> guard(mutex);
    return StringBufferUnSafe::toString();
}

void StringBuffer::trimToSize() {
    std::lock_guard<std::mutex> guard(mutex);
    StringBufferUnSafe::trimToSize();
}
