#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <string>
#include <stack>
#include <stdexcept>
#include <cctype>
#include <cmath>

class Evaluator {
public:
    static int applyOp(int a, int b, char op);
    static int evaluatePostfix(const std::string& postfix);
    static int evaluatePrefix(const std::string& prefix);
};

#endif
