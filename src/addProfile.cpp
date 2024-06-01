#include "University.hpp"
#include "Primary.hpp"

void University::runAddProfile() {
    if(input_line.size() != ADD_PROFILE_MODE_SIZE) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkLogin()) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else if(user->getId() == ZERO_STRING) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else if(!isQuestionMark(input_line[2])) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(input_line[3] != PHOTO) {
        throw runtime_error(BAD_REQUEST);
    }
    else {
        user->addProfile(input_line[4]);
        throw runtime_error(OK);
    }
}