#include "Course.hpp"

Course::Course(string id, string name, int credit, int prerequisite, string majors_id_string) :
University(id, name), credit(credit), prerequisite(prerequisite), majors_id_string(majors_id_string) {}