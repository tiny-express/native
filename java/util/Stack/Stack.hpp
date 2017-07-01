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

#include <stack>
#include "../function/UnaryOperator/UnaryOperator.hpp"
#include "../Iterator/Iterator.hpp"
#include "../Collection/Collection.hpp"
#include "../Comparator/Comparator.hpp"

namespace Java {
    namespace Util {
        template <typename E>
        class Stack {

		private:
			std::stack<E> original;

		public:
			Stack() {}
			~Stack() {}

		public:
			/**
			 * Tests if this stack is empty.
			 * @return boolean
			 */
			boolean empty() {
				if (this->original.size() == 0) {
					return false;
				}
				return true;
	        }

	        /**
	         *Looks at the object at the top of this stack without removing it from the stack.
	         * @return E
	         */
			E peek() {
				E e;
				if (this->original.size() > 0) {
					e = this->original.top();
				}
				return e;
			}

			/**
			 * Removes the object at the top of this stack and returns that object as the value of this function.
			 * @return E
			 */
	        E pop() {
		        E e;
				if (this->original.size() > 0) {
					e = this->original.top();
					this->original.pop();
				}
				return e;
	        }

			/**
			 * Pushes an item onto the top of this stack
			 * @param item
			 * @return E
			 */
	        E push(const E &item) {
		        this->original.push(item);
				return item;
	        }

			/**
			 * Don't support this method
			 */
//	        int search(Object &o);
        };
    }
}

#endif

