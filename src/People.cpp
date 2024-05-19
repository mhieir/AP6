#include "People.hpp"

People::People(string id, string name, string major_id, string password) :
University(id, name), major_id(major_id), password(password) {}