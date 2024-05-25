#include "Student.hpp"

Student::Student(string id, string name, Major* major, int semester, string password) :
People(id, name, major, password, _STUDENT), semester(semester) {}

void Student::personalPage(vector<string>& output) {
    output.push_back(name + SPACE + major->getName() + SPACE + to_string(semester) + SPACE);
    People ::showOfferCourses(output);
    People ::showPosts(output);
}

void Student::getPost(vector<string>& output, int post_id) {
    output.push_back(name + SPACE + major->getName() + SPACE + to_string(semester) + SPACE);
    People ::showOfferCourses(output);
    People ::showOnePost(output, post_id);
}