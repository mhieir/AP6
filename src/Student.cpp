#include "Student.hpp"

Student::Student(string id, string name, string major_id, int semester, string password) :
People(id, name, major_id, password, _STUDENT), semester(semester) {}

void Student::personalPage(string major_name) {
    cout << name << " " << major_name << " " << semester << " ";
    People ::showOfferCourses();
    People ::showPosts();
}

void Student::getPost(string major_name, int post_id) {
    cout << name << " " << major_name << " " << semester << " ";
    People ::showOfferCourses();
    People ::showOnePost(post_id);
}