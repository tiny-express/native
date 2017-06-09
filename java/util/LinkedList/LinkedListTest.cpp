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

TEST(JavaUtil, LinkedListAddAndGet) {
    /// Given valid LinkedList<int> to test add(), addFirst(), addLast(), size(), getFirst(), getLast(), get(index) also
    LinkedList<int> linkedList;
    linkedList.add(25);

    // add(): Get very first value inside linkedList, check through getFirst()
    ASSERT_EQUAL(25, linkedList.getFirst());

    // size(): Add one more param to test
    linkedList.addLast(30);
    ASSERT_EQUAL(2, linkedList.size());

    // addFirst(): Add one more param through this function, check through getFirst()
    linkedList.addFirst(45);
    ASSERT_EQUAL(45, linkedList.getFirst());

    // addLast(): Add one more param through this function, check through getLast()
    linkedList.addLast(101);
    ASSERT_EQUAL(101, linkedList.getLast());

    //get(index: ): Test to get correct data inside
    ASSERT_EQUAL(45, linkedList.get(0));

    //get(index: ): A throw exception for pass index that our of linkedList - this test is described how to use linkedList exception
    //ASSERT_EQUAL(-1, linkedList.get(101));

    //add(index: element: ): Add element to specific index inside linkedList (from 0 to linkedList.size), check through get(index: )
    linkedList.add(2, 200);
    ASSERT_EQUAL(200, linkedList.get(2));
}

TEST(JavaUtil, LinkedListGetAndRemove) {
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

    //peekLast(): return last element and must be queal to 'e'
    ASSERT_EQUAL('e', linkedList.peekLast());

    //pool(): return first element and must be equal to 'a'
    ASSERT_EQUAL('a', linkedList.poll());

    //pollFirst(): return first element and must be equal to 'a', and remove that element also, so next first element must be equal to 'b'
    ASSERT_EQUAL('a', linkedList.pollFirst());
    ASSERT_EQUAL('b', linkedList.getFirst());

    //pollFirst(): return first element and must be equal to 'e', and remove that element also, so next first element must be equal to 'd'
    ASSERT_EQUAL('e', linkedList.pollLast());
    ASSERT_EQUAL('d', linkedList.getLast());
}

TEST(JavaUtil, LinkedListRemove) {
    /// Given valid LinkList<float> to test) peek(), peek..(), poll(), poll..(), offer(), offer..(
    LinkedList<float> linkedList;
    linkedList.add(1.3);
    linkedList.add(52.2);
    linkedList.add(0.2);
    linkedList.add(7.3);
    linkedList.add(10.3);

    // remove(): remove first element, so next getFirst must be equal to 52 - this test case wrapped removeFirst() also
    linkedList.remove();
    ASSERT_DBL_NEAR(52.2, linkedList.getFirst());

    // removeLast(): remove last element, so next getLast must be equal to 7.3
    linkedList.removeLast();
    ASSERT_DBL_NEAR(7.3, linkedList.getLast());
}