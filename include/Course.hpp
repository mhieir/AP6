#ifndef COURSE_INCLUDE
#define COURSE_INCLUDE

#include "Global.hpp"
#include "University.hpp"

class Course : public University {
public:
    Course(string id, string name, int credit, int prerequisite, string majors_id_string);
    ~Course() {};
    int getCredit() {return credit;}
    int getPrerequisite() {return prerequisite;}
protected:
    int credit, prerequisite;
    string majors_id_string;
private:
};

#endif