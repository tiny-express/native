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
		class Node {
		public:
			E element;
			Node<E> *previous = NULL;
			Node<E> *next = NULL;
			
			Node(Node<E> *previous2, const E &element, Node<E> *next2) {
				this->element = element;
				this->previous = previous2;
				this->next = next2;
			}

            Node(const Node<E> &target) {
                this->element = target.element;
                this->next = target.next;
                this->previous = target.previous;
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
			Node<E> *first = NULL;
			Node<E> *last = NULL;
			int nodeSize = 0;
		
		public:
			LinkedList() {}
			LinkedList(Collection<E> c) {}
			~LinkedList() {}
		
		public:
			/**
			 * Appends the specified element to the end of this list.
			 * @param e
			 * @return boolean
			 */
			boolean add(const E &e) {
				this->linkLast(e);
				return true;
			}

			/**
			 * Inserts the specified element at the specified position in this list.
			 * @param index
			 * @param element
			 */
			void add(int index, const E &element) {
				Node<E> *temp = node0(index);
				
				Node<E> *newNode = new Node<E>(temp->previous, element, temp);
				temp->previous->next = newNode;
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
			 * @param e
			 */
			void addFirst(E &e) {
				linkFirst(e);
				return;
			}

			/**
			 * Appends the specified element to the end of this list.
			 * @param e
			 */
			void addLast(E &e) {
				linkLast(e);
				return;
			}

			/**
			 * Removes all of the elements from this list.
			 */
			void clear() {
                int nodeSize = this->nodeSize;
				for (int i = 0; i < nodeSize; ++i) {
					remove();
				}
			}
			
			/**
			 * Don't support this method
			 */
//			Object clone();

			/**
			 * Returns true if this list contains the specified element.
			 * @param e
			 * @return boolean
			 */
			boolean contains(E &e) const {
                Node<E> *node = node1(e);

				if (NULL == node) {
					return false;
				}
				
				return true;
			}
			
			/**
			 * Don't support this method
			 */
//			Iterator<E> descendingIterator();

			/**
			 * Retrieves, but does not remove, the head (first element) of this list.
			 * @return E
			 */
			E element() {
				return getFirst();
			}

			/**
			 * Returns the element at the specified position in this list.
			 * @param index
			 * @return E
			 */
			E get(int index) {
				return node0(index)->element;
			}

			/**
			 * Returns the first element in this list.
			 * @return E
			 */
			E getFirst() {
				if (this->first == NULL) {
					exception();
				}
				return this->first->element;
			}

			/**
			 * Returns the last element in this list.
			 * @return E
			 */
			E getLast() {
				if (this->last == NULL) {
					exception();
				}
				return this->last->element;
			}

			/**
			 * Returns the index of the first occurrence of the specified element in this list,
			 * or -1 if this list does not contain the element.
			 * @param e
			 * @return int
			 */
			int indexOf(E &e) const {
				Node<E> *temp = this->first;
				for (int i = 0; i < this->nodeSize; ++i) {
					if (temp->element == e) {
						return i;
					}
					temp = temp->next;
				}
				return -1;
			}

			/**
			 * Returns the index of the last occurrence of the specified element in this list,
			 * or -1 if this list does not contain the element.
			 * @param e
			 * @return int
			 */
			int lastIndexOf(E &e) const {
				Node<E> *temp = this->last;
				for (int i = 0; i < this->nodeSize; ++i) {
					if (temp->element == e) {
						return i;
					}
					temp = temp->previous;
				}
				return -1;
			}
			
			/**
			 * Don't support this method
			 */
//			ListIterator<E> listIterator(int index);

			/**
			 * Adds the specified element as the tail (last element) of this list.
			 * @param e
			 * @return boolean
			 */
			boolean offer(E e) {
				linkLast(e);
				return true;
			}

			/**
			 * Inserts the specified element at the front of this list.
			 * @param e
			 * @return boolean
			 */
			boolean offerFirst(E e) {
				linkFirst(e);
				return true;
			}

			/**
			 * Inserts the specified element at the end of this list.
			 * @param e
			 * @return boolean
			 */
			boolean offerLast(E e) {
				linkLast(e);
				return true;
			}

			/**
			 * Retrieves, but does not remove, the head (first element) of this list.
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
			 * @return E
			 */
			E peekLast() {
				return getLast();
			}

			/**
			 * Retrieves and removes the head (first element) of this list.
			 * @return
			 */
			E poll() {
                return unlinkFirst();
			}

			/**
			 * Retrieves and removes the first element of this list, or throw an exception if this->first is NULL
			 * @return E
			 */
			E pollFirst() {
				return unlinkFirst();
			}

			/**
			 * Retrieves and removes the last element of this list, or throw an exception if this->last is NULL
			 * @return E
			 */
			E pollLast() {
				return unlinkLast();
			}

			/**
			 * Pops an element from the stack represented by this list.
			 * @return
			 */
			E pop() {
				return unlinkFirst();
			}

			/**
			 * Pushes an element onto the stack represented by this list.
			 * @param e
			 */
			void push(E e) {
				addFirst(e);
			}

			/**
			 * Retrieves and removes the head (first element) of this list.
			 * @return E
			 */
			E remove() {
				return unlinkFirst();
			}
			
			/**
			 * Don't support this method, use boolean remove(E e) instead
			 */
//			E remove(int index) {
//				Node<E> *nodeIndex = node0(index);
//				Node<E> *temp = nodeIndex;
//				temp->previous = nodeIndex->next;
//
//				E element = nodeIndex->element;
//				delete ( nodeIndex );
//
//				return element;
//			}
			
			/**
			 * Remove a specific element
			 *
			 * @param E e
			 * @return boolean
			 */
			boolean remove(E &e) {
				Node<E> *nodeIndex = node1(e);
				
				if (nodeIndex == NULL) {
					return false;
				}
				
				Node<E> *temp = nodeIndex;
				temp->previous = nodeIndex->next;

				deleteNode(nodeIndex);
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
			 * Don't support this method, use removeFirstOccurrence(E &e) instead
			 */
//			boolean	removeFirstOccurrence(Object o);
			
			/**
			 * Don't support this method, use removeLastOccurrence(E &e) instead
			 */
//			boolean	removeLastOccurrence(Object o);
			
			/**
			 * Removes the first occurrence of the specified element in this list (when traversing the list from head to tail).
			 * @param e
			 * @return
			 */
			boolean removeFirstOccurrence(E &e) {
				Node<E> *temp = this->first;
				
				for (int i = 0; i < this->nodeSize; ++i) {
					if (temp->element == e) {
						return remove(i);
					}
					temp = temp->next;
				}
				return false;
			}

			/**
			 * Removes the last occurrence of the specified element in this list (when traversing the list from head to tail).
			 * @param e
			 * @return
			 */
			boolean removeLastOccurrrence(E &e) {
				Node<E> *temp = this->last;
				
				for (int i = this->nodeSize; i > 0; ++i) {
					if (temp->element == e) {
						return remove(i);
					}
					temp = temp->previous;
				}
				return false;
			}

			/**
			 * Replaces the element at the specified position in this list with the specified element.
			 * @param index
			 * @param element
			 * @return E
			 */
			E set(int index, E &element) {
				Node<E> *temp = node0(index);
				
				temp->element = element;
				return temp->element;
			}

			/**
			 * Returns the number of elements in this list.
			 * @return
			 */
			int size() {
				return this->nodeSize;
			}

            /**
             * Don't support this method at this time
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

            /**
             * Don't support this method
             */
//			boolean equals(const Object &o);

		private:
			void linkFirst(const E &e) {
				Node<E> *node = new Node<E>(NULL, e, this->first);
				
				Node<E> *first = this->first;
				this->first = node;
				
				if (this->last == NULL) {
					this->last = node;
				} else {
					first->previous = node;
				}
				
				this->nodeSize++;
			}
			
			void linkLast(const E &e) {
				Node<E> *node = new Node<E>(this->last, e, NULL);

				Node<E> *last = this->last;
				this->last = node;

				if (this->first == NULL) {
					this->first = node;
				} else {
					last->next = node;
				}

                this->nodeSize++;
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
			
			Node<E> *node1(E &e) const {
				Node<E> *temp = this->first;
				for (int i = 0; i < this->nodeSize; ++i) {
					if (temp->element == e) {
						return temp;
					}
					temp = temp->next;
				}
				
				return NULL;
			}
			
			E unlinkFirst() {
				if (this->first == NULL) {
					exception();
				}

				Node<E> *temp = this->first;
				this->first = temp->next;

				E element = temp->element;
				deleteNode(temp);
				
				return element;
			}
			
			E unlinkLast() {
				if (this->last == NULL) {
					exception();
				}

				Node<E> *temp = this->last;
				this->last = temp->previous;
				
				E element = temp->element;
				
				deleteNode(temp);
				return element;
			}
			
			void deleteNode(Node<E> *node) {
				delete ( node );
				this->nodeSize--;
            }
			
			void exception() {
				throw std::invalid_argument("[ERROR]: index is out o scope");
			}
		};
	}
}

#endif //NATIVE_JAVA_UTIL_LINKED_LIST_HPP
