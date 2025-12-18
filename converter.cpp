#include "converter.h"
#include <algorithm>

int Converter::precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

bool Converter::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

std::string Converter::infixToPostfix(const std::string& infix) {
    std::stack<char> st;
    std::string postfix;

    for(char c : infix) {
        if(isalnum(c)) {
            postfix += c;
        } else if(c == '(') {
            st.push(c);
        } else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // pop '('
        } else if(isOperator(c)) {
            while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

std::string Converter::infixToPrefix(const std::string& infix) {
    std::string reversedInfix = infix;
    std::reverse(reversedInfix.begin(), reversedInfix.end());
    for(auto& c : reversedInfix) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }
    std::string reversedPostfix = infixToPostfix(reversedInfix);
    std::reverse(reversedPostfix.begin(), reversedPostfix.end());
    return reversedPostfix;
}

std::string Converter::postfixToInfix(const std::string& postfix) {
    std::stack<std::string> st;
    for(char c : postfix) {
        if(isalnum(c)) {
            st.push(std::string(1, c));
        } else if(isOperator(c)) {
            if(st.size() < 2) throw std::runtime_error("Malformed expression");
            std::string b = st.top(); st.pop();
            std::string a = st.top(); st.pop();
            st.push("(" + a + c + b + ")");
        }
    }
    if(st.size() != 1) throw std::runtime_error("Malformed expression");
    return st.top();
}

std::string Converter::prefixToInfix(const std::string& prefix) {
    std::stack<std::string> st;
    for(auto it = prefix.rbegin(); it != prefix.rend(); ++it) {
        char c = *it;
        if(isalnum(c)) {
            st.push(std::string(1, c));
        } else if(isOperator(c)) {
            if(st.size() < 2) throw std::runtime_error("Malformed expression");
            std::string a = st.top(); st.pop();
            std::string b = st.top(); st.pop();
            st.push("(" + a + c + b + ")");
        }
    }
    if(st.size() != 1) throw std::runtime_error("Malformed expression");
    return st.top();
}
