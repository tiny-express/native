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

#define FIREBASE_SERVICE_URL "https://fcm.googleapis.com/fcm/send"
#define FIREBASE_SERVICE_TOKEN "AAAARs12iRs:APA91bGcaUlACTb6VdvjeUNmeQ-I3Tsr14p8Q20-egTAFu3zq2juaRYyVDSNohBjRKutx4bqpoY8BM8BxolEILw6A1A-YfBecDCzhBIDoQTwwPNADOmhulj-8NTbRIobK28EwOfZnMQd"
#define FIREBASE_DEVICE_TOKEN "dqs-1BBsWEE:APA91bHs7ixQativdjcIJ_3DRNWceVH8fLIriF9shRFoauodG9VXpG4D86VzAmJakgcu7mrYaQmZEwvKC124uiRUABPaBv0zrjftI9CuhoOfxOKVPBR1qSHRtQmbynsECRv6I2Y_XLQ0"

// Warning
// Because in send_notification we used is_empty to verify all parameters are NULL or empty string
// so when test cases go wrong in NULL value absolutely it will go wrong in empty string value
// See: int is_empty(char *target);

TEST(Vendor, FirebaseCheckNULL) {

}

TEST(Vendor, FirebaseCheckValidation) {

}

TEST(Vendor, FirebaseCheckRequestToServer) {
    char* service_url = FIREBASE_SERVICE_URL;
    char* service_token = FIREBASE_SERVICE_TOKEN;
    char* device_token = FIREBASE_DEVICE_TOKEN;
    char* title = "Hello";
    char* body = "Test notification";
    char* data = "[{test:test},{test:test2}]";
    ASSERT_TRUE(push_notification(service_url, service_token, device_token, title, body, data));
}

