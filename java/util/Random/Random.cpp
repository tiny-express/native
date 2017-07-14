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


#include <chrono>
#include "Random.hpp"

std::atomic_long Random::seedUniquifierField{8682522807148012L};

Random::Random() : Random(seedUniquifier() ^ nanoTime()) {
}

/**
 * Get system time in nanoseconds
 *
 * @return long
 */
long Random::nanoTime(){
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto nanosecond = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
    return nanosecond;
}

/**
 * Constructor
 *
 * @param seed
 */
Random::Random(long seed) {
    this->seed.store(initialScramble(seed));
}

/**
 * Return a scramble for Construtor
 *
 * @param seed
 * @return
 */
long Random::initialScramble(long seed) {
    return (seed ^ multiplier) & mask;
}

/**
 * Sets the seedUniquifierField of the random number generator.
 *
 * @return
 */
long Random::seedUniquifier() {
    long current = 0;
    long next = 0;
    do{
        long current = seedUniquifierField.load();
        long next = current * 181783497276652981L;
    }while(!seedUniquifierField.compare_exchange_strong(current, next));
    return next;
}

void Random::resetSeed(long seedVal) {

}

Random::Random(const Random &other) {
    this->seed.store(other.seed.load());
}
