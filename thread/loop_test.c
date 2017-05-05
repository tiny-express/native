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

#include "../builtin.h"
#include "../unit_test.h"
#include "../thread.h"

int t = 0;
int count1 = 0;
int count2 = 0;
pthread_t interval_thread;
pthread_t time_out_thread;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *add() {
    t ++;
}

void *add_for_interval_mutex() {
    count1 ++;
    pthread_mutex_lock(&mutex);
    t ++;
    pthread_mutex_unlock(&mutex);
}

void *subtract_for_interval_mutex() {
    count2 ++;
    pthread_mutex_lock(&mutex);
    t --;
    pthread_mutex_lock(&mutex);
}


void *stop_interval() {
    pthread_cancel(interval_thread);
}


TEST(Thread, LoopSetInterval) {

    pthread_t pthread1 = set_interval(add, 100);
    while(1) {
        sleep(1);
        pthread_cancel(pthread1);
        break;
    }
    ASSERT_TRUE(t > 0);
}


TEST(Thread, LoopSetIntervalNullCallback) {
    pthread_t pthread1 = set_interval(NULL, 10);
    ASSERT_NULL(pthread1);
}

TEST(Thread, LoopSetIntervalMutex) {
    t = 0;
    pthread_t pthread2 = set_interval(add_for_interval_mutex, 0);
    pthread_t pthread3 = set_interval(subtract_for_interval_mutex, 0);
    while(1) {
        sleep(1);
        pthread_cancel(pthread3);
        pthread_cancel(pthread2);
        break;
    }
    ASSERT_TRUE(t != count1 - count2);
}

TEST(Thread, LoopSetTimeOut) {
    t = 0;
    set_time_out(add, 200);
    ASSERT_EQUAL(0, t);
    while (1) {
        sleep(1);
        break;
    }
    ASSERT_EQUAL(1, t);
}

TEST(Thread, LoopTimeOutStopInterval) {
    t = 0;
    interval_thread = set_interval(add, 20);
    time_out_thread = set_time_out(stop_interval, 500);
    while (1) {
        sleep(1);
        break;
    }
    ASSERT_TRUE(t > 0);
}

TEST(Thread, LoopSetTimeOutNullCallback) {
    pthread_t pthread = set_time_out(NULL, 0);
    ASSERT_NULL(pthread);
}

