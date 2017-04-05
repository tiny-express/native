#include "../storage/file.h"

// Get content of file
char *file_get_content(char *filename){
	FILE *fi;
	fi = fopen(filename, "r");

	if(fi == NULL){
		fprintf(stderr, "File not available\n");
		exit(1);
	}

	fseek(fi, 0, SEEK_END);
	size_t size_of_file = ftell(fi);
	char *result = (char*)malloc((size_of_file + 1)* sizeof(char));
	rewind(fi);
	fread(result, 1, size_of_file, fi);

	fclose(fi);
	return result;
}

// Put content to file
int file_put_content(char *file_path, char *content){
	FILE *fo = fopen(file_path, "w");
	if(fo == NULL){
		return 0;
	}
	fputs(content, fo);
	fclose(fo);
	return 1;
}