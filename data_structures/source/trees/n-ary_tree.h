//
// Created by andreas on 03.04.22.
//

#ifndef I_TREE_H
#define I_TREE_H
#include <vector>


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
		auto node = root_;
		insert(node, value);
	}

	void insert(N_aryTreeNode<T, maximum_number_of_children> *node, T value)
	{
		if (node->number_of_children() < maximum_number_of_children) {
			auto new_node = new N_aryTreeNode<T, maximum_number_of_children>(value);
			node->push_back(new_node);
			return;
		}
		for (size_t child_index = 0; child_index < maximum_number_of_children; ++child_index) {
			insert(node->children[child_index], value);
		}
	}


private:
	N_aryTreeNode<T, maximum_number_of_children> *root_ = nullptr;
};


#endif //I_TREE_H


