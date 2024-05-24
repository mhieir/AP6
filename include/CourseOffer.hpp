#ifndef COURSE_OFFER_INCLUDE
#define COURSE_OFFER_INCLUDE

#include "Global.hpp"
#include "Course.hpp"
#include "Time.hpp"
#include "Date.hpp"

class CourseOffer : public Course {
public:

    CourseOffer(int courseOfferId, string id, string professor_id, int capacity, Time time, Date exam_time, int class_number,
    string name, int credit, int prerequisite, vector<string> majors_id);
    ~CourseOffer() {};
    int getCourseOfferId() {return courseOfferId;}
    int getClassNumber() {return class_number;}
    int getCapacity() {return capacity;}
    string getProfessorId() {return professor_id;}
    string getTime() {return time.getCompleteTime();}
    string getExamTime() {return exam_time.getCompleteDate();}
    bool inSameTime(Time new_time);
protected:
    string professor_id;
    Time time;
    Date exam_time;
    int courseOfferId, class_number, capacity;
private:
};

#endif