/* simple-server.c
 *
 * Copyright (c) 2000 Sean Walton and Macmillan Publishers.  Use may be in
 * whole or in part in accordance to the General Public License (GPL).
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
*/

/*****************************************************************************/
/*** simple-server.c                                                       ***/
/***                                                                       ***/
/*****************************************************************************/

/**************************************************************************
*	This is a simple echo server.  This demonstrates the steps to set up
*	a streaming server.
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h> // for close
#include <pthread.h>
#include "../network.h"

#define MY_PORT		9999
#define MAXBUF		1024

pthread_t pthread;
int sockfd;

void* start() {
    struct sockaddr_in self;
    char buffer[MAXBUF];

    /*---Create streaming socket---*/
    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
        perror("Socket");
        exit(errno);
    }

    /*---Initialize address/port structure---*/
    bzero(&self, sizeof(self));
    self.sin_family = AF_INET;
    self.sin_port = htons(MY_PORT);
    self.sin_addr.s_addr = INADDR_ANY;

    /*---Assign a port number to the socket---*/
    if ( bind(sockfd, (struct sockaddr*)&self, sizeof(self)) != 0 ) {
        perror("socket--bind");
        exit(errno);
    }

    /*---Make it a "listening socket"---*/
    if ( listen(sockfd, 20) != 0 ) {
        perror("socket--listen");
        exit(errno);
    }

    /*---Forever... ---*/
    while (1) {
        int clientfd;
        struct sockaddr_in client_addr;
        int addrlen=sizeof(client_addr);

        /*---accept a connection (creating a data pipe)---*/
        clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &addrlen);

        /*---On receive message---*/
        recv(clientfd, buffer, MAXBUF, 0);
        on_receive((int) clientfd, (http_response*) parse(buffer));

        /*---Close data connection---*/
        close(clientfd);
    }
}

void close_socket() {
    close(sockfd);
}

void start_mock_server() {
    int error = pthread_create(&pthread, NULL, start, NULL);
    if (error) {
        printf("Could not start mock server\n");
        fflush(stdout);
    }
}

void stop_mock_server() {
    close_socket();
    pthread_cancel(pthread);
}

void on_receive(int client_id, http_response* content) {
    char* path = content->path;
    if (strcmp(path, "/test/")) {
        on_test_http_request(client_id, content);
    }
}

void send_response(int client_id, char* content) {
    size_t size = sizeof(content);
    send(client_id, content, size, 0);
}