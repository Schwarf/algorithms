//
// Created by andreas on 22.01.22.
//

#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "avl_node.h"
#include <iostream>

template <typename T>
class AVLTree
{
public:
    void insert(const T& value)
    {
        root_ = insert_(root_, value);
        number_of_nodes_++;
    }

    void delete_node_with_value(const T& value)
    {
        root_ = delete_(root_, value);
        if (root_)
            number_of_nodes_--;
        else
            number_of_nodes_ = 0;
    }

    void print_inorder_traversal() const
    {
        print_inorder_traversal_(root_);
    }

    std::vector<T> get_vector_inorder()
    {
        std::vector<T> result;
        write_to_vector_inorder_(root_, result);
        return result;
    }

    int height() const
    {
        return root_->height;
    }

    int number_of_nodes() const
    {
        return number_of_nodes_;
    }

    bool is_value_in_tree(const T& value) const
    {
        return find_(value, root_);
    }

private:
    AVLNode<T>* root_ = nullptr;
    size_t number_of_nodes_{};

    int height_(AVLNode<T>* node) const
    {
        if (node)
            return node->height;
        return 0;
    }

    bool find_(const T& value, AVLNode<T>* node) const
    {
        if (node == nullptr)
            return false;
        if (node->value == value)
            return true;
        if (value < node->value)
            return find_(value, node->left);
        return find_(value, node->right);
    }

    void write_to_vector_inorder_(AVLNode<T>* node, std::vector<T>& result) const
    {
        if (!node)
            return;
        write_to_vector_inorder_(node->left, result);
        result.push_back(node->value);
        write_to_vector_inorder_(node->right, result);
    }

    void print_inorder_traversal_(AVLNode<T>* node) const
    {
        if (!node)
            return;
        print_inorder_traversal_(node->left);
        std::cout << node->value << " " << std::endl;
        print_inorder_traversal_(node->right);
    }

    AVLNode<T>* minimal_value_in_subtree_(AVLNode<T>* node) const
    {
        auto current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    AVLNode<T>* balance_tree_(AVLNode<T>* node)
    {
        node->height = 1 + std::max(height_(node->left), height_(node->right));
        auto balance = compute_balance_(node);
        auto left_balance = compute_balance_(node->left);
        auto right_balance = compute_balance_(node->right);
        // left left case
        // we check the value of the child-node and compare it with the inserted-value
        // if the inserted-value is smaller than the child-node-value
        // we have to perform a simple right rotation
        // https://media.geeksforgeeks.org/wp-content/uploads/AVL-Insertion1-1.jpg
        // definition of balance value seems to be off by a minus sign
        // alternatively check that the balance of the child has the SAME sign (or zero) than the node

        // if (balance > 1 && value < node->left->value)
        if (balance > 1 && left_balance >= 0)
            return right_rotation(node);
        // left right case
        // we check the value of the child-node and compare it with the inserted-value
        // if the inserted-value is larger than the child-node-value
        // we have to perform a left rotation first, than a right rotation
        // https://media.geeksforgeeks.org/wp-content/uploads/AVL_Insertion_3-1.jpg
        // definition of balance value seems to be off by a minus sign
        // alternatively check that the balance of the child has the OPPOSITE sign than the node
        // if (balance > 1 && value > node->left->value) {
        if (balance > 1 && left_balance < 0)
        {
            node->left = left_rotation(node->left);
            return right_rotation(node);
        }
        // right right case
        // we check the value of the child-node and compare it with the inserted-value
        // if the inserted-value is larger than the child-node-value
        // we have to perform a simple left rotation first
        // https://media.geeksforgeeks.org/wp-content/uploads/AVL_INSERTION2-1.jpg
        // definition of balance value seems to be off by a minus sign
        // alternatively check that the balance of the child has the SAME sign (or zero) than the node
        // if (balance < -1 && value > node->right->value)
        if (balance < -1 && right_balance <= 0)
            return left_rotation(node);
        // right left case
        // we check the value of the child-node and compare it with the inserted-value
        // if the inserted-value is smaller than the child-node-value
        // we have to perform a right rotation first, than a left rotation
        // https://media.geeksforgeeks.org/wp-content/uploads/AVL_Tree_4-1.jpg
        // definition of balance value seems to be off by a minus sign
        // alternatively check that the balance of the child has the OPPOSITE sign than the node
        // if (balance < -1 && value < node->right->value) {
        if (balance < -1 && right_balance > 0)
        {
            node->right = right_rotation(node->right);
            return left_rotation(node);
        }
        return nullptr;
    }

    AVLNode<T>* delete_(AVLNode<T>* node, T value)
    {
        if (node == nullptr)
            return nullptr;
        if (value < node->value)
            node->left = delete_(node->left, value);
        else if (value > node->value)
            node->right = delete_(node->right, value);
        else
        {
            AVLNode<T>* temp = nullptr;
            // node with one or no child
            if (node->left == nullptr || node->right == nullptr)
            {
                temp = node->left ? node->left : node->right;
                // no child
                if (temp == nullptr)
                {
                    temp = node;
                    node = nullptr;
                }
                // One child ... copy child content
                else
                    *node = *temp;
                delete (temp);
            }
            // node with two children
            else
            {
                // the node successor is the minimum in the right subtree
                temp = minimal_value_in_subtree_(node->right);
                // replace value in current node with successor node
                node->value = temp->value;
                // delete the successor note
                node->right = delete_(node->right, temp->value);
            }
        }
        // Now check if we need re-balancing
        // tree has only one node
        if (node == nullptr)
            return node;
        auto balanced = balance_tree_(node);
        return balanced ? balanced : node;
    }

    /*
                                   RIGHT ROTATION
                  parent                                        p_l
                  /     \                                      /   \
                 /       \              ------->              /     \
               p_l        p_r                            p_l_l       parent
              /  \                                                   /    \
             /    \                                                 /      \
         p_l_l    p_l_r                                           p_l_r    p_r
    */
    AVLNode<T>* right_rotation(AVLNode<T>* parent)
    {
        auto p_l = parent->left;
        auto p_l_r = p_l->right;
        p_l->right = parent;
        parent->left = p_l_r;
        parent->height = 1 + std::max(height_(parent->left), height_(parent->right));
        p_l->height = 1 + std::max(height_(p_l->left), height_(p_l->right));
        return p_l;
    }

    /*
                                   LEFT ROTATION
                    p_r                                        parent
                  /     \                                      /    \
                 /       \              <-------              /      \
               parent    p_r_r                              p_l       p_r
              /  \                                                   /    \
             /    \                                                 /      \
           p_l    p_r_l                                           p_r_l    p_r_r
    */

    AVLNode<T>* left_rotation(AVLNode<T>* parent)
    {
        auto p_r = parent->right;
        auto p_r_l = p_r->left;
        p_r->left = parent;
        parent->right = p_r_l;
        parent->height = 1 + std::max(height_(parent->left), height_(parent->right));
        p_r->height = 1 + std::max(height_(p_r->left), height_(p_r->right));
        return p_r;
    }

    int compute_balance_(AVLNode<T>* node) const
    {
        if (node == nullptr)
            return 0;
        return height_(node->left) - height_(node->right);
    }

    AVLNode<T>* insert_(AVLNode<T>* node, const T& value)
    {
        if (!node)
            return new AVLNode<T>(value);

        if (value < node->value)
            node->left = insert_(node->left, value);
        else if (value > node->value)
            node->right = insert_(node->right, value);
        else
            return node;

        auto balanced = balance_tree_(node);
        return balanced ? balanced : node;
    }
};


#endif //AVL_TREE_H
