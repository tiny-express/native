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

#include "../unit_test.h"
#include "../vendor.h"

char* account_id = "AC85ddd85dbdd4f002c799676b7ad28914";
char* from = "15005550006";
char* account_token = "87c76ffe015078c17e7080d19af46cae";
char* url = "https://api.twilio.com/2010-04-01/Accounts/AC85ddd85dbdd4f002c799676b7ad28914/Messages.json";

TEST(Vendor, Twilio) {
    char* to = "84909015425";
    char* content = "HelloSms";
    ASSERT_TRUE(send_sms(account_id, account_token, url, from, to, content));

    to = "84909015425";
    content = "Hello Sms";
    ASSERT_TRUE(send_sms(account_id, account_token, url, from, to, content));

    to = "84 909 015 425";
    content = "Hello Sms";
    ASSERT_FALSE(send_sms(account_id, account_token, url, from, to, content));

    to = "84909015425";
    content = "Hello Sms";
    ASSERT_TRUE(send_sms(account_id, account_token, url, from, to, content));

    to = "04909015425";
    content = "";
    ASSERT_FALSE(send_sms(account_id, account_token, url, from, to, content));

    to = NULL;
    content = "";
    ASSERT_FALSE(send_sms(account_id, account_token, url, from, to, content));

    to = "04909015425";
    content = NULL;
    ASSERT_FALSE(send_sms(account_id, account_token, url, from, to, content));
}