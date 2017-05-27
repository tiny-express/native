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
 * Print const pointer char to screen
 * @param target
 */
void print(const char *target) {
	std::cout << target << std::endl;
}

/**
 * Print poiter char to screen
 * @param target
 */
void print(char *target) {
	print((const char *) target);
}

/**
 * Print `std::string' to screen
 * @param target
 */
void print(std::string target) {
	std::cout << target << std::endl;
}

/**
 * Print `short' number to screen
 * @param target
 */
void print(short target) {
	std::cout << target << std::endl;
}

/**
 * Print `int' number to screen
 * @param target
 */
void print(int target) {
	std::cout << target << std::endl;
}

/**
 * Print `long' number to screen
 * @param target
 */
void print(long target) {
	std::cout << target << std::endl;
}

/**
 * Print `double' number to screen
 * @param target
 */
void print(double target) {
	std::cout << target << std::endl;
}

/**
 * Convert `std::vector<int>' to `char *' and print this to screen
 * @param target
 */
void print(std::vector<int> target) {
	const char *convertString = String(target);
	print(convertString);
}

/**
 * Convert `std::vector<double>' to `char *' and print this to screen
 * @param target
 */
void print(std::vector<double> target) {
	const char *convertString = String(target);
	print(convertString);
}


