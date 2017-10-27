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

#include "Byte.hpp"
#include "../NumberFormatException/NumberFormatException.hpp"
#include "../ArithmeticException/ArithmeticException.hpp"

using namespace Java::Lang;

ByteCache *ByteCache::instance = nullptr;

Byte::Byte(byte byteValue) {
	this->original = byteValue;
    this->originalString = stringFromInt(this->original);
}

Byte::Byte(String inputString) {
	this->original = parseByte(inputString, 10);
    this->originalString = stringFromInt(this->original);
}

Byte::Byte() {
    this->original = 0;
    this->originalString = stringCopy("0");
}

Byte::~Byte() {
    if (this->originalString != nullptr) {
        free(this->originalString);
    }
}

char Byte::charValue() const {
    return (char) this->original;
}

byte Byte::byteValue() const {
	return this->original;
}

int Byte::compare(byte byteA, byte byteB) {
    return byteA - byteB;
}

int Byte::compareTo(const Byte &other) const {
	return this->original - other.original;
}

Byte Byte::decode(String stringToDecode) {
    int value = Integer::decode(stringToDecode).intValue();
    if (value < Byte::MIN_VALUE || value > Byte::MAX_VALUE) {
        throw NumberFormatException("out of byte range");
    }
    return (byte) value;
}

double Byte::doubleValue() const {
	return (double) this->original;
}

//TODO need instanceof
boolean Byte::equals(Byte object) {
//    boolean isByte = instanceof<Byte>(object);
//	if (isByte) {
//        return this->original == parseByte(object.toString());
//    }
//	return false;
    return this->original == parseByte(object.toString());
}

float Byte::floatValue() const {
    return (float) this->original;
}

long Byte::hashCode() const {
    return (long) this->original;
}

int Byte::hashCode(byte value) {
    return (int) value;
}

int Byte::intValue() const {
    return (int) this->original;
}

long Byte::longValue() const {
    return (long) this->original;
}

byte Byte::parseByte(String stringToParse) {
	return parseByte(stringToParse, 10);
}

byte Byte::parseByte(String stringToParse, int radix) {
    int value = Integer::parseInt(stringToParse, radix);
    if (value < Byte::MIN_VALUE || value > Byte::MAX_VALUE) {
        throw NumberFormatException("out of byte range");
    }
    return (byte)value;
}

short Byte::shortValue() const {
    return (short) this->original;
}

string Byte::toString() const {
    return this->originalString;
}

String Byte::toString(byte byteValue) {
    return Integer::toString((int) byteValue, 10);
}

int Byte::toUnsignedInt(byte byteValue) {
    return ((int) byteValue) & 0xff;
}

long Byte::toUnsignedLong(byte byteValue) {
    return ((long) byteValue) & 0xffL;
}

Byte Byte::valueOf(byte byteValue) {
    return ByteCache::getInstance()->getByteAtIndex((int) byteValue);
}

Byte Byte::valueOf(String stringValue) {
    return Byte(parseByte(stringValue));
}

Byte Byte::valueOf(String stringValue, int radix) {
    return Byte(parseByte(stringValue, radix));
}

Byte Byte::operator+(const Byte &target) {
	return this->original + target.original;
}

Byte Byte::operator-(const Byte &target) {
	return this->original - target.original;
}

Byte Byte::operator/(const Byte &target) {
    if (target.intValue() == 0) {
        throw ArithmeticException("Divide by zero");
    }
	return this->original / target.original;
}

Byte Byte::operator%(const Byte &target) {
    if (target.intValue() == 0) {
        throw ArithmeticException("Divide by zero");
    }
	return this->original % target.original;
}

Byte Byte::operator*(const Byte &target) {
	return this->original * target.original;
}

boolean Byte::operator==(const Byte &target) {
	return this->original == target.original;
}

boolean Byte::operator!=(const Byte &target) {
	return this->original != target.original;
}

boolean Byte::operator<(const Byte &target) {
	return this->original < target.original;
}

boolean Byte::operator>(const Byte &target) {
	return this->original > target.original;
}

boolean Byte::operator<=(const Byte &target) {
	return this->original <= target.original;
}

boolean Byte::operator>=(const  Byte &target) {
	return this->original >= target.original;
}

Byte &Byte::operator-=(const Byte &target) {
    free((this->originalString));
    this->original -= target.original;
    this->originalString = stringFromInt(this->original);
    return *this;
}

Byte &Byte::operator+=(const Byte &target) {
    free((this->originalString));
    this->original += target.original;
    this->originalString = stringFromInt(this->original);
    return *this;
}

Byte &Byte::operator*=(const Byte &target) {
    free((this->originalString));
    this->original *= target.original;
    this->originalString = stringFromInt(this->original);
    return *this;
}

Byte &Byte::operator/=(const Byte &target) {
    if (target.intValue() == 0) {
        throw ArithmeticException("Divide by zero");
    }
    free((this->originalString));
    this->original /= target.original;
    this->originalString = stringFromInt(this->original);
    return *this;
}

Byte &Byte::operator%=(const Byte &target) {
    if (target.intValue() == 0) {
        throw ArithmeticException("Divide by zero");
    }
    free((this->originalString));
    this->original %= target.original;
    this->originalString = stringFromInt(this->original);
    return *this;
}

Byte &Byte::operator=(const Byte &target) {
    free((this->originalString));
    this->original = target.original;
    this->originalString = stringFromInt(this->original);
    return *this;
}

Byte::Byte(const Byte &anotherByte) {
    this->original = anotherByte.original;
    this->originalString = stringFromInt(this->original);
}
