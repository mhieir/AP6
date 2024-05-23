#include "University.hpp"
#include "Primary.hpp"

void University::validGetPostInput() {
    string id = NULL_STRING, post_id = NULL_STRING;
    for(int i = 3; i < 7; i += 2) {
        string input_type = input_line[i], value = input_line[i + 1];
        if(input_type == ID) {
            id = value;
        }
        else if(input_type == POST_ID) {
            post_id = value;
        }
    }
    if(!isNumber(id) || !isNumber(post_id)) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkValidId(id) || !checkValidPostNumberById(post_id, id)) {
        throw runtime_error(NOT_FOUND);
    }
    else {
        string major_name;
        if(input_line[4] != ZERO_STRING) {
            major_name = majors[findMajor(people[findPeopleIndexById(input_line[4])]->getMajorId())]->getName();
        }
        user->getPost(major_name, stoi(post_id));
    }
}

void University::runGetPost() {
    if(input_line.size() != GET_POST_MODE_SIZE) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkLogin()) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else if(!isQuestionMark(input_line[2])) {
        throw runtime_error(BAD_REQUEST);
    }
    else {
        validGetPostInput();
    }
}