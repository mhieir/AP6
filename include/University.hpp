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
    University();
    ~University() {};
    void run(string input_string);
    void addMajor(string id, string name);
    void addStudent(string id, string name, string major_id, int semester, string password);
    void addProfessor(string id, string name, string major_id, string string_position, string password);
    void addCourse(string id, string name, int credit, int prerequisite, vector<string> majors_id);
protected:
private:
    vector<Major*> majors;
    vector<People*> people;
    vector<Course*> courses;
    vector<string> input_line;
    People* user;


    void makeMessageText();
    void runSharePost();
    void runRemovePost();
    bool isFloatId(string id);
    bool checkLogin();
    bool checkValidPassword(string id, string password);
    bool checkValidId(string id);
    void findPeopleById(string id);
    void loginModeInput();
    void runLogin();
    void runLogout();
    void runConnect();
    void runPersonalPage();
    bool checkValidPostNumber(string post_id);
    void handleInput();
    void handleGetRequest();
    void handlePostRequest();
    void handlePutRequest() {};
    void handleDeleteRequest();
};

#endif