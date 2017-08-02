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
//     subtype is wildcard, other subtype is wildcard, expected true
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
    MediaType mediaType6(MediaType::MEDIA_TYPE_WILDCARD, "text");
    MediaType mediaType7("application", MediaType::MEDIA_TYPE_WILDCARD);
    ASSERT_TRUE(mediaType6.isCompatible(mediaType7));
    ASSERT_TRUE(mediaType7.isCompatible(mediaType6));


}
