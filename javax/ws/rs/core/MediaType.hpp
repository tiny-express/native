/**
 * Copyright (c) 2017 Food Tiny Project. All rights reserved.
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

#ifndef NATIVE_JAVAX_WS_RS_CORE_MEDIA_TYPE_HPP
#define NATIVE_JAVAX_WS_RS_CORE_MEDIA_TYPE_HPP

#include "../../../../java/Lang.hpp"
#include "../../../../java/util/HashMap/HashMap.hpp"

namespace Javax {
    namespace Ws {
        class MediaType : public virtual Java::Lang::Object {
        public:
            static const String APPLICATION_ATOM_XML;
            static const String APPLICATION_FORM_URLENCODED;
            static const String APPLICATION_JSON;
            static const String APPLICATION_OCTET_STREAM;
            static const String APPLICATION_SVG_XML;
            static const String APPLICATION_XHTML_XML;
            static const String APPLICATION_XML;
            static const String MEDIA_TYPE_WILDCARD;
            static const String MULTIPART_FORM_DATA;
            static const String TEXT_HTML;
            static const String TEXT_PLAIN;
            static const String TEXT_XML;
            static const String WILDCARD;
            static const MediaType APPLICATION_ATOM_XML_TYPE;
            static const MediaType APPLICATION_FORM_URLENCODED_TYPE;
            static const MediaType APPLICATION_JSON_TYPE;
            static const MediaType APPLICATION_OCTET_STREAM_TYPE;
            static const MediaType APPLICATION_SVG_XML_TYPE;
            static const MediaType APPLICATION_XHTML_XML_TYPE;
            static const MediaType APPLICATION_XML_TYPE;
            static const MediaType MULTIPART_FORM_DATA_TYPE;
            static const MediaType TEXT_HTML_TYPE;
            static const MediaType TEXT_PLAIN_TYPE;
            static const MediaType TEXT_XML_TYPE;
            static const MediaType WILDCARD_TYPE;

            /**
             * Creates a new instance of MediaType, both type and subtype are wildcards.
             */
            MediaType();

            /**
             * Creates a new instance of MediaType with the supplied type and subtype.
             *
             * @param type
             * @param subtype
             */
            MediaType(const String &type, const String &subtype);

            /**
             * Creates a new instance of MediaType with the supplied type, subtype and parameters.
             *
             * @param type
             * @param subtype
             * @param parameters
             */
            MediaType(const String &type, const String &subtype, const HashMap<String, String> &parameters);

            /**
             * Remove media type instance
             */
            ~MediaType();

            /**
             * Getter for a read-only parameter map.
             *
             * @return HashMap<String, String> &
             */
            const HashMap<String, String> &getParameters() const;

            /**
             * Getter for subtype.
             *
             * @return String &
             */
            const String &getSubtype() const;

            /**
             * Getter for primary type.
             *
             * @return String &
             */
            const String &getType() const;

            /**
             * Check if this media type is compatible with another media type.
             *
             * @param other - the media type to compare with.
             * @return boolean
             * true if the types are compatible, false otherwise.
             */
            boolean isCompatible(MediaType other);

            /**
             * Checks if the subtype is a wildcard
             *
             * @return boolean
             */
            boolean isWildcardSubtype();

            /**
             * Checks if the primary type is a wildcard.
             *
             * @return boolean
             */
            boolean isWildcardType();

            /**
             * Convert the media type to a string suitable for use as the value of a corresponding HTTP header.
             *
             * @return string
             */
            string toString();

            /**
             * Creates a new instance of MediaType by parsing the supplied string.
             *
             * @param type
             * @return MediaType
             */
            static MediaType valueOf(String type);

        private:
            String type;
            String subtype;
            HashMap<String, String> parameters;

        private:
            String backupForToString;
        };  // class MediaType
    }  // namespace Ws
}  // namespace Javax

#endif  // NATIVE_JAVAX_WS_RS_CORE_MEDIA_TYPE_HPP
