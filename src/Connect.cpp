#include "University.hpp"
#include "Primary.hpp"

void University::runConnect() {
    if(input_line.size() != CONNECT_MODE_SIZE) {
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
    else if(isFloatId(input_line[4])) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkValidId(input_line[4])) {
        throw runtime_error(NOT_FOUND);
    }
    else if(user->inConnection(input_line[4])) {
        throw runtime_error(BAD_REQUEST);
    }
    else {
        user->addConnection(people[findPeopleIndexById(input_line[4])]);
        throw runtime_error(OK);
    }
}