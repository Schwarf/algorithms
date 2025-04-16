//
// Created by andreas on 16.04.25.
//

#ifndef ORDER_STATISTIC_NODE_H
#define ORDER_STATISTIC_NODE_H
#include "avl_node.h"
template <typename T>
struct OrderStatisticNode: public AVLNode<T> {
    explicit OrderStatisticNode(const T& val)
            : AVLNode<T>(val), subtree_size(1) {}
    int subtree_size{};
};

#endif //ORDER_STATISTIC_NODE_H
