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
#include "../builtin.h"

#define JSON_FORMAT \
                "{\"to\":\"%s\","\
                    "\"notification\":{" \
                        "\"title\":\"%s\"," \
                        "\"body\":\"%s\"" \
                    "},\"priority\":10, \"data\":{\"%s\"}"
#define SUCCESS "success"
#define SUCCESS_CHARACTER '1'

int send_notification(char *service_url,
                      char* service_token,
                      char* device_token,
                      char* title,
                      char* body,
                      char* data) {

    if (!is_url(service_url)
            || is_empty(service_token)
            || is_empty(device_token)
            || is_empty(title)
            || is_empty(body)) {
        return FALSE;
    }

    if (data == NULL) {
        data = "";
    }

    char *request_body[2];
    asprintf(&request_body[0], JSON_FORMAT, device_token, title, body, data);
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

    int success_index = string_index(response, SUCCESS, 1) + length_pointer_char(SUCCESS) + 2;
    if (response[success_index] == SUCCESS_CHARACTER) {
        return TRUE;
    }
    return FALSE;
}