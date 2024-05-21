#include "University.hpp"
#include "Primary.hpp"

void University::checkNotInLogoutMode() {
    try {
        if(user != nullptr) {
            user = nullptr;
            throw runtime_error(OK);
        }
        else {
            throw runtime_error(PERMISSION_DENIED);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::checkQuestionMarkLogout() {
    try {
        if(input_line[2] == QUESTION_MARK) {
            checkNotInLogoutMode();
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::runLogout() {
    try {
        if(input_line.size() == LOGOUT_MODE_SIZE) {
            checkQuestionMarkLogout();
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}