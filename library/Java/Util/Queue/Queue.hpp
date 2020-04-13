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

#ifndef NATIVE_JAVA_UTIL_QUEUE_HPP
#define NATIVE_JAVA_UTIL_QUEUE_HPP

#include "../../Lang.hpp"
#include "../Collection/Collection.hpp"

namespace Java {
		namespace Util {
				template <typename E>
				class Queue : public Collection<E> {
				protected:
				        /**
				         *  Inserts the specified element into this queue if it is possible to do
				         *  so immediately without violating capacity restrictions,
				         *  returning true upon success and throwing an IllegalStateException
				         *  if no space is currently available.
				         * @param e
				         * @return  boolean
				         */
						virtual boolean add(const E &e) = 0;

						/**
						 * Retrieves, but does not remove, the head of this queue.
						 * @return E
						 */
						virtual E element()  = 0;

						/**
						 * Inserts the specified element into this queue i
						 * f it is possible to do so immediately without violating capacity restrictions.
						 *
						 * @param e
						 * @return boolean
						 */
						virtual boolean offer(const E &e) = 0;

						/**
						 * Retrieves, but does not remove, the head of this queue,
						 * or throw exception if this queue is empty.
						 * @return  E
						 */
						virtual E peek() const = 0;

						/**
						 * Retrieves and removes the head of this queue, or
						 * throw exception if this queue is empty.
						 * @return  E
						 */
						virtual E poll() = 0;

						/**
						 * Retrieves and removes the head of this queue
						 * @return E
						 */
						virtual E remove() = 0;
				};
		} // namespace Util
} // namespace Java

#endif // NATIVE_JAVA_UTIL_QUEUE_HPP