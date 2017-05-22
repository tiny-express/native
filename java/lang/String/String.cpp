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

#include "String.hpp"

using namespace Java::Lang;

String::String() {
    this->original = "";
}

String::String(const_string target) {
    this->original = (string) target;
}

String::String(string target) {
    this->original = target;
}

String::String(Array<byte> bytes) {
//    for (byte byte: bytes) {
//    }
//    this->original = reinterpret_cast<string>(bytes);
}

String::String(const String& target) {
    this->original = target.original;
}

String::~String() {
}

int String::length() const {
    return length_pointer_char(this->original);
}

string String::toCharArray() const {
    return this->original;
}

String String::toString() const {
    return this->original;
}

String String::operator+(const String& target2) {
    String result = string_concat(this->original, target2.original);
    return result;
}

bool String::operator==(const String &target2) {
    if (string_equals(this->original, target2.toCharArray())) {
        return true;
    }
    return false;
}

bool String::operator!=(const String &target2) {
    return !this->operator==(target2);
}

String String::valueOf(boolean target) {
    if (target) return (string) "1";
    return (string) "0";
}

String String::valueOf(char target) {
    return string_from_char(target);
}

String String::valueOf(string target) {
    if (is_empty(target)) return (string) "";
    return target;
}

String String::valueOf(short target) {
    return string_from_short(target);
}

String String::valueOf(int target) {
    return string_from_int(target);
}

String String::valueOf(long target) {
    return string_from_long(target);
}

String String::valueOf(float target) {
    return string_from_float(target);
}

String String::valueOf(double target) {
    return string_from_double(target);
}

boolean String::isEmpty() const {
    if (length_pointer_char(this->original) == 0) {
        return true;
    }
    return false;
}
