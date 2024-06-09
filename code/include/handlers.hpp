#pragma once
#ifndef HANDLERS_HPP_INCLUDE
#define HANDLERS_HPP_INCLUDE

#include "Global.hpp"
#include "server.hpp"
#include "University.hpp"

const string SHOW_SERVER_PORT = "Server running on port: ";

class Handle : public RequestHandler{
public:
    Handle() {};
    ~Handle() {};
    virtual Response* callback(Request* req) {};
    void run();
    void setServer(int port) {server = new Server(port);}
    void setUniversity(char **argv) {university = new University(argv);}
protected:
    University* university;
    Server* server;
private:
    void mapServerPaths();
};

class RandomNumberHandler : public Handle {
public:
    RandomNumberHandler() {};
    ~RandomNumberHandler() {};
    Response* callback(Request*) override;
};

class LoginHandler : public Handle {
public:
    LoginHandler() {};
    ~LoginHandler() {};
    Response* callback(Request*) override;
};

class UploadHandler : public Handle {
public:
    UploadHandler() {};
    ~UploadHandler() {};
    Response* callback(Request*) override;
};

class ColorHandler : public TemplateHandler {
public:
    ColorHandler(const std::string& filePath);
    std::map<std::string, std::string> handle(Request* req) override;
};

#endif // HANDLERS_HPP_INCLUDE
