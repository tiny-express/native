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

#ifndef NATIVE_JAVA_UTIL_UUID_HPP
#define NATIVE_JAVA_UTIL_UUID_HPP

#include "../../Lang.hpp"

using namespace Java::Lang;

namespace Java {
    namespace  Util {
        class UUID
        : public Object
//        , public virtual Serializable
//        , public virtual Comparable<UUID>
        {
        private:
            UUID(Array<byte> data);
            long mostSigBits;
            long leastSigBits;

        public:
            UUID(long mostSigBits, long leastSigBits);
            ~UUID();

        public:
            /**
             * Don't support this method
             * The clock sequence value associated with this UUID.
             * @return
             */
//            int	clockSequence();

            /**
             * Compares this UUID with the specified UUID.
             * @param val
             * @return
             */
            int	compareTo(UUID target);

            /**
             * Compares this object to the specified object.
             * @param obj
             * @return
             */
            boolean	equals(UUID target);

            /**
             * Returns the least significant 64 bits of this UUID's 128 bit value.
             * @return
             */
            long getLeastSignificantBits();

            /**
             * Returns the most significant 64 bits of this UUID's 128 bit value.
             * @return
             */
            long getMostSignificantBits();

            /**
             * This method was implemented on Object, no need to define again
             * Returns a hash code for this UUID.
             * @return
             */
//            int	hashCode();

            /**
             * The node value associated with this UUID.
             * @return
             */
            long node();

            /**
             * Don't support this method - don't have >>> operator in C++
             * The timestamp value associated with this UUID.
             * @return
             */
//            long timestamp();

            /**
             * Returns a String object representing this UUID.
             * @return
             */
            String toString();

            /**
             * Don't support this method - don't have >>> operator in C++
             * The variant number associated with this UUID.
             * @return
             */
//            int	variant();

            /**
             * Don't support this method - don't have >>> operator in C++
             * The version number associated with this UUID.
             * @return
             */
//            int	version();

            /**
             * Static factory to retrieve a type 4 (pseudo randomly generated) UUID.
             * @return
             */
            static UUID	randomUUID() {

            }

            /**
             * Don't support this method
             *  Static factory to retrieve a type 3 (name based) UUID based on the specified byte array.
             */
//            static UUID	nameUUIDFromBytes(Array<byte> name);

            /**
             * Creates a UUID from the string standard representation as described in the toString() method.
             * @param name
             * @return
             */
            static UUID	fromString(String name) {

            }

        };
    }
}


#endif //NATIVE_JAVA_UTIL_UUID_HPP