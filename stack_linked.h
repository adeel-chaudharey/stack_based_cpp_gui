#ifndef STACK_LINKED_H
#define STACK_LINKED_H

#include <string>

class StackLinked {
private:
    struct Node {
        std::string data;
        Node* next;
    };

    Node* top;

public:
    StackLinked();

    bool isEmpty() const;
    void push(const std::string& value);
    std::string pop();
    std::string peek() const;
};

#endif

