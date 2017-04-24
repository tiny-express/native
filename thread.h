//
// Created by dquang on 4/24/17.
//

#ifndef BUILTIN_THREAD_H
#define BUILTIN_THREAD_H

#include <pthread.h>

pthread_t set_interval(void *callback, unsigned int miliseconds);

pthread_t set_time_out(void *callback, unsigned int miliseconds);

void stop_thread(pthread_t pthread);

#endif