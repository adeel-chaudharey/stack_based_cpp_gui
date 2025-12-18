#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
#include <stack>
#include <stdexcept>

class Converter {
public:
    static int precedence(char op);
    static bool isOperator(char c);
    static std::string infixToPostfix(const std::string& infix);
    static std::string infixToPrefix(const std::string& infix);
    static std::string postfixToInfix(const std::string& postfix);
    static std::string prefixToInfix(const std::string& prefix);
};

#endif
