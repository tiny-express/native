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

#ifndef NATIVE_JAVA_STACK_LIST_HPP
#define NATIVE_JAVA_STACK_LIST_HPP

#include <stack>
#include "../function/UnaryOperator/UnaryOperator.hpp"
#include "../Iterator/Iterator.hpp"
#include "../Collection/Collection.hpp"
#include "../Comparator/Comparator.hpp"

namespace Java {
    namespace Util {
        template <typename E>
        class Stack : public virtual Collection<E> {
            private:
			std::stack<E> original;
            
            public:
			Stack(){}
			~Stack(){}

            public:
            virtual bool empty() {}
            virtual E peek(){}
            virtual E pop(){}
            virtual E push(const E &item){}
            virtual int search(const Object &o){}
            
            virtual boolean add(E &e) {
				this->original.push(e);
			}

			virtual boolean addAll(Collection<E> &c){}
			virtual void clear(){}
			virtual boolean contains(Object &o) const{}
			virtual boolean equals(Object &o) const{}
			virtual int hashCode() const{}
			virtual boolean isEmpty() const{}
			virtual Iterator<E> &iterator() const{}
			virtual boolean remove(Object &o){}
			virtual boolean removeAll(Collection<Object> &c){}
			virtual boolean removeIf(Java::Util::Function::Predicate<E> &filter){}
			virtual boolean retainAll(Collection<Object> &c){}

			virtual int size() const {
				return this->original.size();
			}

        };
    }
}

#endif

