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

#define TWILLIO_SERVICE_URL         "https://api.twilio.com/2010-04-01/Accounts/AC85ddd85dbdd4f002c799676b7ad28914/Messages.json"
#define TWILLIO_ACCOUNT_ID          "AC85ddd85dbdd4f002c799676b7ad28914"
#define TWILLIO_ACCOUNT_TOKEN       "87c76ffe015078c17e7080d19af46cae"
#define TWILLIO_FROM_PHONE_NUMBER   "15005550006"
#define TWILLIO_TO_PHONE_NUMBER     "84909015425"
#define TWILLIO_SMS_CONTENT         "HelloSms"

// Warning
// Because in send_sms we used is_empty to verify all parameters are NULL or empty string
// so when test cases go wrong in NULL value absolutely it will go wrong in empty string value
// See: int is_empty(char *target);
TEST(Vendor, TwilioCheckNULL) {

    // Initialize all parameters are NULL
    char *service_url       = NULL;
    char *account_id        = NULL;
    char *account_token     = NULL;
    char *from_phone_number = NULL;
    char *to_phone_number   = NULL;
    char *sms_content       = NULL;

    // Re-assign service_url with valid string but fail because account_id is still NULL
    service_url = "valid_string";
    ASSERT_FALSE(send_sms(service_url, account_id, account_token, from_phone_number, to_phone_number, sms_content));

    // Re-assign account_id with valid string but fail because account_token is still NULL
    account_id = "sample";
    ASSERT_FALSE(send_sms(service_url, account_id, account_token, from_phone_number, to_phone_number, sms_content));

    // Re-assign account_token with valid string but fail because from_phone_number is still NULL
    account_token = "sample";
    ASSERT_FALSE(send_sms(service_url, account_id, account_token, from_phone_number, to_phone_number, sms_content));

    // Re-assign from_phone_number with valid string but fail because to_phone_number is still NULL
    from_phone_number = "sample";
    ASSERT_FALSE(send_sms(service_url, account_id, account_token, from_phone_number, to_phone_number, sms_content));

    // Re-assign to_phone_number with valid string but fail because sms_content is NULL
    to_phone_number = "sample";
    ASSERT_FALSE(send_sms(service_url, account_id, account_token, from_phone_number, to_phone_number, sms_content));

    // Re-assign sms_content with valid string but fail because of validation does not check
    // We will check in next test case
    // See Vendor.TwilioCheckValidation
    sms_content = "sample";
    ASSERT_FALSE(send_sms(service_url, account_id, account_token, from_phone_number, to_phone_number, sms_content));
}

TEST(Vendor, TwilioCheckValidation) {

    // Initialize all variable with valid information
    char *service_url           = TWILLIO_SERVICE_URL;
    char *account_id            = TWILLIO_ACCOUNT_ID;
    char *account_token         = TWILLIO_ACCOUNT_TOKEN;
    char *from_phone_number     = TWILLIO_FROM_PHONE_NUMBER;
    char *to_phone_number       = TWILLIO_TO_PHONE_NUMBER;
    char *sms_content           = TWILLIO_SMS_CONTENT;

    // Fail because wrong url format
    char *invalid_service_url = "asdasdkasdkasd";
    ASSERT_FALSE(send_sms(invalid_service_url, account_id, account_token, from_phone_number, to_phone_number, sms_content));

    // Fail because wrong phone number format
    char *invalid_from_phone_number = "11111111111111111111111111111111111111";
    ASSERT_FALSE(send_sms(service_url, account_id, account_token, invalid_from_phone_number, to_phone_number, sms_content));

    // Fail because wrong phone number format
    char *invalid_to_phone_number = "--84 909 015 425";
    ASSERT_FALSE(send_sms(service_url, account_id, account_token, from_phone_number, invalid_to_phone_number, sms_content));

    // More wrong phone number format

    // Fail because sms content can not be empty
    char *invalid_sms_content = "";
    ASSERT_FALSE(send_sms(account_id, account_token, service_url, from_phone_number, to_phone_number, invalid_sms_content));
}

TEST(Vendor, TwilioCheckRequestToServer) {

    // Initialize all variable with valid information
    char *account_id        = TWILLIO_ACCOUNT_ID;
    char *account_token     = TWILLIO_ACCOUNT_TOKEN;
    char *service_url       = TWILLIO_SERVICE_URL;
    char *from_phone_number = TWILLIO_FROM_PHONE_NUMBER;
    char *to_phone_number   = TWILLIO_TO_PHONE_NUMBER;
    char *sms_content       = TWILLIO_SMS_CONTENT;

    // Test success cases
    ASSERT_TRUE(send_sms(service_url, account_id, account_token, from_phone_number, to_phone_number, sms_content));

    // Fail because from phone number is not exist
    char *from_phone_number_not_exist = "84000000000";
    ASSERT_FALSE(send_sms(service_url, account_id, account_token, from_phone_number_not_exist, to_phone_number, sms_content));

    // Can not check to phone number is not exist because Twilio does not validate phone number that's sent
}

