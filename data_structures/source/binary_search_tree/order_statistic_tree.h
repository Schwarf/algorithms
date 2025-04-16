//
// Created by andreas on 16.04.25.
//

#ifndef ORDER_STATISTIC_TREE_H
#define ORDER_STATISTIC_TREE_H
#include "avl_tree.h"
#include "order_statistic_node.h"

template <typename T>
class OrderStatisticTree : public AVLTree<T> {
public:
    T get_ith(int i) const {
        auto node = get_ith_(static_cast<OrderStatisticNode<T>*>(this->root_), i);
        if (!node)
              throw std::out_of_range("Index out of bounds");
        return node->value;
    }

protected:
    using Node = OrderStatisticNode<T>;

    OrderStatisticNode<T>* insert_(OrderStatisticNode<T>* node, const T& value) override {
        if (!node)
          return new OrderStatisticNode<T>(value);

        if (value < node->value)
            node->left = insert_(static_cast<Node*>(node->left), value);
        else if (value > node->value)
            node->right = insert_(static_cast<Node*>(node->right), value);
        else
            return static_cast<Node*>(node);
        node->height = 1 + std::max(this->height_(node->left), this->height_(node->right));
        node->subtree_size = 1 + size_(static_cast<Node*>(node->left)) + size_(static_cast<Node*>(node->right));


        // balance as needed
        auto balanced = balance_tree_(node);
        return balanced ? balanced : node;
    }

    int size_(Node* node) const {
        return node ? node->subtree_size : 0;
    }

    void update_(Node* node) {
        if (!node) return;
    }

    Node* get_ith_(Node* node, int i) const {
        if (!node)
          return nullptr;

        int left_size = size_(static_cast<Node*>(node->left));

        if (i == left_size + 1)
            return node;
        else if (i <= left_size)
            return get_ith_(static_cast<Node*>(node->left), i);
        else
            return get_ith_(static_cast<Node*>(node->right), i - left_size - 1);
    }
};

#endif //ORDER_STATISTIC_TREE_H
