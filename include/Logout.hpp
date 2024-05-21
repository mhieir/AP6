#ifndef LOGOUT_INCLUDE
#define LOGOUT_INCLUDE

#include "Global.hpp"
#include "People.hpp"

class Logout {
public:
    Logout(vector<string> input_line, People* user);
    ~Logout() {};
    void checkNotInLogoutMode();
    void checkQuestionMarkLogout();
    void checkInputSizeLogout();
protected:
private:
    vector<string> input_line;
    People* user;
};

#endif