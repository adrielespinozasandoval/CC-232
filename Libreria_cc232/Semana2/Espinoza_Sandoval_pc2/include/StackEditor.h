#include "Stack.h"
#include <stdexcept>
#include <string>

namespace cc232 {
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
                size_t prevLength = str.length();
                openPos = stack.pop();
                if (openPos == pos || i == pos) {
                    str.erase(openPos, i - openPos + 1);
                    if (openPos == 0) { //Correction
                        return 0;
                    }
                    return openPos - ((i + 1 < prevLength) ? 0 : 1);
                }
            }
        }
        throw std::invalid_argument("Position does not correspond to a bracket");
    }
};
}