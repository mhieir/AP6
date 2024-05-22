#include "Professor.hpp"

Professor::Professor(string id, string name, string major_id, string string_position, string password):
People(id, name, major_id, password, PROFESSOR), string_position(string_position) {}