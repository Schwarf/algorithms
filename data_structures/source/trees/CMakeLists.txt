add_library(trees_lib INTERFACE
        n-ary_tree.h)
add_library(binary_tree_lib INTERFACE binary_trees/tree_has_path_sum.h binary_trees/invert_binary_tree.h binary_trees/tree_node.h binary_trees/pre_order_traversal.h binary_trees/in_order_traversal.h binary_trees/post_order_traversal.h binary_trees/maximum_depth.h)
add_library(segment_tree_lib INTERFACE segment_trees/segment_tree.h)