//
// Created by andreas on 22.01.22.
//

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "node.h"
#include <iostream>

template<typename T>
class BinarySearchTree{
public:
	void insert(const T & value)
	{
		if(!root_) {
			root_ = new Node<T>(value);
			return;
		}
		else {
			auto node = root_;
			insert_(node, value);
		}
	}

	void delete_node_with_value(const T & value)
	{
		root_ = delete_(root_, value);
	}

	void print_inorder_traversal()
	{
		print_inorder_traversal_(root_);
	}


private:

	Node<T> *  print_inorder_traversal_(Node<T> * node){
		if(!node)
			return;
		print_inorder_traversal_(node->left);
		std::cout<< node->value << " " << std::endl;
		print_inorder_traversal_(node->right);
	}

	Node<T> * root_ = nullptr;
	void delete_(Node<T> * node, const T & value)
	{
		if(node ==nullptr)
			return;
		if(value < node->value)
			delete_(node->left,value);
		else if(value > node->value)
			delete_(node->right,value);
		else
		{
			if(node->left == nullptr && node->right != nullptr)
			{
				Node<T> * temp = node->right;
				delete node;
			}
			if(node->left != nullptr && node->right == nullptr)
			{
				Node<T> * temp = node->left;
				delete node;
			}
			Node<T> * temp =
		}
	}

	void insert_(Node<T> * node, const T & value){

		if(value <= node->value)
		{
			if(node->left == nullptr)
				node->left = new Node<T>(value);
			else
				insert_(node->left, value);
		}

		if(value > node->value)
		{
			if(node->right == nullptr)
				node->right = new Node<T>(value);
			else
				insert_(node->right, value);
		}
	}

};


#endif //BINARY_SEARCH_TREE_H
