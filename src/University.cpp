#include "University.hpp"
#include "Primary.hpp"

void University::makeMajorString(vector<string> major_string) {
    for(int i = 1; i < major_string.size(); i++) {
        vector<string> splitted = splitByInputSign(major_string[i], COMMA);
        majors.push_back(new Major(splitted[0], splitted[1]));
    }
}

void University::makeStudentString(vector<string> student_string) {
    for(int i = 1; i < student_string.size(); i++) {
        vector<string> splitted = splitByInputSign(student_string[i], COMMA);
        people.push_back(new Student(splitted[0], splitted[1], splitted[2], stoi(splitted[3]), splitted[4]));
    }
}

void University::makeCourseString(vector<string> course_string) {
    for(int i = 1; i < course_string.size(); i++) {
        vector<string> splitted = splitByInputSign(course_string[i], COMMA);
        courses.push_back(new Course(splitted[0], splitted[1], stoi(splitted[2]), stoi(splitted[3]), splitByInputSign(splitted[4], SEMI_COLON)));
    }
}

void University::makeProfessorString(vector<string> professor_string) {
    for(int i = 1; i < professor_string.size(); i++) {
        vector<string> splitted = splitByInputSign(professor_string[i], COMMA);
        people.push_back(new Professor(splitted[0], splitted[1], splitted[2], splitted[3], splitted[4]));
    }
}

University::University(char *argv[]) {
    makeMajorString(read_csv(argv[1]));
    makeStudentString(read_csv(argv[2]));
    makeCourseString(read_csv(argv[3]));
    makeProfessorString(read_csv(argv[4]));
    user = nullptr;
}

void University::checkNotInLoginMode() {
    try {
        if(user != nullptr) {
            throw runtime_error(PERMISSION_DENIED);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::checkPassword(People* person, string password) {
    try {
        if(person->getPassword() == password) {
            user = person;
            throw runtime_error(OK);
        }
        else {
            throw runtime_error(PERMISSION_DENIED);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::checkValidInfo(string id, string password) {
    try {
        for(int i = 0; i < people.size(); i++) {
            if(people[i]->getId() == id) {
                checkPassword(people[i], password);
            }
        }
        if(user == nullptr) {
            throw runtime_error(NOT_FOUND);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::loginModeInput() {
    string id = NULL_STRING, password = NULL_STRING;
    for(int i = 0; i < 2; i++) {
        try {
            string input_type, value;
            cin >> input_type >> value;
            if(input_type == ID) {
                id = value;
            }
            else if(input_type == PASSWORD) {
                password = value;
            }
            else {
                throw runtime_error(PERMISSION_DENIED);
            }
        } catch(runtime_error& ex) {
            catchError(ex);
        }
    }
    checkValidInfo(id, password);
}

void University::handleLoginMode() {
    checkNotInLoginMode();
    loginModeInput();
}

void University::handlePostRequest() {
    try {
        string new_input;
        cin >> new_input;
        if(new_input == LITTLE_POST) {
            checkQuestionMark();
        }
        else if(new_input == LOGIN) {
            checkQuestionMark();
            handleLoginMode();
        }
        else if(new_input == LOGOUT) {
            checkQuestionMark();
        }
        else if(new_input == CONNECT) {
            checkQuestionMark();
        }
        else if(new_input == COURSE_OFFER) {
            checkQuestionMark();
        }
        else {
            throw runtime_error(NOT_FOUND);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::handleInput() {
    try {
        string new_input;
        cin >> new_input;
        if(new_input == GET) {
            handleGetRequest();
        }
        else if(new_input == POST) {
            handlePostRequest();
        }
        else if(new_input == PUT) {
            handlePutRequest();
        }
        else if(new_input == DELETE) {
            handleDeleteRequest();
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::run() {
    while(true) {
        handleInput();
        if(user != nullptr) cout << user->getId() << endl;
    }
}