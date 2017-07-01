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

#ifndef JAVA_UTIL_UUID_HPP_
#define JAVA_UTIL_UUID_HPP_

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
            long timestamp;
            String trap;

        public:
            UUID();
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
             * @param target
             * @return int
             */
            int	compareTo(UUID target);

            /**
             * Compares this object to the specified object.
             * @param target
             * @return boolean
             */
            boolean	equals(UUID target);

            /**
             * Returns the least significant 64 bits of this UUID's 128 bit value.
             * @return long
             */
            long getLeastSignificantBits();

            /**
             * Returns the most significant 64 bits of this UUID's 128 bit value.
             * @return long
             */
            long getMostSignificantBits();

            /**
             * Returns a hash code for this UUID.
             * @return
             */
            int	hashCode();

            /**
             * The node value associated with this UUID.
             * @return long
             */
            long node();

            /**
             * The timestamp value associated with this UUID.
             * @return long
             */
            long getTimestamp();

            /**
             * Returns a String object representing this UUID.
             * @return String
             */
            String toString();

            /**
             * The variant number associated with this UUID.
             * @return
             */
            int	variant();

            /**
             * The version number associated with this UUID.
             * @return
             */
            int	version();

            /**
             * Static factory to retrieve a type 4 (pseudo randomly generated) UUID.
             * @return
             */
            static UUID	randomUUID() {
                Array<byte> randomBytes = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

                //FIXME: will be replaced by Java.Util.Random after it was implemented
                srand(time(0));
                for (int i = 0; i < 16; ++i) {
                    randomBytes[i] = (byte)(random()%100);
                }

                randomBytes[6]  &= 0x0f;  /* clear version        */
                randomBytes[6]  |= 0x40;  /* set to version 4     */
                randomBytes[8]  &= 0x3f;  /* clear variant        */
                randomBytes[8]  |= 0x80;  /* set to IETF variant  */
                return UUID(randomBytes);
            }

            /**
             * Don't support this method
             *  Static factory to retrieve a type 3 (name based) UUID based on the specified byte array.
             */
//            static UUID	nameUUIDFromBytes(Array<byte> name);

            /**
             * Fix this later
             * Creates a UUID from the string standard representation as described in the toString() method.
             * @param name
             * @return
             */
            static UUID	fromString(String name);

            String getTrap();
            void setTrap(const String &trap);
        };
    }
}


#endif //JAVA_UTIL_UUID_HPP_