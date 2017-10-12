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

#include "../../../kernel/Test.hpp"

#include "Thread.hpp"
#include "../InterruptedException/InterruptedException.hpp"

using namespace std;
using namespace Java::Lang;

class RunnableTarget1 : public virtual Runnable {
public:
    long value;

    RunnableTarget1() {
        value = 0;
    }

    ~RunnableTarget1() {

    }

	void run() override {
        value = 0xb00b;
        Thread::sleep(1000);
	}
};

class RunnableTarget2 : public virtual Runnable {
public:
    long value;

    RunnableTarget2() {
        value = 0;
    }

    ~RunnableTarget2() {

    }

    void run() override {
        value = 0xb00b;
        Thread::sleep(1000);
        value = 0xbeef;
    }
};

class RunnableTarget3 : public virtual Runnable {
public:
    unsigned long tid;

    RunnableTarget3() {

    }

    ~RunnableTarget3() {

    }

    void run() override {
        tid = (unsigned long)pthread_self();
    }
};

TEST(JavaLang, ThreadRun) {
    long expect = 0xb00b;
    long result = 0;
    RunnableTarget1* target = new RunnableTarget1();

    {
        Thread thread(target);
        thread.start();
        thread.join();
        result = target->value;
    }

    delete target;
    ASSERT_EQUAL(expect, result);
}

TEST(JavaLang, ThreadSetName) {
    Thread thread;

    String name = "Thread 1";
    thread.setName(name);
    ASSERT_STR("Thread 1", thread.getName().toString());

    thread.setName("Thread 2");
    ASSERT_STR("Thread 2", thread.getName().toString());
}

TEST(JavaLang, ThreadGetName) {
    Thread thread;

    String name = "Thread 1";
    thread.setName(name);
    ASSERT_STR("Thread 1", thread.getName().toString());

    thread.setName("Thread 2");
    ASSERT_STR("Thread 2", thread.getName().toString());
}

TEST(JavaLang, ThreadGetThreadId) {
    RunnableTarget3 target;
    Thread thread(&target);

    thread.start();
    thread.join();

    String expect = String::format("%lld", target.tid);
    String result = String::format("%lld", thread.getId());

    ASSERT_STR(expect.toString(), result.toString());
}

TEST(JavaLang, ThreadJoinWithTimeout) {
    long expect1 = 0xb00b;
    long result1 = 0;
    long expect2 = 0xbeef;
    long result2 = 0;

    {
        RunnableTarget2 target;
        Thread thread(&target);
        thread.start();

        //
        thread.join(100);
        result1 = target.value;

        //
        thread.join();
        result2 = target.value;
    }

    ASSERT_EQUAL(expect1, result1);
    ASSERT_EQUAL(expect2, result2);
}