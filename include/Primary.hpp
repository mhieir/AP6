#ifndef PRIMARY_INCLUDE
#define PRIMARY_INCLUDE

#include "Global.hpp"

vector<string> read_csv(const char path[256]);
void signInSplitting(string &result, vector<string> &splitted);
void notSignInSplitting(string &result, char character);
vector<string> splitByInputSign(string inputString, char sign);
void catchError(runtime_error& ex);
void checkQuestionMark();

#endif