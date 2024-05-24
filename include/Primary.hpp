#pragma once
#ifndef PRIMARY_INCLUDE
#define PRIMARY_INCLUDE

#include "Global.hpp"

vector<string> read_csv(const char path[256]);
void signInSplitting(string &result, vector<string> &splitted);
void notSignInSplitting(string &result, char character);
vector<string> splitByInputSign(string inputString, char sign);
void catchError(runtime_error& ex);
bool isQuestionMark(string input_line);
void okMode();
bool isNumber(string post_id);
string makeText(vector<string> input_line, int start, int end);
vector<int> findQuotion(vector<string> input_line);
bool hasCommon(int a, int b, int c, int d);

#endif