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

#ifndef JAVA_STACK_LIST_HPP_
#define JAVA_STACK_LIST_HPP_

#include "../Vector/Vector.hpp"
#include "../../io/IOException/IOException.hpp"
#include "../EmptyStackException/EmptyStackException.hpp"

using namespace Java::Util;

namespace Java {
		namespace Util {
				template <typename E>
				class Stack : public Vector<E> {
				public:
						/**
						 * Constructor
						 */
						Stack() {
						}
						
						/**
						* Stack empty - check whether the Stack is empty or not
						*
						* @return true only if this stack has no item; false otherwise
						*/
						bool empty() {
							return this->size() == 0;
						}
						
						/**
						 * Stack peek - return the top element
						 *
						 * @return E
						 * @throw EmptyStackException
						 */
						E peek() {
							int len = this->size();
							if (len == 0) {
								throw EmptyStackException();
							}
							return this->elementAt(len - 1);
						}
						
						/**
						 * Stack pop - return the top element and remove it
						 *
						 * @return E
						 * @throw EmptyStackException
						 */
						E pop() {
							int len = this->size();
							E result = this->peek();
							this->removeElementAt(len - 1);
							return result;
						}
						
						/**
						 * Stack push - Push new element
						 *
						 * @param element
						 * @return E
						 */
						E push(const E &element) {
							this->addElement(element);
							return element;
						}
						
						/**
						 * Stack search - search the object in Stack
						 *
						 * @param object
						 * @return the 1-based position from the top, -1 if can not find the object in Stack
						 */
						int search(const E &object) {
							int index = this->lastIndexOf(object);
							if (index >= 0) {
								return index;
							}
							return -1;
						}
				};
		}
}

#endif

