#ifndef PROFESSOR_INCLUDE
#define PROFESSOR_INCLUDE

#include "Global.hpp"
#include "People.hpp"
#include "Time.hpp"
#include "CourseOffer.hpp"

enum Position {
    INSTRUCTOR,
    ASSISTANT,
    ASSOCIATE,
    PROFESSSOR
};

class Professor : public People {
public:
    Professor(string id, string name, string major_id, string string_position, string password);
    ~Professor() {};
    Position getPosition() {return position;}
    void personalPage(string major_name);
    void getPost(string major_name, int post_id);
    void addCourse(CourseOffer* new_course_offer) {course_offers.push_back(new_course_offer);}
protected:
    string string_position;
    vector<CourseOffer*> course_offers;
    Position position;
private:
};

#endif