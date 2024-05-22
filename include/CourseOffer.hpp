#ifndef COURSE_OFFER_INCLUDE
#define COURSE_OFFER_INCLUDE

#include "Global.hpp"
#include "Time.hpp"
#include "Date.hpp"

class CourseOffer {
public:
    CourseOffer(int id, string course_id, string professor_id, int capacity, Time time, Date exam_time, int class_number);
    ~CourseOffer() {};
    int getId() {return id;}
    int getClassNumber() {return class_number;}
    int getCapacity() {return capacity;}
    string getCourseId() {return course_id;}
    string getProfessorId() {return professor_id;}
    Time getTime() {return time;}
    Date getExamTime() {return exam_time;}
    int getClassNumber() {return class_number;}
protected:
    string course_id, professor_id;
    Time time;
    Date exam_time;
    int id, class_number, capacity;
private:
};

#endif