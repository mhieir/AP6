#ifndef PROFESSOR_INCLUDE
#define PROFESSOR_INCLUDE

#include "Global.hpp"
#include "People.hpp"

enum Position {
    INSTRUCTOR,
    ASSISTANT,
    ASSOCIATE,
    PROFESSSOR
};

class Professor : public People {
public:
    Professor(string id, string name, string major_id, string string_position, string password);
    ~Professor() {};
    Position getPosition() {return position;}
protected:
    string string_position;
    Position position;
private:
};

#endif