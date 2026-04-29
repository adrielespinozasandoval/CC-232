#pragma once

#include "AVLTree.h"
#include <functional>
#include <cstddef>
#include <cstdint>

#define BYTE(x) static_cast<std::byte>(x)

template <typename T>
struct aux_ptr {
    T* value;

    aux_ptr(T v) : value(v) {}
    ~aux_ptr() {

    }

    operator T*() const {
        return value;
    }
};

template <typename T>
class AVLWeightedList: public AVLTree<aux_ptr<T>> {
    using Base = AVLTree<aux_ptr<T>>;
    using Node = typename Base::Node;

    struct Data {
        Node* parent;
        size_t size;
        unsigned int weight;
        T value;

        Data(T v, unsigned int w) : parent(nullptr), size(1), weight(w), value(v) {};
    };
    struct Tracker {
        T* id;
        T* other;
        size_t i;
        std::byte compare;
    };
    AVLTree<Tracker> ctxts;

    template <typename U, typename V>
    static inline U* containerOf(V* val, V U::*member) {
        return reinterpret_cast<T*>(reinterpret_cast<std::byte*>(ptr) - offsetof(T, *member));
    }
    
    bool compare(const T*& val0, const T*& val1) {
        Tracker ctxt = ctxts.find(val0);
        if (!ctxt) {
            ctxt = ctxts.find(val1);
        }
        if (!ctxt) {
            if (val0 == root || val1 == root) {
                ctxt = ctxts.insert({val0 == root ? val0 : val1, nullptr, 0, false});
            } else {
                ctxt = ctxts.insert({val0, nullptr, BYTE(0), false});
                Tracker ctxt1 = ctxts.insert({val1, nullptr, BYTE(0), false});
                ctxt.other = val1, ctxt1.other = val0;
                Node* curr = containerOf(&val0, &Node::key);
                size_t r = curr->left ? curr->left->size + 1 : 1;
                if (ctxt.i == r) {
                    ctxt.compare = BYTE(0);
                    return false;
                }
                if (ctxt.i < r) {
                    ctxt.compare = BYTE(1);
                    return true;
                }
                ctxt.i -= r;
                ctxt1.i -= r;
                ctxt.compare = BYTE(2);
                return false
            }
        }

        bool dir = val0 == ctxt.id;
        T*& other = dir ? val1 : val0;
        if (ctxt.other == other) {
            return ctxt.compare == BYTE(dir ? 1 : 2);
        }
        ctxt.other = other;
        Node* curr = containerOf(&(dir ? val0 : val1), &Node::key);
        size_t r = curr->left ? curr->left->size + 1 : 1;
        if (ctxt.i == r) {
            ctxt.compare = BYTE(0);
            return false;
        }
        if (ctxt.i < r) {
            ctxt.compare = BYTE(1);
            return true;
        }
        ctxt.i -= r;
        ctxt.compare = BYTE(2);
        return false;
    }
    static inline void update(Node* parent, Node* child, bool dir) {
        if (!child) {
            return;
        }
        Data* childData = containerOf(child->key);
        childData->parent = parent;
        if (dir) {
            containerOf(parent->key, &Data::value)->size = (parent->right ? containerOf(parent->right->key, &Data::value)->size : 0) + childData->size + 1;
        } else {
            containerOf(parent->key, &Data::value)->size = (parent->left ? containerOf(parent->left->key, &Data::value)->size : 0) + childData->size + 1;
        }
    }
public:
    AVLWeightedList(std::function<bool(T, T)> compare) : Base([](){}, update) {}

    void add(T value) {
        insert();
    }
    void ins(T value, size_t pos) {
        Data* data = new Data(v, 0);
        T* ptr = &data.value;

    }
    void del(size_t pos) {

    }
    T at(size_t pos) {

    }
};