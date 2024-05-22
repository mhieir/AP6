#include "CourseOffer.hpp"
#include "Primary.hpp"

CourseOffer::CourseOffer(int id, string course_id, string professor_id, int capacity, Time time, Date exam_time, int class_number) :
capacity(capacity), id(id), course_id(course_id), time(time), exam_time(exam_time), professor_id(professor_id), class_number(class_number) {}