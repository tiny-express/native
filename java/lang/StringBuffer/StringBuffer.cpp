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
#include "StringBuffer.hpp"
#include "../StringIndexOutOfBoundsException/StringIndexOutOfBoundsException.hpp"
#include "../NegativeArraySizeException/NegativeArraySizeException.hpp"

using namespace Java::Lang;

StringBufferUnSafe::StringBufferUnSafe() : StringBufferUnSafe(
        DEFAULT_CAPACITY) {
}

StringBufferUnSafe::StringBufferUnSafe(long int capacity) {
    if (capacity < 0) {
        throw NegativeArraySizeException("Capacity must be non-negative");
    }

    this->currentCapacity = capacity;
    this->original = (string) calloc((size_t) this->currentCapacity,
                                     sizeof(char));
}

StringBufferUnSafe::StringBufferUnSafe(String originalString) {
    this->currentCapacity = originalString.length() + DEFAULT_CAPACITY;
    this->original = (string) calloc((size_t) this->currentCapacity,
                                     sizeof(char));
    this->append(originalString);
}

StringBufferUnSafe::StringBufferUnSafe(CharSequence &sequence) {
    if (&sequence == nullptr) {
        this->currentCapacity = DEFAULT_CAPACITY + 4;
    } else {
        this->currentCapacity = sequence.length() + DEFAULT_CAPACITY;
    }

    this->original = (string) calloc((size_t) this->currentCapacity,
                                     sizeof(char));
    this->append(sequence);
}

long int StringBufferUnSafe::capacity() const {
    return this->currentCapacity;
}

string StringBufferUnSafe::getValue() const {
    return this->original;
}

StringBufferUnSafe &StringBufferUnSafe::append(CharSequence &sequence) {
    if (&sequence == nullptr) {
        return this->append(sequence, 0, 4);
    }
    return this->append(sequence, 0, sequence.length());
}

StringBufferUnSafe &
StringBufferUnSafe::append(CharSequence &sequence, long int start, long int end) {
    if (&sequence == nullptr) {
        return this->append((string) "null", 0, 4);
    }

    if (start < 0 || start > end || start > sequence.length()) {
        throw IndexOutOfBoundsException();
    }

    return this->append(sequence.toString(), start, end - start);
}

void StringBufferUnSafe::ensureCapacity(long int minimumCapacity) {
    if (minimumCapacity <= 0) {
        return;
    }

    if (minimumCapacity <= capacity()) {
        return;
    }

    long int newCapacity = 0;
    do {
        newCapacity = capacity() * 2 + 2;
        this->currentCapacity = newCapacity;
    } while (newCapacity < minimumCapacity);

    long int newSize = newCapacity * sizeof(char);
    this->original = (string) allocateMemory(this->original, (size_t) newSize);
}

StringBufferUnSafe &StringBufferUnSafe::append(String stringToAppend) {
    return this->append(stringToAppend.toString(), 0, stringToAppend.length());
}

long int StringBufferUnSafe::length() const {
    return this->currentLength;
}

StringBufferUnSafe &
StringBufferUnSafe::append(String stringToAppend, long int offset, long int len) {
    if (offset < 0 || len < 0 || (offset + len) > stringToAppend.length()) {
        throw IndexOutOfBoundsException();
    }

    this->ensureCapacity(this->length() + len);
    string appendPosition = this->original + this->currentLength;
    string startIndex = stringToAppend.toCharPointer() + offset;
    long int memorySizeToMove = len * sizeof(char);
    memmove(appendPosition, startIndex, (size_t) memorySizeToMove);
    this->currentLength += len;
    return *this;
}

StringBufferUnSafe &
StringBufferUnSafe::insert(long int index, String stringToInsert, long int offset,
                           long int len) {
    if (index < 0 || index > length() || offset < 0
        || len < 0 || (offset + len) > stringToInsert.length()) {
        throw StringIndexOutOfBoundsException();
    }

    this->ensureCapacity(this->length() + len);
    string insertPosition = this->original + index;
    string newTailStart = this->original + index + len;
    long int memorySizeToMove = (this->currentLength - index) * sizeof(char);
    memmove(newTailStart, insertPosition, (size_t) memorySizeToMove);
    string startIndex = stringToInsert.toCharPointer() + offset;
    long int memorySizeToInsert = len * sizeof(char);
    memmove(insertPosition, startIndex, (size_t) memorySizeToInsert);
    this->currentLength += len;
    return *this;
}

