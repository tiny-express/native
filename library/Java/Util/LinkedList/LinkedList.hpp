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
#include "../List/List.hpp"
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
						Node<E> *previous = nullptr;
						Node<E> *next = nullptr;

						Node(Node<E> *previous, const E &element, Node<E> *next) {
                            this->id = (intptr_t) std::addressof(*this);
						    this->element = element;
							this->previous = previous;
							this->next = next;
						}
				};
				
				template <typename E>
				class LinkedList
//						: public AbstractSequentialList<E>
//						, public virtual List<E>
//						, public virtual Deque<E>
//						, public virtual Cloneable
//						, public virtual Serializable
				{
				private:
						Node<E> *first = nullptr;
						Node<E> *last = nullptr;
						int nodeSize = 0;

                public:
						/**
						 * LinkedList default constructor
						 */
						LinkedList() = default;
						
						/**
						 * LinkedList with std::initializer_list
						 *
						 * @param target
						 */
						LinkedList(const std::initializer_list<E> &target) {
							for (E item : target) {
								this->add(item);
							}
						}

						/**
						 * LinkedList destructor
						 */
						~LinkedList() {
							this->clear();
						}
				
				public:
						/**
						 * Appends the specified element to the end of this list.
						 *
						 * @param element
						 * @return boolean
						 */
						boolean add(const E &element) {
							this->linkLast(element);
							return true;
						}
						
						/**
						 * Inserts the specified element at the specified position in this list.
						 *
						 * @param index
						 * @param element
						 */
						void add(int index, const E &element) {
							var temporaryNode = findNodeByIndex(index);
							if (temporaryNode != nullptr && temporaryNode->previous != nullptr) {
                                temporaryNode->previous->next = new Node<E>(temporaryNode->previous, element, temporaryNode);
							}
						}
						
						/**
						 * Don't support this method
						 */
//			boolean addAll(Collection<E> c);
						
						/**
						 * Don't support this method
						 */
//			boolean addAll(int index, Collection<E> c);
						
						
						/**
						 *Inserts the specified element at the beginning of this list.
						 *
						 * @param element
						 */
						void addFirst(const E &element) {
							linkFirst(element);
						}
						
						/**
						 * Appends the specified element to the end of this list.
						 *
						 * @param element
						 */
						void addLast(const E &element) {
							linkLast(element);
						}
						
						/**
						 * Removes all of the elements from this list.
						 */
						void clear() {
							int nodeSize = this->nodeSize;
							for (var index = 0; index < nodeSize; index++) {
								remove();
							}
						}
						
						/**
						 * Don't support this method
						 */
//			Object clone();
						
						/**
						 * Returns true if this list contains the specified element.
						 *
						 * @param element
						 * @return boolean
						 */
						boolean contains(const E &element) const {
                            var node = this->first;
                            while (node->next != nullptr) {
                                if (element == node->element) {
                                    return true;
                                }
                                node = node->next;
                            }
							return false;
						}

						/**
						 * Foreach linked list
						 *
						 * @param callback
						 */
						void forEach(const std::function<boolean(Node<E>* node)> &callback) {
                            ArrayList<Node<E>*> nodes;
                            var node = this->first;
                            while (hasNext(node)) {
                                nodes.add(node);
                                node = node->next;
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
							return getFirst();
						}

                        /**
                         * Returns the element at the specified id in list.
                         *
                         * @param index
                         * @return Node<E>
                         */
                        Node<E> *getNode(long nodeId) {
                            return findNodeById(nodeId);
                        }

						/**
						 * Returns the element at the specified position in this list.
						 *
						 * @param index
						 * @return E
						 */
						E get(int index) {
							if (index < 0 || index > this->nodeSize - 1) {
								throw IndexOutOfBoundsException("Index is out of bounds!");
							}
							return findNodeByIndex(index)->element;
						}
						
						/**
						 * Returns the first element in this list.
						 *
						 * @return E
						 */
						E getFirst() {
							if (this->first == nullptr) {
								throw NoSuchElementException();
							}
							return this->first->element;
						}
						
						/**
						 * Returns the last element in this list.
						 *
						 * @return E
						 */
						E getLast() {
							if (this->last == nullptr) {
								throw NoSuchElementException();
							}
							return this->last->element;
						}
						
						/**
						 * Returns the index of the first occurrence of the specified element in this list,
						 * or -1 if this list does not contain the element.
						 *
						 * @param element
						 * @return int
						 */
						int indexOf(const E &element) const {
							Node<E> *temporary = this->first;
							int index;
							for (index = 0; index < this->nodeSize; ++index) {
								if (temporary->element == element) {
									return index;
								}
								temporary = temporary->next;
							}
							return -1;
						}
						
						/**
						 * Returns the index of the last occurrence of the specified element in this list,
						 * or -1 if this list does not contain the element.
						 *
						 * @param element
						 * @return int
						 */
						int lastIndexOf(const E &element) const {
							Node<E> *temporary = this->last;
							int index;
							for (index = 0; index < this->nodeSize; ++index) {
								if (temporary->element == element) {
									return index;
								}
								temporary = temporary->previous;
							}
							return -1;
						}
						
						/**
						 * Don't support this method
						 */
//			ListIterator<E> listIterator(int index);
						
						/**
						 * Adds the specified element as the tail (last element) of this list.
						 *
						 * @param element
						 * @return boolean
						 */
						boolean offer(const E &element) {
							linkLast(element);
							return true;
						}
						
						/**
						 * Inserts the specified element at the front of this list.
						 *
						 * @param element
						 * @return boolean
						 */
						boolean offerFirst(const E &element) {
							linkFirst(element);
							return true;
						}
						
						/**
						 * Inserts the specified element at the end of this list.
						 *
						 * @param element
						 * @return boolean
						 */
						boolean offerLast(const E &element) {
							linkLast(element);
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
							return unlinkFirst();
						}
						
						/**
						 * Retrieves and removes the first element of this list, or throw an exception if this->first is nullptr
						 *
						 * @return E
						 */
						E pollFirst() {
							return unlinkFirst();
						}
						
						/**
						 * Retrieves and removes the last element of this list, or throw an exception if this->last is nullptr
						 *
						 * @return E
						 */
						E pollLast() {
							return unlinkLast();
						}
						
						/**
						 * Pops an element from the stack represented by this list.
						 *
						 * @return E
						 */
						E pop() {
							return unlinkFirst();
						}
						
						/**
						 * Pushes an element onto the stack represented by this list.
						 *
						 * @param element
						 */
						void push(const E &element) {
							addFirst(element);
						}
						
						/**
						 * Retrieves and removes the head (first element) of this list.
						 *
						 * @return E
						 */
						E remove() {
							return unlinkFirst();
						}
						
						/**
						 * Remove a specific index
						 *
						 * @param element e
						 * @return boolean
						 */
						boolean remove(int index) {
                            return removeNode(findNodeByIndex(index));
						}

                        /**
                         * Remove a specific node
                         *
                         * @param element e
                         * @return boolean
                         */
                        boolean remove(const Node<E> &node) {
                            return removeNode(findNodeById(node.id));
                        }

                        /**
                         * Remove middle node and link previous with next node
                         *
                         * @param node
                         * @return
                         */
                        boolean removeNode(Node<E> *node) {
                            if (node == nullptr) {
                                return false;
                            }

                            var previousNode = node->previous;
                            var nextNode = node->next;

                            // Link left node and right node
                            if (previousNode == nullptr) {
                                this->first = nextNode;
                            } else {
                                previousNode->next = nextNode;
                            }

                            if (nextNode == nullptr) {
                                this->last = previousNode;
                            } else {
                                nextNode->previous = previousNode;
                            }

                            // Remove middle node
                            deleteNode(node);

                            return true;
                        }
						
						/**
						 * Remove first element
						 *
						 * @return E
						 */
						E removeFirst() {
							return unlinkFirst();
						}
						
						/**
						 * Remove last element
						 *
						 * @return E
						 */
						E removeLast() {
							return unlinkLast();
						}
						
						/**
						 * Don't support this method, use removeFirstOccurrence(const E &element) instead
						 */
//			boolean	removeFirstOccurrence(Object o);
						
						/**
						 * Don't support this method, use removeLastOccurrence(const E &element) instead
						 */
//			boolean	removeLastOccurrence(Object o);
						
						/**
						 * Removes the first occurrence of the specified element in this list (when traversing the list from head to tail).
						 *
						 * @param element
						 * @return
						 */
						boolean removeFirstOccurrence(const E &element) {
							var temporary = this->first;
							int index;
							for (index = 0; index < this->nodeSize; ++index) {
								if (temporary->element == element) {
									return remove(index);
								}
								temporary = temporary->next;
							}
							return false;
						}
						
						/**
						 * Removes the last occurrence of the specified element in this list (when traversing the list from head to tail).
						 *
						 * @param element
						 * @return boolean
						 */
						boolean removeLastOccurrence(const E &element) {
							var temporary = this->last;
							int index;
							for (index = this->nodeSize; index > 0; ++index) {
								if (temporary->element == element) {
									return remove(index);
								}
								temporary = temporary->previous;
							}
							return false;
						}
						
						/**
						 * Replaces the element at the specified position in this list with the specified element.
						 *
						 * @param index
						 * @param element
						 * @return E
						 */
						E set(int index, E &element) {
							var temporary = findNodeByIndex(index);
							temporary->element = element;
							return temporary->element;
						}
						
						/**
						 * Returns the number of elements in this list.
						 *
						 * @return
						 */
						int size() {
							return this->nodeSize;
						}
						
						/**
						 * Don't support this method at this time
						 *
						 * @return
						 */
//			Iterator<E> &iterator();
						
						/**
						 * Don't support this method
						 */
//			Array<Object> toArray();
						
						/**
						 * Don't support this method
						 */
//			Array<E> toArray(Array<E> a);
						

                    String toString() {
                        var node = this->first;
                        String serializeStr = "*";
                        while (hasNext(node)) {
                            if (node->previous != nullptr) {
                                serializeStr += String("[") + String::valueOf(node->previous->element) + String("]");
                            }
                            serializeStr += String::valueOf(node->element) + String("");
                            if (node->next != nullptr) {
                                serializeStr += String("[") + String::valueOf(node->next->element) + String("]");
                            }
                            serializeStr += "-->";
                            node = node->next;
                        }
                        return serializeStr;
                    }

				private:
						void linkFirst(const E &e) {
							var node = new Node<E>(nullptr, e, this->first);

							Node<E> *first = this->first;
							this->first = node;
							
							if (this->last == nullptr) {
								this->last = node;
							} else {
								first->previous = node;
							}
							
							this->nodeSize++;
						}
						
						void linkLast(const E &e) {
							var last = this->last;

							this->last = new Node<E>(this->last, e, nullptr);

							if (this->first == nullptr) {
								this->first = this->last;
							} else {
								last->next = this->last;
							}

							this->nodeSize++;
						}

						Node<E> *findNodeByIndex(int index) {
							if (index < 0 || index >= this->nodeSize) {
							    throw IndexOutOfBoundsException();
							}
							int currentIndex = 0;
                            var node = this->first;
                            while (hasNext(node)) {
                                if (currentIndex == index) {
                                    return node;
                                }
                                currentIndex++;
                                node = node->next;
                            }
                            return nullptr;
						}

                        Node<E> *findNodeById(long id) {
                            var node = this->first;
                            while (hasNext(node)) {
                                if (node->id == id) {
                                    return node;
                                }
                                node = node->next;
                            }
                            return nullptr;
                        }

						E unlinkFirst() {
							if (this->first == nullptr) {
								throw NoSuchElementException();
							}
							
							Node<E> *temporary = this->first;
							this->first = temporary->next;
							
							E element = temporary->element;
							deleteNode(temporary);
							
							return element;
						}
						
						E unlinkLast() {
							if (this->last == nullptr) {
								throw NoSuchElementException();
							}
							
							var temporary = this->last;
							this->last = temporary->previous;
							
							E element = temporary->element;
							
							deleteNode(temporary);
							return element;
						}
						
						inline void deleteNode(Node<E> *node) {
                            delete node;
                            this->nodeSize--;
						}

						inline boolean hasNext(Node<E> *node) {
                            return node != nullptr;
                        }
				};
		}
}

#endif // NATIVE_JAVA_UTIL_LINKED_LIST_HPP
