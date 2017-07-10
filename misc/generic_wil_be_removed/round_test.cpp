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

extern "C" {
#include "../../unit_test.h"
}

#include "../../library.hpp"

TEST (Generic, Round) {
	
	double number = 1.5345;
	double result = round(number, 2);
	ASSERT_TRUE(result == 1.53);
	
	result = round(number, 3);
	ASSERT_TRUE(1.535 == result);
	
	result = round(number, 0);
	ASSERT_TRUE(2 == result);
	
	number = -2.3;
	result = round(number, 0);
	ASSERT_TRUE(-2.0 == result);
	
	number = -3.8;
	result = round(number, 0);
	ASSERT_TRUE(-4 == result);
	
	number = -5.5;
	result = round(number, 0);
	ASSERT_TRUE(-6.0 == result);
	
	float target1 = 2.3;
	float result1 = round(target1, 0);
	ASSERT_TRUE(2 == result1);
	
	target1 = 3.8;
	result1 = round(target1, 0);
	ASSERT_TRUE(4 == result1);
	
	target1 = -2.3;
	result1 = round(target1, 0);
	ASSERT_TRUE(-2.0 == result1);
	
	target1 = -3.8;
	result1 = round(target1, 0);
	ASSERT_TRUE(-4 == result1);
	
}