StringBufferUnSafe::StringBufferUnSafe(const StringBufferUnSafe &other) {
    this->original = (string) calloc((size_t) other.currentCapacity,
                                     sizeof(char));
    long int index;
    for (index = 0; index < other.currentLength; index++) {
        this->original[index] = other.original[index];
    }
    this->currentLength = other.currentLength;
    this->currentCapacity = other.currentCapacity;
}

StringBufferUnSafe &StringBufferUnSafe::append(string stringToAppend) {
    return this->append(stringToAppend, 0, lengthPointerChar(stringToAppend));
}

//StringBufferUnSafe &StringBufferUnSafe::append(Object *object) {
//	if (object == nullptr) {
//		return this->append((string) "null", 0, 4);
//	}
//
//	return this->append(object->toString());
//}

StringBufferUnSafe &StringBufferUnSafe::append(float floatValue) {
    return this->append(String::valueOf(floatValue).toString());
}

StringBufferUnSafe &StringBufferUnSafe::append(double doubleValue) {
    return this->append(String::valueOf(doubleValue).toString());
}

StringBufferUnSafe &StringBufferUnSafe::append(long int intValue) {
    return this->append(String::valueOf(intValue).toString());
}

StringBufferUnSafe &StringBufferUnSafe::append(longValue) {
    return this->append(String::valueOf(longValue).toString());
}

StringBufferUnSafe &StringBufferUnSafe::append(boolean boolValue) {
    if (boolValue) {
        return this->append((string) "true", 0, 4);
    }

    return this->append((string) "false", 0, 5);
}

StringBufferUnSafe &StringBufferUnSafe::append(char charValue) {
    return this->append(String::valueOf(charValue).toString());
}

StringBufferUnSafe &
StringBufferUnSafe::append(StringBufferUnSafe stringBufferUnSafe) {
    return this->append(stringBufferUnSafe.getValue());
}

StringBufferUnSafe &StringBufferUnSafe::appendCodePoint(long int codePoint) {
    long int unicodePlane = ((unsigned) codePoint) >> 16;
    boolean isBmpCodePolong int = (unicodePlane == 0);
    boolean isValidCodePolong int = (unicodePlane <
                                (((unsigned) (0X10FFFF + 1)) >> 16));

    if (isBmpCodePoint) {
        return this->append((char) codePoint);
    }
    if (isValidCodePoint) {
        long int MIN_HIGH_SURROGATE = 0xD800;
        unsigned long int MIN_SUPPLEMENTARY_CODE_POINT = 0x010000;
        long int MIN_LOW_SURROGATE = 0xDC00;

        auto lowSurrogate = (char) ((codePolong int & 0x3ff) + MIN_LOW_SURROGATE);
        auto highSurrogate = (char) ((((unsigned) codePoint) >> 10)
                                     + (MIN_HIGH_SURROGATE -
                                        (MIN_SUPPLEMENTARY_CODE_POINT >> 10)));
        this->append(highSurrogate);
        this->append(lowSurrogate);
        return *this;
    }

    throw InterruptedException();
}

char StringBufferUnSafe::charAt(long int index) const {
    if (index < 0) {
        throw IndexOutOfBoundsException("index must be positive");
    }

    if (index >= this->currentLength) {
        throw IndexOutOfBoundsException();
    }

    return this->original[index];
}

long int StringBufferUnSafe::codePointAt(long int index) const {
    if (index < 0) {
        throw IndexOutOfBoundsException("index must be positive");
    }

    if (index >= this->currentLength) {
        throw IndexOutOfBoundsException();
    }

    char charAtIndex = this->original[index];
    long int followingIndex = index + 1;
    if (Character::isHighSurrogate(charAtIndex) &&
        (followingIndex < this->currentLength)) {
        char charAtFollowingIndex = this->original[followingIndex];
        if (Character::isLowSurrogate(charAtFollowingIndex)) {
            return Character::toCodePoint(charAtIndex, charAtFollowingIndex);
        }
    }

    return charAtIndex;
}

