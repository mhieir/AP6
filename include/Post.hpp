#pragma once
#ifndef POST_INCLUDE
#define POST_INCLUDE

#include "Global.hpp"

class Post {
public:
    Post(string title, string message, int id, string image_address, string author, PostType post_type, string extra);
    ~Post() {};
    string getTitle() {return title;}
    string getAuthor() {return author;}
    string getMessage() {return message;}
    int getId() {return id;}
    string getAddress() {return image_address;}
    PostType getPostType() {return post_type;}
    string getExtra() {return extra;}
protected:
private:
    string title, message, image_address, author, extra;
    PostType post_type;
    int id;
    bool available;
};

#endif