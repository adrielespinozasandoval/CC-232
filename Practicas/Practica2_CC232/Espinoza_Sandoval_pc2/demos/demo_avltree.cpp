#include "AVLTree.h"
#include <iostream>
#include <vector>

int main() {
    // 1. Constructor: Initialize the tree with a comparison lambda
    auto compare = [](int a, int b) { return a < b; };
    AVLTree<int> tree(compare);

    std::cout << "=== AVL Tree Public Methods Demo ===" << std::endl;

    // 2. insert(T& key): Adding elements
    // We use a vector and iterate by reference to satisfy the T& parameter requirement
    std::vector<int> elements = {44, 17, 78, 32, 50, 88, 48, 62, 54};
    std::cout << "Inserting elements: 44, 17, 78, 32, 50, 88, 48, 62, 54" << std::endl;
    
    for (int& val : elements) {
        std::cout << "insert(" << val << "): ";
        tree.insert(val);
    }

    // 3. tostr(): Displaying the balanced tree structure
    std::cout << "\nInitial Tree structure (Hierarchical):\n";
    std::cout << tree.tostr() << std::endl;

    // 4. find(T& key): Searching for a specific key
    int searchKey = 32;
    auto* foundNode = tree.find(searchKey);
    if (foundNode) {
        std::cout << "find(" << searchKey << "): Key found successfully." << std::endl;
    } else {
        std::cout << "find(" << searchKey << "): Key not found." << std::endl;
    }

    // 5. remove(T& key): Deleting a node and triggering rebalancing
    int deleteKey = 78;
    bool wasRemoved = tree.remove(deleteKey);
    std::cout << "\nremove(" << deleteKey << "): " << (wasRemoved ? "Success" : "Failure") << std::endl;

    // Verify final structure
    std::cout << "Tree structure after removal:\n";
    std::cout << tree.tostr() << std::endl;

    // The Destructor is called automatically when 'tree' goes out of scope
    return 0;
}