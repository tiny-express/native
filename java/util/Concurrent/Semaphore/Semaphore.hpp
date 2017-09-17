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

#ifndef JAVA_UTIL_CONCURRENT_SEMAPHORE_SEMAPHORE_HPP_
#define JAVA_UTIL_CONCURRENT_SEMAPHORE_SEMAPHORE_HPP_

#include "../../../Lang.hpp"
#include "../../../lang/IllegalArgumentException/IllegalArgumentException.hpp"
#include <mutex>
#include <condition_variable>

using namespace Java::Lang;

namespace Java {
    namespace Util {
        namespace Concurrent {
            class Semaphore : public Object {
            public:
                /**
                 * Create a semaphore
                 */
                Semaphore();

                /**
                 * Create a semaphore with the given number of permits.
                 */
                Semaphore(int permits);

                /**
                 * Destructor
                 */
                ~Semaphore();

                /**
                 * Returns the current number of permits available in this
                 * semaphore.
                 *
                 * @return the number of permits available in this semaphore
                 */
                int availablePermits();

                /**
                 * Returns a string identifying this semaphore (the state, in
                 * brackets, includes the String "Permits =" followed by the
                 * number of permits.
                 *
                 * @return a string identifying this semaphore
                 */
                String toString();

                /**
                 * Acquires a permit from this semaphore, blocking util one is
                 * available or the thread is interrupted.
                 */
                void acquire();

                /**
                 * Acquires the given number of permits from this semaphore,
                 * blocking util all are available or the thread is interrupted.
                 *
                 * @param permits the number of permits to acquire
                 */
                void acquire(int permits);

                /**
                 * Releases a permit, returning it to the semaphore.
                 */
                void release();

                /**
                 * Releases the given number of permits, returning them to the
                 * semaphore.
                 */
                void release(int permits);

                /**
                 * Acquires a permit, only if one is available at the time of
                 * invocation.
                 *
                 * @return true if a permit was acquired and false otherwise
                 */
                boolean tryAcquire();

                /**
                 * Acquires the given number of permits from this semaphore, if
                 * all are available at the time of invocation.
                 *
                 * @param permits the number of permits to acquire
                 * @return true if the permits were acquired and false otherwise
                 * acquired.
                 */
                boolean tryAcquire(int permits);

                /**
                 * Acquires the given number of permits from this semaphore, if
                 * all are available within the given waiting time and the
                 * current thread has not been interrupted.
                 *
                 * @param permits the number of permits to acquire
                 * @param timeout the maximum time to wait for the permits
                 * @return true if all permits were acquired and false if the
                 * waiting time elapsed before all permits were acquired
                 */
                boolean tryAcquire(int permits, long timeout);

            private:
                std::mutex permitMutexObject;
                std::mutex conditionMutexObject;
                std::condition_variable conditionObject;
                int permitCounter;
            };
        } // namespace Concurrent
    } // namespace Util
} // namespace Java

#endif //JAVA_UTIL_CONCURRENT_SEMAPHORE_SEMAPHORE_HPP_
