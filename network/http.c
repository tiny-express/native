//
// Created by dquang on 15/04/2017.
//

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <resolv.h>
#include <errno.h>
#include "../general.h"
#include "../string.h"

#define MAXBUF  1024
#define ERROR "error"

char* http_get(char* url) {
	char* domain;
	int port;
	char* message;
	int sockfd, bytes_read;
	struct sockaddr_in dest;
	char buffer[MAXBUF];
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		return ERROR;
	}

	register index;
	char** url_split = string_split(url, "/");
	int url_split_length = length_pointer_pointer_char(url_split);
	if (url_split_length < 1) {
		return ERROR;
	}


	bzero(&dest, sizeof(dest));
	dest.sin_family = AF_INET;
	dest.sin_port = htons(2379); /*default HTTP Server port */
	inet_addr("127.0.0.1", &dest.sin_addr.s_addr);
	return "";
}