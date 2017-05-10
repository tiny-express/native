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

#include "../network.h"
#include "../string.h"
#include "../general.h"
#include "../vendor.h"

/**
 * Etcd Get
 * @param host
 * @param key
 * @return json
 */
char *etcd_get(char* url, char *key) {

    if (length_pointer_char(url) == 0 ||
        length_pointer_char(key) == 0) {
        return "";
    }

    char* connection_url = string_concat("", url);
    connection_url = string_concat(connection_url, "/v2/keys");
    connection_url = string_concat(connection_url, key);
    char *headers[2] = {"\0"};
    char *body[2] = {"\0"};
    char* response = http_request("GET", connection_url, headers, body);
    int response_body_begin_index = string_index(response, "{", 1);
    int response_length = length_pointer_char(response);
    char* result = string_from_to(response, response_body_begin_index, response_length - 2);
    return result;
}

/**
 * Etcd Set
 * @param host
 * @param key
 * @param value
 * @return json
 */
char *etcd_set(char *url, char *key, char *value) {

    if (length_pointer_char(url) == 0 ||
        length_pointer_char(key) == 0 ||
        length_pointer_char(value) == 0) {
        return "";
    }

    key = string_concat("/v2/keys", key);
    if (string_index(key, "/", 1) >= 0) {
        url = string_concat(url, key);
    } else {
        url = string_concat(url, "/");
        url = string_concat(url, key);
    }

    char *header[2] = {
            "Content-Type: application/x-www-form-urlencoded",
            '\0'
    };

    char *body_message = "value=";
    body_message = string_concat(body_message, value);
    char *body[2] = {
            body_message,
            '\0'
    };

    char* response = http_request("PUT", url, header, body);
    int response_body_begin_index = string_index(response, "{", 1);
    int response_length = length_pointer_char(response);
    char* result = string_from_to(
            response,
            response_body_begin_index,
            response_length - 2);

    return result;
}
