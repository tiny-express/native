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

extern "C" {
#include "../crypto.h"
#include "../string.h"
}

#include <iostream>

/**
 * MD5 Encode for char pointer
 *
 * @param target
 * @return MD5 encoded string
 */
char *md5(char *target) {
	char *result = md5_encode((unsigned char *) target);
	return result;
}

/**
 * MD5 Encode for std::string
 *
 * @param std::string
 * @return MD5 encoded string
 */
char *md5(std::string target) {
	char *result = md5_encode((unsigned char *) target.c_str());
	return result;
}

/**
 * MD5 Encode for short
 *
 * @param Short number
 * @return MD5 encoded string
 */
char *md5(short target) {
	char *result = md5_encode((unsigned char *) string_from_short(target));
	return result;
}

/**
 * MD5 Encode for int
 *
 * @param Short number
 * @return MD5 encoded string
 */
char *md5(int target) {
	char *result = md5_encode((unsigned char *) string_from_int(target));
	return result;
}

/**
 * MD5 Encode for long
 *
 * @param Long number
 * @return Pointer char md5 encoded string
 */
char *md5(long target) {
	char *result = md5_encode((unsigned char *) string_from_long(target));
	return result;
}

/**
 * MD5 Encode for float
 *
 * @param Long number
 * @return Pointer char md5 encoded string
 */
char *md5(float target) {
	char *result = md5_encode((unsigned char *) string_from_float(target));
	return result;
}

/**
 * MD5 Encode for double
 *
 * @param target
 * @return md5 encoded string
 */
char *md5(double target) {
	char *result = md5_encode((unsigned char *) string_from_double(target));
	return result;
}






