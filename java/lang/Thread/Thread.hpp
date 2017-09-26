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

#ifndef JAVA_LANG_THREAD_THREAD_HPP_
#define JAVA_LANG_THREAD_THREAD_HPP_

#include <mutex>
#include <thread>

#include "../Object/Object.hpp"
#include "../Runnable/Runnable.hpp"
#include "../../util/Concurrent/Semaphore/Semaphore.hpp"
using Java::Util::Concurrent::Semaphore;

namespace Java {
		namespace Lang {
            class Thread : public Object, public virtual Runnable {
                private:
                    boolean alive = false;
                    String name;
                    long long tid = 0;
                    Runnable *target = NULL;
                    Semaphore semahoreObject;
                    std::thread threadObject;
                    std::mutex mutexObject;

                 private:
                    /**
                     * Initializes a Thread.
                     *
                     * @param target the object whose run() method gets called
                     * @param name the name of the new Thread
                     * @param stackSize the desired stack size for the new thread, or
                     *        zero to indicate that this parameter is to be ignored.
                     */
                    void init(Runnable *target, String name);

				 public:
                    Thread();
                    Thread(Runnable* target);
                    ~Thread();

                    void run() override;

                    /**
                     * Changes the name of this thread to be equal to the argument
                     * name.
                     * 
                     * First the checkAccess method of this thread is called
                     * with no arguments. This may result in throwing a
                     * SecurityException.
                     *
                     * @param      name   the new name for this thread.
                     * @exception  SecurityException  if the current thread cannot modify this
                     *               thread.
                     * @see        #getName
                     * @see        #checkAccess()
                     */
                    void setName(String name);

                    /**
                     * Returns this thread's name.
                     *
                     * @return  this thread's name.
                     * @see     #setName(String)
                     */
                    String getName();

                    boolean isAlive();

                    long long getId();

                    void start();

                    void join();

                    void join(long millis);

                    static void sleep(long millis);

                    static Thread* currentThread();
            };
        } // namespace Lang
} // namespace Java

#endif   // JAVA_LANG_THREAD_THREAD_HPP_

