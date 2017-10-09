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

#include "../Common.hpp"
#include "../Test.hpp"

TEST (KernelCommon, LengthPointerChar) {
	auto data = (string) "Hello world";
	assertEquals(11, lengthPointerChar(data));
	
	assertEquals(11, lengthPointerChar("Hello world"));
	
	data = (string) "";
	assertEquals(0, lengthPointerChar(data));
	
	data = (string) "\0";
	assertEquals(0, lengthPointerChar(data));
	
	data = nullptr;
	assertEquals(0, lengthPointerChar(data));
	
	//  Please use calloc instead of malloc because it is dangerous
	//  data = malloc(10);
	//  assertEquals(0, lengthPointerChar(data));
	//  free(data);
}

TEST (KernelCommon, LengthPointerPointerChar) {

    char *data_null = nullptr;
    assertEquals(0, lengthPointerPointerChar((char **) data_null));

    char *data_raw[] = {
            (char *) "abc",
            (char *) "abd",
            (char *) "abf",
            (char *) "xyz",
            (char *) "123",
            (char *) "3456",
            nullptr
    };
    auto data1 = (char **) data_raw;
    assertEquals(6, lengthPointerPointerChar(data1));

    // Dynamic string
    int NUM = 135;
    auto data2 = (char **) calloc((size_t) NUM + 1, sizeof(char *));
    int i;
    for (i = 0; i < NUM; i++) {
        data2[i] = (string) "test";
    }
    data2[NUM] = nullptr;
    assertEquals(NUM, lengthPointerPointerChar(data2));
    free(data2);
}

TEST (KernelCommon, IsEmpty) {
	string target1 = nullptr;
	ASSERT_TRUE(isEmptyString(target1));

    auto target2 = (string) "";
	ASSERT_TRUE(isEmptyString(target2));

	auto target3 = (string) "abcd";
	ASSERT_FALSE(isEmptyString(target3));
}
