#include "Interface.hpp"
#include "Primary.hpp"

void Interface::makeMajorString(vector<string> major_string) {
    for(int i = 1; i < major_string.size(); i++) {
        vector<string> splitted = splitByInputSign(major_string[i], COMMA);
        university->addMajor(splitted[0], splitted[1]);
    }
}

void Interface::makeStudentString(vector<string> student_string) {
    for(int i = 1; i < student_string.size(); i++) {
        vector<string> splitted = splitByInputSign(student_string[i], COMMA);
        university->addStudent(splitted[0], splitted[1], university->getMajorById(university->findMajor(splitted[2])), stoi(splitted[3]), splitted[4]);
    }
}

void Interface::makeCourseString(vector<string> course_string) {
    for(int i = 1; i < course_string.size(); i++) {
        vector<string> splitted = splitByInputSign(course_string[i], COMMA);
        university->addCourse(splitted[0], splitted[1], stoi(splitted[2]), stoi(splitted[3]), splitByInputSign(splitted[4], SEMI_COLON));
    }
}

void Interface::makeProfessorString(vector<string> professor_string) {
    for(int i = 1; i < professor_string.size(); i++) {
        vector<string> splitted = splitByInputSign(professor_string[i], COMMA);
        university->addProfessor(splitted[0], splitted[1], university->getMajorById(university->findMajor(splitted[2])), splitted[3], splitted[4]);
    }
}

Interface::Interface(char *argv[]) {
    university = new University;
    makeMajorString(read_csv(argv[1]));
    makeStudentString(read_csv(argv[2]));
    makeCourseString(read_csv(argv[3]));
    makeProfessorString(read_csv(argv[4]));
}

void Interface::showOutput(vector<string> outputs) {
    for(string output : outputs) {
        cout << output;
    }
}

void Interface::run() {
    university->makeDefaultConnections();
    string line;
    while (getline(cin, line)) {
        university->run(line);
        showOutput(university->getOutput());
        university->cleanOutput();
    }
}
