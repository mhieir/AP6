#ifndef PEOPLE_INCLUDE
#define PEOPLE_INCLUDE

#include "Global.hpp"
#include "Entity.hpp"

class People : public Entity {
public:
    People(string id, string name, string major_id, string password);
    ~People() {};
    string getMajorId() {return major_id;}
    string getPassword() {return password;}
    void addConnection(string new_id) {connections.push_back(new_id);}
protected:
    string major_id, password;
    vector<string> connections;
private:
};

#endif