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
#include "../../../unit_test.h"
}

#include "LinkedList.hpp"

using namespace Java::Util;

TEST (JavaUtil, LinkedListAdd) {
	// Given linked list with 2 elements - Return size is 2 and added elements
	LinkedList<int> linkedList;
	linkedList.add(25);
	linkedList.add(24);
	ASSERT_EQUAL(2, linkedList.size());
	ASSERT_EQUAL(25, linkedList.getFirst());
	ASSERT_EQUAL(24, linkedList.getLast());
}

TEST (JavaUtil, LinkedListGetFirst) {
	// Given list of strings - Return first element
	LinkedList<String> linkedList;
	linkedList.add("Hello");
	linkedList.add("World");
	ASSERT_STR("Hello", linkedList.getFirst().toString());
}

TEST (JavaUtil, LinkedListGetLast) {
	// Given list of strings - Return last element
	LinkedList<String> linkedList;
	linkedList.add("Hello");
	linkedList.add("World");
	ASSERT_STR("World", linkedList.getLast().toString());
}

TEST (JavaUtil, LinkedListPeek) {
	//TODO - tucao will fix this
}

TEST (JavaUtil, LinkedListPoll) {
	//TODO - tucao will fix this
}

TEST (JavaUtil, LinkedListGetAndRemove) {
	/// Given valid LinkList<char> to test peek(), peek..(), poll(), poll..(), offer(), offer..()
	LinkedList<char> linkedList;
	linkedList.add('a');
	linkedList.add('b');
	linkedList.add('c');
	linkedList.add('d');
	linkedList.add('e');
	
	//peek(): return first element and must be equal to 'a'
	ASSERT_EQUAL('a', linkedList.peek());
	
	//peekFirst(): return first element and must be equal to 'a'
	ASSERT_EQUAL('a', linkedList.peekFirst());
	
	//peekLast(): return last element and must be equal to 'e'
	ASSERT_EQUAL('e', linkedList.peekLast());
	
	//pool(): return first element and must be equal to 'a'
	ASSERT_EQUAL('a', linkedList.poll());
	
	//pollFirst(): return first element and must be equal to 'a', and remove that element also, so next first element must be equal to 'b'
	ASSERT_EQUAL('a', linkedList.pollFirst());
	ASSERT_EQUAL('b', linkedList.getFirst());
	
	//pollFirst(): return first element and must be equal to 'e', and remove that element also, so next last element must be equal to 'd'
	ASSERT_EQUAL('e', linkedList.pollLast());
	ASSERT_EQUAL('d', linkedList.getLast());
}

TEST (JavaUtil, LinkedListRemove) {
	/// Given valid LinkList<float> to test remove(), remove..()
	LinkedList<float> linkedList;
	linkedList.add(1.3);
	linkedList.add(52.2);
	linkedList.add(0.2);
	linkedList.add(7.3);
	linkedList.add(10.3);
	
	// remove(): remove first element, so next getFirst must be equal to 52.2 - this test case wrapped removeFirst() also
	linkedList.remove();
	ASSERT_DBL_NEAR(52.2, linkedList.getFirst());
	
	// removeLast(): remove last element, so next getLast must be equal to 7.3
	linkedList.removeLast();
	ASSERT_DBL_NEAR(7.3, linkedList.getLast());
}

TEST (JavaUtil, LinkedListSize) {
	// Given empty linked list - Return size of list is zero
	LinkedList<int> linkedList;
	ASSERT_EQUAL(0, linkedList.size());
	
	// Append two elements to linked list - Return two elements
	linkedList.add(25);
	linkedList.add(25);
	ASSERT_EQUAL(2, linkedList.size());
}