#pragma once

#include <stdexcept>
#include <cstddef>
#include <string>
#include <vector>

class BracketSequence {
    struct Node {
        std::vector<Node> children;
        Node* parent;
        
        size_t listPos;
        size_t seqPos;

        Node(Node* p, size_t k, size_t i): parent(p), listPos(k), seqPos(i) {}
    };

    std::vector<Node> roots;
    size_t len;

    void build(Node& node, std::string& seq, size_t& i) {
        size_t j = i, k = 0;
        while (i < seq.length()) {
            if (seq[i] == '(') {
                Node child = Node(&node, ++k, i - j);
                build(child, seq, ++i);
                node.children.push_back(child);
            } else if (seq[i] == ')') {
                i++;
                return;
            } else {
                break;
            }
        }
        throw std::invalid_argument("Invalid sequence");
    }
    void nstr(Node& node, std::string& str, size_t& i) {
        str[i++] = '(';
        for (Node& child: node.children) {
            nstr(child, str, i);
        }
        str[i++] = ')';
    }
    Node* nxt(Node& node) {
        std::vector<Node>& vec = node.parent ? roots : node.parent->children;
        if (node.listPos + 1 == vec.size()) {
            if (!node.parent) {
                return nullptr;
            }
            return nxt(*node.parent);
        }
        return &vec[node.listPos + 1];
    }
    Node* prv(Node& node) {
        if (node.children.empty()) {
            return &node;
        }
        return prv(node.children.back());
    }

    Node& searchNode(std::vector<Node>& nodes, size_t pos) {
        size_t l = 0, r = nodes.size() - 1;
        while (l < r) {
            size_t m = (l + r) / 2;
            if (nodes[m].seqPos > pos) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (nodes[l].children.empty() || nodes[l].seqPos == pos) {
            return nodes[l];
        }
        return searchNode(nodes[l].children, pos - nodes[l].seqPos);
    }
    Node* nextNode(Node& node) {
        if (!node.children.empty()) {
            return &node.children[0];
        }
        return nxt(node);
    }
    Node* prevNode(Node& node) {
        if (node.listPos != 0) {
            std::vector<Node>& vec = node.parent ? roots : node.parent->children;
            return prv(vec[node.listPos - 1]);
        }
        return node.parent;
    }
    size_t startPos(Node& node) {
        size_t pos;
        Node* ancestor = node.parent;
        while (ancestor) {
            pos += ancestor->seqPos + 1;
            ancestor = ancestor->parent;
        }
        return pos;
    }
    size_t finalPos(Node& node) {
        Node* next = nextNode(node);
        if (!next) {
            return len;
        }
        return startPos(*next) - 1;
    }
public:
    BracketSequence(std::string seq) {
        size_t i = 0, k = 0;
        while (i < seq.length()) {
            if (seq[i] != '(') {
                throw std::invalid_argument("Invalid sequence");
            }
            Node root = Node(nullptr, ++k, i);
            build(root, seq, ++i);
            roots.push_back(root);
        }
        len = seq.length();
    }
    ~BracketSequence() = default;

    size_t delNode(size_t i) {
        Node& node = searchNode(roots, i);
        size_t k = node.listPos, pos;
        std::vector<Node>& vec = node.parent ? roots : node.parent->children;
        Node* next = nextNode(node);
        if (next) {
            pos = startPos(*next);
        } else {
            //pos = finalPos(*prevNode(node));
            pos = (node.listPos == 1) ? 0 : (node.listPos - 1);
        }
        if (k + 1 == vec.size()) {
            vec.pop_back();
            len -= vec[k].seqPos + 1;
        } else {
            size_t removed = vec[k + 1].seqPos - vec[k].seqPos;
            vec.erase(vec.begin() + k);
            for (size_t i = k; i < vec.size(); i++) {
                vec[i].seqPos -= removed;
                vec[i].listPos--;
            }
            len -= removed;
        }
        
        //return finalPos(*prevNode(node));

    }
    std::string tostr() {
        std::string str;
        str.reserve(len);
        size_t i = 0;
        for (Node& root: roots) {
            nstr(root, str, i);
        }
        return str;
    }
};