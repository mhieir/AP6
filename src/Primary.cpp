#include "Global.hpp"

vector<string> read_csv(const char path[256]) {
    vector<string> lines;
    ifstream file_name;
    string new_line;
    file_name.open(path);
    while (getline(file_name, new_line)) {
        lines.push_back(new_line);
    }
    file_name.close();
    return lines;
}

void signInSplitting(string &result, vector<string> &splitted)
{
    splitted.push_back(result);
    result = NULL_STRING;
}

void notSignInSplitting(string &result, char character)
{
    result += character;
}

vector<string> splitByInputSign(string inputString, char sign)
{
    string result = NULL_STRING;
    vector<string> splitted;
    for (auto &character : inputString){
        if (character == sign) {
            signInSplitting(result, splitted);
        }
        else {
            notSignInSplitting(result, character);
        }
    }
    signInSplitting(result, splitted);
    return splitted;
}

void catchError(runtime_error& ex) {
    cerr << ex.what() << endl;
}

void checkQuestionMark() {
	try {
        string new_input;
        cin >> new_input;
        if(new_input != QUESTION_MARK) {
            throw runtime_error(BAD_REQUEST);
        }
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

void okMode() {
	try {
        throw runtime_error(OK);
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

