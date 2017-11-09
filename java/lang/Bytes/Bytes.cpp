/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
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

#include "Bytes.hpp"
#include "../NumberFormatException/NumberFormatException.hpp"
#include "../ArithmeticException/ArithmeticException.hpp"

using namespace Java::Lang;

ByteCache *ByteCache::instance = nullptr;

Bytes::Bytes(byte byteValue) {
    this->original = byteValue;
    this->originalString = stringFromInt(this->original);
}

Bytes::Bytes(String inputString) {
    this->original = parseBytes(inputString, 10);
    this->originalString = stringFromInt(this->original);
}

Bytes::Bytes() {
    this->original = 0;
    this->originalString = stringCopy("0");
}

Bytes::~Bytes() {
    if (this->originalString != nullptr) {
        free(this->originalString);
    }
}

char Bytes::charValue() const {
    return (char) this->original;
}

byte Bytes::byteValue() const {
    return this->original;
}

long int Bytes::compare(byte byteA, byte byteB) {
    return byteA - byteB;
}

long int Bytes::compareTo(const Bytes &other) const {
    return this->original - other.original;
}

Bytes Bytes::decode(String stringToDecode) {
    long int value = Integer::decode(stringToDecode).intValue();
    if (value < Bytes::MIN_VALUE || value > Bytes::MAX_VALUE) {
        throw NumberFormatException("out of byte range");
    }
    return (Bytes) value;
}

double Bytes::doubleValue() const {
    return (double) this->original;
}

//TODO need instanceof
boolean Bytes::equals(Bytes object) {
//    boolean isBytes = instanceof<Byte>(object);
//	if (isByte) {
//        return this->original == parseBytes(object.toString());
//    }
//	return false;
    return this->original == parseBytes(object.toString());
}

float Bytes::floatValue() const {
    return (float) this->original;
}

long int Bytes::hashCode() const {
    return (int) this->original;
}

long int Bytes::hashCode(byte value) {
    return value;
}

long int Bytes::intValue() const {
    return (int) this->original;
}

long long Bytes::longValue() const {
    return this->original;
}

byte Bytes::parseBytes(String stringToParse) {
    return parseBytes(stringToParse, 10);
}

byte Bytes::parseBytes(String stringToParse, long int radix) {
    long int value = Integer::parseInt(stringToParse, radix);
    if (value < Bytes::MIN_VALUE || value > Bytes::MAX_VALUE) {
        throw NumberFormatException("out of byte range");
    }
    return (byte) value;
}

int Bytes::shortValue() const {
    return (int) this->original;
}

String Bytes::toString() const {
    return this->originalString;
}

String Bytes::toString(byte byteValue) {
    return Integer::toString((int) byteValue, 10);
}

long int Bytes::toUnsignedInt(byte byteValue) {
    return ((int) byteValue) & 0xff;
}

long long Bytes::toUnsignedLong(byte byteValue) {
    return ((long) byteValue) & 0xffL;
}

Bytes Bytes::valueOf(byte byteValue) {
    return ByteCache::getInstance()->getByteAtIndex((int) byteValue);
}

Bytes Bytes::valueOf(String stringValue) {
    return Bytes(parseBytes(stringValue));
}

Bytes Bytes::valueOf(String stringValue, long int radix) {
    return Bytes(parseBytes(stringValue, radix));
}

Bytes Bytes::operator+(const Bytes &target) {
    return this->original + target.original;
}

Bytes Bytes::operator-(const Bytes &target) {
    return this->original - target.original;
}

Bytes Bytes::operator/(const Bytes &target) {
    if (target.intValue() == 0) {
        throw ArithmeticException("Divide by zero");
    }
    return this->original / target.original;
}

Bytes Bytes::operator%(const Bytes &target) {
    if (target.intValue() == 0) {
        throw ArithmeticException("Divide by zero");
    }
    return this->original % target.original;
}

Bytes Bytes::operator*(const Bytes &target) {
    return this->original * target.original;
}

boolean Bytes::operator==(const Bytes &target) {
    return this->original == target.original;
}

boolean Bytes::operator!=(const Bytes &target) {
    return this->original != target.original;
}

boolean Bytes::operator<(const Bytes &target) {
    return this->original < target.original;
}

boolean Bytes::operator>(const Bytes &target) {
    return this->original > target.original;
}

boolean Bytes::operator<=(const Bytes &target) {
    return this->original <= target.original;
}

boolean Bytes::operator>=(const Bytes &target) {
    return this->original >= target.original;
}

Bytes &Bytes::operator-=(const Bytes &target) {
    free((this->originalString));
    this->original -= target.original;
    this->originalString = stringFromInt(this->original);
    return *this;
}

Bytes &Bytes::operator+=(const Bytes &target) {
    free((this->originalString));
    this->original += target.original;
    this->originalString = stringFromInt(this->original);
    return *this;
}

Bytes &Bytes::operator*=(const Bytes &target) {
    free((this->originalString));
    this->original *= target.original;
    this->originalString = stringFromInt(this->original);
    return *this;
}

Bytes &Bytes::operator/=(const Bytes &target) {
    if (target.intValue() == 0) {
        throw ArithmeticException("Divide by zero");
    }
    free((this->originalString));
    this->original /= target.original;
    this->originalString = stringFromInt(this->original);
    return *this;
}

Bytes &Bytes::operator%=(const Bytes &target) {
    if (target.intValue() == 0) {
        throw ArithmeticException("Divide by zero");
    }
    free((this->originalString));
    this->original %= target.original;
    this->originalString = stringFromInt(this->original);
    return *this;
}

Bytes &Bytes::operator=(const Bytes &target) {
    free((this->originalString));
    this->original = target.original;
    this->originalString = stringFromInt(this->original);
    return *this;
}

Bytes::Bytes(const Bytes &anotherByte) {
    this->original = anotherByte.original;
    this->originalString = stringFromInt(this->original);
}
