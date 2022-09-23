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


private:
	Node<T> *root_ = nullptr;

	void write_to_vector_inorder_(Node<T> *node, std::vector<T> & result)
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

	Node<T> *delete_(Node<T> *node, const T &value)
	{
		if (node == nullptr)
			return nullptr;
		if (value < node->value)
			delete_(node->left, value);
		else if (value > node->value)
			delete_(node->right, value);
		else {
			if (node->left == nullptr && node->right != nullptr) {
				Node<T> *temp = node->right;
				delete node;
			}
			if (node->left != nullptr && node->right == nullptr) {
				Node<T> *temp = node->left;
				delete node;
			}
			Node<T> *temp = nullptr;
		}
		return nullptr;
	}

	void insert_(Node<T> *node, const T &value)
	{

		if (value <= node->value) {
			if (node->left == nullptr)
				node->left = new Node<T>(value);
			else
				insert_(node->left, value);
		}

		if (value > node->value) {
			if (node->right == nullptr)
				node->right = new Node<T>(value);
			else
				insert_(node->right, value);
		}
	}

};


#endif //BINARY_SEARCH_TREE_H
