#ifndef server_h
#define server_h

#include <sys/socket.h>
#include <netinet/in.h>
#include<stdlib.h>
struct Server{
    int domain;
    int protocol;
    int service;
    unsigned long interface;
    int backlog;
    int port;

    struct sockaddr_in address;
    int socket;

    void (*launch)(struct Server* server);
};

struct Server* server_constructor(int domain, int protocol, int service, unsigned long interface, int port, int backlog, void(*launch)(struct Server* server));

#endif