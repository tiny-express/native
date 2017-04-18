#include "../network.h"
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>

char *getIPAddress()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        close(sockfd);
        return "0.0.0.0";
    }

    const char* dns_ip = "8.8.8.8";
    uint16_t dns_port = 53;

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(dns_port);
    serv_addr.sin_addr.s_addr = inet_addr(dns_ip);

    if (connect(sockfd, &serv_addr, sizeof(serv_addr)) < 0) {
        close(sockfd);
        return "0.0.0.0";
    }

    struct sockaddr_in name;
    socklen_t name_len = sizeof(name);
    if (getsockname(sockfd, &name, &name_len) < 0) {
        close(sockfd);
        return "0.0.0.0";
    }

    char *ip_addr = calloc(INET_ADDRSTRLEN, sizeof(char));
    inet_ntop(AF_INET, &(name.sin_addr), ip_addr, INET_ADDRSTRLEN);

    close(sockfd);
    return ip_addr;
}