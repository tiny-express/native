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
#include "../../lang/String/String.hpp"
#include "Stack.hpp"

using namespace Java::Util;


TEST (JavaUtil, StackPush) {
	// int
	Stack<int> pushIntStack;
	
	int pushInt1 = 1;
	int pushInt2 = 2;
	int pushInt3 = 3;
	
	// Push elements to Stack
	pushIntStack.push(pushInt1);
	pushIntStack.push(pushInt2);
	pushIntStack.push(pushInt3);
	
	// Check size
	assertEquals(3, pushIntStack.size());
	
	// Integer
	Stack<Integer> pushIntegerStack;
	
	Integer pushInteger1 = 1;
	Integer pushInteger2 = 2;
	Integer pushInteger3 = 3;
	
	// Push elements to Stack
	pushIntegerStack.push(pushInteger1);
	pushIntegerStack.push(pushInteger2);
	pushIntegerStack.push(pushInteger3);
	
	// Check size
	assertEquals(3, pushIntegerStack.size());
	
	// string
	Stack<String> pushStringStack;
	
	String pushString1 = "1";
	String pushString2 = "2";
	String pushString3 = "3";
	
	// Push elements to Stack
	pushStringStack.push(pushString1);
	pushStringStack.push(pushString2);
	pushStringStack.push(pushString3);
	
	// Check size
	assertEquals(3, pushStringStack.size());
	
	// Object
	Stack<Object> pushObjectStack;
	
	Object pushObject1;
	Object pushObject2;
	Object pushObject3;
	
	// Push elements to Stack
	pushObjectStack.push(pushObject1);
	pushObjectStack.push(pushObject2);
	pushObjectStack.push(pushObject3);
	
	// Check size
	assertEquals(3, pushObjectStack.size());
	
}

TEST (JavaUtil, StackEmpty) {
	// Give an emtpy Stack
	
	// int
	Stack<int> emptyIntStack;
	assertTrue(emptyIntStack.empty());
	
	// Integer
	Stack<Integer> emptyIntegerStack;
	assertTrue(emptyIntegerStack.empty());
	
	// string
	Stack<String> emptyStringStack;
	assertTrue(emptyStringStack.empty());
	
	// Object
	Stack<Object> emptyObjectStack;
	assertTrue(emptyObjectStack.empty());
	
	// Give an not empty Stack
	
	// int
	Stack<int> notEmptyIntStack;
	int intTemp = 123;
	notEmptyIntStack.push(intTemp);
	assertFalse(notEmptyIntStack.empty());
	
	// Integer
	Stack<Integer> notEmptyIntegerStack;
	Integer integerTemp = 123;
	notEmptyIntegerStack.push(integerTemp);
	assertFalse(notEmptyIntegerStack.empty());
	
	// string
	Stack<String> notEmptyStringStack;
	String stringTemp = "123";
	notEmptyStringStack.push(stringTemp);
	assertFalse(notEmptyStringStack.empty());
	
	// Object
	Stack<Object> notEmptyObjectStack;
	Object objectTemp;
	notEmptyObjectStack.push(objectTemp);
	assertFalse(notEmptyObjectStack.empty());
}

TEST (JavaUtil, StackPeek) {
	//int
	Stack<int> peekIntStack;
	
	int pushInt1 = 1;
	int pushInt2 = 2;
	int pushInt3 = 3;
	
	// Push elements to Stack
	peekIntStack.push(pushInt1);
	peekIntStack.push(pushInt2);
	peekIntStack.push(pushInt3);
	
	// Return the top element without removing it
	int intResult = peekIntStack.peek();
	assertEquals(intResult, peekIntStack.peek());
	assertEquals(3, peekIntStack.size());// check size to make sure the top element is not removed
	
	// Integer
	Stack<Integer> peekIntegerStack;
	
	Integer pushInteger1 = 1;
	Integer pushInteger2 = 2;
	Integer pushInteger3 = 3;
	
	// Push elements to Stack
	peekIntegerStack.push(pushInteger1);
	peekIntegerStack.push(pushInteger2);
	peekIntegerStack.push(pushInteger3);
	
	// Return the top element without removing it
	Integer integerResult = peekIntegerStack.peek();
	assertEquals(integerResult.intValue(), peekIntegerStack.peek().intValue());
	assertEquals(3, peekIntegerStack.size()); // Check size to make sure the top element is not removed
	
	// string
	Stack<String> peekStringStack;
	
	String pushString1 = "1";
	String pushString2 = "2";
	String pushString3 = "3";
	
	// Push elements to Stack
	peekStringStack.push(pushString1);
	peekStringStack.push(pushString2);
	peekStringStack.push(pushString3);
	
	// Return the top element without removing it
	String stringResult = peekStringStack.peek();
	assertEquals(stringResult.toString(), pushString3.toString());
	assertEquals(3, peekStringStack.size());// check size to make sure the top element is not removed
	
	// Given an empty stack
	Stack<int> emptyStack;
	// Test if peek() throw EmptyStackException
	try {
		emptyStack.peek();
	}
	catch (Exception e) {
		assertEquals("", e.getMessage().toString());
	}
}

