#include "Professor.hpp"

Professor::Professor(string id, string name, Major* major, string string_position, string password):
People(id, name, major, password, _PROFESSOR), string_position(string_position) {}

void Professor::personalPage() {
    cout << name << " " << major->getName() << " " << string_position << " ";
    People ::showOfferCourses();
    People ::showPosts();
}

void Professor::getPost(int post_id) {
    cout << name << " " << major->getName()  << " " << string_position << " ";
    People ::showOfferCourses();
    People ::showOnePost(post_id);
}