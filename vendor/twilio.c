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

#include <stdlib.h>
#include "../vendor.h"
#include "../network.h"
#include "../string.h"
#include "../validator.h"
#include "../crypto.h"
#include "../common.h"
#include "../network/response_parser.h"

/**
 * Send mail via Twillio service
 *
 * @param account_id
 * @param account_token
 * @param url
 * @param from
 * @param to
 * @param content
 * @return TRUE | FALSE
 */
int send_sms(
	char *service_url,
	char *account_id,
	char *account_token,
	char *from_phone_number,
	char *to_phone_number,
	char *sms_content) {
	
	// NULL value or empty string can not be accepted
	if (is_empty(service_url)
	    || is_empty(account_id)
	    || is_empty(account_token)
	    || is_empty(from_phone_number)
	    || is_empty(to_phone_number)
	    || is_empty(sms_content)) {
		return FALSE;
	}
	
	// Check service url format
	if (!is_url(service_url)) {
		return FALSE;
	}
	
	// Check phone number
	if (!is_phone_number(from_phone_number) || !is_phone_number(to_phone_number)) {
		return FALSE;
	}
	
	char *username_password;
	asprintf(&username_password, "%s:%s", account_id, account_token);
    char *token = base64_encode((const unsigned char*) username_password, (size_t) length_pointer_char(username_password));
	char *standard_phone_number;
    char *phone_number_with_prefix;
    char *phone_number_sign = (string_index(from_phone_number, "+", 1) == STRING_NOT_FOUND)? "+" : "";
    asprintf(&phone_number_with_prefix, "%s%s", phone_number_sign, from_phone_number);
	// Remove all space from 'from phone number'
	standard_phone_number = string_replace(phone_number_with_prefix, " ", "");

	char *to_phone_number_with_prefix = to_phone_number;
	if (string_index(to_phone_number, "+", 1) == STRING_NOT_FOUND) {
		to_phone_number_with_prefix = string_concat("+", to_phone_number);
	}
	
	// Remove all spaces from 'to phone number'
	char *to_phone_number_with_prefix_no_space = string_replace(to_phone_number_with_prefix, " ", "");

    char *from_phone_number_with_prefix_encoded = url_encode(standard_phone_number);
    char *to_phone_number_with_prefix_encoded = url_encode(to_phone_number_with_prefix_no_space);
	char *url_content_encoded = url_encode(sms_content);
    char *body_string;
	asprintf(
		&body_string,
		"From=%s&To=%s&Body=%s",
        from_phone_number_with_prefix_encoded,
        to_phone_number_with_prefix_encoded,
		url_content_encoded
	);

	char *body[3] = {
		body_string,
		'\0'
	};

    char *auth_basic_header = string_concat("Authorization: Basic ", token);
	char *headers[3] = {
		"Content-Type: application/x-www-form-urlencoded",
		auth_basic_header,
		'\0'
	};
	
	char *response = http_request("POST", service_url, headers, body);
	http_response *response_parser = parse(response);

	int result = string_to_int(response_parser->status_code);

    free(phone_number_with_prefix);
    free(to_phone_number_with_prefix);
    free(username_password);
    free(token);
    free(auth_basic_header);
    free(body_string);
    free(standard_phone_number);
    free(to_phone_number_with_prefix_no_space);
    free(from_phone_number_with_prefix_encoded);
    free(to_phone_number_with_prefix_encoded);
    free(url_content_encoded);
    free(response);
	free_http_response(response_parser);
	return result == TWILIO_RESPONSE_CREATED;
}