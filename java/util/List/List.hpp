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

#ifndef JAVA_UTIL_LIST_HPP_
#define JAVA_UTIL_LIST_HPP_

#include "../function/UnaryOperator/UnaryOperator.hpp"
#include "../Iterator/Iterator.hpp"
#include "../Collection/Collection.hpp"
#include "../Comparator/Comparator.hpp"

namespace Java {
		namespace Util {
				template <class E>
				class ListIterator;
				
				template <class E>
				class List;
				
				template <class E>
				class List : public virtual Collection<E> {
				public:
						/**
						 * Appends the specified element to the end of this list (optional operation).
						 *
						 * @param e
						 * @return boolean
						 */
						virtual boolean add(E element);
						
						/**
						 * Inserts the specified element at the specified position in this list (optional operation).
						 *
						 * @param index
						 * @param element
						 * @return
						 */
						virtual void add(int index, E element) = 0;
						
						/**
						 * Appends all of the elements in the specified collection to the end of this list,
						 * in the order that they are returned by the specified collection's iterator (optional operation).
						 *
						 * @param c
						 * @return boolean
						 */
//			virtual boolean addAll(Collection<E> &c) = 0; //FIXME: should to implement foreach first
						
						/**
						 * Inserts all of the elements in the specified collection
						 * into this list at the specified position (optional operation).
						 *
						 * @param index
						 * @param c
						 * @return boolean
						 */
//			virtual boolean addAll(int index, Collection<E> &c) = 0; //FIXME: should to implement foreach first
						
						/**
						 * Removes all of the elements from this list (optional operation).
						 */
						virtual void clear();
						
						/**
						 * Returns true if this list contains the specified element.
						 *
						 * @param o
						 * @return boolean
						 */
						virtual boolean contains(E element);
						
						/**
						 * Returns true if this list contains all of the elements of the specified collection.
						 * @param c
						 * @return
						 */
//			virtual boolean containsAll(Collection<Object> &c) const = 0; //FIXME: implement foreach this first
						
						/**
						 * Compares the specified object with this list for equality.
						 * @param o
						 * @return
						 */
						virtual boolean equals(const Object object);
						
						/**
						 * Returns the element at the specified position in this list.
						 * @param index
						 * @return E
						 */
						virtual E get(int index);
						
						/**
						 * Returns the hash code value for this list.
						 * @return
						 */
						virtual long hashCode();
						
						/**
						 * Returns the index of the first occurrence of the specified element in this list,
						 * or -1 if this list does not contain the element.
						 * @param o
						 * @return
						 */
						virtual int indexOf(E element);
						
						/**
						 * Returns true if this list contains no elements.
						 * @return boolean
						 */
						virtual boolean isEmpty();
						
						/**
						 * Don't support this method
						 * @return
						 */
//			virtual Iterator<E> &iterator() const = 0;
						
						/**
						 * Returns the index of the last occurrence of the specified element in this list,
						 * or -1 if this list does not contain the element.
						 * @param o
						 * @return
						 */
						virtual int lastIndexOf(E element);
						
						/**
						 * Don't support this method
						 */
//			virtual ListIterator<E> &listIterator() const = 0;
						
						/**
						 * Don't support this method
						 */
//			virtual ListIterator<E> &listIterator(int index) const = 0;
						
						/**
						 * Removes the element at the specified position in this list (optional operation).
						 * @param index
						 * @return E
						 */
//			virtual E remove(int index) = 0; //Note: duplicate function, just implement at derived class
						
						/**
						 * Removes the first occurrence of the specified element from this list,
						 * if it is present (optional operation).
						 * @param o
						 * @return boolean
						 */
//			virtual boolean remove(Object &o) = 0; //Note: duplicate function, just implement at derived class
						
						/**
						 * Removes from this list all of its elements that are contained in the specified collection
						 * (optional operation).
						 * @param c
						 * @return boolean
						 */
//			virtual boolean removeAll(Collection<Object> &c) = 0; //FIXME: implement foreach this first
						
						/**
						 * Replaces the element at the specified position in this list with the specified element
						 * (optional operation).
						 * @param index
						 * @param element
						 * @return E
						 */
						virtual E set(int index, E element);
						
						/**
						 * Returns the number of elements in this list.
						 * @return int
						 */
						virtual int size();
						
						/**
						 * Don't support this method
						 */
//			virtual Spliterator<E> &spliterator() const  = 0;
						
						/**
						 * Don't support this method
						 */
//			virtual List<E> &subList(int fromIndex, int toIndex) const = 0;
						
						/**
						 * Don't support this method
						 */
//			virtual Array<Object> &toArray() const = 0;
						
						/**
						 * Don't support this method
						 */
//			template <typename T>
//			Array<T> toArray(Array<T> &a) const;
				};
		}
}

#endif  // JAVA_UTIL_LIST_HPP_
