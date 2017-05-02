//
// Created by dquang on 4/24/17.
//

#include "../thread.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct thread_argument {
    void *callback;
    unsigned int miliseconds;
} thread_argument;

void *loop(void *argument);

void *run(void *argument);

/**
 * Run a callback repeatedly after period of time
 * @param callback
 * @param miliseconds
 * @return thread
 */
pthread_t set_interval(void *callback, unsigned int miliseconds) {
    if (callback == NULL) {
        return NULL;
    }
    pthread_t thread;
    thread_argument *argument = malloc(sizeof(thread_argument));
    argument->miliseconds = miliseconds;
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
pthread_t set_time_out(void *callback, unsigned int miliseconds) {

    if (callback == NULL) {
        return NULL;
    }
    pthread_t thread;
    thread_argument *argument = malloc(sizeof(thread_argument));
    argument->miliseconds = miliseconds;
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
        usleep(((thread_argument *)argument)->miliseconds*1000);
    }
}

/**
 * execute a callback
 * @param argument
 * @return
 */
void *run(void *argument) {
    usleep(((thread_argument *)argument)->miliseconds*1000);
    ((void(*)())((thread_argument*)argument)->callback)();
}
