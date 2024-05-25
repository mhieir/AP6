#include "University.hpp"
#include "Primary.hpp"

void University::runNotification(){
    if(input_line.size() != NOTIFICATION_MODE_SIZE) {
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
    else if(user->emptyNotification()) {
        throw runtime_error(EMPTY);
    }
    else {
        user->printNotification(output);
    }
}