#include "server.h"
#include<stdio.h>

struct Server* server_constructor(int domain, int protocol, int service, unsigned long interface, int port, int backlog, void(*launch)(struct Server* server)){
    struct Server* server = (struct Server*) malloc(sizeof(struct Server));
    server->domain = domain;
    server->protocol = protocol;
    server->service = service;
    server->interface = interface;
    server->port = port;
    server->backlog = backlog;

    server->address.sin_family = domain;
    server->address.sin_port = htons(port);
    server->address.sin_addr.s_addr = htonl(interface);

    server->socket = socket(domain, service, protocol);

    if(server->socket < 0){
        perror("Failed to connect to socket...\n");
        exit(1);
    }

    if(bind(server->socket,(struct sockaddr*)&server->address, (socklen_t)sizeof(server->address))<0){
        perror("Failed to BIND socket.....\n");
        exit(1);
    }

    if(listen(server->socket,server->backlog)<0){
        perror("Failed to start LISTENING");
        exit(1);
    }

    server->launch = launch;

    return server;

}