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
             *
             */
            PriorityQueue() { };

            /**
             *
             * @param target
             */
//          PriorityQueue(const Collection<E> &target);

            /**
             *
             * @param target
             */
//          PriorityQueue(const Comparator<E> &target);

            /**
             *
             * @param initialCapacity
             */
//          PriorityQueue(int initialCapacity);

            /**
             *
             * @param initialCapacity
             * @param target
             */
//          PriorityQueue(int initialCapacity, const Comparator<E> &target);

            /**
             *
             * @param target
             */
            PriorityQueue(const PriorityQueue<E> &target) {
                int targetSize = (int)target.original.size();
                int index;
                for (index = 0; index < targetSize; index++) {
                    this->original.push_back(target.original[index]);
                }
            };

            /**
             *
             * @param target
             */
//          PriorityQueue(const SortedSet<E> &target);

            /**
             *
             * @param target
             */
            PriorityQueue(const std::initializer_list<E> &target) {
                std::initializer_list<E>::const_iterator targetIterator;
                for (targetIterator = target.begin(); targetIterator != target.end(); targetIterator++) {
                    this->original.push_back(*targetIterator);
                }
                std::make_heap(this->original.begin(), this->original.end());
            }

            virtual ~PriorityQueue() { }

        public:
            /**
             *
             * @param target
             * @return
             */
            boolean add(const E &target) {
                this->original.push_back(target);
                try {
                    std::make_heap(this->original.begin(), this->original.end());
                }
                catch (Exception ex){
                    throw "";
                    // TODO: throw ClassCastException
                }
                return true;
            }
        };
    }
}

#endif // JAVA_UTIL_PRIORITY_QUEUE_HPP
