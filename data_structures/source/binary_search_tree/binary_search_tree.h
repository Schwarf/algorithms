//
// Created by andreas on 22.01.22.
//

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "node.h"
template<typename Key, typename Value>
class BinarySearchTree{
public:
	void add(const Key & key, const Value & value)
	{
		root_ = add_(root_, key, value);
	}

	Node<Key, Value>* add_(Node<Key, Value> * node, const Key & key, const Value & value){
		if(node == nullptr)
			return new Node<Key, Value>(key, value);
		if(key <= node->key())
			add_(node->left(), key, value);
		if(key > node->key())
			add_(node->right(), key, value);

		node->reset_value(value);
		return node;
	}

	Value get(const Key & key) const
	{
		auto node = root_;
		while(node != nullptr)
		{
			if(node->key() < key)
			{
				node = node->left();
			}
			else if(node->key() > key)
			{
				node = node->right();
			}
			else
			{
				return node->value();
			}
		}
		return Value{};
	}


private:
	Node<Key, Value> * root_ = nullptr;

};


#endif //BINARY_SEARCH_TREE_H
