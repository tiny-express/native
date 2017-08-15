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

#ifndef JAVA_LANG_THREAD_HPP_
#define JAVA_LANG_THREAD_HPP_

#include <pthread.h>
#include "../Object/Object.hpp"
#include "../String/String.hpp"
#include "../Runnable/Runnable.hpp"

namespace Java {
		namespace Lang {
				class Thread : public Object, public virtual Runnable {
				private:
						pthread_t original;
						string threadName;
						Runnable *target;
						
						boolean isThreadRunning;
						///Adds-on function to adapt pthread_create of C style
				public:
						void *pthread_run(void *context) {
							((Thread *) context )->target->run();
						}
						
						static void *pthread_helper(void *context) {
							return ((Thread *) context )->pthread_run(context);
						}
				
				public:
						Thread();
						Thread(Runnable &target2);
						Thread(Runnable &target2, String name);
						Thread(String name);
						//Thread(ThreadGroup group, Runnable &target);
						//Thread(ThreadGroup group, Runnable &target, String &name);
						//Thread(ThreadGroup group, Runnable &target, String &name, long stackSize);
						//Thread(ThreadGroup group, String &name);
						~Thread();
				
				public:
						void run() const;
						void start();
						void stop();
						void join();
						void join(unsigned int millis);
						
						string getName();
						void setName(string target);
						string toString() const;
					
				};
		}
}

#endif   // JAVA_LANG_THREAD_THREAD_HPP_