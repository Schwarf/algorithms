//
// Created by andreas on 22.01.22.
//

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "node.h"
#include <iostream>

template<typename T>
class BinarySearchTree
{
public:
	void insert(const T &value)
	{
		if (!root_) {
			root_ = new Node<T>(value);
			return;
		}
		else {
			auto node = root_;
			insert_(node, value);
		}
	}

	void delete_node_with_value(const T &value)
	{
		root_ = delete_(root_, value);
	}

	void print_inorder_traversal()
	{
		print_inorder_traversal_(root_);
	}

	std::vector<T> write_to_vector_inorder()
	{
		std::vector<T> result;
		write_to_vector_inorder_(root_, result);
		return result;
	}

	int height(Node<T> * node)
	{
		if(node)
			return node->height;
		return 0;
	}


private:
	Node<T> *root_ = nullptr;

	void write_to_vector_inorder_(Node<T> *node, std::vector<T> &result)
	{
		if (!node)
			return;
		write_to_vector_inorder_(node->left, result);
		result.push_back(node->value);
		write_to_vector_inorder_(node->right, result);
	}

	void print_inorder_traversal_(Node<T> *node)
	{
		if (!node)
			return;
		print_inorder_traversal_(node->left);
		std::cout << node->value << " " << std::endl;
		print_inorder_traversal_(node->right);
	}

	Node<T> *delete_(Node<T> *node, T value)
	{
		if (node == nullptr)
			return nullptr;
		if (value < node->value)
			delete_(node->left, value);
		else if (value > node->value)
			delete_(node->right, value);
		else {
			// Case: Is leaf node
			if (node->left == nullptr && node->right == nullptr) {
				delete node;
				return nullptr;
			}
			// Case: Has one child
			if (node->left == nullptr) {
				auto child = node->right;
				delete node;
				return child;
			}
			else if (node->right == nullptr) {
				auto child = node->left;
				delete node;
				return child;
			}
			// Case: Has two children
			if (node->left && node->right) {
				auto temp = node->right;
				while (temp->left)
					temp = temp->left;
				node->value = temp->value;
				node->right = delete_(node->right, node->value);
			}
		}
		return node;
	}
	//                               RIGHT ROTATION
	//              parent                                        p_l
	//              /     \                                      /   \
	//             /       \              ------->              /     \
	//           p_l        p_r                            p_l_l       parent
	//          /  \                                                   /    \
	//         /    \                                                 /      \
	//     p_l_l    p_l_r                                           p_l_r    p_r
	//
	Node<T> *right_rotation(Node<T> *parent)
	{
		auto p_l = parent->left;
		auto p_l_r = p_l->right;
		p_l->right = parent;
		parent->left = p_l_r;
		parent->height = 1 + std::max(height(parent->left), height(parent->right));
		p_l->height = 1 + std::max(height(p_l->left), height(p_l->right));
		return p_l;

	}



	void insert_(Node<T> *node, const T &value)
	{
		if(!node)
			return new Node<T>(value);

		if (value < node->value)
				node->left = insert_(node->left, value);
		else if (value > node->value)
				node->right = insert_(node->right, value);
		else
			return node;

		node->height = 1 + std::max(height(node->left), height(node->right));
		int balance = height(node->left) - height(node->right);

	}

};


#endif //BINARY_SEARCH_TREE_H
