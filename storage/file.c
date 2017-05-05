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