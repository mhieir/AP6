#include "University.hpp"
#include "Primary.hpp"

void University::runDeleteCourse() {
    if(input_line.size() != PUT_COURSE_MODE_SIZE) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkLogin() || !isStudent()) {
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
    else if(stoi(input_line[4]) == 0) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(stoi(input_line[4]) >= course_offer_id) {
        throw runtime_error(NOT_FOUND);
    }
    else if(!user->hasCourseOfferById(stoi(input_line[4]))) {
        throw runtime_error(NOT_FOUND);
    }
    else {
        user->removeCourse(all_course_offers[stoi(input_line[4]) - 1]->getCourseOfferId());
        user->shareNotification(user->getId() + SPACE + user->getName() + COLON + SPACE + NEW_DELETE_COURSE + '\n');
        throw runtime_error(OK);
    }
}