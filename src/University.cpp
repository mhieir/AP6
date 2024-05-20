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

void University::handleInput() {
    try {
        string new_input;
        cin >> new_input;
        if(!invalidInput(new_input)) throw runtime_error(BAD_REQUEST);
    }
    catch(runtime_error& ex) {
        cerr << ex.what() << endl;
    }
}

void University::run() {
    while(true) {
        handleInput();
    }
}