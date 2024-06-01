#pragma once
#ifndef CLOUD_INCLUDE
#define CLOUD_INCLUDE

#include "Global.hpp"
#include "Post.hpp"

class Cloud {
public:
    Cloud();
    ~Cloud() {};
    bool isInPost(int post_id);
    void addPost(string title, string message, string image_address, string author, PostType post_type, string extra);
    void removePost(int post_id);
    void showOnePost(vector<string>& output, int post_id);
    void showPosts(vector<string>& output);
protected:
private:
    int post_number;
    vector<Post*> posts;
};

#endif