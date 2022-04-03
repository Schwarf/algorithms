//
// Created by andreas on 03.04.22.
//

#ifndef I_TREE_H
#define I_TREE_H
#include <vector>
#include <functional>
#include <iostream>
#include <stack>

template <typename T>
void print(T value)
{
	std::cout << value << std::endl;
}


template  <typename T>
struct fill_stack
{
	void operator()(T value){
		stack_.push(value);
		auto x = size();
	}
	T operator()(){
		stack_.pop();
	}
	size_t size() const
	{
		return stack_.size();
	}

private:
	std::stack<T> stack_;
};


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
		if(root_==nullptr)
		{
			root_ = new N_aryTreeNode<T, maximum_number_of_children>(value);
			return;
		}
		insert(root_, value);
	}

	void insert(N_aryTreeNode<T, maximum_number_of_children> *node, T value)
	{
		if (node->number_of_children() < maximum_number_of_children) {
			auto new_node = new N_aryTreeNode<T, maximum_number_of_children>(value);
			node->children.push_back(new_node);
			return;
		}
		for (size_t child_index = 0; child_index < maximum_number_of_children; ++child_index) {
			insert(node->children[child_index], value);
		}
	}

	void traverse_in_preorder(std::function<void(T)> function){
		auto node = root_;
		if(!node)
			return;
		preorder_traversal(node, function);
	}

	void traverse_in_postorder(std::function<void(T)> function){
		auto node = root_;
		if(!node)
			return;
		auto help = fill_stack<T>();
		preorder_traversal(node, help);
		auto size = help.size();
		if(function) {
			for (size_t index = 0; index < size; ++index) {
				function(pop());
			}
		}

	}


private:
	void preorder_traversal(N_aryTreeNode<T, maximum_number_of_children> * node, std::function<void(T)> function)
	{
		if(function)
			function(node->value);
		for(const auto & child: node->children)
			{
				if(function)
					function(child->value);
			}
	}



private:
	N_aryTreeNode<T, maximum_number_of_children> *root_ = nullptr;
};


#endif //I_TREE_H


