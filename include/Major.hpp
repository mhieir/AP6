#ifndef MAJOR_INCLUDE
#define MAJOR_INCLUDE

#include "Global.hpp"
#include "University.hpp"

class Major : public University {
public:
    Major(string id, string name);
    ~Major(){};
protected:

private:
};

#endif