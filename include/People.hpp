#ifndef PEOPLE_INCLUDE
#define PEOPLE_INCLUDE

#include "Global.hpp"
#include "Entity.hpp"
#include "Post.hpp"
#include "Time.hpp"
#include "CourseOffer.hpp"

enum PeopleType {
    _STUDENT,
    _PROFESSOR,
    _UTACCOUNT
};

class People : public Entity {
public:
    People(string id, string name, string major_id, string password, PeopleType people_type);
    ~People() {};
    string getMajorId() {return major_id;}
    string getPassword() {return password;}
    void addConnection(string new_id) {connections.push_back(new_id);}
    bool inConnection(string new_id);
    bool isInPost(int post_id);
    void addPost(string title, string message);
    void removePost(int post_id);
    virtual void personalPage(string major_name) = 0;
    virtual void getPost(string major_name, int post_id) = 0;
    bool validCourseTime(Time new_time);
    void addCourse(CourseOffer* course_offer) {course_offers.push_back(course_offer);}
    void removeCourse(int course_offer_id);
    PeopleType getPeopleType() {return people_type;}
    void showOnePost(int post_id);
protected:
    string major_id, password;
    vector<string> connections;
    vector<Post*> posts;
    vector<CourseOffer*> course_offers;
    int post_number;
    PeopleType people_type;
    void showOfferCourses();
    void showPosts();
private:
};

#endif