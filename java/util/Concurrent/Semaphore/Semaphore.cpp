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

#include "Semaphore.hpp"

using namespace std::chrono;

Concurrent::Semaphore::Semaphore() {
    permitCounter = 0;
}

Concurrent::Semaphore::Semaphore(int permits) {
    permitCounter = permits;
}

Concurrent::Semaphore::~Semaphore() {
    conditionObject.notify_one();
}

int Concurrent::Semaphore::availablePermits() {
    std::unique_lock<std::mutex> locker(permitMutexObject);
    return permitCounter;
}

String Concurrent::Semaphore::toString() {
    String result;
    try {
        result = String::format("[Permits = %d]", availablePermits());
    } catch (IllegalArgumentException& e) {

    }
    return result;
}

void Concurrent::Semaphore::acquire() {
    acquire(1);
}

void Concurrent::Semaphore::acquire(int permits) {
    tryAcquire(permits, -1);
}

void Concurrent::Semaphore::release() {
    release(1);
}

void Concurrent::Semaphore::release(int permits) {
    std::unique_lock<std::mutex> locker(conditionMutexObject);
    permitMutexObject.lock();
    permitCounter += permits;
    permitMutexObject.unlock();
    conditionObject.notify_one();
}

boolean Concurrent::Semaphore::tryAcquire() {
    return tryAcquire(1);
}

boolean Concurrent::Semaphore::tryAcquire(int permits) {
    return tryAcquire(permits, 0);
}

boolean Concurrent::Semaphore::tryAcquire(int permits, long timeout) {
    int currentPermits = 0;
    if (timeout < 0) {
        for (int i = 0; i < permits; ++i) {
            permitMutexObject.lock();
            currentPermits = permitCounter;
            permitMutexObject.unlock();

            if (currentPermits == 0) {
                std::unique_lock<std::mutex> conditionLocker(conditionMutexObject);
                conditionObject.wait(conditionLocker);
            }

            permitMutexObject.lock();
            --permitCounter;
            permitMutexObject.unlock();
        }
        return true;
    } else {
        {
            std::unique_lock<std::mutex> permitsLocker(permitMutexObject);
            if (permits <= permitCounter) {
                permitCounter -= permits;
                return true;
            }
        }

        long waitTime = timeout;
        while (true) {
            std::unique_lock<std::mutex> conditionLocker(conditionMutexObject);
            const long startTime = duration_cast<milliseconds>(
                    steady_clock::now().time_since_epoch()).count();
            std::cv_status waitStatus = conditionObject.wait_for(
                    conditionLocker, std::chrono::milliseconds(waitTime));
            if (waitStatus == std::cv_status::timeout) {
                return false;
            }

            const long elapsedTime = duration_cast<milliseconds>(
                    steady_clock::now().time_since_epoch()).count() - startTime;
            waitTime -= elapsedTime;

            {
                std::unique_lock<std::mutex> permitsLocker(permitMutexObject);
                if (permits <= permitCounter) {
                    permitCounter -= permits;
                    return true;
                }
            }
        }
    }
}
