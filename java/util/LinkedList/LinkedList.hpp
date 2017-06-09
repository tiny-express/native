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
            E element;
            Node<E> *previous = NULL;
            Node<E> *next = NULL;

            Node(Node<E> *previous2, E element, Node<E> *next2) {
                this->element   = element;
                this->previous  = previous2;
                this->next      = next2;
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
                printf("Read %lf\n", e);
                linkLast(e);
                return true;
            }

            void add(int index, E element) {
                Node<E> *temp = node0(index);

                Node<E> *newNode = new Node<E>(temp->previous, element, temp);
                temp->previous->next = newNode;
            }

            /**
             * We don't support this method, use add(E e) instead because type casting problem
             * */
            //boolean	addAll(Collection<E> c);

            /**
             * We don't support this method, use add(E e) instead because type casting problem
             * */
            //boolean	addAll(int index, Collection<E> c);

            void addFirst(E e) {
                linkFirst(e);
                return;
            }

            void addLast(E e) {
                linkLast(e);
                return;
            }

            void clear() {
                for (int i = 0; i < nodeSize; ++i) {
                    remove();
                }
            }

            Object clone() {
                //TODO
            }

            /**
             * Don't support this method, use contains(E) instead
             * */
            //boolean	contains(Object o);

            boolean contains(E e) {
                if (node1(e) == NULL) {
                    return false;
                }

                return true;
            }

            ///Returns an iterator over the elements in this deque in reverse sequential order.
            Iterator<E>	descendingIterator() {
                //FIXME: discuss about this method
            }

            E element() {
                return getFirst();
            }

            E get(int index) {
                return node0(index)->element;
            }

            E getFirst() {
                if (first == NULL) {
                    exception();
                }
                return first->element;
            }

            E getLast() {
                if (last == NULL) {
                    exception();
                }
                printf("Get last :%lf\n", last->element);
                return last->element;
            }

            /**
             * Don't support this method - use indexOf(E) instead
             * */
            //int	indexOf(Object o);

            /**
             * Don't support this method - use use lastIndexOf(E) instead
             * */
            //int	lastIndexOf(Object o);

            int indexOf(E e) {
                Node<E> *temp = this->first;
                for (int i = 0; i < nodeSize; ++i) {
                    if (temp->element == e) {
                        return i;
                    }
                    temp = temp->next;
                }
                return -1;
            }

            int lastIndexOf(E e) {
                Node<E> *temp  = last;
                for (int i = 0; i < nodeSize; ++i) {
                    if (temp->element == e) {
                        return i;
                    }
                    temp = temp->previous;
                }
                return -1;
            }

            //Returns a list-iterator of the elements in this list (in proper sequence), starting at the specified position in the list.
            ListIterator<E>	listIterator(int index) {
                //FIXME: Discuss about this method
            }

            boolean	offer(E e) {
                linkLast(e);
                return true;
            }

            boolean	offerFirst(E e) {
                linkFirst(e);
                return true;
            }

            boolean	offerLast(E e) {
                linkLast(e);
                return true;
            }

            E peek() {
                return getFirst();
            }

            /// We don't support nullable
            E peekFirst() {
                return getFirst();
            }

            /// We don't support nullable
            E peekLast() {
                return getLast();
            }

            E poll() {
                return getFirst();
            }

            E pollFirst() {
                return unlinkFirst();
            }

            E pollLast() {
                return unlinkLast();
            }

            E pop() {
                return unlinkFirst();
            }

            void push(E e) {
                addFirst(e);
            }

            E remove() {
                return unlinkFirst();
            }


            /**
             * Currently we don't support this method because it makes a duplication with: boolean remove(E e)
             * */
//            E remove(int index) {
//                Node<E> *nodeIndex = node0(index);
//
//                Node<E> *temp = nodeIndex;
//                temp->previous = nodeIndex->next;
//
//                E element = nodeIndex->element;
//                delete(nodeIndex);
//
//                return element;
//            }

            /**
             * Dont' support this method, use <E> instead
             * */
            //boolean remove(Object o);

            boolean remove(E e) {
                Node<E> *nodeIndex = node1(e);

                if (nodeIndex == NULL) {
                    return false;
                }

                Node<E> *temp = nodeIndex;
                temp->previous = nodeIndex->next;

                delete(nodeIndex);
                return true;
            }

            E removeFirst() {
                return unlinkFirst();
            }

            E removeLast() {
                return unlinkLast();
            }
            /**
             * Don't support this method, use <E> instead
             * */
            //boolean	removeFirstOccurrence(Object o);

            /**
             * Don't support this method, use <E> instead
             * */
            //boolean	removeLastOccurrence(Object o);

            boolean removeFirstOccurrence(E e) {
                Node<E> *temp = first;

                for (int i = 0; i < nodeSize; ++i) {
                    if (temp->element == e) {
                        return remove(i);
                    }
                    temp = temp->next;
                }
                return false;
            }

            boolean removeLastOccurrrence(E e) {
                Node<E> *temp = last;

                for (int i = nodeSize; i > 0; ++i) {
                    if (temp->element == e) {
                        return remove(i);
                    }
                    temp = temp->previous;
                }
                return false;
            }

            E set(int index, E element) {
                Node<E> *temp = node0(index);

                temp->element = element;
                return temp->element;
            }

            int	size() {
                return this->nodeSize;
            }

            Iterator<E> &iterator() {
                //TODO
            }

            /**
             * Don't support this method, use <E> toArray() instead
             * */
            //Array<Object> toArray();

            Array<E> toArray() {
                //TODO
            }

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
                printf("Add last: %lf\n", node->element);
                nodeSize++;
            }

            Node<E> *node0(int index) {
                if (index < 0 || index >= this->nodeSize) {
                    exception();
                }

                Node<E> *temp = this->first;
                for (int i = 1; i < index; ++i) {
                    temp = temp->next;
                }
                return temp;
            }

            Node<E> *node1(E e) {
                Node<E> *temp = this->first;
                for (int i = 0; i < nodeSize; ++i) {
                    if (temp->element == e) {
                        return temp;
                    }
                    temp = temp->next;
                }

                return NULL;
            }

            E unlinkFirst() {
                if (first == NULL) {
                    exception();
                }

                Node<E> *temp = first;
                first = temp->next;

                E element = temp->element;
                deleteNode(temp);

                return element;
            }

            E unlinkLast() {
                if (last == NULL) {
                    exception();
                }

                Node<E> *temp = last;
                last = temp->previous;

                E element = temp->element;

                deleteNode(temp);
                return element;
            }

            void deleteNode(Node<E> *node) {
                delete(node);
                nodeSize--;
            }

            void exception() {
                throw std::invalid_argument( "[ERROR]: index is out o scope" );
            }
        };
    }
}

#endif //NATIVE_JAVA_UTIL_LINKED_LIST_HPP
