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

#define GRID_SERVICE_URL        "https://api.sendgrid.com/v3/mail/send"
#define GRID_SERVICE_TOKEN      "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"
#define GRID_SERVICE_MAIL_FROM  "sample_mail@sample.com"
#define GRID_SERVICE_MAIL_TO    "testmail@gmail.com"
#define GRID_SERVICE_SUBJECT    "Hello world"
#define GRID_SERVICE_CONTENT    "Say hi"

// Warning
// Because in send_mail we used is_empty to verify all parameters are NULL or empty string
// so when test cases go wrong in NULL value absolutely it will go wrong in empty string value
// See: int is_empty(char *target);
TEST(Vendor, SendGridCheckNULL) {
    // Initialize all parameters are NULL
    char *service_url   = NULL;
    char *service_token = NULL;
    char *mail_from     = NULL;
    char *mail_to       = NULL;
    char *mail_subject  = NULL;
    char *mail_content  = NULL;

    // Re-assign service_url with valid url but fail because service_token is still NULL
    service_url = "valid_url";
    ASSERT_FALSE(send_mail(service_url, service_token, mail_from, mail_to, mail_subject, mail_content));

    // Re-assign service_token with some string but fail because mail_from is still NULL
    service_token = "some_token";
    ASSERT_FALSE(send_mail(service_url, service_token, mail_from, mail_to, mail_subject, mail_content));

    // Re-assign mail_from with valid string but fail because mail_to is still NULL
    mail_from = "valid_email";
    ASSERT_FALSE(send_mail(service_url, service_token, mail_from, mail_to, mail_subject, mail_content));

    // Re-assign mail_to with valid string but fail because mail_subject is still NULL
    mail_to = "valid_email";
    ASSERT_FALSE(send_mail(service_url, service_token, mail_from, mail_to, mail_subject, mail_content));

    // Re-assign mail_subject with valid string but fail because mail_content is NULL
    mail_subject = "some_subject";
    ASSERT_FALSE(send_mail(service_url, service_token, mail_from, mail_to, mail_subject, mail_content));

    // Re-assign mail_content with valid string but fail because validation does not check
    // We will check in next test case
    // See Vendor.SendGridCheckValidation
    mail_content = "some_content";
    ASSERT_FALSE(send_sms(service_url, service_token, mail_from, mail_to, mail_subject, mail_content));

}

TEST(Vendor, SendGridCheckValidation) {
    // Initialize all variable with valid information
    char *service_url           = GRID_SERVICE_URL;
    char *service_token         = GRID_SERVICE_TOKEN;
    char *mail_from             = GRID_SERVICE_MAIL_FROM;
    char *mail_to               = GRID_SERVICE_MAIL_TO;
    char *mail_subject          = GRID_SERVICE_SUBJECT;
    char *mail_content          = GRID_SERVICE_CONTENT;

    // Fail because wrong url format
    char *invalid_service_url = "some_url_here_without_http";
    ASSERT_FALSE(send_mail(invalid_service_url, service_token, mail_from, mail_to, mail_subject, mail_content));

    // Fail because wrong phone number format
    char *invalid_mail_from_format = "some_email_without_domain";
    ASSERT_FALSE(send_mail(service_url, service_token, invalid_mail_from_format, mail_to, mail_subject, mail_content));

    // Fail because wrong phone number format
    char *invalid_mail_to_format = "123123123email";
    ASSERT_FALSE(send_mail(service_url, service_token, mail_from, invalid_mail_to_format, mail_subject, mail_content));

    // More wrong mail format

}

TEST(Vendor, SendGridCheckRequestToServer) {
    // Initialize all variable with valid information
    char *service_url           = GRID_SERVICE_URL;
    char *service_token         = GRID_SERVICE_TOKEN;
    char *mail_from             = GRID_SERVICE_MAIL_FROM;
    char *mail_to               = GRID_SERVICE_MAIL_TO;
    char *mail_subject          = GRID_SERVICE_SUBJECT;
    char *mail_content          = GRID_SERVICE_CONTENT;

    // Test success case
    ASSERT_TRUE(send_mail(service_url, service_token, mail_from, mail_to, mail_subject, mail_content));

    // Fail because wrong token
    char *wrong_token = "some_wrong_token";
    ASSERT_FALSE(send_mail(service_url, wrong_token, mail_from, mail_to, mail_subject, mail_content));

    //Fail because wrong service url
    char *wrong_service_url = "https://api.somewhereoninternet.com/v3/mail/send";
    ASSERT_FALSE(send_mail(wrong_service_url, service_token, mail_from, mail_to, mail_subject, mail_content));

}