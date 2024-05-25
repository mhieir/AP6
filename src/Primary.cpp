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

void signInSplitting(string &result, vector<string> &splitted) {
    splitted.push_back(result);
    result = NULL_STRING;
}

void notSignInSplitting(string &result, char character) {
    result += character;
}

bool hasQuotion(string inputString) {
    for (auto &character : inputString){
        if (character == QUOTION) {
            return true;
        }
    }
    return false;
}

void handleQoution(int& i, string& result, vector<string>& splitted, string inputString, int& check) {
    for(i; i < inputString.size(); i++) {
        notSignInSplitting(result, inputString[i]);
        if(inputString[i] == QUOTION) {
            check++;
            if((int) result.size() != 1) {
                signInSplitting(result, splitted);
                break;
            }
        }
    }
}

vector<string> splitInQuotionMode(string inputString) {
    int check = 0;
    string result = NULL_STRING;
    vector<string> splitted;
    for(int i = 0; i < inputString.size(); i++) {
        if (inputString[i] == SPACE) {
            if(result != NULL_STRING) signInSplitting(result, splitted);
        }
        else if(inputString[i] != QUOTION) {
            notSignInSplitting(result, inputString[i]);
        }
        else {
            if(result != NULL_STRING) {
                splitted.clear();
                return splitted;
            }
            handleQoution(i, result, splitted, inputString, check);
        }
    }

    if(check != 4) splitted.clear();
    if(result != NULL_STRING) signInSplitting(result, splitted);
    return splitted;
}

vector<string> splitByInputSign(string inputString, char sign) {
    if(hasQuotion(inputString)) {
        return splitInQuotionMode(inputString);
    }
    string result = NULL_STRING;
    vector<string> splitted;
    for (auto &character : inputString){
        if (character == sign) {
            if(result != NULL_STRING) signInSplitting(result, splitted);
        }
        else {
            notSignInSplitting(result, character);
        }
    }
    if(result != NULL_STRING) signInSplitting(result, splitted);
    return splitted;
}

bool isQuestionMark(string input_line) {
    if(input_line == QUESTION_MARK) {
        return true;
    }
    else {
        return false;
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
    for(int i = start; i < end; i++) {
        result += input_line[i] + SPACE;
    }
    result += input_line[end];
    return result;
}

vector<int> findQuotion(vector<string> input_line) {
    vector<int> quotion;
    for(int i = 3; i < input_line.size(); i++) {
        if(input_line[i][0] == QUOTION) {
            quotion.push_back(i);
        }
        if(input_line[i].back() == QUOTION and (int) input_line[i].size() != 1) {
            quotion.push_back(i);
        }
    }
    return quotion;
}

bool hasCommon(int a, int b, int c, int d) {
    if(max(a, c) < min(b, d)) {
        return true;
    }
    else {
        return false;
    }
}