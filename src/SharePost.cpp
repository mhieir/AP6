#include "University.hpp"
#include "Primary.hpp"

void University::makeMessageText() {
    if(input_line[3] == TITLE and input_line[5] == MESSAGE) {
        user->addPost(input_line[4], input_line[6]);
        user->shareNotification(user->getId() + SPACE + user->getName() + COLON + SPACE + NEW_POST + '\n');
        throw runtime_error(OK);
    }
    else if(input_line[5] == TITLE and input_line[3] == MESSAGE) {
        user->addPost(input_line[6], input_line[4]);
        user->shareNotification(user->getId() + SPACE + user->getName() + COLON + SPACE + NEW_POST + '\n');
        throw runtime_error(OK);
    }
    else {
        throw runtime_error(BAD_REQUEST);
    }
}

void University::runSharePost() {
    if(input_line.size() != SHARE_POST_MODE_SIZE) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkLogin()) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else if(!isQuestionMark(input_line[2])) {
        throw runtime_error(BAD_REQUEST);
    }
    else {
        makeMessageText();
    }
}