#include "Student.hpp"

Student::Student(string id, string name, string major_id, int semester, string password) :
People(id, name, major_id, password, STUDENT), semester(semester) {}

void Student::personalPage() {
    // cout << name << " " << major << " " << semester << " ";
    // for(int i = 0; i + 1 < offer_courses.size(); i++) {
    //     cout << offer_courses[i].getName() << COMMA;
    // }
    // if(offer_courses.size())
    cout << "fuck" << endl;
}