long int StringBufferUnSafe::codePointBefore(long int index) const {
    if (index < 0 || index == 0) {
        throw IndexOutOfBoundsException("index must be positive");
    }
    if (index > this->currentLength) {
        throw IndexOutOfBoundsException();
    }
    char charAtPreviousIndex = this->original[index - 1];
    if (Character::isLowSurrogate(charAtPreviousIndex) && (index > 1)) {
        char charAtTwoBeforeIndex = this->original[index - 2];
        if (Character::isLowSurrogate(charAtTwoBeforeIndex)) {
            return Character::toCodePoint(charAtTwoBeforeIndex,
                                          charAtPreviousIndex);
        }
    }
    return charAtPreviousIndex;
}

long int StringBufferUnSafe::codePointCount(long int beginIndex, long int endIndex) const {
    if (beginIndex < 0 || endIndex > this->currentLength ||
        beginIndex > endIndex) {
        throw IndexOutOfBoundsException();
    }

    long int codePointCount = endIndex - beginIndex;
    for (beginIndex; beginIndex < endIndex; beginIndex++) {
        if (Character::isHighSurrogate(this->original[beginIndex + 1]) &&
            beginIndex < endIndex
            && Character::isLowSurrogate(this->original[beginIndex])) {
            codePointCount--;
            beginIndex++;
        }
    }

    return codePointCount;
}

