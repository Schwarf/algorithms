#include <iostream>
#include <vector>
#include <queue>

template<typename T>
struct Node
{
	explicit Node(const T &val)
		: value(val)
	{}
	Node()
		: value(0)
	{}

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
	int start_index = 0;
	int end_index = sorted.size() - 1;
	int middle_index{};
	auto head = new Node<T>();
	auto queue = std::queue<std::pair<Node<T> *, std::pair<int, int >>>();
	queue.push(std::make_pair(head, std::make_pair(start_index, end_index)));
	while (!queue.empty()) {
		auto node = queue.front().first;
		start_index = queue.front().second.first;
		end_index = queue.front().second.second;
		queue.pop();
		middle_index = (start_index + end_index) / 2;
		node->value = sorted[middle_index];
		if (middle_index < end_index ) {
			node->right = new Node<T>();
			queue.push(std::make_pair(node->right, std::make_pair(middle_index + 1, end_index)));
		}
		if (middle_index > start_index) {
			node->left = new Node<T>();
			queue.push(std::make_pair(node->left, std::make_pair(start_index, middle_index -1)));
		}
	}
	return head;
}

template<typename T>
void in_order_traversal(Node<T> *head)
{
	if (head == nullptr)
		return;

	in_order_traversal(head->left);
	std::cout << head->value << "  ";
	in_order_traversal(head->right);
}

int main()
{
	std::vector<int> x{-4, -3, -1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	auto head = create_minimal_binary_search_tree(x);
	auto head2 = create_minimal_binary_search_tree_iteratively(x);
	//std::cout << head->value/head2->value << std::endl;

	//std::cout << head->left->left->value << "  " << head2->left->left->value << std::endl;
	//std::cout << head->right->value/head2->right->value << std::endl;
	in_order_traversal<int>(head);
	std::cout << std::endl;
	// TODO iterative approach not working
	in_order_traversal<int>(head2);
}
