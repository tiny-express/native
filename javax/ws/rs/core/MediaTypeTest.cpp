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
#include "MediaTypeException/MediaTypeException.hpp"

extern "C" {
#include "../../../../kernel/test.h"
}

using namespace Javax::Ws;

TEST(MediaType, Constructor) {
    // Default constructor expected type and subtype are wildcard, parameters empty
    MediaType mediaType;
    ASSERT_STR(MediaType::MEDIA_TYPE_WILDCARD.toString(), mediaType.getType().toString());
    ASSERT_STR(MediaType::MEDIA_TYPE_WILDCARD.toString(), mediaType.getSubtype().toString());
    ASSERT_TRUE(mediaType.getParameters().isEmpty());

    // Constructor with type and subtype, expected type, subtype
    MediaType mediaType1("application", "json");
    ASSERT_STR("application", mediaType1.getType().toString());
    ASSERT_STR("json", mediaType1.getSubtype().toString());
    ASSERT_TRUE(mediaType.getParameters().isEmpty());

    // Constructor with type, subtype and parameters, expected type, subtype and parameters equal params
    HashMap<String, String> parameters;
    parameters.put("key", "value");
    MediaType mediaType2("text", "html", parameters);
    ASSERT_STR("text", mediaType2.getType().toString());
    ASSERT_STR("html", mediaType2.getSubtype().toString());
    ASSERT_STR("value", mediaType2.getParameters().get("key").toString());

    // Constructor with type empty, expected Exception "`type` must not be empty"
    MediaTypeException exception; // This variable is used to confirm Exception will happen
    try {
        MediaType mediaType3("", "text");
    } catch (MediaTypeException &e) {
        exception = e;
    }
    ASSERT_STR("`type` must not be empty", exception.getMessage().toString());

    // Constructor with subtype empty, expected Exception "`subtype` must not be empty"
    MediaTypeException exception1;
    try {
        MediaType mediaType3("text", "");
    } catch (MediaTypeException &e) {
        exception1 = e;
    }
    ASSERT_STR("`subtype` must not be empty", exception1.getMessage().toString());

    // Constructor with type MEDIA_WILDCARD_TYPE, subtype is not empty, Expected exception wrong type
    MediaTypeException exception2;
    try {
        MediaType mediaType3("*", "text");
    } catch (MediaTypeException &e) {
        exception2 = e;
    }
    ASSERT_STR("Wildcard type is legal only in '*/*' (all types)", exception2.getMessage().toString());
}

TEST(MediaType, IsWildcardSubtype) {
    // Default constructor, expected true
    MediaType mediaType;
    ASSERT_TRUE(mediaType.isWildcardSubtype());

    // Subtype card is "html", expected false
    MediaType mediaType1("text", "html");
    ASSERT_FALSE(mediaType1.isWildcardSubtype());

    // Subtype card is "plain", expected true
    HashMap<String, String> parameters;
    parameters.put("text", "plain");
    MediaType mediaType2("application", "json", parameters);
    ASSERT_FALSE(mediaType2.isWildcardSubtype());

    // Constructor with subtype is wildcard, expected true
    MediaType mediaType3("text", MediaType::MEDIA_TYPE_WILDCARD);
    ASSERT_TRUE(mediaType3.isWildcardSubtype());
}

TEST(MediaType, IsWildcardType) {

    // Default constructor, expected true
    MediaType mediaType;
    ASSERT_TRUE(mediaType.isWildcardType());

    // Constructor with type is "text", expected false
    MediaType mediaType1("text", "html");
    ASSERT_FALSE(mediaType1.isWildcardType());

    // Constructor with type is "application", expected false
    HashMap<String, String> parameters;
    parameters.put("text", "plain");
    MediaType mediaType2("application", "json", parameters);
    ASSERT_FALSE(mediaType2.isWildcardType());
}

