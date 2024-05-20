#include "People.hpp"

People::People(string id, string name, string major_id, string password) :
Entity(id, name), major_id(major_id), password(password) {}