#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "../general.h"
#include "../string.h"
#include "../network.h"


/**
 * Retrieve url schema
 *
 * @param url
 * @return string (https or http)
 */
char *http_schema(char *url) {
	if (length_pointer_char(url) == 0) {
		return NULL;
	}
	if (string_startswith(url, "https://") == 1) {
		return HTTPS;
	} else if (string_startswith(url, "http://") == 1) {
		return HTTP;
	}
	return NULL;
}

/**
 * Retrieve url schema
 *
 * @param url
 * @return string (hostname)
 */
char *http_hostname(char *url) {
	if (length_pointer_char(url) == 0) {
		return NULL;
	}

	if (string_index(url, "127.0.0.1", FIRST_TIMES) != -1) {
		return LOCALHOST;
	} else {
		int firstPos = string_index(url, "://", FIRST_TIMES);
        char *indexUrl = url + sizeof(char) * (firstPos + 3);
        char *result = string_get_substr(indexUrl, 0, ":/?");
        return result;
	}

	return NULL;
}

/**
 * Retrieve url schema
 *
 * @param url
 * @return int
 */
int http_port(char *url) {
    int https_port = string_startswith(url, HTTPS);
    int http_port = string_startswith(url, HTTP);

	if (length_pointer_char(url) == 0 || (http_port == 0 && https_port == 0)) {
		return -1;
	}

    char **element = string_split(url, "/");
    char *result = element[1];

    int indexColon = string_index(result, ":", FIRST_TIMES) + 1;
    char *index = result + sizeof(char) * indexColon;

    int port = atoi(index);
    if (port == 0) {
        return https_port ? HTTPS_PORT : HTTP_PORT;
    }

    return port;
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

	int first_position = string_index(url, "?", FIRST_TIMES);
	int end_position = first_position;
	int length_target = length_pointer_char(url);
	for (end_position; end_position < length_target; end_position++) {
		if (url[end_position] == '/' || url[end_position] == ':') {
			break;
		}
	}

	if (first_position != -1) {
		return string_from_to(url, first_position + 1, end_position - 1);
	}

	return NULL;
}

/**
 * return paht of URL if paht doesn't exit return "/"
 * @param url
 * @return string path
 */
char *http_path(char *url) {
    int exitHttp = string_startswith(url, HTTP);
    int exitHttps = string_startswith(url, HTTPS);

    if (exitHttp == 0 && exitHttps == 0) {
        return NULL;
    }

    char *index = url + sizeof(char) * (exitHttp ? LENGHT_OF_HTTP : LENGHT_OF_HTTPS);
    int indexOfFirstSlash = string_index(index, "/", FIRST_TIMES);
    char *result = string_get_substr(index, indexOfFirstSlash, ":?");
    if (result == NULL) {
        return "/";
    }
    return result;
}

/**
 * Send request to server with data in request body
 * This function can be used in general case with all requests
 *
 * @method GET POST PUT PATCH DELETE HEAD OPTIONS
 * @return string
 */

