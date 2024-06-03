#include "University.hpp"
#include "Primary.hpp"

void University::runCloseTAForm() {
    if(input_line.size() != CLOSE_TA_FORM_MODE_SIZE) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!isQuestionMark(input_line[2])) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkLogin() || !isProfessor(user->getId())) {
        throw runtime_error(PERMISSION_DENIED);
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
    else if(!user->isTAForm(stoi(input_line[4]))) {
        throw runtime_error(NOT_FOUND);
    }
    else if(!all_course_offers[user->findCourseByPost(stoi(input_line[4])) - 1]->getOpenForm()) {
        throw runtime_error(NOT_FOUND);
    }
    else {
        askProfessorForTA(user->findCourseByPost(stoi(input_line[4])) - 1);
        user->removePost(stoi(input_line[4]));
    }
}