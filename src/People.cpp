#include "People.hpp"

People::People(string id, string name, string major_id, string password, PeopleType people_type) :
Entity(id, name), major_id(major_id), password(password), people_type(people_type) {
    post_number = 1;
}

bool People::inConnection(string new_id) {
    for(int i = 0; i < connections.size(); i++) {
        if(new_id == connections[i]) return true;
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