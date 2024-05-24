#include "People.hpp"

People::People(string id, string name, Major* major, string password, PeopleType people_type) :
Entity(id, name), major(major), password(password), people_type(people_type) {
    post_number = 1;
}

bool People::inConnection(string new_id) {
    cout << connections.size() << endl;
    for(int i = 0; i < connections.size(); i++) {
        cout << new_id << " " << connections[i]->getId() << endl;
        if(new_id == connections[i]->getId()) return true;
    }
    return false;
}

void People::addPost(string title, string message) {
    posts.push_back(new Post(title, message, post_number));
    post_number++;
}

void People::removePost(int post_id) {
    for(int i = 0; i < (int) posts.size(); i++) {
        if(posts[i]->getId() == post_id) {
            posts.erase(posts.begin() + i);
            return;
        }
    }
}

bool People::isInPost(int post_id) {
    for(int i = 0; i < (int) posts.size(); i++) {
        if(posts[i]->getId() == post_id) {
            return true;
        }
    }
    return false;
}

void People::showOnePost(int post_id) {
    for(int i = 0; i < (int) posts.size(); i++) {
        if(posts[i]->getId() == post_id) {
            cout << posts[i]->getId() << " " << posts[i]->getTitle() << " " << posts[i]->getMessage();
        }
    }
    cout << endl;
}

bool People::validCourseTime(Time new_time) {
    for(int i = 0; i < course_offers.size(); i++) {
        if(course_offers[i]->inSameTime(new_time)) {
            return false;
        }
    }
    return true;
}

bool People::validCourseDate(string new_date) {
    for(int i = 0; i < course_offers.size(); i++) {
        if(course_offers[i]->getExamTime() == new_date) {
            return false;
        }
    }
    return true;
}

void People::removeCourse(int course_offer_id) {
    for(int i = 0; i < course_offers.size(); i++) {
        if(course_offers[i]->getCourseOfferId() == course_offer_id) {
            course_offers.erase(course_offers.begin() + i);
            return;
        }
    }
}

void People::showOfferCourses() {
    for(int i = 0; i + 1 < course_offers.size(); i++) {
        cout << course_offers[i]->getName() << COMMA;
    }
    if(!course_offers.empty()) {
        cout << course_offers.back()->getName();
    }
    cout << endl;
}

void People::showPosts() {
    for(int i = 0; i < posts.size(); i++) {
        cout << posts[i]->getId() << " " << posts[i]->getTitle() << endl;
    }
    if(posts.empty()) cout << endl;
}


bool People::hasCourseOfferById(int course_id) {
    for(int i = 0; i < course_offers.size(); i++) {
        cout << course_offers[i]->getCourseOfferId() << " " << course_id << endl;
        if(course_offers[i]->getCourseOfferId() == course_id) {
            return true;
        }
    }
    return false;
}

void People::showCourses(){
    for(int i = 0; i < course_offers.size(); i++) {
        cout << course_offers[i]->getCourseOfferId() << " ";
        cout << course_offers[i]->getName() << " ";
        cout << course_offers[i]->getCapacity() << " ";
        cout << course_offers[i]->getProfessorName() << " ";
        cout << course_offers[i]->getTime() << " ";
        cout << course_offers[i]->getExamTime() << " ";
        cout << course_offers[i]->getClassNumber() << endl;
    }
}