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

#include "Thread.hpp"

using namespace Java::Lang;

int Thread::threadInitNumber = 0;
long Thread::threadSeqNumber = 0;

Thread::Thread() {
    init(nullptr, "Thread - " + Thread::nextThreadNum(), 0);
}

Thread::Thread(Runnable *target) {
    init(target, "Thread - " + Thread::nextThreadNum(), 0);
}

Thread::~Thread() {
    if(threadObject) {
        if (threadObject->joinable())
            threadObject->join();
        delete threadObject;
    }
}

void Thread::run() {
    mutexObject.lock();
    alive = true;
    mutexObject.unlock();

    target->run();
//    if(semaphoreObject) {
//        semaphoreObject->release(1, NULL);
//    }

    mutexObject.lock();
    alive = false;
    mutexObject.unlock();
}

// TODO(thoangminh): Need method checkAccess, threadStatus, setNativeName
void Thread::setName(String name) {
    this->name = name;
}

void Thread::init(Runnable *target, String name, long stackSize) {
    this->target = target;
    this->name = name;
    this->stackSize = stackSize;
    this->tid = nextThreadID();
    this->threadObject = NULL;
}

String Thread::getName() {
    return this->name;
}

// TODO(thoangminh): Need IllegalThreadStateException, method checkAccess, isAlive
void Thread::setDaemon(boolean on) {
    this->daemon = on;
}

boolean Thread::isAlive() {
    std::unique_lock<std::mutex> locker(mutexObject);
    return alive;
}

boolean Thread::isDaemon() {
    return this->daemon;
}

// TODO(thoangminh): Need class ThreadGroup, IllegalThreadStateException, method checkAccess
void Thread::setPriority(int newPriority) {
        if (newPriority > Thread::MAX_PRIORITY) {
            newPriority = Thread::MAX_PRIORITY;
        }

        if (newPriority < Thread::MIN_PRIORITY) {
            newPriority = Thread::MIN_PRIORITY;
        }

        this->priority = newPriority;
}

int Thread::getPriority() {
    return this->priority;
}

int Thread::nextThreadNum() {
    return threadInitNumber++;
}

long Thread::nextThreadID() {
    ++threadSeqNumber;
}

void Thread::start() {
    if(target && !isAlive()) {
        threadObject = new std::thread(&Thread::run, this);
    }
}

void Thread::join() {
    join(0);
}

void Thread::join(long millis) {
    if(millis > 0) {
        //semaphoreObject->wait(millis);
    } else {
        //semaphoreObject->wait();
    }
}
