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

#ifndef NATIVE_JAVA_UTIL_LIST_HPP
#define NATIVE_JAVA_UTIL_LIST_HPP

#include "../function/UnaryOperator/UnaryOperator.hpp"
#include "../Iterator/Iterator.hpp"
#include "../Collection/Collection.hpp"
#include "../Comparator/Comparator.hpp"

namespace Java {
	namespace Util {
		template <typename E>
		class ListIterator;
		
		template <typename E>
		class List;
		
		template <typename E>
		class List : public virtual Collection<E>, public virtual Iterable<E> {
		protected:
			virtual boolean add(E &e) = 0;
			virtual void add(int index, E &element) = 0;
			virtual boolean addAll(Collection<E> &c) = 0;
			virtual boolean addAll(int index, Collection<E> &c) = 0;
			virtual void clear() = 0;
			virtual boolean contains(Object &o) const = 0;
			virtual boolean containsAll(Collection<Object> &c) const = 0;
			virtual boolean equals(Object &o) const = 0;
			virtual E &get(int index) const = 0;
			virtual int hashCode() const = 0;
			virtual int indexOf(Object &o) const = 0;
			virtual boolean isEmpty() const = 0;
			virtual Iterator<E> &iterator() const = 0;
			virtual int lastIndexOf(Object &o) const = 0;
			virtual ListIterator<E> &listIterator() const = 0;
			virtual ListIterator<E> &listIterator(int index) const = 0;
			virtual E &remove(int index) = 0;
			virtual boolean remove(Object &o) = 0;
			virtual boolean removeAll(Collection<Object> &c) = 0;
			virtual void replaceAll(Java::Util::Function::UnaryOperator<E> &unaryOperator) = 0;
			virtual boolean retainAll(Collection<Object> &c)  = 0;
			virtual E &set(int index, E &element) = 0;
			virtual int size() const = 0;
			virtual void sort(Comparator<E> &c) = 0;
			virtual Spliterator<E> &spliterator() const  = 0;
			virtual List<E> &subList(int fromIndex, int toIndex) const = 0;
			virtual Array<Object> &toArray() const = 0;
			template <typename T>
			 Array<T> toArray(Array<T> &a) const;
		};
	}
}

#endif//NATIVE_JAVA_UTIL_LIST_HPP