StringBufferUnSafe &StringBufferUnSafe::deletes(long int start, long int end) {
    if (start < 0) {
        throw StringIndexOutOfBoundsException("index must be positive");
    }

    if (start > end || start > this->currentLength) {
        throw StringIndexOutOfBoundsException();
    }

    if (start == end || start == this->currentLength) {
        return *this;
    }

    string fromPosition;
    long int memorySizeToMove;

    if (end > this->currentLength) {
        fromPosition = this->original + this->currentLength;
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

StringBufferUnSafe &StringBufferUnSafe::deleteCharAt(long int index) {
    if (index < 0) {
        throw StringIndexOutOfBoundsException("index must be positive");
    }

    if (index >= this->currentLength) {
        throw StringIndexOutOfBoundsException();
    }

    // move block of memory from index + 1 to index
    string fromPosition = this->original + index + 1;
    string toPosition = this->original + index;
    long int memorySizeToMove = (this->currentLength - index) * sizeof(char);
    memmove(toPosition, fromPosition, (size_t) memorySizeToMove);
    this->currentLength--;
    return *this;
}

StringBufferUnSafe::~StringBufferUnSafe() {
    free(this->original);
}

/*void StringBufferUnSafe::getChars(long int sourceBegin, long int sourceEnd, string destination, long int destinationBegin) {
    if (sourceBegin < 0 || destinationBegin < 0 || sourceBegin > sourceEnd
        || (destinationBegin + sourceEnd - sourceEnd) > this->currentLength
        || sourceEnd > this->currentLength ) {

        throw IndexOutOfBoundsException();
    }
     // TODO need arrayCopy
}*/

long int StringBufferUnSafe::indexOf(String stringToGetIndex) const {
    return stringIndex(this->original, stringToGetIndex.toCharPointer(), 1);
}

long int StringBufferUnSafe::indexOf(String stringToGetIndex, long int fromIndex) const {
    String originalString = this->original;
    String fromIndexString = originalString.getStringFromIndex(fromIndex);
    long int result = fromIndexString.indexOf(stringToGetIndex);
    if (result == -1) {
        return result;
    }
    return result + fromIndex;
}

StringBufferUnSafe &StringBufferUnSafe::insert(long int offset, float floatValue) {
    String value = String::valueOf(floatValue);
    return this->insert(offset, value.toString(), 0, value.length());
}

StringBufferUnSafe &
StringBufferUnSafe::insert(long int offset, CharSequence *charSequence) {
    if (offset < 0) {
        throw IndexOutOfBoundsException("offset must be positive");
    }

    if (charSequence == nullptr) {
        return this->insert(offset, (string) "null", 0, 4);
    }

    return this->insert(offset, charSequence->toString(), 0,
                        charSequence->length());
}

StringBufferUnSafe &StringBufferUnSafe::insert(long int offset, boolean boolValue) {
    if (boolValue) {
        return this->insert(offset, (string) "true", 0, 4);
    }

    return this->insert(offset, (string) "false", 0, 5);
}

StringBufferUnSafe &
StringBufferUnSafe::insert(long int offset, string stringToInsert) {
    return this->insert(offset, stringToInsert, 0,
                        lengthPointerChar(stringToInsert));
}

StringBufferUnSafe &StringBufferUnSafe::insert(long int offset, char charValue) {
    String value = String::valueOf(charValue);
    return this->insert(offset, value.toString(), 0, value.length());
}

StringBufferUnSafe &
StringBufferUnSafe::insert(long int offset, String stringToInsert) {
    return this->insert(offset, stringToInsert.toString(), 0,
                        stringToInsert.length());
}

StringBufferUnSafe &StringBufferUnSafe::insert(long int offset, longValue) {
    String value = String::valueOf(longValue);
    return this->insert(offset, value.toString(), 0, value.length());
}

//StringBufferUnSafe &StringBufferUnSafe::insert(long int offset, Object &object) {
//	if (&object == nullptr) {
//		return this->insert(offset, (string) "null", 0, 4);
//	}
//
//	return this->insert(offset, object.toString(), 0, lengthPointerChar(object.toString()));
//}

StringBufferUnSafe &StringBufferUnSafe::insert(long int offset, long int intValue) {
    String value = String::valueOf(intValue);
    return this->insert(offset, value.toString(), 0, value.length());
}

StringBufferUnSafe &StringBufferUnSafe::insert(long int offset, double doubleValue) {
    String value = String::valueOf(doubleValue);
    return this->insert(offset, value.toString(), 0, value.length());
}

StringBufferUnSafe &
StringBufferUnSafe::insert(long int destinationOffset, CharSequence &sequence,
                           long int start, long int end) {
    if (destinationOffset < 0) {
        throw IndexOutOfBoundsException("offset must be positive");
    }

    if (&sequence == nullptr) {
        return this->insert(destinationOffset, (string) "null", 0, 4);
    }

    if (destinationOffset > this->currentLength || start < 0 || end < 0
        || start > end || end > sequence.length()) {
        throw IndexOutOfBoundsException();
    }

    return this->insert(destinationOffset, sequence.toString(), start,
                        end - start);
}

long int StringBufferUnSafe::lastIndexOf(String stringToGetIndex) const {
    String originalString = this->original;
    return originalString.lastIndexOf(stringToGetIndex);
}

int
StringBufferUnSafe::lastIndexOf(String stringToGetIndex, long int fromIndex) const {
    string reversedOriginal = stringReverse(this->original);
    string reversedString = stringReverse(stringToGetIndex.toCharPointer());
    String reversedOriginalString = reversedOriginal;

    long int substringIndex = this->length() - fromIndex - stringToGetIndex.length();
    reversedOriginalString = reversedOriginalString.getStringFromIndex(
            substringIndex);
    long int result = reversedOriginalString.indexOf(reversedString);

    free(reversedOriginal);
    free(reversedString);
    // Calculate result with original
    if (result == -1) {
        return result;
    }
    result = reversedOriginalString.length() - stringToGetIndex.length() -
             result;
    return result;
}

int
StringBufferUnSafe::offsetByCodePoints(long int index, long int codePointOffset) const {
    if (index < 0 || index > this->currentLength) {
        throw IndexOutOfBoundsException();
    }
    // TODO need Character::offsetByCodePoints
    // return Character::offsetByCodePoints(this->original, 0, this->currentLength, index, codePointOffset);
    return 0;
}

StringBufferUnSafe &
StringBufferUnSafe::replace(long int start, long int end, String stringToReplace) {
    if (start < 0) {
        throw StringIndexOutOfBoundsException("start must be positive");
    }
    if (start > this->currentLength || start > end) {
        throw StringIndexOutOfBoundsException();
    }

    if (end > this->currentLength) {
        end = this->currentLength;
    }

    long int newLength =
            this->currentLength + stringToReplace.length() - end + start;
    this->ensureCapacity(newLength);
    this->currentLength = newLength;

    string fromPosition = this->original + end;
    string toPosition = this->original + start + stringToReplace.length();
    long int memorySizeToMove = stringToReplace.length() * sizeof(char);
    memmove(toPosition, fromPosition, (size_t) memorySizeToMove);

    string insertPosition = this->original + start;
    memcpy(insertPosition, stringToReplace.toCharPointer(),
           (size_t) memorySizeToMove);

    return *this;
}

StringBufferUnSafe &StringBufferUnSafe::reverse() {
    boolean hasSurrogates = false;
    long int index = 0;
    long int oppositeIndex;
    long int stopIndex = this->currentLength / 2;
    char temp;
    for (index; index < stopIndex; index++) {
        oppositeIndex = (this->currentLength - 1) - index;
        temp = this->original[index];
        this->original[index] = this->original[oppositeIndex];
        this->original[oppositeIndex] = temp;
        if (Character::isSurrogate((this->original[index]))
            || Character::isSurrogate(this->original[oppositeIndex])) {
            hasSurrogates = true;
        }
    }
    if (hasSurrogates) {
        stopIndex = this->currentLength - 1;
        index = 0;
        char char1;
        char char2;
        for (index; index < stopIndex; index++) {
            char2 = this->original[index];
            if (Character::isLowSurrogate(char2)) {
                char1 = this->original[index + 1];
                if (Character::isHighSurrogate(char1)) {
                    this->original[index] = char1;
                    index = index + 1;
                    this->original[index] = char2;
                }
            }
        }
    }

    return *this;
}

void StringBufferUnSafe::setCharAt(long int index, char charValue) {
    if (index < 0) {
        throw IndexOutOfBoundsException("index must be positive");
    }
    if (index >= this->currentLength) {
        throw IndexOutOfBoundsException();
    }

    this->original[index] = charValue;
}

void StringBufferUnSafe::setLength(long int newLength) {
    if (newLength < 0) {
        throw IndexOutOfBoundsException("newLength must be positive");
    }

    long int oldLength = this->currentLength;
    if (newLength > this->currentLength) {
        this->ensureCapacity(newLength);
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

/*CharSequence *StringBufferUnSafe::subSequence(long int start, long int end) {
    if (start < 0 || end < 0) {
        throw IndexOutOfBoundsException("start and end must be positive");
    }

    if (start >= this->currentLength || end > this->currentLength || start > end) {
        throw IndexOutOfBoundsException();
    }

    String *result = new String(this->subString(start, end));
    return result;
}*/

String StringBufferUnSafe::subString(long int start) const {
    return this->subString(start, this->currentLength);
}

String StringBufferUnSafe::subString(long int start, long int end) const {
    if (start < 0 || end < 0) {
        throw StringIndexOutOfBoundsException("start and end must be positive");
    }

    if (start >= this->currentLength || end > this->currentLength ||
        start > end) {
        throw StringIndexOutOfBoundsException();
    }

    long int resultStringLength = end - start;
    string resultString = (string) calloc((size_t) resultStringLength + 1,
                                          sizeof(char));
    long int memorySizeToCopy = resultStringLength * sizeof(char);
    memcpy(resultString, this->original + start, (size_t) memorySizeToCopy);
    String result = String(resultString);
    free(resultString);
    return result;
}

String StringBufferUnSafe::toString() const {
    return this->original;
}

void StringBufferUnSafe::trimToSize() {
    if (this->currentCapacity <= this->currentLength) {
        return;
    }
    long int newSize = this->currentLength * sizeof(char);
    this->original = (string) allocateMemory(this->original, (size_t) newSize);
    this->currentCapacity = this->currentLength;
}

StringBufferUnSafe &
StringBufferUnSafe::operator=(const StringBufferUnSafe &other) {
    free(this->original);
    this->original = (string) calloc((size_t) other.currentCapacity,
                                     sizeof(char));
    long int index;
    for (index = 0; index < other.currentLength; index++) {
        this->original[index] = other.original[index];
    }
    this->currentLength = other.currentLength;
    this->currentCapacity = other.currentCapacity;
    return *this;
}


// StringBuffer
StringBuffer::StringBuffer() : StringBufferUnSafe() {
}

StringBuffer::StringBuffer(CharSequence &sequence) : StringBufferUnSafe(
        sequence) {
}

StringBuffer::StringBuffer(long int capacity) : StringBufferUnSafe(capacity) {
}

StringBuffer::StringBuffer(String originalString) : StringBufferUnSafe(
        originalString) {
}

StringBuffer::StringBuffer(const StringBuffer &other) {
    std::lock_guard<std::mutex> guard(this->mutex);
    free(this->original);
    this->original = (string) calloc((size_t) other.currentCapacity,
                                     sizeof(char));
    long int index;
    for (index = 0; index < other.currentLength; index++) {
        this->original[index] = other.original[index];
    }
    this->currentLength = other.currentLength;
    this->currentCapacity = other.currentCapacity;
}

//StringBuffer &StringBuffer::append(Object &object) {
//	std::lock_guard<std::mutex> guard(this->mutex);
//	StringBufferUnSafe::append(&object);
//	return *this;
//}

StringBuffer &StringBuffer::append(float floatValue) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::append(floatValue);
    return *this;
}

StringBuffer &StringBuffer::append(string stringToAppend) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::append(stringToAppend);
    return *this;
}

StringBuffer &StringBuffer::append(boolean boolValue) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::append(boolValue);
    return *this;
}

StringBuffer &StringBuffer::append(CharSequence &sequence) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::append(sequence);
    return *this;
}

