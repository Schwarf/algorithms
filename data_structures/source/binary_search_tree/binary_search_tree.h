//
// Created by andreas on 22.01.22.
//

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "node.h"
template<typename T>
class BinarySearchTree{
public:
	void insert(const T & value)
	{
		insert_(root_, value);
	}

	void delete_node_with_value(const T & value)
	{
		delete_(root_, value);
	}



private:
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

		}
	}

	void insert_(Node<T> * node, const T & value){
		if(node == nullptr) {
			node = new Node<T>(value);
			return;
		}
		if(value <= node->value)
			insert_(node->left(), value);
		if(value > node->value)
			insert_(node->right(), value);
	}

};


#endif //BINARY_SEARCH_TREE_H
