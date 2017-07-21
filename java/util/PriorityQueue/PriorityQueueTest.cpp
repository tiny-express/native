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

#include "../PriorityQueue/PriorityQueue.hpp"
#include "../Vector/Vector.hpp"
#include "../../Lang.hpp"

using namespace Java::Util;

TEST(JavaUtil, PriorityQueueConstructor) {
    PriorityQueue<int> defaultConstructor;
    ASSERT_EQUAL(0, defaultConstructor.size());

    PriorityQueue<int> initializerListConstructor {1, 2, 3, 4, 5};
    ASSERT_EQUAL(5, initializerListConstructor.size());
    ASSERT_EQUAL(5, initializerListConstructor.peek());

    PriorityQueue<int> copyConstructor(initializerListConstructor);
    ASSERT_EQUAL(5, copyConstructor.size());
    ASSERT_EQUAL(5, copyConstructor.peek());
}

TEST(JavaUtil, PriorityQueueDestructor) {
    PriorityQueue<int> priorityQueue1;

    PriorityQueue<int> *priorityQueue2 = new PriorityQueue<int>();
    delete priorityQueue2;
}

TEST(JavaUtil, PriorityQueueAdd) {
    PriorityQueue<int> priorityQueue {1, 2, 3, 4, 5};
    ASSERT_EQUAL(5, priorityQueue.size());
    ASSERT_EQUAL(5, priorityQueue.peek());
    priorityQueue.add(10);
    ASSERT_EQUAL(6, priorityQueue.size());
    ASSERT_EQUAL(10, priorityQueue.peek());
}

TEST(JavaUtil, PriorityQueueClear) {
    PriorityQueue<int> priorityQueue {1, 2, 3, 4, 5};
    ASSERT_EQUAL(5, priorityQueue.size());
    priorityQueue.clear();
    ASSERT_EQUAL(0, priorityQueue.size());
}

TEST(JavaUtil, PriorityQueueContains) {
    PriorityQueue<int> priorityQueue {1, 2, 3, 4, 5};
    ASSERT_EQUAL(5, priorityQueue.size());
    ASSERT_EQUAL(5, priorityQueue.peek());
    ASSERT_TRUE(priorityQueue.contains(1));
    ASSERT_FALSE(priorityQueue.contains(7));
}

TEST(JavaUtil, PriorityQueueOffer) {
    PriorityQueue<int> priorityQueue {1, 2, 3, 4, 5};
    ASSERT_EQUAL(5, priorityQueue.size());
    ASSERT_EQUAL(5, priorityQueue.peek());
    priorityQueue.offer(10);
    ASSERT_EQUAL(6, priorityQueue.size());
    ASSERT_EQUAL(10, priorityQueue.peek());
}

TEST(JavaUtil, PriorityQueuePeek) {
    PriorityQueue<int> priorityQueue {1, 2, 3, 4, 5};
    ASSERT_EQUAL(5, priorityQueue.size());
    ASSERT_EQUAL(5, priorityQueue.peek());
    ASSERT_EQUAL(5, priorityQueue.size());
    priorityQueue.add(10);
    ASSERT_EQUAL(10, priorityQueue.peek());
    ASSERT_EQUAL(6, priorityQueue.size());

    PriorityQueue<Integer> integerPriorityQueue;
    ASSERT_EQUAL(0, integerPriorityQueue.size());
    ASSERT_TRUE(Integer() == integerPriorityQueue.peek()); // default value of Integer.
}

TEST(JavaUtil, PriorityQueuePoll) {
    PriorityQueue<int> priorityQueue {1, 2, 3, 4, 5};
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

TEST(JavaUtil, PriorityQueueRemove) {
    PriorityQueue<int> priorityQueue {1, 2, 3, 4, 5};
    ASSERT_EQUAL(5, priorityQueue.size());
    ASSERT_EQUAL(5, priorityQueue.peek());

    ASSERT_TRUE(priorityQueue.remove(5));
    ASSERT_EQUAL(4, priorityQueue.size());
    ASSERT_EQUAL(4, priorityQueue.peek());

    ASSERT_FALSE(priorityQueue.remove(10));
    ASSERT_EQUAL(4, priorityQueue.size());
    ASSERT_EQUAL(4, priorityQueue.peek());
}

TEST(JavaUtil, PriorityQueueSize) {
    PriorityQueue<int> priorityQueue;
    ASSERT_EQUAL(0, priorityQueue.size());
    priorityQueue.add(-1);
    ASSERT_EQUAL(1, priorityQueue.size());
}
