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
 * @param target
 */
Integer::Integer(int target) {
   this->value = target;
}

/**
 * Parse Char to Integer
 *
 * @param target
 * @return Integer
 */
Integer* Integer::parseChar(char target) {
    return new Integer(string_to_int(string_from_char(target)));
}

/**
 * Parse integer
 *
 * @param target
 * @return Integer
 */
Integer* Integer::parseInt(int target) {
    return new Integer(target);
}

/**
 * Parse CString to Integer
 *
 * @param target
 * @return Integer
 */
Integer* Integer::parseCString(char *target) {
    return new Integer(string_to_int(target));
}

/**
 * Parse String to Integer
 *
 * @param target
 * @return Integer
 */
Integer* Integer::parseString(std::string target) {
    return new Integer(string_to_int((char*) target.c_str()));
}

/**
 * Parse Long to Integer
 *
 * @param target
 * @return Integer
 */
Integer* Integer::parseLong(long target) {
    if ((target >= INT_MIN) && (target <= INT_MAX)) {
        return new Integer((int) target);
    }
    return new Integer(0);
}

/**
 * Parse Float to Integer
 *
 * @param target
 * @return Integer
 */
Integer* Integer::parseFloat(float target) {
    return new Integer((int) floor(target));
}

/**
 * Parse Float to Integer
 *
 * @param target
 * @return Integer
 */
Integer* Integer::parseDouble(double target) {
    return new Integer((int) floor(target));
}

/**
 * Integer to String
 *
 * @return String
 */
String Integer::toString() const  {
    return string_from_int(this->value);
}

/**
 * Integer to Char
 *
 * @return char
 */
char Integer::charValue() const {
    return string_to_char(string_from_int(this->value));
}

/**
 * Integer to CString
 *
 * @return CString
 */
char* Integer::cstringValue() const  {
    return string_from_int(this->value);
}

/**
 * Integer to String
 *
 * @return CString
 */
std::string Integer::stringValue() const  {
    return std::string(this->cstringValue());
}

/**
 * Short value of Integer
 *
 * @return short
 */
short Integer::shortValue() const  {
    return this->value;
}

/**
 * Integer value
 *
 * @return int
 */
int Integer::intValue() const  {
    return this->value;
}

/**
 * Integer value in Long
 *
 * @return int
 */
long Integer::longValue() const  {
    return (long) this->value;
}

/**
 * Integer value in float
 *
 * @return int
 */
float Integer::floatValue() const  {
    return (float) this->value;
}

/**
 * Integer value in double
 *
 * @return int
 */
double Integer::doubleValue() const  {
    return (double) this->value;
}
