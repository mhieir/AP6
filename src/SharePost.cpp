#include "University.hpp"
#include "Primary.hpp"

string University::makeText(int start, int end) {
    string result = NULL_STRING;
    for(int i = start; i <= end; i++) {
        result += input_line[i] + SPACE;
    }
    result = result.substr(0, int(result.size()) - 2);
    result = result.substr(1, int(result.size()) - 1);
    return result;
}

void University::makeMessageText() {
    vector<int> quotion;
    for(int i = 3; i < input_line.size(); i++) {
        if(input_line[i][0] == QUOTION) {
            quotion.push_back(i);
        }
        if(input_line[i].back() == QUOTION) {
            quotion.push_back(i);
        }
    }
    try {
        if(quotion.size() != 4) {
            throw runtime_error(BAD_REQUEST);
        }
        else if(quotion[0] != 4) {
            throw runtime_error(BAD_REQUEST);
        }
        else if(quotion[3] + 1 != input_line.size()) {
            throw runtime_error(BAD_REQUEST);
        }
        else if(input_line[quotion[0] - 1] == TITLE and input_line[quotion[2] - 1] == MESSAGE) {
            user->addPost(makeText(quotion[0], quotion[1]), makeText(quotion[2], quotion[3]));
            throw runtime_error(OK);
        }
        else if(input_line[quotion[0] - 1] == MESSAGE and input_line[quotion[2] - 1] == TITLE) {
            user->addPost(makeText(quotion[2], quotion[3]), makeText(quotion[0], quotion[1]));
            throw runtime_error(OK);
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::checkQuestionMarkSharePost() {
    try {
        if(input_line[2] == QUESTION_MARK) {
            makeMessageText();
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::runSharePost() {
    try {
        if(input_line.size() >= SHARE_POST_MODE_SIZE) {
            checkQuestionMarkSharePost();
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}