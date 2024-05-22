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

    string makeText(int start, int end);
    void makeMessageText();
    void checkQuestionMarkSharePost();
    void runSharePost();
    bool isFloatId(string id);
    bool checkLogin();
    void checkLoginConnect();
    void checkConnectionValidInput();
    void checkQuestionMarkConnect();
    bool checkValidPassword(string id, string password);
    bool checkValidId(string id);
    void findPeopleById(string id);
    void loginModeInput();
    void checkNotInLoginMode();
    void checkQuestionMark();
    void runLogin();
    void runLogout();
    void runConnect();
    void checkNotInLogoutMode();
    void checkQuestionMarkLogout();
    void checkInputSize(string input_string);
    void handleInput();
    void handleGetRequest() {};
    void handlePostRequest();
    void handlePutRequest() {};
    void handleDeleteRequest() {};
    bool wasConnected(string id);
    void makeMajorString(vector<string> major_string);
    void makeStudentString(vector<string> student_string);
    void makeCourseString(vector<string> course_string);
    void makeProfessorString(vector<string> professor_string);
};

#endif