/**
 * Copyright 2017 Tiny Express Project. All rights reserved.
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

#include "SimpleDateFormat.hpp"

using namespace Java::Text;

SimpleDateFormat::SimpleDateFormat(const_string datePattern) {
    this->datePattern = datePattern;
}

SimpleDateFormat::SimpleDateFormat(const String &datePattern) {
    this->datePattern = datePattern;
}

void SimpleDateFormat::setTimeZone(const TimeZone &timeZone) {
    this->timeZone = timeZone;
}

String SimpleDateFormat::format(const Date &date) {
    String tz = String("TZ=") + this->timeZone.getID();
    putenv(tz.toCharPointer());

    std::time_t current_time;
    std::time(&current_time);
    struct std::tm *timeinfo = std::localtime(&current_time);
    long offset = timeinfo->tm_gmtoff;

    size_t bufferLength = 80;
    string buffer = (string) calloc(bufferLength, sizeof(char));
    time_t timestamp = (time_t) ((date.getTime() / 1000) + offset);
    std::strftime(buffer, bufferLength, this->datePattern.toCharPointer(), std::gmtime(&timestamp));
    String formattedDate = buffer;
    free(buffer);
    return formattedDate.trim();
}