#pragma once

#include <cstddef>

template <typename T>
class Stack {
    T* stack;
    size_t top;
public:
    Stack(size_t size) {
        stack = new T[size];
    }
    ~Stack() {
        delete[] stack;
    }

    void push(const T& item) {
        stack[top++] = item;
    }
    T pop() {
        return stack[--top];
    }
};