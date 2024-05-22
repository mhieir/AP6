#include "University.hpp"
#include "Primary.hpp"

void University::runPersonalPage() {
    if(input_line.size() != REMOVE_POST_MODE_SIZE) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkLogin()) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else if(!isQuestionMark(input_line[2])) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(input_line[3] != ID) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!isNumber(input_line[4])) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkValidId(input_line[4])) {
        throw runtime_error(NOT_FOUND);
    }
    else {
        user->personalPage();
    }
}