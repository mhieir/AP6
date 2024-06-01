#include "University.hpp"
#include "Primary.hpp"

University::University() {
    user = nullptr;
    course_offer_id = START_ID;
}

void University::addMajor(string id, string name) {
    majors.push_back(new Major(id, name));
}

void University::addStudent(string id, string name, Major* major, int semester, string password) {
    people.push_back(new Student(id, name, major, semester, password));
}

void University::addCourse(string id, string name, int credit, int prerequisite, vector<string> majors_id) {
    courses.push_back(new Course(id, name, credit, prerequisite, majors_id));
}

void University::addProfessor(string id, string name, Major* major, string string_position, string password) {
    people.push_back(new Professor(id, name, major, string_position, password));
}

void University::catchError(runtime_error& ex) {
    output.push_back(string(ex.what()) + END_LINE);
}

bool University::checkValidPassword(string id, string password) {
    for(int i = 0; i < people.size(); i++) {
        if(people[i]->getId() == id and people[i]->getPassword() == password) {
            return true;
        }
    }
    return false;
}

bool University::isStudent() {
    if(user->getPeopleType() == _STUDENT) {
        return true;
    }
    else {
        return false;
    }
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
        if(people[i]->getPeopleType() == _PROFESSOR and people[i]->getId() == id) {
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

bool University::checkValidPostNumberById(string post_id, string id) {
    int index = findPeopleIndexById(id);
    return people[index]->isInPost(stoi(post_id));
}

bool University::inCommonTime(string professor_id, string time) {
    int professor_index = findPeopleIndexById(professor_id);
    Time new_time(time);
    if(people[professor_index]->validCourseTime(new_time)) {
        return false;
    }
    else {
        return true;
    }

}

int University::findMajor(string id) {
    for(int i = 0; i < majors.size(); i++) {
        if(majors[i]->getId() == id) {
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

void University::showOneCourseOffers(int index) {
    output.push_back(to_string(all_course_offers[index]->getCourseOfferId()) + SPACE);
    output.push_back(all_course_offers[index]->getName() + SPACE);
    output.push_back(to_string(all_course_offers[index]->getCapacity()) + SPACE);
    output.push_back(people[findPeopleIndexById(all_course_offers[index]->getProfessorId())]->getName() + SPACE);
    output.push_back(all_course_offers[index]->getTime()  + SPACE);
    output.push_back(all_course_offers[index]->getExamTime() + SPACE);
    output.push_back(to_string(all_course_offers[index]->getClassNumber()) + END_LINE);
}

void University::addNotificationCoursePost(int index, string notification_line) {
    for(int i = 0; i < all_course_offers[index]->students.size(); i++) {
        people[findPeopleIndexById(all_course_offers[index]->students[i])]->addNotification(notification_line);
    }
    if(user->getPeopleType() != _PROFESSOR) {
        people[findPeopleIndexById(all_course_offers[index]->professor_id)]->addNotification(notification_line);
    }
    for(int i = 0; i < all_course_offers[index]->ta_ids.size(); i++) {
        if(user->getId() == all_course_offers[index]->ta_ids[i]) {
            continue;
        }
        else {
            people[findPeopleIndexById(all_course_offers[index]->ta_ids[i])]->addNotification(notification_line);
        }
    }
}


void University::showAllCourseOffers() {
    for(int i = 0; i < all_course_offers.size(); i++) {
        output.push_back(to_string(all_course_offers[i]->getCourseOfferId()) + SPACE);
        output.push_back(all_course_offers[i]->getName()  + SPACE);
        output.push_back(to_string(all_course_offers[i]->getCapacity()) + SPACE);
        output.push_back(people[findPeopleIndexById(all_course_offers[i]->getProfessorId())]->getName() + END_LINE);
    }
}

Major* University::getMajorById(int index) {
    return majors[index];
}

void University::askQuestion(string output_line) {
    string enter;
    while(enter != ACCEPT and enter != REJECT) {
        output.push_back(output_line);
        getline(cin, enter);
        output.push_back(enter + END_LINE);
    }
}

void University::askProfessorForTA(int index) {
    output.push_back(TA_FORM_FIRST + to_string(all_course_offers[index]->getRequestedTA().size()) + TA_FORM_SECOND + END_LINE);
    for(int i = 0; i < all_course_offers[index]->getRequestedTA().size(); i++) {
        askQuestion(all_course_offers[index]->getRequestedTA()[i]);
    }
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
    else if(input_line[1] == PROFILE_PHOTO) {
        runAddProfile();
    }
    else if(input_line[1] == COURSE_POST) {
        runCoursePost();
    }
    else if(input_line[1] == TA_FORM) {
        runPostTAForm();
    }
    else {
        throw runtime_error(NOT_FOUND);
    }
}

void University::handleGetRequest() {
    if(input_line[1] == MY_COURSES) {
        runGetMyCourse();
    }
    else if(input_line[1] == NOTIFICATION) {
        runNotification();
    }
    else if(input_line[1] == LITTLE_POST) {
        runGetPost();
    }
    else if(input_line[1] == PERSONAL_PAGE) {
        runPersonalPage();
    }
    else if(input_line[1] == COURSES) {
        runGetCourse();
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
        runDeleteCourse();
    }
    else {
        throw runtime_error(NOT_FOUND);
    }
}

void University::handlePutRequest() {
    if(input_line[1] == MY_COURSES) {
        runPutCourse();
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

void University::makeDefaultConnections() {
    people.push_back(new UTAccount(ZERO_STRING, UT_ACCOUNT));
    for(int i = 0; i + 1 < people.size(); i++) {
        people[i]->addConnection(people.back());
        people.back()->addConnection(people[i]);
    }
}

void University::run(string input_string) {
    input_line = splitByInputSign(input_string, SPACE);
    try {
        if(input_line.size() > MIN_INPUT_SIZE) {
            handleInput();
        }
        else {
            throw runtime_error(BAD_REQUEST);
        }
    } catch (runtime_error &e) {
        catchError(e);
    }
}