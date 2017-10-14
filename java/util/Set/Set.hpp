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

#ifndef JAVA_UTIL_SET_HPP
#define JAVA_UTIL_SET_HPP

#include "../../Lang.hpp"
#include "../../util/Collection/Collection.hpp"

using namespace Java::Lang;

namespace Java {
		namespace Util {
				template <class E>
				class Set :
					public virtual Collection<E>,
					public virtual Iterable<E> {
				private:
						std::set<E> original;
						typedef typename std::set<E>::iterator _iterator;
						typedef typename std::set<E>::const_iterator _const_iterator;
						
				public:
						_iterator begin() {
							return this->original.begin();
						}
						
						_const_iterator begin() const {
							return this->original.begin();
						}
						
						_iterator end() {
							return this->original.end();
						}
						
						_const_iterator end() const {
							return this->original.end();
						}
				public:
						Set() {
							// TODO - loint@foodtiny.com
						}
						
						~Set() {
							// TODO - loint@foodtiny.com
						}
						
						/**
						 * Adds the specified element to this set if
						 * it is not already present (optional operation).
						 *
						 * @param e
						 * @return boolean
						 */
						boolean add(const E &e) {
							auto insertResult = this->original.insert(e);
							if (insertResult.first != this->original.end()) {
								return true;
							}
							return false;
						}
						
						/**
						 * Adds all of the elements in the specified collection
						 * to this set if they're not already present (optional operation).
						 *
						 * @param c
						 * @return boolean
						 */
						boolean addAll(Collection<E> c) {
							// TODO - loint@foodtiny.com
							return true;
						}
						
						/**
						 * Removes all of the elements from this set
						 * (optional operation).
						 */
						void clear() {
							this->original.clear();
						}
						
						/**
						 * Returns true if this set contains the specified element.
						 *
						 * @param o
						 * @return
						 */
						boolean contains(Object o) {
							// TODO - loint@foodtiny.com
							return true;
						}
						
						/**
						 * Returns true if this set contains all of the elements
						 * of the specified collection.
						 *
						 * @param c
						 * @return
						 */
						boolean containsAll(Collection<E> c) {
							// TODO - loint@foodtiny.com
						}
						
						/**
						 *  Compares the specified object with this set for equality.
						 *
						 * @param o
						 * @return boolean
						 */
						boolean equals(Object o) {
							// TODO - loint@foodtiny.com
						}
						
						/**
						 * Returns the hash code value for this set.
						 *
						 * @return int
						 */
						long hashCode() {
							// TODO - loint@foodtiny.com
						}
						
						/**
						 * Returns true if this set contains no elements.
						 *
						 * @return boolean
						 */
						boolean isEmpty() {
							return this->original.empty();
						}
						
						/**
						 * Returns an iterator over the elements in this set.
						 *
						 * @return Iterator<E>
						 */
						Iterator<E> iterator() {
							// TODO - loint@foodtiny.com
						}
						
						/**
						 * Removes the specified element from this set
						 * if it is present (optional operation).
						 *
						 * @param o
						 * @return boolean
						 */
						boolean remove(Object o) {
							// TODO - loint@foodtiny.com
							return true;
						}
						
						/**
						 * Removes from this set all of its elements
						 * that are contained in the specified collection
						 * (optional operation).
						 *
						 * @return boolean
						 */
						boolean removeAll(Collection<E> c) {
							// TODO - loint@foodtiny.com
						}
						
						/**
						 * Retains only the elements in this set
						 * that are contained in the specified collection
						 * (optional operation).
						 *
						 * @param c
						 * @return boolean
						 */
						boolean retainAll(Collection<E> c) {
							// TODO - loint@foodtiny.com
						}
						
						/**
						 * Returns the number of elements in this set (its cardinality).
						 *
						 * @return int
						 */
						int size() {
							return original.size();
						}
						
						/**
						 * Creates a Spliterator over the elements in this set.
						 *
						 * @return
						 */
						Spliterator<E> spliterator() {
							// TODO - loint@foodtiny.com
						}
						
						/**
						 * Returns an array containing all of the elements in this set.
						 *
						 * @return Array<Object>
						 */
						Array<Object> toArray() {
							Array<Object> array;
							// TODO - loint@foodtiny.com
							return array;
						}
						
						/**
						 * Returns an array containing all of the elements in this set;
						 * the runtime type of the returned array is that of the specified array.
						 *
						 * @param T
						 */
						template <class T>
						Array<E> toArray(Array<T> a) {
							Array<E> array;
							return array;
						}
				};
		}
}

#endif  // JAVA_UTIL_SET_HPP