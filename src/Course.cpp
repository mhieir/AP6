#include "Course.hpp"

Course::Course(string id, string name, int credit, int prerequisite, vector<string> majors_id) :
Entity(id, name), credit(credit), prerequisite(prerequisite), majors_id(majors_id) {} 