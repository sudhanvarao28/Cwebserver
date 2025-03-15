#include "http_request.h"
#include<stdlib.h>
#include<string.h>

#include <string.h>

int get_http_method(const char* method) {
    if (strncmp(method, "GET", 3) == 0) {
        return GET;
    } 
    else if (strncmp(method, "POST", 4) == 0) {
        return POST;
    } 
    else if (strncmp(method, "PUT", 3) == 0) {
        return PUT;
    } 
    else if (strncmp(method, "DELETE", 6) == 0) {
        return DELETE;
    }
    else if (strncmp(method, "PATCH", 5) == 0) {
        return PATCH;
    }
    else if (strncmp(method, "HEAD", 4) == 0) {
        return HEAD;
    }
    else if (strncmp(method, "OPTIONS", 7) == 0) {
        return OPTIONS;
    }
    else if (strncmp(method, "TRACE", 5) == 0) {
        return TRACE;
    }
    else {
        return UNKNOWN;  // Assuming UNKNOWN exists in your enum for invalid methods
    }
}

struct HttpRequest* http_request_constructor(char* request){
    struct HttpRequest* http_request = (struct HttpRequest*)malloc(sizeof(struct HttpRequest));
    char* request_line;
    char* header;
    char* body;
    char* method;
    char* path;
    char* http_version;
    for(int i = 0;i<strlen(request)-1;i++){
        if(request[i]=='\n' && request[i+1]=='\n'){
            request[i+1] = '|';
        }
    }
        request_line = strtok(request, "\n");
        header = strtok(NULL, "|");
        body = strtok(NULL, "|");

        method = strtok(request_line, " ");
        path = strtok(NULL, " ");
        http_version = strtok(NULL, " ");

        http_request->method = get_http_method(method);
        http_request->http_version = (float)atof(http_version);
        http_request->uri = path;

        return http_request;


}