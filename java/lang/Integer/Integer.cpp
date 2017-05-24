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

#include "Integer.hpp"

using namespace Java::Lang;

/**
 * Integer initialization
 *
 * @param original
 */
Integer::Integer() {
    this->original = 0;
}

/**
 * Integer initialization
 *
 * @param original
 */
Integer::Integer(int original) {
   this->original = original;
}

/**
 * Integer initialization
 *
 * @param original
 */
Integer::Integer(const Integer &integer) {
    this->original = integer.original;
}

Integer::~Integer() {
}

/**
 * Parse integer
 *
 * @param target
 * @return Integer
 */
Integer *Integer::parseInt(String target) {
    return new Integer(string_to_int(target.toString()));
}

/**
 * Integer to String
 *
 * @return String
 */
string Integer::toString() const {
    return string_from_int(this->original);
}

/**
 * Integer to Char
 *
 * @return char
 */
char Integer::charValue() const {
    return string_to_char(string_from_int(this->original));
}

/**
 * Integer to String
 *
 * @return CString
 */
string Integer::stringValue() const  {
    return String::valueOf(this->original).toString();
}

/**
 * Short value of Integer
 *
 * @return short
 */
short Integer::shortValue() const  {
    return this->original;
}

/**
 * Integer value
 *
 * @return int
 */
int Integer::intValue() const  {
    return this->original;
}

/**
 * Integer value in Long
 *
 * @return int
 */
long Integer::longValue() const  {
    return this->original;
}

/**
 * Integer value in float
 *
 * @return int
 */
float Integer::floatValue() const  {
    return (float) this->original;
}

/**
 * Integer value in double
 *
 * @return int
 */
double Integer::doubleValue() const  {
    return (double) this->original;
}

/**
 * Make a summation with target Integer
 *
 * @return Integer
 */
Integer Integer::operator+(const Integer &target) {
    return this->original + target.original;
}

/**
 * Make a subtraction with target Integer
 *
 * @return Integer
 */
Integer Integer::operator-(const Integer& target) {
    return this->original - target.original;
}

/**
 * Compare this Integer is equal target
 *
 * @return bool
 */
boolean Integer::operator==(const Integer& target) {
    return this->original == target.original;
}

/**
 * Compare this Integer is not equal target
 *
 * @return bool
 */
boolean Integer::operator!=(const Integer& target) {
    return !this->operator==(target);
}

/**
 * Compare this Integer is less than target
 *
 * @return bool
 */
boolean Integer::operator<(const Integer& target) const {
    return this->original < target.original;
}

/**
 * Compare this Integer is more than target
 *
 * @return bool
 */
boolean Integer::operator>(const Integer& target) {
    return this->original > target.original;
}

/**
 * Compare this Integer is equal or less than target
 *
 * @return bool
 */
boolean Integer::operator<=(const Integer& target) {
    return this->original <= target.original;
}

/**
 *  Compare this Integer is equal or more than target
 *
 * @return bool
 */
boolean Integer::operator>=(const Integer& target) {
    return this->original >= target.original;
}

/**
 *  Make a division from this Integer with target
 *
 * @return Integer
 */
Integer Integer::operator/(const Integer& target) {
    return (this->original / target.original);
}

/**
 * Make a multiple from this Integer with target
 *
 * @return Integer
 */
Integer Integer::operator*(const Integer& target) {
    return (this->original * target.original);
}

/**
 * Make a modulo from this Integer with target
 *
 * @return Integer
 */
Integer Integer::operator%(const Integer& target) {
    return (this->original % target.original);
}