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

#ifndef JAVA_LANG_OBJECT_HPP
#define JAVA_LANG_OBJECT_HPP

#include "../../../kernel/Kernel.hpp"

namespace Java {
    namespace Lang {
        template<typename E>
        class Class;

		class String;
        class Object;

        template<typename E>
        class Class {
        public:
            Class();

            ~Class();
        };

        class Object {
        protected:
            /**
             * Return a copy of this Object
             * Not support this function yet
             * @return
             */
            template<typename E>
            E clone();

            /**
             * Not support this function yet
             */
            void finalize();

        public:

            /**
             * Support compare two Object through hashCode()
             *
             * @param obj
             * @return boolean
             */
            virtual boolean equals(const Object &o) const {
                if (this->hashCode() == o.hashCode()) {
                    return true;
                }
                return false;
            }

            /**
             * Not support this function yet
             */
            Class<Object> getClass();

            /**
             * A hash code value for this object.
             *
             * @return int
             */
            virtual long hashCode() const {
                return (intptr_t) std::addressof(*this);
            }

            /**
             * Not support this function yet
             */
            void notify();

            /**
             * Not support this function yet
             */
            void notifyAll();

            /**
             * Not support this function yet
             */
            void wait();

            /**
             * Not support this function yet
             */
            void wait(int timeout);

            /**
             * Not support this function yet
             */
            void wait(int timeout, int nanos);

            /**
             * Compare two object is equal or not
             * @param target
             * @return boolean
             */
            boolean operator==(const Object &target) const {
                return this->equals(target);
            }

            /**
             * Compare two object is not equal or not
             * @param target
             * @return boolean
             */
            boolean operator!=(const Object &target) const {
                return !this->equals(target);
            }
        };
    }
}

#endif //JAVA_LANG_OBJECT_HPP
