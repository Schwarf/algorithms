add_library(trees_lib INTERFACE
        n-ary_tree.h)
add_library(binary_tree_lib INTERFACE
        binary_trees/tree_has_path_sum.h
        binary_trees/invert_binary_tree.h
        binary_trees/tree_node.h
        binary_trees/pre_order_traversal.h
        binary_trees/in_order_traversal.h
        binary_trees/post_order_traversal.h
        binary_trees/maximum_depth.h
        binary_trees/right_side_view.h
        binary_trees/construct_binary_tree_from_preorder_and_inorder.h
        binary_trees/level_order_traversal.h
        binary_trees/construct_binary_tree_from_inorder_and_postorder.h
        binary_trees/binary_search_tree_from_sorted_array.h
        binary_trees/flatten_binary_search_tree_to_array.h
        binary_trees/flatten_binary_search_tree_to_linked_list.h
        binary_trees/maximum_difference_betwee_node_and_ancestor.h
        binary_trees/maximum_product_of_splitted_tree.h
        binary_trees/maximum_path_sum.h
        binary_trees/find_duplicate_subtrees.h
        binary_trees/is_binary_tree_complete.h
        binary_trees/minimum_depth_of_binary_tree.h binary_trees/all_nodes_in_distance_k.h binary_trees/find_mode_in_binary_tree.h binary_trees/count_nodes_equal_to_average_of_subtree.h binary_trees/find_two_sum_in_binary_tree.h)

add_library(segment_tree_lib INTERFACE segment_trees/segment_tree.h)