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
    void *add_for_interval_mutex() {
        t ++;
    }

    void *subtract_for_interval_mutex() {
        t --;
    }
    pthread_t pthread3 = set_interval(subtract_for_interval_mutex, 100);
    pthread_t pthread2 = set_interval(add_for_interval_mutex, 200);
    while(1) {
        sleep(1);
        stop_thread(pthread2);
        stop_thread(pthread3);
        break;
    }
    ASSERT_TRUE(t < 0);
}

TEST(Builtin_Thread, SetTimeOut) {

    int a = 0;

    void *add_for_timeout() {
        a ++;
        printf("%d\n", a);
    }

    pthread_t pthread = set_time_out(add_for_timeout, 200);
    ASSERT_EQUAL(0, a);
    while (1) {
        sleep(2);
        break;
    }
    ASSERT_EQUAL(1, a);
}