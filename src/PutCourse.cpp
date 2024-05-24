#include "University.hpp"
#include "Primary.hpp"

void University::runPutCourse() {
    if(input_line.size() != PUT_COURSE_MODE_SIZE || !isStudent()) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkLogin()) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else if(!isQuestionMark(input_line[2])) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(input_line[3] != ID) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!isNumber(input_line[4])) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(stoi(input_line[4]) > course_offer_id) {
        throw runtime_error(NOT_FOUND);
    }
    else if(user->getSemester() < all_course_offers[stoi(input_line[4]) - 1]->getPrerequisite()) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else if(!all_course_offers[stoi(input_line[4]) - 1]->hasMajor(user->getMajorId())) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else if(!user->validCourseTime(all_course_offers[stoi(input_line[4]) - 1]->getTime()) || !user->validCourseDate(all_course_offers[stoi(input_line[4]) - 1]->getExamTime()) ) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else {
        user->addCourse(all_course_offers[stoi(input_line[4]) - 1]);
        throw runtime_error(OK);
    }
}