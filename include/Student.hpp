#ifndef STUDENT_INCLUDE
#define STUDENT_INCLUDE

#include "Global.hpp"
#include "People.hpp"

class Student : public People {
public:
    Student(string id, string name, string major_id, int semester, string password);
    ~Student() {};
    int getSemester() {return semester;}
    void personalPage();
protected:
    int semester;
private:
};

#endif