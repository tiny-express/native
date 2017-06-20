
#include <stdlib.h>
#include "response_parser.h"
#include "../string.h"
#include "../builtin.h"

/**
 * init result
 * @reference how to use flexible memory: https://stackoverflow.com/questions/17344745/how-to-use-flexible-array-in-c-to-keep-several-values
 * @return an empty http_response
 */
http_response *init_result();

/**
 * count header quantity from response
 * @param response
 * @return header quantity
 */
int count_header(char* response);

/**
 * parse version, status, status code into result
 * @param response
 * @param result
 * @return false if could not parse uri, else return true
 */
int parse_uri(char **response_split, http_response *result);

/**
 * parse header to result
 * @param response
 * @param result
 * @param index
 * @return false if could not parse header, else return true
 */
int parse_header(char **response_split, http_response *result, int header_quantity);

/**
 * parse response body to result
 * @param response_split
 * @param result
 * @return true
 */
int parse_body(char **response_split, http_response *result);

/**
 * parse http response to
 * @param response
 * @return http response
 */
http_response *parse(char *response) {
    char** response_split = string_split(response, "\r\n");
    http_response *result = init_result();
    const int header_quantity = count_header(response);

    if (!(parse_uri(response_split, result) &&
            parse_header(response_split, result, header_quantity) &&
            parse_body(response_split, result))) {
        free_http_response(result);
        result = init_result();
    }

    free_pointer_pointer_char(response_split);
    return result;
}


http_response *init_result() {
    http_response *result = calloc(1, sizeof(http_response) + 4 * sizeof(char *));
    result->header_quantity = 0;
    result->version = strdup("");
    result->status_code = strdup("");
    result->status = strdup("");
    result->body = strdup("");
    return result;
}

int parse_uri(char **response_split, http_response *result) {
    char** uri_split = string_split(response_split[0], " ");
    int uri_split_length = length_pointer_pointer_char(uri_split);
    if (uri_split_length < 3) {
        free_pointer_pointer_char(uri_split);
        return FALSE;
    }
    free(result->status);
    free(result->version);
    free(result->status_code);

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

header* get_header(char **response_split, int index) {
    char* line = response_split[index + 1];
    int colon_index = string_index(line, ":", 1);
    header* result = calloc(1, sizeof(header));
    result->name = string_from_to(line, 0, colon_index - 1);
    result->value = string_from_to(line, colon_index + 2, length_pointer_char(line) - 1);
    return result;
}

int parse_header(char **response_split, http_response *result, int header_quantity) {
    if (header_quantity == 0) {
        return FALSE;
    }
    result->header_quantity = header_quantity;
    register int index;
    for (index = 0; index < header_quantity; index ++) {
        result->headers[index] = get_header(response_split, index);
    }
    return TRUE;
}

int parse_body(char **response_split, http_response* result) {
    const int response_split_length = length_pointer_pointer_char(response_split);
    if (result->header_quantity + 1 < response_split_length) {
        free(result->body);
        char* pointer_holder;
        register int index;
        result->body = strdup(response_split[result->header_quantity + 1]);
        for (index = result->header_quantity + 2; index < response_split_length; index ++) {
            pointer_holder = result->body;
            asprintf(&result->body, "%s\r\n%s", result->body, response_split[index]); // append all data remain to body
            free(pointer_holder);
        }
    }
    return TRUE;
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
