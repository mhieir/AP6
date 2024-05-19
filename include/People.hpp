#ifndef PEOPLE_INCLUDE
#define PEOPLE_INCLUDE

#include "Global.hpp"
#include "University.hpp"

class People : public University {
public:
    People(string id, string name, string major_id, string password);
    ~People() {};
    string getMajorId() {return major_id;}
    string getPassword() {return password;}
protected:
    string major_id, password;
private:
};

#endif