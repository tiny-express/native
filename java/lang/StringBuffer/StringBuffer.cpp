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

StringBuffer::StringBuffer() : StringBuffer(16){
}

StringBuffer::StringBuffer(int capacity) {
    if (capacity < 0) {
        throw NegativeArraySizeException("Capacity must be non-negative");
    }

    this->currentCapacity = capacity;
    this->original = (string)(calloc((size_t)(currentCapacity), sizeof(char)));
}

StringBuffer::StringBuffer(String str) {
    this->currentCapacity = str.length() + 16;
    this->original = (string)(calloc((size_t)(currentCapacity), sizeof(char)));
    append(str);
}

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

int StringBuffer::capacity() {
    return this->currentCapacity;
}

string StringBuffer::getValue() {
    return this->original;
}

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

StringBuffer::~StringBuffer() {
    free(this->original);
}

StringBuffer StringBuffer::append(String str) {
    return this->append(str.toString(), 0, str.length());
}

int StringBuffer::length() {
    return this->currentLength;
}

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

StringBuffer::StringBuffer(const StringBuffer &other) {
    this->original = (string) calloc((size_t) other.currentCapacity, sizeof(char));
    int index;
    for (index = 0; index < other.currentLength; index++) {
        this->original[index] = other.original[index];
    }
    this->currentLength = other.currentLength;
    this->currentCapacity = other.currentCapacity;
}

StringBuffer StringBuffer::append(string str) {
    return this->append(str, 0, length_pointer_char(str));
}

StringBuffer StringBuffer::append(Object *obj) {
    if (obj == nullptr) {
        return this->append((string)"null");    }
    else {
        return this->append(obj->toString());
    }
}

StringBuffer StringBuffer::append(float floatValue) {
    return this->append(String::valueOf(floatValue).toString());
}

StringBuffer StringBuffer::append(double doubleValue) {
    return this->append(String::valueOf(doubleValue).toString());
}

StringBuffer StringBuffer::append(int intValue) {
    return this->append(String::valueOf(intValue).toString());
}

StringBuffer StringBuffer::append(long longValue) {
    return this->append(String::valueOf(longValue).toString());
}

StringBuffer StringBuffer::append(boolean boolValue) {
    if (boolValue) {
        return this->append((string)"true");
    }
    else {
        return this->append((string)"false");
    }
}

StringBuffer StringBuffer::append(char charValue) {
    return this->append(String::valueOf(charValue).toString());
}

StringBuffer StringBuffer::append(StringBuffer *stringBuffer) {
    if (stringBuffer == nullptr) {
        return this->append((string)"null");
    }
    else {
        return this->append(stringBuffer->getValue());
    }

}

StringBuffer StringBuffer::appendCodePoint(int codePoint) {
    int plane = ((unsigned) codePoint) >> 16;
    boolean isBmpCodePoint = (plane == 0);
    boolean isValidCodePoint = (plane < (((unsigned) (0X10FFFF + 1)) >> 16));

    if (isBmpCodePoint) {
        return this->append((char) codePoint);
    }
    else if (isValidCodePoint) {
        //TODO append lowSurrogate and highSurrogate
    }
    else {
        throw IllegalArgumentException();
    }
}





