#pragma once

#include <vector>

template <typename T>
class Stack {
    std::vector<T> data;
public:
    Stack() = default;
    explicit Stack(size_t size) { data.reserve(size); }
    ~Stack() = default;

    void push(const T& item) {
        data.push_back(item);
    }

    T pop() {
        T item = data.back();
        data.pop_back();
        return item;
    }

    bool empty() const {
        return data.empty();
    }
    size_t size() const {
        return data.size();
    }
};