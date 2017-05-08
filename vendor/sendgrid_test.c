///**
// * Copyright (c) 2016 Food Tiny Project. All rights reserved.
// *
// * Redistribution and use in source and binary forms, with or without
// * modification, are permitted provided that the following conditions are met:
// *
// * Redistributions of source code must retain the above copyright
// * notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above
// * copyright notice, this list of conditions and the following disclaimer
// * in the documentation and/or other materials provided with the
// * distribution.
// *
// * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// */
//
//#include "../unit_test.h"
//#include "../vendor.h"
//
//char *from_mail = "sample_mail@sample.com";
//char *to_mail = "test@gmail.com";
//char *subject = "Sample";
//char *content = "hello world";
//char *service_url   = "https://api.sendgrid.com/v3/mail/send";
//char *service_token = "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";
//
//TEST(Vendor, SendGridCheckProcess) {
//    ASSERT_EQUAL(0, send_mail(from_mail, to_mail, subject, content, service_url, "wrong_token"));
//
//    ASSERT_EQUAL(1, send_mail(from_mail, to_mail, subject, content, service_url, service_token));
//}
//
//TEST(Vendor, SendGridCheckNULLFields) {
//    ASSERT_EQUAL(0, send_mail(NULL, to_mail, subject, content, service_url, service_token));
//
//    ASSERT_EQUAL(0, send_mail(from_mail, NULL, subject, content, service_url, service_token));
//
//    ASSERT_EQUAL(0, send_mail(from_mail, to_mail, NULL, content, service_url, service_token));
//
//    ASSERT_EQUAL(0, send_mail(from_mail, to_mail, subject, NULL, service_url, service_token));
//
//    ASSERT_EQUAL(0, send_mail(from_mail, to_mail, subject, content, NULL, service_token));
//
//    ASSERT_EQUAL(0, send_mail(from_mail, to_mail, subject, content, service_url, NULL));
//}
//
//TEST(Vendor, SendGridCheckEmptyFields) {
//    ASSERT_EQUAL(0, send_mail("", to_mail, subject, content, service_url, service_token));
//
//    ASSERT_EQUAL(0, send_mail(from_mail, "", subject, content, service_url, service_token));
//
//    ASSERT_EQUAL(0, send_mail(from_mail, to_mail, "", content, service_url, service_token));
//
//    ASSERT_EQUAL(0, send_mail(from_mail, to_mail, subject, "", service_url, service_token));
//
//    ASSERT_EQUAL(0, send_mail(from_mail, to_mail, subject, content, "", service_token));
//
//    ASSERT_EQUAL(0, send_mail(from_mail, to_mail, subject, content, service_url, ""));
//}
//
//TEST(Vendor, SendGridCheckWrongFormat) {
//    ASSERT_EQUAL(0, send_mail("wrong_mail_format", to_mail, subject, content, service_url, service_token));
//
//    ASSERT_EQUAL(0, send_mail(from_mail, "wrong_mail_format", subject, content, "", service_token));
//
//    ASSERT_EQUAL(0, send_mail(from_mail, to_mail, subject, content, "wrong_url_format", service_token));
//}