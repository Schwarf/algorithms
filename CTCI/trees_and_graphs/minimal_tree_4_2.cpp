#include <iostream>
#include <vector>

template<typename T>

struct Node
{
	Node(T val) {value = val;}
	T value;
	Node *left = nullptr;
	Node *right = nullptr;
};

template<typename T>
Node<T> *create_minimal_tree(std::vector<T> &sorted, int start_index, int end_index)
{
	if (end_index < start_index)
		return nullptr;
	int middle = (start_index + end_index) / 2;
	auto node = new Node<T>(sorted[middle]);
	node->left = create_minimal_tree(sorted, start_index, middle - 1);
	node->right = create_minimal_tree(sorted, middle + 1, end_index);
	return node;
}

template<typename T>
Node<T> *create_minimal_binary_search_tree(std::vector<T> &sorted)
{
	return create_minimal_tree(sorted, 0, sorted.size() - 1);
}

int main()
{
	std::vector<int> x{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	auto head = create_minimal_binary_search_tree(x);
	std::cout << head->value << std::endl;
	std::cout << head->left->left->left->value << std::endl;
	std::cout << head->right->value << std::endl;
}
