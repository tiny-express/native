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

#ifndef NATIVE_JAVA_TIME_ZONE_ID_HPP_
#define NATIVE_JAVA_TIME_ZONE_ID_HPP_

#include "../../Lang.hpp"
#include "../../util/Map/Map.hpp"

namespace Java {
    namespace Time {
        class ZoneId : public Serializable {
        public:
            static const Map<String, String> SHORT_IDS;

        public:
//          static ZoneId from(const TemporalAccessor &temporal);
//          static Set<String> 	getAvailableZoneIds();
            static ZoneId &of(const String &zoneId);
            static ZoneId &of(const String &zoneId, const Map<String,String> &aliasMap);
//          static ZoneId &ofOffset(const String &prefix, const ZoneOffset &offset);
            static ZoneId &systemDefault();
        public:
            virtual boolean equals(const Object &target) const;
            virtual String getID() const = 0;
//          virtual ZoneRules getRules() const = 0;
            virtual long hashCode() const;
            ZoneId &normalized();
            string toString() const;
        };  // class ZoneId
    }  // namespace Time
}  // namespace Java

#endif  // NATIVE_JAVA_TIME_ZONE_ID_HPP_
