//
// Created by andreas on 09.05.22.
//

#include "setup_binary_tree.h"
#include "trees/binary_trees/post_order_traversal.h"


TEST_F(SetupBinaryTree, test_postorder_traversal) {
    auto root = SetupBinaryTree::binary_tree_root();
    auto result = post_order_traversal(root);
    for (size_t index = 0; index < postorder.size(); ++index) {
        EXPECT_EQ(result.at(index), postorder.at(index));
    }
}

TEST_F(SetupBinaryTree, test_postorder_traversal_recursive) {
    auto root = SetupBinaryTree::binary_tree_root();
    auto result = post_order_traversal_recursive(root);
    for (size_t index = 0; index < postorder.size(); ++index) {
        EXPECT_EQ(result.at(index), postorder.at(index));
    }
}