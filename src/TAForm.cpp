#include "University.hpp"
#include "Primary.hpp"

void University::validInputTAForm() {
    string course_id = DEFINE_STRING, message = DEFINE_STRING;
    for(int i = 3; i < (int) input_line.size(); i += 2) {
        string input_type = input_line[i], value = input_line[i + 1];
        if(input_type == COURSE_ID) {
            course_id = value;
        }
        else if(input_type == MESSAGE) {
            message = value;
        }
    }

    if(course_id == DEFINE_STRING || message == DEFINE_STRING) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!isNumber(course_id)) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(stoi(course_id) == 0) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(stoi(course_id) >= course_offer_id) {
        throw runtime_error(NOT_FOUND);
    }
    else if(!user->hasCourseOfferById(stoi(course_id))) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else {
        all_course_offers[stoi(course_id) - 1]->changeStatusTAForm();
        user->addPost(TA_FORM_FOR + all_course_offers[stoi(course_id) - 1]->getName() + SPACE_COURSE, message,
         NULL_STRING, user->getName(), _TA_FORM, course_id + SPACE + all_course_offers[stoi(course_id) - 1]->getName() + SPACE  +
         to_string(all_course_offers[stoi(course_id) - 1]->getCapacity()) + SPACE + user->getName() + SPACE + all_course_offers[stoi(course_id) - 1]->getTime() + SPACE +
         all_course_offers[stoi(course_id) - 1]->getExamTime() + SPACE + to_string(all_course_offers[stoi(course_id) - 1]->getClassNumber()));
        user->shareNotification(user->getId() + SPACE + user->getName() + COLON + SPACE + NEW_FORM + END_LINE);
        throw runtime_error(OK);
    }
}

void University::runPostTAForm() {
    if(input_line.size() != POST_TA_FORM_MODE_SIZE) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!isQuestionMark(input_line[2])) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkLogin() || !isProfessor(user->getId())) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else {
        validInputTAForm();
    }
}