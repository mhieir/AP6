#include "UTAccount.hpp"

UTAccount::UTAccount(string id, string password) :
People(id, NULL_STRING, NULL_STRING, password, _UTACCOUNT) {}

void UTAccount::personalPage(string major_name) {
    cout << UT_ACCOUNT << endl;
    People ::showPosts();
}

void UTAccount::getPost(string major_name, int post_id) {
    cout << UT_ACCOUNT << endl;
    People ::showOnePost(post_id);
}