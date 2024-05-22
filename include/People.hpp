#ifndef PEOPLE_INCLUDE
#define PEOPLE_INCLUDE

#include "Global.hpp"
#include "Entity.hpp"
#include "Post.hpp"

enum PeopleType {
    STUDENT,
    PROFESSOR,
    UTACCOUNT
};

class People : public Entity {
public:
    People(string id, string name, string major_id, string password, PeopleType people_type);
    ~People() {};
    string getMajorId() {return major_id;}
    string getPassword() {return password;}
    void addConnection(string new_id) {connections.push_back(new_id);}
    bool inConnection(string new_id);
    bool isInPost(int post_id);
    void addPost(string title, string message);
    void removePost(int post_id);
    virtual void personalPage() = 0;
    PeopleType getPeopleType() {return people_type;}
protected:
    string major_id, password;
    vector<string> connections;
    vector<Post*> posts;
    int post_number;
    PeopleType people_type;
private:
};

#endif