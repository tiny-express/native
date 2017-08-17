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

#ifndef NATIVE_JAVA_UTIL_VECTOR_HPP
#define NATIVE_JAVA_UTIL_VECTOR_HPP

#include "../../Lang.hpp"
#include "../AbstractSequentialList/AbstractSequentialList.hpp"
#include "../Collection/Collection.hpp"
#include "../RandomAccess/RandomAccess.hpp"
#include <initializer_list>

using namespace Java::Lang;

namespace Java {
		namespace Util {
				template <typename E>
				class Vector
//                :
//                public virtual List<E>,
//                public virtual RandomAccess,
//                public virtual Cloneable,
//                public virtual Serializable
				{
				protected:
						std::vector<E> original;
						int capacityIncrement;
				
				public:
						/**
						 * Vector Constructor
						 * Constructs an empty vector so that its internal data array has size 10 and its standard capacity increment is zero.
						 */
						Vector() : Vector(10) {
						}
						
						/**
						 * Vector Constructor
						 * Constructs an empty vector with the specified initial capacity and with its capacity increment equal to zero.
						 *
						 * @param initialCapacity
						 * @throw - if the specified initial capacity is negative
						 */
						Vector(int initialCapacity) : Vector(initialCapacity, 0) {
						}
						
						/**
						 * Vector Constructor
						 * Constructs an empty vector with the specified initial capacity and capacity increment.
						 *
						 * @param initialCapacity
						 * @param capacityIncrement
						 * @throw - if the specified initial capacity is negative
						 */
						Vector(int initialCapacity, int capacityIncrement) {
							if (initialCapacity < 0) {
								throw std::invalid_argument("initial capacity is negative");
							}
							this->original.reserve(initialCapacity);
							this->capacityIncrement = capacityIncrement;
						}
						
						/**
						 * Vector Constructor
						 * Constructs a Vector containing the elements of the initializer list.
						 *
						 * @param list
						 */
						Vector(const std::initializer_list<E> &list) {
							this->original.reserve(list.size());
							typename std::initializer_list<E>::iterator listIterator;
							for (listIterator = list.begin(); listIterator != list.end(); listIterator++) {
								this->original.push_back(*listIterator);
							}
						}
						
						/**
						 * Vector Constructor
						 * Constructs a Vector from a Vector.
						 *
						 * @param target
						 */
						Vector(const Vector<E> &target) {
							const E *targetData = target.original.data();
							register int index;
							for (index = 0; index < target.original.size(); index++) {
								this->original.push_back(targetData[ index ]);
							}
						}
						
						/**
						 * Vector Destructor
						 */
						virtual ~Vector() {
						}
				
				public:
						/**
						 * Adds an element to the end of this Vector.
						 *
						 * @param element
						 * @return boolean
						 */
						boolean add(const E &element) {
							int oldSize = (int) this->original.size();
							this->ensureCapacity(oldSize + 1);
							this->original.push_back(element);
							return ( oldSize != this->original.size());
						}
						
						/**
						 * Inserts a new element to the specified index in this Vector.
						 *
						 * @param index
						 * @param element
						 */
						void add(int index, const E &element) {
							int size = (int) this->original.size();
							if (index < 0 || index > size) {
								throw std::invalid_argument("index is out of range");
							}
							this->ensureCapacity(size + 1);
							this->original.insert(this->original.begin() + index, element);
						}
						
						/**
						 * Appends all of the elements in the specified initializer list to the end of this Vector.
						 *
						 * @param list
						 * @return boolean
						 */
						boolean addAll(const std::initializer_list<E> &list) {
							return this->addAll(0, list);
						}
						
						/**
						 * Inserts all of the elements in the specified initializer list into this Vector at the specified index.
						 *
						 * @param index
						 * @param list
						 * @return boolean
						 */
						boolean addAll(int index, const std::initializer_list<E> &list) {
							typename std::initializer_list<E>::iterator listIterator;
							for (listIterator = list.begin(); listIterator != list.end(); listIterator++) {
								this->add(index, ( *listIterator ));
								// We increase index by 1, because we must insert next element
								// after element we have inserted before.
								index = index + 1;
							}
							return ( list.size() != 0 );
						}
						
						/**
						 * Adds an element to the end of this Vector.
						 *
						 * @param element
						 */
						void addElement(const E &element) {
							this->add(element);
						}
						
						/**
						 * Return capacity (current number of slots allocated for this Vector).
						 *
						 * @return int
						 */
						int capacity() const {
							return (int) this->original.capacity();
						}
						
						/**
						 * Clears all element inside this Vector.
						 */
						void clear() {
							this->original.clear();
						}
						
						/**
						 * Returns a clone of this Vector.
						 *
						 * @return Vector<E>
						 */
						Vector<E> clone() const {
							Vector<E> clonedVector;
							const E *vectorData = this->original.data();
							register int index;
							for (index = 0; index < this->original.size(); index++) {
								clonedVector.add(vectorData[ index ]);
							}
							return clonedVector;
						}
						
						/**
						 * Returns true if this Vector contains the specified element.
						 *
						 * @param element
						 * @return boolean
						 */
						boolean contains(const E &element) const {
							return ( this->indexOf(element) != -1 );
						}
						
						/**
						 * Returns true if this Vector contains all of the elements in the specified initializer list.
						 *
						 * @param list
						 * @return boolean
						 */
						boolean containsAll(const std::initializer_list<E> &list) {
							typename std::initializer_list<E>::iterator listIterator;
							typename std::vector<E>::iterator vectorIterator;
							for (listIterator = list.begin(); listIterator != list.end(); listIterator++) {
								vectorIterator = std::find(this->original.begin(), this->original.end(), *listIterator);
								if (vectorIterator == this->original.end()) {
									return false;
								}
							}
							return true;
						}
						
						/**
						 * Copies the components of this vector into the specified array.
						 *
						 * @param anArray
						 */
						void copyInto(Array<E> &anArray) const {
							typename std::vector<E>::const_iterator vectorIterator;
							for (vectorIterator = this->original.cbegin(); vectorIterator != this->original.cend(); vectorIterator++) {
								anArray.push(*vectorIterator);
							}
						}
						
						/**
						 * Gets an element at specified index.
						 *
						 * @param index
						 * @return E
						 */
						E elementAt(int index) const {
							return this->get(index);
						}
						
						/**
						 * Returns an enumeration of the components of this Vector.
						 *
						 * @return Enumeration<E>
						 */
//          Enumeration<E> elements() const {
//              // TODO
//          }
						
						/**
						 * Increases the capacity of this Vector,
						 * if necessary, to ensure that it can hold at least the number of elements specified by
						 * the minimum capacity argument.
						 *
						 * @param minCapacity
						 */
						void ensureCapacity(int minCapacity) {
							int oldCapacity = this->capacity();
							if (( minCapacity > 0 ) && ( minCapacity > oldCapacity )) {
								int newCapacity;
								if (this->capacityIncrement > 0) {
									newCapacity = oldCapacity + this->capacityIncrement;
								} else {
									newCapacity = oldCapacity * 2;
								}
								
								if (newCapacity < minCapacity) {
									newCapacity = minCapacity;
								}
								
								this->original.reserve(newCapacity);
							}
						}
						
						/**
						 * Compares the specified Vector with this Vector for equality.
						 *
						 * @param target
						 * @return boolean
						 */
						boolean equals(const Vector<E> &target) const {
							int size = this->size();
							if (size != target.size()) {
								return false;
							}
							
							register int index;
							for (index = 0; index < size; index++) {
								E elementOfVector = this->original[ index ];
								E elementOfTarget = target.original[ index ];
								if (elementOfVector != elementOfTarget) {
									return false;
								}
							}
							
							return true;
						}
						
						/**
						 * Returns the first element (index = 0) of this Vector.
						 *
						 * @return E
						 */
						E firstElement() {
							if (this->original.empty()) {
								throw std::out_of_range("vector is empty");
							}
							return this->original.front();
						}
						
						/**
						 * Gets an element at specified index.
						 *
						 * @param index
						 * @return E
						 */
						E get(int index) const {
							if (index < 0 || index >= this->original.size()) {
								throw std::invalid_argument("index is out of range");
							}
							return this->original.at(index);
						}
						
						/**
						 * Returns the hash code value for this Vector.
						 *
						 * @return int
						 */
						int hashCode() const {
							// TODO
						}
						
						/**
						 * Returns index of an element in this Vector or returns -1 if the element is not found.
						 *
						 * @param element
						 * @return int
						 */
						int indexOf(const E &element) const {
							int currentSize = (int) this->original.size();
							register int index;
							for (index = 0; index < currentSize; index++) {
								if (element == this->original[ index ]) {
									return index;
								}
							}
							return -1;
						}
						
						/**
						 * Returns the index of the first occurrence of the specified element in this Vector,
						 * searching forwards from index, or returns -1 if the element is not found.
						 *
						 * @param element
						 * @param index
						 * @return int
						 */
						int indexOf(const E &element, int index) {
							if (index < 0) {
								throw std::invalid_argument("index is negative");
							}
							
							register int position;
							for (position = index; position < this->original.size(); position++) {
								if (element == this->original[ position ]) {
									return position;
								}
							}
							
							return -1;
						}
						
						/**
						 * Inserts the specified element at the specified index in this Vector.
						 *
						 * @param element
						 * @param index
						 */
						void insertElementAt(const E &element, int index) {
							this->add(index, element);
						}
						
						/**
						 * Checks this Vector is empty or not.
						 *
						 * @return boolean
						 */
						boolean isEmpty() const {
							return this->original.empty();
						}
						
						/**
						 * Returns an iterator over the elements in this list in proper sequence.
						 * @return Iterator<E>
						 */
//          Iterator<E> iterator() const {
//              // TODO
//          }
						
						/**
						 * Returns the last element of this Vector.
						 *
						 * @return E
						 */
						E lastElement() const {
							if (this->original.empty()) {
								throw std::out_of_range("vector is empty");
							}
							return this->original.back();
						}
						
						/**
						 * The last index of an element.
						 * This function returns the index of the last occurrence of the specified element in this Vector.
						 * If this Vector doesn't contain the element, returns -1.
						 *
						 * @param element
						 * @return int
						 */
						int lastIndexOf(const E &element) const {
							int maxIndex = (int) this->original.size() - 1;
							return this->lastIndexOf(element, maxIndex);
						}
						
						/**
						 * Returns the index of the last occurrence of the specified element in this Vector,
						 * searching backwards from index, or returns -1 if the element is not found.
						 *
						 * @param element
						 * @param index
						 * @return int
						 */
						int lastIndexOf(const E &element, int index) const {
							if (index >= this->original.size()) {
								throw std::invalid_argument("index is greater than or equal to the current size of this vector");
							}
							
							register int position;
							for (position = index; position >= 0; position--) {
								if (element == this->original[ position ]) {
									return position;
								}
							}
							
							return -1;
						}
						
						/**
						 * Returns a list iterator over the elements in this list (in proper sequence).
						 *
						 * @return ListIterator<E>
						 */
						ListIterator<E> listIterator() const {
							// TODO
						}
						
						/**
						 * Returns a list iterator over the elements in this list (in proper sequence),
						 * starting at the specified position in the list.
						 *
						 * @param index
						 * @return ListIterator<E>
						 */
						ListIterator<E> listIterator(int index) {
							// TODO
						}
						
						/**
						 * Removes an element at specified index in this Vector.
						 *
						 * @param index
						 * @return E
						 */
						E remove(int index) {
							if (index < 0 || index >= this->original.size()) {
								throw std::invalid_argument("index is out of range");
							}
							E removedItem = this->original.at(index);
							this->original.erase(this->original.begin() + index);
							return removedItem;
						}
						
						/**
						 * Removes the first occurrence of the specified element in this Vector.
						 *
						 * @param element
						 * @return boolean
						 */
						boolean remove(const Object &element) {
							const E *referenceToElement = dynamic_cast<const E *>(&element);
							register int index;
							for (index = 0; index < this->original.size(); index++) {
								if (( *referenceToElement ) == this->original[ index ]) {
									this->remove(index);
									return true;
								}
							}
							return false;
						}
						
						/**
						 * Removes from this Vector all of its elements that are contained in the specified initializer list.
						 *
						 * @param list
						 * @return boolean
						 */
						boolean removeAll(const std::initializer_list<E> &list) {
							int oldSize = (int) this->original.size();
							typename std::vector<E>::iterator vectorIterator;
							typename std::initializer_list<E>::iterator listIterator;
							for (vectorIterator = this->original.begin(); vectorIterator != this->original.end();) {
								listIterator = std::find(list.begin(), list.end(), *vectorIterator);
								if (listIterator != list.end()) {
									this->original.erase(vectorIterator);
								} else {
									vectorIterator++;
								}
							}
							return ( oldSize != this->original.size());
						}
						
						/**
						 * Removes all elements of this Vector.
						 */
						void removeAllElements() {
							this->clear();
						}
						
						/**
						 * Removes the first (lowest-indexed) occurrence of the argument from this ector.
						 *
						 * @param element
						 * @return boolean
						 */
						boolean removeElement(const Object &element) {
							return this->remove(element);
						}
						
						/**
						 * Deletes the element at the specified index.
						 *
						 * @param index
						 */
						void removeElementAt(int index) {
							this->remove(index);
						}
						
						/**
						 * Removes all of the elements of this Vector that satisfy the given predicate.
						 *
						 * @param filter
						 * @return boolean
						 */
//          boolean removeIf(Predicate<E> filter) {
//              // TODO
//          }
				
				protected:
						/**
						 * Removes all elements have index between fromIndex (inclusive) and toIndex (exclusive).
						 *
						 * @param fromIndex
						 * @param toIndex
						 */
						void removeRange(int fromIndex, int toIndex) {
							if (fromIndex >= toIndex) {
								return;
							}
							
							int currentSize = (int) this->original.size();
							if (fromIndex < 0 || fromIndex >= currentSize || toIndex < 0 || toIndex >= currentSize) {
								return;
							}
							
							int numberOfElementsWillBeDeleted = toIndex - fromIndex; // Excluding element at toIndex;
							int numberOfElementsDeleted;
							for (numberOfElementsDeleted = 0; numberOfElementsDeleted < numberOfElementsWillBeDeleted; numberOfElementsDeleted++) {
								this->remove(fromIndex);
							}
						}
				
				public:
						/**
						 * Removes all of the elements of this collection that satisfy the given predicate.
						 *
						 * @param filter
						 * @return boolean
						 */
//          boolean	removeIf(Predicate<E> filter) {
//              // TODO
//          }
						
						/**
						 * Replaces each element of this list with the result of applying the operator to that element.
						 *
						 * @param unaryOperator
						 */
//          void replaceAll(UnaryOperator<E> unaryOperator) {
//              // TODO
//          }
						
						/**
						 * Retains only the elements in this Vector that are contained in the specified initializer list.
						 *
						 * @param list
						 * @return boolean
						 */
						boolean retainAll(const std::initializer_list<E> &list) {
							int oldSize = (int) this->original.size();
							typename std::vector<E>::iterator vectorIterator;
							typename std::initializer_list<E>::iterator listIterator;
							for (vectorIterator = this->original.begin(); vectorIterator != this->original.end();) {
								listIterator = std::find(list.begin(), list.end(), *vectorIterator);
								if (listIterator == list.end()) {
									this->original.erase(vectorIterator);
								} else {
									vectorIterator++;
								}
							}
							return ( oldSize != this->original.size());
						}
						
						/**
						 * Replaces the element at the specified index with the specified element.
						 *
						 * @param index
						 * @param element
						 * @return E
						 */
						E set(int index, const E &element) {
							if (index < 0 || index >= this->original.size()) {
								throw std::invalid_argument("index is out of range");
							}
							E removedElement = this->get(index);
							this->original[ index ] = element;
							return removedElement;
						}
						
						/**
						 * Sets the element at the specified index of this Vector to be the specified element.
						 *
						 * @param element
						 * @param index
						 */
						void setElementAt(const E &element, int index) {
							this->set(index, element);
						}
						
						/**
						 * Sets the size of this Vector.
						 *
						 * @param newSize
						 */
						void setSize(int newSize) {
							if (newSize < 0) {
								throw std::invalid_argument("new size is negative");
							}
							if (newSize > this->original.size()) {
								this->ensureCapacity(newSize);
							}
							this->original.resize(newSize);
						}
						
						/**
						 * Returns size (number of elements) of this Vector.
						 *
						 * @return int
						 */
						int size() const {
							return (int) this->original.size();
						}
						
						/**
						 * Sorts this list according to the order induced by the specified Comparator.
						 *
						 * @param comparator
						 */
						void sort(Comparator<E> comparator) {
							// TODO
						}
						
						/**
						 * Creates a late-binding and fail-fast Spliterator over the elements in this list.
						 *
						 * @return Spliterator<E>
						 */
						Spliterator<E> spliterator() const {
						
						}
						
						/**
						 * Returns a view of the portion of this List between fromIndex, inclusive, and toIndex, exclusive.
						 *
						 * @param fromIndex
						 * @param toIndex
						 * @return List<E>
						 */
						List<E> subList(int fromIndex, int toIndex) const {
							// TODO
						}
						
						/**
						 * Returns an array containing all of the elements in this Vector in the correct order.
						 *
						 * @return Array<E>
						 */
						Array<E> toArray() const {
							Array<E> anArray;
							typename std::vector<E>::const_iterator vectorIterator;
							for (vectorIterator = this->original.cbegin(); vectorIterator != this->original.cend(); vectorIterator++) {
								anArray.push(*vectorIterator);
							}
							return anArray;
						}
						
						/**
						 * Returns an array containing all of the elements in this Vector in the correct order;
						 * the runtime type of the returned array is that of the specified array.
						 *
						 * @param anArray
						 * @return Array<E>
						 */
						Array<E> toArray(const Array<E> &anArray) const {
							int arrayLength = anArray.length;
							int vectorLength = (int) this->original.size();
							if (arrayLength < vectorLength) {
								return toArray();
							}
							
							typename std::vector<E>::iterator vectorIterator;
							int arrayIndex = 0;
							for (vectorIterator = this->original.begin(); vectorIterator != this->original; vectorIterator++) {
								anArray[ arrayIndex ] = *vectorIterator;
								arrayIndex++;
							}
							
							if (arrayLength > vectorLength) {
								// anArray[vectorLength] = nullptr; // FIXME: Can't assign null value.
							}
							
							return anArray;
						}
						
						/**
						 * Trims the capacity of this Vector to be the Vector's current size.
						 */
						void trimToSize() {
							this->original.shrink_to_fit();
						}
						
						/**
						 * Returns a string representation of this Vector, containing the String representation of each element.
						 *
						 * @return String
						 */
						String toString() const {
							// TODO
						}
				
				public:
						typedef typename std::vector<E>::iterator iterator;
						typedef typename std::vector<E>::const_iterator const_iterator;
						
						/**
						 * Returns an iterator pointing to the first element in the Vector.
						 *
						 * @return iterator
						 */
						iterator begin() {
							return this->original.begin();
						}
						
						/**
						 * Returns a const_iterator pointing to the first element in the Vector.
						 *
						 * @return const_iterator
						 */
						const_iterator begin() const {
							return this->original.begin();
						}
						
						/**
						 * Returns a const_iterator pointing to the first element in the Vector.
						 *
						 * @return const_iterator
						 */
						const_iterator cbegin() const {
							return this->original.cbegin();
						}
						
						/**
						 * Returns an iterator referring to the past-the-end element in the Vector.
						 *
						 * @return iterator
						 */
						iterator end() {
							return this->original.end();
						}
						
						/**
						 * Returns a const_iterator referring to the past-the-end element in the Vector.
						 *
						 * @return const_iterator
						 */
						const_iterator end() const {
							return this->original.end();
						}
						
						/**
						 * Returns a const_iterator pointing to the past-the-end element in the Vector.
						 *
						 * @return const_iterator
						 */
						const_iterator cend() const {
							return this->original.cend();
						}
						
						/**
						 * Array operator.
						 * Uses this operator to access an element at the specified index.
						 *
						 * @param index
						 * @return E
						 */
						E &operator[](const int index) {
							if (index < 0 || index >= this->original.size()) {
								throw std::invalid_argument("index is out of range");
							}
							E *vectorData = this->original.data();
							return *( vectorData + index );
						}
						
						const E &operator[](const int index) const {
							if (index < 0 || index >= this->original.size()) {
								throw std::invalid_argument("index is out of range");
							}
							const E *vectorData = this->original.data();
							return *( vectorData + index );
						}
						
						/**
						 * Assignment operator.
						 * Assigns values from right side operands to left side operand.
						 *
						 * @param target
						 * @return Vector<E>
						 */
						Vector<E> &operator=(const Vector<E> &target) {
							this->clear();
							this->ensureCapacity(target.size());
							const E *targetData = target.original.data();
							register int index;
							for (index = 0; index < target.size(); index++) {
								this->original.push_back(targetData[ index ]);
							}
							return *this;
						}
						
						/**
						 * Assignment operator.
						 * Assigns values from right side operands to left side operand.
						 *
						 * @param list
						 * @return Vector<E>
						 */
						Vector<E> &operator=(const std::initializer_list<E> &list) {
							this->clear();
							this->ensureCapacity((int) list.size());
							typename std::initializer_list<E>::iterator listIterator;
							for (listIterator = list.begin(); listIterator != list.end(); listIterator++) {
								this->original.push_back(*listIterator);
							}
							return *this;
						}
				};
		}
}

#endif // NATIVE_JAVA_UTIL_VECTOR_HPP
