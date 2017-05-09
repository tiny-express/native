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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../thread.h"

typedef struct thread_argument {
    void *callback;
    unsigned int milliseconds;
} thread_argument;

void *loop(void *argument);

void *run(void *argument);

/**
 * Run a callback repeatedly after period of time
 * @param callback
 * @param miliseconds
 * @return thread
 */
pthread_t set_interval(void *callback, unsigned int milliseconds) {
    if (callback == NULL) {
        return NULL;
    }
    pthread_t thread;
    thread_argument *argument = malloc(sizeof(thread_argument));
    argument->milliseconds = milliseconds;
    argument->callback = callback;
    int error = pthread_create(&thread, NULL, loop, (void *)argument);
    if (error) {
        printf("Error\n");
        fflush(stdout);
    }
    return thread;
}

/**
 * Run callback after milisenconds
 * @param callback
 * @param miliseconds
 * @return thread
 */
pthread_t set_time_out(void *callback, unsigned int milliseconds) {

    if (callback == NULL) {
        return NULL;
    }
    pthread_t thread;
    thread_argument *argument = malloc(sizeof(thread_argument));
    argument->milliseconds = milliseconds;
    argument->callback = callback;
    int error = pthread_create(&thread, NULL, run, (void *)argument);
    if (error) {
        printf("Error\n");
        fflush(stdout);
    }
    return thread;
}

/**
 * run callback repeatedly
 * @param argument
 * @return
 */
void *loop(void *argument) {
    while(1) {
        ((void(*)())((thread_argument*)argument)->callback)();
        usleep(((thread_argument *)argument)->milliseconds*1000);
    }
}

/**
 * execute a callback
 * @param argument
 * @return
 */
void *run(void *argument) {
    usleep(((thread_argument *)argument)->milliseconds*1000);
    ((void(*)())((thread_argument*)argument)->callback)();
}
