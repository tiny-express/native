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

#ifndef NATIVE_JAVA_UTIL_SIMPLE_TIME_ZONE_HPP_
#define NATIVE_JAVA_UTIL_SIMPLE_TIME_ZONE_HPP_

#include "../../Lang.hpp"
#include "../TimeZone/TimeZone.hpp"
#include "../Date/Date.hpp"

using namespace Java::Lang;

namespace Java {
    namespace Util {
        class SimpleTimeZone : public TimeZone {
        public:
            SimpleTimeZone(int rawOffset, const String &ID);
            SimpleTimeZone(int rawOffset, const String &ID,
                           int startMonth, int startDay, int startDayOfWeek, int startTime,
                           int endMonth, int endDay, int endDayOfWeek, int endTime);
            SimpleTimeZone(int rawOffset, const String &ID,
                           int startMonth, int startDay, int startDayOfWeek, int startTime,
                           int endMonth, int endDay, int endDayOfWeek, int endTime,
                           int dstSavings);
            SimpleTimeZone(int rawOffset, const String &ID,
                           int startMonth, int startDay, int startDayOfWeek, int startTime,
                           int startTimeMode,
                           int endMonth, int endDay, int endDayOfWeek, int endTime,
                           int endTimeMode,
                           int dstSavings);
            virtual ~SimpleTimeZone();

        public:
            SimpleTimeZone clone();
            boolean equals(const Object &object) const;
            int getDSTSavings() const;
            int getOffset(int era, int year, int month, int day, int dayOfWeek, int millis) const;
            int getOffset(long date);
            int getRawOffset() const;
            long hashCode() const;
            boolean hasSameRules(const TimeZone &other) const;
            boolean inDaylightTime(const Date &date) const;
            boolean observesDaylightTime() const;
            void setDSTSavings(int millisSavedDuringDST);
            void setEndRule(int endMonth, int endDay, int endTime);
            void setEndRule(int endMonth, int endDay, int endDayOfWeek, int endTime);
            void setEndRule(int endMonth, int endDay, int endDayOfWeek, int endTime, boolean after);
            void setRawOffset(int offsetMillis);
            void setStartRule(int startMonth, int startDay, int startTime);
            void setStartRule(int startMonth, int startDay, int startDayOfWeek, int startTime);
            void setStartRule(int startMonth, int startDay, int startDayOfWeek, int startTime, boolean after);
            void setStartYear(int year);
            string toString() const;
            boolean useDaylightTime() const;
        };  // class SimpleTimeZone
    }  // namespace Util
}  // namespace Java

#endif  // NATIVE_JAVA_UTIL_SIMPLE_TIME_ZONE_HPP_
