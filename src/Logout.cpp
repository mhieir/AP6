#include "University.hpp"
#include "Primary.hpp"

void University::runLogout() {
    if(input_line.size() != LOGOUT_MODE_SIZE) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!isQuestionMark(input_line[2])) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkLogin()) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else {
        user = nullptr;
        throw runtime_error(OK);
    }
}