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

bool University::checkValidPassword(string id, string password) {
    for(int i = 0; i < people.size(); i++) {
        if(people[i]->getId() == id and people[i]->getPassword() == password) {
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

void University::loginModeInput() {
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
        if(!checkValidId(id)) {
            throw runtime_error(NOT_FOUND);
        }
        else if(!checkValidPassword(id, password)) {
            throw runtime_error(PERMISSION_DENIED);
        }
        else {
            throw runtime_error(OK);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::checkNotInLoginMode() {
    try {
        if(user == nullptr) {
            loginModeInput();
        }
        else {
            throw runtime_error(PERMISSION_DENIED);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

// void University::checkNotInLogoutMode() {
//     try {
//         if(user != nullptr) {
//             cout << 2;
//         }
//         else {
//             throw runtime_error(PERMISSION_DENIED);
//         }
//     } catch(runtime_error& ex) {
//         catchError(ex);
//     }
// }

// void University::handleLogoutMode() {
//     checkNotInLogoutMode();
//     checkQuestionMark();
//     okMode();
// }

void University::checkQuestionMarkLogin() {
    try {
        if(input_line[2] == QUESTION_MARK) {
            checkNotInLoginMode();
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::handlePostRequest() {
    try {
        if(input_line[1] == LITTLE_POST) {
            checkQuestionMark();
        }
        else if(input_line[1] == LOGIN) {
            checkQuestionMarkLogin();
        }
        else if(input_line[1] == LOGOUT) {
            checkQuestionMark();
            // handleLogoutMode();
        }
        else if(input_line[1] == CONNECT) {
            checkQuestionMark();
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

void University::checkInputSize() {
    try {
        if(input_line.size() == LOGIN_MODE_SIZE) {
            handleInput();
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void University::getInput() {
    string input_string;
   
    if(cin.peek() == '\n') cin.clear();

    getline(cin, input_string);
  
  //  getline(cin, input_string);
    //
    // if (getline(cin, input_string)) {
    //     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // }
	input_line = splitByInputSign(input_string, SPACE);
}

void University::run() {
    while(true) {
        getInput();
        checkInputSize();
        if(user != nullptr) cout << user->getId() << endl;
    }
}