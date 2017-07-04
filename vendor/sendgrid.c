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
#include "../network/response_parser.h"

/**
 * Send mail via SendGrid service
 *
 * @param service_url
 * @param service_token
 * @param mail_from
 * @param mail_to
 * @param mail_subject
 * @param mail_content
 * @return TRUE | FALSE
 */
int send_mail(
	char *service_url,
	char *service_token,
	char *mail_from,
	char *mail_to,
	char *mail_subject,
	char *mail_content) {
	
	if (!is_email(mail_from)
	    || !is_email(mail_to)
	    || !is_url(service_url)
	    || is_empty(mail_subject)
	    || is_empty(mail_content)
	    || is_empty(service_token)) {
		return FALSE;
	}
	
	char *body[2];
	asprintf(&body[ 0 ], SENDGRID_REQUEST_FORMAT, mail_to, mail_subject, mail_from, mail_content);
	body[ 1 ] = '\0';

	char *auth_bearer_header = string_concat("Authorization: Bearer ", service_token);
	char *header[3] = {
		auth_bearer_header,
		"Content-Type: application/json",
		'\0'
	};
	
	char *response = http_request("POST", service_url, header, body);
    http_response *response_parser = parse(response);
    int result = string_to_int(response_parser->status_code);
    free(response);
    free_http_response(response_parser);
	free(auth_bearer_header);
	free(body[0]);
	return result == SENDGRID_RESPONSE_ACCEPTED;
}