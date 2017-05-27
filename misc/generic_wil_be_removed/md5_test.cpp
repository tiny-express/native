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
#include "../../unit_test.h"
}

#include "../../library.hpp"

TEST (Generic, Md5) {
	char *result1 = md5(NULL);
	const char *expect1 = "cfcd208495d565ef66e7dff9f98764da";
	ASSERT_STR(expect1, result1);
	
	short shortNumber = 1234;
	char *result2 = md5(shortNumber);
	const char *expect2 = "81dc9bdb52d04dc20036dbd8313ed055";
	ASSERT_STR(expect2, result2);
	
	long longNumber = 0;
	char *result3 = md5(longNumber);
	const char *expect3 = "cfcd208495d565ef66e7dff9f98764da";
	ASSERT_STR(expect3, result3);
	
	double doubleNumber = 132412.341234;
	char *result4 = md5(doubleNumber);
	const char *expect4 = "b018ba22165908a093cdd171c121a749";
	ASSERT_STR(expect4, result4);
	
	std::string str = "happy";
	char *result5 = md5(str);
	const char *expect5 = "56ab24c15b72a457069c5ea42fcfc640";
	ASSERT_STR(expect5, result5);
	
	char *pointerChar = (char *) "";
	char *result6 = md5(pointerChar);
	const char *expect6 = "d41d8cd98f00b204e9800998ecf8427e";
	ASSERT_STR(expect6, result6);
}
