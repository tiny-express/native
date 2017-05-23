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

#ifndef NATIVE_ABSTRACT_LIST_HPP
#define NATIVE_ABSTRACT_LIST_HPP

#include "../AbstractCollection/AbstractCollection.hpp"
#include "../Collection/Collection.hpp"

namespace Java {
    namespace Util {
        template <class E>
        class AbstractList : public virtual AbstractCollection<E> {
            protected:
                virtual bool add(E &element);
                virtual void add(int index, E &element);
                virtual bool addAll(Collection<E> &c);
                virtual bool contains(E &element);
                virtual bool remove(int index);
                virtual bool remove(E &element);
                virtual bool removeAll();
                virtual bool removeRange(int fromIndex, int toIndex);
                virtual E get(int index);
                virtual bool set(int index, E &element);
                virtual int size();
                virtual bool isEmpty();
        };
    }
}

#endif //NATIVE_ABSTRACT_LIST_HPP
