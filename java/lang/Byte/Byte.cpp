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

/**
 * Compare this Byte to another Byte object
 *
 * @param object
 * @return true if object is a Byte and has the same value as this Bytes; false otherwise
 */
//TODO need instanceof
boolean Bytes::equals(Object object) {

    boolean isByte = instanceof<Bytes>(object);
	if (isByte) {
        return this->original == parseByte(object.toString());
    }
	return false;
}

/**
 * Returns the value of this Byte as an float.
 *
 * @return float
 */
float Bytes::floatValue() const {
    return (float) this->original;
}

/**
 * Returns a hash code for this Byte
 *
 * @return int
 */
int Bytes::hashCode() {
    return (int) this->original;
}

/**
 * Returns a hash code for this Byte
 *
 * @param value
 * @return int
 */
int Bytes::hashCode(byte value) {
    return (int) value;
}

/**
 * Returns the value of this Byte as an int.
 *
 * @return int
 */
int Bytes::intValue() const {
    return (int) this->original;
}

/**
 * Returns the value of this Byte as an long.
 *
 * @return long
 */
long Bytes::longValue() const {
    return (long) this->original;
}

/**
 * Parse the parameter string as a byte
 *
 * @param stringToParse
 * @return Byte
 */
byte Bytes::parseByte(String stringToParse) {
	return parseByte(stringToParse, 10);
}
/**
 * Parse the parameter string as a byte with radix =10
 *
 * @param stringToParse
 * @param radix
 * @return
 */
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
/**
 * Returns the value of this Byte as an short.
 *
 * @return short
 */
short Bytes::shortValue() const {
    return (short) this->original;
}

string Bytes::stringValue() const {
    return String::valueOf(this->original).toString();
}

/**
 * Returns a String object representing this Byte's value
 *
 * @return String
 */
String Bytes::toString() {
    return String::valueOf((int) this->original);
}

/**
 * Returns a new String object representing the specified byte with radix = 10
 *
 * @param byteValue
 * @return String
 */
String Bytes::toString(byte byteValue) {
    //TODO need Integer.toString(int, radix)
    //return Integer::toString((int) byteValue, 10);
}

/**
 * Converts the argument to an int by an unsigned conversion.
 *
 * @param byteValue
 * @return int
 */
int Bytes::toUnsignedInt(byte byteValue) {
    return ((int) byteValue) & 0xff;
}

/**
 * Converts the argument to an int by an unsigned conversion.
 *
 * @param byteValue
 * @return long
 */
long Bytes::toUnsignedLong(byte byteValue) {
    return ((long) byteValue) & 0xffL;
}

/**
 * Returns a Byte instance representing the specified byte value.
 *
 * @param byteValue
 * @return Bytes
 */
Bytes Bytes::valueOf(byte byteValue) {
	const int offset = 128;
    return  ByteCache::getInstance()->cache[((int) byteValue+offset)];
}

/**
 * Returns a Byte instance representing the specified String value.
 *
 * @param stringValue
 * @return Bytes
 */
Bytes Bytes::valueOf(String stringValue) {
    return Bytes(parseByte(stringValue));
}

/**
 * Returns a Byte instance representing the specified String value with radix
 *
 * @param stringValue
 * @param radix
 * @return
 */
Bytes Bytes::valueOf(String stringValue, int radix) {
    return Bytes(parseByte(stringValue, radix));
}

/**
 * Make a summation with target Byte
 *
 * @param target
 * @return Byte
 */
Bytes Bytes::operator+(const Bytes &target) {
	return this->original + target.original;
}

/**
 * Make a subtraction with target Byte
 *
 * @param target
 * @return Byte
 */
Bytes Bytes::operator-(const Bytes &target) {
	return this->original - target.original;
}

/**
 *  Make a division from this Byte with target
 *
 * @param target
 * @return Byte
 */
Bytes Bytes::operator/(const Bytes &target) {
	return  this->original / target.original;
}

/**
 * Make a modulo from this Byte with target
 *
 * @param target
 * @return Byte
 */
Bytes Bytes::operator%(const Bytes &target) {
	return this->original % target.original;
}

/**
 * Make a multiplication from this Byte with target
 *
 * @param target
 * @return Byte
 */
Bytes Bytes::operator*(const Bytes &target) {
	return this->original * target.original;
}

/**
 * Compare 2 Byte
 *
 * @param target
 * @return true if target Byte is equal to this Byte; false otherwise
 */
boolean Bytes::operator==(const Bytes &target) {
	return this->original == target.original;
}

/**
 * Compare 2 Byte
 *
 * @param target
 * @return true if target Byte is not equal to this Byte; false otherwise
 */
boolean Bytes::operator!=(const Bytes &target) {
	return this->original != target.original;
}

/**
 * Determine if this Byte is smaller than target
 *
 * @param target
 * @return true if this Byte is smaller than target; false otherwise
 */
boolean Bytes::operator<(const Bytes &target) {
	return this->original < target.original;
}

/**
 * Determine if this Byte is bigger than target
 *
 * @param target
 * @return true if this Byte is bigger than target; false otherwise
 */
boolean Bytes::operator>(const Bytes &target) {
	return this->original > target.original;
}

/**
 * Determine if this Byte is equal or less than target
 *
 * @param target
 * @return true if this Byte is equal or less than target; false otherwise
 */
boolean Bytes::operator<=(const Bytes &target) {
	return this->original <= target.original;
}

/**
 * Determine if this Byte is equal or bigger than target
 *
 * @param target
 * @return true if this Byte is equal or bigger than target; false otherwise
 */
boolean Bytes::operator>=(const  Bytes &target) {
	return this->original >= target.original;
}

/**
 * Make a subtraction from this Byte with target and assign the result value to this Byte
 *
 * @param target
 * @return Byte
 */
void Bytes::operator-=(const Bytes &target) {
    this->original -= target.original;
}

/**
 * Make an summation from this Byte with target and assign the result value to this Byte
 *
 * @param target
 * @return Byte
 */
void Bytes::operator+=(const Bytes &target) {
    this->original += target.original;
}

/**
 * Make a multiplication from this Byte with target and assign the result value to this Byte
 *
 * @param target
 * @return Byte
 */
void Bytes::operator*=(const Bytes &target) {
    this->original *= target.original;
}

/**
 * Make a division from this Byte with target and assign the result value to this Byte
 *
 * @param target
 * @return Byte
 */
void Bytes::operator/=(const Bytes &target) {
    this->original /= target.original;
}
/**
 * Make a modulo from this Byte with target and assign the result value to this Byte
 *
 * @param target
 * @return Byte
 */
void Bytes::operator%=(const Bytes &target) {
    this->original %= target.original;
}

/**
 *  Assign the value of target to this Byte
 *
 * @param target
 * @return Byte
 */
Bytes &Bytes::operator=(const Bytes &target) {
    this->original = target.original;
}





