StringBuffer &StringBuffer::append(char charValue) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::append(charValue);
    return *this;
}

StringBuffer &StringBuffer::append(String stringToAppend) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::append(stringToAppend);
    return *this;
}

StringBuffer &StringBuffer::append(long int intValue) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::append(intValue);
    return *this;
}

StringBuffer &StringBuffer::append(longValue) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::append(longValue);
    return *this;
}

StringBuffer &StringBuffer::append(string stringToAppend, long int offset, long int len) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::append(stringToAppend, offset, len);
    return *this;
}

StringBuffer &StringBuffer::append(CharSequence &sequence, long int start, long int end) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::append(sequence, start, end);
    return *this;
}

StringBuffer &StringBuffer::appendCodePoint(long int codePoint) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::appendCodePoint(codePoint);
    return *this;
}

StringBuffer &StringBuffer::append(StringBuffer stringBuffer) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::append(stringBuffer);
    return *this;
}

long int StringBuffer::capacity() const {
    std::lock_guard<std::mutex> guard(this->mutex);
    return StringBufferUnSafe::capacity();
}

char StringBuffer::charAt(long int index) const {
    std::lock_guard<std::mutex> guard(this->mutex);
    return StringBufferUnSafe::charAt(index);
}

long int StringBuffer::codePointAt(long int index) const {
    std::lock_guard<std::mutex> guard(this->mutex);
    return StringBufferUnSafe::codePointAt(index);
}

