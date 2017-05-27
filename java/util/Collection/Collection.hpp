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

#ifndef NATIVE_UTIL_COLLECTION_HPP
#define NATIVE_UTIL_COLLECTION_HPP

#include "../../lang/Iterable/Iterable.hpp"
#include "../Collection/Collection.hpp"
#include "../Spliterator/Spliterator.hpp"
#include "../../util/function/Predicate/Predicate.hpp"
#include "../../util/stream/Stream/Stream.hpp"

using namespace Java::Lang;

namespace Java {
	namespace Util {
		template <typename E>
		class Collection;
		
		template <typename E>
		class Collection : public virtual Iterable<E> {
		public:
			boolean add(E &e);
			boolean addAll(Collection<E> &c);
			void clear();
			boolean contains(Object &o);
			boolean containsAll(Collection<Object> &c);
			boolean equals(Object &o);
			int hashCode();
			boolean isEmpty() const;
			Iterator<E> &iterator() const;
			Java::Util::Stream::Stream<E> &parallelStream() const;
			boolean remove(Object &o);
			boolean removeAll(Collection<Object> &c);
			boolean removeIf(Java::Util::Function::Predicate<E> &filter);
			boolean retainAll(Collection<Object> &c);
			int size() const;
			Spliterator<E> &spliterator() const;
			Java::Util::Stream::Stream<E> &stream() const;
			Array<Object> &toArray() const;
			template <typename T>
			Array<T> toArray(Array<T> &a) const;
		};
	}
}

#endif //NATIVE_COLLECTION_HPP
