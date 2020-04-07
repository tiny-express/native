/**
 * Copyright 2017-2020 Tiny Express Project. All rights reserved.
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
#include "../Deque/Deque.hpp"
#include "../ArrayList/ArrayList.hpp"
#include "../Queue/Queue.hpp"
#include "../../Lang/Exception/Exception.hpp"
#include "../../Lang/IndexOutOfBoundsException/IndexOutOfBoundsException.hpp"
#include "../../Lang/NoSuchElementException/NoSuchElementException.hpp"

using namespace Java::Lang;

namespace Java {
		namespace Util {

		        template <typename E>
                class Node {
                public:
                    E element;
                    long id;
                    explicit Node(E element) {
                        this->id = (intptr_t) std::addressof(*this);
                        this->element = element;
                    }
                };

				template <typename E>
				class LinkedList
//						: public AbstractSequentialList<E>
//						, public virtual List<E>
//						, public virtual Deque<E>
//						public virtual Cloneable
//						, public virtual Serializable
		  		{
                private:
                    std::list<Node<E>*> original;
                    typedef typename std::list<Node<E>*>::iterator IteratorType;
                    typedef typename std::list<Node<E>*>::const_iterator ConstIteratorType;
                public:

                    LinkedList() = default;

                    /**
                     * LinkedList with std::initializer_list
                     *
                     * @param target
                     */
                    LinkedList(const std::initializer_list<E> &target) {
                        for (const E &item : target) {
                            this->add(item);
                        }
                    }

                    ~LinkedList() {
                        this->clear();
                    }

                public:
                    IteratorType begin() {
                        return this->original.begin();
                    }

                    IteratorType begin() const {
                        return this->original.begin();
                    }

                    IteratorType end() {
                        return this->original.end();
                    }

                    ConstIteratorType end() const {
                        return this->original.end();
                    }

                    /**
                     * Appends the specified element to the end of this list.
                     *
                     * @param element
                     * @return boolean
                     */
                    boolean add(const E &element) {
                        this->original.push_back(new Node<E>(element));
                        return true;
                    }

                    /**
                     *Inserts the specified element at the beginning of this list.
                     *
                     * @param element
                     */
                    void addFirst(const E &element) {
                        this->original.push_front(new Node<E>(element));
                    }

                    /**
                     * Appends the specified element to the end of this list.
                     *
                     * @param element
                     */
                    void addLast(const E &element) {
                        this->original.push_back(new Node<E>(element));
                    }

                    /**
                     * Removes all of the elements from this list.
                     */
                    void clear() {
                        forEach([](Node<E> *node) {
                            delete node;
                            return true;
                        });
                        this->original.clear();
                    }

                    /**
                     * Foreach linked list
                     *
                     * @param callback
                     */
                    void forEach(const std::function<boolean(Node<E> *node)> &callback) {
                        ArrayList<Node<E>*> nodes;
                        for (typename std::list<Node<E>*>::iterator it = this->original.begin(); it != this->original.end(); ++it) {
                            nodes.add(*it);
                        }
                        nodes.forEach(callback);
                    }

                    /**
                     * Don't support this method
                     */
