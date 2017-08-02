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

#include "MediaType.hpp"

using namespace Javax::Ws;

#define CHAR_NOT_FOUND -1

String MediaType::APPLICATION_ATOM_XML          = "application/atom+xml";
String MediaType::APPLICATION_FORM_URLENCODED   = "application/x-www-form-urlencoded";
String MediaType::APPLICATION_JSON              = "application/json";
String MediaType::APPLICATION_OCTET_STREAM      = "application/octet-stream";
String MediaType::APPLICATION_SVG_XML           = "application/svg+xml";
String MediaType::APPLICATION_XHTML_XML         = "application/xhtml+xml";
String MediaType::APPLICATION_XML               = "application/xml";
String MediaType::MEDIA_TYPE_WILDCARD           = "*";
String MediaType::MULTIPART_FORM_DATA           = "multipart/form-data";
String MediaType::TEXT_HTML                     = "text/html";
String MediaType::TEXT_PLAIN                    = "text/plain";
String MediaType::TEXT_XML                      = "text/xml";
String MediaType::WILDCARD                      = "*/*";

MediaType::MediaType() {
    type = MEDIA_TYPE_WILDCARD;
    subtype = MEDIA_TYPE_WILDCARD;
}

MediaType::MediaType(const String &type, const String &subtype) {
    this->type = type;
    this->subtype = subtype;
}

MediaType::MediaType(const String &type, const String &subtype, const HashMap<String, String> &parameters) {
    this->type = type;
    this->subtype = subtype;
    this->parameters = parameters;
}

const HashMap<String, String> &MediaType::getParameters() const {
    return parameters;
};

const String &MediaType::getSubtype() const {
    return subtype;
}

const String &MediaType::getType() const {
    return type;
}

boolean MediaType::isCompatible(MediaType other) {

    if (!isWildcardType() && !other.isWildcardType() && !type.equals(other.getType())) {
        return false;
    }

    if (isWildcardType() || other.isWildcardSubtype()) {
        return true;
    }

    if (type.equals(other.getType()) && subtype.equals(other.getSubtype())) {
        return true;
    }

    // wildcard with suffix? e.g. application/*+xml
    if (isWildcardSubtype() || other.isWildcardSubtype()) {
        int thisPlusIndex = subtype.indexOf('+');
        int otherPlusIndex = other.getSubtype().indexOf('+');
        if (thisPlusIndex == CHAR_NOT_FOUND && otherPlusIndex == CHAR_NOT_FOUND) {
            return true;
        }

        if (thisPlusIndex != CHAR_NOT_FOUND && otherPlusIndex != CHAR_NOT_FOUND) {
            String subtypeBeforePlus = subtype.subString(0, thisPlusIndex - 1);
            String otherSubtypeBeforePlus = ((String) other.getSubtype()).subString(0, otherPlusIndex - 1);
            String subtypeAfterPlus = subtype.subString(thisPlusIndex + 1);
            String otherSubtypeAfterPlus = ((String) other.getSubtype()).subString(otherPlusIndex + 1);

            if (subtypeAfterPlus.equals(otherSubtypeAfterPlus) &&
                    (subtypeBeforePlus.equals(MEDIA_TYPE_WILDCARD)
                     || otherSubtypeBeforePlus.equals(MEDIA_TYPE_WILDCARD))) {
                return true;
            }
        }

    }

    return false;

}

const String &MediaType::toString() {
    // TODO @DQuang
    return "";
}

boolean MediaType::isWildcardSubtype() {
    return subtype.equals(MEDIA_TYPE_WILDCARD) || subtype.startsWith("*+");
}

boolean MediaType::isWildcardType() {
    return type.equals(MEDIA_TYPE_WILDCARD);
}

MediaType MediaType::valueOf(String type) {
    // TODO @DQuang
    MediaType mediaType;
    return mediaType;
}

MediaType::~MediaType() = default;