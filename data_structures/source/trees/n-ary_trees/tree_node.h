//
// Created by andreas on 26.08.24.
//

#ifndef DATA_STRUCTURES_TREE_NODE_H
#define DATA_STRUCTURES_TREE_NODE_H

#include <vector>

template<typename T>
struct TreeNode {
    explicit TreeNode(T val) : value{val} {}

    std::vector<TreeNode *> children{};
    T value{};
};

#endif //DATA_STRUCTURES_TREE_NODE_H
