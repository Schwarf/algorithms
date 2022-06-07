#include <iostream>
#include <vector>
#include <queue>

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

template<typename T>
Node<T> *create_minimal_binary_search_tree_iteratively(std::vector<T> &sorted)
{
	int index = (sorted.size() -1)/ 2;
	auto head = new Node<T>(sorted[index]);
	auto queue = std::queue<std::pair<Node<T>*, int>>();
	queue.push(std::make_pair(head, index));
	while(!queue.empty() && ((index+index/2) < sorted.size()) && ((index-index/2) > -1))
	{
		auto node = queue.front().first;
		index = queue.front().second;
		queue.pop();
		auto left_index = index - index/2;
		auto right_index = index + index/2;
		auto left = new Node<T>(sorted[left_index]);
		auto right = new Node<T>(sorted[right_index]);
		node->left = left;
		node->right = right;
		queue.push(std::make_pair(left, left_index));
		queue.push(std::make_pair(right, right_index));
	}
	return head;
}

int main()
{
	std::vector<int> x{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	auto head = create_minimal_binary_search_tree(x);
	auto head2 = create_minimal_binary_search_tree_iteratively(x);

	std::cout << head->value << std::endl;
	std::cout << head->left->left->left->value << std::endl;
	std::cout << head->right->value << std::endl;
}
