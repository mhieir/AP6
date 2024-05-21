#ifndef LOGIN_INCLUDE
#define LOGIN_INCLUDE

#include "Global.hpp"
#include "People.hpp"

class Login {
public:
    Login(vector<string> input_line);
    ~Login() {};
    void run(People* &user, vector<People*> &people);
    void checkQuestionMark(People* &user, vector<People*> &people);
    void checkNotInLoginMode(People* &user, vector<People*> &people);
    void loginModeInput(People* &user, vector<People*> &people);
    void findPeopleById(string id, People* &user, vector<People*> &people);
    bool checkValidId(string id, People* &user, vector<People*> &people);
    bool checkValidPassword(string id, string password, People* &user, vector<People*> &people);
protected:
private:
    vector<string> input_line;

};

#endif