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

extern "C" {
#include "../../../../kernel/test.h"
}

#include <thread>
#include <vector>
#include "Semaphore.hpp"

using namespace Java::Util::Concurrent;

void SemaphoreTestThread(int sleepTime, int releasePermits,
                         Semaphore* semaphore) {
    std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
    if(semaphore)
        semaphore->release(releasePermits);
}

void SemaphoreTestThread2(int sleepTime, int loopCount, Semaphore* semaphore) {
    for (int i = 0; i < loopCount; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        if (semaphore) {
            semaphore->release();
        }
    }
}

TEST(JavaUtilConcurrent, SemaphoreConstructor) {
    {
        Semaphore semaphoreObject;
        ASSERT_EQUAL(0, semaphoreObject.availablePermits());
    }

    {
        const int initPermits = 3;
        Semaphore semaphoreObject(initPermits);
        ASSERT_EQUAL(initPermits, semaphoreObject.availablePermits());
    }
}

TEST(JavaUtilConcurrent, SemaphoreToString) {
    Semaphore semaphoreObject(3);
    String expect = "[Permits = 3]";
    String result;

    result = semaphoreObject.toString();
    ASSERT_STR(expect.toString(), result.toString());
}

TEST(JavaUtilConcurrent, SemaphoreRelease) {
    const int expectPermits = 2;
    Semaphore semaphoreObject(1);
    semaphoreObject.release();
    ASSERT_EQUAL(semaphoreObject.availablePermits(), expectPermits);
}

TEST(JavaUtilConcurrent, SemaphoreAcquireNotPassingPermits) {
    const int expectPermits = 0;
    Semaphore semaphoreObject;
    std::thread testThread(SemaphoreTestThread, 1000, 1, &semaphoreObject);
    semaphoreObject.acquire();
    if (testThread.joinable()) {
        testThread.join();
    }

    ASSERT_EQUAL(expectPermits, semaphoreObject.availablePermits());
}

TEST(JavaUtilConcurrent, SemaphoreAcquirePassingPermits) {
    const int expectPermits = 1;
    const int threadCount = 3;
    Semaphore semaphoreObject;
    std::vector<std::thread> testThreads(threadCount);
    for (auto& it : testThreads) {
        it = std::move(std::thread(SemaphoreTestThread,
                                   1000, 1, &semaphoreObject));
    }

    semaphoreObject.acquire(2);

    for (auto& it : testThreads) {
        if (it.joinable()) {
            it.join();
        }
    }

    ASSERT_EQUAL(expectPermits, semaphoreObject.availablePermits());
}

TEST(JavaUtilConcurrent, SemaphoreTryAcquireNotPassingPermits) {
    const int expectPermits = 1;
    Semaphore semaphoreObject;
    std::thread testThread(SemaphoreTestThread,
                           1000, 1, &semaphoreObject);
    boolean result = semaphoreObject.tryAcquire();

    if (testThread.joinable()) {
        testThread.join();
    }

    ASSERT_FALSE(result);
    ASSERT_EQUAL(expectPermits, semaphoreObject.availablePermits());
}

TEST(JavaUtilConcurrent, SemaphoreTryAcquirePassingPermitsWithTimeout) {
    const int expectPermits = 0;
    Semaphore semaphoreObject;
    std::thread testThread(SemaphoreTestThread2, 1000, 2, &semaphoreObject);

    semaphoreObject.release();
    bool result = semaphoreObject.tryAcquire(3, 10000);

    if (testThread.joinable()) {
        testThread.join();
    }

    ASSERT_TRUE(result);
    ASSERT_EQUAL(expectPermits, semaphoreObject.availablePermits());
}

TEST(JavaUtilConcurrent, SemaphoreTryAcquirePassingPermitsWithInitPermits) {
    const int expectPermits = 1;
    Semaphore semaphoreObject(2);
    semaphoreObject.tryAcquire();
    ASSERT_EQUAL(expectPermits, semaphoreObject.availablePermits());
}