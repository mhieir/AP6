#include "University.hpp"
#include "Primary.hpp"

void University::makeMessageText() {
    string title = DEFINE_STRING, message = DEFINE_STRING, image_address = DEFINE_STRING;
    for(int i = 3; i < (int) input_line.size(); i += 2) {
        string input_type = input_line[i], value = input_line[i + 1];
        if(input_type == TITLE) {
            title = value;
        }
        else if(input_type == MESSAGE) {
            message = value;
        }
        else if(input_type == IMAGE) {
            image_address = value;
        }
    }

    if(title == DEFINE_STRING || message == DEFINE_STRING) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(input_line.size() == SHARE_POST_MODE_SIZE_SECOND and image_address == DEFINE_STRING) {
        throw runtime_error(BAD_REQUEST);
    }
    else {
        if(image_address == DEFINE_STRING) image_address = NULL_STRING;
        user->addPost(title, message, image_address, NULL_STRING, _NORMAL, NULL_STRING, 0);
        user->shareNotification(user->getId() + SPACE + user->getName() + COLON + SPACE + NEW_POST + END_LINE);
        throw runtime_error(OK);
    }
}

void University::runSharePost() {
    if(input_line.size() != SHARE_POST_MODE_SIZE_FIRST and input_line.size() != SHARE_POST_MODE_SIZE_SECOND) {
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