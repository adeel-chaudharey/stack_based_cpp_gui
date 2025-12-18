#include "evaluator.h"
#include <cmath>

int Evaluator::applyOp(int a, int b, char op) {
    switch(op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if(b == 0) throw std::runtime_error("Division by zero");
        return a / b;
    case '^': return static_cast<int>(std::pow(a, b));
    default: throw std::runtime_error("Unknown operator");
    }
}

int Evaluator::evaluatePostfix(const std::string& postfix) {
    std::stack<int> st;

    for(char c : postfix) {
        if(std::isdigit(c)) {
            st.push(c - '0');  // simple single-digit numbers
        } else {
            if(st.size() < 2) throw std::runtime_error("Malformed expression");
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(applyOp(a, b, c));
        }
    }

    if(st.size() != 1) throw std::runtime_error("Malformed expression");
    return st.top();
}

int Evaluator::evaluatePrefix(const std::string& prefix) {
    std::stack<int> st;

    for(auto it = prefix.rbegin(); it != prefix.rend(); ++it) {
        char c = *it;
        if(std::isdigit(c)) {
            st.push(c - '0');
        } else {
            if(st.size() < 2) throw std::runtime_error("Malformed expression");
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push(applyOp(a, b, c));
        }
    }

    if(st.size() != 1) throw std::runtime_error("Malformed expression");
    return st.top();
}
