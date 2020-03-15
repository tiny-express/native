/**
 * Copyright 2017-2020 Tiny Express Project. All rights reserved.
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

#include "../../../Test.hpp"
#include "LinkedList.hpp"

using namespace Java::Util;

TEST (JavaUtilLinkedList, Add) {
	// Given linked list with 2 elements - Return size is 2 and added elements
	LinkedList<int> linkedList;
	linkedList.add(25);
	linkedList.add(24);
	assertEquals(2, linkedList.size());
	assertEquals(25, linkedList.getFirst());
	assertEquals(24, linkedList.getLast());
}

TEST(JavaUtilLinkedList, Contains) {
	// Given valid linked list to test contains of a element inside list
	LinkedList<char> linkedList;
	linkedList.add('6');
	linkedList.add('#');
	linkedList.add('f');
	linkedList.add(';');
	
	char expectedValue = '#';
	assertTrue(linkedList.contains(expectedValue));
	
	char unexpectedValue = '5';
	assertFalse(linkedList.contains(unexpectedValue));
}

TEST (JavaUtilLinkedList, GetFirst) {
	// Given list of strings - Return first element
	LinkedList<String> linkedList;
	linkedList.add("Hello");
	linkedList.add("World");
	assertEquals("Hello", linkedList.getFirst().toString());
}

TEST (JavaUtilLinkedList, GetLast) {
	// Given list of strings - Return last element
	LinkedList<String> linkedList;
	linkedList.add("Hello");
	linkedList.add("World");
	assertEquals("World", linkedList.getLast().toString());
}

TEST (JavaUtilLinkedList, Peek) {
	//Given valid linked list to test peek(), peek..() also
	LinkedList<String> linkedList;
	linkedList.add("sample 1");
	linkedList.add("sample 2");
	linkedList.add("sample 3");
	
	String result = linkedList.peek();
	String expectedValue = "sample 1";
	assertEquals(expectedValue.toString(), result.toString());
	
	result = linkedList.peekFirst();
	assertEquals(expectedValue.toString(), result.toString());
	
	result = linkedList.peekLast();
	expectedValue = "sample 3";
	assertEquals(expectedValue.toString(), result.toString());
}

TEST (JavaUtilLinkedList, Poll) {
	// Given valid linked list to test poll(), poll..() also
	// Brief: after called function, linked list must return correct value and decrease linked list size also
	LinkedList<Integer> linkedList;
	linkedList.add(10);
	linkedList.add(20);
	linkedList.add(30);
	
	Integer result = linkedList.poll();
	Integer expectedValue = 10;
	int expectedSize = 2;
	assertEquals(expectedValue.intValue(), result.intValue());
	assertEquals(expectedSize, linkedList.size());
	
	result = linkedList.pollLast();
	expectedValue = 30;
	expectedSize = 1;
	assertEquals(expectedValue.intValue(), result.intValue());
	assertEquals(expectedSize, linkedList.size());
	
	result = linkedList.pollFirst();
	expectedValue = 20;
	expectedSize = 0;
	assertEquals(expectedValue.intValue(), result.intValue());
	assertEquals(expectedSize, linkedList.size());
	
	// In this test case, we get element and remove it also, so don't need to clear after finished
}

TEST (JavaUtilLinkedList, Remove) {
	// Given valid linked list to test remove(), remove..()
	LinkedList<float> linkedList;
	linkedList.add(1.3);
	linkedList.add(52.2);
	linkedList.add(0.2);
	linkedList.add(7.3);
	linkedList.add(10.3);
	
	// Remove first element, so next getFirst must be equal to 52.2 - this test case wrapped removeFirst() also
	linkedList.remove();
	assertEquals(52.2f, linkedList.getFirst());
	
	// Remove last element, so next getLast must be equal to 7.3
	linkedList.removeLast();
	assertEquals(7.3f, linkedList.getLast());
}

TEST (JavaUtilLinkedList, RemoveByIndex) {
    // Given valid linked list to test remove(), remove..()
    LinkedList<long> linkedList;
    linkedList.add(3);
    linkedList.add(5);
    linkedList.add(9);
    linkedList.add(10);
    linkedList.add(15);

    {
        assertTrue(linkedList.remove(2));
        assertEquals(4, linkedList.size());
    }

    {
        assertTrue(linkedList.remove(3));
        assertEquals(3, linkedList.size());
    }

    assertEquals(3, linkedList.get(0));
    assertEquals(5, linkedList.get(1));
    assertEquals(10, linkedList.get(2));
}

TEST (JavaUtilLinkedList, RemoveByNode) {
    // Given valid linked list to test remove(), remove..()
    LinkedList<long> linkedList;
    linkedList.add(3);
    linkedList.add(5);
    linkedList.add(9);
    linkedList.add(10);
    linkedList.add(15);
    assertEquals(5, linkedList.size());
    linkedList.forEach([&](Node<long> *node) {
        assertTrue(linkedList.remove(*node));
    });
    assertEquals(0, linkedList.size());

    // Test data manipulation
    linkedList.add(1);
    linkedList.add(2);
    assertEquals(2, linkedList.size());

    linkedList.forEach([&](Node<long> *node) {
        assertTrue(linkedList.remove(*node));
    });
    assertEquals(0, linkedList.size());

    // Test writable data
    linkedList.add(4);
    linkedList.add(5);
    linkedList.forEach([](Node<long> *node) {
        node->element = 3;
    });
    var sum = 0;
    linkedList.forEach([&sum](Node<long> *node) {
        sum += node->element;
    });
    assertEquals(sum, 6);
}

TEST (JavaUtilLinkedList, GetNodeById) {
    LinkedList<long> linkedList;
    linkedList.add(3);
    linkedList.add(5);
    linkedList.add(9);
    linkedList.add(10);
    linkedList.add(15);
    assertEquals(5, linkedList.size());

    linkedList.forEach([&](Node<long> *node) {
        assertEquals(linkedList.getNode(node->id)->id, node->id);
    });
}

TEST (JavaUtilLinkedList, Size) {
	// Given empty linked list - Return size of list is zero
	LinkedList<int> linkedList;
	assertEquals(0, linkedList.size());
	
	// Append two elements to linked list - Return two elements
	linkedList.add(25);
	linkedList.add(25);
	assertEquals(2, linkedList.size());
}