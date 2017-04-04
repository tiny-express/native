//
// Created by coder on 04/04/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <curl/curl.h>


struct string {
	char *ptr;
	size_t len;
};

void init_string(struct string *s) {
	s->len = 0;
	s->ptr = malloc(s->len+1);
	s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
	size_t new_len = s->len + size*nmemb;
	s->ptr = realloc(s->ptr, new_len+1);
	memcpy(s->ptr+s->len, ptr, size*nmemb);
	s->ptr[new_len] = '\0';
	s->len = new_len;

	return size*nmemb;
}

// Get content from file or url
char *file_get_content(char *filename)
{
	if(strstr(filename, "http://") != NULL){
		CURL *curl;
		CURLcode res;

		curl = curl_easy_init();
		if(curl) {
			struct string s;
			init_string(&s);

			curl_easy_setopt(curl, CURLOPT_URL, filename);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
			res = curl_easy_perform(curl);
			curl_easy_cleanup(curl);

			return s.ptr;
		}
	}
		// If filename not a url
	else{
		FILE *fi = fopen(filename, "r");
		if(fi == NULL){
			fprintf(stderr ,"Can not find the file\n");
			exit(1);
		}

		fseek(fi, 0, SEEK_END);
		size_t size_of_file = ftell(fi);
		char *result = (char*)malloc((size_of_file + 1)* sizeof(char));
		rewind(fo);
		fread(result, 1, size_of_file, fo);
		result[size_of_file] = '\0';

		fclose(fo);
		return result;
	}
}

// Put content to file
void file_put_content(char *file_path, char *content){
	FILE *fo = fopen(file_path, "w");
	fputs(content);
	fclose(fo);
	return;
}