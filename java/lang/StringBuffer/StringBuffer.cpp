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

StringBuffer::StringBuffer() : StringBuffer(16){
}

StringBuffer::StringBuffer(int capacity) {
    if (capacity < 0) {
        throw NegativeArraySizeException();
    }

    this->currentcapacity = capacity;
    this->original = (string)(calloc((size_t)(currentcapacity), sizeof(char)));
}

StringBuffer::StringBuffer(String str) {
    this->currentcapacity = str.length() + 16;
    this->original = (string)(calloc((size_t)(currentcapacity), sizeof(char)));
    append(str);
}

StringBuffer::StringBuffer(CharSequence *seq) {
    this->currentcapacity = seq->length() + 16;
    this->original = (string)(calloc((size_t)(currentcapacity), sizeof(char)));
    append(seq);
}

int StringBuffer::capacity() {
    return currentcapacity;
}

string StringBuffer::getValue() {
    return original;
}

StringBuffer StringBuffer::append(CharSequence *seq) {
    this->original = seq->toString();
}

StringBuffer StringBuffer::append(CharSequence *seq, int start, int end) {

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
        currentcapacity = newCapacity;
    } while (newCapacity < minimumCapacity);

    int newSize = newCapacity * sizeof(char);
    original = (string)(realloc(original, (size_t)(newSize)));
}

StringBuffer::~StringBuffer() {
    free(original);
}

StringBuffer StringBuffer::append(String str) {
    return this->append(str.toString(), 0, str.length());
}

int StringBuffer::length() {
    return currentlength;
}

StringBuffer StringBuffer::append(string str, int offset, int len) {
    if (offset < 0 || len < 0 || (offset + len) > length_pointer_char(str)) {
        throw IndexOutOfBoundsException();
    }

    ensureCapacity(this->length() + length_pointer_char(str));
    std::string string(this->original);
    string.append(getString(str, offset, len));
    strcpy(this->original, string.c_str());
    this->currentlength += len;
    return *this;
}

StringBuffer StringBuffer::insert(int index, string str, int offset, int len) {
    if (index < 0 || index > length() || offset < 0
        || len < 0 || (offset + len) > length_pointer_char(str)) {
        throw StringIndexOutOfBoundsException();
    }

    ensureCapacity(this->length() + length_pointer_char(str));
    std::string string(original);
    string.insert(index, str, offset, len);
    strcpy(original, string.c_str());
    currentlength += len;
    return *this;

}

string StringBuffer::getString(string str, int offset, int len) {
    string result;
    int end = offset + len;
    int begin = offset;
    for (begin; begin < end; begin++) {
        result[begin - offset] = str[begin];
    }
    return result;
}

StringBuffer StringBuffer::append(string destination, string str) {
    int strLen = length_pointer_char(str);
    for (int index = 0; index < strLen; ++index) {
        int originalIndex = currentlength +index;
        char character = str[index];
        destination[originalIndex] = character;
    }
}

StringBuffer::StringBuffer(const StringBuffer &other) {
    this->original = (string) calloc((size_t) other.currentcapacity, sizeof(char));
    int index;
    for (index = 0; index < other.currentlength; index++) {
        this->original[index] = other.original[index];
    }
    this->currentlength = other.currentlength;
    this->currentcapacity = other.currentcapacity;
}





