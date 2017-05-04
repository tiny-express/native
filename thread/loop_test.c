//
// Created by dquang on 4/24/17.
//

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

