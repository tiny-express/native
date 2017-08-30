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

#include "MediaType.hpp"
#include "../../../../java/lang/StringBuilder/StringBuilder.hpp"
#include "MediaTypeException/MediaTypeException.hpp"

using namespace Javax::Ws;

#define CHAR_NOT_FOUND -1

const String MediaType::APPLICATION_ATOM_XML          = "application/atom+xml";
const String MediaType::APPLICATION_FORM_URLENCODED   = "application/x-www-form-urlencoded";
const String MediaType::APPLICATION_JSON              = "application/json";
const String MediaType::APPLICATION_OCTET_STREAM      = "application/octet-stream";
const String MediaType::APPLICATION_SVG_XML           = "application/svg+xml";
const String MediaType::APPLICATION_XHTML_XML         = "application/xhtml+xml";
const String MediaType::APPLICATION_XML               = "application/xml";
const String MediaType::MEDIA_TYPE_WILDCARD           = "*";
const String MediaType::MULTIPART_FORM_DATA           = "multipart/form-data";
const String MediaType::TEXT_HTML                     = "text/html";
const String MediaType::TEXT_PLAIN                    = "text/plain";
const String MediaType::TEXT_XML                      = "text/xml";
const String MediaType::WILDCARD                      = "*/*";

const MediaType APPLICATION_ATOM_XML_TYPE             = MediaType("application","atom+xml");
const MediaType APPLICATION_FORM_URLENCODED_TYPE      = MediaType("application","x-www-form-urlencoded");
const MediaType APPLICATION_JSON_TYPE                 = MediaType("application","json");
const MediaType APPLICATION_OCTET_STREAM_TYPE         = MediaType("application","octet-stream");
const MediaType APPLICATION_SVG_XML_TYPE              = MediaType("application","svg+xml");
const MediaType APPLICATION_XHTML_XML_TYPE            = MediaType("application","xhtml+xml");
const MediaType APPLICATION_XML_TYPE                  = MediaType("application","xml");
const MediaType MULTIPART_FORM_DATA_TYPE              = MediaType("multipart","form-data");
const MediaType TEXT_HTML_TYPE                        = MediaType("text","html");
const MediaType TEXT_PLAIN_TYPE                       = MediaType("text","plain");
const MediaType TEXT_XML_TYPE                         = MediaType("text","xml");
const MediaType WILDCARD_TYPE                         = MediaType();

MediaType::MediaType() {
    this->type = MEDIA_TYPE_WILDCARD;
    this->subtype = MEDIA_TYPE_WILDCARD;
}

MediaType::MediaType(const String &type, const String &subtype) {
    if (type.isEmpty()) {
        throw MediaTypeException("`type` must not be empty");
    }

    if (subtype.isEmpty()) {
        throw MediaTypeException("`subtype` must not be empty");
    }

    if (type.equals(MEDIA_TYPE_WILDCARD) && !subtype.equals(MEDIA_TYPE_WILDCARD)) {
        throw MediaTypeException("Wildcard type is legal only in '*/*' (all types)");
    }

    this->type = type;
    this->subtype = subtype;
}

MediaType::MediaType(const String &type, const String &subtype, const HashMap<String, String> &parameters) {

    if (type.isEmpty()) {
        throw MediaTypeException("`type` must not be empty");
    }

    if (subtype.isEmpty()) {
        throw MediaTypeException("`subtype` must not be empty");
    }

    if (type.equals(MEDIA_TYPE_WILDCARD) && !subtype.equals(MEDIA_TYPE_WILDCARD)) {
        throw MediaTypeException("Wildcard type is legal only in '*/*' (all types)");
    }

    this->type = type;
    this->subtype = subtype;
    this->parameters = parameters;
}

const HashMap<String, String> &MediaType::getParameters() const {
    return this->parameters;
};

const String &MediaType::getSubtype() const {
    return this->subtype;
}

const String &MediaType::getType() const {
    return this->type;
}

boolean MediaType::isCompatible(MediaType other) {
    if (!this->isWildcardType() && !other.isWildcardType() && !this->type.equals(other.getType())) {
        return false;
    }

    if (this->isWildcardType() || other.isWildcardSubtype()) {
        return true;
    }

    if (this->type.equals(other.getType()) && this->subtype.equals(other.getSubtype())) {
        return true;
    }

    // wildcard with suffix? e.g. application/*+xml
    if (this->isWildcardSubtype() || other.isWildcardSubtype()) {
        int thisPlusIndex = this->subtype.indexOf('+');
        int otherPlusIndex = other.getSubtype().indexOf('+');
        if (thisPlusIndex == CHAR_NOT_FOUND && otherPlusIndex == CHAR_NOT_FOUND) {
            return true;
        }

        if (thisPlusIndex != CHAR_NOT_FOUND && otherPlusIndex != CHAR_NOT_FOUND) {
            String subtypeBeforePlus = this->subtype.subString(0, thisPlusIndex);
            String otherSubtypeBeforePlus = ((String) other.getSubtype()).subString(0, otherPlusIndex);
            String subtypeAfterPlus = this->subtype.subString(thisPlusIndex);
            String otherSubtypeAfterPlus = ((String) other.getSubtype()).subString(otherPlusIndex);

            if (subtypeAfterPlus.equals(otherSubtypeAfterPlus) &&
                    (subtypeBeforePlus.equals(MEDIA_TYPE_WILDCARD)
                     || otherSubtypeBeforePlus.equals(MEDIA_TYPE_WILDCARD))) {
                return true;
            }
        }
    }

    return false;
}

string MediaType::toString() {
    this->backupForToString = this->type + "/" + this->subtype;
    return this->backupForToString.toString();
}

boolean MediaType::isWildcardSubtype() {
    return this->subtype.equals(MEDIA_TYPE_WILDCARD) || subtype.startsWith("*+");
}

boolean MediaType::isWildcardType() {
    return this->type.equals(MEDIA_TYPE_WILDCARD);
}

MediaType MediaType::valueOf(String type) {

    if (type.isEmpty()) {
        throw MediaTypeException("`type` must not be empty");
    }

    int indexOfSemicolon = type.indexOf(";");
    String fullType = (indexOfSemicolon >= 0 ? type.subString(0, indexOfSemicolon) : type).trim();
    if (fullType.isEmpty()) {
        throw MediaTypeException("`type` must not be empty");
    }

    if (fullType.equals(MEDIA_TYPE_WILDCARD)) {
        fullType = WILDCARD;
    }

    int splashIndex = fullType.indexOf('/');

    if (splashIndex == CHAR_NOT_FOUND) {
        String exceptionMessage = type + (String) " does not contains '/'";
        throw MediaTypeException(exceptionMessage);
    }

    if (splashIndex == fullType.length() - 1) {
        String exceptionMessage = type + (String) " does not contain subtype after '/'";
        throw MediaTypeException(exceptionMessage);
    }

    String getType = fullType.subString(0, splashIndex);
    String getSubtype = fullType.subString(splashIndex + 1);
    if (getType.equals(MEDIA_TYPE_WILDCARD) && !getSubtype.equals(MEDIA_TYPE_WILDCARD)) {
        String exceptionMessage = type + (String) " wildcard type is legal only in '*/*' (all types)";
        throw MediaTypeException(exceptionMessage);
    }

    MediaType mediaType(getType, getSubtype);

    return mediaType;
}

MediaType::~MediaType() = default;
