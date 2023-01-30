#include <iostream>
#include <vector>
#include "binary_search_tree/avl_tree.h"
#include "binary_trees/find_two_sum_in_binary_tree.h"
#include "binary_trees/tree_node.h"
#include "tries/trie.h"
#include "graphs/graph.h"
#include "graphs/does_path_in_graph_exist.h"
#include "graphs/is_bipartition_possible.h"
#include "union_find_disjoint_set/quick_find.h"
#include "union_find_disjoint_set/quick_union.h"
int main()
{
	auto avl_tree = AVLTree<int>();
	avl_tree.insert(3);
	avl_tree.insert(5);
	avl_tree.insert(1);
	avl_tree.insert(2);
	avl_tree.insert(7);
	avl_tree.insert(6);
	avl_tree.insert(4);
	avl_tree.insert(10);

	avl_tree.print_inorder_traversal();
//	auto ordered = avl_tree.get_vector_inorder();
	std::cout << "******************" << std::endl;
	avl_tree.delete_node_with_value(5);
	avl_tree.delete_node_with_value(10);
	avl_tree.print_inorder_traversal();

	auto root = new TreeNode<int>(5);
	root->left = new TreeNode<int>(2);
	root->right = new TreeNode<int>(8);
	root->left->left = new TreeNode<int>(1);
	root->left->right = new TreeNode<int>(3);
	std::cout << "******************" << std::endl;
	std::cout << find_target_two_sum(root, 10) << std::endl;
	std::cout << find_target_two_sum(root, 27) << std::endl;
	std::cout << find_target_two_sum(root, 2) << std::endl;

	std::string str_and{"and"};
	std::string str_ant{"ant"};
	std::string str_ban{"ban"};
	std::cout << "*******************TRIE*********************" << std::endl;
	auto trie = Trie<128>();
	trie.insert(str_and);
	trie.insert(str_ant);
	std::cout << trie.search(str_and) << std::endl;
	std::cout << trie.search(str_ban) << std::endl;

	auto graph = Graph<int, int>();
	const std::shared_ptr<GraphNode<int, int>> vertex1(new GraphNode<int, int>(1, 1));
	const std::shared_ptr<GraphNode<int, int>> vertex2(new GraphNode<int, int>(2, 2));
	const std::shared_ptr<GraphNode<int, int>> vertex3(new GraphNode<int, int>(3, 3));

	const std::shared_ptr<GraphNode<int, int>> vertex4(new GraphNode<int, int>(4, 4));
	const std::shared_ptr<GraphNode<int, int>> vertex5(new GraphNode<int, int>(5, 5));
	const std::shared_ptr<GraphNode<int, int>> vertex6(new GraphNode<int, int>(6, 6));

	graph.add_edge(vertex1, vertex2);
	graph.add_edge(vertex1, vertex3);
	graph.add_edge(vertex2, vertex3);
	graph.add_edge(vertex3, vertex5);
	graph.add_edge(vertex4, vertex6);

	std::cout << "Does path exist (1,3): " << does_path_exist(graph, vertex1, vertex5) << std::endl;
	std::cout << "Bi partite should not work: " << is_bi_partition_possible(graph) << std::endl;
	std::cout << std::numeric_limits<int32_t>::min() << std::endl;
	auto queue = std::priority_queue<std::tuple<float, int>, std::vector<std::tuple<float, int> >, std::greater<> >();

	queue.emplace(1.1f, 2);
	queue.emplace(3.1f, -1);
	auto h = queue.top();
	int x = 1;

	auto u = DisjointSetQuickUnion(10);
	std::cout << std::boolalpha;
	u.union_set(1, 2);
	u.union_set(2, 5);
	u.union_set(5, 6);
	u.union_set(6, 7);
	u.union_set(3, 8);
	u.union_set(8, 9);
	std::cout << u.are_connected(1, 5) << std::endl;  // true
	std::cout << u.are_connected(5, 7) << std::endl;  // true
	std::cout << u.are_connected(4, 9) << std::endl;  // false
	// 1-2-5-6-7 3-8-9-4
	u.union_set(9, 4);
	std::cout << u.are_connected(4, 9) << std::endl;  // true

}

