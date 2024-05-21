#ifndef UNIVERSITY_INCLUDE
#define UNIVERSITY_INCLUDE

#include "Global.hpp"
#include "Entity.hpp"
#include "Course.hpp"
#include "Major.hpp"
#include "People.hpp"
#include "Student.hpp"
#include "Professor.hpp"

class University {
public:
    University(char *argv[]);
    ~University() {};
    void run();
protected:
private:
    vector<Major*> majors;
    vector<People*> people;
    vector<Course*> courses;
    vector<string> input_line;
    People* user;

    bool checkValidId(string id);
    bool checkValidPassword(string id, string password);
    void checkQuestionMarkLogin();
    void checkInputSize(string input_string);
    void loginModeInput();
    void handleInput();
    void checkNotInLoginMode();
    void handleGetRequest() {};
    void handlePostRequest();
    void handlePutRequest() {};
    void handleDeleteRequest() {};
    void makeMajorString(vector<string> major_string);
    void makeStudentString(vector<string> student_string);
    void makeCourseString(vector<string> course_string);
    void makeProfessorString(vector<string> professor_string);
};

#endif