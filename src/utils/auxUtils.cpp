#include "auxUtils.h"
#include <string>
#include <regex>

int trimCoords(std::string coord){
    return stoi(std::regex_replace(coord, std::regex(R"([\D])"), ""));
};