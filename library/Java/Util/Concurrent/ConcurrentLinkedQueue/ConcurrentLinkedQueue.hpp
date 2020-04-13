/**
 * Copyright 2017-2020 Tiny Express Project. All rights reserved.
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

#ifndef NATIVE_JAVA_UTIL_CONCURRENT_CONCURRENT_LINKED_QUEUE_HPP
#define NATIVE_JAVA_UTIL_CONCURRENT_CONCURRENT_LINKED_QUEUE_HPP

#include "../../../Util/Collection/Collection.hpp"
#include "../../../Lang/Iterable/Iterable.hpp"
#include "../../Queue/Queue.hpp"
#include "concurrentqueue.hpp"

using namespace Java::Lang;

namespace Java {
    namespace Util {
        namespace Concurrent {
            template<class E>
            class ConcurrentLinkedQueue :
                    public virtual Queue<E>,
                    public virtual Serializable {
            private:
                moodycamel::ConcurrentQueue<E> original;

            public:
                ConcurrentLinkedQueue() = default;

                ConcurrentLinkedQueue(const ConcurrentLinkedQueue <E> &target) {
                    original = target.original;
                }

                boolean add(const E &e) {
                    original.enqueue(e);
                    return true;
                }

                E element() {
                    throw UnsupportedOperationException();
                }

                boolean offer(const E &e) {
                    return true;
                }

                E peek() const {
                    throw UnsupportedOperationException();
                }

                E poll() {
                    E e;
                    original.try_dequeue(e);
                    return e;
                }

                E remove() {
                    return true;
                }

                void clear() {
                }

                boolean contains(const E &e) {
                    return true;
                }

                boolean equals(const E &e) {
                    return true;
                }

                int hashCode() {
                    return 0;
                }

                boolean isEmpty() {
                    return original.size_approx() == 0;
                }

                boolean remove(Object &e) {
                    return false;
                }

                boolean removeAll(Collection<Object> &collection) {
                    return false;
                }

                int size() {
                    return original.size_approx();
                }
            };
        } // namespace Concurrent
    } // namespace Util
} // namespace Java

#endif // NATIVE_JAVA_UTIL_CONCURRENT_CONCURRENT_LINKED_QUEUE_HPP
