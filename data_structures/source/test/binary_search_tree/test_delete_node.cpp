//
// Created by andreas on 13.09.26.
//
#include "../../binary_search_tree/delete_node.h"

#include "gtest/gtest.h"
#include "test_helper.h"

#include <vector>

namespace
{
class DeleteNodeTest : public testing::Test
{
protected:
    void SetUp() override { TestTracker::getInstance().clear(); }
};

template <typename T>
TreeNode<T>* node(T value, TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr)
{
    return new TreeNode<T>(value, left, right);
}

template <typename T>
void collect_in_order(TreeNode<T>* root, std::vector<T>& values)
{
    if (!root)
        return;

    collect_in_order(root->left, values);
    values.push_back(root->value);
    collect_in_order(root->right, values);
}

template <typename T>
std::vector<T> values_in_order(TreeNode<T>* root)
{
    std::vector<T> values;
    collect_in_order(root, values);
    return values;
}
} // namespace

TEST_F(DeleteNodeTest, EmptyTreeReturnsNull)
{
    EXPECT_EQ(delete_node<int>(nullptr, 10), nullptr);
}

TEST_F(DeleteNodeTest, MissingValueLeavesTreeUnchanged)
{
    auto root = node(5, node(3, node(2), node(4)), node(7, node(6), node(8)));

    root = delete_node(root, 10);

    EXPECT_TRUE(is_valid_binary_search_tree(root));
    EXPECT_EQ(values_in_order(root), (std::vector<int>{2, 3, 4, 5, 6, 7, 8}));

    delete_tree(root);
}

TEST_F(DeleteNodeTest, DeletesLeafNode)
{
    auto root = node(5, node(3, node(2), node(4)), node(7));
    auto deleted = root->left->right;

    root = delete_node(root, 4);

    EXPECT_TRUE(TestTracker::getInstance().wasNodeDeleted(deleted));
    EXPECT_TRUE(is_valid_binary_search_tree(root));
    EXPECT_EQ(values_in_order(root), (std::vector<int>{2, 3, 5, 7}));

    delete_tree(root);
}

TEST_F(DeleteNodeTest, DeletesNodeWithOnlyLeftChild)
{
    auto root = node(5, node<int>(3, node(2), nullptr), node(7));
    auto deleted = root->left;

    root = delete_node(root, 3);

    EXPECT_TRUE(TestTracker::getInstance().wasNodeDeleted(deleted));
    EXPECT_TRUE(is_valid_binary_search_tree(root));
    EXPECT_EQ(values_in_order(root), (std::vector<int>{2, 5, 7}));
    EXPECT_EQ(root->left->value, 2);

    delete_tree(root);
}

TEST_F(DeleteNodeTest, DeletesNodeWithOnlyRightChild)
{
    auto root = node(5, node(3), node<int>(7, nullptr, node(8)));
    auto deleted = root->right;

    root = delete_node(root, 7);

    EXPECT_TRUE(TestTracker::getInstance().wasNodeDeleted(deleted));
    EXPECT_TRUE(is_valid_binary_search_tree(root));
    EXPECT_EQ(values_in_order(root), (std::vector<int>{3, 5, 8}));
    EXPECT_EQ(root->right->value, 8);

    delete_tree(root);
}

TEST_F(DeleteNodeTest, DeletesNodeWithTwoChildrenUsingInOrderPredecessor)
{
    auto root = node(20, node(10, node<int>(5, nullptr, node(7)), node(15)), node(25));
    auto predecessor = root->left->left->right;

    root = delete_node(root, 10);

    EXPECT_TRUE(TestTracker::getInstance().wasNodeDeleted(predecessor));
    EXPECT_TRUE(is_valid_binary_search_tree(root));
    EXPECT_EQ(values_in_order(root), (std::vector<int>{5, 7, 15, 20, 25}));
    EXPECT_EQ(root->left->value, 7);

    delete_tree(root);
}

TEST_F(DeleteNodeTest, DeletesRootWithTwoChildren)
{
    auto root = node(10, node(5, node(3), node(7)), node(15, node(12), node(20)));
    auto original_root = root;

    root = delete_node(root, 10);

    EXPECT_FALSE(TestTracker::getInstance().wasNodeDeleted(original_root));
    EXPECT_TRUE(is_valid_binary_search_tree(root));
    EXPECT_EQ(root->value, 7);
    EXPECT_EQ(values_in_order(root), (std::vector<int>{3, 5, 7, 12, 15, 20}));

    delete_tree(root);
}

TEST_F(DeleteNodeTest, DeletesSingleNodeRoot)
{
    auto root = node(42);
    auto original_root = root;

    root = delete_node(root, 42);

    EXPECT_EQ(root, nullptr);
    EXPECT_TRUE(TestTracker::getInstance().wasNodeDeleted(original_root));
}
