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

#ifndef JAVA_UTIL_DEQUE_HPP_
#define JAVA_UTIL_DEQUE_HPP_

#include "../../Lang.hpp"
#include "../Collection/Collection.hpp"
#include "../Queue/Queue.hpp"

namespace Java {
		namespace Util {
				template <typename E>
				class Deque : public virtual Queue<E> {
				public:
						virtual boolean add(E &e) = 0;
						virtual void addFirst(E &e) = 0;
						virtual void addLast(E &e) = 0;
						virtual boolean contains(Object &o) = 0;
//            virtual Iterator<E>	descendingIterator() = 0;
						virtual E element() = 0;
						virtual E getFirst() = 0;
						virtual E getLast() = 0;
//            virtual Iterator<E>	iterator() = 0;
						virtual boolean offer(E &e) = 0;
						virtual boolean offerFirst(E &e) = 0;
						virtual boolean offerLast(E &e) = 0;
						virtual E peek() = 0;
						virtual E peekFirst() = 0;
						virtual E peekLast() = 0;
						virtual E poll() = 0;
						virtual E pollFirst() = 0;
						virtual E pollLast() = 0;
						virtual E pop() = 0;
						virtual void push(E e) = 0;
						virtual E remove() = 0;
						virtual boolean remove(Object &o) = 0;
						virtual E removeFirst() = 0;
//            virtual boolean removeFirstOccurrence(Object &o) = 0;
						virtual boolean removeFirstOccurrence(E &e) = 0;
						virtual E removeLast() = 0;
//            virtual boolean removeLastOccurrence(Object &o) = 0;
						virtual boolean removeLastOccurrence(E &e) = 0;
						virtual int size() = 0;
				};
		}
}

#endif //JAVA_UTIL_LINKED_LIST_HPP_
