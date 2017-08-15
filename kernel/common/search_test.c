///**
// * Copyright (c) 2016 Food Tiny Project. All rights reserved.
// *
// * Redistribution and use in source and binary forms, with or without
// * modification, are permitted provided that the following conditions are met:
// *
// * Redistributions of source code must retain the above copyright
// * notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above
// * copyright notice, this list of conditions and the following disclaimer
// * in the documentation and/or other materials provided with the
// * distribution.
// *
// * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// */
//
//#include "../builtin.h"
//#include "../unit_test.h"
//
//
//TEST(KernelCommon, BinarySearch) {
//	int array[] = { 2, 3, 4, 7, 8, 10 };
//	int length = 6;
//	int key = 7;
//	int result = binary_search(array, length, key);
//	ASSERT_EQUAL(3, result);
//
//	length = -1;
//	key = -5;
//	result = binary_search(array, length, key);
//	ASSERT_EQUAL(-1, result);
//
//	length = 6;
//	key = 2;
//	result = binary_search(array, length, key);
//	ASSERT_EQUAL(0, result);
//
//	length = 6;
//	key = 10;
//	result = binary_search(array, length, key);
//	ASSERT_EQUAL(5, result);
//
//	length = 6;
//	key = 9;
//	result = binary_search(array, length, key);
//	ASSERT_EQUAL(-1, result);
//
//	length = -1;
//	key = 10;
//	result = binary_search(array, length, key);
//	ASSERT_EQUAL(-1, result);
//
//	length = 10;
//	key = 200;
//	result = binary_search(array, length, key);
//	ASSERT_EQUAL(-1, result);
//}
//
//
//TEST(KernelCommon, LinearSearch) {
//	int array[] = { 2, 3, 4, 7, 8, 10 };
//	int length = 6;
//	int key = 7;
//	int result = linear_search(array, length, key);
//	ASSERT_EQUAL(3, result);
//
//	length = -1;
//	key = 5;
//	result = linear_search(array, length, key);
//	ASSERT_EQUAL(-1, result);
//
//	length = 6;
//	key = 2;
//	result = linear_search(array, length, key);
//	ASSERT_EQUAL(0, result);
//
//	length = 6;
//	key = 10;
//	result = linear_search(array, length, key);
//	ASSERT_EQUAL(5, result);
//
//	length = 6;
//	key = -9;
//	result = linear_search(array, length, key);
//	ASSERT_EQUAL(-1, result);
//
//	length = -1;
//	key = -10;
//	result = linear_search(array, length, key);
//	ASSERT_EQUAL(-1, result);
//
//}
//

