#include "Stack.h"
#include <stdexcept>
#include <string>

class StackEditor {
    std::string str;
    
public:
    StackEditor(std::string s) : str(std::move(s)) {}

    std::string tostr() const {
        return str;
    }
    size_t deleteBracket(size_t pos) {
        Stack<size_t> stack;
        size_t openPos = 0;
        for (size_t i = 0; i < str.length(); ++i) {
            if (str[i] == '(') {
                stack.push(i);
            } else if (str[i] == ')') {
                openPos = stack.pop();
                size_t removed;
                if (openPos == pos || i == pos) {
                    removed = i - openPos + 1;
                    str.erase(openPos, removed);
                    return openPos - ((i + 1 <= str.length() - removed) ? 0 : 1);
                }
            }
        }
        throw std::invalid_argument("Position does not correspond to a bracket");
    }
};