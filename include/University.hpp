#ifndef UNIVERSITY_INCLUDE
#define UNIVERSITY_INCLUDE

#include "Global.hpp"
#include "Entity.hpp"
#include "Course.hpp"
#include "Major.hpp"
#include "People.hpp"
#include "Student.hpp"
#include "Professor.hpp"
#include "UTAccount.hpp"
#include "CourseOffer.hpp"

class University {
public:
    University();
    ~University() {};
    void run(string input_string);
    void addMajor(string id, string name);
    void addStudent(string id, string name, Major* major, int semester, string password);
    void addProfessor(string id, string name, Major* major, string string_position, string password);
    int findMajor(string id);
    Major* getMajorById(int index);
    void addCourse(string id, string name, int credit, int prerequisite, vector<string> majors_id);
    vector<string> getOutput() {return output;}
    void cleanOutput() {output.clear();}
    void makeDefaultConnections();
protected:
private:
    vector<Major*> majors;
    vector<People*> people;
    vector<Course*> courses;
    vector<string> input_line;
    vector<CourseOffer*> all_course_offers;
    vector<string> output;
    People* user;
    int course_offer_id;

    void runCloseTAForm();
    void validInputTAForm();
    void runPostTAForm();
    void makeMessageTextCoursePost();
    void addNotificationCoursePost(int index, string notification_line);
    void runCoursePost();
    void runAddProfile();
    void runNotification();
    void runGetMyCourse();
    void runDeleteCourse();
    bool isStudent();
    void runPutCourse();
    bool checkValidPostNumberById(string post_id, string id);
    void validGetPostInput();
    void runGetPost();
    void runGetCourse();
    bool inCommonTime(string professor_id, string time);
    bool isPresentByProfessor(string professor_id, string course_id);
    int findCourseIndexById(string id);
    int findPeopleIndexById(string id);
    bool isProfessor(string id);
    bool checkValidCourse(string id);
    void shareCourseModeInput();
    void makeMessageText();
    void runSharePost();
    void runRemovePost();
    void runShareCourse();
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
    void handleInput();
    void handleGetRequest();
    void handlePostRequest();
    void handlePutRequest();
    void handleDeleteRequest();
    void showAllCourseOffers();
    void showOneCourseOffers(int index);
    void catchError(runtime_error& ex);
    void askProfessorForTA(int index);
    void askQuestion(string output_line);
    void runTARequest();
    void validInputTARequest();

};

#endif