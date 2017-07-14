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

#include "../StringBuilder/StringBuilder.hpp"
#include "../IndexOutOfBoundsException/IndexOutOfBoundsException.hpp"
#include "../StringIndexOutOfBoundsException/StringIndexOutOfBoundsException.hpp"

using namespace Java::Lang;

StringBuilder::StringBuilder() : StringBuilder(16) { }

StringBuilder::StringBuilder(int capacity) {
    int numberOfBytesForCapacity = capacity * sizeof(char);
    this->original = (string)malloc((size_t)numberOfBytesForCapacity);
    this->currentLength = 0;
    this->currentCapacity = capacity;
}

StringBuilder::StringBuilder(const string target) {
    int stringLength = (int)strlen(target);
    int newCapacity = 16 + stringLength;
    this->ensureCapacity(newCapacity);
    this->append(target);
}

StringBuilder::StringBuilder(const String &target) {
    int newCapacity = 16 + target.length();
    this->ensureCapacity(newCapacity);
    this->append(target.toString());
}

StringBuilder::StringBuilder(const std::initializer_list<char> &target) {
    int newCapacity = 16 + (int)target.size();
    this->ensureCapacity(newCapacity);
    this->append(target);
}

StringBuilder::StringBuilder(const StringBuilder &target) {
    int numberOfBytesOfCapacity = target.currentCapacity * sizeof(char);
    this->original = (string)malloc((size_t)numberOfBytesOfCapacity);
    int index;
    for (index = 0; index < target.currentLength; index++) {
        this->original[index] = target.original[index];
    }
    this->currentLength = target.currentLength;
    this->currentCapacity = target.currentCapacity;
}

StringBuilder::~StringBuilder() {
    free(original);
}

StringBuilder StringBuilder::append(const Boolean &target) {
    return this->append(target.toString());
}

StringBuilder StringBuilder::append(boolean target) {
    return this->append(Boolean(target));
}

StringBuilder StringBuilder::append(const Character &target) {
    Character *pointerToTarget = const_cast<Character *>(&target);
    return this->append(pointerToTarget->charValue());
}

StringBuilder StringBuilder::append(char target) {
    int newLength = this->currentLength + 1;
    this->ensureCapacity(newLength);
    this->original[this->currentLength] = target;
    this->currentLength = newLength;
    return *this;
}

StringBuilder StringBuilder::append(const Array<Character> &target) {
    int newLength = this->currentLength + target.length;
    this->ensureCapacity(newLength);
    int indexOfOriginal = this->currentLength;
    for (Character character : target) {
        this->original[indexOfOriginal] = character.charValue();
        indexOfOriginal = indexOfOriginal + 1;
    }
    this->currentLength = newLength;
    return *this;
}

StringBuilder StringBuilder::append(const Array<char> &target) {
    int newLength = this->currentLength + target.length;
    this->ensureCapacity(newLength);
    int indexOfOriginal = this->currentLength;
    for (char character: target) {
        this->original[indexOfOriginal] = character;
        indexOfOriginal = indexOfOriginal + 1;
    }
    this->currentLength = newLength;
    return *this;
}

StringBuilder StringBuilder::append(const Array<Character> &target, int offset, int length) {
    return this->insert(this->currentLength, target, offset, length);
}

StringBuilder StringBuilder::append(const Array<char> &target, int offset, int length) {
    return this->insert(this->currentLength, target, offset, length);
}

StringBuilder StringBuilder::append(const std::initializer_list<char> &target) {
    int newLength = this->currentLength + (int)target.size();
    this->ensureCapacity(newLength);
    int index = this->currentLength;
    std::initializer_list<char>::const_iterator listIterator;
    for (listIterator = target.begin(); listIterator != target.end(); listIterator++) {
        this->original[index] = *listIterator;
        index = index + 1;
    }
    this->currentLength = newLength;
    return *this;
}

StringBuilder StringBuilder::append(const string target) {
    int stringLength = (int)strlen(target);
    int newLength = this->currentLength + stringLength;
    this->ensureCapacity(newLength);
    int indexOfOriginal;
    int indexOfString = 0;
    for (indexOfOriginal = this->currentLength; indexOfOriginal < newLength; indexOfOriginal++) {
        this->original[indexOfOriginal] = target[indexOfString];
        indexOfString = indexOfString + 1;
    }
    this->currentLength = newLength;
    return *this;
}

StringBuilder StringBuilder::append(const Double &target) {
    return this->append(target.toString());
}

