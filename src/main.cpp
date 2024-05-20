#include "Global.hpp"
#include "Student.hpp"
#include "Professor.hpp"
#include "Course.hpp"
#include "Entity.hpp"
#include "Major.hpp"
#include "University.hpp"

int main(int argc, char *argv[]){
    University* university = new University(argv);
    university->run();
}