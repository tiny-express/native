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

Thread::Thread() {
    this->original = NULL;
    this->target = NULL;
}

//Thread::Thread(Runnable &target2) {
//}
//
//Thread::Thread(Runnable &target2, String &name) {
//
//}
//Thread::Thread(String &name) {
//
//}

Thread::~Thread() {
}

/**
 * Call Runnable object's run method
 */
void Thread::run() const {

}

/**
 * Call Runnable object's run method
 */
void Thread::start() {
}

/**
 * Stop a thread
 */
void Thread::stop() {

}

/**
 * Waits for this thread to die.
 */
void Thread::join() {

}

/**
 * Waits at most millis milliseconds for this thread to die.
 */
void Thread::join(long millis) {

}

/**
 * Return this thread's name
 */
string Thread::getName() {
    return this->threadName;
}

/**
 * Set this thread's name
 */
void Thread::setName(string target) {
    this->threadName = target;
}

/**
 * Returns a string representation of this thread, including the thread's name, priority, and thread group.
 */
string Thread::toString() const {
    return "";
}

/**
 * Return current pthread_t inside for testing
 */
pthread_t Thread::getCurrentThread() {
    return this->original;
}
