#ifndef PEOPLE_INCLUDE
#define PEOPLE_INCLUDE

#include "Global.hpp"
#include "Entity.hpp"
#include "Major.hpp"
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
    People(string id, string name, Major* major, string password, PeopleType people_type);
    ~People() {};
    bool validCourseDate(string new_date);
    string getMajorId() {return major->getId();}
    string getPassword() {return password;}
    void addConnection(People* new_connection) {connections.push_back(new_connection);}
    bool inConnection(string new_id);
    bool isInPost(int post_id);
    void addPost(string title, string message);
    void removePost(int post_id);
    virtual void personalPage() = 0;
    virtual void getPost(int post_id) = 0;
    bool validCourseTime(Time new_time);
    void addCourse(CourseOffer* course_offer) {course_offers.push_back(course_offer);}
    void removeCourse(int course_offer_id);
    PeopleType getPeopleType() {return people_type;}
    void showOnePost(int post_id);
    virtual int getSemester() {return 0;};
    bool hasCourseOfferById(int course_id);
    int numberOfCourses() {return (int) course_offers.size();}
    void showCourses();
protected:
    Major* major;
    string password;
    vector<People*> connections;
    vector<Post*> posts;
    vector<CourseOffer*> course_offers;
    int post_number;
    PeopleType people_type;
    void showOfferCourses();
    void showPosts();
private:
};

#endif