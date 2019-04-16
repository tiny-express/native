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

#include "../../../Test.hpp"
#include "SimpleDateFormat.hpp"

using namespace Java::Lang;
using namespace Java::Text;

// SimpleDateFormat simpleDateFormat = "yyyy-MM-dd HH:mm:ss";
// FIX ME

TEST (JavaTextSimpleDateFormat, Constructor) {
    SimpleDateFormat simpleDateFormat = "%Y-%m-%d %H:%M:%S"; // GMT
    assertEquals("2019-04-15 12:09:15", simpleDateFormat.format(Date(1555330155000)));
}

TEST (JavaTextSimpleDateFormat, SetTimeZone) {
    SimpleDateFormat simpleDateFormat = "%Y-%m-%d %H:%M:%S"; // GMT
    simpleDateFormat.setTimeZone(TimeZone::getTimeZone("Asia/Ho_Chi_Minh")); // +07
    assertEquals("2019-04-15 19:09:15", simpleDateFormat.format(Date(1555330155000)));

    simpleDateFormat.setTimeZone(TimeZone::getTimeZone("Asia/Singapore")); // +08
    assertEquals("2019-04-15 20:09:15", simpleDateFormat.format(Date(1555330155000)));
}