StringBuilder StringBuilder::append(double target) {
    return this->append(Double(target));
}

StringBuilder StringBuilder::append(const Float &target) {
    return this->append(target.toString());
}

StringBuilder StringBuilder::append(float target) {
    return this->append(Float(target));
}

StringBuilder StringBuilder::append(const Integer &target) {
    return this->append(target.toString());
}

StringBuilder StringBuilder::append(int target) {
    return this->append(Integer(target));
}

StringBuilder StringBuilder::append(const Long &target) {
    return this->append(target.toString());
}

StringBuilder StringBuilder::append(long target) {
    return this->append(Long(target));
}

StringBuilder StringBuilder::append(const String &target) {
    return this->append(target.toString());
}

int StringBuilder::capacity() const {
    return this->currentCapacity;
}

char StringBuilder::charAt(int index) const {
    if (index < 0 || index >= this->currentLength) {
        throw StringIndexOutOfBoundsException(index);
    }

    return this->original[index];
}

void StringBuilder::ensureCapacity(int minimumCapacity) {
    if ((minimumCapacity > 0) && (minimumCapacity > this->currentCapacity)) {
        int newCapacity = this->currentCapacity * 2 + 2;
        if (newCapacity < minimumCapacity) {
            newCapacity = minimumCapacity;
        }
        int numberOfBytes = newCapacity * sizeof(char);
        this->original = (string)realloc(this->original, (size_t)numberOfBytes);
        this->currentCapacity = newCapacity;
    }
}

StringBuilder StringBuilder::insert(int offset, boolean target) {
    return this->insert(offset, Boolean(target));
}

StringBuilder StringBuilder::insert(int offset, const Boolean &target) {
    return this->insert(offset, target.toString());
}

StringBuilder StringBuilder::insert(int offset, char target) {
    if (offset < 0 || offset > this->currentLength) {
        throw StringIndexOutOfBoundsException(offset);
    }

    int newLength = this->currentLength + 1;
    this->ensureCapacity(newLength);

    string newShiftPosition = this->original + offset + 1;
    string oldShiftPosition = this->original + offset;
    int sizeOfShiftMemory = sizeof(char) * (this->currentLength - offset);
    memmove(newShiftPosition, oldShiftPosition, (size_t)sizeOfShiftMemory);
    this->original[offset] = target;
    this->currentLength = newLength;

    return *this;
}

StringBuilder StringBuilder::insert(int offset, const Character &target) {
    Character *pointerToTarget = const_cast<Character *>(&target);
    return this->insert(offset, pointerToTarget->charValue());
}

StringBuilder StringBuilder::insert(int offset, const Array<char> &target) {
    return this->insert(offset, target, 0, target.length);
}

StringBuilder StringBuilder::insert(int offset, const Array<Character> &target) {
    return this->insert(offset, target, 0, target.length);
}

StringBuilder StringBuilder::insert(int index, const Array<char> &target, int offset, int length) {
    if (index < 0 || index > this->currentLength) {
        throw StringIndexOutOfBoundsException(offset);
    }

    int stopIndexOfTarget = offset + length;
    if (offset < 0 || length < 0 || stopIndexOfTarget > target.length) {
        throw StringIndexOutOfBoundsException(offset);
    }

    int newLength = this->currentLength + length;
    this->ensureCapacity(newLength);

    string newShiftPosition = this->original + index + length;
    string oldShiftPosition = this->original + index;
    int sizeOfShiftMemory = sizeof(char) * (this->currentLength - index);
    memmove(newShiftPosition, oldShiftPosition, (size_t)sizeOfShiftMemory);
    int indexOfTarget;
    int indexOfOriginal = index;
    for (indexOfTarget = offset; indexOfTarget < stopIndexOfTarget; indexOfTarget++) {
        this->original[indexOfOriginal] = target.get(indexOfTarget);
        indexOfOriginal = indexOfOriginal + 1;
    }
    this->currentLength = newLength;

    return *this;
}

