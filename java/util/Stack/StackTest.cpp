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

#include "../../lang/String/String.hpp"
#include "Stack.hpp"

using namespace Java::Util;

TEST(JavaUtil, StackConstructor) {
    Stack<int> stack;
    int temp = 123;
    stack.add(temp);

    ASSERT_EQUAL(1, stack.size());
}

TEST(JavaLang, StackDestructor) {
    
}

// Check Stack is empty or not
TEST(JavaLang, StackEmpty) {
    Stack<int> emptyStack;
    ASSERT_FALSE(emptyStack.empty());

    Stack<int> notEmptyStack;
    int temp = 123;
    notEmptyStack.add(temp);
    ASSERT_TRUE(notEmptyStack.empty());
}

// Push elements to Stack then return the top element without removing it
TEST(JavaLang, StackPeek) {
    Stack<int> peekStack;
    
    int push1 = 1;
    int push2 = 2;
    int push3 = 3;
    
    peekStack.push(push1);
    peekStack.push(push2);
    peekStack.push(push3);
    
    int result = peekStack.peek();
    ASSERT_EQUAL(3, result);
}

// Push elements to Stack then return the top element and remove it
TEST(JavaLang, StackPop) {
    Stack<int> popStack;
    
    int push1 = 1;
    int push2 = 2;
    int push3 = 3;
    
    popStack.push(push1);
    popStack.push(push2);
    popStack.push(push3);
    
    int result = popStack.pop();
    ASSERT_EQUAL(3, result);
}

// Push elements to Stack then check its size
TEST(Java, StackPush) {
    Stack<int> pushStack;

    int push1 = 1;
    int push2 = 2;
    int push3 = 3;
    
    pushStack.push(push1);
    pushStack.push(push2);
    pushStack.push(push3);

    ASSERT_EQUAL(3, pushStack.size());
}