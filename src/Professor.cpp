#include "Professor.hpp"

Professor::Professor(string id, string name, string major_id, string string_position, string password):
People(id, name, major_id, password, _PROFESSOR), string_position(string_position) {}

void Professor::personalPage(string major_name) {
    cout << name << " " << major_name << " " << string_position << " ";
    People ::showOfferCourses();
    People ::showPosts();
}

void Professor::getPost(string major_name, int post_id) {
    cout << name << " " << major_name << " " << string_position << " ";
    People ::showOfferCourses();
    People ::showOnePost(post_id);
}