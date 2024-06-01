#pragma once
#ifndef INTERFACE_INCLUDE
#define INTERFACE_INCLUDE

#include "Global.hpp"
#include "University.hpp"

class Interface {
public:
    Interface(char *argv[]);
    ~Interface() {};
    void run();
protected:
private:
    University* university;

    void showOutput(vector<string> outputs);
    void makeMajorString(vector<string> major_string);
    void makeStudentString(vector<string> student_string);
    void makeCourseString(vector<string> course_string);
    void makeProfessorString(vector<string> professor_string);
};

#endif