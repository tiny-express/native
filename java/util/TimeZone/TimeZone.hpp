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

#ifndef NATIVE_JAVA_UTIL_TIME_ZONE_HPP_
#define NATIVE_JAVA_UTIL_TIME_ZONE_HPP_

#include "../../Lang.hpp"
#include "../../Util.hpp"
#include "../Locale/Locale.hpp"
#include "../Date/Date.hpp"
#include "../../time/ZoneId/ZoneId.hpp"

using namespace Java::Lang;
using namespace Java::Time;

namespace Java {
    namespace Util {
        class TimeZone : public Serializable, public Cloneable {
        public:
            static const int SHORT = 0;
            static const int LONG = 1;

        private:
            static const int ONE_MINUTE = 60 * 1000;
            static const int ONE_HOUR = 60 * ONE_MINUTE;
            static const int ONE_DAY = 24 * ONE_HOUR;

        public:
            TimeZone();
            virtual ~TimeZone();

        public:
            static Array<String> getAvailableIDs();
            static Array<String> getAvailableIDs(int rawOffset);
            static TimeZone &getDefault();
            static TimeZone &getTimeZone(const String &id);
            static TimeZone &getTimeZone(const ZoneId &zoneId);
            static void setDefault(const TimeZone &zone);

        public:
            virtual String getDisplayName() const;
            virtual String getDisplayName(boolean dayLight, int style) const;
//          virtual String getDisplayName(boolean dayLight, int style, const Locale &locale) const;
//          virtual String getDisplayName(const Locale &locale) const;
            virtual int getDSTsavings() const;
            virtual String getID() const;
            virtual int getOffset(int era, int year, int month, int day, int dayOfWeek, int milliseconds) const = 0;
            virtual int getOffset(long date);
            virtual int getRawOffset() const = 0;
            virtual boolean hasSameRules(const TimeZone &other) const;
            virtual boolean inDaylightTime(const Date &date) const = 0;
            virtual boolean observesDaylightTime() const;
            virtual void setID(const String &id);
            virtual void setRawOffset(int offsetMillis) = 0;
            ZoneId &toZoneId() const;
            virtual boolean useDaylightTime() const = 0;
        };  // class TimeZone
    }  // namespace Util
}  // namespace Java

#endif  // NATIVE_JAVA_UTIL_TIME_ZONE_HPP_
