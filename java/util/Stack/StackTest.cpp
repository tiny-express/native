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
#include "../../../unit_test.h"
}

#include "../../lang/String/String.hpp"
#include "Stack.hpp"

using namespace Java::Util;

//TEST(JavaUtil, StackConstructor) {
//    // Give a not empty Stack
//    Stack<int> stack;
//    int temp = 123;
//    stack.add(temp);
//
//    // Check size
//    ASSERT_EQUAL(1, stack.size());
//}
//
//TEST(JavaLang, StackDestructor) {
//
//}
//
//
//TEST(JavaLang, StackEmpty) {
//    // Give a emtpy Stack
//    Stack<int> emptyStack;
//    ASSERT_FALSE(emptyStack.empty());
//
//    // Give a not empty Stack
//    Stack<int> notEmptyStack;
//    int temp = 123;
//    notEmptyStack.add(temp);
//    ASSERT_TRUE(notEmptyStack.empty());
//}
//
//
//TEST(JavaLang, StackPeek) {
//
//    Stack<int> peekStack;
//
//    int push1 = 1;
//    int push2 = 2;
//    int push3 = 3;
//
//    // Push elements to Stack
//    peekStack.push(push1);
//    peekStack.push(push2);
//    peekStack.push(push3);
//
//    // Return the top element without removing it
//    int result = peekStack.peek();
//    ASSERT_EQUAL(3, result);
//}
//
//
//TEST(JavaLang, StackPop) {
//    Stack<int> popStack;
//
//    int push1 = 1;
//    int push2 = 2;
//    int push3 = 3;
//
//    // Push elements to Stack
//    popStack.push(push1);
//    popStack.push(push2);
//    popStack.push(push3);
//
//    // Return the top element and remove it
//    int result = popStack.pop();
//    ASSERT_EQUAL(3, result);
//}
//
//TEST(JavaLang, StackPush) {
//    Stack<int> pushStack;
//
//    int push1 = 1;
//    int push2 = 2;
//    int push3 = 3;
//
//    // Push elements to Stack
//    pushStack.push(push1);
//    pushStack.push(push2);
//    pushStack.push(push3);
//    // Check size
//    ASSERT_EQUAL(3, pushStack.size());
//}
//
//TEST(JavaLang, StackSearch) {
//    Stack<int> searchStack;
//
//    int push1 = 1;
//    int push2 = 2;
//    int push3 = 3;
//
//    // Push elements to Stack
//    searchStack.push(push1);
//    searchStack.push(push2);
//    searchStack.push(push3);
//
//    // Check size
//    ASSERT_EQUAL(2, searchStack.search(2));
//    ASSERT_EQUAL(-1, searchStack.search(5));
//}