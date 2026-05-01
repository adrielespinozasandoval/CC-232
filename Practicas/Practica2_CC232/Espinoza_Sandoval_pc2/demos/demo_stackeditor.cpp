#include <iostream>
#include "StackEditor.h"

int main() {
    StackEditor se("()(())");
    std::cout << se.deleteBracket(2) << std::endl;
    std::cout << se.tostr() << std::endl;
    return 0;
}