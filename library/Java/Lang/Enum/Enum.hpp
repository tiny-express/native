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

#ifndef NATIVE_JAVA_LANG_ENUM_HPP
#define NATIVE_JAVA_LANG_ENUM_HPP

#include "../String/String.hpp"

namespace Java {
    namespace Lang {
        template<typename E>
        class Enum : public Object,
                //public virtual Comparable<E>,
                     public virtual Serializable {
        private:
            String name;
            int original;
            String originalString;

        public:
            Enum(const_string name, int original) {
                this->name = stringCopy(name);
                this->original = original;
                this->originalString = stringCopy(name);
            }

            Enum(string name, int original) {
                this->name = stringCopy(name);
                this->original = original;
                this->originalString = stringCopy(name);
            }

            ~Enum() {}

        public:
            Enum clone() {
                Enum result;
                result.name = this->name;
                result.original = this->original;
                return result;
            }

            /**
             * Make a comparision from this enum to another
             *
             * @param e
             * @return int
             */
            int compareTo(const Enum<E> &e) {
                return this->original - e.original;
            }

            /**
             * Returns the name of this enum constant, exactly as declared in its enum declaration.
             * @return String
             */
            String getName() {
                return this->name;
            }

            /**
             * Returns the original of this enumeration constant
             * (its position in its enum declaration, where the initial constant is assigned an original of zero).
             * @return int
             */
            int getOrdinal() {
                return this->original;
            }

            /**
             * Returns the name of this enum constant, as contained in the declaration.
             * @return String
             */
            String toString() {
                return this->originalString;
            }

            /**
            * Returns true if the specified object is equal to this enum constant
            * @return boolean
            */
            boolean equals(Enum<E> &other) {
                return this->original == other.original;
            }
        };
    }
}

#endif // NATIVE_JAVA_LANG_ENUM_HPP