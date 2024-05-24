#include "CourseOffer.hpp"
#include "Primary.hpp"

CourseOffer::CourseOffer(int courseOfferId, string id, Professor* professor, int capacity, Time time, Date exam_time, int class_number, string name, int credit, int prerequisite, vector<string> majors_id) :
Course(id, name, credit, prerequisite, majors_id), capacity(capacity), courseOfferId(courseOfferId), time(time), exam_time(exam_time), professor(professor), class_number(class_number) {}


bool CourseOffer::inSameTime(Time new_time) {
    if(new_time.getWeekDay() == time.getWeekDay() and hasCommon(new_time.getStart(), new_time.getEnd(), time.getStart(), time.getEnd())) {
        return true;
    }
    else {
        return false;
    }
}