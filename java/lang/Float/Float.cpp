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

#include "Float.hpp"

using namespace Java::Lang;

Float::Float() {
    this->original = 0;
    this->originalString = string_from_float(this->original);
}

Float::Float(float original) {
    this->original = original;
    this->originalString = string_from_float(this->original);
}

Float::Float(const Float &floatNumber) {
    this->original = floatNumber.original;
    this->originalString = string_from_float(this->original);
}

Float::~Float() {
    if (this->originalString != NULL) {
        free(this->originalString);
    }
}

Float Float::operator+(const Float &target) {
    return Float(this->original + target.original);
}

Float Float::operator-(const Float &target) {
    return Float(this->original - target.original);
}

Float Float::operator*(const Float &target) {
    return Float( this->original * target.original );
}

Float Float::operator/(const Float &target) {
    return Float( this->original / target.original );
}

boolean Float::operator==(const Float &target) const {
    return (boolean) (this->original == target.original);
}

// TODO(thoangminh): enable after finish method equals , compare
//boolean Float::operator==(const Float &target) const {
//    return (boolean) equals(target.original);
//}
//
//boolean Float::operator!=(const Float &target) const {
//    return (boolean) !equals(target.original);
//}
//
//boolean Float::operator<(const Float &target) const {
//    if (compare(this->doubleValue(), target.doubleValue()) == -1) {
//        return true;
//    }
//    return false;
//}
//
//boolean Float::operator>(const Float &target) const {
//    if (compare(this->doubleValue(), target.doubleValue()) == 1) {
//        return true;
//    }
//    return false;
//}
//
//boolean Float::operator>=(const Float &target) const {
//    if (compare(this->doubleValue(), target.doubleValue()) == 1
//        || compare(this->doubleValue(), target.doubleValue()) == 0) {
//
//        return true;
//    }
//    return false;
//}
//
//boolean Float::operator<=(const Float &target) const {
//
//    if (compare(this->doubleValue(), target.doubleValue()) == -1
//        || compare(this->doubleValue(), target.doubleValue()) == 0) {
//
//        return true;
//    }
//    return false;
//}

boolean Float::operator&&(const Float &target) const {
    return (boolean) (this->original && target.original);
}

boolean Float::operator||(const Float &target) const {
    return (boolean) (this->original || target.original);
}

Float Float::operator=(const Float &target) {
    this->original = target.original;
    free(this->originalString);
    this->originalString = string_from_float(this->original);
    return *this;
}

Float Float::operator+=(const Float &target) const {
    return (Float) (this->original + target.original);
}

Float Float::operator-=(const Float &target) const {
    return (Float) (this->original - target.original);
}

Float Float::operator*=(const Float &target) const {
    return (Float) (this->original * target.original);
}

Float Float::operator/=(const Float &target) const {
    return (Float) (this->original / target.original);
}

char Float::charValue() const {
    string convertResult = string_from_float(this->original);
    char charValueResult = string_to_char(convertResult);
    free(convertResult);
    return charValueResult;
}
// TODO(thoangminh): enable after finish toString()
//string Float::stringValue() const {
//    return (string) this->toString();
//}

float Float::floatValue() const {
    return this->original;
}

short Float::shortValue() const {
    return (short) this->original;
}

int Float::intValue() const {
    return (int) this->original;
}

/**
 * Long value
 *
 * @return long
 */
long Float::longValue() const {
    return (long) this->original;
}

/**
 * Float value
 *
 * @return
 */
double Float::doubleValue() const {
    return this->original;
}

/**
 * Float to String
 *
 * @return String
 */
string Float::toString() const {
    return this->originalString;
}

/**
 * String to Float
 *
 * @param target
 * @return Float
 */

//Float Float::parseFloat(String target) {
//    Float result = string_to_float(target.toString());
//    return result;
//}

boolean Float::isNaN(float v) {
    return v != v;
}