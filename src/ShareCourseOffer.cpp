#include "University.hpp"
#include "Primary.hpp"

void University::shareCourseModeInput() {
    string course_id = NULL_STRING, professor_id = NULL_STRING, capacity = NULL_STRING,
    time = NULL_STRING, exam_date = NULL_STRING, class_number = NULL_STRING;
    for(int i = 3; i < 15; i += 2) {
        string input_type = input_line[i], value = input_line[i + 1];
        if(input_type == COURSE_ID) {
            course_id = value;
        }
        else if(input_type == PROFESSOR_ID) {
            professor_id = value;
        }
        else if(input_type == CAPACITY) {
            capacity = value;
        }
        else if(input_type == TIME) {
            time = value;
        }
        else if(input_type == EXAM_DATE) {
            exam_date = value;
        }
        else if(input_type == CLASS_NUMBER) {
            class_number = value;
        }
    }

    if(!isNumber(course_id) || !isNumber(professor_id) || !isNumber(capacity) || !isNumber(class_number)) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkValidId(professor_id) || !checkValidCourse(course_id)) {
        throw runtime_error(NOT_FOUND);
    }
    else if(!isProfessor(professor_id)) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else if(!isPresentByProfessor(professor_id, course_id)) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else {

    }
}

void University::runShareCourse() {
    course_offer_id++;
    if(input_line.size() != SHARE_COURSE_MODE_SIZE) {
        throw runtime_error(BAD_REQUEST);
    }
    else if(!checkLogin()) {
        throw runtime_error(PERMISSION_DENIED);
    }
    else if(!isQuestionMark(input_line[2])) {
        throw runtime_error(BAD_REQUEST);
    }
    else {
        shareCourseModeInput();
    }
}