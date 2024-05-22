#ifndef POST_INCLUDE
#define POST_INCLUDE

#include "Global.hpp"

class Post {
public:
    Post(string title, string message, int id);
    ~Post() {};
    string getTitle() {return title;}
    string getMessage() {return message;}
    int getId() {return id;}
protected:
private:
    string title, message;
    int id;
};

#endif