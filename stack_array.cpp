#include "stack_array.h"
#include <stdexcept>

StackArray::StackArray(int size) {
    capacity = size;
    top = -1;
    arr = new std::string[capacity];
}

bool StackArray::isEmpty() const {
    return top == -1;
}

bool StackArray::isFull() const {
    return top == capacity - 1;
}

void StackArray::push(const std::string& value) {
    if (isFull()) {
        throw std::overflow_error("Stack Overflow");
    }
    arr[++top] = value;
}

std::string StackArray::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack Underflow");
    }
    return arr[top--];
}

std::string StackArray::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Stack is Empty");
    }
    return arr[top];
}
