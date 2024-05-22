#include "University.hpp"
#include "Primary.hpp"

void University::makeMessageText() {
    vector<int> quotion = findQuotion(input_line);

    if(quotion.size() != 4) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(quotion[0] != 4) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(quotion[3] + 1 != (int) input_line.size()) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(input_line[quotion[0] - 1] == TITLE and input_line[quotion[2] - 1] == MESSAGE) {
        user->addPost(makeText(input_line, quotion[0], quotion[1]), makeText(input_line, quotion[2], quotion[3]));
        throw runtime_error(OK);
    }
    else if(input_line[quotion[0] - 1] == MESSAGE and input_line[quotion[2] - 1] == TITLE) {
        user->addPost(makeText(input_line, quotion[2], quotion[3]), makeText(input_line, quotion[0], quotion[1]));
        throw runtime_error(OK);
    }
    else {
        throw runtime_error(BAD_REQUEST);
    }
}

void University::runSharePost() {
    if(input_line.size() < SHARE_POST_MODE_SIZE) {
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