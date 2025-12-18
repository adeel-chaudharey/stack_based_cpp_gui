#include "utils.h"
#include <fstream>
#include <cctype>

void Utils::saveHistory(const std::string& expression, const std::string& result) {
    std::ofstream file("history/history.txt", std::ios::app);
    if(file.is_open()) {
        file << expression << " = " << result << std::endl;
        file.close();
    }
}

bool Utils::isNumber(const std::string& s) {
    for(char c : s) {
        if(!std::isdigit(c)) return false;
    }
    return true;
}
