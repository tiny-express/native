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

#ifndef JAVA_UTIL_ARRAY_LIST_HPP_
#define JAVA_UTIL_ARRAY_LIST_HPP_

#include "../../Lang.hpp"
#include "../../io/Serializable/Serializable.hpp"
#include "../AbstractList/AbstractList.hpp"
#include "../Collection/Collection.hpp"
#include "../RandomAccess/RandomAccess.hpp"
#include "../ListIterator/ListIterator.hpp"
#include "../List/List.hpp"
#include "../Comparator/Comparator.hpp"
#include "../Spliterator/Spliterator.hpp"
#include "../function/Consumer/Consumer.hpp"
#include "../function/Predicate/Predicate.hpp"
#include "../function/UnaryOperator/UnaryOperator.hpp"
#include "../../lang/String/String.hpp"
#include "../../lang/IndexOutOfBoundsException/IndexOutOfBoundsException.hpp"
#include <initializer_list>
#include <iostream>

using namespace Java::Lang;
using namespace Java::IO;
using namespace Java::Util::Function;

namespace Java {
		namespace Util {
				template <class E>
				class ArrayList;
				
				template <class E>
				class ArrayList :
					// public virtual AbstractList<E>,
					// public virtual List<E>,
					public virtual Serializable,
					public virtual Cloneable,
					public virtual RandomAccess {
				
				private:
						std::vector<E> original;
						String backup;
						typedef E *_iterator;
						typedef const E *_const_iterator;
				
				public:
						_iterator begin() {
							this->original[0];
							return &this->original[ 0 ];
						}
						
						_const_iterator begin() const {
							return &this->original[ 0 ];
						}
						
						_iterator end() {
							return &this->original[ this->original.size() ];
						}
						
						_const_iterator end() const {
							return &this->original[ this->original.size() ];
						}
						
						/**
						 * Constructs an empty list
						 */
						ArrayList() {
						}
						
						/**
						 * ArrayList copy constructor from initializer list
						 *
						 * @param target
						 */
						ArrayList(const std::initializer_list<E> &target) {
							for (E item : target) {
								this->add(item);
							}
						}
						
						/**
						 * Array copy constructor for basic array
						 *
						 * @param target
						 */
						ArrayList(const Array<E> &target) {
							for (E item : target) {
								this->add(item);
							}
						}
						
						/**
						 * Constructs a list containing the elements of the specified collection
						 *
						 * @param collection
						 */
						ArrayList(Collection<E> collection) {
						
						}
						
						/**
						 * Constructs an empty list with the specified initial capacity.
						 *
						 * @param initialCapacity
						 */
						ArrayList(int initialCapacity) {
							this->original.resize(initialCapacity);
						}
						
						/**
						 * Destructor ArrayList
						 */
						~ArrayList() {
						
						}
				
				public:
						
						/**
						 * Appends the specified element to the end of this list.
						 *
						 * @param e
						 * @return boolean
						 */
						boolean add(E element) {
							this->original.push_back(element);
							return true;
						}
						
						/**
						 * Inserts the specified element at the specified position in this list.
						 *
						 * @param index
						 * @param element
						 */
						void add(int index, E element) {
							if (index < 0 || index > this->original.size() - 1) {
								return;
							}
							this->original.insert(this->original.begin() + index, element);
						}
						
						/**
						 * Appends all of the elements in the specified collection to the end of this list,
						 * in the order that they are returned by the specified collection's Iterator.
						 *
						 * @param c
						 * @return boolean
						 */
						boolean addAll(Collection<E> collection) {
							// TODO: Please discuss about param Collection
							return true;
						}
						
						/**
						 * Inserts all of the elements in the specified collection into this list,
						 * starting at the specified position.
						 *
						 * @param index
						 * @param collection
						 * @return boolean
						 */
						boolean addAll(int index, Collection<E> collection) {
							// TODO: Please discuss about param Collection
							return true;
						}
						
						/**
						 * Removes all of the elements from this list.
						 *
						 */
						void clear() {
							this->original.clear();
						}
						
						/**
						 * Returns a shallow copy of this ArrayList instance.
						 *
						 * @return ArrayList
						 */
						ArrayList clone() {
							ArrayList<E> resultArrayList = *this;
							return resultArrayList;
						}
						
						/**
						 * Returns true if this list contains the specified element.
						 *
						 * @param element
						 * @return boolean
						 */
						boolean contains(E element) const {
							for (E item : *this) {
								if (item == element) {
									return true;
								}
							}
							return false;
						}
						
						/**
						 * Returns true if this collection contains all of the elements in the specified collection.
						 *
						 * @param collection
						 * @return boolean
						 */
						boolean containsAll(Collection<Object> collection) const {
							// TODO: Please discuss about param Collection
							return true;
						}
						
						/**
						 * Increases the capacity of this ArrayList instance, if necessary,
						 * to ensure that it can hold at least the number of elements specified by
						 * the minimum capacity argument.
						 *
						 * @param minCapacity
						 */
						void ensureCapacity(int minCapacity) const {
							this->original.reserve(minCapacity);
						}
						
						/**
						 *  Performs the given action for each element of the Iterable until all elements
						 *  have been processed or the action throws an exception.
						 *
						 * @param action
						 */
						void forEach(Consumer<E> action) const {
							// TODO: Please complete class Consumer
						}
						
						/**
						 * Returns the element at the specified position in this list.
						 *
						 * @param index
						 * @return E
						 */
						E get(int index) const {
							if (index < 0 || index >= this->size()) {
								String message = "Index out of range: ";
								message += Integer(index).stringValue();
								throw IndexOutOfBoundsException(message);
							}
							return original.at(index);
						}
						
						/**
						 * Returns the index of the first occurrence of the specified element in this list,
						 * or -1 if this list does not contain the element.
						 *
						 * @param element
						 * @return int
						 */
						int indexOf(E element) const {
							int index;
							for (index = 0; index < this->size(); ++index) {
								if (this->get(index) == element) {
									return index;
								}
							}
							return -1;
						}
						
						/**
						 * Returns true if this list contains no elements.
						 *
						 * @return boolean
						 */
						boolean isEmpty() const {
							return original.empty();
						}
						
						/**
						 * Returns an iterator over the elements in this list in proper sequence.
						 *
						 * @return Address of Iterator<E>
						 */
						Iterator<E> &iterator() const {
							// TODO: Please complete class Iterator
							Iterator<E> *it = new Iterator<E>();
							return *it;
						}
						
						/**
						 * Returns the index of the last occurrence of the specified element in this list,
						 * or -1 if this list does not contain the element.
						 *
						 * @param object
						 * @return int
						 */
						int lastIndexOf(E element) const {
							int index;
							for (index = this->size() - 1; index >= 0; --index) {
								if (this->get(index) == element) {
									return index;
								}
							}
							return -1;
						}
						
						/**
						 * Returns a list iterator over the elements in this list (in proper sequence).
						 *
						 * @return Address of ListIterator<E>
						 */
						ListIterator<E> &listIterator() const {
							ListIterator<E> *listIterator = new ListIterator<E>();
							return *listIterator;
						}
						
						/**
						 * Returns a list iterator over the elements in this list (in proper sequence),
						 * starting at the specified position in the list.
						 *
						 * @param index
						 * @return Address of ListIterator<E>
						 */
						ListIterator<E> &listIterator(int index) const {
							ListIterator<E> *listIterator = new ListIterator<E>();
							return *listIterator;
						}
						
						/**
						 * Removes the element at the specified position in this list.
						 *
						 * @param index
						 * @return Address of element
						 */
						E remove(int index) {
							if (index < 0 || index >= this->size()) {
								String message = "Index out of range: ";
								message += Integer(index).stringValue();
								throw IndexOutOfBoundsException(message);
							}
							
							E holder = this->get(index);
							this->original.erase(this->original.begin() + index);
							return holder;
						}
						
						/**
						 * Removes the first occurrence of the specified element
						 * from this list, if it is present.
						 *
						 * @param element
						 * @return boolean
						 */
						boolean remove(E element) {
							int position = this->indexOf(element);
							if (position == -1) {
								return false;
							}
							this->remove(position);
							return true;
						}
						
						/**
						 * Removes from this list all of its elements that are
						 * contained in the specified collection.
						 *
						 * @param target
						 * @return boolean
						 */
						boolean removeAll(Collection<Object> target) {
							// TODO: Please discuss about param Collection
							return true;
						}
						
						/**
						 * Removes all of the elements of this collection that satisfy the given predicate.
						 *
						 * @param filter
						 * @return boolean
						 */
						boolean removeIf(Predicate<E> filter) {
							// TODO: Please complete class Predicate
							return true;
						}
						
						/**
						 * Replaces each element of this list with the result of applying
						 * the operator to that element.
						 *
						 * @param unaryOperator
						 */
						void replaceAll(UnaryOperator<E> unaryOperator) {
							// TODO: Please complete class UnaryOperator
						}
						
						/**
						 * Retains only the elements in this list that are contained
						 * in the specified collection.
						 *
						 * @param collection
						 * @return boolean
						 */
						boolean retainAll(Collection<Object> collection) {
							// TODO: Please discuss about Param Collection
							return true;
						}
						
						/**
						 * Replaces the element at the specified position in this list with
						 * the specified element.
						 *
						 * @param index
						 * @param element
						 * @return E
						 */
						E set(int index, E element) {
							if (index < 0 || index >= this->size()) {
								String message = "Index out of range: ";
								message += Integer(index).stringValue();
								throw IndexOutOfBoundsException(message);
							}
							this->original[ index ] = element;
							return this->original[ index ];
						}
						
						/**
						 * Return the number of the all element of this list
						 *
						 * @return int
						 */
						int size() const {
							return static_cast<int>(this->original.size());
						}
						
						/**
						 * Sorts this list according to the order induced by the specified Comparator.
						 *
						 * @param cmp
						 */
						void sort(Comparator<E> cmp) {
							// TODO: Please complete class Comparator
						}
						
						/**
						 * Creates a late-binding and fail-fast Spliterator over the elements in this list.
						 *
						 * @return Spliterator<E>
						 */
						Spliterator<E> &spliterator() const {
							// TODO: Please complete class Spliterator
							Spliterator<E> *spliterator = new Spliterator<E>();
							return *spliterator;
						}

//            List<E> &subList(int fromIndex, int toIndex) const {
//                // TODO: Please discuss about type return List
//                List<E> *list = new ArrayList<E>();
//                return *list;
//            }

/**
 * Returns an array containing all of the elements in this
 * list in proper sequence (from first to last element).
 *
 * @return Array<Object>
 */
						Array<E> toArray() {
							Array<E> resultArray;
							for (E item : *this) {
								resultArray.push(item);
							}
							return resultArray;
						}

//			/**
//			 * Returns an array containing all of the elements in this list
//			 * in proper sequence (from first to last element);the runtime type of
//			 * the returned array is that of the specified array.
//			 *
//			 * @tparam T
//			 * @param a
//			 * @return Array<T>
//			 */
//			template <class T>
//			Array<T> &toArray(Array<T> array) const {
//				return array;
//			}

/**
 * Trims the capacity of this ArrayList instance to be the list's current size.
 */
						void trimToSize() {
							this->original.shrink_to_fit();
						}

/**
 * Convert ArrayList to string
 *
 * @return string
 */
						string toString() {
							if (this->size() == 0) {
								this->backup = "[]";
								return this->backup.toString();
							}
							String startArrayList = "[";
							String commaAndSpace = ", ";
							String endArrayList = "]";
							int index;
							for (index = 0; index < this->size() - 1; ++index) {
								String appendString = this->original[ index ].toString();
								appendString += commaAndSpace;
								startArrayList += appendString;
							}
							startArrayList += this->original[ this->size() - 1 ].toString();
							// Remove last semicolon
							if (startArrayList.length() > 0) {
								startArrayList = startArrayList.subString(0, startArrayList.length());
							}
							startArrayList += endArrayList;
							this->backup = startArrayList;
							return this->backup.toString();
						}

/**
 * A hash code value for this object.
 *
 * @return long
 */
						long hashCode() const {
							return Object::hashCode();
						}

// TODO: Please discuss about param Object
						boolean equals(const Object object) const {
							return true;
						}

/**
 * Print ArrayList to screen
 *
 * @param os
 * @param target
 * @return std::ostream
 */
						friend std::ostream &operator<<(std::ostream &os, const ArrayList &target) {
							for (E item : target) {
								os << item << " ";
							}
							os << std::endl;
							return os;
						}

/**
 * Get and set element at index in ArrayList
 *
 * @param index
 * @return E
 */
						E &operator[](int index) {
							return this->original[ index ];
						}
				
				protected:
/**
 * Removes from this list all of the elements
 * whose index is between fromIndex, inclusive, and toIndex, exclusive.
 * Shifts any succeeding elements to the left (reduces their index).
 *
 * @param fromIndex
 * @param toIndex
 */
						void removeRange(int fromIndex, int toIndex) {
							this->original.erase(this->original.begin() + fromIndex,
							                     this->original.begin() + toIndex);
						}
				};
				
				template <class E>
				class SubList : public virtual AbstractList<E> {
				private:
						AbstractList<E> l;
				};
			
		} // namespace Util
} // namespace Java

#endif  // JAVA_UTIL_ARRAY_LIST_HPP_
