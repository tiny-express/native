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
//extern "C" {
//#include "../../../kernel/test.h"
//};
//
//#include "Thread.hpp"
//
//using namespace Java::Lang;
//
//class RunnableTarget : public virtual Runnable {
//public:
//	void run() const {
//	}
//};
//
//class RunnableTarget2 : public virtual Runnable {
//public:
//	void run() const {
//		int index = 0;
//		int limit = 51;
//		for (; index <= limit; index++) {
//			// printf("Index [%d] must not equal to %d to test Thread.stop()\n", index, limit);
//			usleep(1);
//		}
//	}
//};
//
//TEST (JavaLang, ThreadConstructor) {
//	return;
//	// Given valid Thread with default constructor
//	Thread thread;
//
//	// Test empty threadName
//	assertEquals("", thread.getName());
//
//	// Given valid Thread & valid Target to test constructor with target and threadName
//	RunnableTarget target;
//	Thread thread2 = Thread(target, String("sample thread"));
//
//	// Test true after call constructor
//	assertEquals("sample thread", thread2.getName());
//}
//
//TEST (JavaLang, ThreadName) {
//	return;
//	// Given valid Thread to test get/set thread name
//	Thread thread;
//
//	// Test true after set new name for threadName
//	thread.setName((string) "Some valid name");
//	assertEquals("Some valid name", thread.getName());
//}
//
//TEST (JavaLang, ThreadStart) {
//	return;
//	// Given valid Target and valid Thread to test start(), join(), join(millis) functions
//	RunnableTarget validTarget;
//	Thread thread = Thread(validTarget);
//
//	thread.start();
//	thread.join();  /// Make sure that thread has join() because if not
//	/// there will be crashed because it's finished this test case before this thread's completed
//
//	///Please help to check this output <"Hello world"> is appeared at test case 74 or not
//}
//
//TEST (JavaLang, ThreadStop) {
//	return;
//	// Given valid RunnableTarget2's instance, valid Thread's instance, start success a Thread to test Thread.stop()
//	RunnableTarget2 target;
//	Thread thread = Thread(target);
//
//	thread.start();
//	usleep(10);
//	thread.stop();
//
//	///Please check: <"Index [%index] must not equal to %limit to test Thread.stop()"> is appeared at test case 75 or not
//}
