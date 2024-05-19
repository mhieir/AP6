#include "Student.hpp"

Student::Student(string id, string name, string major_id, int semester, string password) :
People(id, name, major_id, password), semester(semester) {}