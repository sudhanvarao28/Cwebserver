#ifndef http_request_h
#define http_request_h

enum HttpMethods{
    GET,
    POST,
    PUT,
    HEAD,
    DELETE,
    PATCH,
    CONNECT,
    OPTIONS,
    TRACE,
    UNKNOWN
};

struct HttpRequest{
    int method;
    char* uri;
    float http_version;
};

struct HttpRequest* http_request_constructor(char* request);


#endif