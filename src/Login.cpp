#include "Login.hpp"
#include "Primary.hpp"

Login::Login(vector<string> input_line) : input_line(input_line) {}

bool Login::checkValidPassword(string id, string password, People* &user, vector<People*> &people) {
    for(int i = 0; i < people.size(); i++) {
        if(people[i]->getId() == id and people[i]->getPassword() == password) {
            return true;
        }
    }
    return false;
}

bool Login::checkValidId(string id, People* &user, vector<People*> &people) {
    for(int i = 0; i < people.size(); i++) {
        if(people[i]->getId() == id) {
            return true;
        }
    }
    return false;
}

void Login::findPeopleById(string id, People* &user, vector<People*> &people) {
    for(int i = 0; i < people.size(); i++) {
        if(people[i]->getId() == id) {
            user = people[i];
        }
    }
}

void Login::loginModeInput(People* &user, vector<People*> &people) {
    string id = NULL_STRING, password = NULL_STRING;
    for(int i = 3; i < 7; i += 2) {
        string input_type = input_line[i], value = input_line[i + 1];
        if(input_type == ID) {
            id = value;
        }
        else if(input_type == PASSWORD) {
            password = value;
        }
    }
    try {
        if(!checkValidId(id, user, people)) {
            throw runtime_error(NOT_FOUND);
        }
        else if(!checkValidPassword(id, password, user, people)) {
            throw runtime_error(PERMISSION_DENIED);
        }
        else {
            findPeopleById(id, user, people);
            throw runtime_error(OK);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void Login::checkNotInLoginMode(People* &user, vector<People*> &people) {
    try {
        if(user == nullptr) {
            loginModeInput(user, people);
        }
        else {
            throw runtime_error(PERMISSION_DENIED);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void Login::checkQuestionMark(People* &user, vector<People*> &people) {
    try {
        if(input_line[2] == QUESTION_MARK) {
            checkNotInLoginMode(user, people);
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void Login::run(People* &user, vector<People*> &people) {
    try {
        if(input_line.size() == LOGIN_MODE_SIZE) {
            checkQuestionMark(user, people);
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

