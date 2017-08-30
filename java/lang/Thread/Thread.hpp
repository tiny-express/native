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

#include "../Object/Object.hpp"
#include "../String/String.hpp"
#include "../Runnable/Runnable.hpp"
#include <mutex>
#include <thread>
#include <condition_variable>
#include <algorithm>

#define synchronized(m) for(std::unique_lock<std::recursive_mutex> lk(m); lk; lk.unlock());

namespace Java {
		namespace Lang {
            class Thread : public Object, public virtual Runnable {
				 private:
                    pthread_t original;
                    boolean alive;

                    String name;
                    int priority;
                    long eetop;

                    /**
                     * Whether or not to single_step this thread.
                     */
                    boolean single_step;

                    /**
                     * Whether or not the thread is a daemon thread.
                     */
                    boolean daemon = false;

                    /**
                     * JVM state
                     */
                    boolean stillborn = false;

                    /**
                     * What will be run.
                     */
                    Runnable *target;

                    // TODO(thoangminh): Need Class ThreadGroup
                    /**
                     * The group of this thread
                     */
//                        ThreadGroup group;

                    // TODO(thoangminh): Need Class ClassLoader
                    /**
                     * The context ClassLoader for this thread
                     */
//                        ClassLoader contextClassLoader;

                    // TODO(thoangminh): Need Class AccessControlContext
                    /**
                     * The inherited AccessControlContext of this thread
                     */
//                        AccessControlContext inheritedAccessControlContext;

                    /**
                     * For autonumbering anonymous threads.
                     */
                    static int threadInitNumber;

                    // TODO(thoangminh): Need Class ThreadLocal
                    /**
                     * ThreadLocal values pertaining to this thread.
                     * This map is maintained
                     * by the ThreadLocal class.
                     */
//                        ThreadLocal.ThreadLocalMap threadLocals = null;

                    // TODO(thoangminh): Need Class ThreadLocal
                    /**
                     * InheritableThreadLocal values pertaining to this thread.
                     * This map is maintained by
                     * the InheritableThreadLocal class.
                     */
//                        ThreadLocal.ThreadLocalMap inheritableThreadLocals = null;

                    /**
                     * The requested stack size for this thread, or 0 if the creator did
                     * not specify a stack size.  It is up to the VM to do
                     * whatever it likes with this number; some VMs will ignore it.                         *
                     */
                    long stackSize;

                    /**
                     * JVM-private state that persists after native thread termination.
                     */
                    long nativeParkEventPointer;

                    /**
                     * Thread ID
                     */
                    long tid;

                    /**
                     * For generating thread ID
                     */
                    static long threadSeqNumber;

                    /**
                     * Java thread status for tools,
                     * initialized to indicate thread 'not yet started'
                     */
                    volatile int threadStatus = 0;

                    // TODO(thoangminh): Need Class Interruptible
                    /**
                     * The object in which this thread is blocked in an interruptible I/O
                     * operation, if any.  The blocker's interrupt method should be invoked
                     * after setting this thread's interrupt status.
                     */
//                    volatile Interruptible blocker;
//                    const Object blockerLock = new Object();

                    std::thread* threadObject;
                    std::mutex mutexObject;

                 private:
                    /**
                     * Initializes a Thread.
                     *
                     * @param g the Thread group
                     * @param target the object whose run() method gets called
                     * @param name the name of the new Thread
                     * @param stackSize the desired stack size for the new thread, or
                     *        zero to indicate that this parameter is to be ignored.
                     * @param acc the AccessControlContext to inherit, or
                     *            AccessController.getContext() if null
                     */
//                    void init(ThreadGroup g, Runnable target, String name, long stackSize, AccessControlContext acc);

                    // TODO(thoangminh): Need to improve this medthod
                    /**
                     * Initializes a Thread.
                     *
                     * @param target the object whose run() method gets called
                     * @param name the name of the new Thread
                     * @param stackSize the desired stack size for the new thread, or
                     *        zero to indicate that this parameter is to be ignored.
                     */
                    void init(Runnable *target, String name, long stackSize);

                    // TODO(thoangminh): Set synchronized for this method
                    static int nextThreadNum();

                    // TODO(thoangminh): Set synchronized for this method
                    static long nextThreadID();

                 public:
                    /**
                     * The minimum priority that a thread can have.
                     */
                    static int const MIN_PRIORITY = 1;

                    /**
                     * The default priority that is assigned to a thread.
                     */
                    static int const NORM_PRIORITY = 5;

                    /**
                     * The maximum priority that a thread can have.
                     */
                    static int const MAX_PRIORITY = 10;

                 public:
                    void *pthread_run(void *context) {
                        ((Thread *) (context))->target->run();
                    }

                    static void *pthread_helper(void *context) {
                        return ((Thread *) (context))->pthread_run(context);
                    }

				 public:
                    Thread();
                    Thread(Runnable* target);
//                    Thread(Runnable &target);
//                    Thread(String name);
//                    Thread(Runnable target, AccessControlContext acc);
//                    Thread(ThreadGroup group, Runnable target);
//                    Thread(ThreadGroup group, String name);
//                    Thread(Runnable &target, String name);
//                    Thread(ThreadGroup group, Runnable target, String name, long stackSize);
//                    Thread(ThreadGroup group, Runnable target, String name);
                    ~Thread();
				
				 public:
                    void run() override ;

                    // TODO(thoangminh): Set synchronized for this method
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

                    /**
                     * Tests if this thread is a daemon thread.
                     *
                     * @return  true if this thread is a daemon thread;
                     *          false otherwise.
                     * @see     #setDaemon(boolean)
                     */
                    boolean isDaemon() ;

                    /**
                     * Marks this thread as either a {#isDaemon daemon} thread
                     * or a user thread. The Java Virtual Machine exits when the only
                     * threads running are all daemon threads.
                     *
                     * This method must be invoked before the thread is started.
                     *
                     * @param  on
                     *         if {true}, marks this thread as a daemon thread
                     *
                     * @throws  IllegalThreadStateException
                     *          if this thread is {#isAlive alive}
                     *
                     * @throws  SecurityException
                     *          if {#checkAccess} determines that the current
                     *          thread cannot modify this thread
                     */
                    void setDaemon(boolean on);

                    /**
                     * Changes the priority of this thread.
                     * 
                     * First the checkAccess method of this thread is called
                     * with no arguments. This may result in throwing a
                     * SecurityException.
                     * 
                     * Otherwise, the priority of this thread is set to the smaller of
                     * the specified newPriority and the maximum permitted
                     * priority of the thread's thread group.
                     *
                     * @param newPriority priority to set this thread to
                     * @exception  IllegalArgumentException  If the priority is not in the
                     *               range MIN_PRIORITY to
                     *               MAX_PRIORITY.
                     * @exception  SecurityException  if the current thread cannot modify
                     *               this thread.
                     * @see        #getPriority
                     * @see        #checkAccess()
                     * @see        #getThreadGroup()
                     * @see        #MAX_PRIORITY
                     * @see        #MIN_PRIORITY
                     * @see        ThreadGroup#getMaxPriority()
                     */
                    void setPriority(int newPriority);

                    /**
                     * Returns this thread's priority.
                     *
                     * @return  this thread's priority.
                     * @see     #setPriority
                     */
                    int getPriority();

                    void start();

                    void join();

                    void join(long millis);
        };
    }  // namespace Lang
}  // namespace Java

#endif   // JAVA_LANG_THREAD_THREAD_HPP_

