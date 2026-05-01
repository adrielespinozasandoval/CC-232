#pragma once

#include <stdexcept>
#include <cstddef>
#include <string>
#include <vector>
#include <memory>

namespace cc232 {

    class BracketSequence {
        struct Node {
            std::vector<std::unique_ptr<Node>> children;
            Node* parent;
            
            size_t listPos;
            size_t seqPos;

            Node(Node* p, size_t k, size_t i): parent(p), listPos(k), seqPos(i) {}
        };

        std::vector<std::unique_ptr<Node>> roots;
        size_t len;

        void build(Node& node, std::string& seq, size_t& i);
        void nstr(Node& node, std::string& str, size_t& i);
        Node* nxt(Node& node);
        Node* prv(Node& node);
        std::vector<std::unique_ptr<Node>>& getVec(Node& node);

        Node& searchNode(std::vector<std::unique_ptr<Node>>& nodes, size_t pos);
        Node* nextNode(Node& node);
        Node* prevNode(Node& node);
        size_t startPos(Node& node);
        size_t finalPos(Node& node);
    public:
        BracketSequence(std::string seq);
        ~BracketSequence() = default;

        size_t delBracketPos(size_t i);
        std::string tostr();
    };
}