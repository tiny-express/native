
#include <stdlib.h>
#include "response_parser.h"
#include "../string.h"
#include "../builtin.h"

int count_header(char* response);

/**
 * parse uri: method(GET, POST, PUT, PATCH ..), path and HTTP version
 * @param response
 * @param result
 * @return index of header start in response
 */
int parse_uri(char *line, http_response *result);

/**
 * parse header
 * @reference how to use flexible memory: https://stackoverflow.com/questions/17344745/how-to-use-flexible-array-in-c-to-keep-several-values
 * @param response
 * @param result
 * @param index
 * @return index of body start in response
 */
int parse_header(char *line, http_response *result, int index);

/**
 * parse http response to
 * @param response
 * @return http response
 */
http_response *parse(char *response) {
    char** response_split = string_split(response, "\r\n");
    int response_split_length = length_pointer_pointer_char(response_split);
    http_response *result = malloc(sizeof(http_response) + 4 * sizeof(char *));
    result->header_quantity = count_header(response);
    if (response_split_length < 2) {
        free_pointer_pointer_char(response_split);
        return result;
    }

    if (result->header_quantity == 0 || !parse_uri(response_split[0], result)) {
        return result;
    }
    register int index;
    for (index = 0; index < result->header_quantity; index ++) {
        if (!parse_header(response_split[index + 1], result, index)) {
            return result;
        }
    }

    result->body = strdup("");
    if (result->header_quantity + 1 < response_split_length) {
        char* pointer_holder;
        free(result->body);
        result->body = strdup(response_split[result->header_quantity + 1]);
        for (index = result->header_quantity + 2; index < response_split_length; index ++) {
            pointer_holder = result->body;
            asprintf(&result->body, "%s\r\n%s", result->body, response_split[index]); // append all data remain to body
            free(pointer_holder);
        }
    }
    free_pointer_pointer_char(response_split);
    return result;
}

int parse_uri(char *line, http_response *result) {
    char** uri_split = string_split(line, " ");
    int uri_split_length = length_pointer_pointer_char(uri_split);
    if (uri_split_length < 3) {
        return FALSE;
    }
    result->version = strdup(uri_split[0]);
    result->status_code = strdup(uri_split[1]);
    result->status = strdup(uri_split[2]);
    char* pointer_holder = NULL;
    register int index;
    for (index = 3; index < uri_split_length; index ++) {
        pointer_holder = result->status;
        asprintf(&result->status, "%s %s", result->status, uri_split[index]); // append all text remain to status
        free(pointer_holder);
    }
    free_pointer_pointer_char(uri_split);
	return TRUE;
}

int parse_header(char *line, http_response *result, int index) {
    const int colon_index = string_index(line, ":", 1);
    result->headers[index] = malloc(sizeof(header));
    char* header_name = string_from_to(line, 0, colon_index - 1);
    char* header_value = string_from_to(line, colon_index + 2, length_pointer_char(line) - 1);
    result->headers[index]->name = header_name;
    result->headers[index]->value = header_value;
    return TRUE;
}

void free_http_response(http_response *response) {
	register int index;
	for (index = 0; index < response->header_quantity; index++) {
        free(response->headers[ index ]->name);
		free(response->headers[ index ]->value);
		free(response->headers[ index ]);
	}
    free(response->status);
	free(response->status_code);
    free(response->version);
    free(response->body);
    free(response);
}

int count_header(char* response) {
    register int index = 0;
    int count = 0;
    const int end_header_index = string_index(response, "\r\n\r\n", 1);
    for (index = 0; index < end_header_index; index ++) {
        if (response[index] == '\n') {
            count ++;
        }
    }
    return count;
}
