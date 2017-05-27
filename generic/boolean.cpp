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

#include "../library.hpp"

/**
 * Boolean value of char pointer
 *
 * @param target
 * @return bool
 */
bool Boolean(char *target) {
	return string_to_boolean(string_lower(target));
}

/**
 * Boolean value of std::string
 *
 * @param target
 * @return bool
 */
template <> bool Boolean(std::string target) {
	return string_to_double((char *) target.c_str()); //here
}
template bool Boolean<std::string>(std::string target);

/**
 * Boolean value of char pointer
 *
 * @param target
 * @return bool
 */

template <> bool Boolean(char *target) {
	return string_to_double(target);
}

template bool Boolean<char *>(char *target);
bool Boolean(std::string target) {
	return string_to_boolean(string_lower((char *) target.c_str()));
}

/**
 * Boolean value of integer
 *
 * @param targetl
 * @return bool
 */
bool Boolean(int target) {
	return (bool) target;
}

/**
 * Boolean value of long
 *
 * @param target
 * @return 0
 */
bool Boolean(long target) {
	return (bool) target;
}

template bool Boolean<double>(double target);

/**
 * Boolean value of boolean
 *
 * @param target
 * @return bool
 */
template <> bool Boolean(bool target) {
	return (bool) floor(target);
}

template bool Boolean<bool>(bool target);

