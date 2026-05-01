#include <iostream>
#include <cassert>
#include "StackEditor.h"

int main() {
    // Test constructor with valid sequences
    cc232::StackEditor bs1("()");
    assert(bs1.tostr() == "()");
    cc232::StackEditor bs2("(())");
    assert(bs2.tostr() == "(())");
    cc232::StackEditor bs3("()()");
    assert(bs3.tostr() == "()()");
    cc232::StackEditor bs4("((()))");
    assert(bs4.tostr() == "((()))");

    // Test deleteBracket with various positions
    cc232::StackEditor bs5("()(())");
    assert(bs5.deleteBracket(0) == 0);
    assert(bs5.tostr() == "(())");
    //std::cout << std::endl << bs5.deleteBracket(1) << std::endl;
    assert(bs5.deleteBracket(1) == 1);
    assert(bs5.tostr() == "()");
    assert(bs5.deleteBracket(0) == 0);
    assert(bs5.tostr() == "");
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}