char *http_request(char *method, char *url, char **headers, char **body) {
	int port = http_port(url);
	char *host = http_hostname(url);
	char *path = http_path(url);

	char *template = 	"%s %s%s%s HTTP/1.1\r\n"
						"Connection: close\r\n"
						"Host: %s:%d\r\n"
						"%s\r\n\r\n"
						"%s";
	char *headerString = string_join(headers, "\r\n");
	char *bodyString = string_join(body, "&");

	if (strcmp(method, "GET")) {
		int bodySize = length_pointer_char(bodyString);
		asprintf(&headerString, "%s\r\nContent-Length: %d", headerString, bodySize);
	}

	struct hostent *server;
	struct sockaddr_in serv_addr;
	int sockfd, bytes, sent, received, total, message_size;
	char *message, response[4096];

	if (!strcmp(method, "GET")) {
		asprintf(&message, template,
				method,
				path,
				length_pointer_char(bodyString) > 0 ? "?" : "",
				bodyString,
				host,
				port,
				headerString,
				"");
	} else {
		asprintf(&message, template,
				method,
				path,
				"",
				"",
				host,
				port,
				headerString,
				bodyString);
	}
	int messageSize = length_pointer_char(message);

	printf("Request:\n%s\n", message);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) error("ERROR opening socket");

	server = gethostbyname(host);
	if (server == NULL) error("ERROR, no such host");

	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	memcpy(&serv_addr.sin_addr.s_addr,server->h_addr,server->h_length);

	if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
		error("ERROR connecting");

	total = messageSize;
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
		if (bytes < 0) {
			error("ERROR reading response from socket");
		}
		if (bytes == 0) {
			break;
		}
		received+=bytes;
	} while (received < total);

	if (received == total)
		error("ERROR storing complete response from socket");

	close(sockfd);

	printf("Response:\n%s\n",response);

	free(message);
	return response;
}
//
//char *http_request(char *method, char* url, char **headers, char *body) {
//	int i;
//	int port = http_port(url);
//	char *host = http_hostname(url);
//	char *query = http_query(url);
//
//	struct hostent *server;
//	struct sockaddr_in serv_addr;
//	int sockfd, bytes, sent, received, total, message_size;
//	char *message, response[4096];
//
//	message_size=0;
//	if(!strcmp(method,"GET"))
//	{
//		message_size+=length_pointer_char("%s %s%s%s HTTP/1.0\r\n");        // method
//		message_size+=length_pointer_char(argv[3]);                         // path
//		message_size+=length_pointer_pointer_char(headers);                         // headers
//		if(argc>5)
//			message_size+=length_pointer_char(query);                     // query string
//		for(i=6;i<argc;i++)                                    // headers
//			message_size+=length_pointer_char(argv[i])+length_pointer_char("\r\n");
//		message_size+=length_pointer_char("\r\n");                          // blank line
//	}
//	else
//	{
//		message_size+=length_pointer_char("%s %s HTTP/1.0\r\n");
//		message_size+=length_pointer_char(argv[3]);                         // method
//		message_size+=length_pointer_char(argv[4]);                         // path
//		for(i=6;i<argc;i++)                                    // headers
//			message_size+=length_pointer_char(argv[i])+length_pointer_char("\r\n");
//		if(argc>5)
//			message_size+=length_pointer_char("Content-Length: %d\r\n")+10; // content length
//		message_size+=length_pointer_char("\r\n");                          // blank line
//		if(argc>5)
//			message_size+=length_pointer_char(argv[5]);                     // body
//	}
//
//	// allocate space for the message
//	message=malloc(message_size);
//
//	// fill in the parameters
//	if(!strcmp(argv[3],"GET"))
//	{
//		if(argc>5)
//			sprintf(message,"%s %s%s%s HTTP/1.0\r\n",
//					length_pointer_char(argv[3])>0?argv[3]:"GET",               // method
//					length_pointer_char(argv[4])>0?argv[4]:"/",                 // path
//					length_pointer_char(argv[5])>0?"?":"",                      // ?
//					length_pointer_char(argv[5])>0?argv[5]:"");                 // query string
//		else
//			sprintf(message,"%s %s HTTP/1.0\r\n",
//					length_pointer_char(argv[3])>0?argv[3]:"GET",               // method
//					length_pointer_char(argv[4])>0?argv[4]:"/");                // path
//		for(i=6;i<argc;i++)                                    // headers
//		{strcat(message,argv[i]);strcat(message,"\r\n");}
//		strcat(message,"\r\n");                                // blank line
//	}
//	else
//	{
//		sprintf(message,"%s %s HTTP/1.0\r\n",
//				length_pointer_char(argv[3])>0?argv[3]:"POST",                  // method
//				length_pointer_char(argv[4])>0?argv[4]:"/");                    // path
//		for(i=6;i<argc;i++)                                    // headers
//		{strcat(message,argv[i]);strcat(message,"\r\n");}
//		if(argc>5)
//			sprintf(message+length_pointer_char(message),"Content-Length: %d\r\n",length_pointer_char(argv[5]));
//		strcat(message,"\r\n");                                // blank line
//		if(argc>5)
//			strcat(message,argv[5]);                           // body
//	}
//
//	// What are we going to send?
//	printf("Request:\n%s\n",message);
//
//	// create the socket
//	sockfd = socket(AF_INET, SOCK_STREAM, 0);
//	if (sockfd < 0) error("ERROR opening socket");
//
//	// lookup the ip address
//	server = gethostbyname(host);
//	if (server == NULL) error("ERROR, no such host");
//
//	// fill in the structure
//	memset(&serv_addr,0,sizeof(serv_addr));
//	serv_addr.sin_family = AF_INET;
//	serv_addr.sin_port = htons(port);
//	memcpy(&serv_addr.sin_addr.s_addr,server->h_addr,server->h_length);
//
//	if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
//		error("ERROR connecting");
//
//	total = length_pointer_char(message);
//	sent = 0;
//	do {
//		bytes = write(sockfd,message+sent,total-sent);
//		if (bytes < 0)
//			error("ERROR writing message to socket");
//		if (bytes == 0)
//			break;
//		sent+=bytes;
//	} while (sent < total);
//
//	memset(response,0,sizeof(response));
//	total = sizeof(response)-1;
//	received = 0;
//	do {
//		bytes = read(sockfd,response+received,total-received);
//		if (bytes < 0)
//			error("ERROR reading response from socket");
//		if (bytes == 0)
//			break;
//		received+=bytes;
//	} while (received < total);
//
//	if (received == total)
//		error("ERROR storing complete response from socket");
//
//	close(sockfd);
//
//	printf("Response:\n%s\n",response);
//
//	free(message);
//	return 0;
//}
