#include "../file.h"
#define TRUE 1
#define FALSE 0

char *file_get_contents(char *file_name){
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

int file_put_contents(char *file_path, char *content){
	FILE *outputFile = fopen(file_path, "wb+");
	if (outputFile == NULL) {
		fprintf(stderr, "Permission denied !\n");
		return FALSE;
	}
	fputs(content, outputFile);
	fclose(outputFile);
	return TRUE;
}