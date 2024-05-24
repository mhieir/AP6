#ifndef STUDENT_INCLUDE
#define STUDENT_INCLUDE

#include "Global.hpp"
#include "People.hpp"

class Student : public People {
public:
    Student(string id, string name, Major* major, int semester, string password);
    ~Student() {};
    int getSemester() {return semester;}
    void personalPage();
    void getPost(int post_id);
protected:
    int semester;
private:
};

#endif