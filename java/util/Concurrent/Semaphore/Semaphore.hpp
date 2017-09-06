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
                Semaphore();
                Semaphore(int permits);
                ~Semaphore();

                int availablePermits();
                String toString();

                void acquire();
                void acquire(int permits);
                void release();
                void release(int permits);
                boolean tryAcquire();
                boolean tryAcquire(int permits);
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

#endif //JAVA_UTIL_CONCURRENT_SEMAPHORE_HPP_
