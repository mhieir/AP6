#include "University.hpp"
#include "Primary.hpp"

void University::makeMessageTextCoursePost() {
    string id = DEFINE_STRING, title = DEFINE_STRING, message = DEFINE_STRING, image_address = DEFINE_STRING;
    for(int i = 3; i < (int) input_line.size(); i += 2) {
        string input_type = input_line[i], value = input_line[i + 1];
        if(input_type == TITLE) {
            title = value;
        }
        else if(input_type == MESSAGE) {
            message = value;
        }
        else if(input_type == ID) {
            id = value;
        }
        else if(input_type == IMAGE) {
            image_address = value;
        }
    }

    if(id == DEFINE_STRING || title == DEFINE_STRING || message == DEFINE_STRING) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!isNumber(id)) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(stoi(id) == ZERO) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(stoi(id) >= course_offer_id) {
        throw runtime_error(NOT_FOUND);
    }
    else if(user->getPeopleType() == _STUDENT and !all_course_offers[stoi(id) - 1]->isTA(user->getId())) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else if(user->getPeopleType() == _PROFESSOR and !all_course_offers[stoi(id) - 1]->isProfessor(user->getId())) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else if(input_line.size() == COURSE_POST_MODE_SIZE_SECOND and image_address == DEFINE_STRING) {
        throw runtime_error(BAD_REQUEST);
    }
    else {
        if(image_address == DEFINE_STRING) image_address = NULL_STRING;
        all_course_offers[stoi(id) - 1]->addPost(title, message, image_address, user->getName(), _NORMAL, NULL_STRING, ZERO);
        addNotificationCoursePost(stoi(id) - 1, id + SPACE + all_course_offers[stoi(id) - 1]->getName() + COLON + SPACE + NEW_COURSE_POST + END_LINE);
       throw runtime_error(OK);

    }
}

void University::runCoursePost() {
    if(input_line.size() != COURSE_POST_MODE_SIZE_FIRST and input_line.size() != COURSE_POST_MODE_SIZE_SECOND) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkLogin()) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else if(!isQuestionMark(input_line[2])) {
        throw runtime_error(BAD_REQUEST);
    }
    else {
        makeMessageTextCoursePost();
    }
}