#ifndef UNIVERSITY_INCLUDE
#define UNIVERSITY_INCLUDE

#include "Global.hpp"

class University {
public:
    University(string id, string name);
    ~University() {};
    string getId() {return id;}
    string getName() {return name;}
protected:
    string id, name;
private:
};

#endif