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

#include "../../../kernel/Test.hpp"
#include "../PriorityQueue/PriorityQueue.hpp"
#include "../Vector/Vector.hpp"

using namespace Java::Util;

TEST (JavaUtilPriorityQueue, Constructor) {
    PriorityQueue<Integer> defaultConstructor;
    assertEquals(0, defaultConstructor.size());

    PriorityQueue<Integer> initializerListConstructor{1, 2, 3, 4, 5};
    assertEquals(5, initializerListConstructor.size());
    assertEquals("5", initializerListConstructor.peek().toString());

    PriorityQueue<Integer> copyConstructor(initializerListConstructor);
    assertEquals(5, copyConstructor.size());
    assertEquals("5", copyConstructor.peek().toString());

    try {
        PriorityQueue<Integer> customCapacityConstructor(-1);
    } catch (InterruptedException &ex) {
        assertEquals("initialCapacity < 1", ex.getMessage());
    }
}

TEST (JavaUtilPriorityQueue, Add) {
    PriorityQueue<Integer> priorityQueue{1, 2, 3, 4, 5};
    assertEquals(5, priorityQueue.size());
    assertEquals("5", priorityQueue.peek().toString());
    priorityQueue.add(10);
    assertEquals(6, priorityQueue.size());
    assertEquals("10", priorityQueue.peek().toString());
}

TEST (JavaUtilPriorityQueue, Clear) {
    PriorityQueue<Integer> priorityQueue{1, 2, 3, 4, 5};
    assertEquals(5, priorityQueue.size());
    priorityQueue.clear();
    assertEquals(0, priorityQueue.size());
}

TEST (JavaUtilPriorityQueue, Contains) {
    PriorityQueue<Integer> priorityQueue{1, 2, 3, 4, 5};
    assertEquals(5, priorityQueue.size());
    assertEquals("5", priorityQueue.peek().toString());
    assertTrue(priorityQueue.contains(1));
    assertFalse(priorityQueue.contains(7));
}

TEST (JavaUtilPriorityQueue, Offer) {
    PriorityQueue<Integer> priorityQueue{1, 2, 3, 4, 5};
    assertEquals(5, priorityQueue.size());
    assertEquals("5", priorityQueue.peek().toString());
    priorityQueue.offer(10);
    assertEquals(6, priorityQueue.size());
    assertEquals("10", priorityQueue.peek().toString());
}

TEST (JavaUtilPriorityQueue, Peek) {
    PriorityQueue<Integer> priorityQueue{1, 2, 3, 4, 5};
    assertEquals(5, priorityQueue.size());
    assertEquals("5", priorityQueue.peek().toString());
    assertEquals(5, priorityQueue.size());
    priorityQueue.add(10);
    assertEquals(10, priorityQueue.peek().toString());
    assertEquals(6, priorityQueue.size());

    PriorityQueue<Integer> integerPriorityQueue;
    assertEquals(0, integerPriorityQueue.size());
    assertTrue(Integer() == integerPriorityQueue.peek().toString()); // default value of Integer (same as null).
}

TEST (JavaUtilPriorityQueue, Poll) {
    PriorityQueue<Integer> priorityQueue{1, 2, 3, 4, 5};
    assertEquals(5, priorityQueue.size());
    assertEquals("5", priorityQueue.poll().toString());
    assertEquals(4, priorityQueue.size());
    priorityQueue.add(10);
    assertEquals("10", priorityQueue.poll().toString());
    assertEquals(4, priorityQueue.size());

    PriorityQueue<Integer> integerPriorityQueue;
    assertEquals(0, integerPriorityQueue.size());
    assertTrue(Integer() == integerPriorityQueue.peek().toString()); // default value of Integer.
}

TEST (JavaUtilPriorityQueue, Remove) {
    PriorityQueue<Integer> priorityQueue{1, 2, 3, 4, 5};
    assertEquals(5, priorityQueue.size());
    assertEquals(5, priorityQueue.peek().toString());

    assertTrue(priorityQueue.remove(5));
    assertEquals(4, priorityQueue.size());
    assertEquals(4, priorityQueue.peek().toString());

    assertFalse(priorityQueue.remove(10));
    assertEquals(4, priorityQueue.size());
    assertEquals(4, priorityQueue.peek().toString());
}

TEST (JavaUtilPriorityQueue, Size) {
    PriorityQueue<Integer> priorityQueue;
    assertEquals(0, priorityQueue.size());
    priorityQueue.add(-1);
    assertEquals(1, priorityQueue.size());
}

TEST (JavaUtilPriorityQueue, ToArray) {
    PriorityQueue<Integer> priorityQueue{1, 2, 3, 4, 5};
    assertEquals(5, priorityQueue.size());
    assertEquals(5, priorityQueue.peek().toString());
    Array<Integer> arrayResult1 = priorityQueue.toArray();
    assertTrue(arrayResult1.length == priorityQueue.size());

    PriorityQueue<Integer> integerPriorityQueue{Integer(1), Integer(2)};
    assertEquals(2, integerPriorityQueue.size());
    assertTrue(Integer(2) == integerPriorityQueue.peek().toString());

    // if length of array is less than queue size.
    Array<Integer> integerArray2;
    assertEquals(0, integerArray2.length);
    Array<Integer> arrayResult2 = integerPriorityQueue.toArray(integerArray2); // new array will be created.
    assertEquals(2, arrayResult2.length);
}
