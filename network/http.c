#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "../general.h"
#include "../string.h"

#define HTTPS "https://"
#define HTTP "http://"
#define LOCALHOST "localhost"

/**
 * Retrieve url schema
 *
 * @param url
 * @return string
 */
char *http_schema(char *url) {
	if (length_pointer_char(url) == 0) {
		return NULL;
	}
	if(string_index(url, "https://")) {
		return HTTPS;
	} else if(string_index(url, "http://")) {
		return HTTP;
	}
	return NULL;
}

/**
 * Retrieve url schema
 *
 * @param url
 * @return string
 */
char *http_hostname(char *url) {
	if (length_pointer_char(url) == 0) {
		return NULL;
	}

	if(string_index(url, "127.0.0.1")) {
		return LOCALHOST;
	}

	int indexOfHostname = string_index(url, "://") + 3;
	char charInUrl = url[indexOfHostname];
	char arrayHostname[100];
	int index = 0; // index in arrayHostname

	while(url[indexOfHostname] != '/' || url[indexOfHostname] != ':') {
		arrayHostname[index++] = url[indexOfHostname++];
	}

	char *result = convert_to_pointer_char(arrayHostname);
	return result;
}

/**
 * Retrieve url schema
 *
 * @param url
 * @return string
 */
char *http_port(char *url) {
	if (length_pointer_char(url) == 0) {
		return NULL;
	}

	return "";
}

/**
 * Get query from url
 * Example: http://localhost/index?key1=value1&key2=value2
 * Query will be 'key1=value1&key2=value2'
 * @param url
 * @return string
 */
char *http_query(char *url) {
	int length_url = length_pointer_char(url);
	if (length_url == 0) {
		return NULL;
	}
	int first_position = string_index(url, "?");
	if (first_position < 0) {
		// Url query does not exist
		return NULL;
	}
	//return string_substr(url, first_position, length_url + 1);
	return "";
}

/**
 * Send request to server with data in request body
 * This function can be used in general case with all requests
 *
 * @method GET POST PUT PATCH DELETE HEAD OPTIONS
 * @return string
 */
char *http_request(char *url, char *body, char *headers) {

}

/*
char *http_request(char* url) {
	int i;
	int portno = atoi(argv[2])>0?atoi(argv[2]):80;
	char *host = strlen(argv[1])>0?argv[1]:"localhost";

	struct hostent *server;
	struct sockaddr_in serv_addr;
	int sockfd, bytes, sent, received, total, message_size;
	char *message, response[4096];

	if (argc < 5) { puts("Parameters: <host> <port> <method> <path> [<data> [<headers>]]"); exit(0); }

	message_size=0;
	if(!strcmp(argv[3],"GET"))
	{
		message_size+=strlen("%s %s%s%s HTTP/1.0\r\n");        // method
		message_size+=strlen(argv[3]);                         // path
		message_size+=strlen(argv[4]);                         // headers
		if(argc>5)
			message_size+=strlen(argv[5]);                     // query string
		for(i=6;i<argc;i++)                                    // headers
			message_size+=strlen(argv[i])+strlen("\r\n");
		message_size+=strlen("\r\n");                          // blank line
	}
	else
	{
		message_size+=strlen("%s %s HTTP/1.0\r\n");
		message_size+=strlen(argv[3]);                         // method
		message_size+=strlen(argv[4]);                         // path
		for(i=6;i<argc;i++)                                    // headers
			message_size+=strlen(argv[i])+strlen("\r\n");
		if(argc>5)
			message_size+=strlen("Content-Length: %d\r\n")+10; // content length
		message_size+=strlen("\r\n");                          // blank line
		if(argc>5)
			message_size+=strlen(argv[5]);                     // body
	}

	// allocate space for the message
	message=malloc(message_size);

	// fill in the parameters
	if(!strcmp(argv[3],"GET"))
	{
		if(argc>5)
			sprintf(message,"%s %s%s%s HTTP/1.0\r\n",
					strlen(argv[3])>0?argv[3]:"GET",               // method
					strlen(argv[4])>0?argv[4]:"/",                 // path
					strlen(argv[5])>0?"?":"",                      // ?
					strlen(argv[5])>0?argv[5]:"");                 // query string
		else
			sprintf(message,"%s %s HTTP/1.0\r\n",
					strlen(argv[3])>0?argv[3]:"GET",               // method
					strlen(argv[4])>0?argv[4]:"/");                // path
		for(i=6;i<argc;i++)                                    // headers
		{strcat(message,argv[i]);strcat(message,"\r\n");}
		strcat(message,"\r\n");                                // blank line
	}
	else
	{
		sprintf(message,"%s %s HTTP/1.0\r\n",
				strlen(argv[3])>0?argv[3]:"POST",                  // method
				strlen(argv[4])>0?argv[4]:"/");                    // path
		for(i=6;i<argc;i++)                                    // headers
		{strcat(message,argv[i]);strcat(message,"\r\n");}
		if(argc>5)
			sprintf(message+strlen(message),"Content-Length: %d\r\n",strlen(argv[5]));
		strcat(message,"\r\n");                                // blank line
		if(argc>5)
			strcat(message,argv[5]);                           // body
	}

	// What are we going to send?
	printf("Request:\n%s\n",message);

	// create the socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) error("ERROR opening socket");

	// lookup the ip address
	server = gethostbyname(host);
	if (server == NULL) error("ERROR, no such host");

	// fill in the structure
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portno);
	memcpy(&serv_addr.sin_addr.s_addr,server->h_addr,server->h_length);

	if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
		error("ERROR connecting");

	total = strlen(message);
	sent = 0;
	do {
		bytes = write(sockfd,message+sent,total-sent);
		if (bytes < 0)
			error("ERROR writing message to socket");
		if (bytes == 0)
			break;
		sent+=bytes;
	} while (sent < total);

	memset(response,0,sizeof(response));
	total = sizeof(response)-1;
	received = 0;
	do {
		bytes = read(sockfd,response+received,total-received);
		if (bytes < 0)
			error("ERROR reading response from socket");
		if (bytes == 0)
			break;
		received+=bytes;
	} while (received < total);

	if (received == total)
		error("ERROR storing complete response from socket");

	close(sockfd);

	printf("Response:\n%s\n",response);

	free(message);
	return 0;
}
*/