#include "University.hpp"
#include "Primary.hpp"

void University::validGetCoursePostInput() {
    string id = NULL_STRING, post_id = NULL_STRING;
    for(int i = 3; i < 7; i += 2) {
        string input_type = input_line[i], value = input_line[i + 1];
        if(input_type == ID) {
            id = value;
        }
        else if(input_type == POST_ID) {
            post_id = value;
        }
    }

    if(!isNumber(id) || !isNumber(post_id)) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(stoi(post_id) == ZERO || stoi(id) == ZERO) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(stoi(id) >= course_offer_id) {
        throw runtime_error(NOT_FOUND);
    }
    else if(!all_course_offers[stoi(id) - 1]->isInPost(stoi(post_id))) {
        throw runtime_error(NOT_FOUND);
    }
    else if(!all_course_offers[stoi(input_line[4]) - 1]->isInCourse(user->getId())) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else {
        showOneCourseOffers(stoi(id) - 1);
        all_course_offers[stoi(id) - 1]->showOnePostCourseChannel(output, stoi(post_id));
    }
}

void University::runGetPostCourseChannel() {
    if(input_line.size() != GET_COURSE_POST_SIZE) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!isQuestionMark(input_line[2])) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkLogin()) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else if(user->getId() == ZERO_STRING) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else {
        validGetCoursePostInput();
    }
}