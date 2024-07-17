//
// Created by andreas on 30.04.22.
//

#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <unordered_set>
#include <unordered_set>
#include <iostream>

class TestTracker {
public:
    static TestTracker &getInstance() {
        static TestTracker instance;
        return instance;
    }

    void addDeletedNode(void *node) {
        deletedNodes.insert(node);
    }

    bool wasNodeDeleted(void *node) const {
        return deletedNodes.find(node) != deletedNodes.end();
    }

    void clear() {
        deletedNodes.clear();
    }

private:
    std::unordered_set<void *> deletedNodes;

    TestTracker() = default;

    TestTracker(const TestTracker &) = delete;

    void operator=(const TestTracker &) = delete;
};


template<typename T>
struct TreeNode {
    T value;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
            :
            value(T{}),
            left(nullptr),
            right(nullptr) {
    }

    explicit TreeNode(const T &val)
            :
            value(val),
            left(nullptr),
            right(nullptr) {
    }

    TreeNode(const T &val, TreeNode *left, TreeNode *right)
            :
            value(val),
            left(left),
            right(right) {
    }

    ~TreeNode() {
        TestTracker::getInstance().addDeletedNode(this);
    }
};

#endif //TREE_NODE_H
