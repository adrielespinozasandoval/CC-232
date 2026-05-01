// Internal tests for the BracketSequence class
// These tests test more specific cases and edge cases that are not covered by the public tests, supporting the correctness of the implementation. They are not meant to be exhaustive, but to cover cases that are more likely to cause issues in the implementation.

#include "BracketSequence.h"
#include <iostream>
#include <cassert>

int main() {
    // Test constructor with invalid sequences
    try {
        cc232::BracketSequence bs1(")(");
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(true);
    }
    try {
        cc232::BracketSequence bs2("(()");
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(true);
    }
    try {
        cc232::BracketSequence bs3("())");
        assert(false);
    } catch (const std::invalid_argument& e) {
        assert(true);
    }

    // Test edge cases for delBracketPos
    cc232::BracketSequence bs4("()");
    assert(bs4.delBracketPos(0) == 0);
    assert(bs4.tostr() == "");

    std::cout << "All tests passed!" << std::endl;
    return 0;
}