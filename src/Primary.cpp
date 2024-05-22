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

bool isQuestionMark(string input_line) {
    if(input_line == QUESTION_MARK) {
        return true;
    }
    else {
        return false;
    }

}

void okMode() {
	try {
        throw runtime_error(OK);
    } catch(runtime_error& ex) {
        catchError(ex);
    }
}

bool isNumber(string post_id) {
    for(char c : post_id) {
        if(!isdigit(c)) {
            return false;
        }
    }
    return true;
}

string makeText(vector<string> input_line, int start, int end) {
    string result = NULL_STRING;
    for(int i = start; i <= end; i++) {
        result += input_line[i] + SPACE;
    }
    result = result.substr(0, int(result.size()) - 2);
    result = result.substr(1, int(result.size()) - 1);
    return result;
}

vector<int> findQuotion(vector<string> input_line) {
    vector<int> quotion;
    for(int i = 3; i < input_line.size(); i++) {
        if(input_line[i][0] == QUOTION) {
            quotion.push_back(i);
        }
        if(input_line[i].back() == QUOTION) {
            quotion.push_back(i);
        }
    }
    return quotion;
}