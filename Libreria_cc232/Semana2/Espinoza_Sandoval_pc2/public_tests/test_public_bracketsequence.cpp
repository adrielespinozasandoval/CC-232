#include <iostream>
#include <cassert>
#include "BracketSequence.h"

int main() {
    // Test constructor with valid sequences
    cc232::BracketSequence bs1("()");
    assert(bs1.tostr() == "()");
    cc232::BracketSequence bs2("(())");
    assert(bs2.tostr() == "(())");
    cc232::BracketSequence bs3("()()");
    assert(bs3.tostr() == "()()");
    cc232::BracketSequence bs4("((()))");
    assert(bs4.tostr() == "((()))");

    // Test delBracketPos with various positions
    cc232::BracketSequence bs5("()(())");
    assert(bs5.delBracketPos(0) == 0);
    assert(bs5.tostr() == "(())");
    std::cout << std::endl << bs5.delBracketPos(1) << std::endl;
    assert(bs5.delBracketPos(1) == 1);
    assert(bs5.tostr() == "()");
    assert(bs5.delBracketPos(0) == 0);
    assert(bs5.tostr() == "");
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}