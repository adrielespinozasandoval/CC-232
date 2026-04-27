#include "BracketSequence.h"
#include <stdexcept>
#include <cstddef>
#include <string>
#include <vector>
#include <memory>

using BS = cc232::BracketSequence;

void BS::build(Node& node, std::string& seq, size_t& i) {
    size_t j = i, k = 0;
    while (i < seq.length()) {
        if (seq[i] == '(') {
            node.children.push_back(std::make_unique<Node>(&node, k++, i - j));
            build(*node.children.back(), seq, ++i);
        } else if (seq[i] == ')') {
            i++;
            return;
        } else {
            break;
        }
    }
    throw std::invalid_argument("Invalid sequence");
}
void BS::nstr(Node& node, std::string& str, size_t& i) {
    str[i++] = '(';
    for (auto& child: node.children) {
        nstr(*child, str, i);
    }
    str[i++] = ')';
}

BS::Node* BS::nxt(Node& node) {
    auto& vec = getVec(node);
    if (node.listPos + 1 == vec.size()) {
        if (!node.parent) {
            return nullptr;
        }
        return nxt(*node.parent);
    }
    return vec[node.listPos + 1].get();
}
BS::Node* BS::prv(Node& node) {
    if (node.children.empty()) {
        return &node;
    }
    return prv(*node.children.back());
}
std::vector<std::unique_ptr<BS::Node>>& BS::getVec(Node& node) {
    return node.parent ? node.parent->children : roots;
}

BS::Node& BS::searchNode(std::vector<std::unique_ptr<Node>>& nodes, size_t pos) {
    size_t l = 0, r = nodes.size() - 1;
    while (r - l > 1) {
        size_t m = (l + r) / 2;
        if (nodes[m]->seqPos > pos) {
            r = m;
        } else {
            l = m;
        }
    }
    if (l != r) {
        if (nodes[r]->seqPos <= pos) {
            l = r;
        }
    }
    if (nodes[l]->children.empty() || nodes[l]->seqPos == pos) {
        return *nodes[l];
    }
    return searchNode(nodes[l]->children, pos - nodes[l]->seqPos - 1);
}
BS::Node* BS::nextNode(Node& node) {
    if (!node.children.empty()) {
        return node.children[0].get();
    }
    return nxt(node);
}
BS::Node* BS::prevNode(Node& node) {
    if (node.listPos != 0) {
        auto& vec = getVec(node);
        return prv(*vec[node.listPos - 1]);
    }
    return node.parent;
}
size_t BS::startPos(Node& node) {
    size_t pos = node.seqPos;
    Node* curr = node.parent;
    while (curr) {
        pos += curr->seqPos + 1;
        curr = curr->parent;
    }
    return pos;
}
size_t BS::finalPos(Node& node) {
    Node* curr = &node;
    size_t i = 0;
    while (curr->parent) {
        if (curr->listPos + 1 != curr->parent->children.size()) {
            return startPos(*curr->parent->children[curr->listPos + 1]) - i;
        }
        curr = curr->parent;
        i++;
    }
    if (curr->listPos + 1 != roots.size()) {
        return startPos(*roots[curr->listPos + 1]) - i;
    }
    return len - i - 1;
}

BS::BracketSequence(std::string seq) {
    size_t i = 0, k = 0;
    while (i < seq.length()) {
        if (seq[i] != '(') {
            throw std::invalid_argument("Invalid sequence");
        }
        roots.push_back(std::make_unique<Node>(nullptr, k++, i));
        build(*roots.back(), seq, ++i);
    }
    len = seq.length();
}

size_t BS::delBracketPos(size_t i) {
    Node& node = searchNode(roots, i);
    size_t k = node.listPos, sPos = startPos(node), fPos = finalPos(node), removed;
    std::vector<std::unique_ptr<Node>>& vec = getVec(node);
    Node* next = nextNode(node);
    if (k + 1 == vec.size()) {
        removed = fPos - sPos + 1;
        vec.pop_back();
    } else {
        removed = vec[k + 1]->seqPos - vec[k]->seqPos;
        vec.erase(vec.begin() + k);
        for (size_t i = k; i < vec.size(); i++) {
            vec[i]->seqPos -= removed;
            vec[i]->listPos--;
        }
    }
    if (fPos + 1 == len) {
        sPos--;
    }
    len -= removed;
    return sPos;
}
std::string BS::tostr() {
    std::string str;
    str.resize(len);
    size_t i = 0;
    for (auto& root: roots) {
        nstr(*root, str, i);
    }
    return str;
}