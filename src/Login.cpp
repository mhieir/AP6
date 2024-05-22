#include "University.hpp"
#include "Primary.hpp"

bool University::checkValidPassword(string id, string password) {
    for(int i = 0; i < people.size(); i++) {
        if(people[i]->getId() == id and people[i]->getPassword() == password) {
            return true;
        }
    }
    return false;
}

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

void University::checkNotInLoginMode() {
    try {
        if(user == nullptr) {
            loginModeInput();
        }
        else {
            throw runtime_error(PERMISSION_DENIED);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::checkQuestionMark() {
    try {
        if(input_line[2] == QUESTION_MARK) {
            checkNotInLoginMode();
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::runLogin() {
    try {
        if(input_line.size() == LOGIN_MODE_SIZE) {
            checkQuestionMark();
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

