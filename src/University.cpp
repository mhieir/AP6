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

bool University::checkLogin() {
    if(user != nullptr) {
        return true;
    }
    else {
        return false;
    }
}

bool University::isFloatId(string id) {
    for(char c : id) {
        if(c == DOT) {
            return true;
        }
    }
    return false;
}

bool University::checkValidId(string id) {
    for(int i = 0; i < people.size(); i++) {
        if(people[i]->getId() == id) {
            return true;
        }
    }
    return false;
}

void University::handlePostRequest() {
    try {
        if(input_line[1] == LITTLE_POST) {
            runSharePost();
        }
        else if(input_line[1] == LOGIN) {
            runLogin();
        }
        else if(input_line[1] == LOGOUT) {
            runLogout();
        }
        else if(input_line[1] == CONNECT) {
            runConnect();
        }
        else if(input_line[1] == COURSE_OFFER) {
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
        if(input_line[0] == GET) {
            handleGetRequest();
        }
        else if(input_line[0] == POST) {
            handlePostRequest();
        }
        else if(input_line[0] == PUT) {
            handlePutRequest();
        }
        else if(input_line[0] == DELETE) {
            handleDeleteRequest();
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::checkInputSize(string input_string) {
    input_line = splitByInputSign(input_string, SPACE);
    try {
        if(input_line.size() > 0) {
            handleInput();
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::run() {
    string line;
    while (getline(cin, line)) {
        try {
            checkInputSize(line);
        } catch (exception &e) {
        cout << BAD_REQUEST << endl;
        }
    }
}