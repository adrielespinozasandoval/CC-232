#include "BracketSequence.h"
#include <iostream>

int main() {
    auto bs = cc232::BracketSequence("()(())");
    auto str0 = bs.tostr();
    std::cout << str0 << std::endl;
    std::cout << str0.length() << std::endl;
    std::cout << bs.delBracketPos(2) << std::endl;
    auto str = bs.tostr();
    std::cout << str << std::endl;
    std::cout << str.length() << std::endl;
    return 0;
}