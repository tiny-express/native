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

#include "Boolean.hpp"

/**
 * Boolean Constructor
 * Allocates a Boolean object representing the value argument.
 *
 * @param target
 */
Boolean::Boolean(const boolean &target) {
    this->original = target;
}

/**
 * Boolean Constructor
 * Allocates a Boolean object representing the value true
 * if the string argument is not null and is equal,
 * ignoring case, to the string "true".
 * Otherwise, allocate a Boolean object representing the value false.
 *
 * @param target
 */
Boolean::Boolean(const_string target) {
    if (strcmp(target, "True") == 0) {
        this->original = true;
    } else {
        this->original = false;
    }
}

/**
 * Boolean Destructor
 */
Boolean::~Boolean() {

}

/**
 * Returns the value of this Boolean object as a boolean primitive.
 *
 * @return `true' or `false'
 */
boolean Boolean::booleanValue() const {
    return this->original;
}

/**
 * Compare tow boolean values
 *
 * @param target1
 * @param target2
 * @return Return 0 if this object represents the same boolean
 * value as the argument; a positive value if this object represents
 * true and the argument represents false; and a negative value if this
 * object represents false and the argument represents true
 */
int Boolean::compare(const boolean &target1, const boolean &target2) {
    return (target1 - target2);
}

/**
 * Compares this Boolean instance with another.
 *
 * @param target
 * @return Return 0 if this object represents the same boolean
 * value as the argument; a positive value if this object represents
 * true and the argument represents false; and a negative value if this
 * object represents false and the argument represents true
 */
int Boolean::compareTo(const Boolean &target) const {
    return Boolean::compare(this->original, target.original);
}

/**
 * Returns true if and only if the system property named
 * by the argument exists and is equal to the string "true".
 *
 * @param target
 * @return boolean
 */
boolean Boolean::getBoolean(const_string target) {
    if (strcmp(target, "True") == 0) {
        return true;
    }

    return false;
}

/**
 * A hash code value for this object.
 *
 * @return long
 */
long Boolean::hashCode() const {
    return Object::hashCode();
}

/**
 * Parses the string argument as a boolean.
 * The boolean returned represents the value true
 * if the string argument is not null and is equal,
 * ignoring case, to the string "true".
 *
 * @param target
 * @return
 */
boolean Boolean::parseBoolean(const_string target) {
    return Boolean::getBoolean(target);
}

/**
 * Returns a String object representing the specified boolean.
 *
 * @return string
 */
string Boolean::toString() const {
    if (this->original == 1) {
        return (string)"True";
    }

    return (string)"False";
}

/**
 * Returns a String object representing the specified boolean.
 *
 * @param target
 * @return
 */
string Boolean::toString(const boolean &target) {
    if (target == 1) {
        return (string)"True";
    }

    return (string)"False";
}

/**
 * Returns a Boolean instance representing the specified boolean value.
 *
 * @param target
 * @return Boolean
 */
Boolean Boolean::valueOf(boolean target) {
    return target;
}

/**
 * Returns a Boolean with a value represented by the specified string.
 *
 * @param target
 * @return boolean
 */
boolean Boolean::valueOf(const_string target) {
    return Boolean::parseBoolean(target);
}
