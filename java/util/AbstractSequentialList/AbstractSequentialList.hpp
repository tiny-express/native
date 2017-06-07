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

#ifndef NATIVE_JAVA_UTIL_ABSTRACT_SEQUENTIAL_LIST_HPP
#define NATIVE_JAVA_UTIL_ABSTRACT_SEQUENTIAL_LIST_HPP

#include "../AbstractList/AbstractList.hpp"

namespace Java {
    namespace Util {
        template <typename E>
        class AbstractSequentialList : public AbstractList<E> {
        protected:
            AbstractSequentialList();
            ~AbstractSequentialList();

        public:
            virtual void add(int index, E element);
            virtual boolean addAll(int index, Collection<E> c);
            virtual E get(int index);
            virtual Iterator<E> interactor();
            // ListIterator<E>	listIterator(int index);
            virtual E remove(int index);
            virtual E set(int index, E element);
        };
    }
}

#endif //NATIVE_JAVA_UTIL_ABSTRACT_SEQUENTIAL_LIST_HPP
