#include "Logout.hpp"
#include "Primary.hpp"

Logout::Logout(vector<string> input_line, People* user) : user(user), input_line(input_line) {}

void Logout::checkNotInLogoutMode() {
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

void Logout::checkQuestionMarkLogout() {
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

void Logout::checkInputSizeLogout() {
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