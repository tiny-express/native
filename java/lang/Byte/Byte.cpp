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

#include "Byte.hpp"

using namespace Java::Lang;

ByteCache *ByteCache::instance = nullptr;

Bytes::Bytes(byte byteValue) {
	this->original = byteValue;
}

Bytes::Bytes(String inputString) {
	this->original = parseByte(inputString, 10);
}

Bytes::Bytes() = default;

Bytes::~Bytes() = default;

char Bytes::charValue() const {
    return (char) this->original;
}

byte Bytes::byteValue() {
	return this->original;
}

int Bytes::compare(byte byteA, byte byteB) {
    return byteA - byteB;
}

int Bytes::compareTo(const Bytes &other) const {
	return this->original - other.original;
}

//TODO need Integer::decode(string)
Bytes Bytes::decode(String stringToDecode) {
    /*int value = Integer::decode(stringToDecode);
    if (i < MIN_VALUE || i > MAX_VALUE)
        //TODO throw NumberFormatException
     return (byte)value;
     */
    return 0;//temporarily
}

double Bytes::doubleValue() const {
	return (double) this->original;
}

//TODO need instanceof
boolean Bytes::equals(Object object) {

    boolean isByte = instanceof<Bytes>(object);
	if (isByte) {
        return this->original == parseByte(object.toString());
    }
	return false;
}

float Bytes::floatValue() const {
    return (float) this->original;
}

int Bytes::hashCode() {
    return (int) this->original;
}

int Bytes::hashCode(byte value) {
    return (int) value;
}

int Bytes::intValue() const {
    return (int) this->original;
}

long Bytes::longValue() const {
    return (long) this->original;
}

byte Bytes::parseByte(String stringToParse) {
	return parseByte(stringToParse, 10);
}

//TODO need Integer::parseInt(string, int)
byte Bytes::parseByte(String stringToParse, int radix) {
    /*int value = Integer::parseInt(stringToParse, radix);
    if( value < MIN_VALUE || value > MAX_VALUE)
    {
        //TODO throw numberFormatException
    }
    return (byte)value;*/
    return 0;//temporarily
}

short Bytes::shortValue() const {
    return (short) this->original;
}

string Bytes::stringValue() const {
    return String::valueOf(this->original).toString();
}

String Bytes::toString() {
    return String::valueOf((int) this->original);
}

String Bytes::toString(byte byteValue) {
    //TODO need Integer.toString(int, radix)
    //return Integer::toString((int) byteValue, 10);
}

int Bytes::toUnsignedInt(byte byteValue) {
    return ((int) byteValue) & 0xff;
}

long Bytes::toUnsignedLong(byte byteValue) {
    return ((long) byteValue) & 0xffL;
}

Bytes Bytes::valueOf(byte byteValue) {
	const int offset = 128;
    return  ByteCache::getInstance()->cache[((int) byteValue+offset)];
}

Bytes Bytes::valueOf(String stringValue) {
    return Bytes(parseByte(stringValue));
}

Bytes Bytes::valueOf(String stringValue, int radix) {
    return Bytes(parseByte(stringValue, radix));
}

Bytes Bytes::operator+(const Bytes &target) {
	return this->original + target.original;
}

Bytes Bytes::operator-(const Bytes &target) {
	return this->original - target.original;
}

Bytes Bytes::operator/(const Bytes &target) {
	return  this->original / target.original;
}

Bytes Bytes::operator%(const Bytes &target) {
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

boolean Bytes::operator>=(const  Bytes &target) {
	return this->original >= target.original;
}

void Bytes::operator-=(const Bytes &target) {
    this->original -= target.original;
}

void Bytes::operator+=(const Bytes &target) {
    this->original += target.original;
}

void Bytes::operator*=(const Bytes &target) {
    this->original *= target.original;
}

void Bytes::operator/=(const Bytes &target) {
    this->original /= target.original;
}

void Bytes::operator%=(const Bytes &target) {
    this->original %= target.original;
}

Bytes &Bytes::operator=(const Bytes &target) {
    this->original = target.original;
}





















