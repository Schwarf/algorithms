//
// Created by andreas on 03.04.22.
//

#ifndef I_TREE_H
#define I_TREE_H
#include <vector>
#include <functional>
#include <iostream>
#include <stack>

template<typename T>
void print(T value)
{
	std::cout << value << std::endl;
}

template<typename T, size_t maximal_number_of_children>
struct N_aryTreeNode
{
	T value;
	std::vector<N_aryTreeNode<T, maximal_number_of_children> *> children;
	N_aryTreeNode()
	{
		children.resize(maximal_number_of_children, nullptr);
	}
	explicit N_aryTreeNode(T val)
	{
		N_aryTreeNode();
		value = val;
	}
	size_t number_of_children()
	{
		return children.size();
	}
};

template<typename T, size_t maximum_number_of_children>
class N_aryTree
{
public:
	void insert(T value)
	{
		if (root_ == nullptr) {
			root_ = new N_aryTreeNode<T, maximum_number_of_children>(value);
			return;
		}
		insert(root_, value);
	}

	bool insert(N_aryTreeNode<T, maximum_number_of_children> *node, T value)
	{
		for(auto & child : node->children)
		{
			if(!child) {
				child = new N_aryTreeNode<T, maximum_number_of_children>(value);
				return true;
			}
		}
	}

	
	void traverse_preorder(std::function<void(T)> function)
	{
		auto node = root_;
		if (!node)
			return;
		preorder_traversal(node, function);
	}

	void traverse_postorder(std::function<void(T)> function)
	{
		auto node = root_;
		if (!node)
			return;
		postorder_traversal(node, function);
	}

	void traverse_inorder(std::function<void(T)> function)
	{
		auto node = root_;
		if (!node)
			return;
		inorder_traversal(node, function);
	}


private:
	void preorder_traversal(N_aryTreeNode<T, maximum_number_of_children> *node, std::function<void(T)> function)
	{
		function(node->value);
		for (const auto child: node->children) {
			preorder_traversal(child, function);
		}
	}

	void postorder_traversal(N_aryTreeNode<T, maximum_number_of_children> *node, std::function<void(T)> function)
	{
		for (const auto child: node->children) {
			postorder_traversal(child, function);
		}
		function(node->value);

	}

	void inorder_traversal(N_aryTreeNode<T, maximum_number_of_children> *node, std::function<void(T)> function)
	{
		for (size_t child_index = 0; child_index < node->number_of_children() / 2; ++child_index) {
			inorder_traversal(node->children[child_index], function);
		}
		function(node->value);
		for (size_t child_index = node->number_of_children() / 2; child_index < node->number_of_children();
			 ++child_index) {
			inorder_traversal(node->children[child_index], function);
		}

	}


private:
	N_aryTreeNode<T, maximum_number_of_children> *root_ = nullptr;
};


#endif //I_TREE_H