long int StringBuffer::codePointBefore(long int index) const {
    std::lock_guard<std::mutex> guard(this->mutex);
    return StringBufferUnSafe::codePointBefore(index);
}

long int StringBuffer::codePointCount(long int beginIndex, long int endIndex) const {
    std::lock_guard<std::mutex> guard(this->mutex);
    return StringBufferUnSafe::codePointCount(beginIndex, endIndex);
}

StringBuffer &StringBuffer::deletes(long int start, long int end) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::deletes(start, end);
    return *this;
}

void StringBuffer::ensureCapacity(long int minimumCapacity) {
    StringBufferUnSafe::ensureCapacity(minimumCapacity);
}

String StringBuffer::getValue() const {
    return StringBufferUnSafe::getValue();
}

StringBuffer &StringBuffer::append(double doubleValue) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::append(doubleValue);
    return *this;
}

StringBuffer &StringBuffer::deleteCharAt(long int index) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::deleteCharAt(index);
    return *this;
}

long int StringBuffer::length() const {
    return StringBufferUnSafe::length();
}

StringBuffer::~StringBuffer() = default;

/*void StringBuffer::getChars(long int sourceBegin, long int sourceEnd, string destination, long int destinationBegin) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::getChars(sourceBegin, sourceEnd, destination, destinationBegin);
}*/

long int StringBuffer::indexOf(String stringToGetIndex) const {
    std::lock_guard<std::mutex> guard(this->mutex);
    return StringBufferUnSafe::indexOf(stringToGetIndex);
}

