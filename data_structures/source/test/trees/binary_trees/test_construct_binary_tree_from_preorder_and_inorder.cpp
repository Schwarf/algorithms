//
// Created by andreas on 14.07.22.
//

#include "setup_binary_tree.h"
#include "trees/binary_trees/construct_binary_tree_from_preorder_and_inorder.h"
#include "trees/binary_trees/post_order_traversal.h"
#include "trees/binary_trees/in_order_traversal.h"

TEST_F(SetupBinaryTree, test_construct_binary_tree_from_preorder_and_inorder)
{
    auto constructed_root = construct_from_preorder_and_inorder(preorder, inorder);
    auto result_constructed = post_order_traversal_recursive(constructed_root);
    auto result_constructed2 = in_order_traversal(constructed_root);
    for (size_t index = 0; index < postorder.size(); ++index)
    {
        EXPECT_EQ(result_constructed.at(index), postorder.at(index));
        EXPECT_EQ(result_constructed2.at(index), inorder.at(index));
    }
}
