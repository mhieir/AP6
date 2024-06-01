#include "Post.hpp"

Post::Post(string title, string message, int id, string image_address, string author, PostType post_type, string extra) : author(author), id(id), extra(extra), image_address(image_address), post_type(post_type), message(message), title(title) {
    available = true;
}