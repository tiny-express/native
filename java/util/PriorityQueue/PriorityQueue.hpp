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

#ifndef JAVA_UTIL_PRIORITY_QUEUE_HPP
#define JAVA_UTIL_PRIORITY_QUEUE_HPP

#include "../Collection/Collection.hpp"
#include "../Comparator/Comparator.hpp"
#include "../../lang/Exception/Exception.hpp"
#include "../../lang/IllegalArgumentException/IllegalArgumentException.hpp"
#include "../../lang/ClassCastException/ClassCastException.hpp"
#include <vector>

namespace Java {
		namespace Util {
				template <typename E>
				class PriorityQueue
//      :
//      public Serializable
//      public AbstractQueue<E>
				{
				private:
						std::vector<E> original;
				
				public:
						/**
						 * Constructor
						 * Creates a empty PriorityQueue.
						 */
						PriorityQueue() {
						};
						
						/**
						 * Constructor
						 * Creates a PriorityQueue containing the elements in the specified collection.
						 *
						 * @param target
						 */
//          PriorityQueue(const Collection<E> &target);
						
						/**
						 * Constructor
						 * Creates a PriorityQueue whose elements are ordered according to the specified comparator.
						 *
						 * @param target
						 */
//          PriorityQueue(const Comparator<E> &target);
						
						/**
						 * Constructor
						 * Creates a PriorityQueue with the specified initial capacity.
						 *
						 * @param initialCapacity
						 * @throw IllegalArgumentException - if initialCapacity is less than 1
						 */
						PriorityQueue(int initialCapacity) {
							if (initialCapacity < 1) {
								throw IllegalArgumentException("initialCapacity < 1");
							}
							this->original.reserve(initialCapacity);
						}
						
						/**
						 * Constructor
						 * Creates a PriorityQueue with the specified initial capacity that orders its elements according to the specified comparator.
						 *
						 * @param initialCapacity
						 * @param target
						 */
//          PriorityQueue(int initialCapacity, const Comparator<E> &target);
						
						/**
						 * Constructor
						 * Creates a PriorityQueue containing the elements in the specified priority queue.
						 *
						 * @param target
						 */
						PriorityQueue(const PriorityQueue<E> &target) {
							int targetSize = (int) target.original.size();
							int index;
							for (index = 0; index < targetSize; index++) {
								this->original.push_back(target.original[ index ]);
							}
						};
						
						/**
						 * Constructor
						 * Creates a PriorityQueue containing the elements in the specified sorted set.
						 *
						 * @param target
						 */
//          PriorityQueue(const SortedSet<E> &target);
						
						/**
						 * Constructor
						 * Creates a PriorityQueue containing the elements in the specified initializer list.
						 *
						 * @param target
						 */
						PriorityQueue(const std::initializer_list<E> &target) {
							typename std::initializer_list<E>::const_iterator targetIterator;
							for (targetIterator = target.begin(); targetIterator != target.end(); targetIterator++) {
								this->original.push_back(*targetIterator);
							}
							std::make_heap(this->original.begin(), this->original.end());
						}
						
						virtual ~PriorityQueue() {
						}
				
				public:
						/**
						 * Inserts the specified element into this priority queue.
						 *
						 * @param target
						 * @return boolean
						 * @throw ClassCastException - if the specified element cannot be compared with elements currently in this priority queue according to the priority queue's ordering
						 */
						boolean add(const E &target) {
							return this->offer(target);
						}
						
						/**
						 * Removes all of the elements from this priority queue.
						 */
						void clear() {
							this->original.clear();
						}
						
						/**
						 * Returns the comparator used to order the elements in this queue.
						 *
						 * @return Comparator<E>
						 */
//          Comparator<E> comparator() const;
						
						/**
						 * Returns true if this queue contains the specified element.
						 *
						 * @param target
						 * @return boolean
						 */
						boolean contains(const E &target) const {
							typename std::vector<E>::const_iterator targetIterator;
							targetIterator = std::find(this->original.begin(), this->original.end(), target);
							return ( targetIterator != this->original.end());
						}
						
						/**
						 * Returns an iterator over the elements in this queue.
						 *
						 * @return Iterator<E>
						 */
//          Iterator<E>	iterator() const;
						
						/**
						 * Inserts the specified element into this priority queue.
						 *
						 * @param target
						 * @return boolean
						 */
						boolean offer(const E &target) {
							int oldSize = (int) this->original.size();
							this->original.push_back(target);
							std::make_heap(this->original.begin(), this->original.end());
							int newSize = (int) this->original.size();
							return ( newSize != oldSize );
						}
						
						/**
						 * Retrieves, but does not remove, the head of this queue.
						 *
						 * @return E
						 */
						E peek() const {
							E defaultOfE;
							if (this->original.empty()) {
								return defaultOfE;
							}
							return this->original.front();
						}
						
						/**
						 * Retrieves and removes the head of this queue.
						 *
						 * @return E
						 */
						E poll() {
							E result = this->peek();
							std::pop_heap(this->original.begin(), this->original.end());
							this->original.pop_back();
							return result;
						}
						
						/**
						 * Removes a single instance of the specified element from this queue, if it is present.
						 *
						 * @param target
						 * @return boolean
						 */
						boolean remove(const E &target) {
							typename std::vector<E>::iterator targetIterator;
							targetIterator = std::find(this->original.begin(), this->original.end(), target);
							if (targetIterator != this->original.end()) {
								this->original.erase(targetIterator);
								return true;
							}
							return false;
						}
						
						/**
						 * Returns the number of elements in this collection.
						 *
						 * @return int
						 */
						int size() const {
							return (int) this->original.size();
						}
						
						/**
						 * Creates a late-binding and fail-fast Spliterator over the elements in this queue.
						 *
						 * @return Spliterator<E>
						 */
//          Spliterator<E> spliterator() const;
						
						/**
						 * Returns an array containing all of the elements in this queue.
						 *
						 * @return Array<E>
						 */
						Array<E> toArray() const {
							Array<E> result;
							typename std::vector<E>::const_iterator originalIterator;
							for (originalIterator = this->original.begin(); originalIterator != this->original.end(); originalIterator++) {
								result.push(*originalIterator);
							}
							return result;
						}
						
						/**
						 * Returns an array containing all of the elements in this queue.
						 *
						 * @param anArray
						 * @return Array<E>
						 */
						Array<E> toArray(Array<E> &anArray) const {
							int originalSize = (int) this->original.size();
							typename std::vector<E>::const_iterator originalIterator;
							if (anArray.length < originalSize) {
								Array<E> result;
								for (originalIterator = this->original.begin(); originalIterator != this->original.end(); originalIterator++) {
									result.push(*originalIterator);
								}
								return result;
							}
							int indexOfArray = 0;
							for (originalIterator = this->original.begin(); originalIterator != this->original.end(); originalIterator++) {
								anArray[ indexOfArray ] = *originalIterator;
								indexOfArray = indexOfArray + 1;
							}
							// Add "null" terminator (but must use default value).
							if (anArray.length > originalSize) {
								E defaultOfE;
								anArray[ indexOfArray ] = defaultOfE;
							}
							return anArray;
						}
				};
		}
}

#endif // JAVA_UTIL_PRIORITY_QUEUE_HPP
