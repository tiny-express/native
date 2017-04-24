//
// Created by dquang on 4/24/17.
//

#include "../builtin.h"
#include "../unit_test.h"
#include "../thread.h"


TEST(Builtin_Thread, SetInterval) {

    int t = 0;

    void *add() {
        t ++;
    }

    void *subtract() {
        t --;
    }

    pthread_t pthread1 = set_interval(add, 100);
    while(1) {
        sleep(1);
        stop_thread(pthread1);
        break;
    }
    ASSERT_TRUE(t > 0);
}

TEST(Builtin_Thread, SetIntervalMutex) {
    int t = 0;
    int count1 = 0;
    int count2 = 0;
    void *add_for_interval_mutex() {
        count1 ++;
        pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
        pthread_mutex_lock(&mutex);
        t ++;
        pthread_mutex_unlock(&mutex);
    }

    void *subtract_for_interval_mutex() {
        count2 ++;
        pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
        pthread_mutex_lock(&mutex);
        t --;
        pthread_mutex_unlock(&mutex);
    }
    pthread_t pthread2 = set_interval(add_for_interval_mutex, 0);
    pthread_t pthread3 = set_interval(subtract_for_interval_mutex, 20);
    while(1) {
        sleep(1);
        stop_thread(pthread3);
        stop_thread(pthread2);
        break;
    }
    printf("t count1 - count2: %d - %d\n",t, count1 - count2);
    ASSERT_TRUE(t != count1 - count2);
}

TEST(Builtin_Thread, SetTimeOut) {

    int a = 0;

    void *add_for_timeout() {
        a ++;
    }

    pthread_t pthread = set_time_out(add_for_timeout, 200);
    ASSERT_EQUAL(0, a);
    while (1) {
        sleep(1);
        break;
    }
    ASSERT_EQUAL(1, a);
}

TEST(Builtin_Thread, TimeOutStopInterval) {
    int x = 0;
    int b = 0;
    void *add() {
        x ++;
    }

    pthread_t interval_thread;

    void *stop_interval() {
        stop_thread(interval_thread);
        b = x;
    }
    interval_thread = set_interval(add, 500);
    pthread_t time_out_thread = set_time_out(stop_interval, 2000);
    while (1) {
        sleep(5);
        break;
    }
    ASSERT_TRUE(b > 0);
}