#include "Professor.hpp"

Professor::Professor(string id, string name, Major* major, string string_position, string password):
People(id, name, major, password, _PROFESSOR), string_position(string_position) {}

void Professor::personalPage(vector<string>& output) {
    output.push_back(name + SPACE + major->getName() + SPACE + string_position + SPACE);
    People ::showOfferCourses(output);
    People ::showPosts(output);
}

void Professor::getPost(vector<string>& output, int post_id) {
    output.push_back(name + SPACE + major->getName() + SPACE + string_position + SPACE);
    People ::showOfferCourses(output);
    People ::showOnePost(output, post_id);
}