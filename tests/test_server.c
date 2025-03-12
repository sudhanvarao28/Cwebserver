#include<stdio.h>
#include "../server/server.h"
#include <unistd.h>
#include<string.h>


void launch(struct Server* server){
    char buffer[20000];
    while(1){
        printf("<==========WAITING FOR CONECTION===========>");
        int address_length = sizeof(server->address); 
        int new_socket = accept(server->socket,(struct sockaddr*)&server->address,(socklen_t*)&address_length);
        read(new_socket,buffer,20000);
        printf("Request: %s\n",buffer);
        char* hello = "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html; charset=UTF-8\r\n"
            "Content-Length: 13\r\n"
            "Connection: close\r\n"
            "\r\n"
            "Hello, world!";

        write(new_socket, hello, strlen(hello));
        close(new_socket);
    }
    


}

int main(){
    struct Server* server = server_constructor(AF_INET,SOCK_STREAM,0,INADDR_ANY,80,10,launch);
    server->launch(server);
}    