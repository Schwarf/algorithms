#include <iostream>
#include <vector>
#include "binary_search_tree/avl_tree.h"
#include "binary_trees/find_two_sum_in_binary_tree.h"
#include "binary_trees/tree_node.h"
#include "tries/trie.h"
#include "graphs/graph.h"
#include "graphs/does_path_in_graph_exist.h"
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

	auto graph = BidirectionalGraph<int, double>();
	const std::shared_ptr<GraphNode<int, double>> node1(new GraphNode<int, double>(1, 1.0));
	const std::shared_ptr<GraphNode<int, double>> node2(new GraphNode<int, double>(2, 2.0));
	const std::shared_ptr<GraphNode<int, double>> node3(new GraphNode<int, double>(3, 3.0));

	const std::shared_ptr<GraphNode<int, double>> node4(new GraphNode<int, double>(4, 4.0));
	const std::shared_ptr<GraphNode<int, double>> node5(new GraphNode<int, double>(5, 5.0));
	const std::shared_ptr<GraphNode<int, double>> node6(new GraphNode<int, double>(6, 6.0));

	graph.add_edge(node1, node2);
	graph.add_edge(node1, node3);
	graph.add_edge(node2, node3);
	graph.add_edge(node3, node5);
	graph.add_edge(node4, node6);

	std::cout << "Does path exist (1,3): " << does_path_exist(graph, node1, node5) << std::endl;

}

