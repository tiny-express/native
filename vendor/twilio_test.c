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

TEST(Vendor, TwilioCheckNULL) {
    // Initialize all parameters are NULL
    char *account_id = NULL;
    char *account_token = NULL;
    char *service_url = NULL;
    char *phone_number_from = NULL;
    char *phone_number_to = NULL;
    char *sms_content = NULL;

    // Fail because account_id is NULL
    ASSERT_FALSE(send_sms(account_id, account_token, service_url, phone_number_from, phone_number_to, sms_content));

    // Re-assign account_id with valid string but fail because account_token is NULL
    account_id = "sample";
    ASSERT_FALSE(send_sms(account_id, account_token, service_url, phone_number_from, phone_number_to, sms_content));

    // Re-assign account_token with valid string but fail because service_url is NULL
    account_token = "sample";
    ASSERT_FALSE(send_sms(account_id, account_token, service_url, phone_number_from, phone_number_to, sms_content));

    // Re-assign service_url with valid string but fail because phone_number_from is NULL
    service_url = "sample";
    ASSERT_FALSE(send_sms(account_id, account_token, service_url, phone_number_from, phone_number_to, sms_content));

    // Re-assign phone_number_from with valid string but fail because phone_number_to is NULL
    phone_number_from = "sample";
    ASSERT_FALSE(send_sms(account_id, account_token, service_url, phone_number_from, phone_number_to, sms_content));

    // Re-assign phone_number_to with valid string but fail because sms_content is NULL
    phone_number_to = "sample";
    ASSERT_FALSE(send_sms(account_id, account_token, service_url, phone_number_from, phone_number_to, sms_content));

    // All things are correct at the end
}

TEST(Vendor, TwilioSendSMS) {

    // Initialize all variable with valid information
    char* account_id = "AC85ddd85dbdd4f002c799676b7ad28914";
    char* account_token = "87c76ffe015078c17e7080d19af46cae";
    char* service_url = "https://api.twilio.com/2010-04-01/Accounts/AC85ddd85dbdd4f002c799676b7ad28914/Messages.json";
    char* phone_number_from = "15005550006";
    char* phone_number_to = "84909015425";
    char* sms_content = "HelloSms";

    // Test fail cases
    char *invalid_url = "asdasdkasdkasd";
    ASSERT_FALSE(send_sms(account_id, account_token, invalid_url, phone_number_from, phone_number_to, sms_content));

    char *invalid_from_phone_number = "111111111111";
    ASSERT_FALSE(send_sms(account_id, account_token, service_url, invalid_from_phone_number, phone_number_to, sms_content));

    char *invalid_to_phone_number = "84 909 015 425";
    ASSERT_FALSE(send_sms(account_id, account_token, service_url, phone_number_from, invalid_to_phone_number, sms_content));

    char *invalid_sms_content = "";
    ASSERT_FALSE(send_sms(account_id, account_token, service_url, phone_number_from, phone_number_to, invalid_sms_content));

    // Test success cases
    ASSERT_TRUE(send_sms(account_id, account_token, service_url, phone_number_from, phone_number_to, sms_content));

    phone_number_to = "84909015425";
    sms_content = "Hello Sms";
    ASSERT_TRUE(send_sms(account_id, account_token, service_url, phone_number_from, phone_number_to, sms_content));
}

