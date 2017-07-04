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

#include <openssl/ssl.h>
#include <openssl/err.h>
#include "../common.h"
#include "../string.h"
#include "../network.h"
#include "../validator.h"
#include "../type.h"

/**
 * Retrieve url schema
 *
 * @param url
 * @return string (https or http)
 */

char *http_schema(char *url) {
	
	if (!is_url(url)) {
		return strdup("");
	}
	
	if (string_startswith(url, HTTPS)) {
		return strdup(HTTPS);
	}
	
	return strdup(HTTP);
}

/**
 * Retrieve url schema
 *
 * @param url
 * @return string (hostname)
 */

char *http_hostname(char *url) {
	
	if (is_url(url) == 0) {
		return strdup("");
	}
	
	if (string_index(url, "127.0.0.1", 1) != -1) {
		return strdup(LOCALHOST);
	}
	
	int length_url = length_pointer_char(url);
	int begin_position = string_index(url, "://", 1) + 3;
	int end_position = length_url;
	
	// Find end position to cut, if meet ':', '?' or '/'
	register int index;
	for (index = begin_position; index < length_url; index++) {
		if (url[ index ] == ':' || url[ index ] == '/' || url[ index ] == '?') {
			end_position = index;
			break;
		}
	}
	
	char *result = string_from_to(url, begin_position, end_position - 1);
	result[ end_position - begin_position ] = '\0';
	return result;
}

/**
 * Retrieve url schema
 *
 * @param url
 * @return int
 */
int http_port(char *url) {
	
	char *schema = http_schema(url);
	
	if (strcmp(schema, "") == 0) {
		free(schema);
		return -1;
	}
	
	int url_length = length_pointer_char(url);
	int prefix_position = string_index(url, "://", 1);
	char *url_without_prefix = string_from_to(url, prefix_position + 3, url_length);
	int url_without_prefix_length = length_pointer_char(url_without_prefix);
	int port_index_begin = string_index(url_without_prefix, ":", 1) + 1;
	int port_index_end = string_index(url_without_prefix, "/", 1) - 1;
	if (port_index_end < 0) {
		port_index_end = url_without_prefix_length - 1;
	}
	char *port_string = string_from_to(url_without_prefix, port_index_begin, port_index_end);
	free(url_without_prefix);
	int port = string_to_int(port_string);
	free(port_string);
	if (port == 0) {
		if (strcmp(schema, HTTPS) == 0) {
			free(schema);
			return HTTPS_PORT;
		}
		free(schema);
		return HTTP_PORT;
	}
	free(schema);
	return port;
}

/**
 * Get query from url
 * Example: http://localhost/index?key1=value1&key2=value2
 * Query will be 'key1=value1&key2=value2'
 * @param url
 * @return string
 */
char *http_query(char *url) {
	
	if (!is_url(url)) {
		return strdup("");
	}
	
	int length_url = length_pointer_char(url);
	int begin_position = string_index(url, "?", 1) + 1;
	
	if (begin_position == 0) {
		return strdup("");
	}
	
	int end_position = begin_position;
	
	for (end_position; end_position < length_url; end_position++) {
		if (url[ end_position ] == '/' || url[ end_position ] == ':') {
			break;
		}
	}
	
	char *result = string_from_to(url, begin_position, end_position - 1);
	return result;
}

/**
 * return path of URL if path doesn't exit return "/"
 * @param url
 * @return string path
 */
char *http_path(char *url) {
	int is_url_result = is_url(url);
	if (is_url_result == 0) {
		return strdup("");
	}
	int len_url = length_pointer_char(url);
	int begin_pos = string_index(url, "/", 3);
	if (begin_pos == -1) {
		return strdup("/");
	}
	int end_pos = len_url;
	int index;
	for (index = begin_pos; index < len_url; index++) {
		if (url[ index ] == ':' || url[ index ] == '?') {
			end_pos = index;
			break;
		}
	}

	char *result = string_from_to(url, begin_pos, end_pos - 1);
	return result;
}

/**
 * get protocol of url
 * @param url
 * @return HTTP or HTTPS
 */
char *http_protocol(char *url) {
	char *schema = http_schema(url);
	if (strcmp(schema, "") == 0) {
		free(schema);
		return strdup("");
	}
	int length_schema = length_pointer_char(schema);
	char *protocol = string_from_to(schema, 0, length_schema - 4); // remove "://"
	free(schema);
	return protocol;
}

