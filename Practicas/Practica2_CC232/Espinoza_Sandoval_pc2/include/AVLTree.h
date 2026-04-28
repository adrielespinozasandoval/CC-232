#pragma once

#include <functional>
#include <sstream>
#include <string>
#include "Stack.h"

template <typename T>
class AVLTree {
    struct Node {
        T key;
        int height;
        Node* left;
        Node* right;
        Node* parent;

        Node(T key) : key(key), height(1), left(nullptr), right(nullptr), parent(nullptr) {}
        ~Node() {
            delete left;
            delete right;
        }
    };

    Node* root;
    std::function<bool(T, T)> compare;

    inline int height(Node* node) {
        return node ? node->height : 0;
    }
    inline int balance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    Node* minValNode(Node* node) {
        Node* curr = node;
        while (curr->left) {
            curr = curr->left;
        }
        return curr;
    }

    Node* rotl(Node* node) {
        Node* newRoot = node->right;
        Node* tmp = newRoot->left;
        newRoot->parent = node->parent;
        newRoot->left = node;
        node->parent = newRoot;
        node->right = tmp;
        tmp->parent = node;
        node->height = std::max(height(node->left), height(node->right)) + 1;
        newRoot->height = std::max(height(newRoot->left), height(newRoot->right)) + 1;
        return newRoot;
    }
    Node* rotr(Node* node) {
        Node* newRoot = node->left;
        Node* tmp = newRoot->right;
        newRoot->parent = node->parent;
        newRoot->right = node;
        node->parent = newRoot;
        node->left = tmp;
        tmp->parent = node;
        node->height = std::max(height(node->left), height(node->right)) + 1;
        newRoot->height = std::max(height(newRoot->left), height(newRoot->right)) + 1;
        return newRoot;
    }
    
    Node* rotll(Node* node) {
        return rotr(node);
    }
    Node* rotrr(Node* node) {
        return rotl(node);
    }
    Node* rotlr(Node* node) {
        node->left = rotl(node->left);
        return rotr(node);
    }
    Node* rotrl(Node* node) {
        node->right = rotr(node->right);
        return rotl(node);
    }

    void tostr_helper(Node* node, const std::string& prefix, bool isLeft, std::stringstream& ss) {
        if (!node) return;

        ss << prefix << (isLeft ? "├── " : "└── ") << node->key << "\n";

        std::string childPrefix = prefix + (isLeft ? "│   " : "    ");

        if (node->left || node->right) {
            if (node->left) tostr_helper(node->left, childPrefix, true, ss);
            else ss << childPrefix << "├── (null)\n";

            if (node->right) tostr_helper(node->right, childPrefix, false, ss);
            else ss << childPrefix << "└── (null)\n";
        }
    }
public:
    AVLTree(std::function<bool(T, T)> compare) {
        root = nullptr;
        this->compare = compare;
    }
    ~AVLTree() {
        delete root;
    }

    Node& insert(T& key) {
        Node* curr = root;
        Node* prev = nullptr;
        Stack<Node*> stack;
        Stack<bool> dir;
        while (curr) {
            stack.push(curr);
            if (compare(key, curr->key)) {
                curr = curr->left;
                dir.push(true);
            } else if (compare(curr->key, key)) {
                curr = curr->right;
                dir.push(false);
            } else {
                return *curr;
            }
        }

        Node* created = new Node(key);
        prev = created;
        while (!stack.empty()) {
            curr = stack.pop();
            if (dir.pop()) {
                curr->left = prev;
            } else {
                curr->right = prev;
            }
            prev->parent = curr;
            curr->height = std::max(height(curr->left), height(curr->right)) + 1;
            int b = balance(curr);
            if (b > 1 && compare(key, curr->left->key)) {
                prev = rotll(curr);
            } else if (b < -1 && compare(curr->right->key, key)) {
                prev = rotrr(curr);
            } else if (b > 1 && compare(curr->left->key, key)) {
                prev = rotlr(curr);
            } else if (b < -1 && compare(key, curr->right->key)) {
                prev = rotrl(curr);
            } else {
                prev = curr;
            }
        }
        root = prev;
        return *created;
    }
    bool remove(T& key) {
        Node* curr = root;
        Node* prev = nullptr;
        T currKey = key;
        bool removed = false;
        Stack<Node*> stack;
        Stack<bool> dir;
        while (curr) {
            stack.push(curr);
            if (compare(currKey, curr->key)) {
                curr = curr->left;
                dir.push(true);
            } else if (compare(curr->key, currKey)) {
                curr = curr->right;
                dir.push(false);
            } else if (curr->left && curr->right) {
                Node* tmp = minValNode(curr->right);
                curr->key = tmp->key;
                curr = curr->right;
                dir.push(false);
                currKey = tmp->key;
            } else {
                prev = curr->left ? curr->left : curr->right;
                removed = true;
                delete curr;
                break;
            }
        }

        if (!removed) {
            prev = curr;
        }
        while (!stack.empty()) {
            curr = stack.pop();
            if (!curr) {
                prev = nullptr;
                continue;
            }
            if (dir.pop()) {
                curr->left = prev;
            } else {
                curr->right = prev;
            }
            prev->parent = curr;
            curr->height = std::max(height(curr->left), height(curr->right)) + 1;
            int b = balance(curr);
            if (b > 1 && balance(curr->left) >= 0) {
                prev = rotll(curr);
            } else if (b < -1 && balance(curr->right) <= 0) {
                prev = rotrr(curr);
            } else if (b > 1 && balance(curr->left) < 0) {
                prev = rotlr(curr);
            } else if (b < -1 && balance(curr->right) > 0) {
                prev = rotrl(curr);
            } else {
                prev = curr;
            }
        }
        root = prev;
        return removed;
    }
    Node* find(T& key) {
        Node* curr = root;
        while (curr) {
            if (compare(key, curr->key)) {
                curr = curr->left;
            } else if (compare(curr->key, key)) {
                curr = curr->right;
            } else {
                return curr;
            }
        }
        return nullptr;
    }

    std::string tostr() {
        if (!root) return "Empty Tree";
        std::stringstream ss;
        ss << root->key << "\n";
        tostr_helper(root->left, "", true, ss);
        tostr_helper(root->right, "", false, ss);
        return ss.str();
    }
};