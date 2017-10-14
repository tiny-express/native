///**
// * Copyright (c) 2016 Food Tiny Project. All rights reserved.
// *
// * Redistribution and use in source and binary forms, with or without
// * modification, are permitted provided that the following conditions are met:
// *
// * Redistributions of source code must retain the above copyright
// * notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above
// * copyright notice, this list of conditions and the following disclaimer
// * in the documentation and/or other materials provided with the
// * distribution.
// *
// * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// */
//
//#include "Thread.hpp"
//
//using namespace Java::Lang;
//
//Thread::Thread() {
//	this->target = nullptr;
//	this->threadName = stringCopy("");
//}
//
//Thread::Thread(Runnable &target2) {
//	this->target = &target2;
//	this->threadName = stringCopy("");
//}
//
//Thread::Thread(Runnable &target2, String name) {
//	this->target = &target2;
//	this->threadName = stringCopy(name.toString());
//}
//
//Thread::Thread(String name) {
//	this->target = nullptr;
//	this->threadName = stringCopy(name.toString());
//}
//
//Thread::~Thread() {
//	//TODO: reduce Thread::Thread.numberThread
//	if (this->threadName != NULL) {
//		free(this->threadName);
//	}
//}
//
///**
// * Call Runnable target's run() method
// */
//void Thread::run() const {
//	if (this->target != NULL) {
//		this->target->run();
//	}
//}
//
///**
// * Force thread and call Runnable target's run() method
// */
//void Thread::start() {
//	this->isThreadRunning = true;
//	pthread_create(&this->original, NULL, &Thread::pthread_helper, (void *) this);
//}
//
///**
// * Stop a thread if it's running
// */
//void Thread::stop() {
//	if (!this->isThreadRunning) {
//		return;
//	}
//
//	//pthread_cancel(this->original);
//	this->isThreadRunning = false;
//}
//
///**
// * Waits for this thread to die if it's running
// */
//void Thread::join() {
//	if (!this->isThreadRunning) {
//		return;
//	}
//
//	pthread_join(this->original, NULL);
//}
//
///**
// * Waits at most millis milliseconds for this thread to die if it's running
// */
//void Thread::join(unsigned int millis) {
//	if (!this->isThreadRunning) {
//		return;
//	}
//
//	usleep(millis * 1000);
//	pthread_join(this->original, NULL);
//}
//
///**
// * Return this thread's name
// */
//string Thread::getName() {
//	return this->threadName;
//}
//
///**
// * Set this thread's name
// */
//void Thread::setName(string target) {
//	this->threadName = stringCopy(target);
//}
//
///**
// * Returns a string representation of this thread, including the thread's name, priority, and thread group.
// */
//string Thread::toString() const {
//	return this->threadName;
//}
