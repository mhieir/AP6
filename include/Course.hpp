#ifndef COURSE_INCLUDE
#define COURSE_INCLUDE

#include "Global.hpp"
#include "Entity.hpp"
#include "CourseOffer.hpp"

class Course : public Entity {
public:
    Course(string id, string name, int credit, int prerequisite, vector<string> majors_id);
    ~Course() {};
    int getCredit() {return credit;}
    int getPrerequisite() {return prerequisite;}
    bool hasMajor(string major_id);
protected:
    int credit, prerequisite;
    vector<string> majors_id;
    vector<CourseOffer> course_offers;
private:
};

#endif