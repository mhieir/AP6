#include "University.hpp"
#include "Primary.hpp"

bool University::wasConnected(string id) {
    if(user->inConnection(id)) {
        return true;
    }
    return false;
}

void University::checkConnectionValidInput() {
    try {
        if(input_line[3] != ID) {
            throw runtime_error(BAD_REQUEST);
        }
        else if(isFloatId(input_line[4])) {
            throw runtime_error(BAD_REQUEST);
        }
        else if(!checkValidId(input_line[4])) {
            throw runtime_error(NOT_FOUND);
        }
        else if(wasConnected(input_line[4])) {
            throw runtime_error(BAD_REQUEST);
        }
        else {
            throw runtime_error(OK);
            user->addConnection(input_line[4]);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::checkQuestionMarkConnect() {
    try {
        if(input_line[2] == QUESTION_MARK) {
            checkConnectionValidInput();
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::checkLoginConnect() {
    try {
        if(checkLogin()) {
            checkQuestionMarkConnect();
        }
        else {
            throw runtime_error(PERMISSION_DENIED);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::runConnect() {
    try {
        if(input_line.size() == CONNECT_MODE_SIZE) {
            checkLoginConnect();
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}