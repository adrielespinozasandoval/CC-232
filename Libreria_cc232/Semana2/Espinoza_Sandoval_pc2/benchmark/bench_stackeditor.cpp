#include "StackEditor.h"
#include <iostream>
#include <chrono>

// Make random bracket sequences of increasing size and test the time taken to delete a bracket at a random position
// First make a function that generates a random and valid bracket sequence of a given size

std::string generateRandomBracketSequence(size_t n) {
    std::string seq;
    seq.reserve(n);
    size_t open = 0;
    for (size_t i = 0; i < n; ++i) {
        if (open == 0) {
            seq += '(';
            ++open;
        } else if (open == n - i) {
            seq += ')';
            --open;
        } else {
            if (rand() % 2 == 0) {
                seq += '(';
                ++open;
            } else {
                seq += ')';
                --open;
            }
        }
    }
    return seq;
}

int main() {
    //Then make a loop that generates them of fixed sizes. For each size, generate random sequences and test the time taken to delete a bracket at a random position, and print the average time taken for each size.
    for (size_t size = 1000; size <= 1000000; size *= 10) {
        size_t trials = 100;
        double totalTime = 0.0;
        for (size_t t = 0; t < trials; ++t) {
            std::string seq = generateRandomBracketSequence(size);
            cc232::StackEditor bs(seq);
            size_t pos = rand() % size;

            auto start = std::chrono::high_resolution_clock::now();
            bs.deleteBracket(pos);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            totalTime += elapsed.count();
        }
        std::cout << "Size: " << size << ", Average Time: " << (totalTime / trials) << " seconds\n";
    }
}