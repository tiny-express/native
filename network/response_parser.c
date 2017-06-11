
#include <stdlib.h>
#include "response_parser.h"
#include "../string.h"
#include "../builtin.h"

/**
 * parse uri: method(GET, POST, PUT, PATCH ..), path and HTTP version
 * @param response
 * @param result
 * @return index of header start in response
 */
int parse_uri(char *response, http_response *result);

/**
 * parse header
 * @reference how to use flexible memory: https://stackoverflow.com/questions/17344745/how-to-use-flexible-array-in-c-to-keep-several-values
 * @param response
 * @param result
 * @param index
 * @return index of body start in response
 */
int parse_header(char *response, http_response *result, int index);

/**
 * free memory of a pointer
 * @param pointer
 */
void get_free(void **pointer);

/**
 * parse http response to
 * @param response
 * @return http response
 */
http_response *parse(char *response) {
	http_response *result = malloc(sizeof(http_response) + 4 * sizeof(char *));
	int header_index = parse_uri(response, result);
	int body_index = parse_header(response, result, header_index);
	result->body = string_from_to(response, body_index, length_pointer_char(response) - 1);
	return result;
}

int parse_uri(char *response, http_response *result) {
	register int scan_index = 0;
	register int mark_index = 0;
	register int count = 0;
	while (response[ scan_index ] != '\n' && response[ scan_index ] != '\0') {
		if (response[ scan_index ] == ' ') {
			count++;
			if (count == 1) {
				result->version = string_from_to(response, mark_index, scan_index - 1);
				mark_index = scan_index + 1;
			} else if (count == 2) {
				result->status_code = string_from_to(response, mark_index, scan_index - 1);
				mark_index = scan_index + 1;
			}
		}
		scan_index++;
	}
	result->status = string_from_to(response, mark_index, scan_index - 1);
	while (response[ scan_index ] == '\n' || response[ scan_index ] == '\r') {
		scan_index++;
	}
	return scan_index;
}

int parse_header(char *response, http_response *result, int index) {
	result->header_quantity = 0;
	register int scan_index = index;
	register int mark_index = scan_index;
	while (response[ scan_index - 1 ] != '\n' || response[ scan_index ] != '\n') {
		if (response[ scan_index ] == ':' && response[ scan_index + 1 ] == ' ') {
			result->headers[ result->header_quantity ] = malloc(sizeof(header));
			char *header_name = string_from_to(response, mark_index, scan_index - 1);
			result->headers[ result->header_quantity ]->name = header_name;
			scan_index++;
			mark_index = scan_index + 1;
		} else if (response[ scan_index ] == '\n') {
			char *header_value = string_from_to(response, mark_index, scan_index - 1);
			result->headers[ result->header_quantity ]->value = header_value;
			mark_index = scan_index + 1;
			result->header_quantity++;
		}
		scan_index++;
	}
	while (response[ scan_index ] == '\n' || response[ scan_index ] == '\r') {
		scan_index++;
	}
	return scan_index;
}

void free_http_response(http_response *response) {
	register int index;
	for (index = 0; index < response->header_quantity; index++) {
		free(response->headers[ index ]->name);
		free(response->headers[ index ]->value);
		free(response->headers[ index ]);
	}
	free(response->headers);
	free(response->status_code);
	free(response->status);
	free(response->version);
	free(response->body);
	free(response);
}
