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
    for (auto &character : inputString)
    {
        if (character == sign)
        {
            signInSplitting(result, splitted);
        }
        else
        {
            notSignInSplitting(result, character);
        }
    }
    signInSplitting(result, splitted);
    return splitted;
}

bool invalidInput(string input_word) {
    if(input_word != GET and input_word != POST and input_word != PUT and input_word != DELETE) {
        return false;
    }
    return true;
}