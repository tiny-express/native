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

#ifndef NATIVE_JAVA_UTIL_LINKED_LIST_HPP
#define NATIVE_JAVA_UTIL_LINKED_LIST_HPP

#include "../../Lang.hpp"
#include "../AbstractSequentialList/AbstractSequentialList.hpp"
#include "../Collection/Collection.hpp"
#include "../Deque/Deque.h"
#include "../List/List.hpp"
#include "../Queue/Queue.hpp"

using namespace Java::Lang;

namespace Java {
    namespace Util {
        template <typename E>
        class LinkedList: public AbstractSequentialList<E>,
            //public virtual Serializable,
            //public virtual Cloneable,
            public virtual Iterable<E>,
            public virtual Collection<E>,
            public virtual Deque<E>,
            public virtual List<E>,
            public virtual Queue<E> {

        private:
//            structCE

        public:
            LinkedList();
            LinkedList(Collection<E> c);
            ~LinkedList();

        public:
            boolean	add(E e);
            void	add(int index, E element);
            boolean	addAll(Collection<E> c);
            boolean	addAll(int index, Collection<E> c);
            void	addFirst(E e);
            void	addLast(E e);
            void	clear();
            Object	clone();
            boolean	contains(Object o);
            Iterator<E>	descendingIterator();
            E	element();
            E	get(int index);
            E	getFirst();
            E	getLast();
            int	indexOf(Object o);
            int	lastIndexOf(Object o);
            ListIterator<E>	listIterator(int index);
            boolean	offer(E e);
            boolean	offerFirst(E e);
            boolean	offerLast(E e);
            E	peek();
            E	peekFirst();
            E	peekLast();
            E	poll();
            E	pollFirst();
            E	pollLast();
            E	pop();
            void	push(E e);
            E	remove();
            E	remove(int index);
            boolean	remove(Object o);
            E	removeFirst();
            boolean	removeFirstOccurrence(Object o);
            E	removeLast();
            boolean	removeLastOccurrence(Object o);
            E	set(int index, E element);
            int	size();
            Array<Object>	toArray();

            template<typename T>
            Array<T> toArray(Array<T> a);

        private:
            void linkFirst();
            void linkLast();
        };
    }
}

#endif //NATIVE_JAVA_UTIL_LINKED_LIST_HPP
