#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <string>

class StackArray {
private:
    int top;
    int capacity;
    std::string* arr;

public:
    StackArray(int size = 100);

    bool isEmpty() const;
    bool isFull() const;

    void push(const std::string& value);
    std::string pop();
    std::string peek() const;
};

#endif
