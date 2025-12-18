#ifndef UTILS_H
#define UTILS_H

#include <string>

class Utils {
public:
    // Save evaluated expression and result to file
    static void saveHistory(const std::string& expression, const std::string& result);

    // Optional: helper function to check if string is numeric
    static bool isNumber(const std::string& s);
};

#endif
