//
// Created by andreas on 12.09.26.
//

#include <memory>
#include <vector>

#include "gtest/gtest.h"
#include "trees/binary_trees/iterative_traversal.h"

namespace
{
using Node = ParentedTreeNode<int>;

std::vector<int>* visited_values = nullptr;

void record_value(Node* node)
{
    visited_values->push_back(node->value);
}
}

class SetupIterativeTraversal : public testing::Test
{
protected:
    Node* make_node(int value)
    {
        nodes.push_back(std::make_unique<Node>(value));
        return nodes.back().get();
    }

    static void connect(Node* parent, Node* left, Node* right)
    {
        parent->left = left;
        parent->right = right;

        if (left)
            left->parent = parent;
        if (right)
            right->parent = parent;
    }

    std::vector<int> collect_values(Node* root)
    {
        std::vector<int> result;
        visited_values = &result;
        iterative_inorder_traversal(root, record_value);
        visited_values = nullptr;
        return result;
    }

    std::vector<int> collect_preorder_values(Node* root)
    {
        std::vector<int> result;
        visited_values = &result;
        iterative_preorder_traversal(root, record_value);
        visited_values = nullptr;
        return result;
    }

    std::vector<int> collect_postorder_values(Node* root)
    {
        std::vector<int> result;
        visited_values = &result;
        iterative_postorder_traversal(root, record_value);
        visited_values = nullptr;
        return result;
    }

    // A complete binary search tree with 15 nodes.
    Node* create_complete_tree()
    {
        auto root = make_node(25);
        auto node15 = make_node(15);
        auto node50 = make_node(50);
        auto node10 = make_node(10);
        auto node22 = make_node(22);
        auto node35 = make_node(35);
        auto node70 = make_node(70);
        auto node4 = make_node(4);
        auto node12 = make_node(12);
        auto node18 = make_node(18);
        auto node24 = make_node(24);
        auto node31 = make_node(31);
        auto node44 = make_node(44);
        auto node66 = make_node(66);
        auto node90 = make_node(90);

        connect(root, node15, node50);
        connect(node15, node10, node22);
        connect(node50, node35, node70);
        connect(node10, node4, node12);
        connect(node22, node18, node24);
        connect(node35, node31, node44);
        connect(node70, node66, node90);

        return root;
    }

    std::vector<std::unique_ptr<Node>> nodes;
};

TEST_F(SetupIterativeTraversal, returns_empty_result_for_null_root)
{
    EXPECT_EQ(collect_values(nullptr), std::vector<int>{});
}

TEST_F(SetupIterativeTraversal, visits_single_node_tree)
{
    auto root = make_node(42);

    EXPECT_EQ(collect_values(root), std::vector<int>{42});
}

TEST_F(SetupIterativeTraversal, visits_complete_tree_in_inorder)
{
    auto root = create_complete_tree();

    const std::vector<int> expected{4, 10, 12, 15, 18, 22, 24, 25, 31, 35, 44, 50, 66, 70, 90};
    EXPECT_EQ(collect_values(root), expected);
}

TEST_F(SetupIterativeTraversal, visits_left_skewed_tree_in_inorder)
{
    auto root = make_node(4);
    auto node3 = make_node(3);
    auto node2 = make_node(2);
    auto node1 = make_node(1);

    connect(root, node3, nullptr);
    connect(node3, node2, nullptr);
    connect(node2, node1, nullptr);

    EXPECT_EQ(collect_values(root), std::vector<int>({1, 2, 3, 4}));
}

TEST_F(SetupIterativeTraversal, visits_right_skewed_tree_in_inorder)
{
    auto root = make_node(1);
    auto node2 = make_node(2);
    auto node3 = make_node(3);
    auto node4 = make_node(4);

    connect(root, nullptr, node2);
    connect(node2, nullptr, node3);
    connect(node3, nullptr, node4);

    EXPECT_EQ(collect_values(root), std::vector<int>({1, 2, 3, 4}));
}

TEST_F(SetupIterativeTraversal, visits_sparse_tree_in_inorder)
{
    auto root = make_node(8);
    auto node3 = make_node(3);
    auto node10 = make_node(10);
    auto node1 = make_node(1);
    auto node6 = make_node(6);
    auto node14 = make_node(14);
    auto node4 = make_node(4);
    auto node7 = make_node(7);
    auto node13 = make_node(13);

    connect(root, node3, node10);
    connect(node3, node1, node6);
    connect(node10, nullptr, node14);
    connect(node6, node4, node7);
    connect(node14, node13, nullptr);

    EXPECT_EQ(collect_values(root), std::vector<int>({1, 3, 4, 6, 7, 8, 10, 13, 14}));
}