TEST(MediaType, IsCompatible) {
    // Subtype is wildcard, other subtype is wildcard, expected true
    MediaType mediaType;
    MediaType mediaType1;
    ASSERT_TRUE(mediaType.isCompatible(mediaType1));

    // MediaType application/*+xml is compatible with application/atom+xml and vice versa, expected true
    MediaType mediaType2("application", "*+xml");
    MediaType mediaType3("application", "atom+xml");
    ASSERT_TRUE(mediaType2.isCompatible(mediaType3));
    ASSERT_TRUE(mediaType3.isCompatible(mediaType2));

    // MediaType application/* is not compatible with text/html, expected false
    MediaType mediaType4("application", "*");
    MediaType mediaType5("text", "html");
    ASSERT_FALSE(mediaType4.isCompatible(mediaType5));

    // MediaType */text is compatible with application/* and vice versa,  expected true
    MediaType mediaType6("application", "*+json");
    MediaType mediaType7("application", "*");
    ASSERT_TRUE(mediaType6.isCompatible(mediaType7));
    ASSERT_TRUE(mediaType7.isCompatible(mediaType6));
}

TEST(MediaType, ValueOf) {
    // MediaType valueOf "application/json", expected type "application", subtype "json"
    MediaType mediaType = MediaType::valueOf("application/json");
    ASSERT_STR("application", mediaType.getType().toString());
    ASSERT_STR("json", mediaType.getSubtype().toString());

    // MediaType valueOf "text/*", expected type "text", subtype "*+plain"
    MediaType mediaType1 = MediaType::valueOf("text/*+plain");
    ASSERT_STR("text", mediaType1.getType().toString());
    ASSERT_STR("*+plain", mediaType1.getSubtype().toString());

    // MediaType valueOf WILDCARD, expected both type and subtype are MEDIA_WILDCARD_TYPE
    MediaType mediaType3 = MediaType::valueOf(MediaType::WILDCARD);
    ASSERT_STR(MediaType::MEDIA_TYPE_WILDCARD.toString(), mediaType3.getType().toString());
    ASSERT_STR(MediaType::MEDIA_TYPE_WILDCARD.toString(), mediaType3.getSubtype().toString());

    // MediaType valueOf empty String, expected exception "`type` must not be empty"
    MediaTypeException exception;
    try {
        MediaType mediaType4 = MediaType::valueOf("");
    } catch (MediaTypeException &e) {
        exception = e;
    }
    ASSERT_STR("`type` must not be empty", exception.getMessage().toString());

    // MediaType valueOf "/", expected exception "/ does not contain subtype after '/'"
    MediaTypeException exception1;
    try {
        MediaType mediaType5 = MediaType::valueOf("/");
    } catch (MediaTypeException &e) {
       exception1 = e;
    }
    ASSERT_STR("/ does not contain subtype after '/'", exception1.getMessage().toString());

    // MediaType valueOf "text/", expected exception "/ does not contain subtype after '/'"
    MediaTypeException exception2;
    try {
        MediaType mediaType5 = MediaType::valueOf("text/");
    } catch (MediaTypeException &e) {
        exception2 = e;
    }
    ASSERT_STR("text/ does not contain subtype after '/'", exception2.getMessage().toString());

    // MediaType valueOf "*/html", expected exception wrong type
    MediaTypeException exception3;
    try {
        MediaType mediaType5 = MediaType::valueOf("*/html");
    } catch (MediaTypeException &e) {
        exception3 = e;
    }
    ASSERT_STR("*/html wildcard type is legal only in '*/*' (all types)", exception3.getMessage().toString());
}

TEST(MediaType, ToString) {

    // Default constructor, expected WILDCARD
    MediaType mediaType;
    mediaType.toString();
    ASSERT_STR(MediaType::WILDCARD.toString(), mediaType.toString());

    // Constructor with type "application", subtype "*+xml", expected "application/*+xml"
    MediaType mediaType2("application", "*+xml");
    ASSERT_STR(mediaType2.toString(), "application/*+xml");

    // Constructor with type "application", subtype "atom+xml", expected "application/atom+xml"
    MediaType mediaType3("application", "atom+xml");
    ASSERT_STR(MediaType::APPLICATION_ATOM_XML.toString(), mediaType3.toString());

    // Constructor with type "application", subtype MEDIA_WILDCARD_TYPE, expected "application/*"
    MediaType mediaType4("application", "*");
    ASSERT_STR("application/*", mediaType4.toString());

    // Constructor with type "text", subtype "html", expected "text/html"
    MediaType mediaType5("text", "html");
}
