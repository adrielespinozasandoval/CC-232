#include "StackEditor.h"
#include <iostream>
#include <cassert>

int main() {
    cc232::StackEditor bs4("()");
    assert(bs4.deleteBracket(0) == 0);
    assert(bs4.tostr() == "");

    std::cout << "All tests passed!" << std::endl;
    return 0;
}