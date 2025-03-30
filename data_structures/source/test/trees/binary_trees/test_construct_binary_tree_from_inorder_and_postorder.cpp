//
// Created by andreas on 14.07.22.
//

#include "setup_binary_tree.h"
#include "trees/binary_trees/construct_binary_tree_from_inorder_and_postorder.h"
#include "trees/binary_trees/pre_order_traversal.h"

TEST_F(SetupBinaryTree, test_construct_binary_tree_from_inorder_and_postorder)
{
    auto constructed_root = construct_from_inorder_and_postorder(postorder, inorder);
    auto result_constructed = pre_order_traversal_recursive(constructed_root);
    for (size_t index = 0; index < preorder.size(); ++index)
    {
        EXPECT_EQ(result_constructed.at(index), preorder.at(index));
    }
}