//			Iterator<E> descendingIterator();

                    /**
                     * Retrieves, but does not remove, the head (first element) of this list.
                     *
                     * @return E
                     */
                    E element() {
                        this->original.front()->element;
                    }

                    /**
                     * Returns the element at the specified position in this list.
                     *
                     * @param index
                     * @return E
                     */
                    E get(int index) {
                        if (index < 0 || index > this->original.size() - 1) {
                            throw IndexOutOfBoundsException("Index is out of bounds!");
                        }
                        typename std::list<Node<E>*>::iterator it =  std::next(this->original.begin(), index);
                        return (*it)->element;
                    }

                    /**
                     * Returns the first element in this list.
                     *
                     * @return E
                     */
                    E getFirst() {
                        return original.front()->element;
                    }

                    /**
                     * Returns the last element in this list.
                     *
                     * @return E
                     */
                    E getLast() {
                        var node = this->original.back();
                        return node->element;
                    }

                    /**
                     * Adds the specified element as the tail (last element) of this list.
                     *
                     * @param element
                     * @return boolean
                     */
                    boolean offer(const E &element) {
                        this->original.push_back();
                        return true;
                    }

                    /**
                     * Inserts the specified element at the front of this list.
                     *
                     * @param element
                     * @return boolean
                     */
                    boolean offerFirst(const E &element) {
                        this->original.push_front(new Node<E>(element));
                        return true;
                    }

                    /**
                     * Inserts the specified element at the end of this list.
                     *
                     * @param element
                     * @return boolean
                     */
                    boolean offerLast(const E &element) {
                        this->original.push_back(new Node<E>(element));
                        return true;
                    }

                    /**
                     * Retrieves, but does not remove, the head (first element) of this list.
                     *
                     * @return E
                     */
                    E peek() {
                        return getFirst();
                    }

                    /**
                     * Retrieves, but does not remove, the first element of this list, or returns default E if this list is empty.
                     * @return E
                     */
                    E peekFirst() {
                        return getFirst();
                    }

                    /**
                     * Retrieves, but does not remove, the last element of this list, or returns default E if this list is empty.
                     *
                     * @return E
                     */
                    E peekLast() {
                        return getLast();
                    }

                    /**
                     * Retrieves and removes the head (first element) of this list.
                     *
                     * @return E
                     */
                    E poll() {
                        return pollFirst();
                    }

                    /**
                     * Retrieves and removes the first element of this list, or throw an exception if this->first is nullptr
                     *
                     * @return E
                     */
                    E pollFirst() {
                        var  node = this->original.front();
                        this->original.pop_front();
                        var element = node->element;
                        delete node;
                        return element;
                    }

                    /**
                     * Retrieves and removes the last element of this list, or throw an exception if this->last is nullptr
                     *
                     * @return E
                     */
                    E pollLast() {
                        var node = this->original.back();
                        this->original.pop_back();
                        var element = node->element;
                        delete node;
                        return element;
                    }

                    /**
                     * Pops an element from the stack represented by this list.
                     *
                     * @return E
                     */
                    E pop() {
                        return pollFirst();
                    }

                    /**
                     * Pushes an element onto the stack represented by this list.
                     *
                     * @param element
                     */
                    void push(const E &element) {
                        this->original.push_front(new Node<E>(element));
                    }

                    /**
                     * Retrieves and removes the head (first element) of this list.
                     *
                     * @return E
                     */
                    E remove() {
                        return pollFirst();
                    }

                    /**
                     * Remove a specific index
                     *
                     * @param element e
                     * @return boolean
                     */
                    boolean remove(int index) {
                        int pos = 0;
                        for (typename std::list<Node<E>*>::iterator it = this->original.begin(); it != this->original.end(); ++it) {
                            if (pos == index) {
                                var node = *it;
                                this->original.erase(it);
                                delete node;
                                break;
                            }
                            ++pos;
                        }
                        return true;
                    }

                    /**
                     * Remove a specific node
                     *
                     * @param element e
                     * @return boolean
                     */
                    boolean remove(const Node<E> &node1) {
                        for (typename std::list<Node<E>*>::iterator it = this->original.begin(); it != this->original.end(); it++) {
                            if ((*it)->id== node1.id) {
                                var node2 = *it;
                                this->original.erase(it);
                                delete node2;
                                break;
                            }
                        }
                        return true;
                    }

                    E removeLast() {
                        var node = this->original.back();
                         this->original.pop_back();
                         var element = node->element;
                         delete node;
                         return element;
                    }

                    /**
                     * Replaces the element at the specified position in this list with the specified element.
                     *
                     * @param index
                     * @param element
                     * @return E
                     */
                    E set(int index, E &element) {
                        var value = get(index);
                        *value = element;
                        return element;
                    }

                    /**
                     * Returns the number of elements in this list.
                     *
                     * @return
                     */
                    long size() {
                        return this->original.size();
                    }

//                    String toString() {
//                        var node = this->first;
//                        String serializeStr = "*";
//                        while (hasNext(node)) {
//                            if (node->previous != nullptr) {
//                                serializeStr += String("[") + String::valueOf(node->previous->element) + String("]");
//                            }
//                            serializeStr += String::valueOf(node->element) + String("");
//                            if (node->next != nullptr) {
//                                serializeStr += String("[") + String::valueOf(node->next->element) + String("]");
//                            }
//                            serializeStr += "-->";
//                            node = node->next;
//                        }
//                        return serializeStr;
//                    }

                };
		}
}

#endif // NATIVE_JAVA_UTIL_LINKED_LIST_HPP
