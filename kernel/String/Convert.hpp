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

#ifndef NATIVE_KERNEL_STRING_CONVERT_HPP
#define NATIVE_KERNEL_STRING_CONVERT_HPP

#include "../Builtin.hpp"
#include "Process.hpp"

/**
 * Convert generic types to string
 *
 * @param target
 * @return string
 */
#define STR_FROM(NAME, TYPE, FORMAT); \
inline string stringFrom##NAME(TYPE target) {\
        string convert;\
        int length = asprintf(&convert, FORMAT, target);\
		if (length <= 0) {\
			return (string) "";\
		}\
        return convert;\
}

/**
 * Convert string to generic types
 *
 * @param target
 * @return generic values
 */
#define STR_TO(NAME, TYPE, FORMAT);\
inline TYPE stringTo##NAME(string target) {\
    if (target == nullptr || strcmp(target, "\0") == 0) return 0;\
        TYPE result;\
    sscanf(target, FORMAT, &result);\
    return result;\
}

STR_FROM(Short, short, "%d");
STR_FROM(Int, int, "%d");
STR_FROM(Long, long, "%ld");
STR_FROM(Float, float, "%g");
STR_TO(Short, short, "%hi");
STR_TO(Float, float, "%g");
STR_TO(Double, double, "%lg");

/**
 * String from char
 *
 * @param target
 * @return string
 */
inline string stringFromChar(char target) {
	if (target == '\0') {
		return stringCopy("");
	}
	auto *result = (char *) calloc(2, sizeof(char));
	result[ 0 ] = target;
	result[ 1 ] = '\0';
	return result;
}

/**
 * String to char
 *
 * @param target
 * @return string
 */
inline char stringToChar(string target) {
	if (isEmptyString(target)) {
		return '\0';
	}
	return target[ 0 ];
}

/**
 * String to int
 *
 * @param target
 * @return string
 */
inline int stringToInt(string target) {
	if (target == nullptr) {
		return 0;
	}
	return atoi(target);
}

/**
 * String to long
 *
 * @param target
 * @return string
 */
inline long stringToLong(string target) {
	if (target == nullptr) {
		return 0;
	}
	return atol(target);
}

/**
 * String to boolean
 *
 * @param target
 * @return true | false
 */
inline boolean stringToBoolean(string target) {
	if (lengthPointerChar(target) == 0) {
		return false;
	}
	string booleanValue = stringLower(target);
	if (stringEquals(booleanValue, (string) "true")) {
		free(booleanValue);
		return true;
	}
	if (stringToInt(booleanValue) == 0) {
		free(booleanValue);
		return false;
	}
	free(booleanValue);
	return true;
}

/**
 * String from boolean
 *
 * @param target
 * @return string
 */
inline string stringFromBoolean(int target) {
	if (!target) {
		return stringCopy("false");
	}

	return stringCopy("true");
}

inline string stringFromDouble(double target) {
	int precision = 15;

	// max_digits = 3 + MANTISSA_DIGIT - MIN_EXPONENT = 3 + 53 - (-1023)
	string result = (string) calloc(1079, sizeof(char));

	// Get string type of input number
	if (target == 0.0f && target < 0) {
		sprintf(result, "-%.*f", precision, target);
	} else {
		sprintf(result, "%.*f", precision, target);
	}

	return result;
}

#endif//NATIVE_KERNEL_STRING_CONVERT_HPP