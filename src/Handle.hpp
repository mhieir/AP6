#pragma once
#ifndef HANDLE_INCLUDE
#define HANDLE_INCLUDE

#include "Global.hpp"
#include "server.hpp"
#include "University.hpp"

const string SHOW_SERVER_PORT = "Server running on port: ";

class Handle {
public:
    Handle(char *argv[], int port);
    ~Handle() {};
    void run();
protected:
private:
    University* university;
    Server* server;
    void mapServerPaths();
};

#endif