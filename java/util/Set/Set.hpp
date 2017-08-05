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

#ifndef JAVA_UTIL_SET_HPP_
#define JAVA_UTIL_SET_HPP_

#include "../../Lang.hpp"
#include "../../util/Collection/Collection.hpp"

using namespace Java::Lang;

namespace Java {
	namespace Util {
		template <class E>
		class Set:
			public Collection<E>,
			public Iterable<E> {
		public:
			/**
			 * Adds the specified element to this set if
			 * it is not already present (optional operation).
			 *
			 * @param e
			 * @return boolean
			 */
			boolean add(E e);
			
			/**
			 * Adds all of the elements in the specified collection
			 * to this set if they're not already present (optional operation).
			 *
			 * @param c
			 * @return boolean
			 */
			boolean addAll(Collection<E> c);
			
			/**
			 * Removes all of the elements from this set
			 * (optional operation).
			 */
			void clear();
			
			/**
			 * Returns true if this set contains the specified element.
			 *
			 * @param o
			 * @return
			 */
			boolean contains(Object o);
			
			/**
			 * Returns true if this set contains all of the elements
			 * of the specified collection.
			 *
			 * @param c
			 * @return
			 */
			boolean containsAll(Collection<E> c);
			
			/**
			 *  Compares the specified object with this set for equality.
			 *
			 * @param o
			 * @return boolean
			 */
			boolean equals(Object o);
			
			/**
			 * Returns the hash code value for this set.
			 *
			 * @return int
			 */
			long hashCode();
			
			/**
			 * Returns true if this set contains no elements.
			 *
			 * @return boolean
			 */
			boolean isEmpty();
			
			/**
			 * Returns an iterator over the elements in this set.
			 *
			 * @return Iterator<E>
			 */
			Iterator<E>	iterator();
			
			/**
			 * Removes the specified element from this set
			 * if it is present (optional operation).
			 *
			 * @param o
			 * @return boolean
			 */
			boolean remove(Object o);
			
			/**
			 * Removes from this set all of its elements
			 * that are contained in the specified collection
			 * (optional operation).
			 *
			 * @return boolean
			 */
			boolean removeAll(Collection<E> c);
			
			/**
			 * Retains only the elements in this set
			 * that are contained in the specified collection
			 * (optional operation).
			 *
			 * @param c
			 * @return boolean
			 */
			boolean retainAll(Collection<E> c);
			
			/**
			 * Returns the number of elements in this set (its cardinality).
			 *
			 * @return int
			 */
			int size();
			
			/**
			 * Creates a Spliterator over the elements in this set.
			 *
			 * @return
			 */
			Spliterator<E> spliterator();
			
			/**
			 * Returns an array containing all of the elements in this set.
			 *
			 * @return Array<Object>
			 */
			Array<Object> toArray();
			
			/**
			 * Returns an array containing all of the elements in this set;
			 * the runtime type of the returned array is that of the specified array.
			 *
			 * @param T
			 */
			template <class T>
			Array<E> toArray(Array<T> a);
		};
	}
}

#endif  // JAVA_UTIL_SET_HPP_