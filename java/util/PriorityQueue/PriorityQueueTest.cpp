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
#include "../../../kernel/test.h"
}

#include "../../Lang.hpp"
#include "../PriorityQueue/PriorityQueue.hpp"
#include "../Vector/Vector.hpp"

using namespace Java::Util;

TEST (JavaUtil, PriorityQueueConstructor) {
	PriorityQueue<int> defaultConstructor;
	ASSERT_EQUAL(0, defaultConstructor.size());
	
	PriorityQueue<int> initializerListConstructor { 1, 2, 3, 4, 5 };
	ASSERT_EQUAL(5, initializerListConstructor.size());
	ASSERT_EQUAL(5, initializerListConstructor.peek());
	
	PriorityQueue<int> copyConstructor(initializerListConstructor);
	ASSERT_EQUAL(5, copyConstructor.size());
	ASSERT_EQUAL(5, copyConstructor.peek());
	
	try {
		PriorityQueue<int> customCapacityConstructor(-1);
	}
	catch (IllegalArgumentException ex) {
		ASSERT_STR("initialCapacity < 1", ex.getMessage().toString());
	}
}

TEST (JavaUtil, PriorityQueueAdd) {
	PriorityQueue<int> priorityQueue { 1, 2, 3, 4, 5 };
	ASSERT_EQUAL(5, priorityQueue.size());
	ASSERT_EQUAL(5, priorityQueue.peek());
	priorityQueue.add(10);
	ASSERT_EQUAL(6, priorityQueue.size());
	ASSERT_EQUAL(10, priorityQueue.peek());
}

TEST (JavaUtil, PriorityQueueClear) {
	PriorityQueue<int> priorityQueue { 1, 2, 3, 4, 5 };
	ASSERT_EQUAL(5, priorityQueue.size());
	priorityQueue.clear();
	ASSERT_EQUAL(0, priorityQueue.size());
}

TEST (JavaUtil, PriorityQueueContains) {
	PriorityQueue<int> priorityQueue { 1, 2, 3, 4, 5 };
	ASSERT_EQUAL(5, priorityQueue.size());
	ASSERT_EQUAL(5, priorityQueue.peek());
	ASSERT_TRUE(priorityQueue.contains(1));
	ASSERT_FALSE(priorityQueue.contains(7));
}

TEST (JavaUtil, PriorityQueueOffer) {
	PriorityQueue<int> priorityQueue { 1, 2, 3, 4, 5 };
	ASSERT_EQUAL(5, priorityQueue.size());
	ASSERT_EQUAL(5, priorityQueue.peek());
	priorityQueue.offer(10);
	ASSERT_EQUAL(6, priorityQueue.size());
	ASSERT_EQUAL(10, priorityQueue.peek());
}

TEST (JavaUtil, PriorityQueuePeek) {
	PriorityQueue<int> priorityQueue { 1, 2, 3, 4, 5 };
	ASSERT_EQUAL(5, priorityQueue.size());
	ASSERT_EQUAL(5, priorityQueue.peek());
	ASSERT_EQUAL(5, priorityQueue.size());
	priorityQueue.add(10);
	ASSERT_EQUAL(10, priorityQueue.peek());
	ASSERT_EQUAL(6, priorityQueue.size());
	
	PriorityQueue<Integer> integerPriorityQueue;
	ASSERT_EQUAL(0, integerPriorityQueue.size());
	ASSERT_TRUE(Integer() == integerPriorityQueue.peek()); // default value of Integer (same as null).
}

TEST (JavaUtil, PriorityQueuePoll) {
	PriorityQueue<int> priorityQueue { 1, 2, 3, 4, 5 };
	ASSERT_EQUAL(5, priorityQueue.size());
	ASSERT_EQUAL(5, priorityQueue.poll());
	ASSERT_EQUAL(4, priorityQueue.size());
	priorityQueue.add(10);
	ASSERT_EQUAL(10, priorityQueue.poll());
	ASSERT_EQUAL(4, priorityQueue.size());
	
	PriorityQueue<Integer> integerPriorityQueue;
	ASSERT_EQUAL(0, integerPriorityQueue.size());
	ASSERT_TRUE(Integer() == integerPriorityQueue.peek()); // default value of Integer.
}

TEST (JavaUtil, PriorityQueueRemove) {
	PriorityQueue<int> priorityQueue { 1, 2, 3, 4, 5 };
	ASSERT_EQUAL(5, priorityQueue.size());
	ASSERT_EQUAL(5, priorityQueue.peek());
	
	ASSERT_TRUE(priorityQueue.remove(5));
	ASSERT_EQUAL(4, priorityQueue.size());
	ASSERT_EQUAL(4, priorityQueue.peek());
	
	ASSERT_FALSE(priorityQueue.remove(10));
	ASSERT_EQUAL(4, priorityQueue.size());
	ASSERT_EQUAL(4, priorityQueue.peek());
}

TEST (JavaUtil, PriorityQueueSize) {
	PriorityQueue<int> priorityQueue;
	ASSERT_EQUAL(0, priorityQueue.size());
	priorityQueue.add(-1);
	ASSERT_EQUAL(1, priorityQueue.size());
}

TEST (JavaUtil, PriorityQueueToArray) {
	PriorityQueue<int> priorityQueue { 1, 2, 3, 4, 5 };
	ASSERT_EQUAL(5, priorityQueue.size());
	ASSERT_EQUAL(5, priorityQueue.peek());
	Array<int> arrayResult1 = priorityQueue.toArray();
	ASSERT_TRUE(arrayResult1.length == priorityQueue.size());
	
	PriorityQueue<Integer> integerPriorityQueue { Integer(1), Integer(2) };
	ASSERT_EQUAL(2, integerPriorityQueue.size());
	ASSERT_TRUE(Integer(2) == integerPriorityQueue.peek());
	
	// if length of array is larger than queue size.
	Array<Integer> integerArray1 = { Integer(), Integer(), Integer(), Integer(4) };
	ASSERT_EQUAL(4, integerArray1.length);
	integerArray1 = integerPriorityQueue.toArray(integerArray1); // this array will be modified.
	ASSERT_TRUE(Integer() != integerArray1[ 0 ]);
	ASSERT_TRUE(Integer().intValue() == integerArray1[ 2 ].intValue()); // default Integer value (same as null).
	
	// if length of array is less than queue size.
	Array<Integer> integerArray2;
	ASSERT_EQUAL(0, integerArray2.length);
	Array<Integer> arrayResult2 = integerPriorityQueue.toArray(integerArray2); // new array will be created.
	ASSERT_EQUAL(2, arrayResult2.length);
}
