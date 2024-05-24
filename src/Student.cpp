#include "Student.hpp"

Student::Student(string id, string name, Major* major, int semester, string password) :
People(id, name, major, password, _STUDENT), semester(semester) {}

void Student::personalPage() {
    cout << name << " " << major->getName() << " " << semester << " ";
    People ::showOfferCourses();
    People ::showPosts();
}

void Student::getPost(int post_id) {
    cout << name << " " << major->getName() << " " << semester << " ";
    People ::showOfferCourses();
    People ::showOnePost(post_id);
}