TEST (JavaUtil, StackPop) {
	//int
	Stack<int> popIntStack;
	
	int pushInt1 = 1;
	int pushInt2 = 2;
	int pushInt3 = 3;
	
	// Push elements to Stack
	popIntStack.push(pushInt1);
	popIntStack.push(pushInt2);
	popIntStack.push(pushInt3);
	
	// Return the top element and remove it
	int intResult = popIntStack.pop();
	assertEquals(intResult, pushInt3);
	assertEquals(2, popIntStack.size()); // check size to make sure the top element is removed
	
	// Integer
	Stack<Integer> popIntegerStack;
	
	Integer pushInteger1 = 1;
	Integer pushInteger2 = 2;
	Integer pushInteger3 = 3;
	
	// Push elements to Stack
	popIntegerStack.push(pushInteger1);
	popIntegerStack.push(pushInteger2);
	popIntegerStack.push(pushInteger3);
	
	// Return the top element and remove it
	Integer integerResult = popIntegerStack.pop();
	assertEquals(integerResult.intValue(), pushInteger3.intValue());
	assertEquals(2, popIntegerStack.size());// check size to make sure the top element is removed
	
	// string
	Stack<String> popStringStack;
	
	String pushString1 = "1";
	String pushString2 = "2";
	String pushString3 = "3";
	
	// Push elements to Stack
	popStringStack.push(pushString1);
	popStringStack.push(pushString2);
	popStringStack.push(pushString3);
	
	// Return the top element and remove it
	String stringResult = popStringStack.pop();
	assertEquals(stringResult.toString(), pushString3.toString());
	assertEquals(2, popStringStack.size());// check size to make sure the top element is removed
	
	// Given an empty stack
	Stack<int> emptyStack;
	// Test if peek() throw EmptyStackException
	try {
		emptyStack.peek();
	}
	catch (Exception e) {
		assertEquals("", e.getMessage().toString());
	}
}

TEST (JavaUtil, StackSearch) {
	//int
	Stack<int> searchIntStack;
	
	int pushInt1 = 1;
	int pushInt2 = 2;
	int pushInt3 = 3;
	
	// Push elements to Stack
	searchIntStack.push(pushInt1);
	searchIntStack.push(pushInt2);
	searchIntStack.push(pushInt3);
	
	// Search elements in Stack
	assertEquals(1, searchIntStack.search(pushInt2));
	assertEquals(-1, searchIntStack.search(5));
	
	// Integer
	Stack<Integer> searchIntegerStack;
	
	Integer pushInteger1 = 1;
	Integer pushInteger2 = 2;
	Integer pushInteger3 = 3;
	
	// Push elements to Stack
	searchIntegerStack.push(pushInteger1);
	searchIntegerStack.push(pushInteger2);
	searchIntegerStack.push(pushInteger3);
	
	// Search elements in Stack
	assertEquals(1, searchIntegerStack.search(pushInteger2));
	assertEquals(-1, searchIntegerStack.search(5));
	
	// string
	Stack<String> searchStringStack;
	
	String pushString1 = "1";
	String pushString2 = "2";
	String pushString3 = "3";
	
	// Push elements to Stack
	searchStringStack.push(pushString1);
	searchStringStack.push(pushString2);
	searchStringStack.push(pushString3);
	
	// Search elements in Stack
	assertEquals(1, searchStringStack.search(pushString2));
	assertEquals(-1, searchStringStack.search("5"));
}
