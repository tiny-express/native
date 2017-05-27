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

using namespace Java::Lang;

namespace Java {
	namespace Util {
		template <typename E>
		class Collection : public virtual Iterable<E> {
		public:
			virtual void add(E &e) = 0;
			virtual bool addAll(Collection<E> &c) = 0;
			virtual void clear() = 0;
			virtual bool contains(E &e) const = 0;
			virtual bool containsAll(Collection<E> &c) const = 0;
			virtual bool equals(E &e) const = 0;
			virtual E get(const int index) = 0;
			virtual int hashCode() const = 0;
			virtual bool isEmpty() const = 0;
			virtual bool remove(E &e) = 0;
			virtual bool removeAll(Collection<E> &c) = 0;
			virtual int size() const = 0;
			//virtual ~Collection() = 0;
		};
	}
}

#endif //NATIVE_COLLECTION_HPP
