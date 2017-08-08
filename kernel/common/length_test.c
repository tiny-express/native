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

#include "../builtin.h"
#include "../test.h"

TEST (KernelCommon, LengthPointerChar) {
	char *data = "Hello world";
	ASSERT_EQUAL(11, length_pointer_char(data));
	
	ASSERT_EQUAL(11, length_pointer_char("Hello world"));
	
	data = "";
	ASSERT_EQUAL(0, length_pointer_char(data));
	
	data = "\0";
	ASSERT_EQUAL(0, length_pointer_char(data));
	
	data = NULL;
	ASSERT_EQUAL(0, length_pointer_char(data));
	
	//  Please use calloc instead of malloc because it is dangerous
	//  data = malloc(10);
	//  ASSERT_EQUAL(0, length_pointer_char(data));
	//  free(data);
}

TEST (KernelCommon, LengthPointerPointerChar) {
	
	char *data_null = NULL;
	ASSERT_EQUAL(0, length_pointer_pointer_char((char **) data_null));
	
	char *data_raw[] = {
		(char *) "abc",
		(char *) "abd",
		(char *) "abf",
		(char *) "xyz",
		(char *) "123",
		(char *) "3456",
		'\0'
	};
	char **data1 = (char **) data_raw;
	ASSERT_EQUAL(6, length_pointer_pointer_char(data1));
	
	// Dynamic string
	int NUM = 135;
	char **data2 = (char **) calloc(NUM + 1, sizeof(char *));
	int i;
	for (i = 0; i < NUM; i++) {
		data2[ i ] = (char *) "test";
	}
	data2[ NUM ] = '\0';
	ASSERT_EQUAL(NUM, length_pointer_pointer_char(data2));
	free(data2);
}

TEST (KernelCommon, LengthShort) {
	short input = 0;
	ASSERT_EQUAL(1, length_short(input));
	input = 123;
	ASSERT_EQUAL(3, length_short(input));
}

TEST (KernelCommon, LengthInt) {
	int input = 0;
	ASSERT_EQUAL(1, length_int(input));
	input = 123;
	ASSERT_EQUAL(3, length_int(input));
}

TEST (KernelCommon, LengthLong) {
	long input = 0;
	ASSERT_EQUAL(1, length_long(input));
	input = 123456;
	ASSERT_EQUAL(6, length_long(input));
}

TEST (KernelCommon, LengthDouble) {
	double input = 0;
	ASSERT_EQUAL(1, length_double(input));
	input = 123.456;
	ASSERT_EQUAL(7, length_double(input));
}

TEST (KernelCommon, LengthFloat) {
	float input = 1.23;
	ASSERT_EQUAL(4, length_float(input));
	input = 0.345;
	ASSERT_EQUAL(5, length_float(input));
}


