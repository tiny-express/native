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

#include <stdexcept>
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
        class Node {
        public:
            E item;
            Node<E> *previous = NULL;
            Node<E> *next = NULL;

            Node(Node<E> *previous2, E element, Node<E> *next2) {
                if (previous2 != NULL) {
                    printf("previous before assigned: %d\n", previous2->item);
                }
                this->item      = element;
                this->previous  = previous2;
                this->next      = next2;
                if (previous2 != NULL) {
                    printf("previous after assigned: %d\n", previous2->item);
                }
            }
        };

        template <typename E>
        class LinkedList {
            //public AbstractSequentialList<E>,
            //public virtual Serializable,
            //public virtual Cloneable,
            //public virtual Deque<E>,
            //public virtual List<E> {
        private:
            Node<E> *first = NULL;
            Node<E> *last = NULL;
            int nodeSize = 0;

        public:
            LinkedList() {}
            LinkedList(Collection<E> c) {}
            ~LinkedList() {}

        public:
            boolean	add(E e) {
                linkLast(e);
                return true;
            }

            void add(int index, E element);
            boolean	addAll(Collection<E> c);
            boolean	addAll(int index, Collection<E> c);
            void addFirst(E e) {
                linkFirst(e);
                return;
            }
            void addLast(E e) {
                linkLast(e);
                return;
            }
            void clear();
            Object clone();
            boolean	contains(Object o);
            Iterator<E>	descendingIterator();
            E element();

            E get(int index) {
                return node(index);
            }

            E getFirst() {
                return first->item;
            }

            E getLast() {
                return last->item;
            }

            int	indexOf(Object o);
            int	lastIndexOf(Object o);
            ListIterator<E>	listIterator(int index);
            boolean	offer(E e);
            boolean	offerFirst(E e);
            boolean	offerLast(E e);
            E peek();
            E peekFirst();
            E peekLast();
            E poll();
            E pollFirst();
            E pollLast();
            E pop();
            void push(E e);
            E remove();
            E remove(int index);
            boolean	remove(Object o);
            E removeFirst();
            boolean	removeFirstOccurrence(Object o);
            E removeLast();
            boolean	removeLastOccurrence(Object o);
            E set(int index, E element);
            int	size() {
                return this->nodeSize;
            }

            Iterator<E> &iterator();
            Array<Object> toArray();

            template<typename T>
            Array<T> toArray(Array<T> a);

        private:
            void linkFirst(E e) {
                Node<E> *node = new Node<E>(NULL, e, first);

                Node<E> *f = first;
                first = node;

                if (last == NULL) {
                    last = node;
                } else {
                    f->previous = node;
                }

                nodeSize++;
            }

            void linkLast(E e) {
                Node<E> *node = new Node<E>(last, e, NULL);

                Node<E> *l = last;
                last = node;

                if (first == NULL) {
                    first = node;
                } else {
                    l->next = node;
                }

                nodeSize++;
            }

            E node(int index) {
                if (index < 0 || index >= this->nodeSize) {
                    throw std::invalid_argument( "index is out o scope" );
                }

                Node<E> *temp = this->first;
                for (int i = 1; i < index; ++i) {
                    temp = temp->next;
                }
                return temp->item;
            }
        };
    }
}

#endif //NATIVE_JAVA_UTIL_LINKED_LIST_HPP