long int StringBuffer::indexOf(String stringToGetIndex, long int fromIndex) const {
    std::lock_guard<std::mutex> guard(this->mutex);
    return StringBufferUnSafe::indexOf(stringToGetIndex, fromIndex);
}

StringBuffer &StringBuffer::insert(long int offset, float floatValue) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::insert(offset, floatValue);
    return *this;
}

StringBuffer &StringBuffer::insert(long int offset, boolean boolValue) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::insert(offset, boolValue);
    return *this;
}

StringBuffer &StringBuffer::insert(long int offset, String stringToInsert) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::insert(offset, stringToInsert);
    return *this;
}

StringBuffer &StringBuffer::insert(long int offset, char charValue) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::insert(offset, charValue);
    return *this;
}

//StringBuffer &StringBuffer::insert(long int offset, Object &object) {
//	std::lock_guard<std::mutex> guard(this->mutex);
//	StringBufferUnSafe::insert(offset, object);
//	return *this;
//}

StringBuffer &StringBuffer::insert(long int offset, double doubleValue) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::insert(offset, doubleValue);
    return *this;
}

StringBuffer &
StringBuffer::insert(long int destinationOffset, CharSequence &sequence, long int start,
                     long int end) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::insert(destinationOffset, sequence, start, end);
    return *this;
}

StringBuffer &StringBuffer::insert(long int offset, longValue) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::insert(offset, longValue);
    return *this;
}

StringBuffer &StringBuffer::insert(long int offset, long int intValue) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::insert(offset, intValue);
    return *this;
}

StringBuffer &StringBuffer::insert(long int offset, CharSequence &charSequence) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::insert(offset, &charSequence);
    return *this;
}

StringBuffer &
StringBuffer::insert(long int index, String stringToInsert, long int offset, long int len) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::insert(index, stringToInsert, offset, len);
    return *this;
}

long int StringBuffer::lastIndexOf(String stringToGetIndex) const {
    std::lock_guard<std::mutex> guard(this->mutex);
    return StringBufferUnSafe::lastIndexOf(stringToGetIndex);
}

long int StringBuffer::lastIndexOf(String stringToGetIndex, long int fromIndex) const {
    std::lock_guard<std::mutex> guard(this->mutex);
    return StringBufferUnSafe::lastIndexOf(stringToGetIndex, fromIndex);
}

long int StringBuffer::offsetByCodePoints(long int index, long int codePointOffset) const {
    std::lock_guard<std::mutex> guard(this->mutex);
    return StringBufferUnSafe::offsetByCodePoints(index, codePointOffset);
}

StringBuffer &
StringBuffer::replace(long int start, long int end, String stringToReplace) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::replace(start, end, stringToReplace);
    return *this;
}

StringBuffer &StringBuffer::reverse() {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::reverse();
    return *this;
}

void StringBuffer::setCharAt(long int index, char charValue) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::setCharAt(index, charValue);
}

void StringBuffer::setLength(long int newLength) {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::setLength(newLength);
}

/*CharSequence *StringBuffer::subSequence(long int start, long int end) {
    std::lock_guard<std::mutex> guard(this->mutex);
    return StringBufferUnSafe::subSequence(start, end);
}*/

String StringBuffer::subString(long int start) const {
    std::lock_guard<std::mutex> guard(this->mutex);
    return StringBufferUnSafe::subString(start);
}

String StringBuffer::subString(long int start, long int end) const {
    std::lock_guard<std::mutex> guard(this->mutex);
    return StringBufferUnSafe::subString(start, end);
}

String StringBuffer::toString() const {
    std::lock_guard<std::mutex> guard(this->mutex);
    return StringBufferUnSafe::toString();
}

void StringBuffer::trimToSize() {
    std::lock_guard<std::mutex> guard(this->mutex);
    StringBufferUnSafe::trimToSize();
}

StringBuffer &StringBuffer::operator=(const StringBuffer &other) {
    std::lock_guard<std::mutex> guard(this->mutex);
    free(this->original);
    this->original = (string) calloc((size_t) other.currentCapacity,
                                     sizeof(char));
    long int index;
    for (index = 0; index < other.currentLength; index++) {
        this->original[index] = other.original[index];
    }
    this->currentLength = other.currentLength;
    this->currentCapacity = other.currentCapacity;
    return *this;
}