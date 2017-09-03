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

void SemaphoreTestThread(int sleepTime, int releasePermits, Semaphore* semaphoreObject) {
    std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
    if(semaphoreObject)
        semaphoreObject->release(releasePermits);
}

TEST(JavaUtilConcurrent, SemaphoreConstructor) {
    {
        Semaphore semaphoreObject;
        ASSERT_EQUAL(semaphoreObject.availablePermits(), 0);
    }

    {
        const int initPermits = 3;
        Semaphore semaphoreObject(initPermits);
        ASSERT_EQUAL(semaphoreObject.availablePermits(), initPermits);
    }
}

TEST(JavaUtilConcurrent, SemaphoreToString) {
    Semaphore semaphoreObject(3);
    String expect = "[Permits = 3]";
    String result;

    try {
        result = semaphoreObject.toString();
    } catch (IllegalArgumentException& e) {

    }

    ASSERT_STR(expect.toString(), result.toString());
}

TEST(JavaUtilConcurrent, SemaphoreAcquireNotPassingPermits) {
    const int expectPermits = 0;
    Semaphore semaphoreObject;
    std::thread testThread(SemaphoreTestThread, 3000, 1, &semaphoreObject);
    semaphoreObject.acquire();
    if (testThread.joinable()) {
        testThread.join();
    }

    ASSERT_EQUAL(semaphoreObject.availablePermits(), expectPermits);
}

TEST(JavaUtilConcurrent, SemaphoreAcquirePassingPermits) {
    const int expectPermits = 1;
    const int threadCount = 3;
    Semaphore semaphoreObject;
    std::vector<std::thread> testThreads;
    for (int i = 0; i < threadCount; ++i) {
        testThreads.push_back(std::move(std::thread(SemaphoreTestThread, 3000, 1, &semaphoreObject)));
    }

    semaphoreObject.acquire(2);
    for (int i = 0; i < testThreads.size(); ++i) {
        if (testThreads[i].joinable()) {
            testThreads[i].join();
        }
    }

    ASSERT_EQUAL(semaphoreObject.availablePermits(), expectPermits);
}

TEST(JavaUtilConcurrent, SemaphoreTryAcquireNotPassingPermits) {
    const int expectPermits = 1;
    Semaphore semaphoreObject;
    std::thread testThread(SemaphoreTestThread, 3000, 1, &semaphoreObject);
    boolean result = semaphoreObject.tryAcquire();
    ASSERT_EQUAL(result, false)
            ;
    if (testThread.joinable()) {
        testThread.join();
    }

    ASSERT_EQUAL(semaphoreObject.availablePermits(), expectPermits);
}

TEST(JavaUtilConcurrent, SemaphoreTryAcquirePassingPermitsWithTimeout) {
    const int expectPermits = 1;
    const int threadCount = 3;
    Semaphore semaphoreObject;
    std::vector<std::thread> testThreads;
    bool result = false;

    for (int i = 0; i < threadCount; ++i) {
        testThreads.push_back(std::move(std::thread(SemaphoreTestThread, 1000, 1, &semaphoreObject)));
    }

    result = semaphoreObject.tryAcquire(2, 5000);
    ASSERT_EQUAL(result, true);

    for (int i = 0; i < testThreads.size(); ++i) {
        if (testThreads[i].joinable()) {
            testThreads[i].join();
        }
    }

    ASSERT_EQUAL(semaphoreObject.availablePermits(), expectPermits);
}