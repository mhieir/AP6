#ifndef LOGIN_INCLUDE
#define LOGIN_INCLUDE

#include "Global.hpp"
#include "People.hpp"

class Login {
public:
    Login(vector<string> input_line);
    ~Login() {};
    void run();
    void checkQuestionMark();
    void checkNotInLoginMode();
    void loginModeInput();
    void findPeopleById(string id);
    bool checkValidId(string id);
    bool checkValidPassword(string id, string password);
protected:
private:
    vector<string> input_line;

};

#endif