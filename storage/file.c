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

#include "../storage.h"
#include "../network.h"
#include "../builtin.h"

#define TRUE 1
#define FALSE 0

inline char *file_get_contents(char *file_name) {
	if (is_url(file_name) != 0) {
        char *headers[2] = {
                "\0"
        };

        char *body[2] = {
                "a=b",
                '\0'
        };
		char *result = http_request("GET", file_name, headers, body);
        int pos = string_index(result, "\r\n\r\n", 1);
        result = result + sizeof(char) * (pos + 4);
		return result;
	}

	FILE *input_file = fopen(file_name, "r");
	if (input_file == NULL) {
		fprintf(stderr, "File does not exist !\n");
		return NULL;
	}
	fseek(input_file, 0, SEEK_END);
	size_t file_size = ftell(input_file);
	char *result = (char*) malloc((file_size + 1) * sizeof(char));
	rewind(input_file);
	fread(result, 1, file_size, input_file);
	fclose(input_file);
    result[file_size] = '\0';
	return result;
}

inline int file_put_contents(char *file_path, char *content) {
	FILE *output_file = fopen(file_path, "wb+");
	if (output_file == NULL) {
		fprintf(stderr, "Permission denied !\n");
		return FALSE;
	}
	fputs(content, output_file);
	fclose(output_file);
	return TRUE;
}