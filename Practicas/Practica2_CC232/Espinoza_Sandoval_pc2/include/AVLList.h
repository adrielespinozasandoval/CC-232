#pragma once

#include "AVLTree.h"
#include <type_traits>
#include <functional>
#include <stdexcept>
#include <cstddef>
#include <cstdint>
#include <any>

template <typename T, typename aux_ptr = typename AVLTree<T>::aux_ptr>
class AVLList: public AVLTree<typename AVLTree<T>::aux_ptr> {
    using largestInt = AVLTree<T>::largestInt;
    using Base = AVLTree<aux_ptr>;
    using Node = typename Base::Node;

    struct Data {
        Node* parent;
        size_t size;
        std::any info;
        T value;

        Data(T v, std::any f) : parent(nullptr), size(1), info(f), value(v) {};
    };
    struct Tracker {
        enum Result: uint8_t {
            Equal = 0,
            Left = 1,
            Right = 2
        }

        aux_ptr* id;
        aux_ptr* other;
        T* val;
        Result compare;

        Tracker(aux_ptr* id) : id(id), other(nullptr), val(nullptr), compare(0) {}
        Tracker(aux_ptr* id, T* v) : id(id), other(nullptr), val(v), compare(0) {}

        bool operator<(const Tracker& other) const {
            return id->data < other.id->data;
        }
        bool operator>(const Tracker& other) const {
            return id->data > other.id->data;
        }
    };
    static thread_local AVLTree<Tracker> ctxts;
    static const size_t offsData = offsetof(Data, value);

    std::function<bool(T, T)> compare_base;

    template <typename Parent, typename Member>
    static inline Parent* containerOf(Member* ptr, size_t offset) {
        return reinterpret_cast<Parent*>(reinterpret_cast<std::byte*>(ptr) - offset);
    }
    
    bool compare_internal(aux_ptr& val0, aux_ptr& val1) {
        static const size_t offset = offsetof(Node, key);
        bool dir = val0.isIndex;
        if (!(dir || val1.isIndex)) {
            return compare_base(val0, val1);
        }
        aux_ptr& indexed = dir ? val0 : val1, &other = dir ? val1 : val0;
        Tracker* ctxt;
        {
            Tracker tmp(&indexed);
            Node* found = ctxts.find(tmp);
            ctxt = &(found ? found->key : ctxts.insert(tmp).key);
        }
        
        if (ctxt->other == other) {
            return ctxt->compare == dir ? 1 : 2;
        }
        ctxt->other = other;
        Node* curr = containerOf<Node>(&other, offset);
        largestInt r = 1;
        if (curr->left) {
            r = static_cast<largestInt>(containerOf<Data>(reinterpret_cast<T*>(curr->left->key.data), offsData)->size + 1);
        }
        if (indexed.data == r) {
            ctxt->compare = 0;
            return false;
        }
        if (indexed.data < r) {
            ctxt->compare = 1;
            return dir;
        }
        indexed.data -= r;
        ctxt->compare = 2;
        return !dir;
    }
    static inline void update(Node* parent, Node* child, bool dir) {
        if (!child) {
            return;
        }
        Data* childData = containerOf<Data>(child->key, offsData);
        childData->parent = parent;
        if (dir) {
            containerOf<Data>(parent->key, offsData)->size = (parent->right ? containerOf<Data>(parent->right->key, offset)->size : 0) + childData->size + 1;
        } else {
            containerOf<Data>(parent->key, offsData)->size = (parent->left ? containerOf<Data>(parent->left->key, offset)->size : 0) + childData->size + 1;
        }
    }
    void newNode(Node* node) {
        Tracker ctxt = ctxts.find(Tracker(node->key))->key;
        node->key.toVal(ctxt.val);
        ctxts.remove(ctxt);
    }
    void delNode(Node* node) {
        delete containerOf<Data>(node->key.operator T*(), offsData);
    }
public:
    AVLList(std::function<bool(T, T)> compare) : Base(compare_internal, update, newNode, delNode), compare_base(compare) {}

    size_t size() const {
        if (!this->root) {
            return 0;
        }
        return containerOf<Data>(this->root->key.operator T*(), offsData)->size;
    }

    void add(T value, std::any info = {}) {
        insert(value, size(), info);
    }
    void insert(T value, size_t pos, std::any info = {}) {
        Data* data = new Data(value, info);
        aux_ptr aux(pos);
        ctxts.insert(Tracker(aux, &data->value));
        Base::insert(aux);
    }
    void remove(size_t pos) {
        if (pos >= size()) return;
        aux_ptr aux(pos);
        Base::remove(aux);
        ctxts.remove(aux);
    }
    T at(size_t pos) {
        aux_ptr aux(pos);
        Node* node = Base::find(aux);
        if (!node) {
            throw std::out_of_range("Position out of bounds for at(pos).")
        }
        return containerOf<Data>(node->key.operator T*(), offsData)->value;
    }
    /*size_t find(T val) {
        Node* node = 

        //return at(node->key);
    }*/
};