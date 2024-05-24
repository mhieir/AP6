#include "University.hpp"
#include "Primary.hpp"

void University::runGetMyCourse() {
    if(input_line.size() != GET_MY_COURSE_MODE_SIZE) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkLogin()) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else if(!isQuestionMark(input_line[2])) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(user->numberOfCourses() == 0) {
        throw runtime_error(EMPTY);
    }
    else {
        user->showCourses(people);
        
    }
}

