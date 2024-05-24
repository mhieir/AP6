#include "University.hpp"
#include "Primary.hpp"

void University::runGetCourse() {
    if(input_line.size() != GET_COURSE_MODE_SIZE_FIRST and input_line.size() != GET_COURSE_MODE_SIZE_SECOND) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkLogin()) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else if(!isQuestionMark(input_line[2])) {
        throw runtime_error(BAD_REQUEST);
    }
    else if((int) input_line.size() == GET_COURSE_MODE_SIZE_FIRST) {
        if((int) all_course_offers.size() == 0) {
            throw runtime_error(EMPTY);
        }
        else {
            showAllCourseOffers();
        }
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
    else {
        showOneCourseOffers(stoi(input_line[4]) - 1);
    }
}

