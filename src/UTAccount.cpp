#include "UTAccount.hpp"

UTAccount::UTAccount(string id, string password) :
People(id, NULL_STRING, nullptr, password, _UTACCOUNT) {}

void UTAccount::personalPage() {
    cout << UT_ACCOUNT << endl;
    People ::showPosts();
}

void UTAccount::getPost(int post_id) {
    cout << UT_ACCOUNT << endl;
    People ::showOnePost(post_id);
}