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

#include <stdio.h>
#include "../string.h"
#include "../network.h"
#include "../validator.h"
#include "../type.h"
#include "../common.h"
#include "../vendor.h"

/**
 * Push Notification via Google FireBase service
 *
 * @param service_url
 * @param service_token
 * @param device_token
 * @param notification_title
 * @param notification_body
 * @return TRUE | FALSE
 */
int push_notification(
    char *service_url,
    char *service_token,
    char *device_token,
    char *notification_title,
    char *notification_body,
    char *notification_data) {

    // NULL value or empty string can not be accepted
    if (is_empty(service_token)
            || is_empty(device_token)
                || is_empty(notification_title)
                    || is_empty(notification_body)) {
        return FALSE;
    }

    // Check validation
    if (!is_url(service_url)) {
        return FALSE;
    }

    if (notification_data == NULL) {
        notification_data = "";
    }

    char *request_body[2];
    asprintf(&request_body[0], FIREBASE_REQUEST_FORMAT, device_token, notification_title, notification_body, notification_data);
    request_body[1] = '\0';

    char *request_header[3] = {
        string_concat("Authorization: key=", service_token),
        "Content-Type: application/json",
        '\0'
    };

    char* response = http_request("POST", service_url, request_header, request_body);
    if (is_empty(response)) {
        return FALSE;
    }

    // Firebase reponse has format
    // {"success": 1}
    // So we need to parse this response to get the success value
    // TODO: @dquang replace by http_parser
    response = string_from_to(
            response,
            string_index(response, "{", 1),
            length_pointer_char(response) - 1
    );
    JSON_Value *root_value = json_parse_string(response);
    JSON_Object *root_object = json_value_get_object(root_value);
    int status_value = (int) json_object_get_number(root_object, SUCCESS_LABEL);
    if (status_value == SUCCESS_VALUE) {
        return TRUE;
    }

    return FALSE;
}