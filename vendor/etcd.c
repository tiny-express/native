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
#include "../common.h"
#include "../vendor.h"
#include "../builtin.h"
#include "../network/response_parser.h"

/**
 * ETCD Get
 * @param host
 * @param key
 * @return json
 */
char *etcd_get(char *url, char *key) {
	if (is_empty(url) ||
		is_email(key)) {
		return strdup("");
	}
	
	char *connection_url;
	asprintf(&connection_url, "%s%s%s", url, ETCD_PATH, key);
	char *headers[2] = { "\0" };
	char *body[2] = { "\0" };
	char *response = http_request("GET", connection_url, headers, body);
	http_response *response_parser = parse(response);
	free(connection_url);
	free(response);
    if (string_to_int(response_parser->status_code) != 200) {
        free_http_response(response_parser);
        return strdup("");
    }
	JSON_Value *root_value = json_parse_string(response_parser->body);
	JSON_Object *root_object = json_value_get_object(root_value);
	JSON_Object *node_object = json_object_get_object(root_object, NODE);
	char *value_result = strdup((char*) json_object_get_string(node_object, VALUE));
	json_value_free(root_value);
    free_http_response(response_parser);
	return value_result;
}

/**
 * Etcd Set
 * @param host
 * @param key
 * @param value
 * @return json
 */
int etcd_set(char *url, char *key, char *value) {
	
	if (!is_url(url) || is_empty(key) || is_empty(value)) {
		return FALSE;
	}
	
	char *path_to_key = string_concat(ETCD_PATH, key);
	char *connection_url;
	char *url_splash = string_index(url, "/", 1) < 0 ? "/" : "";
	asprintf(&connection_url, "%s%s%s", url, url_splash, path_to_key);
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
	
	char *response = http_request("PUT", connection_url, header, body);
	int response_body_begin_index = string_index(response, "{", 1);
	int response_length = length_pointer_char(response);
	char *result = string_from_to(
		response,
		response_body_begin_index,
		response_length - 1);
	
	free(path_to_key);
	free(body_message);
	free(connection_url);
	free(response);
	
	if (is_empty(result)) {
		free(result);
		return FALSE;
	}
	JSON_Value *root_value = json_parse_string(result);
	JSON_Object *root_object = json_value_get_object(root_value);
	JSON_Object *node_object = json_object_get_object(root_object, NODE);
	string value_result = (string) json_object_get_string(node_object, VALUE);
	string key_result = (string) json_object_get_string(node_object, KEY);
	int return_value = !( strcmp(value_result, value) != 0 || strcmp(key_result, key) != 0 );
	
	free(result);
	json_value_free(root_value);
	
	return return_value;
}
