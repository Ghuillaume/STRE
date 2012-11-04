#include "common.h"

ListOfString explode(const std::string& str, const char& delimiter)
{
    std::istringstream split(str);
    std::vector<std::string> tokens;
    for (std::string each; std::getline(split, each, delimiter); tokens.push_back(each));
    return tokens;
}

