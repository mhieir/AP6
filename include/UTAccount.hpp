#ifndef UTACCOUNT_INCLUDE
#define UTACCOUNT_INCLUDE

#include "Global.hpp"
#include "People.hpp"

class UTAccount : public People {
public:
    UTAccount(string id = ZERO_STRING, string password = UT_ACCOUNT);
    ~UTAccount() {};
    void personalPage(string major_name);
    void getPost(string major_name, int post_id);
protected:
private:
};

#endif