TEST_F(SetupIterativeTraversal, preorder_returns_empty_result_for_null_root)
{
    EXPECT_EQ(collect_preorder_values(nullptr), std::vector<int>{});
}

TEST_F(SetupIterativeTraversal, preorder_visits_single_node_tree)
{
    auto root = make_node(42);

    EXPECT_EQ(collect_preorder_values(root), std::vector<int>{42});
}

TEST_F(SetupIterativeTraversal, visits_complete_tree_in_preorder)
{
    auto root = create_complete_tree();

    const std::vector<int> expected{25, 15, 10, 4, 12, 22, 18, 24, 50, 35, 31, 44, 70, 66, 90};
    EXPECT_EQ(collect_preorder_values(root), expected);
}

TEST_F(SetupIterativeTraversal, visits_left_skewed_tree_in_preorder)
{
    auto root = make_node(4);
    auto node3 = make_node(3);
    auto node2 = make_node(2);
    auto node1 = make_node(1);

    connect(root, node3, nullptr);
    connect(node3, node2, nullptr);
    connect(node2, node1, nullptr);

    EXPECT_EQ(collect_preorder_values(root), std::vector<int>({4, 3, 2, 1}));
}

TEST_F(SetupIterativeTraversal, visits_right_skewed_tree_in_preorder)
{
    auto root = make_node(1);
    auto node2 = make_node(2);
    auto node3 = make_node(3);
    auto node4 = make_node(4);

    connect(root, nullptr, node2);
    connect(node2, nullptr, node3);
    connect(node3, nullptr, node4);

    EXPECT_EQ(collect_preorder_values(root), std::vector<int>({1, 2, 3, 4}));
}

TEST_F(SetupIterativeTraversal, visits_sparse_tree_in_preorder)
{
    auto root = make_node(8);
    auto node3 = make_node(3);
    auto node10 = make_node(10);
    auto node1 = make_node(1);
    auto node6 = make_node(6);
    auto node14 = make_node(14);
    auto node4 = make_node(4);
    auto node7 = make_node(7);
    auto node13 = make_node(13);

    connect(root, node3, node10);
    connect(node3, node1, node6);
    connect(node10, nullptr, node14);
    connect(node6, node4, node7);
    connect(node14, node13, nullptr);

    EXPECT_EQ(collect_preorder_values(root), std::vector<int>({8, 3, 1, 6, 4, 7, 10, 14, 13}));
}

TEST_F(SetupIterativeTraversal, postorder_returns_empty_result_for_null_root)
{
    EXPECT_EQ(collect_postorder_values(nullptr), std::vector<int>{});
}

TEST_F(SetupIterativeTraversal, postorder_visits_single_node_tree)
{
    auto root = make_node(42);

    EXPECT_EQ(collect_postorder_values(root), std::vector<int>{42});
}

TEST_F(SetupIterativeTraversal, visits_complete_tree_in_postorder)
{
    auto root = create_complete_tree();

    const std::vector<int> expected{4, 12, 10, 18, 24, 22, 15, 31, 44, 35, 66, 90, 70, 50, 25};
    EXPECT_EQ(collect_postorder_values(root), expected);
}

TEST_F(SetupIterativeTraversal, visits_left_skewed_tree_in_postorder)
{
    auto root = make_node(4);
    auto node3 = make_node(3);
    auto node2 = make_node(2);
    auto node1 = make_node(1);

    connect(root, node3, nullptr);
    connect(node3, node2, nullptr);
    connect(node2, node1, nullptr);

    EXPECT_EQ(collect_postorder_values(root), std::vector<int>({1, 2, 3, 4}));
}

TEST_F(SetupIterativeTraversal, visits_right_skewed_tree_in_postorder)
{
    auto root = make_node(1);
    auto node2 = make_node(2);
    auto node3 = make_node(3);
    auto node4 = make_node(4);

    connect(root, nullptr, node2);
    connect(node2, nullptr, node3);
    connect(node3, nullptr, node4);

    EXPECT_EQ(collect_postorder_values(root), std::vector<int>({4, 3, 2, 1}));
}

TEST_F(SetupIterativeTraversal, visits_sparse_tree_in_postorder)
{
    auto root = make_node(8);
    auto node3 = make_node(3);
    auto node10 = make_node(10);
    auto node1 = make_node(1);
    auto node6 = make_node(6);
    auto node14 = make_node(14);
    auto node4 = make_node(4);
    auto node7 = make_node(7);
    auto node13 = make_node(13);

    connect(root, node3, node10);
    connect(node3, node1, node6);
    connect(node10, nullptr, node14);
    connect(node6, node4, node7);
    connect(node14, node13, nullptr);

    EXPECT_EQ(collect_postorder_values(root), std::vector<int>({1, 4, 7, 6, 3, 13, 14, 10, 8}));
}
