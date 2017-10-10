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

#include <pthread.h>
#include <chrono>
#include <sstream>
#include "Thread.hpp"
#include "../InterruptedException/InterruptedException.hpp"

using namespace std;
using namespace Java::Lang;

thread_local Thread* currentThreadPtr = NULL;

Thread::Thread() {
    init(nullptr, "");
}

Thread::Thread(Runnable *target) {
    init(target, "");
}

Thread::~Thread() {
    if (threadObject.joinable())
        threadObject.join();
    if (semahoreObject.availablePermits() > 0)
        semahoreObject.release(semahoreObject.availablePermits());
}

void Thread::run() {
    // set thread id
    this->tid = (unsigned long) pthread_self();

    // set tls
    if (currentThreadPtr == NULL) {
        currentThreadPtr = this;
    }

    mutexObject.lock();
    alive = true;
    mutexObject.unlock();

    target->run();
    semahoreObject.release(1);

    mutexObject.lock();
    alive = false;
    mutexObject.unlock();
}

void Thread::setName(String name) {
    this->name = name;
}

void Thread::init(Runnable *target, String name) {
    this->target = target;
    this->name = name;
}

String Thread::getName() {
    return this->name;
}

boolean Thread::isAlive() {
    std::unique_lock<std::mutex> locker(mutexObject);
    return alive;
}

unsigned long Thread::getId() {
    return this->tid;
}

void Thread::start() {
    if (target && !isAlive()) {
        threadObject = std::move(std::thread(&Thread::run, this));
    }
}

void Thread::join() {
    join(0);
}

void Thread::join(long millis) {
    if (millis > 0) {
        semahoreObject.tryAcquire(1, millis);
    } else {
        semahoreObject.acquire();
    }
}

void Thread::sleep(long millis) {
    this_thread::sleep_for(chrono::milliseconds(millis));
}

Thread *Thread::currentThread() {
    return currentThreadPtr;
}