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
//#define NOT_FOUND -1
//
///**
// * Linear Search
// * Complexity O(N)
// *
// * @param array
// * @param length
// * @param key
// * @return result
// */
//int linearSearch(int array[], int length, int key) {
//	register int index;
//	for (index = 0; index < length; index++) {
//		if (array[ index ] == key) {
//			return index;
//		}
//	}
//	return NOT_FOUND;
//}
//
///**
// * Binary Search
// * Complexity O(log(N))
// *
// * @param array
// * @param length
// * @param key
// * @return result
// */
//int binarySearch(int array[], int length, int key) {
//	register int middle, left, right;
//	left = 0;
//	right = length;
//	while (left <= right) {
//		middle = ( left + right ) / 2;
//		if (key == array[ middle ]) {
//			return middle;
//		}
//		if (key < array[ middle ]) {
//			right = middle - 1;
//		} else {
//			left = middle + 1;
//		}
//	}
//	return NOT_FOUND;
//}