StringBuilder StringBuilder::insert(int index, const Array<Character> &target, int offset, int length) {
    if (index < 0 || index > this->currentLength) {
        throw StringIndexOutOfBoundsException(offset);
    }

    int stopIndexOfTarget = offset + length;
    if (offset < 0 || length < 0 || stopIndexOfTarget > target.length) {
        throw StringIndexOutOfBoundsException(offset);
    }

    int newLength = this->currentLength + length;
    this->ensureCapacity(newLength);

    string newShiftPosition = this->original + index + length;
    string oldShiftPosition = this->original + index;
    int sizeOfShiftMemory = sizeof(char) * (this->currentLength - index);
    memmove(newShiftPosition, oldShiftPosition, (size_t)sizeOfShiftMemory);
    int indexOfTarget;
    int indexOfOriginal = index;
    for (indexOfTarget = offset; indexOfTarget < stopIndexOfTarget; indexOfTarget++) {
        this->original[indexOfOriginal] = target.get(indexOfTarget).charValue();
        indexOfOriginal = indexOfOriginal + 1;
    }
    this->currentLength = newLength;

    return *this;
}

StringBuilder StringBuilder::insert(int offset, const Double &target) {
    return this->insert(offset, target.toString());
}

StringBuilder StringBuilder::insert(int offset, double target) {
    return this->insert(offset, Double(target));
}

StringBuilder StringBuilder::insert(int offset, const Float &target) {
    return this->insert(offset, target.toString());
}

StringBuilder StringBuilder::insert(int offset, float target) {
    return this->insert(offset, Float(target));
}

StringBuilder StringBuilder::insert(int offset, const Integer &target) {
    return this->insert(offset, target.toString());
}

StringBuilder StringBuilder::insert(int offset, int target) {
    return this->insert(offset, Integer(target));
}

StringBuilder StringBuilder::insert(int offset, const Long &target) {
    return this->insert(offset, target.toString());
}

StringBuilder StringBuilder::insert(int offset, long target) {
    return this->insert(offset, Long(target));
};

StringBuilder StringBuilder::insert(int offset, const String &target) {
    return this->insert(offset, target.toString());
}

StringBuilder StringBuilder::insert(int offset, const string target) {
    if (offset < 0 || offset > this->currentLength) {
        throw StringIndexOutOfBoundsException(offset);
    }

    int targetLength = (int)strlen(target);
    int newLength = this->currentLength + targetLength;
    this->ensureCapacity(newLength);

    string newShiftPosition = this->original + offset + targetLength;
    string oldShiftPosition = this->original + offset;
    // Number of bytes of memory will be to shift = size of char type multiple with number of character begin from the offset to the end.
    int sizeOfShiftMemory = sizeof(char) * (this->currentLength - offset);
    memmove(newShiftPosition, oldShiftPosition, (size_t)sizeOfShiftMemory);

    int indexOfOriginal = offset;
    int indexOfTarget;
    for (indexOfTarget = 0; indexOfTarget < targetLength; indexOfTarget++) {
        this->original[indexOfOriginal] = target[indexOfTarget];
        indexOfOriginal = indexOfOriginal + 1;
    }

    this->currentLength = newLength;
    return *this;
}

int StringBuilder::length() const {
    return this->currentLength;
}

String StringBuilder::substring(int start) const {
    return this->substring(start, this->currentLength);
}

String StringBuilder::substring(int start, int end) const {
    if (start < 0 || start > this->currentLength) {
        throw StringIndexOutOfBoundsException(start);
    }
    if (end < 0 || end > this->currentLength) {
        throw StringIndexOutOfBoundsException(end);
    }
    if (start > end) {
        throw StringIndexOutOfBoundsException(end - start);
    }

    int numberOfBytesForSubString = (end - start + 1) * sizeof(char);
    string copyOfSubString = (string)malloc((size_t)numberOfBytesForSubString);
    int indexOfOriginal;
    int indexOfSubString = 0;
    for (indexOfOriginal = start; indexOfOriginal < end;indexOfOriginal++) {
        copyOfSubString[indexOfSubString] = this->original[indexOfOriginal];
        indexOfSubString = indexOfSubString + 1;
    }
    copyOfSubString[indexOfSubString] = '\0';
    String result(copyOfSubString);
    free(copyOfSubString);
    return result;
}

String StringBuilder::toString() const {
    int numberOfBytes = (this->currentLength + 1) * sizeof(char); // increases by 1 for null terminator.
    string content = (string)malloc((size_t)numberOfBytes);
    int index;
    for (index = 0; index < this->currentLength; index++) {
        content[index] = this->original[index];
    }
    content[this->currentLength] = '\0';
    String result(content);
    free(content);
    return result;
}

void StringBuilder::trimToSize() {
    if (this->currentCapacity > this->currentLength) {
        int numberOfBytesForCapacity = this->currentLength * sizeof(char);
        this->original = (string)realloc(this->original, (size_t)numberOfBytesForCapacity);
        this->currentCapacity = this->currentLength;
    }
}
