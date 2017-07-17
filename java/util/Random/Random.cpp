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
#include <functional>
#include "Random.hpp"
#include "../../lang/IllegalArgumentException/IllegalArgumentException.hpp"

/**
 * Set seedUniquifierField
 */
std::atomic_long Random::seedUniquifierField {8682522807148012L};

/**
 * Set seed offset;
 */
long Random::seedOffset = setSeedOffset();

/**
 * Constructor
 */
Random::Random() : Random(seedUniquifier() ^ nanoTime()) {
}

/**
 * Get system time in nanoseconds
 *
 * @return long
 */
long Random::nanoTime() {
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
    do {
        current = seedUniquifierField.load();
        next = current * 181783497276652981L;
    } while (!seedUniquifierField.compare_exchange_strong(current, next));
    return next;
}

/**
 * Reset the seed to a long seed value
 *
 * @param seedVal
 */
void Random::resetSeed(long seedVal) {
    char *base = (char *) this;
    long *seed = (long *) (base+seedOffset);
    *seed = std::atomic_long {seedVal};
}

/**
 * Copy constructor, std::atomic has it's copy constructor deleted, so a copy constructor is required
 *
 * @param other
 */
Random::Random(const Random &other) {
    this->seed.store(other.seed.load());
}

/**
 * Generates the next pseudorandom number
 *
 * @param bits
 * @return the next pseudorandom value from this random number generator's sequence
 */
int Random::next(int bits) {
    long oldSeed = 0;
    long nextSeed = 0;
    do {
        oldSeed = seed.load();
        nextSeed = ((oldSeed * multiplier + addend) & mask);
    } while (!seed.compare_exchange_weak(oldSeed, nextSeed));
    return (int) (nextSeed >> (48 - bits));
}

/**
 * Returns the next pseudorandom,
 * uniformly distributed boolean value from this random number generator's sequence.
 *
 * @return true if next(1) return a pseudorandom != 0, false otherwise
 */
boolean Random::nextBoolean() {
    return next(1) != 0;
}

/**
 * Returns the next pseudorandom,
 * uniformly distributed int value from this random number generator's sequence
 *
 * @return int
 */
int Random::nextInt() {
    return next(32);
}

/**
 * Returns a pseudorandom, uniformly distributed int value between 0 (inclusive)
 * and the specified value (exclusive), drawn from this random number generator's sequence.
 *
 * @param bound
 * @return int
 * @throw IllegalArgumentException("bound must be positive");
 */
int Random::nextInt(int bound) {
    if (bound <= 0)
        throw IllegalArgumentException(BadBound);
    if (bound & (bound - 1) == 0)
        return (int) ((bound * (long) next(31)) >> 31);
    int bits, val;
    do {
        bits = next(31);
        val = bits % bound;
    } while (bits - val + (bound - 1) < 0);
    return val;
}

/**
 * Generates random bytes and places them into a user-supplied byte array.
 * The number of random bytes produced is equal to the length of the byte array.
 *
 * @param bytes
 */
void Random::nextBytes(Array<byte> *bytes) {
    int len = bytes->length;
    int index = 0;
    while (index < len) {
        int randomNumber = nextInt();
        //TODO change to Math::min when merge Math, change 4 = Integer::SIZE/BYTE::SIZE
        int n = (len - index) <= 4 ? (len - index) : 4;
        for (n; n >= 1; n--) {
            index++;
            //TODO change to BYTE::SIZE
            randomNumber >>= 8;
            bytes->push((byte)randomNumber);
        }
    }
}

/**
 * Returns the next pseudorandom,
 * uniformly distributed double value between 0.0 and 1.0 from this random number generator's sequence.
 *
 * @return double
 */
double Random::nextDouble() {
    return (((long) (next(26)) << 27) + next(27)) * DOUBLE_UNIT;
}

/**
 * Returns the next pseudorandom, uniformly distributed long value from this random number generator's sequence.
 *
 * @return long
 */
long Random::nextLong() {
    return ((long) (next(32)) << 32) + next(32);
}

/**
 * Returns the next pseudorandom,
 * uniformly distributed double value between 0.0 and 1.0 from this random number generator's sequence.
 *
 * @return float
 */
float Random::nextFloat() {
    return next(24) / ((float) (1 << 24));
}

/**
 * the next pseudorandom, Gaussian ("normally") distributed double value
 * with mean 0.0 and standard deviation 1.0 from this random number generator's sequence
 *
 * @return double
 */
double Random::nextGaussian() {
    if (haveNextNextGaussian) {
        haveNextNextGaussian = false;
        return nextNextGaussian;
    }
    else {
        double v1, v2, s;
        do {
            v1 = 2 * nextDouble() - 1; // between -1 and 1
            v2 = 2 * nextDouble() - 1; // between -1 and 1
            s = v1 * v1 + v2 * v2;
        } while (s >= 1 || s == 0);
        double multiplier = sqrt(-2 * log(s) / s);
        nextNextGaussian = v2 * multiplier;
        haveNextNextGaussian = true;
        return v1 * multiplier;
    }
}

/**
 * Sets the seed of this random number generator using a single long seed.
 *
 * @param seed
 */
void Random::setSeed(long seed) {
    this->seed.store(initialScramble(seed));
    haveNextNextGaussian = false;
}
