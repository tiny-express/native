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

#ifndef JAVA_NET_URL_ENCODER_HPP
#define JAVA_NET_URL_ENCODER_HPP

#include "../../../kernel/String.hpp"
#include "../../lang/String/String.hpp"

using namespace Java::Lang;

namespace Java {
    namespace Net {
        class URLDecoder : public virtual Object {
        public:
            /**
             * Decodes a x-www-form-urlencoded string.
             * The platform's default encoding is used to determine what characters are
             * represented by any consecutive sequences of the form "%xy".
             * The platform's default encoding is UTF-8.
             *
             * @param source
             * @return String
             */
            static String decode(const String &source);

            /**
             * Decodes a application/x-www-form-urlencoded string using a specific
             * encoding scheme.
             * The supplied encoding is used to determine what characters are represented
             * by any consecutive sequences of the form "%xy".
             *
             * @param source
             * @param encoding
             * @return String
             * @throw UnsupportedEncodingException - If character encoding needs
             * to be consulted, but named character encoding is not supported.
             */
            static String decode(const String &source, const String &encoding);
        };  // class URLDecoder
    }  // namespace Net
}  // namespace Java

#endif  // JAVA_NET_URL_ENCODER_HPP