int url_port(char *url) {
	char *path = http_path(url);
	int path_index = string_index(url, path, 1);
	char *domain = url;
	int port = http_port(url);
	if (port == -1) {
		free(path);
		return -1;
	}
	int isDynamic = FALSE;
	if (strcmp(path, "/") != 0) {
		domain = string_from_to(domain, 0, path_index - 1);
		isDynamic = TRUE;
	}

	char *port_string;
	asprintf(&port_string, ":%d", port);
	if (string_index(domain, port_string, 1) == -1) {
		if (isDynamic) {
			free(domain);
		}
		free(path);
		free(port_string);
		return -1;
	}
	if (isDynamic) {
		free(domain);
	}

	free(port_string);
	free(path);
	return port;
}

/**
 * Send request to server with data in request body
 * This function can be used in general case with all requests
 *
 * @method GET POST PUT PATCH DELETE HEAD OPTIONS
 * @return string
 */
char *http_request(char *method, char *url, char **headers, char **body) {
	// Parse URL
	int port = http_port(url);
	char *host_no_port = http_hostname(url);
	char *port_string = string_from_int(port);
	char *host;
	asprintf(&host, "%s:%s", host_no_port, port_string);
	free(host_no_port);
	free(port_string);
	char *path = http_path(url);
	char *schema = http_schema(url);
	int is_https = strcmp(schema, HTTPS) ? 0 : 1;
	free(schema);
	int is_get_method = strcmp(method, "GET") ? 0 : 1;
	
	// Prepare request message
	char *template = "%s %s%s%s HTTP/1.1\r\n"
		"Connection: close\r\n"
		"Host: %s\r\n"
		"%s\r\n\r\n"
		"%s";
	char *header_content = string_join(headers, "\r\n");
	char *body_string = string_join(body, "&");
	if (!is_get_method) {
		int body_size = length_pointer_char(body_string);
		char *header_post;
		asprintf(&header_post, "%s%sContent-Length: %d", header_content, length_pointer_char(header_content) > 0 ? "\r\n" : "", body_size);
		free(header_content);
		header_content = header_post;
	}
	
	char *request;
	if (is_get_method) {
		asprintf(&request, template,
		         method,
		         path,
		         length_pointer_char(body_string) > 0 ? "?" : "",
		         body_string,
		         host,
		         header_content,
		         "");
	} else {
		asprintf(&request, template,
		         method,
		         path,
		         "",
		         "",
		         host,
		         header_content,
		         body_string);
	}
	free(path);
	free(body_string);
	free(header_content);
	
	BIO *bio;
	SSL *ssl;
	SSL_CTX *ctx;
	int received = 0;
	
	if (is_https) {
		SSL_library_init();
	}
	
	ERR_load_BIO_strings();
	SSL_load_error_strings();
	OpenSSL_add_all_algorithms();
	
	if (is_https) {
		const SSL_METHOD *method = TLSv1_2_client_method();        /* SSLv3 but can rollback to v2 */
		if (!method) {
			fprintf(stderr, "SSL client method failed\n");
			return strdup("");
		}
		
		ctx = SSL_CTX_new(method);
		if (!ctx) {
			fprintf(stderr, "SSL context is NULL\n");
			ERR_print_errors_fp(stderr);
			return strdup("");
		}
		
		/* Setup the connection */
		bio = BIO_new_ssl_connect(ctx);
		
		/* Set the SSL_MODE_AUTO_RETRY flag */
		BIO_get_ssl(bio, &ssl);
		SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);
		
		/* Create and setup the connection */
		BIO_set_conn_hostname(bio, host);
		
		if (BIO_do_connect(bio) <= 0) {
			fprintf(stderr, "Error attempting to connect\n");
			ERR_print_errors_fp(stderr);
			printf("%s\n", ERR_error_string(ERR_get_error(), NULL));
			BIO_free_all(bio);
			SSL_CTX_free(ctx);
			free(host);
			return strdup("");
		}
	} else {
		bio = BIO_new_connect(host);
		if (bio == NULL) {
			fprintf(stderr, "BIO is null\n");
			free(host);
			return strdup("");
		}
		
		if (BIO_do_connect(bio) <= 0) {
			fprintf(stderr, "Error attempting to connect\n");
			ERR_print_errors_fp(stderr);
			BIO_free_all(bio);
			free(host);
			return strdup("");
		}
	}
	free(host);
	/* Send the request */
	BIO_write(bio, request, length_pointer_char(request));
	
	/* Read in the response */
	char *response = calloc(100000, sizeof(char));
	int bytes;
	for (;;) {
		bytes = BIO_read(bio, response + received, 1023);
		if (bytes < 0) {
			printf("ERROR received");
			free(response);
			return strdup("");
		}
		if (bytes == 0) {
			break;
		}
		received += bytes;
	}
	/* Close the connection and free the context */
	BIO_free_all(bio);
	if (is_https) {
		SSL_CTX_free(ctx);
	}
	free(request);
	return response;
}
