#include "University.hpp"
#include "Primary.hpp"

void University::validInputTARequest() {
    string professor_id = DEFINE_STRING, form_id = DEFINE_STRING;
    for(int i = 3; i < (int) input_line.size(); i += 2) {
        string input_type = input_line[i], value = input_line[i + 1];
        if(input_type == FORM_ID) {
            form_id = value;
        }
        else if(input_type == PROFESSOR_ID) {
            professor_id = value;
        }
    }

    if(professor_id == DEFINE_STRING || form_id == DEFINE_STRING) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!isNumber(form_id)) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!isProfessor(professor_id)) {
        throw runtime_error(NOT_FOUND);
    }
    else if(stoi(form_id) == 0) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!people[findPeopleIndexById(professor_id)]->isInPost(stoi(form_id))){
        throw runtime_error(NOT_FOUND);
    }
    else if(!people[findPeopleIndexById(professor_id)]->isTAForm(stoi(form_id))){
        throw runtime_error(NOT_FOUND);
    }
    else if(user->getSemester() <= all_course_offers[people[findPeopleIndexById(professor_id)]->findCourseByPost(stoi(form_id)) - 1]->getPrerequisite()) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else {
        all_course_offers[people[findPeopleIndexById(professor_id)]->findCourseByPost(stoi(form_id)) - 1]->addRequestedTA(user->getId());
        throw runtime_error(OK);
    }
}

void University::runTARequest() {
    if(input_line.size() != TA_REQUEST_MODE_SIZE) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!isQuestionMark(input_line[2])) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkLogin() || !isStudent()) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else {
        validInputTARequest();
    }
}