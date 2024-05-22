#include "University.hpp"
#include "Primary.hpp"

University::University() {
    user = nullptr;
    people.push_back(new UTAccount(ZERO_STRING, UT_ACCOUNT));
    course_offer_id = 0;
}

void University::addMajor(string id, string name) {
    majors.push_back(new Major(id, name));
}

void University::addStudent(string id, string name, string major_id, int semester, string password) {
    people.push_back(new Student(id, name, major_id, semester, password));
}

void University::addCourse(string id, string name, int credit, int prerequisite, vector<string> majors_id) {
    courses.push_back(new Course(id, name, credit, prerequisite, majors_id));
}

void University::addProfessor(string id, string name, string major_id, string string_position, string password) {
    people.push_back(new Professor(id, name, major_id, string_position, password));
}

bool University::checkValidPassword(string id, string password) {
    for(int i = 0; i < people.size(); i++) {
        if(people[i]->getId() == id and people[i]->getPassword() == password) {
            return true;
        }
    }
    return false;
}


bool University::checkValidPostNumber(string post_id) {
    if(!isNumber(post_id)) {
        return false;
    }
    return user->isInPost(stoi(post_id));
}

bool University::checkLogin() {
    if(user != nullptr) {
        return true;
    }
    else {
        return false;
    }
}

bool University::isFloatId(string id) {
    for(char c : id) {
        if(c == DOT) {
            return true;
        }
    }
    return false;
}

bool University::checkValidId(string id) {
    for(int i = 0; i < people.size(); i++) {
        if(people[i]->getId() == id) {
            return true;
        }
    }
    return false;
}

bool University::checkValidCourse(string id) {
    for(int i = 0; i < courses.size(); i++) {
        if(courses[i]->getId() == id) {
            return true;
        }
    }
    return false;
}

bool University::isProfessor(string id) {
    for(int i = 0; i < people.size(); i++) {
        if(people[i]->getPeopleType() == PROFESSSOR and people[i]->getId() == id) {
            return true;
        }
    }
    return false;
}

int University::findPeopleIndexById(string id) {
    for(int i = 0; i < people.size(); i++) {
        if(people[i]->getId() == id) {
            return i;
        }
    }
}

int University::findCourseIndexById(string id) {
    for(int i = 0; i < courses.size(); i++) {
        if(courses[i]->getId() == id) {
            return i;
        }
    }
}

bool University::isPresentByProfessor(string professor_id, string course_id) {
    int professor_index = findPeopleIndexById(professor_id);
    int course_index = findCourseIndexById(course_id);
    return courses[course_index]->hasMajor(people[professor_index]->getMajorId());

}

void University::handlePostRequest() {
    if(input_line[1] == LITTLE_POST) {
        runSharePost();
    }
    else if(input_line[1] == LOGIN) {
        runLogin();
    }
    else if(input_line[1] == LOGOUT) {
        runLogout();
    }
    else if(input_line[1] == CONNECT) {
        runConnect();
    }
    else if(input_line[1] == COURSE_OFFER) {
        runShareCourse();
    }
    else {
        throw runtime_error(NOT_FOUND);
    }

}

void University::handleGetRequest() {
    if(input_line[1] == MY_COURSES) {
        
    }
    else if(input_line[1] == NOTIFICATION) {
        // runLogin();
    }
    else if(input_line[1] == LITTLE_POST) {
        // runLogin();
    }
    else if(input_line[1] == PERSONAL_PAGE) {
        runPersonalPage();
    }
    else if(input_line[1] == COURSES) {

    }
    else {
        throw runtime_error(NOT_FOUND);
    }

}

void University::handleDeleteRequest() {
    if(input_line[1] == LITTLE_POST) {
        runRemovePost();
    }
    else if(input_line[1] == MY_COURSES) {
        // runLogin();
    }
    else {
        throw runtime_error(NOT_FOUND);
    }
}

void University::handleInput() {
    if(input_line[0] == GET) {
        handleGetRequest();
    }
    else if(input_line[0] == POST) {
        handlePostRequest();
    }
    else if(input_line[0] == PUT) {
        handlePutRequest();
    }
    else if(input_line[0] == DELETE) {
        handleDeleteRequest();
    }
    else {
        throw runtime_error(BAD_REQUEST);
    }
}

void University::run(string input_string) {
    input_line = splitByInputSign(input_string, SPACE);
    try {
        if(input_line.size() > 0) {
            handleInput();
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch (runtime_error &e) {
        catchError(e);
    }
}
