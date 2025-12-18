#include "stack_linked.h"
#include <stdexcept>

StackLinked::StackLinked() {
    top = nullptr;
}

bool StackLinked::isEmpty() const {
    return top == nullptr;
}

void StackLinked::push(const std::string& value) {
    Node* newNode = new Node{value, top};
    top = newNode;
}

std::string StackLinked::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack Underflow");
    }
    Node* temp = top;
    std::string value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

std::string StackLinked::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Stack is Empty");
    }
    return top->data;
}
