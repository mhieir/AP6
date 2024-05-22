#include "University.hpp"
#include "Primary.hpp"

void University::findPeopleById(string id) {
    for(int i = 0; i < people.size(); i++) {
        if(people[i]->getId() == id) {
            user = people[i];
        }
    }
}

void University::loginModeInput() {
    string id = NULL_STRING, password = NULL_STRING;
    for(int i = 3; i < 7; i += 2) {
        string input_type = input_line[i], value = input_line[i + 1];
        if(input_type == ID) {
            id = value;
        }
        else if(input_type == PASSWORD) {
            password = value;
        }
    }
    try {
        if(!checkValidId(id)) {
            throw runtime_error(NOT_FOUND);
        }
        else if(!checkValidPassword(id, password)) {
            throw runtime_error(PERMISSION_DENIED);
        }
        else {
            findPeopleById(id);
            throw runtime_error(OK);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::runLogin() {
    if(input_line.size() != LOGIN_MODE_SIZE) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!isQuestionMark(input_line[2])) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(user != nullptr) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else {
        loginModeInput();
    }
}