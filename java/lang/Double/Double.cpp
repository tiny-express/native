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

#include "Double.hpp"

using namespace Java::Lang;

Double::Double() {
	this->original = 0;
	this->string_original = string_from_double(this->original);
}

Double::Double(double original) {
	this->original = original;
	this->string_original = string_from_double(this->original);
}

Double::Double(const Double &doubleNumber) {
	this->original = doubleNumber.original;
	this->string_original = string_from_double(this->original);
}

Double::~Double() {
	if (this->string_original != NULL) {
		free(this->string_original);
	}
}

Double Double::parseDouble(String target) {
    return Double(string_to_double(target.toString()));
}

string Double::toString() const {
	return (string) this->string_original;
}

char Double::charValue() const {
    string convertResult = string_from_double(this->original);
    char charValueResult = string_to_char(convertResult);
    free(convertResult);
    return charValueResult;
}

string Double::stringValue() const {
        return (string) this->toString();
}

short Double::shortValue() const {
    return (short) this->original;
}

int Double::intValue() const {
    return (int) this->original;
}

long Double::longValue() const {
    return (long) this->original;
}

float Double::floatValue() const {
    return (float) this->original;
}

double Double::doubleValue() const {
    return this->original;
}

byte Double::byteValue() const {
    return (byte) this->original;
}

/// ---------- Arithmetic Operators ----------

Double Double::operator+(const Double &target) {
    return Double(this->original + target.original);
}

Double Double::operator-(const Double &target) {
    return Double(this->original - target.original);
}

Double Double::operator*(const Double &target) {
    return Double( this->original * target.original );
}

Double Double::operator/(const Double &target) {
    return Double( this->original / target.original );
}

// /**
//  * Make a modulo from this Double with target
//  *
//  * @return Double
//  */
// Double Double::operator%(const Double &target) {
// 	return ( this->original % target.original );
// }

/// ---------- Relational Operators ----------

boolean Double::operator==(const Double &target) const {
    return (boolean) (this->original == target.original);
}

boolean Double::operator!=(const Double &target) const {
    return (boolean ) (!this->operator==(target));
}

boolean Double::operator<(const Double &target) const {
    return (boolean) (this->original < target.original);
}

boolean Double::operator>(const Double &target) const {
    return (boolean ) (this->original > target.original);
}

boolean Double::operator>=(const Double &target) const {
    return (boolean) (this->original >= target.original);
}

boolean Double::operator<=(const Double &target) const {
    return (boolean) (this->original <= target.original);
}

/// ---------- Logical Operators ----------

boolean Double::operator&&(const Double &target) const {
    return (boolean) (this->original && target.original);
}

boolean Double::operator||(const Double &target) const {
    return (boolean) (this->original || target.original);
}

/// ---------- Assignment Operators ----------


Double Double::operator=(const Double &target) {
    this->original = target.original;
    free(this->string_original);
    this->string_original = string_from_double(this->original);
    return *this;
}

Double Double::operator+=(const Double &target) const {
    return (Double) (this->original + target.original);
}

Double Double::operator-=(const Double &target) const {
    return (Double) (this->original - target.original);
}

Double Double::operator*=(const Double &target) const {
    return (Double) (this->original * target.original);
}

Double Double::operator/=(const Double &target) const {
    return (Double) (this->original / target.original);
}
