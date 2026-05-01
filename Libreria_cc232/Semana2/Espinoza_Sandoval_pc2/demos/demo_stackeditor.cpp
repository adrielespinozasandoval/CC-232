#include <iostream>
#include "StackEditor.h"

int main() {
    auto bs = cc232::StackEditor("()(())");
    auto str0 = bs.tostr();
    std::cout << str0 << std::endl;
    std::cout << str0.length() << std::endl;
    std::cout << bs.deleteBracket(2) << std::endl;
    auto str = bs.tostr();
    std::cout << str << std::endl;
    std::cout << str.length() << std::endl;
    return 0;
}