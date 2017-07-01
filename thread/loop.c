/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
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

/**
 * Run a callback repeatedly after a period of time
 * This function is converted from Javascript setInterval()
 *
 * @param callback
 * @param miliseconds
 * @return thread
 */
pthread_t set_interval(void *callback, unsigned int milliseconds) {
	if (callback == NULL) {
		return (pthread_t) NULL;
	}
	pthread_t thread;
	thread_argument *argument = calloc(2, sizeof(thread_argument));
	argument->milliseconds = milliseconds;
	argument->callback = callback;
	int error = pthread_create(&thread, NULL, loop, (void *) argument);
	if (error) {
		printf("Error when set_interval pthread_t\n");
		fflush(stdout);
	}
	return thread;
}

/**
 * Run callback after milliseconds
 * This function is converted from Javascript setTimeout()
 *
 * @param callback
 * @param milliseconds
 * @return thread_t
 */
pthread_t set_time_out(void *callback, unsigned int milliseconds) {
	if (callback == NULL) {
		return (pthread_t) NULL;
	}
	pthread_t thread;
	thread_argument *argument = calloc(2, sizeof(thread_argument));
	argument->milliseconds = milliseconds;
	argument->callback = callback;
	int error = pthread_create(&thread, NULL, run, (void *) argument);
	if (error) {
		printf("Error\n");
		fflush(stdout);
	}
	return thread;
}

/**
 * Loop callback
 * @param argument
 */
void *loop(void *argument) {
	while (1) {
		((void (*)()) ((thread_argument *) argument )->callback )();
		usleep(((thread_argument *) argument )->milliseconds * 1000);
	}
}

/**
 * Run a callback
 * @param argument
 */
void *run(void *argument) {
	usleep(((thread_argument *) argument )->milliseconds * 1000);
	((void (*)()) ((thread_argument *) argument )->callback )();
	return EXIT_SUCCESS;
}

/**
 * deley miliseconds
 * @param miliseconds
 */
void sleep_miliseconds(unsigned int miliseconds) {
	unsigned long start = 0;
	unsigned long stop = miliseconds * 1000000;
	unsigned long counter = 0;
	unsigned long index = 0;
	for (index = start; index < stop; index++) {
		counter++;
	}
}